

# @ohos.web.webview (Webview)

@ohos.web.webview提供web控制能力，[web](../arkui-ts/ts-basic-components-web.md)组件提供网页显示的能力。

> **说明：**
>
> - 本模块接口从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[权限申请声明](../../security/accesstoken-guidelines.md)。

## 导入模块

```ts
import web_webview from '@ohos.web.webview';
```

## once

once(type: string, callback: Callback\<void\>): void

订阅一次指定类型Web事件的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型              | 必填 | 说明                  |
| ------- | ---------------- | ---- | -------------------- |
| type     | string          | 是   | Web事件的类型，目前支持："webInited"（Web初始化完成）。      |
| callback | Callback\<void\> | 是   | 所订阅的回调函数。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

web_webview.once("webInited", () => {
  console.log("setCookie")
  web_webview.WebCookieManager.setCookie("https://www.example.com", "a=b")
})

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebMessagePort

通过WebMessagePort可以进行消息的发送以及接收。

### postMessageEvent

postMessageEvent(message: WebMessage): void

发送消息。完整示例代码参考[postMessage](#postmessage)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| message | [WebMessage](#webmessage) | 是   | 要发送的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100010 | Can not post message using this port. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('postMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            this.ports[1].postMessageEvent("post message from ets to html5");
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onMessageEvent

onMessageEvent(callback: (result: WebMessage) => void): void

注册回调函数，接收HTML侧发送过来的消息。完整示例代码参考[postMessage](#postmessage)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | :------------------- |
| result | [WebMessage](#webmessage) | 是   | 接收到的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                        |
| -------- | ----------------------------------------------- |
| 17100006 | Can not register message event using this port. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('onMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.ports[1].onMessageEvent((msg) => {
              if (typeof(msg) == "string") {
                console.log("received string message from html5, string is:" + msg);
              } else if (typeof(msg) == "object") {
                if (msg instanceof ArrayBuffer) {
                  console.log("received arraybuffer from html5, length is:" + msg.byteLength);
                } else {
                  console.log("not support");
                }
              } else {
                console.log("not support");
              }
            })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isExtentionType<sup>10+</sup>

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 类型   | 可读 | 可写 | 说明                                              |
| ------------ | ------ | ---- | ---- | ------------------------------------------------|
| isExtentionType | boolean | 是   | 否 | 创建WebMessagePort时是否指定使用扩展增强接口。   |

### postMessageEventExt<sup>10+</sup>

postMessageEventExt(message: WebMessageExt): void

发送消息。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| message | [WebMessageExt](#webmessageext10) | 是   | 要发送的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100010 | Can not post message using this port. |

### onMessageEventExt<sup>10+</sup>

onMessageEventExt(callback: (result: WebMessageExt) => void): void

注册回调函数，接收HTML5侧发送过来的消息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | :------------------- |
| result | [WebMessageExt](#webmessageext10) | 是   | 接收到的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                        |
| -------- | ----------------------------------------------- |
| 17100006 | Can not register message event using this port. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

// 应用与网页互发消息的示例：使用"init_web_messageport"的通道，通过端口0在应用侧接受网页发送的消息，通过端口1在网页侧接受应用发送的消息。
@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[] = [];
  nativePort: web_webview.WebMessagePort | null = null;
  @State msg1: string = "";
  @State msg2: string = "";
  message: web_webview.WebMessageExt = new web_webview.WebMessageExt();

  build() {
    Column() {
      Text(this.msg1).fontSize(16)
      Text(this.msg2).fontSize(16)
      Button('SendToH5')
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setString("helloFromEts");
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.log("In ArkTS side send message catch error:" + e.code + ", msg:" + e.message);
          }
        })

      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onPageEnd(() => {
          console.log("In ArkTS side message onPageEnd init mesaage channel");
          // 1. 创建消息端口
          this.ports = this.controller.createWebMessagePorts(true);
          // 2. 发送端口1到HTML5
          this.controller.postMessage("init_web_messageport", [this.ports[1]], "*");
          // 3. 保存端口0到本地
          this.nativePort = this.ports[0];
          // 4. 设置回调函数
          this.nativePort.onMessageEventExt((result) => {
            console.log("In ArkTS side got message");
            try {
              let type = result.getType();
              console.log("In ArkTS side getType:" + type);
              switch (type) {
                case web_webview.WebMessageType.STRING: {
                  this.msg1 = "result type:" + typeof (result.getString());
                  this.msg2 = "result getString:" + ((result.getString()));
                  break;
                }
                case web_webview.WebMessageType.NUMBER: {
                  this.msg1 = "result type:" + typeof (result.getNumber());
                  this.msg2 = "result getNumber:" + ((result.getNumber()));
                  break;
                }
                case web_webview.WebMessageType.BOOLEAN: {
                  this.msg1 = "result type:" + typeof (result.getBoolean());
                  this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                  break;
                }
                case web_webview.WebMessageType.ARRAY_BUFFER: {
                  this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                  this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                  break;
                }
                case web_webview.WebMessageType.ARRAY: {
                  this.msg1 = "result type:" + typeof (result.getArray());
                  this.msg2 = "result getArray:" + result.getArray();
                  break;
                }
                case web_webview.WebMessageType.ERROR: {
                  this.msg1 = "result type:" + typeof (result.getError());
                  this.msg2 = "result getError:" + result.getError();
                  break;
                }
                default: {
                  this.msg1 = "default break, type:" + type;
                  break;
                }
              }
            }
            catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          });
        })
    }
  }
}
```

加载的html文件。
```html
<!--index.html-->
<!DOCTYPE html>
<html lang="en-gb">
<head>
    <title>WebView MessagePort Demo</title>
</head>

<body>
<h1>Html5 Send and Receive Message</h1>
<h3 id="msg">Receive string:</h3>
<h3 id="msg2">Receive arraybuffer:</h3>
<div style="font-size: 10pt; text-align: center;">
    <input type="button" value="Send String" onclick="postStringToApp();" /><br/>
</div>
</body>
<script src="index.js"></script>
</html>
```

```js
//index.js
var h5Port;
window.addEventListener('message', function(event) {
    if (event.data == 'init_web_messageport') {
        if(event.ports[0] != null) {
            h5Port = event.ports[0]; // 1. 保存从ets侧发送过来的端口
            h5Port.onmessage = function(event) {
                console.log("hwd In html got message");
                // 2. 接收ets侧发送过来的消息.
                var result = event.data;
                console.log("In html got message, typeof: ", typeof(result));
                console.log("In html got message, result: ", (result));
                if (typeof(result) == "string") {
                    console.log("In html got message, String: ", result);
                    document.getElementById("msg").innerHTML  =  "String:" + result;
                } else if (typeof(result) == "number") {
                  console.log("In html side got message, number: ", result);
                    document.getElementById("msg").innerHTML = "Number:" + result;
                } else if (typeof(result) == "boolean") {
                    console.log("In html side got message, boolean: ", result);
                    document.getElementById("msg").innerHTML = "Boolean:" + result;
                } else if (typeof(result) == "object") {
                    if (result instanceof ArrayBuffer) {
                        document.getElementById("msg2").innerHTML  =  "ArrayBuffer:" + result.byteLength;
                        console.log("In html got message, byteLength: ", result.byteLength);
                    } else if (result instanceof Error) {
                        console.log("In html error message, err:" + (result));
                        console.log("In html error message, typeof err:" + typeof(result));
                        document.getElementById("msg2").innerHTML  =  "Error:" + result.name + ", msg:" + result.message;
                    } else if (result instanceof Array) {
                        console.log("In html got message, Array");
                        console.log("In html got message, Array length:" + result.length);
                        console.log("In html got message, Array[0]:" + (result[0]));
                        console.log("In html got message, typeof Array[0]:" + typeof(result[0]));
                        document.getElementById("msg2").innerHTML  =  "Array len:" + result.length + ", value:" + result;
                    } else {
                        console.log("In html got message, not any instance of support type");
                        document.getElementById("msg").innerHTML  = "not any instance of support type";
                    }
                } else {
                    console.log("In html got message, not support type");
                    document.getElementById("msg").innerHTML  = "not support type";
                }
            }
            h5Port.onmessageerror = (event) => {
                console.error(`hwd In html Error receiving message: ${event}`);
            };
        }
    }
})

