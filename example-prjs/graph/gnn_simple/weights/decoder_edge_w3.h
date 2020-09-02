//Numpy array shape [4, 1]
//Min -0.396985014597
//Max 0.536917573453
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {0.094945, 0.536918, -0.133876, -0.396985};
#endif

#endif
