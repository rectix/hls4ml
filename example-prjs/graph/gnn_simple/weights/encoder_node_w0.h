//Numpy array shape [4, 3]
//Min -0.313745913653
//Max 1.028358164034
//Number of zeros 0

#ifndef ENCODER_NODE_W0_H_
#define ENCODER_NODE_W0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w0[12];
#else
ap_fixed<16,6> encoder_node_w0[12] = {0.636689, -0.270055, 1.028358, 0.999794, 0.698060, 0.468161, 0.884273, 0.225766, -0.313746, 0.185702, -0.305437, 0.080937};
#endif

#endif
