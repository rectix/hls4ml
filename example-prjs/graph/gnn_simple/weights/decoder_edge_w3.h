//Numpy array shape [1, 4]
//Min -0.849675628749
//Max 0.450269900158
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {-0.849676, -0.397978, 0.450270, -0.033313};
#endif

#endif
