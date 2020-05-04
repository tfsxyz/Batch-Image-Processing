#include "processing.hpp"
using namespace std;
using namespace cv;
// int main(int argc, char *argv[]) {
//     //    cout << "succcessful"<<endl;
//     Mat blue;
//     blue = imread("/home/xyz/work/Batch_image_processing/processing/build/"
//                   "d043ad4bd11373f0d52ed2eeab0f4bfbfbed04a9.png");
//     Parameter test_all;
//     test_all.temperatur_color = -50;
//     test_all.tone = -90;
//     test_all.black = 20;
//     test_all.white = 50;
//     test_all.highlight = 20;
//     test_all.shadow = 15;
//     test_all.contrast = 20;
//     test_all.contrast = 25;
//     test_all.sharpness = 10;
//     Processing test_processing;
//     cout << "s" << endl;
//     blue = test_processing.processing_mat(blue, test_all);
//     namedWindow("blue_after", CV_WINDOW_FREERATIO);
//     imshow("blue_after", blue);
//     Parameter test_sharpness;
//     test_sharpness.sharpness = 1;
//     Mat dva;
//     dva = imread("/home/xyz/work/Batch_image_processing/processing/build/"
//                  "0748c987e950352a19f857195943fbf2b3118b46.jpg");
//     namedWindow("dva", CV_WINDOW_FREERATIO);
//     imshow("dva", dva);
//     waitKey(0);
//     dva = test_processing.sharpness_soft(dva, 40,-50).clone();
//     namedWindow("dva2", CV_WINDOW_FREERATIO);
//     imshow("dva2", dva);
//     waitKey(0);
//     // Processing::BGR bgr_test;
//     // bgr_test.bgr(210,0.8,1);
//     // cout << bgr_test.b<<endl;
//     // cout <<bgr_test.g<<endl;
//     // cout <<bgr_test.r<<endl;
// }