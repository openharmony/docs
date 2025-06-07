# Class (WebResourceResponse)

Web组件资源响应对象。示例代码参考[onHttpErrorReceive事件](./arkts-basic-components-web-events.md#onhttperrorreceive)。

> **说明：**
>
> - 本模块接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## constructor

constructor()

WebResourceResponse的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## getReasonMessage

getReasonMessage(): string

获取资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源响应的状态码描述。 |

## getResponseCode

getResponseCode(): number

获取资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回资源响应的状态码。 |

## getResponseData

getResponseData(): string

获取资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 返回资源响应数据。 |

## getResponseEncoding

getResponseEncoding(): string

获取资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回资源响应的编码。 |

## getResponseHeader

getResponseHeader() : Array\<Header\>

获取资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明       |
| -------------------------- | -------- |
| Array\<[Header](./arkts-basic-components-web-i.md#header)\> | 返回资源响应头。 |

## getResponseMimeType

getResponseMimeType(): string

获取资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 返回资源响应的媒体（MIME）类型。 |

## getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

获取资源响应数据，支持多种数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|string|返回HTML格式的字符串。|
|number|返回文件句柄。|
|ArrayBuffer|返回二进制数据。|
|[Resource](../apis-arkui/arkui-ts/ts-types.md#resource)|返回`$rawfile`资源。|
|undefined|如果没有可用数据，返回`undefined`。|

## getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

获取响应数据是否已准备就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|boolean|`true`表示响应数据已准备好，`false`表示未准备好。|

## setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

设置资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                     | 必填   | 说明                                     |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | 是    | 要设置的资源响应数据。string表示HTML格式的字符串。number表示文件句柄，此句柄由系统的Web组件负责关闭。Resource表示应用rawfile目录下文件资源。ArrayBuffer表示资源的原始二进制数据。 |

## setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

设置资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明         |
| -------- | ------ | ---- | ------------ |
| encoding | string | 是    | 要设置的资源响应的编码。 |

## setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

设置资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明                 |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | 是   | 要设置的资源响应的媒体（MIME）类型。 |

## setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

设置资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明            |
| ------ | ------ | ---- | --------------- |
| reason | string | 是   | 要设置的资源响应的状态码描述。 |

## setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

设置资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                       | 必填   | 说明       |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](./arkts-basic-components-web-i.md#header)\> | 是   | 要设置的资源响应头。 |

## setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

设置资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明          |
| ---- | ------ | ---- | ------------- |
| code | number | 是   | 要设置的资源响应的状态码。如果该资源以错误结束，请参考[@ohos.web.netErrorList](arkts-apis-netErrorList.md)设置相应错误码，避免设置错误码为 ERR_IO_PENDING，设置为该错误码可能会导致XMLHttpRequest同步请求阻塞。 |

## setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

设置资源响应数据是否已经就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填  | 说明          |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | 是   | 资源响应数据是否已经就绪。<br>true表示资源响应数据已经就绪，false表示资源响应数据未就绪。默认值：true。 |