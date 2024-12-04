# Web

The **Web** component can be used to display web pages. It can be used with the [@ohos.web.webview](js-apis-webview.md) module, which provides APIs for web control.

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

To use online resources, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Child Components

Not supported

## APIs

Web(value: WebOptions)

> **NOTE**
>
> Transition animation is not supported.
>
> **Web** components on the same page must be bound to different **WebviewController** instances.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](#weboptions)   | Yes   | Define web options.|

**Example**

Example of loading online web pages:

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

Example of loading online web pages in incognito mode:

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

Example of rendering the **Web** component in synchronous mode:

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

Example of using the **Web** component to specify the shared rendering process.

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

Example of loading local web pages using **$rawfile()**:


  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through $rawfile.
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

Example of loading a link with the hash (#) route through the resource protocol in WebView:
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through the resource protocol.
        Web({ src: "resource://rawfile/index.html", controller: this.controller })
      }
    }
  }
  ```

Example of loading local resource files in the sandbox:

1. Obtain the sandbox path through the constructed singleton object **GlobalContext**.

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
         // Load the files in the sandbox.
         Web({ src: url, controller: this.controller })
       }
     }
   }
   ```

2. Modify the **EntryAbility.ets** file.

   The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // Data synchronization between the UIAbility component and UI can be implemented by binding filesDir to the GlobalContext object.
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
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

## WebOptions

Define web options through [APIs](#apis).

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src        | string \| [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)   | Yes   | Address of a web page resource. To access local resource files, use the **$rawfile** or **resource** protocol. To load a local resource file (in HTML or TXT format) in the sandbox outside of the application package, use **file://** to specify the path of the sandbox.<br>**src** cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](js-apis-webview.md#loadurl).|
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller)  | Yes   | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| renderMode<sup>12+</sup> | [RenderMode](#rendermode12)| No  | Rendering mode.<br>**RenderMode.ASYNC_RENDER** (default, cannot be dynamically adjusted): The **Web** component is rendered asynchronously.<br>**RenderMode.SYNC_RENDER**: The **Web** component is rendered synchronously within the current execution context.|
| incognitoMode<sup>11+</sup> | boolean | No| Whether to enable incognito mode. The value **true** means to enable incognito mode, and **false** means the opposite.<br> Default value: **false**|
| sharedRenderProcessToken<sup>12+</sup> | string | No| The token of the shared rendering process specified by the **Web** component. In multi-rendering process mode, the **Web** component with the same token preferentially attempts to reuse the rendering process bound to the token. The token is bound to the rendering process when the rendering process is initialized. When the rendering process is not associated with a **Web** component, its binding to the token is removed.<br> Default value: **""** |

## Attributes

The following universal attributes are supported: [aspectRatio](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio), [backdropBlur](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backdropblur), [backgroundColor](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor), [bindContentCover](../apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover), [bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8), [bindMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu), [bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet), [borderColor](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#bordercolor), [borderRadius](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderradius), [borderStyle](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderstyle), [borderWidth](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderwidth), [clip](../apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clip), [constraintSize](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#constraintsize), [defaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9), [focusable](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable), [tabIndex](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#tabindex9), [groupDefaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#groupdefaultfocus9), [focusOnTouch](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusontouch9), [displayPriority](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority), [enabled](../apis-arkui/arkui-ts/ts-universal-attributes-enable.md#enabled), [flexBasis](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis), [flexGrow](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexgrow), [flexShrink](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink), [layoutWeight](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight), [id](../apis-arkui/arkui-ts/ts-universal-attributes-component-id.md), [gridOffset](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md), [gridSpan](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md), [useSizeType](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md), [height](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#height), [touchable](../apis-arkui/arkui-ts/ts-universal-attributes-click.md), [margin](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin), [markAnchor](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#markanchor), [offset](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset), [width](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#width), [zIndex](../apis-arkui/arkui-ts/ts-universal-attributes-z-order.md#zindex), [visibility](../apis-arkui/arkui-ts/ts-universal-attributes-visibility.md#visibility), [scale](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale), [translate](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#translate), [responseRegion](../apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregion), [size](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#size), [stateStyles](../apis-arkui/arkui-ts/ts-universal-attributes-polymorphic-style.md#statestyles), [opacity](../apis-arkui/arkui-ts/ts-universal-attributes-opacity.md#opacity), [shadow](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow), [sharedTransition](../apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md), [transition](../apis-arkui/arkui-ts/ts-transition-animation-component.md)

### domStorageAccess

domStorageAccess(domStorageAccess: boolean)

Sets whether to enable the DOM Storage API. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  | Description                                |
| ---------------- | ------- | ---- | ------------------------------------ |
| domStorageAccess | boolean | Yes   | Whether to enable the DOM Storage API. The default value is **false**.|

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
          .domStorageAccess(true)
      }
    }
  }
  ```

### fileAccess

fileAccess(fileAccess: boolean)

Sets whether to enable access to the file system in the application. This setting does not affect the access to the files specified through [$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md).

**fileAccess** is disabled by default since API version 12. When **fileAccess** is set to **false**, files in the read-only **/data/storage/el1/bundle/entry/resources/resfile** directory can still be accessed through the **file** protocol.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type   | Mandatory  | Description                  |
| ---------- | ------- | ---- | ---------------------- |
| fileAccess | boolean | Yes   | Whether to enable access to the file system in the application.<br>Default value:<br>API version 11 and earlier: **true**<br> API version 12 and later: **false**|

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
          .fileAccess(true)
      }
    }
  }
  ```

### imageAccess

imageAccess(imageAccess: boolean)

Sets whether to enable automatic image loading. By default, this feature is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description           |
| ----------- | ------- | ---- | --------------- |
| imageAccess | boolean | Yes   | Whether to enable automatic image loading. Default value: **true**|

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
          .imageAccess(true)
      }
    }
  }
  ```

### javaScriptProxy

javaScriptProxy(javaScriptProxy: JavaScriptProxy)

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. The parameters cannot be updated. This API can be used in synchronous or asynchronous mode, or in both modes. If the API can be used in both synchronous and asynchronous modes, it is called asynchronously by default. Only one object can be registered through this API. To register multiple objects, use [registerJavaScriptProxy<sup>9+</sup>](js-apis-webview.md#registerjavascriptproxy).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- |---------------------------------------- |
| javaScriptProxy     | [JavaScriptProxy](#javascriptproxy12)                                   | Yes   |  Object to be registered. Methods can be declared, but attributes cannot.                  |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class TestObj {
    constructor() {
    }

    test(data1: string, data2: string, data3: string): string {
      console.log("data1:" + data1);
      console.log("data2:" + data2);
      console.log("data3:" + data3);
      return "AceString";
    }

    asyncTest(data: string): void {
      console.log("async data:" + data);
    }

    toString(): void {
      console.log('toString' + "interface instead.");
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    testObj = new TestObj();
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          .javaScriptProxy({
            object: this.testObj,
            name: "objName",
            methodList: ["test", "toString"],
            asyncMethodList: ["asyncTest"],
            controller: this.controller,
        })
      }
    }
  }
  ```

### javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

Sets whether JavaScript scripts can be executed. By default, JavaScript scripts can be executed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  | Description               |
| ---------------- | ------- | ---- | ------------------- |
| javaScriptAccess | boolean | Yes   | Whether JavaScript scripts can be executed. Default value: **true**|

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
          .javaScriptAccess(true)
      }
    }
  }
  ```

### overScrollMode<sup>11+</sup>

overScrollMode(mode: OverScrollMode)

Sets the overscroll mode, which is disabled by default. When the overscroll mode is enabled and the boundary of the scrolling area is reached, the **Web** component plays a bounce effect animation.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                   | Mandatory  | Description              |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [OverScrollMode](#overscrollmode11) | Yes   | Whether to enable the overscroll mode. Default value: **OverScrollMode.NEVER**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: OverScrollMode = OverScrollMode.ALWAYS;
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .overScrollMode(this.mode)
      }
    }
  }
  ```

### mixedMode

mixedMode(mixedMode: MixedMode)

Sets whether to enable loading of HTTP and HTTPS hybrid content can be loaded. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| mixedMode | [MixedMode](#mixedmode)| Yes   | Mixed content to load. Default value: **MixedMode.None**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: MixedMode = MixedMode.All;
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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description            |
| ----------------- | ------- | ---- | ---------------- |
| onlineImageAccess | boolean | Yes   | Whether to enable access to online images through HTTP and HTTPS. Default value: **true**|

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
          .onlineImageAccess(true)
      }
    }
  }
  ```

### zoomAccess

zoomAccess(zoomAccess: boolean)

Sets whether to enable zoom gestures. By default, this feature is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type   | Mandatory  | Description         |
| ---------- | ------- | ---- | ------------- |
| zoomAccess | boolean | Yes   | Whether to enable zoom gestures. Default value: **true**|

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
          .zoomAccess(true)
      }
    }
  }
  ```

### overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

Sets whether to load web pages by using the overview mode. By default, this feature is enabled. Currently, only mobile devices are supported.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name               | Type   | Mandatory  | Description           |
| ------------------ | ------- | ---- | --------------- |
| overviewModeAccess | boolean | Yes   | Whether to load web pages by using the overview mode. Default value: **true**|

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
          .overviewModeAccess(true)
      }
    }
  }
  ```

### databaseAccess

databaseAccess(databaseAccess: boolean)

Sets whether to enable database access. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name           | Type   | Mandatory  | Description             |
| -------------- | ------- | ---- | ----------------- |
| databaseAccess | boolean | Yes   | Whether to enable database access. The default value is **false**.|

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
          .databaseAccess(true)
      }
    }
  }
  ```

### geolocationAccess

geolocationAccess(geolocationAccess: boolean)

Sets whether to enable geolocation access. By default, this feature is enabled. For details, see [Managing Location Permissions](../../web/web-geolocation-permission.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description           |
| ----------------- | ------- | ---- | --------------- |
| geolocationAccess | boolean | Yes   | Whether to enable geolocation access. Default value: **true**|

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
          .geolocationAccess(true)
      }
    }
  }
  ```

### mediaPlayGestureAccess<sup>9+</sup>

mediaPlayGestureAccess(access: boolean)

Sets whether video playback must be started by user gestures. This API is not applicable to videos that do not have an audio track or whose audio track is muted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory  | Description               |
| ------ | ------- | ---- | ------------------- |
| access | boolean | Yes   | Whether video playback must be started by user gestures. Default value: **true**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State access: boolean = true;

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

Sets whether to enable the multi-window permission. By default, this feature is disabled.
Enabling the multi-window permission requires implementation of the **onWindowNew** event. For the sample code, see [onWindowNew](#onwindownew9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description        |
| ----------- | ------- | ---- | ------------ |
| multiWindow | boolean | Yes   | Whether to enable the multi-window permission. The default value is **false**.|

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
        .multiWindowAccess(false)
      }
    }
  }
  ```

### horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

Sets whether to display the horizontal scrollbar, including the default system scrollbar and custom scrollbar. By default, the horizontal scrollbar is displayed.

> **NOTE**
>
> - If an @State decorated variable is used to control the horizontal scrollbar visibility, **controller.refresh()** must be called for the settings to take effect.
> - If the horizontal scrollbar visibility changes frequently through an @State decorated variable, it is recommended that the variable correspond to the **Web** component one by one.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name                | Type   | Mandatory  | Description        |
| ------------------- | ------- | ---- | ------------ |
| horizontalScrollBar | boolean | Yes   | Whether to display the horizontal scrollbar. Default value: **true**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = false;
  
    build() {
      Column() {
        // If an @State decorated variable is used to control the horizontal scrollbar visibility, controller.refresh() must be called for the settings to take effect.
        Button('refresh')
          .onClick(() => {
              this.isShow = true;
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .horizontalScrollBarAccess(this.isShow)
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

> **NOTE**
>
> - If an @State decorated variable is used to control the vertical scrollbar visibility, **controller.refresh()** must be called for the settings to take effect.
> - If the vertical scrollbar visibility changes frequently through an @State decorated variable, it is recommended that the variable correspond to the **Web** component one by one.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description        |
| ----------------- | ------- | ---- | ------------ |
| verticalScrollBar | boolean | Yes   | Whether to display the vertical scrollbar. Default value: **true**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = false;
  
    build() {
      Column() {
        // If an @State decorated variable is used to control the vertical scrollbar visibility, controller.refresh() must be called for the settings to take effect.
        Button('refresh')
          .onClick(() => {
              this.isShow = true;
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
        })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .verticalScrollBarAccess(this.isShow)
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

### password<sup>(deprecated)</sup>

password(password: boolean)

Sets whether the password should be saved. This API is a void API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

### cacheMode

cacheMode(cacheMode: CacheMode)

Sets the cache mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| cacheMode | [CacheMode](#cachemode)| Yes   | Cache mode to set. Default value: **CacheMode.Default**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: CacheMode = CacheMode.None;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .cacheMode(this.mode)
      }
    }
  }
  ```

### copyOptions<sup>11+</sup>

copyOptions(value: CopyOptions)

Sets the pasteboard copy options.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| value | [CopyOptions](../apis-arkui/arkui-ts/ts-appendix-enums.md#copyoptions9) | Yes   | Pasteboard copy options. Default value: **CopyOptions.LocalDevice**|

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
        .copyOptions(CopyOptions.None)
    }
  }
}
  ```

### textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

Sets the text zoom ratio of the page. The default value is **100**, which indicates 100%.

**System capability**: SystemCapability.Web.Webview.Core

This API is deprecated since API version 9. You are advised to use [textZoomRatio<sup>9+</sup>](#textzoomratio9) instead.

**Parameters**

| Name         | Type  | Mandatory | Description                            |
| ------------ | ------ | ---- | -------------------------------- |
| textZoomAtio | number | Yes  | Text zoom ratio to set. The value is an integer. The value range is (0, +∞). Default value: **100**|

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description                            |
| ------------- | ------ | ---- | -------------------------------- |
| textZoomRatio | number | Yes   | Text zoom ratio to set. The value is an integer. The value range is (0, +∞). Default value: **100**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State atio: number = 150;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory  | Description                         |
| ------- | ------ | ---- | ----------------------------- |
| percent | number | Yes   | Scale factor of the entire page. Default value: **100**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State percent: number = 100;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .initialScale(this.percent)
      }
    }
  }
  ```

### userAgent<sup>(deprecated)</sup>

userAgent(userAgent: string)

Sets the user agent.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [setCustomUserAgent](js-apis-webview.md#setcustomuseragent10)<sup>10+</sup> instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type  | Mandatory  | Description     |
| --------- | ------ | ---- | --------- |
| userAgent | string | Yes   | User agent to set.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State userAgent:string = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36';

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory  | Description               |
| ----- | ------- | ---- | ------------------- |
| block | boolean | Yes   | Sets whether to block online downloads. The default value is **false**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State block: boolean = true;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Default fixed font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. Default value: **13**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 16;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Default font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. Default value: **16**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Minimum font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. Default value: **8**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Minimum logical font size to set, in px. The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 are handled as 72, and values less than 1 are handled as 1. Default value: **8**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description               |
| ------ | ------ | ---- | ------------------- |
| family | string | Yes   | Sets the fixed font family for the web page. Default value: **monospace**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "monospace";

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Sets the sans serif font family for the web page. Default value: **sans-serif**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "sans-serif";

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description               |
| ------ | ------ | ---- | ------------------- |
| family | string | Yes   | Sets the serif font family for the web page. Default value: **serif**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "serif";

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                  |
| ------ | ------ | ---- | ---------------------- |
| family | string | Yes   | Sets the standard font family for the web page. Default value: **sans-serif**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "sans-serif";

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| family | string | Yes   | Sets the fantasy font family for the web page. Default value: **fantasy**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "fantasy";

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| family | string | Yes   | Sets the cursive font family for the web page. Default value: **cursive**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "cursive";

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

Sets the web dark mode. By default, web dark mode is disabled. When it is enabled, the **Web** component enables the dark theme defined for web pages if the theme has been defined in **prefers-color-scheme** of a media query, and remains unchanged otherwise. To enable the forcible dark mode, use this API with [forceDarkAccess](#forcedarkaccess9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                            | Mandatory  | Description                  |
| ---- | -------------------------------- | ---- | ---------------------- |
| mode | [WebDarkMode](#webdarkmode9) | Yes   | Web dark mode to set. Default value: **WebDarkMode.Off**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: WebDarkMode = WebDarkMode.On;

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

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory  | Description           |
| ------ | ------- | ---- | --------------- |
| access | boolean | Yes   | Sets whether to enable forcible dark mode for the web page. The default value is **false**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: WebDarkMode = WebDarkMode.On;
    @State access: boolean = true;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
          .forceDarkAccess(this.access)
      }
    }
  }
  ```

### tableData<sup>(deprecated)</sup>

tableData(tableData: boolean)

Sets whether form data should be saved. This API is a void API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

### wideViewModeAccess<sup>(deprecated)</sup>

wideViewModeAccess(wideViewModeAccess: boolean)

Sets whether to support the viewport attribute of the HTML **\<meta>** tag. This API is a void API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

### pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

Sets whether to enable smooth pinch mode for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type   | Mandatory  | Description         |
| --------- | ------- | ---- | ------------- |
| isEnabled | boolean | Yes   | Whether to enable smooth pinch mode for the web page. The default value is **false**.|

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
          .pinchSmooth(true)
      }
    }
  }
  ```

### allowWindowOpenMethod<sup>10+</sup>

allowWindowOpenMethod(flag: boolean)

Sets whether to allow a new window to automatically open through JavaScript.

When **flag** is set to **true**, a new window can automatically open through JavaScript. When **flag** is set to **false**, a new window can still automatically open through JavaScript for user behavior, but cannot for non-user behavior. The user behavior here refers to that a user requests to open a new window (**window.open**) within 5 seconds of operating the **Web** component.

This API takes effect only when [javaScriptAccess](#javascriptaccess) is enabled.

This API opens a new window when [multiWindowAccess](#multiwindowaccess9) is enabled and opens a local window when [multiWindowAccess](#multiwindowaccess9) is disabled.

The default value of **flag** is subject to the settings of the **persist.web.allowWindowOpenMethod.enabled** system attribute. If this attribute is not set, the default value of **flag** is **false**.

To check the settings of **persist.web.allowWindowOpenMethod.enabled**,

run the **hdc shell param get persist.web.allowWindowOpenMethod.enabled** command. If the attribute is set to 0 or does not exist,
you can run the **hdc shell param set persist.web.allowWindowOpenMethod.enabled 1** command to enable it.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory   | Description                     |
| ---- | ------- | ---- | ------------------------- |
| flag | boolean | Yes   | Whether to allow a new window to automatically open through JavaScript. When the **persist.web.allowWindowOpenMethod.enabled** system attribute is set to **true**, the default value of **flag** is **true**; otherwise, the default value of **flag** is **false**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // There are two Web components on the same page. When the WebComponent object opens a new window, the NewWebViewComp object is displayed. 
  @CustomDialog
  struct NewWebViewComp {
    controller?: CustomDialogController;
    webviewController1: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            console.info("NewWebViewComp onWindowExit");
            if (this.controller) {
              this.controller.close();
            }
          })
      }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          // MultiWindowAccess needs to be enabled.
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close();
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController })
            })
            this.dialogController.open();
            // Return the WebviewController object corresponding to the new window to the Web kernel.
            // If opening a new window is not needed, set the parameter to null when calling the event.handler.setWebController API.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

### mediaOptions<sup>10+</sup>

mediaOptions(options: WebMediaOptions)

Sets the web-based media playback policy, including the validity period for automatically resuming a paused web audio, and whether the audio of multiple **Web** instances in an application is exclusive.

> **NOTE**
>
> - Audios in the same **Web** instance are considered as the same audio.
> - The media playback policy controls videos with an audio track.
> - After the parameter settings are updated, the playback must be started again for the settings to take effect.
> - It is recommended that you set the same **audioExclusive** value for all **Web** components.
> - Audio and video interruption takes effect within an app and between apps, and playback resumption takes effect only between apps.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                                 | Mandatory  | Description                                    |
| ------- | ------------------------------------- | ---- | ---------------------------------------- |
| options | [WebMediaOptions](#webmediaoptions10) | Yes   | Web-based media playback policy. The default value of **resumeInterval** is **0**, indicating that the playback is not automatically resumed. Default value: **{resumeInterval: 0, audioExclusive: true}**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State options: WebMediaOptions = {resumeInterval: 10, audioExclusive: true};

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mediaOptions(this.options)
      }
    }
  }
  ```