// 使用h5Port往ets侧发送String类型的消息.
function postStringToApp() {
    if (h5Port) {
        console.log("In html send string message");
        h5Port.postMessage("hello");
        console.log("In html send string message end");
    } else {
        console.error("In html h5port is null, please init first");
    }
}
```

### close

close(): void

关闭该消息端口。在使用close前，请先使用[createWebMessagePorts](#createwebmessageports)创建消息端口。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  msgPort: web_webview.WebMessagePort[] = [];

  build() {
    Column() {
      // 先使用createWebMessagePorts创建端口。
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.msgPort = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.msgPort.length)
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('close')
        .onClick(() => {
          try {
            if (this.msgPort && this.msgPort.length == 2) {
              this.msgPort[1].close();
            } else {
              console.error("msgPort is null, Please initialize first");
            }
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebviewController

通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。

### initializeWebEngine

static initializeWebEngine(): void

在 Web 组件初始化之前，通过此接口加载 Web 引擎的动态库文件，以提高启动性能。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

本示例以EntryAbility为例，描述了在 Ability 创建阶段完成 Web 组件动态库加载的功能。

```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate")
    web_webview.WebviewController.initializeWebEngine()
    console.log("EntryAbility onCreate done")
  }
}
```

### setHttpDns<sup>10+</sup>

static setHttpDns(secureDnsMode:SecureDnsMode, secureDnsConfig:string): void

设置Web组件是否使用HTTPDNS解析dns。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| secureDnsMode         |   [SecureDnsMode](#securednsmode10)   | 是   | 使用HTTPDNS的模式。|
| secureDnsConfig       | string | 是 | HTTPDNS server的配置，必须是https协议并且只允许配置一个server。 |

**示例：**

```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';
import business_error from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate")
    try {
      web_webview.WebviewController.setHttpDns(web_webview.SecureDnsMode.AUTO, "https://example1.test")
    } catch (error) {
      let e: business_error.BusinessError = error as business_error.BusinessError;
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
    }

    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done")
  }
}
```

### setWebDebuggingAccess

static setWebDebuggingAccess(webDebuggingAccess: boolean): void

设置是否启用网页调试功能。详情请参考[Devtools工具](../../web/web-debugging-with-devtools.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| webDebuggingAccess | boolean | 是   | 设置是否启用网页调试功能。|

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  aboutToAppear(): void {
    try {
      web_webview.WebviewController.setWebDebuggingAccess(true);
    } catch (error) {
      let e: business_error.BusinessError = error as business_error.BusinessError;
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### loadUrl

loadUrl(url: string | Resource, headers?: Array\<WebHeader>): void

加载指定的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                  |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string \| Resource | 是   | 需要加载的 URL。      |
| headers | Array\<[WebHeader](#webheader)> | 否   | URL的附加HTTP请求头。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 需要加载的URL是string类型。
            this.controller.loadUrl('www.example.com');
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 带参数headers。
            this.controller.loadUrl('www.example.com', [{ headerKey: "headerKey", headerValue: "headerValue" }]);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

加载本地网页，加载本地资源文件有三种方式。

1.$rawfile方式。
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 通过$rawfile加载本地资源文件。
            this.controller.loadUrl($rawfile('index.html'));
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.resources协议。
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 通过resource协议加载本地资源文件。
            this.controller.loadUrl("resource://rawfile/index.html");
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

3.通过沙箱路径加载本地文件，可以参考[web](../arkui-ts/ts-basic-components-web.md#web)加载沙箱路径的示例代码。

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

### loadData

loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void

加载指定的数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| data       | string | 是   | 按照"Base64"或者"URL"编码后的一段字符串。                    |
| mimeType   | string | 是   | 媒体类型（MIME）。                                           |
| encoding   | string | 是   | 编码类型，具体为"Base64"或者"URL"编码。                       |
| baseUrl    | string | 否   | 指定的一个URL路径（"http"/"https"/"data"协议），并由Web组件赋值给window.origin。 |
| historyUrl | string | 否   | 用作历史记录所使用的URL。非空时，历史记录以此URL进行管理。当baseUrl为空时，此属性无效。 |

> **说明：**
> 
> 若加载本地图片，可以给baseUrl或historyUrl任一参数赋值空格，详情请参考示例代码。
> 加载本地图片场景，baseUrl和historyUrl不能同时为空，否则图片无法成功加载。

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(
              "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              "text/html",
              "UTF-8"
            );
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

加载本地资源
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  updataContent: string = '<body><div><image src=resource://rawfile/xxx.png alt="image -- end" width="500" height="250"></image></div></body>'

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(this.updataContent, "text/html", "UTF-8", " ", " ");
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessForward

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 可以前进返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('accessForward')
        .onClick(() => {
          try {
            let result = this.controller.accessForward();
            console.log('result:' + result);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### forward

forward(): void

按照历史栈，前进一个页面。一般结合accessForward一起使用。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessBackward

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                             |
| ------- | -------------------------------- |
| boolean | 可以后退返回true,否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('accessBackward')
        .onClick(() => {
          try {
            let result = this.controller.accessBackward();
            console.log('result:' + result);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### backward

backward(): void

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onActive

onActive(): void

调用此接口通知Web组件进入前台激活状态。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('onActive')
        .onClick(() => {
          try {
            this.controller.onActive();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onInactive

onInactive(): void

调用此接口通知Web组件进入未激活状态。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('onInactive')
        .onClick(() => {
          try {
            this.controller.onInactive();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### refresh
refresh(): void

调用此接口通知Web组件刷新网页。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessStep

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                   |
| ------ | -------- | ---- | ------------------------------------------ |
| step   | number   | 是   | 要跳转的步数，正数代表前进，负数代表后退。 |

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| boolean | 页面是否前进或后退 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State steps: number = 2;

  build() {
    Column() {
      Button('accessStep')
        .onClick(() => {
          try {
            let result = this.controller.accessStep(this.steps);
            console.log('result:' + result);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearHistory

clearHistory(): void

删除所有前进后退记录。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearHistory')
        .onClick(() => {
          try {
            this.controller.clearHistory();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getHitTest

getHitTest(): WebHitTestType

获取当前被点击区域的元素类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| [WebHitTestType](#webhittesttype)| 被点击区域的元素类型。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getHitTest')
        .onClick(() => {
          try {
            let hitTestType = this.controller.getHitTest();
            console.log("hitTestType: " + hitTestType);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### registerJavaScriptProxy

registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refresh)接口生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型       | 必填 | 说明                                        |
| ---------- | -------------- | ---- | ------------------------------------------------------------ |
| object     | object         | 是   | 参与注册的应用侧JavaScript对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean |
| name       | string         | 是   | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string> | 是   | 参与注册的应用侧JavaScript对象的方法。                       |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

class testObj {
  constructor() {
  }

  test(): string {
    console.log('ArkUI Web Component');
    return "ArkUI Web Component";
  }

  toString(): void {
    console.log('Web Component toString');
  }
}

class webObj {
  constructor() {
  }

  webTest(): string {
    console.log('Web test');
    return "Web test";
  }

  webString(): void {
    console.log('Web test toString');
  }
}

@Entry
@Component
struct Index {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State testObjtest: testObj = new testObj();
  @State webTestObj: webObj = new webObj();
  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObjtest, "objName", ["test", "toString"]);
            this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
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
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <p id="webDemo"></p>
    </body>
    <script type="text/javascript">
    function htmlTest() {
      // This function call expects to return "ArkUI Web Component"
      let str=objName.test();
      document.getElementById("demo").innerHTML=str;
      console.log('objName.test result:'+ str)

      // This function call expects to return "Web test"
      let webStr = objTestName.webTest();
      document.getElementById("webDemo").innerHTML=webStr;
      console.log('objTestName.webTest result:'+ webStr)
    }
</script>
</html>
```

### runJavaScript

