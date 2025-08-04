# Class (JsGeolocation)
<!--Kit: ArkWeb-->
<!--Subsystem: ArkWeb-->
<!--Owner: @zhang-yinglie-->
<!--SE: @handyohos-->
<!--TSE: @ghiker-->

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onGeolocationShow事件](./arkts-basic-components-web-events.md#ongeolocationshow)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 8开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## constructor

constructor()

JsGeolocation的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## invoke

invoke(origin: string, allow: boolean, retain: boolean): void

设置网页地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填  | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | 是   | 指定源的字符串索引。                               |
| allow  | boolean | 是   | 设置的地理位置权限状态。<br>true表示开启地理位置权限，false表示不开启地理位置权限。                             |
| retain | boolean | 是   | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions<sup>9+</sup>](./arkts-apis-webview-GeolocationPermissions.md)接口管理保存到系统的地理位置权限。<br>true表示允许将地理位置权限状态保存到系统中，false表示不允许将地理位置权限状态保存到系统中。 |