#include "Widget/dialog.h"
#include "Widget/widget.h"
#include <QApplication>
#include <QtGui>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFont font;
    font.setFamily("微软雅黑"); // win全局字体设置
    a.setFont(font);
    Widget w;
    w.show();
    return a.exec();
}
