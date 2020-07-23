############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project gnn_simple_22
set_top myproject
add_files weights/b1.h
add_files weights/b10.h
add_files weights/b11.h
add_files weights/b12.h
add_files weights/b2.h
add_files weights/b3.h
add_files weights/b4.h
add_files weights/b5.h
add_files weights/b6.h
add_files weights/b7.h
add_files weights/b8.h
add_files weights/b9.h
add_files myproject.cpp
add_files myproject.h
add_files nnet_activation.h
add_files nnet_batchnorm.h
add_files nnet_common.h
add_files nnet_conv.h
add_files nnet_conv2d.h
add_files nnet_dense.h
add_files nnet_dense_large.h
add_files nnet_graph.h
add_files nnet_helpers.h
add_files nnet_merge.h
add_files nnet_pooling.h
add_files parameters.h
add_files weights/w1.h
add_files weights/w10.h
add_files weights/w11.h
add_files weights/w12.h
add_files weights/w2.h
add_files weights/w3.h
add_files weights/w4.h
add_files weights/w5.h
add_files weights/w6.h
add_files weights/w7.h
add_files weights/w8.h
add_files weights/w9.h
add_files -tb myproject_test.cpp
open_solution "solution1"
set_part {xc7k160tfbg484-2} -tool vivado
create_clock -period 10 -name default
#source "./gnn_simple_22/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
