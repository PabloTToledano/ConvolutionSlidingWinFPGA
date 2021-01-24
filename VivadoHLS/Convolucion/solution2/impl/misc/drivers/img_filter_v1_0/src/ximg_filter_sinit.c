// ==============================================================
// File generated on Fri Jan 01 19:20:20 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "ximg_filter.h"

extern XImg_filter_Config XImg_filter_ConfigTable[];

XImg_filter_Config *XImg_filter_LookupConfig(u16 DeviceId) {
	XImg_filter_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XIMG_FILTER_NUM_INSTANCES; Index++) {
		if (XImg_filter_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XImg_filter_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XImg_filter_Initialize(XImg_filter *InstancePtr, u16 DeviceId) {
	XImg_filter_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XImg_filter_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XImg_filter_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

