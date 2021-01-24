############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_stream -depth 640 -dim 2 "img_filter" line_buffer
set_directive_pipeline "img_filter/Buffer_padding"
set_directive_pipeline "img_filter/conv_windows_padding"
set_directive_pipeline "img_filter/convolution2"
set_directive_pipeline "img_filter/wind_data_move1"
set_directive_array_partition -type cyclic -factor 3 -dim 1 "img_filter" conv_window
set_directive_pipeline "img_filter/convolution"
set_directive_pipeline "img_filter/convolution_rows"
set_directive_pipeline "img_filter/wind_data_move"
