#include "Enviroment.h"

void displayInstructions() {
    // ����ͼƬ��Դ
    std::vector<IMAGE> images(4);
    loadimage(&images[0], _T("./src/picture/instruction/�õ�Ƭ1.jpg"), 1600, 900);
    loadimage(&images[1], _T("./src/picture/instruction/�õ�Ƭ2.jpg"), 1600, 900);
    loadimage(&images[2], _T("./src/picture/instruction/�õ�Ƭ3.jpg"), 1600, 900);
    loadimage(&images[3], _T("./src/picture/instruction/�õ�Ƭ4.jpg"), 1600, 900);


    int currentImage = 0;
    while (true) {
        // ��ʾ��ǰͼƬ
        putimage(0, 0, &images[currentImage]);

        // �ȴ�������¼�
        msg = getmessage(EX_MOUSE);
        if (msg.message == WM_LBUTTONDOWN) {
            currentImage++;
            if (currentImage >= images.size()) {
                return; // ����ͼƬ����������
            }
        }

        // ˢ����Ļ
        FlushBatchDraw();
    }

    // �����Ļ
    //cleardevice();
}