//Numpy array shape [8]
//Min -0.091409188558
//Max 0.070832211212
//Number of zeros 0

#ifndef CORE_EDGE_B1_H_
#define CORE_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_edge_b1[8];
#else
ap_fixed<16,6> core_edge_b1[8] = {-0.091409, 0.040113, 0.070832, -0.008732, 0.012578, -0.004646, 0.003015, 0.060709};
#endif

#endif
