//Numpy array shape [4, 4]
//Min -0.563401105183
//Max 0.950352565097
//Number of zeros 0

#ifndef DECODER_EDGE_W0_H_
#define DECODER_EDGE_W0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w0[16];
#else
ap_fixed<16,6> decoder_edge_w0[16] = {0.182129, 0.460513, -0.552095, 0.407346, -0.563401, 0.195808, -0.281366, 0.100040, 0.950353, 0.201082, 0.822796, -0.470660, 0.438414, 0.766177, -0.534115, -0.227172};
#endif

#endif
