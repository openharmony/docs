# Types
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## WebviewController<sup>9+</sup>

type WebviewController = WebviewController

提供Web控制器的方法。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型     | 说明       |
| ------ | ---------- |
| [WebviewController](./arkts-apis-webview-WebviewController.md)  | 通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。 |

## OnAdsBlockedCallback<sup>12+</sup>

type OnAdsBlockedCallback = (details: AdsBlockedDetails) => void

当页面发生广告过滤时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型                                        | 必填   | 说明                         |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| details | [AdsBlockedDetails](./arkts-basic-components-web-i.md#adsblockeddetails12) | 是    | 发生广告拦截时，广告资源信息。 |

## OnSslErrorEventCallback<sup>12+</sup>

type OnSslErrorEventCallback = (sslErrorEvent: SslErrorEvent) => void

用户加载资源时发生SSL错误时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| sslErrorEvent | [SslErrorEvent](./arkts-basic-components-web-i.md#sslerrorevent12)  | 是 | 用户加载资源时发生SSL错误时触发的回调详情。 |

## OnContextMenuHideCallback<sup>11+</sup>

type OnContextMenuHideCallback = () => void

上下文菜单自定义隐藏的回调。

**系统能力：** SystemCapability.Web.Webview.Core

## OnRenderProcessNotRespondingCallback<sup>12+</sup>

type OnRenderProcessNotRespondingCallback = (data : RenderProcessNotRespondingData) => void

渲染进程无响应时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| data | [RenderProcessNotRespondingData](./arkts-basic-components-web-i.md#renderprocessnotrespondingdata12) | 是 | 渲染进程无响应的详细信息。 |

## OnRenderProcessRespondingCallback<sup>12+</sup>

type OnRenderProcessRespondingCallback = () => void

渲染进程由无响应状态变回正常运行状态时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

## OnViewportFitChangedCallback<sup>12+</sup>

type OnViewportFitChangedCallback = (viewportFit: ViewportFit) => void

网页meta中viewport-fit配置项更改时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| viewportFit | [ViewportFit](./arkts-basic-components-web-e.md#viewportfit12) | 是 | 网页meta中viewport-fit配置的视口类型。 |

## OnNativeEmbedVisibilityChangeCallback<sup>12+</sup>

type OnNativeEmbedVisibilityChangeCallback = (nativeEmbedVisibilityInfo: NativeEmbedVisibilityInfo) => void

当同层标签可见性变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](./arkts-basic-components-web-i.md#nativeembedvisibilityinfo12)  | 是 | 提供同层标签的可见性信息。 |

## OnFullScreenEnterCallback<sup>12+</sup>

type OnFullScreenEnterCallback = (event: FullScreenEnterEvent) => void

Web组件进入全屏时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| event | [FullScreenEnterEvent](./arkts-basic-components-web-i.md#fullscreenenterevent12)  | 是 | Web组件进入全屏的回调事件详情。 |

## OnFirstMeaningfulPaintCallback<sup>12+</sup>

type OnFirstMeaningfulPaintCallback = (firstMeaningfulPaint: [FirstMeaningfulPaint](./arkts-basic-components-web-i.md#firstmeaningfulpaint12)) => void

网页绘制页面度量信息的回调，当网页加载完页面主要内容时会触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](./arkts-basic-components-web-i.md#firstmeaningfulpaint12) | 是 | 绘制页面主要内容度量的详细信息。 |

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](./arkts-basic-components-web-i.md#largestcontentfulpaint12
)) => void

网页绘制页面最大内容度量信息的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| largestContentfulPaint | [LargestContentfulPaint](./arkts-basic-components-web-i.md#largestcontentfulpaint12) | 是 | 网页绘制页面最大内容度量的详细信息。 |

## OnNavigationEntryCommittedCallback<sup>11+</sup>

type OnNavigationEntryCommittedCallback = (loadCommittedDetails: [LoadCommittedDetails](./arkts-basic-components-web-i.md#loadcommitteddetails11)) => void

导航条目提交时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| loadCommittedDetails | [LoadCommittedDetails](./arkts-basic-components-web-i.md#loadcommitteddetails11)  | 是 | 提供已提交跳转的网页的详细信息。 |

## OnSafeBrowsingCheckResultCallback<sup>11+</sup>

type OnSafeBrowsingCheckResultCallback = (threatType: ThreatType) => void

网站安全风险检查触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| threatType | [ThreatType](./arkts-basic-components-web-e.md#threattype11)  | 是 | 定义网站threat类型。  |

## OnIntelligentTrackingPreventionCallback<sup>12+</sup>

type OnIntelligentTrackingPreventionCallback = (details: IntelligentTrackingPreventionDetails) => void

当跟踪者cookie被拦截时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| details | [IntelligentTrackingPreventionDetails](./arkts-basic-components-web-i.md#intelligenttrackingpreventiondetails12)  | 是 | 提供智能防跟踪拦截的详细信息。 |

## OnOverrideUrlLoadingCallback<sup>12+</sup>

type OnOverrideUrlLoadingCallback = (webResourceRequest: WebResourceRequest) => boolean

onOverrideUrlLoading的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| webResourceRequest   |   [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md)   | 是   | url请求的相关信息。|

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 返回true表示阻止此次加载，否则允许此次加载。 |

## WebKeyboardCallback<sup>12+</sup>

type WebKeyboardCallback = (keyboardCallbackInfo: WebKeyboardCallbackInfo) => WebKeyboardOptions

拦截网页可编辑元素拉起软键盘的回调，一般在点击网页input标签时触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| keyboardCallbackInfo    | [WebKeyboardCallbackInfo](./arkts-basic-components-web-i.md#webkeyboardcallbackinfo12) | 是    | 拦截网页拉起软键盘回调通知的入参，其中包括[WebKeyboardController](./arkts-basic-components-web-WebKeyboardController.md)、可编辑元素的属性。  |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| [WebKeyboardOptions](./arkts-basic-components-web-i.md#webkeyboardoptions12) | 回调函数通过返回[WebKeyboardOptions](./arkts-basic-components-web-i.md#webkeyboardoptions12)来决定ArkWeb内核拉起不同类型的软键盘。 |

## OnOverrideErrorPageCallback<sup>20+</sup>

type OnOverrideErrorPageCallback = (errorPageEvent: OnErrorReceiveEvent) => string

onOverrideErrorPage的回调函数，网页加载失败时触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| errorPageEvent | [OnErrorReceiveEvent](./arkts-basic-components-web-i.md#onerrorreceiveevent12) | 是 | 网页加载遇到错误时返回的相关信息。      |

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| string | 返回以Base64编码的HTML文本内容。 |

## MouseInfoCallback<sup>20+<sup>

type MouseInfoCallback = (event: NativeEmbedMouseInfo) => void

当鼠标/触摸板点击到同层标签时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| event | [NativeEmbedMouseInfo](./arkts-basic-components-web-i.md#nativeembedmouseinfo20) | 是 | 提供鼠标/触摸板在同层标签上点击或长按的详细信息。 |

**示例：**

完整示例代码参考[onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。

## OnNativeEmbedObjectParamChangeCallback<sup>21+<sup>

type OnNativeEmbedObjectParamChangeCallback = (event: NativeEmbedParamDataInfo) => void

增加、修改或删除同层渲染object标签内嵌param元素时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| event | [NativeEmbedParamDataInfo](./arkts-basic-components-web-i.md#nativeembedparamdatainfo21) | 是 | object标签内嵌param元素的详细变化信息。 |

**示例：**

完整示例代码参考[onNativeEmbedObjectParamChange](./arkts-basic-components-web-events.md#onnativeembedobjectparamchange21)。