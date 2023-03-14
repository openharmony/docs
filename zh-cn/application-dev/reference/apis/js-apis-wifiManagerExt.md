# @ohos.wifiManagerExt (WLAN扩展接口)

该模块主要提供WLAN扩展接口，供非通用类型产品使用。

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
该文档中的接口只供非通用类型产品使用，如路由器等，对于常规类型产品，不应该使用这些接口。


## 导入模块

```js
import wifiManagerExt from '@ohos.wifiManagerExt';
```

## wifiext.enableHotspot<sup>9+</sup>

enableHotspot(): void;

使能WLAN热点。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.disableHotspot<sup>9+</sup>

disableHotspot(): void;

去使能WLAN热点。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(): Promise&lt;Array&lt;PowerMode&gt;&gt;

获取支持的功率模式，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[PowerMode](#powermode)&gt;&gt; | Promise对象。表示功率模式。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## PowerMode

表示功率模式的枚举。

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SLEEPING | 0 | 睡眠模式。 |
| GENERAL | 1 | 常规模式。 |
| THROUGH_WALL | 2 | 穿墙模式。 |


## wifiext.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(callback: AsyncCallback&lt;Array&lt;PowerMode&gt;&gt;): void

获取支持的功率模式，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;[PowerMode](#powermode)&gt;&gt; | 是 | 回调函数。当操作成功时，err为0，data表示支持的功率模式。如果error为非0，表示处理出现错误。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerMode<sup>9+</sup>

getPowerMode(): Promise&lt;PowerMode&gt;

获取功率模式，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[PowerMode](#powermode)&gt; | Promise对象。表示功率模式。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerMode<sup>9+</sup>

getPowerMode(callback: AsyncCallback&lt;PowerMode&gt;): void

获取功率模式，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[PowerMode](#powermode)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示功率模式。如果error为非0，表示处理出现错误。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.setPowerMode<sup>9+</sup>

setPowerMode(model: PowerMode) : boolean;

 设置功率模式。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | model | [PowerMode](#powermode) | 是 | 功率模式。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **类型** | **说明** |
  | -------- | -------- |
| 2701000  | Operation failed.|
