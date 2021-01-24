#include "img_filter.h"


void img_filter(AXI_STREAM& in, AXI_STREAM& out) {
	#pragma HLS INTERFACE axis      port=in
	#pragma HLS INTERFACE axis      port=out
	#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
	hls::stream<pixel_gray_t> line_buffer[KERNELROWS-1];
	ap_int<32> conv_window[KERNELROWS][KERNELCOLS];
	//const ap_int<4> kernel[KERNELROWS*KERNELCOLS] = {-1,-1,-1,-1,8,-1,-1,-1,-1};
	const ap_int<4> kernel[KERNELROWS*KERNELCOLS] = {0,1,0,1,-4,1,0,1,0};
	int row,col;
	ap_int<32> conv_result;


	//inicializacion de los buffers fifo
	Buffer_padding:for(int i=0;i< KERNELROWS-1;i++){
		for(int j=0;j< COLS-3; j++){
			line_buffer[i].write(0);
		}
	}

	//inicializacion de la ventana de convolucion
	conv_windows_padding:for(int i=0;i< KERNELROWS;i++){
		for(int j=0;j< KERNELCOLS; j++){
			conv_window[i][j] = 0;
		}
	}


	//Codigo de ejemplo. Ley del flujo de entrada y convierto RGB-->Escala de grises

	for (row = 0; row < ROWS; row++) {
		convolution:for (col = 0; col < COLS; col++) {
			pixel_rgb_t pixel_color;
			pixel_gray_t pixel_gray;
			pixel_rgb_t pixel_out;
			AXI_VAL e;

			in >> e;
			pixel_color = e.data;

			//R, G y B son macros que toman una parte de los bits
			pixel_gray = (R(pixel_color) + G(pixel_color) + B(pixel_color))/3;

			wind_data_move1:for(int i=0;i< KERNELROWS;i++){
					wind_data_move:for(int j=0;j< KERNELCOLS-1; j++){
						conv_window[i][j] = conv_window[i][j+1];
					}
					if(i != KERNELROWS-1){
						conv_window[i][KERNELCOLS-1] = line_buffer[i].read();
						line_buffer[i].write(conv_window[i+1][0]); //copio el pixel de la fila siguiente
					}


				}
				conv_window[KERNELCOLS-1][KERNELROWS-1] = pixel_gray; //nuevo pixel


			convolution1:for(int i=0;i< KERNELROWS;i++){
				convolution2:for(int j=0;j< KERNELCOLS; j++){
					conv_result = conv_result +( conv_window[i][j]*kernel[i*KERNELROWS+j]);
				}
			}
			if(conv_result>255) conv_result = 255;
			if(conv_result<0) conv_result = 0;

			pixel_out = (conv_result(7,0),conv_result(7,0),conv_result(7,0));
			out << push_stream(pixel_out, (row == (ROWS-1) && col == (COLS-1))); //envio el resultado
			conv_result = 0;
		}
	}
}

AXI_VAL push_stream(pixel_rgb_t const &v, bool last = false)
{
#pragma HLS INLINE
	AXI_VAL e;

	e.data = v;

	e.strb = -1;
	e.keep = 15; //e.strb;
	e.user = 1;
	e.last = last ? 1 : 0;
	e.id = 1;
	e.dest = 1;
	return e;
}
