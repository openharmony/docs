# Vibrator


## 概述

为马达服务提供统一的API以访问马达驱动程序属性。

**起始版本**：11


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [vibrator_type.h](vibrator_type_8h.md) | 为您提供标准的开放api，用于控制马达振动的启停。  |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_Attribute](_vibrator_attribute.md) | 马达属性。  |
| [Vibrator_FileDescription](_vibrator_file_description.md) | 振动文件描述。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) | 为用户定义错误码。  |
| [Vibrator_Usage](#vibrator_usage) | 振动优先级。       |
| [Vibrator_Attribute](#vibrator_attribute) | 马达属性。  |
| [Vibrator_FileDescription](#vibrator_filedescription) | 振动文件描述。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) : int32_t { <br/>PERMISSION_DENIED = 201, <br/>PARAMETER_ERROR = 401, <br/>UNSUPPORTED = 801, <br/>DEVICE_OPERATION_FAILED = 14600101<br/>} | 为用户定义错误码。  |
| [Vibrator_Usage](#vibrator_usage) {<br/>USAGE_UNKNOWN = 0, <br/>USAGE_ALARM = 1, <br/>USAGE_RING = 2,<br/> USAGE_NOTIFICATION = 3,<br/>USAGE_COMMUNICATION = 4, <br/>USAGE_TOUCH = 5, <br/>USAGE_MEDIA = 6, <br/>USAGE_PHYSICAL_FEEDBACK = 7,<br/>USAGE_SIMULATE_REALITY = 8, <br/>USAGE_MAX = 9<br/>} | 振动优先级。  |


## 类型定义说明


### Vibrator_Attribute

```
typedef struct Vibrator_Attribute Vibrator_Attribute
```
**描述**：

马达属性。

**起始版本**：11


### Vibrator_ErrorCode

```
typedef enum Vibrator_ErrorCode Vibrator_ErrorCode
```
**描述**：

为用户定义错误码。

**起始版本**：11


### Vibrator_FileDescription

```
typedef struct Vibrator_FileDescription Vibrator_FileDescription
```
**描述**：

振动文件描述。

**起始版本**：11


### Vibrator_Usage

```
typedef enum Vibrator_Usage Vibrator_Usage
```
**描述**：

振动优先级。

**起始版本**：11


## 枚举类型说明


### Vibrator_ErrorCode

```
enum Vibrator_ErrorCode:int32_t
```
**描述**：

为用户定义错误码。

**起始版本**：11

| 枚举值 | 描述 |
| -------- | -------- |
| PERMISSION_DENIED  | 权限校验失败。 |
| PARAMETER_ERROR  | 参数检查失败，包括必选参数没有传入，参数类型错误等。 |
| UNSUPPORTED  | 该设备不支持此 API，通常用于在设备已支持该 SysCap 时，针对其少量的 API 的支持处理。 |
| DEVICE_OPERATION_FAILED | 设备操作失败。 |


### Vibrator_Usage

```
enum Vibrator_Usage
```
**描述**：

振动优先级。

**起始版本**：11

| 枚举值 | 描述 |
| -------- | -------- |
| USAGE_UNKNOWN  | 未知场景。 |
| USAGE_ALARM  | 报警。 |
| USAGE_RING  | 铃声。 |
| USAGE_NOTIFICATION  | 通知。 |
| USAGE_COMMUNICATION  | 通信。 |
| USAGE_TOUCH  | 触摸。 |
| USAGE_MEDIA  | 媒体。 |
| USAGE_PHYSICAL_FEEDBACK  | 物理反馈。 |
| USAGE_SIMULATE_REALITY | 模拟现实。 |
