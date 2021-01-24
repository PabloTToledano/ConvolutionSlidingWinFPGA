// ==============================================================
// File generated on Tue Dec 15 12:01:56 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XIMG_FILTER_H
#define XIMG_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "ximg_filter_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_bus_BaseAddress;
} XImg_filter_Config;
#endif

typedef struct {
    u32 Control_bus_BaseAddress;
    u32 IsReady;
} XImg_filter;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XImg_filter_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XImg_filter_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XImg_filter_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XImg_filter_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XImg_filter_Initialize(XImg_filter *InstancePtr, u16 DeviceId);
XImg_filter_Config* XImg_filter_LookupConfig(u16 DeviceId);
int XImg_filter_CfgInitialize(XImg_filter *InstancePtr, XImg_filter_Config *ConfigPtr);
#else
int XImg_filter_Initialize(XImg_filter *InstancePtr, const char* InstanceName);
int XImg_filter_Release(XImg_filter *InstancePtr);
#endif

void XImg_filter_Start(XImg_filter *InstancePtr);
u32 XImg_filter_IsDone(XImg_filter *InstancePtr);
u32 XImg_filter_IsIdle(XImg_filter *InstancePtr);
u32 XImg_filter_IsReady(XImg_filter *InstancePtr);
void XImg_filter_EnableAutoRestart(XImg_filter *InstancePtr);
void XImg_filter_DisableAutoRestart(XImg_filter *InstancePtr);


void XImg_filter_InterruptGlobalEnable(XImg_filter *InstancePtr);
void XImg_filter_InterruptGlobalDisable(XImg_filter *InstancePtr);
void XImg_filter_InterruptEnable(XImg_filter *InstancePtr, u32 Mask);
void XImg_filter_InterruptDisable(XImg_filter *InstancePtr, u32 Mask);
void XImg_filter_InterruptClear(XImg_filter *InstancePtr, u32 Mask);
u32 XImg_filter_InterruptGetEnabled(XImg_filter *InstancePtr);
u32 XImg_filter_InterruptGetStatus(XImg_filter *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
