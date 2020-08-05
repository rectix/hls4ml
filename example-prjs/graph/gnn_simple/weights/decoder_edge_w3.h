//Numpy array shape [4, 1]
//Min -0.846597736333
//Max 0.750111027925
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {0.272592, -0.512854, -0.846598, 0.750111};
#endif

#endif
