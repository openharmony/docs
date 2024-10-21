# @ohos.web.webview (Webview)

@ohos.web.webview提供web控制能力，[Web](ts-basic-components-web.md)组件提供网页显示的能力。

> **说明：**
>
> - 本模块接口从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

webview.once("webInited", () => {
  console.log("configCookieSync");
  webview.WebCookieManager.configCookieSync("https://www.example.com", "a=b");
})

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

## WebMessagePort

通过WebMessagePort可以进行消息的发送以及接收。

### 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 类型   | 可读 | 可写 | 说明                                              |
| ------------ | ------ | ---- | ---- | ------------------------------------------------|
| isExtentionType<sup>10+</sup> | boolean | 是   | 是 | 创建WebMessagePort时是否指定使用扩展增强接口。   |

### postMessageEvent

postMessageEvent(message: WebMessage): void

发送消息，必须先调用[onMessageEvent](#onmessageevent)，否则会发送失败。完整示例代码参考[postMessage](#postmessage)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| message | [WebMessage](#webmessage) | 是   | 要发送的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100010 | Failed to post messages through the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  ports: webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('postMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            this.ports[1].postMessageEvent("post message from ets to html5");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| callback | (result: [WebMessage](#webmessage)) => void | 是   | 接收到的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                        |
| -------- | ----------------------------------------------- |
| 17100006 | Failed to register a message event for the port.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.|

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  ports: webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('onMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.ports[1].onMessageEvent((msg) => {
              if (typeof (msg) == "string") {
                console.log("received string message from html5, string is:" + msg);
              } else if (typeof (msg) == "object") {
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
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### postMessageEventExt<sup>10+</sup>

postMessageEventExt(message: WebMessageExt): void

发送消息，必须先调用[onMessageEventExt](#onmessageeventext10)，否则会发送失败。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| message | [WebMessageExt](#webmessageext10) | 是   | 要发送的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100010 | Failed to post messages through the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### onMessageEventExt<sup>10+</sup>

onMessageEventExt(callback: (result: WebMessageExt) => void): void

注册回调函数，接收HTML5侧发送过来的消息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | :------------------- |
| callback | (result: [WebMessageExt](#webmessageext10)) => void | 是   | 接收到的消息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                        |
| -------- | ----------------------------------------------- |
| 17100006 | Failed to register a message event for the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
  test(str: string): ArrayBuffer {
    let buf = new ArrayBuffer(str.length);
    let buff = new Uint8Array(buf);

    for (let i = 0; i < str.length; i++) {
      buff[i] = str.charCodeAt(i);
    }
    return buf;
  }
}

// 应用与网页互发消息的示例：使用"init_web_messageport"的通道，通过端口0在应用侧接受网页发送的消息，通过端口1在网页侧接受应用发送的消息。
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  ports: webview.WebMessagePort[] = [];
  nativePort: webview.WebMessagePort | null = null;
  @State msg1: string = "";
  @State msg2: string = "";
  message: webview.WebMessageExt = new webview.WebMessageExt();
  @State testObjtest: TestObj = new TestObj();

  build() {
    Column() {
      Text(this.msg1).fontSize(16)
      Text(this.msg2).fontSize(16)
      Button('SendToH5 setString').margin({
        right: 800,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setType(1);
              this.message.setString("helloFromEts");
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Button('SendToH5 setNumber').margin({
        top: 10,
        right: 800,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setType(2);
              this.message.setNumber(12345);
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('SendToH5 setBoolean').margin({
        top: -90,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setType(3);
              this.message.setBoolean(true);
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('SendToH5 setArrayBuffer').margin({
        top: 10,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setType(4);
              this.message.setArrayBuffer(this.testObjtest.test("Name=test&Password=test"));
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('SendToH5 setArray').margin({
        top: -90,
        left: 800,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            if (this.nativePort) {
              this.message.setType(5);
              this.message.setArray([1, 2, 3]);
              this.nativePort.postMessageEventExt(this.message);
            }
          }
          catch (error) {
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('SendToH5 setError').margin({
        top: 10,
        left: 800,
      })
        .onClick(() => {
          // 使用本侧端口发送消息给HTML5
          try {
            console.log("In ArkTS side send true start");
            throw new ReferenceError("ReferenceError");
          }
          catch (error) {
            if (this.nativePort) {
              this.message.setType(6);
              this.message.setError(error);
              this.nativePort.postMessageEventExt(this.message);
            }
            console.error(`In ArkTS side send message catch error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onPageEnd(() => {
          console.log("In ArkTS side message onPageEnd init message channel");
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
                case webview.WebMessageType.STRING: {
                  this.msg1 = "result type:" + typeof (result.getString());
                  this.msg2 = "result getString:" + ((result.getString()));
                  break;
                }
                case webview.WebMessageType.NUMBER: {
                  this.msg1 = "result type:" + typeof (result.getNumber());
                  this.msg2 = "result getNumber:" + ((result.getNumber()));
                  break;
                }
                case webview.WebMessageType.BOOLEAN: {
                  this.msg1 = "result type:" + typeof (result.getBoolean());
                  this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                  break;
                }
                case webview.WebMessageType.ARRAY_BUFFER: {
                  this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                  this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                  break;
                }
                case webview.WebMessageType.ARRAY: {
                  this.msg1 = "result type:" + typeof (result.getArray());
                  this.msg2 = "result getArray:" + result.getArray();
                  break;
                }
                case webview.WebMessageType.ERROR: {
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
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  msgPort: webview.WebMessagePort[] = [];

  build() {
    Column() {
      // 先使用createWebMessagePorts创建端口。
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.msgPort = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.msgPort.length)
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebviewController

通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。

### constructor<sup>11+</sup>

constructor(webTag?: string)

用于创建 WebviewController 对象的构造函数。

> **说明：**
>
> webTag是需要开发者自定义的一个标记，即开发者给web的一个字符串形式参数，用来做标记。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| webTag   | string | 否   | 指定了 Web 组件的名称，默认为 Empty。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class WebObj {
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
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController()
  @State webTestObj: WebObj = new WebObj();

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: '', controller: this.controller })
        .javaScriptAccess(true)
        .onControllerAttached(() => {
          this.controller.loadUrl($rawfile("index.html"));
          this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);
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
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <p id="webDemo"></p>
    </body>
    <script type="text/javascript">
    function htmlTest() {
      // This function call expects to return "Web test"
      let webStr = objTestName.webTest();
      document.getElementById("webDemo").innerHTML=webStr;
      console.log('objTestName.webTest result:'+ webStr)
    }
</script>
</html>
```

### initializeWebEngine

static initializeWebEngine(): void

在 Web 组件初始化之前，通过此接口加载 Web 引擎的动态库文件，以提高启动性能。自动预连接历史访问过的高频网站。

> **说明：**
>
> - initializeWebEngine不支持在异步线程中调用，否则会造成崩溃。
> - initializeWebEngine全局生效，在整个APP生命周期中调用一次即可，不需要重复调用。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

本示例以EntryAbility为例，描述了在 Ability 创建阶段完成 Web 组件动态库加载的功能。

```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate")
    webview.WebviewController.initializeWebEngine()
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |

**示例：**

```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate")
    try {
      webview.WebviewController.setHttpDns(webview.SecureDnsMode.AUTO, "https://example1.test")
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }

    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done")
  }
}
```

### setWebDebuggingAccess

static setWebDebuggingAccess(webDebuggingAccess: boolean): void

设置是否启用网页调试功能，默认不开启。详情请参考[Devtools工具](../../web/web-debugging-with-devtools.md)。

安全提示：启用网页调试功能可以让用户检查修改Web页面内部状态，存在安全隐患，不建议在应用正式发布版本中启用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| webDebuggingAccess | boolean | 是   | 设置是否启用网页调试功能。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear(): void {
    try {
      webview.WebviewController.setWebDebuggingAccess(true);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 17100003 | Invalid resource path or file type.                          |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 需要加载的URL是string类型。
            this.controller.loadUrl('www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 带参数headers。
            this.controller.loadUrl('www.example.com', [{ headerKey: "headerKey", headerValue: "headerValue" }]);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 通过$rawfile加载本地资源文件。
            this.controller.loadUrl($rawfile('index.html'));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.resources协议，适用Webview加载带有"#"路由的链接。
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 通过resource协议加载本地资源文件。
            this.controller.loadUrl("resource://rawfile/index.html");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

3.通过沙箱路径加载本地文件，可以参考[web](ts-basic-components-web.md#web)加载沙箱路径的示例代码。

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

baseUrl与historyUrl同时为空的情况下：

encoding如果为非base64（包括空值），则假定数据对安全URL字符范围内的八位字节使用ASCII编码，对该范围外的八位字节使用URL的标准%xx十六进制编码。

data数据必须使用base64编码或将内容中的任何#字符编码为%23。否则#将被视为内容的结尾而剩余的文本将被用作文档片段标识符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| data       | string | 是   | 按照"base64"或者"URL"编码后的一段字符串。                    |
| mimeType   | string | 是   | 媒体类型（MIME）。                                           |
| encoding   | string | 是   | 编码类型，具体为"base64"或者"URL"编码。                       |
| baseUrl    | string | 否   | 指定的一个URL路径（"http"/"https"/"data"协议），并由Web组件赋值给window.origin。 |
| historyUrl | string | 否   | 用作历史记录所使用的URL。非空时，历史记录以此URL进行管理。当baseUrl为空时，此属性无效。 |

> **说明：**
>
> 若加载本地图片，可以给baseUrl或historyUrl任一参数赋值空格，详情请参考示例代码。
> 加载本地图片场景，baseUrl和historyUrl不能同时为空，否则图片无法成功加载。
> 若html中的富文本中带有注入#等特殊字符，建议将baseUrl和historyUrl两个参数的值设置为"空格"。

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

baseUrl与historyUrl同时为空。
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(
              "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              "text/html",
              // UTF-8为charset。
              "UTF-8"
            );
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(
              // Coding tests通过base64编码后的字符串。
              "Q29kaW5nIHRlc3Rz",
              "text/html",
              "base64"
            );
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  updataContent: string = '<body><div><image src=resource://rawfile/xxx.png alt="image -- end" width="500" height="250"></image></div></body>'

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            // UTF-8为charset。
            this.controller.loadData(this.updataContent, "text/html", "UTF-8", " ", " ");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('accessForward')
        .onClick(() => {
          try {
            let result = this.controller.accessForward();
            console.log('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('accessBackward')
        .onClick(() => {
          try {
            let result = this.controller.accessBackward();
            console.log('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
<br />激活状态是应用与用户互动的状态。应用会保持这种状态，直到发生某些事件（例如收到来电或设备屏幕关闭）时将焦点从应用移开。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('onActive')
        .onClick(() => {
          try {
            this.controller.onActive();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onInactive

onInactive(): void

调用此接口通知Web组件进入未激活状态。开发者可以在此回调中实现应用失去焦点时应表现的恰当行为。

此状态下会尽可能的暂停任何可以安全暂停的内容，例如动画和地理位置。但不会暂停JavaScript，要全局暂停JavaScript，请使用[pauseAllTimers](#pausealltimers12)。要重新激活Web组件，请调用[onActive](#onactive)。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('onInactive')
        .onClick(() => {
          try {
            this.controller.onInactive();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State steps: number = 2;

  build() {
    Column() {
      Button('accessStep')
        .onClick(() => {
          try {
            let result = this.controller.accessStep(this.steps);
            console.log('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearHistory

clearHistory(): void

删除所有前进后退记录，不建议在onErrorReceive与onPageBegin中调用clearHistory，会造成异常退出。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearHistory')
        .onClick(() => {
          try {
            this.controller.clearHistory();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getHitTest')
        .onClick(() => {
          try {
            let hitTestType = this.controller.getHitTest();
            console.log("hitTestType: " + hitTestType);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### registerJavaScriptProxy

registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>, asyncMethodList?: Array\<string>, permission?: string): void

registerJavaScriptProxy提供了应用与Web组件加载的网页之间强大的交互能力。
<br>注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refresh)接口生效。

> **说明：**
>
> - 请尽可能只在可信的URL及安全通信HTTPS场景下进行registerJavaScriptProxy注册。在非可信的Web组件中注入JavaScript对象，可能会导致应用被恶意攻击。
> - 在注册registerJavaScriptProxy后，应用会将JavaScript对象暴露给所有的页面frames。
> - 同一方法在同步与异步列表中重复注册，将默认异步调用。
> - 同步函数列表和异步函数列表不可同时为空，否则此次调用接口注册失败。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型       | 必填 | 说明                                        |
| ---------- | -------------- | ---- | ------------------------------------------------------------ |
| object     | object         | 是   | 参与注册的应用侧JavaScript对象。可以声明方法，也可以声明属性，但是不支持h5直接调用。<br>方法的参数和返回类型可以为string，number，boolean。<br>方法的参数和返回类型支持Dictionary，Array，最多嵌套10层，每层1w个数据。<br>方法的参数和返回类型支持Object，需要在Object里添加属性methodNameListForJsProxy:[fun1, fun2]，fun1和fun2为可被调用的方法。<br>方法的参数支持Function，Promise，它们的Callback不能有返回值。<br>方法的返回类型支持Promise，Promise的Callback不能有返回值。<br>示例请参考[前端页面调用应用侧函数](../../web/web-in-page-app-function-invoking.md)。 |
| name       | string         | 是   | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string> | 是   | 参与注册的应用侧JavaScript对象的同步方法。                       |
| asyncMethodList<sup>12+</sup> | Array\<string> | 否   | 参与注册的应用侧JavaScript对象的异步方法，默认为空。异步方法无法获取返回值。  |
| permission<sup>12+</sup> | string | 否   | json字符串，默认为空，通过该字符串配置JSBridge的权限管控，可以定义object、method一级的url白名单。<br>示例请参考[前端页面调用应用侧函数](../../web/web-in-page-app-function-invoking.md)。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
  constructor() {
  }

  test(testStr:string): string {
    console.log('Web Component str' + testStr);
    return testStr;
  }

  toString(): void {
    console.log('Web Component toString');
  }

  testNumber(testNum:number): number {
    console.log('Web Component number' + testNum);
    return testNum;
  }

  asyncTestBool(testBol:boolean): void {
    console.log('Web Component boolean' + testBol);
  }
}

class WebObj {
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

class AsyncObj {
  constructor() {
  }

  asyncTest(): void {
    console.log('Async test');
  }

  asyncString(testStr:string): void {
    console.log('Web async string' + testStr);
  }
}

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  @State testObjtest: TestObj = new TestObj();
  @State webTestObj: WebObj = new WebObj();
  @State asyncTestObj: AsyncObj = new AsyncObj();

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObjtest, "objName", ["test", "toString", "testNumber"], ["asyncTestBool"]);
            this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);
            this.controller.registerJavaScriptProxy(this.asyncTestObj, "objAsyncName", [], ["asyncTest", "asyncString"]);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
      <p id="asyncDemo"></p>
    </body>
    <script type="text/javascript">
    function htmlTest() {
      // This function call expects to return "ArkUI Web Component"
      let str=objName.test("webtest data");
      objName.testNumber(1);
      objName.asyncTestBool(true);
      document.getElementById("demo").innerHTML=str;
      console.log('objName.test result:'+ str)

      // This function call expects to return "Web test"
      let webStr = objTestName.webTest();
      document.getElementById("webDemo").innerHTML=webStr;
      console.log('objTestName.webTest result:'+ webStr)

      objAsyncName.asyncTest();
      objAsyncName.asyncString("async test data");
    }
</script>
</html>
```
更多示例，请参考[前端页面调用应用侧函数](../../web/web-in-page-app-function-invoking.md)。

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State webResult: string = '';

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
                  console.error(`run JavaScript error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                  return;
                }
                if (result) {
                  this.webResult = result;
                  console.info(`The test() return value is: ${result}`);
                }
              });
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

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
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              })
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

runJavaScriptExt(script: string | ArrayBuffer, callback : AsyncCallback\<JsMessageExt>): void

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScriptExt需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string \| ArrayBuffer<sup>12+</sup>         | 是   | JavaScript脚本。 |
| callback | AsyncCallback\<[JsMessageExt](#jsmessageext10)\> | 是   | 回调执行JavaScript脚本结果。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State msg1: string = '';
  @State msg2: string = '';

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
                  console.error(`run JavaScript error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`)
                  return;
                }
                if (result) {
                  try {
                    let type = result.getType();
                    switch (type) {
                      case webview.JsMessageType.STRING: {
                        this.msg1 = "result type:" + typeof (result.getString());
                        this.msg2 = "result getString:" + ((result.getString()));
                        break;
                      }
                      case webview.JsMessageType.NUMBER: {
                        this.msg1 = "result type:" + typeof (result.getNumber());
                        this.msg2 = "result getNumber:" + ((result.getNumber()));
                        break;
                      }
                      case webview.JsMessageType.BOOLEAN: {
                        this.msg1 = "result type:" + typeof (result.getBoolean());
                        this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                        break;
                      }
                      case webview.JsMessageType.ARRAY_BUFFER: {
                        this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                        this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                        break;
                      }
                      case webview.JsMessageType.ARRAY: {
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
                    console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                  }
                }
              });
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
    }
  }
}
```

```ts
// 使用ArrayBuffer入参，从文件中获取JavaScript脚本数据
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State msg1: string = ''
  @State msg2: string = ''

  build() {
    Column() {
      Text(this.msg1).fontSize(20)
      Text(this.msg2).fontSize(20)
      Button('runJavaScriptExt')
        .onClick(() => {
          try {
            let context = getContext(this) as common.UIAbilityContext;
            let filePath = context.filesDir + 'test.txt';
            // 新建并打开文件
            let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
            // 写入一段内容至文件
            fileIo.writeSync(file.fd, "test()");
            // 从文件中读取内容
            let arrayBuffer: ArrayBuffer = new ArrayBuffer(6);
            fileIo.readSync(file.fd, arrayBuffer, { offset: 0, length: arrayBuffer.byteLength });
            // 关闭文件
            fileIo.closeSync(file);
            this.controller.runJavaScriptExt(
              arrayBuffer,
              (error, result) => {
                if (error) {
                  console.error(`run JavaScript error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`)
                  return;
                }
                if (result) {
                  try {
                    let type = result.getType();
                    switch (type) {
                      case webview.JsMessageType.STRING: {
                        this.msg1 = "result type:" + typeof (result.getString());
                        this.msg2 = "result getString:" + ((result.getString()));
                        break;
                      }
                      case webview.JsMessageType.NUMBER: {
                        this.msg1 = "result type:" + typeof (result.getNumber());
                        this.msg2 = "result getNumber:" + ((result.getNumber()));
                        break;
                      }
                      case webview.JsMessageType.BOOLEAN: {
                        this.msg1 = "result type:" + typeof (result.getBoolean());
                        this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                        break;
                      }
                      case webview.JsMessageType.ARRAY_BUFFER: {
                        this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                        this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                        break;
                      }
                      case webview.JsMessageType.ARRAY: {
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
                    console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                  }
                }
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

runJavaScriptExt(script: string | ArrayBuffer): Promise\<JsMessageExt>

异步执行JavaScript脚本，并通过Promise方式返回脚本执行的结果。runJavaScriptExt需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | -------- | ---- | ---------------- |
| script | string \| ArrayBuffer<sup>12+</sup> | 是   | JavaScript脚本。 |

**返回值：**

| 类型            | 说明                                                |
| --------------- | --------------------------------------------------- |
| Promise\<[JsMessageExt](#jsmessageext10)> | Promise实例，返回脚本执行的结果。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State webResult: string = '';
  @State msg1: string = '';
  @State msg2: string = '';

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
                  case webview.JsMessageType.STRING: {
                    this.msg1 = "result type:" + typeof (result.getString());
                    this.msg2 = "result getString:" + ((result.getString()));
                    break;
                  }
                  case webview.JsMessageType.NUMBER: {
                    this.msg1 = "result type:" + typeof (result.getNumber());
                    this.msg2 = "result getNumber:" + ((result.getNumber()));
                    break;
                  }
                  case webview.JsMessageType.BOOLEAN: {
                    this.msg1 = "result type:" + typeof (result.getBoolean());
                    this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                    break;
                  }
                  case webview.JsMessageType.ARRAY_BUFFER: {
                    this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                    this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                    break;
                  }
                  case webview.JsMessageType.ARRAY: {
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
                console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            }).catch((error: BusinessError) => {
            console.error("error: " + error);
          })
        })
    }
  }
}
```

```ts
// 使用ArrayBuffer入参，从文件中获取JavaScript脚本数据
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State msg1: string = '';
  @State msg2: string = '';

  build() {
    Column() {
      Text(this.msg1).fontSize(20)
      Text(this.msg2).fontSize(20)
      Button('runJavaScriptExt')
        .onClick(() => {
          try {
            let context = getContext(this) as common.UIAbilityContext;
            let filePath = context.filesDir + 'test.txt';
            // 新建并打开文件
            let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
            // 写入一段内容至文件
            fileIo.writeSync(file.fd, "test()");
            // 从文件中读取内容
            let arrayBuffer: ArrayBuffer = new ArrayBuffer(6);
            fileIo.readSync(file.fd, arrayBuffer, { offset: 0, length: arrayBuffer.byteLength });
            // 关闭文件
            fileIo.closeSync(file);
            this.controller.runJavaScriptExt(arrayBuffer)
              .then((result) => {
                try {
                  let type = result.getType();
                  switch (type) {
                    case webview.JsMessageType.STRING: {
                      this.msg1 = "result type:" + typeof (result.getString());
                      this.msg2 = "result getString:" + ((result.getString()));
                      break;
                    }
                    case webview.JsMessageType.NUMBER: {
                      this.msg1 = "result type:" + typeof (result.getNumber());
                      this.msg2 = "result getNumber:" + ((result.getNumber()));
                      break;
                    }
                    case webview.JsMessageType.BOOLEAN: {
                      this.msg1 = "result type:" + typeof (result.getBoolean());
                      this.msg2 = "result getBoolean:" + ((result.getBoolean()));
                      break;
                    }
                    case webview.JsMessageType.ARRAY_BUFFER: {
                      this.msg1 = "result type:" + typeof (result.getArrayBuffer());
                      this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));
                      break;
                    }
                    case webview.JsMessageType.ARRAY: {
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
                  console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
                }
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100008 | Failed to delete JavaScriptProxy because it does not exist.                               |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
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
  controller: webview.WebviewController = new webview.WebviewController();
  @State testObjtest: TestObj = new TestObj();
  @State name: string = 'objName';
  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObjtest, this.name, ["test", "toString"]);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister(this.name);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

调整当前网页的缩放比例，[zoomAccess](ts-basic-components-web.md#zoomaccess)需为true。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | 是   | 基于当前网页所需调整的相对缩放比例，入参要求大于0，当入参为1时为默认加载网页的缩放比例，入参小于1为缩小，入参大于1为放大。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State factor: number = 1;

  build() {
    Column() {
      Button('zoom')
        .onClick(() => {
          try {
            this.controller.zoom(this.factor);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

异步查找网页中所有匹配关键字'searchString'的内容并高亮，结果通过[onSearchResultReceive](ts-basic-components-web.md#onsearchresultreceive9)异步返回。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型 | 必填 | 说明       |
| ------------ | -------- | ---- | -------------- |
| searchString | string   | 是   | 查找的关键字。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State searchString: string = "Hello World";

  build() {
    Column() {
      Button('searchString')
        .onClick(() => {
          try {
            this.controller.searchAllAsync(this.searchString);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearMatches')
        .onClick(() => {
          try {
            this.controller.clearMatches();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('searchNext')
        .onClick(() => {
          try {
            this.controller.searchNext(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearSslCache')
        .onClick(() => {
          try {
            this.controller.clearSslCache();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearClientAuthenticationCache')
        .onClick(() => {
          try {
            this.controller.clearClientAuthenticationCache();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| isExtentionType<sup>10+</sup>   | boolean     | 否  | 是否使用扩展增强接口，默认false不使用。 |

**返回值：**

| 类型                   | 说明              |
| ---------------------- | ----------------- |
| Array\<[WebMessagePort](#webmessageport)> | web消息端口列表。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  ports: webview.WebMessagePort[] = [];

  build() {
    Column() {
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.ports.length);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| ports  | Array\<[WebMessagePort](#webmessageport)> | 是   | 要发送的消息端口。            |
| uri    | string                 | 是   | 接收该消息的URI。                |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  ports: webview.WebMessagePort[] = [];
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
            this.ports[1].onMessageEvent((result: webview.WebMessage) => {
              let msg = 'Got msg from HTML:';
              if (typeof (result) == "string") {
                console.log("received string message from html5, string is:" + result);
                msg = msg + result;
              } else if (typeof (result) == "object") {
                if (result instanceof ArrayBuffer) {
                  console.log("received arraybuffer from html5, length is:" + result.byteLength);
                  msg = msg + "length is " + result.byteLength;
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
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
                  msg = msg + "length is " + result.byteLength;
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('requestFocus')
        .onClick(() => {
          try {
            this.controller.requestFocus();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('zoomIn')
        .onClick(() => {
          try {
            this.controller.zoomIn();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('zoomOut')
        .onClick(() => {
          try {
            this.controller.zoomOut();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getHitTestValue')
        .onClick(() => {
          try {
            let hitValue = this.controller.getHitTestValue();
            console.log("hitType: " + hitValue.type);
            console.log("extra: " + hitValue.extra);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getWebId')
        .onClick(() => {
          try {
            let id = this.controller.getWebId();
            console.log("id: " + id);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

默认UserAgent定义与使用场景请参考[UserAgent详情参考](../../web/web-default-userAgent.md)

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| string | 默认用户代理。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getUserAgent')
        .onClick(() => {
          try {
            let userAgent = this.controller.getUserAgent();
            console.log("userAgent: " + userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State ua: string = "";

  aboutToAppear(): void {
    webview.once('webInited', () => {
      try {
        // 应用侧用法示例，定制UserAgent。
        this.ua = this.controller.getUserAgent() + 'xxx';
        this.controller.setCustomUserAgent(this.ua);
      } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
      }
    })
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getTitle')
        .onClick(() => {
          try {
            let title = this.controller.getTitle();
            console.log("title: " + title);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| number | 当前网页的页面高度。单位：vp。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getPageHeight')
        .onClick(() => {
          try {
            let pageHeight = this.controller.getPageHeight();
            console.log("pageHeight : " + pageHeight);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('storeWebArchive')
        .onClick(() => {
          try {
            this.controller.storeWebArchive("/data/storage/el2/base/", true, (error, filename) => {
              if (error) {
                console.error(`save web archive error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              if (filename != null) {
                console.info(`save web archive success: ${filename}`);
              }
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

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
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getUrl')
        .onClick(() => {
          try {
            let url = this.controller.getUrl();
            console.log("url: " + url);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('stop')
        .onClick(() => {
          try {
            this.controller.stop();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State step: number = -2;

  build() {
    Column() {
      Button('backOrForward')
        .onClick(() => {
          try {
            this.controller.backOrForward(this.step);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### scrollTo

scrollTo(x:number, y:number, duration?:number): void

在指定时间内，将页面滚动到指定的绝对位置。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| x   | number   | 是   | 绝对位置的水平坐标，当传入数值为负数时，按照传入0处理。单位：vp。 |
| y   | number   | 是   | 绝对位置的垂直坐标，当传入数值为负数时，按照传入0处理。单位：vp。|
| duration<sup>14+</sup> | number | 否 | 滚动动画时间。<br>单位：ms。<br>不传入为无动画，当传入数值为负数或传入0时，按照不传入处理。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('scrollTo')
        .onClick(() => {
          try {
            this.controller.scrollTo(50, 50, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Button('stopScroll')
        .onClick(() => {
          try {
            this.controller.scrollBy(0, 0, 1); //如果想停止当前scroll产生的动画，可再次生成一个1ms的动画去打断该动画。
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
            width:2000px;
            height:2000px;
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

scrollBy(deltaX:number, deltaY:number,duration?:number): void

在指定时间内将页面滚动指定的偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | 是   | 水平偏移量，其中水平向右为正方向。单位：vp。 |
| deltaY | number   | 是   | 垂直偏移量，其中垂直向下为正方向。单位：vp。 |
| duration<sup>14+</sup> | number | 否 | 滚动动画时间。<br>单位：ms。<br>不传入为无动画，当传入数值为负数或传入0时，按照不传入处理。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

> **说明：**
>
> 嵌套滚动场景中，调用scrollBy不会触发父组件的嵌套滚动。

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('scrollBy')
        .onClick(() => {
          try {
            this.controller.scrollBy(50, 50, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('stopScroll')
        .onClick(() => {
          try {
            this.controller.scrollBy(0, 0, 1); //如果想停止当前scroll产生的动画，可再次生成一个1ms的动画去打断该动画。
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
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
            width:2000px;
            height:2000px;
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
### scrollByWithResult<sup>12+</sup>

scrollByWithResult(deltaX: number, deltaY: number): boolean

将页面滚动指定的偏移量，返回值表示此次滚动是否执行成功。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | 是   | 水平偏移量，其中水平向右为正方向。 |
| deltaY | number   | 是   | 垂直偏移量，其中垂直向下为正方向。 |

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| boolean | 当前网页是否可以滑动，默认为false。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

> **说明：**
>
> - 返回值场景：Web页面处于触摸中状态时，返回false，否则返回true。
> - 同层渲染场景中，Web的同层渲染区域处于触摸中状态时，返回值为true。
> - 嵌套滚动场景中，调用scrollByWithResult不会触发父组件的嵌套滚动。
> - 此接口不保证滑动帧率性能。

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('scrollByWithResult')
        .onClick(() => {
          try {
          let result = this.controller.scrollByWithResult(50, 50);
          console.log("original result: " + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
            width:2000px;
            height:2000px;
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
| vx     | number   | 是   | 轻扫滚动的水平速度分量，其中水平向右为速度正方向。单位：vp/ms。 |
| vy     | number   | 是   | 轻扫滚动的垂直速度分量，其中垂直向下为速度正方向。单位：vp/ms。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('slideScroll')
        .onClick(() => {
          try {
            this.controller.slideScroll(500, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
风险提示：如果想获取url来做JavascriptProxy通信接口认证，请使用[getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](#getlastjavascriptproxycallingframeurl12)

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                    |
| ------ | ----------------------- |
| string | 当前页面的原始url地址。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getOrgUrl')
        .onClick(() => {
          try {
            let url = this.controller.getOriginalUrl();
            console.log("original url: " + url);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 页面favicon图标的PixelMap对象。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State pixelmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Button('getFavicon')
        .onClick(() => {
          try {
            this.pixelmap = this.controller.getFavicon();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setNetworkAvailable')
        .onClick(() => {
          try {
            this.controller.setNetworkAvailable(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('hasImageCb')
        .onClick(() => {
          try {
            this.controller.hasImage((error, data) => {
              if (error) {
                console.error(`hasImage error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.info("hasImage: " + data);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('hasImagePm')
        .onClick(() => {
          try {
            this.controller.hasImage().then((data) => {
              console.info('hasImage: ' + data);
            }).catch((error: BusinessError) => {
              console.error("error: " + error);
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('removeCache')
        .onClick(() => {
          try {
            this.controller.removeCache(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageUp

pageUp(top: boolean): void

将Webview的内容向上滚动半个视框大小或者跳转到页面最顶部，通过top入参控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| top    | boolean | 是   | 是否跳转到页面最顶部，设置为false时将页面内容向上滚动半个视框大小，设置为true时跳转到页面最顶部。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('pageUp')
        .onClick(() => {
          try {
            this.controller.pageUp(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageDown

pageDown(bottom: boolean): void

将Webview的内容向下滚动半个视框大小或者跳转到页面最底部，通过bottom入参控制。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| bottom | boolean | 是   | 是否跳转到页面最底部，设置为false时将页面内容向下滚动半个视框大小，设置为true时跳转到页面最底部。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('pageDown')
        .onClick(() => {
          try {
            this.controller.pageDown(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getBackForwardEntries')
        .onClick(() => {
          try {
            let list = this.controller.getBackForwardEntries()
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](../apis-core-file-kit/js-apis-file-fs.md)。
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

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
              let file = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
              fileIo.writeSync(file.fd, state.buffer);
              fileIo.closeSync(file.fd);
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.修改EntryAbility.ets。
获取应用缓存文件路径。
```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](../apis-core-file-kit/js-apis-file-fs.md)。
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('RestoreWebState')
        .onClick(() => {
          try {
            let path: string | undefined = AppStorage.get("cacheDir");
            if (path) {
              path += '/WebState';
              // 以同步方法打开文件。
              let file = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE);
              let stat = fileIo.statSync(path);
              let size = stat.size;
              let buf = new ArrayBuffer(size);
              fileIo.read(file.fd, buf, (err, readLen) => {
                if (err) {
                  console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);
                } else {
                  console.info("read file data succeed");
                  this.controller.restoreWebState(new Uint8Array(buf.slice(0, readLen)));
                  fileIo.closeSync(file);
                }
              });
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2.修改EntryAbility.ets。
获取应用缓存文件路径。
```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // 通过在AppStorage对象上绑定cacheDir，可以实现UIAbility组件与Page之间的数据同步。
    AppStorage.setOrCreate("cacheDir", this.context.cacheDir);
  }
}
```

### customizeSchemes

static customizeSchemes(schemes: Array\<WebCustomScheme\>): void

对Web内核赋予自定义协议url的跨域请求与fetch请求的权限。当Web在跨域fetch自定义协议url时，该fetch请求可被onInterceptRequest事件接口所拦截，从而开发者可以进一步处理该请求。建议在任何Web组件初始化之前调用该接口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明                      |
| -------- | ------- | ---- | -------------------------------------- |
| schemes | Array\<[WebCustomScheme](#webcustomscheme)\> | 是   | 自定义协议配置，最多支持同时配置10个自定义协议。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |
| 17100020 | Failed to register custom schemes. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  responseWeb: WebResourceResponse = new WebResourceResponse();
  scheme1: webview.WebCustomScheme = { schemeName: "name1", isSupportCORS: true, isSupportFetch: true };
  scheme2: webview.WebCustomScheme = { schemeName: "name2", isSupportCORS: true, isSupportFetch: true };
  scheme3: webview.WebCustomScheme = { schemeName: "name3", isSupportCORS: true, isSupportFetch: true };

  aboutToAppear(): void {
    try {
      webview.WebviewController.customizeSchemes([this.scheme1, this.scheme2, this.scheme3]);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onInterceptRequest((event) => {
          if (event) {
            console.log('url:' + event.request.getRequestUrl());
          }
          return this.responseWeb;
        })
    }
  }
}
```

### getCertificate<sup>10+</sup>

getCertificate(): Promise<Array<cert.X509Cert>>

获取当前网站的证书信息。使用Web组件加载https网站，会进行SSL证书校验，该接口会通过Promise异步返回当前网站的X509格式证书（X509Cert证书类型定义见[X509Cert](../apis-device-certificate-kit/js-apis-cert.md#x509cert)定义），便于开发者展示网站证书信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型       | 说明                                          |
| ---------- | --------------------------------------------- |
| Promise<Array<cert.X509Cert>> | Promise实例，用于获取当前加载的https网站的X509格式证书数组。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { cert } from '@kit.DeviceCertificateKit';

function Uint8ArrayToString(dataArray: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < dataArray.length; i++) {
    dataString += String.fromCharCode(dataArray[i]);
  }
  return dataString;
}

function ParseX509CertInfo(x509CertArray: Array<cert.X509Cert>) {
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;
  for (let i = 0; i < x509CertArray.length; i++) {
    res += ', index = ' + i + ', issuer name = '
      + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '
      + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '
      + x509CertArray[i].getNotBeforeTime()
      + ', valid end = ' + x509CertArray[i].getNotAfterTime();
  }
  return res;
}

@Entry
@Component
struct Index {
  // outputStr在UI界面显示调试信息
  @State outputStr: string = '';
  webviewCtl: webview.WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ListItem() {
            Button() {
              Text('load bad ssl')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个过期的证书网站，查看获取到的证书信息
              this.webviewCtl.loadUrl('https://expired.badssl.com');
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
              this.webviewCtl.loadUrl('https://www.example.com');
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
                this.webviewCtl.getCertificate().then((x509CertArray: Array<cert.X509Cert>) => {
                  this.outputStr = ParseX509CertInfo(x509CertArray);
                })
              } catch (error) {
                this.outputStr = 'getCertificate failed: ' + (error as BusinessError).code + ", errMsg: " + (error as BusinessError).message;
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
                this.webviewCtl.getCertificate((error: BusinessError, x509CertArray: Array<cert.X509Cert>) => {
                  if (error) {
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;
                  } else {
                    this.outputStr = ParseX509CertInfo(x509CertArray);
                  }
                })
              } catch (error) {
                this.outputStr = 'getCertificate failed: ' + (error as BusinessError).code + ", errMsg: " + (error as BusinessError).message;
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
              this.outputStr = 'onPageEnd : url = ' + e.url;
            }
          })
          .onSslErrorEventReceive((e) => {
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com
            e.handler.handleConfirm();
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

获取当前网站的证书信息。使用Web组件加载https网站，会进行SSL证书校验，该接口会通过AsyncCallback异步返回当前网站的X509格式证书（X509Cert证书类型定义见[X509Cert定义](../apis-device-certificate-kit/js-apis-cert.md)），便于开发者展示网站证书信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<Array<cert.X509Cert>> | 是   | 通过AsyncCallback异步返回当前网站的X509格式证书。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { cert } from '@kit.DeviceCertificateKit';

function Uint8ArrayToString(dataArray: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < dataArray.length; i++) {
    dataString += String.fromCharCode(dataArray[i]);
  }
  return dataString;
}

function ParseX509CertInfo(x509CertArray: Array<cert.X509Cert>) {
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;
  for (let i = 0; i < x509CertArray.length; i++) {
    res += ', index = ' + i + ', issuer name = '
      + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '
      + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '
      + x509CertArray[i].getNotBeforeTime()
      + ', valid end = ' + x509CertArray[i].getNotAfterTime();
  }
  return res;
}

@Entry
@Component
struct Index {
  // outputStr在UI界面显示调试信息
  @State outputStr: string = '';
  webviewCtl: webview.WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ListItem() {
            Button() {
              Text('load bad ssl')
                .fontSize(10)
                .fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .onClick(() => {
              // 加载一个过期的证书网站，查看获取到的证书信息
              this.webviewCtl.loadUrl('https://expired.badssl.com');
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
              this.webviewCtl.loadUrl('https://www.example.com');
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
                this.webviewCtl.getCertificate().then((x509CertArray: Array<cert.X509Cert>) => {
                  this.outputStr = ParseX509CertInfo(x509CertArray);
                })
              } catch (error) {
                this.outputStr = 'getCertificate failed: ' + (error as BusinessError).code + ", errMsg: " + (error as BusinessError).message;
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
                this.webviewCtl.getCertificate((error: BusinessError, x509CertArray: Array<cert.X509Cert>) => {
                  if (error) {
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;
                  } else {
                    this.outputStr = ParseX509CertInfo(x509CertArray);
                  }
                })
              } catch (error) {
                this.outputStr = 'getCertificate failed: ' + (error as BusinessError).code + ", errMsg: " + (error as BusinessError).message;
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
              this.outputStr = 'onPageEnd : url = ' + e.url;
            }
          })
          .onSslErrorEventReceive((e) => {
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com
            e.handler.handleConfirm();
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State muted: boolean = false;

  build() {
    Column() {
      Button("Toggle Mute")
        .onClick(event => {
          if (event) {
            this.muted = !this.muted;
            this.controller.setAudioMuted(this.muted);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### prefetchPage<sup>10+</sup>

prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void

在预测到将要加载的页面之前调用，提前下载页面所需的资源，包括主资源子资源，但不会执行网页JavaScript代码或呈现网页，以加快加载速度。

> **说明：**
>
> 下载的页面资源，会缓存五分钟左右，超过这段时间Web组件会自动释放。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型                             | 必填  | 说明                      |
| ------------------| --------------------------------| ---- | ------------- |
| url               | string                          | 是    | 预加载的url。|
| additionalHeaders | Array\<[WebHeader](#webheader)> | 否    | url的附加HTTP请求头。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('prefetchPopularPage')
        .onClick(() => {
          try {
            // 预加载时，需要将'https://www.example.com'替换成一个真实的网站地址。
            this.controller.prefetchPage('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // 需要将'www.example1.com'替换成一个真实的网站地址。
      Web({ src: 'www.example1.com', controller: this.controller })
    }
  }
}
```

### prefetchResource<sup>12+</sup>

static prefetchResource(request: RequestInfo, additionalHeaders?: Array\<WebHeader>, cacheKey?: string, cacheValidTime?: number): void

根据指定的请求信息和附加的http请求头去预获取资源请求，存入内存缓存，并指定其缓存key和有效期，以加快加载速度。目前仅支持Content-Type为application/x-www-form-urlencoded的post请求。最多可以预获取6个post请求。如果要预获取第7个，请通过[clearPrefetchedResource](#clearprefetchedresource12)清除不需要的post请求缓存，否则会自动清除最早预获取的post缓存。如果要使用预获取的资源缓存，开发者需要在正式发起的post请求的请求头中增加键值“ArkWebPostCacheKey”，其内容为对应缓存的cacheKey。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型                             |  必填  | 说明                                                              |
| ------------------| ------------------------------- | ---- | ------------------------------------------------------------------ |
| request           | [RequestInfo](#requestinfo12)   | 是   | 预获取请求的信息。                                                      |
| additionalHeaders | Array\<[WebHeader](#webheader)> | 否   | 预获取请求的附加HTTP请求头。                                             |
| cacheKey          | string                          | 否   | 用于后续查询预获取资源缓存的key。仅支持字母和数字，未传入或传入空则取默认值url作为key。 |
| cacheValidTime    | number                          | 否   | 预获取资源缓存的有效期。取值范围：(0, 2147483647]。单位：秒。默认值：300秒。          |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // 预获取时，需要將"https://www.example1.com/post?e=f&g=h"替换成真实要访问的网站地址。
    webview.WebviewController.prefetchResource(
      {url:"https://www.example1.com/post?e=f&g=h",
        method:"POST",
        formData:"a=x&b=y",},
      [{headerKey:"c",
        headerValue:"z",},],
      "KeyX", 500);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

### clearPrefetchedResource<sup>12+</sup>

static clearPrefetchedResource(cacheKeyList: Array\<string>): void

根据指定的缓存key列表清除对应的预获取资源缓存。入参中的缓存key必须是[prefetchResource](#prefetchresource12)指定预获取到的资源缓存key。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名             | 类型        | 必填  | 说明                                                                       |
| ------------------| ----------- | ---- | ------------------------------------------------------------------------- |
| cacheKeyList      | Array\<string>      | 是   | 用于后续查询预获取资源缓存的key。仅支持字母和数字，未传入或传入空则取默认值url作为key。 |

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
      Web({ src: "https://www.example.com/", controller: this.controller})
        .onAppear(() => {
          // 预获取时，需要將"https://www.example1.com/post?e=f&g=h"替换成真实要访问的网站地址。
          webview.WebviewController.prefetchResource(
            {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
            [{headerKey:"c",
              headerValue:"z",},],
            "KeyX", 500);
        })
        .onPageEnd(() => {
          // 清除后续不再使用的预获取缓存。
          webview.WebviewController.clearPrefetchedResource(["KeyX",]);
        })
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100002 | Invalid url.                                                 |
| 171000013| The number of preconnect sockets is invalid.                                                 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // 预连接时，需要將'https://www.example.com'替换成一个真实的网站地址。
    webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

### setCustomUserAgent<sup>10+</sup>

setCustomUserAgent(userAgent: string): void

设置自定义用户代理，会覆盖系统的用户代理。

当Web组件src设置了url时，建议在onControllerAttached回调事件中设置UserAgent，设置方式请参考示例。不建议将UserAgent设置在onLoadIntercept回调事件中，会概率性出现设置失败。

当Web组件src设置为空字符串时，建议先调用setCustomUserAgent方法设置UserAgent，再通过loadUrl加载具体页面。

默认UserAgent定义与使用场景请参考[UserAgent详情参考](../../web/web-default-userAgent.md)

> **说明：**
>
>当Web组件src设置了url，且未在onControllerAttached回调事件中设置UserAgent。再调用setCustomUserAgent方法时，可能会出现加载的页面与实际设置UserAgent不符的异常现象。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | 是   | 用户自定义代理信息。建议先使用[getUserAgent](#getuseragent)获取当前默认用户代理，在此基础上追加自定义用户代理信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State customUserAgent: string = ' DemoApp';

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
      .onControllerAttached(() => {
        console.log("onControllerAttached");
        try {
          let userAgent = this.controller.getUserAgent() + this.customUserAgent;
          this.controller.setCustomUserAgent(userAgent);
        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

默认UserAgent定义与使用场景请参考[UserAgent详情参考](../../web/web-default-userAgent.md)

**系统能力：**  SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 用户自定义代理信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State userAgent: string = '';

  build() {
    Column() {
      Button('getCustomUserAgent')
        .onClick(() => {
          try {
            this.userAgent = this.controller.getCustomUserAgent();
            console.log("userAgent: " + this.userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| timeout        | number  | 是   | socket连接超时时间，以秒为单位，socket必须为大于0的整数。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setConnectionTimeout')
        .onClick(() => {
          try {
            webview.WebviewController.setConnectionTimeout(5);
            console.log("setConnectionTimeout: 5s");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onErrorReceive((event) => {
          if (event) {
            console.log('getErrorInfo:' + event.error.getErrorInfo());
            console.log('getErrorCode:' + event.error.getErrorCode());
          }
        })
    }
  }
}
```

### warmupServiceWorker<sup>12+</sup>

static warmupServiceWorker(url: string): void

预热ServiceWorker，以提升首屏页面的加载速度（仅限于会使用ServiceWorker的页面）。在加载url之前调用此API。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| url            | string  | 是   | 需要预热ServiceWorker的url。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100002 | Invalid url.                                                 |

**示例：**

```ts
// xxx.ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        webview.WebviewController.warmupServiceWorker("https://www.example.com");
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

### enableSafeBrowsing<sup>11+</sup>

enableSafeBrowsing(enable: boolean): void

<!--RP1-->启用检查网站安全风险的功能，非法和欺诈网站是强制启用的，不能通过此功能禁用。
本功能默认不生效，OpenHarmony只提供恶意网址拦截页WebUI，网址风险检测以及显示WebUI的功能由Vendor实现。推荐在WebContentsObserver中监听跳转[DidStartNavigation](https://gitee.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidStartNavigation)、[DidRedirectNavigation](https://gitee.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidRedirectNavigation)进行检测。
<!--RP1End-->

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | 是   | 是否启用检查网站安全风险的功能。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('enableSafeBrowsing')
        .onClick(() => {
          try {
            this.controller.enableSafeBrowsing(true);
            console.log("enableSafeBrowsing: true");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isSafeBrowsingEnabled<sup>11+</sup>

isSafeBrowsingEnabled(): boolean

获取当前网页是否启用了检查网站安全风险。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| boolean | 当前网页是否启用了检查网站安全风险的功能，默认为false。|

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
      Button('isSafeBrowsingEnabled')
        .onClick(() => {
          let result = this.controller.isSafeBrowsingEnabled();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### enableIntelligentTrackingPrevention<sup>12+</sup>

enableIntelligentTrackingPrevention(enable: boolean): void

启用智能防跟踪功能，默认该功能未启用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | 是   | 是否启用智能防跟踪功能。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('enableIntelligentTrackingPrevention')
        .onClick(() => {
          try {
            this.controller.enableIntelligentTrackingPrevention(true);
            console.log("enableIntelligentTrackingPrevention: true");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isIntelligentTrackingPreventionEnabled<sup>12+</sup>

isIntelligentTrackingPreventionEnabled(): boolean

获取当前Web是否启用了智能防跟踪功能。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| boolean | 当前Web是否启用了智能防跟踪功能，默认为false。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isIntelligentTrackingPreventionEnabled')
        .onClick(() => {
          try {
            let result = this.controller.isIntelligentTrackingPreventionEnabled();
            console.log("result: " + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### addIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static addIntelligentTrackingPreventionBypassingList(hostList: Array\<string>): void

添加智能防跟踪功能绕过的域名列表。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型           | 必填  | 说明                      |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | 是   | 绕过智能防跟踪功能的域名列表。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                  |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('addIntelligentTrackingPreventionBypassingList')
        .onClick(() => {
          try {
            let hostList = ["www.test1.com", "www.test2.com", "www.test3.com"];
            webview.WebviewController.addIntelligentTrackingPreventionBypassingList(hostList);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### removeIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static removeIntelligentTrackingPreventionBypassingList(hostList: Array\<string>): void

删除通过addIntelligentTrackingPreventionBypassingList接口添加的部分域名列表。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型           | 必填  | 说明                      |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | 是   | 绕过智能防跟踪功能的域名列表。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                  |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('removeIntelligentTrackingPreventionBypassingList')
        .onClick(() => {
          try {
            let hostList = ["www.test1.com", "www.test2.com"];
            webview.WebviewController.removeIntelligentTrackingPreventionBypassingList(hostList);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static clearIntelligentTrackingPreventionBypassingList(): void

删除通过addIntelligentTrackingPreventionBypassingList接口添加的所有域名。

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
      Button('clearIntelligentTrackingPreventionBypassingList')
        .onClick(() => {
          webview.WebviewController.clearIntelligentTrackingPreventionBypassingList();
      })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### enableAdsBlock<sup>12+</sup>

enableAdsBlock(enable: boolean): void

启用广告过滤功能，默认该功能未启用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | 是   | 是否启用广告过滤功能。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('enableAdsBlock')
        .onClick(() => {
          try {
            this.controller.enableAdsBlock(true);
            console.log("enableAdsBlock: true")
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isAdsBlockEnabled<sup>12+</sup>

isAdsBlockEnabled() : boolean

查询广告过滤功能是否开启，默认该功能未启用。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| boolean | 返回true代表广告过滤功能已开启，返回false代表广告过滤功能关闭。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isAdsBlockEnabled')
        .onClick(() => {
          try {
            let isAdsBlockEnabled: boolean = this.controller.isAdsBlockEnabled();
            console.log("isAdsBlockEnabled:", isAdsBlockEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### isAdsBlockEnabledForCurPage<sup>12+</sup>

isAdsBlockEnabledForCurPage() : boolean

查询当前网页是否开启广告过滤功能。
当Web组件使能广告过滤功能后，默认所有页面都是开启广告过滤的，支持通过[addAdsBlockDisallowedList](#addadsblockdisallowedlist12)指定域名禁用广告过滤。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| boolean | 返回true代表此网页已开启广告过滤，返回false代表当前网页已关闭广告过滤。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isAdsBlockEnabledForCurPage')
        .onClick(() => {
          try {
            let isAdsBlockEnabledForCurPage: boolean = this.controller.isAdsBlockEnabledForCurPage();
            console.log("isAdsBlockEnabledForCurPage:", isAdsBlockEnabledForCurPage);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setRenderProcessMode<sup>12+</sup>

static setRenderProcessMode(mode: RenderProcessMode): void

设置ArkWeb渲染子进程模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型           | 必填  | 说明                      |
| ----------- | ------------- | ---- | ------------------------ |
| mode        | [RenderProcessMode](#renderprocessmode12)| 是   | 渲染子进程模式。如果传入RenderProcessMode枚举值之外的非法数字，则默认识别为多渲染子进程模式。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                  |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setRenderProcessMode')
        .onClick(() => {
          try {
            webview.WebviewController.setRenderProcessMode(webview.RenderProcessMode.MULTIPLE);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
### getRenderProcessMode<sup>12+</sup>

static getRenderProcessMode(): RenderProcessMode

查询ArkWeb的渲染子进程模式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| [RenderProcessMode](#renderprocessmode12)| 渲染子进程模式类型。如果获取的值不在RenderProcessMode枚举值范围内，则默认为多渲染子进程模式。|


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
      Button('getRenderProcessMode')
        .onClick(() => {
          let mode = webview.WebviewController.getRenderProcessMode();
          console.log("getRenderProcessMode: " + mode);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### terminateRenderProcess<sup>12+</sup>

terminateRenderProcess(): boolean

销毁渲染进程。

调用该接口将会主动销毁相关联的渲染进程。如果渲染进程尚未启动，或者已销毁则没有任何影响。此外销毁渲染进程会同时影响所有与该渲染进程关联的其他实例。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| boolean | 返回销毁渲染进程的结果，如果渲染进程可以被销毁则返回true，否则返回false。 如果渲染进程已被销毁则直接返回true。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

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
      Button('terminateRenderProcess')
        .onClick(() => {
          let result = this.controller.terminateRenderProcess();
          console.log("terminateRenderProcess result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### postUrl<sup>11+</sup>

postUrl(url: string, postData: ArrayBuffer): void

使用"POST"方法加载带有postData的url。如果url不是网络url，则会使用[loadUrl](#loadurl)方法加载url，忽略postData参数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                  |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string | 是   | 需要加载的 URL。      |
| postData | ArrayBuffer | 是   | 使用"POST"方法传递数据。 该请求必须采用"application/x-www-form-urlencoded"编码。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
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
  controller: webview.WebviewController = new webview.WebviewController();
  @State testObjtest: TestObj = new TestObj();

  build() {
    Column() {
      Button('postUrl')
        .onClick(() => {
          try {
            // 数据转化为ArrayBuffer类型。
            let postData = this.testObjtest.test("Name=test&Password=test");
            this.controller.postUrl('www.example.com', postData);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: '', controller: this.controller })
    }
  }
}
```

### createWebPrintDocumentAdapter<sup>11+</sup>

createWebPrintDocumentAdapter(jobName: string): print.PrintDocumentAdapter

创建web相关打印功能。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                  |
| ------- | ------ | ---- | :-------------------- |
| jobName | string | 是   | 需要打印的文件名。      |

**返回值：**

| 类型                 | 说明                      |
| -------------------- | ------------------------- |
| print.printDocumentAdapter | 返回打印文档的适配器。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                                    |
| -------- | -------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError, print } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('createWebPrintDocumentAdapter')
        .onClick(() => {
          try {
            let webPrintDocadapter = this.controller.createWebPrintDocumentAdapter('example.pdf');
            print.print('example_jobid', webPrintDocadapter, null, getContext());
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
### isIncognitoMode<sup>11+</sup>

isIncognitoMode(): boolean

查询当前是否是隐私模式的Webview。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                 | 说明                      |
| -------------------- | ------------------------- |
| boolean              | 返回是否是隐私模式的Webview。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                                    |
| -------- | -------------------------------------------------------------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isIncognitoMode')
        .onClick(() => {
          try {
            let result = this.controller.isIncognitoMode();
            console.log('isIncognitoMode' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
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
| [SecurityLevel](#securitylevel11) | 当前网页的安全级别，具体值为NONE、SECURE、WARNING、DANGEROUS。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onPageEnd((event) => {
          if (event) {
            let securityLevel = this.controller.getSecurityLevel();
            console.info('securityLevel: ', securityLevel);
          }
        })
    }
  }
}
```

### setScrollable<sup>12+</sup>

setScrollable(enable: boolean, type?: ScrollType): void

设置网页是否允许滚动。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ---------------------- |
| enable     | boolean   | 是   | 表示是否将网页设置为允许滚动，true表示设置为允许滚动，false表示禁止滚动。 |
| type       | [ScrollType](#scrolltype12) |  否 | 网页可触发的滚动类型，支持缺省配置。<br/> - enable为false时，表示禁止ScrollType类型的滚动，当ScrollType缺省时表示禁止所有类型网页滚动。<br/> - enable为true时，ScrollType缺省与否，都表示允许所有类型的网页滚动。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setScrollable')
        .onClick(() => {
          try {
            this.controller.setScrollable(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getScrollable<sup>12+</sup>

getScrollable(): boolean

获取当前网页是否允许滚动。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| boolean | 当前网页是否允许滚动，true为允许滚动，false为禁止滚动。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getScrollable')
        .onClick(() => {
          try {
            let scrollEnabled = this.controller.getScrollable();
            console.log("scrollEnabled: " + scrollEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setPrintBackground<sup>12+</sup>

setPrintBackground(enable: boolean): void

设置是否打印网页背景。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明                      |
| -------- | ------- | ---- | -------------------------------------- |
| enable | boolean | 是   | 表示是否打印网页背景，true表示设置为打印网页背景，false表示取消网页背景打印。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setPrintBackground')
        .onClick(() => {
          try {
            this.controller.setPrintBackground(false);
          } catch (error) {
            console.error(`ErrorCode:${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getPrintBackground<sup>12+</sup>

getPrintBackground(): boolean

查询webview是否打印网页背景。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                 | 说明                      |
| -------------------- | ------------------------- |
| boolean              | 返回Webview是否打印网页背景。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setPrintBackground')
        .onClick(() => {
          try {
            let enable = this.controller.getPrintBackground();
            console.log("getPrintBackground: " + enable);
          } catch (error) {
            console.error(`ErrorCode:${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>

getLastJavascriptProxyCallingFrameUrl(): string

通过[registerJavaScriptProxy](#registerjavascriptproxy)或者[javaScriptProxy](ts-basic-components-web.md#javascriptproxy)注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入的对象的frame的url。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
  mycontroller: webview.WebviewController;

  constructor(controller: webview.WebviewController) {
    this.mycontroller = controller;
  }

  test(testStr: string): string {
    console.log('Web Component str' + testStr + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testStr;
  }

  toString(): void {
    console.log('Web Component toString ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
  }

  testNumber(testNum: number): number {
    console.log('Web Component number' + testNum + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testNum;
  }

  testBool(testBol: boolean): boolean {
    console.log('Web Component boolean' + testBol + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testBol;
  }
}

class WebObj {
  mycontroller: webview.WebviewController;

  constructor(controller: webview.WebviewController) {
    this.mycontroller = controller;
  }

  webTest(): string {
    console.log('Web test ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return "Web test";
  }

  webString(): void {
    console.log('Web test toString ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
  }
}

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  @State testObjtest: TestObj = new TestObj(this.controller);
  @State webTestObj: WebObj = new WebObj(this.controller);

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObjtest, "objName", ["test", "toString", "testNumber", "testBool"]);
            this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
      let str=objName.test("webtest data");
      objName.testNumber(1);
      objName.testBool(true);
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

### pauseAllTimers<sup>12+</sup>

pauseAllTimers(): void

暂停所有WebView的定时器。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button('PauseAllTimers')
          .onClick(() => {
            try {
              webview.WebviewController.pauseAllTimers();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
      }
      Web({ src: $rawfile("index.html"), controller: this.controller })
    }
  }
}
```
加载的html文件。

```html
<!DOCTYPE html>
<html>
    <body>
        <button style="width:300px;height:150px;font-size:50px" onclick="startTimer()">start</button>
        <button style="width:300px;height:150px;font-size:50px" onclick="resetTimer()">reset</button>
        <input style="width:300px;height:150px;font-size:50px" value="0" id="show_num">
    </body>
</html>
<script>
    var timer = null;
    var num = 0;

    function startTimer() {
        timer = setInterval(function() {
            document.getElementById("show_num").value = ++num;
        }, 1000);
    }
</script>
```

### resumeAllTimers<sup>12+</sup>

resumeAllTimers(): void

恢复从pauseAllTimers()接口中被暂停的所有的定时器。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button('ResumeAllTimers')
          .onClick(() => {
            try {
              webview.WebviewController.resumeAllTimers();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('PauseAllTimers')
          .onClick(() => {
            try {
              webview.WebviewController.pauseAllTimers();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
      }
      Web({ src: $rawfile("index.html"), controller: this.controller })
    }
  }
}
```
加载的html文件。

```html
<!DOCTYPE html>
<html>
    <body>
        <button style="width:300px;height:150px;font-size:50px" onclick="startTimer()">start</button>
        <button style="width:300px;height:150px;font-size:50px" onclick="resetTimer()">reset</button>
        <input style="width:300px;height:150px;font-size:50px" value="0" id="show_num">
    </body>
</html>
<script>
    var timer = null;
    var num = 0;

    function startTimer() {
        timer = setInterval(function() {
            document.getElementById("show_num").value = ++num;
        }, 1000);
    }

    function resetTimer() {
        clearInterval(timer);
        document.getElementById("show_num").value = 0;
        num = 0;
    }
</script>
```

### stopAllMedia<sup>12+</sup>

stopAllMedia(): void

控制网页所有音视频停止。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('stopAllMedia')
        .onClick(() => {
          try {
            this.controller.stopAllMedia();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pauseAllMedia<sup>12+</sup>

pauseAllMedia(): void

控制网页所有音视频暂停。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('pauseAllMedia')
        .onClick(() => {
          try {
            this.controller.pauseAllMedia();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### resumeAllMedia<sup>12+</sup>

resumeAllMedia(): void

控制网页被pauseAllMedia接口暂停的音视频继续播放。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('resumeAllMedia')
        .onClick(() => {
          try {
            this.controller.resumeAllMedia();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### closeAllMediaPresentations<sup>12+</sup>

closeAllMediaPresentations(): void

控制网页所有全屏视频关闭。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('closeAllMediaPresentations')
        .onClick(() => {
          try {
            this.controller.closeAllMediaPresentations();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getMediaPlaybackState<sup>12+</sup>

getMediaPlaybackState(): MediaPlaybackState

查询当前所有音视频播控状态。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                        | 说明                                                      |
| ------------------------------------------- | --------------------------------------------------------- |
| [MediaPlaybackState](#mediaplaybackstate12) | 当前网页的播控状态，具体值为NONE、PLAYING、PAUSED、STOPPED。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getMediaPlaybackState')
        .onClick(() => {
          try {
            console.log("MediaPlaybackState : " + this.controller.getMediaPlaybackState());
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setWebSchemeHandler<sup>12+</sup>

setWebSchemeHandler(scheme: string, handler: WebSchemeHandler): void

为当前Web组件设置[WebSchemeHandler](#webschemehandler12), [WebSchemeHandler](#webschemehandler12)类用于拦截指定scheme的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | 是   | 要拦截的协议。 |
| handler    | [WebSchemeHandler](#webschemehandler12) | 是   | 拦截此协议的拦截器。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types.                                    |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

  build() {
    Column() {
      Button('setWebSchemeHandler')
        .onClick(() => {
          try {
            this.controller.setWebSchemeHandler('http', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearWebSchemeHandler<sup>12+</sup>

clearWebSchemeHandler(): void

清除当前Web组件设置的所有WebSchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearWebSchemeHandler')
        .onClick(() => {
          try {
            this.controller.clearWebSchemeHandler();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setServiceWorkerWebSchemeHandler<sup>12+</sup>

setServiceWorkerWebSchemeHandler(scheme: string, handler: WebSchemeHandler): void

为当前应用的所有Web组件设置用于拦截ServiceWorker的WebSchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | 是   | 要拦截的协议。 |
| handler    | [WebSchemeHandler](#webschemehandler12) | 是   | 拦截此协议的拦截器。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

  build() {
    Column() {
      Button('setWebSchemeHandler')
        .onClick(() => {
          try {
            webview.WebviewController.setServiceWorkerWebSchemeHandler('http', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearServiceWorkerWebSchemeHandler<sup>12+</sup>

clearServiceWorkerWebSchemeHandler(): void

清除应用中设置的所有用于拦截ServiceWorker的WebSchemeHandler。

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
      Button('clearServiceWorkerWebSchemeHandler')
        .onClick(() => {
          webview.WebviewController.clearServiceWorkerWebSchemeHandler();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### startCamera<sup>12+</sup>

startCamera(): void

开启当前网页摄像头捕获。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, PermissionRequestResult, common } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
try {
  let context: Context = getContext(this) as common.UIAbilityContext;
  atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA'], (err: BusinessError, data: PermissionRequestResult) => {
    console.info('data:' + JSON.stringify(data));
    console.info('data permissions:' + data.permissions);
    console.info('data authResults:' + data.authResults);
  })
} catch (error) {
  console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button("startCamera").onClick(() => {
        try {
          this.controller.startCamera();
        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Button("stopCamera").onClick(() => {
        try {
          this.controller.stopCamera();
        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Button("closeCamera").onClick(() => {
        try {
          this.controller.closeCamera();
        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onPermissionRequest((event) => {
          if (event) {
            AlertDialog.show({
              title: 'title',
              message: 'text',
              primaryButton: {
                value: 'deny',
                action: () => {
                  event.request.deny();
                }
              },
              secondaryButton: {
                value: 'onConfirm',
                action: () => {
                  event.request.grant(event.request.getAccessibleResource());
                }
              },
              cancel: () => {
                event.request.deny();
              }
            })
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
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
    <video id="video" width="400px" height="400px" autoplay="autoplay">
    </video>
    <input type="button" title="HTML5摄像头" value="开启摄像头" onclick="getMedia()" />
    <script>
      function getMedia() {
        let constraints = {
          video: {
            width: 500,
            height: 500
          },
          audio: true
        }
        let video = document.getElementById("video");
        let promise = navigator.mediaDevices.getUserMedia(constraints);
        promise.then(function(MediaStream) {
          video.srcObject = MediaStream;
          video.play();
        })
      }
    </script>
  </body>
</html>
 ```

### stopCamera<sup>12+</sup>

stopCamera(): void

停止当前网页摄像头捕获。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

完整示例代码参考[startCamera](#startcamera12)。

### closeCamera<sup>12+</sup>

closeCamera(): void

关闭当前网页摄像头捕获。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

完整示例代码参考[startCamera](#startcamera12)。

### precompileJavaScript<sup>12+</sup>

precompileJavaScript(url: string, script: string | Uint8Array, cacheOptions: CacheOptions): Promise\<number\>

预编译JavaScript生成字节码缓存或根据提供的参数更新已有的字节码缓存。
接口通过提供的文件信息、E-Tag响应头和Last-Modified响应头判断是否需要更新已有的字节码缓存。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                  |
| ------- | ------ | ---- | :-------------------- |
| url | string | 是   | 本地JavaScript文件对应的网络地址，即业务网页请求该文件的服务器版本时使用的网络地址。网络地址仅支持http或https协议，长度不超过2048。如果该网络地址对应的缓存失效，则业务网页将通过网络请求对应的资源。      |
| script | string \| Uint8Array | 是   | 本地JavaScript的文本内容。内容不能为空。      |
| cacheOptions | [CacheOptions](#cacheoptions12) | 是   | 用于控制字节码缓存更新。      |

**返回值：**

| 类型                                | 说明                        |
| ----------------------------------- | --------------------------- |
| Promise\<number\> | 生成字节码缓存的错误码，0表示无错误，-1表示内部错误。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

接口推荐配合动态组件使用，使用离线的Web组件用于生成字节码缓存，并在适当的时机加载业务用Web组件使用这些字节码缓存。下方是代码示例：

1. 首先，在EntryAbility中将UIContext存到localStorage中。

   ```ts
   // EntryAbility.ets
   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';

   const localStorage: LocalStorage = new LocalStorage('uiContext');

   export default class EntryAbility extends UIAbility {
     storage: LocalStorage = localStorage;

     onWindowStageCreate(windowStage: window.WindowStage) {
       windowStage.loadContent('pages/Index', this.storage, (err, data) => {
         if (err.code) {
           return;
         }

         this.storage.setOrCreate<UIContext>("uiContext", windowStage.getMainWindowSync().getUIContext());
       });
     }
   }
   ```

2. 编写动态组件所需基础代码。

   ```ts
   // DynamicComponent.ets
   import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

   export interface BuilderData {
     url: string;
     controller: WebviewController;
   }

   const storage = LocalStorage.getShared();

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>) {
       super();
       this.wrappedBuilder = wrappedBuilder;
     }

     makeNode(): FrameNode | null {
       if (this.rootNode != null) {
         return this.rootNode.getFrameNode();
       }
       return null;
     }

     initWeb(url: string, controller: WebviewController) {
       if(this.rootNode != null) {
         return;
       }

       const uiContext: UIContext = storage.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder);
     baseNode.initWeb(data.url, data.controller);
     return baseNode;
   }
   ```

3. 编写用于生成字节码缓存的组件，本例中的本地Javascript资源内容通过文件读取接口读取rawfile目录下的本地文件。

   <!--code_no_check-->
   ```ts
   // PrecompileWebview.ets
   import { BuilderData } from "./DynamicComponent";
   import { Config, configs } from "./PrecompileConfig";

   @Builder
   function WebBuilder(data: BuilderData) {
     Web({ src: data.url, controller: data.controller })
       .onControllerAttached(() => {
         precompile(data.controller, configs);
       })
       .fileAccess(true)
   }

   export const precompileWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export const precompile = async (controller: WebviewController, configs: Array<Config>) => {
     for (const config of configs) {
       let content = await readRawFile(config.localPath);

       try {
         controller.precompileJavaScript(config.url, content, config.options)
           .then(errCode => {
             console.error("precompile successfully! " + errCode);
           }).catch((errCode: number) => {
             console.error("precompile failed. " + errCode);
         });
       } catch (err) {
         console.error("precompile failed. " + err.code + " " + err.message);
       }
     }
   }

   async function readRawFile(path: string) {
     try {
       return await getContext().resourceManager.getRawFileContent(path);;
     } catch (err) {
       return new Uint8Array(0);
     }
   }
   ```

JavaScript资源的获取方式也可通过[网络请求](../apis-network-kit/js-apis-http.md)的方式获取，但此方法获取到的http响应头非标准HTTP响应头格式，需额外将响应头转换成标准HTTP响应头格式后使用。如通过网络请求获取到的响应头是e-tag，则需要将其转换成E-Tag后使用。

4. 编写业务用组件代码。

   <!--code_no_check-->
   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // 此处组件可根据业务需要自行扩展
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. 编写资源配置信息。

   ```ts
   // PrecompileConfig.ets
   import { webview } from '@kit.ArkWeb'

   export interface Config {
     url:  string,
     localPath: string, // 本地资源路径
     options: webview.CacheOptions
   }

   export let configs: Array<Config> = [
     {
       url: "https://www.example.com/example.js",
       localPath: "example.js",
       options: {
         responseHeaders: [
           { headerKey: "E-Tag", headerValue: "aWO42N9P9dG/5xqYQCxsx+vDOoU="},
           { headerKey: "Last-Modified", headerValue: "Wed, 21 Mar 2024 10:38:41 GMT"}
         ]
       }
     }
   ]
   ```

6. 在页面中使用。

   <!--code_no_check-->
   ```ts
   // Index.ets
   import { webview } from '@kit.ArkWeb';
   import { NodeController } from '@kit.ArkUI';
   import { createNode } from "./DynamicComponent"
   import { precompileWebview } from "./PrecompileWebview"
   import { businessWebview } from "./BusinessWebview"

   @Entry
   @Component
   struct Index {
     @State precompileNode: NodeController | undefined = undefined;
     precompileController: webview.WebviewController = new webview.WebviewController();

     @State businessNode: NodeController | undefined = undefined;
     businessController: webview.WebviewController = new webview.WebviewController();

     aboutToAppear(): void {
       // 初始化用于注入本地资源的Web组件
       this.precompileNode = createNode(precompileWebview,
         { url: "https://www.example.com/empty.html", controller: this.precompileController});
     }

     build() {
       Column() {
         // 在适当的时机加载业务用Web组件，本例以Button点击触发为例
         Button("加载页面")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url:  "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // 用于业务的Web组件
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

当需要更新本地已经生成的编译字节码时，修改cacheOptions参数中responseHeaders中的E-Tag或Last-Modified响应头对应的值，再次调用接口即可。

### onCreateNativeMediaPlayer<sup>12+</sup>

onCreateNativeMediaPlayer(callback: CreateNativeMediaPlayerCallback): void

注册回调函数，开启[应用接管网页媒体播放功能](ts-basic-components-web.md#enablenativemediaplayer12)后，当网页中有播放媒体时，触发注册的回调函数。
如果应用接管网页媒体播放功能未开启，则注册的回调函数不会被触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| callback | [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) | 是 | 接管网页媒体播放的回调函数。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

class ActualNativeMediaPlayerListener {
  handler: webview.NativeMediaPlayerHandler;

  constructor(handler: webview.NativeMediaPlayerHandler) {
    this.handler = handler;
  }

  onPlaying() {
    // 本地播放器开始播放。
    this.handler.handleStatusChanged(webview.PlaybackStatus.PLAYING);
  }
  onPaused() {
    // 本地播放器暂停播放。
    this.handler.handleStatusChanged(webview.PlaybackStatus.PAUSED);
  }
  onSeeking() {
    // 本地播放器开始执行跳转到目标时间点。
    this.handler.handleSeeking();
  }
  onSeekDone() {
    // 本地播放器 seek 完成。
    this.handler.handleSeekFinished();
  }
  onEnded() {
    // 本地播放器播放完成。
    this.handler.handleEnded();
  }
  onVolumeChanged() {
    // 获取本地播放器的音量。
    let volume: number = getVolume();
    this.handler.handleVolumeChanged(volume);
  }
  onCurrentPlayingTimeUpdate() {
    // 更新播放时间。
    let currentTime: number = getCurrentPlayingTime();
    // 将时间单位换算成秒。
    let currentTimeInSeconds = convertToSeconds(currentTime);
    this.handler.handleTimeUpdate(currentTimeInSeconds);
  }
  onBufferedChanged() {
    // 缓存发生了变化。
    // 获取本地播放器的缓存时长。
    let bufferedEndTime: number = getCurrentBufferedTime();
    // 将时间单位换算成秒。
    let bufferedEndTimeInSeconds = convertToSeconds(bufferedEndTime);
    this.handler.handleBufferedEndTimeChanged(bufferedEndTimeInSeconds);

    // 检查缓存状态。
    // 如果缓存状态发生了变化，则向 ArkWeb 内核通知缓存状态。
    let lastReadyState: webview.ReadyState = getLastReadyState();
    let currentReadyState:  webview.ReadyState = getCurrentReadyState();
    if (lastReadyState != currentReadyState) {
      this.handler.handleReadyStateChanged(currentReadyState);
    }
  }
  onEnterFullscreen() {
    // 本地播放器进入了全屏状态。
    let isFullscreen: boolean = true;
    this.handler.handleFullscreenChanged(isFullscreen);
  }
  onExitFullscreen() {
    // 本地播放器退出了全屏状态。
    let isFullscreen: boolean = false;
    this.handler.handleFullscreenChanged(isFullscreen);
  }
  onUpdateVideoSize(width: number, height: number) {
    // 当本地播放器解析出视频宽高时， 通知 ArkWeb 内核。
    this.handler.handleVideoSizeChanged(width, height);
  }
  onDurationChanged(duration: number) {
    // 本地播放器解析到了新的媒体时长， 通知 ArkWeb 内核。
    this.handler.handleDurationChanged(duration);
  }
  onError(error: webview.MediaError, errorMessage: string) {
    // 本地播放器出错了，通知 ArkWeb 内核。
    this.handler.handleError(error, errorMessage);
  }
  onNetworkStateChanged(state: webview.NetworkState) {
    // 本地播放器的网络状态发生了变化， 通知 ArkWeb 内核。
    this.handler.handleNetworkStateChanged(state);
  }
  onPlaybackRateChanged(playbackRate: number) {
    // 本地播放器的播放速率发生了变化， 通知 ArkWeb 内核。
    this.handler.handlePlaybackRateChanged(playbackRate);
  }
  onMutedChanged(muted: boolean) {
    // 本地播放器的静音状态发生了变化， 通知 ArkWeb 内核。
    this.handler.handleMutedChanged(muted);
  }

  // ... 监听本地播放器其他的状态 ...
}

class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
  constructor(handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {
    // 1. 创建一个本地播放器的状态监听。
    let listener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
    // 2. 创建一个本地播放器。
    // 3. 监听该本地播放器。
    // ...
  }

  updateRect(x: number, y: number, width: number, height: number) {
    // <video> 标签的位置和大小发生了变化。
    // 根据该信息变化，作出相应的改变。
  }

  play() {
    // 启动本地播放器播放。
  }

  pause() {
    // 暂停本地播放器播放。
  }

  seek(targetTime: number) {
    // 本地播放器跳转到指定的时间点。
  }

  release() {
    // 销毁本地播放器。
  }

  setVolume(volume: number) {
    // ArkWeb 内核要求调整本地播放器的音量。
    // 设置本地播放器的音量。
  }

  setMuted(muted: boolean) {
    // 将本地播放器静音或取消静音。
  }

  setPlaybackRate(playbackRate: number) {
    // 调整本地播放器的播放速度。
  }

  enterFullscreen() {
    // 将本地播放器设置为全屏播放。
  }

  exitFullscreen() {
    // 将本地播放器退出全屏播放。
  }

  resumePlayer() {
    // 重新创建应用内播放器。
    // 恢复应用内播放器的状态信息。
  }

  suspendPlayer(type: webview.SuspendType) {
    // 记录应用内播放器的状态信息。
    // 销毁应用内播放器。
  }
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController()
  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .enableNativeMediaPlayer({enable: true, shouldOverlay: false})
        .onPageBegin((event) => {
          this.controller.onCreateNativeMediaPlayer((handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) => {
            if (!shouldHandle(mediaInfo)) {
              // 本地播放器不接管该媒体。
              // ArkWeb 内核将用自己的播放器来播放该媒体。
              return null;
            }
            let nativePlayer: webview.NativeMediaPlayerBridge = new NativeMediaPlayerImpl(handler, mediaInfo);
            return nativePlayer;
          });
        })
    }
  }
}

// stub
function getVolume() {
  return 1;
}
function getCurrentPlayingTime() {
  return 1;
}
function getCurrentBufferedTime() {
  return 1;
}
function convertToSeconds(input: number) {
  return input;
}
function getLastReadyState() {
  return webview.ReadyState.HAVE_NOTHING;
}
function getCurrentReadyState() {
  return webview.ReadyState.HAVE_NOTHING;
}
function shouldHandle(mediaInfo: webview.MediaInfo) {
  return true;
}
```

### enableWholeWebPageDrawing<sup>12+</sup>

static enableWholeWebPageDrawing(): void

设置开启网页全量绘制能力。仅在web初始化时设置。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear(): void {
    try {
      webview.WebviewController.enableWholeWebPageDrawing();
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### webPageSnapshot<sup>12+</sup>

webPageSnapshot(info: SnapshotInfo, callback: AsyncCallback\<SnapshotResult>): void

获取网页全量绘制结果。（本地资源网页暂不支持）

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型           | 必填  | 说明                      |
| ----------- | ------------- | ---- | ------------------------ |
| info        | [SnapshotInfo](#snapshotinfo12)| 是   | 全量绘制结果入参。 |
| callback        | [SnapshotResult](#snapshotresult12)| 是   | 全量绘制回调结果。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('webPageSnapshot')
        .onClick(() => {
          try {
            this.controller.webPageSnapshot({ id: "1234", size: { width: 100, height: 100 } }, (error, result) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              if (result) {
                console.info(`return value is:${result}`);
                //开发者可以根据需要处理返回结果
              }
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### injectOfflineResources<sup>12+</sup>

injectOfflineResources(resourceMaps: Array\<[OfflineResourceMap](#offlineresourcemap12)\>): void

将本地离线资源注入到内存缓存中，以提升页面首次启动速度。
内存缓存中的资源由内核自动管理，当注入的资源过多导致内存压力过大，内核自动释放未使用的资源，应避免注入大量资源到内存缓存中。
正常情况下，资源的有效期由提供的Cache-Control或Expires响应头控制其有效期，默认的有效期为86400秒，即1天。
资源的MIMEType通过提供的Content-Type响应头配置，Content-Type需符合标准，否则无法正常使用，MODULE_JS必须提供有效的MIMEType，其他类型可不提供。
以此方式注入的资源，仅支持通过HTML中的标签加载。如果业务网页中的script标签使用了crossorigin属性，则必须在接口的responseHeaders参数中设置Cross-Origin响应头的值为anoymous或use-credentials。
当调用`webview.WebviewController.SetRenderProcessMode(webview.RenderProcessMode.MULTIPLE)`接口后，应用会启动多渲染进程模式，此接口在此场景下不会生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                  |
| ------- | ------ | ---- | :-------------------- |
| resourceMaps | Array\<[OfflineResourceMap](#offlineresourcemap12)\> | 是   | 本地离线资源配置对象，单次调用最大支持注入30个资源，单个资源最大支持10Mb。      |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**示例：**

接口推荐配合动态组件使用，使用离线的Web组件用于将资源注入到内核的内存缓存中，并在适当的时机加载业务用Web组件使用这些资源。下方是代码示例：
1. 首先，在EntryAbility中将UIContext存到localStorage中。

   ```ts
   // EntryAbility.ets
   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';

   const localStorage: LocalStorage = new LocalStorage('uiContext');

   export default class EntryAbility extends UIAbility {
     storage: LocalStorage = localStorage;

     onWindowStageCreate(windowStage: window.WindowStage) {
       windowStage.loadContent('pages/Index', this.storage, (err, data) => {
         if (err.code) {
           return;
         }

         this.storage.setOrCreate<UIContext>("uiContext", windowStage.getMainWindowSync().getUIContext());
       });
     }
   }
   ```

2. 编写动态组件所需基础代码。

   ```ts
   // DynamicComponent.ets
   import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

   export interface BuilderData {
     url: string;
     controller: WebviewController;
   }

   const storage = LocalStorage.getShared();

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>) {
       super();
       this.wrappedBuilder = wrappedBuilder;
     }

     makeNode(): FrameNode | null {
       if (this.rootNode != null) {
         return this.rootNode.getFrameNode();
       }
       return null;
     }

     initWeb(url: string, controller: WebviewController) {
       if(this.rootNode != null) {
         return;
       }

       const uiContext: UIContext = storage.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder);
     baseNode.initWeb(data.url, data.controller);
     return baseNode;
   }
   ```

3. 编写用于注入资源的组件代码，本例中的本地资源内容通过文件读取接口读取rawfile目录下的本地文件。

   <!--code_no_check-->
   ```ts
   // InjectWebview.ets
   import { webview } from '@kit.ArkWeb';
   import { resourceConfigs } from "./Resource";
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     Web({ src: data.url, controller: data.controller })
       .onControllerAttached(async () => {
         try {
           data.controller.injectOfflineResources(await getData ());
         } catch (err) {
           console.error("error: " + err.code + " " + err.message);
         }
       })
       .fileAccess(true)
   }

   export const injectWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export async function getData() {
     const resourceMapArr: Array<webview.OfflineResourceMap> = [];

     // 读取配置，从rawfile目录中读取文件内容
     for (let config of resourceConfigs) {
       let buf: Uint8Array = new Uint8Array(0);
       if (config.localPath) {
         buf = await readRawFile(config.localPath);
       }

       resourceMapArr.push({
         urlList: config.urlList,
         resource: buf,
         responseHeaders: config.responseHeaders,
         type: config.type,
       })
     }

     return resourceMapArr;
   }

   export async function readRawFile(url: string) {
     try {
       return await getContext().resourceManager.getRawFileContent(url);
     } catch (err) {
       return new Uint8Array(0);
     }
   }
   ```

4. 编写业务用组件代码。

   <!--code_no_check-->
   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // 此处组件可根据业务需要自行扩展
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. 编写资源配置信息。

   ```ts
   // Resource.ets
   import { webview } from '@kit.ArkWeb';

   export interface ResourceConfig {
     urlList: Array<string>,
     type: webview.OfflineResourceType,
     responseHeaders: Array<Header>,
     localPath: string, // 本地资源存放在rawfile目录下的路径
   }

   export const resourceConfigs: Array<ResourceConfig> = [
     {
       localPath: "example.png",
       urlList: [
         "https://www.example.com/",
         "https://www.example.com/path1/example.png",
         "https://www.example.com/path2/example.png",
       ],
       type: webview.OfflineResourceType.IMAGE,
       responseHeaders: [
         { headerKey: "Cache-Control", headerValue: "max-age=1000" },
         { headerKey: "Content-Type", headerValue: "image/png" },
       ]
     },
     {
       localPath: "example.js",
       urlList: [ // 仅提供一个url，这个url既作为资源的源，也作为资源的网络请求地址
         "https://www.example.com/example.js",
       ],
       type: webview.OfflineResourceType.CLASSIC_JS,
       responseHeaders: [
         // 以<script crossorigin="anoymous" />方式使用，提供额外的响应头
         { headerKey: "Cross-Origin", headerValue:"anonymous" }
       ]
     },
   ];
   ```

6. 在页面中使用。
   <!--code_no_check-->
   ```ts
   // Index.ets
   import { webview } from '@kit.ArkWeb';
   import { NodeController } from '@kit.ArkUI';
   import { createNode } from "./DynamicComponent"
   import { injectWebview } from "./InjectWebview"
   import { businessWebview } from "./BusinessWebview"

   @Entry
   @Component
   struct Index {
     @State injectNode: NodeController | undefined = undefined;
     injectController: webview.WebviewController = new webview.WebviewController();

     @State businessNode: NodeController | undefined = undefined;
     businessController: webview.WebviewController = new webview.WebviewController();

     aboutToAppear(): void {
       // 初始化用于注入本地资源的Web组件, 提供一个空的html页面作为url即可
       this.injectNode = createNode(injectWebview,
           { url: "https://www.example.com/empty.html", controller: this.injectController});
     }

     build() {
       Column() {
         // 在适当的时机加载业务用Web组件，本例以Button点击触发为例
         Button("加载页面")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url: "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // 用于业务的Web组件
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

7. 加载的HTML网页示例。

   ```HTML
   <!DOCTYPE html>
   <html lang="en">
   <head></head>
   <body>
     <img src="https://www.example.com/path1/request.png" />
     <img src="https://www.example.com/path2/request.png" />
     <script src="https://www.example.com/example.js" crossorigin="anonymous"></script>
   </body>
   </html>
   ```

### setHostIP<sup>12+</sup>

static setHostIP(hostName: string, address: string, aliveTime: number): void

设置主机域名解析后的IP地址。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型 | 必填 | 说明                             |
| --------- | -------- | ---- | ------------------------------------ |
| hostName  | string   | 是   | 要添加DNS记录的主机域名。            |
| address   | string   | 是   | 主机域名解析地址（支持IPv4，IPv6）。 |
| aliveTime | number   | 是   | 缓存有效时间（秒）。                 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |

**示例：**

请参考[clearHostIP](#clearhostip12)。

### clearHostIP<sup>12+</sup>

static clearHostIP(hostName: string): void

清除指定主机域名解析后的IP地址。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明                  |
| -------- | -------- | ---- | ------------------------- |
| hostName | string   | 是   | 要清除DNS记录的主机域名。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      // url加载前设置生效.
      Button('setHostIP')
        .onClick(() => {
          try {
            webview.WebviewController.setHostIP('www.example.com', '127.0.0.1', 30);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('clearHostIP')
        .onClick(() => {
          try {
            webview.WebviewController.clearHostIP('www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getSurfaceId<sup>12+</sup>

getSurfaceId(): string

获取ArkWeb对应Surface的ID，仅Web组件渲染模式是ASYNC_RENDER时有效。getSurfaceId需要在Web组件初始化之后才能获取到值。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                |
| ------ | ------------------- |
| string | ArkWeb持有Surface的ID。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Example{
  controller: webview.WebviewController = new webview.WebviewController();

  @State imagePixelMap: image.PixelMap | undefined = undefined;

  build(){
    Column(){
      Button("截图")
        .onClick(()=>{
          try {
            let surfaceId = this.controller.getSurfaceId();
            console.log("surfaceId: " + surfaceId);
            if(surfaceId.length != 0) {
              let region:image.Region = { x: 0, y: 0, size: { height: 800, width: 1000}}
              this.imagePixelMap = image.createPixelMapFromSurfaceSync(surfaceId, region)
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Image(this.imagePixelMap)
        .height(100)
      Web({src: 'www.example.com', controller: this.controller})
    }
  }
}
```

### setUrlTrustList<sup>12+</sup>

setUrlTrustList(urlTrustList: string): void

设置当前web的url白名单，只有白名单内的url才能允许加载/跳转，否则将拦截并弹出告警页。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                  |
| ------- | ------ | ---- | :-------------------- |
| urlTrustList | string | 是   | url白名单列表，使用json格式配置，最大支持10MB。<br/>白名单设置接口为覆盖方式，多次调用接口时，以最后一次设置为准。<br/>当本参数为空字符串时，表示取消白名单，放行所有url的访问。<br/>json格式示例：<br/>{<br>&nbsp;&nbsp;"UrlPermissionList":&nbsp;[<br/>&nbsp;&nbsp;&nbsp;&nbsp;{<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"scheme":&nbsp;"https",<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"host":&nbsp;"www\.example1.com",<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"port":&nbsp;443,<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"path":&nbsp;"pathA/pathB"<br/>&nbsp;&nbsp;&nbsp;&nbsp;},<br/>&nbsp;&nbsp;&nbsp;&nbsp;{<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"scheme":&nbsp;"http",<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"host":&nbsp;"www\.example2.com",<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"port":&nbsp;80,<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"path":&nbsp;"test1/test2/test3"<br/>&nbsp;&nbsp;&nbsp;&nbsp;}<br/>&nbsp;&nbsp;]<br/>} |

**白名单json格式参数**
| 字段   | 参数类型 | 必填 | 参数描述                  |
| -------- | -------- | ---- | ------------------------- |
| scheme | string   | 否 | 可选参数，不设置即不匹配该项，支持协议：http、https。 |
| host | string | 是 | 必选参数，精准匹配，即url的host字段和规则字段完全一致才会放行，可允许同一host多条规则同时生效。 |
| port | number | 否 | 可选字段，不设置即不匹配该项。 |
| path | string | 否 | 可选字段，不设置即不匹配该项，匹配方式为前缀匹配，以"pathA/pathB/pathC"为例：pathA/pathB/pathC三级目录下全部允许访问，其中pathC必须是完整的目录名或者文件名，不允许部分匹配。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Parameter string is too long.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    urltrustList: string = "{\"UrlPermissionList\":[{\"scheme\":\"http\", \"host\":\"trust.example.com\", \"port\":80, \"path\":\"test\"}]}"

    build() {
      Column() {
        Button('Setting the trustlist')
          .onClick(() => {
            try {
              // 设置白名单，只允许访问trust网页
              this.controller.setUrlTrustList(this.urltrustList);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Cancel the trustlist.')
          .onClick(() => {
            try {
              // 白名单传入空字符串表示关闭白名单机制，所有url都可以允许访问
              this.controller.setUrlTrustList("");
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Access the trust web')
          .onClick(() => {
            try {
              // 白名单生效，可以访问trust网页
              this.controller.loadUrl('http://trust.example.com/test');
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Access the untrust web')
          .onClick(() => {
            try {
              // 白名单生效，此时不可以访问untrust网页，并弹出错误页
              this.controller.loadUrl('http://untrust.example.com/test');
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'http://untrust.example.com/test', controller: this.controller }).onControllerAttached(() => {
          try {
            // onControllerAttached回调中设置白名单，可以保证在加载url之前生效，此时不可以访问untrust网页，并弹出错误页
            this.controller.setUrlTrustList(this.urltrustList);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      }
    }
  }
  ```

### setPathAllowingUniversalAccess<sup>12+</sup>

setPathAllowingUniversalAccess(pathList: Array\<string\>): void

设置一个路径列表，当file协议访问该路径列表中的资源时，允许跨域访问本地文件。此外，当设置了路径列表时，file协议仅允许访问路径列表中的资源（[fileAccess](ts-basic-components-web.md#fileAccess)的行为将会被此接口行为覆盖）。路径列表中的路径必须满足以下路径格式之一：

1.应用文件目录的子目录（应用文件目录通过Ability Kit中的[Context.filesDir](../apis-ability-kit/js-apis-inner-application-context.md#context)获取），例如：

* /data/storage/el2/base/files/example
* /data/storage/el2/base/haps/entry/files/example

2.应用资源目录及其子目录（应用资源目录通过Ability Kit中的[Context.resourceDir](../apis-ability-kit/js-apis-inner-application-context.md#context)获取），例如：

* /data/storage/el1/bundle/entry/resource/resfile
* /data/storage/el1/bundle/entry/resource/resfile/example

当路径列表中有其中一个路径不满足以上条件之一，则会抛出异常码401，并且设置路径列表失败。当设置的路径列表为空，则file协议可访问范围以[fileAccess](ts-basic-components-web.md#fileAccess)的行为为准。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明                  |
| -------- | -------- | ---- | ------------------------- |
| pathList | Array\<string\>   | 是   | 路径列表 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Web({ src: "", controller: this.controller })
        .onControllerAttached(() => {
          try {
            // 设置允许可以跨域访问的路径列表
            this.controller.setPathAllowingUniversalAccess([
              getContext().resourceDir,
              getContext().filesDir + "/example"
            ])
            this.controller.loadUrl("file://" + getContext().resourceDir + "/index.html")
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .fileAccess(true)
        .domStorageAccess(true)
    }
  }
}

```

加载的html文件，位于应用资源目录resource/resfile/index.html。
```html
<!-- index.html -->
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Demo</title>
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no, viewport-fit=cover">
    <script>
		function getFile() {
			var file = "file:///data/storage/el1/bundle/entry/resources/resfile/js/script.js";
			var xmlHttpReq = new XMLHttpRequest();
			xmlHttpReq.onreadystatechange = function(){
			    console.log("readyState:" + xmlHttpReq.readyState);
			    console.log("status:" + xmlHttpReq.status);
				if(xmlHttpReq.readyState == 4){
				    if (xmlHttpReq.status == 200) {
                // 如果ets侧正确设置路径列表，则此处能正常获取资源
				        const element = document.getElementById('text');
                        element.textContent = "load " + file + " success";
				    } else {
                // 如果ets侧不设置路径列表，则此处会触发CORS跨域检查错误
				        const element = document.getElementById('text');
                        element.textContent = "load " + file + " failed";
				    }
				}
			}
			xmlHttpReq.open("GET", file);
			xmlHttpReq.send(null);
		}

    </script>
</head>

<body>
<div class="page">
    <button id="example" onclick="getFile()">stealFile</button>
</div>
<div id="text"></div>
</body>

</html>
```

html中使用file协议通过XMLHttpRequest跨域访问本地js文件，js文件位于resource/resfile/js/script.js。
<!--code_no_check-->
```javascript
const body = document.body;
const element = document.createElement('div');
element.textContent = 'success';
body.appendChild(element);
```

### enableBackForwardCache<sup>12+</sup>

static enableBackForwardCache(features: BackForwardCacheSupportedFeatures): void

开启Web组件前进后退缓存功能，通过参数指定是否允许使用特定的页面进入前进后退缓存。

需要在[initializeWebEngine()](#initializewebengine)初始化内核之前调用。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| features     |  [BackForwardCacheSupportedFeatures](#backforwardcachesupportedfeatures12) | 是   | 允许使用特定的页面进入前进后退缓存中。|

**示例：**

```ts
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        let features = new webview.BackForwardCacheSupportedFeatures();
        features.nativeEmbed = true;
        features.mediaTakeOver = true;
        // 如果一个页面同时使用了同层渲染和视频托管的能力，需要 nativeEmbed 和
        // mediaTakeOver 同时设置为 true，该页面才可以进入前进后退缓存中。
        webview.WebviewController.enableBackForwardCache(features);
        webview.WebviewController.initializeWebEngine();
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

### setBackForwardCacheOptions<sup>12+</sup>

setBackForwardCacheOptions(options: BackForwardCacheOptions): void

可以设置Web组件中前进后退缓存的相关选项。

**系统能力：**  SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| options     |  [BackForwardCacheOptions](#backforwardcacheoptions12) | 是   | 用来控制web组件前进后退缓存相关选项。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button("Add options").onClick((event: ClickEvent) => {
          let options = new webview.BackForwardCacheOptions();
          options.size = 3;
          options.timeToLive = 10;
          this.controller.setBackForwardCacheOptions(options);
        })
        Button("Backward").onClick((event: ClickEvent) => {
          this.controller.backward();
        })
        Button("Forward").onClick((event: ClickEvent) => {
          this.controller.forward();
        })
      }
      Web({ src: "https://www.example.com", controller: this.controller })
    }
    .height('100%')
    .width('100%')
  }
}
```

### trimMemoryByPressureLevel<sup>14+</sup>

trimMemoryByPressureLevel(level: number): void

根据指定的内存压力等级，主动清理Web组件占用的缓存。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                  |
| ------- | ------ | ---- | :-------------------- |
| level | [PressureLevel](#pressurelevel14) | 是 | 需要清理内存的内存等级。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Parameter string is too long.3. Parameter verification failed. |

**示例：**
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: WebviewController = new webview.WebviewController();
  build() {
    Column() {
      Row() {
        Button('trim_Memory')
          .onClick(() => {
            try {
              // 设置当前内存压力等级为适中，释放少量内存
              webview.WebviewController.trimMemoryByPressureLevel(
                webview.PressureLevel.MEMORY_PRESSURE_LEVEL_MODERATE);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
      }.height('10%')
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### createPdf<sup>14+</sup>

createPdf(configuration: PdfConfiguration, callback: AsyncCallback\<PdfData\>): void

异步callback方式获取指定网页的数据流。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                    |
| ------------- | --------------------------------------- | ---- | ----------------------- |
| configuration | [PdfConfiguration](#pdfconfiguration14) | 是   | 生成PDF所需参数。       |
| callback      | AsyncCallback<[PdfData](#pdfdata14)>    | 是   | 回调返回网页PDF数据流。 |

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: Incorrect parameter types. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例**:

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }

  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          this.controller.createPdf(
            this.pdfConfig,
            (error, result: webview.PdfData) => {
              try {
                // 获取组件上下文
                let context = getContext(this) as common.UIAbilityContext;
                // 获取沙箱路径，设置pdf文件名
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            });
        })
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

### createPdf<sup>14+</sup>

createPdf(configuration: PdfConfiguration): Promise\<PdfData\>

以Promise方式异步获取指定网页的数据流。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                    | 必填 | 说明              |
| ------------- | --------------------------------------- | ---- | ----------------- |
| configuration | [PdfConfiguration](#pdfconfiguration14) | 是   | 生成PDF所需参数。 |

**返回值：**

| 类型                           | 说明                          |
| ------------------------------ | ----------------------------- |
| Promise<[PdfData](#pdfdata14)> | Promise实例，返回网页数据流。 |

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: Incorrect parameter types. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例**:

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }

  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          this.controller.createPdf(this.pdfConfig)
            .then((result: webview.PdfData) => {
              try {
                // 获取组件上下文
                let context = getContext(this) as common.UIAbilityContext;
                // 获取沙箱路径，设置pdf文件名
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            })
        })
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

### getScrollOffset<sup>13+</sup>

getScrollOffset(): ScrollOffset

获取网页当前的滚动偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值**

| 类型                            | 说明                   |
| :------------------------------ | ---------------------- |
| [ScrollOffset](#scrolloffset13) | 网页当前的滚动偏移量。 |

**示例：**

```ts
import { webview } from '@kit.ArkWeb';
import { componentUtils } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  @State testTitle: string = 'webScroll'
  controller: webview.WebviewController = new webview.WebviewController();
  @State controllerX: number =-100;
  @State controllerY: number =-100;
  @State mode: OverScrollMode = OverScrollMode.ALWAYS;

  build() {
    Column() {
      Row() {
        Text(this.testTitle)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .margin(5)
      }
      Column() {
        Text(`controllerX: ${this.controllerX}, controllerY: ${this.controllerY}`)
      }
      .margin({ top: 10, bottom: 10 })
      Web({ src: $rawfile("scrollByTo.html"), controller: this.controller })
        .key("web_01")
        .overScrollMode(this.mode)
        .onTouch((event) => {
          this.controllerX = this.controller.getScrollOffset().x;
          this.controllerY = this.controller.getScrollOffset().y;
          let componentInfo = componentUtils.getRectangleById("web_01");
          let webHeight = px2vp(componentInfo.size.height);
          let pageHeight = this.controller.getPageHeight();
          if (this.controllerY < 0) {
            // case1：网页向下过滚动时，可直接使用ScrollOffset.y
            console.log(`get downwards overscroll offsetY = ${this.controllerY}`);
          } else if ((this.controllerY != 0) && (this.controllerY > (pageHeight - webHeight))) {
            // case2：网页向上过滚动时，需计算出网页下边界与Web组件下边界的偏移量
            console.log(`get upwards overscroll offsetY = ${this.controllerY - (pageHeight >= webHeight ? (pageHeight - webHeight) : 0)}`);
          } else {
            // case3：网页未发生过滚动时，可直接使用ScrollOffset.y
            console.log(`get scroll offsetY = ${this.controllerY}`);
          }
        })
        .height(600)
    }
    .width('100%')
    .height('100%')
  }
}
```

## WebCookieManager

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有Web组件共享一个WebCookieManager实例。

### getCookie<sup>(deprecated)</sup>

static getCookie(url: string): string

获取指定url对应cookie的值。

> **说明：**
>
> 从API version9开始支持，从API version 11开始废弃。建议使用[fetchCookieSync](#fetchcookiesync11)替代

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getCookie')
        .onClick(() => {
          try {
            let value = webview.WebCookieManager.getCookie('https://www.example.com');
            console.log("value: " + value);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### fetchCookieSync<sup>11+</sup>

static fetchCookieSync(url: string, incognito?: boolean): string

获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 否   | true表示获取隐私模式下webview的内存cookies，false表示正常非隐私模式下的cookies。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookieSync')
        .onClick(() => {
          try {
            let value = webview.WebCookieManager.fetchCookieSync('https://www.example.com');
            console.log("fetchCookieSync cookie = " + value);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com', (error, cookie) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              if (cookie) {
                console.log('fetchCookie cookie = ' + cookie);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com')
              .then(cookie => {
                console.log("fetchCookie cookie = " + cookie);
              })
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### fetchCookie<sup>14+</sup>

static fetchCookie(url: string, incognito: boolean): Promise\<string>

以Promise方式异步获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 是   | true表示获取隐私模式下webview的内存cookies，false表示正常非隐私模式下的cookies。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<string> | Promise实例，用于获取指定url对应的cookie值。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com', false)
              .then(cookie => {
                console.log("fetchCookie cookie = " + cookie);
              })
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
> 从API version9开始支持，从API version 11开始废弃。建议使用[configCookieSync<sup>11+</sup>](#configcookiesync11)替代

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('setCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.setCookie('https://www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookieSync<sup>11+</sup>

static configCookieSync(url: string, value: string, incognito?: boolean): void

为指定url设置cookie的值。

> **说明：**
>
>configCookie中的url，可以指定域名的方式来使得页面内请求也附带上cookie。

>同步cookie的时机建议在Web组件加载之前完成。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 否   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookieSync')
        .onClick(() => {
          try {
            // 仅支持设置单个cookie值。
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookieSync<sup>14+</sup>

static configCookieSync(url: string, value: string, incognito: boolean, includeHttpOnly: boolean): void

为指定url设置cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 是   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。 |
| includeHttpOnly    | boolean | 是   | true表示允许覆盖含有http-only的cookies，false表示不允许覆盖含有http-only的cookies。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookieSync')
        .onClick(() => {
          try {
            // 仅支持设置单个cookie值。
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b', false, false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', "a=b", (error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', 'a=b')
              .then(() => {
                console.log('configCookie success!');
              })
              .catch((error: BusinessError) => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### configCookie<sup>14+</sup>

static configCookie(url: string, value: string, incognito: boolean, includeHttpOnly: boolean): Promise\<void>

以异步Promise方式为指定url设置单个cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 是   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。 |
| includeHttpOnly    | boolean | 是   | true表示允许覆盖含有http-only的cookies，false表示不允许覆盖含有http-only的cookies。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<void> | Promise实例，用于获取指定url设置单个cookie值是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', 'a=b', false, false)
              .then(() => {
                console.log('configCookie success!');
              })
              .catch((error: BusinessError) => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            webview.WebCookieManager.saveCookieAsync((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            webview.WebCookieManager.saveCookieAsync()
              .then(() => {
                console.log("saveCookieAsyncCallback success!");
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| accept | boolean | 是   | 设置是否拥有发送和接收cookie的权限，默认为true。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptCookieEnabled')
        .onClick(() => {
          try {
            webview.WebCookieManager.putAcceptCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isCookieAllowed')
        .onClick(() => {
          let result = webview.WebCookieManager.isCookieAllowed();
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
| accept | boolean | 是   | 设置是否拥有发送和接收第三方cookie的权限，默认为false。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptThirdPartyCookieEnabled')
        .onClick(() => {
          try {
            webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isThirdPartyCookieAllowed')
        .onClick(() => {
          let result = webview.WebCookieManager.isThirdPartyCookieAllowed();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### existCookie

static existCookie(incognito?: boolean): boolean

获取是否存在cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito<sup>11+</sup>    | boolean | 否   | true表示隐私模式下查询是否存在cookies，false表示正常非隐私模式下查询是否存在cookies。 |

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | true表示存在cookie，false表示不存在cookie。 |

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
      Button('existCookie')
        .onClick(() => {
          let result = webview.WebCookieManager.existCookie();
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
> 从API version9开始支持，从API version 11开始废弃。建议使用[clearAllCookiesSync](#clearallcookiessync11)替代

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
      Button('deleteEntireCookie')
        .onClick(() => {
          webview.WebCookieManager.deleteEntireCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearAllCookiesSync<sup>11+</sup>

static clearAllCookiesSync(incognito?: boolean): void

清除所有cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito    | boolean | 否   | true表示清除隐私模式下webview的所有内存cookies，false表示清除正常非隐私模式下的持久化cookies。 |

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
      Button('clearAllCookiesSync')
        .onClick(() => {
          webview.WebCookieManager.clearAllCookiesSync();
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearAllCookies')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearAllCookies((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearAllCookies')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearAllCookies()
              .then(() => {
                console.log("clearAllCookies success!");
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
> 从API version9开始支持，从API version 11开始废弃。建议使用[clearSessionCookiesync](#clearsessioncookiesync11)替代

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
      Button('deleteSessionCookie')
        .onClick(() => {
          webview.WebCookieManager.deleteSessionCookie();
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
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookieSync')
        .onClick(() => {
          webview.WebCookieManager.clearSessionCookieSync();
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearSessionCookie((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearSessionCookie()
              .then(() => {
                console.log("clearSessionCookie success!");
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static deleteOrigin(origin: string): void

清除指定源所使用的存储。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| origin | string | 是   | 指定源的字符串索引，来自于[getOrigins](#getorigins)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('deleteOrigin')
        .onClick(() => {
          try {
            webview.WebStorage.deleteOrigin(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void

以回调方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                   |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](#webstorageorigin)>> | 是   | 以数组方式返回源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            webview.WebStorage.getOrigins((error, origins) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              for (let i = 0; i < origins.length; i++) {
                console.log('origin: ' + origins[i].origin);
                console.log('usage: ' + origins[i].usage);
                console.log('quota: ' + origins[i].quota);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOrigins(): Promise\<Array\<WebStorageOrigin>>

以Promise方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Promise实例，用于获取当前所有源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            webview.WebStorage.getOrigins()
              .then(origins => {
                for (let i = 0; i < origins.length; i++) {
                  console.log('origin: ' + origins[i].origin);
                  console.log('usage: ' + origins[i].usage);
                  console.log('quota: ' + origins[i].quota);
                }
              })
              .catch((e: BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void

使用callback回调异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储配额   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.log('quota: ' + quota);
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOriginQuota(origin: string): Promise\<number>

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota);
              })
              .catch((e: BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void

以回调方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储量。   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.log('usage: ' + usage);
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static getOriginUsage(origin: string): Promise\<number>

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid origin.                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage);
              }).catch((e: BusinessError) => {
              console.error('error: ' + JSON.stringify(e));
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

static deleteAllData(incognito?: boolean): void

清除Web SQL数据库当前使用的所有存储。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| incognito<sup>11+</sup>    | boolean | 否   | true表示删除所有隐私模式下内存中的web数据，false表示删除正常非隐私模式下Web的SQL数据库当前使用的所有存储。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllData')
        .onClick(() => {
          try {
            webview.WebStorage.deleteAllData();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

Web组件数据库管理对象。

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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";
  username_password: string[] = [];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.username_password = webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.log('num: ' + this.username_password.length);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";

  build() {
    Column() {
      Button('saveHttpAuthCredentials')
        .onClick(() => {
          try {
            webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('existHttpAuthCredentials')
        .onClick(() => {
          try {
            let result = webview.WebDataBase.existHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteHttpAuthCredentials')
        .onClick(() => {
          try {
            webview.WebDataBase.deleteHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## GeolocationPermissions

Web组件地理位置权限管理对象。

> **说明：**
>
> 目前调用GeolocationPermissions下的方法，都需要先加载Web组件。

### 需要权限

访问地理位置时需添加权限：ohos.permission.LOCATION、ohos.permission.APPROXIMATELY_LOCATION、ohos.permission.LOCATION_IN_BACKGROUND，具体权限说明请参考[位置服务](../apis-location-kit/js-apis-geolocation.md)。

### allowGeolocation

static allowGeolocation(origin: string, incognito?: boolean): void

允许指定来源使用地理位置接口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   |指定源的字符串索引 |
| incognito<sup>11+</sup>    | boolean | 否   | true表示隐私模式下允许指定来源使用地理位置，false表示正常非隐私模式下允许指定来源使用地理位置。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('allowGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.allowGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteGeolocation

static deleteGeolocation(origin: string, incognito?: boolean): void

清除指定来源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |
| incognito<sup>11+</sup>   | boolean | 否   | true表示隐私模式下清除指定来源的地理位置权限状态，false表示正常非隐私模式下清除指定来源的地理位置权限状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('deleteGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.deleteGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>, incognito?: boolean): void

以回调方式异步获取指定源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| origin   | string                 | 是   | 指定源的字符串索引                                           |
| callback | AsyncCallback\<boolean> | 是   | 返回指定源的地理位置权限状态。获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |
| incognito<sup>11+</sup>    | boolean | 否   | true表示获取隐私模式下以回调方式异步获取指定源的地理位置权限状态，false表示正常非隐私模式下以回调方式异步获取指定源的地理位置权限状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
              if (error) {
                console.error(`getAccessibleGeolocationAsync error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.log('getAccessibleGeolocationAsync result: ' + result);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string, incognito?: boolean): Promise\<boolean>

以Promise方式异步获取指定源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | -------- | ---- | -------------------- |
| origin | string   | 是   | 指定源的字符串索引。 |
| incognito<sup>11+</sup>    | boolean | 否   | true表示获取隐私模式下以Promise方式异步获取指定源的地理位置权限状态，false表示正常非隐私模式下以Promise方式异步获取指定源的地理位置权限状态。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise实例，用于获取指定源的权限状态，获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.getAccessibleGeolocation(this.origin)
              .then(result => {
                console.log('getAccessibleGeolocationPromise result: ' + result);
              }).catch((error: BusinessError) => {
              console.error(`getAccessibleGeolocationPromise error, ErrorCode: ${error.code},  Message: ${error.message}`);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>, incognito?: boolean): void

以回调方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<Array\<string>> | 是   | 返回已存储地理位置权限状态的所有源信息。 |
| incognito<sup>11+</sup>    | boolean | 否   | true表示获取隐私模式下以回调方式异步获取已存储地理位置权限状态的所有源信息，false表示正常非隐私模式下以回调方式异步获取已存储地理位置权限状态的所有源信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.getStoredGeolocation((error, origins) => {
              if (error) {
                console.error(`getStoredGeolocationAsync error, ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              let origins_str: string = origins.join();
              console.log('getStoredGeolocationAsync origins: ' + origins_str);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(incognito?: boolean): Promise\<Array\<string>>

以Promise方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| incognito<sup>11+</sup>   | boolean | 否   | true表示获取隐私模式下以Promise方式异步获取已存储地理位置权限状态的所有源信息，false表示正常非隐私模式下以Promise方式异步获取已存储地理位置权限状态的所有源信息。 |

**返回值：**

| 类型                   | 说明                                                      |
| ---------------------- | --------------------------------------------------------- |
| Promise\<Array\<string>> | Promise实例，用于获取已存储地理位置权限状态的所有源信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.getStoredGeolocation()
              .then(origins => {
                let origins_str: string = origins.join();
                console.log('getStoredGeolocationPromise origins: ' + origins_str);
              }).catch((error: BusinessError) => {
              console.error(`getStoredGeolocationPromise error, ErrorCode: ${error.code},  Message: ${error.message}`);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteAllGeolocation

static deleteAllGeolocation(incognito?: boolean): void

清除所有来源的地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                     |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| incognito<sup>11+</sup>    | boolean | 否   | true表示获取隐私模式下清除所有来源的地理位置权限状态，false表示正常非隐私模式下清除所有来源的地理位置权限状态。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.deleteAllGeolocation();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

## RequestInfo<sup>12+</sup>

Web组件发送的资源请求信息。

**系统能力：**: SystemCapability.Web.Webview.Core

| 名称      | 类型   | 可读 | 可写 |说明        |
| ---------| ------ | -----|------|--------  |
| url      | string | 是 | 是 | 请求的链接。    |
| method   | string | 是 | 是 | 请求的方法。    |
| formData | string | 是 | 是 | 请求的表单数据。 |

## WebHitTestType

[getHitTest](#gethittest)接口用于指示游标节点。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| EditText      | 0 |可编辑的区域。                            |
| Email         | 1 |电子邮件地址。                            |
| HttpAnchor    | 2 |超链接，其中src为http。                     |
| HttpAnchorImg | 3 |带有超链接的图片，其中src为http + HTML::img。 |
| Img           | 4 |HTML::img标签。                           |
| Map           | 5 |地理地址。                                |
| Phone         | 6 |电话号码。                                |
| Unknown       | 7 |未知内容。                                |

## SecurityLevel<sup>11+</sup>

当前网页的安全级别。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| NONE          | 0 |页面既不绝对安全，也不是不安全，即是中立。例如，部分scheme非http/https的URL。|
| SECURE        | 1 |页面安全，页面使用的是HTTPS协议，且使用了信任的证书。|
| WARNING       | 2 |页面不安全。例如，使用HTTP协议或使用HTTPS协议但使用旧版TLS版本。|
| DANGEROUS     | 3 |页面不安全。尝试HTTPS并失败、页面未通过身份验证、页面上包含不安全活动内容的HTTPS、恶意软件、网络钓鱼或任何其他可能危险的严重安全问题。 |

##  HitTestValue

提供点击区域的元素信息。示例代码参考[getHitTestValue](#gethittestvalue)。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 可读 | 可写 | 说明|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](#webhittesttype) | 是 | 是 | 当前被点击区域的元素类型。|
| extra | string        | 是 | 是 |点击区域的附加参数信息。若被点击区域为图片或链接，则附加参数信息为其url地址。 |

## WebMessage

type WebMessage = ArrayBuffer | string

用于描述[WebMessagePort](#webmessageport)所支持的数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 类型       | 说明                                     |
| -------- | -------------------------------------- |
| string   | 字符串类型数据。 |
| ArrayBuffer   | 二进制类型数据。 |

## JsMessageType<sup>10+</sup>

[runJavaScriptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。

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

## MediaPlaybackState<sup>12+</sup>

当前网页的播控状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值   | 说明               |
| ------- | ---- | ------------------ |
| NONE    | 0    | 页面无音视频启播。 |
| PLAYING | 1    | 页面音视频播放中。 |
| PAUSED  | 2    | 页面音视频暂停。   |
| STOPPED | 3    | 页面音视频停止。   |

## RenderProcessMode<sup>12+</sup>

ArkWeb渲染子进程模式类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| SINGLE        | 0 |ArkWeb单渲染子进程模式。该模式下，多个Web复用一个渲染子进程。|
| MULTIPLE      | 1 |ArkWeb多渲染子进程模式。该模式下，每个Web一个渲染子进程。|


## JsMessageExt<sup>10+</sup>

[runJavaScriptExt](#runjavascriptext10)接口执行脚本返回的数据对象。

### getType<sup>10+</sup>

getType(): JsMessageType

获取数据对象的类型。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明                                                      |
| --------------| --------------------------------------------------------- |
| [JsMessageType](#jsmessagetype10) | [runJavaScriptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。 |

### getString<sup>10+</sup>

getString(): string

获取数据对象的字符串类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| string | 返回字符串类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getNumber<sup>10+</sup>

getNumber(): number

获取数据对象的数值类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| number | 返回数值类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

获取数据对象的布尔类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| boolean | 返回布尔类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

获取数据对象的原始二进制数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| ArrayBuffer | 返回原始二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

获取数据对象的数组类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | 返回数组类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## WebMessageExt<sup>10+</sup>

[webMessagePort](#webmessageport)接口接收、发送的数据对象。

### getType<sup>10+</sup>

getType(): WebMessageType

获取数据对象的类型。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getNumber<sup>10+</sup>

getNumber(): number

获取数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| number | 返回数值类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

获取数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| boolean | 返回布尔类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

获取数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| ArrayBuffer | 返回原始二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

获取数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | 返回数组类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getError<sup>10+</sup>

getError(): Error

获取数据对象的错误类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型           | 说明          |
| --------------| ------------- |
| Error | 返回错误对象类型的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### setType<sup>10+</sup>

setType(type: WebMessageType): void

设置数据对象的类型。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| type  | [WebMessageType](#webmessagetype10) | 是   | [webMessagePort](#webmessageport)接口所支持的数据类型。 |

**错误码：**

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

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
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

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
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

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
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setArrayBuffer<sup>10+</sup>

setArrayBuffer(message: ArrayBuffer): void

设置数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | ArrayBuffer | 是   | 原始二进制类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setArray<sup>10+</sup>

setArray(message: Array\<string | number | boolean\>): void

设置数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Array\<string \| number \| boolean\> | 是   | 数组类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setError<sup>10+</sup>

setError(message: Error): void

设置数据对象的错误对象类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | -------------------- |
| message  | Error | 是   | 错误对象类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## WebStorageOrigin

提供Web SQL数据库的使用信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 类型   | 可读 | 可写 | 说明 |
| ------ | ------ | ---- | ---- | ---- |
| origin | string | 是  | 是 | 指定源的字符串索引。 |
| usage  | number | 是  | 是 | 指定源的存储量。     |
| quota  | number | 是  | 是 | 指定源的存储配额。   |

## BackForwardList

当前Webview的历史信息列表。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 类型   | 可读 | 可写 | 说明                                                         |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | 是   | 是   | 当前在页面历史列表中的索引。                                 |
| size         | number | 是   | 是   | 历史列表中索引的数量，最多保存50条，超过时起始记录会被覆盖。 |

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

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
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
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
| icon          | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 否   | 历史页面图标的PixelMap对象。 |
| historyUrl    | string                                 | 是   | 是   | 历史记录项的url地址。        |
| historyRawUrl | string                                 | 是   | 是   | 历史记录项的原始url地址。    |
| title         | string                                 | 是   | 是   | 历史记录项的标题。           |

## WebCustomScheme

自定义协议配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 可读 | 可写 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | 是   | 是   | 自定义协议名称。最大长度为32，其字符仅支持小写字母、数字、'.'、'+'、'-', 同时需要以字母开头。        |
| isSupportCORS  | boolean   | 是   | 是   | 是否支持跨域请求。    |
| isSupportFetch | boolean   | 是   | 是   | 是否支持fetch请求。           |
| isStandard<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme是否将作为标准scheme进行处理。标准scheme需要符合RFC 1738第3.1节中定义的URL规范化和解析规则。           |
| isLocal<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme是否将使用与应用于“FILE”的安全规则相同的安全规则来处理。           |
| isDisplayIsolated<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme的内容是否只能从相同scheme的其他内容中显示或访问。           |
| isSecure<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme是否将使用与应用于“https”的安全规则相同的安全规则来处理。           |
| isCspBypassing<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme可以绕过内容安全策略（CSP）检查。在大多数情况下，当设置isStandard为true时，不应设置此值。         |
| isCodeCacheSupported<sup>12+</sup> | boolean   | 是   | 是   | 设置了该选项的scheme的js资源，支持生成code cache。         |

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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update current speed: " + webDownloadItem.getCurrentSpeed());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update total bytes: " + webDownloadItem.getTotalBytes());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update download state: " + webDownloadItem.getState());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getLastErrorCode<sup>11+</sup>

getLastErrorCode(): WebDownloadErrorCode

获取下载的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| [WebDownloadErrorCode](#webdownloaderrorcode11) | 下载发生错误的时候的错误码。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              console.log("download error code: " + webDownloadItem.getLastErrorCode());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download， method:" + webDownloadItem.getMethod());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download， mime type:" + webDownloadItem.getMimeType());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download, url:" + webDownloadItem.getUrl());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download, suggest name:" + webDownloadItem.getSuggestedFileName());
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              console.log("download update received bytes: " + webDownloadItem.getReceivedBytes());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
              console.log("download finish full path: " + webDownloadItem.getFullPath());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| serializedData | Uint8Array | 是   | 序列化后的下载。|

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| [WebDownloadItem](#webdownloaditem11) | 从字节数组反序列化为一个WebDownloadItem对象。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

| 参数名 | 类型                   | 必填 | 说明                             |
| ------ | ---------------------- | ---- | ------------------------------|
| downloadPath   | string     | 是  | 下载文件的路径(包含文件名)。|

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100019 | The download task is not started yet. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID  | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 17100016 | The download task is not paused. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

onBeforeDownload(callback: Callback\<WebDownloadItem>): void

下载开始前通知给用户，用户需要在此接口中调用WebDownloadItem.start("xxx")并提供下载路径，否则下载会一直处于PENDING状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | 是   | 触发下载的回调。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadUpdated<sup>11+</sup>

onDownloadUpdated(callback: Callback\<WebDownloadItem>): void

下载过程中的回调，通过该回调的参数可以了解下载进度等信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | 是   | 下载的回调已更新。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadFinish<sup>11+</sup>

onDownloadFinish(callback: Callback\<WebDownloadItem>): void

下载完成的通知。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | 是   | 下载的回调已完成。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onDownloadFailed<sup>11+</sup>

onDownloadFailed(callback: Callback\<WebDownloadItem>): void

下载失败的通知。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | 是   | 下载回调失败。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
            webview.WebDownloadManager.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### resumeDownload<sup>11+</sup>

static resumeDownload(webDownloadItem: WebDownloadItem): void

恢复一个失败的下载任务。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| webDownloadItem      | [WebDownloadItem](#webdownloaditem11)  | 是   | 待恢复的下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100018 | No WebDownloadDelegate has been set yet. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
            webview.WebDownloadManager.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebHttpBodyStream<sup>12+</sup>

POST、PUT请求的数据体，支持BYTES、FILE、BLOB、CHUNKED类型的数据。注意本类中其他接口需要在[initialize](#initialize12)成功后才能调用。

### initialize<sup>12+</sup>

initialize(): Promise\<void\>

初始化WebHttpBodyStream。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<void\> | Promise实例，用于获取WebHttpBodyStream是否初始化成功。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100022 | Failed to initialize the HTTP body stream. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';
import { WebNetErrorList } from '@ohos.web.netErrorList'

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
  htmlData: string = "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

  build() {
    Column() {
      Button('postUrl')
        .onClick(() => {
          try {
            let postData = buffer.from(this.htmlData);
            this.controller.postUrl('https://www.example.com', postData.buffer);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          try {
            this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
              console.log("[schemeHandler] onRequestStart");
              try {
                let stream = request.getHttpBodyStream();
                if (stream) {
                  stream.initialize().then(() => {
                    if (!stream) {
                      return;
                    }
                    console.log("[schemeHandler] onRequestStart postDataStream size:" + stream.getSize());
                    console.log("[schemeHandler] onRequestStart postDataStream position:" + stream.getPosition());
                    console.log("[schemeHandler] onRequestStart postDataStream isChunked:" + stream.isChunked());
                    console.log("[schemeHandler] onRequestStart postDataStream isEof:" + stream.isEof());
                    console.log("[schemeHandler] onRequestStart postDataStream isInMemory:" + stream.isInMemory());
                    stream.read(stream.getSize()).then((buffer) => {
                      if (!stream) {
                        return;
                      }
                      console.log("[schemeHandler] onRequestStart postDataStream readlength:" + buffer.byteLength);
                      console.log("[schemeHandler] onRequestStart postDataStream isEof:" + stream.isEof());
                      console.log("[schemeHandler] onRequestStart postDataStream position:" + stream.getPosition());
                    }).catch((error: BusinessError) => {
                      console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
                    })
                  }).catch((error: BusinessError) => {
                    console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
                  })
                } else {
                  console.log("[schemeHandler] onRequestStart has no http body stream");
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              return false;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.log("[schemeHandler] onRequestStop");
            });

            this.controller.setWebSchemeHandler('https', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .domStorageAccess(true)
    }
  }
}

```

### read<sup>12+</sup>

read(size: number): Promise\<ArrayBuffer\>

读取WebHttpBodyStream中的数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  size | number | 是   | 读取WebHttpBodyStream中的字节数。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<ArrayBuffer\> | Promise实例，用于获取WebHttpBodyStream中读取的数据。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |

**示例：**

完整示例代码参考[initialize](#initialize12)。

### getSize<sup>12+</sup>

getSize(): number

获取WebHttpBodyStream中的数据大小，分块传输时总是返回零。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 获取WebHttpBodyStream中的数据大小。 |

**示例：**

完整示例代码参考[initialize](#initialize12)。

### getPosition<sup>12+</sup>

getPosition(): number

读取WebHttpBodyStream中当前的读取位置。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | WebHttpBodyStream中当前的读取位置。 |

**示例：**

完整示例代码参考[initialize](#initialize12)。

### isChunked<sup>12+</sup>

isChunked(): boolean

WebHttpBodyStream是否采用分块传输。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| boolean | WebHttpBodyStream是否采用分块传输。 |

**示例：**

完整示例代码参考[initialize](#initialize12)。

### isEof<sup>12+</sup>

isEof(): boolean

判断WebHttpBodyStream中的所有数据是否都已被读取。如果所有数据都已被读取，则返回true。对于分块传输类型的 WebHttpBodyStream，在第一次读取尝试之前返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| boolean | WebHttpBodyStream中的所有数据是否都已被读取。 |

**示例：**

完整示例代码参考[initialize](#initialize12)。

### isInMemory<sup>12+</sup>

isInMemory(): boolean

判断WebHttpBodyStream中的上传数据是否在内存中。如果WebHttpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。对于分块传输类型的数据，预期返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| boolean | WebHttpBodyStream中的上传数据是否在内存中。 |

**示例：**

完整示例代码参考[initialize](#initialize12)。

## WebSchemeHandlerRequest<sup>12+</sup>

通过WebSchemeHandler拦截到的请求。

### getHeader<sup>12+</sup>

getHeader(): Array\<WebHeader\>

获取资源请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array\<[WebHeader](#webheader)\> | 返回资源请求头信息。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getRequestUrl<sup>12+</sup>

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getRequestMethod<sup>12+</sup>

getRequestMethod(): string

获取请求方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回请求方法。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getReferrer<sup>12+</sup>

getReferrer(): string

获取referrer。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 获取到的referrer。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### isMainFrame<sup>12+</sup>

isMainFrame(): boolean

判断资源请求是否为主frame。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| boolean | 判断资源请求是否为主frame。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### hasGesture<sup>12+</sup>

hasGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getHttpBodyStream<sup>12+</sup>

getHttpBodyStream(): WebHttpBodyStream | null

获取资源请求中的WebHttpBodyStream。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [WebHttpBodyStream](#webhttpbodystream12) \| null | 返回资源请求中的WebHttpBodyStream，如果没有则返回null。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getRequestResourceType<sup>12+</sup>

getRequestResourceType(): WebResourceType

获取资源请求的资源类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [WebResourceType](#webresourcetype12) | 返回资源请求的资源类型。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

### getFrameUrl<sup>12+</sup>

getFrameUrl(): string

获取触发此请求的Frame的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回触发此请求的Frame的URL。 |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

## WebSchemeHandlerResponse<sup>12+</sup>

请求的响应，可以为被拦截的请求创建一个Response并填充自定义的内容返回给Web组件。

### constructor<sup>12+</sup>

constructor()

Response的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

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
          console.log("[schemeHandler] getUrl:" + response.getUrl())
          console.log("[schemeHandler] getStatus:" + response.getStatus())
          console.log("[schemeHandler] getStatusText:" + response.getStatusText())
          console.log("[schemeHandler] getMimeType:" + response.getMimeType())
          console.log("[schemeHandler] getEncoding:" + response.getEncoding())
          console.log("[schemeHandler] getHeaderByValue:" + response.getHeaderByName("header1"))
          console.log("[schemeHandler] getNetErrorCode:" + response.getNetErrorCode())

        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Web({ src: 'https://www.example.com', controller: this.controller })
    }
  }
}

```

### setUrl<sup>12+</sup>

setUrl(url: string): void

给当前的Response设置重定向或因HSTS而更改后的URL，设置了url后会触发请求的跳转。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  url | string | 是   | 即将要跳转的URL。 |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

### setNetErrorCode<sup>12+</sup>

setNetErrorCode(code: WebNetErrorList): void

给当前的Response设置网络错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | 是   | 网络错误码。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### setStatus<sup>12+</sup>

setStatus(code: number): void

给当前的Response设置HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  code | number | 是   | Http状态码。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### setStatusText<sup>12+</sup>

setStatusText(text: string): void

给当前的Response设置状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  text | string | 是   | 状态文本。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### setMimeType<sup>12+</sup>

setMimeType(type: string): void

给当前的Response设置媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  type | string | 是   | 媒体类型。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### setEncoding<sup>12+</sup>

setEncoding(encoding: string): void

给当前的Response设置字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  encoding | string | 是   | 字符集。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### setHeaderByName<sup>12+</sup>

setHeaderByName(name: string, value: string, overwrite: boolean): void

给当前的Response设置头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  name | string | 是   | 头部（header）的名称。 |
|  value | string | 是   | 头部（header）的值。 |
|  overwrite | boolean | 是   | 如果为true，将覆盖现有的头部，否则不覆盖。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getUrl<sup>12+</sup>

getUrl(): string

获取重定向或由于HSTS而更改后的URL。
风险提示：如果想获取url来做JavascriptProxy通信接口认证，请使用[getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](#getlastjavascriptproxycallingframeurl12)

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 获取经过重定向或由于HSTS而更改后的URL。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getNetErrorCode<sup>12+</sup>

getNetErrorCode(): WebNetErrorList

获取Response的网络错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | 获取Response的网络错误码。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getStatus<sup>12+</sup>

getStatus(): number

获取Response的Http状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| number | 获取Response的Http状态码。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getStatusText<sup>12+</sup>

getStatusText(): string

获取Response的状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 状态文本。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getMimeType<sup>12+</sup>

getMimeType(): string

获取Response的媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 媒体类型。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getEncoding<sup>12+</sup>

getEncoding(): string

获取Response的字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 字符集。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

### getHeaderByName<sup>12+</sup>

getHeaderByName(name: string): string

获取Response的字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                  |
| ------- | ---------------- | ---- | -------------------- |
| name     | string | 是   | 头部（header）的名称。      |


**返回值：**

| 类型    | 说明                                     |
| ------- | --------------------------------------- |
| string | 头部（header）的值。|

**示例：**

示例完整示例代码参考[constructor](#constructor12)。

## WebResourceHandler<sup>12+</sup>

通过WebResourceHandler，可以提供自定义的返回头以及返回体给Web组件。

### didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](#webschemehandlerresponse12)  | 是   | 该拦截请求的响应。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](#onrequeststart12)。

### didReceiveResponseBody<sup>12+</sup>

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

示例请参考[OnRequestStart](#onrequeststart12)。

### didFinish<sup>12+</sup>

didFinish(): void

通知Web组件被拦截的请求已经完成，并且没有更多的数据可用，调用前需要优先调用[didReceiveResponse](#didreceiveresponse12)将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](#onrequeststart12)。

### didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

通知ArkWeb内核被拦截请求应该返回失败，调用前需要优先调用[didReceiveResponse](#didreceiveresponse12)将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | 是   | 网络错误码。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

示例请参考[OnRequestStart](#onrequeststart12)。

## WebSchemeHandler<sup>12+</sup>

用于拦截指定scheme的请求的拦截器。

### onRequestStart<sup>12+</sup>

onRequestStart(callback: (request: WebSchemeHandlerRequest, handler: WebResourceHandler) => boolean): void

当请求开始时的回调，在该回调函数中可以决定是否拦截该请求。当回调返回false是表示不拦截此请求，此时handler失效；当回调返回true，表示拦截此请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数**：

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback   | (request: [WebSchemeHandlerRequest](#webschemehandlerrequest12), handler: [WebResourceHandler](#webresourcehandler12)) => boolean | 是 | 拦截对应scheme请求开始时触发的回调。request为请求，handler用于提供自定义的返回头以及返回体给Web组件，返回值表示该请求是否拦截。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
  htmlData: string = "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

  build() {
    Column() {
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          try {
            this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
              console.log("[schemeHandler] onRequestStart");
              try {
                console.log("[schemeHandler] onRequestStart url:" + request.getRequestUrl());
                console.log("[schemeHandler] onRequestStart method:" + request.getRequestMethod());
                console.log("[schemeHandler] onRequestStart referrer:" + request.getReferrer());
                console.log("[schemeHandler] onRequestStart isMainFrame:" + request.isMainFrame());
                console.log("[schemeHandler] onRequestStart hasGesture:" + request.hasGesture());
                console.log("[schemeHandler] onRequestStart header size:" + request.getHeader().length);
                console.log("[schemeHandler] onRequestStart resource type:" + request.getRequestResourceType());
                console.log("[schemeHandler] onRequestStart frame url:" + request.getFrameUrl());
                let header = request.getHeader();
                for (let i = 0; i < header.length; i++) {
                  console.log("[schemeHandler] onRequestStart header:" + header[i].headerKey + " " + header[i].headerValue);
                }
                let stream = request.getHttpBodyStream();
                if (stream) {
                  console.log("[schemeHandler] onRequestStart has http body stream");
                } else {
                  console.log("[schemeHandler] onRequestStart has no http body stream");
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              if (request.getRequestUrl().endsWith("example.com")) {
                return false;
              }

              let response = new webview.WebSchemeHandlerResponse();
              try {
                response.setNetErrorCode(WebNetErrorList.NET_OK);
                response.setStatus(200);
                response.setStatusText("OK");
                response.setMimeType("text/html");
                response.setEncoding("utf-8");
                response.setHeaderByName("header1", "value1", false);
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              // 调用 didFinish/didFail 前需要优先调用 didReceiveResponse 将构造的响应头传递给被拦截的请求。
              let buf = buffer.from(this.htmlData)
              try {
                if (buf.length == 0) {
                  console.log("[schemeHandler] length 0");
                  resourceHandler.didReceiveResponse(response);
                  // 如果认为buf.length为0是正常情况，则调用resourceHandler.didFinish，否则调用resourceHandler.didFail
                  resourceHandler.didFail(WebNetErrorList.ERR_FAILED);
                } else {
                  console.log("[schemeHandler] length 1");
                  resourceHandler.didReceiveResponse(response);
                  resourceHandler.didReceiveResponseBody(buf.buffer);
                  resourceHandler.didFinish();
                }
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
              return true;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.log("[schemeHandler] onRequestStop");
            });

            this.controller.setWebSchemeHandler('https', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .domStorageAccess(true)
    }
  }
}
```
### onRequestStop<sup>12+</sup>

onRequestStop(callback: Callback\<WebSchemeHandlerRequest\>): void

当请求完成时的回调，仅当前面onRequestStart中回调决定拦截此请求中触发。触发的时机有以下两点：

1.WebResourceHandler调用didFail或者didFinish。

2.此请求因为其他原因中断。

**系统能力：** SystemCapability.Web.Webview.Core

**参数**：

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | Callback\<[WebSchemeHandlerRequest](#webschemehandlerrequest12)\> | 是   | 对应请求结束的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 401 | Invalid input parameter. |

**示例：**

完整示例代码参考[onRequestStart](#onrequeststart12)。

## CacheOptions<sup>12+</sup>

Web组件预编译JavaScript生成字节码缓存的配置对象，用于控制字节码缓存更新。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 可读 | 可写 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| responseHeaders   | Array<[WebHeader](#webheader)> | 是 | 是 | 请求此JavaScript文件时服务器返回的响应头，使用E-Tag或Last-Modified标识文件版本，判断是否需要更新。   |

## PlaybackStatus<sup>12+</sup>

[handleStatusChanged](#handlestatuschanged12) 接口参数， 用于表示播放器的播放状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| PAUSED  | 0 | 播放状态为播放状态。 |
| PLAYING | 1 | 播放状态为暂停状态。 |

## NetworkState<sup>12+<sup>

播放器的网络状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| EMPTY         | 0 | 播放器还没有开始下载数据。 |
| IDLE          | 1 | 播放器网络状态空闲，比如媒体分片下载完成，下一个分片还没有开始下载。 |
| LOADING       | 2 | 播放器正在下载媒体数据。 |
| NETWORK_ERROR | 3 | 发生了网络错误。 |

## ReadyState<sup>12+<sup>

播放器的缓存状态。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| HAVE_NOTHING      | 0 | 没有缓存。 |
| HAVE_METADATA     | 1 | 只缓存了媒体元数据。 |
| HAVE_CURRENT_DATA | 2 | 只缓存到当前的播放进度。 |
| HAVE_FUTURE_DATA  | 3 | 缓存时长超过了当前的播放进度, 但是仍有可能导致卡顿。 |
| HAVE_ENOUGH_DATA  | 4 | 缓存了足够的数据，保证播放流畅。 |

## MediaError<sup>12+<sup>

播放器的错误类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| NETWORK_ERROR | 1 | 网络错误。 |
| FORMAT_ERROR  | 2 | 媒体格式错误。 |
| DECODE_ERROR  | 3 | 解码错误。 |

## NativeMediaPlayerHandler<sup>12+<sup>

[CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) 回调函数的参数。
应用通过该对象，将播放器的状态报告给ArkWeb内核。

### handleStatusChanged<sup>12+<sup>

handleStatusChanged(status: PlaybackStatus): void

当播放器的播放状态发生变化时，调用该方法将播放状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| status | [PlaybackStatus](#playbackstatus12) | 是 | 播放器的播放状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleVolumeChanged<sup>12+<sup>

handleVolumeChanged(volume: number): void

当播放器的音量发生变化时，调用该方法将音量通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| volume | number | 是 | 播放器的音量。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleMutedChanged<sup>12+<sup>

handleMutedChanged(muted: boolean): void

当播放器的静音状态发生变化时，调用该方法将静音状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| muted | boolean | 是 | 当前播放器是否静音。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handlePlaybackRateChanged<sup>12+<sup>

handlePlaybackRateChanged(playbackRate: number): void

当播放器的播放速度发生变化时，调用该方法将播放速度通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| playbackRate | number | 是 | 播放速率。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleDurationChanged<sup>12+<sup>

handleDurationChanged(duration: number): void

当播放器解析出媒体的总时长时，调用该方法将媒体的总时长通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| duration | number | 是 | 媒体的总时长。单位： 秒 。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleTimeUpdate<sup>12+<sup>

handleTimeUpdate(currentPlayTime: number): void

当媒体的播放进度发生变化时，调用该方法将媒体的播放进度通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| currentPlayTime | number | 是 | 当前播放时间。单位： 秒。  |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleBufferedEndTimeChanged<sup>12+<sup>

handleBufferedEndTimeChanged(bufferedEndTime: number): void

当媒体的缓冲时长发生变化时，调用该方法将媒体的缓冲时长通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| bufferedEndTime | number | 是 | 媒体缓冲的时长。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleEnded<sup>12+<sup>

handleEnded(): void

当媒体播放结束时，调用该方法通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleNetworkStateChanged<sup>12+<sup>

handleNetworkStateChanged(state: NetworkState): void

当播放器的网络状态发生变化时，调用该方法将播放器的网络状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| state | [NetworkState](#networkstate12) | 是 | 播放器的网络状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleReadyStateChanged<sup>12+<sup>

handleReadyStateChanged(state: ReadyState): void

当播放器的缓存状态发生变化时，调用该方法将播放器的缓存状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| state | [ReadyState](#readystate12) | 是 | 播放器的缓存状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleFullscreenChanged<sup>12+<sup>

handleFullscreenChanged(fullscreen: boolean): void

当播放器的全屏状态发生变化时，调用该方法将播放器的全屏状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| fullscreen | boolean | 是 | 是否全屏。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleSeeking<sup>12+<sup>

handleSeeking(): void

当播放器进入seek 状态时，调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleSeekFinished<sup>12+<sup>

handleSeekFinished(): void

当播放器 seek 完成后，调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleError<sup>12+<sup>

handleError(error: MediaError, errorMessage: string): void

当播放器发生错误时， 调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| error | [MediaError](#mediaerror12) | 是 | 错误类型。 |
| errorMessage | string | 是 | 错误的详细描述。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### handleVideoSizeChanged<sup>12+<sup>

handleVideoSizeChanged(width: number, height: number): void

当播放器解析出视频的尺寸时， 调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| width  | number | 是 | 视频的宽。 |
| height | number | 是 | 视频的高。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

## SuspendType<sup>12+<sup>

表示播放器的挂起类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| ENTER_BACK_FORWARD_CACHE | 0 | 页面进BFCache。 |
| ENTER_BACKGROUND         | 1 | 页面进后台。 |
| AUTO_CLEANUP             | 2 | 系统自动清理。 |

## NativeMediaPlayerBridge<sup>12+<sup>

[CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) 回调函数的返回值类型。
接管网页媒体的播放器和 ArkWeb 内核之间的一个接口类。
ArkWeb 内核通过该接口类的实例对象来控制应用创建的用来接管网页媒体的播放器。

### updateRect<sup>12+<sup>

updateRect(x: number, y: number, width: number, height: number): void

更新 surface 位置信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| x | number | 是 | surface 相对于 Web 组件的 x 坐标信息。 |
| y | number | 是 | surface 相对于 Web 组件的 y 坐标信息。 |
| width  | number | 是 | surface 的宽度。 |
| height | number | 是 | surface 的高度。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### play<sup>12+<sup>

play(): void

播放视频。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### pause<sup>12+<sup>

pause(): void

暂停播放。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### seek<sup>12+<sup>

seek(targetTime: number): void

播放跳转到某个时间点。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| targetTime | number | 是 | 单位： 秒。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### setVolume<sup>12+<sup>

setVolume(volume: number): void

设置播放器音量值。
取值范围: [0, 1.0]

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| volume | number | 是 | 播放器的音量。取值范围是从 0 到 1.0 。 其中 0 表示静音， 1.0 表示最大音量。 |

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### setMuted<sup>12+<sup>

setMuted(muted: boolean): void

设置静音状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| muted | boolean | 是 | 是否静音。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### setPlaybackRate<sup>12+<sup>

setPlaybackRate(playbackRate: number): void

设置播放速度。
取值范围: [0, 10.0]

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| playbackRate | number | 是 | 播放倍率。取值范围是从 0 到 10.0 。其中 1 表示原速播放。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### release<sup>12+<sup>

release(): void

销毁播放器。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### enterFullscreen<sup>12+<sup>

enterFullscreen(): void

播放器进入全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### exitFullscreen<sup>12+<sup>

exitFullscreen(): void

播放器退出全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### resumePlayer<sup>12+<sup>

resumePlayer?(): void

通知应用重建应用内播放器，并恢复应用内播放器的状态信息。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

### suspendPlayer<sup>12+<sup>

suspendPlayer?(type: SuspendType): void

通知应用销毁应用内播放器，并保存应用内播放器的状态信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| type | [SuspendType](#suspendtype12) | 是 | 播放器挂起类型。|

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

## MediaType<sup>12+<sup>

表示媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| VIDEO | 0 | 视频。 |
| AUDIO | 1 | 音频。 |

## SourceType<sup>12+<sup>

表示媒体源的类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| URL | 0 | 媒体源的类型是 URL 。 |
| MSE | 1 | 媒体源的类型是 blob 。 |

## MediaSourceInfo<sup>12+<sup>

表示媒体源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| type | [SourceType](#sourcetype12) | 是 | 媒体源的类型。 |
| source | string | 是 | 媒体源地址。 |
| format | string | 是 | 媒体源格式， 可能为空， 需要使用者自己去判断格式。 |

## NativeMediaPlayerSurfaceInfo<sup>12+<sup>

[应用接管网页媒体播放功能](ts-basic-components-web.md#enablenativemediaplayer12)中用于同层渲染的 surface 信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| id | string | 是 | surface 的id ， 用于同层渲染的NativeImage的 psurfaceid。<br/>详见[NativeEmbedDataInfo](ts-basic-components-web.md#nativeembeddatainfo11)。 |
| rect | [RectEvent](#rectevent12) | 是 | surface 的位置信息。 |

## Preload<sup>12+<sup>

播放器预加载媒体数据。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
|------|----|------|
| NONE     | 0 | 不预加载。 |
| METADATA | 1 | 只预加载媒体的元数据。 |
| AUTO     | 2 | 预加载足够多的媒体数据，以保证能流畅地播放。 |

## MediaInfo<sup>12+<sup>

[CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12)回调函数的一个参数。
包含了网页中媒体的信息。应用可以根据这些信息来创建接管网页媒体播放的播放器。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| embedID | string | 是 | 网页中的 `<video>` 或 `<audio>` 的 ID 。|
| mediaType | [MediaType](#mediatype12) | 是 | 媒体的类型。 |
| mediaSrcList | [MediaSourceInfo](#mediasourceinfo12)[] | 是 | 媒体的源。可能有多个源，应用需要选择一个支持的源来播放。 |
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](#nativemediaplayersurfaceinfo12) | 是 | 用于同层渲染的 surface 信息。 |
| controlsShown | boolean | 是 | `<video>` 或 `<audio>` 中是否有 `controls`属性。 |
| controlList | string[] | 是 | `<video>` 或 `<audio>` 中的 `controlslist` 属性的值。 |
| muted | boolean | 是 | 是否要求静音播放。 |
| posterUrl | string | 是 | 海报的地址。 |
| preload | [Preload](#preload12) | 是 | 是否需要预加载。 |
| headers | Record\<string, string\> | 是 | 播放器请求媒体资源时，需要携带的 HTTP 头。 |
| attributes | Record\<string, string\> | 是 | `<video>` 或 `<audio>` 标签中的属性。 |


## CreateNativeMediaPlayerCallback<sup>12+<sup>

type CreateNativeMediaPlayerCallback = (handler: NativeMediaPlayerHandler, mediaInfo: MediaInfo) => NativeMediaPlayerBridge

[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)方法的参数。
一个回调函数， 创建一个播放器, 用于接管网页中的媒体播放。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| handler | [NativeMediaPlayerHandler](#nativemediaplayerhandler12) | 是 | 通过该对象，将播放器的状态报告给 ArkWeb 内核。 |
| mediaInfo | [MediaInfo](#mediainfo12) | 是 | 网页媒体的信息。 |

**返回值：**

| 类型 | 说明 |
|------|------|
| [NativeMediaPlayerBridge](#nativemediaplayerbridge12) | 接管网页媒体的播放器和 ArkWeb 内核之间的一个接口类。<br/>应用需要实现该接口类。<br/> ArkWeb 内核通过该接口类的对象来控制应用创建的用来接管网页媒体的播放器。<br/>如果应用返回了 null ， 则表示应用不接管这个媒体，由 ArkWeb 内核来播放该媒体。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](#oncreatenativemediaplayer12)。

## OfflineResourceMap<sup>12+</sup>

本地离线资源配置对象，用于配置将被[injectOfflineResources](#injectofflineresources12)接口注入到内存缓存的本地离线资源的相关信息, 内核会根据此信息生成资源缓存，并据此控制缓存的有效期。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型   | 可读 | 可写 |说明                 |
| ----------- | ------ | -----|------|------------------- |
| urlList | Array\<string\> | 是   | 是   | 本地离线资源对应的网络地址列表，列表的第一项将作为资源的源(Origin), 如果仅提供一个网络地址，则使用该地址作为这个资源的源。url仅支持http或https协议，长度不超过2048。      |
| resource | Uint8Array | 是   | 是   | 本地离线资源的内容。      |
| responseHeaders | Array<[WebHeader](#webheader)> | 是   | 是   | 资源对应的HTTP响应头。其中提供的Cache-Control或Expires响应头将被用于控制资源在内存缓存中的有效期。如果不提供，默认的有效期为86400秒，即1天。其中提供的Content-Type响应头将被用于定义资源的MIMEType，MODULE_JS必须提供有效的MIMEType，其他类型可不提供，无默认值，不符合标准的MIMEType会导致内存缓存失效。如果业务网页中的script标签使用了crossorigin属性，则必须在接口的responseHeaders参数中设置Cross-Origin响应头的值为anoymous或use-credentials。      |
| type | [OfflineResourceType](#offlineresourcetype12) | 是   | 是   | 资源的类型，目前仅支持Javascript、图片和CSS类型的资源。      |

## OfflineResourceType<sup>12+</sup>

[OfflineResourceMap](#offlineresourcemap12)对象对应的本地离线资源的接口类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 值 | 说明                              |
| ------------ | -- |--------------------------------- |
| IMAGE  | 0 | 图片类型的资源。 |
| CSS       | 1 | CSS类型的资源。|
| CLASSIC_JS       | 2 | 通过<script src="" /\>标签加载的Javascript资源。|
| MODULE_JS      | 3 |通过<script src="" type="module" /\>标签加载的Javascript资源。|

## WebResourceType<sup>12+</sup>

资源请求的资源类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 值 | 说明                              |
| ------------ | -- |--------------------------------- |
| MAIN_FRAME | 0 | 顶层页面。 |
| SUB_FRAME | 1 | Frame或Iframe。 |
| STYLE_SHEET | 2 | CSS样式表。 |
| SCRIPT | 3 | 外部脚本。 |
| IMAGE | 4 | 图片（jpg/gif/png/以及其他）。 |
| FONT_RESOURCE | 5 | 字体。 |
| SUB_RESOURCE | 6 | 其他子资源。如果实际类型未知，则是默认类型。 |
| OBJECT | 7 | 插件的Object（或embed）标签，或者插件请求的资源。 |
| MEDIA | 8 | 媒体资源。 |
| WORKER | 9 | 专用工作线程的主资源。 |
| SHARED_WORKER | 10 | 共享工作线程的主资源。 |
| PREFETCH | 11 | 明确的预取请求。 |
| FAVICON | 12 | 网站图标。 |
| XHR | 13 | XMLHttpRequest。 |
| PING | 14 | <a ping\>/sendBeacon的Ping请求。 |
| SERVICE_WORKER | 15 | service worker的主资源。 |
| CSP_REPORT | 16 | 内容安全策略违规报告。 |
| PLUGIN_RESOURCE | 17 | 插件请求的资源。 |
| NAVIGATION_PRELOAD_MAIN_FRAME | 19 | 触发service worker预热的主frame跳转请求。 |
| NAVIGATION_PRELOAD_SUB_FRAME | 20 | 触发service worker预热的子frame跳转请求。 |

## RectEvent<sup>12+<sup>

矩形定义。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型       | 可读 | 可写 | 说明                         |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x  | number   | 是   | 是   | 矩形区域左上角x坐标。    |
| y  | number   | 是   | 是   | 矩形区域左上角y坐标。    |
| width  | number   | 是   | 是   | 矩形的宽度。    |
| height  | number   | 是   | 是   | 矩形的高度。    |

## BackForwardCacheSupportedFeatures<sup>12+<sup>

选择性允许使用以下特性的页面进入前进后退缓存。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| nativeEmbed | boolean | 是 | 是否允许使用同层渲染的页面进入前进后退缓存，默认不允许。如果设置为允许，需要维护为同层渲染元素创建的原生控件的生命周期，避免造成泄漏。 |
| mediaTakeOver | boolean | 是 | 是否允许使用视频托管的页面进入前进后退缓存，默认不允许。如果设置为允许，需要维护为视频元素创建的原生控件的生命周期，避免造成泄漏。|

## BackForwardCacheOptions<sup>12+<sup>

前进后退缓存相关设置对象，用来控制web组件前进后退缓存相关选项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| size | number | 是 | 设置每个Web组件允许缓存的最大页面个数。默认为1，最大可设置为50。设置为0或负数时，前进后退缓存功能不生效。Web会根据内存压力对缓存进行回收。 |
| timeToLive | number | 是 | 设置每个Web组件允许页面在前进后退缓存中停留的时间，默认为600秒。设置为0或负数时，前进后退缓存功能不生效。|

## AdsBlockManager<sup>12+</sup>

通过AdsBlockManager可以向Web组件中设置自定义的广告过滤配置、关闭特定网站的广告过滤功能，其中每个应用中的所有Web组件都共享一个AdsBlockManager实例。

### setAdsBlockRules<sup>12+</sup>

static setAdsBlockRules(rulesFile: string, replace: boolean): void

向Web组件中设置自定义的符合通用easylist语法规则的广告过滤配置文件。

> **说明：**
>
> 此接口设置的广告过滤规则，内部解析成功后会持久化存储，应用重启后不需要重复设置。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| rulesFile | string | 是   | 指定了符合 easylist 通用语法的规则文件路径，应用需要有此文件的读权限。 |
| replace   | boolean | 是   | true表示强制替换掉内置的默认规则，false表示设置的自定义规则将与内置规则共同工作。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// 演示点击按钮，通过filepicker打开一个easylist规则文件并设置到Web组件中
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Flex() {
        Button({ type: ButtonType.Capsule }) {
          Text("setAdsBlockRules")
        }
        .onClick(() => {
          try {
            let documentSelectionOptions: ESObject = new picker.DocumentSelectOptions();
            let documentPicker: ESObject = new picker.DocumentViewPicker();
            documentPicker.select(documentSelectionOptions).then((documentSelectResult: ESObject) => {
              if (documentSelectResult && documentSelectResult.length > 0) {
                let fileRealPath = new fileUri.FileUri(documentSelectResult[0]);
                console.info('DocumentViewPicker.select successfully, uri: ' + fileRealPath);
                webview.AdsBlockManager.setAdsBlockRules(fileRealPath.path, true);
              }
            })
          } catch (err) {
            console.error('DocumentViewPicker.select failed with err:' + err);
          }
        })
      }
    }
  }
}
```

### addAdsBlockDisallowedList<sup>12+</sup>

static addAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

向AdsBlockManager的DisallowedList中添加一组域名。广告过滤功能开启时，将禁用这些网站的广告过滤功能。

> **说明：**
>
> 此接口设置的域名不会持久化，应用重启需要重新设置。
>
> 广告过滤特性会使用后缀匹配的方式判断domainSuffix和当前站点的url是否能匹配，例如，当前Web组件打开的网站是https://www.example.com，设置的DisallowList中有'example.com'或者'www.example.com'，后缀匹配成功，此网站将禁用广告过滤，访问'https://m.example.com'也将禁用广告过滤。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | 是   | 一组域名列表，例如['example.com', 'abcd.efg.com'] |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示通过一个按钮的点击向Web组件设置广告过滤的域名策略
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### removeAdsBlockDisallowedList<sup>12+</sup>

static removeAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

从AdsBlockManager的DisallowedList中删除一组域名。

> **说明：**
>
> AdsBlockManager的DisallowedList不会持久化，应用重启需要重新设置。删除不存在的条目不会触发异常。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | 是   | 一组域名列表，例如['example.com', 'abcd.efg.com'] |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示通过一个按钮的点击从AdsBlockManager的DisallowedList中删除域名元素
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### clearAdsBlockDisallowedList<sup>12+</sup>

static clearAdsBlockDisallowedList(): void

清空AdsBlockManager的DisallowedList。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockDisallowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockDisallowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### addAdsBlockAllowedList<sup>12+</sup>

static addAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

向AdsBlockManager的AllowedList中添加一组域名，主要用于重新开启DisallowList中的部分网站的广告过滤。

> **说明：**
>
> 此接口设置的域名不会持久化，应用重启需要重新设置。
>
> AllowedList的优先级比DisAllowList高，例如，DisallowList中配置了['example.com']，禁用了所有example.com域名下的网页，此时如果需要开启'news.example.com'下的广告过滤，可以使用addAdsBlockAllowedList(['news.example.com'])。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | 是   | 一组域名列表，例如['example.com', 'abcd.efg.com'] |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示通过一个按钮的点击向Web组件设置广告过滤的域名策略
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockAllowedList") }
          .onClick(() => {
            let arrDisallowDomainSuffixes = new Array<string>();
            arrDisallowDomainSuffixes.push('example.com');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDisallowDomainSuffixes);

            let arrAllowedDomainSuffixes = new Array<string>();
            arrAllowedDomainSuffixes.push('news.example.com');
            webview.AdsBlockManager.addAdsBlockAllowedList(arrAllowedDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true)
        })
    }
  }
}
```

### removeAdsBlockAllowedList<sup>12+</sup>

static removeAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

从AdsBlockManager的AllowedList中删除一组域名。

> **说明：**
>
> AdsBlockManager的AllowedList不会持久化，应用重启需要重新设置。删除不存在的条目不会触发异常。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | 是   | 一组域名列表，例如['example.com', 'abcd.efg.com'] |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                  |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示通过一个按钮的点击从AdsBlockManager的DisallowedList中删除域名元素
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockAllowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockAllowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### clearAdsBlockAllowedList<sup>12+</sup>

static clearAdsBlockAllowedList(): void

清空AdsBlockManager的AllowedList。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';


  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockAllowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockAllowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
      .onControllerAttached(()=>{
        this.controller.enableAdsBlock(true);
      })
    }
  }
}
```

## SnapshotInfo<sup>12+</sup>

获取全量绘制结果入参。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 |  必填 | 说明 |
|------|------|------|------|
| id | string | 否 | snapshot的id。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)  | 否 | web绘制的尺寸，最多支持16000px * 16000px, 长度单位支持px、vp、%，需保持不同参数传入长度单位一致, 默认单位vp，超过规格时返回最大规格。（示例：width:'100px', height:'200px'。或者 width:'20%', height'30%'。只写数字时单位为vp。）|

## SnapshotResult<sup>12+</sup>

全量绘制回调结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 |  说明 |
|------|------|--|---------|
| id | string | 否 | snapshot的id。|
| status | boolean | 否 |  snapshot的状态，正常为true，失败为false，获取全量绘制结果失败，返回size的长宽都为0，map为空。|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)   | 否 | web绘制的真实尺寸，number类型，单位vp。|
| imagePixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 否 | 全量绘制结果image.pixelMap格式。|

## ScrollType<sup>12+</sup>

Scroll滚动类型，用于[setScrollable](#setscrollable12)。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 值 | 说明                              |
| ------------ | -- |--------------------------------- |
| EVENT  | 0 | 滚动事件，表示通过触摸屏，触摸板，鼠标滚轮生成的网页滚动。|

## PressureLevel<sup>14+</sup>

内存压力等级。在应用主动清理Web组件占用的缓存时，Web内核会根据内存压力等级，进行缓存释放。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
| ------------------------------- | - | ---------- |
| MEMORY_PRESSURE_LEVEL_MODERATE | 1 | 中等内存压力等级。这个等级下，Web内核会尝试释放重新分配开销较小且不需要立即使用的缓存。 |
| MEMORY_PRESSURE_LEVEL_CRITICAL | 2 | 严重内存压力等级。这个等级下，Web内核会尝试释放所有可能的内存缓存。 |

##  PdfConfiguration<sup>14+</sup>

createPdf函数输入参数。

> **说明：**
>
> 英寸与像素之间转换公式：像素 = 96 * 英寸。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                  | 类型    | 必填 | 说明                                                         |
| --------------------- | ------- | ---- | ------------------------------------------------------------ |
| width                 | number  | 是   | 页面宽度。单位：英寸。<br />推荐值：A4纸页面宽度8.27英寸。   |
| height                | number  | 是   | 页面高度。单位：英寸。<br />推荐值：A4纸页面高度11.69英寸。  |
| scale                 | number  | 否   | 放大倍数。取值范围：[0.0, 2.0]。如果不在取值范围内，小于0.0设置为0.0，大于2.0设置为2.0。默认值：1.0。 |
| marginTop             | number  | 是   | 上边距。取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。单位：英寸。 |
| marginBottom          | number  | 是   | 下边距。取值范围：[0.0, 页面高度的一半)。如果不在取值范围内，则设置为0.0。单位：英寸。 |
| marginRight           | number  | 是   | 右边距。取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。单位：英寸。 |
| marginLeft            | number  | 是   | 左边距。取值范围：[0.0, 页面宽度的一半)。如果不在取值范围内，则设置为0.0。单位：英寸。 |
| shouldPrintBackground | boolean | 否   | 是否打印背景颜色。默认值：false。                            |

## PdfData<sup>14+</sup>

createPdf函数输出数据流类。

> **说明：**
>
> 在网页生成PDF过程中，返回的是数据流，由PdfData类封装。

### pdfArrayBuffer<sup>14+</sup>

pdfArrayBuffer(): Uint8Array

获取网页生成的数据流。完整示例代码参考[createPdf](#createpdf14)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型       | 说明     |
| ---------- | -------- |
| Uint8Array | 数据流。 |

## ScrollOffset<sup>13+</sup>

网页当前的滚动偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型   | 可读 | 可写 | 说明                                                         |
| ---- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x    | number | 是   | 是   | 网页在水平方向的滚动偏移量。取值为网页左边界x坐标与Web组件左边界x坐标的差值。单位为vp。<br/>当网页向右过滚动时，取值范围为负值。<br/>当网页没有过滚动或者网页向左过滚动时，取值为0或正值。 |
| y    | number | 是   | 是   | 网页在垂直方向的滚动偏移量。取值为网页上边界y坐标与Web组件上边界y坐标的差值。单位为vp。<br/>当网页向下过滚动时，取值范围为负值。<br/>当网页没有过滚动或者网页向上过滚动时，取值为0或正值。 |
