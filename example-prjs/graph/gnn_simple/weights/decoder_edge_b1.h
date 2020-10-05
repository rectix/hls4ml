//Numpy array shape [8]
//Min -0.219099491359
//Max 0.227165241622
//Number of zeros 0

#ifndef DECODER_EDGE_B1_H_
#define DECODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b1[8];
#else
ap_fixed<16,6> decoder_edge_b1[8] = {0.048453, -0.219099, 0.080519, 0.104487, 0.080032, 0.227165, -0.012257, 0.045821};
#endif

#endif
