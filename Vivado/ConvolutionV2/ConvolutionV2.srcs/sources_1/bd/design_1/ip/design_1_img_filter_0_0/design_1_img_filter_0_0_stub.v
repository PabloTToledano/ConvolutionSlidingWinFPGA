// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
// Date        : Sat Jan  2 12:58:44 2021
// Host        : Oshiroku-Laptop running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/pablo/Documents/Empotrados/Workspace/ConvolutionV2/ConvolutionV2.srcs/sources_1/bd/design_1/ip/design_1_img_filter_0_0/design_1_img_filter_0_0_stub.v
// Design      : design_1_img_filter_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sbva484-1-i
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "img_filter,Vivado 2018.3" *)
module design_1_img_filter_0_0(s_axi_CONTROL_BUS_AWADDR, 
  s_axi_CONTROL_BUS_AWVALID, s_axi_CONTROL_BUS_AWREADY, s_axi_CONTROL_BUS_WDATA, 
  s_axi_CONTROL_BUS_WSTRB, s_axi_CONTROL_BUS_WVALID, s_axi_CONTROL_BUS_WREADY, 
  s_axi_CONTROL_BUS_BRESP, s_axi_CONTROL_BUS_BVALID, s_axi_CONTROL_BUS_BREADY, 
  s_axi_CONTROL_BUS_ARADDR, s_axi_CONTROL_BUS_ARVALID, s_axi_CONTROL_BUS_ARREADY, 
  s_axi_CONTROL_BUS_RDATA, s_axi_CONTROL_BUS_RRESP, s_axi_CONTROL_BUS_RVALID, 
  s_axi_CONTROL_BUS_RREADY, ap_clk, ap_rst_n, interrupt, in_r_TVALID, in_r_TREADY, in_r_TDATA, 
  in_r_TDEST, in_r_TKEEP, in_r_TSTRB, in_r_TUSER, in_r_TLAST, in_r_TID, out_r_TVALID, 
  out_r_TREADY, out_r_TDATA, out_r_TDEST, out_r_TKEEP, out_r_TSTRB, out_r_TUSER, out_r_TLAST, 
  out_r_TID)
/* synthesis syn_black_box black_box_pad_pin="s_axi_CONTROL_BUS_AWADDR[3:0],s_axi_CONTROL_BUS_AWVALID,s_axi_CONTROL_BUS_AWREADY,s_axi_CONTROL_BUS_WDATA[31:0],s_axi_CONTROL_BUS_WSTRB[3:0],s_axi_CONTROL_BUS_WVALID,s_axi_CONTROL_BUS_WREADY,s_axi_CONTROL_BUS_BRESP[1:0],s_axi_CONTROL_BUS_BVALID,s_axi_CONTROL_BUS_BREADY,s_axi_CONTROL_BUS_ARADDR[3:0],s_axi_CONTROL_BUS_ARVALID,s_axi_CONTROL_BUS_ARREADY,s_axi_CONTROL_BUS_RDATA[31:0],s_axi_CONTROL_BUS_RRESP[1:0],s_axi_CONTROL_BUS_RVALID,s_axi_CONTROL_BUS_RREADY,ap_clk,ap_rst_n,interrupt,in_r_TVALID,in_r_TREADY,in_r_TDATA[23:0],in_r_TDEST[0:0],in_r_TKEEP[2:0],in_r_TSTRB[2:0],in_r_TUSER[0:0],in_r_TLAST[0:0],in_r_TID[0:0],out_r_TVALID,out_r_TREADY,out_r_TDATA[23:0],out_r_TDEST[0:0],out_r_TKEEP[2:0],out_r_TSTRB[2:0],out_r_TUSER[0:0],out_r_TLAST[0:0],out_r_TID[0:0]" */;
  input [3:0]s_axi_CONTROL_BUS_AWADDR;
  input s_axi_CONTROL_BUS_AWVALID;
  output s_axi_CONTROL_BUS_AWREADY;
  input [31:0]s_axi_CONTROL_BUS_WDATA;
  input [3:0]s_axi_CONTROL_BUS_WSTRB;
  input s_axi_CONTROL_BUS_WVALID;
  output s_axi_CONTROL_BUS_WREADY;
  output [1:0]s_axi_CONTROL_BUS_BRESP;
  output s_axi_CONTROL_BUS_BVALID;
  input s_axi_CONTROL_BUS_BREADY;
  input [3:0]s_axi_CONTROL_BUS_ARADDR;
  input s_axi_CONTROL_BUS_ARVALID;
  output s_axi_CONTROL_BUS_ARREADY;
  output [31:0]s_axi_CONTROL_BUS_RDATA;
  output [1:0]s_axi_CONTROL_BUS_RRESP;
  output s_axi_CONTROL_BUS_RVALID;
  input s_axi_CONTROL_BUS_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
  input in_r_TVALID;
  output in_r_TREADY;
  input [23:0]in_r_TDATA;
  input [0:0]in_r_TDEST;
  input [2:0]in_r_TKEEP;
  input [2:0]in_r_TSTRB;
  input [0:0]in_r_TUSER;
  input [0:0]in_r_TLAST;
  input [0:0]in_r_TID;
  output out_r_TVALID;
  input out_r_TREADY;
  output [23:0]out_r_TDATA;
  output [0:0]out_r_TDEST;
  output [2:0]out_r_TKEEP;
  output [2:0]out_r_TSTRB;
  output [0:0]out_r_TUSER;
  output [0:0]out_r_TLAST;
  output [0:0]out_r_TID;
endmodule