# Web

提供具有网页显示能力的Web组件，[@ohos.web.webview](js-apis-webview.md)提供web控制能力。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 子组件

无

## 接口

Web(value: WebOptions)

> **说明：**
>
> 不支持转场动画。
>
> 同一页面的多个Web组件，必须绑定不同的WebviewController。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](#weboptions)   | 是    | 定义Web选项。 |

**示例：**

加载在线网页。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

隐私模式Webview加载在线网页。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

Web组件同步渲染模式。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
      }
    }
  }
  ```

Web组件指定共享渲染进程。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, sharedRenderProcessToken: "111" })
        Web({ src: 'www.w3.org', controller: this.controller, sharedRenderProcessToken: "111" })
      }
    }
  }
  ```

加载本地网页。

通过$rawfile方式加载。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过$rawfile加载本地资源文件。
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

通过resources协议加载，适用Webview加载带有"#"路由的链接。

使用 `resource://rawfile/` 协议前缀可以避免常规 `$rawfile` 方式在处理带有"#"路由链接时的局限性。当URL中包含"#"号时，"#"后面的内容会被视为锚点（fragment）。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过resource协议加载本地资源文件。
        Web({ src: "resource://rawfile/index.html#home", controller: this.controller })
      }
    }
  }
  ```

在“src\main\resources\rawfile”文件夹下创建index.html：
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<div id="content"></div>

<script>
	function loadContent() {
	  var hash = window.location.hash;
	  var contentDiv = document.getElementById('content');

	  if (hash === '#home') {
		contentDiv.innerHTML = '<h1>Home Page</h1><p>Welcome to the Home Page!</p>';
	  } else {
		contentDiv.innerHTML = '<h1>Default Page</h1><p>This is the default content.</p>';
	  }
	}

	// 加载界面
	window.addEventListener('load', loadContent);

	// 当hash变化时，更新界面
	window.addEventListener('hashchange', loadContent);
</script>
</body>
</html>
```

加载沙箱路径下的本地资源文件，需要开启应用中文件系统的访问[fileAccess](./ts-basic-components-web-attributes.md#fileaccess)权限。

1. 通过构造的单例对象GlobalContext获取沙箱路径。

   ```ts
   // GlobalContext.ets
   export class GlobalContext {
     private constructor() {}
     private static instance: GlobalContext;
     private _objects = new Map<string, Object>();

     public static getContext(): GlobalContext {
       if (!GlobalContext.instance) {
         GlobalContext.instance = new GlobalContext();
       }
       return GlobalContext.instance;
     }

     getObject(value: string): Object | undefined {
       return this._objects.get(value);
     }

     setObject(key: string, objectClass: Object): void {
       this._objects.set(key, objectClass);
     }
   }
   ```

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   let url = 'file://' + GlobalContext.getContext().getObject("filesDir") + '/index.html';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         // 加载沙箱路径文件。
         Web({ src: url, controller: this.controller })
         .fileAccess(true)
       }
     }
   }
   ```

2. 修改EntryAbility.ets。

   以filesDir为例，获取沙箱路径。若想获取其他路径，请参考[应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // 通过在GlobalContext对象上绑定filesDir，可以实现UIAbility组件与UI之间的数据同步。
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
     }
   }
   ```

   加载的html文件。

   ```html
   <!-- index.html -->
   <!DOCTYPE html>
   <html>
       <body>
           <p>Hello World</p>
       </body>
   </html>
   ```

## WebOptions

