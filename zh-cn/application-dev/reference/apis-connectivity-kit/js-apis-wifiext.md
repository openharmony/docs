# @ohos.wifiext (WLAN扩展接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @qq_43802146-->
<!--Designer: @qq_43802146-->
<!--Tester: @furryfurry123-->
<!--Adviser: @zhang_yixin13-->
该模块主要提供WLAN扩展接口，供非通用类型产品使用。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
该文档中的接口只供非通用类型产品使用，如路由器等，对于常规类型产品，不应该使用这些接口。
> 从API Version 9开始，该接口不再维护，推荐使用[`@ohos.wifiManagerExt（WLAN扩展接口）`](js-apis-wifiManagerExt.md)等相关接口。

## 导入模块

```js
import wifiext from '@ohos.wifiext';
```

## wifiext.enableHotspot

enableHotspot(): boolean;

使能WLAN热点。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |


## wifiext.disableHotspot

disableHotspot(): boolean;

去使能WLAN热点。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |


## wifiext.getSupportedPowerModel

getSupportedPowerModel(): Promise&lt;Array&lt;PowerModel&gt;&gt;

获取支持的功率模式，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[PowerModel](#powermodel)&gt;&gt; | Promise对象。表示功率模式。 |


## PowerModel

表示功率模式的枚举。

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SLEEPING | 0 | 睡眠模式。 |
| GENERAL | 1 | 常规模式。 |
| THROUGH_WALL | 2 | 穿墙模式。 |


## wifiext.getSupportedPowerModel

getSupportedPowerModel(callback: AsyncCallback&lt;Array&lt;PowerModel&gt;&gt;): void

获取支持的功率模式，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;[PowerModel](#powermodel)&gt;&gt; | 是 | 回调函数。当操作成功时，err为0，data表示支持的功率模式。如果err为非0，表示处理出现错误。 |


## wifiext.getPowerModel

getPowerModel(): Promise&lt;PowerModel&gt;

获取功率模式，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[PowerModel](#powermodel)&gt; | Promise对象。表示功率模式。 |


## wifiext.getPowerModel

getPowerModel(callback: AsyncCallback&lt;PowerModel&gt;): void

获取功率模式，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[PowerModel](#powermodel)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示功率模式。如果err为非0，表示处理出现错误。 |


## wifiext.setPowerModel

setPowerModel(model: PowerModel) : boolean;

 设置功率模式。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | model | [PowerModel](#powermodel) | 是 | 功率模式。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |
