# Web

>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供具有网页显示能力的Web组件。

## 权限列表

ohos.permission.INTERNET

ohos.permission.READ_USER_STORAGE

## 子组件

无

## 接口

-   Web\(options: { src: string, controller?: WebController }\)

    表1 options参数说明

    | 参数名        | 参数类型                            | 必填   | 默认值  | 参数描述    |
    | ---------- | ------------------------------- | ---- | ---- | ------- |
    | src        | string                          | 是    | -    | 网页资源地址。 |
    | controller | [WebController](#WebController) | 否    | -    | 控制器。    |


> ![icon-note.gif](public_sys-resources/icon-note.gif)**说明：**
>
> - 不支持转场动画；
> - 不支持音视频播放；
> - 不支持横竖屏事件。

## 属性
| 名称              | 参数类型                                                     | 默认值         | 描述                                                         |
| ----------------- | ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ |
| domStorageAccess  | boolean                                                      | false          | 设置是否开启DOM Storage API权限，默认未开启。                |
| fileAccess        | boolean                                                      | true           | 设置是否开启Web中通过FILE方式访问应用中的本地文件， 默认启用。 |
| geolocationAccess | boolean                                                      | true           | 设置是否允许访问地理位置， 默认允许访问。                    |
| imageAccess       | boolean                                                      | true           | 设置是否允许自动加载图片资源，默认允许。                     |
| javaScriptAccess  | boolean                                                      | true           | 设置是否允许执行JavaScript脚本，默认允许执行。               |
| mixedMode         | MixedMode                                                    | MixedMode.None | 设置是否允许加载HTTP和HTTPS混合内容，默认不允许加载HTTP和HTTPS混合内容。 |
| onlineImageAccess | boolean                                                      | true           | 设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。 |
| zoomAccess        | boolean                                                      | true           | 设置是否支持使用屏幕控件或手势进行缩放，默认允许执行缩放。   |
| javaScriptProxy   | { <br> obj: object, <br/> name: string, <br/> methodList: Array<string>, <br/> controller: [WebController](#WebController)  <br>} | -              | 注入ArkUI对象到HTML中，并在HTML中调用该对象的方法，参数不支持更新。 <br> -obj: 参与注册的对象。 <br> -name: 注册对象的名称，与HTML中调用的对象名一致。<br> -methodList: 参与注册的方法。<br> -controller: 控制器。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 通用属性仅支持width、height、padding、margin、border。
- MixedMode枚举说明

  | 名称         | 描述                                       |
  | ---------- | ---------------------------------------- |
  | All        | 允许加载HTTP和HTTPS混合内容。                      |
  | Compatible | 混合内容兼容性模式，一些不安全的内容可能被安全来源加载，其他类型的内容将被阻止。 |
  | None       | 不允许加载HTTP和HTTPS混合内容。                     |

## 事件

通用事件仅支持onFocus。

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void) | <p>下载开始时触发该回调。<br />url：Web引擎返回的下载URL。<br />userAgent：Web引擎返回的用户代理名称。<br />contentDisposition：Web引擎返回的响应头。<br />mimetype：Web引擎返回的mimetype信息。<br />contentLength：Web引擎返回的内容长度。</p> |
| onGeolocationHide(callback: () => void)                      | <p>调用onGeolocationShow时发出的地理位置权限请求被取消后触发该回调。</p> |
| onGeolocationShow(callback: (event?: { origin: string, geolocation: JsGeolocation }) => void) | <p>应用尝试使用地理位置时触发该回调，并向用户请求权限。<br/>origin：尝试获取地理位置的Web内容的来源。<br/>geolocation：用于请求地理位置权限。</p> |
| onPageBegin(callback: (event?: { url: string }) => void)     | <p>网页加载时触发该回调。<br/>url：Web引擎返回的URL。</p>    |
| onPageEnd(callback: (event?: { url: string }) => void)       | <p>网页加载结束时触发该回调。<br/>url：Web引擎返回的URL。</p> |
| onProgressChange(callback: (event?: { newProgress: number }) => void) | <p>网页加载进度变化时触发该回调。<br/>newProgress：加载进度，取值范围为0到100的整数。</p> |
| onTitleReceive(callback: (event?: { title: string }) => void) | <p>网页主页面标题更改时触发该回调。<br/>title：标题内容。</p> |
| onErrorReceive(callback: (event?: { request: WebResourceRequest, error: WebResourceError }) => void) | <p>网页加载错误时触发该回调。<br/>request：网页的请求信息。<br/>error：网页的错误信息 。</p> |
| onHttpErrorReceive(callback: (event?: { request: WebResourceRequest, response: WebResourceResponse }) => void) | <p>网页加载出现网络错误时触发该回调。<br/>request：网页的请求信息。<br/>response：网页的响应信息</p> |
| onConsole(callback: (event?: { message: ConsoleMessage }) => boolean) | <p>向主应用报告JavaScript控制台消息时触发该回调。<br/>message：触发的控制台信息。</p> |
| onAlert(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>网页触发alert()告警弹窗时触发。<br />url：Web引擎返回的下载URL。<br />message：Web引擎返回的信息。<br />JsResult：Web引擎返回的弹窗确认或弹窗取消功能对象。</p> |
| onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>网页重新加载或关闭时触发。<br />url：Web引擎返回的下载URL。<br />message：Web引擎返回的信息。<br />JsResult：Web引擎返回的弹窗确认或弹窗取消功能对象。</p> |
| onConfirm(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>即将离开当前页面（刷新或关闭）时触发。<br />url：Web引擎返回的下载URL。<br />message：Web引擎返回的信息。<br />JsResult：Web引擎返回的弹窗确认或弹窗取消功能对象。</p> |

### JsResult  对象说明

Web引擎返回的弹窗确认或弹窗取消功能对象。

- 接口

  | 接口名称              | 功能描述          |
  | --------------------- | ----------------- |
  | handleCancel(): void  | <p>取消弹窗。</p> |
  | handleConfirm(): void | <p>确认弹窗。</p> |

### JsGeolocation 对象说明

用于请求地理位置权限。

- 接口

  | 接口名称                                                     | 功能描述                                                     |
  | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | invoke(origin: string, allow: boolean, retain: boolean): void | <p>通知系统用户是否批准该应用使用地理位置权限。<br/>origin：尝试获取地理位置的Web内容的来源。<br/>allow：用户是否批准该应用使用地理位置权限。true: 允许访问，false: 不允许访问。<br/>retain：是否允许将地理位置权限状态保存到系统中。true: 允许，false: 不允许。</p> |

### WebResourceRequest对象说明

- 接口

  | 接口名称                          | 功能描述                             |
  | --------------------------------- | ------------------------------------ |
  | getRequestUrl(): string           | 获取请求的url信息。                  |
  | isRequestGesture(): boolean       | 获取请求是否与手势关联。             |
  | isMainFrame(): boolean            | 获取请求是否时为了获取主窗口的信息。 |
  | isRedirect(): boolean             | 获取请求是否重定向。                 |
  | getRequestHeader(): Array<Header> | 获取请求头信息。                     |

### WebResourceError对象说明

- 接口

  | 接口名称               | 功能描述                 |
  | ---------------------- | ------------------------ |
  | getErrorInfo(): string | 获取加载资源的错误信息。 |
  | getErrorCode(): number | 获取加载资源的错误码。   |

### WebResourceResponse对象说明

- 接口

  | 接口名称                           | 功能描述               |
  | ---------------------------------- | ---------------------- |
  | getResponseData(): string          | 获取响应数据。         |
  | getResponseEncoding(): string      | 获取响应的编码。       |
  | getResponseMimeType(): string      | 获取响应的MIME类型。   |
  | getResponseCode(): number          | 获取响应的状态码。     |
  | getReasonMessage(): string         | 获取响应的状态码描述。 |
  | getResponseHeader(): Array<Header> | 获取响应头信息。       |

### ConsoleMessage对象说明

- 接口

  | 接口名称                        | 功能描述                       |
  | ------------------------------- | ------------------------------ |
  | getMessage(): string            | 获取ConsoleMessage的日志信息。 |
  | getSourceId(): string           | 获取ConsoleMessage的源的Id。   |
  | getLineNumber(): number         | 获取ConsoleMessage的行数。     |
  | getMessageLevel(): MessageLevel | 获取ConsoleMessage的信息级别。 |

- MessageLevel枚举说明

  | 名称  | 描述       |
  | ----- | :--------- |
  | Debug | 调试级别。 |
  | Error | 错误级别。 |
  | Info  | 消息级别。 |
  | Log   | 日志级别。 |
  | Warn  | 警告级别。 |

## WebController

Web 组件的控制器。

### 创建对象

```
webController: WebController = new WebController()
```

### accessBackward

accessBackward(): boolean

当前页面是否可后退。

### accessForward

accessForward(): boolean

当前页面是否可前进。

### accessStep

accessStep(step: number): boolean

当前页面是否可前进或者后退step步。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                  |
  | ---- | ------ | ---- | ---- | --------------------- |
  | step | number | 是    | -    | 要跳转的步数，正数代表前进，负数代表后退。 |

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

清空指定对象已注册的JavaScript方法。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                    |
  | ---- | ------ | ---- | ---- | ----------------------- |
  | name | string | 是    | -    | 注册对象的名称，与HTML中调用的对象名一致。 |

### backward

backward(): void

页面后退。

### forward

forward(): void

页面前进。

### getHitTest

getHitTest(): HitTestType

获取当前已点击的对象类型。

- HitTestType枚举说明

  | 名称      | 描述                               |
  | ------- | -------------------------------- |
  | Edit    | 可编辑的区域。                          |
  | Email   | 邮件地址。                            |
  | Http    | HTTP网址的HTML \<a\>标签。             |
  | HttpImg | HTTP网址与\<img\>标签组成的HTML \<a\>标签。 |
  | Img     | HTML \<img\>标签。                  |
  | Map     | 地图地址。                            |
  | Phone   | 电话号码。                            |
  | Unknown | 未知内容。                            |

### loadData

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string }): void

加载数据。

- options参数说明

  | 参数名        | 参数类型   | 必填   | 默认值  | 参数描述               |
  | ---------- | ------ | ---- | ---- | ------------------ |
  | data       | string | 是    | -    | 需要加载的数据。           |
  | mimeType   | string | 是    | -    | 媒体类型，格式为''\*/\*''。 |
  | encoding   | string | 是    | -    | 编码类型。              |
  | baseUrl    | string | 否    | -    | 基础URL。             |
  | historyUrl | string | 否    | -    | 历史URL。             |

### loadUrl

loadUrl(options:{ url: string, headers?: Array<{ key: string, value: string }> }): void

加载URL。

- options参数说明

  | 参数名                   | 参数类型                                  | 必填   | 默认值  | 参数描述       |
  | --------------------- | ------------------------------------- | ---- | ---- | ---------- |
  | url                   | string                                | 是    | -    | 需要加载的 URL。 |
  | additionalHttpHeaders | Array<{ key: string, value: string }> | 否    | []   | HTTP附加信息。  |

### onActive

onActive(): void

页面重新激活。当Web被重新激活为活跃状态时，执行此方法。

### onInactive

onInactive(): void

页面暂停渲染。当Web被切换到后台不可见状态时，执行此方法。

### refresh

refresh(): void

刷新页面。

### registerJavaScriptProxy

registerJavaScriptProxy(options: { obj: object, name: string, methodList: string[] }): void

将JavaScript对象与方法注册到Web内核，可被已加载的HTML直接调用。注册后，须调用refresh接口生效。

- options 参数说明

  | 参数名        | 参数类型     | 必填   | 默认值  | 参数描述                    |
  | ---------- | -------- | ---- | ---- | ----------------------- |
  | obj        | object   | 是    | -    | 参与注册的对象。                |
  | name       | string   | 是    | -    | 注册对象的名称，与HTML中调用的对象名一致。 |
  | methodList | string[] | 是    | -    | 参与注册的方法。                |

### runJavaScript

runJavaScript(options: { script: string, callback?: (result: string) => void }): void

执行JavaScript脚本。

- options参数说明

  | 参数名      | 参数类型                     | 必填   | 默认值  | 参数描述                                 |
  | -------- | ------------------------ | ---- | ---- | ------------------------------------ |
  | script   | string                   | 是    | -    | JavaScript脚本。                        |
  | callback | (result: string) => void | 否    | -    | 回调执行JavaScript脚本结果，默认result为null字符串。 |

### requestFocus

requestFocus(): void

Web组件获焦。

### stop

stop(): void

停止页面加载。

## 示例

```
// webComponent.ets
@Entry
@Component
struct WebComponent {
  @State javaScriptAccess: boolean = true;
  @State fileAccess: boolean = true;
  controller: WebController = new WebController();
  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
      .javaScriptAccess(this.javaScriptAccess)
      .fileAccess(this.fileAccess)
      .onPageEnd(e => {
        // test() 在 index.html 中已定义
        this.controller.runJavaScript('test()');
        console.log("url: ", e.url);
      })
    }
  }
}
```
```
<!-- index.html -->
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<body>
    Hello world!
</body>
<script type="text/javascript">
	function test() {
		console.log('Ark WebComponent');
	}
</script>
</html>
```

![](figures/Web.png)