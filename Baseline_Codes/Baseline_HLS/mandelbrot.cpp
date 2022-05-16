#include <iostream>
#include "mandelbrot.h"
using namespace std;

void mandel(int out[1920*1080], Config& config) {
	for (int i = 0; i < config.img_width; i++) {
	  for (int j = 0; j < config.img_height; j++) {
		double x_scaled = config.plot_x_min
		        + (double)i / (double)config.img_height * config.plot_height
		    ;
		    double y_scaled = config.plot_y_max
		        - (double)j / (double)config.img_width * config.plot_width
		    ;
		    double x = 0.0;
		    double y = 0.0;
		    int iteration = 0;
		    do {
		        double temp = x*x - y*y + x_scaled;
		        y = 2*x*y + y_scaled;
		        x = temp;
		        iteration = iteration + 1;
		    }while (x*x + y*y < 4 && iteration < 1000);

		    if (iteration == 1000) {
		    		  // This point is in the Mandelbrot set as it did not escape so its colour is black
		    		  out[i*config.img_height+j]     = 0; // black colour
		    } else {
		    		  // This point is not in the Mandelbrot set as it escaped
		    		  // So its colour is based on how quickly it escaped
		    		  out[i*config.img_height+j]  = 256-iteration%256;
//		    		  cout << i*config.img_width+j << " " << 256-iteration%256 <<endl;
		    }
	        //cout << out <<endl;

	  }
	}
}