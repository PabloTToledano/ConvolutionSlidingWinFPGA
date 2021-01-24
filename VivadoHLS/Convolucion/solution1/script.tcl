############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Convolucion
set_top img_filter
add_files Convolucion/Resources/car.bmp
add_files Convolucion/Resources/img_filter.h
add_files Convolucion/Resources/top.cpp
add_files -tb Convolucion/Resources/testbench.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
source "./Convolucion/solution1/directives.tcl"
csim_design -clean
csynth_design
cosim_design -O
export_design -rtl verilog -format ip_catalog
