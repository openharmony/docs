# Web

The **<Web\>** component can be used to display web pages. It can be used with the [@ohos.web.webview](../apis/js-apis-webview.md) module, which provides APIs for web control.

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

## Required Permissions
To use online resources, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).

## Child Components

Not supported

## APIs

Web(options: { src: ResourceStr, controller: WebviewController | WebController})

> **NOTE**
>
> Transition animation is not supported.
>
> **\<Web>** components on a page must be bound to different **WebviewController**s.

**Parameters**

| Name       | Type                                    | Mandatory  | Description   |
| ---------- | ---------------------------------------- | ---- | ------- |
| src        | [ResourceStr](ts-types.md)               | Yes   | Address of a web page resource. To load a local resource file in the sandbox outside of the application package, use **file://** to specify the path of the sandbox.|
| controller | [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) \| [WebController](#webcontroller) | Yes   | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|

**Example**

  Example of loading online web pages:
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

  Example of loading local resource files in the sandbox:

  1. Use [globalthis](../../application-models/uiability-data-sync-with-ui.md#using-globalthis-between-uiability-and-page) to obtain the path of the sandbox.
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  let url = 'file://' + globalThis.filesDir + '/index.html'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        // Load the files in the sandbox.
        Web({ src: url, controller: this.controller })
      }
    }
  }
  ```

  2. Modify the **EntryAbility.ts** file.

     The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see [Obtaining the Application Development Path](../../application-models/application-context-stage.md#obtaining-the-application-development-path).
     ```ts
     // xxx.ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     import web_webview from '@ohos.web.webview';

     export default class EntryAbility extends UIAbility {
         onCreate(want, launchParam) {
             // Bind filesDir to the globalThis object to implement data synchronization between the UIAbility component and the UI.
             globalThis.filesDir = this.context.filesDir
             console.log("Sandbox path is " + globalThis.filesDir)
         }
     }
     ```

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
    controller: WebviewController | WebController})

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. The parameters cannot be updated.

**Parameters**

| Name       | Type                                    | Mandatory  | Default Value | Description                     |
| ---------- | ---------------------------------------- | ---- | ---- | ------------------------- |
| object     | object                                   | Yes   | -    | Object to be registered. Methods can be declared, but attributes cannot.   |
| name       | string                                   | Yes   | -    | Name of the object to be registered, which is the same as that invoked in the window.|
| methodList | Array\<string\>                          | Yes   | -    | Methods of the JavaScript object to be registered at the application side. |
| controller | [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) \| [WebController](#webcontroller) | Yes   | -    | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|

**Example**

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Sets whether video playback must be started by user gestures. This API is not applicable to videos that do not have an audio track or whose audio track is muted.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description             |
| ------ | ------- | ---- | ---- | ----------------- |
| access | boolean | Yes   | true | Whether video playback must be started by user gestures.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
Enabling the multi-window permission requires implementation of the **onWindowNew** event. For the sample code, see [onWindowNew](#onwindownew9).

**Parameters**

| Name        | Type   | Mandatory  | Default Value  | Description        |
| ----------- | ------- | ---- | ----- | ------------ |
| multiWindow | boolean | Yes   | false | Whether to enable the multi-window permission.|

**Example**

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
        .multiWindowAccess(false)
      }
    }
  }
  ```

### horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

Sets whether to display the horizontal scrollbar, including the default system scrollbar and custom scrollbar. By default, the horizontal scrollbar is displayed.

**Parameters**

| Name        | Type   | Mandatory  | Default Value  | Description        |
| ----------- | ------- | ---- | ----- | ------------ |
| horizontalScrollBar | boolean | Yes   | true | Whether to display the horizontal scrollbar.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .horizontalScrollBarAccess(true)
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

### verticalScrollBarAccess<sup>9+</sup>

verticalScrollBarAccess(verticalScrollBar: boolean)

Sets whether to display the vertical scrollbar, including the default system scrollbar and custom scrollbar. By default, the vertical scrollbar is displayed.

**Parameters**

| Name        | Type   | Mandatory  | Default Value  | Description        |
| ----------- | ------- | ---- | ----- | ------------ |
| verticalScrollBarAccess | boolean | Yes   | true | Whether to display the vertical scrollbar.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .verticalScrollBarAccess(true)
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

### password

password(password: boolean)

Sets whether the password should be saved. This API is a void API.

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: CacheMode = CacheMode.None
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .cacheMode(this.mode)
      }
    }
  }
  ```

### textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

Sets the text zoom ratio of the page. The default value is **100**, which indicates 100%.

This API is deprecated since API version 9. You are advised to use [textZoomRatio<sup>9+</sup>](#textzoomratio9) instead.

**Parameters**

| Name          | Type  | Mandatory  | Default Value | Description           |
| ------------- | ------ | ---- | ---- | --------------- |
| textZoomAtio | number | Yes   | 100  | Text zoom ratio to set.|

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
          .textZoomAtio(this.atio)
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State userAgent:string = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36'
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .userAgent(this.userAgent)
      }
    }
  }
  ```

### blockNetwork<sup>9+</sup>

blockNetwork(block: boolean)

