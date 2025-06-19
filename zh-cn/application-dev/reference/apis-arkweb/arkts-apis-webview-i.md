# Interfaces（其他）

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## WebStorageOrigin

提供Web SQL数据库的使用信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ---- |
| origin | string | 否  | 否 | 指定源的字符串索引。 |
| usage  | number | 否  | 否 | 指定源的存储量。     |
| quota  | number | 否  | 否 | 指定源的存储配额。   |

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

**系统能力：**: SystemCapability.Web.Webview.Core

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
| responseHeaders   | Array<[WebHeader](#webheader)> | 否 | 否 | 请求此JavaScript文件时服务器返回的响应头，使用E-Tag或Last-Modified标识文件版本，判断是否需要更新。   |

## SnapshotInfo<sup>12+</sup>

获取全量绘制结果入参。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 |  必填 | 说明 |
|------|------|------|------|
| id | string | 否 | snapshot的id。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)  | 否 | web绘制的尺寸，最多支持16000px * 16000px，长度单位支持px、vp、%，需保持不同参数传入长度单位一致，默认单位vp，超过规格时返回最大规格。（示例：width:'100px'，height:'200px'。或者 width:'20%'，height:'30%'。只写数字时单位为vp。）|

## SnapshotResult<sup>12+</sup>

全量绘制回调结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 |  说明 |
|------|------|--|---------|
| id | string | 否 | snapshot的id。|
| status | boolean | 否 |  snapshot的状态，正常为true，失败为false，获取全量绘制结果失败，返回size的长宽都为0，map为空。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)   | 否 | web绘制的真实尺寸，number类型，单位vp。|
| imagePixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否 | 全量绘制结果image.pixelMap格式。|

## OfflineResourceMap<sup>12+</sup>

本地离线资源配置对象，用于配置将被[injectOfflineResources](./arkts-apis-webview-WebviewController.md#injectofflineresources12)接口注入到内存缓存的本地离线资源的相关信息，内核会根据此信息生成资源缓存，并据此控制缓存的有效期。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 只读 | 可选 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| urlList | Array\<string\> | 否   | 否   | 本地离线资源对应的网络地址列表，列表的第一项将作为资源的源(Origin)，如果仅提供一个网络地址，则使用该地址作为这个资源的源。url仅支持http或https协议，长度不超过2048。      |
| resource | Uint8Array | 否   | 否   | 本地离线资源的内容。      |
| responseHeaders | Array<[WebHeader](#webheader)> | 否   | 否   | 资源对应的HTTP响应头。其中提供的Cache-Control或Expires响应头将被用于控制资源在内存缓存中的有效期。如果不提供，默认的有效期为86400秒，即1天。其中提供的Content-Type响应头将被用于定义资源的MIMEType，MODULE_JS必须提供有效的MIMEType，其他类型可不提供，无默认值，不符合标准的MIMEType会导致内存缓存失效。如果业务网页中的script标签使用了crossorigin属性，则必须在接口的responseHeaders参数中设置Cross-Origin响应头的值为anonymous或use-credentials。      |
| type | [OfflineResourceType](./arkts-apis-webview-e.md#offlineresourcetype12) | 否   | 否   | 资源的类型，目前仅支持Javascript、图片和CSS类型的资源。      |

##  PdfConfiguration<sup>14+</sup>

createPdf函数输入参数。

> **说明：**
>
> 英寸与像素之间转换公式：像素 = 96 * 英寸。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                  | 类型    | 必填 | 说明                                                         |
| --------------------- | ------- | ---- | ------------------------------------------------------------ |
| width                 | number  | 是   | 页面宽度。<br>单位：英寸。<br />推荐值：A4纸页面宽度8.27英寸。   |
| height                | number  | 是   | 页面高度。<br>单位：英寸。<br />推荐值：A4纸页面高度11.69英寸。  |
| scale                 | number  | 否   | 放大倍数。<br>取值范围：[0.0, 2.0]。如果不在取值范围内，小于0.0设置为0.0，大于2.0设置为2.0。<br>默认值：1.0。 |
| marginTop             | number  | 是   | 上边距。<br>取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginBottom          | number  | 是   | 下边距。<br>取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginRight           | number  | 是   | 右边距。<br>取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| marginLeft            | number  | 是   | 左边距。<br>取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。<br>单位：英寸。 |
| shouldPrintBackground | boolean | 否   | true表示打印背景颜色，false表示不打印背景颜色。<br>默认值：false。                            |

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

## HistoryItem

页面历史记录项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型                                   | 只读 | 可选 | 说明                         |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是   | 否   | 历史页面图标的PixelMap对象。 |
| historyUrl    | string                                 | 否   | 否   | 历史记录项的url地址。        |
| historyRawUrl | string                                 | 否   | 否   | 历史记录项的原始url地址。    |
| title         | string                                 | 否   | 否   | 历史记录项的标题。           |

## MediaInfo<sup>12+<sup>

[CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12)回调函数的一个参数。
包含了网页中媒体的信息。应用可以根据这些信息来创建接管网页媒体播放的播放器。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| embedID | string | 是 | 网页中的 `<video>` 或 `<audio>` 的 ID 。|
| mediaType | [MediaType](./arkts-apis-webview-e.md#mediatype12) | 是 | 媒体的类型。 |
| mediaSrcList | [MediaSourceInfo](./arkts-apis-webview-MediaSourceInfo.md)[] | 是 | 媒体的源。可能有多个源，应用需要选择一个支持的源来播放。 |
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](./arkts-apis-webview-NativeMediaPlayerSurfaceInfo.md) | 是 | 用于同层渲染的 surface 信息。 |
| controlsShown | boolean | 是 | `<video>` 或 `<audio>` 中是否有 `controls`属性。<br>true表示有，false表示没有。 |
| controlList | string[] | 是 | `<video>` 或 `<audio>` 中的 `controlslist` 属性的值。 |
| muted | boolean | 是 | 是否要求静音播放。<br>true表示静音播放，false表示未静音播放。 |
| posterUrl | string | 是 | 海报的地址。 |
| preload | [Preload](./arkts-apis-webview-e.md#preload12) | 是 | 是否需要预加载。 |
| headers | Record\<string, string\> | 是 | 播放器请求媒体资源时，需要携带的 HTTP 头。 |
| attributes | Record\<string, string\> | 是 | `<video>` 或 `<audio>` 标签中的属性。 |

## RectEvent<sup>12+<sup>

矩形定义。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 只读 | 可选 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x  | number   | 否   | 否   | 矩形区域左上角x坐标。    |
| y  | number   | 否   | 否   | 矩形区域左上角y坐标。    |
| width  | number   | 否   | 否   | 矩形的宽度。    |
| height  | number   | 否   | 否   | 矩形的高度。    |