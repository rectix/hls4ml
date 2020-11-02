//Numpy array shape [4, 4]
//Min -0.920279009001
//Max 0.859458612747
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> encoder_node_w1[16];
#else
ap_fixed<12,6> encoder_node_w1[16] = {0.338585, -0.730187, -0.241376, -0.565159, 0.518411, -0.710157, 0.144454, 0.859459, -0.444162, -0.473569, -0.050193, -0.175845, 0.821191, -0.082314, -0.466547, -0.920279};
#endif

#endif
