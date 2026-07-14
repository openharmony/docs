# Interfaces (其他)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准。

## 概述

本页面汇总了ArkWeb Webview模块（`@kit.ArkWeb`）中的辅助接口与数据结构类型。这些类型主要作为Web组件各能力的方法入参、回调出参或状态枚举使用，配合[WebviewController](./arkts-apis-webview-WebviewController.md)、[WebCookieManager](./arkts-apis-webview-WebCookieManager.md)、[WebStorage](./arkts-apis-webview-WebStorage.md)等核心类共同完成Web网页的加载、渲染、交互、媒体接管及性能优化等控制能力。

本模块提供Web控制能力，网页显示的能力请参考[组件描述](arkts-basic-components-web.md)；Web控制能力的完整说明及核心控制器类请参考[模块描述](./arkts-apis-webview.md)。

## WebStorageOrigin

提供Web SQL数据库的使用信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ---- |
| origin | string | 否  | 否 | 指定源的字符串索引。 |
| usage  | number | 否  | 否 | 指定源的存储量。<br>单位：byte。     |
| quota  | number | 否  | 否 | 指定源的存储配额。<br>单位：byte。   |

## WebHeader

Web组件返回的请求/响应头对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| headerKey   | string | 否 | 否 | 请求/响应头的key。   |
| headerValue | string | 否 | 否 | 请求/响应头的value。 |

## WebCustomScheme

自定义协议配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 只读 | 可选 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | 否   | 否   | 自定义协议名称。最大长度为32，其字符仅支持小写字母、数字、'.'、'+'、'-'，同时需要以字母开头。        |
| isSupportCORS  | boolean   | 否   | 否   | 是否支持跨域请求。<br>true表示支持跨域请求，false表示不支持跨域请求。<br>默认值：true。    |
| isSupportFetch | boolean   | 否   | 否   | 是否支持fetch请求。<br>true表示支持fetch请求，false表示不支持fetch请求。<br>默认值：true。           |
| isStandard<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme是否将作为标准scheme进行处理。标准scheme需要符合RFC 1738第3.1节中定义的URL规范化和解析规则。<br>true表示设置了该选项的scheme将作为标准scheme进行处理，false表示设置了该选项的scheme不作为标准scheme进行处理。<br>默认值：true。           |
| isLocal<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme是否将使用与“file”协议相同的安全规则来处理。<br>true表示设置了该选项的scheme将使用与“file”协议相同的安全规则来处理，false表示设置了该选项的scheme不使用与“file”协议相同的安全规则来处理。<br>默认值：true。           |
| isDisplayIsolated<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme的内容是否只能从相同scheme的其他内容中显示或访问。<br>true表示设置了该选项的scheme的内容只能从相同scheme的其他内容中显示或访问，false表示设置了该选项的scheme的内容不是只能从相同scheme的其他内容中显示或访问。<br>默认值：true。           |
| isSecure<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme是否将使用与应用于“https”的安全规则相同的安全规则来处理。true表示设置了该选项的scheme将使用与应用于“https”的安全规则相同的安全规则来处理，false表示设置了该选项的scheme不使用与应用于“https”的安全规则相同的安全规则来处理。<br>默认值：true。           |
| isCspBypassing<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme可以绕过内容安全策略（CSP）检查。<br>true表示设置了该选项的scheme可以绕过内容安全策略（CSP）检查，false表示设置了该选项的scheme不可以绕过内容安全策略（CSP）检查。<br>默认值：true。<br>在大多数情况下，当设置isStandard为true时，不应设置此值。         |
| isCodeCacheSupported<sup>12+</sup> | boolean   | 否   | 是   | 设置了该选项的scheme的js资源是否支持生成code cache。<br>true表示设置了该选项的scheme的js资源支持生成code cache，false表示设置了该选项的scheme的js资源不支持生成code cache。<br>默认值：false。         |

## RequestInfo<sup>12+</sup>

Web组件发送的资源请求信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称      | 类型   | 只读 | 可选 |说明        |
| ---------| ------ | -----|------|--------  |
| url      | string | 否 | 否 | 请求的链接。    |
| method   | string | 否 | 否 | 请求的方法。    |
| formData | string | 否 | 否 | 请求的表单数据。 |

