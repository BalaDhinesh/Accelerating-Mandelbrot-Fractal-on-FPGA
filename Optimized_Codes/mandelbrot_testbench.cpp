#include "mandelbrot.h"
#include <iostream>
using namespace std;
#include <fstream>


int main() {
	hls::stream<int> s_out[M];
	//int s_out[M];

	Config config;
	config.img_width = 1920;
	config.img_height = 1080;
	config.plot_x_min = -2.5;
	config.plot_y_max = 1.0;
	config.plot_width = 3.5;
	config.plot_height = 2.0;
	config.max_iteration = 1000;

    dut(s_out, config);

    int num_pixels = config.img_width*config.img_height;
    for (unsigned j = 0; j < num_pixels; j++) {
            cout << s_out[0].read() << endl;
    }

//    ofstream out_file;
//    out_file.open("pixel_data.txt");
//    for(int i=0; i<config.img_width; i++){
//       	for(int j=0; j<config.img_height; j++){
//       		out_file << s_out[i*config.img_height+j] << " ";
//       	}
//       	out_file << endl;
//    }
//    out_file.close();

    return 0;
}
