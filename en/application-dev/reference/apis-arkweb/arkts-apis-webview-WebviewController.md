# Class (WebviewController)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Represents a **WebviewController** object used to control various behaviors of **Web** components, including page navigation, lifecycle status, and JavaScript interaction. A **WebviewController** object can control only one **Web** component, and the APIs (except static APIs) in the **WebviewController** can be invoked only after it has been bound to the target **Web** component.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## constructor<sup>11+</sup>

constructor(webTag?: string)

Constructs a **WebviewController** object.

> **NOTE**
>
> When no parameter is passed in **new webview.WebviewController()**, it indicates that the constructor is empty. If the C API is not used, no parameter needs to be passed.
> 
> When a valid string is passed in, **new webview.WebviewController("xxx")** can be used to distinguish multiple instances and invoke the methods of the corresponding instance.
> 
> When an empty parameter is passed in, such as **new webview.WebviewController("")** or **new webview.WebviewController(undefined)**, the parameter is meaningless that multiple instances cannot be distinguished and **undefined** is returned. You need to check whether the return value is normal.
>
> After the **Web** component is destroyed, the **WebViewController** is unbound, and exception 17100001 will be thrown when the non-static method of **WebViewController** is called. You need to pay attention to the calling time and capture exceptions to prevent abnormal process exit.

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
    console.info('Web test');
    return "Web test";
  }

  webString(): void {
    console.info('Web test toString');
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
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister("objTestName");
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
    <head>
      <meta charset="utf-8">
    </head>
    <body>
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <p id="webDemo"></p>
      <script type="text/javascript">
        function htmlTest() {
          // This function call expects to return "Web test"
          let webStr = objTestName.webTest();
          document.getElementById("webDemo").innerHTML=webStr;
          console.info('objTestName.webTest result:'+ webStr)
        }
      </script>
    </body>
</html>
```

## initializeWebEngine

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
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate")
    webview.WebviewController.initializeWebEngine()
    console.info("EntryAbility onCreate done")
  }
}
```

## setHttpDns<sup>10+</sup>

static setHttpDns(secureDnsMode:SecureDnsMode, secureDnsConfig:string): void

Sets how the **Web** component uses HTTPDNS for DNS resolution.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| secureDnsMode         |   [SecureDnsMode](./arkts-apis-webview-e.md#securednsmode10)   | Yes  | Mode in which HTTPDNS is used.|
| secureDnsConfig       | string | Yes| Information about the HTTPDNS server to use, which must use HTTPS. Only one HTTPDNS server can be configured.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |

**Example**

```ts
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate")
    try {
      webview.WebviewController.setHttpDns(webview.SecureDnsMode.AUTO, "https://example1.test")
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }

    AppStorage.setOrCreate("abilityWant", want);
    console.info("EntryAbility onCreate done")
  }
}
```

## setWebDebuggingAccess

static setWebDebuggingAccess(webDebuggingAccess: boolean): void

Sets whether to enable web debugging. For details, see [Debugging Frontend Pages by Using DevTools](../../web/web-debugging-with-devtools.md).

NOTE: Enabling web debugging allows users to check and modify the internal status of the web page, which poses security risks. Therefore, you are advised not to enable this feature in the officially released version of the application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webDebuggingAccess | boolean | Yes  | Sets whether to enable web debugging.<br>The value **true** indicates that web debugging is enabled, and **false** indicates the opposite .<br>Default value: **false**.|

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

## loadUrl

loadUrl(url: string | Resource, headers?: Array\<WebHeader>): void

Loads a specified URL.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | :-------------------- |
| url     | string \| Resource | Yes  | URL to load.     |
| headers | Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)> | No  | Additional HTTP request header of the URL.<br>Default value: **[]**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.                                                 |
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

1. Using $rawfile.
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

3. Load the local file through the sandbox path. For details, see the sample code for loading the sandbox path in [Loading Web Pages](../../web/web-page-loading-with-web-components.md#loading-local-pages).

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

## loadData

loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void

Loads specified data.

When both **baseUrl** and **historyUrl** are empty:

If **encoding** is not base64 (including null values), ASCII encoding is used for octets within the secure URL character range, and the standard %xx hexadecimal encoding of the URL is used for octets outside the secure URL character range.

**data** must be encoded using Base64 or any hash (#) in the content must be encoded as %23. Otherwise, hash (#) is considered as the end of the content, and the remaining text is used as the document fragment identifier.

> **NOTE**
>
> - To load a local image, you can assign a space to either **baseUrl** or **historyUrl**. For details, see the sample code.
>
> - In the scenario of loading a local image, **baseUrl** and **historyUrl** cannot be both empty. Otherwise, the image cannot be loaded.
>
> - If the rich text in HTML contains special characters such as hash (#), you are advised to set the values of **baseUrl** and **historyUrl** to spaces.
>
> - To load texts, you need to set `<meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">` to avoid inconsistent font sizes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| data       | string | Yes  | String obtained after being base64 or URL encoded.                   |
| mimeType   | string | Yes  | Media type (MIME).                                          |
| encoding   | string | Yes  | Encoding type, which can be base64 or URL.                      |
| baseUrl    | string | No  | URL (HTTP/HTTPS/data compliant), which is assigned by the **Web** component to **window.origin**. If a large number of HTML files need to be loaded, set this parameter to **data**.|
| historyUrl | string | No  | URL used for historical records. If this parameter is not empty, historical records are managed based on this URL. This parameter is invalid when **baseUrl** is left empty.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

Specify **baseURL**.
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
              "<img src=aa/bb.jpg>," // Attempt to load the image from "https: // xxx.com/" + "aa/bb.jpg".
              "text/html",
              "UTF-8",
              "https://xxx.com/",
              "about:blank"
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
  updataContent: string = '<body><div><image src="resource://rawfile/xxx.png" alt="image -- end" width="500" height="250"></image></div></body>'

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

Load the sandbox image.
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
              "<img src=bb.jpg>", // Try to download the image from "file:///xxx/" + "bb.jpg".
              "text/html",
              "UTF-8",
              // Load the image path in the local application sandbox. Change the path to the actual sandbox path.
              "file:///data/storage/el2/base/haps/entry/files/data/.cache_dir/",
              ""
            );
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .fileAccess(true) // Enable the file access functionality to load images in the application sandbox.
    }
  }
}
```

## accessForward

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

You can use [getBackForwardEntries](#getbackforwardentries) to obtain the historical information list of the current WebView and use [accessStep](#accessstep) to determine whether to move forward or backward based on the specified number of steps.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | **true** is returned if going to the next page can be performed on the current page; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## forward

forward(): void

Moves to the next page based on the history stack. This API is generally used together with **accessForward**.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## accessBackward

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

You can use [getBackForwardEntries](#getbackforwardentries) to obtain the historical information list of the current WebView and use [accessStep](#accessstep) to determine whether to move forward or backward based on the specified number of steps.

> **NOTE**
>
> If [setCustomUserAgent](#setcustomuseragent10) is called when the **Web** component is loaded for the first time, the value of **accessBackward** may be **false** when there are multiple historical entries. That is, there is no backward entry. You are advised to call the **setCustomUserAgent** method to set a user agent before using **loadUrl** to load a specific page.
>
> Causes: When the **Web** component is loaded for the first time, calling [setCustomUserAgent](#setcustomuseragent10) causes the component to reload and retain the initial history entry. Then the new entry replaces the initial history entry and no new history entry is generated. As a result, the value of **accessBackward** is false.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | **true** is returned if going to the previous page can be performed on the current page. Otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## backward

backward(): void

Moves to the previous page based on the history stack. This API is generally used together with [accessBackward](#accessbackward).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## onActive

onActive(): void

Called when the **Web** component enters the active state.
<br>The application can interact with the user while in the active foreground state, and it remains in this state until the focus is moved away from it due to some event (for example, an incoming call is received or the device screen is turned off).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## onInactive

onInactive(): void

Called when the **Web** component enters the inactive state. You can implement the behavior to perform after the application loses focus.

When this API is called, any content that can be safely paused, such as animations and geographical locations, is paused as much as possible. However, the JavaScript is not paused. To pause the JavaScript globally, use [pauseAllTimers](#pausealltimers12). To reactivate the **Web** component, use [onActive](#onactive).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## refresh

refresh(): void

Called when the **Web** component refreshes the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## accessStep

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
| boolean | Whether a specific number of steps forward or backward can be performed on the current page.<br>**true** is returned if a specific number of steps forward or backward can be performed on the current page; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            console.info('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearHistory

clearHistory(): void

Clears the browsing history. You are not advised to call **clearHistory()** in **onErrorReceive()** and **onPageBegin()**. Otherwise, abnormal exit occurs.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## registerJavaScriptProxy

registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>, asyncMethodList?: Array\<string>, permission?: string): void

Registers a proxy for interaction between the application and web pages loaded by the **Web** component.
<br>Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. After this API is called, call [refresh](#refresh) for the registration to take effect.
<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).

> **NOTE**
>
> - The **registerJavaScriptProxy** API must be used together with the **deleteJavaScriptRegister** API to prevent memory leak.
> - It is recommended that **registerJavaScriptProxy** be used only with trusted URLs and over secure HTTPS connections. Injecting JavaScript objects into untrusted web components can expose your application to malicious attacks.
> - After **registerJavaScriptProxy** is called, the application exposes the registered JavaScript object to all page frames.
> - If a **registerJavaScriptProxy** is both registered in the synchronous and asynchronous lists, it is called asynchronously by default.
> - You should register **registerJavaScriptProxy** either in synchronous list or in asynchronous list. Otherwise, this API fails to be registered.
> - After the HTML5 thread submits an asynchronous JavaScript task to the ETS main thread, the HTML5 thread can continue to execute subsequent tasks without waiting for the task execution to complete and return a result. In this way, scenarios where the HTML5 thread is blocked due to long-running JavaScript tasks or a congested ETS thread can be effectively reduced. However, an asynchronous JavaScript task cannot return a value, and a task execution sequence cannot be ensured. Therefore, you should determine whether to use a synchronous or asynchronous function based on a specific scenario.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                       |
| ---------- | -------------- | ---- | ------------------------------------------------------------ |
| object     | object         | Yes  | Application-side JavaScript object to be registered. Methods and attributes can be declared separately, but cannot be registered and used at the same time. If an object contains only attributes, HTML5 can access the attributes in the object. If an object contains only methods, HTML5 can access the methods in the object.<br>1. The parameter and return value can be any of the following types:<br>string, number, boolean.<br>2. Dictionary or Array, with a maximum of 10 nested layers and 10,000 data records per layer.<br>3. Object, which must contain the **methodNameListForJsProxy:[fun1, fun2]** attribute, where **fun1** and **fun2** are methods that can be called.<br>4. The parameter also supports Function and Promise. Their callback cannot have return values.<br>5. The return value supports Promise. Its callback cannot have a return value.|
| name       | string         | Yes  | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string> | Yes  | Synchronous methods of the JavaScript object to be registered at the application side.                      |
| asyncMethodList<sup>12+</sup> | Array\<string> | No  | Asynchronous methods of the JavaScript object to be registered at the application side. The default value is null. Asynchronous methods cannot obtain return values. |
| permission<sup>12+</sup> | string | No  | JSON string, which is empty by default. This string is used to configure JSBridge permission control and define the URL trustlist at the object and method levels.<br>1. The **scheme** and **host** parameters cannot be empty. The **host** does not support wildcards and can contain only complete host names.<br>2. You can configure only the object-level trustlist, which takes effect for all JSBridge methods.<br>3. If method-level trustlists are configured for JSBridge method A, the intersection of object-level and method-level trustlists takes effect.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

class TestObj {
  constructor() {
  }

  test(testStr: string): string {
    console.info('Web Component str' + testStr);
    return testStr;
  }

  toString(): void {
    console.info('Web Component toString');
  }

  testNumber(testNum: number): number {
    console.info('Web Component number' + testNum);
    return testNum;
  }

  asyncTestBool(testBol: boolean): void {
    console.info('Web Component boolean' + testBol);
  }
}

class WebObj {
  constructor() {
  }

  webTest(): string {
    console.info('Web test');
    return "Web test";
  }

  webString(): void {
    console.info('Web test toString');
  }
}

class AsyncObj {
  constructor() {
  }

  asyncTest(): void {
    console.info('Async test');
  }

  asyncString(testStr: string): void {
    console.info('Web async string' + testStr);
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
            // Register both synchronous and asynchronous functions.
            this.controller.registerJavaScriptProxy(this.testObjtest, "objName", ["test", "toString", "testNumber"], ["asyncTestBool"]);
            // Register only the synchronous function.
            this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);
            // Register only the asynchronous function.
            this.controller.registerJavaScriptProxy(this.asyncTestObj, "objAsyncName", [], ["asyncTest", "asyncString"]);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister("objName");
            this.controller.deleteJavaScriptRegister("objTestName");
            this.controller.deleteJavaScriptRegister("objAsyncName");
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
    <head>
      <meta charset="utf-8">
    </head>
    <body>
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <p id="webDemo"></p>
      <p id="asyncDemo"></p>
      <script type="text/javascript">
        function htmlTest() {
          // This function call expects to return "ArkUI Web Component"
          let str=objName.test("webtest data");
          objName.testNumber(1);
          objName.asyncTestBool(true);
          document.getElementById("demo").innerHTML=str;
          console.info('objName.test result:'+ str)

          // This function call expects to return "Web test"
          let webStr = objTestName.webTest();
          document.getElementById("webDemo").innerHTML=webStr;
          console.info('objTestName.webTest result:'+ webStr)

          objAsyncName.asyncTest();
          objAsyncName.asyncString("async test data");
        }
      </script>
    </body>
</html>
```
For more examples, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).