### javaScriptOnDocumentStart<sup>11+</sup>

javaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document starts to be loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree may not have been loaded or rendered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](#scriptitem11)> | Yes   | Script item array to be injected.|

**Example in the .ets file**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
      controller: webview.WebviewController = new webview.WebviewController();
      private localStorage: string =
          "if (typeof(Storage) !== 'undefined') {" +
          "   localStorage.setItem('color', 'Red');" +
          "}";
      @State scripts: Array<ScriptItem> = [
          { script: this.localStorage, scriptRules: ["*"] }
      ];

      build() {
          Column({ space: 20 }) {
              Web({ src: $rawfile('index.html'), controller: this.controller })
                  .javaScriptAccess(true)
                  .domStorageAccess(true)
                  .backgroundColor(Color.Grey)
                  .javaScriptOnDocumentStart(this.scripts)
                  .width('100%')
                  .height('100%')
          }
      }
  }
  ```
**Example in the HTML file**

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
  </head>
  <body style="font-size: 30px;" onload='bodyOnLoadLocalStorage()'>
      Hello world!
      <div id="result"></div>
  </body>
  <script type="text/javascript">
    function bodyOnLoadLocalStorage() {
      if (typeof(Storage) !== 'undefined') {
        document.getElementById('result').innerHTML = localStorage.getItem('color');
      } else {
        document.getElementById('result').innerHTML = 'Your browser does not support localStorage.';
      }
    }
  </script>
</html>
```

### javaScriptOnDocumentEnd<sup>11+</sup>

javaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document has been loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree has been loaded and rendered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](#scriptitem11)> | Yes   | Script item array to be injected.|

**Example**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from javaScriptOnDocumentEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .javaScriptOnDocumentEnd(this.scripts)
        .width('100%')
        .height('100%')
    }
  }
}
  ```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
</head>
<body style="font-size: 30px;">
Hello world!
<div id="result">test msg</div>
</body>
</html>
```

### layoutMode<sup>11+</sup>

layoutMode(mode: WebLayoutMode)

Sets the web layout mode.

> **NOTE**
>
> Currently, only two web layout modes are supported: **WebLayoutMode.NONE** and **WebLayoutMode.FIT_CONTENT**.
>
> The following restrictions apply with the usage of **WebLayoutMode.FIT_CONTENT**:
> - If the web content is wider or longer than 8000 px, specify the **RenderMode.SYNC_RENDER** mode when creating the **Web** component; otherwise, the screen may be blank.
> - After the **Web** component is created, dynamic switching of the **layoutMode** is not supported.
> - The width and height of the **Web** component cannot exceed 500,000 px each.
> - Frequent changes to the page width and height will trigger a re-layout of the **Web** component, which can affect the user experience.
> - Waterfall web pages are not supported (drop down to the bottom to load more).
> - Only height adaptation is supported. Width adaptation is not supported.
> - Because the height is adaptive to the web page height, the component height cannot be changed by modifying the component height attribute.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                 | Mandatory  | Description                 |
| ---- | ------------------------------------- | ---- | --------------------- |
| mode | [WebLayoutMode](#weblayoutmode11) | Yes   | Web layout mode. Default value: **WebLayoutMode.NONE**.|

**Example**

  1. After specifying the **layoutMode** as **WebLayoutMode.FIT_CONTENT**, you need to explicitly specify the **renderMode** to **RenderMode.SYNC_RENDER**. Otherwise, rendering errors may occur when the viewport height exceeds 7680px in the default **RenderMode.ASYNC_RENDER**.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    mode: WebLayoutMode = WebLayoutMode.FIT_CONTENT;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
          .layoutMode(this.mode)
      }
    }
  }
  ```

  2. After specifying the layoutMode as **WebLayoutMode.FIT_CONTENT**, you are advised to specify **overScrollMode** as **OverScrollMode.NEVER**. Otherwise, when the web page scrolls to the edge in the nested scrolling scenario, the rebounding effect is triggered first, which affects user experience.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    layoutMode: WebLayoutMode = WebLayoutMode.FIT_CONTENT;
    @State overScrollMode: OverScrollMode = OverScrollMode.NEVER;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
          .layoutMode(this.layoutMode)
          .overScrollMode(this.overScrollMode)
      }
    }
  }
  ```

### nestedScroll<sup>11+</sup>

nestedScroll(value: NestedScrollOptions)

Sets nested scrolling options.

> **NOTE**
>
> - You can set the nested scrolling mode in the forward and backward directions to implement scrolling linkage with the parent component.
> - You can set separate nested scrolling modes for the forward and backward directions.
> - The default mode for **scrollForward** and **scrollBackward** is [NestedScrollMode.SELF_FIRST](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10).
> - Containers that support nested scrolling: **\<Grid>**, **\<List>**, **\<Scroll>**, **\<Swiper>**, **\<Tabs>**, **\<WaterFlow>**.
> - Input sources that support nested scrolling: gestures, mouse device, and touchpad.
> - In nested scrolling scenarios, since the **Web** component's over-scrolling to the edge will trigger the over-scroll bounce effect first, it is recommended that you set **overScrollMode** to **OverScrollMode.NEVER** to avoid undermining the user experience.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                    | Mandatory  | Description            |
| ----- | ---------------------------------------- | ---- | ---------------- |
| value | [NestedScrollOptions](../apis-arkui/arkui-ts/ts-container-scrollable-common.md#nestedscrolloptions10)| Yes   | Nested scrolling options.|

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
          .nestedScroll({
            scrollForward: NestedScrollMode.SELF_FIRST,
            scrollBackward: NestedScrollMode.SELF_FIRST,
          })
      }
    }
  }
  ```
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    build() {
      Scroll(){
        Column() {
          Text ("Nested Web")
            .height("25%")
            .width("100%")
            .fontSize(30)
            .backgroundColor(Color.Yellow)
          Web({ src: $rawfile('index.html'),
                controller: this.controller })
            .nestedScroll({
              scrollUp: NestedScrollMode.SELF_FIRST,
              scrollDown: NestedScrollMode.PARENT_FIRST,
              scrollLeft: NestedScrollMode.SELF_FIRST,
              scrollRight: NestedScrollMode.SELF_FIRST,
            })
        }
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
    <style>
      .blue {
        background-color: lightblue;
      }
      .green {
        background-color: lightgreen;
      }
      .blue, .green {
       width: 100%;
  	 font-size:70px;
  	 height:1000px;
      }
    </style>
  </head>
  <body>
    <div class="blue" align="center" >Scroll 1</div>
    <div class="green" align="center">Scroll 2</div>
    <div class="blue" align="center" >Scroll 3</div>
    <div class="green" align="center">Scroll 4</div>
    <div class="blue" align="center" >Scroll 5</div>
    <div class="green" align="center">Scroll 6</div>
    <div class="blue" align="center" >Scroll 7</div>
  </body>
  </html>
  ```

### enableNativeEmbedMode<sup>11+</sup>

enableNativeEmbedMode(mode: boolean)

Specifies whether to enable the same-layer rendering feature. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                     | Mandatory  | Description            |
| ----- | ---------------------------------------- | ---- | ---------------- |
| mode |  boolean | Yes   | Whether to enable the same-layer rendering feature. The default value is **false**.|

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
          .enableNativeEmbedMode(true)
      }
    }
  }
  ```
### registerNativeEmbedRule<sup>12+</sup>

registerNativeEmbedRule(tag: string, type: string)

Registers the HTML tag name and type for same-layer rendering. The tag name only supports **object** and **embed**. The tag type can be any non-empty string, case-insensitive.

If the specified type is the same as the W3C standard **object** or **embed** type, the ArkWeb kernel identifies the type as a non-same-layer tag.

This API is also controlled by the **enableNativeEmbedMode** API and does not take effect if same-layer rendering is not enabled. When this API is not used, the ArkWeb engine recognizes the **embed** tags with the "native/" prefix as same-layer tags.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description            |
|------|--------| ---- |------------------|
| tag  | string | Yes   | Tag name.            |
| type | string | Yes  | Tag type. It is used by the ArkWeb engine for prefix matching.|

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
          .enableNativeEmbedMode(true)
          .registerNativeEmbedRule("object", "application/view")
      }
    }
  }
  ```
### defaultTextEncodingFormat<sup>12+</sup>

defaultTextEncodingFormat(textEncodingFormat: string)

Sets the default character encoding for web pages.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| textEncodingFormat | string | Yes   | Default character encoding. Default value: **"UTF-8"**|

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
        Web({ src: $rawfile('index.html'), controller: this.controller })
          // Set the height.
          .height(500)
          .defaultTextEncodingFormat("UTF-8")
          .javaScriptAccess(true)
      }
    }
  }
  ```

```html

<!doctype html>
<html>
<head>
    <meta name="viewport" content="width=device-width" />
    <title>My test html5 page</title>
</head>
<body>
    Hello world!
</body>
</html>
```
### metaViewport<sup>12+</sup>

metaViewport(enabled: boolean)

Sets whether the **viewport** property of the **meta** tag is enabled.

> **NOTE**
>
> - If this parameter is set to **false**, the **viewport** property of the **meta** tag is not enabled. This means that the property will not be parsed and a default layout will be used.
> - If this parameter is set to **true**, the **viewport** property of the **meta** tag is enabled. This means that the property will be parsed and used for the layout.
> - If set to an invalid value, this parameter does not take effect.
> - If the device is 2-in-1, the **viewport** property is not supported. This means that, regardless of whether this parameter is set to **true** or **false**, the **viewport** property will not be parsed and a default layout will be used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | -------- | ---- | -------------------------------- |
| enabled | boolean  | Yes  | Whether the **viewport** property of the **meta** tag is enabled. Default value: **true**|

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
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .metaViewport(true)
    }
  }
}
  ```

```html
<!doctype html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
	<p>Hello world! </p>
</body>
</html>
```

### textAutosizing<sup>12+</sup>

textAutosizing(textAutosizing: boolean)

Sets whether automatic text resizing is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| textAutosizing | boolean | Yes   | Whether automatic text resizing is enabled. Default value: **true**|

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
          .textAutosizing(false)
      }
    }
  }
  ```
### enableNativeMediaPlayer<sup>12+</sup>

enableNativeMediaPlayer(config: NativeMediaPlayerConfig)

Enable the [application takeover of web media playback feature](../../web/app-takeovers-web-media.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description|
| ---- | ------ | ---- | ---------------------|
| config | [NativeMediaPlayerConfig](#nativemediaplayerconfig12) | Yes   | **enable**: whether to enable the feature.<br> **shouldOverlay**: whether the image of the video player taken over by the application will overlay the web page content, if this feature is enabled. Default value: **{enable: false, shouldOverlay: false}**|

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
          .enableNativeMediaPlayer({enable: true, shouldOverlay: false})
      }
    }
  }
  ```

### selectionMenuOptions<sup>12+</sup>

selectionMenuOptions(expandedMenuOptions: Array\<ExpandedMenuItemOptions>)

Sets the extended options of the custom context menu on selection, including the text content, icon, and callback.

The API only supports the selection of plain text; if the selected content contains images or other non-text elements, the **action** information may display garbled content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                                                        | Mandatory  | Description         |
| ------------------- | ----------------------------------------------------------    | ---- | ------------- |
| expandedMenuOptions | Array<[ExpandedMenuItemOptions](#expandedmenuitemoptions12)> | Yes   | Extended options of the custom context menu on selection.<br>The number of menu options, menu content size, and start icon size must be the same as those of the ArkUI [\<Menu>](../apis-arkui/arkui-ts/ts-basic-components-menu.md) component.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State menuOptionArray: Array<ExpandedMenuItemOptions> = [
      {content: 'Apple', startIcon: $r('app.media.icon'), action: (selectedText) => {
        console.info('select info ' + selectedText.toString());
      }},
      {content: 'Banana', startIcon: $r('app.media.icon'), action: (selectedText) => {
        console.info('select info ' + selectedText.toString());
      }}
    ];

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
        .selectionMenuOptions(this.menuOptionArray)
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
    <title>Test Web Page</title>
  </head>
  <body>
    <h1>selectionMenuOptions Demo</h1>
    <span>selection menu options</span>
  </body>
  </html>
  ```

### onAdsBlocked<sup>12+</sup>

onAdsBlocked(callback: OnAdsBlockedCallback)

Called after an ad is blocked on the web page to notify the user of detailed information about the blocked ad. To reduce the frequency of notifications and minimize the impact on the page loading process, only the first notification is made when the page is fully loaded. Subsequent blocking events are reported at intervals of 1 second, and no notifications are sent if there is no ad blocked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnAdsBlockedCallback](#onadsblockedcallback12) | Yes| Callback for **onAdsBlocked**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    @State totalAdsBlockCounts: number = 0;
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'https://www.example.com', controller: this.controller })
        .onAdsBlocked((details: AdsBlockedDetails) => {
          if (details) {
            console.log(' Blocked ' + details.adsBlocked.length + ' in ' + details.url);
            let adList: Array<string> = Array.from(new Set(details.adsBlocked));
            this.totalAdsBlockCounts += adList.length;
            console.log('Total blocked counts :' + this.totalAdsBlockCounts);
          }
        })
      }
    }
  }
  ```

### keyboardAvoidMode<sup>12+</sup>

keyboardAvoidMode(mode: WebKeyboardAvoidMode)

Sets the custom soft keyboard avoidance mode.

