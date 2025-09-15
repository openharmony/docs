# Interface (WebMessagePort)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements a **WebMessagePort** to send and receive [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) or [WebMessage](./arkts-apis-webview-t.md#webmessage) messages to the HTML5 side.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Read-Only| Optional| Description                                             |
| ------------ | ------ | ---- | ---- | ------------------------------------------------|
| isExtentionType<sup>10+</sup> | boolean | No  | Yes| Whether to use the extended interface such as [postMessageEventExt](#postmessageeventext10) and [onMessageEventExt](#onmessageeventext10) when creating a **WebMessagePort**.<br>The value **true** means to use the extended interface, and **false** means the opposite.<br>Default value: **false**.  |

## postMessageEvent

postMessageEvent(message: WebMessage): void

Sends a message of the [WebMessage](./arkts-apis-webview-t.md#webmessage) type to the HTML5 side. The [onMessageEvent](#onmessageevent) API must be invoked first. Otherwise, the message fails to be sent. For details about the sample code, see [postMessage](./arkts-apis-webview-WebviewController.md#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| message | [WebMessage](./arkts-apis-webview-t.md#webmessage) | Yes  | Message to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
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

## onMessageEvent

onMessageEvent(callback: (result: WebMessage) => void): void

Registers a callback on the application message port to receive messages of the [WebMessage](./arkts-apis-webview-t.md#webmessage) type from the HTML5 side. For details about the sample code, see [postMessage](./arkts-apis-webview-WebviewController.md#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | :------------------- |
| callback | (result: [WebMessage](./arkts-apis-webview-t.md#webmessage)) => void | Yes  | Message received.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                                       |
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
                console.info("received string message from html5, string is:" + msg);
              } else if (typeof (msg) == "object") {
                if (msg instanceof ArrayBuffer) {
                  console.info("received arraybuffer from html5, length is:" + msg.byteLength);
                } else {
                  console.info("not support");
                }
              } else {
                console.info("not support");
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

## postMessageEventExt<sup>10+</sup>

postMessageEventExt(message: WebMessageExt): void

Sends a message of the [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) type to the HTML5 side. You must call [onMessageEventExt](#onmessageeventext10) first. Otherwise, the message fails to be sent. For the complete sample code, see [onMessageEventExt](#onmessageeventext10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| message | [WebMessageExt](./arkts-apis-webview-WebMessageExt.md) | Yes  | Message to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100010 | Failed to post messages through the port. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

## onMessageEventExt<sup>10+</sup>

onMessageEventExt(callback: (result: WebMessageExt) => void): void

Registers a callback on the application message port to receive messages of the [WebMessageType](./arkts-apis-webview-e.md#webmessagetype10) type from the HTML5 side.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | :------------------- |
| callback | (result: [WebMessageExt](./arkts-apis-webview-WebMessageExt.md)) => void | Yes  | Message received.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                                       |
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
            console.info("In ArkTS side send true start");
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
            console.info("In ArkTS side send true start");
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
            console.info("In ArkTS side send true start");
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
            console.info("In ArkTS side send true start");
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
            console.info("In ArkTS side send true start");
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
            console.info("In ArkTS side send true start");
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
          console.info("In ArkTS side message onPageEnd init message channel");
          // 1. Create a message port.
          this.ports = this.controller.createWebMessagePorts(true);
          // 2. Send port 1 to HTML5.
          this.controller.postMessage("init_web_messageport", [this.ports[1]], "*");
          // 3. Save port 0 to the local host.
          this.nativePort = this.ports[0];
          // 4. Set the callback.
          this.nativePort.onMessageEventExt((result) => {
            console.info("In ArkTS side got message");
            try {
              let type = result.getType();
              console.info("In ArkTS side getType:" + type);
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

<!--code_no_check-->
```js
//index.js
var h5Port;
window.addEventListener('message', function(event) {
    if (event.data == 'init_web_messageport') {
        if(event.ports[0] != null) {
            h5Port = event.ports[0]; // 1. Save the port number sent from the eTS side.
            h5Port.onmessage = function(event) {
                console.info("hwd In html got message");
                // 2. Receive the message sent from the eTS side.
                var result = event.data;
                console.info("In html got message, typeof: ", typeof(result));
                console.info("In html got message, result: ", (result));
                if (typeof(result) == "string") {
                    console.info("In html got message, String: ", result);
                    document.getElementById("msg").innerHTML  =  "String:" + result;
                } else if (typeof(result) == "number") {
                  console.info("In html side got message, number: ", result);
                    document.getElementById("msg").innerHTML = "Number:" + result;
                } else if (typeof(result) == "boolean") {
                    console.info("In html side got message, boolean: ", result);
                    document.getElementById("msg").innerHTML = "Boolean:" + result;
                } else if (typeof(result) == "object") {
                    if (result instanceof ArrayBuffer) {
                        document.getElementById("msg2").innerHTML  =  "ArrayBuffer:" + result.byteLength;
                        console.info("In html got message, byteLength: ", result.byteLength);
                    } else if (result instanceof Error) {
                        console.info("In html error message, err:" + (result));
                        console.info("In html error message, typeof err:" + typeof(result));
                        document.getElementById("msg2").innerHTML  =  "Error:" + result.name + ", msg:" + result.message;
                    } else if (result instanceof Array) {
                        console.info("In html got message, Array");
                        console.info("In html got message, Array length:" + result.length);
                        console.info("In html got message, Array[0]:" + (result[0]));
                        console.info("In html got message, typeof Array[0]:" + typeof(result[0]));
                        document.getElementById("msg2").innerHTML  =  "Array len:" + result.length + ", value:" + result;
                    } else {
                        console.info("In html got message, not any instance of support type");
                        document.getElementById("msg").innerHTML  = "not any instance of support type";
                    }
                } else {
                    console.info("In html got message, not support type");
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
        console.info("In html send string message");
        h5Port.postMessage("hello");
        console.info("In html send string message end");
    } else {
        console.error("In html h5port is null, please init first");
    }
}
```

## close

close(): void

Closes this message port when messages do not need to be sent. Before calling this method, call [createWebMessagePorts](./arkts-apis-webview-WebviewController.md#createwebmessageports) to create a message port.

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
            console.info("createWebMessagePorts size:" + this.msgPort.length)
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