## runJavaScript

runJavaScript(script: string, callback : AsyncCallback\<string>): void

Executes a JavaScript script asynchronously in the context of the current page. This API uses an asynchronous callback to return the script execution result. This method and its callback must be used on the UI thread.

> **NOTE**
>
> - The JavaScript status is no longer retained during navigation operations (such as **loadUrl**). For example, the global variables and functions defined before **loadUrl** is called do not exist on the loaded page.
> - You are advised to use **registerJavaScriptProxy** to maintain the JavaScript status during page navigation.
> - Currently, objects cannot be transferred, but structs can be transferred.
> - The asynchronous method cannot obtain the return value. You need to determine whether to use the synchronous or asynchronous method based on the specific scenario.
> - The string data type passed from the frontend page to native is treated as JSON-formatted and need to be deserialized with JSON.parse.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string                   | Yes  | JavaScript script.                                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. **null** is returned if the JavaScript script fails to be executed or no value is returned.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    Hello world!
    <script type="text/javascript">
      function test() {
        console.info('Ark WebComponent')
        return "This value is from index.html"
      }
    </script>
  </body>
</html>
```

## runJavaScript

runJavaScript(script: string): Promise\<string>

Executes a JavaScript script asynchronously in the context of the current page. This API uses a promise to return the script execution result. This method and its callback must be used on the UI thread.

> **NOTE**
>
> - The JavaScript status is no longer retained during navigation operations (such as **loadUrl**). For example, the global variables and functions defined before **loadUrl** is called do not exist on the loaded page.
> - You are advised to use **registerJavaScriptProxy** to maintain the JavaScript status during page navigation.
> - Currently, objects cannot be transferred, but structs can be transferred.
> - The asynchronous method cannot obtain the return value. You need to determine whether to use the synchronous or asynchronous method based on the specific scenario.
> - The string data type passed from the frontend page to native is treated as JSON-formatted and need to be deserialized with JSON.parse.

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
                console.info('result: ' + result);
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
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    Hello world!
    <script type="text/javascript">
      function test() {
        console.info('Ark WebComponent')
        return "This value is from index.html"
      }
    </script>
  </body>
</html>
```

## runJavaScriptExt<sup>10+</sup>

runJavaScriptExt(script: string | ArrayBuffer, callback : AsyncCallback\<JsMessageExt>): void

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScriptExt** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

