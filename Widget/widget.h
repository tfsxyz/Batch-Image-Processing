#ifndef WIDGET_H
#define WIDGET_H
#include "../processing/processing.hpp"
#include "dialog.h"
#include <QDebug>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QWidget>
#include <QtGui>
namespace Ui {
class Widget;
}
// class Processing;
class Widget : public QWidget {
    Q_OBJECT
  public:
    QStringList image_list;
    //当前打开的图片列表
    int image_list_i;
    //当前处在的图片数字
    int image_list_all;
    //列表总共的图片数字
    QString number_show;
    //展现当前照片属性
    Parameter all;
    //所有的照片最后都按照这个属性进行
    Dialog color;
    //颜色选取窗口
  public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
  public:
    void ClearOldShow();
    //清理当前显示窗口
    void show_image(QString strjpge);
    //展示image到主窗口,等比例缩放
    void show_QImage(QImage img);
    // tongshang
    void removeListSame(QStringList list);
    //清除所有重复的项
    void number_show_change();
    //更改底下的显示控件
    void buttum_show();
    //底部的展示
    void slider_css();
    //滑动条的样式
  private slots:
    void on_pushButton_basic_clicked();
    //基本状态按钮切换
    void on_pushButton_in_clicked();
    //镶嵌状态按钮切换
    void on_pushButton_open_clicked();
    void on_pushButton_cancle_clicked();
    void on_pushButton_right_clicked();
    void on_pushButton_left_clicked();
    void on_horizontalSlider_temperature_color_valueChanged(int value);
    void on_lineEdit_temperature_color_textEdited(const QString &arg1);
    void on_horizontalSlider_tone_valueChanged(int value);
    void on_lineEdit_tone_textEdited(const QString &arg1);
    void on_horizontalSlider_exposure_valueChanged(int value);
    void on_lineEdit_exposure_textEdited(const QString &arg1);
    void on_horizontalSlider_contrast_valueChanged(int value);
    void on_lineEdit_contrast_textEdited(const QString &arg1);
    void on_horizontalSlider_highlight_valueChanged(int value);
    void on_lineEdit_highlight_textEdited(const QString &arg1);
    void on_horizontalSlider_shadow_valueChanged(int value);
    void on_lineEdit_shadow_textEdited(const QString &arg1);
    void on_horizontalSlider_white_valueChanged(int value);
    void on_lineEdit_white_textEdited(const QString &arg1);
    void on_horizontalSlider_black_valueChanged(int value);
    void on_lineEdit_black_textEdited(const QString &arg1);
    void on_horizontalSlider_sharpness_valueChanged(int value);
    void on_lineEdit_sharpness_textEdited(const QString &arg1);
    void on_horizontalSlider_soft_valueChanged(int value);
    void on_lineEdit_soft_textEdited(const QString &arg1);
    void on_lineEdit_text_textChanged(const QString &arg1);
    void on_lineEdit_x_textChanged(const QString &arg1);
    void on_lineEdit_y_textChanged(const QString &arg1);
    void on_pushButton_text_color_clicked();
    void on_lineEdit_line_textChanged(const QString &arg1);
    void on_lineEdit_x_2_textChanged(const QString &arg1);
    void on_lineEdit_y_2_textChanged(const QString &arg1);
    void on_pushButton_text_color_2_clicked();
    void on_pushButton_out_clicked();
    void on_pushButton_show_clicked();
    void on_lineEdit_size_textChanged(const QString &arg1);
    void on_pushButton_help_2_clicked();
  private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
