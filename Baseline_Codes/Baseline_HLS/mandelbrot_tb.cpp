#include <iostream>
#include "mandelbrot.h"
#include <fstream>

using namespace std;

int main () {
	Config config;
	    config.img_width = 1920;
	    config.img_height = 1080;
	    config.plot_x_min = -2.5;
	    config.plot_y_max = 1.0;
	    config.plot_width = 3.5;
	    config.plot_height = 2.0;
	    config.max_iteration = 1000;

	    ofstream out_file;
	    out_file.open("pixel_data.txt");

//    int iteration;
    int out[1920*1080];

    mandel(out, config);
    for(int i=0; i<1; i++){
    	for(int j=0; j<1080; j++){
    		out_file << out[i*1080+j] << " ";
    	}
    	out_file << endl;
    }
    // cout << i << "   "<< out[i] << endl;

    out_file.close();
    return 0;
}