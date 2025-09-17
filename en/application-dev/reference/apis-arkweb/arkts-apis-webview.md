# Module Description
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc-->
<!--Designer: @ctqctq99-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

The **Webview** module provides APIs for web control. It can work with the [Web](arkts-basic-components-web.md) component, which is used to display web pages.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.
>
> - Static methods must be used on the user interface (UI) thread.

This module provides the following common functionalities for web control:

- [AdsBlockManager](./arkts-apis-webview-AdsBlockManager.md): Ad filtering configuration.
- [BackForwardCacheOptions](./arkts-apis-webview-BackForwardCacheOptions.md): Forward and backward cache configuration.
- [BackForwardCacheSupportedFeatures](./arkts-apis-webview-BackForwardCacheSupportedFeatures.md): Forward and backward cache feature configuration.
- [GeolocationPermissions](./arkts-apis-webview-GeolocationPermissions.md): Geolocation permission configuration.
- [JsMessageExt](./arkts-apis-webview-JsMessageExt.md): JavaScript execution result.
- [MediaSourceInfo](./arkts-apis-webview-MediaSourceInfo.md): Media source information configuration.
- [NativeMediaPlayerSurfaceInfo](./arkts-apis-webview-NativeMediaPlayerSurfaceInfo.md): Rendering information when the application takes over media playback.
- [PdfData](./arkts-apis-webview-PdfData.md): Generated PDF output data.
- [ProxyConfig](./arkts-apis-webview-ProxyConfig.md): Network proxy configuration.
- [ProxyController](./arkts-apis-webview-ProxyController.md): Network proxy controller.
- [WebviewController](./arkts-apis-webview-WebviewController.md): **Web** component controller.
- [WebCookieManager](./arkts-apis-webview-WebCookieManager.md): Cookie management.
- [WebDataBase](./arkts-apis-webview-WebDataBase.md): Database management.
- [WebDownloadDelegate](./arkts-apis-webview-WebDownloadDelegate.md): Download task status event.
- [WebDownloadItem](./arkts-apis-webview-WebDownloadItem.md): Download task.
- [WebDownloadManager](./arkts-apis-webview-WebDownloadManager.md): Download task management.
- [WebHttpBodyStream](./arkts-apis-webview-WebHttpBodyStream.md): HTTP request body.
- [WebMessageExt](./arkts-apis-webview-WebMessageExt.md): Data object for communication between the frontend and application.
- [WebResourceHandler](./arkts-apis-webview-WebResourceHandler.md): Resource loading control.
- [WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md): Request interceptor of a specified scheme.
- [WebSchemeHandlerRequest](./arkts-apis-webview-WebSchemeHandlerRequest.md): Request intercepted by the interceptor.
- [WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md): Custom responses for intercepted requests.
- [WebStorage](./arkts-apis-webview-WebStorage.md): Storage operation API of the **Web** component.
- [BackForwardList](./arkts-apis-webview-BackForwardList.md): History information list.
- [NativeMediaPlayerBridge](./arkts-apis-webview-NativeMediaPlayerBridge.md): Bridge API for taking over web media players.
- [NativeMediaPlayerHandler](./arkts-apis-webview-NativeMediaPlayerHandler.md): Event API for taking over web media players.
- [WebMessagePort](./arkts-apis-webview-WebMessagePort.md): Message port between the web page and application.

## Required Permissions

**ohos.permission.INTERNET**, required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

**System capability**: SystemCapability.Web.Webview.Core
