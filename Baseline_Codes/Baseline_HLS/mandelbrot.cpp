#include "mandelbrot.h"

void mandel(int out[1920*1080], Config& config) {
	for (int i = 0; i < config.img_height; i++) {
	  for (int j = 0; j < config.img_width; j++) {
		int x = 0.0;
		int y = 0.0;
		int iteration = 0;
		int max_iteration = 1000;
		double xrange = config.maxR - config.minR;
		double yrange = config.maxI - config.minI;
		double x_c = (x * (xrange / config.img_width) + config.minR);
		double y_c = (y * (yrange / config.img_height) + config.minI);
		while (x*x + y*y <= 4 && iteration < max_iteration) {
		  float xtemp = x*x - y*y + x_c;
		  y = 2 * x*y + y_c;
		  x = xtemp;
		  iteration = iteration + 1;
		}
		if (iteration == max_iteration) {
		  // This point is in the Mandelbrot set as it did not escape so its colour is black
		  out[i*config.img_width+j]     = 0; // black colour
		} else {
		  // This point is not in the Mandelbrot set as it escaped
		  // So its colour is based on how quickly it escaped
		  out[i*config.img_width+j]  = 256-iteration%256;
		}
	  }
	}
}
