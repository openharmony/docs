# WiFi


## 概述

提供用于查询WiFi开关状态的功能。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_wifi.h](oh__wifi_8h.md) | 定义查询WiFi开关状态的接口。<br>**引用文件：** \<ConnectivityKit\/wifi\/oh_wifi.h\> | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Wifi_ResultCode](#wifi_resultcode) [Wifi_ResultCode](#wifi_resultcode) | 定义WiFi接口返回值的错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Wifi_ResultCode](#wifi_resultcode) {<br/>WIFI_SUCCESS = 0,<br/>WIFI_PERMISSION_DENIED = 201,<br/>WIFI_INVALID_PARAM = 401,<br/>WIFI_NOT_SUPPORTED = 801,<br/>WIFI_OPERATION_FAILED = 2501000<br/>} | 定义WiFi接口返回值的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Wifi_ResultCode](#wifi_resultcode) [OH_Wifi_IsWifiEnabled](#oh_wifi_iswifienabled) (bool \*enabled) | 查询WiFi开关是否开启。 | 


## 类型定义说明


### Wifi_ResultCode

```
typedef enum Wifi_ResultCode Wifi_ResultCode
```

**描述**

定义WiFi接口返回值的错误码。

**起始版本：** 13


## 枚举类型说明


### Wifi_ResultCode

```
enum Wifi_ResultCode
```

**描述**

定义WiFi接口返回值的错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| WIFI_SUCCESS | 操作成功。 | 
| WIFI_PERMISSION_DENIED | 权限校验失败。 | 
| WIFI_INVALID_PARAM | 参数错误。<br/>可能原因：1.输入参数为空指针；2.参数数值超出定义范围。 | 
| WIFI_NOT_SUPPORTED | 该功能不支持。由于设备能力有限，无法调用该函数。 | 
| WIFI_OPERATION_FAILED | 操作失败。<br/>可能原因：服务内部执行失败。 | 


## 函数说明


### OH_Wifi_IsWifiEnabled()

```
Wifi_ResultCode OH_Wifi_IsWifiEnabled (bool * enabled)
```

**描述**

查询WiFi开关是否开启。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| enabled | bool类型的指针，用于接收WiFi开关状态值。<br/>等于true表示WiFi开关开启，false表示WiFi开关开启。<br/>需要传入非空指针，否则会返回错误。 | 

**返回：**

返回操作结果，详细定义参见[Wifi_ResultCode](#wifi_resultcode)。

WIFI_SUCCESS 查询WiFi开关状态成功。

WIFI_INVALID_PARAM 入参是空指针。

WIFI_OPERATION_FAILED 服务内部执行错误。
