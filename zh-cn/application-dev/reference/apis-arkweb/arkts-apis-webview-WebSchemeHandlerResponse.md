# Class (WebSchemeHandlerResponse)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebSchemeHandlerResponse是自定义scheme拦截场景中用于构造HTTP响应数据的类。开发者通过该类创建Response对象，设置HTTP状态码、状态文本、媒体类型、字符集、自定义响应头、网络错误码以及重定向URL等属性，然后通过WebResourceHandler将自定义响应返回给Web组件。该类是自定义资源拦截的核心数据载体。

WebSchemeHandlerResponse与WebResourceHandler配合使用：开发者构造WebSchemeHandlerResponse对象并填充响应属性，然后通过WebResourceHandler的didReceiveResponse方法将响应头发送给被拦截的请求。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## constructor<sup>12+</sup>

constructor()

Response的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview, WebNetErrorList } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('response').onClick(() => {
        let response = new webview.WebSchemeHandlerResponse();
        try {
          response.setUrl("http://www.example.com")
          response.setStatus(200)
          response.setStatusText("OK")
          response.setMimeType("text/html")
          response.setEncoding("utf-8")
          response.setHeaderByName("header1", "value1", false)
          response.setNetErrorCode(WebNetErrorList.NET_OK)
          console.info("[schemeHandler] getUrl:" + response.getUrl())
          console.info("[schemeHandler] getStatus:" + response.getStatus())
          console.info("[schemeHandler] getStatusText:" + response.getStatusText())
          console.info("[schemeHandler] getMimeType:" + response.getMimeType())
          console.info("[schemeHandler] getEncoding:" + response.getEncoding())
          console.info("[schemeHandler] getHeaderByName:" + response.getHeaderByName("header1"))
          console.info("[schemeHandler] getNetErrorCode:" + response.getNetErrorCode())

        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Web({ src: 'https://www.example.com', controller: this.controller })
    }
  }
}

```

## setUrl<sup>12+</sup>

setUrl(url: string): void

给当前的Response设置重定向或因HSTS而更改后的URL，设置了url后会触发请求的跳转。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| url | string | 是 | 重定向或因HSTS而更改后的URL。 |

**示例：**

完整示例代码参考[constructor](#constructor12)。

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

## setNetErrorCode<sup>12+</sup>

setNetErrorCode(code: WebNetErrorList): void

给当前的Response设置网络错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | 是 | 网络错误码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## setStatus<sup>12+</sup>

setStatus(code: number): void

给当前的Response设置HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| code | number | 是 | HTTP状态码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## setStatusText<sup>12+</sup>

setStatusText(text: string): void

给当前的Response设置状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| text | string | 是 | 状态文本。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## setMimeType<sup>12+</sup>

setMimeType(type: string): void

给当前的Response设置媒体类型。例如，注入HTML内容时设置为text/html，注入JSON数据时设置为application/json。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| type | string | 是 | 媒体类型（MIME类型）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## setEncoding<sup>12+</sup>

setEncoding(encoding: string): void

给当前的Response设置字符编码格式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| encoding | string | 是 | 字符编码格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## setHeaderByName<sup>12+</sup>

setHeaderByName(name: string, value: string, overwrite: boolean): void

给当前的Response设置头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| name | string | 是 | 头部（header）的名称，指定要设置的HTTP响应头字段名。常见值包括'Content-Type'（内容类型）、'Authorization'（授权信息）、'Cache-Control'（缓存控制）等。 |
| value | string | 是 | 头部（header）的值，指定HTTP响应头字段的具体内容。需要与name参数对应的头部字段匹配，如name为'Content-Type'时，value可以是'text/html; charset=utf-8'。 |
|  overwrite | boolean | 是   | 如果为true，将覆盖现有的头部，否则不覆盖。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getUrl<sup>12+</sup>

getUrl(): string

获取重定向或因HSTS而更改后的URL。

风险提示：若想获取URL来做JavascriptProxy通信接口认证，请使用[getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](./arkts-apis-webview-WebviewController.md#getlastjavascriptproxycallingframeurl12)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 获取经过重定向或因HSTS而更改后的URL。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getNetErrorCode<sup>12+</sup>

getNetErrorCode(): WebNetErrorList

获取Response的网络错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | 返回Response的网络错误码。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getStatus<sup>12+</sup>

getStatus(): number

获取Response的HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| number | 返回Response的HTTP状态码。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getStatusText<sup>12+</sup>

getStatusText(): string

获取Response的状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 状态文本。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getMimeType<sup>12+</sup>

getMimeType(): string

获取Response的媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 返回响应内容的MIME类型字符串，如'text/html'、'application/json'等。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getEncoding<sup>12+</sup>

getEncoding(): string

获取Response的字符编码格式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 返回响应内容的字符编码格式，如'utf-8'、'gbk'等。|

**示例：**

完整示例代码参考[constructor](#constructor12)。

## getHeaderByName<sup>12+</sup>

getHeaderByName(name: string): string

按名称获取Response头部字段值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                  |
| ------- | ---------------- | ---- | -------------------- |
| name     | string | 是   | 要获取的响应头字段名称。      |


**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 指定名称的响应头字段对应的值。|

**示例：**

完整示例代码参考[constructor](#constructor12)。