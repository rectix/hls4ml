//Numpy array shape [4, 4]
//Min -0.888412322024
//Max 0.899158047518
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {-0.615292, 0.477647, -0.405121, 0.523746, -0.743993, -0.115643, -0.517081, 0.899158, -0.707972, 0.433007, 0.430168, 0.531208, -0.401553, -0.449230, 0.280552, -0.888412};
#endif

#endif
