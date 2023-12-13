# vibrator_type.h


## 概述

为您提供标准的开放api，用于控制马达振动的启停。

**库：** libohvibrator.z.so

**系统能力：** SystemCapability.Sensors.MiscDevice

**起始版本：** 11

**相关模块：**[马达](_xe9_xa9_xac_xe8_xbe_xbe.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [Vibrator_Attribute](_vibrator___attribute.md) | struct<br/>马达属性。  | 
| [Vibrator_FileDescription](_vibrator___file_description.md) | struct<br/>振动文件描述。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode) | typedef enum [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode)<br/>为用户定义错误码。  | 
| [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage) | typedef enum [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage)<br/>振动优先级。  | 
| [Vibrator_Attribute](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_attribute) | typedef struct [Vibrator_Attribute](_vibrator___attribute.md)<br/>马达属性。  | 
| [Vibrator_FileDescription](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_filedescription) | typedef struct [Vibrator_FileDescription](_vibrator___file_description.md)<br/>振动文件描述。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode) : int32_t { [PERMISSION_DENIED](_xe9_xa9_xac_xe8_xbe_xbe.md) = 201, [PARAMETER_ERROR](_xe9_xa9_xac_xe8_xbe_xbe.md) = 401, [UNSUPPORTED](_xe9_xa9_xac_xe8_xbe_xbe.md) = 801, **DEVICE_OPERATION_FAILED** = 14600101 } | 为用户定义错误码。  | 
| [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage) {<br/>[USAGE_UNKNOWN](_xe9_xa9_xac_xe8_xbe_xbe.md) = 0, [USAGE_ALARM](_xe9_xa9_xac_xe8_xbe_xbe.md) = 1, [USAGE_RING](_xe9_xa9_xac_xe8_xbe_xbe.md) = 2, [USAGE_NOTIFICATION](_xe9_xa9_xac_xe8_xbe_xbe.md) = 3,<br/>[USAGE_COMMUNICATION](_xe9_xa9_xac_xe8_xbe_xbe.md) = 4, [USAGE_TOUCH](_xe9_xa9_xac_xe8_xbe_xbe.md) = 5, [USAGE_MEDIA](_xe9_xa9_xac_xe8_xbe_xbe.md) = 6, [USAGE_PHYSICAL_FEEDBACK](_xe9_xa9_xac_xe8_xbe_xbe.md) = 7,<br/>**USAGE_SIMULATE_REALITY** = 8, **USAGE_MAX** = 9<br/>} | 振动优先级。  | 
