# Types
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @gzweioh-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

本文档提供 ArkWeb 组件中使用的类型定义，包括 Web 控制器及各类事件回调函数类型。其中，WebviewController 用于控制 Web 组件的行为；各类回调函数类型为开发者提供 Web 组件运行过程中多种事件场景的事件监听和处理能力。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准。

## WebviewController<sup>9+</sup>

type WebviewController = import('../api/@ohos.web.webview').default.WebviewController

提供Web控制器的方法。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型     | 说明       |
| ------ | ---------- |
| [import('../api/@ohos.web.webview').default.WebviewController](./arkts-apis-webview-WebviewController.md)  | 通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。 |

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

## OnVerifyPinCallback<sup>22+</sup>

type OnVerifyPinCallback = (verifyPinEvent: VerifyPinEvent) => void

需要用户进行PIN码认证时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| verifyPinEvent | [VerifyPinEvent](./arkts-basic-components-web-i.md#verifypinevent22)  | 是 | 需要用户进行PIN码认证时触发的回调详情。 |

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
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](./arkts-basic-components-web-i.md#nativeembedvisibilityinfo12)  | 是 | 提供同层标签可见性变化的信息。|

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

网页首次绘制页面主要内容度量的回调，当网页加载完页面主要内容时会触发此回调。与OnLargestContentfulPaintCallback关注最大内容元素绘制时间、OnFirstScreenPaintCallback关注首屏可见内容渲染完成相比，本回调更关注主要内容是否加载完成，适合评估用户可见内容的加载体验。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](./arkts-basic-components-web-i.md#firstmeaningfulpaint12) | 是 | 绘制页面主要内容度量的详细信息。 |

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](./arkts-basic-components-web-i.md#largestcontentfulpaint12)) => void

当网页绘制最大内容区域时触发的回调，用于获取最大内容绘制的性能度量信息。适用于需要监控网页加载性能、优化页面渲染速度等场景。与OnFirstMeaningfulPaintCallback关注主要内容加载完成、OnFirstScreenPaintCallback关注首屏可见内容渲染完成相比，本回调关注最大内容元素的绘制时间，适合评估页面渲染完成度和性能瓶颈。

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

## MouseInfoCallback<sup>20+</sup>

type MouseInfoCallback = (event: NativeEmbedMouseInfo) => void

当鼠标/触摸板单击到同层标签时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| event | [NativeEmbedMouseInfo](./arkts-basic-components-web-i.md#nativeembedmouseinfo20) | 是 | 提供鼠标/触摸板在同层标签上单击或长按的详细信息。 |

**示例：**

完整示例代码参考[onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20)。

## OnNativeEmbedObjectParamChangeCallback<sup>21+</sup>

type OnNativeEmbedObjectParamChangeCallback = (event: NativeEmbedParamDataInfo) => void

增加、修改或删除同层渲染object标签内嵌param元素时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| event | [NativeEmbedParamDataInfo](./arkts-basic-components-web-i.md#nativeembedparamdatainfo21) | 是 | object标签内嵌param元素的详细变化信息。 |

**示例：**

完整示例代码参考[onNativeEmbedObjectParamChange](./arkts-basic-components-web-events.md#onnativeembedobjectparamchange21)。

## OnDetectBlankScreenCallback<sup>22+</sup>

type OnDetectBlankScreenCallback = (event: BlankScreenDetectionEventInfo) => void

检测到白屏时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| event | [BlankScreenDetectionEventInfo](./arkts-basic-components-web-i.md#blankscreendetectioneventinfo22) | 是 | 检测到白屏时的详细信息。 |

**示例：**

完整示例代码参考[onDetectedBlankScreen](./arkts-basic-components-web-events.md#ondetectedblankscreen22)。

## OnCameraCaptureStateChangeCallback<sup>23+</sup>

type OnCameraCaptureStateChangeCallback = (event: CameraCaptureStateChangeInfo) => void

当页面摄像设备状态发生改变时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型                                        | 必填   | 说明                         |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| event | [CameraCaptureStateChangeInfo](./arkts-basic-components-web-i.md#cameracapturestatechangeinfo23) | 是    | 网页摄像头状态发生改变时，返回原来的状态和改变后的状态。 |

## OnMicrophoneCaptureStateChangeCallback<sup>23+</sup>

type OnMicrophoneCaptureStateChangeCallback = (event: MicrophoneCaptureStateChangeInfo) => void

当页面麦克风状态发生改变时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型                                        | 必填   | 说明                         |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| event | [MicrophoneCaptureStateChangeInfo](./arkts-basic-components-web-i.md#microphonecapturestatechangeinfo23) | 是    | 网页麦克风状态发生改变时，返回原来的状态和改变后的状态。 |

## TextSelectionChangeCallback<sup>23+</sup>

type TextSelectionChangeCallback = (selectionText: string) => void

onTextSelectionChange的回调，选区内容改变时触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| selectionText | string | 是 | 返回所选文本的内容。      |

**示例：**

完整示例代码参考[onTextSelectionChange](./arkts-basic-components-web-events.md#ontextselectionchange23)。

## OnFirstScreenPaintCallback<sup>23+</sup>

type OnFirstScreenPaintCallback = (firstScreenPaint: FirstScreenPaint) => void

检测到首屏渲染结束时会触发此回调。与OnFirstMeaningfulPaintCallback关注主要内容加载完成、OnLargestContentfulPaintCallback关注最大内容元素绘制时间相比，本回调更关注首屏可见内容的渲染完成时间，适合评估用户首次视觉体验。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| firstScreenPaint | [FirstScreenPaint](./arkts-basic-components-web-i.md#firstscreenpaint23) | 是 | 检测到首屏渲染时的详细信息。 |

**示例：**

完整示例代码参考[onFirstScreenPaint](./arkts-basic-components-web-events.md#onfirstscreenpaint23)。

## OnCreateAISession

type OnCreateAISession = (id: string, params: string, result: OnAISessionCallback) => boolean

AI会话创建回调函数类型。允许自定义模型初始化和结果处理。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                                            | 必填 | 说明                 |
| ------ | --------------------------------------------- | -- | ------------------ |
| id     | string                                        | 是  | 会话任务ID。            |
| params | string                                        | 是  | 会话创建时传递的上下文数据，JSON字符串格式。|
| result | [OnAISessionCallback](#onaisessioncallback) | 是  | 用于通知系统会话创建结果的回调函数。 |

**返回值：**

| 类型      | 说明                                            |
| ------- | --------------------------------------------- |
| boolean | `true`表示使用自定义逻辑，跳过系统默认行为；`false`表示继续执行系统默认逻辑。 |

## OnExecuteAIAction

type OnExecuteAIAction = (id: string, params: string, result: OnAISessionCallback) => void

AI会话执行操作回调函数类型。用于自定义实现AI模型执行。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                                            | 必填 | 说明                 |
| ------ | --------------------------------------------- | -- | ------------------ |
| id     | string                                        | 是  | 会话任务ID。            |
| params | string                                        | 是  | 执行操作时传递的上下文数据，JSON字符串格式。|
| result | [OnAISessionCallback](#onaisessioncallback) | 是  | 用于通知系统操作执行结果的回调函数。 |

## OnDestroyAISession

type OnDestroyAISession = (id: string) => void

AI会话销毁回调函数类型。用于清理与自定义AI模型关联的资源。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型     | 必填 | 说明      |
| --- | ------ | -- | ------- |
| id  | string | 是  | 会话任务ID。 |

## OnAISessionCallback

type OnAISessionCallback = (state: AISessionResultType, content: string) => void

AI会话操作结果回调函数类型。用于报告会话创建或执行的结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                                                             | 必填 | 说明              |
| ------- | ------------------------------------------------------------------------------ | -- | --------------- |
| state   | [AISessionResultType](./arkts-basic-components-web-e.md#aisessionresulttype) | 是  | AI会话创建或执行的状态结果。 |
| content | string                                                                         | 是  | AI会话的响应内容，文本或JSON格式，包含AI模型生成的回复内容。|

## OnInputmethodAttachedCallback

type OnInputmethodAttachedCallback = () => void;

当检测到输入法绑定成功时，会触发此回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onInputmethodAttached](./arkts-basic-components-web-events.md#oninputmethodattached)。