############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project gnn_simple_22
set_top myproject
add_files ../myproject.cpp
add_files ../myproject.h
add_files ../nnet_activation.h
add_files ../nnet_batchnorm.h
add_files ../nnet_common.h
add_files ../nnet_conv.h
add_files ../nnet_conv2d.h
add_files ../nnet_dense.h
add_files ../nnet_dense_large.h
add_files ../nnet_graph.h
add_files ../nnet_helpers.h
add_files ../nnet_merge.h
add_files ../nnet_pooling.h
add_files ../parameters.h
add_files -tb ../myproject_test.cpp
open_solution "solution1"
set_part {xc7k160tfbg484-2} -tool vivado
create_clock -period 10 -name default
#source "./gnn_simple_22/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
