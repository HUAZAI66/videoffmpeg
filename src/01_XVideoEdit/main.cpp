#include "xvideoui.h"
#include <QtWidgets/QApplication>
//#include "XAudio.h"
int main(int argc, char *argv[])
{
   //XAudio::Get()->ExportA("v1080.mp4","test.mp3");
   //XAudio::Get()->Merge("v1080.mp4", "test.mp3","re.avi");

    QApplication a(argc, argv);
    XVideoUI v;
    v.show();
    return a.exec();
}