## CacheOptions<sup>12+</sup>

Web组件预编译JavaScript生成字节码缓存的配置对象，用于控制字节码缓存更新。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| responseHeaders   | Array<[WebHeader](#webheader)> | 否 | 否 | 请求此JavaScript文件时服务器返回的响应头，使用ETag或Last-Modified标识文件版本，判断是否需要更新。   |

## SnapshotInfo<sup>12+</sup>

获取全量绘制结果入参。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 |  只读 |  可选 | 说明 |
|------|------|------|------|------|
| id | string | 否 | 是 | snapshot的id。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)  | 否 | 是 | web绘制的尺寸，最多支持16000px * 16000px，长度单位支持px、vp、%，需保持不同参数传入长度单位一致，默认单位vp，超过规格时返回最大规格。（示例：width:'100px'，height:'200px'。或者 width:'20%'，height:'30%'。只写数字时单位为vp。）|

## SnapshotResult<sup>12+</sup>

全量绘制回调结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 |  说明 |
|------|------|-- |--|---------|
| id | string | 否 | 是 | snapshot的id。|
| status | boolean | 否 | 是 |  snapshot的状态，正常为true，失败为false，获取全量绘制结果失败，返回size的长宽都为0，map为空。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)   | 否 | 是 | web绘制的真实尺寸，number类型，单位vp。|
| imagePixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否 | 是 | 全量绘制结果为image.PixelMap格式。|

## OfflineResourceMap<sup>12+</sup>