Sets whether to block online downloads.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                           |
| ------ | -------- | ---- | ------ | ----------------------------------- |
| block  | boolean  | Yes  | false  | Whether to block online downloads.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State block: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .blockNetwork(this.block)
      }
    }
  }
  ```

### defaultFixedFontSize<sup>9+</sup>

defaultFixedFontSize(size: number)

Sets the default fixed font size for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                    |
| ------ | -------- | ---- | ------ | ---------------------------- |
| size   | number   | Yes  | 13     | Default fixed font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 16
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFixedFontSize(this.fontSize)
      }
    }
  }
  ```

### defaultFontSize<sup>9+</sup>

defaultFontSize(size: number)

Sets the default font size for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | Yes  | 16     | Default font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFontSize(this.fontSize)
      }
    }
  }
  ```

### minFontSize<sup>9+</sup>

minFontSize(size: number)

Sets the minimum font size for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | Yes  | 8      | Minimum font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minFontSize(this.fontSize)
      }
    }
  }
  ```

### minLogicalFontSize<sup>9+</sup>

minLogicalFontSize(size: number)

Sets the minimum logical font size for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | Yes  | 8      | Minimum logical font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minLogicalFontSize(this.fontSize)
      }
    }
  }
  ```


### webFixedFont<sup>9+</sup>

webFixedFont(family: string)

Sets the fixed font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value   | Description                    |
| ------ | -------- | ---- | --------- | ---------------------------- |
| family | string   | Yes  | monospace | Fixed font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "monospace"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFixedFont(this.family)
      }
    }
  }
  ```

### webSansSerifFont<sup>9+</sup>

webSansSerifFont(family: string)

Sets the sans serif font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value    | Description                         |
| ------ | -------- | ---- | ---------- | --------------------------------- |
| family | string   | Yes  | sans-serif | Sans serif font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "sans-serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSansSerifFont(this.family)
      }
    }
  }
  ```

### webSerifFont<sup>9+</sup>

webSerifFont(family: string)

Sets the serif font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                    |
| ------ | -------- | ---- | ------ | ---------------------------- |
| family | string   | Yes  | serif  | Serif font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSerifFont(this.family)
      }
    }
  }
  ```

### webStandardFont<sup>9+</sup>

webStandardFont(family: string)

Sets the standard font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value    | Description                       |
| ------ | -------- | ---- | ---------- | ------------------------------- |
| family | string   | Yes  | sans serif | Standard font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "sans-serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webStandardFont(this.family)
      }
    }
  }
  ```

### webFantasyFont<sup>9+</sup>

webFantasyFont(family: string)

Sets the fantasy font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value | Description                      |
| ------ | -------- | ---- | ------- | ------------------------------ |
| family | string   | Yes  | fantasy | Fantasy font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "fantasy"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFantasyFont(this.family)
      }
    }
  }
  ```

### webCursiveFont<sup>9+</sup>

webCursiveFont(family: string)

Sets the cursive font family for the web page.

**Parameters**

| Name| Type| Mandatory| Default Value | Description                      |
| ------ | -------- | ---- | ------- | ------------------------------ |
| family | string   | Yes  | cursive | Cursive font family to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "cursive"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webCursiveFont(this.family)
      }
    }
  }
  ```

### darkMode<sup>9+</sup>

darkMode(mode: WebDarkMode)

Sets the web dark mode. By default, web dark mode is disabled. When it is enabled, the **\<Web>** component enables the dark theme defined for web pages if the theme has been defined in **prefer-color-scheme** of a media query, and remains unchanged otherwise. To enable the forcible dark mode, use this API with [forceDarkAccess](#forcedarkaccess9).

**Parameters**

| Name| Type| Mandatory| Default Value | Description                      |
| ------ | ----------- | ---- | --------------- | ------------------ |
|  mode  | [WebDarkMode](#webdarkmode9) | Yes  | WebDarkMode.Off | Web dark mode to set.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: WebDarkMode = WebDarkMode.On
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
      }
    }
  }
  ```

### forceDarkAccess<sup>9+</sup>

forceDarkAccess(access: boolean)

Sets whether to enable forcible dark mode for the web page. By default, this feature is turned off. This API is applicable only when dark mode is enabled in [darkMode](#darkmode9).

**Parameters**

| Name| Type| Mandatory| Default Value | Description                      |
| ------ | ------- | ---- | ----- | ------------------ |
| access | boolean | Yes  | false | Whether to enable forcible dark mode for the web page.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: WebDarkMode = WebDarkMode.On
    @State access: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
          .forceDarkAccess(this.access)
      }
    }
  }
  ```

### tableData

tableData(tableData: boolean)

Sets whether form data should be saved. This API is a void API.

### wideViewModeAccess

wideViewModeAccess(wideViewModeAccess: boolean)

Sets whether to support the viewport attribute of the HTML **\<meta>** tag. This API is a void API.

### pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

Sets whether to enable smooth pinch mode for the web page.

**Parameters**

| Name   | Type| Mandatory| Default Value| Description                  |
| --------- | -------- | ---- | ------ | -------------------------- |
| isEnabled | boolean  | Yes  | false  | Whether to enable smooth pinch mode for the web page.|

**Example**

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
        .pinchSmooth(true)
    }
  }
}
  ```


