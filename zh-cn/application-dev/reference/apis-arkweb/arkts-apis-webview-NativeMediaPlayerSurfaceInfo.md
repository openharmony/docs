# Class (NativeMediaPlayerSurfaceInfo)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @gzweioh-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

NativeMediaPlayerSurfaceInfo 使用[enableNativeMediaPlayer](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12)来进行同层渲染的 surface 信息配置。该类允许应用接管网页媒体播放功能，通过配置 surface 的 id 和位置信息，实现网页媒体内容与应用界面的同层渲染融合，提升媒体播放体验。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选  | 说明 |
|------|------|------|------|------|
| id<sup>12+</sup> | string | 否 | 否 | surface 的 id，用于同层渲染的 NativeImage 的 surfaceId。<br>详见[NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11)。 |
| rect<sup>12+</sup> | [RectEvent](./arkts-apis-webview-i.md#rectevent12) | 否 | 否 | surface 的位置信息，用于指定同层渲染时 surface 的显示位置和尺寸。 |
