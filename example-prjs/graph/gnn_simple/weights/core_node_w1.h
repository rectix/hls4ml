//Numpy array shape [4, 4]
//Min -0.893029485455
//Max 0.758100477326
//Number of zeros 0

#ifndef CORE_NODE_W1_H_
#define CORE_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_node_w1[16];
#else
ap_fixed<16,6> core_node_w1[16] = {0.344516, 0.316506, 0.758100, 0.039221, -0.893029, 0.559517, -0.563963, 0.028091, 0.432336, -0.035460, -0.791384, 0.097947, -0.031618, -0.711599, 0.194014, -0.259064};
#endif

#endif
