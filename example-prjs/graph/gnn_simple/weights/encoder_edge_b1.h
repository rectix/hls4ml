//Numpy array shape [8]
//Min -0.045575334516
//Max 0.218452679851
//Number of zeros 0

#ifndef ENCODER_EDGE_B1_H_
#define ENCODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b1[8];
#else
ap_fixed<16,6> encoder_edge_b1[8] = {-0.045575, 0.005791, -0.001564, -0.035313, 0.005364, 0.218453, 0.005808, 0.001280};
#endif

#endif
