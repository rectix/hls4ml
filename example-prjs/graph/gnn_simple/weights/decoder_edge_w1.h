//Numpy array shape [4, 4]
//Min -0.970139865871
//Max 0.610048449208
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {-0.532163, -0.627924, -0.588049, 0.528605, 0.002999, 0.347636, 0.317730, 0.357072, -0.970140, -0.266443, 0.486911, -0.000654, -0.160214, 0.610048, -0.722423, 0.103844};
#endif

#endif
