# Web子系统ChangeLog

## cl.web.1 对viewport类型的meta标签启用规则变更

**访问级别**

公开接口

**变更原因**

在此之前默认根据设备类型判断，在移动设备上启用viewport类型的meta标签，按照移动版显示网页；在其他设备上禁用viewport类型的meta标签，按照桌面版显示网页。开发者无法自定义显示的效果。

**变更影响**

[setCustomUserAgent](../../../application-dev/reference/apis/js-apis-webview.md#setcustomuseragent10)接口设置的自定义用户代理字段中，如果不存在"Mobile"字段，则识别为桌面平台设备，默认禁用viewport类型的meta标签，按照桌面版页面显示；如果存在"Mobile"字段，则识别为移动平台设备，默认启用viewport类型的meta标签，按照移动版页面显示，开发者可以通过用户代理自定义网页显示的效果。

该变更为非兼容性变更。当应用自定义的用户代理不规范时，网页布局会显示不正常。

**API Level**

10

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

setCustomUserAgent

**适配指导**

需要应用开发者使用规范的自定义用户代理或使用默认用户代理，建议先使用[getUserAgent](../../../application-dev/reference/apis/js-apis-webview.md#getuseragent)获取当前默认用户代理，在此基础上追加自定义用户代理字段。
