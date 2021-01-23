//Numpy array shape [1, 8]
//Min -0.666646801183
//Max 1.424230233567
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[8];
#else
ap_fixed<16,6> decoder_edge_w3[8] = {1.424230, -0.298240, 0.866225, -0.495760, -0.666647, 0.756322, 1.212669, 0.546960};
#endif

#endif
