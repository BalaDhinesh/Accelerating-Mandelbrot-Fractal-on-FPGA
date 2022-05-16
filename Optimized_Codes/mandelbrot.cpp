#include "mandelbrot.h"

void dut(hls::stream<int> out[M], Config& config) {
//void dut(int out[M], Config& config) {
#pragma HLS INTERFACE s_axilite port=config
#pragma HLS INTERFACE axis port=out
#pragma HLS INTERFACE s_axilite port=return

#pragma HLS pipeline II=38
#pragma HLS DEPENDENCE variable=out type=inter false

double x_scaled, y_scaled, x, y;
int iteration, i, j;
bool iterate;

	for (i = 0; i < config.img_width; i++) {
		  #pragma HLS unroll skip_exit_check factor=4
		  for (j = 0; j < config.img_height; j++) {
			#pragma HLS unroll skip_exit_check factor=4
			x_scaled = config.plot_x_min + (double)i / (double)config.img_height * config.plot_height;
			y_scaled = config.plot_y_max - (double)j / (double)config.img_width * config.plot_width;
			x = 0.0;
			y = 0.0;
			iteration = 0;
			iterate = false;
			do {
				#pragma HLS unroll skip_exit_check factor=4
			    double temp = x*x - y*y + x_scaled;
			    y = 2*x*y + y_scaled;
			    x = temp;
			    iteration = iteration + 1;
			    iterate = x*x + y*y < 4 && iteration < config.max_iteration;
			}while (iterate);

			if (iteration == 100) {
				// This point is in the Mandelbrot set as it did not escape so its colour is black
				out[0].write(0); // black colour
				//out[0] = 0; //black colour
			}
			else {
				// This point is not in the Mandelbrot set as it escaped
			    // So its colour is based on how quickly it escaped
			    out[0].write(256-iteration%256);
			    //out[0] = 256-iteration%256;
			    }
		  }
		}
}


