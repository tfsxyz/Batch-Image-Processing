#include "dialog.h"
#include "widget.h"
Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle(QStringLiteral("颜色对话框"));
    colorBtn = new QPushButton; //创建各个控件的对象
    colorBtn->setText(QStringLiteral("颜色标准对话框"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    //布局设计
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame);
    //事件关联
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
}
Dialog::~Dialog() {}
QColor Dialog::showColor() {
    QColor c;
    c = QColorDialog::getColor(Qt::blue);
    if (c.isValid()) { //判断用户选择颜色是否有效
        colorFrame->setPalette(QPalette(c));
    }
    Dialog::bridge(c);
    return c;
}
QColor Dialog::bridge(QColor tra) { return tra; }
