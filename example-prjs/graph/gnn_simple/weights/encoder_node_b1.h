//Numpy array shape [8]
//Min -0.034835523377
//Max 0.145436475877
//Number of zeros 0

#ifndef ENCODER_NODE_B1_H_
#define ENCODER_NODE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b1[8];
#else
ap_fixed<16,6> encoder_node_b1[8] = {-0.023697, 0.024938, 0.044935, 0.115685, -0.034836, -0.005889, 0.145436, 0.017615};
#endif

#endif