If the keyboard avoidance mode set in **UIContext** is [KeyboardAvoidMode.RESIZE](../apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11), this API does not take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                             | Mandatory  | Description         |
| ------------------- | ------------------------------   | ------ | ------------- |
| mode | [WebKeyboardAvoidMode](#webkeyboardavoidmode12) | Yes    | Web soft keyboard avoidance mode.<br>Default value: **WebKeyboardAvoidMode.RESIZE_CONTENT**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State avoidMode: WebKeyboardAvoidMode = WebKeyboardAvoidMode.RESIZE_VISUAL;

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
        .keyboardAvoidMode(this.avoidMode)
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
    <title>Test Web Page</title>
  </head>
  <body>
    <input type="text" placeholder="Text">
  </body>
  </html>
  ```

### editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

Sets the custom menu options of the **Web** component.

You can use this property to customize a text menu.

You can use [onCreateMenu](../apis-arkui/arkui-ts/ts-text-common.md#oncreatemenu) to modify, add, and delete menu options. If you do not want to display text menus, return an empty array.

You can use [onMenuItemClick](../apis-arkui/arkui-ts/ts-text-common.md#onmenuitemclick) to customize the callback for menu options. This function is triggered after a menu option is clicked and determines whether to execute the default callback based on the return value. If **true** is returned, the system callback is not executed. If **false** is returned, the system callback is executed.

If this API is used together with [selectionMenuOptions](#selectionmenuoptions12), **selectionMenuOptions** does not take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                             | Mandatory  | Description         |
| ------------------- | ------------------------------   | ------ | ------------- |
| editMenu | [EditMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#editmenuoptions)| Yes    | Custom menu options of the **Web** component.<br>The number of menu options, menu content size, and icon size must be the same as those of the ArkUI [\<Menu>](../apis-arkui/arkui-ts/ts-basic-components-menu.md) component.<br>The values of ([TextMenuItemId](../apis-arkui/arkui-ts/ts-text-common.md#textmenuitemid12)) supported by the **Web** component are **CUT**, **COPY**, **PASTE**, and **SELECT_ALL**.<br>**textRange** in **onMenuItemClick()** is useless in the **Web** component. The input value is **-1**.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // Filter the menu items as required.
      return (
        menuItem.id.equals(TextMenuItemId.CUT) ||
        menuItem.id.equals(TextMenuItemId.COPY) ||
        menuItem.id.equals((TextMenuItemId.PASTE))
      )
    });
    let customItem1: TextMenuItem = {
      content: 'customItem1',
      id: TextMenuItemId.of('customItem1'),
      icon: $r('app.media.icon')
    };
    let customItem2: TextMenuItem = {
      content: $r('app.string.customItem2'),
      id: TextMenuItemId.of('customItem2'),
      icon: $r('app.media.icon')
    };
    items.push(customItem1);// Add an option to the end of the option list.
    items.unshift(customItem2);// Add an option to the beginning of the option list.

    return items;
  }

  onMenuItemClick(menuItem: TextMenuItem, textRange: TextRange): boolean {
    if (menuItem.id.equals(TextMenuItemId.CUT)) {
      // User-defined behavior.
      console.log ("Intercept ID: CUT")
      return true; // Return true to not execute the system callback.
    } else if (menuItem.id.equals(TextMenuItemId.COPY)) {
      // User-defined behavior.
      console.log ("Do not intercept ID: COPY")
      return false; // Return false to execute the system callback.
    } else if (menuItem.id.equals(TextMenuItemId.of('customItem1'))) {
      // User-defined behavior.
      console.log ("Intercept ID: customItem1")
      return true;// There is no difference between true and false to the custom menu option, but true is recommended.
    } else if (menuItem.id.equals((TextMenuItemId.of($r('app.string.customItem2'))))){
      // User-defined behavior.
      console.log ("Intercept ID: app.string.customItem2")
      return true;
    }
    return false;// Return the default value false.
  }

  @State EditMenuOptions: EditMenuOptions = { onCreateMenu: this.onCreateMenu, onMenuItemClick: this.onMenuItemClick }

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .editMenuOptions(this.EditMenuOptions)
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
      <title>Test Web Page</title>
  </head>
  <body>
    <h1>editMenuOptions Demo</h1>
    <span>edit menu options</span>
  </body>
</html>
```

### enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(enabled: boolean)

Sets whether to enable vibration when the text in the **Web** component is pressed and held. The vibration is enabled by default. The **ohos.permission.VIBRATE** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type       | Mandatory  | Description|
| --------- | ---------   | ------ | ------------- |
| enabled   | boolean | Yes | Whether to enable vibration. Default value: **true**|

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
      Web({ src: $rawfile("index.html"), controller: this.controller })
      .enableHapticFeedback(true)
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
      <title>Test Web Page</title>
  </head>
  <body>
    <h1>enableHapticFeedback Demo</h1>
    <span>enable haptic feedback</span>
  </body>
</html>
```

### bindSelectionMenu<sup>13+</sup>

bindSelectionMenu(elementType: WebElementType, content: CustomBuilder, responseType: WebResponseType, options?: SelectionMenuOptionsExt)

Sets the custom selection menu.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                            | Mandatory| Description                               |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| elementType     | [WebElementType](#webelementtype13)            | Yes  | Menu type.  |
| content      | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)     | Yes  | Menu content.  |
| responseType | [WebResponseType](#webresponsetype13)          | Yes  | Response type of the menu.|
| options      | [SelectionMenuOptionsExt](#selectionmenuoptionsext13)   | No  | Menu options.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

interface PreviewBuilderParam {
  previewImage: Resource | string | undefined;
  width: number;
  height: number;
}

@Builder function PreviewBuilderGlobal($$: PreviewBuilderParam) {
  Column() {
    Image($$.previewImage)
      .objectFit(ImageFit.Fill)
      .autoResize(true)
  }.width($$.width).height($$.height)
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  private result: WebContextMenuResult | undefined = undefined;
  @State previewImage: Resource | string | undefined = undefined;
  @State previewWidth: number = 0;
  @State previewHeight: number = 0;

  @Builder
  MenuBuilder() {
    Menu() {
      MenuItem({content:'Copy',})
        .onClick(() => {
          this.result?.copy();
          this.result?.closeContextMenu();
        })
      MenuItem({content:'Select All',})
        .onClick(() => {
          this.result?.selectAll();
          this.result?.closeContextMenu();
        })
    }
  }
  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .bindSelectionMenu(WebElementType.IMAGE, this.MenuBuilder, WebResponseType.LONG_PRESS,
          {
            onAppear: () => {},
            onDisappear: () => {
              this.result?.closeContextMenu();
            },
            preview: PreviewBuilderGlobal({
              previewImage: this.previewImage,
              width: this.previewWidth,
              height: this.previewHeight
            }),
            menuType: MenuType.PREVIEW_MENU
          })
        .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result;
              if (event.param.getLinkUrl()) {
                return false;
              }
              this.previewWidth = px2vp(event.param.getPreviewWidth());
              this.previewHeight = px2vp(event.param.getPreviewHeight());
              if (event.param.getSourceUrl().indexOf("resource://rawfile/") == 0) {
                this.previewImage = $rawfile(event.param.getSourceUrl().substr(19));
              } else {
                this.previewImage = event.param.getSourceUrl();
              }
              return true;
            }
            return false;
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
      <title>Test Web Page</title>
  </head>
  <body>
    <h1>bindSelectionMenu Demo</h1>
    <img src="./img.png" >
  </body>
</html>
```

## Events

The following universal events are supported: [onAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#onappear), [onDisAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear), [onBlur](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onblur), [onFocus](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onfocus), [onDragEnd](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragend), [onDragEnter](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragenter), [onDragStart](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart), [onDragMove](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragmove), [onDragLeave](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave), [onDrop](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop), [onHover](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onhover), [onMouse](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onmouse), [onKeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#onkeyevent), [onTouch](../apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch), [onVisibleAreaChange](../apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange)

### onAlert

onAlert(callback: Callback\<OnAlertEvent, boolean\>)

Called when **alert()** is invoked to display an alert dialog box on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                  | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnAlertEvent](#onalertevent12), boolean\>                | Yes   | Callback used when **alert()** is invoked to display an alert dialog box on the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **Web** component to exit the current page based on the user operation. The value **false** means that the custom dialog box drawn in the function is ineffective.|

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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onAlert((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onAlert',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onBeforeUnload(callback: Callback\<OnBeforeUnloadEvent, boolean\>)

Called when this page is about to exit after the user refreshes or closes the page. This API takes effect only when the page has obtained focus.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnBeforeUnloadEvent](#onbeforeunloadevent12), boolean\>                | Yes   | Callback used when this page is about to exit after the user refreshes or closes the page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **Web** component to exit the current page based on the user operation. The value **false** means that the custom dialog box drawn in the function is ineffective.|

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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onBeforeUnload((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onBeforeUnload',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onConfirm(callback: Callback\<OnConfirmEvent, boolean\>)

Called when **confirm()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnConfirmEvent](#onconfirmevent12), boolean\>                | Yes   | Called when **confirm()** is invoked by the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **Web** component to exit the current page based on the user operation. The value **false** means that the custom dialog box drawn in the function is ineffective.|

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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onConfirm((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onConfirm',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onPrompt(callback: Callback\<OnPromptEvent, boolean\>)

Called when **prompt()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnPromptEvent](#onpromptevent12), boolean\>                | Yes   | Called when **prompt()** is invoked by the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to instruct the **Web** component to exit the current page based on the user operation. The value **false** means that the custom dialog box drawn in the function is ineffective.|

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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onPrompt((event) => {
            if (event) {
              console.log("url:" + event.url);
              console.log("message:" + event.message);
              console.log("value:" + event.value);
              AlertDialog.show({
                title: 'onPrompt',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handlePromptConfirm(event.value);
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onConsole(callback: Callback\<OnConsoleEvent, boolean\>)

Called to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                             | Mandatory  | Description     |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnConsoleEvent](#onconsoleevent12), boolean\> | Yes   | Called when the web page receives a JavaScript console message.<br>Return value: boolean<br> Returns **true** if the message will not be printed to the console; returns **false** otherwise.|

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
        Button('onconsole message')
          .onClick(() => {
            this.controller.runJavaScript('myFunction()');
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onConsole((event) => {
            if (event) {
              console.log('getMessage:' + event.message.getMessage());
              console.log('getSourceId:' + event.message.getSourceId());
              console.log('getLineNumber:' + event.message.getLineNumber());
              console.log('getMessageLevel:' + event.message.getMessageLevel());
            }
            return false;
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
  <script>
      function myFunction() {
          console.log("onconsole printf");
      }
  </script>
  </body>
  </html>
  ```

### onDownloadStart

onDownloadStart(callback: Callback\<OnDownloadStartEvent\>)

Instructs the main application to start downloading a file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name               | Type  | Mandatory  | Description                               |
| ------------------ | ------ | ---- | ----------------------------------- |
| callback           | Callback\<[OnDownloadStartEvent](#ondownloadstartevent12)\> | Yes   | Called when the download starts. |

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
          .onDownloadStart((event) => {
            if (event) {
              console.log('url:' + event.url)
              console.log('userAgent:' + event.userAgent)
              console.log('contentDisposition:' + event.contentDisposition)
              console.log('contentLength:' + event.contentLength)
              console.log('mimetype:' + event.mimetype)
            }
          })
      }
    }
  }
  ```

### onErrorReceive

onErrorReceive(callback: Callback\<OnErrorReceiveEvent\>)

Called when an error occurs during web page loading. The error may occur on the main resource or sub-resource. You can use **request.isMainFrame()** to determine whether an error occurs on the main resource. For better results, simplify the implementation logic in the callback. This API is called when there is no network connection.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description           |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | Callback\<[OnErrorReceiveEvent](#onerrorreceiveevent12)\> | Yes   | Called when an error occurs during web page loading.     |

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
          .onErrorReceive((event) => {
            if (event) {
              console.log('getErrorInfo:' + event.error.getErrorInfo());
              console.log('getErrorCode:' + event.error.getErrorCode());
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

### onHttpErrorReceive

onHttpErrorReceive(callback: Callback\<OnHttpErrorReceiveEvent\>)

Called when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type                                    | Mandatory  | Description      |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback  | Callback\<[OnHttpErrorReceiveEvent](#onhttperrorreceiveevent12)\> | Yes   | Called when an HTTP error occurs during web page resource loading.|

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
          .onHttpErrorReceive((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getResponseData:' + event.response.getResponseData());
              console.log('getResponseEncoding:' + event.response.getResponseEncoding());
              console.log('getResponseMimeType:' + event.response.getResponseMimeType());
              console.log('getResponseCode:' + event.response.getResponseCode());
              console.log('getReasonMessage:' + event.response.getReasonMessage());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
              let resph = event.response.getResponseHeader();
              console.log('The response header result size is ' + resph.length);
              for (let i of resph) {
                console.log('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

### onPageBegin

onPageBegin(callback: Callback\<OnPageBeginEvent\>)

Called when the web page starts to be loaded. This API is called only for the main frame content, and not for the iframe or frameset content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageBeginEvent](#onpagebeginevent12)\> | Yes   | Called when the web page starts to be loaded.|

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
          .onPageBegin((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

### onPageEnd

onPageEnd(callback: Callback\<OnPageEndEvent\>)

Called when the web page loading is complete. This API takes effect only for the main frame content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageEndEvent](#onpageendevent12)\> | Yes   | Called when the web page loading is complete.|

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
          .onPageEnd((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

### onProgressChange

onProgressChange(callback: Callback\<OnProgressChangeEvent\>)

Called when the web page loading progress changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type  | Mandatory  | Description                 |
| ----------- | ------ | ---- | --------------------- |
| callback | Callback\<[OnProgressChangeEvent](#onprogresschangeevent12)\> | Yes   | Called when the web page loading progress changes.|

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
          .onProgressChange((event) => {
            if (event) {
              console.log('newProgress:' + event.newProgress);
            }
          })
      }
    }
  }
  ```

### onTitleReceive

onTitleReceive(callback: Callback\<OnTitleReceiveEvent\>)

Called when the document title of a web page is changed. If the <title\> element is not set for an HTML5 page, the corresponding URL is returned.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type  | Mandatory  | Description         |
| ----- | ------ | ---- | ------------- |
| callback | Callback\<[OnTitleReceiveEvent](#ontitlereceiveevent12)\> | Yes   | Called when the document title of the web page is changed.|

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
          .onTitleReceive((event) => {
            if (event) {
              console.log('title:' + event.title);
            }
          })
      }
    }
  }
  ```

### onRefreshAccessedHistory

onRefreshAccessedHistory(callback: Callback\<OnRefreshAccessedHistoryEvent\>)

Called when loading of the web page is complete and the access history of a web page is refreshed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description                                    |
| ----------- | ------- | ---- | ---------------------------------------- |
| callback         | Callback\<[OnRefreshAccessedHistoryEvent](#onrefreshaccessedhistoryevent12)\>  | Yes   | Called when the access history of the web page is refreshed.               |

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
          .onRefreshAccessedHistory((event) => {
            if (event) {
              console.log('url:' + event.url + ' isReload:' + event.isRefreshed);
            }
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

**System capability**: SystemCapability.Web.Webview.Core

### onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

Called to process an HTML form whose input type is **file**, in response to the tapping of the **Select File** button.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [onShowFileSelector<sup>9+</sup>](#onshowfileselector9) instead.

**System capability**: SystemCapability.Web.Webview.Core

### onRenderExited<sup>9+</sup>

onRenderExited(callback: Callback\<OnRenderExitedEvent\>)

Called when the rendering process exits abnormally.

After **onRenderExited()** is executed on a page of an application, all **Web** components exit.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                                    | Mandatory  | Description            |
| ---------------- | ---------------------------------------- | ---- | ---------------- |
| callback | Callback\<[OnRenderExitedEvent](#onrenderexitedevent12)\> | Yes   | Called when the rendering process exits abnormally.|

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
        Web({ src: 'chrome://crash/', controller: this.controller })
          .onRenderExited((event) => {
            if (event) {
              console.log('reason:' + event.renderExitReason);
            }
          })
      }
    }
  }
  ```
### onRenderProcessNotResponding<sup>12+</sup>

onRenderProcessNotResponding(callback: OnRenderProcessNotRespondingCallback)

Called when the rendering process does not respond.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                                        | Mandatory  | Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessNotRespondingCallback](#onrenderprocessnotrespondingcallback12) | Yes   | Callback triggered when the rendering process does not respond.|

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
          .onRenderProcessNotResponding((data) => {
            console.log("onRenderProcessNotResponding: [jsStack]= " + data.jsStack +
              ", [process]=" + data.pid + ", [reason]=" + data.reason);
          })
      }
    }
  }
  ```

### onRenderProcessResponding<sup>12+</sup>

onRenderProcessResponding(callback: OnRenderProcessRespondingCallback)

Called when the rendering process transitions back to a normal operating state from an unresponsive state. This callback indicates that the web page was not actually frozen.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                                        | Mandatory  | Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessRespondingCallback](#onrenderprocessrespondingcallback12) | Yes   | Callback triggered when the rendering process transitions back to a normal operating state from an unresponsive state.|

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
          .onRenderProcessResponding(() => {
            console.log("onRenderProcessResponding again");
          })
      }
    }
  }
  ```

### onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: Callback\<OnShowFileSelectorEvent, boolean\>)

Called to process an HTML form whose input type is **file**. If this function is not called or returns **false**, the **Web** component provides the default **Select File** handling UI. If it returns **true**, the application can customize the response behavior for **Select File**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ---- | ----------------- |
| callback       | Callback\<[OnShowFileSelectorEvent](#onshowfileselectorevent12), boolean\> | Yes   | File selection result to be sent to the **Web** component.<br>Return value: boolean<br> The value **true** means that you can invoke the system-provided popup capability. The value **false** means that the custom dialog box drawn in the function is ineffective.|

**Example**

1. Start the file selector.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             console.log('MyFileUploader onShowFileSelector invoked')
             const documentSelectOptions = new picker.DocumentSelectOptions();
             let uri: string | null = null;
             const documentViewPicker = new picker.DocumentViewPicker();
             documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
               uri = documentSelectResult[0];
               console.info('documentViewPicker.select to file succeed and uri is:' + uri);
               if (event) {
                 event.result.handleFileList([uri]);
               }
             }).catch((err: BusinessError) => {
               console.error(`Invoke documentViewPicker.select failed, code is ${err.code},  message is ${err.message}`);
             })
             return true;
           })
       }
     }
   }
   ```

2. Start the photo selector.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';

   @Entry
   @Component
   export struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     async selectFile(result: FileSelectorResult): Promise<void> {
       let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
       let photoPicker = new photoAccessHelper.PhotoViewPicker();
       // Set the MIME file type to IMAGE.
       photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
       // Set the maximum number of media files that can be selected.
       photoSelectOptions.maxSelectNumber = 5;
       let chooseFile: picker.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
       // Obtain the list of selected files.
       result.handleFileList(chooseFile.photoUris);
     }

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             if (event) {
               this.selectFile(event.result);
             }
             return true;
           })
       }
     }
   }
   ```

   HTML file to be loaded:
   ```html
   <!DOCTYPE html>
   <html>
   <head>
     <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
   </head>
   <body>
     <form id="upload-form" enctype="multipart/form-data">
       <input type="file" id="upload" name="upload"/>
       </form>
   </body>
   </html>
   ```

### onResourceLoad<sup>9+</sup>

onResourceLoad(callback: Callback\<OnResourceLoadEvent\>)

Called to notify the **Web** component of the URL of the loaded resource file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnResourceLoadEvent](#onresourceloadevent12)\> | Yes| Callback invoked when a URL is loaded.|

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
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url);
          })
      }
    }
  }
  ```

### onScaleChange<sup>9+</sup>

onScaleChange(callback: Callback\<OnScaleChangeEvent\>)

Called when the display ratio of this page changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScaleChangeEvent](#onscalechangeevent12)\> | Yes| Callback invoked when the display ratio of the page changes.|

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
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale);
          })
      }
    }
  }
  ```

### onUrlLoadIntercept<sup>(deprecated)</sup>

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

Called when the **Web** component is about to access a URL. This API is used to determine whether to block the access, which is allowed by default.
This API is deprecated since API version 10. You are advised to use [onLoadIntercept<sup>10+</sup>](#onloadintercept10) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { data:string \| [WebResourceRequest](#webresourcerequest) }) => boolean | Yes| URL information. Returns **true** if the access is blocked; returns **false** otherwise.|

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
          .onUrlLoadIntercept((event) => {
            if (event) {
              console.log('onUrlLoadIntercept ' + event.data.toString());
            }
            return true
          })
      }
    }
  }
  ```

### onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: Callback<OnInterceptRequestEvent, WebResourceResponse>)

Called when the **Web** component is about to access a URL. This API is used to block the URL and return the response data.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnInterceptRequestEvent](#oninterceptrequestevent12)\> | Yes| Callback invoked when the **Web** component is about to load a URL.<br>The return value is [WebResourceResponse](#webresourceresponse). If response data is returned, the data is loaded based on the response data. If no response data is returned, null is returned, indicating that the data is loaded in the original mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    responseWeb: WebResourceResponse = new WebResourceResponse();
    heads: Header[] = new Array();
    @State webData: string = "<!DOCTYPE html>\n" +
      "<html>\n" +
      "<head>\n" +
      "<title>intercept test</title>\n" +
      "</head>\n" +
      "<body>\n" +
      "<h1>intercept test</h1>\n" +
      "</body>\n" +
      "</html>";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onInterceptRequest((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
            }
            let head1: Header = {
              headerKey: "Connection",
              headerValue: "keep-alive"
            }
            let head2: Header = {
              headerKey: "Cache-Control",
              headerValue: "no-cache"
            }
            // Add a new element to the end of the array and return the length of the new array.
            let length = this.heads.push(head1);
            length = this.heads.push(head2);
            console.log('The response header result length is :' + length);
            const promise: Promise<String> = new Promise((resolve: Function, reject: Function) => {
              this.responseWeb.setResponseHeader(this.heads);
              this.responseWeb.setResponseData(this.webData);
              this.responseWeb.setResponseEncoding('utf-8');
              this.responseWeb.setResponseMimeType('text/html');
              this.responseWeb.setResponseCode(200);
              this.responseWeb.setReasonMessage('OK');
              resolve("success");
            })
            promise.then(() => {
              console.log("prepare response ready");
              this.responseWeb.setResponseIsReady(true);
            })
            this.responseWeb.setResponseIsReady(false);
            return this.responseWeb;
          })
      }
    }
  }
  ```

### onHttpAuthRequest<sup>9+</sup>

onHttpAuthRequest(callback: Callback\<OnHttpAuthRequestEvent, boolean\>)

Called when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnHttpAuthRequestEvent](#onhttpauthrequestevent12), boolean\> | Yes| Callback invoked when the browser requires user credentials.<br>Return value: boolean<br> Returns **true** if the authentication is successful; returns **false** otherwise.  |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    httpAuth: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpAuthRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'onHttpAuthRequest',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.handler.cancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    this.httpAuth = event.handler.isHttpAuthInfoSaved();
                    if (this.httpAuth == false) {
                      webview.WebDataBase.saveHttpAuthCredentials(
                        event.host,
                        event.realm,
                        "2222",
                        "2222"
                      )
                      event.handler.cancel();
                    }
                  }
                },
                cancel: () => {
                  event.handler.cancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```
### onSslErrorEventReceive<sup>9+</sup>

onSslErrorEventReceive(callback: Callback\<OnSslErrorEventReceiveEvent\>)

Called to notify users when an SSL error occurs with a request for the main frame.
To include errors with requests for subframes, use the [OnSslErrorEvent](#onsslerrorevent12) API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSslErrorEventReceiveEvent](#onsslerroreventreceiveevent12)\> | Yes| Callback invoked when the web page receives an SSL error.|

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
          .onSslErrorEventReceive((event) => {
            AlertDialog.show({
              title: 'onSslErrorEventReceive',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel();
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

### onSslErrorEvent<sup>12+</sup>

onSslErrorEvent(callback: OnSslErrorEventCallback)

Called to notify users when an SSL error occurs during the loading of resources (for the main frame and subframes). To handle SSL errors for requests for the main frame, use the **isMainFrame** field to distinguish.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnSslErrorEventCallback](#onsslerroreventcallback12) | Yes| Callback invoked when an SSL error occurs during resource loading.|

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
          .onSslErrorEvent((event: SslErrorEvent) => {
            console.log("onSslErrorEvent url: " + event.url);
            console.log("onSslErrorEvent error: " + event.error);
            console.log("onSslErrorEvent originalUrl: " + event.originalUrl);
            console.log("onSslErrorEvent referrer: " + event.referrer);
            console.log("onSslErrorEvent isFatalError: " + event.isFatalError);
            console.log("onSslErrorEvent isMainFrame: " + event.isMainFrame);
            AlertDialog.show({
              title: 'onSslErrorEvent',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel();
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

### onClientAuthenticationRequest<sup>9+</sup>

onClientAuthenticationRequest(callback: Callback\<OnClientAuthenticationEvent\>)

Called when an SSL client certificate request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnClientAuthenticationEvent](#onclientauthenticationevent12)\> | Yes| Callback invoked when an SSL client certificate is required from the user. |

  **Example**

  This example shows two-way authentication when interconnection with certificate management is not supported.

  ```ts
  // xxx.ets API9
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

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
                  event.handler.confirm("/system/etc/user.pk8", "/system/etc/chain-user.pem");
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel();
                }
              },
              cancel: () => {
                event.handler.ignore();
              }
            })
          })
      }
    }
  }
  ```

  This example shows two-way authentication when interconnection with certificate management is supported.

  1. Construct the singleton object **GlobalContext**.

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


  2. Implement two-way authentication.

     ```ts
     // xxx.ets API10
     import { webview } from '@kit.ArkWeb';
     import { common, Want, bundleManager } from '@kit.AbilityKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { GlobalContext } from '../GlobalContext';

     let uri = "";

     export default class CertManagerService {
       private static sInstance: CertManagerService;
       private authUri = "";
       private appUid = "";

       public static getInstance(): CertManagerService {
         if (CertManagerService.sInstance == null) {
           CertManagerService.sInstance = new CertManagerService();
         }
         return CertManagerService.sInstance;
       }

       async grantAppPm(callback: (message: string) => void) {
         let message = '';
         let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION;
         // Note: Replace com.example.myapplication with the actual application name.
         try {
           bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
             console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
            this.appUid = data.appInfo.uid.toString();
           }).catch((err: BusinessError) => {
             console.error('getBundleInfoForSelf failed. Cause: %{public}s', err.message);
           });
         } catch (err) {
           let message = (err as BusinessError).message;
           console.error('getBundleInfoForSelf failed: %{public}s', message);
         }

         // Note: Add GlobalContext.getContext().setObject("AbilityContext", this.context) to the onCreate function in the MainAbility.ts file.
         let abilityContext = GlobalContext.getContext().getObject("AbilityContext") as common.UIAbilityContext
         await abilityContext.startAbilityForResult(
           {
             bundleName: "com.ohos.certmanager",
             abilityName: "MainAbility",
             uri: "requestAuthorize",
             parameters: {
               appUid: this.appUid, // Pass the UID of the requesting application.
             }
           } as Want)
           .then((data: common.AbilityResult) => {
             if (!data.resultCode && data.want) {
               if (data.want.parameters) {
                 this.authUri = data.want.parameters.authUri as string; // Obtain the returned authUri after successful authorization.
               }
             }
           })
         message += "after grantAppPm authUri: " + this.authUri;
         uri = this.authUri;
         callback(message)
       }
     }

     @Entry
     @Component
     struct WebComponent {
       controller: webview.WebviewController = new webview.WebviewController();
       @State message: string = 'Hello World' // message is used for debugging and observation.
       certManager = CertManagerService.getInstance();

       build() {
         Row() {
           Column() {
             Row() {
               // Step 1: Perform authorization to obtain the URI.
               Button('GrantApp')
                 .onClick(() => {
                   this.certManager.grantAppPm((data) => {
                     this.message = data;
                   });
                 })
               // Step 2: After the authorization, in two-way authentication, the onClientAuthenticationRequest callback is used to send the URI to the web server for authentication.
               Button("ClientCertAuth")
                 .onClick(() => {
                   this.controller.loadUrl('https://www.example2.com'); // Server website that supports two-way authentication.
                 })
             }

             Web({ src: 'https://www.example1.com', controller: this.controller })
               .fileAccess(true)
               .javaScriptAccess(true)
               .domStorageAccess(true)
               .onlineImageAccess(true)

               .onClientAuthenticationRequest((event) => {
                 AlertDialog.show({
                   title: 'ClientAuth',
                   message: 'Text',
                   confirm: {
                     value: 'Confirm',
                     action: () => {
                       event.handler.confirm(uri);
                     }
                   },
                   cancel: () => {
                     event.handler.cancel();
                   }
                 })
               })
           }
         }
         .width('100%')
         .height('100%')
       }
     }
     ```

### onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: Callback\<OnPermissionRequestEvent\>)

Called when a permission request is received. To call this API, you need to declare the **ohos.permission.CAMERA** and **ohos.permission.MICROPHONE** permissions.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnPermissionRequestEvent](#onpermissionrequestevent12)\> | Yes| Callback invoked when a permission request is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl } from '@kit.AbilityKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(getContext(this), ['ohos.permission.CAMERA', 'ohos.permission.MICROPHONE'])
        .then((data) => {
          console.info('data:' + JSON.stringify(data));
          console.info('data permissions:' + data.permissions);
          console.info('data authResults:' + data.authResults);
        }).catch((error: BusinessError) => {
        console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
      })
    }

    build() {
      Column() {
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
  <video id="video" width="500px" height="500px" autoplay="autoplay"></video>
  <canvas id="canvas" width="500px" height="500px"></canvas>
  <br>
  <input type="button" title="HTML5 Camera" value="Enable Camera" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // Obtain the video camera area.
      let video = document.getElementById("video");
      // Returned Promise object
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then() is asynchronous. Invoke the MediaStream object as a parameter.
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      });
    }
  </script>
  </body>
  </html>
 ```

### onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: Callback\<OnContextMenuShowEvent, boolean\>)

Called when a context menu is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnContextMenuShowEvent](#oncontextmenushowevent12), boolean\> | Yes| Callback invoked during a call to allow for the display of a custom context menu.<br>Return value: boolean<br> The value **true** means a valid custom menu, and **false** means an invalid custom menu.    |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { pasteboard } from '@kit.BasicServicesKit';

  const TAG = 'ContextMenu';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    private result: WebContextMenuResult | undefined = undefined;
    @State linkUrl: string = '';
    @State offsetX: number = 0;
    @State offsetY: number = 0;
    @State showMenu: boolean = false;

    @Builder
    // Build and trigger a custom menu.
    MenuBuilder() {
      // A component that is used to present a vertical list of items to the user.
      Menu() {
        // A component that is used to represent an item in a menu.
        MenuItem({
          content: 'Copy Image',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copyImage();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Cut',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.cut();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Copy',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copy();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Paste',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.paste();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Copy Link',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            let pasteData = pasteboard.createData('text/plain', this.linkUrl);
            pasteboard.getSystemPasteboard().setData(pasteData, (error) => {
              if (error) {
                return;
              }
            })
            this.showMenu = false;
          })
        MenuItem({
          content: 'Select All',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.selectAll();
            this.showMenu = false;
          })
      }
      .width(150)
      .height(300)
    }

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          // Trigger a custom dialog box.
          .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result
              console.info("x coord = " + event.param.x());
              console.info("link url = " + event.param.getLinkUrl());
              this.linkUrl = event.param.getLinkUrl();
            }
            console.info(TAG, `x: ${this.offsetX}, y: ${this.offsetY}`);
            this.showMenu = true;
            this.offsetX = 250;
            this.offsetY = Math.max(px2vp(event?.param.y() ?? 0) - 0, 0);
            return true;
          })
          .bindPopup(this.showMenu,
            {
              builder: this.MenuBuilder(),
              enableArrow: false,
              placement: Placement.LeftTop,
              offset: { x: this.offsetX, y: this.offsetY },
              mask: false,
              onStateChange: (e) => {
                if (!e.isVisible) {
                  this.showMenu = false;
                  this.result!.closeContextMenu();
                }
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
  <html lang="en">
  <body>
    <h1>onContextMenuShow</h1>
    <a href="http://www.example.com" style="font-size:27px">URL www.example.com</a>
    // Place any image in the rawfile directory and name it example.png.
    <div><img src="example.png"></div>
    <p>Right-click text to display the context menu</p>
  </body>
  </html>
  ```

### onContextMenuHide<sup>11+</sup>

onContextMenuHide(callback: OnContextMenuHideCallback)

Called when a context menu is hidden after the user clicks the right mouse button or long presses a specific element, such as an image or a link.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnContextMenuHideCallback](#oncontextmenuhidecallback11) | Yes| Parameters related to the context menu.    |

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
          .onContextMenuHide(() => {
            console.log("onContextMenuHide callback");
          })
      }
    }
  }
  ```

### onScroll<sup>9+</sup>

onScroll(callback: Callback\<OnScrollEvent\>)

Called when the scrollbar of the page scrolls.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScrollEvent](#onscrollevent12)\> | Yes| Callback invoked when the scrollbar scrolls to a specified position.|

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
          .onScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

### onGeolocationShow

onGeolocationShow(callback: Callback\<OnGeolocationShowEvent\>)

Called when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback      | Callback\<[OnGeolocationShowEvent](#ongeolocationshowevent12)\>  | Yes| Callback invoked when a request to obtain the geolocation information is received.    |

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
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title',
                message: 'text',
                confirm: {
                  value: 'onConfirm',
                  action: () => {
                    event.geolocation.invoke(event.origin, true, true);
                  }
                },
                cancel: () => {
                  event.geolocation.invoke(event.origin, false, true);
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
  <!DOCTYPE html>
  <html>
  <body>
  <p id="locationInfo">Location information</p>
  <button onclick="getLocation()">Get Location</button>
  <script>
  var locationInfo=document.getElementById("locationInfo");
  function getLocation(){
    if (navigator.geolocation) {
      <!-- Access to the device location by the frontend page -->
      navigator.geolocation.getCurrentPosition(showPosition);
    }
  }
  function showPosition(position){
    locationInfo.innerHTML="Latitude: " + position.coords.latitude + "<br />Longitude: " + position.coords.longitude;
  }
  </script>
  </body>
  </html>
  ```

### onGeolocationHide

onGeolocationHide(callback: () => void)

Called to notify the user that the request for obtaining the geolocation information received when [onGeolocationShow](#ongeolocationshow) is called has been canceled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the request for obtaining geolocation information has been canceled. |

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
          .geolocationAccess(true)
          .onGeolocationHide(() => {
            console.log("onGeolocationHide...");
          })
      }
    }
  }
  ```

### onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: OnFullScreenEnterCallback)

Called when the **Web** component enters full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFullScreenEnterCallback](#onfullscreenentercallback12) | Yes| Callback invoked when the **Web** component enters full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenEnter((event) => {
            console.log("onFullScreenEnter videoWidth: " + event.videoWidth +
              ", videoHeight: " + event.videoHeight);
            // The application can proactively exit fullscreen mode by calling this.handler.exitFullScreen().
            this.handler = event.handler;
          })
      }
    }
  }
  ```

### onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

Called when the **Web** component exits full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the component exits full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenExit(() => {
            console.log("onFullScreenExit...")
            if (this.handler) {
              this.handler.exitFullScreen();
            }
          })
          .onFullScreenEnter((event) => {
            this.handler = event.handler;
          })
      }
    }
  }
  ```

### onWindowNew<sup>9+</sup>

onWindowNew(callback: Callback\<OnWindowNewEvent\>)

Called to notify the user of a new window creation request, when **multiWindowAccess** is enabled.
If the **event.handler.setWebController** API is not called, the render process will be blocked.
If opening a new window is not needed, set the parameter to **null** when calling the **event.handler.setWebController** API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | Callback\<[OnWindowNewEvent](#onwindownewevent12)\>           | Yes| Callback invoked when the web page requests the user to create a new window.   |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // There are two Web components on the same page. When the WebComponent object opens a new window, the NewWebViewComp object is displayed. 
  @CustomDialog
  struct NewWebViewComp {
    controller?: CustomDialogController;
    webviewController1: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            console.info("NewWebViewComp onWindowExit");
            if (this.controller) {
              this.controller.close();
            }
          })
      }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          // MultiWindowAccess needs to be enabled.
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close();
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController })
            })
            this.dialogController.open();
            // Return the WebviewController object corresponding to the new window to the Web kernel.
            // If opening a new window is not needed, set the parameter to null when calling the event.handler.setWebController API.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

### onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

Called when this window is closed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the window is closed.|

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
          .onWindowExit(() => {
            console.log("onWindowExit...");
          })
      }
    }
  }
  ```

### onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: Callback\<OnSearchResultReceiveEvent\>)

Called to notify the caller of the search result on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSearchResultReceiveEvent](#onsearchresultreceiveevent12)\>  | Yes| Callback invoked to notify the caller of the search result on the web page.        |

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

### onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: Callback\<OnDataResubmittedEvent\>)

Called when the web form data can be resubmitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnDataResubmittedEvent](#ondataresubmittedevent12)\> | Yes| Callback invoked when the web form data can be resubmitted.|

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
        // After you click Submit on the web page, you can click Refresh to trigger the function again.
        Button('refresh')
          .onClick(() => {
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
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
    <form action="http://httpbin.org/post" method="post">
      <input type="text" name="username">
      <input type="submit" name="Submit">
    </form>
  </body>
  </html>
 ```

### onPageVisible<sup>9+</sup>

onPageVisible(callback: Callback\<OnPageVisibleEvent\>)

Called when the old page is not displayed and the new page is about to be visible.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnPageVisibleEvent](#onpagevisibleevent12)\> | Yes| Callback invoked when the old page is not displayed and the new page is about to be visible.|

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
          .onPageVisible((event) => {
            console.log('onPageVisible url:' + event.url);
          })
      }
    }
  }
  ```

### onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

Called when the key event is intercepted and before it is consumed by the webview.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | (event:[KeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent)) => boolean| Yes| Key event that is triggered. Return value: Whether to continue to transfer the key event to the webview kernel.|

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
          .onInterceptKeyEvent((event) => {
            if (event.keyCode == 2017 || event.keyCode == 2018) {
              console.info(`onInterceptKeyEvent get event.keyCode ${event.keyCode}`);
              return true;
            }
            return false;
          })
      }
    }
  }
  ```

### onTouchIconUrlReceived<sup>9+</sup>

onTouchIconUrlReceived(callback: Callback\<OnTouchIconUrlReceivedEvent\>)

Called when an apple-touch-icon URL is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnTouchIconUrlReceivedEvent](#ontouchiconurlreceivedevent12)\>  | Yes| Callback invoked when an apple-touch-icon URL is received.|

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
        Web({ src: 'www.baidu.com', controller: this.controller })
          .onTouchIconUrlReceived((event) => {
            console.log('onTouchIconUrlReceived:' + JSON.stringify(event));
          })
      }
    }
  }
  ```

### onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: Callback\<OnFaviconReceivedEvent\>)

Called when this web page receives a new favicon.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnFaviconReceivedEvent](#onfaviconreceivedevent12)\> | Yes| Callback invoked when the current web page receives a new favicon.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { image } from '@kit.ImageKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State icon: image.PixelMap | undefined = undefined;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFaviconReceived((event) => {
            console.log('onFaviconReceived');
            this.icon = event.favicon;
          })
      }
    }
  }
  ```

### onAudioStateChanged<sup>10+</sup>

onAudioStateChanged(callback: Callback\<OnAudioStateChangedEvent\>)

Called when the audio playback status on the web page changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnAudioStateChangedEvent](#onaudiostatechangedevent12)\> | Yes| Callback invoked when the audio playback status on the web page changes.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State playing: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onAudioStateChanged(event => {
            this.playing = event.playing;
            console.debug('onAudioStateChanged playing: ' + this.playing);
          })
      }
    }
  }
  ```

### onFirstContentfulPaint<sup>10+</sup>

 onFirstContentfulPaint(callback: Callback\<OnFirstContentfulPaintEvent\>)

Called when the first content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback    | Callback\<[OnFirstContentfulPaintEvent](#onfirstcontentfulpaintevent12)\> | Yes| Callback invoked when the first content paint occurs on the web page.         |

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
          .onFirstContentfulPaint(event => {
            if (event) {
              console.log("onFirstContentfulPaint:" + "[navigationStartTick]:" +
              event.navigationStartTick + ", [firstContentfulPaintMs]:" +
              event.firstContentfulPaintMs);
            }
          })
      }
    }
  }
  ```

### onFirstMeaningfulPaint<sup>12+</sup>

onFirstMeaningfulPaint(callback: [OnFirstMeaningfulPaintCallback](#onfirstmeaningfulpaintcallback12))

Called when the first meaningful paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFirstMeaningfulPaintCallback](#onfirstmeaningfulpaintcallback12) | Yes| Callback invoked when the First Meaningful Paint occurs on the web page.|

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
          .onFirstMeaningfulPaint((details) => {
            console.log("onFirstMeaningfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [firstMeaningfulPaintTime]=" + details.firstMeaningfulPaintTime);
          })
      }
    }
  }
  ```

### onLargestContentfulPaint<sup>12+</sup>

onLargestContentfulPaint(callback: [OnLargestContentfulPaintCallback](#onlargestcontentfulpaintcallback12))

Called when the largest content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnLargestContentfulPaintCallback](#onlargestcontentfulpaintcallback12) | Yes| Callback invoked when the largest content paint occurs on the web page.|

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
          .onLargestContentfulPaint((details) => {
            console.log("onLargestContentfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [largestImagePaintTime]=" + details.largestImagePaintTime +
              ", [largestTextPaintTime]=" + details.largestTextPaintTime +
              ", [largestImageLoadStartTime]=" + details.largestImageLoadStartTime +
              ", [largestImageLoadEndTime]=" + details.largestImageLoadEndTime +
              ", [imageBPP]=" + details.imageBPP);
          })
      }
    }
  }
  ```

### onLoadIntercept<sup>10+</sup>

onLoadIntercept(callback: Callback\<OnLoadInterceptEvent, boolean\>)

Called when the **Web** component is about to access a URL. This API is used to determine whether to block the access, which is allowed by default.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnLoadInterceptEvent](#onloadinterceptevent12), boolean\> | Yes| Callback invoked when the **Web** component is about to access a URL.<br>Return value: boolean<br> Returns **true** if the access is blocked; returns **false** otherwise.|

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
          .onLoadIntercept((event) => {
            console.log('url:' + event.data.getRequestUrl());
            console.log('isMainFrame:' + event.data.isMainFrame());
            console.log('isRedirect:' + event.data.isRedirect());
            console.log('isRequestGesture:' + event.data.isRequestGesture());
            return true;
          })
      }
    }
  }
  ```

### onRequestSelected

onRequestSelected(callback: () => void)

Called when the **Web** component obtains the focus.

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
        Web({ src: 'www.example.com', controller: this.controller })
          .onRequestSelected(() => {
            console.log('onRequestSelected');
          })
      }
    }
  }
  ```
### onScreenCaptureRequest<sup>10+</sup>

onScreenCaptureRequest(callback: Callback\<OnScreenCaptureRequestEvent\>)

Called when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScreenCaptureRequestEvent](#onscreencapturerequestevent12)\> | Yes| Called when a screen capture request is received.|

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
          .onScreenCaptureRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title: ' + event.handler.getOrigin(),
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.handler.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.handler.grant({ captureMode: WebCaptureMode.HOME_SCREEN });
                  }
                },
                cancel: () => {
                  event.handler.deny();
                }
              })
            }
          })
      }
    }
  }
  ```