## Events

The universal events are not supported.

### onAlert

onAlert(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Called when **alert()** is invoked to display an alert dialog box on the web page.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | User operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **true**, the application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **\<Web>** component to exit the current page based on the user operation. If the callback returns **false**, the **\<Web>** component cannot trigger the system dialog box.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onAlert((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
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

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body>
    <h1>WebView onAlert Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <script>
      function myFunction() {
        alert("Hello World");
      }
    </script>
  </body>
  </html>
  ```

### onBeforeUnload

onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Called when this page is about to exit after the user refreshes or closes the page. This API takes effect only when the page has obtained focus.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | User operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **true**, the application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **\<Web>** component to exit the current page based on the user operation. If the callback returns **false**, the **\<Web>** component cannot trigger the system dialog box.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
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

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body onbeforeunload="return myFunction()">
    <h1>WebView onBeforeUnload Demo</h1>
    <a href="https://www.example.com">Click here</a>
    <script>
      function myFunction() {
        return "onBeforeUnload Event";
      }
    </script>
  </body>
  </html>
  ```

### onConfirm

onConfirm(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

Called when **confirm()** is invoked by the web page.

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | User operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **true**, the application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **\<Web>** component to exit the current page based on the user operation. If the callback returns **false**, the **\<Web>** component cannot trigger the system dialog box.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onConfirm((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
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

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onConfirm Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let x;
        let r = confirm("click button!");
        if (r == true) {
          x = "ok";
        } else {
          x = "cancel";
        }
        document.getElementById("demo").innerHTML = x;
      }
    </script>
  </body>
  </html>
  ```

### onPrompt<sup>9+</sup>

onPrompt(callback: (event?: { url: string; message: string; value: string; result: JsResult }) => boolean)

**Parameters**

| Name    | Type                 | Description           |
| ------- | --------------------- | --------------- |
| url     | string                | URL of the web page where the dialog box is displayed.|
| message | string                | Message displayed in the dialog box.      |
| result  | [JsResult](#jsresult) | User operation. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | If the callback returns **true**, the application can use the system dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **\<Web>** component to exit the current page based on the user operation. If the callback returns **false**, the **\<Web>** component cannot trigger the system dialog box.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
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
                  event.result.handlePromptConfirm(event.value)
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

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onPrompt Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let message = prompt("Message info", "Hello World");
        if (message != null && message != "") {
          document.getElementById("demo").innerHTML = message;
        }
      }
    </script>
  </body>
  </html>
  ```

### onConsole

onConsole(callback: (event?: { message: ConsoleMessage }) => boolean)

Called to notify the host application of a JavaScript console message.

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

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

Instructs the main application to start downloading a file.

**Parameters**

| Name               | Type         | Description                               |
| ------------------ | ------------- | ----------------------------------- |
| url                | string        | URL for the download task.                          |
| userAgent          | string        | User agent used for download.                          |
| contentDisposition | string        | Content-Disposition response header returned by the server, which may be empty.|
| mimetype           | string        | MIME type of the content returned by the server.               |
| contentLength      | contentLength | Length of the content returned by the server.                        |

**Example**

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

Called when an error occurs during web page loading. For better results, simplify the implementation logic in the callback. This API is called when there is no network connection.

**Parameters**

| Name    | Type                                    | Description           |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | Encapsulation of a web page request.     |
| error   | [WebResourceError](#webresourceerror)    | Encapsulation of a web page resource loading error.|

**Example**

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

Called when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.

**Parameters**

| Name    | Type                                    | Description           |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | Encapsulation of a web page request.     |
| response | [WebResourceResponse](#webresourceresponse)    | Encapsulation of a resource response.|

**Example**

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


Called when the web page starts to be loaded. This API is called only for the main frame content, and not for the iframe or frameset content.

**Parameters**

| Name | Type  | Description     |
| ---- | ------ | --------- |
| url  | string | URL of the page.|

**Example**

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
          .onPageBegin((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onPageEnd

onPageEnd(callback: (event?: { url: string }) => void)


Called when the web page loading is complete. This API takes effect only for the main frame content.

**Parameters**

| Name | Type  | Description     |
| ---- | ------ | --------- |
| url  | string | URL of the page.|

**Example**

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
          .onPageEnd((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onProgressChange

onProgressChange(callback: (event?: { newProgress: number }) => void)

Called when the web page loading progress changes.

**Parameters**

| Name        | Type  | Description                 |
| ----------- | ------ | --------------------- |
| newProgress | number | New loading progress. The value is an integer ranging from 0 to 100.|

**Example**

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
          .onProgressChange((event) => {
            console.log('newProgress:' + event.newProgress)
          })
      }
    }
  }
  ```

### onTitleReceive

onTitleReceive(callback: (event?: { title: string }) => void)

Called when the document title of the web page is changed.

**Parameters**

| Name  | Type  | Description         |
| ----- | ------ | ------------- |
| title | string | Document title.|

**Example**

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
          .onTitleReceive((event) => {
            console.log('title:' + event.title)
          })
      }
    }
  }
  ```

### onRefreshAccessedHistory

onRefreshAccessedHistory(callback: (event?: { url: string, isRefreshed: boolean }) => void)

Called when loading of the web page is complete. This API is used by an application to update the historical link it accessed.

**Parameters**

| Name        | Type   | Description                                    |
| ----------- | ------- | ---------------------------------------- |
| url         | string  | URL to be accessed.                                 |
| isRefreshed | boolean | Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh<sup>9+</sup>](../apis/js-apis-webview.md#refresh) API, and **false** means the opposite.|

**Example**

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
          .onRefreshAccessedHistory((event) => {
            console.log('url:' + event.url + ' isReload:' + event.isRefreshed)
          })
      }
    }
  }
  ```

### onSslErrorReceive<sup>(deprecated)</sup>

onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void)

Called when an SSL error occurs during resource loading.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [onSslErrorEventReceive<sup>9+</sup>](#onsslerroreventreceive9) instead.

### onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

Called to process an HTML form whose input type is **file**, in response to the tapping of the **Select File** button.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [onShowFileSelector<sup>9+</sup>](#onshowfileselector9) instead.

### onRenderExited<sup>9+</sup>

onRenderExited(callback: (event?: { renderExitReason: RenderExitReason }) => void)

Called when the rendering process exits abnormally.

**Parameters**

| Name             | Type                                    | Description            |
| ---------------- | ---------------------------------------- | ---------------- |
| renderExitReason | [RenderExitReason](#renderexitreason)| Cause for the abnormal exit of the rendering process.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

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

Called to process an HTML form whose input type is **file**, in response to the tapping of the **Select File** button.

**Parameters**

| Name         | Type                                    | Description             |
| ------------ | ---------------------------------------- | ----------------- |
| result       | [FileSelectorResult](#fileselectorresult9) | File selection result to be sent to the **\<Web>** component.|
| fileSelector | [FileSelectorParam](#fileselectorparam9) | Information about the file selector.      |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** means that the pop-up window provided by the system is displayed. If the callback returns **false**, the **\<Web>** component cannot trigger the system dialog box.|

**Example**

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

Called to notify the **\<Web>** component of the URL of the loaded resource file.

**Parameters**

| Name | Type  | Description          |
| ---- | ------ | -------------- |
| url  | string | URL of the loaded resource file.|

**Example**

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
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url)
          })
      }
    }
  }
  ```

### onScaleChange<sup>9+</sup>

onScaleChange(callback: (event: {oldScale: number, newScale: number}) => void)

Called when the display ratio of this page changes.

**Parameters**

| Name     | Type  | Description        |
| -------- | ------ | ------------ |
| oldScale | number | Display ratio of the page before the change.|
| newScale | number | Display ratio of the page after the change.|

**Example**

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
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale)
          })
      }
    }
  }
  ```

### onUrlLoadIntercept

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

Called when the **\<Web>** component is about to access a URL. This API is used to determine whether to block the access, which is allowed by default.

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

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

Called when the **\<Web>** component is about to access a URL. This API is used to block the URL and return the response data.

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when an HTTP authentication request is received.

**Parameters**

| Name    | Type                                | Description            |
| ------- | ------------------------------------ | ---------------- |
| handler | [HttpAuthHandler](#httpauthhandler9) | User operation.  |
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
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when an SSL error occurs during resource loading.

**Parameters**

| Name    | Type                                | Description          |
| ------- | ------------------------------------ | -------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | User operation.|
| error   | [SslError](#sslerror9)          | Error code.          |

**Example**

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

Called when an SSL client certificate request is received.

**Parameters**

| Name     | Type                                    | Description           |
| -------- | ---------------------------------------- | --------------- |
| handler  | [ClientAuthenticationHandler](#clientauthenticationhandler9) | User operation. |
| host     | string                                   | Host name of the server that requests a certificate.   |
| port     | number                                   | Port number of the server that requests a certificate.   |
| keyTypes | Array<string>                            | Acceptable asymmetric private key types.   |
| issuers  | Array<string>                            | Issuer of the certificate that matches the private key.|

  **Example**
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

Called when a permission request is received.

**Parameters**

| Name    | Type                                    | Description          |
| ------- | ---------------------------------------- | -------------- |
| request | [PermissionRequest](#permissionrequest9) | User operation.|

**Example**

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

Called when a context menu is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link.

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
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when the scrollbar of the page scrolls.

**Parameters**

| Name    | Type  | Description        |
| ------- | ------ | ------------ |
| xOffset | number | Position of the scrollbar on the x-axis relative to the leftmost of the web page.|
| yOffset | number | Position of the scrollbar on the y-axis relative to the top of the web page.|

**Example**

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

Called when a request to obtain the geolocation information is received.

**Parameters**

| Name        | Type                           | Description          |
| ----------- | ------------------------------- | -------------- |
| origin      | string                          | Index of the origin.    |
| geolocation | [JsGeolocation](#jsgeolocation) | User operation.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called to notify the user that the request for obtaining the geolocation information received when **[onGeolocationShow](#ongeolocationshow)** is called has been canceled.

**Parameters**

| Name     | Type      | Description                |
| -------- | ---------- | -------------------- |
| callback | () => void | Callback invoked when the request for obtaining geolocation information has been canceled. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when the component enters full screen mode.

**Parameters**

| Name    | Type                                    | Description          |
| ------- | ---------------------------------------- | -------------- |
| handler | [FullScreenExitHandler](#fullscreenexithandler9) | Function handle for exiting full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when the component exits full screen mode.

**Parameters**

| Name     | Type      | Description         |
| -------- | ---------- | ------------- |
| callback | () => void | Callback invoked when the component exits full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called when a new window is created. This API takes effect when **multiWindowAccess** is enabled.
If the **event.handler.setWebController** API is not called, the render process will be blocked.
If opening a new window is not needed, set the parameter to **null** when calling the **event.handler.setWebController** API.

**Parameters**

| Name          | Type                                    | Description                      |
| ------------- | ---------------------------------------- | -------------------------- |
| isAlert       | boolean                                  | Whether to open the target URL in a new window. The value **true** means to open the target URL in a new window, and **false** means to open the target URL in a new tab.|
| isUserTrigger | boolean                                  | Whether the creation is triggered by the user. The value **true** means that the creation is triggered by the user, and **false** means the opposite.  |
| targetUrl     | string                                   | Target URL.                    |
| handler       | [ControllerHandler](#controllerhandler9) | **WebviewController** instance for setting the new window. |

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  
  // There are two <Web> components on the same page. When the WebComponent object opens a new window, the NewWebViewComp object is displayed. 
  @CustomDialog
  struct NewWebViewComp {
  controller: CustomDialogController
  webviewController1: web_webview.WebviewController
  build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(()=> {
            console.info("NewWebViewComp onWindowExit")
            this.controller.close()
          })
        }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    dialogController: CustomDialogController = null
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          // MultiWindowAccess needs to be enabled.
          .multiWindowAccess(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController:web_webview.WebviewController = new web_webview.WebviewController()
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({webviewController1: popController})
            })
            this.dialogController.open()
            // Return the WebviewController object corresponding to the new window to the <Web> kernel.
            // If opening a new window is not needed, set the parameter to null when calling the event.handler.setWebController API.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            event.handler.setWebController(popController)
          })
      }
    }
  }
  ```

### onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

Called when this window is closed.

**Parameters**

| Name     | Type      | Description        |
| -------- | ---------- | ------------ |
| callback | () => void | Callback invoked when the window is closed.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
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

Called to notify the caller of the search result on the web page.

**Parameters**

| Name               | Type   | Description                                    |
| ------------------ | ------- | ---------------------------------------- |
| activeMatchOrdinal | number  | Sequence number of the current match, which starts from 0.                      |
| numberOfMatches    | number  | Total number of matches.                           |
| isDoneCounting     | boolean | Whether the search operation on the current page is complete. This API may be called multiple times until **isDoneCounting** is **true**.|

**Example**

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
     	  .onSearchResultReceive(ret => {
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
              "[total]" + ret.numberOfMatches + "[isDone]"+ ret.isDoneCounting)
          })
      }
    }
  }
  ```

### onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: (event: {handler: DataResubmissionHandler}) => void)

Called when the web form data is resubmitted.

**Parameters**

| Name | Type                                            | Description              |
| ------- | ---------------------------------------------------- | ---------------------- |
| handler | [DataResubmissionHandler](#dataresubmissionhandler9) | Handler for resubmitting web form data.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.resend();
        })
      }
    }
  }
  ```

### onPageVisible<sup>9+</sup>

onPageVisible(callback: (event: {url: string}) => void)

