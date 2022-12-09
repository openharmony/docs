# Web

The **<Web\>** component can be used to display web pages.

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

## Required Permissions
To use online resources, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).

## Child Components

Not supported

## APIs

Web(options: { src: ResourceStr, controller: WebController | WebviewController})

> **NOTE**
>
> Transition animation is not supported.

**Parameters**

| Name       | Type                                    | Mandatory  | Description   |
| ---------- | ---------------------------------------- | ---- | ------- |
| src        | [ResourceStr](ts-types.md)               | Yes   | Address of a web page resource.|
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) | Yes   | Controller.   |

**Example**

  Example of loading online web pages:
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
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
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

  Example of loading local web pages:
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <body>
          <p>Hello World</p>
      </body>
  </html>
  ```

## Attributes

Only the following universal attributes are supported: [width](ts-universal-attributes-size.md#Attributes), [height](ts-universal-attributes-size.md#attributes), [padding](ts-universal-attributes-size.md#Attributes), [margin](ts-universal-attributes-size.md#attributes), and [border](ts-universal-attributes-border.md#attributes).

### domStorageAccess

domStorageAccess(domStorageAccess: boolean)

Sets whether to enable the DOM Storage API. By default, this feature is disabled.

**Parameters**

| Name             | Type   | Mandatory  | Default Value  | Description                                |
| ---------------- | ------- | ---- | ----- | ------------------------------------ |
| domStorageAccess | boolean | Yes   | false | Whether to enable the DOM Storage API.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .domStorageAccess(true)
      }
    }
  }
  ```

### fileAccess

fileAccess(fileAccess: boolean)

Sets whether to enable access to the file system in the application. This setting does not affect the access to the files specified through [$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md).

**Parameters**

| Name       | Type   | Mandatory  | Default Value | Description                  |
| ---------- | ------- | ---- | ---- | ---------------------- |
| fileAccess | boolean | Yes   | true | Whether to enable access to the file system in the application. By default, this feature is enabled.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .fileAccess(true)
      }
    }
  }
  ```

### imageAccess

imageAccess(imageAccess: boolean)

Sets whether to enable automatic image loading. By default, this feature is enabled.

**Parameters**

| Name        | Type   | Mandatory  | Default Value | Description           |
| ----------- | ------- | ---- | ---- | --------------- |
| imageAccess | boolean | Yes   | true | Whether to enable automatic image loading.|

**Example**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .imageAccess(true)
      }
    }
  }
  ```

### javaScriptProxy

javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string\>,
    controller: WebController | WebviewController})

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. The parameters cannot be updated.

**Parameters**

| Name       | Type                                    | Mandatory  | Default Value | Description                     |
| ---------- | ---------------------------------------- | ---- | ---- | ------------------------- |
| object     | object                                   | Yes   | -    | Object to be registered. Methods can be declared, but attributes cannot.   |
| name       | string                                   | Yes   | -    | Name of the object to be registered, which is the same as that invoked in the window.|
| methodList | Array\<string\>                          | Yes   | -    | Methods of the JavaScript object to be registered at the application side. |
| controller | [WebController](#webcontroller) or [WebviewController](../apis/js-apis-webview.md#webviewcontroller) | Yes   | -    | Controller.                     |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    testObj = {
      test: (data1, data2, data3) => {
        console.log("data1:" + data1)
        console.log("data2:" + data2)
        console.log("data3:" + data3)
        return "AceString"
      },
      toString: () => {
        console.log('toString' + "interface instead.")
      }
    }
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          .javaScriptProxy({
            object: this.testObj,
            name: "objName",
            methodList: ["test", "toString"],
            controller: this.controller,
        })
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
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    testObj = {
      test: (data1, data2, data3) => {
        console.log("data1:" + data1)
        console.log("data2:" + data2)
        console.log("data3:" + data3)
        return "AceString"
      },
      toString: () => {
        console.log('toString' + "interface instead.")
      }
    }
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          .javaScriptProxy({
            object: this.testObj,
            name: "objName",
            methodList: ["test", "toString"],
            controller: this.controller,
        })
      }
    }
  }
  ```

### javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

Sets whether JavaScript scripts can be executed. By default, JavaScript scripts can be executed.

**Parameters**

| Name             | Type   | Mandatory  | Default Value | Description               |
| ---------------- | ------- | ---- | ---- | ------------------- |
| javaScriptAccess | boolean | Yes   | true | Whether JavaScript scripts can be executed.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

### mixedMode

mixedMode(mixedMode: MixedMode)

Sets whether to enable loading of HTTP and HTTPS hybrid content can be loaded. By default, this feature is disabled.

**Parameters**

| Name      | Type                       | Mandatory  | Default Value           | Description     |
| --------- | --------------------------- | ---- | -------------- | --------- |
| mixedMode | [MixedMode](#mixedmode)| Yes   | MixedMode.None | Mixed content to load.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State mode: MixedMode = MixedMode.All
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mixedMode(this.mode)
      }
    }
  }
  ```

### onlineImageAccess

onlineImageAccess(onlineImageAccess: boolean)

Sets whether to enable access to online images through HTTP and HTTPS. By default, this feature is enabled.

**Parameters**

| Name              | Type   | Mandatory  | Default Value | Description            |
| ----------------- | ------- | ---- | ---- | ---------------- |
| onlineImageAccess | boolean | Yes   | true | Whether to enable access to online images through HTTP and HTTPS.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onlineImageAccess(true)
      }
    }
  }
  ```

### zoomAccess

zoomAccess(zoomAccess: boolean)

Sets whether to enable zoom gestures. By default, this feature is enabled.

**Parameters**

| Name       | Type   | Mandatory  | Default Value | Description         |
| ---------- | ------- | ---- | ---- | ------------- |
| zoomAccess | boolean | Yes   | true | Whether to enable zoom gestures.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .zoomAccess(true)
      }
    }
  }
  ```

### overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

Sets whether to load web pages by using the overview mode. By default, this feature is enabled.

**Parameters**

| Name               | Type   | Mandatory  | Default Value | Description           |
| ------------------ | ------- | ---- | ---- | --------------- |
| overviewModeAccess | boolean | Yes   | true | Whether to load web pages by using the overview mode.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .overviewModeAccess(true)
      }
    }
  }
  ```

### databaseAccess

databaseAccess(databaseAccess: boolean)

Sets whether to enable database access. By default, this feature is disabled.

**Parameters**

| Name           | Type   | Mandatory  | Default Value  | Description             |
| -------------- | ------- | ---- | ----- | ----------------- |
| databaseAccess | boolean | Yes   | false | Whether to enable database access.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### geolocationAccess

geolocationAccess(geolocationAccess: boolean)

Sets whether to enable geolocation access. By default, this feature is enabled.

**Parameters**

| Name              | Type   | Mandatory  | Default Value | Description           |
| ----------------- | ------- | ---- | ---- | --------------- |
| geolocationAccess | boolean | Yes   | true | Whether to enable geolocation access.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .geolocationAccess(true)
      }
    }
  }
  ```

### mediaPlayGestureAccess

mediaPlayGestureAccess(access: boolean)

Sets whether a manual click is required for video playback.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description             |
| ------ | ------- | ---- | ---- | ----------------- |
| access | boolean | Yes   | true | Whether a manual click is required for video playback.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State access: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mediaPlayGestureAccess(this.access)
      }
    }
  }
  ```

### multiWindowAccess<sup>9+</sup>

multiWindowAccess(multiWindow: boolean)

Sets whether to enable the multi-window permission.

**Parameters**

| Name        | Type   | Mandatory  | Default Value  | Description        |
| ----------- | ------- | ---- | ----- | ------------ |
| multiWindow | boolean | Yes   | false | Whether to enable the multi-window permission.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
        .multiWindowAccess(true)
      }
    }
  }
  ```

### cacheMode

cacheMode(cacheMode: CacheMode)

Sets the cache mode.

**Parameters**

| Name      | Type                       | Mandatory  | Default Value              | Description     |
| --------- | --------------------------- | ---- | ----------------- | --------- |
| cacheMode | [CacheMode](#cachemode)| Yes   | CacheMode.Default | Cache mode to set.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State mode: CacheMode = CacheMode.None
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .cacheMode(this.mode)
      }
    }
  }
  ```

### textZoomRatio<sup>9+</sup>

textZoomRatio(textZoomRatio: number)

Sets the text zoom ratio of the page. The default value is **100**, which indicates 100%.

**Parameters**

| Name          | Type  | Mandatory  | Default Value | Description           |
| ------------- | ------ | ---- | ---- | --------------- |
| textZoomRatio | number | Yes   | 100  | Text zoom ratio to set.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State atio: number = 150
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomRatio(this.atio)
      }
    }
  }
  ```

### initialScale<sup>9+</sup>

initialScale(percent: number)

Sets the scale factor of the entire page. The default value is 100%.

**Parameters**

| Name    | Type  | Mandatory  | Default Value | Description           |
| ------- | ------ | ---- | ---- | --------------- |
| percent | number | Yes   | 100  | Scale factor of the entire page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State percent: number = 100
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .initialScale(this.percent)
      }
    }
  }
  ```

### userAgent

userAgent(userAgent: string)

Sets the user agent.

**Parameters**

| Name      | Type  | Mandatory  | Default Value | Description     |
| --------- | ------ | ---- | ---- | --------- |
| userAgent | string | Yes   | -    | User agent to set.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State userAgent:string = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36'
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .userAgent(this.userAgent)
      }
    }
  }
  ```

### webDebuggingAccess<sup>9+</sup>

webDebuggingAccess(webDebuggingAccess: boolean)

Sets whether to enable web debugging.

**Parameters**

