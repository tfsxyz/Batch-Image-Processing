#include "widget.h"
#include "../build/ui_widget.h"
//#include "../processing/processing.hpp"
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    image_list_i = 0;
    //定义初始的i为0
    image_list_all = 0;
    ClearOldShow();
    slider_css();
}
Widget::~Widget() { delete ui; }
void Widget::buttum_show() {
    ui->label_number->show();
    ui->pushButton_left->show();
    ui->pushButton_right->show();
}
void Widget::ClearOldShow() {
    //清空标签内容
    ui->label_image_show->clear();
    // ui->label_number->hide();
    // ui->pushButton_left->hide();
    //   ui->pushButton_right->hide();
}
void Widget::removeListSame(QStringList list) {
    for (int i = 0; i < list.count(); i++) {
        for (int k = i + 1; k < list.count(); k++) {
            if (list.at(i) == list.at(k)) {
                list.removeAt(k);
                k--;
            }
        }
    }
}
void Widget::show_QImage(QImage Img) {
    ClearOldShow();
    QSize laSize; //输出大小
    // double k;
    // k = double(Img.width()) / double(Img.height());
    // double show_k;
    // show_k = double(ui->label_image_show->width()) /
    //  double(ui->label_image_show->height());
    //  QPixmap *m_pPixMap;
    //  m_pPixMap = new QPixmap();
    //加载
    //   m_pPixMap->load(strjpge);
    laSize = ui->label_image_show->size();
    // if (0) {
    //     if (k < show_k) {
    //         //竖版图片
    //         laSize.setWidth((laSize.height()) * k);
    //         // qDebug() << laSize.width()<<endl;
    //         // qDebug()<<laSize.height()<<endl;
    //     } else {
    //         //横版图片,比较横的
    //         laSize.setHeight(laSize.width() / k);
    //     }
    // }
    QImage image1 =
        Img.scaled(laSize, Qt::KeepAspectRatio, Qt::FastTransformation);
    ui->label_image_show->setAlignment(Qt::AlignCenter);
    ui->label_image_show->setPixmap(QPixmap::fromImage(image1));
}
void Widget::show_image(QString strjpge) {
    if (strjpge.isEmpty() == 0) {
        //  ClearOldShow();
        QImage Img; //图片文件储存
                    // QSize laSize; //输出大小
        Img.load(strjpge);
        show_QImage(Img);
    }
}
void Widget::number_show_change() {
    QString str;
    str = QString::number((image_list_i + 1));
    QString str_2;
    str_2 = QString::number(image_list_all);
    number_show = "第";
    if (image_list_i + 1 < 10)
        number_show.append("0");
    number_show.append(str);
    number_show.append("/");
    if (image_list_all < 10)
        number_show.append("0");
    number_show.append(str_2);
    number_show.append("张");
}
void Widget::on_pushButton_basic_clicked() {
    ui->pushButton_basic->setStyleSheet(
        "QPushButton{background-color: rgb(50, 50, "
        "50);border-top-width:3px;border-left:none;border-right:none;border-"
        "color: rgb(40, 40, 40);color: rgb(255, 255, 255);font: 18px;}");
    ui->pushButton_in->setStyleSheet(
        "  background-color: rgb(40, 40, 40); font: 18px ;  "
        "border-top-width:3px;    "
        "border-left:none;border-right:none;border-color: rgb(40, 40, "
        "40);color: rgb(204, 204, 204);");
}
void Widget::on_pushButton_in_clicked() {
    ui->pushButton_in->setStyleSheet(
        "QPushButton{background-color: rgb(50, 50, "
        "50);border-top-width:3px;border-left:none;border-right-width:3px;"
        "border-color: rgb(40, 40, 40);color: rgb(255, 255, 255);font: 18px;}");
    ui->pushButton_basic->setStyleSheet(
        "  background-color: rgb(40, 40, 40); font: 18px ;  "
        "border-top-width:3px;    "
        "border-left:none;border-right:none;border-color: rgb(40, 40, "
        "40);color: rgb(204, 204, 204);");
}
void Widget::slider_css() {
    ui->horizontalSlider_temperature_color->setMaximum(
        all.temperatur_color_max);
    ui->horizontalSlider_temperature_color->setMinimum(
        all.temperatur_color_min);
    ui->lineEdit_temperature_color->setText(QString::number(0));
    ui->horizontalSlider_tone->setMaximum(all.tone_max);
    ui->horizontalSlider_tone->setMinimum(all.tone_min);
    ui->lineEdit_tone->setText(QString::number(0));
    ui->horizontalSlider_exposure->setMaximum(all.exposure_max);
    ui->horizontalSlider_exposure->setMinimum(all.exposure_min);
    ui->lineEdit_exposure->setText(QString::number(0));
    ui->horizontalSlider_contrast->setMaximum(all.contrast_max);
    ui->horizontalSlider_contrast->setMinimum(all.contrast_min);
    ui->lineEdit_contrast->setText(QString::number(0));
    ui->horizontalSlider_highlight->setMaximum(all.highlight_max);
    ui->horizontalSlider_highlight->setMinimum(all.highlight_min);
    ui->lineEdit_highlight->setText(QString::number(0));
    ui->horizontalSlider_shadow->setMaximum(all.shadow_max);
    ui->horizontalSlider_shadow->setMinimum(all.shadow_min);
    ui->lineEdit_shadow->setText(QString::number(0));
    ui->horizontalSlider_white->setMaximum(all.white_max);
    ui->horizontalSlider_white->setMinimum(all.white_min);
    ui->lineEdit_white->setText(QString::number(0));
    ui->horizontalSlider_black->setMaximum(all.black_max);
    ui->horizontalSlider_black->setMinimum(all.black_min);
    ui->lineEdit_black->setText(QString::number(0));
    ui->horizontalSlider_sharpness->setMaximum(all.sharpness_max);
    ui->horizontalSlider_sharpness->setMinimum(all.sharpness_min);
    ui->lineEdit_sharpness->setText(QString::number(0));
    ui->horizontalSlider_soft->setMaximum(all.soft_max);
    ui->horizontalSlider_soft->setMinimum(all.soft_min);
    ui->lineEdit_soft->setText(QString::number(0));
}
void Widget::on_pushButton_open_clicked() {
    //批量打开图片编写
    QStringList strFileNames; //文件名list
    strFileNames = QFileDialog::getOpenFileNames(
        this, tr("打开静态图片"), "",
        "Pictures (*.bmp *.jpg *.jpeg *.png *.xpm);;All files(*)");
    if (strFileNames.isEmpty()) {
        //文件名为空，返回
        return;
    }
    //清空旧的图片或短片
    // ClearOldShow();
    //打印文件名
    // qDebug() << strFileNames.at(0);
    show_image(strFileNames.at(image_list_i)); //展示所选的第一张
    buttum_show();
    image_list.append(strFileNames); //从头开始，实际上应该是接着走
    // removeListSame(image_list);
    image_list_all = image_list.count();
    number_show_change();
    ui->label_number->setText(number_show);
    // qDebug()<<image_list_all;
}
void Widget::on_pushButton_cancle_clicked() {
    ClearOldShow();
    image_list.clear();
    image_list_all = 0;
    image_list_i = 0;
    number_show_change();
    ui->label_number->setText(number_show);
}
void Widget::on_pushButton_right_clicked() {
    if (image_list_i < image_list_all - 1) {
        image_list_i++;
        show_image(image_list.at(image_list_i));
    }
    // qDebug()<<image_list_i;
    number_show_change();
    ui->label_number->setText(number_show);
}
void Widget::on_pushButton_left_clicked() {
    if (image_list_i > 0) {
        image_list_i--;
        show_image(image_list.at(image_list_i));
    }
    number_show_change();
    ui->label_number->setText(number_show);
    // qDebug()<<image_list_i;
}
void Widget::on_horizontalSlider_temperature_color_valueChanged(int value) {
    all.temperatur_color = value;
    ui->lineEdit_temperature_color->setText(
        QString::number(all.temperatur_color));
    //  show_image(image_list.at(image_list_i));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_temperature_color_textEdited(const QString &arg1) {
    all.temperatur_color = arg1.toInt();
    ui->horizontalSlider_temperature_color->setValue(all.temperatur_color);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_tone_valueChanged(int value) {
    all.tone = value;
    ui->lineEdit_tone->setText(QString::number(all.tone));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_tone_textEdited(const QString &arg1) {
    all.tone = arg1.toInt();
    ui->horizontalSlider_tone->setValue(all.tone);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_exposure_valueChanged(int value) {
    all.exposure = value;
    ui->lineEdit_exposure->setText(QString::number(all.exposure));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_exposure_textEdited(const QString &arg1) {
    all.exposure = arg1.toInt();
    ui->horizontalSlider_exposure->setValue(all.exposure);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_contrast_valueChanged(int value) {
    all.contrast = value;
    ui->lineEdit_contrast->setText(QString::number(all.contrast));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_contrast_textEdited(const QString &arg1) {
    all.contrast = arg1.toInt();
    ui->horizontalSlider_contrast->setValue(all.contrast);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_highlight_valueChanged(int value) {
    all.highlight = value;
    ui->lineEdit_highlight->setText(QString::number(all.highlight));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_highlight_textEdited(const QString &arg1) {
    all.highlight = arg1.toInt();
    ui->horizontalSlider_highlight->setValue(all.highlight);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_shadow_valueChanged(int value) {
    all.shadow = value;
    ui->lineEdit_shadow->setText(QString::number(all.shadow));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_shadow_textEdited(const QString &arg1) {
    all.shadow = arg1.toInt();
    ui->horizontalSlider_shadow->setValue(all.shadow);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_white_valueChanged(int value) {
    all.white = value;
    ui->lineEdit_white->setText(QString::number(all.white));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_white_textEdited(const QString &arg1) {
    all.white = arg1.toInt();
    ui->horizontalSlider_white->setValue(all.white);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_black_valueChanged(int value) {
    all.black = value;
    ui->lineEdit_black->setText(QString::number(all.black));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_black_textEdited(const QString &arg1) {
    all.black = arg1.toInt();
    ui->horizontalSlider_black->setValue(all.black);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_sharpness_valueChanged(int value) {
    all.sharpness = value;
    ui->lineEdit_sharpness->setText(QString::number(all.sharpness));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_sharpness_textEdited(const QString &arg1) {
    all.sharpness = arg1.toInt();
    ui->horizontalSlider_sharpness->setValue(all.sharpness);
    on_pushButton_show_clicked();
}
void Widget::on_horizontalSlider_soft_valueChanged(int value) {
    all.soft = value;
    ui->lineEdit_soft->setText(QString::number(all.soft));
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_soft_textEdited(const QString &arg1) {
    all.soft = arg1.toInt();
    ui->horizontalSlider_soft->setValue(all.soft);
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_text_textChanged(const QString &arg1) {
    all.text_add = arg1;
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_x_textChanged(const QString &arg1) {
    all.text_add_x = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_y_textChanged(const QString &arg1) {
    all.text_add_y = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_pushButton_text_color_clicked() {
    QColor tra;
    tra = color.showColor();
    all.text_add_b = tra.red();
    all.text_add_g = tra.green();
    all.text_add_r = tra.red();
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_line_textChanged(const QString &arg1) {
    all.text_add_line = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_x_2_textChanged(const QString &arg1) {
    all.logo_x = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_lineEdit_y_2_textChanged(const QString &arg1) {
    all.logo_y = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_pushButton_text_color_2_clicked() {
    QString strFileName; //文件名list
    strFileName = QFileDialog::getOpenFileName(
        this, tr("打开静态图片"), "",
        "Pictures (*.bmp *.jpg *.jpeg *.png *.xpm);;All files(*)");
    if (strFileName.isEmpty()) {
        //文件名为空，返回
        return;
    }
    all.logo = strFileName;
    on_pushButton_show_clicked();
}
void Widget::on_pushButton_out_clicked() {
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save Image"), "",
        tr("Images ()")); //选择路径,而且后面会自动补齐这个东西
    for (int i = 0; i < image_list_all; i++) {
        QString filename_i;
        QString str;
        str = QString::number(i + 1);
        filename_i = filename;
        filename_i.append(str);
        filename_i.append(".png");
        QImage image_after;
        // image_before.load(image_list.at(image_list_i));
        Processing show_test;
        image_after = show_test.processing(image_list.at(i), all);
        QPixmap pix;
        pix = QPixmap::fromImage(image_after);
        pix.save(filename_i);
        qDebug() << filename_i;
    }
    on_pushButton_show_clicked();
}
void Widget::on_pushButton_show_clicked() {
    // QImage image_before;
    // ClearOldShow();
    QImage image_after;
    // image_before.load(image_list.at(image_list_i));
    Processing show_test;
    image_after = show_test.processing(image_list.at(image_list_i), all);
    // bug主要在这这里
    // proceessing no process bug still have
    // show_test.test_debug();
    ClearOldShow();
    show_QImage(image_after);
}
void Widget::on_lineEdit_size_textChanged(const QString &arg1) {
    all.text_size = arg1.toInt();
    on_pushButton_show_clicked();
}
void Widget::on_pushButton_help_2_clicked() {
    all.temperatur_color = 0;
    all.black = 0;
    all.white = 0;
    all.tone = 0;
    all.contrast = 0;
    all.exposure = 0;
    all.highlight = 0;
    all.shadow = 0;
    all.sharpness = 0;
    all.soft = 0;
    ui->horizontalSlider_soft->setValue(all.soft);
    ui->horizontalSlider_black->setValue(all.black);
    ui->horizontalSlider_contrast->setValue(all.contrast);
    ui->horizontalSlider_exposure->setValue(all.exposure);
    ui->horizontalSlider_highlight->setValue(all.highlight);
    ui->horizontalSlider_shadow->setValue(all.shadow);
    ui->horizontalSlider_temperature_color->setValue(all.temperatur_color);
    ui->horizontalSlider_tone->setValue(all.tone);
    ui->horizontalSlider_white->setValue(all.white);
    ui->horizontalSlider_sharpness->setValue(all.sharpness);
}