Called when the old page is not displayed and the new page is about to be visible.

**Parameters**

| Name| Type| Description                                         |
| ------ | -------- | ------------------------------------------------- |
| url    | string   | URL of the new page that is able to be visible when the old page is not displayed.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onPageVisible((event) => {
          console.log('onPageVisible url:' + event.url)
        })
      }
    }
  }
  ```

### onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

Called when the key event is intercepted and before it is consumed by the webview.

**Parameters**

| Name| Type                                               | Description            |
| ------ | ------------------------------------------------------- | -------------------- |
| event  | [KeyEvent](ts-universal-events-key.md#keyevent) | Key event that is triggered.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether to continue to transfer the key event to the webview kernel.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onInterceptKeyEvent((event) => {
          if (event.keyCode == 2017 || event.keyCode == 2018) {
            console.info(`onInterceptKeyEvent get event.keyCode ${event.keyCode}`)
            return true;
          }
          return false;
        })
      }
    }
  }
  ```

### onTouchIconUrlReceived<sup>9+</sup>

onTouchIconUrlReceived(callback: (event: {url: string, precomposed: boolean}) => void)

Called when an apple-touch-icon URL is received.

**Parameters**

| Name     | Type| Description                          |
| ----------- | -------- | ---------------------------------- |
| url         | string   | Received apple-touch-icon URL.|
| precomposed | boolean  | Whether the apple-touch-icon is precomposed.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.baidu.com', controller: this.controller })
         .onTouchIconUrlReceived((event) => {
          console.log('onTouchIconUrlReceived:' + JSON.stringify(event))
        })
      }
    }
  }
  ```

### onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: (event: {favicon: image.PixelMap}) => void)

Called when this web page receives a new favicon.

**Parameters**

| Name | Type                                      | Description                           |
| ------- | ---------------------------------------------- | ----------------------------------- |
| favicon | [PixelMap](../apis/js-apis-image.md#pixelmap7) | **PixelMap** object of the received favicon.|

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  import image from "@ohos.multimedia.image"
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State icon: image.PixelMap = undefined;
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onFaviconReceived((event) => {
          console.log('onFaviconReceived');
          this.icon = event.favicon;
        })
      }
    }
  }
  ```

