#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("in_V_data_V_dout", 24, hls_in, 0, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_data_V_empty_n", 1, hls_in, 0, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_data_V_read", 1, hls_out, 0, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_keep_V_dout", 3, hls_in, 1, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_keep_V_empty_n", 1, hls_in, 1, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_keep_V_read", 1, hls_out, 1, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_strb_V_dout", 3, hls_in, 2, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_strb_V_empty_n", 1, hls_in, 2, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_strb_V_read", 1, hls_out, 2, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_user_V_dout", 1, hls_in, 3, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_user_V_empty_n", 1, hls_in, 3, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_user_V_read", 1, hls_out, 3, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_last_V_dout", 1, hls_in, 4, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_last_V_empty_n", 1, hls_in, 4, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_last_V_read", 1, hls_out, 4, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_id_V_dout", 1, hls_in, 5, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_id_V_empty_n", 1, hls_in, 5, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_id_V_read", 1, hls_out, 5, "ap_fifo", "fifo_update", 640),
	Port_Property("in_V_dest_V_dout", 1, hls_in, 6, "ap_fifo", "fifo_data", 640),
	Port_Property("in_V_dest_V_empty_n", 1, hls_in, 6, "ap_fifo", "fifo_status", 640),
	Port_Property("in_V_dest_V_read", 1, hls_out, 6, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_data_V_din", 24, hls_out, 7, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_data_V_full_n", 1, hls_in, 7, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_data_V_write", 1, hls_out, 7, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_keep_V_din", 3, hls_out, 8, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_keep_V_full_n", 1, hls_in, 8, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_keep_V_write", 1, hls_out, 8, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_strb_V_din", 3, hls_out, 9, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_strb_V_full_n", 1, hls_in, 9, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_strb_V_write", 1, hls_out, 9, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_user_V_din", 1, hls_out, 10, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_user_V_full_n", 1, hls_in, 10, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_user_V_write", 1, hls_out, 10, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_last_V_din", 1, hls_out, 11, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_last_V_full_n", 1, hls_in, 11, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_last_V_write", 1, hls_out, 11, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_id_V_din", 1, hls_out, 12, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_id_V_full_n", 1, hls_in, 12, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_id_V_write", 1, hls_out, 12, "ap_fifo", "fifo_update", 640),
	Port_Property("out_V_dest_V_din", 1, hls_out, 13, "ap_fifo", "fifo_data", 640),
	Port_Property("out_V_dest_V_full_n", 1, hls_in, 13, "ap_fifo", "fifo_status", 640),
	Port_Property("out_V_dest_V_write", 1, hls_out, 13, "ap_fifo", "fifo_update", 640),
};
const char* HLS_Design_Meta::dut_name = "img_filter";