//Numpy array shape [4, 4]
//Min -0.889682819960
//Max 0.927021354635
//Number of zeros 0

#ifndef CORE_NODE_W1_H_
#define CORE_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_node_w1[16];
#else
ap_fixed<16,6> core_node_w1[16] = {0.011808, -0.889683, 0.037600, 0.104225, 0.011686, 0.055800, 0.927021, 0.161125, -0.414013, 0.120202, -0.006427, 0.597417, -0.045341, -0.027273, -0.608830, 0.104864};
#endif

#endif