| Name               | Type   | Mandatory  | Default Value  | Description         |
| ------------------ | ------- | ---- | ----- | ------------- |
| webDebuggingAccess | boolean | Yes   | false | Whether to enable web debugging.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State webDebuggingAccess: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webDebuggingAccess(this.webDebuggingAccess)
      }
    }
  }
  ```

## Events

The universal events are not supported.

### onAlert

onAlert(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Triggered when **alert()** is invoked to display an alert dialog box on the web page.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | The user's operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onAlert((event) => {
            AlertDialog.show({
              title: 'onAlert',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onBeforeUnload

onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Triggered when this page is about to exit after the user refreshes or closes the page. This callback is triggered only when the page has obtained focus.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | The user's operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onBeforeUnload((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
            AlertDialog.show({
              title: 'onBeforeUnload',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onConfirm

onConfirm(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Triggered when **confirm()** is invoked by the web page.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | The user's operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onConfirm((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
            console.log("event.result:" + event.result)
            AlertDialog.show({
              title: 'onConfirm',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onPrompt<sup>9+</sup>

onPrompt(callback: (event?: { url: string; message: string; value: string; result: JsResult }) => boolean)

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | The user's operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPrompt((event) => {
            console.log("url:" + event.url)
            console.log("message:" + event.message)
            console.log("value:" + event.value)
            AlertDialog.show({
              title: 'onPrompt',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onConsole

onConsole(callback: (event?: { message: ConsoleMessage }) => boolean)

Triggered to notify the host application of a JavaScript console message.

**Parameters**

| Name    | Type                             | Description     |
| ------- | --------------------------------- | --------- |
| message | [ConsoleMessage](#consolemessage) | Console message.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | Returns **true** if the message will not be printed to the console; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onConsole((event) => {
            console.log('getMessage:' + event.message.getMessage())
            console.log('getSourceId:' + event.message.getSourceId())
            console.log('getLineNumber:' + event.message.getLineNumber())
            console.log('getMessageLevel:' + event.message.getMessageLevel())
            return false
          })
      }
    }
  }
  ```

### onDownloadStart

onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void)

**Parameters**

| Name               | Type         | Description                               |
| ------------------ | ------------- | ----------------------------------- |
| url                | string        | URL for the download task.                          |
| contentDisposition | string        | Content-Disposition response header returned by the server, which may be empty.|
| mimetype           | string        | MIME type of the content returned by the server.               |
| contentLength      | contentLength | Length of the content returned by the server.                        |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDownloadStart((event) => {
            console.log('url:' + event.url)
            console.log('userAgent:' + event.userAgent)
            console.log('contentDisposition:' + event.contentDisposition)
            console.log('contentLength:' + event.contentLength)
            console.log('mimetype:' + event.mimetype)
          })
      }
    }
  }
  ```

### onErrorReceive

onErrorReceive(callback: (event?: { request: WebResourceRequest, error: WebResourceError }) => void)

Triggered when an error occurs during web page loading. For better results, simplify the implementation logic in the callback.

**Parameters**

| Name    | Type                                    | Description           |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | Encapsulation of a web page request.     |
| error   | [WebResourceError](#webresourceerror)    | Encapsulation of a web page resource loading error.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onErrorReceive((event) => {
            console.log('getErrorInfo:' + event.error.getErrorInfo())
            console.log('getErrorCode:' + event.error.getErrorCode())
            console.log('url:' + event.request.getRequestUrl())
            console.log('isMainFrame:' + event.request.isMainFrame())
            console.log('isRedirect:' + event.request.isRedirect())
            console.log('isRequestGesture:' + event.request.isRequestGesture())
            console.log('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString())
            let result = event.request.getRequestHeader()
            console.log('The request header result size is ' + result.length)
            for (let i of result) {
              console.log('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue)
            }
          })
      }
    }
  }
  ```

### onHttpErrorReceive

onHttpErrorReceive(callback: (event?: { request: WebResourceRequest, response: WebResourceResponse }) => void)

Triggered when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.

**Parameters**

| Name    | Type                                    | Description           |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | Encapsulation of a web page request.     |
| error   | [WebResourceError](#webresourceerror)    | Encapsulation of a web page resource loading error.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpErrorReceive((event) => {
            console.log('url:' + event.request.getRequestUrl())
            console.log('isMainFrame:' + event.request.isMainFrame())
            console.log('isRedirect:' + event.request.isRedirect())
            console.log('isRequestGesture:' + event.request.isRequestGesture())
            console.log('getResponseData:' + event.response.getResponseData())
            console.log('getResponseEncoding:' + event.response.getResponseEncoding())
            console.log('getResponseMimeType:' + event.response.getResponseMimeType())
            console.log('getResponseCode:' + event.response.getResponseCode())
            console.log('getReasonMessage:' + event.response.getReasonMessage())
            let result = event.request.getRequestHeader()
            console.log('The request header result size is ' + result.length)
            for (let i of result) {
              console.log('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue)
            }
            let resph = event.response.getResponseHeader()
            console.log('The response header result size is ' + resph.length)
            for (let i of resph) {
              console.log('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue)
            }
          })
      }
    }
  }
  ```

### onPageBegin

onPageBegin(callback: (event?: { url: string }) => void)


Triggered when the web page starts to be loaded. This API is triggered only for the main frame content, and not for the iframe or frameset content.

**Parameters**

| Name | Type  | Description     |
| ---- | ------ | --------- |
| url  | string | URL of the page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageBegin((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onPageEnd

onPageEnd(callback: (event?: { url: string }) => void)


Triggered when the web page loading is complete. This API is triggered only for the main frame content.

**Parameters**

| Name | Type  | Description     |
| ---- | ------ | --------- |
| url  | string | URL of the page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageEnd((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onProgressChange

onProgressChange(callback: (event?: { newProgress: number }) => void)

Triggered when the web page loading progress changes.

**Parameters**

| Name        | Type  | Description                 |
| ----------- | ------ | --------------------- |
| newProgress | number | New loading progress. The value is an integer ranging from 0 to 100.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onProgressChange((event) => {
            console.log('newProgress:' + event.newProgress)
          })
      }
    }
  }
  ```

### onTitleReceive

onTitleReceive(callback: (event?: { title: string }) => void)

Triggered when the document title of the web page is changed.

**Parameters**

| Name  | Type  | Description         |
| ----- | ------ | ------------- |
| title | string | Document title.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onTitleReceive((event) => {
            console.log('title:' + event.title)
          })
      }
    }
  }
  ```

### onRefreshAccessedHistory

onRefreshAccessedHistory(callback: (event?: { url: string, isRefreshed: boolean }) => void)

Triggered when loading of the web page is complete. This API is used by an application to update the historical link it accessed.

**Parameters**

| Name        | Type   | Description                                    |
| ----------- | ------- | ---------------------------------------- |
| url         | string  | URL to be accessed.                                 |
| isRefreshed | boolean | Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh](#refresh) API, and **false** means the opposite.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onRefreshAccessedHistory((event) => {
            console.log('url:' + event.url + ' isReload:' + event.isRefreshed)
          })
      }
    }
  }
  ```

### onRenderExited

onRenderExited(callback: (event?: { renderExitReason: RenderExitReason }) => void)

Triggered when the rendering process exits abnormally.

**Parameters**

| Name             | Type                                    | Description            |
| ---------------- | ---------------------------------------- | ---------------- |
| renderExitReason | [RenderExitReason](#renderexitreason)| Cause for the abnormal exit of the rendering process.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'chrome://crash/', controller: this.controller })
          .onRenderExited((event) => {
            console.log('reason:' + event.renderExitReason)
          })
      }
    }
  }
  ```

### onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: (event?: { result: FileSelectorResult, fileSelector: FileSelectorParam }) => boolean)

Triggered to process an HTML form whose input type is **file**, in response to the tapping of the **Select File** button.

**Parameters**

| Name         | Type                                    | Description             |
| ------------ | ---------------------------------------- | ----------------- |
| result       | [FileSelectorResult](#fileselectorresult9) | File selection result to be sent to the **\<Web>** component.|
| fileSelector | [FileSelectorParam](#fileselectorparam9) | Information about the file selector.      |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** means that the pop-up window provided by the system is displayed. The value **false** means that the default web pop-up window is displayed.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onShowFileSelector((event) => {
            AlertDialog.show({
              title: event.fileSelector.getTitle(),
              message: 'isCapture:' + event.fileSelector.isCapture() + " mode:" + event.fileSelector.getMode() + 'acceptType:' + event.fileSelector.getAcceptType(),
              confirm: {
                value: 'upload',
                action: () => {
                  let fileList: Array<string> = [
                    '/data/storage/el2/base/test',
                  ]
                  event.result.handleFileList(fileList)
                }
              },
              cancel: () => {
                let fileList: Array<string> = []
                event.result.handleFileList(fileList)
              }
            })
            return true
          })
      }
    }
  }
  ```

### onResourceLoad<sup>9+</sup>

onResourceLoad(callback: (event: {url: string}) => void)

Invoked to notify the **\<Web>** component of the URL of the loaded resource file.

**Parameters**

| Name | Type  | Description          |
| ---- | ------ | -------------- |
| url  | string | URL of the loaded resource file.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url)
          })
      }
    }
  }
  ```

### onScaleChange<sup>9+</sup>

onScaleChange(callback: (event: {oldScale: number, newScale: number}) => void)

Invoked when the display ratio of this page changes.

**Parameters**

| Name     | Type  | Description        |
| -------- | ------ | ------------ |
| oldScale | number | Display ratio of the page before the change.|
| newScale | number | Display ratio of the page after the change.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale)
          })
      }
    }
  }
  ```

### onUrlLoadIntercept

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

Triggered when the **\<Web>** component is about to access a URL. This API is used to determine whether to block the access.

**Parameters**

| Name | Type                                    | Description     |
| ---- | ---------------------------------------- | --------- |
| data | string / [WebResourceRequest](#webresourcerequest) | URL information.|

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if the access is blocked; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onUrlLoadIntercept((event) => {
            console.log('onUrlLoadIntercept ' + event.data.toString())
            return true
          })
      }
    }
  }
  ```

### onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: (event?: { request: WebResourceRequest}) => WebResourceResponse)

Invoked when the **\<Web>** component is about to access a URL. This API is used to block the URL and return the response data.

**Parameters**

| Name    | Type                                    | Description       |
| ------- | ---------------------------------------- | ----------- |
| request | [WebResourceRequest](#webresourcerequest) | Information about the URL request.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| [WebResourceResponse](#webresourceresponse) | If response data is returned, the data is loaded based on the response data. If no response data is returned, null is returned, indicating that the data is loaded in the original mode.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    responseweb: WebResourceResponse = new WebResourceResponse()
    heads:Header[] = new Array()
    @State webdata: string = "<!DOCTYPE html>\n" +
    "<html>\n"+
    "<head>\n"+
    "<title>intercept test</title>\n"+
    "</head>\n"+
    "<body>\n"+
    "<h1>intercept test</h1>\n"+
    "</body>\n"+
    "</html>"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onInterceptRequest((event) => {
            console.log('url:' + event.request.getRequestUrl())
            var head1:Header = {
              headerKey:"Connection",
              headerValue:"keep-alive"
            }
            var head2:Header = {
              headerKey:"Cache-Control",
              headerValue:"no-cache"
            }
            var length = this.heads.push(head1)
            length = this.heads.push(head2)
            this.responseweb.setResponseHeader(this.heads)
            this.responseweb.setResponseData(this.webdata)
            this.responseweb.setResponseEncoding('utf-8')
            this.responseweb.setResponseMimeType('text/html')
            this.responseweb.setResponseCode(200)
            this.responseweb.setReasonMessage('OK')
            return this.responseweb
          })
      }
    }
  }
  ```

