# Web

> **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供具有网页显示能力的Web组件。

## 权限列表
访问在线网页时需添加网络权限：ohos.permission.INTERNET

## 子组件

无

## 接口

-   Web\(options: { src: string, controller?: WebController }\)

    表1 options参数说明

    | 参数名        | 参数类型                            | 必填   | 默认值  | 参数描述    |
    | ---------- | ------------------------------- | ---- | ---- | ------- |
    | src        | string                          | 是    | -    | 网页资源地址。 |
    | controller | [WebController](#webcontroller) | 否    | -    | 控制器。    |


> **说明：**
>
> - 不支持转场动画；
> - 不支持多实例；
> - 仅支持本地音视频播放。

## 属性
| 名称                 | 参数类型                                     | 默认值               | 描述                                       |
| ------------------ | ---------------------------------------- | ----------------- | ---------------------------------------- |
| domStorageAccess   | boolean                                  | false             | 设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启。 |
| fileAccess         | boolean                                  | false             | 设置是否开启通过[$rawfile(filepath/filename)](../../ui/ts-application-resource-access.md#资源引用)访问应用中rawfile路径的文件， 默认启用。 |
| fileFromUrlAccess  | boolean                                  | true              | 设置是否允许通过网页中的JavaScript脚本访问[$rawfile(filepath/filename)](../../ui/ts-application-resource-access.md#资源引用)的内容，默认未启用。 |
| imageAccess        | boolean                                  | true              | 设置是否允许自动加载图片资源，默认允许。                     |
| javaScriptProxy    | { <br>  object: object, <br/> name: string, <br/> methodList: Array\<string\>, <br/> controller: WebController <br>} | -                 | 注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。所有参数不支持更新。 <br/> object: 参与注册的对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean。<br/> name: 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。<br/> methodList: 参与注册的应用侧JavaScript对象的方法。<br/> controller: 控制器。 |
| javaScriptAccess   | boolean                                  | true              | 设置是否允许执行JavaScript脚本，默认允许执行。             |
| mixedMode          | [MixedMode](#mixedmode枚举说明)              | MixedMode.None    | 设置是否允许加载超文本传输协议（HTTP）和超文本传输安全协议（HTTPS）混合内容，默认不允许加载HTTP和HTTPS混合内容。 |
| onlineImageAccess  | boolean                                  | true              | 设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。 |
| zoomAccess         | boolean                                  | true              | 设置是否支持手势进行缩放，默认允许执行缩放。                   |
| overviewModeAccess | boolean                                  | true              | 设置是否使用概览模式加载网页，默认使用该方式。                  |
| databaseAccess     | boolean                                  | false             | 设置是否开启数据库存储API权限，默认不开启。                  |
| cacheMode          | [CacheMode](#cachemode枚举说明)              | CacheMode.Default | 设置缓存模式。                                  |
| textZoomAtio       | number                                   | 100               | 设置页面的文本缩放百分比，默认为100%。                    |
| userAgent          | string                                   | -                 | 设置用户代理。                                  |

>  **说明：**
>
> 通用属性仅支持[width](ts-universal-attributes-size.md#属性)、[height](ts-universal-attributes-size.md#属性)、[padding](ts-universal-attributes-size.md#属性)、[margin](ts-universal-attributes-size.md#属性)、[border](ts-universal-attributes-border.md#属性)。

## 事件

不支持通用事件。

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onAlert(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult对象说明) }) => boolean) | <p>网页触发alert()告警弹窗时触发回调。<br />当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（只有确认场景），并且根据用户的确认操作调用JsResult通知Web组件。<br />url：当前显示弹窗所在网页的URL。<br />message：弹窗中显示的信息。<br />JsResult：通知Web组件用户操作行为。</p> |
| onBeforeUnload(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult对象说明) }) => boolean) | <p>刷新或关闭场景下，在即将离开当前页面时触发此回调。<br />当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。<br />url：当前显示弹窗所在网页的URL。<br />message：弹窗中显示的信息。<br />JsResult：通知Web组件用户操作行为。</p> |
| onConfirm(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult对象说明) }) => boolean) | <p>网页调用confirm()告警时触发此回调。<br />当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件。<br />url：当前显示弹窗所在网页的URL。<br />message：弹窗中显示的信息。<br />JsResult：通知Web组件用户操作行为。</p> |
| onConsole(callback: (event?: { message: [ConsoleMessage](#consolemessage对象说明) }) => boolean) | <p>通知宿主应用JavaScript console消息。<br/>message：触发的控制台信息。</p> |
| onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void) | <p>网页的下载任务开始时触发该回调。<br />url：文件下载的URL。<br />userAgent：下载的用户代理（UA）名称。<br />contentDisposition：服务器返回的 Content-Disposition响应头，可能为空。<br />mimetype：服务器返回内容媒体类型（MIME）信息。<br />contentLength：服务器返回文件的长度。</p> |
| onErrorReceive(callback: (event?: { request: [WebResourceRequest](#webresourceerror对象说明), error: [WebResourceError](#webresourceerror对象说明) }) => void) | <p>网页加载遇到错误时触发该回调。<br/>出于性能考虑，建议此回调中尽量执行简单逻辑。<br/>request：网页请求的封装信息。<br/>error：网页加载资源错误的封装信息 。</p> |
| onHttpErrorReceive(callback: (event?: { request: [WebResourceRequest](#webresourceerror对象说明), response: [WebResourceResponse](#webresourceresponse对象说明) }) => void) | <p>网页加载资源遇到的HTTP错误（响应码>=400)时触发该回调。<br/>request：网页请求的封装信息。<br/>response：网页响应的封装信息</p> |
| onPageBegin(callback: (event?: { url: string }) => void) | <p>网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。<br/>url：页面的URL地址。</p> |
| onPageEnd(callback: (event?: { url: string }) => void) | <p>网页加载完成时触发该回调，且只在主frame触发。<br/>url：页面的URL地址。</p> |
| onProgressChange(callback: (event?: { newProgress: number }) => void) | <p>网页加载进度变化时触发该回调。<br/>newProgress：新的加载进度，取值范围为0到100的整数。</p> |
| onTitleReceive(callback: (event?: { title: string }) => void) | <p>网页document标题更改时触发该回调。<br/>title：document标题内容。</p> |
| onRefreshAccessedHistory(callback: (event?: { url: string, isRefreshed: boolean }) => void) | <p>加载网页页面完成时触发该回调，用于应用更新其访问的历史链接。<br/>url：访问的url。<br/>isRefreshed：true表示该页面是被重新加载的，false表示该页面是新加载的。</p> |
| onRenderExited(callback: (event?: { renderExitReason:  [RenderExitReason](#renderexitreason枚举说明) }) => void) | <p>应用渲染进程异常退出时触发该回调。<br/>renderExitReason：渲染进程进程异常退出的具体原因。</p> |
| onShowFileSelector(callback: (event?: { result: [FileSelectorResult](#fileselectorresult对象说明), fileSelector:  [FileSelectorParam](#fileselectorparam对象说明) }) => void) | <p>调用此函数以处理具有“文件”输入类型的HTML表单，以响应用户按下的“选择文件”按钮<br/>result：用于通知Web组件文件选择的结果。<br/>fileSelector：文件选择器的相关信息。</p> |
| onUrlLoadIntercept(callback: (event?: { data:string \| [WebResourceRequest](#webresourcerequest对象说明) }) => boolean) | <p>当Web组件加载url之前触发该回调，用于是否阻止此次访问。callback返回true表示阻止此次加载，否则允许此次加载。<br/>data：url的相关信息。</p> |

### ConsoleMessage对象说明

- 接口

  | 接口名称                            | 功能描述                   |
  | ------------------------------- | ---------------------- |
  | getLineNumber(): number         | 获取ConsoleMessage的行数。   |
  | getMessage(): string            | 获取ConsoleMessage的日志信息。 |
  | getMessageLevel(): MessageLevel | 获取ConsoleMessage的信息级别。 |
  | getSourceId(): string           | 获取网页源文件路径和名字。          |

- MessageLevel枚举说明

  | 名称    | 描述    |
  | ----- | :---- |
  | Debug | 调试级别。 |
  | Error | 错误级别。 |
  | Info  | 消息级别。 |
  | Log   | 日志级别。 |
  | Warn  | 警告级别。 |

### JsResult对象说明

Web组件返回的弹窗确认或弹窗取消功能对象。

- 接口

  | 接口名称                  | 功能描述                    |
  | --------------------- | ----------------------- |
  | handleCancel(): void  | <p>通知Web组件用户取消弹窗操作。</p> |
  | handleConfirm(): void | <p>通知Web组件用户确认弹窗操作。</p> |

### WebResourceError对象说明

- 接口

  | 接口名称                   | 功能描述         |
  | ---------------------- | ------------ |
  | getErrorCode(): number | 获取加载资源的错误码。  |
  | getErrorInfo(): string | 获取加载资源的错误信息。 |

### WebResourceRequest对象说明

- 接口

  | 接口名称                                     | 功能描述                 |
  | ---------------------------------------- | -------------------- |
  | getRequestHeader(): Array\<[Header](#header对象说明)\> | 获取资源请求头信息。           |
  | getRequestUrl(): string                  | 获取资源请求的URL信息。        |
  | isMainFrame(): boolean                   | 判断资源请求是否为主frame。     |
  | isRedirect(): boolean                    | 判断资源请求是否被服务端重定向。     |
  | isRequestGesture(): boolean              | 获取资源请求是否与手势（如点击）相关联。 |

### Header对象说明

Web组件返回的请求/响应头对象。

- 参数

  | 参数名称        | 参数类型   | 参数描述          |
  | ----------- | ------ | ------------- |
  | headerKey   | string | 请求/响应头的key。   |
  | headerValue | string | 请求/响应头的value。 |


### WebResourceResponse对象说明

- 接口

  | 接口名称                                     | 功能描述               |
  | ---------------------------------------- | ------------------ |
  | getReasonMessage(): string               | 获取资源响应的状态码描述。      |
  | getResponseCode(): number                | 获取资源响应的状态码。        |
  | getResponseData(): string                | 获取资源响应数据。          |
  | getResponseEncoding(): string            | 获取资源响应的编码。         |
  | getResponseHeader(): Array\<[Header](#header对象说明)\> | 获取资源响应头。           |
  | getResponseMimeType(): string            | 获取资源响应的媒体（MIME）类型。 |

### RenderExitReason枚举说明

onRenderExited接口返回的渲染进程退出的具体原因。

| 名称                         | 描述                |
| -------------------------- | ----------------- |
| ProcessAbnormalTermination | 渲染进程异常退出。         |
| ProcessWasKilled           | 收到SIGKILL，或被手动终止。 |
| ProcessCrashed             | 渲染进程崩溃退出，如段错误。    |
| ProcessOom                 | 程序内存不足。           |
| ProcessExitUnknown         | 其他原因。             |

### MixedMode枚举说明

| 名称         | 描述                                 |
| ---------- | ---------------------------------- |
| All        | 允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 不允许加载HTTP和HTTPS混合内容。               |

### CacheMode枚举说明
| 名称      | 描述                                   |
| ------- | ------------------------------------ |
| Default | 使用未过期的cache加载资源，如果cache中无该资源则从网络中获取。 |
| None    | 加载资源使用cache，如果cache中无该资源则从网络中获取。     |
| Online  | 加载资源不使用cache，全部从网络中获取。               |
| Only    | 只从cache中加载资源。                        |

### FileSelectorResult对象说明
通知Web组件的文件选择结果。

- 接口

  | 接口名称                                     | 功能描述                                   |
  | ---------------------------------------- | -------------------------------------- |
  | handleFileList(fileList: Array\<string>): void | 通知Web组件进行文件选择操作。fileList: 需要进行操作的文件列表。 |

### FileSelectorParam对象说明
- 接口

  | 接口名称                             | 功能描述         |
  | -------------------------------- | ------------ |
  | getTitle(): string               | 获取文件选择器标题。   |
  | getMode(): FileSelectorMode      | 获取文件选择器的模式。  |
  | getAcceptType(): Array\<string\> | 获取文件过滤类型。    |
  | isCapture(): boolean             | 获取是否调用多媒体能力。 |

### FileSelectorMode枚举说明
| 名称                   | 描述         |
| -------------------- | ---------- |
| FileOpenMode         | 打开上传单个文件。  |
| FileOpenMultipleMode | 打开上传多个文件。  |
| FileOpenFolderMode   | 打开上传文件夹模式。 |
| FileSaveMode         | 文件保存模式。    |

## WebController

通过WebController可以控制Web组件各种行为。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法。

### 创建对象

```
webController: WebController = new WebController()
```

### accessBackward

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

### accessForward

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

### accessStep

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                  |
  | ---- | ------ | ---- | ---- | --------------------- |
  | step | number | 是    | -    | 要跳转的步数，正数代表前进，负数代表后退。 |

- 返回值

  | 参数类型    | 说明        |
  | ------- | --------- |
  | boolean | 页面是否前进或后退 |

### backward

backward(): void

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                                     |
  | ---- | ------ | ---- | ---- | ---------------------------------------- |
  | name | string | 是    | -    | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

### forward

forward(): void

按照历史栈，前进一个页面。一般结合accessForward一起使用。

### getHitTest

getHitTest(): HitTestType

获取当前被点击区域的元素类型。	

- HitTestType枚举说明

  | 名称            | 描述                       |
  | ------------- | ------------------------ |
  | EditText      | 可编辑的区域。                  |
  | Email         | 电子邮件地址。                  |
  | HttpAnchor    | 超链接。其src为http。           |
  | HttpAnchorImg | 带有超链接的图片，其中超链接的src为http。 |
  | Img           | HTML::img标签。             |
  | Map           | 地理地址。                    |
  | Unknown       | 未知内容。                    |

### loadData

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string }): void

baseUrl为空时，通过”data“协议加载指定的一段字符串。

当baseUrl为”data“协议时，编码后的data字符串将被Web组件作为”data"协议加载。

当baseUrl为“http/https"协议时，编码后的data字符串将被Web组件以类似loadUrl的方式以非编码字符串处理。

- options参数说明

  | 参数名        | 参数类型   | 必填   | 默认值  | 参数描述                                     |
  | ---------- | ------ | ---- | ---- | ---------------------------------------- |
  | data       | string | 是    | -    | 按照”Base64“或者”URL"编码后的一段字符串。              |
  | mimeType   | string | 是    | -    | 媒体类型（MIME）。                              |
  | encoding   | string | 是    | -    | 编码类型，具体为“Base64"或者”URL编码。                |
  | baseUrl    | string | 否    | -    | 指定的一个URL路径（“http”/“https”/"data"协议），并由Web组件赋值给window.origin。 |
  | historyUrl | string | 否    | -    | 历史记录URL。非空时，可被历史记录管理，实现前后后退功能。当baseUrl为空时，此属性无效。 |

### loadUrl

loadUrl(options:{ url: string, headers?: Array\<Header\> }): void

使用指定的http头加载指定的URL。

通过loadUrl注入的对象只在当前document有效，即通过loadUrl导航到新的页面会无效。

而通过registerJavaScriptProxy注入的对象，在loadUrl导航到新的页面也会有效。

- options参数说明

  | 参数名     | 参数类型                           | 必填   | 默认值  | 参数描述           |
  | ------- | ------------------------------ | ---- | ---- | -------------- |
  | url     | string                         | 是    | -    | 需要加载的 URL。     |
  | headers | Array\<[Header](#header对象说明)\> | 否    | []   | URL的附加HTTP请求头。 |

### onActive

onActive(): void

调用此接口通知Web组件进入前台激活状态。

### onInactive

onInactive(): void

调用此接口通知Web组件进入未激活状态。

### refresh

refresh(): void

调用此接口通知Web组件刷新网页。

### registerJavaScriptProxy

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> }): void

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用refresh接口生效。

- options 参数说明

  | 参数名        | 参数类型            | 必填   | 默认值  | 参数描述                                     |
  | ---------- | --------------- | ---- | ---- | ---------------------------------------- |
  | object     | object          | 是    | -    | 参与注册的应用侧JavaScript对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean |
  | name       | string          | 是    | -    | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
  | methodList | Array\<string\> | 是    | -    | 参与注册的应用侧JavaScript对象的方法。                 |

### runJavaScript

runJavaScript(options: { script: string, callback?: (result: string) => void }): void

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

- options参数说明

  | 参数名      | 参数类型                     | 必填   | 默认值  | 参数描述                                     |
  | -------- | ------------------------ | ---- | ---- | ---------------------------------------- |
  | script   | string                   | 是    | -    | JavaScript脚本。                            |
  | callback | (result: string) => void | 否    | -    | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

### stop

stop(): void

停止页面加载。

### clearHistory

clearHistory(): void

删除所有前进后退记录。

### getCookieManager

getCookieManager(): WebCookie

获取web组件cookie管理对象。
- 返回值
  | 参数类型      | 说明                                       |
  | --------- | ---------------------------------------- |
  | WebCookie | web组件cookie管理对象，参考[WebCookie](#webcookie)定义。 |
## WebCookie
通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。
### setCookie
setCookie(url: string, value: string): boolean

设置cookie，该方法为同步方法。设置成功返回true，否则返回false。

- 参数说明

  | 参数名   | 参数类型   | 必填   | 默认值  | 参数描述              |
  | ----- | ------ | ---- | ---- | ----------------- |
  | url   | string | 是    | -    | 要设置的cookie所属的url。 |
  | value | string | 是    | -    | cookie的值。         |
- 返回值 
  | 参数类型    | 说明            |
  | ------- | ------------- |
  | boolean | 设置cookie是否成功。 |

### saveCookieSync
saveCookieSync(): boolean

将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。
- 返回值
  | 参数类型    | 说明                   |
  | ------- | -------------------- |
  | boolean | 同步内存cookie到磁盘操作是否成功。 |
## 示例

```ts
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
```html
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