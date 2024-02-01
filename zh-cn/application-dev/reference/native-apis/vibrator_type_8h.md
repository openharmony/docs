# vibrator_type.h


## 概述

为您提供标准的开放api，用于控制马达振动的启停。

**库：** libohvibrator.z.so

**系统能力：** SystemCapability.Sensors.MiscDevice

**起始版本：** 11

**相关模块：** [Vibrator](_vibrator.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_Attribute](_vibrator_attribute.md) | 马达属性。  |
| [Vibrator_FileDescription](_vibrator_file_description.md) | 振动文件描述。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode) | 为用户定义错误码。  |
| [Vibrator_Usage](_vibrator.md#vibrator_usage) | 振动优先级。  |
| [Vibrator_Attribute](_vibrator.md#vibrator_attribute) | 马达属性。  |
| [Vibrator_FileDescription](_vibrator.md#vibrator_filedescription) | 振动文件描述。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode) : int32_t {<br/>PERMISSION_DENIED = 201<br/>PARAMETER_ERROR = 401, <br/>[UNSUPPORTED] = 801, <br/>[DEVICE_OPERATION_FAILED = 14600101<br/>} | 为用户定义错误码。  |
| [Vibrator_Usage](_vibrator.md#vibrator_usage) {<br/>USAGE_UNKNOWN = 0, <br/>USAGE_ALARM = 1, <br/>USAGE_RING = 2,<br/>USAGE_NOTIFICATION = 3,<br/>USAGE_COMMUNICATION = 4,<br/>USAGE_TOUCH = 5, <br/>USAGE_MEDIA = 6, <br/>USAGE_PHYSICAL_FEEDBACK = 7,<br/>USAGE_SIMULATE_REALITY = 8, <br/>USAGE_MAX = 9<br/>} | 振动优先级。  |

