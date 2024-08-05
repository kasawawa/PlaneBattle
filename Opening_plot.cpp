#include <iostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <easyx.h>

// 获取屏幕分辨率
void getScreenResolution(int& width, int& height) {
    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
}

// 计算保持宽高比的缩放尺寸
cv::Size calculateSize(int srcWidth, int srcHeight, int maxWidth, int maxHeight) {
    double ratioW = (double)maxWidth / srcWidth;
    double ratioH = (double)maxHeight / srcHeight;
    double ratio = min(ratioW, ratioH);

    int newWidth = static_cast<int>(srcWidth * ratio);
    int newHeight = static_cast<int>(srcHeight * ratio);

    return cv::Size(newWidth, newHeight);
}

// 绘制进度条
void drawProgressBar(cv::Mat& frame, int current_frame, int total_frames, cv::Rect position) {
	// 计算进度条的百分比
	int progress = static_cast<int>((current_frame * 100) / total_frames);

	// 进度条的高度
	int barHeight = 20;

	// 绘制背景
	cv::rectangle(frame, position, cv::Scalar(50, 50, 50), -1);

	// 计算进度条的宽度
	int barWidth = static_cast<int>((position.width * progress) / 100);

	// 绘制进度条
	cv::rectangle(frame, cv::Rect(position.tl(), cv::Size(barWidth, barHeight)), cv::Scalar(255, 0, 0), -1);

	// 添加文本
	std::string progressText = std::to_string(progress) + " %";
	cv::putText(frame, progressText, cv::Point(position.x + 10, position.y + 15),
		cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);
}

// 打开视频文件并播放
void Opening_plot(const char* file_path) {
    cv::VideoCapture capture(file_path);
    if (!capture.isOpened()) {
        std::cout << "Error opening video file" << std::endl;
    }

    double rate = capture.get(cv::CAP_PROP_FPS);
    int total_frames = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_COUNT));
    std::cout << "Frame rate: " << rate << std::endl;
    std::cout << "Total frames: " << total_frames << std::endl;

    // 创建全屏窗口
    cv::namedWindow("Movie Player", cv::WINDOW_NORMAL);
    cv::setWindowProperty("Movie Player", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    // 获取屏幕分辨率
    int screenWidth, screenHeight;
    getScreenResolution(screenWidth, screenHeight);

    cv::Mat frame, resized_frame, display_frame;
    int delay = static_cast<int>(1000 / rate);

    // 获取视频的原始尺寸
    int frameWidth = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeight = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT));

    // 计算保持宽高比的新尺寸
    cv::Size newSize = calculateSize(frameWidth, frameHeight, screenWidth, screenHeight);
	int current_frame = 0; // 定义current_frame变量

	//std::string exitText = "[ Esc ] -> ......";

    while (true) {
        if (!capture.read(frame))
            break;

        // 调整帧大小，保持宽高比
        cv::resize(frame, resized_frame, newSize);

        // 创建一个与屏幕大小相同的黑色背景
        display_frame = cv::Mat(screenHeight, screenWidth, CV_8UC3, cv::Scalar(0, 0, 0));

        // 计算居中位置
        int x = (screenWidth - newSize.width) / 2;
        int y = (screenHeight - newSize.height) / 2;

        // 将调整大小后的帧复制到显示帧的中心
        resized_frame.copyTo(display_frame(cv::Rect(x, y, newSize.width, newSize.height)));

		// 更新current_frame变量
		current_frame = static_cast<int>(capture.get(cv::CAP_PROP_POS_FRAMES));

		// 绘制进度条的位置
		cv::Rect progressBarRect(0, display_frame.rows - 30, display_frame.cols, 30);

		// 在显示帧上绘制进度条
		drawProgressBar(display_frame, current_frame, total_frames, progressBarRect);

		// 在右上角添加“【Esc】跳过……”文字提示
		//cv::Point exitTextPosition(display_frame.cols - 200, 30); // 定义文本位置
		//cv::putText(display_frame, exitText, exitTextPosition,
		//	cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

        // 显示
        cv::imshow("Movie Player", display_frame);

        int current_frame = static_cast<int>(capture.get(cv::CAP_PROP_POS_FRAMES));
        std::cout << "Progress: " << current_frame << "/" << total_frames << "\r" << std::flush;

        char c = cv::waitKey(delay);
        //if (c == VK_ESCAPE)		// [Esc]（27）
		//	if (MessageBox(GetHWnd(), "视频也就不到【1.5min】\t（^_^）/\n\n\t再看看好嘛？求求了！\n\t(T_T)", "跳过提示（-. -\"）", MB_YESNO) == IDNO)
		//		break;
		//	else
		//		c = 0;
    }

    capture.release();
    cv::destroyAllWindows();
}