### onOverScroll<sup>10+</sup>

onOverScroll(callback: Callback\<OnOverScrollEvent\>)

Called when the web page is overscrolled. It is used to notify the user of the offset of the overscroll.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnOverScrollEvent](#onoverscrollevent12)\> | Yes| Callback invoked when the web page is overscrolled.|

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
          .onOverScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

### onControllerAttached<sup>10+</sup>

onControllerAttached(callback: () => void)

Called when the controller is successfully bound to the **Web** component. The controller must be WebviewController. Do not call APIs related to the **Web** component before this callback event. Otherwise, a js-error exception will be thrown.
As the web page is not yet loaded when this callback is called, APIs for operating the web page, for example, [zoomIn](js-apis-webview.md#zoomin) and [zoomOut](js-apis-webview.md#zoomout), cannot be used in the callback. Other APIs, such as [loadUrl](js-apis-webview.md#loadurl) and [getWebId](js-apis-webview.md#getwebid), which do not involve web page operations, can be used properly.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

The following example uses **loadUrl** in the callback to load the web page.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: '', controller: this.controller })
          .onControllerAttached(() => {
            this.controller.loadUrl($rawfile("index.html"));
          })
      }
    }
  }
  ```

The following example uses **getWebId** in the callback
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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onControllerAttached(() => {
            try {
              let id = this.controller.getWebId();
              console.log("id: " + id);
            } catch (error) {
              let code = (error as BusinessError).code;
              let message = (error as BusinessError).message;
              console.error(`ErrorCode: ${code},  Message: ${message}`);
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
          <p>Hello World</p>
      </body>
  </html>
  ```

