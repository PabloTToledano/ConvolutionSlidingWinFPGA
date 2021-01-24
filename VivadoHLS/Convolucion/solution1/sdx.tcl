# ==============================================================
# File generated on Tue Dec 15 12:01:58 +0100 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../Resources/testbench.cpp -cflags { -Wno-unknown-pragmas}
add_files Convolucion/Resources/car.bmp
add_files Convolucion/Resources/img_filter.h
add_files Convolucion/Resources/top.cpp
set_part xczu3eg-sbva484-1-e
create_clock -name default -period 10
config_export -format=ip_catalog
config_export -rtl=verilog
set_directive_stream img_filter 
