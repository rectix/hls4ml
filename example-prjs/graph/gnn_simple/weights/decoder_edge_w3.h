//Numpy array shape [4, 1]
//Min -0.346636547173
//Max 0.445123749369
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {0.445124, -0.346637, 0.006669, 0.049423};
#endif

#endif