> **NOTE**
>
> - The string data type passed from the frontend page to native is treated as JSON-formatted and need to be deserialized with JSON.parse.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| script   | string \| ArrayBuffer<sup>12+</sup>         | Yes  | JavaScript script.|
| callback | AsyncCallback\<[JsMessageExt](./arkts-apis-webview-JsMessageExt.md)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
                    console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
                  }
                }
              });
            if (e) {
              console.info('url: ', e.url);
            }
          } catch (resError) {
            console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
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
            let uiContext : UIContext = this.getUIContext();
            let context : Context | undefined = uiContext.getHostContext() as common.UIAbilityContext;
            let filePath = context!.filesDir + 'test.txt';
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
                    console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
                  }
                }
              });
          } catch (resError) {
            console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
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

## runJavaScriptExt<sup>10+</sup>

runJavaScriptExt(script: string | ArrayBuffer): Promise\<JsMessageExt>

Executes a JavaScript script. This API uses a promise to return the script execution result. **runJavaScriptExt** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

> **NOTE**
>
> - The string data type passed from the frontend page to native is treated as JSON-formatted and need to be deserialized with JSON.parse.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description        |
| ------ | -------- | ---- | ---------------- |
| script | string \| ArrayBuffer<sup>12+</sup> | Yes  | JavaScript script.|

**Return value**

| Type           | Description                                               |
| --------------- | --------------------------------------------------- |
| Promise\<[JsMessageExt](./arkts-apis-webview-JsMessageExt.md)> | Promise used to return the script execution result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            let uiContext : UIContext = this.getUIContext();
            let context : Context | undefined = uiContext.getHostContext() as common.UIAbilityContext;
            let filePath = context!.filesDir + 'test.txt';
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

## deleteJavaScriptRegister

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
    console.info('Web Component toString');
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
    <head>
      <meta charset="utf-8">
    </head>
    <body>
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <script type="text/javascript">
        function htmlTest() {
          let str=objName.test();
          document.getElementById("demo").innerHTML=str;
          console.info('objName.test result:'+ str)
        }
      </script>
    </body>
</html>
```

## zoom

zoom(factor: number): void

Zooms in or out of this web page. This API is effective only when [zoomAccess](arkts-basic-components-web-attributes.md#zoomaccess) is **true**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | Yes  | Relative zoom ratio. The value must be greater than 0. The value **1** indicates that the page is not zoomed. A value smaller than **1** indicates zoom-out, and a value greater than **1** indicates zoom-in.<br>Value range: (0, 100]|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
  @State factor: number = 2;

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

## searchAllAsync

searchAllAsync(searchString: string): void

Searches the web page for content that matches the keyword specified by **'searchString'** and highlights the matches on the page. This API returns the result asynchronously through [onSearchResultReceive](./arkts-basic-components-web-events.md#onsearchresultreceive9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type| Mandatory| Description      |
| ------------ | -------- | ---- | -------------- |
| searchString | string   | Yes  | Search keyword.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            console.info("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
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

## clearMatches

clearMatches(): void

Clears the matches found through [searchAllAsync](#searchallasync).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## searchNext

searchNext(forward: boolean): void

Searches for and highlights the next match.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type| Mandatory| Description              |
| ------- | -------- | ---- | ---------------------- |
| forward | boolean  | Yes  | Whether to search forward or backward.<br>The value **true** indicates a forward search, and the value **false** indicates a backward search.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## clearSslCache

clearSslCache(): void

Clears the user operation corresponding to the SSL certificate error event recorded by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## clearClientAuthenticationCache

clearClientAuthenticationCache(): void

Clears the user operation corresponding to the client certificate request event recorded by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## createWebMessagePorts

createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>

Creates web message ports.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | :------------------------------|
| isExtentionType<sup>10+</sup>   | boolean     | No | Whether to use the extended interface.<br>The value **true** means to use the extended interface, and **false** means the opposite.<br>Default value: **false**.|

**Return value**

| Type                  | Description             |
| ---------------------- | ----------------- |
| Array\<[WebMessagePort](./arkts-apis-webview-WebMessagePort.md)> | List of web message ports.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

For details about the sample code, see [onMessageEventExt](./arkts-apis-webview-WebMessagePort.md#onmessageeventext10).

## postMessage

postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void

Sends a web message to an HTML window.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | :------------------------------- |
| name   | string                 | Yes  | Name of the message to send.           |
| ports  | Array\<[WebMessagePort](./arkts-apis-webview-WebMessagePort.md)> | Yes  | Message ports for sending the message.           |
| uri    | string                 | Yes  | URI for receiving the message.               |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
                console.info("received string message from html5, string is:" + result);
                msg = msg + result;
              } else if (typeof (result) == "object") {
                if (result instanceof ArrayBuffer) {
                  console.info("received arraybuffer from html5, length is:" + result.byteLength);
                  msg = msg + "length is " + result.byteLength;
                } else {
                  console.info("not support");
                }
              } else {
                console.info("not support");
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

<!--code_no_check-->
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
                console.info("received string message from html5, string is:" + result);
                msg = msg + result;
              } else if (typeof(result) == "object") {
                if (result instanceof ArrayBuffer) {
                  console.info("received arraybuffer from html5, length is:" + result.byteLength);
                  msg = msg + "length is " + result.byteLength;
                } else {
                  console.info("not support");
                }
              } else {
                console.info("not support");
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

## requestFocus

requestFocus(): void

Requests focus for this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## zoomIn

zoomIn(): void

Zooms in on this web page by 25%.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## zoomOut

zoomOut(): void

Zooms out of this web page by 20%.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## getWebId

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("id: " + id);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getUserAgent

getUserAgent(): string

Obtains the default user agent of this web page.

For details about the default **User-Agent**, see [Developing User-Agent](../../web/web-default-userAgent.md).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description          |
| ------ | -------------- |
| string | Default user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("userAgent: " + userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

You can customize **User-Agent** based on the default **User-Agent**.
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
        // Customize a User-Agent on the application side.
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

## getTitle

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("title: " + title);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getPageHeight

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## storeWebArchive

storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void

Stores this web page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type             | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| baseName | string                | Yes  | Save path of the web page. The value cannot be null.                                |
| autoName | boolean               | Yes  | Whether to automatically generate a file name.<br>The value **false** means to name and store a file based on the **baseName** value. The value **true** means to automatically generate a file name based on the current URL and store the file in the **baseName** directory.|
| callback | AsyncCallback\<string> | Yes  | Callback used to return the save path if the operation is successful and null otherwise.                  |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## storeWebArchive

storeWebArchive(baseName: string, autoName: boolean): Promise\<string>

Stores this web page. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type| Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| baseName | string   | Yes  | Save path of the web page. The value cannot be null.                                |
| autoName | boolean  | Yes  | Whether to automatically generate a file name.<br>The value **false** means to name and store a file based on the **baseName** value. The value **true** means to automatically generate a file name based on the current URL and store the file in the **baseName** directory.|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<string> | Promise used to return the save path if the operation is successful and null otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                                   |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## getUrl

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("url: " + url);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## stop

stop(): void

Stops page loading.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## backOrForward

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## scrollTo

scrollTo(x:number, y:number, duration?:number): void

Scrolls the page to the specified absolute position within a specified period.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| x   | number   | Yes  | X coordinate of the absolute position. If the value is a negative number, the value 0 is used.<br>Unit: vp|
| y   | number   | Yes  | Y coordinate of the absolute position. If the value is a negative number, the value 0 is used.<br>Unit: vp|
| duration<sup>14+</sup> | number | No| Scrolling animation duration,<br>in milliseconds.<br>If no value is input or the input value is a negative number or 0, the animation is disabled.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            this.controller.scrollTo(50, 50, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Button('stopScroll')
        .onClick(() => {
          try {
            this.controller.scrollBy(0, 0, 1); // If you want to stop the animation generated by the current scroll, you can generate another 1 ms animation to interrupt the animation.
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
            border:5px solid blueviolet;
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```

## scrollBy

scrollBy(deltaX:number, deltaY:number,duration?:number): void

Scrolls the page by the specified amount within a specified period.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | Yes  | Amount to scroll by along the x-axis. The positive direction is rightward.<br>Unit: vp|
| deltaY | number   | Yes  | Amount to scroll by along the y-axis. The positive direction is downward.<br>Unit: vp|
| duration<sup>14+</sup> | number | No| Scrolling animation duration,<br>in milliseconds.<br>If no value is input or the input value is a negative number or 0, the animation is disabled.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            this.controller.scrollBy(50, 50, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('stopScroll')
        .onClick(() => {
          try {
            this.controller.scrollBy(0, 0, 1); // If you want to stop the animation generated by the current scroll, you can generate another 1 ms animation to interrupt the animation.
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
            border:5px solid blueviolet;
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```
## scrollByWithResult<sup>12+</sup>

scrollByWithResult(deltaX: number, deltaY: number): boolean

Scrolls the page by the specified amount and returns value to indicate whether the scrolling is successful.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| deltaX | number   | Yes  | Amount to scroll by along the x-axis. The positive direction is rightward.<br>Unit: vp|
| deltaY | number   | Yes  | Amount to scroll by along the y-axis. The positive direction is downward.<br>Unit: vp|

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether the current web page can be scrolled. The value **true** indicates that the current web page can be scrolled, and the value **false** indicates the opposite.<br>Default value: **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
          console.info("original result: " + result);
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
            border:5px solid blueviolet;
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```
## slideScroll

slideScroll(vx:number, vy:number): void

Simulates a slide-to-scroll action on the page at the specified velocity.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| vx     | number   | Yes  | Horizontal velocity component of the slide-to-scroll action, where the positive direction is rightward.<br>Unit: vp/ms.|
| vy     | number   | Yes  | Vertical velocity component of the slide-to-scroll action, where the positive direction is downward.<br>Unit: vp/ms.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            border:5px solid blueviolet;
        }
    </style>
</head>
<body>
Scroll Test
</body>
</html>
```

## getOriginalUrl

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("original url: " + url);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getFavicon

getFavicon(): image.PixelMap

Obtains the favicon of this page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                  | Description                           |
| -------------------------------------- | ------------------------------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | **PixelMap** object of the favicon of the page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## setNetworkAvailable

setNetworkAvailable(enable: boolean): void

Sets the **window.navigator.onLine** attribute in JavaScript.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | --------------------------------- |
| enable | boolean | Yes  | Whether the **window.navigator.onLine** attribute is enabled.<br>The value **true** indicates that the **window.navigator.onLine** attribute is enabled, and the value **false** indicates the opposite.<br>Default value: **true**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
    // Check whether the browser is online.
    var online1 = navigator.onLine;
    document.getElementById("demo").innerHTML = "Browser online:" + online1;

    function func(){
      var online2 = navigator.onLine;
      document.getElementById("demo").innerHTML = "Browser online:" + online2;
    }
</script>
</body>
</html>
```

## hasImage

hasImage(callback: AsyncCallback\<boolean>): void

Checks whether this page contains images. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                      |
| -------- | ----------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result.<br> The value **true** indicates that this page contains images, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## hasImage

hasImage(): Promise\<boolean>

Checks whether this page contains images. This API uses a promise to return the result.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise used to return the result.<br> The value **true** indicates that this page contains images, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## removeCache

removeCache(clearRom: boolean): void

Removes all Webview cache files in an application.

> **NOTE**
>
> You can view the Webview cache in the **data/storage/el2/base/cache/web/Cache** directory.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| clearRom | boolean | Yes  | Whether to clear the cache files in both ROM and RAM. If this parameter is set to **true**, the cache files in both ROM and RAM are cleared. If this parameter is set to **false**, only the cache files in RAM are cleared.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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

## removeAllCache<sup>18+</sup>

static removeAllCache(clearRom: boolean): void

Removes all Webview cache files in an application.

> **NOTE**
>
> You can view the WebView cache files in the **data/app/el2/100/base/\<applicationPackageName\>/cache/web/** directory.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| clearRom | boolean | Yes  | Whether to clear the cache files in both ROM and RAM. If this parameter is set to **true**, the cache files in both ROM and RAM are cleared. If this parameter is set to **false**, only the cache files in RAM are cleared.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
      Button('removeAllCache')
        .onClick(() => {
          try {
            webview.WebviewController.removeAllCache(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## pageUp

pageUp(top: boolean): void

Scrolls the page up by half the viewport or jumps to the top of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| top    | boolean | Yes  | Whether to jump to the top of the page.<br>The value **false** means to scroll the page up by half the viewport, and the value **true** means to jump to the top of the page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
      Web({ src: $rawfile("index.html"), controller: this.controller })
    }
  }
}
```
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" id="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        .blue {
          background-color: lightblue;
        }
        .green {
          background-color: lightgreen;
        }
        .blue, .green {
         font-size:16px;
         height:200px;
         text-align: center;       /* Horizontally centered */
         line-height: 200px;       /* Vertically centered (the height matches the container height) */
        }
    </style>
</head>
<body>
<div class="blue" >webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
</body>
</html>
```

## pageDown

pageDown(bottom: boolean): void

Scrolls the page down by half the viewport or jumps to the bottom of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| bottom | boolean | Yes  | Whether to jump to the bottom of the page.<br>The value **false** means to scroll the page down by half the viewport, and the value **true** means to jump to the bottom of the page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
      Web({ src: $rawfile("index.html"), controller: this.controller })
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
    <meta name="viewport" id="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        .blue {
          background-color: lightblue;
        }
        .green {
          background-color: lightgreen;
        }
        .blue, .green {
         font-size:16px;
         height:200px;
         text-align: center;       /* Horizontally centered */
         line-height: 200px;       /* Vertically centered (the height matches the container height) */
        }
    </style>
</head>
<body>
<div class="blue" >webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
</body>
</html>
```

## getBackForwardEntries

getBackForwardEntries(): BackForwardList

Obtains the historical information list of the current webview.

> **NOTE**
>
> [onLoadIntercept](./arkts-basic-components-web-events.md#onloadintercept10) is triggered when the loading starts. At this time, no historical node is generated. Therefore, the historical stack obtained by calling **getBackForwardEntries** in **onLoadIntercept** does not include the page that is being loaded.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| [BackForwardList](./arkts-apis-webview-BackForwardList.md) | The historical information list of the current webview.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## serializeWebState

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## restoreWebState

restoreWebState(state: Uint8Array): void

Restores the page status history from the serialized data of the current WebView.

If the value of **state** is too large, exceptions may occur. It is recommended that the page status history be not restored when the **state** value is greater than 512 KB.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type      | Mandatory| Description                        |
| ------ | ---------- | ---- | ---------------------------- |
| state  | Uint8Array | Yes  | Serialized data of the page status history.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
                  console.error("console error with error message: " + err.message + ", error code: " + err.code);
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

## customizeSchemes

static customizeSchemes(schemes: Array\<WebCustomScheme\>): void

Grants the cross-domain request and fetch request permissions for the specified URL schemes (also known as protocols) to the web kernel. A cross-domain fetch request for any of the specified URL schemes can be intercepted by the [onInterceptRequest](./arkts-basic-components-web-events.md#oninterceptrequest9) API, so that you can further process the request. It is recommended that this API be called before any **Web** component is initialized.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| schemes | Array\<[WebCustomScheme](./arkts-apis-webview-i.md#webcustomscheme)\> | Yes  | Array of up to 10 custom schemes.|

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
            console.info('url:' + event.request.getRequestUrl());
          }
          return this.responseWeb;
        })
    }
  }
}
```

## getCertificate<sup>10+</sup>

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

## getCertificate<sup>10+</sup>

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

## setAudioMuted<sup>10+</sup>

setAudioMuted(mute: boolean): void

Mutes this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| mute | boolean | Yes  | Whether to mute the web page.<br>The value **true** means to mute the web page, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## prefetchPage<sup>21+</sup>

prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>, prefetchOptions?: PrefetchOptions): void

Prefetches resources in the background for a page that is likely to be accessed in the near future, without executing the page JavaScript code or presenting the page. This can significantly reduce the load time for the prefetched page.

> **NOTE**
>
> - The downloaded page resources are cached for about 5 minutes. After this period, the **Web** component automatically releases the resources.
>
> - **prefetchPage** can also prefetch 302 redirect pages.
>
> - When a page is loaded after **prefetchPage** is executed, the prefetched resources are directly loaded from the cache.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type                            | Mandatory | Description                     |
| ------------------| --------------------------------| ---- | ------------- |
| url               | string                          | Yes   | URL to be preloaded.|
| additionalHeaders | Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)> | No   | Additional HTTP headers of the URL.<br>Default value: **[]**.|
| prefetchOptions | [PrefetchOptions](./arkts-apis-webview-PrefetchOptions.md) | No   | Options for customizing the prefetch behavior.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
            let options = new webview.PrefetchOptions();
            options.ignoreCacheControlNoStore = true;
            options.minTimeBetweenPrefetchesMs = 100;
            this.controller.prefetchPage('https://www.example.com', [{ headerKey: "headerKey", headerValue: "headerValue" }], options);
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

## prefetchPage<sup>10+</sup>

prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void

Prefetches resources in the background for a page that is likely to be accessed in the near future, without executing the page JavaScript code or presenting the page. This can significantly reduce the load time for the prefetched page.

> **NOTE**
>
> - The downloaded page resources are cached for about 5 minutes. After this period, the **Web** component automatically releases the resources.
>
> - **prefetchPage** can also prefetch 302 redirect pages.
>
> - When a page is loaded after **prefetchPage** is executed, the prefetched resources are directly loaded from the cache.
>
> - If multiple URLs are specified for **prefetchPage**, only the first URL takes effect.
>
> - **prefetchPage** cannot be executed twice within 500 ms.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type                            | Mandatory | Description                     |
| ------------------| --------------------------------| ---- | ------------- |
| url               | string                          | Yes   | URL to be preloaded.|
| additionalHeaders | Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)> | No   | Additional HTTP headers of the URL.<br>Default value: **[]**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.                                                 |

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

## prefetchResource<sup>12+</sup>

static prefetchResource(request: RequestInfo, additionalHeaders?: Array\<WebHeader>, cacheKey?: string, cacheValidTime?: number): void

Prefetches resource requests based on specified request information and additional HTTP request headers, saves the requests to the memory cache, and specifies the cache key and validity period to accelerate loading. Currently, only POST requests whose Content-Type is application/x-www-form-urlencoded are supported. A maximum of six POST requests can be pre-obtained. To prefetch the seventh post request, call [clearPrefetchedResource](#clearprefetchedresource12) to clear the cache of unnecessary post requests. Otherwise, the cache of the earliest prefetched POST request will be automatically cleared. To use the prefetched resource cache, you need to add the key value **ArkWebPostCacheKey** to the header of the POST request. The content of the key value is the cacheKey of the corresponding cache.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type                            |  Mandatory | Description                                                             |
| ------------------| ------------------------------- | ---- | ------------------------------------------------------------------ |
| request           | [RequestInfo](./arkts-apis-webview-i.md#requestinfo12)   | Yes  | Information about the prefetched request.                                                     |
| additionalHeaders | Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)> | No  | Additional HTTP request header of the prefetched request.                                            |
| cacheKey          | string                          | No  | Key used to query the cache of prefetched resources. The value can contain only letters and digits. If this parameter is not passed or is left empty, **url** is used by default.|
| cacheValidTime    | number                          | No  | Validity period for caching prefetched resources.<br>Value range: (0, 2147483647]<br>Default value: **300s**<br>Unit: second.        |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed. |
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.                                                 |

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
      {
        url: "https://www.example1.com/post?e=f&g=h",
        method: "POST",
        formData: "a=x&b=y",
      },
      [{
        headerKey: "c",
        headerValue: "z",
      },],
      "KeyX", 500);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

## clearPrefetchedResource<sup>12+</sup>

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
      Web({ src: "https://www.example.com/", controller: this.controller })
        .onAppear(() => {
          // Replace "https://www.example1.com/post?e=f&g=h" with the actual website address to visit. 
          webview.WebviewController.prefetchResource(
            {
              url: "https://www.example1.com/post?e=f&g=h",
              method: "POST",
              formData: "a=x&b=y",
            },
            [{
              headerKey: "c",
              headerValue: "z",
            },],
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

## prepareForPageLoad<sup>10+</sup>

static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void

Preconnects to a URL. This API can be called before the URL is loaded, to resolve the DNS and establish a socket connection, without obtaining the resources.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| url            | string  | Yes  | URL to be preconnected.|
| preconnectable | boolean | Yes  | Whether to perform preconnection, which involves DNS resolution and socket connection establishment. The value **true** means to perform pre-connection, and **false** means the opposite.|
| numSockets     | number  | Yes  | Number of sockets to be preconnected. The value must be greater than 0. A maximum of six socket connections are allowed.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.                                                 |
| 17100013 | The number of preconnect sockets is invalid.                                                 |

**Example**

```ts
// EntryAbility.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Replace 'https://www.example.com' with a real URL for the API to work.
    webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
    AppStorage.setOrCreate("abilityWant", want);
    console.info("EntryAbility onCreate done");
  }
}
```

## setCustomUserAgent<sup>10+</sup>

setCustomUserAgent(userAgent: string): void

Sets a custom user agent, which will overwrite the default user agent.

When **src** of the **Web** component is set to a URL, set **User-Agent** in **onControllerAttached**. For details, see the following example. Avoid setting the user agent in **onLoadIntercept**. Otherwise, the setting may fail occasionally.

When **src** of the **Web** component is set to an empty string, call **setCustomUserAgent** to set **User-Agent** and then use **loadUrl** to load a specific page.

For details about the default **User-Agent**, see [Developing User-Agent](../../web/web-default-userAgent.md).

> **NOTE**
>
>If a URL is set for the **Web** component **src** and **User-Agent** is not set in the **onControllerAttached** callback, calling **setCustomUserAgent** may cause mismatches between the loaded page and the intended user agent.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | Yes  | Information about the custom user agent. It is recommended that you obtain the current default user agent through [getUserAgent](#getuseragent) and then customize the obtained user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
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
  @State customUserAgent: string = ' DemoApp';

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
      .onControllerAttached(() => {
        console.info("onControllerAttached");
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

## setDownloadDelegate<sup>11+</sup>

setDownloadDelegate(delegate: WebDownloadDelegate): void

Sets a **WebDownloadDelegate** object to receive downloads and download progress triggered from a page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](./arkts-apis-webview-WebDownloadDelegate.md)  | Yes  | Delegate used to receive the download progress.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## startDownload<sup>11+</sup>

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048. |

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

## getCustomUserAgent<sup>10+</sup>

getCustomUserAgent(): string

Obtains a custom user agent.

For details about the default **User-Agent**, see [Developing User-Agent](../../web/web-default-userAgent.md).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Information about the custom user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("userAgent: " + this.userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setAppCustomUserAgent<sup>20+</sup>

static setAppCustomUserAgent(userAgent: string): void

Sets the application-level custom user agent, which will overwrite the system user agent and take effect for all **Web** components in the application.

If you need to set the application-level custom user agent, you are advised to call the **setAppCustomUserAgent** method to set the user agent before creating the **Web** component, and then create the **Web** component with the specified src or load the page using [loadUrl](#loadurl).

For details about the default User-Agent definition, application scenarios, and API priorities, see [Developing User-Agent](../../web/web-default-userAgent.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description|
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | Yes  | Information about the custom user agent. It is recommended that you obtain the current default user agent through [getDefaultUserAgent](#getdefaultuseragent14) and then customize the obtained user agent.|

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
      webview.WebviewController.initializeWebEngine();
      let defaultUserAgent = webview.WebviewController.getDefaultUserAgent();
      let appUA = defaultUserAgent + " appUA";
      webview.WebviewController.setAppCustomUserAgent(appUA);
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

## setUserAgentForHosts<sup>20+</sup>

static setUserAgentForHosts(userAgent: string, hosts: Array\<string>): void

Sets a custom user agent for a specific website, which overwrites the system user agent and takes effect for all **Web** components in the application.

To set a custom user agent for a specific website, you are advised to call the **setUserAgentForHosts** method to set **User-Agent** before creating a **Web** component, and then create a **Web** component with a specified src or use [loadUrl](#loadurl) to load a specific page.

For details about the default User-Agent definition, application scenarios, and API priorities, see [Developing User-Agent](../../web/web-default-userAgent.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description|
| ---------------| ------- | ---- | ------------- |
| userAgent      | string  | Yes  | Information about the custom user agent. It is recommended that you obtain the current default user agent through [getDefaultUserAgent](#getdefaultuseragent14) and then customize the obtained user agent.|
| hosts      | Array\<string>  | Yes  | List of domain names related to the custom user agent. Only the latest list is retained each time the API is called. The maximum number of entries is 20,000, and the excessive entries are automatically truncated.|

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

  aboutToAppear(): void {
    try {
      webview.WebviewController.initializeWebEngine();
      let defaultUserAgent = webview.WebviewController.getDefaultUserAgent();
      let appUA = defaultUserAgent + " appUA";
      webview.WebviewController.setUserAgentForHosts(
        appUA,
        [
          "www.example.com",
          "www.baidu.com"
        ]
      );
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

## setConnectionTimeout<sup>11+</sup>

static setConnectionTimeout(timeout: number): void

Sets the network connection timeout. You can use the **onErrorReceive** method in the **Web** component to obtain the timeout error code.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| timeout        | number  | Yes  | Timeout interval of the socket connection, in seconds. The value must be an integer greater than 0.|

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
            console.info("setConnectionTimeout: 5s");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onErrorReceive((event) => {
          if (event) {
            console.info('getErrorInfo:' + event.error.getErrorInfo());
            console.info('getErrorCode:' + event.error.getErrorCode());
          }
        })
    }
  }
}
```

