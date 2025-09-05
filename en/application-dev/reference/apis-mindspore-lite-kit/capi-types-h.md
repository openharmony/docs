# types.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Provides the model file types and device types supported by MindSpore Lite.

**File to include**: <mindspore/types.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) | NNRTDeviceDesc | Defines NNRt device information, including the device ID and device name.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AI_ModelType](#oh_ai_modeltype) | OH_AI_ModelType | Defines model file types.|
| [OH_AI_DeviceType](#oh_ai_devicetype) | OH_AI_DeviceType | Defines supported device types.|
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) | OH_AI_NNRTDeviceType | Defines NNRt device types.|
| [OH_AI_PerformanceMode](#oh_ai_performancemode) | OH_AI_PerformanceMode | Defines performance modes of the NNRt device.|
| [OH_AI_Priority](#oh_ai_priority) | OH_AI_Priority | Defines NNRt inference task priorities.|
| [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) | OH_AI_OptimizationLevel | Defines training optimization levels.|
| [OH_AI_QuantizationType](#oh_ai_quantizationtype) | OH_AI_QuantizationType | Defines quantization types.|

## Enum Description

### OH_AI_ModelType

```
enum OH_AI_ModelType
```

**Description**

Defines model file types.

**Since**: 9

| Enum Item| Description                                       |
| -- |-------------------------------------------|
| OH_AI_MODELTYPE_MINDIR = 0 | Model type of MindIR. The extension of the model file name is **.ms**.|
| OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF | Invalid model type. |

### OH_AI_DeviceType

```
enum OH_AI_DeviceType
```

**Description**

Defines the supported device types.

**Since**: 9

| Enum Item| Description|
| -- | -- |
| OH_AI_DEVICETYPE_CPU = 0 | Device type: CPU.|
| OH_AI_DEVICETYPE_GPU | Device type: GPU (reserved).|
| OH_AI_DEVICETYPE_KIRIN_NPU | Device type: Kirin NPU (reserved).|
| OH_AI_DEVICETYPE_NNRT = 60 | Device type: NNRt|
| OH_AI_DEVICETYPE_INVALID = 100 | Invalid device type.|

### OH_AI_NNRTDeviceType

```
enum OH_AI_NNRTDeviceType
```

**Description**

Defines NNRt device types.

**Since**: 10

| Enum Item| Description                                |
| -- |------------------------------------|
| OH_AI_NNRTDEVICE_OTHERS = 0 | Others (any device type except the following three types).|
| OH_AI_NNRTDEVICE_CPU = 1 | CPU.                |
| OH_AI_NNRTDEVICE_GPU = 2 | GPU.              |
| OH_AI_NNRTDEVICE_ACCELERATOR = 3 | Specific acceleration device.     |

### OH_AI_PerformanceMode

```
enum OH_AI_PerformanceMode
```

**Description**

Defines performance modes of the NNRt device.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_AI_PERFORMANCE_NONE = 0 | No special settings.|
| OH_AI_PERFORMANCE_LOW = 1 | Low power consumption.|
| OH_AI_PERFORMANCE_MEDIUM = 2 | Power consumption and performance balancing.|
| OH_AI_PERFORMANCE_HIGH = 3 | High performance.|
| OH_AI_PERFORMANCE_EXTREME = 4 | Ultimate performance.|

### OH_AI_Priority

```
enum OH_AI_Priority
```

**Description**

Defines NNRt inference task priorities.

**Since**: 10

| Enum Item| Description         |
| -- |-------------|
| OH_AI_PRIORITY_NONE = 0 | No priority preference.|
| OH_AI_PRIORITY_LOW = 1 | Low priority.    |
| OH_AI_PRIORITY_MEDIUM = 2 | Medium priority.    |
| OH_AI_PRIORITY_HIGH = 3 | High priority.      |

### OH_AI_OptimizationLevel

```
enum OH_AI_OptimizationLevel
```

**Description**

Defines training optimization levels.

**Since**: 11

| Enum Item| Description                                  |
| -- |--------------------------------------|
| OH_AI_KO0 = 0 | No optimization level.             |
| OH_AI_KO2 = 2 | Converts the precision type of the network to float16 and keeps the precision type of the batch normalization layer and loss function as float32.|
| OH_AI_KO3 = 3 | Converts the precision type of the network (including the batch normalization layer) to float16.    |
| OH_AI_KAUTO = 4 | Selects an optimization level based on the device.   |
| OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF | Invalid optimization level.    |

### OH_AI_QuantizationType

```
enum OH_AI_QuantizationType
```

**Description**

Defines quantization types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| OH_AI_NO_QUANT = 0 | No quantification.|
| OH_AI_WEIGHT_QUANT = 1 | Weight quantization.|
| OH_AI_FULL_QUANT = 2 | Full quantization.|
| OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF | Invalid quantization type.|
