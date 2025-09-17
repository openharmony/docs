# Class (NativeMediaPlayerSurfaceInfo)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

[应用接管网页媒体播放功能](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12)中用于同层渲染的 surface 信息。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选  | 说明 |
|------|------|------|------|------|
| id<sup>12+</sup> | string | 否 | 否 | surface的id，用于同层渲染的NativeImage的psurfaceid。<br/>详见[NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11)。 |
| rect<sup>12+</sup> | [RectEvent](./arkts-apis-webview-i.md#rectevent12) | 否 | 否 | surface的位置信息。 |