## warmupServiceWorker<sup>12+</sup>

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
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.              |

**Example**

```ts
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("EntryAbility onCreate");
        webview.WebviewController.initializeWebEngine();
        webview.WebviewController.warmupServiceWorker("https://www.example.com");
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

## enableSafeBrowsing<sup>11+</sup>

enableSafeBrowsing(enable: boolean): void

Enables the safe browsing feature. This feature is forcibly enabled and cannot be disabled for identified untrusted websites.
By default, this feature does not take effect. OpenHarmony provides only the malicious website blocking web UI. The website risk detection and web UI display features are implemented by the vendor. You are advised to listen for [DidStartNavigation](https://gitcode.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidStartNavigation) and [DidRedirectNavigation](https://gitee.com/openharmony-tpc/chromium_src/blob/master/content/public/browser/web_contents_observer.h#:~:text=virtual%20void-,DidRedirectNavigation) in **WebContentsObserver** to detect risks.

> **NOTE**
> 
> This API does not take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable the safe browsing feature.<br>The value **true** means to enable the safe browsing feature, and **false** means the opposite.<br>Default value: **false**.|

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
            console.info("enableSafeBrowsing: true");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isSafeBrowsingEnabled<sup>11+</sup>

isSafeBrowsingEnabled(): boolean

Checks whether the safe browsing feature is enabled for this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether the safe browsing feature is enabled for this web page.<br>The value **true** indicates that the safe browsing feature is enabled, and **false** indicates the opposite.<br>Default value: **false**.|

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
          console.info("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## enableIntelligentTrackingPrevention<sup>12+</sup>

enableIntelligentTrackingPrevention(enable: boolean): void

Enables intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be used on phones, tablets, PCs, and 2-in-1 devices. Since API version 18, error code **801** is returned for other device types.

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable intelligent tracking prevention.<br>The value **true** means to enable intelligent tracking prevention, and **false** means the opposite.<br>Default value: **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

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
            console.info("enableIntelligentTrackingPrevention: true");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isIntelligentTrackingPreventionEnabled<sup>12+</sup>

isIntelligentTrackingPreventionEnabled(): boolean

Obtains whether intelligent tracking prevention is enabled on this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be used on phones, tablets, PCs, and 2-in-1 devices. Since API version 18, error code **801** is returned for other device types.

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether intelligent tracking prevention is enabled on this web page.<br>The value **true** indicates that intelligent tracking prevention is enabled, and **false** indicates the opposite.<br>Default value: **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
|  801 | Capability not supported. |

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
            console.info("result: " + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## addIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static addIntelligentTrackingPreventionBypassingList(hostList: Array\<string>): void

Adds a list of domain names that bypass intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be used on phones, tablets, PCs, and 2-in-1 devices. Since API version 18, error code **801** is returned for other device types.

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | Yes  | List of domain names that bypass intelligent tracking prevention.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801     | Capability not supported. |

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

## removeIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static removeIntelligentTrackingPreventionBypassingList(hostList: Array\<string>): void

Deletes the domain names from the list of domain names added through the **addIntelligentTrackingPreventionBypassingList** API.

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be used on phones, tablets, PCs, and 2-in-1 devices. Since API version 18, error code **801** is returned for other device types.

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| hostList    | Array\<string> | Yes  | List of domain names that bypass intelligent tracking prevention.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801     | Capability not supported. |

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

## clearIntelligentTrackingPreventionBypassingList<sup>12+</sup>

static clearIntelligentTrackingPreventionBypassingList(): void

Deletes all domain names from the list of domain names added through the **addIntelligentTrackingPreventionBypassingList** API.

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be used on phones, tablets, PCs, and 2-in-1 devices. Since API version 18, error code **801** is returned for other device types.

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                 |
| -------- | ------------------------ |
|  801     | Capability not supported. |

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

## getDefaultUserAgent<sup>14+</sup>

static getDefaultUserAgent(): string

Obtains the default user agent.

This API can be called only in the UI thread.

For details about the default **User-Agent**, see [Developing User-Agent](../../web/web-default-userAgent.md).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Default **User-Agent** string of ArkWeb.|

**Example**

```ts
// EntryAbility.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    let defaultUserAgent = webview.WebviewController.getDefaultUserAgent();
    console.info("defaultUserAgent: " + defaultUserAgent);
  }
}
```

## enableAdsBlock<sup>12+</sup>

enableAdsBlock(enable: boolean): void

Enables ad blocking.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  enable | boolean | Yes  | Whether to enable ad blocking.<br>The value **true** means to enable ad blocking, and **false** means the opposite.<br>Default value: **false**.|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |
|  801 | Capability not supported. |

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
            console.info("enableAdsBlock: true")
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isAdsBlockEnabled<sup>12+</sup>

isAdsBlockEnabled() : boolean

Checks whether ad blocking is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | **true** is returned if ad blocking is enabled; otherwise, **false** is returned.<br>Default value: **false**.|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

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
            console.info("isAdsBlockEnabled:", isAdsBlockEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isAdsBlockEnabledForCurPage<sup>12+</sup>

isAdsBlockEnabledForCurPage() : boolean

Checks whether ad blocking is enabled on this web page.
After ads blocking is enabled for the **Web** component, this feature is enabled for all web pages by default. You can call [addAdsBlockDisallowedList](./arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12) to disable the feature for specific domains.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | **true** is returned if ad blocking is enabled; otherwise, **false** is returned.|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

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
            console.info("isAdsBlockEnabledForCurPage:", isAdsBlockEnabledForCurPage);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setRenderProcessMode<sup>12+</sup>

static setRenderProcessMode(mode: RenderProcessMode): void

Sets the ArkWeb render subprocess mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| mode        | [RenderProcessMode](./arkts-apis-webview-e.md#renderprocessmode12)| Yes  | Render subprocess mode.<br>You can call [getRenderProcessMode()](#getrenderprocessmode12) to view the ArkWeb rendering subprocess mode of the current device. The enumerated value **0** indicates the single render subprocess mode, and **1** indicates the multi-render subprocess mode.<br>By default, mobile phones use the single render subprocess mode, and tablets and PCs/2in1 devices use the multi-render subprocess mode.<br>If an invalid number other than the enumerated value of **RenderProcessMode** is passed, the multi-render subprocess mode is used by default.|

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
## getRenderProcessMode<sup>12+</sup>

static getRenderProcessMode(): RenderProcessMode

Obtains the ArkWeb render subprocess mode.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| [RenderProcessMode](./arkts-apis-webview-e.md#renderprocessmode12) | Render subprocess mode.<br>You can call **getRenderProcessMode()** to obtain the ArkWeb child render process mode of the current device. The enumerated value **0** indicates the single child render process mode, and **1** indicates the multi-child render process mode.<br>If the obtained value is not an enumerated value of **RenderProcessMode**, the multi-render subprocess mode is used by default.|


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
          console.info("getRenderProcessMode: " + mode);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## terminateRenderProcess<sup>12+</sup>

terminateRenderProcess(): boolean

Terminates this render process.

Calling this API will destroy the associated render process. If the render process has not been started or has been destroyed, there is no impact. In addition, destroying the render process affects all other instances associated with the render process.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| boolean | Whether the render process is terminated.<br>The value **true** indicates that the render process can be destroyed or has been destroyed, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
          console.info("terminateRenderProcess result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## postUrl<sup>11+</sup>

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.  |
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

## createWebPrintDocumentAdapter<sup>11+</sup>

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
| print.[PrintDocumentAdapter](../apis-basic-services-kit/js-apis-print.md#printdocumentadapter11) | **PrintDocumentAdapter** instance created.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                                   |
| -------- | -------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            print.print('example_jobid', webPrintDocadapter, null, this.getUIContext().getHostContext());
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## isIncognitoMode<sup>11+</sup>

isIncognitoMode(): boolean

Checks whether this Webview is in incognito mode.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| boolean              | Whether the Webview is in incognito mode.<br>The value **true** indicates that incognito mode is enabled for WebView, and **false** indicates the opposite.<br>Default value: **false**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                                   |
| -------- | -------------------------------------------------------------------------- |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info('isIncognitoMode' + result);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getSecurityLevel<sup>11+</sup>

getSecurityLevel(): SecurityLevel

Obtains the security level of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| [SecurityLevel](./arkts-apis-webview-e.md#securitylevel11) | Security level of the web page. The value can be **NONE**, **SECURE**, **WARNING**, or **DANGEROUS**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## setScrollable<sup>12+</sup>

setScrollable(enable: boolean, type?: ScrollType): void

Sets whether this web page is scrollable.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| enable     | boolean   | Yes  | Whether this web page is scrollable.<br>The value **true** indicates that this web page is scrollable, and **false** indicates the opposite.<br>Default value: **true**.|
| type       | [ScrollType](./arkts-apis-webview-e.md#scrolltype12) |  No| Scrolling type supported by the web page. The default value is supported.<br> - If the value of **enable** is set to **false**, the specified **ScrollType** is disabled. If **ScrollType** is set to the default value, all scrolling types are disabled.<br> - If the value of **enable** is set to **true**, all scrolling types are enabled regardless of the value of **ScrollType**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## getScrollable<sup>12+</sup>

getScrollable(): boolean

Obtains whether this web page is scrollable.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description          |
| ------ | -------------- |
| boolean | Whether this web page is scrollable.<br>The value **true** indicates that this web page is scrollable, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("scrollEnabled: " + scrollEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setPrintBackground<sup>12+</sup>

setPrintBackground(enable: boolean): void

Sets whether to print the web page background.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| enable | boolean | Yes  | Whether to print the web page background.<br>The value **true** means to print the web page background, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## getPrintBackground<sup>12+</sup>

getPrintBackground(): boolean

Obtains whether the web page background is printed.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| boolean              | Whether the web page background is printed.<br>The value **true** indicates that the web page background is printed, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
            console.info("getPrintBackground: " + enable);
          } catch (error) {
            console.error(`ErrorCode:${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>

getLastJavascriptProxyCallingFrameUrl(): string

Obtains the URL of the last frame from which the JavaScript proxy object was called. You can inject a JavaScript object into the window object using APIs like [registerJavaScriptProxy](#registerjavascriptproxy) or [javaScriptProxy](./arkts-basic-components-web-attributes.md#javascriptproxy). This API can be used to obtain the URL of the frame of the object that is injected last time.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | URL of the last frame from which the JavaScript proxy object was called.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
    console.info('Web Component str' + testStr + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testStr;
  }

  toString(): void {
    console.info('Web Component toString ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
  }

  testNumber(testNum: number): number {
    console.info('Web Component number' + testNum + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testNum;
  }

  testBool(testBol: boolean): boolean {
    console.info('Web Component boolean' + testBol + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return testBol;
  }
}

class WebObj {
  mycontroller: webview.WebviewController;

  constructor(controller: webview.WebviewController) {
    this.mycontroller = controller;
  }

  webTest(): string {
    console.info('Web test ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
    return "Web test";
  }

  webString(): void {
    console.info('Web test toString ' + " url " + this.mycontroller.getLastJavascriptProxyCallingFrameUrl());
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
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister("objName");
            this.controller.deleteJavaScriptRegister("objTestName");
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
    <head>
      <meta charset="utf-8">
    </head>
    <body>
      <button type="button" onclick="htmlTest()">Click Me!</button>
      <p id="demo"></p>
      <p id="webDemo"></p>
      <script type="text/javascript">
        function htmlTest() {
          // This function call expects to return "ArkUI Web Component"
          let str=objName.test("webtest data");
          objName.testNumber(1);
          objName.testBool(true);
          document.getElementById("demo").innerHTML=str;
          console.info('objName.test result:'+ str)

          // This function call expects to return "Web test"
          let webStr = objTestName.webTest();
          document.getElementById("webDemo").innerHTML=webStr;
          console.info('objTestName.webTest result:'+ webStr)
        }
      </script>
    </body>
</html>
```

## pauseAllTimers<sup>12+</sup>

static pauseAllTimers(): void

Pauses all WebView timers.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button('PauseAllTimers')
          .onClick(() => {
            webview.WebviewController.pauseAllTimers();
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

## resumeAllTimers<sup>12+</sup>

static resumeAllTimers(): void

Resumes all timers that are paused from the **pauseAllTimers()** API.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button('ResumeAllTimers')
          .onClick(() => {
            webview.WebviewController.resumeAllTimers();
          })
        Button('PauseAllTimers')
          .onClick(() => {
            webview.WebviewController.pauseAllTimers();
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

## stopAllMedia<sup>12+</sup>

stopAllMedia(): void

Stops all audio and video on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## pauseAllMedia<sup>12+</sup>

pauseAllMedia(): void

Pauses all audio and video on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## resumeAllMedia<sup>12+</sup>

resumeAllMedia(): void

Resumes the playback of the audio and video that are paused by the pauseAllMedia interface.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## closeAllMediaPresentations<sup>12+</sup>

closeAllMediaPresentations(): void

Closes all full-screen videos on a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## getMediaPlaybackState<sup>12+</sup>

getMediaPlaybackState(): MediaPlaybackState

Queries the audio and video playback status of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                       | Description                                                     |
| ------------------------------------------- | --------------------------------------------------------- |
| [MediaPlaybackState](./arkts-apis-webview-e.md#mediaplaybackstate12) | Playback control status of the current web page. The options are **NONE**, **PLAYING**, **PAUSED**, and **STOPPED**.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## setWebSchemeHandler<sup>12+</sup>

setWebSchemeHandler(scheme: string, handler: WebSchemeHandler): void

Sets the [WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md) class for the current Web component to intercept requests of the specified scheme.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | Yes  | Protocol to be intercepted.|
| handler    | [WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md) | Yes  | Interceptor that intercepts this protocol.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types.                                    |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## clearWebSchemeHandler<sup>12+</sup>

clearWebSchemeHandler(): void

Clears all WebSchemeHandlers set for the current Web component.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## setServiceWorkerWebSchemeHandler<sup>12+</sup>

setServiceWorkerWebSchemeHandler(scheme: string, handler: WebSchemeHandler): void

Sets the WebSchemeHandler used to intercept ServiceWorker for all Web components of the current application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | :------------------------ |
| scheme    | string | Yes  | Protocol to be intercepted.|
| handler    | [WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md) | Yes  | Interceptor that intercepts this protocol.|

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

## clearServiceWorkerWebSchemeHandler<sup>12+</sup>

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

## startCamera<sup>12+</sup>

startCamera(): void

Enables the camera capture of the current web page. Before using the camera, add the **ohos.permission.CAMERA** permission to **module.json5**. For details about how to add the permission, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md).

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, PermissionRequestResult, common } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  uiContext: UIContext = this.getUIContext();

  aboutToAppear(): void {
    let context: Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
    atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA'], (err: BusinessError, data: PermissionRequestResult) => {
      console.info('data:' + JSON.stringify(data));
      console.info('data permissions:' + data.permissions);
      console.info('data authResults:' + data.authResults);
    })
  }

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
            this.uiContext.showAlertDialog({
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
    <video id="video" width="400px" height="400px" autoplay>
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
        promise.then(function(mediaStream) {
          video.srcObject = mediaStream;
          video.play();
        })
      }
    </script>
  </body>
</html>
 ```

## stopCamera<sup>12+</sup>

stopCamera(): void

Stops the camera capture of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

For the complete sample code, see [startCamera](#startcamera12).

## closeCamera<sup>12+</sup>

closeCamera(): void

Disables the camera capture of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

For the complete sample code, see [startCamera](#startcamera12).

## precompileJavaScript<sup>12+</sup>

precompileJavaScript(url: string, script: string | Uint8Array, cacheOptions: CacheOptions): Promise\<number\>

Precompiles JavaScript to generate the bytecode cache or update the existing bytecode cache based on the provided parameters.
The API determines whether to update the existing bytecode cache based on the provided file information, E-Tag response header, and Last-Modified response header.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| url | string | Yes  | Network address corresponding to the local JavaScript file, that is, the network address used when the service web page requests the server version of the file. The network address supports only the HTTP and HTTPS protocols and contains a maximum of 2048 characters. If the cache corresponding to the network address is invalid, the service web page requests the corresponding resource through the network.     |
| script | string \| Uint8Array | Yes  | Text content of the local JavaScript. The content cannot be empty.     |
| cacheOptions | [CacheOptions](./arkts-apis-webview-i.md#cacheoptions12) | Yes  | Whether to update the bytecode cache.     |

**Return value**

| Type                               | Description                       |
| ----------------------------------- | --------------------------- |
| Promise\<number\> | Promise used to return the error code for generating the bytecode cache. The value **0** indicates no error, and the value **-1** indicates an internal error.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
     context: UIContext;
   }

   let storage : LocalStorage | undefined = undefined;

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>, context: UIContext) {
       storage = context.getSharedLocalStorage();
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

       const uiContext: UIContext = storage!.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder, data.context);
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
         precompile(data.controller, configs, data.context);
       })
       .fileAccess(true)
   }

   export const precompileWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export const precompile = async (controller: WebviewController, configs: Array<Config>, context: UIContext) => {
     for (const config of configs) {
       let content = await readRawFile(config.localPath, context);

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

   async function readRawFile(path: string, context: UIContext) {
     try {
       return await context.getHostContext()!.resourceManager.getRawFileContent(path);
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
         { url: "https://www.example.com/empty.html", controller: this.precompileController, context: this.getUIContext()});
     }

     build() {
       Column() {
         // Load the Web component used by the service at a proper time. In this example, the button is clicked.
         Button ("Load Page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url:  "https://www.example.com/business.html",
               controller: this.businessController,
               context: this.getUIContext()
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

To update the locally generated compiled bytecode, change the value of E-Tag or Last-Modified in responseHeaders of the cacheOptions parameter and call the API again.

## onCreateNativeMediaPlayer<sup>12+</sup>

onCreateNativeMediaPlayer(callback: CreateNativeMediaPlayerCallback): void

Called when the [application takes over media playback of the web page](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12) and a media file is played on the web page.
If the application does not take over media playback on the web page, this callback is not invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| callback | [CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) | Yes| Callback when the application takes over media playback on the web page.|

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
    // The ArkWeb kernel requires to adjust the volume of the local player.
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

## enableWholeWebPageDrawing<sup>12+</sup>

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

## webPageSnapshot<sup>12+</sup>

webPageSnapshot(info: SnapshotInfo, callback: AsyncCallback\<SnapshotResult>): void

Obtains the full drawing result of the web page.

> **NOTE**
>
> Only static images and texts in the rendering process can be captured.
> 
> If there is a video on the page, the placeholder image of the video is displayed when you take a snapshot. If there is no placeholder image, the page is blank.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type          | Mandatory | Description                     |
| ----------- | ------------- | ---- | ------------------------ |
| info        | [SnapshotInfo](./arkts-apis-webview-i.md#snapshotinfo12)| Yes  | Information for obtaining the full drawing result.|
| callback        | AsyncCallback\<[SnapshotResult](./arkts-apis-webview-i.md#snapshotresult12)>| Yes  | Callback used to return the result.|

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

## injectOfflineResources<sup>12+</sup>

injectOfflineResources(resourceMaps: Array\<[OfflineResourceMap](./arkts-apis-webview-i.md#offlineresourcemap12)\>): void

Injects local offline resources to the memory cache to improve the initial page startup speed.
Resources in the memory cache are automatically managed by the ArkWeb engine. When the injected resources are excessive and cause significant memory pressure, the engine will automatically release unused resources. It is advisable to avoid injecting a large number of resources into the memory cache.
Under normal circumstances, the validity period of the resources is controlled by the provided Cache-Control or Expires response header, with a default validity period of 86,400 seconds, which is one day.
The MIME type of the resources is configured through the provided Content-Type response header. The Content-Type must comply with standards; otherwise, the resources cannot be used correctly. For resources of type MODULE_JS, a valid MIME type must be provided. For other types, the MIME type is optional.
Resources injected in this mode can be loaded only through HTML tags. If a **script** tag on the web page uses the **crossorigin** attribute, the **Cross-Origin** response header must be set in the **responseHeaders** parameter of the API. The value for this header should be **anonymous** or **use-credentials**.
After **webview.WebviewController.SetRenderProcessMode(webview.RenderProcessMode.MULTIPLE)** is called, the application starts the multi-rendering process mode. This API does not take effect in this scenario.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| resourceMaps | Array\<[OfflineResourceMap](./arkts-apis-webview-i.md#offlineresourcemap12)\> | Yes  | Configuration object for local offline resources. A maximum of 30 resources can be injected in a single call, with a maximum size of 10 MB per individual resource.     |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types.3. Parameter verification failed.                                     |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 17100002 | URL error. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.  |

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
     context: UIContext;
   }

   let storage : LocalStorage | undefined = undefined;

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>, context: UIContext) {
       storage = context.getSharedLocalStorage();
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

       const uiContext: UIContext = storage!.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder, data.context);
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
           data.controller.injectOfflineResources(await getData (data.context));
         } catch (err) {
           console.error("error: " + err.code + " " + err.message);
         }
       })
       .fileAccess(true)
   }

   export const injectWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export async function getData(context: UIContext) {
     const resourceMapArr: Array<webview.OfflineResourceMap> = [];

     // Read the configuration and read the file content from the rawfile directory.
     for (let config of resourceConfigs) {
       let buf: Uint8Array = new Uint8Array(0);
       if (config.localPath) {
         buf = await readRawFile(config.localPath, context);
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

   export async function readRawFile(url: string, context: UIContext) {
     try {
       return await context.getHostContext()!.resourceManager.getRawFileContent(url);
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
         // Used in <script crossorigin="anonymous"/> mode to provide additional response headers.
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
           { url: "https://www.example.com/empty.html", controller: this.injectController, context: this.getUIContext()});
     }

     build() {
       Column() {
         // Load the Web component used by the service at a proper time. In this example, the button is clicked.
         Button ("Load Page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url: "https://www.example.com/business.html",
               controller: this.businessController,
               context: this.getUIContext()
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

## setHostIP<sup>12+</sup>

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

## clearHostIP<sup>12+</sup>

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

## getSurfaceId<sup>12+</sup>

getSurfaceId(): string

Obtains the ID of the surface corresponding to ArkWeb. The ID can be used to capture a screenshot of the web page.

> **NOTE**
>
> This API is valid only when the **Web** component rendering mode is **ASYNC_RENDER**. The value of **getSurfaceId** can be obtained only after the **Web** component is initialized.

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
            console.info("surfaceId: " + surfaceId);
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

## setUrlTrustList<sup>12+</sup>

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## setPathAllowingUniversalAccess<sup>12+</sup>

setPathAllowingUniversalAccess(pathList: Array\<string\>): void

Sets a path list. When a file protocol accesses resources in the path list, it can access the local files across domains. In addition, when a path list is set, the file protocol can access only the resources in the path list. The behavior of [fileAccess](./arkts-basic-components-web-attributes.md#fileaccess) will be overwritten by that of this API. The paths in the list must be any of the following:

1. The path of subdirectory of the application file directory. (The application file directory is obtained using [Context.filesDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in the Ability Kit.) For example:

* /data/storage/el2/base/files/example
* /data/storage/el2/base/haps/entry/files/example

2. The path of application resource directory or its subdirectory. (The application resource directory is obtained from [Context.resourceDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in the Ability Kit.) For example:

* /data/storage/el1/bundle/entry/resource/resfile
* /data/storage/el1/bundle/entry/resource/resfile/example

3. Since API version 21, the application cache directory and its subdirectories are also supported. (The application cache directory is obtained through [Context.cacheDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in Ability Kit). For example:

* /data/storage/el2/base/cache
* /data/storage/el2/base/haps/entry/cache/example
* The **cache/web** directory is not allowed. If it is included, an exception with the code **401** will be thrown. If the **cache** directory is set, **cache/web** cannot be accessed.

4. Since API version 21, the temporary application directory and its subdirectories are also supported. (The temporary application directory is obtained through [Context.tempDir](../apis-ability-kit/js-apis-inner-application-context.md#context) in Ability Kit). For example:

* /data/storage/el2/base/temp
* /data/storage/el2/base/haps/entry/temp/example

If a path in the list is not of the preceding paths, error code 401 is reported and the path list fails to be set. When the path list is set to empty, the accessible files for the file protocol are subject to the behavior of the [fileAccess](./arkts-basic-components-web-attributes.md#fileaccess).

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
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: WebviewController = new webview.WebviewController();
  uiContext: UIContext = this.getUIContext();

  build() {
    Row() {
      Web({ src: "", controller: this.controller })
        .onControllerAttached(() => {
          try {
            // Set the list of paths that can be accessed across domains.
            this.controller.setPathAllowingUniversalAccess([
              this.uiContext.getHostContext()!.resourceDir,
              this.uiContext.getHostContext()!.filesDir + "/example"
            ])
            this.controller.loadUrl("file://" + this.getUIContext().getHostContext()!.resourceDir + "/index.html")
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
                console.info("readyState:" + xmlHttpReq.readyState);
                console.info("status:" + xmlHttpReq.status);
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

In the HTML file, use the file protocol to access the local JS file through **XMLHttpRequest**. The JS file is stored in **resource/resfile/js/script.js**.
<!--code_no_check-->
```javascript
const body = document.body;
const element = document.createElement('div');
element.textContent = 'success';
body.appendChild(element);
```

## enableBackForwardCache<sup>12+</sup>

static enableBackForwardCache(features: BackForwardCacheSupportedFeatures): void

Enables the back-forward cache of a **Web** component. You can specify whether to add a specific page to the back-forward cache.

This API must be called before [initializeWebEngine()](#initializewebengine) initializes the kernel.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| features     |  [BackForwardCacheSupportedFeatures](./arkts-apis-webview-BackForwardCacheSupportedFeatures.md) | Yes  | Features of the pages, which allow them to be added to the back-forward cache.|

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
        // If a page uses the same-layer rendering and takes over media playback at the same time,
        // you need to set the values of nativeEmbed and mediaTakeOver to true to add the page to the back-forward cache.
        webview.WebviewController.enableBackForwardCache(features);
        webview.WebviewController.initializeWebEngine();
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

## setBackForwardCacheOptions<sup>12+</sup>

setBackForwardCacheOptions(options: BackForwardCacheOptions): void

Sets the back-forward cache options of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| options     |  [BackForwardCacheOptions](./arkts-apis-webview-BackForwardCacheOptions.md) | Yes  | Options to control the back-forward cache of the **Web** component.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## trimMemoryByPressureLevel<sup>14+</sup>

trimMemoryByPressureLevel(level: PressureLevel): void

Clears the cache occupied by **Web** component based on the specified memory pressure level.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory| Description                 |
| ------- | ------ | ---- | :-------------------- |
| level | [PressureLevel](./arkts-apis-webview-e.md#pressurelevel14) | Yes| Pressure level of the memory to be cleared.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Parameter string is too long. 3.Parameter verification failed. |

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
    Column() {
      Row() {
        Button('trim_Memory')
          .onClick(() => {
            try {
              // Set the current memory pressure level to moderate and release a small amount of memory.
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

## createPdf<sup>14+</sup>

createPdf(configuration: PdfConfiguration, callback: AsyncCallback\<PdfData\>): void

Obtains the data stream of a specified web page using an asynchronous callback.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description                   |
| ------------- | --------------------------------------- | ---- | ----------------------- |
| configuration | [PdfConfiguration](./arkts-apis-webview-i.md#pdfconfiguration14) | Yes  | Parameters required for creating a PDF file.      |
| callback      | AsyncCallback<[PdfData](./arkts-apis-webview-PdfData.md)>    | Yes  | Callback used to return the data stream of an online PDF file.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter.  |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

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
                // Obtain the component context.
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                // Obtain the sandbox path and set the PDF file name.
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

## createPdf<sup>14+</sup>

createPdf(configuration: PdfConfiguration): Promise\<PdfData\>

Obtains the data stream of a specified web page using a promise.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description             |
| ------------- | --------------------------------------- | ---- | ----------------- |
| configuration | [PdfConfiguration](./arkts-apis-webview-i.md#pdfconfiguration14) | Yes  | Parameters required for creating a PDF file.|

**Return value**

| Type                          | Description                         |
| ------------------------------ | ----------------------------- |
| Promise<[PdfData](./arkts-apis-webview-PdfData.md)> | Promise used to return the data stream of a web page.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Invalid input parameter. |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

**Example**

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
                // Obtain the component context.
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                // Obtain the sandbox path and set the PDF file name.
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

## getScrollOffset<sup>13+</sup>

getScrollOffset(): ScrollOffset

Obtains the current scrolling offset (including the over-scrolling offset) of the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                           | Description                  |
| :------------------------------ | ---------------------- |
| [ScrollOffset](./arkts-apis-webview-i.md#scrolloffset13) | Current scrolling offset (including the over-scrolling offset) of the web page.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

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
        .onTouch(() => {
          this.controllerX = this.controller.getScrollOffset().x;
          this.controllerY = this.controller.getScrollOffset().y;
          let componentInfo = this.getUIContext().getComponentUtils().getRectangleById("web_01");
          let webHeight = this.getUIContext().px2vp(componentInfo.size.height);
          let pageHeight = this.controller.getPageHeight();
          if (this.controllerY < 0) {
            // Case 1: When a web page is scrolled down, use ScrollOffset.y directly.
            console.info(`get downwards overscroll offsetY = ${this.controllerY}`);
          } else if ((this.controllerY != 0) && (this.controllerY > (pageHeight - webHeight))) {
            // Case 2: When a web page is scrolled up, calculate the offset between the lower boundary of the web page and that of the Web component.
            console.info(`get upwards overscroll offsetY = ${this.controllerY - (pageHeight >= webHeight ? (pageHeight - webHeight) : 0)}`);
          } else {
            // Case 3: If the web page is not scrolled, use ScrollOffset.y directly.
            console.info(`get scroll offsetY = ${this.controllerY}`);
          }
        })
        .height(600)
    }
    .width('100%')
    .height('100%')
  }
}
```
  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" id="viewport" content="width=device-width,initial-scale=1.0">
      <title>Demo</title>
      <style>
          body {
            width:3000px;
            height:6000px;
            padding-right:170px;
            padding-left:170px;
            border:5px solid blueviolet;
          }
      </style>
  </head>
  <body>
  Scroll Test
  </body>
  </html>
  ```

## getPageOffset<sup>20+</sup>

getPageOffset(): ScrollOffset

Obtains the current scrolling offset of the web page (excluding the over-scrolling offset).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                           | Description                  |
| :------------------------------ | ---------------------- |
| [ScrollOffset](./arkts-apis-webview-i.md#scrolloffset13) | Current scrolling offset of the web page (excluding the over-scrolling offset).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  801     | Capability not supported. |

**Example**

```ts
// xxx.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onScroll((event) => {
          try {
            console.info("getPageOffset x:" + this.controller.getPageOffset().x + ",y:" +
            this.controller.getPageOffset().y);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
    }
  }
}
```
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" id="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        .blue {
          background-color: lightblue;
        }
        .green {
          background-color: lightgreen;
        }
        .blue, .green {
         font-size:16px;
         height:200px;
         text-align: center;       /* Horizontally centered */
         line-height: 200px;       /* Vertically centered (the height matches the container height) */
        }
    </style>
</head>
<body>
<div class="blue" >webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
<div class="green">webArea</div>
<div class="blue">webArea</div>
</body>
</html>
```

## getLastHitTest<sup>18+</sup>

getLastHitTest(): HitTestValue

Obtains the element information of the area being clicked last time.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type        | Description                |
| ------------ | -------------------- |
| [HitTestValue](./arkts-apis-webview-i.md#hittestvalue) | Element information of the area being clicked.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
      Button('getLastHitTest')
        .onClick(() => {
          try {
            let hitValue = this.controller.getLastHitTest();
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

## getAttachState<sup>20+</sup>

getAttachState(): ControllerAttachState

Checks whether the current **WebViewController** is bound to a **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type        | Description                |
| ------------ | -------------------- |
| [ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20) | Attach status of **WebViewController** and the **Web** component.|

**Example**
Click the button to obtain the attach status of the current **WebViewController** and output logs.

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
      Button('getAttachState')
        .onClick(() => {
          try {
            if (this.controller.getAttachState() == webview.ControllerAttachState.ATTACHED) {
              console.info('Controller is attached.');
            } else {
              console.info('Controller is unattached.');
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
## on('controllerAttachStateChange')<sup>20+</sup>

on(type: 'controllerAttachStateChange', callback: Callback&lt;ControllerAttachState&gt;): void

Registers the attach state event of **WebViewController**, which obtains the attach state change notification through a callback.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Attach state event of **WebViewController**, whose value is fixed to **controllerAttachStateChange**.|
| callback | Callback<[ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20)> | Yes| Callback triggered when the attach state of **WebViewController** changes.|

**Example**

For details, see [off](#offcontrollerattachstatechange20).

## off('controllerAttachStateChange')<sup>20+</sup>

off(type: 'controllerAttachStateChange', callback?: Callback&lt;ControllerAttachState&gt;): void

Deregisters the attach state event of **WebViewController**. After the deregistration, callback notifications will not be received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Attach state event of **WebViewController**, whose value is fixed to **controllerAttachStateChange**.|
| callback | Callback<[ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20)> | No| Callback triggered when the attach state of **WebViewController** changes. By default, this parameter is left blank. If **Callback** is specified, only the specified callback is deregistered. Otherwise, all callbacks will be deregistered.|

**Example**

Use **on** to register multiple callbacks, which are triggered when the attach state changes. Use **off** to deregister a callback or all callbacks.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  // Build a callback.
  handleControllerAttachStateChange = (state: webview.ControllerAttachState) => {
    if (state == webview.ControllerAttachState.UNATTACHED) {
      console.info('handleControllerAttachStateChange: Controller is unattached.');
    } else {
      console.info('handleControllerAttachStateChange: Controller is attached.');
    }
  };
  aboutToAppear() {
    try {
      this.controller.on('controllerAttachStateChange', this.handleControllerAttachStateChange);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
    try {
      // Register a callback to receive the notification of the controller attach state change.
      this.controller.on('controllerAttachStateChange', (state: webview.ControllerAttachState) => {
        if (state == webview.ControllerAttachState.UNATTACHED) {
          console.info('Controller is unattached.');
        } else {
          console.info('Controller is attached.');
        }
      })
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  }
  aboutToDisappear() {
    // Cancel the specified registered callback.
    // this.controller.off('controllerAttachStateChange', this.handleControllerAttachStateChange);
    // Cancel all registered callbacks.
    this.controller.off('controllerAttachStateChange');
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## waitForAttached<sup>20+</sup>

waitForAttached(timeout: number):Promise&lt;ControllerAttachState&gt;

Asynchronously waits for the **WebViewController** to be attached to the **Web** component. If the attachment is complete or times out, a callback is triggered to return the current [ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20) through a promise.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description             |
| ------------- | --------------------------------------- | ---- | ----------------- |
| timeout | number | Yes  | Asynchronous waiting duration.<br>Value range: [0, 65535]<br>Unit: ms.|

**Return value**

| Type                          | Description                         |
| ------------------------------ | ----------------------------- |
| Promise<[ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20)> | Promise used to return the current [ControllerAttachState](./arkts-apis-webview-i.md#controllerattachstate20).|


**Example**

In the initialization phase, set the **WebViewController** to wait for the attachment to complete. The timeout interval is 1000 ms. If the attachment is complete or times out, the callback is triggered.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  async aboutToAppear() {
    this.controller.waitForAttached(1000).then((state: webview.ControllerAttachState) => {
      if (state == webview.ControllerAttachState.ATTACHED) {
        // The callback is triggered when the attachment is complete or times out.
        console.info('Controller is attached.');
      }
    })
    try {
      const state = await this.controller.waitForAttached(1000);
      if (state == webview.ControllerAttachState.ATTACHED) {
        console.info('Controller is attached.');
      }
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

## setWebDebuggingAccess<sup>20+</sup>

static setWebDebuggingAccess(webDebuggingAccess: boolean, port: number): void

Sets whether to enable wireless web debugging. By default, wireless web debugging is disabled.

* If no port is specified, this API is equivalent to the [setWebDebuggingAccess](#setwebdebuggingaccess) API. In this case, ArkWeb starts a local domain socket listener.
* When a port is specified, ArkWeb starts a TCP socket listener. In this case, you can debug the web page wirelessly. For details, see [Wireless Debugging](../../web/web-debugging-with-devtools.md#wireless-debugging).

A port number smaller than 1024 is a well-known or system port and can be enabled only with privileges in the operating system. Therefore, the value of port must be greater than 1024. Otherwise, the API throws an exception.

NOTE: Enabling web debugging allows users to check and modify the internal status of the web page, which poses security risks. Therefore, you are advised not to enable this feature in the officially released version of the application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webDebuggingAccess | boolean | Yes  | Sets whether to enable web debugging.<br>The value **true** indicates that web page debugging is enabled, and **false** indicates the opposite.|
| port               | number  | Yes  | Specifies the TCP port number of the devtools service. If no port is specified, this API is equivalent to the [setWebDebuggingAccess] (#setwebdebuggingaccess) API.<br>Value range: (1024, 65535]<br>If the value of port is within the range of [0, 1024], the **BusinessError** exception is thrown. The error code is **17100023**.|


**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100023 | The port number is not within the allowed range. |

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
      webview.WebviewController.setWebDebuggingAccess(true, 8888);
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

## getProgress<sup>20+</sup>

getProgress(): number

Obtains the loading progress of the current web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                           | Description                  |
| :------------------------------ | ---------------------- |
| number | Loading progress of the current page. The value range is [0, 100].|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801 | Capability not supported. |

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
        .onPageBegin(() => {
          let curProgress = this.controller.getProgress();
          console.info("current page loading progress is :" + curProgress);
        })
    }
  }
}
```

## getHitTest<sup>(deprecated)</sup>

getHitTest(): WebHitTestType

Obtains the element type of the area being clicked.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 18. You are advised to use [getLastHitTest](#getlasthittest18) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [WebHitTestType](./arkts-apis-webview-e.md#webhittesttype)| Element type of the area being clicked.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## getHitTestValue<sup>(deprecated)</sup>

getHitTestValue(): HitTestValue

Obtains the element information of the area being clicked.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 18. You are advised to use [getLastHitTest](#getlasthittest18) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type        | Description                |
| ------------ | -------------------- |
| [HitTestValue](./arkts-apis-webview-i.md#hittestvalue) | Element information of the area being clicked.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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

## avoidVisibleViewportBottom<sup>20+</sup>

avoidVisibleViewportBottom(avoidHeight: number): void

Sets the bottom avoidance height of the visible viewport on the web page.

> **NOTE**
>
> - The valid value range of **avoidHeight** is [0, height of the **Web** component]. Values outside this range are adjusted to the nearest boundary.
> - When a non-zero value is specified for **avoidHeight**, the position and size of the **Web** component remain unchanged, but the visible viewport shift upwards by the specified height, lifting the web page content by the **avoidHeight**. This API is used to customize the avoidance area at the bottom of a web page. It is not recommended that this API be used when the editable area of the web page is tapped to pull up the keyboard. If this API is used in this scenario, the keyboard avoidance mode is set to **OVERLAYS_CONTENT**.
> - When the height of this API is set to **0**, the web page content can be restored, and the keyboard avoidance mode is specified by [keyboardAvoidMode()](./arkts-basic-components-web-attributes.md#keyboardavoidmode12).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ---------------------- |
| avoidHeight   | number   | Yes  | Bottom avoidance height of the visible viewport on the web page.<br>Default value: **0**.<br>Unit: vp.<br>Value range: [0, height of the **Web** component]<br>If the value is set to an invalid value, the boundary value is used.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|
| 801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  avoidHeight: number = 100;

  build() {
    Column() {
      Button('avoid')
        .onClick(() => {
          try {
            this.controller.avoidVisibleViewportBottom(this.avoidHeight);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('reset')
        .onClick(() => {
          try {
            this.controller.avoidVisibleViewportBottom(0);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setErrorPageEnabled<sup>20+</sup>

setErrorPageEnabled(enable: boolean): void

Sets whether to enable the default error page.

When this API is set to true, if an error occurs during page loading, the [onOverrideErrorPage](./arkts-basic-components-web-events.md#onoverrideerrorpage20) callback is triggered. You can customize the error display page in the callback.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| enable | boolean | Yes| Whether to enable the default error page. The value **true** means to enable the default error page, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
      Web({ src: 'www.example.com', controller: this.controller })
       .onControllerAttached(() => {
            this.controller.setErrorPageEnabled(true);
            if (!this.controller.getErrorPageEnabled()) {
                this.controller.setErrorPageEnabled(true);
            }
        })
    }
  }
}
```

## getErrorPageEnabled<sup>20+</sup>

getErrorPageEnabled(): boolean

Queries whether the default error page is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| boolean | Whether the default error page is enabled.<br>The value true indicates that the default error page is enabled, and false indicates the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component.|

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
      Web({ src: 'www.example.com', controller: this.controller })
       .onControllerAttached(() => {
            this.controller.setErrorPageEnabled(true);
            if (!this.controller.getErrorPageEnabled()) {
                this.controller.setErrorPageEnabled(true);
            }
        })
    }
  }
}
```

## enablePrivateNetworkAccess<sup>20+</sup>

static enablePrivateNetworkAccess(enable: boolean): void

Sets the private network access check feature.

After this feature is enabled, the **Web** component performs CORS preflight on private network requests (such as requests for accessing local servers or intranet resources). It sends an OPTIONS preflight request to obtain explicit authorization from the target server and then transmits the actual data. Disabling this feature will skip the security check.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| enable | boolean | Yes  | Whether to enable the private network access check feature. The value **true** means to enable the private network access check feature, and **false** means the opposite.|

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
        .onControllerAttached(() => {
          // If the value is set to false, ArkWeb does not check whether the private network request is valid.
          webview.WebviewController.enablePrivateNetworkAccess(false);
        })
    }
  }
}
```

## isPrivateNetworkAccessEnabled<sup>20+</sup>

static isPrivateNetworkAccessEnabled(): boolean

Obtains whether the private network access check feature is enabled for the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether the private network access check feature is enabled for the **Web** component. The value **true** indicates that the private network access check feature is enabled, and **false** indicates the opposite.|

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
      Button('isPrivateNetworkAccessEnabled')
        .onClick(() => {
          try {
            let isEnabled: boolean = webview.WebviewController.isPrivateNetworkAccessEnabled();
            console.log("isPrivateNetworkAccessEnabled:", isEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          // If the value is set to false, ArkWeb does not check whether the private network request is valid.
          webview.WebviewController.enablePrivateNetworkAccess(false);
        })
    }
  }
}
```

## getBlanklessInfoWithKey<sup>20+</sup>

getBlanklessInfoWithKey(key: string): BlanklessInfo

Obtains the prediction information about blankless loading (for details, see [BlanklessInfo](./arkts-apis-webview-i.md#blanklessinfo20)) and starts to generate the loading transition frame. The application determines whether to enable blankless loading based on the information. This API must be used together with the [setBlanklessLoadingWithKey](#setblanklessloadingwithkey20) API before the page loading API is triggered or in **onLoadIntercept**, and after the **WebViewController** is bound to the **Web** component.

> **NOTE**
>
> - The default size of the persistent cache capacity is 30 MB (about 30 pages). You can set the cache capacity by calling [setBlanklessLoadingCacheCapacity](#setblanklessloadingcachecapacity20). For details, see the description of this API. When the maximum capacity is exceeded, the cache is updated based on the Least Recently Used (LRU) mechanism. The persistent cache data that has been stored for more than seven days is automatically cleared. After the cache is cleared, the optimization effect appears when the page is loaded for the third time.
> - If the snapshot similarity (**similarity** in [BlanklessInfo](./arkts-apis-webview-i.md#blanklessinfo20)) is extremely low, check whether the **key** value is correct.
> - After this API is called, page loading snapshot detection and transition frame generation calculation are enabled, which generates certain resource overhead.
> - Blankless loading consumes certain resources, which depends on the resolution of the **Web** component. When the width and height of the resolution are respectively **w** and **h**, the peak memory usage increases by about **12×w×h** B in the page-opening phase. After the page is opened, the memory is reclaimed, which does not affect the stable memory usage. When the size of the solid-state application cache is increased, the increased cache of each page is about **w×h/10** B and the cache is located in the application cache.
> - Add the **ohos.permission.INTERNET** and **ohos.permission.GET_NETWORK_INFO** permissions to **module.json5**. For details, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

**System capability**: SystemCapability.Web.Webview.Core

**Device behavior differences**: This API can be called on phones. For other device types, error code **801** is returned.

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| key | string | Yes| Key value that uniquely identifies the page.<br>The value cannot be empty and can contain a maximum of 2048 characters.<br>Invalid values do not take effect.|

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| [BlanklessInfo](./arkts-apis-webview-i.md#blanklessinfo20) | Prediction information about blankless loading, including the first screen similarity and first screen loading duration. The application determines whether to enable blankless loading based on the prediction information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  801     | Capability not supported. |

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
      Web({ src: 'https://www.example.com', controller: this.controller })
       .javaScriptAccess(true)
       .onLoadIntercept((event) => {
            // Enable frame interpolation only when the similarity exceeds 50% and the loading duration is less than 1000 ms.
            try {
              let info = this.controller.getBlanklessInfoWithKey('https://www.example.com/page1');
              if (info.errCode == webview.WebBlanklessErrorCode.SUCCESS) {
                if (info.similarity >= 0.5 && info.loadingTime < 1000) {
                  this.controller.setBlanklessLoadingWithKey('http://www.example.com/page1', true);
                } else {
                  this.controller.setBlanklessLoadingWithKey('http://www.example.com/page1', false);
                }
              } else {
                console.log('getBlankless info err');
              }
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
            return false;
        })
    }
  }
}
```

## setBlanklessLoadingWithKey<sup>20+</sup>

setBlanklessLoadingWithKey(key: string, is_start: boolean): WebBlanklessErrorCode

Sets whether to enable blankless loading. This API must be used together with [getBlanklessInfoWithKey](#getblanklessinfowithkey20).

> **NOTE**
>
> - This API must be called after the page loading API is triggered. Other restrictions are the same as those of [getBlanklessInfoWithKey](#getblanklessinfowithkey20).
> - The page must be loaded in the component that calls this API.
> - When the similarity is low, the system will deem the scene change too abrupt and frame insertion will fail.
> - Add the **ohos.permission.INTERNET** and **ohos.permission.GET_NETWORK_INFO** permissions to **module.json5**. For details, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| key | string | Yes| Key value that uniquely identifies the page. This value must be the same as the **key** value of the **getBlanklessInfoWithKey** API.<br>The value cannot be empty and can contain a maximum of 2048 characters.<br>When an invalid value is set, the error code **WebBlanklessErrorCode** is returned, and the API does not take effect.|
| is_start | boolean | Yes| Whether to enable frame interpolation. The value **true** means to enable frame interpolation, and **false** means the opposite.<br>Default value: **false**.|

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| [WebBlanklessErrorCode](./arkts-apis-webview-e.md#webblanklesserrorcode20) | Whether the API is successfully called. For details, see [WebBlanklessErrorCode](./arkts-apis-webview-e.md#webblanklesserrorcode20).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  801     | Capability not supported. |

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
      Web({ src: 'https://www.example.com', controller: this.controller })
       .javaScriptAccess(true)
       .onLoadIntercept((event) => {
            // Enable frame interpolation only when the similarity exceeds 50% and the loading duration is less than 1000 ms.
            try {
              let info = this.controller.getBlanklessInfoWithKey('https://www.example.com/page1');
              if (info.errCode == webview.WebBlanklessErrorCode.SUCCESS) {
                if (info.similarity >= 0.5 && info.loadingTime < 1000) {
                  this.controller.setBlanklessLoadingWithKey('http://www.example.com/page1', true);
                } else {
                  this.controller.setBlanklessLoadingWithKey('http://www.example.com/page1', false);
                }
              } else {
                console.log('getBlankless info err');
              }
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
            return false;
        })
    }
  }
}
```

## clearBlanklessLoadingCache<sup>20+</sup>

static clearBlanklessLoadingCache(keys?: Array\<string\>): void

Clears the blankless loading cache of the page with a specified key value.

In an applet or web application, when the content changes significantly during page loading, an obvious scene change may occur. If you are concerned about this change, you can use this API to clear the page cache.

> **NOTE**
>
> - After the page is cleared, the optimization effect appears when the page is loaded for the third time.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| keys | Array\<string\> | No| Key value list on the pages using the blankless optimization solution. The **key** value has been specified in [getBlanklessInfoWithKey](#getblanklessinfowithkey20).<br>Default value: key list of all pages cached by the blankless optimization solution.<br>The key length cannot exceed 2048 characters, and the number of keys must be less than or equal to 100. The key value is the same as that input to the **Web** component during page loading.<br>If the key length exceeds 2048 characters, the key does not take effect. If the key length exceeds 100 characters, the first 100 characters are used. If the key length is NULL, the default value is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  801     | Capability not supported. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    // If the web page of the application will be greatly changed on May 6, 2022, for example, during product promotion activities, you are advised to clear the frame interpolation to optimize the cache.
    webview.WebviewController.initializeWebEngine();
    let pageUpdateTime: number = Date.UTC(2025, 5, 10, 0, 0, 0, 0);
    let pageUpdateTime1: number = Date.UTC(2025, 5, 11, 0, 0, 0, 0);
    let pageUpdateTimeNow: number = Date.now();
    if (pageUpdateTimeNow > pageUpdateTime && pageUpdateTime < pageUpdateTime1) {
      // Clear the cache of the frame interpolation on the specified page.
      try {
        webview.WebviewController.clearBlanklessLoadingCache(["https://www.example.com", "https://www.example1.com"]);
      } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
      }
    }
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

## setBlanklessLoadingCacheCapacity<sup>20+</sup>

static setBlanklessLoadingCacheCapacity(capacity: number): number

Sets the persistent cache capacity of the blankless loading solution and returns the value that takes effect. The default cache capacity is 30 MB, and the maximum cache capacity is 100 MB. When this limit is exceeded, transition frames that are not frequently used are eliminated.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| capacity | number | Yes| Persistent cache capacity, in MB. The maximum value is 100 MB.<br>The default value is 30 MB.<br>The value ranges from 0 to 100. If this parameter is set to **0**, no cache capacity is available and the functionality is disabled globally.<br>When a value less than 0 is set, the value **0** takes effect. When a value greater than 100 is set, the value **100** takes effect.|

**Return value**

| Type                | Description                     |
| -------------------- | ------------------------- |
| number | Effective value that ranges from 0 MB to 100 MB.<br>When a value less than 0 is set, the value **0** takes effect. When a value greater than 100 is set, the value **100** takes effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  801     | Capability not supported. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Set the cache capacity to 10 MB.
    try {
      webview.WebviewController.setBlanklessLoadingCacheCapacity(10);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

## setWebDestroyMode<sup>20+</sup>

setWebDestroyMode(mode: WebDestroyMode): void

Sets the destroy mode of the **Web** component. The destroy mode of the **Web** component affects the time when web kernel resources, such as the JavaScript running context and rendering context, are released. The default value is [WebDestroyMode.NORMAL_MODE](./arkts-apis-webview-e.md#webdestroymode20) (normal mode), indicating that the system determines the destroy time. You can set [WebDestroyMode.FAST_MODE](./arkts-apis-webview-e.md#webdestroymode20) (fast mode) to destroy resources immediately, improving performance in specific scenarios.

> **NOTE**
>
> [WebDestroyMode.FAST_MODE](./arkts-apis-webview-e.md#webdestroymode20) changes the time when the **Web** component is destroyed. When it is used, pay attention to the incorrect implementation that depends on the destroy time of the **Web** component. For example, when a **WebViewController** is called in fast mode rather than using [WebDestroyMode.NORMAL_MODE](./arkts-apis-webview-e.md#webdestroymode20), the unbinding exception is more likely to be triggered. In this case, the application needs to capture the exception, or use [getAttachState](#getattachstate20) to obtain the attach state to avoid stability problems.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| mode | [WebDestroyMode](./arkts-apis-webview-e.md#webdestroymode20) | Yes| Destroy mode of the **Web** component.<br>Default value: **WebDestroyMode.NORMAL_MODE**|

**Example**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Set the fast destroy mode.
    webview.WebviewController.setWebDestroyMode(webview.WebDestroyMode.FAST_MODE);
    AppStorage.setOrCreate("abilityWant", want);
    console.info("EntryAbility onCreate done");
  }
}
```

## setActiveWebEngineVersion<sup>20+</sup>

static setActiveWebEngineVersion(engineVersion: ArkWebEngineVersion): void

Sets the ArkWeb kernel version. If the system does not support the specified version, the setting is invalid. This API is a global static API and must be called before **initializeWebEngine** is called. If any **Web** component has been loaded, the setting of this API is invalid.

**Legacy kernel adaptation**

Since OpenHarmony 6.0, some ArkWeb APIs do not take effect when the legacy kernel is used. For details, see [Adaptation Guide for the M114 Kernel on OpenHarmony 6.0](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/CompatibleWithLegacyWebEngine.md).

> **NOTE**
>
> - **setActiveWebEngineVersion** cannot be called in an asynchronous thread.
> - **setActiveWebEngineVersion** takes effect globally and needs to be called only once in an application lifecycle.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| engineVersion         |   [ArkWebEngineVersion](./arkts-apis-webview-e.md#arkwebengineversion20)   | Yes  | ArkWeb kernel version.|

**Example**

This example shows how to set the ArkWeb kernel version in the EntryAbility creation phase.

```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate")
    webview.WebviewController.setActiveWebEngineVersion(webview.ArkWebEngineVersion.M114)
    if (webview.WebviewController.getActiveWebEngineVersion() == webview.ArkWebEngineVersion.M114) {
      console.log("Active Web Engine Version set to M114")
    }
    console.log("EntryAbility onCreate done")
  }
}
```

## getActiveWebEngineVersion<sup>20+</sup>

static getActiveWebEngineVersion(): ArkWebEngineVersion

Obtains the current ArkWeb kernel version.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [ArkWebEngineVersion](./arkts-apis-webview-e.md#arkwebengineversion20) | The ArkWeb kernel version defined by [ArkWebEngineVersion](./arkts-apis-webview-e.md#arkwebengineversion20).|

**Example**

For details, see [setActiveWebEngineVersion](#setactivewebengineversion20).

## setAutoPreconnect<sup>21+</sup>

static setAutoPreconnect(enabled: boolean): void

Sets the automatic preconnection status of the Web kernel. If this API is not set, automatic preconnection is enabled by default.

This API must be called before [initializeWebEngine()](#initializewebengine) is called to initialize the kernel or create a **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                    |
| -------- | ------- | ---- | -------------------------------------------------------- |
| enabled | boolean | Yes  | Whether to enable automatic preconnection of the Web kernel. The value **true** means to enable the private network access check feature, and **false** means the opposite.|

**Example**

```ts
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        webview.WebviewController.setAutoPreconnect(false);
        webview.WebviewController.initializeWebEngine();
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

## isAutoPreconnectEnabled<sup>21+</sup>

static isAutoPreconnectEnabled(): boolean

Queries the automatic preconnection status of the Web kernel.

If the automatic preconnection status of the Web kernel is not set by using [setAutoPreconnect](#setautopreconnect21), automatic preconnection is enabled by default, and **true** is returned.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| boolean | Whether auto preconnection is enabled for the Web kernel. The value **true** indicates that the private network access check feature is enabled, and **false** indicates the opposite.|

**Example**

```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  build() {
    Column() {
      Button('isAutoPreconnectEnabled')
        .onClick(() => {
          try {
            let isEnabled: boolean = webview.WebviewController.isAutoPreconnectEnabled();
            console.log("isAutoPreconnectEnabled:", isEnabled);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
    }
  }
}
```
## getSiteIsolationMode<sup>21+</sup>

static getSiteIsolationMode(): SiteIsolationMode

Queries the currently effective site isolation mode.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| [SiteIsolationMode](./arkts-apis-webview-e.md#siteisolationmode21) | Site isolation mode.<br>getSiteIsolationMode() queries the currently effective site isolation mode.


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
      Button('getSiteIsolationMode')
        .onClick(() => {
          let mode = webview.WebviewController.getSiteIsolationMode();
          console.info("getSiteIsolationMode: " + mode);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## setSiteIsolationMode<sup>21+</sup>

setSiteIsolationMode(mode: SiteIsolationMode): void

Sets the site isolation mode. Enumerates the site isolation modes. The site isolation mechanism isolates websites from different sources in different render processes to reduce the cross-domain attack surface. For example, on a PC, if site isolation is disabled, each tab page corresponds to a render process. After site isolation is enabled, iframes from different sources in a tab page can run in independent render processes.

For third-party applications that load only trusted web pages, you can disable this functionality to improve performance, reduce memory usage, and reduce interception of cross-domain access. The default value varies according to the device. [SiteIsolationMode.STRICT](./arkts-apis-webview-e.md#siteisolationmode21) is used for PCs and tablets, and [SiteIsolationMode.PARTIAL](./arkts-apis-webview-e.md#siteisolationmode21) is used for phones. In [Secure Shield mode](../..//web/web-secure-shield-mode.md), strict site isolation is used.

> **NOTE**
>
> Strict site isolation cannot be set in single-process mode.
>
> This API can be called only once during initialization. The site isolation mode cannot be repeatedly changed.


**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | -------------------------------------- |
| mode | [SiteIsolationMode](./arkts-apis-webview-e.md#siteisolationmode21) | Yes| Site isolation mode.<br>The default value depends on the device type and device mode. For PCs and tablets, strict site isolation is used by default. For phones, partial site isolation is used by default. In Secure Shield mode, strict site isolation is used by default.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17100001 |Init Error .  |

**Example**


```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear() {
    Column() {
      Button('setSiteIsolationMode')
        .onClick(() => {
          webview.WebviewController.setSiteIsolationMode(web_webview.SiteIsolationMode.PARTIAL);          
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