runJavaScript(script: string, callback : AsyncCallback\<string>): void

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string                   | 是   | JavaScript脚本。                                             |
| callback | AsyncCallback\<string> | 是   | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State webResult: string = ''

  build() {
    Column() {
      Text(this.webResult).fontSize(20)
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            this.controller.runJavaScript(
              'test()',
              (error, result) => {
                if (error) {
                  console.info(`run JavaScript error: ` + JSON.stringify(error))
                  return;
                }
                if (result) {
                  this.webResult = result
                  console.info(`The test() return value is: ${result}`)
                }
              });
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
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

### runJavaScript

runJavaScript(script: string): Promise\<string>

异步执行JavaScript脚本，并通过Promise方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | -------- | ---- | ---------------- |
| script | string   | 是   | JavaScript脚本。 |

**返回值：**

| 类型            | 说明                                                |
| --------------- | --------------------------------------------------- |
| Promise\<string> | Promise实例，返回脚本执行的结果，执行失败返回null。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            this.controller.runJavaScript('test()')
              .then((result) => {
                console.log('result: ' + result);
              })
              .catch((error: business_error.BusinessError) => {
                console.error("error: " + error);
              })
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
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

### runJavaScriptExt<sup>10+</sup>

runJavaScriptExt(script: string, callback : AsyncCallback\<JsMessageExt>): void

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScriptExt需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string                   | 是   | JavaScript脚本。                                             |
| callback | AsyncCallback\<[JsMessageExt](#jsmessageext10)\> | 是   | 回调执行JavaScript脚本结果。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State msg1: string = ''
  @State msg2: string = ''

  build() {
    Column() {
      Text(this.msg1).fontSize(20)
      Text(this.msg2).fontSize(20)
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            this.controller.runJavaScriptExt(
              'test()',
              (error, result) => {
                if (error) {
                  console.info(`run JavaScript error: ` + JSON.stringify(error))
                  return;
                }
                if (result) {
                  try {
                    let type = result.getType();
                    switch (type) {
                      case web_webview.JsMessageType.STRING: {
                        this.msg1 = "result type:" + typeof (result.getString());
                        this.msg2 = "result getString:" + ((result.getString()));
                        break;
                      }
                      case web_webview.JsMessageType.NUMBER: {
                        this.msg1 = "result type:" + typeof (result.getNumber());
                        this.msg2 = "result getNumber:" + ((result.getNumber()));
                        break;
                      }
                      case web_webview.JsMessageType.BOOLEAN: {
                        this.msg1 = "result type:" + typeof (result.getBoolean());
                        this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                        break;
                      }
                      case web_webview.JsMessageType.ARRAY_BUFFER: {
                        this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                        this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                        break;
                      }
                      case web_webview.JsMessageType.ARRAY: {
                        this.msg1 = "result type:" + typeof (result.getArray());
                        this.msg2 = "result getArray:" + result.getArray();
                        break;
                      }
                      default: {
                        this.msg1 = "default break, type:" + type;
                        break;
                      }
                    }
                  }
                  catch (resError) {
                    let e: business_error.BusinessError = resError as business_error.BusinessError;
                    console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
                  }
                }
              });
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
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
<html lang="en-gb">
<body>
<h1>run JavaScript Ext demo</h1>
</body>
<script type="text/javascript">
function test() {
  return "hello, world";
}
</script>
</html>
```

### runJavaScriptExt<sup>10+</sup>

runJavaScriptExt(script: string): Promise\<JsMessageExt>

异步执行JavaScript脚本，并通过Promise方式返回脚本执行的结果。runJavaScriptExt需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | -------- | ---- | ---------------- |
| script | string   | 是   | JavaScript脚本。 |

**返回值：**

| 类型            | 说明                                                |
| --------------- | --------------------------------------------------- |
| Promise\<[JsMessageExt](#jsmessageext10)> | Promise实例，返回脚本执行的结果。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State webResult: string = '';
  @State msg1: string = ''
  @State msg2: string = ''

  build() {
    Column() {
      Text(this.webResult).fontSize(20)
      Text(this.msg1).fontSize(20)
      Text(this.msg2).fontSize(20)
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(() => {
          this.controller.runJavaScriptExt('test()')
            .then((result) => {
              try {
                let type = result.getType();
                switch (type) {
                  case web_webview.JsMessageType.STRING: {
                    this.msg1 = "result type:" + typeof (result.getString());
                    this.msg2 = "result getString:" + ((result.getString()));
                    break;
                  }
                  case web_webview.JsMessageType.NUMBER: {
                    this.msg1 = "result type:" + typeof (result.getNumber());
                    this.msg2 = "result getNumber:" + ((result.getNumber()));
                    break;
                  }
                  case web_webview.JsMessageType.BOOLEAN: {
                    this.msg1 = "result type:" + typeof (result.getBoolean());
                    this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                    break;
                  }
                  case web_webview.JsMessageType.ARRAY_BUFFER: {
                    this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                    this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                    break;
                  }
                  case web_webview.JsMessageType.ARRAY: {
                    this.msg1 = "result type:" + typeof (result.getArray());
                    this.msg2 = "result getArray:" + result.getArray();
                    break;
                  }
                  default: {
                    this.msg1 = "default break, type:" + type;
                    break;
                  }
                }
              }
              catch (resError) {
                let e: business_error.BusinessError = resError as business_error.BusinessError;
                console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
              }
            })
            .catch((error: business_error.BusinessError) => {
              console.error("error: " + error);
            })
        })
    }
  }
}
```

加载的html文件。
```html
<!-- index.html -->
<!DOCTYPE html>
<html lang="en-gb">
<body>
<h1>run JavaScript Ext demo</h1>
</body>
<script type="text/javascript">
function test() {
  return "hello, world";
}
</script>
</html>
```

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后，须调用[refresh](#refresh)接口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------ | -------- | ---- | ---- |
| name   | string   | 是   | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100008 | Cannot delete JavaScriptProxy.                               |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

class testObj {
  constructor() {
  }

  test(): string {
    return "ArkUI Web Component";
  }

  toString(): void {
    console.log('Web Component toString');
  }
}

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State testObjtest: testObj = new testObj();
  @State name: string = 'objName';
  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObjtest, this.name, ["test", "toString"]);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister(this.name);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
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
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
    </body>
    <script type="text/javascript">
    function htmlTest() {
      let str=objName.test();
      document.getElementById("demo").innerHTML=str;
      console.log('objName.test result:'+ str)
    }
</script>
</html>
```

### zoom

zoom(factor: number): void

调整当前网页的缩放比例，[zoomAccess](../arkui-ts/ts-basic-components-web.md#zoomaccess)需为true。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | 是   | 基于当前网页所需调整的相对缩放比例，入参要求大于0，当入参为1时为默认加载网页的缩放比例，入参小于1为缩小，入参大于1为放大。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100004 | Function not enable.                                         |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State factor: number = 1;

  build() {
    Column() {
      Button('zoom')
        .onClick(() => {
          try {
            this.controller.zoom(this.factor);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .zoomAccess(true)
    }
  }
}
```

### searchAllAsync

searchAllAsync(searchString: string): void

异步查找网页中所有匹配关键字'searchString'的内容并高亮，结果通过[onSearchResultReceive](../arkui-ts/ts-basic-components-web.md#onsearchresultreceive9)异步返回。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型 | 必填 | 说明       |
| ------------ | -------- | ---- | -------------- |
| searchString | string   | 是   | 查找的关键字。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State searchString: string = "Hello World";

  build() {
    Column() {
      Button('searchString')
        .onClick(() => {
          try {
            this.controller.searchAllAsync(this.searchString);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onSearchResultReceive(ret => {
          if (ret) {
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
              "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
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
  <body>
    <p>Hello World Highlight Hello World</p>
  </body>
</html>
```

### clearMatches

clearMatches(): void

清除所有通过[searchAllAsync](#searchallasync)匹配到的高亮字符查找结果。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearMatches')
        .onClick(() => {
          try {
            this.controller.clearMatches();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件，请参考[searchAllAsync](#searchallasync)接口下加载的html文件。

### searchNext

searchNext(forward: boolean): void

滚动到下一个匹配的查找结果并高亮。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明               |
| ------- | -------- | ---- | ---------------------- |
| forward | boolean  | 是   | 从前向后或者逆向查找。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('searchNext')
        .onClick(() => {
          try {
            this.controller.searchNext(true);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件，请参考[searchAllAsync](#searchallasync)接口下加载的html文件。

### clearSslCache

clearSslCache(): void

清除Web组件记录的SSL证书错误事件对应的用户操作行为。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearSslCache')
        .onClick(() => {
          try {
            this.controller.clearSslCache();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearClientAuthenticationCache

clearClientAuthenticationCache(): void

清除Web组件记录的客户端证书请求事件对应的用户操作行为。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearClientAuthenticationCache')
        .onClick(() => {
          try {
            this.controller.clearClientAuthenticationCache();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### createWebMessagePorts

createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>

创建Web消息端口。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型                   | 必填 | 说明                             |
| ------ | ---------------------- | ---- | :------------------------------|
| isExtentionType<sup>10+</sup>   | boolean     | 否  | 是否使用扩展增强接口，默认false不使用。 从API version 10开始，该接口支持此参数。|

**返回值：**

| 类型                   | 说明              |
| ---------------------- | ----------------- |
| Array\<[WebMessagePort](#webmessageport)> | web消息端口列表。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

  ```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.ports.length)
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
  ```

### postMessage

postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void

发送Web消息端口到HTML。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型                   | 必填 | 说明                             |
| ------ | ---------------------- | ---- | :------------------------------- |
| name   | string                 | 是   | 要发送的消息名称。            |
| ports  | Array\<WebMessagePort> | 是   | 要发送的消息端口。            |
| uri    | string                 | 是   | 接收该消息的URI。                |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[] = [];
  @State sendFromEts: string = 'Send this message from ets to HTML';
  @State receivedFromHtml: string = 'Display received message send from HTML';

  build() {
    Column() {
      // 展示接收到的来自HTML的内容
      Text(this.receivedFromHtml)
      // 输入框的内容发送到html
      TextInput({ placeholder: 'Send this message from ets to HTML' })
        .onChange((value: string) => {
          this.sendFromEts = value;
        })

      Button('postMessage')
        .onClick(() => {
          try {
            // 1、创建两个消息端口。
            this.ports = this.controller.createWebMessagePorts();
            // 2、在应用侧的消息端口(如端口1)上注册回调事件。
            this.ports[1].onMessageEvent((result: web_webview.WebMessage) => {
              let msg = 'Got msg from HTML:';
              if (typeof(result) == "string") {
                console.log("received string message from html5, string is:" + result);
                msg = msg + result;
              } else if (typeof(result) == "object") {
                if (result instanceof ArrayBuffer) {
                  console.log("received arraybuffer from html5, length is:" + result.byteLength);
                  msg = msg + "lenght is " + result.byteLength;
                } else {
                  console.log("not support");
                }
              } else {
                console.log("not support");
              }
              this.receivedFromHtml = msg;
            })
            // 3、将另一个消息端口(如端口0)发送到HTML侧，由HTML侧保存并使用。
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })

      // 4、使用应用侧的端口给另一个已经发送到html的端口发送消息。
      Button('SendDataToHTML')
        .onClick(() => {
          try {
            if (this.ports && this.ports[1]) {
              this.ports[1].postMessageEvent(this.sendFromEts);
            } else {
              console.error(`ports is null, Please initialize first`);
            }
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件。
```html
<!--index.html-->
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WebView Message Port Demo</title>
</head>

  <body>
    <h1>WebView Message Port Demo</h1>
    <div>
        <input type="button" value="SendToEts" onclick="PostMsgToEts(msgFromJS.value);"/><br/>
        <input id="msgFromJS" type="text" value="send this message from HTML to ets"/><br/>
    </div>
    <p class="output">display received message send from ets</p>
  </body>
  <script src="xxx.js"></script>
</html>
```

```js
//xxx.js
var h5Port;
var output = document.querySelector('.output');
window.addEventListener('message', function (event) {
    if (event.data == '__init_port__') {
        if (event.ports[0] != null) {
            h5Port = event.ports[0]; // 1. 保存从ets侧发送过来的端口
            h5Port.onmessage = function (event) {
              // 2. 接收ets侧发送过来的消息.
              var msg = 'Got message from ets:';
              var result = event.data;
              if (typeof(result) == "string") {
                console.log("received string message from html5, string is:" + result);
                msg = msg + result;
              } else if (typeof(result) == "object") {
                if (result instanceof ArrayBuffer) {
                  console.log("received arraybuffer from html5, length is:" + result.byteLength);
                  msg = msg + "lenght is " + result.byteLength;
                } else {
                  console.log("not support");
                }
              } else {
                console.log("not support");
              }
              output.innerHTML = msg;
            }
        }
    }
})

// 3. 使用h5Port往ets侧发送消息.
function PostMsgToEts(data) {
    if (h5Port) {
      h5Port.postMessage(data);
    } else {
      console.error("h5Port is null, Please initialize first");
    }
}
```

### requestFocus

requestFocus(): void

使当前web页面获取焦点。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('requestFocus')
        .onClick(() => {
          try {
            this.controller.requestFocus();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        });
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoomIn

zoomIn(): void

调用此接口将当前网页进行放大，比例为20%。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('zoomIn')
        .onClick(() => {
          try {
            this.controller.zoomIn();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoomOut

zoomOut(): void

调用此接口将当前网页进行缩小，比例为20%。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('zoomOut')
        .onClick(() => {
          try {
            this.controller.zoomOut();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getHitTestValue

getHitTestValue(): HitTestValue

获取当前被点击区域的元素信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型         | 说明                 |
| ------------ | -------------------- |
| [HitTestValue](#hittestvalue) | 点击区域的元素信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getHitTestValue')
        .onClick(() => {
          try {
            let hitValue = this.controller.getHitTestValue();
            console.log("hitType: " + hitValue.type);
            console.log("extra: " + hitValue.extra);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getWebId

getWebId(): number

获取当前Web组件的索引值，用于多个Web组件的管理。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                  |
| ------ | --------------------- |
| number | 当前Web组件的索引值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getWebId')
        .onClick(() => {
          try {
            let id = this.controller.getWebId();
            console.log("id: " + id);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUserAgent

getUserAgent(): string

获取当前默认用户代理。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| string | 默认用户代理。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  
  build() {
    Column() {
      Button('getUserAgent')
        .onClick(() => {
          try {
            let userAgent = this.controller.getUserAgent();
            console.log("userAgent: " + userAgent);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

支持开发者基于默认的UserAgent去定制UserAgent。
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State ua: string = ""

  aboutToAppear():void {
    web_webview.once('webInited', () => {
      try {
        // 应用侧用法示例，定制UserAgent。
        this.ua = this.controller.getUserAgent() + 'xxx';
      } catch(error) {
        let e:business_error.BusinessError = error as business_error.BusinessError;
        console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
      }
    })
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .userAgent(this.ua)
    }
  }
}
```

### getTitle

getTitle(): string

获取当前网页的标题。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 当前网页的标题。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getTitle')
        .onClick(() => {
          try {
            let title = this.controller.getTitle();
            console.log("title: " + title);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getPageHeight

getPageHeight(): number

获取当前网页的页面高度。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 当前网页的页面高度。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getPageHeight')
        .onClick(() => {
          try {
            let pageHeight = this.controller.getPageHeight();
            console.log("pageHeight : " + pageHeight);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### storeWebArchive

storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void

以回调方式异步保存当前页面。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型              | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| baseName | string                | 是   | 生成的离线网页存储位置，该值不能为空。                                 |
| autoName | boolean               | 是   | 决定是否自动生成文件名。如果为false，则按baseName的文件名存储；如果为true，则根据当前Url自动生成文件名，并按baseName的文件目录存储。 |
| callback | AsyncCallback\<string> | 是   | 返回文件存储路径，保存网页失败会返回null。                   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('storeWebArchive')
        .onClick(() => {
          try {
            this.controller.storeWebArchive("/data/storage/el2/base/", true, (error, filename) => {
              if (error) {
                console.info(`save web archive error: ` + JSON.stringify(error))
                return;
              }
              if (filename != null) {
                console.info(`save web archive success: ${filename}`)
              }
            });
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### storeWebArchive

storeWebArchive(baseName: string, autoName: boolean): Promise\<string>

以Promise方式异步保存当前页面。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| baseName | string   | 是   | 生成的离线网页存储位置，该值不能为空。                                 |
| autoName | boolean  | 是   | 决定是否自动生成文件名。如果为false，则按baseName的文件名存储；如果为true，则根据当前Url自动生成文件名，并按baseName的文件目录存储。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<string> | Promise实例，保存成功返回文件路径，保存失败返回null。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('storeWebArchive')
        .onClick(() => {
          try {
            this.controller.storeWebArchive("/data/storage/el2/base/", true)
              .then(filename => {
                if (filename != null) {
                  console.info(`save web archive success: ${filename}`)
                }
              })
              .catch((error:business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUrl

getUrl(): string

获取当前页面的url地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                |
| ------ | ------------------- |
| string | 当前页面的url地址。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getUrl')
        .onClick(() => {
          try {
            let url = this.controller.getUrl();
            console.log("url: " + url);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### stop

stop(): void

停止页面加载。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('stop')
        .onClick(() => {
          try {
            this.controller.stop();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        });
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### backOrForward

backOrForward(step: number): void

按照历史栈，前进或者后退指定步长的页面，当历史栈中不存在对应步长的页面时，不会进行页面跳转。

前进或者后退页面时，直接使用已加载过的网页，无需重新加载网页。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| step   | number   | 是   | 需要前进或后退的步长。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State step: number = -2;

  build() {
    Column() {
      Button('backOrForward')
        .onClick(() => {
          try {
            this.controller.backOrForward(this.step);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### scrollTo

scrollTo(x:number, y:number): void

将页面滚动到指定的绝对位置。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| x   | number   | 是   | 绝对位置的水平坐标，当传入数值为负数时，按照传入0处理。 |
| y   | number   | 是   | 绝对位置的垂直坐标，当传入数值为负数时，按照传入0处理。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('scrollTo')
        .onClick(() => {
          try {
            this.controller.scrollTo(50, 50);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件。
```html
<!--index.html-->
<!DOCTYPE html>
<html>
<head>
    <title>Demo</title>
    <style>
        body {
            width:3000px;
            height:3000px;
            padding-right:170px;
            padding-left:170px;
            border:5px solid blueviolet
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```

### scrollBy

scrollBy(deltaX:number, deltaY:number): void

将页面滚动指定的偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | 是   | 水平偏移量，其中水平向右为正方向。 |
| deltaY | number   | 是   | 垂直偏移量，其中垂直向下为正方向。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('scrollBy')
        .onClick(() => {
          try {
            this.controller.scrollBy(50, 50);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件。
```html
<!--index.html-->
<!DOCTYPE html>
<html>
<head>
    <title>Demo</title>
    <style>
        body {
            width:3000px;
            height:3000px;
            padding-right:170px;
            padding-left:170px;
            border:5px solid blueviolet
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```

### slideScroll

slideScroll(vx:number, vy:number): void

按照指定速度模拟对页面的轻扫滚动动作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| vx     | number   | 是   | 轻扫滚动的水平速度分量，其中水平向右为速度正方向。 |
| vy     | number   | 是   | 轻扫滚动的垂直速度分量，其中垂直向下为速度正方向。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('slideScroll')
        .onClick(() => {
          try {
            this.controller.slideScroll(500, 500);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`); 
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件。
```html
<!--index.html-->
<!DOCTYPE html>
<html>
<head>
    <title>Demo</title>
    <style>
        body {
            width:3000px;
            height:3000px;
            padding-right:170px;
            padding-left:170px;
            border:5px solid blueviolet
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```

### getOriginalUrl

getOriginalUrl(): string

获取当前页面的原始url地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                    |
| ------ | ----------------------- |
| string | 当前页面的原始url地址。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getOrgUrl')
        .onClick(() => {
          try {
            let url = this.controller.getOriginalUrl();
            console.log("original url: " + url);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getFavicon

getFavicon(): image.PixelMap

获取页面的favicon图标。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                   | 说明                            |
| -------------------------------------- | ------------------------------- |
| [PixelMap](js-apis-image.md#pixelmap7) | 页面favicon图标的PixelMap对象。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import image from "@ohos.multimedia.image";
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State pixelmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Button('getFavicon')
        .onClick(() => {
          try {
            this.pixelmap = this.controller.getFavicon();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setNetworkAvailable

setNetworkAvailable(enable: boolean): void

设置JavaScript中的window.navigator.onLine属性。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | --------------------------------- |
| enable | boolean | 是   | 是否使能window.navigator.onLine。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('setNetworkAvailable')
        .onClick(() => {
          try {
            this.controller.setNetworkAvailable(true);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

加载的html文件。
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<h1>online 属性</h1>
<p id="demo"></p>
<button onclick="func()">click</button>
<script>
    let online = navigator.onLine;
    document.getElementById("demo").innerHTML = "浏览器在线：" + online;

    function func(){
      var online = navigator.onLine;
      document.getElementById("demo").innerHTML = "浏览器在线：" + online;
    }
</script>
</body>
</html>
```

### hasImage

hasImage(callback: AsyncCallback\<boolean>): void

通过Callback方式异步查找当前页面是否存在图像。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                       |
| -------- | ----------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 返回查找页面是否存在图像。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('hasImageCb')
        .onClick(() => {
          try {
            this.controller.hasImage((error, data) => {
              if (error) {
                console.info(`hasImage error: ` + JSON.stringify(error))
                return;
              }
              console.info("hasImage: " + data);
            });
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### hasImage

hasImage(): Promise\<boolean>

通过Promise方式异步查找当前页面是否存在图像。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise实例，返回查找页面是否存在图像。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('hasImagePm')
        .onClick(() => {
          try {
            this.controller.hasImage().then((data) => {
              console.info('hasImage: ' + data);
            })
            .catch((error:business_error.BusinessError) => {
              console.error("error: " + error);
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### removeCache

removeCache(clearRom: boolean): void

清除应用中的资源缓存文件，此方法将会清除同一应用中所有webview的缓存文件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                     |
| -------- | ------- | ---- | -------------------------------------------------------- |
| clearRom | boolean | 是   | 设置为true时同时清除rom和ram中的缓存，设置为false时只清除ram中的缓存。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('removeCache')
        .onClick(() => {
          try {
            this.controller.removeCache(false);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageUp

pageUp(top:boolean): void

将Webview的内容向上滚动半个视框大小或者跳转到页面最顶部，通过top入参控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| top    | boolean | 是   | 是否跳转到页面最顶部，设置为false时将页面内容向上滚动半个视框大小，设置为true时跳转到页面最顶部。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('pageUp')
        .onClick(() => {
          try {
            this.controller.pageUp(false);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageDown

pageDown(bottom:boolean): void

将Webview的内容向下滚动半个视框大小或者跳转到页面最底部，通过bottom入参控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| bottom | boolean | 是   | 是否跳转到页面最底部，设置为false时将页面内容向下滚动半个视框大小，设置为true时跳转到页面最底部。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('pageDown')
        .onClick(() => {
          try {
            this.controller.pageDown(false);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getBackForwardEntries

getBackForwardEntries(): BackForwardList

获取当前Webview的历史信息列表。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                | 说明                        |
| ----------------------------------- | --------------------------- |
| [BackForwardList](#backforwardlist) | 当前Webview的历史信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getBackForwardEntries')
        .onClick(() => {
          try {
            let list = this.controller.getBackForwardEntries()
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### serializeWebState

serializeWebState(): Uint8Array

将当前Webview的页面状态历史记录信息序列化。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型       | 说明                                          |
| ---------- | --------------------------------------------- |
| Uint8Array | 当前Webview的页面状态历史记录序列化后的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](./js-apis-file-fs.md)。
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import fs from '@ohos.file.fs';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('serializeWebState')
        .onClick(() => {
          try {
            let state = this.controller.serializeWebState();
            let path:string | undefined = AppStorage.get("cacheDir");
            if (path) {
              path += '/WebState';
              // 以同步方法打开文件。
              let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
              fs.writeSync(file.fd, state.buffer);
              fs.closeSync(file.fd);
            }
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.修改EntryAbility.ts。
获取应用缓存文件路径。
```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        // 通过在AppStorage对象上绑定cacheDir，可以实现UIAbility组件与Page之间的数据同步。
        AppStorage.setOrCreate("cacheDir", this.context.cacheDir);
    }
}
```

### restoreWebState

restoreWebState(state: Uint8Array): void

当前Webview从序列化数据中恢复页面状态历史记录。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型       | 必填 | 说明                         |
| ------ | ---------- | ---- | ---------------------------- |
| state  | Uint8Array | 是   | 页面状态历史记录序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](./js-apis-file-fs.md)。
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import fs from '@ohos.file.fs';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('RestoreWebState')
        .onClick(() => {
          try {
            let path:string | undefined = AppStorage.get("cacheDir");
            if (path) {
              path += '/WebState';
              // 以同步方法打开文件。
              let file = fs.openSync(path, fs.OpenMode.READ_WRITE);
              let stat = fs.statSync(path);
              let size = stat.size;
              let buf = new ArrayBuffer(size);
              fs.read(file.fd, buf, (err, readLen) => {
                if (err) {
                  console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
                } else {
                  console.info("read file data succeed");
                  this.controller.restoreWebState(new Uint8Array(buf.slice(0, readLen)));
                  fs.closeSync(file);
                }
              });
            }
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.修改EntryAbility.ts。
获取应用缓存文件路径。
```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        // 通过在AppStorage对象上绑定cacheDir，可以实现UIAbility组件与Page之间的数据同步。
        AppStorage.setOrCreate("cacheDir", this.context.cacheDir);
    }
}
```

### customizeSchemes

static customizeSchemes(schemes: Array\<WebCustomScheme\>): void

配置Web自定义协议请求的权限。建议在任何Web组件初始化之前进行调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明                      |
| -------- | ------- | ---- | -------------------------------------- |
| schemes | Array\<[WebCustomScheme](#webcustomscheme)\> | 是   | 自定义协议配置，最多支持同时配置10个自定义协议。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  responseweb: WebResourceResponse = new WebResourceResponse()
  scheme1: web_webview.WebCustomScheme = {schemeName: "name1", isSupportCORS: true, isSupportFetch: true}
  scheme2: web_webview.WebCustomScheme = {schemeName: "name2", isSupportCORS: true, isSupportFetch: true}
  scheme3: web_webview.WebCustomScheme = {schemeName: "name3", isSupportCORS: true, isSupportFetch: true}

  aboutToAppear():void {
    try {
      web_webview.WebviewController.customizeSchemes([this.scheme1, this.scheme2, this.scheme3])
    } catch(error) {
      let e:business_error.BusinessError = error as business_error.BusinessError;
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onInterceptRequest((event) => {
          if (event) {
            console.log('url:' + event.request.getRequestUrl())
          }
          return this.responseweb
        })
    }
  }
}
```

### getCertificate<sup>10+</sup>

getCertificate(): Promise<Array<cert.X509Cert>>

获取当前网站的证书信息。使用web组件加载https网站，会进行SSL证书校验，该接口会通过Promise异步返回当前网站的X509格式证书（X509Cert证书类型定义见[X509Cert](./js-apis-cert.md#x509cert)定义），便于开发者展示网站证书信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型       | 说明                                          |
| ---------- | --------------------------------------------- |
| Promise<Array<cert.X509Cert>> | Promise实例，用于获取当前加载的https网站的X509格式证书数组。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';
import cert from '@ohos.security.cert';

function Uint8ArrayToString(dataArray:Uint8Array) {
  let dataString = ''
  for (let i = 0; i < dataArray.length; i++) {
    dataString += String.fromCharCode(dataArray[i])
  }
  return dataString
}

function ParseX509CertInfo(x509CertArray:Array<cert.X509Cert>) {
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;
  for (let i = 0; i < x509CertArray.length; i++) {
    res += ', index = ' + i + ', issuer name = '
    + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '
    + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '
    + x509CertArray[i].getNotBeforeTime()
    + ', valid end = ' + x509CertArray[i].getNotAfterTime()
  }
  return res
}

@Entry
@Component
struct Index {
  // outputStr在UI界面显示调试信息
  @State outputStr: string = ''
  webviewCtl: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Row() {
      Column() {
        List({space: 20, initialIndex: 0}) {
          ListItem() {
            Button() {
              Text('load bad ssl')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个过期的证书网站，查看获取到的证书信息
              this.webviewCtl.loadUrl('https://expired.badssl.com')
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('load example')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个https网站，查看网站的证书信息
              this.webviewCtl.loadUrl('https://www.example.com')
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('getCertificate Promise')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              try {
                this.webviewCtl.getCertificate().then((x509CertArray:Array<cert.X509Cert>) => {
                  this.outputStr = ParseX509CertInfo(x509CertArray);
                })
              } catch (error) {
                let e:business_error.BusinessError = error as business_error.BusinessError;
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;
              }
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('getCertificate AsyncCallback')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              try {
                this.webviewCtl.getCertificate((error:business_error.BusinessError, x509CertArray:Array<cert.X509Cert>) => {
                  if (error) {
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;
                  } else {
                    this.outputStr = ParseX509CertInfo(x509CertArray);
                  }
                })
              } catch (error) {
                let e:business_error.BusinessError = error as business_error.BusinessError;
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;
              }
            })
            .height(50)
          }
        }
        .listDirection(Axis.Horizontal)
        .height('10%')

        Text(this.outputStr)
          .width('100%')
          .fontSize(10)

        Web({ src: 'https://www.example.com', controller: this.webviewCtl })
          .fileAccess(true)
          .javaScriptAccess(true)
          .domStorageAccess(true)
          .onlineImageAccess(true)
          .onPageEnd((e) => {
            if(e) {
              this.outputStr = 'onPageEnd : url = ' + e.url
            }
          })
          .onSslErrorEventReceive((e) => {
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com
            e.handler.handleConfirm()
          })
          .width('100%')
          .height('70%')
      }
      .height('100%')
    }
  }
}
```

### getCertificate<sup>10+</sup>

getCertificate(callback: AsyncCallback<Array<cert.X509Cert>>): void

获取当前网站的证书信息。使用web组件加载https网站，会进行SSL证书校验，该接口会通过AsyncCallback异步返回当前网站的X509格式证书（X509Cert证书类型定义见[X509Cert定义](./js-apis-cert.md)），便于开发者展示网站证书信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<Array<cert.X509Cert>> | 是   | 通过AsyncCallback异步返回当前网站的X509格式证书。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';
import cert from '@ohos.security.cert';

function Uint8ArrayToString(dataArray:Uint8Array) {
  let dataString = ''
  for (let i = 0; i < dataArray.length; i++) {
    dataString += String.fromCharCode(dataArray[i])
  }
  return dataString
}

function ParseX509CertInfo(x509CertArray:Array<cert.X509Cert>) {
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;
  for (let i = 0; i < x509CertArray.length; i++) {
    res += ', index = ' + i + ', issuer name = '
    + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '
    + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '
    + x509CertArray[i].getNotBeforeTime()
    + ', valid end = ' + x509CertArray[i].getNotAfterTime()
  }
  return res
}

@Entry
@Component
struct Index {
  // outputStr在UI界面显示调试信息
  @State outputStr: string = ''
  webviewCtl: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Row() {
      Column() {
        List({space: 20, initialIndex: 0}) {
          ListItem() {
            Button() {
              Text('load bad ssl')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个过期的证书网站，查看获取到的证书信息
              this.webviewCtl.loadUrl('https://expired.badssl.com')
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('load example')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个https网站，查看网站的证书信息
              this.webviewCtl.loadUrl('https://www.example.com')
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('getCertificate Promise')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              try {
                this.webviewCtl.getCertificate().then((x509CertArray:Array<cert.X509Cert>) => {
                  this.outputStr = ParseX509CertInfo(x509CertArray);
                })
              } catch (error) {
                let e:business_error.BusinessError = error as business_error.BusinessError;
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;
              }
            })
            .height(50)
          }

          ListItem() {
            Button() {
              Text('getCertificate AsyncCallback')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              try {
                this.webviewCtl.getCertificate((error:business_error.BusinessError, x509CertArray:Array<cert.X509Cert>) => {
                  if (error) {
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;
                  } else {
                    this.outputStr = ParseX509CertInfo(x509CertArray);
                  }
                })
              } catch (error) {
                let e:business_error.BusinessError = error as business_error.BusinessError;
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;
              }
            })
            .height(50)
          }
        }
        .listDirection(Axis.Horizontal)
        .height('10%')

        Text(this.outputStr)
          .width('100%')
          .fontSize(10)

        Web({ src: 'https://www.example.com', controller: this.webviewCtl })
          .fileAccess(true)
          .javaScriptAccess(true)
          .domStorageAccess(true)
          .onlineImageAccess(true)
          .onPageEnd((e) => {
            if (e) {
              this.outputStr = 'onPageEnd : url = ' + e.url
            }
          })
          .onSslErrorEventReceive((e) => {
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com
            e.handler.handleConfirm()
          })
          .width('100%')
          .height('70%')
      }
      .height('100%')
    }
  }
}
```

### setAudioMuted<sup>10+</sup>

setAudioMuted(mute: boolean): void

设置网页静音。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明                      |
| -------- | ------- | ---- | -------------------------------------- |
| mute | boolean | 是   | 表示是否将网页设置为静音状态，true表示设置为静音状态，false表示取消静音状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController()
  @State muted: boolean = false
  build() {
    Column() {
      Button("Toggle Mute")
        .onClick(event => {
          this.muted = !this.muted
          this.controller.setAudioMuted(this.muted)
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### prefetchPage<sup>10+</sup>

prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void

在预测到将要加载的页面之前调用，提前下载页面所需的资源，包括主资源子资源，但不会执行网页JavaScript代码或呈现网页，以加快加载速度。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型                             | 必填  | 说明                      |                            
| ------------------| --------------------------------| ---- | ------------- |
| url               | string                          | 是    | 预加载的url。|
| additionalHeaders | Array\<[WebHeader](#webheader)> | 否    | url的附加HTTP请求头。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('prefetchPopularPage')
        .onClick(() => {
          try {
            // 预加载时，需要将'https://www.example.com'替换成一个真实的网站地址。
            this.controller.prefetchPage('https://www.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      // 需要将'www.example1.com'替换成一个真实的网站地址。
      Web({ src: 'www.example1.com', controller: this.controller })
    }
  }
}
```

### prepareForPageLoad<sup>10+</sup>

static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void

预连接url，在加载url之前调用此API，对url只进行dns解析，socket建链操作，并不获取主资源子资源。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| url            | string  | 是   | 预连接的url。|
| preconnectable | boolean | 是   | 是否进行预连接。如果preconnectable为true，则对url进行dns解析，socket建链预连接；如果preconnectable为false，则不做任何预连接操作。|
| numSockets     | number  | 是   | 要预连接的socket数。socket数目连接需要大于0，最多允许6个连接。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100002 | Invalid url.                                                 |
| 171000013| The number of preconnect sockets is invalid.                                                 |

**示例：**

```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate")
        web_webview.WebviewController.initializeWebEngine()
        // 预连接时，需要將'https://www.example.com'替换成一个真实的网站地址。
        web_webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
        AppStorage.setOrCreate("abilityWant", want)
        console.log("EntryAbility onCreate done")
    }
}
```

### setCustomUserAgent<sup>10+</sup>

setCustomUserAgent(userAgent: string): void

设置自定义用户代理。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | 是   | 用户自定义代理信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State userAgent: string = 'test'

  build() {
    Column() {
      Button('setCustomUserAgent')
        .onClick(() => {
          try {
            this.controller.setCustomUserAgent(this.userAgent);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setDownloadDelegate<sup>11+</sup>

setDownloadDelegate(delegate: WebDownloadDelegate): void

为当前的Web组件设置一个WebDownloadDelegate，该delegate用来接收页面内触发的下载与下载的进展。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](#webdownloaddelegate11)  | 是   | 用来接收下载进回调的委托。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### startDownload<sup>11+</sup>

startDownload(url: string): void

使用Web组件的下载能力来下载指定的url, 比如下载网页中指定的图片。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| url      | string  | 是   | 下载地址。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getCustomUserAgent<sup>10+</sup>

getCustomUserAgent(): string

获取自定义用户代理。

**系统能力：**  SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 用户自定义代理信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State userAgent: string = ''

  build() {
    Column() {
      Button('getCustomUserAgent')
        .onClick(() => {
          try {
            this.userAgent = this.controller.getCustomUserAgent();
            console.log("userAgent: " + this.userAgent);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setConnectionTimeout<sup>11+</sup>

static setConnectionTimeout(timeout: number): void

设置网络连接超时时间，使用者可通过Web组件中的onErrorReceive方法获取超时错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| timeout        | number  | 是   | socket连接超时时间，以秒为单位。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('setConnectionTimeout')
        .onClick(() => {
          try {
            web_webview.WebviewController.setConnectionTimeout(5);
            console.log("setConnectionTimeout: 5s");
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onErrorReceive((event) => {
          if (event) {
            console.log('getErrorInfo:' + event.error.getErrorInfo())
            console.log('getErrorCode:' + event.error.getErrorCode())
          }
        })
    }
  }
}
```

### postUrl<sup>11+</sup>

static postUrl(url: string, postData: ArrayBuffer): void

使用"POST"方法加载带有postData的url。如果url不是网络url，则会使用[loadUrl](#loadurl)方法加载url，忽略postData参数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                  |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string \| Resource | 是   | 需要加载的 URL。      |
| postData | ArrayBuffer | 否   | 使用"POST"方法传递数据。 该请求必须采用"application/x-www-form-urlencoded"编码。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

class testObj {
  constructor() {
  }

  test(str: string): ArrayBuffer {
    let buf = new ArrayBuffer(str.length);
    let buff = new Uint8Array(buf);

    for (let i = 0; i < str.length; i++) {
      buff[i] = str.charCodeAt(i);
    }
    return buf;
  }
}

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State testObjtest: testObj = new testObj();

  build() {
    Column() {
      Button('postUrl')
        .onClick(() => {
          try {
            // 数据转化为ArrayBuffer类型。
            let postData = this.testObjtest.test("Name=test&Password=test");
            this.controller.postUrl('www.example.com', postData);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: '', controller: this.controller })
    }
  }
}
```

### getSecurityLevel<sup>11+</sup>

getSecurityLevel(): SecurityLevel

获取当前网页的安全级别。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                | 说明                        |
| ----------------------------------- | --------------------------- |
| [SecurityLevel](#securitylevel) | 当前网页的安全级别，具体值为NONE、SECURE、WARNING、DANGEROUS。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import webview from '@ohos.web.webview'
	
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController()
  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onPageEnd((event) => {
          if (event) {
            let securityLevel = this.controller.getSecurityLevel()
            console.info('securityLevel: ', securityLevel)
          }
        })
    }
  }
}
```

## WebCookieManager

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookieManager实例。

> **说明：**
>
> 目前调用WebCookieManager下的方法，都需要先加载Web组件。

### getCookie<sup>(deprecated)</sup>

static getCookie(url: string): string

获取指定url对应cookie的值。

> **说明：**
>
> 从API version9开始支持，从API version 11开始废弃。建议使用[fetchCookieSync](###fetchCookieSync11)替代

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getCookie')
        .onClick(() => {
          try {
            let value = web_webview.WebCookieManager.getCookie('https://www.example.com');
            console.log("value: " + value);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### fetchCookieSync<sup>11+</sup>

static fetchCookieSync(url: string): string

获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookieSync')
        .onClick(() => {
          try {
            let value = web_webview.WebCookieManager.fetchCookieSync('https://www.example.com');
            console.log("fetchCookieSync cookie = " + value);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### fetchCookie<sup>11+</sup>

static fetchCookie(url: string, callback: AsyncCallback\<string>): void

异步callback方式获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| callback | AsyncCallback\<string> | 是 | callback回调，用于获取cookie |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401 | Invalid input parameter.                                           |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.fetchCookie('https://www.example.com', (error, cookie) => {
              if (error) {
                console.log('error: ' + JSON.stringify(error));
                return;
              }
              if (cookie) {
                console.log('fetchCookie cookie = ' + cookie);
              }
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### fetchCookie<sup>11+</sup>

static fetchCookie(url: string): Promise\<string>

以Promise方式异步获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<string> | Promise实例，用于获取指定url对应的cookie值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401 | Invalid input parameter.                                           |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.fetchCookie('https://www.example.com')
              .then(cookie => {
                console.log("fetchCookie cookie = " + cookie);
              })
              .catch((error:business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```


### setCookie<sup>(deprecated)</sup>

static setCookie(url: string, value: string): void

为指定url设置单个cookie的值。

> **说明：**
>
> 从API version9开始支持，从API version 11开始废弃。建议使用[configCookieSync](###configCookieSync11+)替代

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('setCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.setCookie('https://www.example.com', 'a=b');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookieSync<sup>11+</sup>

static configCookieSync(url: string, value: string): void

为指定url设置单个cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('configCookieSync')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookie<sup>11+</sup>

static configCookie(url: string, value: string, callback: AsyncCallback\<void>): void

异步callback方式为指定url设置单个cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| callback | AsyncCallback\<void> | 是 | callback回调，用于获取设置cookie的结果 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Invalid input parameter.                               |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('configCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.configCookie('https://www.example.com', "a=b", (error) => {
              if (error) {
                console.log("error: " + JSON.stringify(error));
              }
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookie<sup>11+</sup>

static configCookie(url: string, value: string): Promise\<void>

以异步Promise方式为指定url设置单个cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<void> | Promise实例，用于获取指定url设置单个cookie值是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Invalid input parameter.                               |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('configCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.configCookie('https://www.example.com', 'a=b')
              .then(() => {
                console.log('configCookie success!');
              })
              .catch((error:business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### saveCookieAsync

static saveCookieAsync(callback: AsyncCallback\<void>): void

将当前存在内存中的cookie异步保存到磁盘中。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取cookie是否成功保存。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.saveCookieAsync((error) => {
              if (error) {
                console.log("error: " + error);
              }
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### saveCookieAsync

static saveCookieAsync(): Promise\<void>

将当前存在内存中的cookie以Promise方法异步保存到磁盘中。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取cookie是否成功保存。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.saveCookieAsync()
              .then(() => {
                console.log("saveCookieAsyncCallback success!");
              })
              .catch((error:business_error.BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### putAcceptCookieEnabled

static putAcceptCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                 |
| ------ | ------- | ---- | :----------------------------------- |
| accept | boolean | 是   | 设置是否拥有发送和接收cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptCookieEnabled')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.putAcceptCookieEnabled(false);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isCookieAllowed

static isCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                             |
| ------- | -------------------------------- |
| boolean | 是否拥有发送和接收cookie的权限，默认为true。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('isCookieAllowed')
        .onClick(() => {
          let result = web_webview.WebCookieManager.isCookieAllowed();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### putAcceptThirdPartyCookieEnabled

static putAcceptThirdPartyCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| accept | boolean | 是   | 设置是否拥有发送和接收第三方cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptThirdPartyCookieEnabled')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isThirdPartyCookieAllowed

static isThirdPartyCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 是否拥有发送和接收第三方cookie的权限，默认为false。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('isThirdPartyCookieAllowed')
        .onClick(() => {
          let result = web_webview.WebCookieManager.isThirdPartyCookieAllowed();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### existCookie

static existCookie(): boolean

获取是否存在cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 是否拥有发送和接收第三方cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('existCookie')
        .onClick(() => {
          let result = web_webview.WebCookieManager.existCookie();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteEntireCookie<sup>(deprecated)</sup>

static deleteEntireCookie(): void

清除所有cookie。

> **说明：**
>
> 从API version9开始支持，从API version 11开始废弃。建议使用[clearAllCookiesSync](###clearAllCookiesSync11+)替代

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteEntireCookie')
        .onClick(() => {
          web_webview.WebCookieManager.deleteEntireCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearAllCookiesSync<sup>11+</sup>

static clearAllCookiesSync(): void

清除所有cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearAllCookiesSync')
        .onClick(() => {
          web_webview.WebCookieManager.clearAllCookiesSync();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearAllCookies<sup>11+</sup>

static clearAllCookies(callback: AsyncCallback\<void>): void

异步callback方式清除所有cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取清除所有cookie是否成功。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearAllCookies')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.clearAllCookies((error) => {
              if (error) {
                console.log("error: " + error);
              }
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearAllCookies<sup>11+</sup>

static clearAllCookies(): Promise\<void>

异步promise方式清除所有cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取清除所有cookie是否成功。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearAllCookies')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.clearAllCookies()
              .then(() => {
                console.log("clearAllCookies success!");
              })
              .catch((error:business_error.BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteSessionCookie<sup>(deprecated)</sup>

static deleteSessionCookie(): void

清除所有会话cookie。

> **说明：**
>
> 从API version9开始支持，从API version 11开始废弃。建议使用[clearSessionCookiesync](###clearSessionCookieSync11+)替代

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteSessionCookie')
        .onClick(() => {
          web_webview.WebCookieManager.deleteSessionCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearSessionCookieSync<sup>11+</sup>

static clearSessionCookieSync(): void

清除所有会话cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookieSync')
        .onClick(() => {
          web_webview.WebCookieManager.clearSessionCookieSync();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearSessionCookie<sup>11+</sup>

static clearSessionCookie(callback: AsyncCallback\<void>): void

异步callback方式清除所有会话cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取清除所有会话cookie是否成功。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.clearSessionCookie((error) => {
              if (error) {
                console.log("error: " + error);
              }
            })
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearSessionCookie<sup>11+</sup>

static clearSessionCookie(): Promise\<void>

异步promise方式清除所有会话cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取清除所有会话cookie是否成功。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.clearSessionCookie()
              .then(() => {
                console.log("clearSessionCookie success!");
              })
              .catch((error:business_error.BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebStorage

通过WebStorage可管理Web SQL数据库接口和HTML5 Web存储接口，每个应用中的所有Web组件共享一个WebStorage。

> **说明：**
>
> 目前调用WebStorage下的方法，都需要先加载Web组件。

### deleteOrigin

static deleteOrigin(origin : string): void

清除指定源所使用的存储。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| origin | string | 是   | 指定源的字符串索引，来自于[getOrigins](#getorigins)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('deleteOrigin')
        .onClick(() => {
          try {
            web_webview.WebStorage.deleteOrigin(this.origin);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件。
 ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <title>test</title>
    <script type="text/javascript">

      var db = openDatabase('mydb','1.0','Test DB',2 * 1024 * 1024);
      var msg;

      db.transaction(function(tx){
        tx.executeSql('INSERT INTO LOGS (id,log) VALUES(1,"test1")');
        tx.executeSql('INSERT INTO LOGS (id,log) VALUES(2,"test2")');
        msg = '<p>数据表已创建,且插入了两条数据。</p>';

        document.querySelector('#status').innerHTML = msg;
      });

      db.transaction(function(tx){
        tx.executeSql('SELECT * FROM LOGS', [], function (tx, results) {
          var len = results.rows.length,i;
          msg = "<p>查询记录条数：" + len + "</p>";

          document.querySelector('#status').innerHTML += msg;

              for(i = 0; i < len; i++){
                msg = "<p><b>" + results.rows.item(i).log + "</b></p>";

          document.querySelector('#status').innerHTML += msg;
          }
        },null);
      });

      </script>
  </head>
  <body>
  <div id="status" name="status">状态信息</div>
  </body>
  </html>
  ```

### getOrigins

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void

以回调方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                   |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](#webstorageorigin)>> | 是   | 以数组方式返回源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOrigins((error, origins) => {
              if (error) {
                console.log('error: ' + JSON.stringify(error));
                return;
              }
              for (let i = 0; i < origins.length; i++) {
                console.log('origin: ' + origins[i].origin);
                console.log('usage: ' + origins[i].usage);
                console.log('quota: ' + origins[i].quota);
              }
            })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### getOrigins

static getOrigins() : Promise\<Array\<WebStorageOrigin>>

以Promise方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Promise实例，用于获取当前所有源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOrigins()
              .then(origins => {
                for (let i = 0; i < origins.length; i++) {
                  console.log('origin: ' + origins[i].origin);
                  console.log('usage: ' + origins[i].usage);
                  console.log('quota: ' + origins[i].quota);
                }
              })
              .catch((e : business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### getOriginQuota

static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void

使用callback回调异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储配额   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {
              if (error) {
                console.log('error: ' + JSON.stringify(error));
                return;
              }
              console.log('quota: ' + quota);
            })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### getOriginQuota

static getOriginQuota(origin : string) : Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                    |
| --------------- | --------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储配额。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota);
              })
              .catch((e : business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### getOriginUsage

static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void

以回调方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储量。   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {
              if (error) {
                console.log('error: ' + JSON.stringify(error));
                return;
              }
              console.log('usage: ' + usage);
            })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### getOriginUsage

static getOriginUsage(origin : string) : Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                  |
| --------------- | ------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储量。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid origin.                            |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage);
              })
              .catch((e : business_error.BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

### deleteAllData

static deleteAllData(): void

清除Web SQL数据库当前使用的所有存储。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllData')
        .onClick(() => {
          try {
            web_webview.WebStorage.deleteAllData();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下加载的html文件。

## WebDataBase

web组件数据库管理对象。

> **说明：**
>
> 目前调用WebDataBase下的方法，都需要先加载Web组件。

### getHttpAuthCredentials

static getHttpAuthCredentials(host: string, realm: string): Array\<string>

检索给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| host   | string | 是   | HTTP身份验证凭据应用的主机。 |
| realm  | string | 是   | HTTP身份验证凭据应用的域。   |

**返回值：**

| 类型  | 说明                                         |
| ----- | -------------------------------------------- |
| Array\<string> | 包含用户名和密码的组数，检索失败返回空数组。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";
  username_password: string[] = [];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.username_password = web_webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.log('num: ' + this.username_password.length);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### saveHttpAuthCredentials

static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void

保存给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| host     | string | 是   | HTTP身份验证凭据应用的主机。 |
| realm    | string | 是   | HTTP身份验证凭据应用的域。   |
| username | string | 是   | 用户名。                     |
| password | string | 是   | 密码。                       |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";

  build() {
    Column() {
      Button('saveHttpAuthCredentials')
        .onClick(() => {
          try {
            web_webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche");
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### existHttpAuthCredentials

static existHttpAuthCredentials(): boolean

判断是否存在任何已保存的HTTP身份验证凭据，该方法为同步方法。存在返回true，不存在返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 是否存在任何已保存的HTTP身份验证凭据。存在返回true，不存在返回false |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('existHttpAuthCredentials')
        .onClick(() => {
          try {
            let result = web_webview.WebDataBase.existHttpAuthCredentials();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteHttpAuthCredentials

static deleteHttpAuthCredentials(): void

清除所有已保存的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteHttpAuthCredentials')
        .onClick(() => {
          try {
            web_webview.WebDataBase.deleteHttpAuthCredentials();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## GeolocationPermissions

web组件地理位置权限管理对象。

> **说明：**
>
> 目前调用GeolocationPermissions下的方法，都需要先加载Web组件。

### 需要权限

访问地理位置时需添加权限：ohos.permission.LOCATION、ohos.permission.APPROXIMATELY_LOCATION、ohos.permission.LOCATION_IN_BACKGROUND，具体权限说明请参考[位置服务](./js-apis-geolocation.md)。

### allowGeolocation

static allowGeolocation(origin: string): void

允许指定来源使用地理位置接口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   |指定源的字符串索引 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('allowGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.allowGeolocation(this.origin);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteGeolocation

static deleteGeolocation(origin: string): void

清除指定来源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('deleteGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.deleteGeolocation(this.origin);
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void

以回调方式异步获取指定源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| origin   | string                 | 是   | 指定源的字符串索引                                           |
| callback | AsyncCallback\<boolean> | 是   | 返回指定源的地理位置权限状态。获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
              if (error) {
                console.log('getAccessibleGeolocationAsync error: ' + JSON.stringify(error));
                return;
              }
              console.log('getAccessibleGeolocationAsync result: ' + result);
            });
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string): Promise\<boolean>

以Promise方式异步获取指定源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | -------- | ---- | -------------------- |
| origin | string   | 是   | 指定源的字符串索引。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise实例，用于获取指定源的权限状态，获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin)
              .then(result => {
                console.log('getAccessibleGeolocationPromise result: ' + result);
              }).catch((error : business_error.BusinessError) => {
              console.log('getAccessibleGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void

以回调方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<Array\<string>> | 是   | 返回已存储地理位置权限状态的所有源信息。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getStoredGeolocation((error, origins) => {
              if (error) {
                console.log('getStoredGeolocationAsync error: ' + JSON.stringify(error));
                return;
              }
              let origins_str: string = origins.join();
              console.log('getStoredGeolocationAsync origins: ' + origins_str);
            });
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(): Promise\<Array\<string>>

以Promise方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                   | 说明                                                      |
| ---------------------- | --------------------------------------------------------- |
| Promise\<Array\<string>> | Promise实例，用于获取已存储地理位置权限状态的所有源信息。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getStoredGeolocation()
              .then(origins => {
                let origins_str: string = origins.join();
                console.log('getStoredGeolocationPromise origins: ' + origins_str);
              }).catch((error : business_error.BusinessError) => {
              console.log('getStoredGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteAllGeolocation

static deleteAllGeolocation(): void

清除所有来源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.deleteAllGeolocation();
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## WebHeader
Web组件返回的请求/响应头对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 可读 | 可写 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| headerKey   | string | 是 | 是 | 请求/响应头的key。   |
| headerValue | string | 是 | 是 | 请求/响应头的value。 |

## WebHitTestType

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| EditText      | 0 |可编辑的区域。                            |
| Email         | 1 |电子邮件地址。                            |
| HttpAnchor    | 2 |超链接，其src为http。                     |
| HttpAnchorImg | 3 |带有超链接的图片，其中超链接的src为http。 |
| Img           | 4 |HTML::img标签。                           |
| Map           | 5 |地理地址。                                |
| Phone         | 6 |电话号码。                                |
| Unknown       | 7 |未知内容。                                |

## SecurityLevel<sup>11+</sup>

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| NONE          | 0 |页面既不绝对安全，也不是不安全，即是中立。例如，部分scheme非http/https的URL。|
| SECURE        | 1 |页面安全，页面使用的是HTTPS协议，且使用了信任的证书。|
| WARNING       | 2 |页面不安全。例如，使用HTTP协议或使用HTTPS协议但使用旧版TLS版本。|
| DANGEROUS     | 3 |页面不安全。尝试HTTPS并失败、页面未通过身份验证、页面上包含不安全活动内容的HTTPS、恶意软件、网络钓鱼或任何其他可能危险的严重安全问题。 |

##  HitTestValue

提供点击区域的元素信息。示例代码参考getHitTestValue。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 可读 | 可写 | 说明|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](#webhittesttype) | 是 | 否 | 当前被点击区域的元素类型。|
| extra | string        | 是 | 否 |点击区域的附加参数信息。若被点击区域为图片或链接，则附加参数信息为其url地址。 |

## WebMessage

用于描述[WebMessagePort](#webmessageport)所支持的数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型       | 说明                                     |
| -------- | -------------------------------------- |
| string   | 字符串类型数据。 |
| ArrayBuffer   | 二进制类型数据。 |

## JsMessageType<sup>10+</sup>

[runJavaScirptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 值 | 说明                              |
| ------------ | -- |--------------------------------- |
| NOT_SUPPORT  | 0 |不支持的数据类型。|
| STRING       | 1 |字符串类型。|
| NUMBER       | 2 |数值类型。|
| BOOLEAN      | 3 |布尔类型。|
| ARRAY_BUFFER | 4 |原始二进制数据缓冲区。|
| ARRAY        | 5 |数组类型|

## WebMessageType<sup>10+</sup>

[webMessagePort](#webmessageport)接口所支持的数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 值 | 说明                            |
| ------------ | -- |------------------------------- |
| NOT_SUPPORT  | 0 |不支持的数据类型。|
| STRING       | 1 |字符串类型。|
| NUMBER       | 2 |数值类型。|
| BOOLEAN      | 3 |布尔类型。|
| ARRAY_BUFFER | 4 |原始二进制数据缓冲区。|
| ARRAY        | 5 |数组类型。|
| ERROR        | 6 |错误类型。|

## JsMessageExt<sup>10+</sup>

[runJavaScirptExt](#runjavascriptext10)接口执行脚本返回的数据对象。

### getType<sup>10+</sup>

getType(): JsMessageType

获取数据对象的类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明                                                      |
| --------------| --------------------------------------------------------- |
| [JsMessageType](#jsmessagetype10) | [runJavaScirptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。 |

### getString<sup>10+</sup>

getString(): string

获取数据对象的字符串类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| string | 返回字符串类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the result. |

### getNumber<sup>10+</sup>

getNumber(): number

获取数据对象的数值类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| number | 返回数值类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the result. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

获取数据对象的布尔类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| boolean | 返回布尔类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the result. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

获取数据对象的原始二进制数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| ArrayBuffer | 返回原始二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the result. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

获取数据对象的数组类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | 返回数组类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the result. |

## WebMessageExt<sup>10+</sup>

[webMessagePort](#webmessageport)接口接收、发送的的数据对象。

### getType<sup>10+</sup>

getType(): WebMessageType

获取数据对象的类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明                                                      |
| --------------| --------------------------------------------------------- |
| [WebMessageType](#webmessagetype10) | [webMessagePort](#webmessageport)接口所支持的数据类型。 |

### getString<sup>10+</sup>

getString(): string

获取数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| string | 返回字符串类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### getNumber<sup>10+</sup>

getNumber(): number

获取数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| number | 返回数值类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

获取数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| boolean | 返回布尔类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

获取数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。
**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| ArrayBuffer | 返回原始二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

获取数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | 返回数组类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### getError<sup>10+</sup>

getError(): Error

获取数据对象的错误类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Error | 返回错误对象类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setType<sup>10+</sup>

setType(type: WebMessageType): void

设置数据对象的类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| type  | [WebMessageType](#webmessagetype10) | 是   | [webMessagePort](#webmessageport)接口所支持的数据类型。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setString<sup>10+</sup>

setString(message: string): void

设置数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | string | 是   | 字符串类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setNumber<sup>10+</sup>

setNumber(message: number): void

设置数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | number | 是   | 数值类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setBoolean<sup>10+</sup>

setBoolean(message: boolean): void

设置数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | boolean | 是   | 布尔类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setArrayBuffer<sup>10+</sup>

setArrayBuffer(message: ArrayBuffer): void

设置数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | ArrayBuffer | 是   | 原始二进制类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setArray<sup>10+</sup>

setArray(message: Array\<string | number | boolean\>): void

设置数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Array\<string \| number \| boolean\> | 是   | 数组类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

### setError<sup>10+</sup>

setError(message: Error): void

设置数据对象的错误对象类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Error | 是   | 错误对象类型数据。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type does not match with the value of the web message. |

## WebStorageOrigin

提供Web SQL数据库的使用信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 类型   | 可读 | 可写 | 说明 |
| ------ | ------ | ---- | ---- | ---- |
| origin | string | 是  | 否 | 指定源的字符串索引。 |
| usage  | number | 是  | 否 | 指定源的存储量。     |
| quota  | number | 是  | 否 | 指定源的存储配额。   |

## BackForwardList

当前Webview的历史信息列表。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 类型   | 可读 | 可写 | 说明                                                         |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | 是   | 否   | 当前在页面历史列表中的索引。                                 |
| size         | number | 是   | 否   | 历史列表中索引的数量，最多保存50条，超过时起始记录会被覆盖。 |

### getItemAtIndex

getItemAtIndex(index: number): HistoryItem

获取历史列表中指定索引的历史记录项信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| index  | number | 是   | 指定历史列表中的索引。 |

**返回值：**

| 类型                        | 说明         |
| --------------------------- | ------------ |
| [HistoryItem](#historyitem) | 历史记录项。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import image from "@ohos.multimedia.image";
import business_error from '@ohos.base';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State icon: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Button('getBackForwardEntries')
        .onClick(() => {
          try {
            let list = this.controller.getBackForwardEntries();
            let historyItem = list.getItemAtIndex(list.currentIndex);
            console.log("HistoryItem: " + JSON.stringify(historyItem));
            this.icon = historyItem.icon;
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## HistoryItem

页面历史记录项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型                                   | 可读 | 可写 | 说明                         |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [PixelMap](js-apis-image.md#pixelmap7) | 是   | 否   | 历史页面图标的PixelMap对象。 |
| historyUrl    | string                                 | 是   | 否   | 历史记录项的url地址。        |
| historyRawUrl | string                                 | 是   | 否   | 历史记录项的原始url地址。    |
| title         | string                                 | 是   | 否   | 历史记录项的标题。           |

## WebCustomScheme

自定义协议配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 可读 | 可写 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | 是   | 是   | 自定义协议名称。最大长度为32，其字符仅支持小写字母、数字、'.'、'+'、'-'。        |
| isSupportCORS  | boolean   | 是   | 是   | 是否支持跨域请求。    |
| isSupportFetch | boolean   | 是   | 是   | 是否支持fetch请求。           |

## SecureDnsMode<sup>10+</sup>

Web组件使用HTTPDNS的模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| OFF                                  | 0 |不使用HTTPDNS， 可以用于撤销之前使用的HTTPDNS配置。|
| AUTO                                 | 1 |自动模式，用于解析的设定dns服务器不可用时，可自动回落至系统DNS。|
| SECURE_ONLY                          | 2 |强制使用设定的HTTPDNS服务器进行域名解析。|

## WebDownloadState<sup>11+</sup>

下载任务的状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| IN_PROGRESS                                  | 0 |下载任务正在进行中。|
| COMPLETED                                 | 1 |下载任务已经完成。|
| CANCELED                          | 2 |下载任务已经被取消。|
| INTERRUPTED                          | 3 |下载任务被中断。|
| PENDING                          | 4 |下载任务等待开始。|
| PAUSED                          | 5 |下载任务已经被暂停。|
| UNKNOWN                          | 6 |下载任务未知状态。|

## WebDownloadErrorCode<sup>11+</sup>

下载任务的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| ERROR_UNKNOWN                                  | 0 |未知的错误。|
| FILE_FAILED | 1 |  常规文件操作失败。|
| FILE_ACCESS_DENIED | 2 | 没有权限访问文件。|
| FILE_NO_SPACE | 3 | 磁盘没有足够的空间。|
| FILE_NAME_TOO_LONG | 5 | 文件名字过长。|
| FILE_TOO_LARGE | 6 | 文件太大。|
| FILE_TRANSIENT_ERROR | 10 |  出现了一些临时问题，例如内存不足、文件正在使用以及同时打开的文件过多。|
| FILE_BLOCKED | 11 |  由于某些本地策略，文件被阻止访问。|
| FILE_TOO_SHORT | 13 |  当尝试恢复下载时，发现文件不够长，可能该文件已不存在。|
| FILE_HASH_MISMATCH | 14 |  哈希不匹配。|
| FILE_SAME_AS_SOURCE | 15 |  文件已存在。|
| NETWORK_FAILED | 20 |  一般网络错误。|
| NETWORK_TIMEOUT | 21 | 网络超时。|
| NETWORK_DISCONNECTED | 22 | 网络断开连接。|
| NETWORK_SERVER_DOWN | 23 |  服务器关闭。|
| NETWORK_INVALID_REQUEST | 24 |  无效的网络请求，可能重定向到不支持的方案或无效的URL。|
| SERVER_FAILED | 30 | 服务器返回了一个一般性错误。|
| SERVER_NO_RANGE | 31 |  服务器不支持范围请求。|
| SERVER_BAD_CONTENT | 33 |   服务器没有请求的数据。|
| SERVER_UNAUTHORIZED | 34 |  服务器不允许下载该文件。|
| SERVER_CERT_PROBLEM | 35 |  服务器证书错误。|
| SERVER_FORBIDDEN | 36 |  服务器访问被禁止。|
| SERVER_UNREACHABLE | 37 |  无法访问服务器。|
| SERVER_CONTENT_LENGTH_MISMATCH | 38 |  接收到的数据与内容长度不匹配。|
| SERVER_CROSS_ORIGIN_REDIRECT | 39 | 发生意外的跨站重定向。|
| USER_CANCELED | 40 | 用户取消了下载。|
| USER_SHUTDOWN | 41 | 用户关闭了应用。|
| CRASH | 50 | 应用发生了崩溃。|

## WebDownloadItem<sup>11+</sup>

 表示下载任务，您可以使用此对象来操作相应的下载任务。

> **说明：**
>
> 在下载过程中，下载的进程会通过WebDownloadDelegate通知给使用者，使用者可以通过参数WebDownloadItem来操作下载任务。

### getGuid<sup>11+</sup>

getGuid(): string

获取下载任务的唯一ID。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载任务的唯一ID。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getCurrentSpeed<sup>11+</sup>

getCurrentSpeed(): number

获取下载的速度，单位：字节每秒。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 下载的速度（字节每秒）。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update current speed: " + webDownloadItem.getCurrentSpeed());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getPercentComplete<sup>11+</sup>

getPercentComplete(): number

获取下载的进度，100代表下载完成。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 下载完成的进度，100代表下载完成。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getTotalBytes<sup>11+</sup>

getTotalBytes(): number

获取待下载文件的总长度。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 待下载文件的总长度。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update total bytes: " + webDownloadItem.getTotalBytes());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getState<sup>11+</sup>

getState(): WebDownloadState

获取下载的状态。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| [WebDownloadState](#webdownloadstate11) | 下载的状态。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update download state: " + webDownloadItem.getState());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getLastErrorCode<sup>11+</sup>

getLastErrorCode(): number

获取下载的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 下载发生错误的时候的错误码。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              console.log("download error code: " + webDownloadItem.getLastErrorCode());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getMethod<sup>11+</sup>

getMethod(): string

获取下载任务的请求方式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载的请求方式。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download， method:" + webDownloadItem.getMethod());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getMimeType<sup>11+</sup>

getMimeType(): string

获取下载的媒体类型（例如，一个声音文件可能被标记为 audio/ogg ，一个图像文件可能是 image/png）。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载的媒体类型（例如，一个声音文件可能被标记为 audio/ogg ，一个图像文件可能是 image/png）。|

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download， mime type:" + webDownloadItem.getMimeType());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUrl<sup>11+</sup>

getUrl(): string

获取下载的请求地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载的请求地址。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download, url:" + webDownloadItem.getUrl());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getSuggestedFileName<sup>11+</sup>

getSuggestedFileName(): string

获取下载的建议文件名。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载的建议文件名。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download, suggest name:" + webDownloadItem.getSuggestedFileName());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getReceivedBytes<sup>11+</sup>

getReceivedBytes(): number

获取已经接收的字节数。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 已经接收的字节数。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              console.log("download update received bytes: " + webDownloadItem.getReceivedBytes());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getFullPath<sup>11+</sup>

getFullPath(): string

获取下载文件在磁盘上的全路径。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载文件在磁盘上的全路径。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
              console.log("download finish full path: " + webDownloadItem.getFullPath());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### serialize<sup>11+</sup>

serialize(): Uint8Array

将失败的下载序列化到一个字节数组。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Uint8Array | 失败的下载序列化后的字节数组。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deserialize<sup>11+</sup>

static deserialize(serializedData: Uint8Array): WebDownloadItem

将序列化后的字节数组反序列化为一个WebDownloadItem对象。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Uint8Array | 序列化后的下载。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| [WebDownloadItem](#webdownloaditem11) | 从字节数组反序列化为一个WebDownloadItem对象。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### start<sup>11+</sup>

start(downloadPath: string): void

开始一个下载，参数为下载文件的磁盘存储路径(包含文件名)。该接口需要在WebDownloadDelegate的onBeforeDownload回调中使用，如果在WebDownloadDelegate的onBeforeDownload中不调用start('xxx')该下载任务会一直处于PENDING状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 下载文件的路径(包含文件名)。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### cancel<sup>11+</sup>

cancel(): void

取消一个正在下载的下载任务。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pause<sup>11+</sup>

pause(): void

暂停一个正在下载的下载任务。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100019 | The download has not been started yet. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
        Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### resume<sup>11+</sup>

resume(): void

恢复一个暂停的下载任务。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md).

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100016 | The download is not paused. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebDownloadDelegate<sup>11+</sup>

 下载任务的状态会通过该类的回调接口通知给用户。

### onBeforeDownload<sup>11+</sup>

onBeforeDownload(): void

下载开始前通知给用户，用户需要在此接口中调用WebDownloadItem.start("xxx")并提供下载路径，否则下载会一直处于PENDING状态。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadUpdated<sup>11+</sup>

onDownloadUpdated(): void

下载过程中的回调，通过该回调的参数可以了解下载进度等信息。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadFinish<sup>11+</sup>

onDownloadFinish(): void

下载完成的通知。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadFailed<sup>11+</sup>

onDownloadFailed(): void

下载失败的通知。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebDownloadManager<sup>11+</sup>

可以通过该类提供的接口来恢复失败的下载任务。

### setDownloadDelegate<sup>11+</sup>

static setDownloadDelegate(delegate: WebDownloadDelegate): void

设置用于接收从WebDownloadManager触发的下载进度的委托。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](#webdownloaddelegate11)  | 是   | 用来接收下载进回调的委托。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### resumeDownload<sup>11+</sup>

static resumeDownload(webDownloadItem: WebDownloadItem): void

设置用于接收从WebDownloadManager触发的下载进度的委托。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| webDownloadItem      | [WebDownloadItem](#webdownloaditem11)  | 是   | 待恢复的下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](../errorcodes/errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100018 | No WebDownloadDelegate has been set yet. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  delegate: web_webview.WebDownloadDelegate = new web_webview.WebDownloadDelegate();
  failedDownload: Uint8Array;
  download: WebDownloadItem;

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("xxxxxxxx");
            })
            this.delegate.onDownloadUpdated((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              failedDownload = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: web_webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('wwww.example.com');
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            web_webview.WebDownloadManager.resumeDownload(web_webview.WebDownloadItem.deserialize(this.failedDownload));
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            let e:business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```