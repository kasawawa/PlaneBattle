#include "Enviroment.h"

void displayInstructions() {
    // 加载图片资源
    std::vector<IMAGE> images(4);
    loadimage(&images[0], _T("./src/picture/instruction/幻灯片1.jpg"), 1600, 900);
    loadimage(&images[1], _T("./src/picture/instruction/幻灯片2.jpg"), 1600, 900);
    loadimage(&images[2], _T("./src/picture/instruction/幻灯片3.jpg"), 1600, 900);
    loadimage(&images[3], _T("./src/picture/instruction/幻灯片4.jpg"), 1600, 900);


    int currentImage = 0;
    while (true) {
        // 显示当前图片
        putimage(0, 0, &images[currentImage]);

        // 等待鼠标点击事件
        msg = getmessage(EX_MOUSE);
        if (msg.message == WM_LBUTTONDOWN) {
            currentImage++;
            if (currentImage >= images.size()) {
                return; // 超出图片数量，返回
            }
        }

        // 刷新屏幕
        FlushBatchDraw();
    }

    // 清除屏幕
    //cleardevice();
}