### onRequestSelected

onRequestSelected(callback: () => void)

Called when the **\<Web>** component obtains the focus.

**Example**

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
          .onRequestSelected(() => {
            console.log('onRequestSelected')
          })
      }
    }
  }
  ```

## ConsoleMessage

Implements the **ConsoleMessage** object. For the sample code, see [onConsole](#onconsole).

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

Implements the **JsResult** object, which indicates the result returned to the **\<Web>** component to indicate the user operation performed in the dialog box. For the sample code, see [onAlert](#onalert).

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

Implements a **WebviewController** object for new **\<Web>** components. For the sample code, see [onWindowNew](#onwindownew9).

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

Sets a **WebviewController** object. If opening a new window is not needed, set the parameter to **null**.

**Parameters**

| Name       | Type         | Mandatory  | Default Value | Description                     |
| ---------- | ------------- | ---- | ---- | ------------------------- |
| controller | [WebviewController](../apis/js-apis-webview.md#webviewcontroller) | Yes   | -    | **WebviewController** object of the **\<Web>** component. If opening a new window is not needed, set it to **null**.|

## WebResourceError

Implements the **WebResourceError** object. For the sample code, see [onErrorReceive](#onerrorreceive).

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

Implements the **WebResourceRequest** object. For the sample code, see [onErrorReceive](#onerrorreceive).

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

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

Obtains the request method.

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| string | Request method.|

## Header

Describes the request/response header returned by the **\<Web>** component.

| Name         | Type    | Description           |
| ----------- | ------ | ------------- |
| headerKey   | string | Key of the request/response header.  |
| headerValue | string | Value of the request/response header.|


## WebResourceResponse

Implements the **WebResourceResponse** object. For the sample code, see [onHttpErrorReceive](#onhttperrorreceive).

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

setResponseData(data: string | number)

Sets the data in the resource response.

**Parameters**

| Name| Type        | Mandatory| Default Value| Description                                                    |
| ------ | ---------------- | ---- | ------ | ------------------------------------------------------------ |
| data   | string \| number | Yes  | -      | Resource response data to set. When set to a number, the value indicates a file handle.|

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

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean)

Sets whether the resource response data is ready.

**Parameters**

| Name | Type| Mandatory| Default Value| Description                  |
| ------- | -------- | ---- | ------ | -------------------------- |
| IsReady | boolean  | Yes  | true   | Whether the resource response data is ready.|

## FileSelectorResult<sup>9+</sup>

Notifies the **\<Web>** component of the file selection result. For the sample code, see [onShowFileSelector](#onshowfileselector9).

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

Instructs the **\<Web>** component to select a file.

**Parameters**

| Name     | Type           | Mandatory  | Default Value | Description        |
| -------- | --------------- | ---- | ---- | ------------ |
| fileList | Array\<string\> | Yes   | -    | List of files to operate.|

## FileSelectorParam<sup>9+</sup>

Implements the **FileSelectorParam** object. For the sample code, see [onShowFileSelector](#onshowfileselector9).

### getTitle<sup>9+</sup>

getTitle(): string

Obtains the title of this file selector.

**Return value**

| Type    | Description      |
| ------ | -------- |
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

Implements the **HttpAuthHandler** object. For the sample code, see [onHttpAuthRequest](#onhttpauthrequest9).

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

Uses the account name and password cached on the server for authentication.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

## SslErrorHandler<sup>9+</sup>

Implements an **SslErrorHandler** object. For the sample code, see [onSslErrorEventReceive Event](#onsslerroreventreceive9).

### handleCancel<sup>9+</sup>

handleCancel(): void

Cancels this request.

### handleConfirm<sup>9+</sup>

handleConfirm(): void

Continues using the SSL certificate.

## ClientAuthenticationHandler<sup>9+</sup>

Implements a **ClientAuthenticationHandler** object returned by the **\<Web>** component. For the sample code, see [onClientAuthenticationRequest](#onclientauthenticationrequest9).

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

Implements the **PermissionRequest** object. For the sample code, see [onPermissionRequest](#onpermissionrequest9).

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
| resources | Array\<string\> | Yes   | -    | List of resources that can be requested by the web page with the permission to grant.|

## ContextMenuSourceType<sup>9+</sup>
| Name                  | Description        |
| -------------------- | ---------- |
| None        | Other event sources. |
| Mouse       | Mouse event. |
| LongPress   | Long press event. |

## ContextMenuMediaType<sup>9+</sup>

| Name          | Description         |
| ------------ | ----------- |
| None      | Non-special media or other media types.|
| Image     | Image.    |

## ContextMenuInputFieldType<sup>9+</sup>

| Name          | Description         |
| ------------ | ----------- |
| None      | Non-input field.      |
| PlainText | Plain text field, such as the text, search, or email field.  |
| Password  | Password field.    |
| Number    | Numeric field.    |
| Telephone | Phone number field.|
| Other     | Field of any other type.    |

## ContextMenuEditStateFlags<sup>9+</sup>

| Name        | Description        |
| ------------ | ----------- |
| NONE         | Editing is not allowed.  |
| CAN_CUT      | The cut operation is allowed.  |
| CAN_COPY     | The copy operation is allowed.  |
| CAN_PASTE    | The paste operation is allowed.  |
| CAN_SELECT_ALL  | The select all operation is allowed.|

## WebContextMenuParam<sup>9+</sup>

Implements a context menu, which is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link. For the sample code, see [onContextMenuShow](#oncontextmenushow9).

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

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

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

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

Obtains the media type of this web page element.

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [ContextMenuMediaType](#contextmenumediatype9) | Media type of the web page element.|

### getSelectionText<sup>9+</sup>

getSelectionText(): string

Obtains the selected text.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| string | Selected text for the context menu. If no text is selected, null is returned.|

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

Obtains the event source of the context menu.

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [ContextMenuSourceType](#contextmenusourcetype9) | Event source of the context menu.|

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

Obtains the input field type of this web page element.

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [ContextMenuInputFieldType](#contextmenuinputfieldtype9) | Input field type.|

### isEditable<sup>9+</sup>

isEditable(): boolean

Checks whether this web page element is editable.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the web page element is editable; returns **false** otherwise.|

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

Obtains the edit state flag of this web page element.

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| number | Edit state flag of the web page element. For details, see [ContextMenuEditStateFlags](#contextmenueditstateflags9).|

## WebContextMenuResult<sup>9+</sup>

Implements a **WebContextMenuResult** object. For the sample code, see [onContextMenuShow](#oncontextmenushow9).

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

Closes this context menu. This API must be called when no operations in **WebContextMenuResult** are performed.

### copyImage<sup>9+</sup>

copyImage(): void

Copies the image specified in **WebContextMenuParam**.

### copy<sup>9+</sup>

copy(): void

Performs the copy operation related to this context menu.

### paste<sup>9+</sup>

paste(): void

Performs the paste operation related to this context menu.

### cut<sup>9+</sup>

cut(): void

Performs the cut operation related to this context menu.

### selectAll<sup>9+</sup>

selectAll(): void

Performs the select all operation related to this context menu.

## JsGeolocation

Implements the **PermissionRequest** object. For the sample code, see [onGeolocationShow Event](#ongeolocationshow).

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

Sets the geolocation permission status of a web page.

**Parameters**

| Name   | Type   | Mandatory  | Default Value | Description                                    |
| ------ | ------- | ---- | ---- | ---------------------------------------- |
| origin | string  | Yes   | -    | Index of the origin.                              |
| allow  | boolean | Yes   | -    | Geolocation permission status.                            |
| retain | boolean | Yes   | -    | Whether the geolocation permission status can be saved to the system. You can manage the geolocation permissions saved to the system through [GeolocationPermissions<sup>9+</sup>](../apis/js-apis-webview.md#geolocationpermissions).|

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

## WebDarkMode<sup>9+</sup>
| Name     | Description                                  |
| ------- | ------------------------------------ |
| Off     | The web dark mode is disabled.                    |
| On      | The web dark mode is enabled.                    |
| Auto    | The web dark mode setting follows the system settings.                |

## DataResubmissionHandler<sup>9+</sup>

Implements the **DataResubmissionHandler** object for resubmitting or canceling the web form data.

### resend<sup>9+</sup>

resend(): void

Resends the web form data.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.resend();
        })
      }
    }
  }
  ```

