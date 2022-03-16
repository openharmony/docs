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

    | 参数名     | 参数类型                        | 必填 | 默认值 | 参数描述       |
    | ---------- | ------------------------------- | ---- | ------ | -------------- |
    | src        | string                          | 是   | -      | 网页资源地址。 |
    | controller | [WebController](#WebController) | 否   | -      | 控制器。       |


> ![icon-note.gif](public_sys-resources/icon-note.gif)**说明：**
>
> - 不支持转场动画；
> - 不支持多实例；
> - 仅支持本地音视频播放。

## 属性
| 名称              | 参数类型                                                     | 默认值         | 描述                                                         |
| ----------------- | ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ |
| domStorageAccess  | boolean                                                      | false          | 设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启。 |
| fileAccess        | boolean                                                      | true           | 设置是否开启通过$rawfile(filepath/filename)访问应用中rawfile路径的文件， 默认启用。 |
| imageAccess       | boolean                                                      | true           | 设置是否允许自动加载图片资源，默认允许。                     |
| javaScriptProxy   | { <br>  object: object, <br/> name: string, <br/> methodList: Array\<string\>, <br/> controller: WebController <br>} | -              | 注入JavaScript对象到window对象中，并在window对象中调用该对象及其方法。所有参数不支持更新。 <br/> object: 参与注册的对象。只能声明方法，不能声明属性 <br/> name: 参与注册对象的名称，与JS中调用的对象名一致。<br/> methodList: 参与注册的对象中的方法列表。<br/> controller: 控制器。 |
| javaScriptAccess  | boolean                                                      | true           | 设置是否允许执行JavaScript脚本，默认允许执行。               |
| mixedMode         | [MixedMode](#MixedMode)                                      | MixedMode.None | 设置是否允许加载超文本传输协议（HTTP）和超文本传输安全协议（HTTPS）混合内容，默认不允许加载HTTP和HTTPS混合内容。 |
| onlineImageAccess | boolean                                                      | true           | 设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。 |
| zoomAccess        | boolean                                                      | true           | 设置是否支持手势进行缩放，默认允许执行缩放。                 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 通用属性仅支持[width](ts-universal-attributes-size.md#属性)、[height](ts-universal-attributes-size.md#属性)、[padding](ts-universal-attributes-size.md#属性)、[margin](ts-universal-attributes-size.md#属性)、[border](ts-universal-attributes-border.md#属性)。
- <span id="MixedMode">MixedMode枚举说明</span>

  | 名称       | 描述                                                         |
  | ---------- | ------------------------------------------------------------ |
  | All        | 允许加载HTTP和HTTPS混合内容。                                |
  | Compatible | 混合内容兼容性模式，一些不安全的内容可能被安全来源加载，其他类型的内容将被阻止。 |
  | None       | HTTP和HTTPS混合内容，不加载HTTP的资源。                      |

## 事件

通用事件仅支持[onFocus](ts-universal-focus-event.md#事件)。

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onAlert(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>网页触发alert()告警弹窗时触发。<br />url：当前显示的对话框所在的网页。<br />message：对话框中显示的信息。<br />JsResult：根据用户的操作确认或取消对话框。</p> |
| onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>即将离开当前页面（刷新或关闭）时触发。<br />url：Web组件返回的下载URL。<br />message：Web组件返回的信息。<br />JsResult：Web组件返回的弹窗确认或弹窗取消功能对象。</p> |
| onConfirm(callback: (event?: { url: string; message: string; result: JsResult }) => boolean) | <p>网页触发confirm()确认弹窗时触发。<br />url：Web组件返回的下载URL。<br />message：Web组件返回的信息。<br />JsResult：Web组件返回的弹窗确认或弹窗取消功能对象。</p> |
| onConsole(callback: (event?: { message: ConsoleMessage }) => boolean) | <p>向主应用报告JavaScript控制台消息时触发该回调。<br/>message：触发的控制台信息。</p> |
| onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void) | <p>下载开始时触发该回调。<br />url：Web组件返回的下载URL。<br />userAgent：Web组件返回的用户代理名称。<br />contentDisposition：Web组件返回的响应头。<br />mimetype：Web组件返回的媒体类型（MIME）信息。<br />contentLength：Web组件返回的内容长度。</p> |
| onErrorReceive(callback: (event?: { request: WebResourceRequest, error: WebResourceError }) => void) | <p>网页加载错误时触发该回调。<br/>request：网页的请求信息。<br/>error：网页的错误信息 。</p> |
| onHttpErrorReceive(callback: (event?: { request: WebResourceRequest, response: WebResourceResponse }) => void) | <p>网页加载出现网络错误时触发该回调。<br/>request：网页的请求信息。<br/>response：网页的响应信息</p> |
| onPageBegin(callback: (event?: { url: string }) => void)     | <p>网页加载时触发该回调。<br/>url：Web组件返回的URL。</p>    |
| onPageEnd(callback: (event?: { url: string }) => void)       | <p>网页加载结束时触发该回调。<br/>url：Web组件返回的URL。</p> |
| onProgressChange(callback: (event?: { newProgress: number }) => void) | <p>网页加载进度变化时触发该回调。<br/>newProgress：加载进度，取值范围为0到100的整数。</p> |
| onTitleReceive(callback: (event?: { title: string }) => void) | <p>网页主页面标题更改时触发该回调。<br/>title：标题内容。</p> |

### ConsoleMessage对象说明

- 接口

  | 接口名称                            | 功能描述                   |
  | ------------------------------- | ---------------------- |
  | getLineNumber(): number         | 获取ConsoleMessage的行数。   |
  | getMessage(): string            | 获取ConsoleMessage的日志信息。 |
  | getMessageLevel(): MessageLevel | 获取ConsoleMessage的信息级别。 |
  | getSourceId(): string           | 获取ConsoleMessage的源的Id。 |

- MessageLevel枚举说明

  | 名称    | 描述    |
  | ----- | :---- |
  | Debug | 调试级别。 |
  | Error | 错误级别。 |
  | Info  | 消息级别。 |
  | Log   | 日志级别。 |
  | Warn  | 警告级别。 |

### JsResult  对象说明

Web组件返回的弹窗确认或弹窗取消功能对象。

- 接口

  | 接口名称                  | 功能描述         |
  | --------------------- | ------------ |
  | handleCancel(): void  | <p>取消弹窗。</p> |
  | handleConfirm(): void | <p>确认弹窗。</p> |

### WebResourceError对象说明

- 接口

  | 接口名称                   | 功能描述         |
  | ---------------------- | ------------ |
  | getErrorCode(): number | 获取加载资源的错误码。  |
  | getErrorInfo(): string | 获取加载资源的错误信息。 |

### WebResourceRequest对象说明

- 接口

  | 接口名称                                | 功能描述               |
  | ----------------------------------- | ------------------ |
  | getRequestHeader(): Array\<Header\> | 获取请求头信息。           |
  | getRequestUrl(): string             | 获取请求的url信息。        |
  | isMainFrame(): boolean              | 获取请求是否时为了获取主窗口的信息。 |
  | isRedirect(): boolean               | 获取请求是否重定向。         |
  | isRequestGesture(): boolean         | 获取请求是否与手势关联。       |

### WebResourceResponse对象说明

- 接口

  | 接口名称                                 | 功能描述        |
  | ------------------------------------ | ----------- |
  | getReasonMessage(): string           | 获取响应的状态码描述。 |
  | getResponseCode(): number            | 获取响应的状态码。   |
  | getResponseData(): string            | 获取响应数据。     |
  | getResponseEncoding(): string        | 获取响应的编码。    |
  | getResponseHeader(): Array\<Header\> | 获取响应头信息。    |
  | getResponseMimeType(): string        | 获取响应的媒体类型。  |

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

### backward

backward(): void

页面后退。

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

清空指定对象已注册的JavaScript方法。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                    |
  | ---- | ------ | ---- | ---- | ----------------------- |
  | name | string | 是    | -    | 注册对象的名称，与HTML中调用的对象名一致。 |

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

  | 参数名        | 参数类型   | 必填   | 默认值  | 参数描述     |
  | ---------- | ------ | ---- | ---- | -------- |
  | data       | string | 是    | -    | 需要加载的数据。 |
  | mimeType   | string | 是    | -    | 媒体类型。    |
  | encoding   | string | 是    | -    | 编码类型。    |
  | baseUrl    | string | 否    | -    | 基础URL。   |
  | historyUrl | string | 否    | -    | 历史URL。   |

### loadUrl

loadUrl(options:{ url: string, headers?: Array<{ key: string, value: string }> }): void

加载URL。

- options参数说明

  | 参数名     | 参数类型                                  | 必填   | 默认值  | 参数描述       |
  | ------- | ------------------------------------- | ---- | ---- | ---------- |
  | url     | string                                | 是    | -    | 需要加载的 URL。 |
  | headers | Array<{ key: string, value: string }> | 否    | []   | HTTP附加信息。  |

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

registerJavaScriptProxy(options: { obj: object, name: string, methodList: Array\<string\> }): void

将JavaScript对象与方法注册到Web内核，可被已加载的HTML直接调用。注册后，须调用refresh接口生效。

- options 参数说明

  | 参数名        | 参数类型            | 必填   | 默认值  | 参数描述                    |
  | ---------- | --------------- | ---- | ---- | ----------------------- |
  | obj        | object          | 是    | -    | 参与注册的对象。                |
  | name       | string          | 是    | -    | 注册对象的名称，与HTML中调用的对象名一致。 |
  | methodList | Array\<string\> | 是    | -    | 参与注册的方法。                |

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
        this.controller.runJavaScript({ script: 'test()' });
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