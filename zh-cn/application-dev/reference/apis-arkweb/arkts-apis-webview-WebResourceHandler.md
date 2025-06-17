# Class (WebResourceHandler)

通过WebResourceHandler，可以提供自定义的返回头以及返回体给Web组件。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md)  | 是   | 该拦截请求的响应。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didReceiveResponseBody<sup>12+</sup>

didReceiveResponseBody(data: ArrayBuffer): void

将构造的响应体传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| data      | ArrayBuffer  | 是   | 响应体数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didFinish<sup>12+</sup>

didFinish(): void

通知Web组件被拦截的请求已经完成，并且没有更多的数据可用，调用前需要优先调用[didReceiveResponse](#didreceiveresponse12)将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

通知ArkWeb内核被拦截请求应该返回失败，调用前需要优先调用[didReceiveResponse](#didreceiveresponse12)将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | 是   | 网络错误码。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。