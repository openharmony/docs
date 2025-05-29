# oh_wifi.h


## 概述

定义查询WIFI开关状态的接口。

**库：** libwifi_ndk.so

**系统能力：** SystemCapability.Communication.WiFi.STA

**起始版本：** 13

**相关模块：**[Wifi](_wifi.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Wifi_ResultCode](_wifi.md#wifi_resultcode) [Wifi_ResultCode](_wifi.md#wifi_resultcode) | 定义WIFI接口返回值的错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Wifi_ResultCode](_wifi.md#wifi_resultcode) {<br/>[WIFI_SUCCESS](_wifi.md) = 0,<br/>[WIFI_PERMISSION_DENIED](_wifi.md) = 201,<br/>[WIFI_INVALID_PARAM](_wifi.md) = 401,<br/>[WIFI_NOT_SUPPORTED](_wifi.md) = 801,<br/>[WIFI_OPERATION_FAILED](_wifi.md) = 2501000<br/>} | 定义WIFI接口返回值的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Wifi_ResultCode](_wifi.md#wifi_resultcode) [OH_Wifi_IsWifiEnabled](_wifi.md#oh_wifi_iswifienabled) (bool \*enabled) | 查询WIFI开关是否开启。 | 