### onHttpAuthRequest<sup>9+</sup>

onHttpAuthRequest(callback: (event?: { handler: HttpAuthHandler, host: string, realm: string}) => boolean)

Invoked when an HTTP authentication request is received.

**Parameters**

| Name    | Type                                | Description            |
| ------- | ------------------------------------ | ---------------- |
| handler | [HttpAuthHandler](#httpauthhandler9) | The user's operation.  |
| host    | string                               | Host to which HTTP authentication credentials apply.|
| realm   | string                               | Realm to which HTTP authentication credentials apply. |

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    httpAuth: boolean = false
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpAuthRequest((event) => {
            AlertDialog.show({
              title: 'onHttpAuthRequest',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  this.httpAuth = event.handler.isHttpAuthInfoSaved()
                  if (this.httpAuth == false) {
                    web_webview.WebDataBase.saveHttpAuthCredentials(
                      event.host,
                      event.realm,
                      "2222",
                      "2222"
                    )
                    event.handler.cancel()
                  }
                }
              },
              cancel: () => {
                event.handler.cancel()
              }
            })
            return true
          })
      }
    }
  }
  ```
### onSslErrorEventReceive<sup>9+</sup>

onSslErrorEventReceive(callback: (event: { handler: SslErrorHandler, error: SslError }) => void)

Invoked when an SSL error occurs during resource loading.

**Parameters**

| Name    | Type                                | Description          |
| ------- | ------------------------------------ | -------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | The user's operation.|
| error   | [SslError](#sslerror9)          | Error code.          |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSslErrorEventReceive((event) => {
            AlertDialog.show({
              title: 'onSslErrorEventReceive',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm()
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel()
                }
              },
              cancel: () => {
                event.handler.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onClientAuthenticationRequest<sup>9+</sup>

onClientAuthenticationRequest(callback: (event: {handler : ClientAuthenticationHandler, host : string, port : number, keyTypes : Array<string>, issuers : Array<string>}) => void)

Invoked when an SSL client certificate request is received.

**Parameters**

| Name     | Type                                    | Description           |
| -------- | ---------------------------------------- | --------------- |
| handler  | [ClientAuthenticationHandler](#clientauthenticationhandler9) | The user's operation. |
| host     | string                                   | Host name of the server that requests a certificate.   |
| port     | number                                   | Port number of the server that requests a certificate.   |
| keyTypes | Array\<string>                          | Acceptable asymmetric private key types.   |
| issuers  | Array\<string>                           | Issuer of the certificate that matches the private key.|

  **Example**
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onClientAuthenticationRequest((event) => {
            AlertDialog.show({
              title: 'onClientAuthenticationRequest',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.confirm("/system/etc/user.pk8", "/system/etc/chain-user.pem")
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel()
                }
              },
              cancel: () => {
                event.handler.ignore()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: (event?: { request: PermissionRequest }) => void)

Invoked when a permission request is received.

**Parameters**

| Name    | Type                                    | Description          |
| ------- | ---------------------------------------- | -------------- |
| request | [PermissionRequest](#permissionrequest9) | The user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPermissionRequest((event) => {
            AlertDialog.show({
              title: 'title',
              message: 'text',
              primaryButton: {
                value: 'deny',
                action: () => {
                  event.request.deny()
                }
              },
              secondaryButton: {
                value: 'onConfirm',
                action: () => {
                  event.request.grant(event.request.getAccessibleResource())
                }
              },
              cancel: () => {
                event.request.deny()
              }
            })
          })
      }
    }
  }
  ```

### onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: (event?: { param: WebContextMenuParam, result: WebContextMenuResult }) => boolean)

Invoked when a context menu is displayed upon a long press on a specific element (such as an image or link).

**Parameters**

| Name   | Type                                    | Description       |
| ------ | ---------------------------------------- | ----------- |
| param  | [WebContextMenuParam](#webcontextmenuparam9) | Parameters related to the context menu.    |
| result | [WebContextMenuResult](#webcontextmenuresult9) | Result of the context menu.|

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | The value **true** means a custom menu, and **false** means the default menu.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onContextMenuShow((event) => {
            console.info("x coord = " + event.param.x())
            console.info("link url = " + event.param.getLinkUrl())
            return true
        })
      }
    }
  }
  ```

### onScroll<sup>9+</sup>

onScroll(callback: (event: {xOffset: number, yOffset: number}) => void)

Invoked when the scrollbar of the page scrolls.

**Parameters**

| Name    | Type  | Description        |
| ------- | ------ | ------------ |
| xOffset | number | Position of the scrollbar on the x-axis.|
| yOffset | number | Position of the scrollbar on the y-axis.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
        .onScroll((event) => {
            console.info("x = " + event.xOffset)
            console.info("y = " + event.yOffset)
        })
      }
    }
  }
  ```

### onGeolocationShow

onGeolocationShow(callback: (event?: { origin: string, geolocation: JsGeolocation }) => void)

Registers a callback for receiving a request to obtain the geolocation information.

**Parameters**

| Name        | Type                           | Description          |
| ----------- | ------------------------------- | -------------- |
| origin      | string                          | Index of the origin.    |
| geolocation | [JsGeolocation](#jsgeolocation) | The user's operation.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .geolocationAccess(true)
        .onGeolocationShow((event) => {
          AlertDialog.show({
            title: 'title',
            message: 'text',
            confirm: {
              value: 'onConfirm',
              action: () => {
                event.geolocation.invoke(event.origin, true, true)
              }
            },
            cancel: () => {
              event.geolocation.invoke(event.origin, false, true)
            }
          })
        })
      }
    }
  }
  ```

### onGeolocationHide

onGeolocationHide(callback: () => void)

Triggered to notify the user that the request for obtaining the geolocation information received when **[onGeolocationShow](#ongeolocationshow)** is called has been canceled.

**Parameters**

| Name     | Type      | Description                |
| -------- | ---------- | -------------------- |
| callback | () => void | Callback invoked when the request for obtaining geolocation information has been canceled. |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .geolocationAccess(true)
        .onGeolocationHide(() => {
          console.log("onGeolocationHide...")
        })
      }
    }
  }
  ```

### onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: (event: { handler: FullScreenExitHandler }) => void)

Registers a callback for the component's entering into full screen mode.

**Parameters**

| Name    | Type                                    | Description          |
| ------- | ---------------------------------------- | -------------- |
| handler | [FullScreenExitHandler](#fullscreenexithandler9) | Function handle for exiting full screen mode.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    handler: FullScreenExitHandler = null
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .onFullScreenEnter((event) => {
          console.log("onFullScreenEnter...")
          this.handler = event.handler
        })
      }
    }
  }
  ```

### onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

Registers a callback for the component's exiting full screen mode.

**Parameters**

| Name     | Type      | Description         |
| -------- | ---------- | ------------- |
| callback | () => void | Callback invoked when the component exits full screen mode.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    handler: FullScreenExitHandler = null
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .onFullScreenExit(() => {
          console.log("onFullScreenExit...")
          this.handler.exitFullScreen()
        })
        .onFullScreenEnter((event) => {
          this.handler = event.handler
        })
      }
    }
  }
  ```

### onWindowNew<sup>9+</sup>

onWindowNew(callback: (event: {isAlert: boolean, isUserTrigger: boolean, targetUrl: string, handler: ControllerHandler}) => void)

Registers a callback for window creation.

**Parameters**

| Name          | Type                                    | Description                      |
| ------------- | ---------------------------------------- | -------------------------- |
| isAlert       | boolean                                  | Whether to open the target URL in a new window. The value **true** means to open the target URL in a new window, and **false** means to open the target URL in a new tab.|
| isUserTrigger | boolean                                  | Whether the creation is triggered by the user. The value **true** means that the creation is triggered by the user, and **false** means the opposite.  |
| targetUrl     | string                                   | Target URL.                    |
| handler       | [ControllerHandler](#controllerhandler9) | **WebController** instance for setting the new window. |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
        .multiWindowAccess(true)
        .onWindowNew((event) => {
          console.log("onWindowNew...")
          var popController: WebController = new WebController()
          event.handler.setWebController(popController)
        })
      }
    }
  }
  ```

### onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

Registers a callback for window closure.

**Parameters**

| Name     | Type      | Description        |
| -------- | ---------- | ------------ |
| callback | () => void | Callback invoked when the window closes.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
        .onWindowExit(() => {
          console.log("onWindowExit...")
        })
      }
    }
  }
  ```

### onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: (event?: {activeMatchOrdinal: number, numberOfMatches: number, isDoneCounting: boolean}) => void): WebAttribute

Invoked to notify the caller of the search result on the web page.

**Parameters**

