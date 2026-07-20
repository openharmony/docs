# Class (WebResourceRequest)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebResourceRequest是Web组件中表示网络资源请求的类，提供了关于请求资源的详细元数据。该对象在`onErrorReceive`、`onHttpErrorReceive`以及请求拦截等事件回调中使用，用于帮助开发者诊断网络错误、监控请求状态和实现资源拦截控制。通过使用该类，应用可以提升错误处理能力、增强请求可控性和优化用户体验。示例代码参考[onErrorReceive事件](./arkts-basic-components-web-events.md#onerrorreceive)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 8开始支持。
>
> - 示例效果请以真机运行为准。

## constructor

constructor()

WebResourceRequest的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## getRequestHeader

getRequestHeader(): Array\<Header\>

获取资源请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array<[Header](./arkts-basic-components-web-i.md#header)> | 返回包含请求头键值对信息的数组，每个Header对象包含请求头的名称和对应的值，例如User-Agent、Content-Type等。 |

## getRequestUrl

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回完整的资源请求URL字符串，包含协议、域名、路径、查询参数等完整信息。 |

## isMainFrame

isMainFrame(): boolean

判断资源请求是否为主frame。用于区分处理主frame和子frame请求。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否为主frame的判断结果。<br>true表示资源请求为主frame，false表示资源请求不为主frame。 |

## isRedirect

isRedirect(): boolean

判断资源请求是否被服务端重定向。用于检查请求重定向链，识别恶意重定向。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否被服务端重定向。<br>true表示资源请求被服务端重定向，false表示资源请求未被服务端重定向。 |

## isRequestGesture

isRequestGesture(): boolean

判断资源请求是否与手势（如点击）相关联。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联。<br>true表示返回资源请求与手势（如点击）相关联，false表示返回资源请求与手势（如点击）不相关联。 |

## getRequestMethod<sup>9+</sup>

getRequestMethod(): string

获取请求方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 返回HTTP请求方法字符串，常见值包括GET、POST、PUT、DELETE等，表示该资源请求所使用的HTTP方法类型。 |