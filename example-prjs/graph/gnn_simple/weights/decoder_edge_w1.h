//Numpy array shape [4, 4]
//Min -0.896825600700
//Max 0.757399072417
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {0.098544, 0.088351, -0.896826, 0.481614, 0.625345, 0.557937, -0.425027, 0.128828, -0.775598, 0.037501, -0.620946, -0.065471, -0.496333, 0.121232, 0.757399, -0.152553};
#endif

#endif
