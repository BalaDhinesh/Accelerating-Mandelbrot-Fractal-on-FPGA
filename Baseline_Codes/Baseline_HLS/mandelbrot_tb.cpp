#include <iostream>
#include "mandelbrot.h"

using namespace std;

int main () {
    Config config;
    config.img_width = 1920;
    config.img_height = 1080;
    config.minR = -1.5;
    config.maxR = 0.5;
    config.minI = -1.0;
    config.maxI = 1.0;
    config.max_iteration = 1000;

//    int iteration;
    int out[1920*1080];

    mandel(out, config);
    cout << out[0] << endl;

    return 0;
}
