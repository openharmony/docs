# Class (NativeMediaPlayerSurfaceInfo)

[应用接管网页媒体播放功能](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12)中用于同层渲染的 surface 信息。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| id | string | 是 | surface的id，用于同层渲染的NativeImage的psurfaceid。<br/>详见[NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11)。 |
| rect | [RectEvent](./arkts-apis-webview-i.md#rectevent12) | 是 | surface的位置信息。 |