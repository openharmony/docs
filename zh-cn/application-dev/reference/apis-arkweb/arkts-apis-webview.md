# 模块描述
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc-->
<!--SE: @ctqctq99-->
<!--TSE: @ghiker-->

@ohos.web.webview提供Web控制能力，[Web](arkts-basic-components-web.md)组件提供网页显示的能力。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。
>
> - 静态方法必须在用户界面（UI）线程上使用。

该模块提供以下Web控制相关的常用功能：

- [AdsBlockManager](./arkts-apis-webview-AdsBlockManager.md)：广告过滤配置。
- [BackForwardCacheOptions](./arkts-apis-webview-BackForwardCacheOptions.md)：前进后退缓存配置。
- [BackForwardCacheSupportedFeatures](./arkts-apis-webview-BackForwardCacheSupportedFeatures.md)：前进后退缓存特性配置。
- [GeolocationPermissions](./arkts-apis-webview-GeolocationPermissions.md)：地理位置权限配置。
- [JsMessageExt](./arkts-apis-webview-JsMessageExt.md)：执行JavaScript脚本的结果。
- [MediaSourceInfo](./arkts-apis-webview-MediaSourceInfo.md)：媒体源信息配置。
- [NativeMediaPlayerSurfaceInfo](./arkts-apis-webview-NativeMediaPlayerSurfaceInfo.md)：应用接管媒体播放时渲染信息。
- [PdfData](./arkts-apis-webview-PdfData.md)：生成的PDF输出数据。
- [ProxyConfig](./arkts-apis-webview-ProxyConfig.md)：网络代理配置。
- [ProxyController](./arkts-apis-webview-ProxyController.md)：网络代理控制器。
- [WebviewController](./arkts-apis-webview-WebviewController.md)：Web组件控制器。
- [WebCookieManager](./arkts-apis-webview-WebCookieManager.md)：Cookie管理。
- [WebDataBase](./arkts-apis-webview-WebDataBase.md)：数据库管理。
- [WebDownloadDelegate](./arkts-apis-webview-WebDownloadDelegate.md)：下载任务状态事件。
- [WebDownloadItem](./arkts-apis-webview-WebDownloadItem.md)：下载任务。
- [WebDownloadManager](./arkts-apis-webview-WebDownloadManager.md)：下载任务管理。
- [WebHttpBodyStream](./arkts-apis-webview-WebHttpBodyStream.md)：HTTP请求体。
- [WebMessageExt](./arkts-apis-webview-WebMessageExt.md)：前端与应用通信数据对象。
- [WebResourceHandler](./arkts-apis-webview-WebResourceHandler.md)：资源加载控制。
- [WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md)：指定Scheme的请求拦截器。
- [WebSchemeHandlerRequest](./arkts-apis-webview-WebSchemeHandlerRequest.md)：通过拦截器拦截到的请求。
- [WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md)：为拦截到的请求创建自定义响应。
- [WebStorage](./arkts-apis-webview-WebStorage.md)：Web组件存储操作接口。
- [BackForwardList](./arkts-apis-webview-BackForwardList.md)：历史信息列表。
- [NativeMediaPlayerBridge](./arkts-apis-webview-NativeMediaPlayerBridge.md)：托管网页媒体播放器桥接接口。
- [NativeMediaPlayerHandler](./arkts-apis-webview-NativeMediaPlayerHandler.md)：托管网页媒体播放器的事件接口。
- [WebMessagePort](./arkts-apis-webview-WebMessagePort.md)：网页前端与应用的消息端口。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

**系统能力：** SystemCapability.Web.Webview.Core