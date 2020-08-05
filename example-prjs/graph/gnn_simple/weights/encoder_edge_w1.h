//Numpy array shape [4, 4]
//Min -0.910214664859
//Max 0.619170328941
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {0.007137, 0.573752, 0.262280, -0.561320, -0.223562, -0.510328, 0.619170, -0.178165, 0.222662, -0.108254, -0.533856, -0.910215, -0.354501, -0.345676, -0.257947, 0.160859};
#endif

#endif
