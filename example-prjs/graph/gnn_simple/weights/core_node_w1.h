//Numpy array shape [4, 4]
//Min -0.702108887463
//Max 0.742771341899
//Number of zeros 0

#ifndef CORE_NODE_W1_H_
#define CORE_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_node_w1[16];
#else
ap_fixed<16,6> core_node_w1[16] = {0.742771, 0.205658, 0.635551, 0.221627, -0.702109, -0.192478, 0.219004, 0.099683, -0.680494, 0.014763, -0.093152, -0.255423, -0.358228, -0.463993, 0.296441, -0.291204};
#endif

#endif