### cancel<sup>9+</sup>

cancel(): void

Cancels the resending of web form data.

**Example**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.cancel();
        })
      }
    }
  }
  ```

  ## WebController

Implements a **WebController** to control the behavior of the **\<Web>** component. A **WebController** can control only one **\<Web>** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **\<Web>** component.

This API is deprecated since API version 9. You are advised to use [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) instead.

### Creating an Object

```
webController: WebController = new WebController()
```

### getCookieManager<sup>9+</sup>

getCookieManager(): WebCookie

Obtains the cookie management object of the **\<Web>** component.

**Return value**

| Type       | Description                                      |
| --------- | ---------------------------------------- |
| WebCookie | Cookie management object. For details, see [WebCookie](#webcookiedeprecated).|

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

### requestFocus<sup>(deprecated)</sup>

requestFocus()

Requests focus for this web page.

This API is deprecated since API version 9. You are advised to use [requestFocus<sup>9+</sup>](../apis/js-apis-webview.md#requestfocus) instead.

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

### accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessBackward<sup>9+</sup>](../apis/js-apis-webview.md#accessbackward) instead.

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

### accessForward<sup>(deprecated)</sup>

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessForward<sup>9+</sup>](../apis/js-apis-webview.md#accessforward) instead.

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

### accessStep<sup>(deprecated)</sup>

accessStep(step: number): boolean

Performs a specific number of steps forward or backward from the current page.

This API is deprecated since API version 9. You are advised to use [accessStep<sup>9+</sup>](../apis/js-apis-webview.md#accessstep) instead.

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

### backward<sup>(deprecated)</sup>

backward(): void

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

This API is deprecated since API version 9. You are advised to use [backward<sup>9+</sup>](../apis/js-apis-webview.md#backward) instead.

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

### forward<sup>(deprecated)</sup>

forward(): void

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

This API is deprecated since API version 9. You are advised to use [forward<sup>9+</sup>](../apis/js-apis-webview.md#forward) instead.

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

### deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately, with no need for invoking the[refresh](#refreshdeprecated) API.

This API is deprecated since API version 9. You are advised to use [deleteJavaScriptRegister<sup>9+</sup>](../apis/js-apis-webview.md#deletejavascriptregister) instead.

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

### getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

Obtains the element type of the area being clicked.

This API is deprecated since API version 9. You are advised to use [getHitTest<sup>9+</sup>](../apis/js-apis-webview.md#gethittest) instead.

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

### loadData<sup>(deprecated)</sup>

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

Loads data. If **baseUrl** is empty, the specified character string will be loaded using the data protocol.

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **\<Web>** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **\<Web>** component as a non-encoded string in a manner similar to **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadData<sup>9+</sup>](../apis/js-apis-webview.md#loaddata) instead.

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

### loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

The object injected through **registerJavaScriptProxy** is still valid on a new page redirected through **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadUrl<sup>9+</sup>](../apis/js-apis-webview.md#loadurl) instead.

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

### onActive<sup>(deprecated)</sup>

onActive(): void

Called when the **\<Web>** component enters the active state.

This API is deprecated since API version 9. You are advised to use [onActive<sup>9+</sup>](../apis/js-apis-webview.md#onactive) instead.

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

### onInactive<sup>(deprecated)</sup>

onInactive(): void

Called when the **\<Web>** component enters the inactive state.

This API is deprecated since API version 9. You are advised to use [onInactive<sup>9+</sup>](../apis/js-apis-webview.md#oninactive) instead.

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

### zoom<sup>(deprecated)</sup>
zoom(factor: number): void

Sets a zoom factor for the current web page.

This API is deprecated since API version 9. You are advised to use [zoom<sup>9+</sup>](../apis/js-apis-webview.md#zoom) instead.

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

### refresh<sup>(deprecated)</sup>

refresh()

Called when the **\<Web>** component refreshes the web page.

This API is deprecated since API version 9. You are advised to use [refresh<sup>9+</sup>](../apis/js-apis-webview.md#refresh) instead.

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

### registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. You must invoke the [refresh](#refreshdeprecated) API for the registration to take effect.

This API is deprecated since API version 9. You are advised to use [registerJavaScriptProxy<sup>9+</sup>](../apis/js-apis-webview.md#registerjavascriptproxy) instead.

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
      function htmlTest() {
          str = objName.test("test function")
          console.log('objName.test result:'+ str)
      }
  </script>
  </html>

  ```

