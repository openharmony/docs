# Class (WebController, deprecated)

Implements a **WebController** to control the behavior of the **Web** component. A **WebController** can control only one **Web** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **Web** component.

This API is deprecated since API version 9. You are advised to use [WebviewController<sup>9+</sup>](./arkts-apis-webview-WebviewController.md) instead.

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Creating an Object

<!--deprecated_code_no_check-->
```ts
let webController: WebController = new WebController()
```

## constructor<sup>(deprecated)</sup>

constructor()

Constructs a **WebController** object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. No API is provided for substitute.

**System capability**: SystemCapability.Web.Webview.Core

## getCookieManager<sup>(deprecated)</sup>

getCookieManager(): WebCookie

Obtains the cookie management object of the **Web** component.

This API is deprecated since API version 9. You are advised to use [getCookie](./arkts-apis-webview-WebCookieManager.md#getcookiedeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type       | Description                                      |
| --------- | ---------------------------------------- |
| WebCookie | Cookie management object of the **Web** component. For details, see [WebCookie](./arkts-basic-components-web-WebCookie.md).|

**Example**

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

## requestFocus<sup>(deprecated)</sup>

requestFocus()

Requests focus for this web page.

This API is deprecated since API version 9. You are advised to use [requestFocus<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#requestfocus) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessBackward<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#accessbackward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | **true** is returned if going to the previous page can be performed on the current page; otherwise, **false** is returned.|

**Example**

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

## accessForward<sup>(deprecated)</sup>

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessForward<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#accessforward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | If going to the next page can be performed on the current page, **true** is returned; otherwise, **false** is returned.|

**Example**

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

## accessStep<sup>(deprecated)</sup>

accessStep(step: number): boolean

Performs a specific number of steps forward or backward from the current page.

This API is deprecated since API version 9. You are advised to use [accessStep<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#accessstep) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory | Description                 |
| ---- | ------ | ---- | --------------------- |
| step | number | Yes  | Number of the steps to take. A positive number means to go forward, and a negative number means to go backward.|

**Return value**

| Type     | Description       |
| ------- | --------- |
| boolean | Whether going forward or backward from the current page is successful.|

**Example**

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

## backward<sup>(deprecated)</sup>

backward()

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

This API is deprecated since API version 9. You are advised to use [backward<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#backward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## forward<sup>(deprecated)</sup>

forward()

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

This API is deprecated since API version 9. You are advised to use [forward<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#forward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately, with no need for invoking the [refresh](#refreshdeprecated) API.

This API is deprecated since API version 9. You are advised to use [deleteJavaScriptRegister<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#deletejavascriptregister) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | Yes  | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side.|

**Example**

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

## getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

Obtains the element type of the area being clicked.

This API is deprecated since API version 9. You are advised to use [getHitTest<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#gethittestdeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                             | Description         |
| ------------------------------- | ----------- |
| [HitTestType](./arkts-basic-components-web-e.md#hittesttype) | Element type of the area being clicked.|

**Example**

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

## loadData<sup>(deprecated)</sup>

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

Loads data. If **baseUrl** is empty, the specified character string will be loaded using the data protocol.

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **Web** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **Web** component as a non-encoded string in a manner similar to **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadData<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#loaddata) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type  | Mandatory  | Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| data       | string | Yes  | Character string obtained after being Base64 or URL encoded.             |
| mimeType   | string | Yes  | Media type (MIME).                             |
| encoding   | string | Yes  | Encoding type, which can be Base64 or URL.               |
| baseUrl    | string | No  | URL (HTTP/HTTPS/data compliant), which is assigned by the **Web** component to **window.origin**.|
| historyUrl | string | No  | Historical record URL. If this parameter is not empty, it can be managed in historical records to implement page going backward and forward. This parameter is invalid when **baseUrl** is left empty.|

**Example**

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

## loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

The object injected through **registerJavaScriptProxy** is still valid on a new page redirected through **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadUrl<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#loadurl) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                      | Mandatory | Description          |
| -------- | -------------------------- | ---- | -------------- |
| url      | string \| Resource                     | Yes | URL to load.    |
| headers  | Array\<[Header](./arkts-basic-components-web-i.md#header)\> | No   | Additional HTTP request header of the URL.<br>The default value is **[]**.|

**Example**

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

## onActive<sup>(deprecated)</sup>

onActive(): void

Called when the **Web** component enters the active state.

This API is deprecated since API version 9. You are advised to use [onActive<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#onactive) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## onInactive<sup>(deprecated)</sup>

onInactive(): void

Called when the **Web** component enters the inactive state.

This API is deprecated since API version 9. You are advised to use [onInactive<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#oninactive) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## zoom<sup>(deprecated)</sup>

zoom(factor: number): void

Sets a zoom factor for the current web page.

This API is deprecated since API version 9. You are advised to use [zoom<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#zoom) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                          |
| ------ | ------ | ---- | ------------------------------ |
| factor | number | Yes   | Zoom factor to set. A positive value indicates zoom-in, and a negative value indicates zoom-out.|

**Example**

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

## refresh<sup>(deprecated)</sup>

refresh()

Called when the **Web** component refreshes the web page.

This API is deprecated since API version 9. You are advised to use [refresh<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#refresh) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. You must invoke the [refresh](#refreshdeprecated) API for the registration to take effect.

This API is deprecated since API version 9. You are advised to use [registerJavaScriptProxy<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#registerjavascriptproxy) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type           | Mandatory | Description                                    |
| ---------- | --------------- | ---- | ---------------------------------------- |
| object     | object          | Yes   | Application-side JavaScript object to be registered. Methods and attributes can be declared, but cannot be directly called on HTML5. The parameters and return value can only be of the string, number, or Boolean type.|
| name       | string          | Yes   | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string\> | Yes   | Methods of the JavaScript object to be registered at the application side.                |

**Example**

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
              function htmlTest() {
                  str = objName.test("test function")
                  console.log('objName.test result:'+ str)
              }
          </script>
      </body>
  </html>

  ```

## runJavaScript<sup>(deprecated)</sup>

runJavaScript(options: { script: string, callback?: (result: string) => void })

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

This API is deprecated since API version 9. You are advised to use [runJavaScript<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#runjavascript) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                                    |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| script   | string                   | Yes  | JavaScript script.                           |
| callback | (result: string) => void | No  | Callback used to return the result. Returns **null** if the JavaScript script fails to be executed or no value is returned.|

**Example**

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
                console.log('Ark WebComponent')
                return "This value is from index.html"
            }
        </script>
    </body>
  </html>
  ```

## stop<sup>(deprecated)</sup>

stop()

Stops page loading.

This API is deprecated since API version 9. You are advised to use [stop<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#stop) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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

## clearHistory<sup>(deprecated)</sup>

clearHistory(): void

Clears the browsing history.

This API is deprecated since API version 9. You are advised to use [clearHistory<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#clearhistory) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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
