//Numpy array shape [4, 4]
//Min -0.764762350924
//Max 0.740388713982
//Number of zeros 0

#ifndef CORE_NODE_W1_H_
#define CORE_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_node_w1[16];
#else
ap_fixed<16,6> core_node_w1[16] = {-0.764762, -0.436160, -0.237526, 0.740389, -0.225788, -0.390131, -0.475001, -0.615550, 0.101355, -0.447044, 0.737675, 0.207309, 0.601678, 0.138193, 0.234556, -0.228478};
#endif

#endif
