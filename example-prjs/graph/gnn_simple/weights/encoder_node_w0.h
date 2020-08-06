//Numpy array shape [3, 4]
//Min -0.969749419487
//Max 0.533292394601
//Number of zeros 0

#ifndef ENCODER_NODE_W0_H_
#define ENCODER_NODE_W0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w0[12];
#else
ap_fixed<16,6> encoder_node_w0[12] = {0.321016, 0.044012, -0.163783, 0.206972, 0.533292, 0.081119, -0.149513, -0.428163, -0.650279, -0.969749, 0.524720, 0.255770};
#endif

#endif
