//Numpy array shape [4]
//Min 0.000000000000
//Max 0.000000000000
//Number of zeros 4

#ifndef CORE_EDGE_B0_H_
#define CORE_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_edge_b0[4];
#else
ap_fixed<16,6> core_edge_b0[4] = {0.000000, 0.000000, 0.000000, 0.000000};
#endif

#endif
