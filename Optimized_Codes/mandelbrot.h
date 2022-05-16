#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <iostream>
#include "hls_stream.h"
#include "config.h"

#define M 1

void dut(hls::stream<int> s_in[M], Config& config);
//void dut(int s_in[M], Config& config);

#endif
