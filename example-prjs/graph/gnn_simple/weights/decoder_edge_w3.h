//Numpy array shape [1, 4]
//Min -3.020043196937
//Max 0.796855770364
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[4];
#else
ap_fixed<16,6> decoder_edge_w3[4] = {-0.172521, -0.794076, 0.796856, -3.020043};
#endif

#endif