通过[接口](#接口)定义Web选项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src        | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)   | 是    | 网页资源地址。如果访问本地资源文件，请使用$rawfile或者resource协议。如果加载应用包外沙箱路径的本地资源文件(文件支持html和txt类型)，请使用file://沙箱文件路径。<br>src不能通过状态变量（例如：@State）动态更改地址，如需更改，请通过[loadUrl()](./js-apis-webview-WebviewController.md#loadurl)重新加载。 |
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](#webviewcontroller9)  | 是    | 控制器，通过controller可以控制Web组件各种行为（包括页面导航、声明周期状态、JavaScript交互等行为）。从API version 9开始，WebController不再维护，建议使用WebviewController替代。 |
| renderMode<sup>12+</sup> | [RenderMode](./ts-basic-components-web-e.md#rendermode12)| 否   | 表示当前Web组件的渲染方式，`RenderMode.ASYNC_RENDER`表示Web组件自渲染，`RenderMode.SYNC_RENDER`表示支持Web组件统一渲染能力，默认值`RenderMode.ASYNC_RENDER`，该模式不支持动态调整。 |
| incognitoMode<sup>11+</sup> | boolean | 否 | 表示当前创建的webview是否是隐私模式。true表示创建隐私模式的webview，false表示创建正常模式的webview。<br> 默认值：false。 |
| sharedRenderProcessToken<sup>12+</sup> | string | 否 | 表示当前Web组件指定共享渲染进程的token，多渲染进程模式下，相同token的Web组件会优先尝试复用与token相绑定的渲染进程。token与渲染进程的绑定发生在渲染进程的初始化阶段。当渲染进程没有关联的Web组件时，其与token绑定关系将被移除。<br> 默认值： ""。  |

## WebviewController<sup>9+</sup>

type WebviewController = WebviewController

提供Web控制器的方法。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型     | 说明       |
| ------ | ---------- |
| [WebviewController](./js-apis-webview-WebviewController.md#class-webviewcontroller)  | 通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。 |

## WebKeyboardController<sup>12+</sup>

控制自定义键盘的输入、删除、关闭等操作。示例代码参考[onInterceptKeyboardAttach](./ts-basic-components-web-events.md#oninterceptkeyboardattach12)。

### constructor<sup>12+</sup>

constructor()

WebKeyboardController的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### insertText<sup>12+</sup>

insertText(text: string): void

Web输入框中插入字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------- | ---- | --------------------- |
| text | string | 是 | 向Web输入框插入字符。 |

### deleteForward<sup>12+</sup>

deleteForward(length: number): void

从后往前删除Web输入框中指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | -------- | ---- | ------------------------ |
| length | number   | 是   | 从后往前删除Web输入框中指定长度的字符。<br>参数无取值范围，当参数值大于字符长度时，默认删除光标前面所有字符；参数值为负数时，不执行删除操作。 |

### deleteBackward12+</sup>

deleteBackward(length: number): void

从前往后删除Web输入框中指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | -------- | ---- | ------------------------ |
| length | number   | 是   | 从前往后删除Web输入框中指定长度的字符。<br>参数无取值范围，当参数值大于字符长度时，默认删除光标后面所有字符；参数值为负数时，不执行删除操作。 |

### sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

插入功能按键，目前仅支持Enter键类型，取值见[EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                   |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | 是   | 向Web输入框传递功能键，目前仅支持Enter键。 |

### close<sup>12+</sup>

close(): void

关闭自定义键盘。

**系统能力：** SystemCapability.Web.Webview.Core

## ConsoleMessage

Web组件获取控制台信息对象。示例代码参考[onConsole事件](./ts-basic-components-web-events.md#onconsole)。

### constructor

constructor(message: string, sourceId: string, lineNumber: number, messageLevel: MessageLevel)

[ConsoleMessage](#consolemessage)的构造函数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[constructor](#constructor9)代替。

**系统能力：** SystemCapability.Web.Webview.Core

### constructor<sup>9+</sup>

constructor()

ConsoleMessage的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### getLineNumber

getLineNumber(): number

获取[ConsoleMessage](#consolemessage)的行数。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 返回ConsoleMessage的行数。 |

### getMessage

getMessage(): string

获取ConsoleMessage的日志信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | 返回ConsoleMessage的日志信息。 |

### getMessageLevel

getMessageLevel(): MessageLevel

获取ConsoleMessage的信息级别。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                | 说明                     |
| --------------------------------- | ---------------------- |
| [MessageLevel](./ts-basic-components-web-e.md#messagelevel) | 返回ConsoleMessage的信息级别。 |

### getSourceId

getSourceId(): string

获取网页源文件路径和名字。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回网页源文件路径和名字。 |

## JsResult

Web组件返回的弹窗确认或弹窗取消功能对象。示例代码参考[onAlert事件](./ts-basic-components-web-events.md#onalert)。

### constructor

constructor()

JsResult的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### handleCancel

handleCancel(): void

通知Web组件用户取消弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

### handleConfirm

handleConfirm(): void

通知Web组件用户确认弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

通知Web组件用户确认弹窗操作及对话框内容。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明        |
| ------ | ------ | ---- | ----------- |
| result | string | 是    | 用户输入的对话框内容。 |

## FullScreenExitHandler<sup>9+</sup>

通知开发者Web组件退出全屏。示例代码参考[onFullScreenEnter事件](./ts-basic-components-web-events.md#onfullscreenenter9)。

### constructor<sup>9+</sup>

constructor()

FullScreenExitHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

通知开发者Web组件退出全屏。

**系统能力：** SystemCapability.Web.Webview.Core

## ControllerHandler<sup>9+</sup>

设置用户新建Web组件的WebviewController对象。示例代码参考[onWindowNew事件](./ts-basic-components-web-events.md#onwindownew9)。

**系统能力：** SystemCapability.Web.Webview.Core

### constructor<sup>9+</sup>

constructor()

ControllerHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

设置WebviewController对象，如果不需要打开新窗口请设置为null。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填 | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| controller | [WebviewController](./js-apis-webview-WebviewController.md#class-webviewcontroller) | 是  | 新建Web组件的WebviewController对象，如果不需要打开新窗口请设置为null。 |

## WebResourceError

Web组件资源管理错误信息对象。示例代码参考[onErrorReceive事件](./ts-basic-components-web-events.md#onerrorreceive)。

### constructor

constructor()

WebResourceError的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### getErrorCode

getErrorCode(): number

获取加载资源的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回加载资源的错误码。错误码的含义可以参考[WebNetErrorList](js-apis-netErrorList.md) |

### getErrorInfo

getErrorInfo(): string

获取加载资源的错误信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 返回加载资源的错误信息。 |

## WebResourceRequest

Web组件获取资源请求对象。示例代码参考[onErrorReceive事件](./ts-basic-components-web-events.md#onerrorreceive)。

### constructor

constructor()

WebResourceRequest的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### getRequestHeader

getRequestHeader(): Array\<Header\>

获取资源请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | 返回资源请求头信息。 |

### getRequestUrl

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

### isMainFrame

isMainFrame(): boolean

判断资源请求是否为主frame。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否为主frame。<br>true表示返回资源请求为主frame，false表示返回资源请求不为主frame。 |

### isRedirect

isRedirect(): boolean

判断资源请求是否被服务端重定向。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否被服务端重定向。<br>true表示返回资源请求被服务端重定向，false表示返回资源请求未被服务端重定向。 |

### isRequestGesture

isRequestGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联。<br>true表示返回资源请求与手势（如点击）相关联，false表示返回资源请求与手势（如点击）不相关联。 |

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

获取请求方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 返回请求方法。 |

## Header

Web组件返回的请求/响应头对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型     | 必填   | 说明            |
| ----------- | ------ | ---- | ------------- |
| headerKey   | string | 是    | 请求/响应头的key。   |
| headerValue | string | 是    | 请求/响应头的value。 |

## WebResourceResponse

Web组件资源响应对象。示例代码参考[onHttpErrorReceive事件](./ts-basic-components-web-events.md#onhttperrorreceive)。

### constructor

constructor()

WebResourceResponse的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### getReasonMessage

getReasonMessage(): string

获取资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源响应的状态码描述。 |

### getResponseCode

getResponseCode(): number

获取资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回资源响应的状态码。 |

### getResponseData

getResponseData(): string

获取资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 返回资源响应数据。 |

### getResponseEncoding

getResponseEncoding(): string

获取资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回资源响应的编码。 |

### getResponseHeader

getResponseHeader() : Array\<Header\>

获取资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明       |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | 返回资源响应头。 |

### getResponseMimeType

getResponseMimeType(): string

获取资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 返回资源响应的媒体（MIME）类型。 |

### getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

获取资源响应数据，支持多种数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|string|返回HTML格式的字符串。|
|number|返回文件句柄。|
|ArrayBuffer|返回二进制数据。|
|[Resource](../apis-arkui/arkui-ts/ts-types.md)|返回`$rawfile`资源。|
|undefined|如果没有可用数据，返回`undefined`。|

### getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

获取响应数据是否已准备就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|boolean|`true`表示响应数据已准备好，`false`表示未准备好。|

### setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

设置资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                     | 必填   | 说明                                     |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | 是    | 要设置的资源响应数据。string表示HTML格式的字符串。number表示文件句柄，此句柄由系统的Web组件负责关闭。Resource表示应用rawfile目录下文件资源。ArrayBuffer表示资源的原始二进制数据。 |

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

设置资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明         |
| -------- | ------ | ---- | ------------ |
| encoding | string | 是    | 要设置的资源响应的编码。 |

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

设置资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明                 |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | 是   | 要设置的资源响应的媒体（MIME）类型。 |

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

设置资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明            |
| ------ | ------ | ---- | --------------- |
| reason | string | 是   | 要设置的资源响应的状态码描述。 |

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

设置资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                       | 必填   | 说明       |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](#header)\> | 是   | 要设置的资源响应头。 |

### setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

设置资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明          |
| ---- | ------ | ---- | ------------- |
| code | number | 是   | 要设置的资源响应的状态码。如果该资源以错误结束，请参考[@ohos.web.netErrorList](js-apis-netErrorList.md)设置相应错误码，避免设置错误码为 ERR_IO_PENDING，设置为该错误码可能会导致XMLHttpRequest同步请求阻塞。 |

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

设置资源响应数据是否已经就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填  | 说明          |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | 是   | 资源响应数据是否已经就绪。<br>true表示资源响应数据已经就绪，false表示资源响应数据未就绪。默认值：true。 |

## FileSelectorResult<sup>9+</sup>

通知Web组件的文件选择结果。示例代码参考[onShowFileSelector事件](./ts-basic-components-web-events.md#onshowfileselector9)。

### constructor<sup>9+</sup>

constructor()

FileSelectorResult的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

通知Web组件进行文件选择操作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型            | 必填  | 说明         |
| -------- | --------------- | ---- | ------------ |
| fileList | Array\<string\> | 是   | 需要进行操作的文件列表。 |

## FileSelectorParam<sup>9+</sup>

Web组件获取文件对象。示例代码参考[onShowFileSelector事件](./ts-basic-components-web-events.md#onshowfileselector9)。

### constructor<sup>9+</sup>

constructor()

FileSelectorParam的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### getTitle<sup>9+</sup>

getTitle(): string

获取文件选择器标题。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回文件选择器标题。 |

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

获取文件选择器的模式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](./ts-basic-components-web-e.md#fileselectormode9) | 返回文件选择器的模式。 |

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

获取文件过滤类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件过滤类型。 |

### isCapture<sup>9+</sup>

isCapture(): boolean

获取是否调用多媒体能力。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否调用多媒体能力。<br>true表示返回调用多媒体能力，false表示返回未调用多媒体能力。 |

### getMimeTypes<sup>18+</sup>

getMimeTypes(): Array\<string\>

获取文件MIME类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件MIME类型。 |

## HttpAuthHandler<sup>9+</sup>

Web组件返回的http auth认证请求确认或取消和使用缓存密码认证功能对象。示例代码参考[onHttpAuthRequest事件](./ts-basic-components-web-events.md#onhttpauthrequest9)。

### constructor<sup>9+</sup>

constructor()

HttpAuthHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### cancel<sup>9+</sup>

cancel(): void

通知Web组件用户取消HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

使用用户名和密码进行HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填  | 说明       |
| -------- | ------ | ---- | ---------- |
| userName | string | 是   | HTTP认证用户名。 |
| password      | string | 是   | HTTP认证密码。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 认证成功返回true，失败返回false。 |

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

通知Web组件用户使用服务器缓存的账号密码认证。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 存在密码认证成功返回true，其他返回false。 |

## SslErrorHandler<sup>9+</sup>

Web组件返回的SSL错误通知事件用户处理功能对象。示例代码参考[onSslErrorEventReceive事件](./ts-basic-components-web-events.md#onsslerroreventreceive9)。

### constructor<sup>9+</sup>

constructor()

SslErrorHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### handleCancel<sup>9+</sup>

handleCancel(): void

通知Web组件取消此请求。

**系统能力：** SystemCapability.Web.Webview.Core

### handleConfirm<sup>9+</sup>

handleConfirm(): void

通知Web组件继续使用SSL证书。

**系统能力：** SystemCapability.Web.Webview.Core

## ClientAuthenticationHandler<sup>9+</sup>

Web组件返回的SSL客户端证书请求事件用户处理功能对象。示例代码参考[onClientAuthenticationRequest事件](./ts-basic-components-web-events.md#onclientauthenticationrequest9)。

### constructor<sup>9+</sup>

constructor()

ClientAuthenticationHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

通知Web组件使用指定的私钥和客户端证书链。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | 是    | 存放私钥文件的完整路径。  |
| certChainFile | string | 是    | 存放证书链文件的完整路径。 |

### confirm<sup>10+</sup>

confirm(authUri : string): void

通知Web组件使用指定的凭据(从证书管理模块获得)。

> **说明：**
>
> 需要配置权限：ohos.permission.ACCESS_CERT_MANAGER。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明    |
| ------- | ------ | ---- | ------- |
| authUri | string | 是    | 凭据的关键值。 |

### cancel<sup>9+</sup>

cancel(): void

通知Web组件取消相同host和port服务器发送的客户端证书请求事件。同时，相同host和port服务器的请求，不重复上报该事件。

**系统能力：** SystemCapability.Web.Webview.Core

### ignore<sup>9+</sup>

ignore(): void

通知Web组件忽略本次请求。

**系统能力：** SystemCapability.Web.Webview.Core

## PermissionRequest<sup>9+</sup>

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onPermissionRequest事件](./ts-basic-components-web-events.md#onpermissionrequest9)。

### constructor<sup>9+</sup>

constructor()

PermissionRequest的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### deny<sup>9+</sup>

deny(): void

拒绝网页所请求的权限。

**系统能力：** SystemCapability.Web.Webview.Core

### getOrigin<sup>9+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

获取网页所请求的权限资源列表，资源列表类型参考[ProtectedResourceType](./ts-basic-components-web-e.md#protectedresourcetype9)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明            |
| --------------- | ------------- |
| Array\<string\> | 网页所请求的权限资源列表。 |

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

对网页访问的给定权限进行授权。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型            | 必填   | 说明            |
| --------- | --------------- | ---- | --------------- |
| resources | Array\<string\> | 是   | 授予网页请求的权限的资源列表。 |

## ScreenCaptureHandler<sup>10+</sup>

Web组件返回授权或拒绝屏幕捕获功能的对象。示例代码参考[onScreenCaptureRequest事件](./ts-basic-components-web-events.md#onscreencapturerequest10)。

### constructor<sup>10+</sup>

constructor()

ScreenCaptureHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### deny<sup>10+</sup>

deny(): void

拒绝网页所请求的屏幕捕获操作。

**系统能力：** SystemCapability.Web.Webview.Core

### getOrigin<sup>10+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

### grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

对网页访问的屏幕捕获操作进行授权。

> **说明：**
>
> 需要配置权限：ohos.permission.MICROPHONE。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                                     | 必填   | 说明    |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](#screencaptureconfig10) | 是   | 屏幕捕获配置。 |

## EventResult<sup>12+</sup>

通知Web组件事件消费结果，支持的事件参考[触摸事件的类型](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype)。如果应用不消费该事件，则设置为false，事件被Web组件消费。应用消费了该事件，设置为true，Web组件不消费。示例代码参考[onNativeEmbedGestureEvent事件](./ts-basic-components-web-events.md#onnativeembedgestureevent11)。

### constructor<sup>12+</sup>

constructor()

EventResult的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean): void

设置手势事件消费结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。默认值为true。 |

**示例：**

请参考[onNativeEmbedGestureEvent事件](./ts-basic-components-web-events.md#onnativeembedgestureevent11)。

### setGestureEventResult<sup>14+</sup>

setGestureEventResult(result: boolean, stopPropagation: boolean): void

设置手势事件消费结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。<br>true表示消费该手势事件，false表示不消费该手势事件。<br>默认值为true。 |
| stopPropagation | boolean  | 是   | 是否阻止冒泡，在result为true时生效。<br>true表示阻止冒泡，false表示不阻止冒泡。<br>默认值为true。 |

**示例：**

请参考[onNativeEmbedGestureEvent事件](./ts-basic-components-web-events.md#onnativeembedgestureevent11)。

## WebContextMenuParam<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单信息。示例代码参考[onContextMenuShow事件](./ts-basic-components-web-events.md#oncontextmenushow9)。

### constructor<sup>9+</sup>

constructor()

WebContextMenuParam的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### x<sup>9+</sup>

x(): number

弹出菜单的x坐标。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。<br>单位：vp。 |

### y<sup>9+</sup>

y(): number

弹出菜单的y坐标。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。<br>单位：vp。 |

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

获取链接地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                        |
| ------ | ------------------------- |
| string | 如果长按位置是链接，返回经过安全检查的url链接。 |

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

获取链接地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| string | 如果长按位置是链接，返回原始的url链接。 |

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

获取sourceUrl链接。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                       |
| ------ | ------------------------ |
| string | 如果选中的元素有src属性，返回src的url。 |

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

是否存在图像内容。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 长按位置中有图片返回true，否则返回false。 |

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

获取网页元素媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](./ts-basic-components-web-e.md#contextmenumediatype9) | 网页元素媒体类型。 |

### getSelectionText<sup>9+</sup>

getSelectionText(): string

获取选中文本。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| string | 菜单上下文选中文本内容，不存在则返回空。 |

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

获取菜单事件来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](./ts-basic-components-web-e.md#contextmenusourcetype9) | 菜单事件来源。 |

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

获取网页元素输入框类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明     |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](./ts-basic-components-web-e.md#contextmenuinputfieldtype9) | 输入框类型。 |

### isEditable<sup>9+</sup>

isEditable(): boolean

获取网页元素是否可编辑标识。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 网页元素可编辑返回true，不可编辑返回false。 |

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

获取网页元素可编辑标识。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 网页元素可编辑标识，参照[ContextMenuEditStateFlags](./ts-basic-components-web-e.md#contextmenueditstateflags9)。 |

### getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

获取预览图的宽。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------- |
| number | 预览图的宽。<br>单位：vp。 |

### getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

获取预览图的高。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------  |
| number | 预览图的高。<br>单位：vp。 |

## WebContextMenuResult<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单所执行的响应事件。示例代码参考[onContextMenuShow事件](./ts-basic-components-web-events.md#oncontextmenushow9)。

### constructor<sup>9+</sup>

constructor()

WebContextMenuResult的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

不执行WebContextMenuResult其他接口操作时，需要调用此接口关闭菜单。

**系统能力：** SystemCapability.Web.Webview.Core

### copyImage<sup>9+</sup>

copyImage(): void

WebContextMenuParam有图片内容则复制图片。

**系统能力：** SystemCapability.Web.Webview.Core

### copy<sup>9+</sup>

copy(): void

执行与此上下文菜单相关的拷贝文本操作。

**系统能力：** SystemCapability.Web.Webview.Core

### paste<sup>9+</sup>

paste(): void

执行与此上下文菜单相关的粘贴操作。

> **说明：**
>
> 需要配置权限：ohos.permission.READ_PASTEBOARD。

**系统能力：** SystemCapability.Web.Webview.Core

### cut<sup>9+</sup>

cut(): void

执行与此上下文菜单相关的剪切操作。

**系统能力：** SystemCapability.Web.Webview.Core

### selectAll<sup>9+</sup>

selectAll(): void

执行与此上下文菜单相关的全选操作。

**系统能力：** SystemCapability.Web.Webview.Core

### undo<sup>20+</sup>

undo(): void

执行与此上下文菜单相关的撤销操作。

**系统能力：** SystemCapability.Web.Webview.Core

### redo<sup>20+</sup>

redo(): void

执行与此上下文菜单相关的重做操作，即取消用户上一次的撤销操作。

**系统能力：** SystemCapability.Web.Webview.Core

### pasteAndMatchStyle<sup>20+</sup>

pasteAndMatchStyle(): void

执行一个和上下文菜单相关的粘贴操作，粘贴的内容会匹配目标格式，以纯文本形式呈现。

> **说明：**
>
> 需要配置权限：ohos.permission.READ_PASTEBOARD。

**系统能力：** SystemCapability.Web.Webview.Core

## JsGeolocation

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onGeolocationShow事件](./ts-basic-components-web-events.md#ongeolocationshow)。

### constructor

constructor()

JsGeolocation的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

设置网页地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填  | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | 是   | 指定源的字符串索引。                               |
| allow  | boolean | 是   | 设置的地理位置权限状态。<br>true表示开启地理位置权限，false表示不开启地理位置权限。                             |
| retain | boolean | 是   | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions<sup>9+</sup>](./js-apis-webview-GeolocationPermissions.md#class-geolocationpermissions)接口管理保存到系统的地理位置权限。<br>true表示允许将地理位置权限状态保存到系统中，false表示不允许将地理位置权限状态保存到系统中。 |

## ScreenCaptureConfig<sup>10+</sup>

Web屏幕捕获的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型                                      | 必填   | 说明         |
| ----------- | --------------------------------------- | ---- | ---------- |
| captureMode | [WebCaptureMode](./ts-basic-components-web-e.md#webcapturemode10) | 是    | Web屏幕捕获模式。 |

## DataResubmissionHandler<sup>9+</sup>

通过DataResubmissionHandler可以重新提交表单数据或取消提交表单数据。

### constructor<sup>9+</sup>

constructor()

DataResubmissionHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### resend<sup>9+</sup>

resend(): void

重新发送表单数据。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
          })
      }
    }
  }
  ```

### cancel<sup>9+</sup>

cancel(): void

取消重新发送表单数据。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.cancel();
          })
      }
    }
  }
  ```

## WebController

通过WebController可以控制Web组件各种行为。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法。

从API version 9开始不再维护，建议使用[WebviewController<sup>9+</sup>](./js-apis-webview-WebviewController.md#class-webviewcontroller)代替。

### 创建对象

<!--code_no_check-->
```ts
let webController: WebController = new WebController()
```

### constructor

constructor()

WebController的构造函数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

### getCookieManager<sup>(deprecated)</sup>

getCookieManager(): WebCookie

获取Web组件cookie管理对象。

从API version 9开始不再维护，建议使用[getCookie](./js-apis-webview-WebCookieManager.md#getcookiedeprecated)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型        | 说明                                       |
| --------- | ---------------------------------------- |
| WebCookie | Web组件cookie管理对象，参考[WebCookie](#webcookie)定义。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getCookieManager')
          .onClick(() => {
            let cookieManager = this.controller.getCookieManager()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### requestFocus<sup>(deprecated)</sup>

requestFocus()

使当前web页面获取焦点。

从API version 9开始不再维护，建议使用[requestFocus<sup>9+</sup>](./js-apis-webview-WebviewController.md#requestfocus)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('requestFocus')
          .onClick(() => {
            this.controller.requestFocus()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

从API version 9开始不再维护，建议使用[accessBackward<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessbackward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 可以后退返回true，否则返回false。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessBackward')
          .onClick(() => {
            let result = this.controller.accessBackward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessForward<sup>(deprecated)</sup>

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

从API version 9开始不再维护，建议使用[accessForward<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessforward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 返回true表示当前页面可以前进，返回false表示当前页面不可以前进。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessForward')
          .onClick(() => {
            let result = this.controller.accessForward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessStep<sup>(deprecated)</sup>

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

从API version 9开始不再维护，建议使用[accessStep<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessstep)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填  | 说明                  |
| ---- | ------ | ---- | --------------------- |
| step | number | 是   | 要跳转的步数，正数代表前进，负数代表后退。 |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 页面是否前进或后退 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State steps: number = 2

    build() {
      Column() {
        Button('accessStep')
          .onClick(() => {
            let result = this.controller.accessStep(this.steps)
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### backward<sup>(deprecated)</sup>

backward()

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

从API version 9开始不再维护，建议使用[backward<sup>9+</sup>](./js-apis-webview-WebviewController.md#backward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('backward')
          .onClick(() => {
            this.controller.backward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### forward<sup>(deprecated)</sup>

forward()

按照历史栈，前进一个页面。一般结合accessForward一起使用。

从API version 9开始不再维护，建议使用[forward<sup>9+</sup>](./js-apis-webview-WebviewController.md#forward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('forward')
          .onClick(() => {
            this.controller.forward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后立即生效，无须调用[refresh](#refreshdeprecated)接口。

从API version 9开始不再维护，建议使用[deleteJavaScriptRegister<sup>9+</sup>](./js-apis-webview-WebviewController.md#deletejavascriptregister)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填  | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是   | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State name: string = 'Object'

    build() {
      Column() {
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            this.controller.deleteJavaScriptRegister(this.name)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

获取当前被点击区域的元素类型。

从API version 9开始不再维护，建议使用[getHitTest<sup>9+</sup>](./js-apis-webview-WebviewController.md#gethittestdeprecated)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                              | 说明          |
| ------------------------------- | ----------- |
| [HitTestType](./ts-basic-components-web-e.md#hittesttype) | 被点击区域的元素类型。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getHitTest')
          .onClick(() => {
            let hitType = this.controller.getHitTest()
            console.log("hitType: " + hitType)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadData<sup>(deprecated)</sup>

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

baseUrl为空时，通过”data“协议加载指定的一段字符串。

当baseUrl为”data“协议时，编码后的data字符串将被Web组件作为”data"协议加载。

当baseUrl为“http/https"协议时，编码后的data字符串将被Web组件以类似loadUrl的方式以非编码字符串处理。

从API version 9开始不再维护，建议使用[loadData<sup>9+</sup>](./js-apis-webview-WebviewController.md#loaddata)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型   | 必填   | 说明                                     |
| ---------- | ------ | ---- | ---------------------------------------- |
| data       | string | 是   | 按照”Base64“或者”URL"编码后的一段字符串。              |
| mimeType   | string | 是   | 媒体类型（MIME）。                              |
| encoding   | string | 是   | 编码类型，具体为“Base64"或者”URL编码。                |
| baseUrl    | string | 否   | 指定的一个URL路径（“http”/“https”/"data"协议），并由Web组件赋值给`window.origin`。 |
| historyUrl | string | 否   | 历史记录URL。非空时，可被历史记录管理，实现前后后退功能。当baseUrl为空时，此属性无效。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadData')
          .onClick(() => {
            this.controller.loadData({
              data: "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              mimeType: "text/html",
              encoding: "UTF-8"
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

使用指定的http头加载指定的URL。

通过loadUrl注入的对象只在当前document有效，即通过loadUrl导航到新的页面会无效。

而通过registerJavaScriptProxy注入的对象，在loadUrl导航到新的页面也会有效。

从API version 9开始不再维护，建议使用[loadUrl<sup>9+</sup>](./js-apis-webview-WebviewController.md#loadurl)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                       | 必填  | 说明           |
| -------- | -------------------------- | ---- | -------------- |
| url      | string \| Resource                     | 是  | 需要加载的 URL。     |
| headers  | Array\<[Header](#header)\> | 否    | URL的附加HTTP请求头。<br>默认值：[]。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            this.controller.loadUrl({ url: 'www.example.com' })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onActive<sup>(deprecated)</sup>

onActive(): void

调用此接口通知Web组件进入前台激活状态。

从API version 9开始不再维护，建议使用[onActive<sup>9+</sup>](./js-apis-webview-WebviewController.md#onactive)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onActive')
          .onClick(() => {
            this.controller.onActive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onInactive<sup>(deprecated)</sup>

onInactive(): void

调用此接口通知Web组件进入未激活状态。

从API version 9开始不再维护，建议使用[onInactive<sup>9+</sup>](./js-apis-webview-WebviewController.md#oninactive)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onInactive')
          .onClick(() => {
            this.controller.onInactive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### zoom<sup>(deprecated)</sup>

zoom(factor: number): void

调整当前网页的缩放比例。

从API version 9开始不再维护，建议使用[zoom<sup>9+</sup>](./js-apis-webview-WebviewController.md#zoom)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| factor | number | 是    | 基于当前网页所需调整的相对缩放比例，正值为放大，负值为缩小。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State factor: number = 1

    build() {
      Column() {
        Button('zoom')
          .onClick(() => {
            this.controller.zoom(this.factor)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### refresh<sup>(deprecated)</sup>

refresh()

调用此接口通知Web组件刷新网页。

从API version 9开始不再维护，建议使用[refresh<sup>9+</sup>](./js-apis-webview-WebviewController.md#refresh)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            this.controller.refresh()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refreshdeprecated)接口生效。

从API version 9开始不再维护，建议使用[registerJavaScriptProxy<sup>9+</sup>](./js-apis-webview-WebviewController.md#registerjavascriptproxy)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型            | 必填  | 说明                                     |
| ---------- | --------------- | ---- | ---------------------------------------- |
| object     | object          | 是    | 参与注册的应用侧JavaScript对象。可以声明方法，也可以声明属性，但是不支持h5直接调用。其中方法的参数和返回类型只能为string，number，boolean |
| name       | string          | 是    | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string\> | 是    | 参与注册的应用侧JavaScript对象的方法。                 |

**示例：**

  ```ts
  // xxx.ets
  class TestObj {
    constructor() {
    }

    test(): string {
      return "ArkUI Web Component"
    }

    toString(): void {
      console.log('Web Component toString')
    }
  }

  @Entry
  @Component
  struct Index {
    controller: WebController = new WebController()
    testObj = new TestObj();
    build() {
      Column() {
        Row() {
          Button('Register JavaScript To Window').onClick(() => {
            this.controller.registerJavaScriptProxy({
              object: this.testObj,
              name: "objName",
              methodList: ["test", "toString"],
            })
          })
        }
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <meta charset="utf-8">
      <body>
          Hello world!
      </body>
      <script type="text/javascript">
      function htmlTest() {
          str = objName.test("test function")
          console.log('objName.test result:'+ str)
      }
  </script>
  </html>

  ```

### runJavaScript<sup>(deprecated)</sup>

runJavaScript(options: { script: string, callback?: (result: string) => void })

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

从API version 9开始不再维护，建议使用[runJavaScript<sup>9+</sup>](./js-apis-webview-WebviewController.md#runjavascript)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                                     |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| script   | string                   | 是   | JavaScript脚本。                            |
| callback | (result: string) => void | 否   | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State webResult: string = ''
    build() {
      Column() {
        Text(this.webResult).fontSize(20)
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd((event) => {
          this.controller.runJavaScript({
            script: 'test()',
            callback: (result: string)=> {
              this.webResult = result
              console.info(`The test() return value is: ${result}`)
            }})
          if (event) {
            console.info('url: ', event.url)
          }
        })
      }
    }
  }
  ```
  加载的html文件。
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
        console.log('Ark WebComponent')
        return "This value is from index.html"
    }
    </script>
  </html>
  ```

### stop<sup>(deprecated)</sup>

stop()

停止页面加载。

从API version 9开始不再维护，建议使用[stop<sup>9+</sup>](./js-apis-webview-WebviewController.md#stop)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('stop')
          .onClick(() => {
            this.controller.stop()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### clearHistory<sup>(deprecated)</sup>

clearHistory(): void

删除所有前进后退记录。

从API version 9开始不再维护，建议使用[clearHistory<sup>9+</sup>](./js-apis-webview-WebviewController.md#clearhistory)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearHistory')
          .onClick(() => {
            this.controller.clearHistory()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebCookie

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有Web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。

### constructor

constructor()

WebCookie的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

### setCookie<sup>(deprecated)</sup>

setCookie()

设置cookie，该方法为同步方法。设置成功返回true，否则返回false。

从API version 9开始不再维护，建议使用[setCookie<sup>9+</sup>](./js-apis-webview-WebCookieManager.md#setcookiedeprecated)代替。

**系统能力：** SystemCapability.Web.Webview.Core

### saveCookie<sup>(deprecated)</sup>

saveCookie()

将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。

从API version 9开始不再维护，建议使用[saveCookieAsync<sup>9+</sup>](./js-apis-webview-WebCookieManager.md#savecookieasync)代替。

**系统能力：** SystemCapability.Web.Webview.Core