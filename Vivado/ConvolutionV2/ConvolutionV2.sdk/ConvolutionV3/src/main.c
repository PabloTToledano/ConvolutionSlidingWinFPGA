
/*
 * Vivado convolution example
 */

#define NUM_TESTS 5

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xstatus.h"
#include "xparameters.h"
#include "xtmrctr.h"
#include "xaxidma.h"
#include "lib_ximg_filter_hw.h"

#include "ff.h"
#define BYTES 921654

static FATFS fat_fs;
u8  __attribute__ ((aligned (4))) data[BYTES];
u8 __attribute__ ((aligned (4))) data_in_hw[BYTES-54];
u8 __attribute__ ((aligned (4))) data_out_hw[BYTES-54];

// TIMER Instance
XTmrCtr timer_dev;

// AXI DMA Instance
XAxiDma AxiDma;

u32 mount_filesystem() {
	TCHAR *Path = "0:/";
	FRESULT res;
	res = f_mount(&fat_fs, Path, 1);

	if (res != FR_OK) {
		xil_printf("mount failed %d\n\r",res);
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

u32 umount_filesystem() {
	TCHAR *Path = "0:/";
	FRESULT res;
	res = f_mount(NULL, Path, 0);

	if (res != FR_OK) {
		xil_printf("umount failed %d\n\r",res);
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

u32 write_img () { FIL fp;
	u32 bytes_write = 0;
	FRESULT res = f_open(&fp,
			"sobel.bmp", FA_WRITE | FA_CREATE_ALWAYS);
	if (res != FR_OK) {
		xil_printf("[WRITE] could not open the file %d\n\r", res);
		return XST_FAILURE; }
	res =  f_write(&fp, data, BYTES, &bytes_write);
	f_close(&fp); printf("Bytes Write: %d\n", bytes_write);
	if (umount_filesystem() == XST_FAILURE) {
		return XST_FAILURE; }
	return XST_SUCCESS;
}

u32 LoadFile(){
	FIL fp;
	u32 bytes_read = 0;


	if (mount_filesystem() == XST_FAILURE)
		return XST_FAILURE;

	FRESULT res = f_open(&fp, "car.bmp", FA_READ);

	if (res != FR_OK) {
		xil_printf("could not open the file %d\n\r",res);
		return XST_FAILURE;
	}

	f_read(&fp, data, BYTES, &bytes_read);
	f_close(&fp);
	printf("Bytes Read %d\r\n",bytes_read);


	return XST_SUCCESS;
}

int init_dma(){
	XAxiDma_Config *CfgPtr;
	int status;

	CfgPtr = XAxiDma_LookupConfig( (XPAR_AXI_DMA_0_DEVICE_ID) );
	if(!CfgPtr){
		print("Error looking for AXI DMA config\n\r");
		return XST_FAILURE;
	}
	status = XAxiDma_CfgInitialize(&AxiDma,CfgPtr);
	if(status != XST_SUCCESS){
		print("Error initializing DMA\n\r");
		return XST_FAILURE;
	}
	//check for scatter gather mode
	if(XAxiDma_HasSg(&AxiDma)){
		print("Error DMA configured in SG mode\n\r");
		return XST_FAILURE;
	}
	/* Disable interrupts, we use polling mode */
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

	// Reset DMA
	XAxiDma_Reset(&AxiDma);
	while (!XAxiDma_ResetIsDone(&AxiDma)) {}

	return XST_SUCCESS;
}

int main()
{
	int status;
	unsigned int dma_size =  BYTES-54;
    init_platform();
    int init_time, curr_time, calibration, run_time_hw;
    int begin_time, end_time;
	printf("***************************************************************\r\n");
	printf("                     CONVOLUTION FPGA                          \r\n");
	printf("***************************************************************\r\n");

	status = init_dma();
	if(status != XST_SUCCESS){
		print("\rError: DMA init failed\n");
		return XST_FAILURE;
	}
	print("\nDMA Init done\n");

	/* ******************************************************************************* */
	// Setup HW timer
	status = XTmrCtr_Initialize(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	if(status != XST_SUCCESS)
	{
		print("Error: timer setup failed\n");
		//return XST_FAILURE;
	}
	XTmrCtr_SetOptions(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID, XTC_ENABLE_ALL_OPTION);

	// Calibrate HW timer
	XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	init_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	curr_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	calibration = curr_time - init_time;

    LoadFile();
    memcpy(data_in_hw,&data[53],BYTES-54);
    printf("Data read\n\r");

    // call the HW accelerator
    XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
    begin_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);

    // Setup the HW Accelerator
    printf("Accelerator Start\n\r");
    status = Start_HW_Accelerator(); //Just once
    printf("Accelerator has started\n\r");

    //flush the cache. You have to do this every time data is changed
    Xil_DCacheFlushRange((UINTPTR)data_in_hw,dma_size);
    Xil_DCacheFlushRange((UINTPTR)data_out_hw,dma_size);
    printf("Accelerator run\n\r");
    Run_HW_Accelerator(data_in_hw, data_out_hw, dma_size);
    printf("Accelerator done\n\r");
	end_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	run_time_hw = end_time - begin_time - calibration;
	Xil_DCacheInvalidateRange((UINTPTR)data_out_hw,dma_size);
    print("\rCache cleared\n\r");

    printf("\rHW Time: %d\n\r",run_time_hw);
    memcpy(&data[53],data_out_hw,BYTES-54);
    write_img();

    cleanup_platform();
    return 0;
}
