# native_deviceinfo.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

## 概述

提供播控设备信息的定义。

**引用文件：** <multimedia/av_session/native_deviceinfo.h>

**库：** libohavsession.so

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 23

**相关模块：** [OHAVSession](capi-ohavsession.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AVSession_OutputDeviceInfo](capi-ohavsession-avsession-outputdeviceinfo.md) | AVSession_OutputDeviceInfo | 目标设备信息的定义。 |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) | AVSession_DeviceInfo | 设备信息的声明。该实例用于获取更多的设备信息及其详细属性。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [AVSession_ErrCode OH_DeviceInfo_GetAVCastCategory(AVSession_DeviceInfo *deviceInfo, AVSession_AVCastCategory *aVCastCategory)](#oh_deviceinfo_getavcastcategory) | 获取目标设备的投播类别。 |
| [AVSession_ErrCode OH_DeviceInfo_GetDeviceId(AVSession_DeviceInfo *deviceInfo, char **deviceId)](#oh_deviceinfo_getdeviceid) | 获取目标设备的设备ID。 |
| [AVSession_ErrCode OH_DeviceInfo_GetDeviceName(AVSession_DeviceInfo *deviceInfo, char **deviceName)](#oh_deviceinfo_getdevicename) | 获取目标设备的设备名称。 |
| [AVSession_ErrCode OH_DeviceInfo_GetDeviceType(AVSession_DeviceInfo *deviceInfo, AVSession_DeviceType *deviceType)](#oh_deviceinfo_getdevicetype) | 获取目标设备的设备类型。 |
| [AVSession_ErrCode OH_DeviceInfo_GetSupportedProtocols(AVSession_DeviceInfo *deviceInfo, uint32_t *deviceProtocolType)](#oh_deviceinfo_getsupportedprotocols) | 获取目标设备支持的协议。 |

## 函数说明

### OH_DeviceInfo_GetAVCastCategory()

```c
AVSession_ErrCode OH_DeviceInfo_GetAVCastCategory(AVSession_DeviceInfo *deviceInfo, AVSession_AVCastCategory *aVCastCategory)
```

**描述**

获取目标设备的投播类别。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) *deviceInfo | 表示设备信息实例指针。 |
| [AVSession_AVCastCategory](capi-native-avsession-base-h.md#avsession_avcastcategory) *aVCastCategory | 输出参数，用于接收投播类别的指针变量，具体枚举值含义见链接说明。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数deviceInfo为nullptr。<br>                                         2. 参数aVCastCategory为nullptr。 |

### OH_DeviceInfo_GetDeviceId()

```c
AVSession_ErrCode OH_DeviceInfo_GetDeviceId(AVSession_DeviceInfo *deviceInfo, char **deviceId)
```

**描述**

获取目标设备的设备ID。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) *deviceInfo | 表示设备信息实例指针。 |
| char **deviceId | 输出参数，用于存储获取到的设备ID字符串指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数deviceInfo为nullptr。<br>                                         2. 参数deviceId为nullptr。 |

### OH_DeviceInfo_GetDeviceName()

```c
AVSession_ErrCode OH_DeviceInfo_GetDeviceName(AVSession_DeviceInfo *deviceInfo, char **deviceName)
```

**描述**

获取目标设备的设备名称。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) *deviceInfo | 表示设备信息实例指针。 |
| char **deviceName | 输出参数，用于存储获取到的设备名称字符串指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数deviceInfo为nullptr。<br>                                         2. 参数deviceName为nullptr。 |

### OH_DeviceInfo_GetDeviceType()

```c
AVSession_ErrCode OH_DeviceInfo_GetDeviceType(AVSession_DeviceInfo *deviceInfo, AVSession_DeviceType *deviceType)
```

**描述**

获取目标设备的设备类型。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) *deviceInfo | 表示设备信息实例指针。 |
| [AVSession_DeviceType](capi-native-avsession-base-h.md#avsession_devicetype) *deviceType | 输出参数，用于接收设备类型的指针，具体枚举值含义见链接说明。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数deviceInfo为nullptr。<br>                                         2. 参数deviceType为nullptr。 |

### OH_DeviceInfo_GetSupportedProtocols()

```c
AVSession_ErrCode OH_DeviceInfo_GetSupportedProtocols(AVSession_DeviceInfo *deviceInfo, uint32_t *deviceProtocolType)
```

**描述**

获取目标设备支持的协议。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) *deviceInfo | 表示设备信息实例指针。 |
| uint32_t *deviceProtocolType | 输出参数，用于接收设备支持的协议类型的指针，返回值为协议类型的位掩码组合，具体协议类型见相关枚举定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数deviceInfo为nullptr。<br>                                         2. 参数deviceProtocolType为nullptr。 |


