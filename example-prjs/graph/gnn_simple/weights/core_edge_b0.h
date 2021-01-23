//Numpy array shape [8]
//Min -0.004614780534
//Max 0.210022208123
//Number of zeros 0

#ifndef CORE_EDGE_B0_H_
#define CORE_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_edge_b0[8];
#else
ap_fixed<16,6> core_edge_b0[8] = {0.141928, 0.210022, -0.004615, 0.075535, 0.129083, -0.000700, 0.003403, 0.081226};
#endif

#endif