| Name               | Type   | Description                                    |
| ------------------ | ------- | ---------------------------------------- |
| activeMatchOrdinal | number  | Sequence number of the current match, which starts from 0.                      |
| numberOfMatches    | number  | Total number of matches.                           |
| isDoneCounting     | boolean | Whether the search operation on the current page is complete. This API may be called multiple times until **isDoneCounting** is **true**.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
     	  .onSearchResultReceive(ret => {
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
              "[total]" + ret.numberOfMatches + "[isDone]"+ ret.isDoneCounting)
          })
      }
    }
  }
  ```

## ConsoleMessage

Implements the **ConsoleMessage** object. For details about the sample code, see [onConsole](#onconsole).

### getLineNumber

getLineNumber(): number

Obtains the number of rows in this console message.

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | Number of rows in the console message.|

### getMessage

getMessage(): string

Obtains the log information of this console message.

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Log information of the console message.|

### getMessageLevel

getMessageLevel(): MessageLevel

Obtains the level of this console message.

**Return value**

| Type                               | Description                    |
| --------------------------------- | ---------------------- |
| [MessageLevel](#messagelevel)| Level of the console message.|

### getSourceId

getSourceId(): string

Obtains the path and name of the web page source file.

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Path and name of the web page source file.|

## JsResult

Implements the **JsResult** object, which indicates the result returned to the **\<Web>** component to indicate the user operation performed in the dialog box. For details about the sample code, see [onAlert Event](#onalert).

### handleCancel

handleCancel(): void

Notifies the **\<Web>** component of the user's cancel operation in the dialog box.

### handleConfirm

handleConfirm(): void

Notifies the **\<Web>** component of the user's confirm operation in the dialog box.

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

Notifies the **\<Web>** component of the user's confirm operation in the dialog box as well as the dialog box content.

**Parameters**

| Name   | Type  | Mandatory  | Default Value | Description       |
| ------ | ------ | ---- | ---- | ----------- |
| result | string | Yes   | -    | User input in the dialog box.|

## FullScreenExitHandler<sup>9+</sup>

Implements a **FullScreenExitHandler** object for listening for exiting full screen mode. For the sample code, see [onFullScreenEnter](#onfullscreenenter9).

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

Exits full screen mode.

## ControllerHandler<sup>9+</sup>

Implements a **WebController** object for new **\<Web>** components. For the sample code, see [onWindowNew](#onwindownew9).

### setWebController<sup>9+</sup>

setWebController(controller: WebController): void

Sets a **WebController** object.

**Parameters**

| Name       | Type         | Mandatory  | Default Value | Description                     |
| ---------- | ------------- | ---- | ---- | ------------------------- |
| controller | WebController | Yes   | -    | **WebController** object to set.|

## WebResourceError

Implements the **WebResourceError** object. For details about the sample code, see [onErrorReceive](#onerrorreceive).

### getErrorCode

getErrorCode(): number

Obtains the error code for resource loading.

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Error code for resource loading.|

### getErrorInfo

getErrorInfo(): string

Obtains error information about resource loading.

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Error information about resource loading.|

## WebResourceRequest

Implements the **WebResourceRequest** object. For details about the sample code, see [onErrorReceive](#onerrorreceive).

### getRequestHeader

getResponseHeader() : Array\<Header\>

Obtains the information about the resource request header.

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | Information about the resource request header.|

### getRequestUrl

getRequestUrl(): string

Obtains the URL of the resource request.

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

### isMainFrame

isMainFrame(): boolean

Checks whether the resource request is in the main frame.

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is in the main frame.|

### isRedirect

isRedirect(): boolean

Checks whether the resource request is redirected by the server.

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is redirected by the server.|

### isRequestGesture

isRequestGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap).|

## Header

Describes the request/response header returned by the **\<Web>** component.

| Name         | Type    | Description           |
| ----------- | ------ | ------------- |
| headerKey   | string | Key of the request/response header.  |
| headerValue | string | Value of the request/response header.|


## WebResourceResponse

Implements the **WebResourceResponse** object. For details about the sample code, see [onHttpErrorReceive](#onhttperrorreceive).

### getReasonMessage

getReasonMessage(): string

Obtains the status code description of the resource response.

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Status code description of the resource response.|

### getResponseCode

getResponseCode(): number

Obtains the status code of the resource response.

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Status code of the resource response.|

### getResponseData

getResponseData(): string

Obtains the data in the resource response.

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Data in the resource response.|

### getResponseEncoding

getResponseEncoding(): string

Obtains the encoding string of the resource response.

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Encoding string of the resource response.|

### getResponseHeader

getResponseHeader() : Array\<Header\>

Obtains the resource response header.

**Return value**

| Type                        | Description      |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | Resource response header.|

### getResponseMimeType

getResponseMimeType(): string

Obtains the MIME type of the resource response.

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | MIME type of the resource response.|

### setResponseData<sup>9+</sup>

setResponseData(data: string)

Sets the data in the resource response.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description       |
| ---- | ------ | ---- | ---- | ----------- |
| data | string | Yes   | -    | Resource response data to set.|

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string)

Sets the encoding string of the resource response.

**Parameters**

| Name     | Type  | Mandatory  | Default Value | Description        |
| -------- | ------ | ---- | ---- | ------------ |
| encoding | string | Yes   | -    | Encoding string to set.|

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string)

Sets the MIME type of the resource response.

**Parameters**

| Name     | Type  | Mandatory  | Default Value | Description                |
| -------- | ------ | ---- | ---- | -------------------- |
| mimeType | string | Yes   | -    | MIME type to set.|

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string)

Sets the status code description of the resource response.

**Parameters**

| Name   | Type  | Mandatory  | Default Value | Description           |
| ------ | ------ | ---- | ---- | --------------- |
| reason | string | Yes   | -    | Status code description to set.|

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>)

Sets the resource response header.

**Parameters**

| Name   | Type                      | Mandatory  | Default Value | Description      |
| ------ | -------------------------- | ---- | ---- | ---------- |
| header | Array\<[Header](#header)\> | Yes   | -    | Resource response header to set.|

### setResponseCode<sup>9+</sup>

setResponseCode(code: number)

Sets the status code of the resource response.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description         |
| ---- | ------ | ---- | ---- | ------------- |
| code | number | Yes   | -    | Status code to set.|

## FileSelectorResult<sup>9+</sup>

Notifies the **\<Web>** component of the file selection result. For details about the sample code, see [onShowFileSelector](#onshowfileselector9).

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

Instructs the **\<Web>** component to select a file.

**Parameters**

| Name     | Type           | Mandatory  | Default Value | Description        |
| -------- | --------------- | ---- | ---- | ------------ |
| fileList | Array\<string\> | Yes   | -    | List of files to operate.|

## FileSelectorParam<sup>9+</sup>

Implements the **FileSelectorParam** object. For details about the sample code, see [onShowFileSelector](#onshowfileselector9).

### getTitle<sup>9+</sup>

getTitle(): string

Obtains the title of the file selector.

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Title of the file selector.|

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

Obtains the mode of the file selector.

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](#fileselectormode)| Mode of the file selector.|

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

Obtains the file filtering type.

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | File filtering type.|

### isCapture<sup>9+</sup>

isCapture(): boolean

Checks whether multimedia capabilities are invoked.

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Whether multimedia capabilities are invoked.|

## HttpAuthHandler<sup>9+</sup>

Implements the **HttpAuthHandler** object. For details about the sample code, see [onHttpAuthRequest](#onhttpauthrequest9).

### cancel<sup>9+</sup>

cancel(): void

Cancels HTTP authentication as requested by the user.

### confirm<sup>9+</sup>

confirm(userName: string, pwd: string): boolean

Performs HTTP authentication with the user name and password provided by the user.

**Parameters**

| Name     | Type  | Mandatory  | Default Value | Description      |
| -------- | ------ | ---- | ---- | ---------- |
| userName | string | Yes   | -    | HTTP authentication user name.|
| pwd      | string | Yes   | -    | HTTP authentication password. |

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

Uses the password cached on the server for authentication.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

## SslErrorHandler<sup>9+</sup>

Implements an **SslErrorHandler** object. For details about the sample code, see [onSslErrorEventReceive Event](#onsslerroreventreceive9).

### handleCancel<sup>9+</sup>

handleCancel(): void

Cancels this request.

### handleConfirm<sup>9+</sup>

handleConfirm(): void

Continues using the SSL certificate.

## ClientAuthenticationHandler<sup>9+</sup>

Implements a **ClientAuthenticationHandler** object returned by the **\<Web>** component. For details about the sample code, see [onClientAuthenticationRequest](#onclientauthenticationrequest9).

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

Uses the specified private key and client certificate chain.

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | Yes   | File that stores the private key, which is a directory including the file name. |
| certChainFile | string | Yes   | File that stores the certificate chain, which is a directory including the file name.|

### cancel<sup>9+</sup>

cancel(): void

Cancels the client certificate request sent by the same host and port server. No additional event will be reported for requests from the same host and port server.

### ignore<sup>9+</sup>

ignore(): void

Ignores this request.

## PermissionRequest<sup>9+</sup>

Implements the **PermissionRequest** object. For details about the sample code, see [onPermissionRequest](#onpermissionrequest9).

### deny<sup>9+</sup>

deny(): void

Denies the permission requested by the web page.

### getOrigin<sup>9+</sup>

getOrigin(): string

Obtains the origin of this web page.

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

Obtains the list of accessible resources requested for the web page. For details about the resource types, see [ProtectedResourceType](#protectedresourcetype9).

**Return value**

| Type             | Description           |
| --------------- | ------------- |
| Array\<string\> | List of accessible resources requested by the web page.|

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

Grants the permission for resources requested by the web page.

**Parameters**

| Name      | Type           | Mandatory  | Default Value | Description         |
| --------- | --------------- | ---- | ---- | ------------- |
| resources | Array\<string\> | Yes   | -    | List of accessible resources requested by the web page.|

## WebContextMenuParam<sup>9+</sup>

Provides the information about the context menu that is displayed when a page element is long pressed. For details about the sample code, see [onContextMenuShow](#oncontextmenushow9).

### x<sup>9+</sup>

x(): number

Obtains the X coordinate of the context menu.

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.|

### y<sup>9+</sup>

y(): number

Obtains the Y coordinate of the context menu.

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.|

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

Obtains the URL of the destination link.

**Return value**

| Type    | Description                       |
| ------ | ------------------------- |
| string | If it is a link that is being long pressed, the URL that has passed the security check is returned.|

### getUnfilterendLinkUrl<sup>9+</sup>

getUnfilterendLinkUrl(): string

Obtains the URL of the destination link.

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| string | If it is a link that is being long pressed, the original URL is returned.|

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

Obtain the source URL.

**Return value**

| Type    | Description                      |
| ------ | ------------------------ |
| string | If the selected element has the **src** attribute, the URL in the **src** is returned.|

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

Checks whether image content exists.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | The value **true** means that there is image content in the element being long pressed, and **false** means the opposite.|

## WebContextMenuResult<sup>9+</sup>

Implements the response event executed when a context menu is displayed. For details about the sample code, see [onContextMenuShow](#oncontextmenushow9).

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

Closes this context menu. This API must be called when no operations in **WebContextMenuResult** are performed.

### copyImage<sup>9+</sup>

copyImage(): void

Copies the image specified in **WebContextMenuParam**.

## JsGeolocation

Implements the **PermissionRequest** object. For details about the sample code, see [onGeolocationShow Event](#ongeolocationshow).

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

Sets the geolocation permission status of a web page.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description                                    |
| ------ | ------- | ---- | ---- | ---------------------------------------- |
| origin | string  | Yes   | -    | Index of the origin.                              |
| allow  | boolean | Yes   | -    | Geolocation permission status.                            |
| retain | boolean | Yes   | -    | Whether the geolocation permission status can be saved to the system. The **[GeolocationPermissions](#geolocationpermissions9)** API can be used to manage the geolocation permission status saved to the system.|

## WebController

Implements a **WebController** object to control the behavior of the **\<Web>** component. A **WebController** can control only one **\<Web>** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **\<Web>** component.

### Creating an Object

```
webController: WebController = new WebController()
```

### requestFocus

requestFocus()

Requests focus for this web page.

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

### accessBackward

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if going to the previous page can be performed on the current page; returns **false** otherwise.|

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

### accessForward

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if going to the next page can be performed on the current page; returns **false** otherwise.|

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

### accessStep

accessStep(step: number): boolean

Performs a specific number of steps forward or backward from the current page.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description                 |
| ---- | ------ | ---- | ---- | --------------------- |
| step | number | Yes   | -    | Number of the steps to take. A positive number means to go forward, and a negative number means to go backward.|

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

### backward

backward(): void

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

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

### forward

forward(): void

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

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

### backOrForward<sup>9+</sup>

backOrForward(step: number): void

Performs a specific number of steps forward or backward on the current page based on the history stack. No redirection will be performed if the corresponding page does not exist in the history stack.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description       |
| ---- | ------ | ---- | ---- | ----------- |
| step | number | Yes   | -    | Number of the steps to take.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State step: number = -2
  
    build() {
      Column() {
        Button('backOrForward')
          .onClick(() => {
            this.controller.backOrForward(this.step)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string)

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately, with no need for invoking the [refresh](#refresh) API.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description                                    |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| name | string | Yes   | -    | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side.|

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

### getHitTest

getHitTest(): HitTestType

Obtains the element type of the area being clicked.	

**Return value**

| Type                             | Description         |
| ------------------------------- | ----------- |
| [HitTestType](#hittesttype)| Element type of the area being clicked.|

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

### getHitTestValue<sup>9+</sup>
getHitTestValue(): HitTestValue

Obtains the element information of the area being clicked.

**Return value**

| Type                            | Description        |
| ------------------------------ | ---------- |
| [HitTestValue](#hittestvalue9) | Element information of the area being clicked.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getHitTestValue')
          .onClick(() => {
            let hitValue = this.controller.getHitTestValue()
            console.log("hitType: " + hitValue.getType())
            console.log("extra: " + hitValue.getExtra())
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getWebId<sup>9+</sup>
getWebId(): number

Obtains the index value of this **\<Web>** component, which can be used for **\<Web>** component management.

**Return value**

| Type    | Description          |
| ------ | ------------ |
| number | Index value of the current **\<Web>** component.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getWebId')
          .onClick(() => {
            let id = this.controller.getWebId()
            console.log("id: " + id)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getTitle<sup>9+</sup>
getTitle(): string

Obtains the title of the current web page.

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Title of the current web page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getTitle')
          .onClick(() => {
            let title = this.controller.getTitle()
            console.log("title: " + title)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getPageHeight<sup>9+</sup>
getPageHeight(): number

Obtains the height of the current web page.

**Return value**

| Type    | Description        |
| ------ | ---------- |
| number | Height of the current web page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getPageHeight')
          .onClick(() => {
            let pageHeight = this.controller.getPageHeight()
            console.log("pageHeight: " + pageHeight)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getDefaultUserAgent<sup>9+</sup>
getDefaultUserAgent(): string

Obtains the default user agent of the current web page.

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Default user agent.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getDefaultUserAgent')
          .onClick(() => {
            let userAgent = this.controller.getDefaultUserAgent()
            console.log("userAgent: " + userAgent)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadData

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

Loads data. If **baseUrl** is empty, the specified character string will be loaded using the data protocol.

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **\<Web>** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **\<Web>** component as a non-encoded string in a manner similar to **loadUrl**.

**Parameters**

| Name       | Type  | Mandatory  | Default Value | Description                                    |
| ---------- | ------ | ---- | ---- | ---------------------------------------- |
| data       | string | Yes   | -    | Character string obtained after being Base64 or URL encoded.             |
| mimeType   | string | Yes   | -    | Media type (MIME).                             |
| encoding   | string | Yes   | -    | Encoding type, which can be Base64 or URL.               |
| baseUrl    | string | No   | -    | URL (HTTP/HTTPS/data compliant), which is assigned by the **\<Web>** component to **window.origin**.|
| historyUrl | string | No   | -    | Historical record URL. If this parameter is not empty, it can be managed in historical records to implement page going backward and forward. This parameter is invalid when **baseUrl** is left empty.|

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

### loadUrl

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

The object injected through **registerJavaScriptProxy** is still valid on a new page redirected through **loadUrl**.

**Parameters**

| Name    | Type                      | Mandatory  | Default Value | Description          |
| ------- | -------------------------- | ---- | ---- | -------------- |
| url     | string                     | Yes   | -    | URL to load.    |
| headers | Array\<[Header](#header)\> | No   | []   | Additional HTTP request header of the URL.|

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

### onActive

onActive(): void

Invoked when the **\<Web>** component enters the active state.

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

### onInactive

onInactive(): void

Invoked when the **\<Web>** component enters the inactive state.

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

### zoom
zoom(factor: number): void

Sets a zoom factor for the current web page.

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

### zoomIn<sup>9+</sup>
zoomIn(): boolean

Zooms in on this web page by 20%.

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Operation result.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('zoomIn')
          .onClick(() => {
            let result = this.controller.zoomIn()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### zoomOut<sup>9+</sup>
zoomOut(): boolean

Zooms out of this web page by 20%.

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Operation result.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('zoomOut')
          .onClick(() => {
            let result = this.controller.zoomOut()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### refresh

refresh()

Invoked when the **\<Web>** component refreshes the web page.

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

### registerJavaScriptProxy

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

Registers a JavaScript object and invokes the methods of the object in the window. You must invoke the [refresh](#refresh) API for the registration to take effect.

**Parameters**

| Name       | Type           | Mandatory  | Default Value | Description                                    |
| ---------- | --------------- | ---- | ---- | ---------------------------------------- |
| object     | object          | Yes   | -    | Application-side JavaScript object to be registered. Methods can be declared, but attributes cannot. The parameters and return value can only be of the string, number, or Boolean type.|
| name       | string          | Yes   | -    | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string\> | Yes   | -    | Methods of the JavaScript object to be registered at the application side.                |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Index {
    controller: WebController = new WebController()
    testObj = {
      test: (data) => {
        return "ArkUI Web Component"
      },
      toString: () => {
        console.log('Web Component toString')
      }
    }
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

### runJavaScript

runJavaScript(options: { script: string, callback?: (result: string) => void })

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**Parameters**

| Name     | Type                    | Mandatory  | Default Value | Description                                    |
| -------- | ------------------------ | ---- | ---- | ---------------------------------------- |
| script   | string                   | Yes   | -    | JavaScript script.                           |
| callback | (result: string) => void | No   | -    | Callback used to return the result. Returns **null** if the JavaScript script fails to be executed or no value is returned.|

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
        .onPageEnd(e => {
          this.controller.runJavaScript({
            script: 'test()',
            callback: (result: string)=> {
              this.webResult = result
              console.info(`The test() return value is: ${result}`)
            }})
          console.info('url: ', e.url)
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
        console.log('Ark WebComponent')
        return "This value is from index.html"
    }
    </script>
  </html>

  ```

