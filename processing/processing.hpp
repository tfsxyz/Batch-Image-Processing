#ifndef PROCESSING_HPP
#define PROCESSING_HPP
//#include "../Widget/widget.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <QDebug>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QWidget>
#include <QtGui>
#include <iostream>
#include <math.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace cv;
#define UCHAR unsigned char
// class Parameter;
class Parameter {
  public:
    int temperatur_color = 0;
    int temperatur_color_min = -100;
    int temperatur_color_max = 100;
    int tone = 0;
    int tone_min = -100;
    int tone_max = 100;
    int exposure = 0;
    int exposure_max = 100;
    int exposure_min = -100;
    int contrast = 0;
    int contrast_max = 100;
    int contrast_min = -100;
    int highlight = 0;
    int highlight_max = 100;
    int highlight_min = -100;
    int shadow = 0;
    int shadow_max = 100;
    int shadow_min = -100;
    int white = 0;
    int white_max = 100;
    int white_min = -100;
    int black = 0;
    int black_max = 100;
    int black_min = -100;
    int sharpness = 0;
    int sharpness_max = 100;
    int sharpness_min = -100;
    int soft = 0;
    int soft_max = 100;
    int soft_min = -100;
    QString text_add;
    int text_add_x = 0;
    int text_add_y = 0;
    int text_add_r = 0;
    int text_add_g = 0;
    int text_add_b = 0;
    int text_add_line = 0;
    int text_size = 0;
    QString logo;
    int logo_x = 0;
    int logo_y = 0;
};
class Processing {
  public:
    Mat LOGO;
    String TEXT;
    //这两个是我不想看到的。但我还是看到了，说明一开始的架构有问题
  public:
    class BGR {
      public:
        double b;
        double g;
        double r;
        void bgr(double H, double S, double V);
        void exposure_contrast(int value_exposure, int value_contrast);
    };
    class HSV {
      public:
        double h;
        double s;
        double v;
        void hsv(double b, double g, double r);
        void temperature_color(int value);
        void tone(int value);
        void temperature_tone_change(int value_temperature, int value_tong);
        // h的改变
        void highlight_change(int value);
        void shadow_change(int value);
        void white_black(int value_white, int value_black);
    };
  public:
    int test_debug();
    // debug测试
    QImage processing(QString image_qstring, Parameter all);
    //最终实现的目的函数
    Mat processing_mat(Mat image, Parameter all);
    // mat的美化功能实现，用于测试方便
    Mat temperature_color(Mat image, int value);
    //色温值的选择
    Mat tone(Mat image, int value);
    //色调的选择
    Mat exposure(Mat image, int value);
    //曝光选择
    Mat contrast(Mat image, int value);
    //对比度的选择
    Mat highlight(Mat image, int value);
    //高光的选择
    Mat shadow(Mat image, int value);
    //阴影的选择
    Mat white(Mat image, int value);
    //白色的选择
    Mat black(Mat image, int value);
    //黑色的选择
    Mat sharpness(Mat image, int value);
    //锐度的xuanze的选择;
    Mat soft(Mat image, int value);
    //柔和的选择
    Mat sharpness_soft(Mat image, int value_sharpness, int value_soft);
    //锐化和柔和在一起
    Mat text_add(Mat image, String text, int text_x, int text_y, int text_line,
                 int text_size, int r_text, int g_text, int b_text);
    //文字加入函数
    Mat logo_add(Mat image, Mat logo, int logo_x, int logo_y);
    // logo加入函数
    Mat Qstring_Mat(QString Qimage);
    // qstring mat 转化
    QImage LabelDisplayMat(cv::Mat &mat);
    // qimage processing 转化
};
#endif // PROCESSING_HPP