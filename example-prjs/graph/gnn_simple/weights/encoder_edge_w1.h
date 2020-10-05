//Numpy array shape [8, 8]
//Min -0.984308001981
//Max 1.003553239633
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[64];
#else
ap_fixed<16,6> encoder_edge_w1[64] = {0.189074, 0.139285, -0.544377, 0.238466, -0.155597, -0.554422, 0.497722, -0.683018, -0.555374, -0.402442, 0.337105, 0.904871, 0.871038, 0.435499, 0.849144, 0.229973, -0.457128, -0.760521, 0.125105, 0.248207, 0.475078, 0.544020, 0.604449, 0.546885, 0.088710, -0.404488, 0.697595, 0.346970, 0.283394, 0.444391, -0.065639, 0.780363, -0.191848, -0.799886, 0.269293, 0.844605, 0.688139, 0.093984, 0.350284, 0.513675, -0.419982, 0.296655, 0.243704, -0.568565, -0.076155, -0.643567, -0.607712, -0.984308, -0.329204, -0.535165, 0.044551, 0.231733, 0.793692, 0.358574, 0.333718, 0.756257, -0.228493, -0.891957, 0.140434, 0.280687, 1.003553, 0.739967, 0.267939, 0.619662};
#endif

#endif