### stop

stop()

Stops page loading.

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

### clearHistory

clearHistory(): void

Clears the browsing history.

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

### clearSslCache

clearSslCache(): void

Clears the user operation corresponding to the SSL certificate error event recorded by the **\<Web>** component.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearSslCache')
          .onClick(() => {
            this.controller.clearSslCache()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### clearClientAuthenticationCache

clearClientAuthenticationCache(): void

Clears the user operation corresponding to the client certificate request event recorded by the **\<Web>** component.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearClientAuthenticationCache')
          .onClick(() => {
            this.controller.clearClientAuthenticationCache()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getCookieManager<sup>9+</sup>

getCookieManager(): WebCookie

Obtains the cookie management object of the **\<Web>** component.

**Return value**

| Type       | Description                                      |
| --------- | ---------------------------------------- |
| WebCookie | Cookie management object. For details, see [WebCookie](#webcookie).|

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

### createWebMessagePorts<sup>9+</sup>

createWebMessagePorts(): Array\<WebMessagePort\>

Creates web message ports.

**Return value**


| Type                                      | Description        |
| ---------------------------------------- | ---------- |
| Array\<[WebMessagePort](#webmessageport9)\> | List of web message ports.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null
    build() {
      Column() {
        Button('createWebMessagePorts')
          .onClick(() => {
            this.ports = this.controller.createWebMessagePorts()
            console.log("createWebMessagePorts size:" + this.ports.length)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### postMessage<sup>9+</sup>

postMessage(options: { message: WebMessageEvent, uri: string}): void

Sends a web message to an HTML5 window.

**Parameters**

| Name    | Type                                | Mandatory  | Default Value | Description             |
| ------- | ------------------------------------ | ---- | ---- | ----------------- |
| message | [WebMessageEvent](#webmessageevent9) | Yes   | -    | Message to send, including the data and message port.|
| uri     | string                               | Yes   | -    | URI for receiving the message.       |

**Example**

  ```ts
  // index.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null
    @State sendFromEts: string = 'Send this message from ets to HTML'
    @State receivedFromHtml: string = 'Display received message send from HTML'

    build() {
      Column() {
        // Display the received HTML content.
        Text(this.receivedFromHtml)
        // Send the content in the text box to an HTML window.
        TextInput({placeholder: 'Send this message from ets to HTML'})
        .onChange((value: string) => {
          this.sendFromEts = value
        })

        // 1. Create two message ports.
        Button('1.CreateWebMessagePorts')
          .onClick(() => {
            this.ports = this.controller.createWebMessagePorts()
            console.log("createWebMessagePorts size:" + this.ports.length)
          })

        // 2. Send one of the message ports to the HTML side, which can then save and use the port.
        Button('2.PostMessagePort')
          .onClick(() => {
            var sendPortArray = new Array(this.ports[1])
            var msgEvent = new WebMessageEvent()
            msgEvent.setData("__init_port__")
            msgEvent.setPorts(sendPortArray)
            this.controller.postMessage({message: msgEvent, uri: "*"})
          })

        // 3. Register a callback for the other message port on the application side.
        Button('3.RegisterCallback')
          .onClick(() => {
              this.ports[0].onMessageEvent((result: string) => {
                var msg = 'Got msg from HTML: ' + result
                this.receivedFromHtml = msg
              })
          })

        // 4. Use the port on the application side to send messages to the message port that has been sent to the HTML.
        Button('4.SendDataToHtml5')
          .onClick(() => {
            var msg = new WebMessageEvent()
            msg.setData(this.sendFromEts)
            this.ports[0].postMessageEvent(msg)
          })
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .javaScriptAccess(true)
          .fileAccess(true)
      }
    }
  }

  // index.html
  <!DOCTYPE html>
  <html>
      <body>
          <h1>Web Message Port Demo</h1>
          <div style="font-size: 24pt;">
            <input type="button" value="5.SendToEts" onclick="PostMsgToEts(msgFromJS.value);" /><br/>
            <input id="msgFromJS" type="text" value="send this message from HTML to ets" style="font-size: 16pt;" /><br/>
          </div>
          <p class="output">display received message send from ets</p>
      </body>
      <script src="index.js"></script>
  </html>

  // index.js
  var h5Port;
  var output = document.querySelector('.output');
  window.addEventListener('message', function(event) {
    if (event.data == '__init_port__') {
      if(event.ports[0] != null) {
        h5Port = event.ports[0]; // 1. Save the port number sent from the eTS side.
        h5Port.onmessage = function(event) {
          // 2. Receive the message sent from the eTS side.
          var msg = 'Got message from ets:' + event.data;
          output.innerHTML = msg;
        }
      }
    }
  })

  // 3. Use h5Port to send messages to the eTS side.
  function PostMsgToEts(data) {
    h5Port.postMessage(data)
  }
  ```

### getUrl<sup>9+</sup>

getUrl(): string

Obtains the URL of this page.

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | URL of the current page.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('getUrl')
          .onClick(() => {
            console.log("url: " + this.controller.getUrl())
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### searchAllAsync<sup>9+</sup>

searchAllAsync(searchString: string): void

Searches the web page for content that matches the keyword specified by **'searchString'** and highlights the matches on the page. This API returns the result asynchronously through [onSearchResultReceive](#onsearchresultreceive9).

**Parameters**

| Name         | Type  | Mandatory  | Default Value | Description   |
| ------------ | ------ | ---- | ---- | ------- |
| searchString | string | Yes   | -    | Search keyword.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State searchString: string = "xxx"

    build() {
      Column() {
        Button('searchString')
          .onClick(() => {
            this.controller.searchAllAsync(this.searchString)
          })
        Button('clearMatches')
          .onClick(() => {
            this.controller.clearMatches()
          })
        Button('searchNext')
          .onClick(() => {
            this.controller.searchNext(true)
          })
        Web({ src: 'www.example.com', controller: this.controller })
     	  .onSearchResultReceive(ret => {
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
              "[total]" + ret.numberOfMatches + "[isDone]"+ ret.isDoneCounting)
          })
      }
    }
  }
  ```

### clearMatches<sup>9+</sup>

clearMatches(): void

Clears the matches found through [searchAllAsync](#searchallasync9).

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearMatches')
          .onClick(() => {
            this.controller.clearMatches()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### searchNext<sup>9+</sup>

searchNext(forward: boolean): void

Searches for and highlights the next match.

**Parameters**

| Name    | Type   | Mandatory  | Default Value | Description       |
| ------- | ------- | ---- | ---- | ----------- |
| forward | boolean | Yes   | -    | Whether to search forward.|


**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('searchNext')
          .onClick(() => {
            this.controller.searchNext(true)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## HitTestValue<sup>9+</sup>
Implements the **HitTestValue** object. For details about the sample code, see [getHitTestValue](#gethittestvalue9).

### getType<sup>9+</sup>
getType(): HitTestType

Obtains the element type of the area being clicked.

**Return value**

| Type                             | Description           |
| ------------------------------- | ------------- |
| [HitTestType](#hittesttype)| Element type of the area being clicked.|

### getExtra<sup>9+</sup>
getExtra(): string

Obtains the extra information of the area being clicked. If the area being clicked is an image or a link, the extra information is the URL of the image or link.

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Extra information of the area being clicked.|


## WebCookie

Manages behavior of cookies in **\<Web>** components. All **\<Web>** components in an application share a **WebCookie**. You can use the **getCookieManager** API in **controller** to obtain the **WebCookie** for subsequent cookie management.

### setCookie<sup>9+</sup>
setCookie(url: string, value: string): boolean

Sets the cookie. This API returns the result synchronously. Returns **true** if the operation is successful; returns **false** otherwise.

**Parameters**

| Name  | Type  | Mandatory  | Default Value | Description             |
| ----- | ------ | ---- | ---- | ----------------- |
| url   | string | Yes   | -    | URL of the cookie to set.|
| value | string | Yes   | -    | Value of the cookie to set.        |

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('setCookie')
          .onClick(() => {
            let result = this.controller.getCookieManager().setCookie("www.example.com", "a=b")
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### saveCookieSync<sup>9+</sup>
saveCookieSync(): boolean

Saves the cookies in the memory to the drive. This API returns the result synchronously.

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Operation result.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('saveCookieSync')
          .onClick(() => {
            let result = this.controller.getCookieManager().saveCookieSync()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getCookie<sup>9+</sup>
getCookie(url: string): string

Obtains the cookie value corresponding to the specified URL.

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description             |
| ---- | ------ | ---- | ---- | ----------------- |
| url  | string | Yes   | -    | URL of the cookie value to obtain.|

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| string | Cookie value corresponding to the specified URL.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('getCookie')
          .onClick(() => {
            let value = webview.WebCookieManager.getCookie('www.example.com')
            console.log("value: " + value)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### setCookie<sup>9+</sup>
setCookie(url: string, value: string): boolean

Sets a cookie value for the specified URL.

**Parameters**

| Name  | Type  | Mandatory  | Default Value | Description             |
| ----- | ------ | ---- | ---- | ----------------- |
| url   | string | Yes   | -    | URL of the cookie to set.|
| value | string | Yes   | -    | Cookie value to set.    |

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('setCookie')
          .onClick(() => {
            let result = web_webview.WebCookieManager.setCookie('www.example.com', 'a=b')
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### saveCookieSync<sup>9+</sup>
saveCookieSync(): boolean

Saves the cookies in the memory to the drive. This API returns the result synchronously.

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Operation result.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('saveCookieSync')
          .onClick(() => {
            let result = web_webview.WebCookieManager.saveCookieSync()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### saveCookieAsync<sup>9+</sup>
saveCookieAsync(): Promise\<boolean>

Saves cookies in the memory to the drive. This API uses a promise to return the value.

**Return value**

| Type               | Description                         |
| ----------------- | --------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('saveCookieAsync')
          .onClick(() => {
            web_webview.WebCookieManager.saveCookieAsync()
              .then (function(result) {
                console.log("result: " + result)
              })
              .catch(function(error) {
                console.error("error: " + error)
              })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### saveCookieAsync<sup>9+</sup>
saveCookieAsync(callback: AsyncCallback\<boolean>): void

Saves cookies in the memory to the drive. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                   | Mandatory  | Default Value | Description                        |
| -------- | ----------------------- | ---- | ---- | ---------------------------- |
| callback | AsyncCallback\<boolean> | Yes   | -    | Callback used to return the operation result.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('saveCookieAsync')
          .onClick(() => {
            web_webview.WebCookieManager.saveCookieAsync(function(result) {
              console.log("result: " + result)
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### isCookieAllowed<sup>9+</sup>
isCookieAllowed(): boolean

Checks whether the **WebCookieManager** instance has the permission to send and receive cookies.

**Return value**

| Type     | Description                 |
| ------- | ------------------- |
| boolean | Whether the **WebCookieManager** instance has the permission to send and receive cookies.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('isCookieAllowed')
          .onClick(() => {
            let result = web_webview.WebCookieManager.isCookieAllowed()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### putAcceptCookieEnabled<sup>9+</sup>
putAcceptCookieEnabled(accept: boolean): void

Sets whether the **WebCookieManager** instance has the permission to send and receive cookies.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description                 |
| ------ | ------- | ---- | ---- | --------------------- |
| accept | boolean | Yes   | -    | Whether the **WebCookieManager** instance has the permission to send and receive cookies.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('putAcceptCookieEnabled')
          .onClick(() => {
            web_webview.WebCookieManager.putAcceptCookieEnabled(false)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### isThirdPartyCookieAllowed<sup>9+</sup>
isThirdCookieAllowed(): boolean

Checks whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.

**Return value**

| Type     | Description                    |
| ------- | ---------------------- |
| boolean | Whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('isThirdPartyCookieAllowed')
          .onClick(() => {
            let result = web_webview.WebCookieManager.isThirdPartyCookieAllowed()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### putAcceptThirdPartyCookieEnabled<sup>9+</sup>
putAcceptThirdPartyCookieEnabled(accept: boolean): void

Sets whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description                    |
| ------ | ------- | ---- | ---- | ------------------------ |
| accept | boolean | Yes   | -    | Whether the **WebCookieManager** instance has the permission to send and receive third-party cookies.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('putAcceptThirdPartyCookieEnabled')
          .onClick(() => {
            web_webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### existCookie<sup>9+</sup>
existCookie(): boolean

Checks whether cookies exist.

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Whether cookies exist.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('existCookie')
          .onClick(() => {
            let result = web_webview.WebCookieManager.existCookie()
            console.log("result: " + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteEntireCookie<sup>9+</sup>
deleteEntireCookie(): void

Deletes all cookies.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('deleteEntireCookie')
          .onClick(() => {
            web_webview.WebCookieManager.deleteEntireCookie()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteSessionCookie<sup>9+</sup>
deleteSessionCookie(): void

Deletes all session cookies.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('deleteSessionCookie')
          .onClick(() => {
            webview.WebCookieManager.deleteSessionCookie()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebDataBase<sup>9+</sup>
Implements the **WebDataBase** object.

### existHttpAuthCredentials<sup>9+</sup>

static existHttpAuthCredentials(): boolean

Checks whether any saved HTTP authentication credentials exist. This API returns the result synchronously. 

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether any saved HTTP authentication credentials exist. Returns **true** if any saved HTTP authentication credentials exist exists; returns **false** otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('existHttpAuthCredentials')
          .onClick(() => {
            let result = web_webview.WebDataBase.existHttpAuthCredentials()
            console.log('result: ' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteHttpAuthCredentials<sup>9+</sup>

static deleteHttpAuthCredentials(): void

Deletes all HTTP authentication credentials saved in the cache. This API returns the result synchronously.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
  
    build() {
      Column() {
        Button('deleteHttpAuthCredentials')
          .onClick(() => {
            web_webview.WebDataBase.deleteHttpAuthCredentials()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getHttpAuthCredentials<sup>9+</sup>

static getHttpAuthCredentials(host: string, realm: string): Array\<string\>

Retrieves HTTP authentication credentials for a given host and domain. This API returns the result synchronously. 

**Parameters**

| Name  | Type  | Mandatory  | Default Value | Description            |
| ----- | ------ | ---- | ---- | ---------------- |
| host  | string | Yes   | -    | Host for which you want to obtain the HTTP authentication credentials.|
| realm | string | Yes   | -    | Realm for which you want to obtain the HTTP authentication credentials. |

**Return value**

| Type             | Description                    |
| --------------- | ---------------------- |
| Array\<string\> | Returns the array of the matching user names and passwords if the operation is successful; returns an empty array otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    host: string = "www.spincast.org"
    realm: string = "protected example"
    username_password: string[]
    build() {
      Column() {
        Button('getHttpAuthCredentials')
          .onClick(() => {
            this.username_password = web_webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm)
            console.log('num: ' + this.username_password.length)
            ForEach(this.username_password, (item) => {
              console.log('username_password: ' + item)
            }, item => item)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### saveHttpAuthCredentials<sup>9+</sup>

static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void

Saves HTTP authentication credentials for a given host and realm. This API returns the result synchronously.

**Parameters**

| Name     | Type  | Mandatory  | Default Value | Description            |
| -------- | ------ | ---- | ---- | ---------------- |
| host     | string | Yes   | -    | Host for which you want to obtain the HTTP authentication credentials.|
| realm    | string | Yes   | -    | Realm to which HTTP authentication credentials apply. |
| username | string | Yes   | -    | User name.            |
| password | string | Yes   | -    | Password.             |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    host: string = "www.spincast.org"
    realm: string = "protected example"
    build() {
      Column() {
        Button('saveHttpAuthCredentials')
          .onClick(() => {
            web_webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche")
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## GeolocationPermissions<sup>9+</sup>

Implements a **GeolocationPermissions** object.

### allowGeolocation<sup>9+</sup>

static allowGeolocation(origin: string): void

Allows the specified origin to use the geolocation information.

**Parameters**

| Name   | Type  | Mandatory  | Default Value | Description      |
| ------ | ------ | ---- | ---- | ---------- |
| origin | string | Yes   | -    | Index of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "file:///"
    build() {
      Column() {
        Button('allowGeolocation')
          .onClick(() => {
            web_webview.GeolocationPermissions.allowGeolocation(this.origin)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteGeolocation<sup>9+</sup>

static deleteGeolocation(origin: string): void

Clears the geolocation permission status of a specified origin.

**Parameters**

| Name   | Type  | Mandatory  | Default Value | Description      |
| ------ | ------ | ---- | ---- | ---------- |
| origin | string | Yes   | -    | Index of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "file:///"
    build() {
      Column() {
        Button('deleteGeolocation')
          .onClick(() => {
            web_webview.GeolocationPermissions.deleteGeolocation(this.origin)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteAllGeolocation<sup>9+</sup>

static deleteAllGeolocation(): void

Clears the geolocation permission status of all sources.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('deleteAllGeolocation')
          .onClick(() => {
            web_webview.GeolocationPermissions.deleteAllGeolocation()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getAccessibleGeolocation<sup>9+</sup>

static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean\>): void

Obtains the geolocation permission status of the specified source. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                    | Mandatory  | Default Value | Description                                    |
| -------- | ------------------------ | ---- | ---- | ---------------------------------------- |
| origin   | string                   | Yes   | -    | Index of the origin.                              |
| callback | AsyncCallback\<boolean\> | Yes   | -    | Callback used to return the geolocation permission status of the specified source. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified source is not found.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "file:///"
    build() {
      Column() {
        Button('getAccessibleGeolocationAsync')
          .onClick(() => {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
              if (error) {
                console.log('getAccessibleGeolocationAsync error: ' + JSON.stringify(error))
                return
              }
              console.log('getAccessibleGeolocationAsync result: ' + result)
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getAccessibleGeolocation<sup>9+</sup>

static getAccessibleGeolocation(origin: string): Promise\<boolean\>

Obtains the geolocation permission status of the specified source. This API uses a promise to return the result.

**Parameters**

| Name   | Type  | Mandatory  | Default Value | Description      |
| ------ | ------ | ---- | ---- | ---------- |
| origin | string | Yes   | -    | Index of the origin.|

**Return value**

| Type                | Description                                      |
| ------------------ | ---------------------------------------- |
| Promise\<boolean\> | Promise used to return the geolocation permission status of the specified source. If the operation is successful, the value **true** means that the geolocation permission is granted, and **false** means the opposite. If the operation fails, the geolocation permission status of the specified source is not found.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "file:///"
    build() {
      Column() {
        Button('getAccessibleGeolocationPromise')
          .onClick(() => {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin).then(result => {
              console.log('getAccessibleGeolocationPromise result: ' + result)
            }).catch(error => {
              console.log('getAccessibleGeolocationPromise error: ' + JSON.stringify(error))
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getStoredGeolocation<sup>9+</sup>

static getStoredGeolocation(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the geolocation permission status of all sources. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                            | Mandatory  | Default Value | Description                |
| -------- | -------------------------------- | ---- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<string\>\> | Yes   | -    | Callback used to return the geolocation permission status of all sources.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('getStoredGeolocationAsync')
          .onClick(() => {
            web_webview.GeolocationPermissions.getStoredGeolocation((error, origins) => {
              if (error) {
                console.log('getStoredGeolocationAsync error: ' + JSON.stringify(error))
                return
              }
              let origins_str: string = origins.join()
              console.log('getStoredGeolocationAsync origins: ' + origins_str)
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getStoredGeolocation<sup>9+</sup>

static getStoredGeolocation(): Promise\<Array\<string\>\>

Obtains the geolocation permission status of all sources. This API uses a promise to return the result.

**Parameters**

| Name     | Type                            | Mandatory  | Default Value | Description                |
| -------- | -------------------------------- | ---- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<string\>\> | Yes   | -    | Callback used to return the geolocation permission status of all sources.|

**Return value**

| Type                        | Description                              |
| -------------------------- | -------------------------------- |
| Promise\<Array\<string\>\> | Promise used to return the geolocation permission status of all sources.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('getStoredGeolocationPromise')
          .onClick(() => {
            web_webview.GeolocationPermissions.getStoredGeolocation().then(origins => {
              let origins_str: string = origins.join()
              console.log('getStoredGeolocationPromise origins: ' + origins_str)
            }).catch(error => {
                console.log('getStoredGeolocationPromise error: ' + JSON.stringify(error))
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebStorage<sup>9+</sup>
Implements the **WebStorage** object, which can be used to manage the Web SQL and the HTML5 Web Storage API. All **\<Web>** components in an application share one **WebStorage**.
### deleteAllData<sup>9+</sup>
static deleteAllData(): void

Deletes all data in the Web SQL Database.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('deleteAllData')
          .onClick(() => {
            web_webview.WebStorage.deleteAllData()
          })
        Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
      }
    }
  }
  ```

### deleteOrigin<sup>9+</sup>
static deleteOrigin(origin : string): void

Deletes all data in the specified origin.

**Parameters**

| Name   | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| origin | string | Yes   | Index of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "origin"
    build() {
      Column() {
        Button('getHttpAuthCredentials')
          .onClick(() => {
            web_webview.WebStorage.deleteOrigin(this.origin)
          })
        Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
      }
    }
  }
  ```

### getOrigins<sup>9+</sup>
static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void

Obtains information about all origins that are currently using the Web SQL Database. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                                    | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<Array<[WebStorageOrigin](#webstorageorigin9)>> | Yes   | Callback used to return the information about the origins. For details, see **WebStorageOrigin**.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "origin"
    build() {
      Column() {
        Button('getOrigins')
          .onClick(() => {
            web_webview.WebStorage.getOrigins((error, origins) => {
              if (error) {
                console.log('error: ' + error)
                return
              }
              for (let i = 0; i < origins.length; i++) {
                console.log('origin: ' + origins[i].origin)
                console.log('usage: ' + origins[i].usage)
                console.log('quota: ' + origins[i].quota)
              }
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
      }
    }
  }
  ```

### getOrigins<sup>9+</sup>
static getOrigins() : Promise\<Array\<WebStorageOrigin>>

Obtains information about all origins that are currently using the Web SQL Database. This API uses a promise to return the result.

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise<Array<[WebStorageOrigin](#webstorageorigin9)>> | Promise used to return the information about the origins. For details, see **WebStorageOrigin**.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "origin"
    build() {
      Column() {
        Button('getOrigins')
          .onClick(() => {
            web_webview.WebStorage.getOrigins()
              .then(origins => {
                for (let i = 0; i < origins.length; i++) {
                  console.log('origin: ' + origins[i].origin)
                  console.log('usage: ' + origins[i].usage)
                  console.log('quota: ' + origins[i].quota)
                }
              })
              .catch(error => {
                console.log('error: ' + error)
              })
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### getOriginQuota<sup>9+</sup>
static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void

Obtains the storage quota of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                  | Mandatory  | Description       |
| -------- | ---------------------- | ---- | --------- |
| origin   | string                 | Yes   | Index of the origin.|
| callback | AsyncCallback\<number> | Yes   | Callback used to return the storage quota of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    origin: string = "origin"
    build() {
      Column() {
        Button('getOriginQuota')
          .onClick(() => {
            web_webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {
              if (error) {
                console.log('error: ' + error)
                return
              }
              console.log('quota: ' + quota)
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### getOriginQuota<sup>9+</sup>
static getOriginQuota(origin : string) : Promise\<number>

Obtains the storage quota of an origin in the Web SQL Database, in bytes. This API uses a promise to return the result.

**Parameters**

| Name   | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| origin | string | Yes   | Index of the origin.|

**Return value**

| Type              | Description                     |
| ---------------- | ----------------------- |
| Promise\<number> | Promise used to return the storage quota of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    origin: string = "origin"
    build() {
      Column() {
        Button('getOriginQuota')
          .onClick(() => {
            web_webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota)
              })
              .catch(error => {
                console.log('error: ' + error)
              })
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### getOriginUsage<sup>9+</sup>
static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void

Obtains the storage usage of an origin in the Web SQL Database, in bytes. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                  | Mandatory  | Description        |
| -------- | ---------------------- | ---- | ---------- |
| origin   | string                 | Yes   | Index of the origin.|
| callback | AsyncCallback\<number> | Yes   | Callback used to return the storage usage of the origin.  |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    origin: string = "origin"
    build() {
      Column() {
        Button('getOriginUsage')
          .onClick(() => {
            web_webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {
              if (error) {
                console.log('error: ' + error)
                return
              }
              console.log('usage: ' + usage)
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### getOriginUsage<sup>9+</sup>
static getOriginUsage(origin : string) : Promise\<number>

Obtains the storage usage of an origin in the Web SQL Database, in bytes. This API uses a promise to return the result.

**Parameters**

| Name   | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| origin | string | Yes   | Index of the origin.|

**Return value**

| Type              | Description                    |
| ---------------- | ---------------------- |
| Promise\<number> | Promise used to return the storage usage of the origin.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    origin: string = "origin"
    build() {
      Column() {
        Button('getOriginQuota')
          .onClick(() => {
            web_webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage)
              })
              .catch(error => {
                console.log('error: ' + error)
              })
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

## WebStorageOrigin<sup>9+</sup>

Provides usage information about the Web SQL Database.

**Parameters**

| Name   | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| origin | string | Yes   | Index of the origin.|
| usage  | number | Yes   | Storage usage of the origin.  |
| quota  | number | Yes   | Storage quota of the origin. |

## MessageLevel

| Name   | Description   |
| ----- | :---- |
| Debug | Debug level.|
| Error | Error level.|
| Info  | Information level.|
| Log   | Log level.|
| Warn  | Warning level. |

## RenderExitReason

Enumerates the reasons why the rendering process exits.

| Name                        | Description               |
| -------------------------- | ----------------- |
| ProcessAbnormalTermination | The rendering process exits abnormally.        |
| ProcessWasKilled           | The rendering process receives a SIGKILL message or is manually terminated.|
| ProcessCrashed             | The rendering process crashes due to segmentation or other errors.   |
| ProcessOom                 | The program memory is running low.          |
| ProcessExitUnknown         | Other reason.            |

## MixedMode

| Name        | Description                                |
| ---------- | ---------------------------------- |
| All        | HTTP and HTTPS hybrid content can be loaded. This means that all insecure content can be loaded.|
| Compatible | HTTP and HTTPS hybrid content can be loaded in compatibility mode. This means that some insecure content may be loaded.          |
| None       | HTTP and HTTPS hybrid content cannot be loaded.              |

## CacheMode
| Name     | Description                                  |
| ------- | ------------------------------------ |
| Default | The cache that has not expired is used to load the resources. If the resources do not exist in the cache, they will be obtained from the Internet.|
| None    | The cache is used to load the resources. If the resources do not exist in the cache, they will be obtained from the Internet.    |
| Online  | The cache is not used to load the resources. All resources are obtained from the Internet.              |
| Only    | The cache alone is used to load the resources.                       |

## FileSelectorMode
| Name                  | Description        |
| -------------------- | ---------- |
| FileOpenMode         | Open and upload a file. |
| FileOpenMultipleMode | Open and upload multiple files. |
| FileOpenFolderMode   | Open and upload a folder.|
| FileSaveMode         | Save a file.   |

 ## HitTestType

| Name           | Description                      |
| ------------- | ------------------------ |
| EditText      | Editable area.                 |
| Email         | Email address.                 |
| HttpAnchor    | Hyperlink whose **src** is **http**.          |
| HttpAnchorImg | Image with a hyperlink, where **src** is **http**.|
| Img           | HTML::img tag.            |
| Map           | Geographical address.                   |
| Phone         | Phone number.                   |
| Unknown       | Unknown content.                   |

## SslError<sup>9+</sup>

Enumerates the error codes returned by **onSslErrorEventReceive** API.

| Name          | Description         |
| ------------ | ----------- |
| Invalid      | Minor error.      |
| HostMismatch | The host name does not match.    |
| DateInvalid  | The certificate has an invalid date.    |
| Untrusted    | The certificate issuer is not trusted.|

## ProtectedResourceType<sup>9+</sup>

| Name       | Description           | Remarks                        |
| --------- | ------------- | -------------------------- |
| MidiSysex | MIDI SYSEX resource.| Currently, only permission events can be reported. MIDI devices are not yet supported.|

## WebAsyncController

Implements the **WebAsyncController** object, which can be used to control the behavior of a **\<Web>** component with asynchronous callbacks. A **WebAsyncController **object controls one **\<Web>** component.

### Creating an Object

```
webController: WebController = new WebController();
webAsyncController: WebAsyncController = new WebAsyncController(webController);
```

### storeWebArchive<sup>9+</sup>

storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback<string>): void

Stores this web page. This API uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                                    | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| baseName | string | Yes| Save path. The value cannot be null.|
| autoName | boolean | Yes| Whether to automatically generate a file name.<br>The value **false** means not to automatically generate a file name.<br>The value **true** means to automatically generate a file name based on the URL of current page and the **baseName** value. In this case, **baseName** is regarded as a directory.|
| callback | AsyncCallback<string> | Yes   | Callback used to return the save path if the operation is successful and null otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        Button('saveWebArchive')
          .onClick(() => {
            let webAsyncController = new web_webview.WebAsyncController(this.controller)
            webAsyncController.storeWebArchive("/data/storage/el2/base/", true, (filename) => {
              if (filename != null) {
                console.info(`save web archive success: ${filename}`)
              }
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### storeWebArchive<sup>9+</sup>

storeWebArchive(baseName: string, autoName: boolean): Promise<string>

Stores this web page. This API uses a promise to return the result.

**Parameters**

| Name     | Type                                    | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| baseName | string | Yes| Save path. The value cannot be null.|
| autoName | boolean | Yes| Whether to automatically generate a file name.<br>The value **false** means not to automatically generate a file name.<br>The value **true** means to automatically generate a file name based on the URL of current page and the **baseName** value. In this case, **baseName** is regarded as a directory.|

**Return value**

| Type             | Description                              |
| --------------- | -------------------------------- |
| Promise<string> | Promise used to return the save path if the operation is successful and null otherwise.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    build() {
      Column() {
        Button('saveWebArchive')
          .onClick(() => {
            let webAsyncController = new web_webview.WebAsyncController(this.controller);
            webAsyncController.storeWebArchive("/data/storage/el2/base/", true)
              .then(filename => {
                if (filename != null) {
                  console.info(`save web archive success: ${filename}`)
                }
              })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebMessagePort<sup>9+</sup>

Implements a **WebMessagePort** instance, which can be used to send and receive messages.

### close<sup>9+</sup>
close(): void

Disables this message port.

### postMessageEvent<sup>9+</sup>
postMessageEvent(message: WebMessageEvent): void

Sends messages. For the complete sample code, see [postMessage](#postmessage9).

**Parameters**

| Name    | Type                                | Mandatory  | Default Value | Description   |
| ------- | ------------------------------------ | ---- | ---- | ------- |
| message | [WebMessageEvent](#webmessageevent9) | Yes   | -    | Message to send.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null

    build() {
      Column() {
        Button('postMessageEvent')
          .onClick(() => {
            var msg = new WebMessageEvent()
            msg.setData("post message from ets to html5")
            this.ports[0].postMessageEvent(msg)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onMessageEvent<sup>9+</sup>
onMessageEvent(callback: (result: string) => void): void

Registers a callback to receive messages from an HTML5 page. For the complete sample code, see [postMessage](#postmessage9).

**Parameters**

| Name     | Type    | Mandatory  | Default Value | Description      |
| -------- | -------- | ---- | ---- | ---------- |
| callback | function | Yes   | -    | Callback for receiving messages.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null

    build() {
      Column() {
        Button('onMessageEvent')
          .onClick(() => {
            this.ports[0].onMessageEvent((result: string) => {
              console.log("received message from html5, on message:" + result);
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```


## WebMessageEvent<sup>9+</sup>

Implements the **WebMessageEvent** object to encapsulate the message and port.

### getData<sup>9+</sup>
getData(): string

Obtains the messages stored in this object.

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | Message stored in the object of this type.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    build() {
      Column() {
        Button('getPorts')
          .onClick(() => {
            var msgEvent = new WebMessageEvent();
            msgEvent.setData("message event data")
            var messageData = msgEvent.getData()
            console.log("message is:" + messageData)
          })
      }
    }
  }
  ```

### setData<sup>9+</sup>
setData(data: string): void

Sets the message in this object. For the complete sample code, see [postMessage](#postmessage9).

**Parameters**

| Name | Type  | Mandatory  | Default Value | Description   |
| ---- | ------ | ---- | ---- | ------- |
| data | string | Yes   | -    | Message to send.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null

    build() {
      Column() {
        Button('setData')
          .onClick(() => {
            var msg = new WebMessageEvent()
            msg.setData("post message from ets to HTML5")
            this.ports[0].postMessageEvent(msg)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```
### getPorts<sup>9+</sup>
getPorts(): Array\<WebMessagePort\>

Obtains the message port stored in this object.

**Return value**

| Type                                      | Description              |
| ---------------------------------------- | ---------------- |
| Array\<[WebMessagePort](#webmessageport9)\> | Message port stored in the object of this type.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    ports: WebMessagePort[] = null
    build() {
      Column() {
        Button('getPorts')
          .onClick(() => {
            var sendPortArray = new Array(this.ports[0])
            var msgEvent = new WebMessageEvent()
            msgEvent.setPorts(sendPortArray)
            var getPorts = msgEvent.getPorts()
            console.log("Ports is:" + getPorts)
          })
      }
    }
  }
  ```

### setPorts<sup>9+</sup>
setPorts(ports: Array\<WebMessagePort\>): void

Sets the message port in this object. For the complete sample code, see [postMessage](#postmessage9).

**Parameters**

| Name  | Type                                    | Mandatory  | Default Value | Description     |
| ----- | ---------------------------------------- | ---- | ---- | --------- |
| ports | Array\<[WebMessagePort](#webmessageport9)\> | Yes   | -    | Message port.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    ports: WebMessagePort[] = null
  
    build() {
      Column() {
        Button('setPorts')
          .onClick(() => {
            var sendPortArray = new Array(this.ports[1])
            var msgEvent = new WebMessageEvent()
            msgEvent.setData("__init_ports__")
            msgEvent.setPorts(sendPortArray)
            this.controller.postMessage({message: msgEvent, uri: "*"})
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```
