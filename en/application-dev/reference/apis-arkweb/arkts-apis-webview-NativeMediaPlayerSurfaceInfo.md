# Class (NativeMediaPlayerSurfaceInfo)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements a **NativeMediaPlayerSurfaceInfo** object to provide the surface information used for same-layer rendering [when the application takes over the media playback of the web page](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Read-Only| Optional | Description|
|------|------|------|------|------|
| id<sup>12+</sup> | string | No| No| Surface ID, which is the **psurfaceid** of the native image used for rendering at the same layer.<br>For details, see [NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11).|
| rect<sup>12+</sup> | [RectEvent](./arkts-apis-webview-i.md#rectevent12) | No| No| Position of the surface.|
