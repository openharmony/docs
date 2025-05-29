# Interfaces（其他）

> **说明：**
>
> - 本模块接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## WebMediaOptions<sup>10+</sup>

Web媒体策略的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| resumeInterval | number  | 否    | 被其他应用暂停的Web音视频能够自动续播的有效期，单位：秒。取值范围：[-2147483648, 2147483647]。resumeInterval值为0时，不自动续播；大于0时，将在该时间内尝试续播；小于0时，将在无限时间内尝试续播。由于近似值原因，该有效期可能存在一秒内的误差。 |
| audioExclusive | boolean | 否    | 应用内多个Web实例的音频是否独占。<br>true表示应用内多个Web实例的音频独占，false表示应用内多个Web实例的音频不独占。                       |

## ScriptItem<sup>11+</sup>

通过[javaScriptOnDocumentStart](./ts-basic-components-web-attributes.md#javascriptondocumentstart11)属性注入到Web组件的ScriptItem对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型             | 必填   | 说明                    |
| ----------- | -------------- | ---- | --------------------- |
| script      | string         | 是    | 需要注入、执行的JavaScript脚本。 |
| scriptRules | Array\<string> | 是   | 一组允许来源的匹配规则。<br>1.如果需要允许所有来源的网址，使用通配符“ * ”。<br>2.如果需要精确匹配，则描述网站地址，如"https:\//www\.example.com"。<br>3.如果模糊匹配网址，可以使用“ * ”通配符替代，如"https://*.example.com"。不允许使用"x. * .y.com"、" * foobar.com"等。<br>4.如果来源是ip地址，则使用规则2。<br>5.对于http/https以外的协议(自定义协议)，不支持使用精确匹配和模糊匹配，且必须以"://"结尾，例如"resource://"。<br>6.一组scriptRule中，如果其中一条不满足以上规则，则整组scriptRule都不生效。 |

## NestedScrollOptionsExt<sup>14+</sup>

通过NestedScrollOptionsExt可以设置上下左右四个方向的嵌套滚动规则。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型               | 必填   | 说明                   |
| -------------- | ---------------- | ---- | -------------------- |
| scrollUp  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 否    | 可滚动组件往上滚动时的嵌套滚动选项。 |
| scrollDown | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 否    | 可滚动组件往下滚动时的嵌套滚动选项。 |
| scrollLeft  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 否    | 可滚动组件往左滚动时的嵌套滚动选项。 |
| scrollRight | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 否    | 可滚动组件往右滚动时的嵌套滚动选项。 |

## NativeMediaPlayerConfig<sup>12+</sup>

用于[开启应用接管网页媒体播放功能](./ts-basic-components-web-attributes.md#enablenativemediaplayer12)的配置信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
|  enable  | boolean | 是 | 是否开启应用接管网页媒体播放功能。<br/> true表示开启应用接管网页媒体播放功能，false表示关闭应用接管网页媒体播放功能。<br/> 默认值：false。 |
|  shouldOverlay | boolean | 是 | 开启应用接管网页媒体播放功能后，应用接管网页视频的播放器画面是否覆盖网页内容。<br/> true表示改变视频图层的高度，使其覆盖网页内容。false表示不覆盖网页内容，跟原视频图层高度一样，嵌入在网页中。<br>默认值：false。 |

## ExpandedMenuItemOptions<sup>12+</sup>

自定义菜单扩展项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                             | 必填    | 说明             |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | 是     | 显示内容。     |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | 否     | 显示图标。     |
| action    | (selectedText: {plainText: string}) => void                    | 是     | 选中的文本信息。|

## AdsBlockedDetails<sup>12+</sup>

发生广告拦截时，广告资源信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型                                                                           | 必填   | 说明                    |
| ------- | --------------------------------------------------------------------------------  | ---- | ------------------------- |
| url | string  | 是    | 发生广告过滤的页面url。 |
| adsBlocked | Array\<string\>  | 是    | 被过滤的资源的url或dompath标识，被过滤的多个对象url相同则可能出现重复元素。 |

## SelectionMenuOptionsExt<sup>13+</sup>

自定义菜单扩展项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                             | 必填    | 说明             |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| onAppear   | Callback\<void\>   | 否     | 自定义选择菜单弹出时回调。     |
| onDisappear | Callback\<void\>  | 否     | 自定义选择菜单关闭时回调。     |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | 否     | 自定义选择菜单的预览内容样式，未配置时无预览内容。|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13)      | 否     | 自定义选择菜单类型。<br>默认值：`MenuType.SELECTION_MENU`。<br> 从API version 20起，`MenuType.PREVIEW_MENU`支持超链接预览。     |
| previewMenuOptions<sup>20+</sup> | [PreviewMenuOptions](#previewmenuoptions20) | 否     | 自定义选择预览菜单选项。 |

## PreviewMenuOptions<sup>20+</sup>

预览菜单选项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                             | 必填    | 说明             |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| hapticFeedbackMode   | [HapticFeedbackMode](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#hapticfeedbackmode18)   | 否     | 菜单弹出时振动效果。需配置"ohos.permission.VIBRATE"权限<br/>默认值：HapticFeedbackMode.DISABLED，菜单弹出时不振动。     |

## EmbedOptions<sup>16+</sup>

Web同层渲染的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| supportDefaultIntrinsicSize | boolean | 否    | 设置同层渲染元素是否支持固定大小 300 * 150。<br>当H5侧CSS设置了大小时，同层渲染元素大小为CSS大小，否则为固定大小。<br>为true时，固定大小为 300 * 150。<br>为false时，若H5侧CSS未设置大小，则同层渲染元素不渲染。<br>默认值：false<br>单位：px |
| supportCssDisplayChange<sup>20+</sup> | boolean | 否    | 设置同层渲染可见性接口是否支持显示属性。 <br>同层渲染可见性接口默认支持同层标签相对于视口的可见状态。 <br>设置为true时，支持显示CSS属性，包括visibility、display和宽高。 <br>设置为false时，不支持显示CSS属性，仅支持同层标签相对于视口的可见性。 |

## OnAlertEvent<sup>12+</sup>

定义网页触发alert()告警弹窗时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnBeforeUnloadEvent<sup>12+</sup>

定义刷新或关闭场景下，在即将离开当前页面时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnConfirmEvent<sup>12+</sup>

定义网页调用confirm()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnPromptEvent<sup>12+</sup>

定义网页调用prompt()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| value | string | 是 | 提示对话框的信息。                       |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnConsoleEvent<sup>12+</sup>

定义通知宿主应用JavaScript console消息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| message | [ConsoleMessage](./ts-basic-components-web.md#consolemessage) | 是 | 触发的控制台信息。                       |

## OnErrorReceiveEvent<sup>12+</sup>

定义网页加载遇到错误时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | 是 | 网页请求的封装信息。      |
| error   | [WebResourceError](./ts-basic-components-web.md#webresourceerror)    | 是 | 网页加载资源错误的封装信息 。 |

## OnHttpErrorReceiveEvent<sup>12+</sup>

定义网页收到加载资源加载HTTP错误时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | 是 | 网页请求的封装信息。      |
| response   | [WebResourceResponse](./ts-basic-components-web.md#webresourceresponse)    | 是 | 资源响应的封装信息。 |

## OnDownloadStartEvent<sup>12+</sup>

定义通知主应用开始下载一个文件。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url                | string | 是 | 文件下载的URL。                           |
| userAgent          | string | 是 | 用于下载的用户代理。                          |
| contentDisposition | string | 是 | 服务器返回的 Content-Disposition响应头，服务器可能返回空。 |
| mimetype           | string | 是 | 服务器返回内容媒体类型（MIME）信息。                |
| contentLength      | number | 是 | 服务器返回文件的长度。                         |

## OnRefreshAccessedHistoryEvent<sup>12+</sup>

定义网页刷新访问历史记录时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | 是 | 访问的url。                                  |
| isRefreshed | boolean | 是 | true表示该页面是被重新加载的（调用[refresh<sup>9+</sup>](./js-apis-webview-WebviewController.md#refresh)接口），false表示该页面是新加载的。 |

## OnRenderExitedEvent<sup>12+</sup>

定义渲染过程退出时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| renderExitReason | [RenderExitReason](./ts-basic-components-web-e.md#renderexitreason9) | 是 | 渲染进程异常退出的具体原因。 |

## OnShowFileSelectorEvent<sup>12+</sup>

定义文件选择器结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| result       | [FileSelectorResult](./ts-basic-components-web.md#fileselectorresult9) | 是 | 用于通知Web组件文件选择的结果。 |
| fileSelector | [FileSelectorParam](./ts-basic-components-web.md#fileselectorparam9) | 是 | 文件选择器的相关信息。       |

## OnResourceLoadEvent<sup>12+</sup>

定义加载url时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | 是 | 所加载的资源文件url信息。 |

## OnScaleChangeEvent<sup>12+</sup>

定义当前页面显示比例的变化时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| oldScale | number | 是 | 变化前的显示比例百分比。 |
| newScale | number | 是 | 变化后的显示比例百分比。 |

## OnHttpAuthRequestEvent<sup>12+</sup>

定义通知收到http auth认证请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [HttpAuthHandler](./ts-basic-components-web.md#httpauthhandler9) | 是 | 通知Web组件用户操作行为。   |
| host    | string                               | 是 | HTTP身份验证凭据应用的主机。 |
| realm   | string                               | 是 | HTTP身份验证凭据应用的域。  |

## OnInterceptRequestEvent<sup>12+</sup>

定义当Web组件加载url之前触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | 是 | url请求的相关信息。 |

## OnPermissionRequestEvent<sup>12+</sup>

定义通知收到获取权限请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](./ts-basic-components-web.md#permissionrequest9) | 是 | 通知Web组件用户操作行为。 |

## OnScreenCaptureRequestEvent<sup>12+</sup>

定义通知收到屏幕捕获请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](./ts-basic-components-web.md#screencapturehandler10) | 是 | 通知Web组件用户操作行为。 |

## OnContextMenuShowEvent<sup>12+</sup>

定义调用时触发的回调，以允许自定义显示上下文菜单。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](./ts-basic-components-web.md#webcontextmenuparam9) | 是 | 菜单相关参数。     |
| result | [WebContextMenuResult](./ts-basic-components-web.md#webcontextmenuresult9) | 是 | 菜单相应事件传入内核。 |

## OnSearchResultReceiveEvent<sup>12+</sup>

定义通知调用方网页页内查找的结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| activeMatchOrdinal | number  | 是 | 当前匹配的查找项的序号（从0开始）。                       |
| numberOfMatches    | number  | 是 | 所有匹配到的关键词的个数。                            |
| isDoneCounting     | boolean | 是 | 当次页内查找操作是否结束。<br>true表示当次页内查找操作结束，false表示当次页内查找操作未结束。<br>该方法可能会回调多次，直到isDoneCounting为true为止。 |

## OnScrollEvent<sup>12+</sup>

定义滚动条滑动到指定位置时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | 是 | 以网页最左端为基准，水平滚动条滚动所在位置。<br>单位：vp。 |
| yOffset | number | 是 | 以网页最上端为基准，竖直滚动条滚动所在位置。<br>单位：vp。 |

## OnSslErrorEventReceiveEvent<sup>12+</sup>

定义网页收到SSL错误时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | 是 | 通知Web组件用户操作行为。 |
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)           | 是 | 错误码。           |
| certChainData<sup>15+</sup>   | Array<Uint8Array\>           | 否 | 证书链数据。           |

## SslErrorEvent<sup>12+</sup>

用户加载资源时发生SSL错误时触发的回调详情。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称     | 类型                                 | 必填   | 说明           |
| ------- | ------------------------------------ | ---- | -------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | 是    | 通知Web组件用户操作行为。 |
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)        | 是    | 错误码。           |
| url   | string                                 | 是    | url地址。           |
| originalUrl   | string                         | 是    | 请求的原始url地址。           |
| referrer   | string                            | 是    | referrer url地址。           |
| isFatalError   | boolean                       | 是    | 是否是致命错误。<br>true表示致命错误，false表示非致命错误。           |
| isMainFrame   | boolean                        | 是    | 是否是主资源。<br>true表示主资源，false表示非主资源。           |

## OnClientAuthenticationEvent<sup>12+</sup>

定义当需要用户提供SSL客户端证书时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler  | [ClientAuthenticationHandler](./ts-basic-components-web.md#clientauthenticationhandler9) | 是 | 通知Web组件用户操作行为。  |
| host     | string                                   | 是 | 请求证书服务器的主机名。    |
| port     | number                                   | 是 | 请求证书服务器的端口号。    |
| keyTypes | Array<string\>                           | 是 | 可接受的非对称秘钥类型。    |
| issuers  | Array<string\>                           | 是 | 与私钥匹配的证书可接受颁发者。 |

## OnWindowNewEvent<sup>12+</sup>

定义网页要求用户创建窗口时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| isAlert       | boolean                                  | 是 | true代表请求创建对话框，false代表新标签页。    |
| isUserTrigger | boolean                                  | 是 | true代表用户触发，false代表非用户触发。      |
| targetUrl     | string                                   | 是 | 目标url。                        |
| handler       | [ControllerHandler](./ts-basic-components-web.md#controllerhandler9) | 是 | 用于设置新建窗口的WebviewController实例。 |

## OnTouchIconUrlReceivedEvent<sup>12+</sup>

定义设置接收到apple-touch-icon url地址时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | 是 | 接收到的apple-touch-icon url地址。 |
| precomposed | boolean | 是 | 对应apple-touch-icon是否为预合成。<br>true表示对应apple-touch-icon为预合成，false表示对应apple-touch-icon不是预合成。   |

## OnFaviconReceivedEvent<sup>12+</sup>

定义应用为当前页面接收到新的favicon时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| favicon | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | 接收到的favicon图标的PixelMap对象。 |

## OnPageVisibleEvent<sup>12+</sup>

定义旧页面不再呈现，新页面即将可见时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | 是 | 旧页面不再呈现，新页面即将可见时新页面的url地址。 |

## OnDataResubmittedEvent<sup>12+</sup>

定义网页表单可以重新提交时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [DataResubmissionHandler](./ts-basic-components-web.md#dataresubmissionhandler9) | 是 | 表单数据重新提交句柄。 |

## OnAudioStateChangedEvent<sup>12+</sup>

定义网页上的音频播放状态发生改变时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| playing | boolean | 是 | 当前页面的音频播放状态，true表示正在播放，false表示未播放。 |

## OnFirstContentfulPaintEvent<sup>12+</sup>

定义网页首次内容绘制回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| navigationStartTick    | number | 是 | 启动页面加载开始的时间，单位以微秒表示。          |
| firstContentfulPaintMs | number | 是 | 从启动页面加载开始到第一次绘制内容的时间，单位是以毫秒表示。 |

## OnLoadInterceptEvent<sup>12+</sup>

定义截获资源加载时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| data | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | 是 | url请求的相关信息。 |

## OnOverScrollEvent<sup>12+</sup>

定义网页过度滚动时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | 是 | 以网页最左端为基准，水平过度滚动的偏移量。<br>单位：vp。 |
| yOffset | number | 是 | 以网页最上端为基准，竖直过度滚动的偏移量。<br>单位：vp。 |

## JavaScriptProxy<sup>12+</sup>

定义要注入的JavaScript对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| object     | object                                   | 是    | 参与注册的对象。只能声明方法，不能声明属性。                   |
| name       | string                                   | 是    | 注册对象的名称，与window中调用的对象名一致。                |
| methodList | Array\<string\>                          | 是    | 参与注册的应用侧JavaScript对象的同步方法。                 |
| controller | [WebController](./ts-basic-components-web.md#webcontroller) \| [WebviewController<sup>9+</sup>](./ts-basic-components-web.md#webviewcontroller9) | 是    | -    | 控制器。从API version 9开始，WebController不再维护，建议使用WebviewController替代。 |
| asyncMethodList<sup>12+</sup>  | Array\<string\>      | 否    | 参与注册的应用侧JavaScript对象的异步方法。异步方法无法获取返回值。   |
| permission<sup>12+</sup>  | string  | 否    | json字符串，默认为空，通过该字符串配置JSBridge的权限管控，可以定义object、method一级的url白名单。<br>示例请参考[前端页面调用应用侧函数](../../web/web-in-page-app-function-invoking.md)。 |

## OnPageEndEvent<sup>12+</sup>

定义网页加载结束时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |

## OnPageBeginEvent<sup>12+</sup>

定义网页加载开始时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |

## OnProgressChangeEvent<sup>12+</sup>

定义网页加载进度变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| newProgress | number | 是 | 新的加载进度，取值范围为0到100的整数。                       |

## OnTitleReceiveEvent<sup>12+</sup>

定义网页document标题更改时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| title | string | 是 | document标题内容。                       |

## OnGeolocationShowEvent<sup>12+</sup>

定义通知用户收到地理位置信息获取请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| origin | string | 是 | 指定源的字符串索引。                       |
| geolocation | [JsGeolocation](./ts-basic-components-web.md#jsgeolocation) | 是 | 通知Web组件用户操作行为。                       |

## NativeEmbedVisibilityInfo<sup>12+</sup>

提供同层标签的可见性信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                | 必填   | 说明              |
| -------------  | ------------------------------------| ----- | ------------------ |
| visibility     | boolean                             | 是     | 可见性。<br>true表示可见，false表示不可见。         |
| embedId        | string                              | 是     | 同层渲染标签的唯一id。  |

## RenderProcessNotRespondingData<sup>12+</sup>

提供渲染进程无响应的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                     | 类型   | 必填 | 说明                                   |
| ------------------------ | ------ | ---- | -------------------------------------- |
| jsStack      | string | 是  | 网页的javaScript调用栈信息。       |
| pid | number | 是   | 网页的进程id。 |
| reason | [RenderProcessNotRespondingReason](./ts-basic-components-web-e.md#renderprocessnotrespondingreason12) | 是   | 触发渲染进程无响应回调的原因。 |

## FullScreenEnterEvent<sup>12+</sup>

Web组件进入全屏回调事件的详情。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| handler     | [FullScreenExitHandler](./ts-basic-components-web.md#fullscreenexithandler9) | 是    | 用于退出全屏模式的函数句柄。 |
| videoWidth  | number | 否    | 视频的宽度，单位：px。如果进入全屏的是 `<video>` 元素，表示其宽度；如果进入全屏的子元素中包含 `<video>` 元素，表示第一个子视频元素的宽度；其他情况下，为0。 |
| videoHeight  | number | 否    | 视频的高度，单位：px。如果进入全屏的是 `<video>` 元素，表示其高度；如果进入全屏的子元素中包含 `<video>` 元素，表示第一个子视频元素的高度；其他情况下，为0。 |

## LoadCommittedDetails<sup>11+</sup>

提供已提交跳转的网页的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| isMainFrame     | boolean                              | 是    | 是否是主文档。<br>true表示是主文档，false表示不是主文档。 |
| isSameDocument  | boolean                              | 是    | 是否在不更改文档的情况下进行的网页跳转。<br>true表示在不更改文档的情况下进行的网页跳转，false表示在更改文档的情况下进行的网页跳转。<br>在同文档跳转的示例：1.参考片段跳转；2.pushState或replaceState触发的跳转；3.同一页面历史跳转。  |
| didReplaceEntry | boolean                              | 是    | 是否提交的新节点替换了已有的节点。<br>true表示提交的新节点替换了已有的节点，false表示提交的新节点未替换已有的节点。<br>另外在一些子文档跳转的场景，虽然没有实际替换已有节点，但是有一些属性发生了变更。  |
| navigationType  | [WebNavigationType](./ts-basic-components-web-e.md#webnavigationtype11)  | 是    | 网页跳转的类型。       |
| url             | string                               | 是    | 当前跳转网页的URL。          |

## NativeEmbedInfo<sup>11+</sup>

提供同层标签的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                | 类型                                  | 必填   | 说明                        |
|-------------------| ------------------------------------ | ---- |---------------------------|
| id                | string             | 否    | 同层标签的id信息。             |
| type              | string                              | 否    | 同层标签的type信息，统一为小写字符。   |
| src               | string                              | 否    | 同层标签的src信息。            |
| width             | number  | 否    | 同层标签的宽，单位为px。          |
| height            | number                              | 否    | 同层标签的高，单位为px。          |
| url               | string                              | 否    | 同层标签的url信息。            |
| tag<sup>12+</sup> | string              | 否    | 标签名，统一为大写字符。              |
| params<sup>12+</sup>            | Map<string, string> | 否    | object标签包含的param标签键值对列表，该map本质为Object类型，请使用Object提供的方法操作该对象，即embed.info?.param?.["name"]。  |
| position<sup>12+</sup>          | Position            | 否    | 同层标签在屏幕坐标系中相对于Web组件的位置信息，此处区别于标准Position，单位为px。 |

## IntelligentTrackingPreventionDetails<sup>12+</sup>

提供智能防跟踪拦截的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                | 必填   | 说明         |
| ------------- | ------------------------------------| ----- | ------------ |
| host          | string                              | 是     | 网站域名。    |
| trackerHost   | string                              | 是     | 追踪者域名。  |

## WebKeyboardCallbackInfo<sup>12+</sup>

拦截网页可编辑元素拉起软键盘的回调入参，其中包括[WebKeyboardController](./ts-basic-components-web.md#webkeyboardcontroller12)、可编辑元素的属性。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| controller | [WebKeyboardController](./ts-basic-components-web.md#webkeyboardcontroller12)  | 是    | 提供控制自定义键盘的输入、删除、关闭等操作。 |
| attributes | Record<string, string> | 是    | 触发本次软键盘弹出的网页元素属性。

## WebKeyboardOptions<sup>12+</sup>

拦截网页可编辑元素拉起软键盘的回调返回值，可以指定使用的键盘类型，并返回给web内核，以控制拉起不同类型的软键盘；

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| useSystemKeyboard | boolean  | 是    | 是否使用系统默认软键盘。<br>true表示使用系统默认软键盘，false表示不使用系统默认软键盘。<br>默认值：true。 |
| enterKeyType | number | 否    | 指定系统软键盘enter键的类型，取值范围见输入框架的定义[EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10)，该参数为可选参数，当useSystemKeyboard为true，并且设置了有效的enterKeyType时候，才有效。|
| customKeyboard | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | 否    | 指定自定义键盘组件builder，可选参数，当useSystemKeyboard为false时，需要设置该参数，然后Web组件会拉起该自定义键盘。


## FirstMeaningfulPaint<sup>12+</sup>

提供网页绘制页面主要内容的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                     | 类型   | 必填 | 说明                                   |
| ------------------------ | ------ | ---- | -------------------------------------- |
| navigationStartTime      | number | 否  | 导航条加载时间，单位以微秒表示。       |
| firstMeaningfulPaintTime | number | 否   | 绘制页面主要内容时间，单位以毫秒表示。 |

## LargestContentfulPaint<sup>12+</sup>

提供网页绘制页面主要内容的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                      | 类型   | 必填 | 说明                                     |
| ------------------------- | ------ | ---- | ---------------------------------------- |
| navigationStartTime       | number | 否   | 导航条加载时间，单位以微秒表示。         |
| largestImagePaintTime     | number | 否   | 最大图片加载的时间，单位是以毫秒表示。   |
| largestTextPaintTime      | number | 否   | 最大文本加载时间，单位是以毫秒表示。     |
| largestImageLoadStartTime | number | 否   | 最大图片开始加载时间，单位是以毫秒表示。 |
| largestImageLoadEndTime   | number | 否   | 最大图片结束记载时间，单位是以毫秒表示。 |
| imageBPP                  | number | 否   | 最大图片像素位数。                           |

## NativeEmbedDataInfo<sup>11+</sup>

提供同层标签生命周期变化的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| status     | [NativeEmbedStatus](./ts-basic-components-web-e.md#nativeembedstatus11)             | 否    | 同层标签生命周期状态。 |
| surfaceId  | string                              | 否    | NativeImage的psurfaceid。  |
| embedId | string                              | 否    | 同层标签的唯一id。  |
| info  | [NativeEmbedInfo](./ts-basic-components-web-i.md#nativeembedinfo11)  | 否    | 同层标签的详细信息。       |

## NativeEmbedTouchInfo<sup>11+</sup>

提供手指触摸到同层标签的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | 否    | 同层标签的唯一id。 |
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent对象说明)  | 否    | 手指触摸动作信息。 |
| result<sup>12+</sup>     | [EventResult](./ts-basic-components-web.md#eventresult12)   | 否    | 通知Web组件手势事件的消费结果。 |

## OnLoadStartedEvent<sup>20+</sup>

定义网页加载开始时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |

## OnLoadFinishedEvent<sup>20+</sup>

定义网页加载结束时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |
