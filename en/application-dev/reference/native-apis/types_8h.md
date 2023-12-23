# types.h


## Overview

Provides the model file types and device types supported by MindSpore Lite.

**Library**: libmindspore_lite_ndk.so

**Since**: 9

**Related module**: [MindSpore](_mind_spore.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) | Defines model file types.|
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) | Defines the supported device types.|
| [OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) | Defines NNRt device types.|
| [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) | Defines performance modes of the NNRt device.|
| [OH_AI_Priority](_mind_spore.md#oh_ai_priority) | Defines NNRt inference task priorities.|
| [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) | Defines the training optimization level.|
| [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) | Defines the quantization type.|
| [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) | Defines the NNRt device information, including the device ID and device name.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) {<br>OH_AI_MODELTYPE_MINDIR = 0,<br>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF<br>} | Model file types.|
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) {<br>OH_AI_DEVICETYPE_CPU = 0,<br>OH_AI_DEVICETYPE_GPU,<br>OH_AI_DEVICETYPE_KIRIN_NPU,<br>OH_AI_DEVICETYPE_NNRT = 60,<br>OH_AI_DEVICETYPE_INVALID = 100<br>} | Supported device types.|
| [OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) {<br>OH_AI_NNRTDEVICE_OTHERS = 0,<br>OH_AI_NNRTDEVICE_CPU = 1,<br>OH_AI_NNRTDEVICE_GPU = 2,<br>OH_AI_NNRTDEVICE_ACCELERATOR = 3<br>} | NNRt device types.|
| [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) {<br>OH_AI_PERFORMANCE_NONE = 0,<br>OH_AI_PERFORMANCE_LOW = 1,<br>OH_AI_PERFORMANCE_MEDIUM = 2,<br>OH_AI_PERFORMANCE_HIGH = 3,<br>OH_AI_PERFORMANCE_EXTREME = 4<br>} | Performance modes of the NNRt device.|
| [OH_AI_Priority](_mind_spore.md#oh_ai_priority) {<br>OH_AI_PRIORITY_NONE = 0,<br>OH_AI_PRIORITY_LOW = 1,<br>OH_AI_PRIORITY_MEDIUM = 2,<br>OH_AI_PRIORITY_HIGH = 3<br>} | NNRt inference task priorities.|
| [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) {<br>OH_AI_KO0 = 0,<br>OH_AI_KO2 = 2,<br>OH_AI_KO3 = 3,<br>OH_AI_KAUTO = 4,<br>OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF<br>} | Training optimization levels.|
| [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) {<br>OH_AI_NO_QUANT = 0,<br>OH_AI_WEIGHT_QUANT = 1,<br>OH_AI_FULL_QUANT = 2,<br>OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF } | Quantization types.|
