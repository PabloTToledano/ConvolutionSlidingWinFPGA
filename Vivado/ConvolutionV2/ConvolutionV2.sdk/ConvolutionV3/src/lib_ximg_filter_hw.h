
#ifndef H_LIB_EXAMPLE_HW_H
#define H_LIB_EXAMPLE_HW_H

#define DIM 921600
#define SIZE  921600

//int Setup_HW_Accelerator(float A[DIM][DIM], float B[DIM][DIM], float res_hw[DIM][DIM], int dma_size);

int Run_HW_Accelerator(u8 data[DIM], u8 res_hw[DIM], int dma_size);

int Start_HW_Accelerator(void);

#endif
