//Numpy array shape [3, 4]
//Min -0.526736822550
//Max 1.071560382313
//Number of zeros 0

#ifndef ENCODER_NODE_W0_H_
#define ENCODER_NODE_W0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w0[12];
#else
ap_fixed<16,6> encoder_node_w0[12] = {0.140432, -0.118502, 0.118355, -0.138382, 0.905054, 0.403572, 1.071560, 0.892676, -0.526737, -0.059592, 0.469554, 0.682575};
#endif

#endif
