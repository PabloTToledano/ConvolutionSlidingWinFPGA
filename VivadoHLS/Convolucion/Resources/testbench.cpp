#include "hls_opencv.h"
#include "hls_video.h"
#include "img_filter.h"
#include <assert.h>

using namespace cv;

void img_filter_sw(Mat& src_IMG,Mat& out_IMG){

	Mat kernel = (Mat_<double>(3,3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
	filter2D(src_IMG,out_IMG,-1, kernel);

}

int main (int argc, char** argv)
{

	AXI_STREAM INPUT_axi,OUTPUT_axi;


    //Lectura de la imagen (formato RGB)
    Mat src_IMG = imread(INPUT_IMAGE,CV_LOAD_IMAGE_COLOR);
    Mat dstSW_IMG(src_IMG.rows, src_IMG.cols, CV_8UC3);
    //Mat->AXI STREAM. Transformación del tipo de datos. El IP
    //recibe los datos de la imagen en formato RGB (24 bits)
    cvMat2AXIvideo(src_IMG, INPUT_axi);

	//Función top
	img_filter(INPUT_axi,OUTPUT_axi);

	Mat dstHW_IMG(src_IMG.rows, src_IMG.cols, CV_8UC3);

	AXIvideo2cvMat(OUTPUT_axi,dstHW_IMG);
	img_filter_sw(src_IMG,dstSW_IMG);
    imshow("Software version", dstSW_IMG);
    imshow("Hardware version", dstHW_IMG);
    int k = waitKey(0); // Wait for a keystroke in the window
	imwrite(OUTPUT_IMAGE,dstHW_IMG);
	imwrite("./carsoft.bmp",dstSW_IMG);
	int mecagoentodo = 0;
	for (int row = 1; row < ROWS-1; row++) {
		for (int col = 1; col < COLS-1; col++) {
			if(dstHW_IMG.at<uint8_t>(row*ROWS+col) == dstSW_IMG.at<uint8_t>(row*ROWS+col)){
				mecagoentodo++;
			}
		}
	}
	printf("Todo mal: %d",mecagoentodo);
    return 0;
}

