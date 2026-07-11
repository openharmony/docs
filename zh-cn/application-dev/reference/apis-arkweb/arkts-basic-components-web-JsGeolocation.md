# Class (JsGeolocation)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

JsGeolocation是Web组件在收到网页地理位置权限请求时，提供给应用的授权响应对象。当网页通过JavaScript调用地理位置接口（如navigator.geolocation）请求获取设备位置信息时，应用需要决定是否授权该请求。JsGeolocation通过invoke方法允许应用对指定源的网页授予或拒绝地理位置权限，同时可选择将该权限决策保存到系统中，避免后续同一源再次请求时重复弹出授权提示。

JsGeolocation适用于Web组件中网页主动请求地理位置权限的场景。应用需先注册[onGeolocationShow事件](./arkts-basic-components-web-events.md#ongeolocationshow)，当网页发起地理位置权限请求时，该事件回调会将JsGeolocation对象传递给应用，应用在回调中调用invoke方法完成授权响应。使用时还需配置"ohos.permission.LOCATION"、"ohos.permission.APPROXIMATELY_LOCATION"权限。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 8开始支持。
>
> - 示例效果请以真机运行为准。

## constructor

constructor()

JsGeolocation的构造函数。构造函数本身不直接被应用调用，通常通过[onGeolocationShow事件](./arkts-basic-components-web-events.md#ongeolocationshow)回调获取JsGeolocation实例。

**系统能力：** SystemCapability.Web.Webview.Core

## invoke

invoke(origin: string, allow: boolean, retain: boolean): void

设置网页地理位置权限状态。该方法需在[onGeolocationShow事件](./arkts-basic-components-web-events.md#ongeolocationshow)回调中调用，用于对发起地理位置权限请求的网页进行授权响应。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填  | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | 是   | 指定源的字符串，格式需符合Web Origin规范。 |
| allow  | boolean | 是   | 设置的地理位置权限状态。<br>true表示开启地理位置权限，false表示不开启地理位置权限。                             |
| retain | boolean | 是   | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions](./arkts-apis-webview-GeolocationPermissions.md)接口管理保存到系统的地理位置权限。<br>true表示保存地理位置权限状态到系统，false表示不保存到系统。 |