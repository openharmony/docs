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
> 从API version 9开始，该接口不再维护，推荐使用[@ohos.wifiManagerExt (WLAN扩展接口)](js-apis-wifiManagerExt.md)等相关接口。

## 导入模块

```js
import wifiext from '@ohos.wifiext';
```

## wifiext.enableHotspot<sup>(deprecated)</sup>

enableHotspot(): boolean;

启用WLAN热点。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.enableHotspot](js-apis-wifiManagerExt.md#wifimanagerextenablehotspotdeprecated)替代。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |


## wifiext.disableHotspot<sup>(deprecated)</sup>

disableHotspot(): boolean;

禁用WLAN热点。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.disableHotspot](js-apis-wifiManagerExt.md#wifimanagerextdisablehotspotdeprecated)替代。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |


## wifiext.getSupportedPowerModel<sup>(deprecated)</sup>

getSupportedPowerModel(): Promise&lt;Array&lt;PowerModel&gt;&gt;

获取支持的功率模式。使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.getSupportedPowerModel](js-apis-wifiManagerExt.md#wifimanagerextgetsupportedpowermode)替代。

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


## wifiext.getSupportedPowerModel<sup>(deprecated)</sup>

getSupportedPowerModel(callback: AsyncCallback&lt;Array&lt;PowerModel&gt;&gt;): void

获取支持的功率模式。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.getSupportedPowerMode](js-apis-wifiManagerExt.md#wifimanagerextgetsupportedpowermode)替代。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;[PowerModel](#powermodel)&gt;&gt; | 是 | 回调函数。当操作成功时，err为0，data表示支持的功率模式。如果err为非0，表示处理出现错误。 |


## wifiext.getPowerModel<sup>(deprecated)</sup>

getPowerModel(): Promise&lt;PowerModel&gt;

获取功率模式，使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.getPowerMode](js-apis-wifiManagerExt.md#wifimanagerextgetpowermode)替代。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[PowerModel](#powermodel)&gt; | Promise对象。表示功率模式。 |


## wifiext.getPowerModel<sup>(deprecated)</sup>

getPowerModel(callback: AsyncCallback&lt;PowerModel&gt;): void

获取功率模式。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.getPowerMode](js-apis-wifiManagerExt.md#wifimanagerextgetpowermode-1)替代。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[PowerModel](#powermodel)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示功率模式。如果err为非0，表示处理出现错误。 |


## wifiext.setPowerModel<sup>(deprecated)</sup>

setPowerModel(model: PowerModel) : boolean;

设置功率模式。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[wifiManagerExt.setPowerMode](js-apis-wifiManagerExt.md#wifimanagerextsetpowermodedeprecated)替代。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**系统能力：** SystemCapability.Communication.WiFi.AP.Extension

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | model | [PowerModel](#powermodel) | 是 | 功率模式。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 操作结果， true: 成功， false: 失败。 |
