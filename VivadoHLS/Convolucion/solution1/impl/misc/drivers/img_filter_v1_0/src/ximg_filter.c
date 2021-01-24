// ==============================================================
// File generated on Tue Dec 15 12:01:56 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "ximg_filter.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XImg_filter_CfgInitialize(XImg_filter *InstancePtr, XImg_filter_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_bus_BaseAddress = ConfigPtr->Control_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XImg_filter_Start(XImg_filter *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL) & 0x80;
    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XImg_filter_IsDone(XImg_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XImg_filter_IsIdle(XImg_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XImg_filter_IsReady(XImg_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XImg_filter_EnableAutoRestart(XImg_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL, 0x80);
}

void XImg_filter_DisableAutoRestart(XImg_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_AP_CTRL, 0);
}

void XImg_filter_InterruptGlobalEnable(XImg_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_GIE, 1);
}

void XImg_filter_InterruptGlobalDisable(XImg_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_GIE, 0);
}

void XImg_filter_InterruptEnable(XImg_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_IER);
    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_IER, Register | Mask);
}

void XImg_filter_InterruptDisable(XImg_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_IER);
    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_IER, Register & (~Mask));
}

void XImg_filter_InterruptClear(XImg_filter *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImg_filter_WriteReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_ISR, Mask);
}

u32 XImg_filter_InterruptGetEnabled(XImg_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_IER);
}

u32 XImg_filter_InterruptGetStatus(XImg_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImg_filter_ReadReg(InstancePtr->Control_bus_BaseAddress, XIMG_FILTER_CONTROL_BUS_ADDR_ISR);
}