本地离线资源配置对象，用于配置将被[injectOfflineResources](./arkts-apis-webview-WebviewController.md#injectofflineresources12)接口注入到内存缓存的本地离线资源的相关信息，内核会根据此信息生成资源缓存，并据此控制缓存的有效期。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| urlList | Array\<string\> | 否   | 否   | 本地离线资源对应的网络地址列表，列表的第一项将作为资源的源（Origin），如果仅提供一个网络地址，则使用该地址作为这个资源的源。url仅支持HTTP或HTTPS协议，长度不超过2048。不符合上述限制时，该资源注入失败。      |
| resource | Uint8Array | 否   | 否   | 本地离线资源的内容。      |
| responseHeaders | Array\<[WebHeader](#webheader)\> | 否   | 否   | 资源对应的HTTP响应头。其中提供的Cache-Control或Expires响应头将被用于控制资源在内存缓存中的有效期。如果不提供，默认的有效期为86400秒，即1天。其中提供的Content-Type响应头将被用于定义资源的MIMEType，MODULE_JS必须提供有效的MIMEType，其他类型可不提供，无默认值，不符合标准的MIMEType会导致内存缓存失效。如果业务网页中的script标签使用了crossorigin属性，则必须在接口的responseHeaders参数中设置Cross-Origin响应头的值为anonymous或use-credentials，否则可能导致内存缓存失效。      |
| type | [OfflineResourceType](./arkts-apis-webview-e.md#offlineresourcetype12) | 否   | 否   | 资源的类型，目前仅支持JavaScript、图片和CSS类型的资源。      |

##  PdfConfiguration<sup>14+</sup>

createPdf函数输入参数。

> **说明：**
>
> 英寸与像素之间转换公式：像素 = 96 * 英寸。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| width                 | number  | 否 | 否   | 页面宽度。<br>单位：英寸。<br />推荐值：A4纸页面宽度8.27英寸。   |
| height                | number  | 否 | 否   | 页面高度。<br>单位：英寸。<br />推荐值：A4纸页面高度11.69英寸。  |
| scale                 | number  | 否 | 是   | 放大倍数。<br>取值范围：[0.0, 2.0]。如果不在取值范围内，小于0.0设置为0.0，大于2.0设置为2.0。<br>默认值：1.0。 |
| marginTop             | number  | 否 | 否   | 上边距。<br>取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginBottom          | number  | 否 | 否   | 下边距。<br>取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginRight           | number  | 否 | 否   | 右边距。<br>取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginLeft            | number  | 否 | 否   | 左边距。<br>取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| shouldPrintBackground | boolean | 否 | 是   | true表示打印背景颜色，false表示不打印背景颜色。<br>默认值：false。                            |

## ScrollOffset<sup>13+</sup>

网页当前的滚动偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型   | 只读 | 可选 | 说明                                                         |
| ---- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x    | number | 否   | 否   | 网页在水平方向的滚动偏移量。取值为网页左边界x坐标与Web组件左边界x坐标的差值。<br/>当网页向右过滚动时，取值范围为负值。<br/>当网页没有过滚动或者网页向左过滚动时，取值为0或正值。<br/>单位：vp。 |
| y    | number | 否   | 否   | 网页在垂直方向的滚动偏移量。取值为网页上边界y坐标与Web组件上边界y坐标的差值。<br/>当网页向下过滚动时，取值范围为负值。<br/>当网页没有过滚动或者网页向上过滚动时，取值为0或正值。<br/>单位：vp。 |

## HitTestValue

提供点击区域的元素信息。示例代码参考[getLastHitTest](./arkts-apis-webview-WebviewController.md#getlasthittest18)。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 | 说明|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](./arkts-apis-webview-e.md#webhittesttype) | 否 | 否 | 当前被点击区域的元素类型。|
| extra | string        | 否 | 否 |点击区域的附加参数信息。若被点击区域为图片或链接，则附加参数信息为其url地址。 |

## ControllerAttachState<sup>20+</sup>

WebViewController与Web组件的绑定状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
| ------------------------------- | - | ---------- |
| UNATTACHED | 0 | 未绑定状态。 |
| ATTACHED   | 1 | 已绑定状态。 |

## BlanklessInfo<sup>20+</sup>

页面首屏加载预测信息，主要包括首屏相似度预测值、首屏加载耗时预测值、预测错误码，应用需根据此信息来决策是否启用无白屏加载插帧方案。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| errCode | [WebBlanklessErrorCode](./arkts-apis-webview-e.md#webblanklesserrorcode20) | 否   | 否   | 无白屏加载的错误码，见[WebBlanklessErrorCode](./arkts-apis-webview-e.md#webblanklesserrorcode20)定义。 |
| similarity | number | 否   | 否   | 首屏相似度，根据历史加载首屏内容计算相似度，范围为[0, 1.0]，1.0表示完全一致，数值越接近1，相似度越高。该值存在滞后性，本地加载的相似度将在下次加载时才可反映。建议当相似度低于具体阈值（如0.33）时，应用不启用无白屏加载插帧方案。 |
| loadingTime | number | 否   | 否   | 根据历史加载首屏耗时预测本次加载耗时，单位ms，取值范围：大于0。 |

## BlanklessFrameInterpolationInfo<sup>23+</sup>

无白屏加载插帧状态信息，作为[BlanklessLoadingParam](#blanklessloadingparam23)中的回调入参使用。

**系统能力：** SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| key | string | 否   | 否   | 唯一标识插帧页面的key值。与[setBlanklessLoadingWithParams](./arkts-apis-webview-WebviewController.md#setblanklessloadingwithparams23)的key值相同。 |
| state | [BlanklessFrameInterpolationState](./arkts-apis-webview-e.md#blanklessframeinterpolationstate-23) | 否   | 否   | 当前插帧状态。 |
| timestamp | number | 否   | 否   | 插帧成功、失败或移除的时间点，UTC时间，单位ms。 |
| reason | string | 否   | 否   | 插帧失败的原因。 |

## BlanklessLoadingParam<sup>23+</sup>

无白屏加载插帧方案的加载参数。

**系统能力：** SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| enable | boolean | 否   | 否   | 是否启用无白屏加载插帧方案。<br>true表示启用，false表示不启用。 |
| duration | number | 否   | 是   | 插帧持续时间。<br>取值范围：[200, 2000] ∪ {0}，其中0表示不指定持续时间，由系统自动设置合适的持续时间。<br>单位：ms。 |
| expirationTime | number | 否   | 是   | 历史帧失效时间，UTC时间。<br>用T表示当前UTC时间，同时已知30天为2592000000ms，取值范围：(T, T + 2592000000] ∪ {0}，其中0表示不指定失效时间，采用系统默认失效时间（7天）。<br>单位：ms。 |
| callback | Callback<[BlanklessFrameInterpolationInfo](#blanklessframeinterpolationinfo23)> | 否   | 是   | 插帧成功、失败或移除后执行的回调。<br>只有在enable为true时生效。可选，不设置则不进行任何操作。 |

## HistoryItem

页面历史记录项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型                                   | 只读 | 可选 | 说明                         |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 否   | 历史页面图标的PixelMap对象。 |
| historyUrl    | string                                 | 否   | 否   | 历史记录项的url地址。        |
| historyRawUrl | string                                 | 否   | 否   | 历史记录项的原始url地址。    |
| title         | string                                 | 否   | 否   | 历史记录项的标题。           |

## MediaInfo<sup>12+</sup>

[CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12)回调函数的一个参数。包含了网页中媒体的信息。应用可以根据这些信息来创建接管网页媒体播放的播放器。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| embedID | string | 否 | 否  | 网页中的 `<video>` 或 `<audio>` 的 ID 。|
| mediaType | [MediaType](./arkts-apis-webview-e.md#mediatype12) | 否 | 否 | 媒体的类型。 |
| mediaSrcList | [MediaSourceInfo](./arkts-apis-webview-MediaSourceInfo.md)[] | 否 | 否 | 媒体的源。可能有多个源，应用需要选择一个支持的源来播放。 |
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](./arkts-apis-webview-NativeMediaPlayerSurfaceInfo.md) | 否 | 否 | 用于同层渲染的 surface 信息。 |
| controlsShown | boolean | 否 | 否 | `<video>` 或 `<audio>` 中是否有 `controls`属性。<br>true表示有，false表示没有。 |
| controlList | string[] | 否 | 否 | `<video>` 或 `<audio>` 中的 `controlslist` 属性的值。 |
| muted | boolean | 否 | 否 | 是否要求静音播放。<br>true表示静音播放，false表示未静音播放。 |
| posterUrl | string | 否 | 否 | 海报的地址。 |
| preload | [Preload](./arkts-apis-webview-e.md#preload12) | 否 | 否 | 是否需要预加载。 |
| headers | Record\<string, string\> | 否 | 否 | 播放器请求媒体资源时，需要携带的 HTTP 头。 |
| attributes | Record\<string, string\> | 否 | 否 | `<video>` 或 `<audio>` 标签中的属性。 |

## RectEvent<sup>12+</sup>

矩形定义。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 只读 | 可选 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x | number | 否 | 否 | 矩形区域左上角x坐标。 <br>单位：px。 |
| y | number | 否 | 否 | 矩形区域左上角y坐标。 <br>单位：px。 |
| width | number | 否 | 否 | 矩形的宽度。 <br>单位：px。 |
| height| number | 否 | 否 | 矩形的高度。 <br>单位：px。 |

## WebHttpCookie<sup>23+</sup>

cookie的相关字段。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | --- | ---- | ---- | ---- |
| samesitePolicy | [WebHttpCookieSameSitePolicy](./arkts-apis-webview-e.md#webhttpcookiesamesitepolicy23) | 否 | 否 | cookie的同站策略。 |
| expiresDate | string | 否 | 否 | cookie的过期时间。时间格式详见[Date](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Reference/Headers/Date)。 |
| name | string | 否 | 否 | cookie的名称。 |
| isSessionCookie | boolean | 否 | 否 | 标记该cookie是否是session cookie。<br>true表示是session cookie，false表示不是session cookie。 |
| value | string | 否 | 否 | cookie的值。 |
| path | string | 否 | 否 | cookie的路径。 |
| isHttpOnly | boolean | 否 | 否 | 标记该cookie是否只能通过http请求访问。<br>true表示仅能通过http访问，不能通过JavaScript访问，false表示可以通过JavaScript访问。 |
| isSecure | boolean | 否 | 否 | 标记该cookie是否只能通过https发送。<br>true表示仅能通过https发送，不能通过http发送，false表示可以通过http发送。 |
| domain | string | 否 | 否 | 指定哪些域名可以访问该cookie。 |
