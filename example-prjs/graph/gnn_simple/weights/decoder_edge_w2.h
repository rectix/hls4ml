//Numpy array shape [4, 4]
//Min -0.790122097561
//Max 0.917770764903
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {0.044602, 0.135194, 0.489383, 0.246268, -0.217704, -0.222629, 0.606750, -0.475064, -0.195005, 0.917771, -0.240387, 0.516337, -0.790122, -0.065392, 0.432547, 0.281664};
#endif

#endif
