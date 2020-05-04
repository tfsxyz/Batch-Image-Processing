#include "processing.hpp"
using namespace std;
using namespace cv;
#define UCHAR unsigned char
QImage Processing::processing(QString image_qstring, Parameter all) {
    Mat image = Qstring_Mat(image_qstring);
    // QImage qimage_test;
    // qimage_test=LabelDisplayMat(image);
    // return qimage_test;
    LOGO = Qstring_Mat(all.logo);
    TEXT = all.text_add.toStdString();
    Mat image_final;
    image_final = processing_mat(image, all).clone();
    QImage qimage_final;
    qimage_final = LabelDisplayMat(image_final);
    return qimage_final;
} //如果直接传出结果，bug仍然会有
int Processing::test_debug() {}
void Processing::BGR::bgr(double H, double S, double V) {
    // convert from HSV/HSB to RGB color
    // R,G,B from 0-255, H from 0-360, S,V from 0-100
    // ref http://colorizer.org/
    // The hue (H) of a color refers to which pure color it resembles
    // The saturation (S) of a color describes how white the color is
    // The value (V) of a color, also called its lightness, describes how dark
    // the color is
    int h = int(H);
    int s = int(S * 100);
    int v = int(V * 100 / 255.0);
    int i;
    float RGB_min, RGB_max;
    RGB_max = v * 2.55f;
    RGB_min = RGB_max * (100 - s) / 100.0f;
    i = h / 60;
    int difs = h % 60; // factorial part of h
    // RGB adjustment amount by hue
    float RGB_Adj = (RGB_max - RGB_min) * difs / 60.0f;
    switch (i) {
    case 0:
        r = RGB_max;
        g = RGB_min + RGB_Adj;
        b = RGB_min;
        break;
    case 1:
        r = RGB_max - RGB_Adj;
        g = RGB_max;
        b = RGB_min;
        break;
    case 2:
        r = RGB_min;
        g = RGB_max;
        b = RGB_min + RGB_Adj;
        break;
    case 3:
        r = RGB_min;
        g = RGB_max - RGB_Adj;
        b = RGB_max;
        break;
    case 4:
        r = RGB_min + RGB_Adj;
        g = RGB_min;
        b = RGB_max;
        break;
    default: // case 5:
        r = RGB_max;
        g = RGB_min;
        b = RGB_max - RGB_Adj;
        break;
    }
}
void Processing::HSV::hsv(double b, double g, double r) {
    // r,g,b values are from 0 to 1
    // h = [0,360], s = [0,1], v = [0,1]
    // if s == 0, then h = -1 (undefined)
    double min, max, delta, tmp;
    tmp = r > g ? g : r;
    min = tmp > b ? b : tmp;
    tmp = r > g ? r : g;
    max = tmp > b ? tmp : b;
    v = max; // v
    delta = max - min;
    if (max != 0)
        s = delta / max; // s
    else {
        // r = g = b = 0 // s = 0, v is undefined
        s = 0;
        h = 0;
        return;
    }
    if (delta == 0) {
        h = 0;
        return;
    } else if (r == max) {
        if (g >= b)
            h = (g - b) / delta; // between yellow & magenta
        else
            h = (g - b) / delta + 6.0;
    } else if (g == max)
        h = 2.0 + (b - r) / delta; // between cyan & yellow
    else if (b == max)
        h = 4.0 + (r - g) / delta; // between magenta & cyan
    h *= 60.0;                     // degrees
}
Mat Processing::processing_mat(Mat image, Parameter all) {
    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            int b = image.ptr<Vec3b>(y)[x][0];
            int g = image.ptr<Vec3b>(y)[x][1];
            int r = image.ptr<Vec3b>(y)[x][2];
            Processing::HSV hsv;
            hsv.hsv(b, g, r);
            hsv.temperature_tone_change(all.temperatur_color, all.tone);
            hsv.highlight_change(all.highlight);
            hsv.shadow_change(all.shadow);
            hsv.white_black(all.white, all.black);
            Processing::BGR bgr;
            bgr.bgr(hsv.h, hsv.s, hsv.v);
            bgr.exposure_contrast(all.exposure, all.contrast);
            // cout <<bgr.b<<endl;
            // cout <<bgr.g<<endl;
            // cout <<bgr.r<<endl;
            image.ptr<Vec3b>(y)[x][0] = bgr.b;
            image.ptr<Vec3b>(y)[x][1] = bgr.g;
            image.ptr<Vec3b>(y)[x][2] = bgr.r;
        }
    }
    Mat image_final;
    image_final = image.clone();
    image_final = sharpness_soft(image_final, all.sharpness, all.soft);
    image_final = text_add(image_final, TEXT, all.text_add_x, all.text_add_y,
                           all.text_add_line, all.text_size, all.text_add_r,
                           all.text_add_g, all.text_add_b);
    image_final = logo_add(image_final, LOGO, all.logo_x, all.logo_y);
    //锐度和柔和
    return image_final;
}
Mat Processing::temperature_color(Mat image, int value) {}
//色温值的选择
Mat Processing::tone(Mat image, int value) {}
//色调的选择
Mat Processing::exposure(Mat image, int value) {}
//曝光选择
Mat Processing::contrast(Mat image, int value) {}
//对比度的选择
Mat Processing::highlight(Mat image, int value) {}
//高光的选择
Mat Processing::shadow(Mat image, int value) {}
//阴影的选择
Mat Processing::white(Mat image, int value) {}
//白色的选择
Mat Processing::black(Mat image, int value) {}
//黑色的选择
Mat Processing::sharpness(Mat image, int value) {
    Mat final_image;
    Mat blur_image;
    blur_image = image.clone();
    GaussianBlur(image, blur_image, Size(0, 0), 25);
    addWeighted(image, 1 + value * 0.01, blur_image, -value * 0.01, 0,
                final_image);
    return final_image;
}
//锐度的的选择;
Mat Processing::soft(Mat image, int value) {
    Mat final_image;
    GaussianBlur(image, final_image, Size(0, 0), 25);
    addWeighted(image, 100, final_image, value, 0, final_image);
}
//柔和的选择
Mat Processing::sharpness_soft(Mat image, int value_sharpness, int value_soft) {
    int value = value_sharpness - value_soft;
    Mat final_image;
    Mat blur_image;
    blur_image = image.clone();
    GaussianBlur(image, blur_image, Size(0, 0), 25);
    addWeighted(image, 1 + value * 0.01, blur_image, -value * 0.01, 0,
                final_image);
    return final_image;
}
void Processing::HSV::temperature_color(int value) {
    if (-0.1 < h && h < 240.01) {
        h += value;
        if (h < 0)
            h = 0;
        if (h > 240)
            h = 240;
    }
    if (h > 240) {
        h -= value;
        if (h < 240)
            h = 240;
        if (h > 360)
            h = 0;
    }
}
void Processing::HSV::temperature_tone_change(int value_temperature,
                                              int value_tone) {
    if (value_temperature != 0 || value_tone != 0) {
        double final_temprature;
        double final_tone;
        if (h > 0) {
            double rate_blue;
            rate_blue = (240.0 - h) / 100.0;
            final_temprature = h + rate_blue * value_temperature;
            double rate_green;
            rate_green = (120.0 - h) / 100.0;
            final_tone = h + rate_green * value_tone;
        } else {
            double rate_yellow;
            rate_yellow = (60.0 - h) / 100.0;
            final_temprature = h + rate_yellow * value_temperature;
            double rate_purple;
            rate_purple = (300.0 - h) / 100.0;
            final_tone = h + rate_purple * value_tone;
        }
        //现在将两个值加成一个
        double final_h;
        final_h = (final_temprature * abs(value_temperature) +
                   final_tone * abs(value_tone)) /
                  (abs(value_temperature) + abs(value_tone));
        if (final_h > 360)
            final_h -= 360;
        h = int(final_h);
    }
}
void Processing::HSV::highlight_change(int value) {
    int v_min;
    int final_s;
    v_min = 255 - abs(value);
    v = (2 * value * v * v / (255 * 255)) + v;
    if (v < 0)
        v = 0;
    if (v > 255)
        v = 255;
}
void Processing::HSV::shadow_change(int value) {
    int v_max;
    int final_s;
    v_max = abs(value);
    v = -(value * 255 / (v)) + v;
    if (v < 0)
        v = 0;
    if (v > 255)
        v = 255;
}
void Processing::HSV::white_black(int value_white, int value_black) {
    int value_final;
    value_final = value_white - value_black;
    v += value_final;
    if (v > 255)
        v = 255;
    if (v < 0)
        v = 0;
}
void Processing::BGR::exposure_contrast(int value_exposure,
                                        int value_contrast) {
    double exposure_ratio;
    exposure_ratio = 1 + double(value_exposure) / 100.0;
    b = b * exposure_ratio + value_contrast;
    g = g * exposure_ratio + value_contrast;
    r = r * exposure_ratio + value_contrast;
    if (b < 0)
        b = 0;
    if (g < 0)
        g = 0;
    if (r < 0)
        r = 0;
    if (b > 255)
        b = 255;
    if (g > 255)
        g = 255;
    if (r > 255)
        r = 255;
}
Mat Processing::text_add(Mat image, String text, int text_x, int text_y,
                         int text_line, int text_size, int r_text, int g_text,
                         int b_text) {
    Mat final_image;
    cv::putText(image, text, Point(text_x, text_y), cv::FONT_HERSHEY_COMPLEX,
                text_size, cv::Scalar(r_text, g_text, b_text), text_line);
    final_image = image.clone();
    return final_image;
}
Mat Processing::logo_add(Mat image, Mat logo, int logo_x, int logo_y) {
    if (logo.empty())
        return image;
    bool condition1 = (logo.cols + logo_x) > image.cols;
    bool condition2 = (logo.rows + logo_y) > image.rows;
    if (condition1 || condition2)
        return image; //判定失败
    int a = 0;
    int b = 0;
    for (int x = logo_x + 1; logo_x < x && x < (logo_x + logo.cols); x++, a++) {
        b = 0;
        for (int y = logo_y + 1; logo_y < y && y < (logo_y + logo.rows);
             y++, b++) {
            // int b = logo.ptr<Vec3b>(y)[x][0];
            // int g = logo.ptr<Vec3b>(y)[x][1];
            // int r = logo.ptr<Vec3b>(y)[x][2];
            if (1) {
                image.ptr<Vec3b>(y)[x][0] = logo.ptr<Vec3b>(b)[a][0];
                image.ptr<Vec3b>(y)[x][1] = logo.ptr<Vec3b>(b)[a][1];
                image.ptr<Vec3b>(y)[x][2] = logo.ptr<Vec3b>(b)[a][2];
            }
        }
    }
    return image;
}
Mat Processing::Qstring_Mat(QString Qimage) {
    string s;
    s = Qimage.toStdString();
    Mat final_mat;
    final_mat = imread(s);
    return final_mat;
} //没有问题
QImage Processing::LabelDisplayMat(Mat &mat) {
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if (mat.type() == CV_8UC1) {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for (int i = 0; i < 256; i++) {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for (int row = 0; row < mat.rows; row++) {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if (mat.type() == CV_8UC3) {
        // Copy input Mat
        const uchar *pSrc = (const uchar *)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    } else if (mat.type() == CV_8UC4) {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar *)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    } else {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}