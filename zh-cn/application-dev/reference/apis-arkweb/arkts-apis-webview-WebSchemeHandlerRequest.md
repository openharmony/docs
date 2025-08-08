# Class (WebSchemeHandlerRequest)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

通过WebSchemeHandler拦截到的请求。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## getHeader<sup>12+</sup>

getHeader(): Array\<WebHeader\>

获取资源请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)\> | 返回资源请求头信息。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getRequestUrl<sup>12+</sup>

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getRequestMethod<sup>12+</sup>

getRequestMethod(): string

获取请求方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回请求方法。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getReferrer<sup>12+</sup>

getReferrer(): string

获取referrer。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 获取到的referrer。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## isMainFrame<sup>12+</sup>

isMainFrame(): boolean

判断资源请求是否为主frame。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| boolean | 判断资源请求是否为主frame，如果资源请求是主frame则返回true，否则返回false。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## hasGesture<sup>12+</sup>

hasGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联，如果返回资源请求与手势相关联则返回true，否则返回false。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getHttpBodyStream<sup>12+</sup>

getHttpBodyStream(): WebHttpBodyStream | null

获取资源请求中的WebHttpBodyStream。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [WebHttpBodyStream](./arkts-apis-webview-WebSchemeHandler.md) \| null | 返回资源请求中的WebHttpBodyStream，如果没有则返回null。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getRequestResourceType<sup>12+</sup>

getRequestResourceType(): WebResourceType

获取资源请求的资源类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [WebResourceType](./arkts-apis-webview-e.md#webresourcetype12) | 返回资源请求的资源类型。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## getFrameUrl<sup>12+</sup>

getFrameUrl(): string

获取触发此请求的Frame的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回触发此请求的Frame的URL。 |

**示例：**

完整示例代码参考[onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。