//Numpy array shape [4]
//Min -0.007564189638
//Max 0.258497324975
//Number of zeros 0

#ifndef ENCODER_EDGE_B0_H_
#define ENCODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> encoder_edge_b0[4];
#else
ap_fixed<12,6> encoder_edge_b0[4] = {0.205708, 0.258497, 0.125076, -0.007564};
#endif

#endif