### onNavigationEntryCommitted<sup>11+</sup>

onNavigationEntryCommitted(callback: [OnNavigationEntryCommittedCallback](#onnavigationentrycommittedcallback11))

Called when a web page redirection request is submitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNavigationEntryCommittedCallback](#onnavigationentrycommittedcallback11) | Yes| Callback invoked when a web page redirection request is submitted.|

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
          .onNavigationEntryCommitted((details) => {
            console.log("onNavigationEntryCommitted: [isMainFrame]= " + details.isMainFrame +
              ", [isSameDocument]=" + details.isSameDocument +
              ", [didReplaceEntry]=" + details.didReplaceEntry +
              ", [navigationType]=" + details.navigationType +
              ", [url]=" + details.url);
          })
      }
    }
  }
  ```

### onSafeBrowsingCheckResult<sup>11+</sup>

onSafeBrowsingCheckResult(callback: OnSafeBrowsingCheckResultCallback)

Called when the safe browsing check result is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnSafeBrowsingCheckResultCallback](#onsafebrowsingcheckresultcallback11) | Yes| Called when the safe browsing check result is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  export enum ThreatType {
    UNKNOWN = -1,
    THREAT_ILLEGAL = 0,
    THREAT_FRAUD = 1,
    THREAT_RISK = 2,
    THREAT_WARNING = 3,
  }

  export class OnSafeBrowsingCheckResultCallback {
    threatType: ThreatType = ThreatType.UNKNOWN;
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSafeBrowsingCheckResult((callback) => {
            let jsonData = JSON.stringify(callback);
            let json: OnSafeBrowsingCheckResultCallback = JSON.parse(jsonData);
            console.log("onSafeBrowsingCheckResult: [threatType]= " + json.threatType);
          })
      }
    }
  }
  ```

### onNativeEmbedLifecycleChange<sup>11+</sup>

onNativeEmbedLifecycleChange(callback: (event: NativeEmbedDataInfo) => void)

Called when the lifecycle of the same-layer **Embed** tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedDataInfo](#nativeembeddatainfo11)) => void | Yes| Callback invoked when the lifecycle of the same-layer tag changes.|

**Example**

```ts
// EntryAbility.ets

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    // Added in API version 12: feature to enable the back/forward cache for same-layer rendering.
    let features = new webview.BackForwardCacheSupportedFeatures();
    features.nativeEmbed = true;
    features.mediaTakeOver = true;
    webview.WebviewController.enableBackForwardCache(features);
    webview.WebviewController.initializeWebEngine();
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
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
    @State embedStatus: string = '';
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Default behavior: Click the button to navigate to a new page, close the index page, and destroy the same-layer tag.
        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking the button navigates to a new page, closes the index page, and puts the same-layer tag into BFCache.
        Button('Destroy')
        .onClick(() => {
          try {
            this.controller.loadUrl("www.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking the button to return to the page causes the same-layer tag to exit BFCache.
        Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking a button to advance to the next page causes the same-layer tag to enter BFCache.
        Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })


        // Added in API version 12: The Web kernel does not allow web pages loaded with non-HTTP and non-HTTPS protocols to enter BFCache.
        // Therefore, to test the ENTER_BFCACHE/LEAVE_BFCACHE states, you need to place the index.html on a web server and load it using the HTTP or HTTPS protocol. Example:
        // Web({ src: "http://xxxx/index.html", controller: this.controller })
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .onNativeEmbedLifecycleChange((event) => {
            // The Create event is triggered when the same-layer tag is detected on the loaded page.
            if (event.status == NativeEmbedStatus.CREATE) {
              this.embedStatus = 'Create';
            }
            // The Update event is triggered when the same-layer tag on the page is moved or scaled.
            if (event.status == NativeEmbedStatus.UPDATE) {
              this.embedStatus = 'Update';
            }
            // The Destroy event is triggered when you exit the page.
            if (event.status == NativeEmbedStatus.DESTROY) {
              this.embedStatus = 'Destroy';
            }
            // The Enter BFCache event is triggered when the page with the same-layer tag enters BFCache.
            if (event.status == NativeEmbedStatus.ENTER_BFCACHE) {
              this.embedStatus = 'Enter BFCache';
            }
            // The Leave BFCache event is triggered when the page with the same-layer tag leaves BFCache.
            if (event.status == NativeEmbedStatus.LEAVE_BFCACHE) {
              this.embedStatus = 'Leave BFCache';
            }
            console.log("status = " + this.embedStatus);
            console.log("surfaceId = " + event.surfaceId);
            console.log("embedId = " + event.embedId);
            if (event.info) {
              console.log("id = " + event.info.id);
              console.log("type = " + event.info.type);
              console.log("src = " + event.info.src);
              console.log("width = " + event.info.width);
              console.log("height = " + event.info.height);
              console.log("url = " + event.info.url);
            }
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```
  <!-- index.html -->
  <!Document>
  <html>
  <head>
      <title>Same-layer rendering test HTML</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test? params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

### onNativeEmbedGestureEvent<sup>11+</sup>

onNativeEmbedGestureEvent(callback: (event: NativeEmbedTouchInfo) => void)

Called when a finger touches a same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedTouchInfo](#nativeembedtouchinfo11)) => void | Yes| Callback invoked when a finger touches a same-layer tag.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class nodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State eventType: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: px2vp(embed.info?.width),
                  height: px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedGestureEvent((event) => {
              if (event && event.touchEvent) {
                if (event.touchEvent.type == TouchType.Down) {
                  this.eventType = 'Down'
                }
                if (event.touchEvent.type == TouchType.Up) {
                  this.eventType = 'Up'
                }
                if (event.touchEvent.type == TouchType.Move) {
                  this.eventType = 'Move'
                }
                if (event.touchEvent.type == TouchType.Cancel) {
                  this.eventType = 'Cancel'
                }
                let ret = this.nodeController.postEvent(event.touchEvent)
                if (event.result) {
                  event.result.setGestureEventResult(ret);
                }
                console.log("embedId = " + event.embedId);
                console.log("touchType = " + this.eventType);
                console.log("x = " + event.touchEvent.touches[0].x);
                console.log("y = " + event.touchEvent.touches[0].y);
                console.log("Component globalPos:(" + event.touchEvent.target.area.globalPosition.x + "," + event.touchEvent.target.area.globalPosition.y + ")");
                console.log("width = " + event.touchEvent.target.area.width);
                console.log("height = " + event.touchEvent.target.area.height);
              }
            })
        }
      }
    }
  }
  ```
HTML file to be loaded:
  ```
  <!-- index.html -->
  <!Document>
<html>
<head>
    <title>Same-layer rendering test HTML</title>
    <meta name="viewport">
</head>
<body>
<div>
    <div id="bodyId">
        <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
    </div>
</div>
</body>
</html>
  ```

### onIntelligentTrackingPreventionResult<sup>12+</sup>

onIntelligentTrackingPreventionResult(callback: OnIntelligentTrackingPreventionCallback)

Called when the intelligent tracking prevention feature is enabled and the tracker cookie is blocked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback    | [OnIntelligentTrackingPreventionCallback](#onintelligenttrackingpreventioncallback12) | Yes| Callback invoked when the intelligent tracking prevention feature is enabled and the tracker cookie is blocked.|

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
        // The onIntelligentTrackingPreventionResult callback is triggered only when the intelligent tracking prevention is enabled.
        Button('enableIntelligentTrackingPrevention')
          .onClick(() => {
            try {
              this.controller.enableIntelligentTrackingPrevention(true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .onIntelligentTrackingPreventionResult((details) => {
            console.log("onIntelligentTrackingPreventionResult: [websiteHost]= " + details.host +
              ", [trackerHost]=" + details.trackerHost);
          })
      }
    }
  }
  ```

### onOverrideUrlLoading<sup>12+</sup>

onOverrideUrlLoading(callback: OnOverrideUrlLoadingCallback)

Called to enable the host application to obtain control when the URL is about to be loaded to this **Web** component. If the callback returns **true**, the **\<Web>** component stops loading the URL. If the callback returns **false**, the **Web** component continues to load the URL.

POST requests do not trigger this callback.

This callback is triggered when the **iframe** loads the redirection of a non-HTTP(s) protocol, but is not triggered when the **iframe** loads the HTTP(s) protocol or **about:blank** and when the redirection initiated by **loadUrl(String)** is called.

