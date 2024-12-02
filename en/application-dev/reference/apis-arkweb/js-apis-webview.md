# @ohos.web.webview (Webview)

The **Webview** module provides APIs for web control. It can work with the [Web](ts-basic-components-web.md) component, which is used to display web pages.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

**ohos.permission.INTERNET**, required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## once

once(type: string, callback: Callback\<void\>): void

Registers a one-time callback for web events of the specified type. Currently, only **webInited** is supported. This callback is triggered when the Web engine initialization is complete.

When the first **Web** component is loaded in an application, the web engine is initialized. When other **Web** components are loaded in the same application, **once()** is not triggered. When the first **Web** component is loaded after the last **Web** component is destroyed in the application, the web engine will be initialized again.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type             | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| type     | string          | Yes  | Web event type. The value can be **"webInited"**, indicating completion of web initialization.     |
| callback | Callback\<void\> | Yes  | Callback to register.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |

**Example**

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

Implements a WebMessagePort object to send and receive messages. The message of the [WebMessageType](#webmessagetype10)/[WebMessage](#webmessage) type can be sent to the HTML5 side.

### Properties

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Readable| Writable| Description                                             |
| ------------ | ------ | ---- | ---- | ------------------------------------------------|
| isExtentionType<sup>10+</sup> | boolean | Yes  | Yes| Whether to use the extended APIs [postMessageEventExt](#postmessageeventext10) and [onMessageEventExt](#onmessageeventext10) when creating a **WebMessagePort**. The default value is **false**, indicating that the extended APIs are not used.  |

### postMessageEvent

postMessageEvent(message: WebMessage): void

Sends a message of the [WebMessage](#webmessage) type to the HTML5 side. The [onMessageEvent](#onmessageevent) API must be invoked first. Otherwise, the message fails to be sent. For the complete sample code, see [postMessage](#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| message | [WebMessage](#webmessage) | Yes  | Message to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100010 | Failed to post messages through the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Registers a callback to receive messages of the [WebMessage](#webmessage) type from the HTML5 side. For the complete sample code, see [postMessage](#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | :------------------- |
| callback | (result: [WebMessage](#webmessage)) => void | Yes  | Message received.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                       |
| -------- | ----------------------------------------------- |
| 17100006 | Failed to register a message event for the port.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.|

**Example**

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

Sends a message of the [WebMessageType](#webmessagetype10) type to the HTML5 side. The [onMessageEventExt](#onmessageeventext10) API must be invoked first. Otherwise, the message fails to be sent. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| message | [WebMessageExt](#webmessageext10) | Yes  | Message to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100010 | Failed to post messages through the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### onMessageEventExt<sup>10+</sup>

onMessageEventExt(callback: (result: WebMessageExt) => void): void

Registers a callback to receive messages of the [WebMessageType](#webmessagetype10) type from the HTML5 side.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | :------------------- |
| callback | (result: [WebMessageExt](#webmessageext10)) => void | Yes  | Message received.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                       |
| -------- | ----------------------------------------------- |
| 17100006 | Failed to register a message event for the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

// Example of sending messages between an application and a web page: Use the init_web_messageport channel to receive messages from the web page on the application side through port 0 and receive messages from the application on the web page side through port 1.
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
          // Use the local port to send messages to HTML5.
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
          // Use the local port to send messages to HTML5.
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
          // Use the local port to send messages to HTML5.
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
          // Use the local port to send messages to HTML5.
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
          // Use the local port to send messages to HTML5.
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
          // Use the local port to send messages to HTML5.
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
          // 1. Create a message port.
          this.ports = this.controller.createWebMessagePorts(true);
          // 2. Send port 1 to HTML5.
          this.controller.postMessage("init_web_messageport", [this.ports[1]], "*");
          // 3. Save port 0 to the local host.
          this.nativePort = this.ports[0];
          // 4. Set the callback.
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

HTML file to be loaded:
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
            h5Port = event.ports[0]; // 1. Save the port number sent from the eTS side.
            h5Port.onmessage = function(event) {
                console.log("hwd In html got message");
                // 2. Receive the message sent from the eTS side.
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

// Use h5Port to send a message of the string type to the ets side.
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

Closes this message port when messages do not need to be sent. To use this API, a message port must first be created using [createWebMessagePorts](#createwebmessageports).

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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
      // Use createWebMessagePorts to create a message port.
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

Implements a **WebviewController** to control the behavior of the **Web** component. A **WebviewController** can control only one **Web** component, and the APIs (except static APIs) in the **WebviewController** can be invoked only after it has been bound to the target **Web** component.

### constructor<sup>11+</sup>

constructor(webTag?: string)

Constructor used to create a **WebviewController** object.

> **NOTE**
>
> When no parameter is passed in **new webview.WebviewController()**, it indicates that the constructor is empty. If the C API is not used, no parameter needs to be passed.
> 
> When a valid string is passed in, **new webview.WebviewController("xxx")** can be used to distinguish multiple instances and invoke the methods of the corresponding instance.
> 
> When an empty parameter is passed in, such as **new webview.WebviewController("")** or **new webview.WebviewController(undefined)**, the parameter is meaningless that multiple instances cannot be distinguished and **undefined** is returned. You need to check whether the returned value is normal.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| webTag   | string | No  | Name of the **Web** component.|

**Example**

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

HTML file to be loaded:
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

Loads the dynamic link library (DLL) file of the web engine. This API can be called before the **Web** component is initialized to improve the startup performance. The frequently visited websites are automatically pre-connected.

> **NOTE**
>
> - **initializeWebEngine** cannot be called in an asynchronous thread. Otherwise, the system breaks down.
> - **initializeWebEngine** takes effect globally and needs to be called only once in an application lifecycle.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

The following code snippet exemplifies calling this API after the EntryAbility is created.

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

Sets how the Web component uses HTTPDNS for DNS resolution.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| secureDnsMode         |   [SecureDnsMode](#securednsmode10)   | Yes  | Mode in which HTTPDNS is used.|
| secureDnsConfig       | string | Yes| Information about the HTTPDNS server to use, which must use HTTPS. Only one HTTPDNS server can be configured.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |

**Example**

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

Sets whether to enable web debugging. For details, see [Debugging Frontend Pages by Using DevTools](../../web/web-debugging-with-devtools.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webDebuggingAccess | boolean | Yes  | Sets whether to enable web debugging.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Loads a specified URL.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string \| Resource | Yes  | URL to load.     |
| headers | Array\<[WebHeader](#webheader)> | No  | Additional HTTP request header of the URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 17100003 | Invalid resource path or file type.                          |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
            // The URL to be loaded is of the string type.
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
            // The headers parameter is passed.
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

There are three methods for loading local resource files:

1. Using $rawfile
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
            // Load a local resource file through $rawfile.
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

2. Using the resources protocol, which can be used by WebView to load links with a hash (#).
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
            // Load local resource files through the resource protocol.
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

3. Using a sandbox path. For details, see the example of loading local resource files in the sandbox in [Web](ts-basic-components-web.md#web).

HTML file to be loaded:
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

Loads specified data.

When both **baseUrl** and **historyUrl** are empty,

if **encoding** is not base64 (including null values), ASCII encoding is used for octets within the secure URL character range, and the standard %xx hexadecimal encoding of the URL is used for octets outside the secure URL character range.

**data** must be encoded using Base64 or any hash (#) in the content must be encoded as %23. Otherwise, hash (#) is considered as the end of the content, and the remaining text is used as the document fragment identifier.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| data       | string | Yes  | String obtained after being base64 or URL encoded.                   |
| mimeType   | string | Yes  | Media type (MIME).                                          |
| encoding   | string | Yes  | Encoding type, which can be base64 or URL.                      |
| baseUrl    | string | No  | URL (HTTP/HTTPS/data compliant), which is assigned by the **Web** component to **window.origin**.|
| historyUrl | string | No  | URL used for historical records. If this parameter is not empty, historical records are managed based on this URL. This parameter is invalid when **baseUrl** is left empty.|

> **NOTE**
>
> To load a local image, you can assign a space to either **baseUrl** or **historyUrl**. For details, see the sample code.
> In the scenario of loading a local image, **baseUrl** and **historyUrl** cannot be both empty. Otherwise, the image cannot be loaded.
> If the rich text in HTML contains special characters such as hash (#), you are advised to set the values of **baseUrl** and **historyUrl** to spaces.

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

When both **baseUrl** and **historyUrl** are empty:
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
              // UTF-8 is charset.
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
              // Coding tests: string encoded using base64.
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

Example of loading local resource:
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
            // UTF-8 is charset.
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

Checks whether going to the next page can be performed on the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Returns **true** if going to the next page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Moves to the next page based on the history stack. This API is generally used together with **accessForward**.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Checks whether going to the previous page can be performed on the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if going to the previous page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Moves to the previous page based on the history stack. This API is generally used together with **accessBackward**.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Called when the **Web** component enters the active state.
<br>The application can interact with the user while in the active foreground state, and it remains in this state until the focus is moved away from it due to some event (for example, an incoming call is received or the device screen is turned off).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Called when the **Web** component enters the inactive state. You can implement the behavior to perform after the application loses focus.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Called when the **Web** component refreshes the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Checks whether a specific number of steps forward or backward can be performed on the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                                  |
| ------ | -------- | ---- | ------------------------------------------ |
| step   | number   | Yes  | Number of the steps to take. A positive number means to move forward, and a negative number means to move backward.|

**Return value**

| Type   | Description              |
| ------- | ------------------ |
| boolean | Whether moving forward or backward is performed on the current page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Clears the browsing history. You are not advised to call **clearHistory()** in **onErrorReceive()** and **onPageBegin()**. Otherwise, abnormal exit occurs.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the element type of the area being clicked.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [WebHitTestType](#webhittesttype)| Element type of the area being clicked.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Registers a proxy for interaction between the application and web pages loaded by the **Web** component.
<br>Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. After this API is called, call [refresh](#refresh) for the registration to take effect.

> **NOTE**
>
> - It is recommended that **registerJavaScriptProxy** be used only with trusted URLs and over secure HTTPS connections. Injecting JavaScript objects into untrusted web components can expose your application to malicious attacks.
> - After **registerJavaScriptProxy** is called, the application exposes the registered JavaScript object to all page frames.
> - If a **registerJavaScriptProxy** is both registered in the synchronous and asynchronous lists, it is called asynchronously by default.
> - You should register **registerJavaScriptProxy** either in synchronous list or in asynchronous list. Otherwise, this API fails to be registered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                       |
| ---------- | -------------- | ---- | ------------------------------------------------------------ |
| object     | object         | Yes  | Application-side JavaScript object to be registered. Methods and attributes can be declared, but cannot be directly called on HTML5.<br>The parameter and return value can be any of the following types:<br>string, number, boolean.<br>Dictionary or Array, with a maximum of 10 nested layers and 10,000 data records per layer.<br>Object, which must contain the **methodNameListForJsProxy:[fun1, fun2]** attribute, where **fun1** and **fun2** are methods that can be called.<br>The parameter also supports Function and Promise. Their callback cannot have return values.<br>The return value supports Promise. Its callback cannot have a return value.<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).|
| name       | string         | Yes  | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string> | Yes  | Synchronous methods of the JavaScript object to be registered at the application side.                      |
| asyncMethodList<sup>12+</sup> | Array\<string> | No  | Asynchronous methods of the JavaScript object to be registered at the application side. The default value is null. Asynchronous methods cannot obtain return values. |
| permission<sup>12+</sup> | string | No  | JSON string, which is empty by default. This string is used to configure JSBridge permission control and define the URL trustlist at the object and method levels.<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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
For more examples, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).

### runJavaScript

runJavaScript(script: string, callback : AsyncCallback\<string>): void

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

> **NOTE**
>
> The offscreen component does not trigger **runJavaScript()**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string                   | Yes  | JavaScript script.                                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. Returns **null** if the JavaScript script fails to be executed or no value is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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

Executes a JavaScript script. This API uses a promise to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description        |
| ------ | -------- | ---- | ---------------- |
| script | string   | Yes  | JavaScript script.|

**Return value**

| Type           | Description                                               |
| --------------- | --------------------------------------------------- |
| Promise\<string> | Promise used to return the result if the operation is successful and null otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScriptExt** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string \| ArrayBuffer<sup>12+</sup>         | Yes  | JavaScript script.|
| callback | AsyncCallback\<[JsMessageExt](#jsmessageext10)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
// Use the ArrayBuffer input parameter to obtain the JavaScript script data from the file.
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
            // Create a file and open it.
            let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
            // Write data to the file.
            fileIo.writeSync(file.fd, "test()");
            // Read data from the file.
            let arrayBuffer: ArrayBuffer = new ArrayBuffer(6);
            fileIo.readSync(file.fd, arrayBuffer, { offset: 0, length: arrayBuffer.byteLength });
            // Close the file.
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

HTML file to be loaded:
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

Executes a JavaScript script. This API uses a promise to return the script execution result. **runJavaScriptExt** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description        |
| ------ | -------- | ---- | ---------------- |
| script | string \| ArrayBuffer<sup>12+</sup> | Yes  | JavaScript script.|

**Return value**

| Type           | Description                                               |
| --------------- | --------------------------------------------------- |
| Promise\<[JsMessageExt](#jsmessageext10)> | Promise used to return the script execution result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
// Use the ArrayBuffer input parameter to obtain the JavaScript script data from the file.
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
            // Create a file and open it.
            let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
            // Write data to the file.
            fileIo.writeSync(file.fd, "test()");
            // Read data from the file.
            let arrayBuffer: ArrayBuffer = new ArrayBuffer(6);
            fileIo.readSync(file.fd, arrayBuffer, { offset: 0, length: arrayBuffer.byteLength });
            // Close the file.
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

HTML file to be loaded:
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

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. After the deletion, the [refresh](#refresh) API must be called.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description |
| ------ | -------- | ---- | ---- |
| name   | string   | Yes  | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100008 | Failed to delete JavaScriptProxy because it does not exist.                               |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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

Zooms in or out of this web page. This API is effective only when [zoomAccess](ts-basic-components-web.md#zoomaccess) is **true**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | Yes  | Relative zoom ratio. The value must be greater than 0. The value **1** indicates that the page is not zoomed. A value smaller than **1** indicates zoom-out, and a value greater than **1** indicates zoom-in.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Searches the web page for content that matches the keyword specified by **'searchString'** and highlights the matches on the page. This API returns the result asynchronously through [onSearchResultReceive](ts-basic-components-web.md#onsearchresultreceive9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type| Mandatory| Description      |
| ------------ | -------- | ---- | -------------- |
| searchString | string   | Yes  | Search keyword.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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

Clears the matches found through [searchAllAsync](#searchallasync).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

For details about the HTML file loaded, see the HMTL file loaded using [searchAllAsync](#searchallasync).

### searchNext

searchNext(forward: boolean): void

Searches for and highlights the next match.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type| Mandatory| Description              |
| ------- | -------- | ---- | ---------------------- |
| forward | boolean  | Yes  | Whether to search forward.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HMTL file loaded using [searchAllAsync](#searchallasync).

### clearSslCache

clearSslCache(): void

Clears the user operation corresponding to the SSL certificate error event recorded by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Clears the user operation corresponding to the client certificate request event recorded by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Creates web message ports. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | :------------------------------|
| isExtentionType<sup>10+</sup>   | boolean     | No | Whether to use the extended interface. The default value is **false**, indicating that the extended interface is not used.|

**Return value**

| Type                  | Description             |
| ---------------------- | ----------------- |
| Array\<[WebMessagePort](#webmessageport)> | List of web message ports.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Sends a web message to an HTML window.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | :------------------------------- |
| name   | string                 | Yes  | Name of the message to send.           |
| ports  | Array\<[WebMessagePort](#webmessageport)> | Yes  | Message ports for sending the message.           |
| uri    | string                 | Yes  | URI for receiving the message.               |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
      // Display the received HTML content.
      Text(this.receivedFromHtml)
      // Send the content in the text box to an HTML window.
      TextInput({ placeholder: 'Send this message from ets to HTML' })
        .onChange((value: string) => {
          this.sendFromEts = value;
        })

      Button('postMessage')
        .onClick(() => {
          try {
            // 1. Create two message ports.
            this.ports = this.controller.createWebMessagePorts();
            // 2. Register a callback on a message port (for example, port 1) on the application side.
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
            // 3. Send another message port (for example, port 0) to the HTML side, which can then save the port for future use.
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // 4. Use the port on the application side to send messages to the port that has been sent to the HTML side.
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

HTML file to be loaded:
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
            h5Port = event.ports[0]; // 1. Save the port number sent from the eTS side.
            h5Port.onmessage = function (event) {
              // 2. Receive the message sent from the eTS side.
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

// 3. Use h5Port to send messages to the eTS side.
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

Requests focus for this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Zooms in on this web page by 20%.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |

**Example**

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

Zooms out of this web page by 20%.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enabled.                                         |

**Example**

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

Obtains the element information of the area being clicked.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type        | Description                |
| ------------ | -------------------- |
| [HitTestValue](#hittestvalue) | Element information of the area being clicked.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the index value of this **Web** component, which can be used for **Web** component management.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| number | Index value of the current **Web** component.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the default user agent of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description          |
| ------ | -------------- |
| string | Default user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

You can define a custom user agent based on the default user agent.
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
        // Define a custom user agent on the application side.
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

Obtains the title of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Title of the current web page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the height of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Height of the current web page. Unit: vp|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Stores this web page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type             | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| baseName | string                | Yes  | Save path of the web page. The value cannot be null.                                |
| autoName | boolean               | Yes  | Whether to automatically generate a file name. The value **false** means not to automatically generate a file name. The value **true** means to automatically generate a file name based on the URL of the current page and the **baseName** value.|
| callback | AsyncCallback\<string> | Yes  | Callback used to return the save path if the operation is successful and null otherwise.                  |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**Example**

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

Stores this web page. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type| Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| baseName | string   | Yes  | Save path of the web page. The value cannot be null.                                |
| autoName | boolean  | Yes  | Whether to automatically generate a file name. The value **false** means not to automatically generate a file name. The value **true** means to automatically generate a file name based on the URL of the current page and the **baseName** value.|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<string> | Promise used to return the save path if the operation is successful and null otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**Example**

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

Obtains the URL of this page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description               |
| ------ | ------------------- |
| string | URL of the current page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Stops page loading.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Performs a specific number of steps forward or backward on the current page based on the history stack. No redirection will be performed if the corresponding page does not exist in the history stack.

Because the previously loaded web pages are used for the operation, no page reloading is involved.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| step   | number   | Yes  | Number of the steps to take.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

scrollTo(x:number, y:number): void

Scrolls the page to the specified absolute position.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| x   | number   | Yes  | X coordinate of the absolute position. If the value is a negative number, the value 0 is used. Unit: vp|
| y   | number   | Yes  | Y coordinate of the absolute position. If the value is a negative number, the value 0 is used. Unit: vp|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
            this.controller.scrollTo(50, 50);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

HTML file to be loaded:
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

Scrolls the page by the specified amount.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | Yes  | Amount to scroll by along the x-axis. The positive direction is rightward. Unit: vp|
| deltaY | number   | Yes  | Amount to scroll by along the y-axis. The positive direction is downward. Unit: vp|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

> **NOTE**
>
> Calling **scrollBy** does not trigger the nested scrolling of the parent component.

**Example**

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
            this.controller.scrollBy(50, 50);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

HTML file to be loaded:
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
### scrollByWithResult<sup>12+</sup>

scrollByWithResult(deltaX: number, deltaY: number): boolean

Scrolls the page by the specified amount and returns value to indicate whether the scrolling is successful.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | Yes  | Amount to scroll by along the x-axis. The positive direction is rightward.|
| deltaY | number   | Yes  | Amount to scroll by along the y-axis. The positive direction is downward.|

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether the current web page can be scrolled. The default value is **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

> **NOTE**
>
> - If the web page is being touched, **false** is returned. Otherwise, **true** is returned.
> - If the rendering area at the same layer of the web page is being touched, **true** is returned.
> - Calling **scrollByWithResult** does not trigger the nested scrolling of the parent component.
> - This API does not support the high frame rate of scrolling performance.

**Example**

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

HTML file to be loaded:
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

Simulates a slide-to-scroll action on the page at the specified velocity.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| vx     | number   | Yes  | Horizontal velocity component of the slide-to-scroll action, where the positive direction is rightward. Unit: vp/ms.|
| vy     | number   | Yes  | Vertical velocity component of the slide-to-scroll action, where the positive direction is downward. Unit: vp/ms.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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

Obtains the original URL of this page.
Risk warning: If you want to obtain the URL for JavaScriptProxy communication API authentication, use [getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](#getlastjavascriptproxycallingframeurl12).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                   |
| ------ | ----------------------- |
| string | Original URL of the current page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the favicon of this page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                  | Description                           |
| -------------------------------------- | ------------------------------- |
| [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | **PixelMap** object of the favicon of the page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets the **window.navigator.onLine** attribute in JavaScript.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | --------------------------------- |
| enable | boolean | Yes  | Whether to enable **window.navigator.onLine**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

HTML file to be loaded:
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<h1>online attribute </h1>
<p id="demo"></p>
<button onclick="func()">click</button>
<script>
    let online = navigator.onLine;
    document.getElementById ("demo").innerHTML = "Browser online:" + online;

    function func(){
      var online = navigator.onLine;
      document.getElementById ("demo").innerHTML = "Browser online:" + online;
    }
</script>
</body>
</html>
```

### hasImage

hasImage(callback: AsyncCallback\<boolean>): void

Checks whether this page contains images. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                      |
| -------- | ----------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Checks whether this page contains images. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**Example**

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

Clears the cache in the application. This API will clear the cache for all webviews in the same application.

> **NOTE**
>
> You can view the Webview cache in the **data/storage/el2/base/cache/web/Cache**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| clearRom | boolean | Yes  | Whether to clear the cache in the ROM and RAM at the same time. The value **true** means to clear the cache in the ROM and RAM at the same time, and **false** means to only clear the cache in the RAM.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Scrolls the page up by half the viewport or jumps to the top of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| top    | boolean | Yes  | Whether to jump to the top of the page. The value **true** means to jump to the top of the page; and **false** means to scroll the page up by half the viewport.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Scrolls the page down by half the viewport or jumps to the bottom of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| bottom | boolean | Yes  | Whether to jump to the bottom of the page. The value **true** means to jump to the bottom of the page; and **false** means to scroll the page down by half the viewport.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Obtains the historical information list of the current webview.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| [BackForwardList](#backforwardlist) | The historical information list of the current webview.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Serializes the page status history of the current Webview.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type      | Description                                         |
| ---------- | --------------------------------------------- |
| Uint8Array | Serialized data of the page status history of the current WebView.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

1. To perform operations on files, you must first import the **fs** module. For details, see [File Management](../apis-core-file-kit/js-apis-file-fs.md).
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
              // Synchronously open a file.
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

2. Modify the **EntryAbility.ets** file.
Obtain the path of the application cache file.
```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        // Data synchronization between the UIAbility component and the page can be implemented by binding cacheDir to the AppStorage object.
        AppStorage.setOrCreate("cacheDir", this.context.cacheDir);
    }
}
```

### restoreWebState

restoreWebState(state: Uint8Array): void

Restores the page status history from the serialized data of the current WebView.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type      | Mandatory| Description                        |
| ------ | ---------- | ---- | ---------------------------- |
| state  | Uint8Array | Yes  | Serialized data of the page status history.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

1. To perform operations on files, you must first import the **fs** module. For details, see [File Management](../apis-core-file-kit/js-apis-file-fs.md).
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
              // Synchronously open a file.
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

2. Modify the **EntryAbility.ets** file.
Obtain the path of the application cache file.
```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // Data synchronization between the UIAbility component and the page can be implemented by binding cacheDir to the AppStorage object.
    AppStorage.setOrCreate("cacheDir", this.context.cacheDir);
  }
}
```

### customizeSchemes

static customizeSchemes(schemes: Array\<WebCustomScheme\>): void

Grants the cross-domain request and fetch request permissions for the specified URL schemes (also known as protocols) to the web kernel. A cross-domain fetch request for any of the specified URL schemes can be intercepted by the **onInterceptRequest** API, so that you can further process the request. It is recommended that this API be called before any **Web** component is initialized.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| schemes | Array\<[WebCustomScheme](#webcustomscheme)\> | Yes  | Array of up to 10 custom schemes.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |
| 17100020 | Failed to register custom schemes. |

**Example**

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

Obtains the certificate information of this website. When the **Web** component is used to load an HTTPS website, SSL certificate verification is performed. This API uses a promise to return the [X.509 certificate](../apis-device-certificate-kit/js-apis-cert.md#x509cert) of the current website.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type      | Description                                         |
| ---------- | --------------------------------------------- |
| Promise<Array<cert.X509Cert>> | Promise used to obtain the X.509 certificate array of the current HTTPS website.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a web component. |

**Example**

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
  // outputStr displays debug information on the UI.
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
              // Load an expired certificate website and view the obtained certificate information.
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
              // Load an HTTPS website and view the certificate information of the website.
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
            // Ignore SSL certificate errors to test websites whose certificates have expired, for example, https://expired.badssl.com.
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

Obtains the certificate information of this website. When the **Web** component is used to load an HTTPS website, SSL certificate verification is performed. This API uses an asynchronous callback to return the [X.509 certificate](../apis-device-certificate-kit/js-apis-cert.md#x509cert) of the current website.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                    |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<Array<cert.X509Cert>> | Yes  | Callback used to obtain the X.509 certificate array of the current website.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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
  // outputStr displays debug information on the UI.
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
              // Load an expired certificate website and view the obtained certificate information.
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
              // Load an HTTPS website and view the certificate information of the website.
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
            // Ignore SSL certificate errors to test websites whose certificates have expired, for example, https://expired.badssl.com.
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

Mutes this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| mute | boolean | Yes  | Whether to mute the web page. The value **true** means to mute the web page, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Prefetches resources in the background for a page that is likely to be accessed in the near future, without executing the page JavaScript code or presenting the page. This can significantly reduce the load time for the prefetched page.

> **NOTE**
>
> The downloaded page resources are cached for about 5 minutes. After this period, the **Web** component automatically releases the resources.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type                            | Mandatory | Description                     |
| ------------------| --------------------------------| ---- | ------------- |
| url               | string                          | Yes   | URL to be preloaded.|
| additionalHeaders | Array\<[WebHeader](#webheader)> | No   | Additional HTTP headers of the URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**Example**

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
            // Replace 'https://www.example.com' with a real URL for the API to work.
            this.controller.prefetchPage('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // Replace ''www.example1.com' with a real URL for the API to work.
      Web({ src: 'www.example1.com', controller: this.controller })
    }
  }
}
```

### prefetchResource<sup>12+</sup>

static prefetchResource(request: RequestInfo, additionalHeaders?: Array\<WebHeader>, cacheKey?: string, cacheValidTime?: number): void

Prefetches resource requests based on specified request information and additional HTTP request headers, saves the requests to the memory cache, and specifies the cache key and validity period to accelerate loading. Currently, only POST requests whose Content-Type is application/x-www-form-urlencoded are supported. A maximum of six POST requests can be pre-obtained. To prefetch the seventh post request, call [clearPrefetchedResource](#clearprefetchedresource12) to clear the cache of unnecessary post requests. Otherwise, the cache of the earliest prefetched POST request will be automatically cleared. To use the prefetched resource cache, you need to add the key value **ArkWebPostCacheKey** to the header of the POST request. The content of the key value is the cacheKey of the corresponding cache.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type                            |  Mandatory | Description                                                             |
| ------------------| ------------------------------- | ---- | ------------------------------------------------------------------ |
| request           | [RequestInfo](#requestinfo12)   | Yes  | Information about the prefetched request.                                                     |
| additionalHeaders | Array\<[WebHeader](#webheader)> | No  | Additional HTTP request header of the prefetched request.                                            |
| cacheKey          | string                          | No  | Key used to query the cache of prefetched resources. The value can contain only letters and digits. If this parameter is not passed or is left empty, **url** is used by default.|
| cacheValidTime    | number                          | No  | Validity period for caching prefetched resources. Value range: (0, 2147483647] Unit: second. Default value: **300s**         |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |
| 17100002 | Invalid url.                                                 |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Replace "https://www.example1.com/post?e=f&g=h" with the actual website address to visit. 
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

Clears the cache of prefetched resources based on the specified cache key list. The cache key in the input parameter must be the prefetched resource cache key specified by [prefetchResource](#prefetchresource12).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type       | Mandatory | Description                                                                      |
| ------------------| ----------- | ---- | ------------------------------------------------------------------------- |
| cacheKeyList      | Array\<string>      | Yes  | Key used to query the cache of prefetched resources. The value can contain only letters and digits. If this parameter is not passed or is left empty, **url** is used by default.|

**Example**

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
          // Replace "https://www.example1.com/post?e=f&g=h" with the actual website address to visit. 
          webview.WebviewController.prefetchResource(
            {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
            [{headerKey:"c",
              headerValue:"z",},],
            "KeyX", 500);
        })
        .onPageEnd(() => {
          // Clear the prefetch cache that is no longer used.
          webview.WebviewController.clearPrefetchedResource(["KeyX",]);
        })
    }
  }
}
```

### prepareForPageLoad<sup>10+</sup>

static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void

Preconnects to a URL. This API can be called before the URL is loaded, to resolve the DNS and establish a socket connection, without obtaining the resources.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| url            | string  | Yes  | URL to be preconnected.|
| preconnectable | boolean | Yes  | Whether to perform preconnection, which involves DNS resolution and socket connection establishment. The value **true** means to perform preconnection, and **false** means the opposite.|
| numSockets     | number  | Yes  | Number of sockets to be preconnected. The value must be greater than 0. A maximum of six socket connections are allowed.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100002 | Invalid url.                                                 |
| 171000013| The number of preconnect sockets is invalid.                                                 |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Replace 'https://www.example.com' with a real URL for the API to work.
    webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

### setCustomUserAgent<sup>10+</sup>

setCustomUserAgent(userAgent: string): void

Sets a custom user agent, which will overwrite the default user agent.

When a URL is set for the **Web** component **src**, you are advised to set UserAgent in the onControllerAttached callback event. For details, see the example. You are not advised to set **UserAgent** in the **onLoadIntercept** callback event. Otherwise, the setting may fail occasionally.

When **src** of the **Web** component is set to an empty string, you are advised to call the **setCustomUserAgent** method to set **UserAgent** and then use **loadUrl** to load a specific page.

> **NOTE**
>
>If a URL is set for the **Web** component **src**, and **UserAgent** is not set in the **onControllerAttached** callback event, calling **setCustomUserAgent** again may result in the loaded page being inconsistent with the actual user agent.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | Yes  | Information about the custom user agent. It is recommended that you obtain the current default user agent through [getUserAgent](#getuseragent) and then customize the obtained user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State customUserAgent: string = 'test';

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

Sets a **WebDownloadDelegate** object to receive downloads and download progress triggered from a page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](#webdownloaddelegate11)  | Yes  | Delegate used to receive the download progress.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Downloads a file, such as an image, from the specified URL.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| url      | string  | Yes  | Download URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url. |

**Example**

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

Obtains a custom user agent.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Information about the custom user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets the network connection timeout. You can use the **onErrorReceive** method in the **Web** component to obtain the timeout error code.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| timeout        | number  | Yes  | Socket connection timeout interval, in seconds. The value of socket must be an integer greater than 0.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

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

Warms up the ServiceWorker to enhance the loading speed of the first screen (only applicable to pages that will use ServiceWorker). This API is called before the URL is loaded.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| url            | string  | Yes  | URL of the ServiceWorker to warm up.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100002 | Invalid url.                                                 |

**Example**

```ts
// xxx.ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        webview.WebviewController.initializeWebEngine();
        webview.WebviewController.warmupServiceWorker("https://www.example.com");
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

### enableSafeBrowsing<sup>11+</sup>

enableSafeBrowsing(enable: boolean): void

<!--RP1-->Enables the safe browsing feature. This feature is forcibly enabled and cannot be disabled for identified untrusted websites.
By default, this feature does not take effect. OpenHarmony provides only the malicious website blocking web UI. The website risk detection and web UI display features are implemented by the vendor. You are advised to listen for [DidStartNavigation](https://gitee.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidStartNavigation) and [DidRedirectNavigation](https://gitee.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidRedirectNavigation) in **WebContentsObserver** to detect risks.
<!--RP1End-->

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable the safe browsing feature.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Checks whether the safe browsing feature is enabled for this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether the safe browsing feature is enabled. The default value is **false**.|

**Example**

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

Enables intelligent tracking prevention. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable intelligent tracking prevention.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Obtains whether intelligent tracking prevention is enabled on this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether intelligent tracking prevention is enabled on the current web page. The default value is **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Adds a list of domain names that bypass intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | Yes  | List of domain names that bypass intelligent tracking prevention.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Deletes the domain names from the list of domain names added through the **addIntelligentTrackingPreventionBypassingList** API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | Yes  | List of domain names that bypass intelligent tracking prevention.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Deletes all domain names from the list of domain names added through the **addIntelligentTrackingPreventionBypassingList** API.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Enables ad blocking. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable ad blocking.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |

**Example**

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

Checks whether ad blocking is enabled. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | Returns **true** if ad blocking is enabled; returns **false** otherwise.|

**Example**

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

Checks whether ad blocking is enabled on this web page.
After ads blocking is enabled for the **Web** component, this feature is enabled for all web pages by default. You can call [addAdsBlockDisallowedList](#addadsblockdisallowedlist12) to disable the feature for specific domains.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | Returns **true** if ad blocking is enabled; returns **false** otherwise.|

**Example**

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

Sets the ArkWeb render subprocess mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| mode        | [RenderProcessMode](#renderprocessmode12)| Yes  | Render subprocess mode. You can call [getRenderProcessMode()](#getrenderprocessmode12) to view the ArkWeb rendering subprocess mode of the current device. The enumerated value **0** indicates the single render subprocess mode, and **1** indicates the multi-render subprocess mode. If an invalid number other than the enumerated value of **RenderProcessMode** is passed, the  multi-render subprocess mode is used by default.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Obtains the ArkWeb render subprocess mode.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| [RenderProcessMode](#renderprocessmode12) | Render subprocess mode. You can call [getRenderProcessMode()](#getrenderprocessmode12) to obtain the ArkWeb render subprocess mode of the current device. The enumerated value **0** indicates the single render subprocess mode, and **1** indicates the multi-render subprocess mode. If the obtained value is not an enumerated value of **RenderProcessMode**, the multi-render subprocess mode is used by default.|


**Example**

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

Terminates this render process.

Calling this API will destroy the associated render process. If the render process has not been started or has been destroyed, there is no impact. In addition, destroying the render process affects all other instances associated with the render process.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | Result of destroying the render process. If the render process can be destroyed, **true** is returned. Otherwise, **false** is returned. If the rendering process is destroyed, **true** is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Loads the specified URL with **postData** using the POST method. If **url** is not a network URL, it will be loaded with [loadUrl](#loadurl) instead, and the **postData** parameter will be ignored.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string | Yes  | URL to load.     |
| postData | ArrayBuffer | Yes  | Data to transfer using the POST method. The request must be encoded in "application/x-www-form-urlencoded" format.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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
            // Convert data to the ArrayBuffer type.
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

Creates a **PrintDocumentAdapter** instance to provide content for printing.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| jobName | string | Yes  | Name of the file to print.     |

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| print.printDocumentAdapter | **PrintDocumentAdapter** instance created.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                                   |
| -------- | -------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Checks whether this Webview is in incognito mode.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| boolean              | Whether the Webview is in incognito mode.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                                   |
| -------- | -------------------------------------------------------------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the security level of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| [SecurityLevel](#securitylevel11) | Security level of the web page. The value can be **NONE**, **SECURE**, **WARNING**, or **DANGEROUS**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets whether this web page is scrollable.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| enable     | boolean   | Yes  | Whether the web page is scrollable. The value **true** means the web page is scrollable, and **false** means the opposite.|
| type       | [ScrollType](#scrolltype12) |  No| Scrolling type supported by the web page. The default value is supported.<br> - If the value of **enable** is set to **false**, the specified **ScrollType** is disabled. If **ScrollType** is set to the default value, all scrolling types are disabled.<br> - If the value of **enable** is set to **true**, all scrolling types are enabled regardless of the value of **ScrollType**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains whether this web page is scrollable.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description          |
| ------ | -------------- |
| boolean | Whether the web page is scrollable. The value **true** means the web page is scrollable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets whether to print the web page background.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| enable | boolean | Yes  | Whether to print the web page background. The value **true** means to print the web page background, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains whether the web page background is printed.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| boolean              | Whether the web page background is printed.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Obtains the URL of the frame from which the last JavaScript proxy object was called. You can inject a JavaScript object into the window object using APIs like [registerJavaScriptProxy](#registerjavascriptproxy) or [javaScriptProxy](ts-basic-components-web.md#javascriptproxy). This API can be used to obtain the URL of the frame of the object that is injected last time.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

HTML file to be loaded:
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

Pauses all WebView timers.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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
HTML file to be loaded:

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

Resumes all timers that are paused from the **pauseAllTimers()** API.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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
HTML file to be loaded:

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

Stops all audio and video on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Pauses all audio and video on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Resumes the playback of the audio and video that are paused by the pauseAllMedia interface.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Closes all full-screen videos on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Queries the current audio and video playback control status.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                       | Description                                                     |
| ------------------------------------------- | --------------------------------------------------------- |
| [MediaPlaybackState](#mediaplaybackstate12) | Playback control status of the current web page. The options are **NONE**, **PLAYING**, **PAUSED**, and **STOPPED**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets the [WebSchemeHandler](#webschemehandler12), [WebSchemeHandler](#webschemehandler12) class for the current Web component to intercept requests of a specified scheme.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | Yes  | Protocol to be intercepted.|
| handler    | [WebSchemeHandler](#webschemehandler12) | Yes  | Interceptor that intercepts this protocol.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types.                                    |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Clears all WebSchemeHandlers set for the current Web component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

Sets the WebSchemeHandler used to intercept ServiceWorker for all Web components of the current application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | Yes  | Protocol to be intercepted.|
| handler    | [WebSchemeHandler](#webschemehandler12) | Yes  | Interceptor that intercepts this protocol.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

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

Clears all WebSchemeHandlers that are set in the application and used to intercept ServiceWorker.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Enables the camera capture of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**
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
HTML file to be loaded:
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
    <input type="button" title="HTML5 Camera" value="Enable Camera" onclick="getMedia()"/>
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

Stops the camera capture of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

For the complete sample code, see [startCamera](#startcamera12).

### closeCamera<sup>12+</sup>

closeCamera(): void

Disables the camera capture of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

For the complete sample code, see [startCamera](#startcamera12).

### precompileJavaScript<sup>12+</sup>

precompileJavaScript(url: string, script: string | Uint8Array, cacheOptions: CacheOptions): Promise\<number\>

Precompiles JavaScript to generate the bytecode cache or update the existing bytecode cache based on the provided parameters.
The API determines whether to update the existing bytecode cache based on the provided file information, E-Tag response header, and Last-Modified response header.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| url | string | Yes  | Network address corresponding to the local JavaScript file, that is, the network address used when the service web page requests the server version of the file. The network address supports only the HTTP and HTTPS protocols and contains a maximum of 2048 characters. If the cache corresponding to the network address is invalid, the service web page requests the corresponding resource through the network.     |
| script | string \| Uint8Array | Yes  | Text content of the local JavaScript. The content cannot be empty.     |
| cacheOptions | [CacheOptions](#cacheoptions12) | Yes  | Whether to update the bytecode cache.     |

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| Promise\<number\> | Promise used to return the error code for generating the bytecode cache. The value **0** indicates no error, and the value **-1** indicates an internal error.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

The API is recommended for use in conjunction with dynamic components. Employ offline **Web** components to generate bytecode caches, and at the appropriate time, load service **Web** components to utilize these bytecode caches. The following is a code example:

1. Save **UIContext** to localStorage in **EntryAbility**.

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

2. Write the basic code required by the dynamic component.

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

3. Write a component for generating bytecode caches. In this example, the local JavaScript resource content is read through the file reading API from a local file in the **rawfile** directory.

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

JavaScript resources can also be obtained through [network requests](../apis-network-kit/js-apis-http.md). However, the HTTP response header obtained using this method is not in the standard HTTP response header format. Additional steps are required to convert the response header into the standard HTTP response header format before use. If the response header obtained through a network request is e-tag, convert it to E-Tag before using it.

4. Compile the code of the service component.

   <!--code_no_check-->
   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // The component can be extended based on service requirements.
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. Write the resource configuration information.

   ```ts
   // PrecompileConfig.ets
   import { webview } from '@kit.ArkWeb'

   export interface Config {
     url:  string,
     localPath: string, // Local resource path
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

6. Use the component on the page.

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
       // Initialize the Web component used to inject local resources.
       this.precompileNode = createNode(precompileWebview,
         { url: "https://www.example.com/empty.html", controller: this.precompileController});
     }

     build() {
       Column() {
         // Load the Web component used by the service at a proper time. In this example, the button is clicked.
         Button ("Load Page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url:  "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

To update the locally generated compiled bytecode, change the value of E-Tag or Last-Modified in responseHeaders of the cacheOptions parameter and call the API again.

### onCreateNativeMediaPlayer<sup>12+</sup>

onCreateNativeMediaPlayer(callback: CreateNativeMediaPlayerCallback): void

Called when the [application takes over media playback on the web page](ts-basic-components-web.md#enablenativemediaplayer12) and media is played on the web page.
If the application does not take over media playback on the web page, this callback is not invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| callback | [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) | Yes| Callback when the application takes over media playback on the web page.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

class ActualNativeMediaPlayerListener {
  handler: webview.NativeMediaPlayerHandler;

  constructor(handler: webview.NativeMediaPlayerHandler) {
    this.handler = handler;
  }

  onPlaying() {
    // The native media player starts playback.
    this.handler.handleStatusChanged(webview.PlaybackStatus.PLAYING);
  }
  onPaused() {
    // The native media player pauses the playback.
    this.handler.handleStatusChanged(webview.PlaybackStatus.PAUSED);
  }
  onSeeking() {
    // The local player starts to jump to the target time point.
    this.handler.handleSeeking();
  }
  onSeekDone() {
    // The native media player seeks to the target time point.
    this.handler.handleSeekFinished();
  }
  onEnded() {
    // The playback on the native media player is ended.
    this.handler.handleEnded();
  }
  onVolumeChanged() {
    // Obtain the volume of the local player.
    let volume: number = getVolume();
    this.handler.handleVolumeChanged(volume);
  }
  onCurrentPlayingTimeUpdate() {
    // Update the playback time.
    let currentTime: number = getCurrentPlayingTime();
    // Convert the time unit to second.
    let currentTimeInSeconds = convertToSeconds(currentTime);
    this.handler.handleTimeUpdate(currentTimeInSeconds);
  }
  onBufferedChanged() {
    // The cache is changed.
    // Obtain the cache duration of the native media player.
    let bufferedEndTime: number = getCurrentBufferedTime();
    // Convert the time unit to second.
    let bufferedEndTimeInSeconds = convertToSeconds(bufferedEndTime);
    this.handler.handleBufferedEndTimeChanged(bufferedEndTimeInSeconds);

    // Check the cache status.
    // If the cache status changes, notify the ArkWeb engine of the cache status.
    let lastReadyState: webview.ReadyState = getLastReadyState();
    let currentReadyState:  webview.ReadyState = getCurrentReadyState();
    if (lastReadyState != currentReadyState) {
      this.handler.handleReadyStateChanged(currentReadyState);
    }
  }
  onEnterFullscreen() {
    // The native media player enters the full screen mode.
    let isFullscreen: boolean = true;
    this.handler.handleFullscreenChanged(isFullscreen);
  }
  onExitFullscreen() {
    // The native media player exits the full screen mode.
    let isFullscreen: boolean = false;
    this.handler.handleFullscreenChanged(isFullscreen);
  }
  onUpdateVideoSize(width: number, height: number) {
    // Notify the ArkWeb kernel when the native media player parses the video width and height.
    this.handler.handleVideoSizeChanged(width, height);
  }
  onDurationChanged(duration: number) {
    // Notify the ArkWeb kernel when the native media player parses the video duration.
    this.handler.handleDurationChanged(duration);
  }
  onError(error: webview.MediaError, errorMessage: string) {
    // Notify the ArkWeb kernel that an error occurs in the native media player.
    this.handler.handleError(error, errorMessage);
  }
  onNetworkStateChanged(state: webview.NetworkState) {
    // Notify the ArkWeb kernel that the network state of the native media player changes.
    this.handler.handleNetworkStateChanged(state);
  }
  onPlaybackRateChanged(playbackRate: number) {
    // Notify the ArkWeb kernel that the playback rate of the native media player changes.
    this.handler.handlePlaybackRateChanged(playbackRate);
  }
  onMutedChanged(muted: boolean) {
    // Notify the ArkWeb kernel that the native media player is muted.
    this.handler.handleMutedChanged(muted);
  }

  // Listen for other state of the native media player.
}

class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
  constructor(handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {
    // 1. Create a listener for the native media player.
    let listener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
    // 2. Create a native media player.
    // 3. Listen for the local player.
    // ...
  }

  updateRect(x: number, y: number, width: number, height: number) {
    // The position and size of the <video> tag are changed.
    // Make changes based on the information change.
  }

  play() {
    // Start the native media player for playback.
  }

  pause() {
    //Pause the playback on the local player.
  }

  seek(targetTime: number) {
    // The local player jumps to a specified time point.
  }

  release() {
    // Destroy the local player.
  }

  setVolume(volume: number) {
    // The ArkWeb kernel requires to adjust the volume of the native player.
    // Set the volume of the local player.
  }

  setMuted(muted: boolean) {
    // Mute or unmute the local player.
  }

  setPlaybackRate(playbackRate: number) {
    // Adjust the playback speed of the local player.
  }

  enterFullscreen() {
    // Set the local player to play in full screen mode.
  }

  exitFullscreen() {
    // Set the local player to exit full screen mode.
  }

  resumePlayer() {
    // Create a player again.
    // Resume the status information of the player.
  }

  suspendPlayer(type: webview.SuspendType) {
    // Record the status information of the player.
    // Destroy the player.
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
              // The local player does not take over the media.
              // The ArkWeb engine will play the media with its own player.
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

Enables the full drawing capability for the web page. This API works only during **Web** component initialization.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Obtains the full drawing result of the web page. (Local resource web pages are not supported currently.)

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| info        | [SnapshotInfo](#snapshotinfo12)| Yes  | Information for obtaining the full drawing result.|
| callback        | [SnapshotResult](#snapshotresult12)| Yes  | Callback used to return the result.|

**Example**

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
                // You can process the returned result as required.
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

Injects local offline resources to the memory cache to improve the initial page startup speed.
Resources in the memory cache are automatically managed by the ArkWeb engine. When the injected resources are excessive and cause significant memory pressure, the engine will automatically release unused resources. It is advisable to avoid injecting a large number of resources into the memory cache.
Under normal circumstances, the validity period of the resources is controlled by the provided Cache-Control or Expires response header, with a default validity period of 86,400 seconds, which is one day.
The MIME type of the resources is configured through the provided Content-Type response header. The Content-Type must comply with standards; otherwise, the resources cannot be used correctly. For resources of type MODULE_JS, a valid MIME type must be provided. For other types, the MIME type is optional.
Resources injected in this mode can be loaded only through HTML tags. If the script tag on the business web page uses the **crossorigin** attribute, you must set the Cross-Origin response header to anonymous or use-credentials in the responseHeaders parameter of the interface.
After **web_webview.WebviewController.SetRenderProcessMode(web_webview.RenderProcessMode.MULTIPLE)** is called, the application starts the multi-rendering process mode. This API does not take effect in this scenario.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| resourceMaps | Array\<[OfflineResourceMap](#offlineresourcemap12)\> | Yes  | Configuration object for local offline resources. A maximum of 30 resources can be injected in a single call, with a maximum size of 10 MB per individual resource.     |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**Example**

When appropriate, use this API in conjunction with dynamic components. Offline **Web** components are used to inject resources into the engine's memory cache, and at the appropriate time, the service **Web** components load and utilize these resources. The following is a code example:
1. Save **UIContext** to localStorage in **EntryAbility**.

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

2. Write the basic code required by the dynamic component.

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

3. Write the component code for injecting resources. In this example, the local resource content reads the local file in the **rawfile** directory through the file reading API.

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

     // Read the configuration and read the file content from the rawfile directory.
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

4. Compile the code of the service component.

   <!--code_no_check-->
   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // The component can be extended based on service requirements.
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. Write the resource configuration information.

   ```ts
   // Resource.ets
   import { webview } from '@kit.ArkWeb';

   export interface ResourceConfig {
     urlList: Array<string>,
     type: webview.OfflineResourceType,
     responseHeaders: Array<Header>,
     localPath: string, // Path for storing local resources in the rawfile directory.
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
       urlList: [ // Only one URL is provided. This URL is used as both the resource origin and the network request address of the resource.
         "https://www.example.com/example.js",
       ],
       type: webview.OfflineResourceType.CLASSIC_JS,
       responseHeaders: [
         // Used in <script crossorigin="anonymous" /> mode to provide additional response headers.
         { headerKey: "Cross-Origin", headerValue:"anonymous" }
       ]
     },
   ];
   ```

6. Use the component on the page.
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
       // Initialize the Web component used to inject local resources and provide an empty HTML page as the URL.
       this.injectNode = createNode(injectWebview,
           { url: "https://www.example.com/empty.html", controller: this.injectController});
     }

     build() {
       Column() {
         // Load the Web component used by the service at a proper time. In this example, the button is clicked.
         Button ("Load Page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url: "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

7. Example of a loaded HTML web page:

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

Sets the IP address of the host after domain name resolution.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type| Mandatory| Description                            |
| --------- | -------- | ---- | ------------------------------------ |
| hostName  | string   | Yes  | Domain name of the host whose DNS records are to be added.           |
| address   | string   | Yes  | Host domain name resolution address (IPv4 and IPv6).|
| aliveTime | number   | Yes  | Cache validity period, in seconds.                |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |

**Example**

For details, see [clearHostIP](#clearhostip12).

### clearHostIP<sup>12+</sup>

static clearHostIP(hostName: string): void

Clears the IP address of a specified host after domain name resolution.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type| Mandatory| Description                 |
| -------- | -------- | ---- | ------------------------- |
| hostName | string   | Yes  | Domain name of the host whose DNS records are to be cleared.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |

**Example**

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
      // The setting takes effect before the URL is loaded.
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

Obtains the ID of the surface corresponding to ArkWeb. This parameter is valid only when the rendering mode of the **Web** component is **ASYNC_RENDER**. The value of **getSurfaceId** can be obtained only after the **Web** component is initialized.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description               |
| ------ | ------------------- |
| string | ID of the surface held by ArkWeb.|

**Example**

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
      Button ("Screenshot")
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

Sets the URL trustlist of the web page. Only URLs in the trustlist can be loaded or redirected. Otherwise, the URL is blocked and an alarm page is displayed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| urlTrustList | string | Yes  | URL trustlist, which is configured in JSON format. The maximum size is 10 MB.<br>**setUrlTrustList()** is used in overwrite mode. If it is called for multiple times, the latest setting overwrites the previous setting.<br>If this parameter is left blank, the trustlist is canceled and access to all URLs is allowed.<br>Example in JSON format:<br>{<br>&nbsp;&nbsp;"UrlPermissionList":&nbsp;[<br>&nbsp;&nbsp;&nbsp;&nbsp;{<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"scheme":&nbsp;"https",<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"host":&nbsp;"www\.example1.com",<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"port":&nbsp;443,<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"path":&nbsp;"pathA/pathB"<br>&nbsp;&nbsp;&nbsp;&nbsp;},<br>&nbsp;&nbsp;&nbsp;&nbsp;{<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"scheme":&nbsp;"http",<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"host":&nbsp;"www\.example2.com",<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"port":&nbsp;80,<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"path":&nbsp;"test1/test2/test3"<br>&nbsp;&nbsp;&nbsp;&nbsp;}<br>&nbsp;&nbsp;]<br>} |

**Parameters in JSON format**:
| Name  | Type| Mandatory| Description                 |
| -------- | -------- | ---- | ------------------------- |
| scheme | string   | No| Optional parameter. The supported protocols are HTTP and HTTPS.|
| host | string | Yes| Mandatory parameter. The URL is permitted only when its host field is the same as the rule field. Multiple rules for the same host at the same time are allowed.|
| port | number | No| Optional parameter.|
| path | string | No| Optional parameter. This field uses prefix matching. For example, in **pathA/pathB/pathC**, **pathA/pathB/** is specified, and all level-3 directories such as **pathC** can be accessed, which must be a complete directory name or file name. Partial matching is not allowed.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Parameter string is too long.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**
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
              // Set a trustlist to allow access only to trust web pages.
              this.controller.setUrlTrustList(this.urltrustList);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Cancel the trustlist.')
          .onClick(() => {
            try {
              // Input an empty string to setUrlTrustList() to disable the trustlist, and all URLs can be accessed.
              this.controller.setUrlTrustList("");
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Access the trust web')
          .onClick(() => {
            try {
              // The trustlist is enabled and trust web pages can be accessed.
              this.controller.loadUrl('http://trust.example.com/test');
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Button('Access the untrust web')
          .onClick(() => {
            try {
              // The trustlist is enabled that untrust web pages cannot be accessed and an error page is displayed.
              this.controller.loadUrl('http://untrust.example.com/test');
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'http://untrust.example.com/test', controller: this.controller }).onControllerAttached(() => {
          try {
            // Set the trustlist using onControllerAttached() to enable the trustlist before the URL starts to be loaded. The untrusted web page cannot be accessed, and an error page is displayed.
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

Sets a path list. When a file protocol accesses resources in the path of list, it can access the local files across domains. In addition, when a path list is set, the file protocol can access only the resources in the path list. The behavior of [fileAccess](ts-basic-components-web.md#fileAccess) will be overwritten by that of this API. The paths in the list must be any of the following:

1. The path of subdirectory of the application file directory. (The application file directory is obtained using [Context.filesDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in the Ability Kit.) For example:

* /data/storage/el2/base/files/example
* /data/storage/el2/base/haps/entry/files/example

2. The path of application resource directory or its subdirectory. (The application resource directory is obtained from [Context.resourceDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in the Ability Kit.) For example:

* /data/storage/el1/bundle/entry/resource/resfile
* /data/storage/el1/bundle/entry/resource/resfile/example

If a path in the list is not any of the preceding paths, error code 401 is reported and the path list fails to be set. When the path list is set to empty, the accessible files for the file protocol are subject to the behavior of the [fileAccess](ts-basic-components-web.md#fileAccess).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type| Mandatory| Description                 |
| -------- | -------- | ---- | ------------------------- |
| pathList | Array\<string\>   | Yes  | The path list.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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
            // Set the list of paths that can be accessed across domains.
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

Load the HTML file, which is located in the application resource directory **resource/resfile/index.html**.
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
                // If the path list is set on the eTS, resources can be obtained.
				        const element = document.getElementById('text');
                        element.textContent = "load " + file + " success";
				    } else {
                // If the path list is not set on the eTS, a CORS error is triggered.
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

In HTML, the file protocol is used to access the local JS file through XMLHttpRequest. The JS file is stored in **resource/resfile/js/script.js**.
<!--code_no_check-->
```javascript
const body = document.body;
const element = document.createElement('div');
element.textContent = 'success';
body.appendChild(element);
```

### enableBackForwardCache<sup>12+</sup>

static enableBackForwardCache(features: BackForwardCacheSupportedFeatures): void

Enables the back-forward cache of a **Web** component. You can specify whether to add a specific page to the back-forward cache.

This API must be called before [initializeWebEngine()](#initializewebengine) initializes the kernel.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| features     |  [BackForwardCacheSupportedFeatures](#backforwardcachesupportedfeatures12) | Yes  | Features of the pages, which allow them to be added to the back-forward cache.|

**Example**

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
        // If a page uses the same-layer rendering and takes over media playback at the same time, you need to set the values of **nativeEmbed** and **mediaTakeOver** to **true** to add the page to the back-forward cache.
         
        webview.WebviewController.enableBackForwardCache(features);
        webview.WebviewController.initializeWebEngine();
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

### setBackForwardCacheOptions<sup>12+</sup>

setBackForwardCacheOptions(options: BackForwardCacheOptions): void

Sets the back-forward cache options of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| options     |  [BackForwardCacheOptions](#backforwardcacheoptions12) | Yes  | Options to control the back-forward cache of the **Web** component.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

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

## WebCookieManager

Implements a **WebCookieManager** instance to manage behavior of cookies in **Web** components. All **Web** components in an application share a **WebCookieManager** instance.

### getCookie<sup>(deprecated)</sup>

static getCookie(url: string): string

Obtains the cookie corresponding to the specified URL.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. You are advised to use [fetchCookieSync](#fetchcookiesync11) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to obtain. A complete URL is recommended.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Cookie value corresponding to the specified URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Obtains the cookie value corresponding to the specified URL.

> **NOTE**
>
> The system automatically deletes expired cookies. For data with the same key name, the new data overwrites the previous data.
> 
> To obtain the cookie value that can be used, pass a complete link to **fetchCookieSync()**.
> 
> **fetchCookieSync()** is used to obtain all cookie values. Cookie values are separated by semicolons (;). However, a specific cookie value cannot be obtained separately.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to obtain. A complete URL is recommended.|
| incognito    | boolean | No  | Whether to obtain the cookie in incognito mode. The value **true** means to obtain the cookie in incognito mode, and **false** means the opposite.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Cookie value corresponding to the specified URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Obtains the cookie value of a specified URL. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to obtain. A complete URL is recommended.|
| callback | AsyncCallback\<string> | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |

**Example**

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

Obtains the cookie value of a specified URL. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to obtain. A complete URL is recommended.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<string> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |

**Example**

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


### setCookie<sup>(deprecated)</sup>

static setCookie(url: string, value: string): void

Sets a cookie for the specified URL.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. You are advised to use [configCookieSync<sup>11+</sup>](#configcookiesync11) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to set. A complete URL is recommended.|
| value  | string | Yes  | Cookie value to set.     |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Sets a cookie for the specified URL.

> **NOTE**
>
> You can set **url** in **configCookieSync** to a domain name so that the cookie is attached to the requests on the page.
>
> It is recommended that cookie syncing be completed before the **Web** component is loaded.
>
> If **configCookieSync()** is used to set cookies for two or more times, the cookies set each time are separated by semicolons (;).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to set. A complete URL is recommended.|
| value  | string | Yes  | Cookie value to set.     |
| incognito    | boolean | No  | Whether to set the cookies in incognito mode. The value **true** means to set the cookies in incognito mode, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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
            // Only one cookie value can be set in configCookieSync at a time.
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

### configCookie<sup>11+</sup>

static configCookie(url: string, value: string, callback: AsyncCallback\<void>): void

Sets the value of a single cookie for a specified URL. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to set. A complete URL is recommended.|
| value  | string | Yes  | Cookie value to set.     |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**Example**

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

Sets the value of a single cookie for a specified URL. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to set. A complete URL is recommended.|
| value  | string | Yes  | Cookie value to set.     |

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**Example**

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

### saveCookieAsync

static saveCookieAsync(callback: AsyncCallback\<void>): void

Saves the cookies in the memory to the drive. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                              |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return whether the cookies are successfully saved.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Saves the cookies in the memory to the drive. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Sets whether the **WebCookieManager** instance has the permission to send and receive cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                |
| ------ | ------- | ---- | :----------------------------------- |
| accept | boolean | Yes  | Whether the **WebCookieManager** instance has the permission to send and receive cookies.<br>Default value: **true**|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Checks whether the **WebCookieManager** instance has the permission to send and receive cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Whether the **WebCookieManager** instance has the permission to send and receive cookies. The default value is **true**.|

**Example**

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

Sets whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                      |
| ------ | ------- | ---- | :----------------------------------------- |
| accept | boolean | Yes  | Whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.<br>Default value: **false**|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Checks whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Whether the **WebCookieManager** instance has the permission to send and receive third-party cookies. The default value is **false**.|

**Example**

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

Checks whether cookies exist.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                      |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito<sup>11+</sup>    | boolean | No  | Whether to check for cookies in incognito mode. The value **true** means to check for cookies in incognito mode, and **false** means the opposite.|

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Whether cookies exist. The value **true** means that cookies exist, and **false** means the opposite.|

**Example**

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

Deletes all cookies.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. You are advised to use [clearAllCookiesSync](#clearallcookiessync11) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Deletes all cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                      |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito    | boolean | No  | Whether to delete all cookies in incognito mode. The value **true** means to delete all cookies in incognito mode, and **false** means the opposite.|

**Example**

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

Clears all cookies. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                              |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Clears all cookies. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**Example**

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

Deletes all session cookies.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. You are advised to use [clearSessionCookiesync](#clearsessioncookiesync11) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Deletes all session cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Clears all session cookies. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                              |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

Clears all session cookies. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**Example**

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

Implements a **WebStorage** object to manage the Web SQL database and HTML5 Web Storage APIs. All **Web** components in an application share a **WebStorage** object.

> **NOTE**
>
> You must load the **Web** component before calling the APIs in **WebStorage**.

### deleteOrigin

static deleteOrigin(origin: string): void

Deletes all data in the specified origin.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| origin | string | Yes  | Index of the origin, which is obtained through [getOrigins](#getorigins).|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

HTML file to be loaded:
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
        msg = '<p>Data table created, with two data records inserted.</p>';

        document.querySelector('#status').innerHTML = msg;
      });

      db.transaction(function(tx){
        tx.executeSql('SELECT * FROM LOGS', [], function (tx, results) {
          var len = results.rows.length,i;
          msg = "<p>Number of records: " + len + "</p>";

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
  <div id="status" name="status">Status</div>
  </body>
  </html>
 ```

### getOrigins

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void

Obtains information about all origins that are currently using the Web SQL Database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                  |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Yes  | Callback used to return the information about the origins. For details, see [WebStorageOrigin](#webstorageorigin).|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### getOrigins

static getOrigins(): Promise\<Array\<WebStorageOrigin>>

Obtains information about all origins that are currently using the Web SQL Database. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Promise used to return the information about the origins. For details, see [WebStorageOrigin](#webstorageorigin).|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### getOriginQuota

static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void

Obtains the storage quota of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | Yes  | Index of the origin.|
| callback | AsyncCallback\<number> | Yes  | Storage quota of the origin.  |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### getOriginQuota

static getOriginQuota(origin: string): Promise\<number>

Obtains the storage quota of an origin in the Web SQL Database, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  | Index of the origin.|

**Return value**

| Type           | Description                                   |
| --------------- | --------------------------------------- |
| Promise\<number> | Promise used to return the storage quota of the origin.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### getOriginUsage

static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void

Obtains the storage usage of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | Yes  | Index of the origin.|
| callback | AsyncCallback\<number> | Yes  | Storage usage of the origin.  |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### getOriginUsage

static getOriginUsage(origin: string): Promise\<number>

Obtains the storage usage of an origin in the Web SQL Database, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  | Index of the origin.|

**Return value**

| Type           | Description                                 |
| --------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the storage usage of the origin.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid origin.                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

### deleteAllData

static deleteAllData(incognito?: boolean): void

Deletes all data in the Web SQL Database.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| incognito<sup>11+</sup>    | boolean | No  | Whether to delete all data in the Web SQL Database in incognito mode. The value **true** means to delete all data in the Web SQL Database in incognito mode, and **false** means the opposite.|

**Example**

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

For details about the HTML file loaded, see the HTML file loaded using the [deleteOrigin](#deleteorigin) API.

## WebDataBase

Implements a **WebDataBase** object.

> **NOTE**
>
> You must load the **Web** component before calling the APIs in **WebDataBase**.

### getHttpAuthCredentials

static getHttpAuthCredentials(host: string, realm: string): Array\<string>

Retrieves HTTP authentication credentials for a given host and realm. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| host   | string | Yes  | Host to which HTTP authentication credentials apply.|
| realm  | string | Yes  | Realm to which HTTP authentication credentials apply.  |

**Return value**

| Type | Description                                        |
| ----- | -------------------------------------------- |
| Array\<string> | Returns the array of the matching user names and passwords if the operation is successful; returns an empty array otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Saves HTTP authentication credentials for a given host and realm. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type  | Mandatory| Description                        |
| -------- | ------ | ---- | ---------------------------- |
| host     | string | Yes  | Host to which HTTP authentication credentials apply.|
| realm    | string | Yes  | Realm to which HTTP authentication credentials apply.  |
| username | string | Yes  | User name.                    |
| password | string | Yes  | Password.                      |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Checks whether any saved HTTP authentication credentials exist. This API returns the result synchronously.  

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether any saved HTTP authentication credentials exist. Returns **true** if any saved HTTP authentication credentials exist; returns **false** otherwise.|

**Example**

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

Deletes all HTTP authentication credentials saved in the cache. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Implements a **GeolocationPermissions** object.

> **NOTE**
>
> You must load the **Web** component before calling the APIs in **GeolocationPermissions**.

### Required Permissions

**ohos.permission.LOCATION**, **ohos.permission.APPROXIMATELY_LOCATION**, and **ohos.permission.LOCATION_IN_BACKGROUND**, which are required for accessing the location information. For details about the permissions, see [@ohos.geolocation (Geolocation)](../apis-location-kit/js-apis-geolocation.md).

### allowGeolocation

static allowGeolocation(origin: string, incognito?: boolean): void

Allows the specified origin to use the geolocation information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  |Index of the origin.|
| incognito<sup>11+</sup>    | boolean | No  | Whether to allow the specified origin to use the geolocation information in incognito mode. The value **true** means to allow the specified origin to use the geolocation information in incognito mode, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Clears the geolocation permission status of a specified origin.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  | Index of the origin.|
| incognito<sup>11+</sup>   | boolean | No  | Whether to clear the geolocation permission status of a specified origin in incognito mode. The value **true** means to clear the geolocation permission status of a specified origin in incognito mode, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Obtains the geolocation permission status of the specified origin. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| origin   | string                 | Yes  | Index of the origin.                                          |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the geolocation permission status of the specified origin. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified origin is not found.|
| incognito<sup>11+</sup>    | boolean | No  | Whether to obtain the geolocation permission status of the specified origin in incognito mode. The value **true** means to obtain the geolocation permission status of the specified origin in incognito mode, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Obtains the geolocation permission status of the specified origin. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | -------- | ---- | -------------------- |
| origin | string   | Yes  | Index of the origin.|
| incognito<sup>11+</sup>    | boolean | No  | Whether to obtain the geolocation permission status of the specified origin in incognito mode. The value **true** means to obtain the geolocation permission status of the specified origin in incognito mode, and **false** means the opposite.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the geolocation permission status of the specified origin. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified origin is not found.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Obtains the geolocation permission status of all origins. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                    |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<Array\<string>> | Yes  | Callback used to return the geolocation permission status of all origins.|
| incognito<sup>11+</sup>    | boolean | No  | Whether to obtain the geolocation permission status of all origins in incognito mode. The value **true** means to obtain the geolocation permission status of all origins in incognito mode, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Obtains the geolocation permission status of all origins. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                    |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| incognito<sup>11+</sup>   | boolean | No  | Whether to obtain the geolocation permission status of all origins in incognito mode. The value **true** means to obtain the geolocation permission status of all origins in incognito mode, and **false** means the opposite.|

**Return value**

| Type                  | Description                                                     |
| ---------------------- | --------------------------------------------------------- |
| Promise\<Array\<string>> | Promise used to return the geolocation permission status of all origins.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Clears the geolocation permission status of all sources.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                    |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| incognito<sup>11+</sup>    | boolean | No  | Whether to clear the geolocation permission status of all sources in incognito mode. The value **true** means to clear the geolocation permission status of all sources in incognito mode, and **false** means the opposite.|

**Example**

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

Describes the request/response header returned by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Readable| Writable|Description                |
| ----------- | ------ | -----|------|------------------- |
| headerKey   | string | Yes| Yes| Key of the request/response header.  |
| headerValue | string | Yes| Yes| Value of the request/response header.|

## RequestInfo<sup>12+</sup>

Describes the information about the resource request sent by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name     | Type  | Readable| Writable|Description       |
| ---------| ------ | -----|------|--------  |
| url      | string | Yes| Yes| URL of the request.   |
| method   | string | Yes| Yes| Method of the request.   |
| formData | string | Yes| Yes| Form data in the request body.|

## WebHitTestType

The [getHitTest](#gethittest) API is used to indicate a cursor node.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| EditText      | 0 |Editable area.                           |
| Email         | 1 |Email address.                           |
| HttpAnchor    | 2 |Hyperlink, where **src** is **http**.                    |
| HttpAnchorImg | 3 |Image with a hyperlink, where **src** is http + HTML::img.|
| Img           | 4 |HTML::img tag.                          |
| Map           | 5 |Geographical address.                               |
| Phone         | 6 |Phone number.                               |
| Unknown       | 7 |Unknown content.                               |

## SecurityLevel<sup>11+</sup>

Defines the security level of the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| NONE          | 0 |The web page is neither absolutely secure nor insecure, that is, neutral. A typical example is a web page whose URL scheme is not HTTP or HTTPS.|
| SECURE        | 1 |The web page is secure, using the HTTPS protocol and a trusted certificate.|
| WARNING       | 2 |The web page is possibly compromised. A typical example is a web page that uses the HTTP or HTTPS protocol but an outdated TLS version.|
| DANGEROUS     | 3 |The web page is insecure. This means that the page may have attempted to load HTTPS scripts to no avail, have failed authentication, or contain insecure active content in HTTPS, malware, phishing, or any other sources of major threats.|

##  HitTestValue

Provides the element information of the area being clicked. For details about the sample code, see [getHitTestValue](#gethittestvalue).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Readable| Writable| Description|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](#webhittesttype) | Yes| Yes| Element type of the area being clicked.|
| extra | string        | Yes| Yes|Extra information of the area being clicked. If the area being clicked is an image or a link, the extra information is the URL of the image or link.|

## WebMessage

type WebMessage = ArrayBuffer | string

Describes the data types supported for [WebMessagePort](#webmessageport).

**System capability**: SystemCapability.Web.Webview.Core

| Type      | Description                                    |
| -------- | -------------------------------------- |
| string   | String type.|
| ArrayBuffer   | Binary type.|

## JsMessageType<sup>10+</sup>

Describes the type of the returned result of script execution using [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| NOT_SUPPORT  | 0 |Unsupported data type.|
| STRING       | 1 |String type.|
| NUMBER       | 2 |Number type.|
| BOOLEAN      | 3 |Boolean type.|
| ARRAY_BUFFER | 4 |Raw binary data buffer.|
| ARRAY        | 5 |Array type.|

## WebMessageType<sup>10+</sup>

Describes the data type supported by the [webMessagePort](#webmessageport) API.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                           |
| ------------ | -- |------------------------------- |
| NOT_SUPPORT  | 0 |Unsupported data type.|
| STRING       | 1 |String type.|
| NUMBER       | 2 |Number type.|
| BOOLEAN      | 3 |Boolean type.|
| ARRAY_BUFFER | 4 |Raw binary data buffer.|
| ARRAY        | 5 |Array type.|
| ERROR        | 6 |Error object type.|

## MediaPlaybackState<sup>12+</sup>

Enumerates the playback states on the current web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value  | Description              |
| ------- | ---- | ------------------ |
| NONE    | 0    | No audio or video playback is started on the page.|
| PLAYING | 1    | The audio and video on the page are being played.|
| PAUSED  | 2    | The audio and video on the page are paused.  |
| STOPPED | 3    | The audio and video on the page are stopped.  |

## RenderProcessMode<sup>12+</sup>

Enumerates the ArkWeb render subprocess modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| SINGLE        | 0 |ArkWeb single render subprocess mode. In this mode, multiple **Web** components share one render subprocess.|
| MULTIPLE      | 1 |ArkWeb multi-render subprocess mode. In this mode, each **Web** component has a rendering subprocess.|


## JsMessageExt<sup>10+</sup>

Implements the **JsMessageExt** data object that is returned after script execution using the [runJavaScriptExt](#runjavascriptext10) API.

### getType<sup>10+</sup>

getType(): JsMessageType

Obtains the type of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description                                                     |
| --------------| --------------------------------------------------------- |
| [JsMessageType](#jsmessagetype10) | Type of the data object that is returned after script execution using the [runJavaScriptExt](#runjavascriptext10) API.|

### getString<sup>10+</sup>

getString(): string

Obtains string-type data of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| string | Data of the string type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getNumber<sup>10+</sup>

getNumber(): number

Obtains number-type data of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| number | Data of the number type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

Obtains Boolean-type data of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| boolean | Data of the Boolean type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

Obtains raw binary data of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| ArrayBuffer | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

Obtains array-type data of the data object. For the complete sample code, see [runJavaScriptExt](#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## WebMessageExt<sup>10+</sup>

Represents a data object received and sent through the [webMessagePort](#webmessageport) API.

### getType<sup>10+</sup>

getType(): WebMessageType

Obtains the type of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description                                                     |
| --------------| --------------------------------------------------------- |
| [WebMessageType](#webmessagetype10) | Data type supported by the [webMessagePort](#webmessageport) API.|

### getString<sup>10+</sup>

getString(): string

Obtains string-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| string | Data of the string type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getNumber<sup>10+</sup>

getNumber(): number

Obtains number-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| number | Data of the number type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

Obtains Boolean-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| boolean | Data of the Boolean type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

Obtains raw binary data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| ArrayBuffer | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

Obtains array-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getError<sup>10+</sup>

getError(): Error

Obtains the error-object-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Error | Data of the error object type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### setType<sup>10+</sup>

setType(type: WebMessageType): void

Sets the type for the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| type  | [WebMessageType](#webmessagetype10) | Yes  | Data type supported by the [webMessagePort](#webmessageport) API.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setString<sup>10+</sup>

setString(message: string): void

Sets the string-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | string | Yes  | String type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setNumber<sup>10+</sup>

setNumber(message: number): void

Sets the number-type data of the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | number | Yes  | Data of the number type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setBoolean<sup>10+</sup>

setBoolean(message: boolean): void

Sets the Boolean-type data for the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | boolean | Yes  | Data of the Boolean type.|

**Error codes**

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setArrayBuffer<sup>10+</sup>

setArrayBuffer(message: ArrayBuffer): void

Sets the raw binary data for the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | ArrayBuffer | Yes  | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setArray<sup>10+</sup>

setArray(message: Array\<string | number | boolean\>): void

Sets the array-type data for the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | Array\<string \| number \| boolean\> | Yes  | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

### setError<sup>10+</sup>

setError(message: Error): void

Sets the error-object-type data for the data object. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | -------------------- |
| message  | Error | Yes  | Data of the error object type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## WebStorageOrigin

Provides usage information of the Web SQL Database.

**System capability**: SystemCapability.Web.Webview.Core

| Name  | Type  | Readable| Writable| Description|
| ------ | ------ | ---- | ---- | ---- |
| origin | string | Yes | Yes| Index of the origin.|
| usage  | number | Yes | Yes| Storage usage of the origin.    |
| quota  | number | Yes | Yes| Storage quota of the origin.  |

## BackForwardList

Provides the historical information list of the current webview.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Readable| Writable| Description                                                        |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | Yes  | Yes  | Index of the current page in the page history stack.                                |
| size         | number | Yes  | Yes  | Number of indexes in the history stack. The maximum value is 50. If this value is exceeded, the earliest index will be overwritten.|

### getItemAtIndex

getItemAtIndex(index: number): HistoryItem

Obtains the page record with the specified index in the history stack.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| index  | number | Yes  | Index of the target page record in the history stack.|

**Return value**

| Type                       | Description        |
| --------------------------- | ------------ |
| [HistoryItem](#historyitem) | Historical page record.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Describes a historical page record.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                  | Readable| Writable| Description                        |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | No  | **PixelMap** object of the icon on the historical page.|
| historyUrl    | string                                 | Yes  | Yes  | URL of the historical page.       |
| historyRawUrl | string                                 | Yes  | Yes  | Original URL of the historical page.   |
| title         | string                                 | Yes  | Yes  | Title of the historical page.          |

## WebCustomScheme

Defines a custom URL scheme.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Readable| Writable| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | Yes  | Yes  | Name of the custom URL scheme. The value can contain a maximum of 32 characters, including lowercase letters, digits, periods (.), plus signs (+), and hyphens (-), and must start with a letter.       |
| isSupportCORS  | boolean   | Yes  | Yes  | Whether to support cross-origin resource sharing (CORS).   |
| isSupportFetch | boolean   | Yes  | Yes  | Whether to support fetch requests.          |
| isStandard<sup>12+</sup> | boolean   | Yes  | Yes  | Whether the scheme is processed as a standard scheme. The standard scheme must comply with the URL normalization and parsing rules defined in section 3.1 of RFC 1738.          |
| isLocal<sup>12+</sup> | boolean   | Yes  | Yes  | Whether the scheme is treated with the same security rules as those applied to file URLs.          |
| isDisplayIsolated<sup>12+</sup> | boolean   | Yes  | Yes  | Whether the content of the scheme can be displayed or accessed from other content that uses the same scheme.          |
| isSecure<sup>12+</sup> | boolean   | Yes  | Yes  | Whether the scheme is treated with the same security rules as those applied to HTTPS URLs.          |
| isCspBypassing<sup>12+</sup> | boolean   | Yes  | Yes  | Whether the scheme can bypass the content security policy (CSP) checks. In most cases, this value should not be set when **isStandard** is set to **true**.        |
| isCodeCacheSupported<sup>12+</sup> | boolean   | Yes  | Yes  | Whether JavaScript resources loaded with the scheme can be used to create a code cache.        |

## SecureDnsMode<sup>10+</sup>

Describes the mode in which the **Web** component uses HTTPDNS.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| OFF                                  | 0 |HTTPDNS is not used. This value can be used to revoke the previously used HTTPDNS configuration.|
| AUTO                                 | 1 |HTTPDNS is used in automatic mode. If the specified HTTPDNS server is unavailable for resolution, the component falls back to the system DNS server.|
| SECURE_ONLY                          | 2 |The specified HTTPDNS server is forcibly used for DNS resolution.|

## WebDownloadState<sup>11+</sup>

Describes the state of a download task.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| IN_PROGRESS                                  | 0 |The download task is in progress.|
| COMPLETED                                 | 1 |The download task is completed.|
| CANCELED                          | 2 |The download task has been canceled.|
| INTERRUPTED                          | 3 |The download task is interrupted.|
| PENDING                          | 4 |The download task is pending.|
| PAUSED                          | 5 |The download task is paused.|
| UNKNOWN                          | 6 |The state of the download task is unknown.|

## WebDownloadErrorCode<sup>11+</sup>

Describes the download task error code.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| ERROR_UNKNOWN                                  | 0 |Unknown error.|
| FILE_FAILED | 1 |  Failed to operate the file.|
| FILE_ACCESS_DENIED | 2 | No permission to access the file.|
| FILE_NO_SPACE | 3 | The disk space is insufficient.|
| FILE_NAME_TOO_LONG | 5 | The file name is too long.|
| FILE_TOO_LARGE | 6 | The file is too large.|
| FILE_TRANSIENT_ERROR | 10 |  Some temporary issues occur, such as insufficient memory, files in use, and too many files open at the same time.|
| FILE_BLOCKED | 11 |  Access to the file is blocked due to certain local policies.|
| FILE_TOO_SHORT | 13 |  The file to resume downloading is not long enough. It may not exist.|
| FILE_HASH_MISMATCH | 14 |  Hash mismatch.|
| FILE_SAME_AS_SOURCE | 15 |  The file already exists.|
| NETWORK_FAILED | 20 |  Common network error.|
| NETWORK_TIMEOUT | 21 | Network connection timeout.|
| NETWORK_DISCONNECTED | 22 | Network disconnected.|
| NETWORK_SERVER_DOWN | 23 |  The server is shut down.|
| NETWORK_INVALID_REQUEST | 24 |  Invalid network request. The request may be redirected to an unsupported scheme or an invalid URL.|
| SERVER_FAILED | 30 | The server returns a general error.|
| SERVER_NO_RANGE | 31 |  The server does not support the range request.|
| SERVER_BAD_CONTENT | 33 |   The server does not have the requested data.|
| SERVER_UNAUTHORIZED | 34 |  The file cannot be downloaded from the server.|
| SERVER_CERT_PROBLEM | 35 |  The server certificate is incorrect.|
| SERVER_FORBIDDEN | 36 |  The access to the server is forbidden.|
| SERVER_UNREACHABLE | 37 |  The server cannot be accessed.|
| SERVER_CONTENT_LENGTH_MISMATCH | 38 |  The received data does not match the content length.|
| SERVER_CROSS_ORIGIN_REDIRECT | 39 | An unexpected cross-site redirection occurs.|
| USER_CANCELED | 40 | The user cancels the download.|
| USER_SHUTDOWN | 41 | The user closes the application.|
| CRASH | 50 | The application crashes.|

## WebDownloadItem<sup>11+</sup>

 Implements a **WebDownloadItem** object. You can use this object to perform operations on the corresponding download task.

> **NOTE**
>
> During the download, the download process is notified to the user through **WebDownloadDelegate**. The user can operate the download task through the **WebDownloadItem** parameter.

### getGuid<sup>11+</sup>

getGuid(): string

Obtains the unique ID of this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Unique ID of the download task.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the download speed, in bytes per second.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Download speed, in bytes per second.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the download progress. The value **100** indicates that the download is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Download progress. The value **100** indicates that the download is complete.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the total length of the file to be downloaded.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Total length of the file to be downloaded.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the download state.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadState](#webdownloadstate11) | Download state.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the download error code.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadErrorCode](#webdownloaderrorcode11) | Error code returned when the download error occurs.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the request mode of this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Request mode of the download task.|

**Example**

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
              console.log("Download will start. Method:" + webDownloadItem.getMethod());
              // Pass in a download path and start the download.
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

Obtains the MIME type of this download task (for example, a sound file may be marked as audio/ogg, and an image file may be image/png).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | MIME type (for example, audio/ogg for a sound file, and image/png for an image file).|

**Example**

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
              console.log("Download will start. MIME type:" + webDownloadItem.getMimeType());
              // Pass in a download path and start the download.
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

Obtains the download request URL.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Download request URL.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the suggested file name for this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Suggested file name.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the number of received bytes.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Number of received bytes.|

**Example**

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
              // Pass in a download path and start the download.
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

Obtains the full path of the downloaded file on the disk.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Full path of the downloaded file on the disk.|

**Example**

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
              // Pass in a download path and start the download.
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

Serializes the failed download to a byte array.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Uint8Array | Byte array into which the failed download is serialized.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Deserializes the serialized byte array into a **WebDownloadItem** object.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| serializedData | Uint8Array | Yes  | Byte array into which the download is serialized.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadItem](#webdownloaditem11) | **WebDownloadItem** object.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Starts a download.

> **NOTE**
>
>This API must be used in the **onBeforeDownloadb** callback of **WebDownloadDelegateb**. If it is not called in the callback, the download task remains in the PENDING state and is downloaded to a temporary directory. After the target path is specified by **WebDownloadItem.start**, the temporary files are renamed to the target path and the files that are not completely downloaded are directly downloaded to the target path. If you do not want to download the file to the temporary directory before invoking **WebDownloadItem.start**, you can call **WebDownloadItem.cancel** to cancel the current download task and then call **WebDownloadManager.resumeDownload** to resume the task.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | ------------------------------|
| downloadPath   | string     | Yes | Path (including the file name) of the file to download.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Cancels a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Pauses a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100019 | The download task is not started yet. |

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Resumes a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100016 | The download task is not paused. |

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Implements a **WebDownloadDelegate** class. You can use the callbacks of this class to notify users of the download state.

### onBeforeDownload<sup>11+</sup>

onBeforeDownload(callback: Callback\<WebDownloadItem>): void

Invoked to notify users before the download starts. **WebDownloadItem.start("xxx")** must be called in this API, with a download path provided. Otherwise, the download remains in the PENDING state.

> **NOTE**
>
>The download task remains in the PENDING state is downloaded to a temporary directory at first. After the target path is specified by **WebDownloadItem.start**, the temporary files are renamed to the target path and the files that are not completely downloaded are directly downloaded to the target path. If you do not want to download the file to the temporary directory before invoking **WebDownloadItem.start**, you can call **WebDownloadItem.cancel** to cancel the current download task and then call **WebDownloadManager.resumeDownload** to resume the task.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback for triggering a download.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Invoked when the download progress is updated.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the downloaded progress is updated.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Invoked when the download is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the download is complete.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Invoked when the download fails.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the download fails.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Implements a **WebDownloadManager** class. You can use the APIs of this class to resume failed download tasks.

### setDownloadDelegate<sup>11+</sup>

static setDownloadDelegate(delegate: WebDownloadDelegate): void

Sets the delegate used to receive download progress triggered from **WebDownloadManager**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](#webdownloaddelegate11)  | Yes  | Delegate used to receive the download progress.|

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Resumes a failed download task.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| webDownloadItem      | [WebDownloadItem](#webdownloaditem11)  | Yes  | Download task to resume.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100018 | No WebDownloadDelegate has been set yet. |

**Example**

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
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
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

Represents the body of the data being sent in POST and PUT requests. It accepts data of the BYTES, FILE, BLOB, and CHUNKED types. Note that other APIs in this class can be called only after [initialize](#initialize12) is called successfully.

### initialize<sup>12+</sup>

initialize(): Promise\<void\>

Initializes this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100022 | Failed to initialize the HTTP body stream. |

**Example**

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

Reads data from this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  size | number | Yes  | Number of bytes obtained from the **WebHttpBodyStream** instance.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<ArrayBuffer\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |

**Example**

For the complete sample code, see [initialize](#initialize12)).

### getSize<sup>12+</sup>

getSize(): number

Obtains the size of data in this **WebHttpBodyStream** instance. This API always returns zero when chunked transfer is used.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Size of data in the current **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### getPosition<sup>12+</sup>

getPosition(): number

Reads the current read position in this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Current read position in the **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isChunked<sup>12+</sup>

isChunked(): boolean

Checks whether this **WebHttpBodyStream** instance is transmitted by chunk.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the **WebHttpBodyStream** instance is transmitted by chunk.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isEof<sup>12+</sup>

isEof(): boolean

Checks whether all data in this **WebHttpBodyStream** instance has been read. This API returns **true** if all data in the **httpBodyStream** instance is read. It returns **false** before the first read attempt is made for the **WebHttpBodyStream** instance that uses chunked transfer.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether all data in the **WebHttpBodyStream** instance has been read.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isInMemory<sup>12+</sup>

isInMemory(): boolean

Checks whether the uploaded data in this **httpBodyStream** instance is in memory. This API returns **true** if all the upload data in the **httpBodyStream** instance is in memory and all read requests will be completed synchronously. It returns **false** if the data is chunked to transfer.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the uploaded data in the **WebHttpBodyStream** instance is stored in memory.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

## WebSchemeHandlerRequest<sup>12+</sup>

Represents a request intercepted by the **WebSchemeHandler** object.

### getHeader<sup>12+</sup>

getHeader(): Array\<WebHeader\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[WebHeader](#webheader)\> | Information about the resource request header.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestUrl<sup>12+</sup>

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestMethod<sup>12+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Request method.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getReferrer<sup>12+</sup>

getReferrer(): string

Obtains the referrer.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Obtained referrer.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### isMainFrame<sup>12+</sup>

isMainFrame(): boolean

Checks whether the resource request is for the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is for the main frame.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### hasGesture<sup>12+</sup>

hasGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap).|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getHttpBodyStream<sup>12+</sup>

getHttpBodyStream(): WebHttpBodyStream | null

Obtains the **WebHttpBodyStream** instance in this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebHttpBodyStream](#webhttpbodystream12) \| null | **WebHttpBodyStream** instance in the resource request. If there is no **WebHttpBodyStream** instance, **null** is returned.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestResourceType<sup>12+</sup>

getRequestResourceType(): WebResourceType

Obtains the resource type of this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebResourceType](#webresourcetype12) | Resource type of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getFrameUrl<sup>12+</sup>

getFrameUrl(): string

Obtains the URL of the frame that triggers this request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the frame that triggers the request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

## WebSchemeHandlerResponse<sup>12+</sup>

Represents a request response. You can create a response for an intercepted request, fill in custom content, and return the response to the **Web** component.

### constructor<sup>12+</sup>

constructor()

A constructor used to create a **Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Sets the redirection URL or the URL changed due to HSTS for this response. After the URL is set, a redirection to the new URL is triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  url | string | Yes  | URL to be redirected to.|

**Example**

For the complete sample code, see [constructor](#constructor12).

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

### setNetErrorCode<sup>12+</sup>

setNetErrorCode(code: WebNetErrorList): void

Sets the network error code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For the complete sample code, see [constructor](#constructor12).

### setStatus<sup>12+</sup>

setStatus(code: number): void

Sets the HTTP status code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | number | Yes  | HTTP status code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

For the complete sample code, see [constructor](#constructor12).

### setStatusText<sup>12+</sup>

setStatusText(text: string): void

Sets the status text for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  text | string | Yes  | Status text.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For the complete sample code, see [constructor](#constructor12).

### setMimeType<sup>12+</sup>

setMimeType(type: string): void

Sets the MIME type for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  type | string | Yes  | MIME type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For the complete sample code, see [constructor](#constructor12).

### setEncoding<sup>12+</sup>

setEncoding(encoding: string): void

Sets the character set for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  encoding | string | Yes  | Character set.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For the complete sample code, see [constructor](#constructor12).

### setHeaderByName<sup>12+</sup>

setHeaderByName(name: string, value: string, overwrite: boolean): void

Sets the header information for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  name | string | Yes  | Name of the header.|
|  value | string | Yes  | Value of the header.|
|  overwrite | boolean | Yes  | Whether to override the existing header. The value **true** means to override the existing header, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For the complete sample code, see [constructor](#constructor12).

### getUrl<sup>12+</sup>

getUrl(): string

Obtains the redirection URL or the URL changed due to HSTS.
Caution: To obtain the URL for JavaScriptProxy communication API authentication, use [getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](#getlastjavascriptproxycallingframeurl12).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Redirection URL or the URL changed due to HSTS.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getNetErrorCode<sup>12+</sup>

getNetErrorCode(): WebNetErrorList

Obtains the network error code of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Network error code of the response.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getStatus<sup>12+</sup>

getStatus(): number

Obtains the HTTP status code of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| number | HTTP status code of the response.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getStatusText<sup>12+</sup>

getStatusText(): string

Obtains the status text of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Status text.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getMimeType<sup>12+</sup>

getMimeType(): string

Obtains the MIME type of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | MIME type.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getEncoding<sup>12+</sup>

getEncoding(): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Character set.|

**Example**

For the complete sample code, see [constructor](#constructor12).

### getHeaderByName<sup>12+</sup>

getHeaderByName(name: string): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| name     | string | Yes  | Name of the header.     |


**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Value of the header.|

**Example**

For the complete sample code, see [constructor](#constructor12).

## WebResourceHandler<sup>12+</sup>

Represents a **WebResourceHandler** object, which can return custom response headers and response bodies to the **Web** component.

### didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

Sends a response header for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](#webschemehandlerresponse12)  | Yes  | Response to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didReceiveResponseBody<sup>12+</sup>

didReceiveResponseBody(data: ArrayBuffer): void

Sends a response body for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| data      | ArrayBuffer  | Yes  | Response body.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didFinish<sup>12+</sup>

didFinish(): void

Notifies the **Web** component that this request is completed and that no more data is available. Before calling this API, you need to call [didReceiveResponse](#didreceiveresponse12) to send a response header for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

Notifies the ArkWeb kernel that this request fails. Before calling this API, call [didReceiveResponse](#didreceiveresponse12) to send a response header to this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |

**System capability**: SystemCapability.Web.Webview.Core

**Example**

See [OnRequestStart](#onrequeststart12).

## WebSchemeHandler<sup>12+</sup>

Represents a **WebSchemeHandler** object used to intercept requests for a specific scheme.

### onRequestStart<sup>12+</sup>

onRequestStart(callback: (request: WebSchemeHandlerRequest, handler: WebResourceHandler) => boolean): void

Called when a request starts. In this callback, you can determine whether to intercept the request. If **false** is returned, the request is not intercepted and the handler is invalid. If **true** is returned, the request is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback   | (request: [WebSchemeHandlerRequest](#webschemehandlerrequest12), handler: [WebResourceHandler](#webresourcehandler12)) => boolean | Yes| Callback invoked when a request for the specified scheme starts. **request** represents a request. **handler** provides the custom response header and response body for the **Web** component. The return value indicates whether the request is intercepted.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

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

              // Before calling didFinish or didFail, call didReceiveResponse to send a response header to this request.
              let buf = buffer.from(this.htmlData)
              try {
                if (buf.length == 0) {
                  console.log("[schemeHandler] length 0");
                  resourceHandler.didReceiveResponse(response);
                  // If the value of buf.length is 0 in normal cases, call resourceHandler.didFinish(). Otherwise, call resourceHandler.didFail().
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

Called when a request is complete, under the prerequisite that the request is indicated as intercepted in the **onRequestStart** callback. Specifically, this callback is invoked in the following cases:

1. The **WebResourceHandler** object calls **didFail** or **didFinish**.

2. The request is interrupted due to other reasons.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | Callback\<[WebSchemeHandlerRequest](#webschemehandlerrequest12)\> | Yes  | Callback invoked when the request is complete.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Invalid input parameter. |

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

## CacheOptions<sup>12+</sup>

Represents a configuration object for precompiling JavaScript in the **Web** component to generate bytecode cache, which is designed to control the updating of the bytecode cache.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Readable| Writable|Description                |
| ----------- | ------ | -----|------|------------------- |
| responseHeaders   | Array<[WebHeader](#webheader)> | Yes| Yes| Array of response headers from the server when a JavaScript file is requested. They include information such as E-Tag or Last-Modified to identify the file version and determine whether the bytecode cache needs to be refreshed.  |

## PlaybackStatus<sup>12+</sup>

Represents the playback status of the player, functioning as a parameter in [handleStatusChanged](#handlestatuschanged12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| PAUSED  | 0 | Playing.|
| PLAYING | 1 | Paused.|

## NetworkState<sup>12+<sup>

Describes the network status of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| EMPTY         | 0 | The player has not started downloading data.|
| IDLE          | 1 | The player's network activity is idle. This could mean that the download of a media segment is complete, and the player is waiting to start downloading the next segment.|
| LOADING       | 2 | The player is downloading media data.|
| NETWORK_ERROR | 3 | A network error occurs.|

## ReadyState<sup>12+<sup>

Enumerates the cache states of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| HAVE_NOTHING      | 0 | There is no data cached.|
| HAVE_METADATA     | 1 | Only media metadata is cached.|
| HAVE_CURRENT_DATA | 2 | Data up to the current playback position is cached.|
| HAVE_FUTURE_DATA  | 3 | Data beyond the current playback position is cached, but there might still be stutters during playback.|
| HAVE_ENOUGH_DATA  | 4 | Sufficient data has been cached to ensure smooth playback.|

## MediaError<sup>12+<sup>

Enumerates the error types of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| NETWORK_ERROR | 1 | Network error.|
| FORMAT_ERROR  | 2 | Media format error.|
| DECODE_ERROR  | 3 | Decoding error.|

## NativeMediaPlayerHandler<sup>12+<sup>

Represents a **NativeMediaPlayerHandler** object used as the parameter of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
The application uses this object to report the player status to the ArkWeb engine.

### handleStatusChanged<sup>12+<sup>

handleStatusChanged(status: PlaybackStatus): void

Called to notify the ArkWeb engine of the playback status of the player when the playback status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| status | [PlaybackStatus](#playbackstatus12) | Yes| Player status.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleVolumeChanged<sup>12+<sup>

handleVolumeChanged(volume: number): void

Called to notify the ArkWeb engine of the volume of the player when the volume changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Volume of the player.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleMutedChanged<sup>12+<sup>

handleMutedChanged(muted: boolean): void

Called to notify the ArkWeb engine of the muted status of the player when the muted status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether the player is muted.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handlePlaybackRateChanged<sup>12+<sup>

handlePlaybackRateChanged(playbackRate: number): void

Called to notify the ArkWeb engine of the playback rate of the player when the playback rate changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleDurationChanged<sup>12+<sup>

handleDurationChanged(duration: number): void

Called to notify the ArkWeb engine of the total duration of the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| duration | number | Yes| Total duration of the media. Unit: second.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleTimeUpdate<sup>12+<sup>

handleTimeUpdate(currentPlayTime: number): void

Called to notify the ArkWeb engine of the playback progress when the playback progress changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| currentPlayTime | number | Yes| Current progress. Unit: second. |

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleBufferedEndTimeChanged<sup>12+<sup>

handleBufferedEndTimeChanged(bufferedEndTime: number): void

Called to notify the ArkWeb engine of the buffer time when the buffer time changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| bufferedEndTime | number | Yes| Duration of media data in the buffer.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleEnded<sup>12+<sup>

handleEnded(): void

Called to notify the ArkWeb engine that the media playback ends.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleNetworkStateChanged<sup>12+<sup>

handleNetworkStateChanged(state: NetworkState): void

Called to notify the ArkWeb engine of the network status of the player when the network status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [NetworkState](#networkstate12) | Yes| Network status of the player.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleReadyStateChanged<sup>12+<sup>

handleReadyStateChanged(state: ReadyState): void

Called to notify the ArkWeb engine of the cache status of the player when the cache status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [ReadyState](#readystate12) | Yes| Cache status of the player.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleFullscreenChanged<sup>12+<sup>

handleFullscreenChanged(fullscreen: boolean): void

Called to notify the ArkWeb engine of the full screen status of the player when the full screen status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| fullscreen | boolean | Yes| Whether the player is in full screen.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleSeeking<sup>12+<sup>

handleSeeking(): void

Called to notify the ArkWeb engine that the player enters the seek state.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleSeekFinished<sup>12+<sup>

handleSeekFinished(): void

Called to notify the ArkWeb engine that the seek operation is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleError<sup>12+<sup>

handleError(error: MediaError, errorMessage: string): void

Called to notify the ArkWeb engine that an error occurs with the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| error | [MediaError](#mediaerror12) | Yes| Error object type.|
| errorMessage | string | Yes| Error message.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### handleVideoSizeChanged<sup>12+<sup>

handleVideoSizeChanged(width: number, height: number): void

Called to notify the ArkWeb engine of the video size of the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| width  | number | Yes| Video width.|
| height | number | Yes| Video height.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

## SuspendType<sup>12+<sup>

Enumerates the suspension types of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| ENTER_BACK_FORWARD_CACHE | 0 | The page enters the BFCache.|
| ENTER_BACKGROUND         | 1 | The page is displayed in the background.|
| AUTO_CLEANUP             | 2 | The page is automatically cleaned up by the system.|

## NativeMediaPlayerBridge<sup>12+<sup>

Implements a **NativeMediaPlayerBridge** object, which is the return value of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
It is an interface class that acts as a bridge between the web media player and the ArkWeb kernel.
The ArkWeb engine uses an object of this interface class to control the player created by the application to take over web page media.

### updateRect<sup>12+<sup>

updateRect(x: number, y: number, width: number, height: number): void

Updates the surface position information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| x | number | Yes| X coordinate of the surface relative to the web component.|
| y | number | Yes| Y coordinate of the surface relative to the web component.|
| width  | number | Yes| Width of the surface.|
| height | number | Yes| Height of the surface.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### play<sup>12+<sup>

play(): void

Plays this video.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### pause<sup>12+<sup>

pause(): void

Pauses playback.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### seek<sup>12+<sup>

seek(targetTime: number): void

Seeks to a specific time point in the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| targetTime | number | Yes| Target time point. Unit: second.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### setVolume<sup>12+<sup>

setVolume(volume: number): void

Sets the playback volume.
The value range is [0, 1.0].

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Playback volume. The value range is [0, 1.0]. The value **0** indicates mute, and **1.0** indicates the maximum volume level.|

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### setMuted<sup>12+<sup>

setMuted(muted: boolean): void

Sets the muted status.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether to mute the player.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### setPlaybackRate<sup>12+<sup>

setPlaybackRate(playbackRate: number): void

Sets the playback rate.
The value range is [0, 10.0].

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate. The value range is [0, 10.0]. The value **1** indicates the original speed of playback.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### release<sup>12+<sup>

release(): void

Releases this player.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### enterFullscreen<sup>12+<sup>

enterFullscreen(): void

Enables the player to enter full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### exitFullscreen<sup>12+<sup>

exitFullscreen(): void

Enables the player to exit full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### resumePlayer<sup>12+<sup>

resumePlayer?(): void

Resumes the player and its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

### suspendPlayer<sup>12+<sup>

suspendPlayer?(type: SuspendType): void

Suspends the player and save its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| type | [SuspendType](#suspendtype12) | Yes| Suspension type of the player.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

## MediaType<sup>12+<sup>

Enumerates the media types.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| VIDEO | 0 | Video.|
| AUDIO | 1 | Audio.|

## SourceType<sup>12+<sup>

Enumerates the media source types.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| URL | 0 | URL.|
| MSE | 1 | Blob.|

## MediaSourceInfo<sup>12+<sup>

Provides the information about the media source.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| type | [SourceType](#sourcetype12) | Yes| Type of the media source.|
| source | string | Yes| Address of the media source.|
| format | string | Yes| Format of the media source, which may be empty. You need to determine the format by yourself.|

## NativeMediaPlayerSurfaceInfo<sup>12+<sup>

Provides the surface information used for same-layer rendering [when the application takes over the media playback functionality of the web page](ts-basic-components-web.md#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| id | string | Yes| Surface ID, which is the **psurfaceid** of the native image used for rendering at the same layer.<br>For details, see [NativeEmbedDataInfo](ts-basic-components-web.md#nativeembeddatainfo11).|
| rect | [RectEvent](#rectevent12) | Yes| Position of the surface.|

## Preload<sup>12+<sup>

Defines how the player preloads media data.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| NONE     | 0 | No media data is preloaded.|
| METADATA | 1 | Only the metadata of the media is preloaded.|
| AUTO     | 2 | A sufficient amount of media data is preloaded to ensure smooth playback|

## MediaInfo<sup>12+<sup>

Represents a **MediaInfo** object used as a parameter of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
The object contains information about media on the web page. The application may create, based on the information, a player that takes over media playback of the web page .

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| embedID | string | Yes| ID of **\<video>** or **\<audio>** on the web page.|
| mediaType | [MediaType](#mediatype12) | Yes| Type of the media.|
| mediaSrcList | [MediaSourceInfo](#mediasourceinfo12)[] | Yes| Source of the media. There may be multiple sources. The application needs to select a supported source to play.|
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](#nativemediaplayersurfaceinfo12) | Yes| Surface information used for same-layer rendering.|
| controlsShown | boolean | Yes| Whether the **controls** attribute exists in **\<video>** or **\<audio>**.|
| controlList | string[] | Yes| Value of the **controlslist** attribute in **\<video>** or **\<audio>**.|
| muted | boolean | Yes| Whether to mute the player.|
| posterUrl | string | Yes| URL of a poster.|
| preload | [Preload](#preload12) | Yes| Whether preloading is required.|
| headers | Record\<string, string\> | Yes| HTTP headers that need to be included in the player's request for media resources.|
| attributes | Record\<string, string\> | Yes| Attributes in **\<video>** or **\<audio>**.|


## CreateNativeMediaPlayerCallback<sup>12+<sup>

type CreateNativeMediaPlayerCallback = (handler: NativeMediaPlayerHandler, mediaInfo: MediaInfo) => NativeMediaPlayerBridge

Represents a **CreateNativeMediaPlayerCallback** object used as a parameter of the [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12) callback.
This object is used to create a player to take over media playback of the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| handler | [NativeMediaPlayerHandler](#nativemediaplayerhandler12) | Yes| Object used to report the player status to the ArkWeb engine.|
| mediaInfo | [MediaInfo](#mediainfo12) | Yes| Information about the media on the web page.|

**Return value**

| Type| Description|
|------|------|
| [NativeMediaPlayerBridge](#nativemediaplayerbridge12) | Instance of the interface class between the player that takes over web media and the ArkWeb kernel.<br>The application needs to implement the interface class.<br> Object used by the ArkWeb engine to control the player created by the application to take over web page media.<br>If the application returns **null**, the application does not take over the media playback, and the media will be played by the ArkWeb engine.|

**Example**

For the complete sample code, see [onCreateNativeMediaPlayer](#oncreatenativemediaplayer12).

## OfflineResourceMap<sup>12+</sup>

Implements an **OfflineResourceMap** object, which is used to set up information related to local offline resources that will be injected into memory cache through the [injectOfflineResources](#injectofflineresources12) API. The ArkWeb engine will generate resource caches based on this information and control the validity period of the cache accordingly.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Readable| Writable|Description                |
| ----------- | ------ | -----|------|------------------- |
| urlList | Array\<string\> | Yes  | Yes  | List of network addresses of the local offline resources. The first item in the list is used as the resources' origin. If only one network address is provided, this single address is used for the resources' origin. The URL supports only the HTTP and HTTPS protocols and contains a maximum of 2048 characters.     |
| resource | Uint8Array | Yes  | Yes  | Content of a local offline resource.     |
| responseHeaders | Array<[WebHeader](#webheader)> | Yes  | Yes  | HTTP response headers corresponding to the resources. The **Cache-Control** or **Expires** response header is used to control the validity period of the resource in the memory cache. If neither of the headers is provided, a default validity time of 86400 seconds (1 day) will be applied. The **Content-Type** response header is used to define the MIME type of the resource. For resources of type MODULE_JS, a valid MIME type must be provided. For other types, the MIME type is optional, with no default value. A non-standard MIME type can lead to the resource being invalidated in the memory cache. If a **script** tag in the web page uses the **crossorigin** attribute, the **Cross-Origin** response header must be set in the **responseHeaders** parameter of the API. The value for this header should be **anonymous** or **use-credentials**.     |
| type | [OfflineResourceType](#offlineresourcetype12) | Yes  | Yes  | Resource type. Currently, only the JavaScript, image, and CSS types are supported.     |

## OfflineResourceType<sup>12+</sup>

Represents the local offline resource type corresponding to an [OfflineResourceMap](#offlineresourcemap12) object.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| IMAGE  | 0 | Resource of the image type.|
| CSS       | 1 | Resource of the CSS type.|
| CLASSIC_JS       | 2 | Javascript resource loaded through the <script src="" /\> tag.|
| MODULE_JS      | 3 |Javascript resource loaded through the <script src="" type="module" /\> tag.|

## WebResourceType<sup>12+</sup>

Enumerates the types of requested resources.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| MAIN_FRAME | 0 | Top-level page.|
| SUB_FRAME | 1 | Frame or Iframe.|
| STYLE_SHEET | 2 | CSS style sheet.|
| SCRIPT | 3 | External script.|
| IMAGE | 4 | Image (JPG, GIF, PNG, or other format).|
| FONT_RESOURCE | 5 | Font.|
| SUB_RESOURCE | 6 | Other sub-resource. If the type is unknown, it is used as the default type.|
| OBJECT | 7 | Object (or embed) tag of the plug-in, or the resource requested by the plug-in.|
| MEDIA | 8 | Media resource.|
| WORKER | 9 | Main resource of a dedicated worker thread.|
| SHARED_WORKER | 10 | Main resource of a shared worker thread.|
| PREFETCH | 11 | Explicit prefetch request.|
| FAVICON | 12 | Website icon.|
| XHR | 13 | XMLHttpRequest.|
| PING | 14 | <a ping\>/sendBeacon ping request.|
| SERVICE_WORKER | 15 | Main resource of a service worker.|
| CSP_REPORT | 16 | Report of Content Security Policy violation.|
| PLUGIN_RESOURCE | 17 | Resource requested by the plug-in.|
| NAVIGATION_PRELOAD_MAIN_FRAME | 19 | Main frame redirection request that triggers service worker preloading.|
| NAVIGATION_PRELOAD_SUB_FRAME | 20 | Subframe redirection request that triggers service worker preloading.|

## RectEvent<sup>12+<sup>

Defines a rectangle.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Readable| Writable| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x  | number   | Yes  | Yes  | X-axis coordinate of the upper left corner of the rectangle.   |
| y  | number   | Yes  | Yes  | Y-axis coordinate of the upper left corner of the rectangle.   |
| width  | number   | Yes  | Yes  | Width of the rectangle.   |
| height  | number   | Yes  | Yes  | Height of the rectangle.   |

## BackForwardCacheSupportedFeatures<sup>12+<sup>

Adds a page that uses any of the following features to the back-forward cache.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| nativeEmbed | boolean | Yes| Whether to add a page that uses same-layer rendering to the back-forward cache. The default value is **false**. When the value is set to **true**, you need to maintain the lifecycle of native controls created for the same-layer rendering elements to avoid resource leak.|
| mediaTakeOver | boolean | Yes| Whether to add a page that takes over media playback to the back-forward cache. The default value is **false**. When the value is set to **true**, you need to maintain the lifecycle of native controls created for video elements to avoid resource leak.|

## BackForwardCacheOptions<sup>12+<sup>

Implements a **BackForwardCacheOptions** object to set back-forward cache options of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| size | number | Yes| The maximum number of pages that can be cached in a **Web** component. The default value is **1**, and the maximum value is **50**. If this parameter is set to **0** or a negative value, the back-forward cache is disabled. The web reclaims the cache for memory pressure.|
| timeToLive | number | Yes| The time that a **Web** component allows a page to stay in the back-forward cache. The default value is **600**, in seconds. If this parameter is set to **0** or a negative value, the back-forward cache is disabled.|

## AdsBlockManager<sup>12+</sup>

Implements an **AdsBlockManager** instance to set custom ad blocking configurations in the **Web** components and disable the ad blocking feature for specific websites. Each application's **Web** components share an **AdsBlockManager** instance.

### setAdsBlockRules<sup>12+</sup>

static setAdsBlockRules(rulesFile: string, replace: boolean): void

Sets a custom ad blocking rule file that conforms to the universal EasyList syntax in the **Web** components.

> **NOTE**
>
> The ad blocking rules set by this API will be persistently stored after successful internal parsing; you do not need to set them again after the application is restarted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| rulesFile | string | Yes  | Path to the rule file that conforms to the universal EasyList syntax. The application needs to have read permission for this file.|
| replace   | boolean | Yes  | Whether to replace the built-in default rules. The value **true** indicates that the built-in default rules will be forcibly replaced; **false** indicates that the custom rules will work alongside the built-in default rules.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// This example demonstrates how to click a button to open an EasyList-compliant rule file through filepicker and set the file in the Web component.
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

Adds an array of domain names to the disallowed list of this **AdsBlockManager** object. When the ad blocking feature is enabled, ad blocking for these websites will be disabled.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The ad blocking feature matches website URLs based on the suffix. For example, if the disallowed list contains **'example.com'** or **'www.example.com'**, then ad blocking will be disabled for sites **https://www.example.com** and **https://m.example.com**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
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

Removes an array of domain names from the disallowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
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

Clears the disallowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Adds an array of domain names to the allowed list of this **AdsBlockManager** object. This API is typically used to re-enable ad blocking for certain websites that were previously added to the disallowed list.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The priority of the allowed list is higher than that of the disallowed list. For example, if the disallowed list includes **['example.com']**, all pages under the **example.com** domain will have their ad blocking disabled; to re-enable ad blocking for the subdomain **news.example.com**, you can use the **addAdsBlockAllowedList(['news.example.com'])** API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
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

Removes an array of domain names from the allowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
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

Clears the allowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

Provides information used to obtain a full drawing result.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type|  Mandatory| Description|
|------|------|------|------|
| id | string | No| Snapshot ID.|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)  | No| Size for web rendering. The maximum size is 16000 px x 16000 px. The length unit can be px, vp, or %. The length unit must be the consistent across parameters. The default unit is vp. If the size exceeds the specifications , the maximum size is returned. Example: **width: '100px', height: '200px'** or **width: '20%', height'30%'**. If only digits are written, the unit is vp.|

## SnapshotResult<sup>12+</sup>

Represents a full drawing result.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory|  Description|
|------|------|--|---------|
| id | string | No| Snapshot ID.|
| status | boolean | No|  Snapshot status. The value can be **true** (normal) or **false** (failure). If the full drawing result fails to be obtained, the width and height of the returned size are both 0, and the map is empty.|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)   | No| Actual size drawn on the web page. The value is of the number type, and the unit is vp.|
| imagePixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | No| Full drawing result in image.pixelMap format.|

## ScrollType<sup>12+</sup>

Represents a scroll type, which is used in [setScrollable](#setscrollable12).

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| EVENT  | 0 | Scrolling event, indicating that a web page is scrolled by using a touchscreen, a touchpad, or a mouse.|
