# Class (WebResourceRequest)

Web组件获取资源请求对象。示例代码参考[onErrorReceive事件](./arkts-basic-components-web-events.md#onerrorreceive)。

> **说明：**
>
> - 本模块接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

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
| Array\<[Header](./arkts-basic-components-web-i.md#header)\> | 返回资源请求头信息。 |

## getRequestUrl

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

## isMainFrame

isMainFrame(): boolean

判断资源请求是否为主frame。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否为主frame。<br>true表示返回资源请求为主frame，false表示返回资源请求不为主frame。 |

## isRedirect

isRedirect(): boolean

判断资源请求是否被服务端重定向。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否被服务端重定向。<br>true表示返回资源请求被服务端重定向，false表示返回资源请求未被服务端重定向。 |

## isRequestGesture

isRequestGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

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
| string | 返回请求方法。 |