### runJavaScript<sup>(deprecated)</sup>

runJavaScript(options: { script: string, callback?: (result: string) => void })

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

This API is deprecated since API version 9. You are advised to use [runJavaScript<sup>9+</sup>](../apis/js-apis-webview.md#runjavascript) instead.

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

### stop<sup>(deprecated)</sup>

stop()

Stops page loading.

This API is deprecated since API version 9. You are advised to use [stop<sup>9+</sup>](../apis/js-apis-webview.md#stop) instead.

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

### clearHistory<sup>(deprecated)</sup>

clearHistory(): void

Clears the browsing history.

This API is deprecated since API version 9. You are advised to use [clearHistory<sup>9+</sup>](../apis/js-apis-webview.md#clearhistory) instead.

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

## WebCookie<sup>(deprecated)</sup>

Manages behavior of cookies in **\<Web>** components. All **\<Web>** components in an application share a **WebCookie**. You can use the **getCookieManager** API in **controller** to obtain the **WebCookie** for subsequent cookie management.

### setCookie<sup>(deprecated)</sup>
setCookie(): boolean

Sets the cookie. This API returns the result synchronously. Returns **true** if the operation is successful; returns **false** otherwise.

This API is deprecated since API version 9. You are advised to use [setCookie<sup>9+</sup>](../apis/js-apis-webview.md#setcookie) instead.

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

### saveCookie<sup>(deprecated)</sup>
saveCookie(): boolean

Saves the cookies in the memory to the drive. This API returns the result synchronously.

This API is deprecated since API version 9. You are advised to use [saveCookieAsync<sup>9+</sup>](../apis/js-apis-webview.md#savecookieasync) instead.

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Operation result.|
