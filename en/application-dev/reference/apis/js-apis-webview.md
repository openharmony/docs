

# @ohos.web.webview (Webview)

The **Webview** module provides APIs for web control. It can be used with the **[<Web\>](../arkui-ts/ts-basic-components-web.md)** component, which can be used to display web pages.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how the APIs of this module work on a real device. The preview is not yet available in the DevEco Studio Previewer.

## Required Permissions

**ohos.permission.INTERNET**, required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).

## Modules to Import

```ts
import web_webview from '@ohos.web.webview';
```

## once

once(type: string, callback: Callback\<void\>): void

Registers a one-time callback for web events of the specified type.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type             | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| type     | string          | Yes  | Web event type. The value can be **"webInited"**, indicating completion of web initialization.     |
| headers | Callback\<void\> | Yes  | Callback to register.|

**Example**

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

Implements a **WebMessagePort** object to send and receive messages.

### postMessageEvent

postMessageEvent(message: WebMessage): void

Sends a message. For the complete sample code, see [postMessage](#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| message | [WebMessage](#webmessage) | Yes  | Message to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100010 | Can not post message using this port. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

  build() {
    Column() {
      Button('postMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            this.ports[1].postMessageEvent("post message from ets to html5");
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onMessageEvent

onMessageEvent(callback: (result: WebMessage) => void): void

Registers a callback to receive messages from the HTML5 side. For the complete sample code, see [postMessage](#postmessage).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | :------------------- |
| result | [WebMessage](#webmessage) | Yes  | Message received.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                       |
| -------- | ----------------------------------------------- |
| 17100006 | Can not register message event using this port. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### close

close(): void

Closes this message port. To use this API, a message port must first be created using [createWebMessagePorts](#createwebmessageports).

**System capability**: SystemCapability.Web.Webview.Core

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  msgPort: web_webview.WebMessagePort[] = null;

  build() {
    Column() {
      // Use createWebMessagePorts to create a message port.
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.msgPort = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.msgPort.length)
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebviewController

Implements a **WebviewController** to control the behavior of the **\<Web>** component. A **WebviewController** can control only one **\<Web>** component, and the APIs (except static APIs) in the **WebviewController** can be invoked only after it has been bound to the target **\<Web>** component.

### initializeWebEngine

static initializeWebEngine(): void

Loads the dynamic link library (DLL) file of the web engine. This API can be called before the **\<Web>** component is initialized to improve the startup performance.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

The following code snippet exemplifies calling this API after the EntryAbility is created.

```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log("EntryAbility onCreate")
        web_webview.WebviewController.initializeWebEngine()
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
| webDebuggingAccess | boolean | Yes  | Whether to enable web debugging.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  aboutToAppear():void {
    try {
      web_webview.WebviewController.setWebDebuggingAccess(true);
    } catch(error) {
      console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 17100003 | Invalid resource path or file type.                          |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // The URL to be loaded is of the string type.
            this.controller.loadUrl('www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // The headers parameter is carried.
            this.controller.loadUrl('www.example.com', [{headerKey: "headerKey", headerValue: "headerValue"}]);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

There are two methods for loading local resource files:
1. Using $rawfile
```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // The URL to be loaded is of the Resource type.
            this.controller.loadUrl($rawfile('index.html'));
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2. Using a sandbox path. For details, see the example of loading local resource files in the sandbox in [Web](../arkui-ts/ts-basic-components-web.md#web).

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| data       | string | Yes  | Character string obtained after being Base64 or URL encoded.                   |
| mimeType   | string | Yes  | Media type (MIME).                                          |
| encoding   | string | Yes  | Encoding type, which can be Base64 or URL.                      |
| baseUrl    | string | No  | URL (HTTP/HTTPS/data compliant), which is assigned by the **\<Web>** component to **window.origin**.|
| historyUrl | string | No  | URL used for historical records. If this parameter is not empty, historical records are managed based on this URL. This parameter is invalid when **baseUrl** is left empty.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  updataContent: string = '<body><div><image src=file:///data/storage/el1/bundle/entry/resources/rawfile/xxx.png alt="image -- end" width="500" height="250"></image></div></body>'

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(this.updataContent, "text/html", "UTF-8", " ", " ");
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessForward

accessForward(): boolean

Checks whether moving to the next page can be performed on the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Returns **true** if moving to the next page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessBackward

accessBackward(): boolean

Checks whether moving to the previous page can be performed on the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if moving to the previous page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onActive

onActive(): void

Invoked to instruct the **\<Web>** component to enter the active foreground state.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onInactive

onInactive(): void

Invoked to instruct the **\<Web>** component to enter the inactive state.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### refresh
refresh(): void

Invoked to instruct the **\<Web>** component to refresh the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearHistory

clearHistory(): void

Clears the browsing history.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### registerJavaScriptProxy

registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. After this API is called, call [refresh](#refresh) for the registration to take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                       |
| ---------- | -------------- | ---- | ------------------------------------------------------------ |
| object     | object         | Yes  | Application-side JavaScript object to be registered. Methods can be declared, but not attributes. The parameters and return values of the methods can only be of the string, number, or Boolean type.|
| name       | string         | Yes  | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string> | Yes  | Methods of the JavaScript object to be registered at the application side.                      |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct Index {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  testObj = {
    test: (data) => {
      return "ArkUI Web Component";
    },
    toString: () => {
      console.log('Web Component toString');
    }
  }

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObj, "objName", ["test", "toString"]);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

### runJavaScript

runJavaScript(script: string, callback : AsyncCallback\<string>): void

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string                   | Yes  | JavaScript script.                                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. Returns **null** if the JavaScript script fails to be executed or no value is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
import web_webview from '@ohos.web.webview'

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
            console.info('url: ', e.url);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
              .then(function (result) {
                console.log('result: ' + result);
              })
              .catch(function (error) {
                console.error("error: " + error);
              })
            console.info('url: ', e.url);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately without invoking the [refresh](#refresh) API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description |
| ------ | -------- | ---- | ---- |
| name   | string   | Yes  | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100008 | Cannot delete JavaScriptProxy.                               |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State name: string = 'Object';

  build() {
    Column() {
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister(this.name);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoom

zoom(factor: number): void

Zooms in or out of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | Yes  | Relative zoom ratio. A positive value indicates zoom-in, and a negative value indicates zoom-out.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100004 | Function not enable.                                         |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### searchAllAsync

searchAllAsync(searchString: string): void

Searches the web page for content that matches the keyword specified by **'searchString'** and highlights the matches on the page. This API returns the result asynchronously through [onSearchResultReceive](../arkui-ts/ts-basic-components-web.md#onsearchresultreceive9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type| Mandatory| Description      |
| ------------ | -------- | ---- | -------------- |
| searchString | string   | Yes  | Search keyword.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State searchString: string = "xxx";

  build() {
    Column() {
      Button('searchString')
        .onClick(() => {
          try {
            this.controller.searchAllAsync(this.searchString);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onSearchResultReceive(ret => {
          console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
          "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
        })
    }
  }
}
```

### clearMatches

clearMatches(): void

Clears the matches found through [searchAllAsync](#searchallasync).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### searchNext

searchNext(forward: boolean): void

Searches for and highlights the next match.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type| Mandatory| Description              |
| ------- | -------- | ---- | ---------------------- |
| forward | boolean  | Yes  | Whether to search forward.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearSslCache

clearSslCache(): void

Clears the user operation corresponding to the SSL certificate error event recorded by the **\<Web>** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearClientAuthenticationCache

clearClientAuthenticationCache(): void

Clears the user operation corresponding to the client certificate request event recorded by the **\<Web>** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### createWebMessagePorts

 createWebMessagePorts(): Array\<WebMessagePort>

Creates web message ports.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                  | Description             |
| ---------------------- | ----------------- |
| Array\<WebMessagePort> | List of web message ports.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

  ```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

  build() {
    Column() {
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.ports.length)
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
  ```

### postMessage

postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void

Sends a web message to an HTML5 window.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | :------------------------------- |
| name   | string                 | Yes  | Message to send, including the data and message port.|
| ports  | Array\<WebMessagePort> | Yes  | Ports for receiving the message.               |
| uri    | string                 | Yes  | URI for receiving the message.               |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];
  @State sendFromEts: string = 'Send this message from ets to HTML';
  @State receivedFromHtml: string = 'Display received message send from HTML';

  build() {
    Column() {
      // Display the received HTML content.
      Text(this.receivedFromHtml)
      // Send the content in the text box to an HTML window.
      TextInput({placeholder: 'Send this message from ets to HTML'})
        .onChange((value: string) => {
          this.sendFromEts = value;
      })

      Button('postMessage')
        .onClick(() => {
          try {
            // 1. Create two message ports.
            this.ports = this.controller.createWebMessagePorts();
            // 2. Register a callback on a message port (for example, port 1) on the application side.
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
            // 3. Send another message port (for example, port 0) to the HTML side, which can then save the port for future use.
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getWebId

getWebId(): number

Obtains the index value of this **\<Web>** component, which can be used for **\<Web>** component management.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| number | Index value of the current **\<Web>** component.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

You can customize the user agent based on the default user agent.
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State ua: string = ""

  aboutToAppear():void {
    web_webview.once('webInited', () => {
      try {
        // Customize the user agent on the application side.
        this.ua = this.controller.getUserAgent() + 'xxx';
      } catch(error) {
        console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

Obtains the title of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Title of the current web page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| number | Height of the current web page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| baseName | string                | Yes  | Save path. The value cannot be null.                                |
| autoName | boolean               | Yes  | Whether to automatically generate a file name. The value **false** means not to automatically generate a file name. The value **true** means to automatically generate a file name based on the URL of the current page and the **baseName** value. In this case, **baseName** is regarded as a directory.|
| callback | AsyncCallback\<string> | Yes  | Callback used to return the save path if the operation is successful and null otherwise.                  |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| baseName | string   | Yes  | Save path. The value cannot be null.                                |
| autoName | boolean  | Yes  | Whether to automatically generate a file name. The value **false** means not to automatically generate a file name. The value **true** means to automatically generate a file name based on the URL of the current page and the **baseName** value. In this case, **baseName** is regarded as a directory.|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<string> | Promise used to return the save path if the operation is successful and null otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
              .catch(error => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| x   | number   | Yes  | X coordinate of the absolute position. If the value is a negative number, the value 0 is used.|
| y   | number   | Yes  | Y coordinate of the absolute position. If the value is a negative number, the value 0 is used.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| deltaX | number   | Yes  | Amount to scroll by along the x-axis. The positive direction is rightward.|
| deltaY | number   | Yes  | Amount to scroll by along the y-axis. The positive direction is downward.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

### slideScroll

slideScroll(vx:number, vy:number): void

Simulates a slide-to-scroll action on the page at the specified velocity.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| vx     | number   | Yes  | Horizontal velocity component of the slide-to-scroll action, where the positive direction is rightward.|
| vy     | number   | Yes  | Vertical velocity component of the slide-to-scroll action, where the positive direction is downward.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                   |
| ------ | ----------------------- |
| string | Original URL of the current page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| [PixelMap](js-apis-image.md#pixelmap7) | **PixelMap** object of the favicon of the page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import image from "@ohos.multimedia.image"
@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State pixelmap: image.PixelMap = undefined;

  build() {
    Column() {
      Button('getFavicon')
        .onClick(() => {
          try {
            this.pixelmap = this.controller.getFavicon();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            .catch(function (error) {
              console.error("error: " + error);
            })
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| clearRom | boolean | Yes  | Whether to clear the cache in the ROM and RAM at the same time. The value **true** means to clear the cache in the ROM and RAM at the same time, and **false** means to only clear the cache in the RAM.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageUp

pageUp(top:boolean): void

Scrolls the page up by half the view port or jumps to the top of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| top    | boolean | Yes  | Whether to jump to the top of the page. The value **true** means to jump to the top of the page; and **false** means to scroll the page up by half the view port.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pageDown

pageDown(bottom:boolean): void

Scrolls the page down by half the view port or jumps to the bottom of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| bottom | boolean | Yes  | Whether to jump to the bottom of the page. The value **true** means to jump to the bottom of the page; and **false** means to scroll the page down by half the view port.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| [BackForwardList](#backforwardlist) | Historical information list of the current webview.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

1. To perform operations on files, you must import the file management module. For details, see [File Management](./js-apis-file-fs.md).
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import fs from '@ohos.file.fs';

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
            // globalThis.cacheDir is obtained from EntryAbility.ts.
            let path = globalThis.cacheDir;
            path += '/WebState';
            // Synchronously open a file.
            let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
            fs.writeSync(file.fd, state.buffer);
            fs.closeSync(file.fd);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2. Modify the **EntryAbility.ts** file.
Obtain the path of the application cache file.
```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        // Bind cacheDir to the globalThis object to implement data synchronization between the UIAbility component and the page.
        globalThis.cacheDir = this.context.cacheDir;
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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**Example**

1. To perform operations on files, you must import the file management module. For details, see [File Management](./js-apis-file-fs.md).
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import fs from '@ohos.file.fs';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('RestoreWebState')
        .onClick(() => {
          try {
            // globalThis.cacheDir is obtained from EntryAbility.ts.
            let path = globalThis.cacheDir;
            path += '/WebState';
            // Synchronously open a file.
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
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

2. Modify the **EntryAbility.ts** file.
Obtain the path of the application cache file.
```ts
// xxx.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        // Bind cacheDir to the globalThis object to implement data synchronization between the UIAbility component and the page.
        globalThis.cacheDir = this.context.cacheDir;
    }
}
```

### customizeSchemes

static customizeSchemes(schemes: Array\<WebCustomScheme\>): void

Customizes the URL schemes (also known as protocols). It is recommended that this API be called before any **\<Web>** component is initialized.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| schemes | Array\<[WebCustomScheme](#webcustomscheme)\> | Yes  | Array of up to 10 custom schemes.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
      console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onInterceptRequest((event) => {
          console.log('url:' + event.request.getRequestUrl())
          return this.responseweb
        })
    }
  }
}
```

## WebCookieManager

Implements a **WebCookieManager** instance to manage behavior of cookies in **\<Web>** components. All **\<Web>** components in an application share a **WebCookieManager** instance.

> **NOTE**
>
> You must load the **\<Web>** component before calling APIs in **WebCookieManager**.

### getCookie

static getCookie(url: string): string

Obtains the cookie corresponding to the specified URL.

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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### setCookie

static setCookie(url: string, value: string): void

Sets a cookie for the specified URL.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| url    | string | Yes  | URL of the cookie to set. A complete URL is recommended.|
| value  | string | Yes  | Cookie value to set.     |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invalid cookie value.                                  |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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


**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
              .catch((error) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| accept | boolean | Yes  | Whether the **WebCookieManager** instance has the permission to send and receive cookies.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

Sets whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                      |
| ------ | ------- | ---- | :----------------------------------------- |
| accept | boolean | Yes  | Whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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

Checks whether cookies exist.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Whether cookies exist.|

**Example**

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

### deleteEntireCookie

static deleteEntireCookie(): void

Deletes all cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

### deleteSessionCookie

static deleteSessionCookie(): void

Deletes all session cookies.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## WebStorage

Implements a **WebStorage** object to manage the Web SQL database and HTML5 Web Storage APIs. All **\<Web>** components in an application share a **WebStorage** object.

> **NOTE**
>
> You must load the **\<Web>** component before calling the APIs in **WebStorage**.

### deleteOrigin

static deleteOrigin(origin : string): void

Deletes all data in the specified origin.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| origin | string | Yes  | Index of the origin, which is obtained through [getOrigins](#getorigins).|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('deleteOrigin')
        .onClick(() => {
          try {
            web_webview.WebStorage.deleteOrigin(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOrigins

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void

Obtains information about all origins that are currently using the Web SQL Database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                  |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Yes  | Callback used to return the information about the origins. For details, see [WebStorageOrigin](#webstorageorigin).|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOrigins

static getOrigins() : Promise\<Array\<WebStorageOrigin>>

Obtains information about all origins that are currently using the Web SQL Database. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Promise used to return the information about the origins. For details, see [WebStorageOrigin](#webstorageorigin).|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
              .catch(e => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginQuota

static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void

Obtains the storage quota of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | Yes  | Index of the origin.|
| callback | AsyncCallback\<number> | Yes  | Storage quota of the origin.  |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginQuota

static getOriginQuota(origin : string) : Promise\<number>

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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota);
              })
              .catch(e => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginUsage

static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void

Obtains the storage usage of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | Yes  | Index of the origin.|
| callback | AsyncCallback\<number> | Yes  | Storage usage of the origin.  |

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginUsage

static getOriginUsage(origin : string) : Promise\<number>

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

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid origin.                            |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage);
              })
              .catch(e => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### deleteAllData

static deleteAllData(): void

Deletes all data in the Web SQL Database.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

## WebDataBase

Implements a **WebDataBase** object.

> **NOTE**
>
> You must load the **\<Web>** component before calling the APIs in **WebDataBase**.

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

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";
  username_password: string[];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.username_password = web_webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.log('num: ' + this.username_password.length);
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
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

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
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
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
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
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
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
> You must load the **\<Web>** component before calling the APIs in **GeolocationPermissions**.

### Required Permissions

**ohos.permission.LOCATION**, **ohos.permission.APPROXIMATELY_LOCATION**, and **ohos.permission.LOCATION_IN_BACKGROUND**, which are required for accessing the location information. For details about the permissions, see [@ohos.geolocation (Geolocation)](./js-apis-geolocation.md).

### allowGeolocation

static allowGeolocation(origin: string): void

Allows the specified origin to use the geolocation information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  |Index of the origin.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteGeolocation

static deleteGeolocation(origin: string): void

Clears the geolocation permission status of a specified origin.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| origin | string | Yes  | Index of the origin.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void

Obtains the geolocation permission status of the specified origin. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| origin   | string                 | Yes  | Index of the origin.                                          |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the geolocation permission status of the specified origin. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified origin is not found.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string): Promise\<boolean>

Obtains the geolocation permission status of the specified origin. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | -------- | ---- | -------------------- |
| origin | string   | Yes  | Index of the origin.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the geolocation permission status of the specified origin. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified origin is not found.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../errorcodes/errorcode-webview.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
              }).catch(error => {
              console.log('getAccessibleGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void

Obtains the geolocation permission status of all origins. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                    |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<Array\<string>> | Yes  | Callback used to return the geolocation permission status of all origins.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(): Promise\<Array\<string>>

Obtains the geolocation permission status of all origins. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                  | Description                                                     |
| ---------------------- | --------------------------------------------------------- |
| Promise\<Array\<string>> | Promise used to return the geolocation permission status of all origins.|

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
              }).catch(error => {
              console.log('getStoredGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteAllGeolocation

static deleteAllGeolocation(): void

Clears the geolocation permission status of all sources.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

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
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## WebHeader
Describes the request/response header returned by the **\<Web>** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Readable| Writable|Description                |
| ----------- | ------ | -----|------|------------------- |
| headerKey   | string | Yes| Yes| Key of the request/response header.  |
| headerValue | string | Yes| Yes| Value of the request/response header.|

## WebHitTestType

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| EditText      | 0 |Editable area.                           |
| Email         | 1 |Email address.                           |
| HttpAnchor    | 2 |Hyperlink whose **src** is **http**.                    |
| HttpAnchorImg | 3 |Image with a hyperlink, where **src** is **http**.|
| Img           | 4 |HTML::img tag.                          |
| Map           | 5 |Geographical address.                               |
| Phone         | 6 |Phone number.                               |
| Unknown       | 7 |Unknown content.                               |

##  HitTestValue

Provides the element information of the area being clicked. For details about the sample code, see **getHitTestValue**.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Readable| Writable| Description|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](#webhittesttype) | Yes| No| Element type of the area being clicked.|
| extra | string        | Yes| No|Extra information of the area being clicked. If the area being clicked is an image or a link, the extra information is the URL of the image or link.|

## WebMessage

Describes the data types supported for [WebMessagePort](#webmessageport).

**System capability**: SystemCapability.Web.Webview.Core

| Type      | Description                                    |
| -------- | -------------------------------------- |
| string   | String type.|
| ArrayBuffer   | Binary type.|

## WebStorageOrigin

Provides usage information of the Web SQL Database.

**System capability**: SystemCapability.Web.Webview.Core

| Name  | Type  | Readable| Writable| Description|
| ------ | ------ | ---- | ---- | ---- |
| origin | string | Yes | No| Index of the origin.|
| usage  | number | Yes | No| Storage usage of the origin.    |
| quota  | number | Yes | No| Storage quota of the origin.  |

## BackForwardList

Provides the historical information list of the current webview.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Readable| Writable| Description                                                        |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | Yes  | No  | Index of the current page in the page history stack.                                |
| size         | number | Yes  | No  | Number of indexes in the history stack. The maximum value is 50. If this value is exceeded, the earliest index will be overwritten.|

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

**Example**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';
import image from "@ohos.multimedia.image"

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State icon: image.PixelMap = undefined;

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
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
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
| icon          | [PixelMap](js-apis-image.md#pixelmap7) | Yes  | No  | **PixelMap** object of the icon on the historical page.|
| historyUrl    | string                                 | Yes  | No  | URL of the historical page.       |
| historyRawUrl | string                                 | Yes  | No  | Original URL of the historical page.   |
| title         | string                                 | Yes  | No  | Title of the historical page.          |

## WebCustomScheme

Defines a custom URL scheme.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Readable| Writable| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | Yes  | Yes  | Name of the custom URL scheme. The value can contain a maximum of 32 characters and include only lowercase letters, digits, periods (.), plus signs (+), and hyphens (-).       |
| isSupportCORS  | boolean   | Yes  | Yes  | Whether to support cross-origin resource sharing (CORS).   |
| isSupportFetch | boolean   | Yes  | Yes  | Whether to support fetch requests.          |
