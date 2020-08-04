//Numpy array shape [4, 1]
//Min -0.253362345820
//Max 0.790052141771
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {0.790052, -0.065157, 0.099850, -0.253362};
#endif

#endif
