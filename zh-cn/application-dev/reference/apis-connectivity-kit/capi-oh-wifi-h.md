# oh_wifi.h

## 概述

定义查询WIFI开关状态的接口。

**引用文件：** <ConnectivityKit/wifi/oh_wifi.h>

**库：** libwifi_ndk.so

**系统能力：** SystemCapability.Communication.WiFi.STA

**起始版本：** 13

**相关模块：** [Wifi](capi-wifi.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Wifi_ResultCode](#wifi_resultcode) | Wifi_ResultCode | 定义WIFI接口返回值的错误码。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)](#oh_wifi_iswifienabled) | 查询WIFI开关是否开启。 |

## 枚举类型说明

### Wifi_ResultCode

```
enum Wifi_ResultCode
```

**描述**

定义WIFI接口返回值的错误码。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| WIFI_SUCCESS = 0 | 操作成功。 |
| WIFI_PERMISSION_DENIED = 201 | 权限校验失败。 |
| WIFI_INVALID_PARAM = 401 | 参数错误。<br> 可能原因：1.输入参数为空指针；2.参数数值超出定义范围。 |
| WIFI_NOT_SUPPORTED = 801 | 表示由于设备能力有限，无法调用该函数。 |
| WIFI_OPERATION_FAILED = 2501000 | 操作失败。<br> 可能原因：服务内部执行失败。 |


## 函数说明

### OH_Wifi_IsWifiEnabled()

```
Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)
```

**描述**

查询WIFI开关是否开启。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool *enabled | - bool类型的指针，用于接收WIFI开关状态值。<br> 等于true表示WIFI开关开启，false表示WIFI开关关闭。<br> 需要传入非空指针，否则会返回错误。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode) | 返回操作结果，详细定义参见[Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode).<br>     [WIFI_SUCCESS](capi-oh-wifi-h.md#wifi_resultcode) 查询WIFI开关状态成功。<br>     [WIFI_INVALID_PARAM](capi-oh-wifi-h.md#wifi_resultcode) 入参是空指针。<br>     [WIFI_OPERATION_FAILED](capi-oh-wifi-h.md#wifi_resultcode) 服务内部执行错误。 |