Do not use the same URL to call the **loadUrl(String)** API and then return **true**. Doing so would unnecessarily cancel the current loading and start a new load with the same URL. The correct way to continue loading the given URL is to simply return **false**, rather than calling **loadUrl(String)**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnOverrideUrlLoadingCallback](#onoverrideurlloadingcallback12) | Yes| Callback for **onOverrideUrlLoading**.|

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
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onOverrideUrlLoading((webResourceRequest: WebResourceRequest) => {
            if (webResourceRequest && webResourceRequest.getRequestUrl() == "about:blank") {
              return true;
            }
            return false;
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
    <title>Test Web Page</title>
  </head>
  <body>
    <h1>onOverrideUrlLoading Demo</h1>
    <a href="about:blank">Click here</a>// to visit about:blank.
  </body>
  </html>
  ```

### onViewportFitChanged<sup>12+</sup>

onViewportFitChanged(callback: OnViewportFitChangedCallback)

Called when the **viewport-fit** configuration in the web page's **\<meta>** tag changes. The application can adapt its layout to the viewport within this callback.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnViewportFitChangedCallback](#onviewportfitchangedcallback12) | Yes| Callback invoked when the **viewport-fit** configuration in the web page's **\<meta>** tag changes.|

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
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onViewportFitChanged((data) => {
            let jsonData = JSON.stringify(data);
            let viewportFit: ViewportFit = JSON.parse(jsonData).viewportFit;
            if (viewportFit === ViewportFit.COVER) {
              // The index.html web page supports immersive layout. You can call expandSafeArea to adjust the Web component layout viewport to cover the safe area (status bar or navigation bar).
            } else if (viewportFit === ViewportFit.CONTAINS) {
              // The index.html web page does not support immersive layout. You can call expandSafeArea to adjust the Web component layout viewport as a safe area.
            } else {
              // Default value. No processing is required.
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
      <meta name="viewport" content="width=device-width,viewport-fit=cover">
    </head>
    <body>
      <div style="position: absolute; bottom: 0; margin-bottom: env(safe-area-inset-bottom)"></div>
    </body>
  </html>
  ```

### onInterceptKeyboardAttach<sup>12+</sup>

onInterceptKeyboardAttach(callback: WebKeyboardCallback)

Called before any editable element (such as the **\<input>** tag) on the web page invokes the soft keyboard. The application can use this API to intercept the display of the system's soft keyboard and configure a custom soft keyboard. (With this API, the application can determine whether to use the system's default soft keyboard, a system soft keyboard with a custom Enter key, or a completely application-defined soft keyboard).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [WebKeyboardCallback](#webkeyboardcallback12) | Yes| Callback invoked for intercepting the soft keyboard invoking in the web page.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { inputMethodEngine } from '@kit.IMEKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    webKeyboardController: WebKeyboardController = new WebKeyboardController()
    inputAttributeMap: Map<string, number> = new Map([
        ['UNSPECIFIED', inputMethodEngine.ENTER_KEY_TYPE_UNSPECIFIED],
        ['GO', inputMethodEngine.ENTER_KEY_TYPE_GO],
        ['SEARCH', inputMethodEngine.ENTER_KEY_TYPE_SEARCH],
        ['SEND', inputMethodEngine.ENTER_KEY_TYPE_SEND],
        ['NEXT', inputMethodEngine.ENTER_KEY_TYPE_NEXT],
        ['DONE', inputMethodEngine.ENTER_KEY_TYPE_DONE],
        ['PREVIOUS', inputMethodEngine.ENTER_KEY_TYPE_PREVIOUS]
      ])

      /**
       * Builder for a custom keyboard component
       */
      @Builder
      customKeyboardBuilder() {
		  // Implement a custom keyboard component and connect to the WebKeyboardController to implement operations such as input, deletion, and close.
        Row() {
          Text("Finish")
            .fontSize(20)
            .fontColor(Color.Blue)
            .onClick(() => {
              this.webKeyboardController.close();
            })
          // Insert characters.
          Button("insertText").onClick(() => {
            this.webKeyboardController.insertText('insert ');
          }).margin({
            bottom: 200,
          })
          // Delete characters from the end to the beginning for the length specified by the length parameter.
          Button("deleteForward").onClick(() => {
            this.webKeyboardController.deleteForward(1);
          }).margin({
            bottom: 200,
          })
          // Delete characters from the beginning to the end for the length specified by the length parameter.
          Button("deleteBackward").onClick(() => {
            this.webKeyboardController.deleteBackward(1);
          }).margin({
            left: -220,
          })
          // Insert a function key.
          Button("sendFunctionKey").onClick(() => {
            this.webKeyboardController.sendFunctionKey(6);
          })
        }
      }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .onInterceptKeyboardAttach((KeyboardCallbackInfo) => {
          // Initialize option. By default, the default keyboard is used.
          let option: WebKeyboardOptions = {
            useSystemKeyboard: true,
          };
          if (!KeyboardCallbackInfo) {
            return option;
          }

          // Save the WebKeyboardController. When using a custom keyboard, this handler is required to control behaviors such as input, deletion, and closing of the soft keyboard.
          this.webKeyboardController = KeyboardCallbackInfo.controller
          let attributes: Record<string, string> = KeyboardCallbackInfo.attributes
          // Traverse attributes.
          let attributeKeys = Object.keys(attributes)
          for (let i = 0; i < attributeKeys.length; i++) {
            console.log('WebCustomKeyboard key = ' + attributeKeys[i] + ', value = ' + attributes[attributeKeys[i]])
          }

          if (attributes) {
            if (attributes['data-keyboard'] == 'customKeyboard') {
              // Determine the soft keyboard to use based on the attributes of editable HTML elements. For example, if the attribute includes data-keyboard and its value is customKeyboard, use a custom keyboard.
              console.log('WebCustomKeyboard use custom keyboard')
              option.useSystemKeyboard = false;
              // Sets the custom keyboard builder.
              option.customKeyboard = () => {
                this.customKeyboardBuilder()
              }
              return option;
            }

            if (attributes['keyboard-return'] != undefined) {
              // Determine the soft keyboard to use based on the attributes of editable HTML elements. For example, if the attribute includes keyboard-return, use the system keyboard and specify the type of the system soft keyboard's Enter key.
              option.useSystemKeyboard = true;
              let enterKeyType: number | undefined = this.inputAttributeMap.get(attributes['keyboard-return'])
              if (enterKeyType != undefined) {
                option.enterKeyType = enterKeyType
              }
              return option;
            }
          }

          return option;
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
        <meta name="viewport" content="width=device-width,minimum-scale=1.0,maximum-scale=1.0">
    </head>

    <body>

    <p style="font-size:12px">input tag. Original default behavior: </p>
    <input type="text" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as UNSPECIFIED: </p>
    <input type="text" keyboard-return="UNSPECIFIED" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as GO: </p>
    <input type="text" keyboard-return="GO" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as SEARCH: </p>
    <input type="text" keyboard-return="SEARCH" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as SEND: </p>
    <input type="text" keyboard-return="SEND" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as NEXT: </p>
    <input type="text" keyboard-return="NEXT" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as DONE: </p>
    <input type="text" keyboard-return="DONE" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as PREVIOUS: </p>
    <input type="text" keyboard-return="PREVIOUS" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. Custom keyboard: </p>
    <input type="text" data-keyboard="customKeyboard" style="width: 300px; height: 20px"><br>

    </body>

    </html>
  ```

### onNativeEmbedVisibilityChange<sup>12+</sup>

onNativeEmbedVisibilityChange(callback: OnNativeEmbedVisibilityChangeCallback)

Called when the visibility of a same-layer tag (such as an **Embed** tag or an **Object** tag) on a web page changes in the viewport. By default, the same-layer tag is invisible. If the rendering tag is visible when you access the page for the first time, the callback is triggered; otherwise, it is not triggered. That is, if the same-layer tag changes from a non-zero value to **0 x 0**, the callback is triggered. If the rendering tag size changes from **0 x 0** to a non-zero value, the callback is not triggered. If all the same-layer tags are invisible, they are reported as invisible. If all the same-layer rendering tags or part of them are visible, they are reported as invisible.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNativeEmbedVisibilityChangeCallback](#onnativeembedvisibilitychangecallback12) | Yes| Called when the visibility of a same-layer tag changes.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class nodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State embedVisibility: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: px2vp(embed.info?.width),
                  height: px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedVisibilityChange((embed) => {
              if (embed.visibility) {
                this.embedVisibility = 'Visible';
              } else {
                this.embedVisibility = 'Hidden';
              }
              console.log("embedId = " + embed.embedId);
              console.log("visibility = " + embed.visibility);
            })
        }
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
      <title>Same-layer rendering test HTML</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## WebKeyboardCallback<sup>12+</sup>

type WebKeyboardCallback = (keyboardCallbackInfo: WebKeyboardCallbackInfo) => WebKeyboardOptions

Called to intercept the soft keyboard from editable elements on a web page. This event is typically called when the **\<input>** tag on the web page is clicked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| keyboardCallbackInfo    | [WebKeyboardCallbackInfo](#webkeyboardcallbackinfo12) | Yes   | Input parameter of the callback for intercepting the soft keyboard from editable elements on a web page, including [WebKeyboardController](#webkeyboardcontroller12) and editable element attributes. |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| [WebKeyboardOptions](#webkeyboardoptions12) | [WebKeyboardOptions](#webkeyboardoptions12) instance, which is used to determine which type of soft keyboard to start by the ArkWeb rendering engine.|

## WebKeyboardCallbackInfo<sup>12+</sup>

Represents the input parameter of the callback for intercepting the soft keyboard from editable elements on a web page, including [WebKeyboardController](#webkeyboardcontroller12) and editable element attributes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| controller | [WebKeyboardController](#webkeyboardcontroller12)  | Yes   | Controller used to control the input, deletion, and closure of the custom keyboard.|
| attributes | Record<string, string> | Yes   | Attributes of the web page element that triggered the soft keyboard to pop up.

## WebKeyboardOptions<sup>12+</sup>

Represents the return value of the callback that intercepts the soft keyboard from editable elements on the web page. You can specify the type of the keyboard to be used, and it is returned to the Web kernel to display a keyboard of the corresponding type.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| useSystemKeyboard | boolean  | Yes   | Whether to use the system's default soft keyboard.|
| enterKeyType | number | No   | Type of the Enter key of the system soft keyboard. For details about the value range, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10). This parameter has effect only when **useSystemKeyboard** is set to **true** and **enterKeyType** is set to a valid value.|
| customKeyboard | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | No   | Builder of a custom keyboard. This parameter is required when **useSystemKeyboard** is set to **false**. After it is set, the **Web** component starts the custom keyboard as configured.

## WebKeyboardController<sup>12+</sup>

Implements a controller to control the input, deletion, and closure of the custom keyboard. For details about the sample code, see [onInterceptKeyboardAttach](#oninterceptkeyboardattach12).

### insertText<sup>12+</sup>

insertText(text: string): void

Inserts a character.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | --------------------- |
| text | string | Yes| Character to insert into the **Web** component text box.|

### deleteForward<sup>12+</sup>

deleteForward(length: number): void

Deletes characters from the end to the beginning for the length specified by the **length** parameter.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to be deleted from the end to the beginning.|

### deleteBackward12+</sup>

deleteBackward(length: number): void

Deletes characters from the beginning to the end for the length specified by the **length** parameter.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to be deleted from the beginning to the end.|

### sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

Inserts a function key. Currently, only the Enter key type is supported. For details about the value, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                                  |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | Yes  | Function key to insert into the **Web** component text box. Currently, only the Enter key is supported.|

### close<sup>12+</sup>

close(): void

Closes this custom keyboard.

**System capability**: SystemCapability.Web.Webview.Core

## ConsoleMessage

Implements the **ConsoleMessage** object. For the sample code, see [onConsole](#onconsole).

### getLineNumber

getLineNumber(): number

Obtains the number of rows in this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | Number of rows in the console message.|

### getMessage

getMessage(): string

Obtains the log information of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Log information of the console message.|

### getMessageLevel

getMessageLevel(): MessageLevel

Obtains the level of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                    |
| --------------------------------- | ---------------------- |
| [MessageLevel](#messagelevel)| Level of the console message.|

### getSourceId

getSourceId(): string

Obtains the path and name of the web page source file.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Path and name of the web page source file.|

## JsResult

Implements the **JsResult** object, which indicates the result returned to the **Web** component to indicate the user operation performed in the dialog box. For the sample code, see [onAlert Event](#onalert).

### handleCancel

handleCancel(): void

Notifies the **Web** component of the user's cancel operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

### handleConfirm

handleConfirm(): void

Notifies the **Web** component of the user's confirm operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

Notifies the **Web** component of the user's confirm operation in the dialog box as well as the dialog box content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description       |
| ------ | ------ | ---- | ----------- |
| result | string | Yes   | User input in the dialog box.|

## FullScreenExitHandler<sup>9+</sup>

Implements a **FullScreenExitHandler** object for listening for exiting full screen mode. For the sample code, see [onFullScreenEnter](#onfullscreenenter9).

### constructor<sup>9+</sup>

constructor()

**System capability**: SystemCapability.Web.Webview.Core

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

Called when the **Web** component exits full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

## ControllerHandler<sup>9+</sup>

Implements a **WebviewController** object for new **Web** components. For the sample code, see [onWindowNew](#onwindownew9).

**System capability**: SystemCapability.Web.Webview.Core

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

Sets a **WebviewController** object. If opening a new window is not needed, set the parameter to **null**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory| Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| controller | [WebviewController](js-apis-webview.md#webviewcontroller) | Yes | **WebviewController** object of the **Web** component. If opening a new window is not needed, set it to **null**.|

## WebResourceError

Implements the **WebResourceError** object. For the sample code, see [onErrorReceive](#onerrorreceive).

### getErrorCode

getErrorCode(): number

Obtains the error code for resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Error code for resource loading. For details about error codes, see [WebNetErrorList](js-apis-netErrorList.md).|

### getErrorInfo

getErrorInfo(): string

Obtains error information about resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Error information about resource loading.|

## WebResourceRequest

Implements the **WebResourceRequest** object. For the sample code, see [onErrorReceive](#onerrorreceive).

### getRequestHeader

getRequestHeader(): Array\<Header\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | Information about the resource request header.|

### getRequestUrl

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

### isMainFrame

isMainFrame(): boolean

Checks whether the resource request is in the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is in the main frame.|

### isRedirect

isRedirect(): boolean

Checks whether the resource request is redirected by the server.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is redirected by the server.|

### isRequestGesture

isRequestGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap).|

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Request method.|

## Header

Describes the request/response header returned by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type    | Mandatory  | Description           |
| ----------- | ------ | ---- | ------------- |
| headerKey   | string | Yes   | Key of the request/response header.  |
| headerValue | string | Yes   | Value of the request/response header.|

## WebResourceResponse

Implements the **WebResourceResponse** object. For the sample code, see [onHttpErrorReceive](#onhttperrorreceive).

### getReasonMessage

getReasonMessage(): string

Obtains the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Status code description of the resource response.|

### getResponseCode

getResponseCode(): number

Obtains the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Status code of the resource response.|

### getResponseData

getResponseData(): string

Obtains the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Data in the resource response.|

### getResponseEncoding

getResponseEncoding(): string

Obtains the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Encoding string of the resource response.|

### getResponseHeader

getResponseHeader() : Array\<Header\>

Obtains the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description      |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | Resource response header.|

### getResponseMimeType

getResponseMimeType(): string

Obtains the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | MIME type of the resource response.|

### getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

Obtains the data in the resource response. Multiple data types are supported.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|string|String in HTML format.|
|number|Handle to the file.|
|ArrayBuffer|Binary data.|
|[Resource](../apis-arkui/arkui-ts/ts-types.md)|Resource referenced by **$rawfile()**.|
|undefined|No available data.|

### getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

Obtains whether the response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|boolean|**true** indicates that the response data is ready, and **false** indicates that the response data is not ready.|

### setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

Sets the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                    | Mandatory  | Description                                    |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | Yes   | Resource response data to set. When set to a string, the value indicates a string in HTML format. When set to a number, the value indicates a file handle, which is closed by the system **Web** component. When set to a **Resource** object, the value indicates the file resources in the **rawfile** directory of the application. When set to a **ArrayBuffer** object, the value indicates the original binary data of a resource.|

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

Sets the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description        |
| -------- | ------ | ---- | ------------ |
| encoding | string | Yes   | Encoding string to set.|

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

Sets the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description                |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | Yes  | MIME type to set.|

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

Sets the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description           |
| ------ | ------ | ---- | --------------- |
| reason | string | Yes  | Status code description to set.|

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

Sets the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                      | Mandatory  | Description      |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](#header)\> | Yes  | Resource response header to set.|

### setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

Sets the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description         |
| ---- | ------ | ---- | ------------- |
| code | number | Yes  | Status code to set. If the resource ends with an error, set the error code by referring to [@ohos.web.netErrorList](js-apis-netErrorList.md). Do not set the error code to **ERR_IO_PENDING**, which may block the synchronous **XMLHttpRequest**.|

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

Sets whether the resource response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory | Description         |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | Yes  | Whether the resource response data is ready. Default value: **true**|

## FileSelectorResult<sup>9+</sup>

Notifies the **Web** component of the file selection result. For the sample code, see [onShowFileSelector](#onshowfileselector9).

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

Instructs the **Web** component to select a file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type           | Mandatory | Description        |
| -------- | --------------- | ---- | ------------ |
| fileList | Array\<string\> | Yes  | List of files to operate.|

## FileSelectorParam<sup>9+</sup>

Implements the **FileSelectorParam** object. For the sample code, see [onShowFileSelector](#onshowfileselector9).

### getTitle<sup>9+</sup>

getTitle(): string

Obtains the title of this file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Title of the file selector.|

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

Obtains the mode of the file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](#fileselectormode9) | Mode of the file selector.|

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

Obtains the file filtering type.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | File filtering type.|

### isCapture<sup>9+</sup>

isCapture(): boolean

Checks whether multimedia capabilities are invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Whether multimedia capabilities are invoked.|

## HttpAuthHandler<sup>9+</sup>

Implements the **HttpAuthHandler** object. For the sample code, see [onHttpAuthRequest](#onhttpauthrequest9).

### cancel<sup>9+</sup>

cancel(): void

Cancels HTTP authentication as requested by the user.

**System capability**: SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

Performs HTTP authentication with the user name and password provided by the user.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory | Description      |
| -------- | ------ | ---- | ---------- |
| userName | string | Yes  | HTTP authentication user name.|
| password      | string | Yes  | HTTP authentication password. |

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

Sets whether to use the account name and password cached on the server for authentication.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

## SslErrorHandler<sup>9+</sup>

Implements an **SslErrorHandler** object. For the sample code, see [onSslErrorEventReceive Event](#onsslerroreventreceive9).

### handleCancel<sup>9+</sup>

handleCancel(): void

Cancels this request.

**System capability**: SystemCapability.Web.Webview.Core

### handleConfirm<sup>9+</sup>

handleConfirm(): void

Continues using the SSL certificate.

**System capability**: SystemCapability.Web.Webview.Core

## ClientAuthenticationHandler<sup>9+</sup>

Implements a **ClientAuthenticationHandler** object returned by the **Web** component. For the sample code, see [onClientAuthenticationRequest](#onclientauthenticationrequest9).

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

Uses the specified private key and client certificate chain.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | Yes   | File that stores the private key, which is a directory including the file name. |
| certChainFile | string | Yes   | File that stores the certificate chain, which is a directory including the file name.|

### confirm<sup>10+</sup>

confirm(authUri : string): void

Instructs the **Web** component to use the specified credentials (obtained from the certificate management module).

> **NOTE**
>
> The **ohos.permission.ACCESS_CERT_MANAGER** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory  | Description   |
| ------- | ------ | ---- | ------- |
| authUri | string | Yes   | Key value of the credentials.|

### cancel<sup>9+</sup>

cancel(): void

Cancels the client certificate request sent by the same host and port server. No additional event will be reported for requests from the same host and port server.

**System capability**: SystemCapability.Web.Webview.Core

### ignore<sup>9+</sup>

ignore(): void

Ignores this request.

**System capability**: SystemCapability.Web.Webview.Core

## PermissionRequest<sup>9+</sup>

Implements the **PermissionRequest** object. For the sample code, see [onPermissionRequest](#onpermissionrequest9).

### deny<sup>9+</sup>

deny(): void

Denies the permission requested by the web page.

**System capability**: SystemCapability.Web.Webview.Core

### getOrigin<sup>9+</sup>

getOrigin(): string

Obtains the origin of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

Obtains the list of accessible resources requested for the web page. For details about the resource types, see [ProtectedResourceType](#protectedresourcetype9).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description           |
| --------------- | ------------- |
| Array\<string\> | List of accessible resources requested by the web page.|

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

Grants the permission for resources requested by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type           | Mandatory  | Description           |
| --------- | --------------- | ---- | --------------- |
| resources | Array\<string\> | Yes  | List of resources that can be requested by the web page with the permission to grant.|

## ScreenCaptureHandler<sup>10+</sup>

Implements the **ScreenCaptureHandler** object for accepting or rejecting a screen capture request. For the sample code, see [onScreenCaptureRequest Event](#onscreencapturerequest10).

### deny<sup>10+</sup>

deny(): void

Rejects this screen capture request.

**System capability**: SystemCapability.Web.Webview.Core

### getOrigin<sup>10+</sup>

getOrigin(): string

Obtains the origin of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

### grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

Grants the screen capture permission.

> **NOTE**
>
> The **ohos.permission.MICROPHONE** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                                    | Mandatory  | Description   |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](#screencaptureconfig10) | Yes  | Screen capture configuration.|

## EventResult<sup>12+</sup>

Represents the event consumption result sent to the **Web** component. For details about the supported events, see [TouchType](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype). If the application does not consume the event, set this parameter to **false**, and the event will be consumed by the **Web** component. If the application has consumed the event, set this parameter to **true**, and the event will not be consumed by the **Web** component. For the sample code, see [onNativeEmbedGestureEvent](#onnativeembedgestureevent11).

### setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean): void

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| ------- | ------ | ---- | ------- |
| result          | boolean  | Yes   | Whether to consume the gesture event.|

**Example**

See [onNativeEmbedGestureEvent](#onnativeembedgestureevent11).

## ContextMenuSourceType<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name      | Value| Description        |
| --------- | -- |------------ |
| None      | 0 | Other event sources.|
| Mouse     | 1 | Mouse event.  |
| LongPress | 2 | Long press event.  |

## ContextMenuMediaType<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value| Description           |
| ----- | -- | ------------- |
| None  | 0 | Non-special media or other media types.|
| Image | 1 | Image.          |

## ContextMenuInputFieldType<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Value| Description                         |
| --------- | -- | --------------------------- |
| None      | 0 | Non-input field.                      |
| PlainText | 1 | Plain text field, such as the text, search, or email field.|
| Password  | 2 | Password field.                      |
| Number    | 3 | Numeric field.                      |
| Telephone | 4 | Phone number field.                    |
| Other     | 5 | Field of any other type.                      |

## ContextMenuEditStateFlags<sup>9+</sup>

Supports using with a bitwise OR operator. For example, to support CAN_CUT, CAN_COPY, and CAN_SELECT_ALL at the same time, use CAN_CUT | CAN_COPY | CAN_SELECT_ALL or 11.

**System capability**: SystemCapability.Web.Webview.Core

| Name           | Value| Description    |
| -------------- | -- | -------- |
| NONE           | 0 | Editing is not allowed.|
| CAN_CUT        | 1 | The cut operation is allowed.|
| CAN_COPY       | 2 | The copy operation is allowed.|
| CAN_PASTE      | 4 | The paste operation is allowed.|
| CAN_SELECT_ALL | 8 | The select all operation is allowed.|

## WebContextMenuParam<sup>9+</sup>

Implements a context menu, which is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link. For the sample code, see [onContextMenuShow](#oncontextmenushow9).

### x<sup>9+</sup>

x(): number

Obtains the X coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.|

### y<sup>9+</sup>

y(): number

Obtains the Y coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.|

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

Obtains the URL of the destination link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                       |
| ------ | ------------------------- |
| string | If it is a link that is being long pressed, the URL that has passed the security check is returned.|

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

Obtains the URL of the destination link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| string | If it is a link that is being long pressed, the original URL is returned.|

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

Obtain the source URL.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                      |
| ------ | ------------------------ |
| string | If the selected element has the **src** attribute, the URL in the **src** is returned.|

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

Checks whether image content exists.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | The value **true** means that there is image content in the element being long pressed, and **false** means the opposite.|

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

Obtains the media type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](#contextmenumediatype9) | Media type of the web page element.|

### getSelectionText<sup>9+</sup>

getSelectionText(): string

Obtains the selected text.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| string | Selected text for the context menu. If no text is selected, null is returned.|

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

Obtains the event source of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](#contextmenusourcetype9) | Event source of the context menu.|

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

Obtains the input field type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description    |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](#contextmenuinputfieldtype9) | Input field type.|

### isEditable<sup>9+</sup>

isEditable(): boolean

Checks whether this web page element is editable.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the web page element is editable; returns **false** otherwise.|

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

Obtains the edit state flag of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Edit state flag of the web page element. For details, see [ContextMenuEditStateFlags](#contextmenueditstateflags9).|

### getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

Obtains the width of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------- |
| number | Width of a preview image.|

### getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

Obtains the height of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------  |
| number | Height of a preview image.|

## WebContextMenuResult<sup>9+</sup>

Implements a **WebContextMenuResult** object. For the sample code, see [onContextMenuShow](#oncontextmenushow9).

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

Closes this context menu. This API must be called when no operations in **WebContextMenuResult** are performed.

**System capability**: SystemCapability.Web.Webview.Core

### copyImage<sup>9+</sup>

copyImage(): void

Copies the image specified in **WebContextMenuParam**.

**System capability**: SystemCapability.Web.Webview.Core

### copy<sup>9+</sup>

copy(): void

Copies text related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

### paste<sup>9+</sup>

paste(): void

Performs the paste operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

### cut<sup>9+</sup>

cut(): void

Performs the cut operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

### selectAll<sup>9+</sup>

selectAll(): void

Performs the select all operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## JsGeolocation

Implements the **PermissionRequest** object. For the sample code, see [onGeolocationShow Event](#ongeolocationshow).

### constructor

constructor()

**System capability**: SystemCapability.Web.Webview.Core

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

Sets the geolocation permission status of a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                    |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | Yes  | Index of the origin.                              |
| allow  | boolean | Yes  | Geolocation permission status.                            |
| retain | boolean | Yes  | Whether the geolocation permission status can be saved to the system. You can manage the geolocation permissions saved to the system through [GeolocationPermissions<sup>9+</sup>](js-apis-webview.md#geolocationpermissions).|

## MessageLevel

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value| Description   |
| ----- | -- | ---- |
| Debug | 1 | Debug level.|
| Error | 4 | Error level.|
| Info  | 2 | Information level.|
| Log   | 5 | Log level.|
| Warn  | 3 | Warning level.|

## RenderExitReason<sup>9+</sup>

Enumerates the reasons why the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name                        | Value| Description               |
| -------------------------- | -- | ----------------- |
| ProcessAbnormalTermination | 0 | The rendering process exits abnormally.        |
| ProcessWasKilled           | 1 | The rendering process receives a SIGKILL message or is manually terminated.|
| ProcessCrashed             | 2 | The rendering process crashes due to segmentation or other errors.   |
| ProcessOom                 | 3 | The program memory is running low.          |
| ProcessExitUnknown         | 4 | Other reason.            |

## MixedMode

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Value| Description                                |
| ---------- | -- | ---------------------------------- |
| All        | 0 | HTTP and HTTPS hybrid content can be loaded. This means that all insecure content can be loaded.|
| Compatible | 1 | HTTP and HTTPS hybrid content can be loaded in compatibility mode. This means that some insecure content may be loaded.          |
| None       | 2 | HTTP and HTTPS hybrid content cannot be loaded.              |

## CacheMode

**System capability**: SystemCapability.Web.Webview.Core

| Name     | Value| Description                                  |
| ------- | -- | ------------------------------------ |
| Default<sup>9+</sup> | 0 | The cache that has not expired is used to load the resources. If the resources do not exist in the cache, they will be obtained from the Internet.|
| None    | 1 | The cache is used to load the resources. If the resources do not exist in the cache, they will be obtained from the Internet.    |
| Online  | 2 | The cache is not used to load the resources. All resources are obtained from the Internet.              |
| Only    | 3 | The cache alone is used to load the resources.                       |

## FileSelectorMode<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name                  | Value| Description        |
| -------------------- | -- | ---------- |
| FileOpenMode         | 0 | Open and upload a file. |
| FileOpenMultipleMode | 1 | Open and upload multiple files. |
| FileOpenFolderMode   | 2 | Open and upload a folder.|
| FileSaveMode         | 3 | Save a file.   |

 ## HitTestType

 **System capability**: SystemCapability.Web.Webview.Core

| Name           | Value| Description                      |
| ------------- | -- | ------------------------ |
| EditText      | 0 | Editable area.                 |
| Email         | 1 | Email address.                 |
| HttpAnchor    | 2 | Hyperlink whose **src** is **http**.          |
| HttpAnchorImg | 3 | Image with a hyperlink, where **src** is **http**.|
| Img           | 4 | HTML::img tag.            |
| Map           | 5 | Geographical address.                   |
| Phone         | 6 | Phone number.                   |
| Unknown       | 7 | Unknown content.                   |

 ## OverScrollMode<sup>11+</sup>

 **System capability**: SystemCapability.Web.Webview.Core

| Name    | Value| Description         |
| ------ | -- | ----------- |
| NEVER  | 0 | The overscroll mode is disabled.|
| ALWAYS | 1 | The overscroll mode is enabled.|

## OnContextMenuHideCallback<sup>11+</sup>

Implements the callback context menu customizes the hidden callback.

## SslError<sup>9+</sup>

Enumerates the error codes returned by **onSslErrorEventReceive** API.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Value| Description         |
| ------------ | -- | ----------- |
| Invalid      | 0 | Minor error.      |
| HostMismatch | 1 | The host name does not match.    |
| DateInvalid  | 2 | The certificate has an invalid date.    |
| Untrusted    | 3 | The certificate issuer is not trusted.|

## ProtectedResourceType<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name                         | Value| Description           | Remarks                        |
| --------------------------- | --------------- | ------------- | -------------------------- |
| MidiSysex                   | TYPE_MIDI_SYSEX | MIDI SYSEX resource.| Currently, only permission events can be reported. MIDI devices are not yet supported.|
| VIDEO_CAPTURE<sup>10+</sup> | TYPE_VIDEO_CAPTURE | Video capture resource, such as a camera. |                            |
| AUDIO_CAPTURE<sup>10+</sup> | TYPE_AUDIO_CAPTURE | Audio capture resource, such as a microphone.|                            |
| SENSOR<sup>12+</sup>        | TYPE_SENSOR | Sensor resource, such as an acceleration sensor.|                            |

## WebDarkMode<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name  | Value| Description          |
| ---- | -- | ------------ |
| Off  | 0 | The web dark mode is disabled.  |
| On   | 1 | The web dark mode is enabled.  |
| Auto | 2 | The web dark mode setting follows the system settings.|

## WebCaptureMode<sup>10+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description     |
| ----------- | -- | ------- |
| HOME_SCREEN | 0 | Capture of the home screen.|

## WebMediaOptions<sup>10+</sup>

Describes the web-based media playback policy.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| resumeInterval | number  | No   | Validity period for automatically resuming a paused web audio, in seconds. The maximum validity period is 60 seconds. Due to the approximate value, the validity period may have a deviation of less than 1 second.|
| audioExclusive | boolean | No   | Whether the audio of multiple **Web** instances in an application is exclusive.                      |

## ScreenCaptureConfig<sup>10+</sup>

Provides the web screen capture configuration.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                     | Mandatory  | Description        |
| ----------- | --------------------------------------- | ---- | ---------- |
| captureMode | [WebCaptureMode](#webcapturemode10) | Yes   | Web screen capture mode.|

## WebLayoutMode<sup>11+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                |
| ----------- | -- | ------------------ |
| NONE        | 0 | The web layout follows the system.        |
| FIT_CONTENT | 1 | The web layout adapts to the page size.|

## DataResubmissionHandler<sup>9+</sup>

Implements the **DataResubmissionHandler** object for resubmitting or canceling the web form data.

### resend<sup>9+</sup>

resend(): void

Resends the web form data.

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

Cancels the resending of web form data.

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

Implements a **WebController** to control the behavior of the **Web** component. A **WebController** can control only one **Web** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **Web** component.

This API is deprecated since API version 9. You are advised to use [WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller) instead.

### Creating an Object

<!--code_no_check-->
```ts
let webController: WebController = new WebController()
```

### getCookieManager<sup>(deprecated)</sup>

getCookieManager(): WebCookie

Obtains the cookie management object of the **Web** component.

This API is deprecated since API version 9. You are advised to use [getCookie](js-apis-webview.md#getcookiedeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

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

This API is deprecated since API version 9. You are advised to use [requestFocus<sup>9+</sup>](js-apis-webview.md#requestfocus) instead.

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

### accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessBackward<sup>9+</sup>](js-apis-webview.md#accessbackward) instead.

**System capability**: SystemCapability.Web.Webview.Core

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

This API is deprecated since API version 9. You are advised to use [accessForward<sup>9+</sup>](js-apis-webview.md#accessforward) instead.

**System capability**: SystemCapability.Web.Webview.Core

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

This API is deprecated since API version 9. You are advised to use [accessStep<sup>9+</sup>](js-apis-webview.md#accessstep) instead.

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

### backward<sup>(deprecated)</sup>

backward()

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

This API is deprecated since API version 9. You are advised to use [backward<sup>9+</sup>](js-apis-webview.md#backward) instead.

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

### forward<sup>(deprecated)</sup>

forward()

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

This API is deprecated since API version 9. You are advised to use [forward<sup>9+</sup>](js-apis-webview.md#forward) instead.

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

### deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately, with no need for invoking the [refresh](#refreshdeprecated) API.

This API is deprecated since API version 9. You are advised to use [deleteJavaScriptRegister<sup>9+</sup>](js-apis-webview.md#deletejavascriptregister) instead.

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

### getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

Obtains the element type of the area being clicked.

This API is deprecated since API version 9. You are advised to use [getHitTest<sup>9+</sup>](js-apis-webview.md#gethittest) instead.

**System capability**: SystemCapability.Web.Webview.Core

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

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **Web** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **Web** component as a non-encoded string in a manner similar to **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadData<sup>9+</sup>](js-apis-webview.md#loaddata) instead.

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

### loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

The object injected through **registerJavaScriptProxy** is still valid on a new page redirected through **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadUrl<sup>9+</sup>](js-apis-webview.md#loadurl) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                      | Mandatory | Description          |
| ------- | -------------------------- | ---- | -------------- |
| url     | string \| Resource                     | Yes | URL to load.    |
| headers | Array\<[Header](#header)\> | No   | Additional HTTP request header of the URL. The default value is **[]**.|

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

Called when the **Web** component enters the active state.

This API is deprecated since API version 9. You are advised to use [onActive<sup>9+</sup>](js-apis-webview.md#onactive) instead.

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

### onInactive<sup>(deprecated)</sup>

onInactive(): void

Called when the **Web** component enters the inactive state.

This API is deprecated since API version 9. You are advised to use [onInactive<sup>9+</sup>](js-apis-webview.md#oninactive) instead.

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

### zoom<sup>(deprecated)</sup>

zoom(factor: number): void

Sets a zoom factor for the current web page.

This API is deprecated since API version 9. You are advised to use [zoom<sup>9+</sup>](js-apis-webview.md#zoom) instead.

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

### refresh<sup>(deprecated)</sup>

refresh()

Called when the **Web** component refreshes the web page.

This API is deprecated since API version 9. You are advised to use [refresh<sup>9+</sup>](js-apis-webview.md#refresh) instead.

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

### registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. You must invoke the [refresh](#refreshdeprecated) API for the registration to take effect.

This API is deprecated since API version 9. You are advised to use [registerJavaScriptProxy<sup>9+</sup>](js-apis-webview.md#registerjavascriptproxy) instead.

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

This API is deprecated since API version 9. You are advised to use [runJavaScript<sup>9+</sup>](js-apis-webview.md#runjavascript) instead.

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

This API is deprecated since API version 9. You are advised to use [stop<sup>9+</sup>](js-apis-webview.md#stop) instead.

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

### clearHistory<sup>(deprecated)</sup>

clearHistory(): void

Clears the browsing history.

This API is deprecated since API version 9. You are advised to use [clearHistory<sup>9+</sup>](js-apis-webview.md#clearhistory) instead.

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

## WebCookie<sup>(deprecated)</sup>

Manages behavior of cookies in **Web** components. All **Web** components in an application share a **WebCookie**. You can use the **getCookieManager** API in **controller** to obtain the **WebCookie** for subsequent cookie management.

### setCookie<sup>(deprecated)</sup>

setCookie()

Sets the cookie. This API returns the result synchronously. Returns **true** if the operation is successful; returns **false** otherwise.

This API is deprecated since API version 9. You are advised to use [setCookie<sup>9+</sup>](js-apis-webview.md#setcookie) instead.

**System capability**: SystemCapability.Web.Webview.Core

### saveCookie<sup>(deprecated)</sup>

saveCookie()

Saves the cookies in the memory to the drive. This API returns the result synchronously.

This API is deprecated since API version 9. You are advised to use [saveCookieAsync<sup>9+</sup>](js-apis-webview.md#savecookieasync) instead.

**System capability**: SystemCapability.Web.Webview.Core

## ScriptItem<sup>11+</sup>

Describes the **ScriptItem** object injected to the **Web** component through the [javaScriptOnDocumentStart](#javascriptondocumentstart11) attribute.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type            | Mandatory  | Description                   |
| ----------- | -------------- | ---- | --------------------- |
| script      | string         | Yes   | JavaScript script to be injected and executed.|
| scriptRules | Array\<string> | Yes  | Matching rules for allowed sources.<br>1. To allow URLs from all sources, use the wildcard (\*).<br>2. If exact match is required, specify the exact URL, for example, **https:\//www\\.example.com**.<br>3. For fuzzy match, you can use a wildcard (\*) in the website URL, for example, **https://\*.example.com**. Websites such as "x,*.y.com" and "* foobar.com" are not allowed.  <br>4. If the source is an IP address, follow rule 2.       |

## WebNavigationType<sup>11+</sup>

Defines the navigation type.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| UNKNOWN                       | 0 | Unknown type.  |
| MAIN_FRAME_NEW_ENTRY          | 1 | Navigation to a new history entry from the main document.  |
| MAIN_FRAME_EXISTING_ENTRY     | 2 | Navigation to an existing history entry from the main document.|
| NAVIGATION_TYPE_NEW_SUBFRAME  | 4 | User-triggered navigation from a subdocument.|
| NAVIGATION_TYPE_AUTO_SUBFRAME | 5 | Non-user-triggered navigation from a subdocument.|

## LoadCommittedDetails<sup>11+</sup>

Provides detailed information about the web page that has been submitted for redirection.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| isMainFrame     | boolean                              | Yes   | Whether the document is the main document.|
| isSameDocument  | boolean                              | Yes   | Whether to navigate without changing the document. Example of navigation in the same document: 1. navigation shown in the example; 2. navigation triggered by **pushState** or **replaceState**; 3. navigation to a history entry on the same page. |
| didReplaceEntry | boolean                              | Yes   | Whether the submitted new entry replaces the existing entry. In certain scenarios for navigation to a subdocument, although the existing entry is not replaced, some attributes are changed. |
| navigationType  | [WebNavigationType](#webnavigationtype11)  | Yes   | Navigation type.      |
| url             | string                               | Yes   | URL of the current navigated-to web page.         |

## ThreatType<sup>11+</sup>

Enumerates the website threat types.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Value| Description                  |
| ---------------- | -- | ----------------------|
| THREAT_ILLEGAL  | 0 | Illegal website.             |
| THREAT_FRAUD    | 1 | Fraudulent website.             |
| THREAT_RISK     | 2 | Website that poses security risks.     |
| THREAT_WARNING  | 3 | Website suspected to contain unsafe content.|

## OnNavigationEntryCommittedCallback<sup>11+</sup>

type OnNavigationEntryCommittedCallback = (loadCommittedDetails: [LoadCommittedDetails](#loadcommitteddetails11)) => void

Called when a navigation item is submitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| loadCommittedDetails | [LoadCommittedDetails](#loadcommitteddetails11)  | Yes| Detailed information about the web page that has been submitted for redirection.|

## OnSafeBrowsingCheckResultCallback<sup>11+</sup>

type OnSafeBrowsingCheckResultCallback = (threatType: ThreatType) => void

Called by a website safe browsing check.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| threatType | [ThreatType](#threattype11)  | Yes| Website threat type. |

## FullScreenEnterEvent<sup>12+</sup>

Provides details about the callback event for the **Web** component to enter the full-screen mode.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| handler     | [FullScreenExitHandler](#fullscreenexithandler9) | Yes   | Function handle for exiting full screen mode.|
| videoWidth  | number | No   | Video width, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its width; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the width of the first sub-video element; in other cases, the value is **0**.|
| videoHeight  | number | No   | Video height, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its height; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the height of the first sub-video element; in other cases, the value is **0**.|

## OnFullScreenEnterCallback<sup>12+</sup>

type OnFullScreenEnterCallback = (event: FullScreenEnterEvent) => void

Called when the **Web** component enters full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| event | [FullScreenEnterEvent](#fullscreenenterevent12)  | Yes| Callback event for the **Web** component to enter full screen mode.|

## SslErrorEvent<sup>12+</sup>

Provides details about the callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type                                | Mandatory  | Description          |
| ------- | ------------------------------------ | ---- | -------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | Yes   | User operation.|
| error   | [SslError](#sslerror9)       | Yes   | Error code.          |
| url   | string                                 | Yes   | URL.          |
| originalUrl   | string                         | Yes   | Original URL of the request.          |
| referrer   | string                            | Yes   | Referrer URL.          |
| isFatalError   | boolean                       | Yes   | Whether the error is a fatal error.          |
| isMainFrame   | boolean                        | Yes   | Whether the request is made for the main frame.          |


## OnSslErrorEventCallback<sup>12+</sup>

type OnSslErrorEventCallback = (sslErrorEvent: SslErrorEvent) => void

Provides details about the callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| sslErrorEvent | [SslErrorEvent](#sslerrorevent12)  | Yes| Details about the callback invoked when an SSL error occurs during resource loading.|

## NativeEmbedStatus<sup>11+</sup>

Defines the lifecycle of the same-layer tag. When the same-layer tag exists on the loaded page, **CREATE** is triggered. When the same-layer tag is moved or is enlarged, **UPDATE **is triggered. When the page exits, **DESTROY** is triggered.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| CREATE                        | 0 | The same-layer tag is created.  |
| UPDATE                        | 1 | The same-layer tag is updated.  |
| DESTROY                       | 2 | The same-layer tag is destroyed.|
| ENTER_BFCACHE<sup>12+</sup>   | 3 | The same-layer tag enters the BFCache.  |
| LEAVE_BFCACHE<sup>12+</sup>   | 4 | The same-layer tag leaves the BFCache.|

## NativeEmbedInfo<sup>11+</sup>

Provides detailed information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name               | Type                                 | Mandatory  | Description                       |
|-------------------| ------------------------------------ | ---- |---------------------------|
| id                | string             | No   | ID of the same-layer tag.            |
| type              | string                              | No   | Type of the same-layer tag. The value is in lowercase.  |
| src               | string                              | No   | **src** information of the same-layer tag.           |
| width             | number  | No   | Width of the same-layer tag, in px.         |
| height            | number                              | No   | Height of the same-layer tag, in px.         |
| url               | string                              | No   | URL of the same-layer tag.           |
| tag<sup>12+</sup> | string              | No   | Name of the tag, which consists of uppercase letters.             |
| params<sup>12+</sup>            | Map<string, string> | No   | List of key-value pairs contained in the **object** tag that form a map of the Object type. Use the methods provided by the Object type to operate the map object. |
| position<sup>12+</sup>          | Position            | No   | Position of the same-layer tag relative to the **Web** component in the screen coordinate system, which is different from the standard **Position**. The unit is px.|

## NativeEmbedDataInfo<sup>11+</sup>

Provides detailed information about the lifecycle changes of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| status     | [NativeEmbedStatus](#nativeembedstatus11)             | No   | Lifecycle status of the same-layer tag.|
| surfaceId  | string                              | No   | Surface ID of the native image. |
| embedId | string                              | No   | Unique ID of the same-layer tag. |
| info  | [NativeEmbedInfo](#nativeembedinfo11)  | No   | Detailed information about the same-layer tag.      |

## NativeEmbedTouchInfo<sup>11+</sup>

Provides touch information of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | No   | Unique ID of the same-layer tag.|
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent)  | No   | Touch action information.|
| result<sup>12+</sup>     | [EventResult](#eventresult12)   | No   | Gesture event consumption result.|

## FirstMeaningfulPaint<sup>12+</sup>

Provides detailed information about the first meaningful paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| navigationStartTime      | number | No | Navigation bar loading time, in microseconds.      |
| firstMeaningfulPaintTime | number | No  | Time taken for the first meaningful paint of the page, in milliseconds.|

## OnFirstMeaningfulPaintCallback<sup>12+</sup>

type OnFirstMeaningfulPaintCallback = (firstMeaningfulPaint: [FirstMeaningfulPaint](#firstmeaningfulpaint12)) => void

Called when the first meaningful paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](#firstmeaningfulpaint12) | Yes| Information about the first meaningful paint.|

## LargestContentfulPaint<sup>12+</sup>

Provides detailed information about the largest content paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                     | Type  | Mandatory| Description                                    |
| ------------------------- | ------ | ---- | ---------------------------------------- |
| navigationStartTime       | number | No  | Navigation bar loading time, in microseconds.        |
| largestImagePaintTime     | number | No  | Maximum image loading time, in milliseconds.  |
| largestTextPaintTime      | number | No  | Maximum text loading time, in milliseconds.    |
| largestImageLoadStartTime | number | No  | Maximum time for an image to start loading, in milliseconds.|
| largestImageLoadEndTime   | number | No  | Maximum time for an image to finish loading, in milliseconds.|
| imageBPP                  | number | No  | Maximum number of image pixels.                          |

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](#largestcontentfulpaint12
)) => void

Called when the largest content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| largestContentfulPaint | [LargestContentfulPaint](#largestcontentfulpaint12) | Yes| Information about the largest content paint.|

## IntelligentTrackingPreventionDetails<sup>12+</sup>

Provides detailed information about intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description        |
| ------------- | ------------------------------------| ----- | ------------ |
| host          | string                              | Yes    | Domain name.   |
| trackerHost   | string                              | Yes    | Domain name of the tracker. |

## OnIntelligentTrackingPreventionCallback<sup>12+</sup>

type OnIntelligentTrackingPreventionCallback = (details: IntelligentTrackingPreventionDetails) => void

Represents the callback invoked when the tracker cookie is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| details | [IntelligentTrackingPreventionDetails](#intelligenttrackingpreventiondetails12)  | Yes| Detailed information about intelligent tracking prevention.|

## OnOverrideUrlLoadingCallback<sup>12+</sup>

type OnOverrideUrlLoadingCallback = (webResourceRequest: WebResourceRequest) => boolean

Represents a callback for **onOverrideUrlLoading**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webResourceRequest   |   [WebResourceRequest](#webresourcerequest)   | Yes  | Information about the URL request.|

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if the access is blocked; returns **false** otherwise.|

## RenderMode<sup>12+</sup>

Enumerates the rendering mode of **Web** components. By default, the asynchronous rendering mode is used.

The asynchronous rendering mode is recommended because it has better performance and lower power consumption.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| ASYNC_RENDER                        | 0 | The **Web** component is rendered asynchronously. The ArkWeb component as a graphic surface node is displayed independently. The maximum width of the **Web** component is 7,680 px (physical pixel).  |
| SYNC_RENDER                        | 1 | The **Web** component is rendered synchronously. The ArkWeb component as a graphic canvas node is displayed together with the system component. The maximum width of the **Web** component is 500,000 px (physical pixel).  |

## NativeMediaPlayerConfig<sup>12+</sup>

Represents the configuration for [enabling the application to take over web page media playback](#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
|  enable  | boolean | Yes| Whether to enable the feature.<br> **true**: enabled<br> **false** (default): disabled|
|  shouldOverlay | boolean | Yes| Whether the video player's display overlays the web page content when the application takes over the web page's video player.<br> **true**: The video player's display overlays the web page content. This means that the height of the video layer is adjusted to cover the web page content.<br> **false** (default): The video player's display does not overlay the web page content. This means that the video player maintains its original height and is embedded within the web page.|

## RenderProcessNotRespondingReason<sup>12+</sup>

Provides the reason why the rendering process does not respond.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| INPUT_TIMEOUT                  | 0 | The response to the input event sent to the rendering process times out.  |
| NAVIGATION_COMMIT_TIMEOUT      | 1 | The navigation for loading a new web page times out.  |

## RenderProcessNotRespondingData<sup>12+</sup>

Provides detailed information about the unresponsive rendering process.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| jsStack      | string | Yes | JavaScript call stack information of the web page.      |
| pid | number | Yes  | Process ID of the web page.|
| reason | [RenderProcessNotRespondingReason](#renderprocessnotrespondingreason12) | Yes  | The reason why the rendering process does not respond.|

## OnRenderProcessNotRespondingCallback<sup>12+</sup>

type OnRenderProcessNotRespondingCallback = (data : RenderProcessNotRespondingData) => void

Represents a callback invoked when the rendering process does not respond.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| data | [RenderProcessNotRespondingData](#renderprocessnotrespondingdata12) | Yes| The detailed information about the unresponsive rendering process.|

## OnRenderProcessRespondingCallback<sup>12+</sup>

type OnRenderProcessRespondingCallback = () => void

Represents a callback invoked when the rendering process transitions back to a normal operating state from an unresponsive state.

**System capability**: SystemCapability.Web.Webview.Core

## ViewportFit<sup>12+</sup>

Enumerates the viewport types available for **viewport-fit** in the web page **\<meta>** tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| AUTO                  | 0 | The entire web page is visible. Default value.  |
| CONTAINS      | 1 | The initial layout viewport and the visual viewport fit within the largest rectangle that adapts to the device's display screen.  |
| COVER      | 2| The initial layout viewport and the visual viewport are confined within the bounding rectangle of the device's physical screen.  |

## OnViewportFitChangedCallback<sup>12+</sup>

type OnViewportFitChangedCallback = (viewportFit: ViewportFit) => void

Represents the callback invoked when the **viewport-fit** configuration in the web page's **\<meta>** tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| viewportFit | [ViewportFit](#viewportfit12) | Yes| Viewport type for **viewport-fit** in the web page **\<meta>** tag.|

## ExpandedMenuItemOptions<sup>12+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | Yes    | Content to display.    |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | No    | Icon to display.    |
| action    | (selectedText: {plainText: string}) => void                                                         | Yes    | Selected text.|

## WebKeyboardAvoidMode<sup>12+</sup>

Enumerates the soft keyboard avoidance modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name              | Value| Description          |
| ------------------ | -- | ------------ |
| RESIZE_VISUAL      | 0 | For soft keyboard avoidance, the visual viewport is resized, but not the layout viewport.  |
| RESIZE_CONTENT     | 1 | For soft keyboard avoidance, both the visual viewport and layout viewport are resized. Default value.|
| OVERLAYS_CONTENT   | 2 | No viewport is resized, and soft keyboard avoidance is not triggered.  |

## OnPageEndEvent<sup>12+</sup>

Represents the callback invoked when the web page loading ends.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## OnPageBeginEvent<sup>12+</sup>

Represents the callback invoked when the web page loading begins.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## OnProgressChangeEvent<sup>12+</sup>

Represents the callback invoked when the web page loading progress changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| newProgress | number | Yes| New loading progress. The value is an integer ranging from 0 to 100.                      |

## OnTitleReceiveEvent<sup>12+</sup>

Represents the callback invoked when the document title of the web page is changed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| title | string | Yes| Document title.                      |

## OnGeolocationShowEvent<sup>12+</sup>

Represents the callback invoked when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| origin | string | Yes| Index of the origin.                      |
| geolocation | [JsGeolocation](#jsgeolocation) | Yes| User operation.                      |

## OnAlertEvent<sup>12+</sup>

Represents the callback invoked when **alert()** is invoked to display an alert dialog box on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](#jsresult) | Yes| User operation.                      |

## OnBeforeUnloadEvent<sup>12+</sup>

Represents the callback invoked when this page is about to exit after the user refreshes or closes the page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](#jsresult) | Yes| User operation.                      |

## OnConfirmEvent<sup>12+</sup>

Represents the callback invoked when **confirm()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](#jsresult) | Yes| User operation.                      |

## OnPromptEvent<sup>12+</sup>

Represents the callback invoked when **prompt()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| value | string | Yes| Information in the dialog box.                      |
| result | [JsResult](#jsresult) | Yes| User operation.                      |

## OnConsoleEvent<sup>12+</sup>

Represents the callback invoked to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| message | [ConsoleMessage](#consolemessage) | Yes| Console message.                      |

## OnErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an error occurs during web page loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | Yes| Encapsulation of a web page request.     |
| error   | [WebResourceError](#webresourceerror)    | Yes| Encapsulation of a web page resource loading error.|

## OnHttpErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an HTTP error occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | Yes| Encapsulation of a web page request.     |
| response   | [WebResourceResponse](#webresourceresponse)    | Yes| Encapsulation of a resource response.|

## OnDownloadStartEvent<sup>12+</sup>

Represents the callback invoked when the main application starts downloading a file.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url                | string | Yes| URL for the download task.                          |
| userAgent          | string | Yes| User agent used for download.                         |
| contentDisposition | string | Yes| Content-Disposition response header returned by the server, which may be empty.|
| mimetype           | string | Yes| MIME type of the content returned by the server.               |
| contentLength      | number | Yes| Length of the content returned by the server.                        |

## OnRefreshAccessedHistoryEvent<sup>12+</sup>

Represents the callback invoked when the access history of the web page is refreshed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | Yes| URL to be accessed.                                 |
| isRefreshed | boolean | Yes| Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh<sup>9+</sup>](js-apis-webview.md#refresh) API, and **false** means the opposite.|

## OnRenderExitedEvent<sup>12+</sup>

Represents the callback invoked when the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| renderExitReason | [RenderExitReason](#renderexitreason9) | Yes| Cause for the abnormal exit of the rendering process.|

## OnShowFileSelectorEvent<sup>12+</sup>

Represents the callback invoked to notify the file selector result.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| result       | [FileSelectorResult](#fileselectorresult9) | Yes| File selection result to be sent to the **Web** component.|
| fileSelector | [FileSelectorParam](#fileselectorparam9) | Yes| Information about the file selector.      |

## OnResourceLoadEvent<sup>12+</sup>

Represents the callback invoked when the URL is loaded.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | Yes| URL of the loaded resource file.|

## OnScaleChangeEvent<sup>12+</sup>

Represents the callback invoked when the display scale of this page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| oldScale | number | Yes| Display ratio of the page before the change.|
| newScale | number | Yes| Display ratio of the page after the change.|

## OnHttpAuthRequestEvent<sup>12+</sup>

Represents the callback invoked when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [HttpAuthHandler](#httpauthhandler9) | Yes| User operation.  |
| host    | string                               | Yes| Host to which HTTP authentication credentials apply.|
| realm   | string                               | Yes| Realm to which HTTP authentication credentials apply. |

## OnInterceptRequestEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to load a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | Yes| Information about the URL request.|

## OnPermissionRequestEvent<sup>12+</sup>

Represents the callback invoked when a permission request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](#permissionrequest9) | Yes| User operation.|

## OnScreenCaptureRequestEvent<sup>12+</sup>

Represents the callback invoked when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](#screencapturehandler10) | Yes| User operation.|

## OnContextMenuShowEvent<sup>12+</sup>

Represents the callback invoked during a call to allow for the display of a custom context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](#webcontextmenuparam9) | Yes| Parameters related to the context menu.    |
| result | [WebContextMenuResult](#webcontextmenuresult9) | Yes| Result of the context menu.|

## OnSearchResultReceiveEvent<sup>12+</sup>

Represents the callback invoked to notify the caller of the search result on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| activeMatchOrdinal | number  | Yes| Sequence number of the current match, which starts from 0.                      |
| numberOfMatches    | number  | Yes| Total number of matches.                           |
| isDoneCounting     | boolean | Yes| Whether the search operation on the current page is complete. This API may be called multiple times until **isDoneCounting** is **true**.|

## OnScrollEvent<sup>12+</sup>

Represents the callback invoked when the scrollbar scrolls to a specified position.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | Yes| Position of the scrollbar on the x-axis relative to the leftmost of the web page.|
| yOffset | number | Yes| Position of the scrollbar on the y-axis relative to the top of the web page.|

## OnSslErrorEventReceiveEvent<sup>12+</sup>

Represents the callback invoked when the web page receives an SSL error.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | Yes| User operation.|
| error   | [SslError](#sslerror9)          | Yes| Error code.          |

## OnClientAuthenticationEvent<sup>12+</sup>

Represents the callback invoked when an SSL client certificate is required from the user.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler  | [ClientAuthenticationHandler](#clientauthenticationhandler9) | Yes| User operation. |
| host     | string                                   | Yes| Host name of the server that requests a certificate.   |
| port     | number                                   | Yes| Port number of the server that requests a certificate.   |
| keyTypes | Array<string\>                           | Yes| Acceptable asymmetric private key types.   |
| issuers  | Array<string\>                           | Yes| Issuer of the certificate that matches the private key.|

## OnWindowNewEvent<sup>12+</sup>

Represents the callback invoked when the web page requests the user to create a new window.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| isAlert       | boolean                                  | Yes| Whether to open the target URL in a new window. The value **true** means to open the target URL in a new window, and **false** means to open the target URL in a new tab.   |
| isUserTrigger | boolean                                  | Yes| Whether the creation is triggered by the user. The value **true** means that the creation is triggered by the user, and **false** means the opposite.     |
| targetUrl     | string                                   | Yes| Target URL.                       |
| handler       | [ControllerHandler](#controllerhandler9) | Yes| **WebviewController** instance for setting the new window.|

## OnTouchIconUrlReceivedEvent<sup>12+</sup>

Represents the callback invoked when an apple-touch-icon URL is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | Yes| Received apple-touch-icon URL.|
| precomposed | boolean | Yes| Whether the apple-touch-icon is precomposed.  |

## OnFaviconReceivedEvent<sup>12+</sup>

Represents the callback invoked when this web page receives a new favicon.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| favicon | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes| **PixelMap** object of the received favicon.|

## OnPageVisibleEvent<sup>12+</sup>

Represents the callback invoked when the old page is not displayed and the new page is about to be visible.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | Yes| URL of the new page that is able to be visible when the old page is not displayed.|

## OnDataResubmittedEvent<sup>12+</sup>

Represents the callback invoked when the web form data can be resubmitted.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [DataResubmissionHandler](#dataresubmissionhandler9) | Yes| Handler for resubmitting web form data.|

## OnAudioStateChangedEvent<sup>12+</sup>

Represents the callback invoked when the audio playback status on the web page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| playing | boolean | Yes| Audio playback status on the current page. The value **true** means that audio is being played, and **false** means the opposite.|

## OnFirstContentfulPaintEvent<sup>12+</sup>

Represents the callback invoked when the first content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| navigationStartTick    | number | Yes| Navigation start time, in microseconds.         |
| firstContentfulPaintMs | number | Yes| Time between navigation and when the content is first rendered, in milliseconds.|

## OnLoadInterceptEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to access a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| data | [WebResourceRequest](#webresourcerequest) | Yes| Information about the URL request.|

## OnOverScrollEvent<sup>12+</sup>

Represents the callback invoked when the web page is overscrolled.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | Yes| Horizontal overscroll offset based on the leftmost edge of the web page.|
| yOffset | number | Yes| Vertical overscroll offset based on the top edge of the web page.|

## JavaScriptProxy<sup>12+</sup>

Defines the JavaScript object to be injected.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| object     | object                                   | Yes   | Object to be registered. Methods can be declared, but attributes cannot.                  |
| name       | string                                   | Yes   | Name of the object to be registered, which is the same as that invoked in the window.               |
| methodList | Array\<string\>                          | Yes   | Synchronous methods of the JavaScript object to be registered at the application side.                |
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller) | Yes   | -    | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| asyncMethodList<sup>12+</sup>  | Array\<string\>      | No   | Asynchronous methods of the JavaScript object to be registered at the application side. Asynchronous methods do not provide return values.  |
| permission<sup>12+</sup>  | string  | No   | JSON string, which is empty by default. This string is used to configure JSBridge permission control and define the URL whitelist at the object and method levels.<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).|

## AdsBlockedDetails<sup>12+</sup>

Provides detailed information about the blocked ads when ads are blocked.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type                                                                          | Mandatory  | Description                   |
| ------- | --------------------------------------------------------------------------------  | ---- | ------------------------- |
| url | string  | Yes   | URL of the page where ads are blocked.|
| adsBlocked | Array\<string\>  | Yes   | URLs or DOMPath of the blocked ads. If ads have the same URLs, duplicate elements may exist.|

## OnAdsBlockedCallback<sup>12+</sup>

type OnAdsBlockedCallback = (details: AdsBlockedDetails) => void

Represents the callback invoked when ads are blocked on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type                                       | Mandatory  | Description                        |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| details | [AdsBlockedDetails](#adsblockeddetails12) | Yes   | Detailed information about the blocked ads when ads are blocked.|

## NativeEmbedVisibilityInfo<sup>12+</sup>

Provides visibility information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description             |
| -------------  | ------------------------------------| ----- | ------------------ |
| visibility     | boolean                             | Yes    | Whether the **embed** tag is visible.        |
| embedId        | string                              | Yes    | ID of the same-layer rendering tag. |

## OnNativeEmbedVisibilityChangeCallback<sup>12+</sup>

type OnNativeEmbedVisibilityChangeCallback = (nativeEmbedVisibilityInfo: NativeEmbedVisibilityInfo) => void

Called when the visibility of a same-layer tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](#nativeembedvisibilityinfo12)  | Yes| Visibility information about the same-layer tag.|

## WebElementType<sup>13+</sup>

Enumerates the web element type.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Value| Description             |
| --------- | -- | ----------------- |
| IMAGE     | 1 | Image type.|

## WebResponseType<sup>13+</sup>

Enumerates the response type of the menu.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name           | Value| Description               |
| -------------- | -- | ------------------  |
| LONG_PRESS     | 1 | The menu is displayed when the component is long-pressed.|

## SelectionMenuOptionsExt<sup>13+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| onAppear   | Callback\<void\>   | No    | Callback invoked when the custom selection menu is displayed.    |
| onDisappear | Callback\<void\>  | No    | Callback invoked when the custom selection menu is closed.    |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | No    | Preview content style of the custom selection menu. If this parameter is not set, there is no preview content.|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13)     | No    | Type of the custom menu.<br>Default value: **MenuType.SELECTION_MENU**    |

<!--no_check-->