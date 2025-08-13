# Attributes

Supported common attributes: [aspectRatio](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio), [backdropBlur](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backdropblur), [backgroundColor](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor), [bindContentCover](../apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover), [bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8), [bindMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu), [bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet), [borderColor](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#bordercolor), [borderRadius](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderradius), [borderStyle](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderstyle), [borderWidth](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderwidth), [clip](../apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clip12), [constraintSize](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#constraintsize), [defaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9), [focusable](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable), [tabIndex](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#tabindex9), [groupDefaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#groupdefaultfocus9), [displayPriority](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority), [enabled](../apis-arkui/arkui-ts/ts-universal-attributes-enable.md#enabled), [flexBasis](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis), [flexShrink](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink), [layoutWeight](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight), [id](../apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#id), [gridOffset](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md#attributes), [gridSpan](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md#attributes), [useSizeType](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md#attributes), [height](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#height), [touchable](../apis-arkui/arkui-ts/ts-universal-attributes-click.md#attributes), [margin](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin), [markAnchor](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#markanchor), [offset](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset), [width](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#width), [zIndex](../apis-arkui/arkui-ts/ts-universal-attributes-z-order.md#zindex), [visibility](../apis-arkui/arkui-ts/ts-universal-attributes-visibility.md#visibility), [scale](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale), [translate](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#translate), [responseRegion](../apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregion), [size](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#size), [opacity](../apis-arkui/arkui-ts/ts-universal-attributes-opacity.md#opacity), [shadow](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow), [sharedTransition](../apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md), [transition](../apis-arkui/arkui-ts/ts-transition-animation-component.md), and [position](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#position).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## domStorageAccess

domStorageAccess(domStorageAccess: boolean)

Sets whether to enable the DOM Storage API. By default, this feature is disabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  | Description                                |
| ---------------- | ------- | ---- | ------------------------------------ |
| domStorageAccess | boolean | Yes   | Whether to enable the DOM Storage API.<br>The value **true** means to the DOM Storage API, and **false** means the opposite.<br>The default value is **false**.|

> **NOTE**
>
> - A web page can be loaded only when its DOM Storage API is set to **true**.

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

## fileAccess

fileAccess(fileAccess: boolean)

Sets whether to enable access to the file system in the application. This setting does not affect the access to the files specified through [$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type   | Mandatory  | Description                  |
| ---------- | ------- | ---- | ---------------------- |
| fileAccess | boolean | Yes   | Whether to enable access to the file system in the application.<br>The value **true** means to enable access to the file system in the application, and **false** means the opposite.<br>For API versions 11 and earlier, the default value is **true**.<br>Since API version 12, the default value is **false**. When this parameter is set to **false**, only file protocol resources in the read-only resource directory **/data/storage/el1/bundle/entry/resources/resfile** can be accessed.|

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

## imageAccess

imageAccess(imageAccess: boolean)

Sets whether to enable automatic image loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description           |
| ----------- | ------- | ---- | --------------- |
| imageAccess | boolean | Yes   | Whether to enable automatic image loading.<br>The value **true** means to enable automatic image loading, and **false** means the opposite.<br>Default value: **true**|

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

## javaScriptProxy

javaScriptProxy(javaScriptProxy: JavaScriptProxy)

Registers an ArkTS object in **javaScriptProxy** with the **Web** component. The object is registered with all frameworks of the web page, including all iframes, using the name specified in **JavaScriptProxy**. This enables JavaScript to invoke methods of the ArkTS object in **javaScriptProxy**.

> **NOTE**
>
> The **javaScriptProxy** API must be used in pair with the **deleteJavaScriptRegister** API to prevent memory leaks.
> All parameters of the **javaScriptProxy** object cannot be updated.
> When registering a **javaScriptProxy** object, select at least one of the synchronous and asynchronous method lists, or both.
> Only one object can be registered through this API. To register multiple objects, use [registerJavaScriptProxy<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#registerjavascriptproxy).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- |---------------------------------------- |
| javaScriptProxy     | [JavaScriptProxy](./arkts-basic-components-web-i.md#javascriptproxy12)                                   | Yes   |  Object to be registered. Methods can be declared, but attributes cannot.                  |

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
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            try {
              this.controller.deleteJavaScriptRegister("objName");
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
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

## javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

Sets whether JavaScript scripts can be executed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  | Description               |
| ---------------- | ------- | ---- | ------------------- |
| javaScriptAccess | boolean | Yes   | Whether JavaScript scripts can be executed.<br>The value **true** indicates that JavaScript scripts can be executed, and **false** indicates the opposite.<br>Default value: **true**|

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

## overScrollMode<sup>11+</sup>

overScrollMode(mode: OverScrollMode)

Sets whether to enable overscroll mode. When overscroll mode is enabled and the boundary of the web page is reached, the **Web** component plays a bounce effect animation and return to the page. The internal page on the root page does not trigger bounce.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                   | Mandatory  | Description              |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [OverScrollMode](./arkts-basic-components-web-e.md#overscrollmode11) | Yes   | Whether to enable the overscroll mode.<br>The default value is **OverScrollMode.NEVER**, meaning to disable overscroll mode.|

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

## mixedMode

mixedMode(mixedMode: MixedMode)

Sets whether a secure source can load resources from a non-secure source. The default value is **MixedMode.None**, indicating that the secure origin cannot load resources from an insecure origin.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| mixedMode | [MixedMode](./arkts-basic-components-web-e.md#mixedmode) | Yes   | Mixed content to load.<br>The default value is **MixedMode.None**, indicating that the secure origin cannot load resources from an insecure origin.|

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

## onlineImageAccess

onlineImageAccess(onlineImageAccess: boolean)

Sets whether to enable access to online images through HTTP and HTTPS.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description            |
| ----------------- | ------- | ---- | ---------------- |
| onlineImageAccess | boolean | Yes   | Whether to enable access to online images through HTTP and HTTPS.<br>The value **true** means to enable access to online images through HTTP and HTTPS, and **false** means the opposite.<br>Default value: **true**|

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

## zoomAccess

zoomAccess(zoomAccess: boolean)

Sets whether to enable zoom gestures.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type   | Mandatory  | Description         |
| ---------- | ------- | ---- | ------------- |
| zoomAccess | boolean | Yes   | Whether to enable zoom gestures.<br>The value **true** means to enable zoom gestures, and **false** means the opposite.<br>Default value: **true**|

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

## overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

Sets whether to load web pages by using the overview mode. That is, zoom out the content to fit the screen width. Currently, only mobile devices are supported.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name               | Type   | Mandatory  | Description           |
| ------------------ | ------- | ---- | --------------- |
| overviewModeAccess | boolean | Yes   | Whether to load web pages by using the overview mode.<br>The value **true** means to load web pages by using the overview mode, and **false** means the opposite.<br>Default value: **true**|

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

## databaseAccess

databaseAccess(databaseAccess: boolean)

Sets whether to enable database access.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name           | Type   | Mandatory  | Description             |
| -------------- | ------- | ---- | ----------------- |
| databaseAccess | boolean | Yes   | Whether to enable database access.<br>The value **true** means to enable database access, and the value **false** means the opposite.<br>The default value is **false**.|

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

## geolocationAccess

geolocationAccess(geolocationAccess: boolean)

Sets whether to enable geolocation access. For details, see [Managing Location Permissions](../../web/web-geolocation-permission.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description           |
| ----------------- | ------- | ---- | --------------- |
| geolocationAccess | boolean | Yes   | Whether to enable geolocation access.<br>The value **true** means to enable geolocation access, and **false** means the opposite.<br>Default value: **true**|

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

## mediaPlayGestureAccess<sup>9+</sup>

mediaPlayGestureAccess(access: boolean)

Sets whether video playback must be started by user gestures. This API is not applicable to muted videos.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory  | Description               |
| ------ | ------- | ---- | ------------------- |
| access | boolean | Yes   | Whether video playback must be started by user gestures.<br>The value **true** indicates that video playback must be started by user gestures, and **false** indicates the opposite.<br>Default value: **true**|

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
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .mediaPlayGestureAccess(this.access)
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
      <title>Video Playback Page</title>
  </head>
  <body>
  <h1>Video Playback</h1>
  <video id="testVideo" controls autoplay>
      // Configure the autoplay attribute in the video tag to allow automatic video playback.
      // Save an MP4 media file in the rawfile directory of resources and name it example.mp4.
      <source src="example.mp4" type="video/mp4">
  </video>
  </body>
  </html>
  ```

## multiWindowAccess<sup>9+</sup>

multiWindowAccess(multiWindow: boolean)

Sets whether to enable the multi-window permission.
Enabling the multi-window permission requires implementation of the **onWindowNew** event. For the sample code, see [onWindowNew](./arkts-basic-components-web-events.md#onwindownew9).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description        |
| ----------- | ------- | ---- | ------------ |
| multiWindow | boolean | Yes   | Whether to enable the multi-window permission.<br>The value **true** means to enable the multi-window permission, and **false** means the opposite.<br>The default value is **false**.|

## horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

Sets whether to display the horizontal scrollbar, including the default system scrollbar and custom scrollbar.

> **NOTE**
>
> - If an @State decorated variable is used to control the horizontal scrollbar visibility, [controller.refresh()](./arkts-apis-webview-WebviewController.md#refresh) must be called for the settings to take effect.
> - If the vertical scrollbar visibility changes frequently through an @State decorated variable, it is recommended that the variable correspond to the **Web** component one by one.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name                | Type   | Mandatory  | Description        |
| ------------------- | ------- | ---- | ------------ |
| horizontalScrollBar | boolean | Yes   | Whether to display the horizontal scrollbar.<br>The value **true** means to display the horizontal scrollbar, and **false** means the opposite.<br>Default value: **true**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = true;
    @State btnMsg: string ="Hide the scrollbar";
  
    build() {
      Column() {
        // If an @State decorated variable is used to control the horizontal scrollbar visibility, controller.refresh() must be called for the settings to take effect.
        Button('refresh')
          .onClick(() => {
            if(this.isShow){
              this.isShow = false;
              this.btnMsg="Display the scrollbar";
            }else{
              this.isShow = true;
              this.btnMsg="Hide the scrollbar";
            }
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          }).height("10%").width("40%")
        Web({ src: $rawfile('index.html'), controller: this.controller }).height("90%")
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
      <meta name="viewport" id="viewport" content="width=device-width,initial-scale=1.0">
      <title>Demo</title>
      <style>
          body {
            width:3000px;
            height:6000px;
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

## verticalScrollBarAccess<sup>9+</sup>

verticalScrollBarAccess(verticalScrollBar: boolean)

Sets whether to display the vertical scrollbar, including the default system scrollbar and custom scrollbar.

> **NOTE**
>
> - If an @State decorated variable is used to control the vertical scrollbar visibility, **controller.refresh()** must be called for the settings to take effect.
> - If the vertical scrollbar visibility changes frequently through an @State decorated variable, it is recommended that the variable correspond to the **Web** component one by one.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type   | Mandatory  | Description        |
| ----------------- | ------- | ---- | ------------ |
| verticalScrollBar | boolean | Yes   | Whether to display the vertical scrollbar.<br>The value **true** means to display the vertical scrollbar, and **false** means the opposite.<br>Default value: **true**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = true;
    @State btnMsg: string ="Hide the scrollbar";
  
    build() {
      Column() {
        // If an @State decorated variable is used to control the horizontal scrollbar visibility, controller.refresh() must be called for the settings to take effect.
        Button(this.btnMsg)
          .onClick(() => {
            if(this.isShow){
              this.isShow = false;
              this.btnMsg="Display the scrollbar";
            }else{
              this.isShow = true;
              this.btnMsg="Hide the scrollbar";
            }
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          }).height("10%").width("40%")
        Web({ src: $rawfile('index.html'), controller: this.controller }).height("90%")
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
      <meta name="viewport" id="viewport" content="width=device-width,initial-scale=1.0">
      <title>Demo</title>
      <style>
          body {
            width:3000px;
            height:6000px;
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

## cacheMode

cacheMode(cacheMode: CacheMode)

Sets the cache mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| cacheMode | [CacheMode](./arkts-basic-components-web-e.md#cachemode) | Yes   | Cache mode to set.<br>Default value: **CacheMode.Default**|

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

## copyOptions<sup>11+</sup>

copyOptions(value: CopyOptions)

Sets the pasteboard copy options.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description     |
| --------- | --------------------------- | ---- | --------- |
| value | [CopyOptions](../apis-arkui/arkui-ts/ts-appendix-enums.md#copyoptions9) | Yes   | Pasteboard copy options.<br>Default value: **CopyOptions.LocalDevice**|

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

## textZoomRatio<sup>9+</sup>

textZoomRatio(textZoomRatio: number)

Sets the text zoom ratio of the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description                            |
| ------------- | ------ | ---- | -------------------------------- |
| textZoomRatio | number | Yes   | Text zoom ratio to set.<br>The value is an integer. The value range is (0, 2147483647].<br>Default value: **100**|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State ratio: number = 150;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomRatio(this.ratio)
      }
    }
  }
  ```

## initialScale<sup>9+</sup>

initialScale(percent: number)

Sets the scale factor of the entire page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory  | Description                         |
| ------- | ------ | ---- | ----------------------------- |
| percent | number | Yes   | Scale factor of the entire page.<br>Value range: (0, 1000]<br>Default value: **100**|

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

## blockNetwork<sup>9+</sup>

blockNetwork(block: boolean)

Sets whether to block online downloads.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory  | Description               |
| ----- | ------- | ---- | ------------------- |
| block | boolean | Yes   | Whether to block online downloads.<br>The value **true** means to block online downloads, and **false** means the opposite.<br>The default value is **false**.|

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

## defaultFixedFontSize<sup>9+</sup>

defaultFixedFontSize(size: number)

Sets the default fixed font size for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Default fixed font size to set, in px.<br>The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 px are handled as 72 px, and values less than 1 px are handled as 1 px.<br>Default value: **13**|

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

## defaultFontSize<sup>9+</sup>

defaultFontSize(size: number)

Sets the default font size for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Default font size to set, in px.<br>The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 px are handled as 72 px, and values less than 1 px are handled as 1 px.<br>Default value: **16**|

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

## minFontSize<sup>9+</sup>

minFontSize(size: number)

Sets the minimum font size for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Minimum font size to set, in px.<br>The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 px are handled as 72 px, and values less than 1 px are handled as 1 px.<br>Default value: **8**|

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

## minLogicalFontSize<sup>9+</sup>

minLogicalFontSize(size: number)

Sets the minimum logical font size for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | Yes   | Minimum logical font size to set, in px.<br>The value ranges from -2^31 to 2^31-1. In actual rendering, values greater than 72 px are handled as 72 px, and values less than 1 px are handled as 1 px.<br>Default value: **8**|

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

## webFixedFont<sup>9+</sup>

webFixedFont(family: string)

Sets a fixed font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Fixed font family to set.<br>Default value: **monospace**|

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

## webSansSerifFont<sup>9+</sup>

webSansSerifFont(family: string)

Sets a sans serif font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Sans serif font family to set.<br>Default value: **sans-serif**|

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

## webSerifFont<sup>9+</sup>

webSerifFont(family: string)

Sets a serif font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Serif font family to set.<br>Default value: **serif**|

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

## webStandardFont<sup>9+</sup>

webStandardFont(family: string)

Sets a standard font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                  |
| ------ | ------ | ---- | ---------------------- |
| family | string | Yes   | Standard font family to set.<br>Default value: **sans-serif**|

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

## webFantasyFont<sup>9+</sup>

webFantasyFont(family: string)

Sets a fantasy font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Fantasy font family to set.<br>Default value: **fantasy**|

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

## webCursiveFont<sup>9+</sup>

webCursiveFont(family: string)

Sets a cursive font family for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                    |
| ------ | ------ | ---- | ------------------------ |
| family | string | Yes   | Cursive font family to set.<br>Default value: **cursive**|

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

## darkMode<sup>9+</sup>

darkMode(mode: WebDarkMode)

Sets dark mode for the web page. When dark mode is enabled, the **Web** component enables the dark style defined in the media query **prefers-color-scheme** of the web page. If it is not defined, the web page remains unchanged. To enable forcible dark mode, use this API with [forceDarkAccess](#forcedarkaccess9). For details about how to use dark mode, see [Setting Dark Mode](../../web/web-set-dark-mode.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                            | Mandatory  | Description                    |
| ---- | -------------------------------- | ---- | ------------------------ |
| mode | [WebDarkMode](./arkts-basic-components-web-e.md#webdarkmode9) | Yes   | Dark mode for the web page, which can be set to **Off**, **On**, or **Auto**.<br>Default value: **WebDarkMode.Off**|

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

## forceDarkAccess<sup>9+</sup>

forceDarkAccess(access: boolean)

Sets whether to enable forcible dark mode for the web page. This API is applicable only when [darkMode](#darkmode9) is enabled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory  | Description           |
| ------ | ------- | ---- | --------------- |
| access | boolean | Yes   | Whether to enable forcible dark mode for the web page.<br>The value **true** means to enable forcible dark mode for the web page, and **false** means the opposite.<br>The default value is **false**.|

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

## pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

Sets whether to enable pinch smooth mode for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type   | Mandatory  | Description         |
| --------- | ------- | ---- | ------------- |
| isEnabled | boolean | Yes   | Whether to enable pinch smooth mode for the web page.<br>The value **true** means to enable pinch smooth mode, and **false** means the opposite.<br>The default value is **false**.|

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

## allowWindowOpenMethod<sup>10+</sup>

allowWindowOpenMethod(flag: boolean)

Sets whether to allow a new window to automatically open through JavaScript.

> **NOTE**
>
> - This API takes effect only when [javaScriptAccess](#javascriptaccess) is enabled.
> - This API opens a new window when [multiWindowAccess](#multiwindowaccess9) is enabled, and a local window when it is disabled.
> - The default value of **flag** is subject to the settings of the **persist.web.allowWindowOpenMethod.enabled** system attribute. If this attribute is not set, the default value of **flag** is **false**.
> - Run the **hdc shell param get persist.web.allowWindowOpenMethod.enabled** command to check whether the system attribute **persist.web.allowWindowOpenMethod.enabled** is enabled. If the attribute value is **1**, the system attribute is enabled. If the attribute value is **0** or does not exist, the system attribute is disabled. You can run the **hdc shell param set persist.web.allowWindowOpenMethod.enabled 1** command to enable the system attribute.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type   | Mandatory   | Description                     |
| ---- | ------- | ---- | ------------------------- |
| flag | boolean | Yes   | <br>Whether to allow a new window to automatically open through JavaScript. The value **true** means to allow a new window to automatically open through JavaScript, and **false** means only to allow a new window to automatically open through JavaScript using user behaviors.<br>The user behavior here refers to a user requests to open a new window (**window.open**) within 5 seconds after operating the **Web** component.<br>The default value of **flag** is subject to the settings of the **persist.web.allowWindowOpenMethod.enabled** system attribute. If this attribute is set to **true**, the default value of **flag** is **true**. If this attribute is not set, the default value of **flag** is **false**.|

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
            // Return the WebviewController object corresponding to the new window to the web kernel.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            // If no new window is created, set the value of event.handler.setWebController to null to notify the Web component that no new window is created.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

## mediaOptions<sup>10+</sup>

mediaOptions(options: WebMediaOptions)

Sets the web-based media playback policy, including the validity period for automatically resuming a paused web audio, and whether the audio of multiple **Web** instances in an application is exclusive.

> **NOTE**
>
> - Audios in the same **Web** instance are considered as the same audio.
> - The media playback policy controls videos with an audio track.
> - You are advised to set [audioExclusive](./arkts-basic-components-web-i.md#webmediaoptions10) to the same value for all **Web** components.
> - Audio and video interruption takes effect within an application and between applications, and playback resumption takes effect only between applications.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                                 | Mandatory  | Description                                    |
| ------- | ------------------------------------- | ---- | ---------------------------------------- |
| options | [WebMediaOptions](./arkts-basic-components-web-i.md#webmediaoptions10) | Yes   | Web-based media playback policy.<br>After the parameter settings are updated, the playback must be started again for the settings to take effect.<br>Default value: **{resumeInterval: 0, audioExclusive: true}**|

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

## javaScriptOnDocumentStart<sup>11+</sup>

javaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document starts to be loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree may not have been loaded or rendered.
>
> - This script is executed in lexicographical order in this API. To execute the script in array order, you are advised to use the [runJavaScriptOnDocumentStart](#runjavascriptondocumentstart15) API.
>
> - You are not advised to use this API together with [runJavaScriptOnDocumentStart](#runjavascriptondocumentstart15).
>
> - If a script with the same content is injected for multiple times, the script is silently deduplicated, not displayed, and no notification is displayed. The **scriptRules** of the first injection is used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | Yes   | Script item array to be injected.|

**Example of the .ets file**

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
**Example of the HTML file**

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

## javaScriptOnDocumentEnd<sup>11+</sup>

javaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document has been loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree has been loaded and rendered.
>
> - The script is executed in the lexicographical order, not the array order.
>
> - You are not advised to use this API together with [runJavaScriptOnDocumentEnd](#runjavascriptondocumentend15).
>
> - If a script with the same content is injected for multiple times, the script is silently deduplicated, not displayed, and no notification is displayed. The **scriptRules** of the first injection is used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | Yes   | Script item array to be injected.|

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

## runJavaScriptOnDocumentStart<sup>15+</sup>

runJavaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document starts to be loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree may not have been loaded or rendered.
>
> - This script is executed in the array order.
>
> - You are advised not to use this API together with [javaScriptOnDocumentStart](#javascriptondocumentstart11).
>
> - If a script with the same content is injected for multiple times, the script is silently deduplicated, not displayed, and no notification is displayed. The **scriptRules** of the first injection is used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | Yes   | Script item array to be injected.|

**Example of the .ets file**

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
                  .runJavaScriptOnDocumentStart(this.scripts)
                  .width('100%')
                  .height('100%')
          }
      }
  }
  ```
**Example of the HTML file**

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

## runJavaScriptOnDocumentEnd<sup>15+</sup>

runJavaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the specified page or document has been loaded, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - The script runs before any JavaScript code of the page, when the DOM tree has been loaded and rendered.
>
> - This script is executed in the array order.
>
> - You are advised not to use this API together with [javaScriptOnDocumentEnd](#javascriptondocumentend11).
>
> - If a script with the same content is injected for multiple times, the script is silently deduplicated, not displayed, and no notification is displayed. The **scriptRules** of the first injection is used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | Yes   | Script item array to be injected.|

**Example**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from runJavaScriptOnDocumentEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .runJavaScriptOnDocumentEnd(this.scripts)
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

## runJavaScriptOnHeadEnd<sup>15+</sup>

runJavaScriptOnHeadEnd(scripts: Array\<ScriptItem>)

Injects a JavaScript script into the **Web** component. When the **head** tag of the DOM tree is parsed, the script is executed on any page whose source matches **scriptRules**.

> **NOTE**
>
> - This script is executed in the array order.
>
> - If a script with the same content is injected for multiple times, the script is silently deduplicated, not displayed, and no notification is displayed. The **scriptRules** of the first injection is used.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                               | Mandatory  | Description              |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | Yes   | Script item array to be injected.|

**Example**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from runJavaScriptOnHeadEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .runJavaScriptOnHeadEnd(this.scripts)
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

## layoutMode<sup>11+</sup>

layoutMode(mode: WebLayoutMode)

Sets the web layout mode. For details, see [Fitting In the Page Content Layout](../../web/web-fit-content.md).

> **NOTE**
>
> Currently, only two web layout modes are supported: **WebLayoutMode.NONE** and **WebLayoutMode.FIT_CONTENT**.
>
> The following restrictions apply with the usage of **WebLayoutMode.FIT_CONTENT**:
> - If the **Web** component is wider or longer than 7680 px, specify the **RenderMode.SYNC_RENDER** mode when creating the **Web** component; otherwise, the screen may be blank.
> - After the **Web** component is created, dynamic switching of the **layoutMode** is not supported.
> - The width and height of a **Web** component cannot exceed 500,000 px when the **RenderMode.SYNC_RENDER** mode is specified, and cannot exceed 7680 px when the **RenderMode.ASYNC_RENDER** mode is specified.
> - Frequent changes to the page width and height will trigger a re-layout of the **Web** component, which can affect the user experience.
> - Waterfall web pages are not supported (pull down to the bottom to load more).
> - Width adaptation is not supported. Only height adaptation is supported.
> - Because the height is adaptive to the web page height, the component height cannot be changed by modifying the component height attribute.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                 | Mandatory  | Description                 |
| ---- | ------------------------------------- | ---- | --------------------- |
| mode | [WebLayoutMode](./arkts-basic-components-web-e.md#weblayoutmode11) | Yes   | Web layout mode.<br>Default value: **WebLayoutMode.NONE**|

**Example**

  1. After specifying the **layoutMode** to **WebLayoutMode.FIT_CONTENT**, you need to explicitly specify the **renderMode** to **RenderMode.SYNC_RENDER**. Otherwise, rendering errors may occur when the viewport height exceeds 7680 px in the default **RenderMode.ASYNC_RENDER**.
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

  2. After specifying the layoutMode to **WebLayoutMode.FIT_CONTENT**, you are advised to specify [overScrollMode](#overscrollmode11) to **OverScrollMode.NEVER**. Otherwise, when the web page scrolls to the edge in the nested scrolling scenario, the rebounding effect is triggered first, which affects user experience.
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

## nestedScroll<sup>11+</sup>

nestedScroll(value: NestedScrollOptions | NestedScrollOptionsExt)

Sets nested scrolling options.

> **NOTE**
>
> - You can set the up, down, left, and right directions, or set the forward and backward nested scrolling modes to implement scrolling linkage with the parent component.
> - Containers that support nested scrolling: [Grid](../apis-arkui/arkui-ts/ts-container-grid.md), [List](../apis-arkui/arkui-ts/ts-container-list.md), [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md), [Swiper](../apis-arkui/arkui-ts/ts-container-swiper.md), [Tabs](../apis-arkui/arkui-ts/ts-container-tabs.md), [WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md), [Refresh](../apis-arkui/arkui-ts/ts-container-refresh.md) and [bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet).
> - Input sources that support nested scrolling: gestures, mouse device, and touchpad.
> - In nested scrolling scenarios, since the **Web** component's over-scrolling to the edge will trigger the over-scroll bounce effect first, it is recommended that you set [overScrollMode](#overscrollmode11) to **OverScrollMode.NEVER** to avoid undermining user experience.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                    | Mandatory  | Description            |
| ----- | ---------------------------------------- | ---- | ---------------- |
| value | [NestedScrollOptions](../apis-arkui/arkui-ts/ts-container-scrollable-common.md#nestedscrolloptions10)\| [NestedScrollOptionsExt](./arkts-basic-components-web-i.md#nestedscrolloptionsext14)<sup>14+</sup> | Yes   | Nested scrolling options.<br> When the **value** is of the **NestedScrollOptions** type (forward and backward), the default nested scrolling mode of the **scrollForward** and **scrollBackward** options is **NestedScrollMode.SELF_FIRST**.<br> When the **value** is of the **NestedScrollOptionsExt** type (up, down, left, and right), the default nested scrolling mode of the **scrollUp**, **scrollDown**, **scrollLeft**, and **scrollRight **options is [NestedScrollMode.SELF_FIRST](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10).|

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

## bypassVsyncCondition<sup>20+</sup>

bypassVsyncCondition(condition: WebBypassVsyncCondition)

Sets the rendering process to bypass vsync (vertical synchronization) scheduling and directly trigger drawing when the **scrollBy** API is called to scroll the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                 | Mandatory  | Description                 |
| ---- | ------------------------------------- | ---- | --------------------- |
| condition | [WebBypassVsyncCondition](./arkts-basic-components-web-e.md#webbypassvsynccondition20) | Yes   | Condition for triggering the rendering process to bypass vsync scheduling.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    condition: WebBypassVsyncCondition = WebBypassVsyncCondition.SCROLLBY_FROM_ZERO_OFFSET;

    build() {
      Column() {
        Button('scrollBy')
          .onClick(() => {
            this.controller.scrollBy(0, 5);
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .bypassVsyncCondition(this.condition)
      }
    }
  }
  ```

## enableNativeEmbedMode<sup>11+</sup>

enableNativeEmbedMode(mode: boolean)

Sets whether to enable the same-layer rendering feature.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                     | Mandatory  | Description            |
| ----- | ---------------------------------------- | ---- | ---------------- |
| mode |  boolean | Yes   | Whether to enable the same-layer rendering feature.<br>The value **true** means to enable the same-layer rendering feature, and **false** means the opposite.<br>The default value is **false**.|

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
## forceDisplayScrollBar<sup>14+</sup>

forceDisplayScrollBar(enabled: boolean)


Sets whether the scroll bar is always visible. Under the always-visible settings, when the page size exceeds one page, the scroll bar appears and remains visible.

When **layoutMode** is set to **WebLayoutMode.FIT_CONTENT**, the **enabled** parameter is set to **false**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type| Mandatory| Description          |
| ------- | -------- | ---- | ------------------ |
| enabled | boolean  | Yes  | Whether the scroll bar is always visible.<br>The value **true** indicates that the scroll bar is always visible, and **false** indicates the opposite.<br>The default value is **false**.|


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
          .forceDisplayScrollBar(true)
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
      <title>Demo</title>
      <style>
        body {
          width:2560px;
          height:2560px;
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
## registerNativeEmbedRule<sup>12+</sup>

registerNativeEmbedRule(tag: string, type: string)

Registers the HTML tag name and type for same-layer rendering. The tag name only supports <object\> and <embed\>. The tag type only supports visible ASCII characters.

If the specified type is the same as the W3C standard <object\> or <embed\> type, the ArkWeb kernel identifies the type as a non-same-layer tag.

This API is also controlled by **enableNativeEmbedMode** and does not take effect when same-layer rendering is disabled. When this API is not used, the ArkWeb kernel recognizes the <embed\> tags with the "native/" prefix as same-layer tags.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description            |
|------|--------| ---- |------------------|
| tag  | string | Yes   | Tag name.            |
| type | string | Yes  | Tag type. The ArkWeb kernel uses a prefix to match this parameter.|

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
## defaultTextEncodingFormat<sup>12+</sup>

defaultTextEncodingFormat(textEncodingFormat: string)

Sets the default text encoding format for the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| textEncodingFormat | string | Yes   | Default text encoding format. Default value: **"UTF-8"**|

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
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width" />
    <title>My test html5 page</title>
</head>
<body>
    <p>Hello world!</p>
</body>
</html>
```
## metaViewport<sup>12+</sup>

metaViewport(enabled: boolean)

Sets whether the **viewport** attribute of the **meta** tag is enabled.

> **NOTE**
>
> - If the device is 2-in-1, the **viewport** attribute is not supported. This means that, regardless of whether this parameter is set to **true** or **false**, the **viewport** attribute will not be parsed and a default layout will be used.
> - If the device is a tablet, the **viewport-fit** attribute of the **meta** tag is parsed regardless of whether this parameter is set to **true** or **false**. When **viewport-fit** is set to **cover**, the size of the safe area can be obtained through the CSS attribute.
> - Currently, the **viewport** parameter of the **meta** tag on the frontend HTML page is enabled or disabled based on whether **User-Agent** contains the **Mobile** field. If a **User-Agent** does not contain the **Mobile** field, the **viewport** attribute in the **meta** tag is disabled by default. In this case, you can explicitly set the **metaViewport** attribute to **true** to overwrite the disabled state.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | -------- | ---- | -------------------------------- |
| enabled | boolean  | Yes  | Whether the **viewport** attribute of the **meta** tag is enabled.<br>The value **true** indicates that the **viewport** attribute of the **meta** tag is enabled and parsed, and the layout is performed based on the **viewport** attribute.<br>The value **false** indicates the **viewport** attribute of the **meta** tag is disabled and not parsed, and the default layout is used.<br>Default value: **true**|

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
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <p>Hello world!</p>
</body>
</html>
```

## textAutosizing<sup>12+</sup>

textAutosizing(textAutosizing: boolean)

Sets whether to enable automatic text resizing.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| textAutosizing | boolean | Yes   | Whether to enable automatic text resizing.<br>The value **true** means to enable automatic text resizing, and **false** means the opposite.<br>Default value: **true**|

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
## enableNativeMediaPlayer<sup>12+</sup>

enableNativeMediaPlayer(config: NativeMediaPlayerConfig)

Sets whether to enable the [application takeover of web media playback feature](../../web/app-takeovers-web-media.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description|
| ---- | ------ | ---- | ---------------------|
| config | [NativeMediaPlayerConfig](./arkts-basic-components-web-i.md#nativemediaplayerconfig12) | Yes   | **enable**: whether to enable the feature.<br> **shouldOverlay**: whether the image of the video player taken over by the application will overlay the web page content, if this feature is enabled.<br>Default value: **{enable: false, shouldOverlay: false}**|

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

## onAdsBlocked<sup>12+</sup>

onAdsBlocked(callback: OnAdsBlockedCallback)

Called after an ad is blocked on the web page to notify the user of detailed information about the blocked ad. To reduce the frequency of notifications and minimize the impact on the page loading process, only the first notification is made when the page is fully loaded. Subsequent blocking events are reported at intervals of 1 second, and no notifications are sent if there is no ad blocked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnAdsBlockedCallback](./arkts-basic-components-web-t.md#onadsblockedcallback12) | Yes| Callback of **onAdsBlocked**.|

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

## keyboardAvoidMode<sup>12+</sup>

keyboardAvoidMode(mode: WebKeyboardAvoidMode)

Sets the custom soft keyboard avoidance mode.

If the keyboard avoidance mode set in **UIContext** is [KeyboardAvoidMode.RESIZE](../apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11), this API does not take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                             | Mandatory  | Description         |
| ------------------- | ------------------------------   | ------ | ------------- |
| mode | [WebKeyboardAvoidMode](./arkts-basic-components-web-e.md#webkeyboardavoidmode12) | Yes    | Web soft keyboard avoidance mode.<br>In the nested scrolling scenario, the soft keyboard avoidance mode of the **Web** component is not recommended, including **RESIZE_VISUAL** and **RESIZE_CONTENT**.<br>Default value: **WebKeyboardAvoidMode.RESIZE_CONTENT**|

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

## editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

Sets the custom menu options of the **Web** component.

You can use this attribute to customize a text menu.

You can use [onCreateMenu](../apis-arkui/arkui-ts/ts-text-common.md#oncreatemenu12) to modify, add, and delete menu options. If you do not want to display the text menu, return an empty array.

You can use [onMenuItemClick](../apis-arkui/arkui-ts/ts-text-common.md#onmenuitemclick12) to customize the callback for menu options. This function is triggered after a menu option is clicked and determines whether to execute the default callback based on the return value. If **true** is returned, the system callback is not executed. If **false** is returned, the system callback is executed.

In onPrepareMenu<sup>20+</sup>, this callback is triggered after the text selection area changes and before the menu is displayed. You can modify, add, or delete menu options in the callback to dynamically update the menu.

If this method is used together with [selectionMenuOptions<sup>(deprecated)</sup>](#selectionmenuoptionsdeprecated), the **selectionMenuOptions<sup> (deprecated) </sup>** method does not take effect.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                             | Mandatory  | Description         |
| ------------------- | ------------------------------   | ------ | ------------- |
| editMenu | [EditMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#editmenuoptions) | Yes    | Custom menu options of the **Web** component.<br>The number of menu options, menu content size, and icon size must be the same as those of the ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md) component.<br>The values of ([TextMenuItemId](../apis-arkui/arkui-ts/ts-text-common.md#textmenuitemid12)) supported by the **Web** component are **CUT**, **COPY**, **PASTE**, **SELECT_ALL**, **TRANSLATE**, **SEARCH**, and **AI_WRITER**.<br>**textRange** in **onMenuItemClick()** is meaningless in the **Web** component. The input value is **-1**.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

let selectText:string = '';
class TestClass {
  setSelectText(param: String) {
    selectText = param.toString();
  }
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State testObj: TestClass = new TestClass();

  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // Filter the menu items as required.
      return (
        menuItem.id.equals(TextMenuItemId.CUT) ||
        menuItem.id.equals(TextMenuItemId.COPY) ||
        menuItem.id.equals((TextMenuItemId.PASTE)) ||
        menuItem.id.equals((TextMenuItemId.TRANSLATE)) ||
        menuItem.id.equals((TextMenuItemId.SEARCH)) ||
        menuItem.id.equals((TextMenuItemId.AI_WRITER))
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
    items.push(customItem1);// Add an item to the end of the item list.
    items.unshift(customItem2);// Add an item to the beginning of the item list.

    return items;
  }

  onMenuItemClick(menuItem: TextMenuItem, textRange: TextRange): boolean {
    if (menuItem.id.equals(TextMenuItemId.CUT)) {
      // Custom behavior
      console.log("Intercept ID: CUT")
      return true; // Return true to not execute the system callback.
    } else if (menuItem.id.equals(TextMenuItemId.COPY)) {
      // Custom behavior
      console.log("Not intercept ID: COPY")
      return false; // Return false to execute the system callback.
    } else if (menuItem.id.equals(TextMenuItemId.of('customItem1'))) {
      // Custom behavior
      console.log("Intercept ID: customItem1")
      return true;// Custom menu item. If true is returned, the menu is not closed after being clicked. If false is returned, the menu is closed.
    } else if (menuItem.id.equals((TextMenuItemId.of($r('app.string.customItem2'))))){
      // Custom behavior
      console.log("Intercept ID: app.string.customItem2")
      return true;
    }
    return false;// Return the default value false.
  }

   onPrepareMenu(menuItems: Array<TextMenuItem>) => {
    let item1: TextMenuItem = {
      content: 'prepare1',
      id: TextMenuItemId.of('prepareMenu1'),
    };
    let item2: TextMenuItem = {
      content: 'prepare2' + selectText,
      id: TextMenuItemId.of('prepareMenu2'),
    };
    items.push(item1);// Add an item to the end of the item list.
    items.unshift(item2);// Add an item to the beginning of the item list.

    return items;
  }

  @State EditMenuOptions: EditMenuOptions =
    { onCreateMenu: this.onCreateMenu, onMenuItemClick: this.onMenuItemClick, onPrepareMenu:this.onPrepareMenu }

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .editMenuOptions(this.EditMenuOptions)
        .javaScriptProxy({
          object: this.testObj,
          name: "testObjName",
          methodList: ["setSelectText"],
          controller: this.controller,
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
    <h1>editMenuOptions Demo</h1>
    <span>edit menu options</span>
    <script>
      function callArkTS() {
        let str = testObjName.test();
        document.getElementById("demo").innerHTML = str;
      }

      document.addEventListener('selectionchange', () => {
        var selection = window.getSelection();
        if (selection.rangeCount > 0) {
          var selectedText = selection.toString();
          testObjName.setSelectText(selectedText);
        }
        callArkTS();
      });
  </script>
  </body>
</html>
```

## enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(enabled: boolean)

Sets whether to enable haptic feedback for long-pressed text in the **Web** component. The **ohos.permission.VIBRATE** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type       | Mandatory  | Description|
| --------- | ---------   | ------ | ------------- |
| enabled   | boolean | Yes | Whether to enable haptic feedback for long-pressed text in the **Web** component.<br>The value **true** means to enable haptic feedback for long-pressed text in the **Web** component, and **false** means the opposite.<br>Default value: **true**|

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

## bindSelectionMenu<sup>13+</sup>

bindSelectionMenu(elementType: WebElementType, content: CustomBuilder, responseType: WebResponseType, options?: SelectionMenuOptionsExt)

Sets the custom selection menu.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                            | Mandatory| Description                               |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| elementType     | [WebElementType](./arkts-basic-components-web-e.md#webelementtype13)             | Yes  | Menu type.  |
| content      | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)     | Yes  | Menu content.  |
| responseType | [WebResponseType](./arkts-basic-components-web-e.md#webresponsetype13)           | Yes  | Response type of the menu.|
| options      | [SelectionMenuOptionsExt](./arkts-basic-components-web-i.md#selectionmenuoptionsext13)   | No  | Menu options.|

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
  uiContext: UIContext = this.getUIContext();

  @Builder
  MenuBuilder() {
    Menu() {
      MenuItem({ content: 'Copy', })
        .onClick(() => {
          this.result?.copy();
          this.result?.closeContextMenu();
        })
      MenuItem({ content: 'Select All', })
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
              this.previewWidth = this.uiContext!.px2vp(event.param.getPreviewWidth());
              this.previewHeight = this.uiContext!.px2vp(event.param.getPreviewHeight());
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

## blurOnKeyboardHideMode<sup>14+</sup>

blurOnKeyboardHideMode(mode: BlurOnKeyboardHideMode)

Sets whether to enable blur mode for the web element when soft keyboard is hidden.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                   | Mandatory  | Description              |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [BlurOnKeyboardHideMode](./arkts-basic-components-web-e.md#bluronkeyboardhidemode14) | Yes   | Whether to enable blur mode of the web element when soft keyboard is hidden. The default value is **BlurOnKeyboardHideMode.SILENT**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State blurMode: BlurOnKeyboardHideMode = BlurOnKeyboardHideMode.BLUR;
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .blurOnKeyboardHideMode(this.blurMode)
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
    <h1>blurOnKeyboardHideMode Demo</h1>
    <input type="text" id="input_a">
    <script>
      const inputElement = document.getElementById('input_a');
      inputElement.addEventListener('blur', function() {
        console.log('Input has lost focus');
      });
    </script>
  </body>
</html>
```

## enableFollowSystemFontWeight<sup>18+</sup>

enableFollowSystemFontWeight(follow: boolean)

Sets whether the **Web** component can change the font weight according to the system settings.

> **NOTE**
>
> Currently, only front-end text elements support this capability. The **canvas** element and embedded .docx and .pdf texts do not support this capability.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                            | Mandatory| Description                               |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| follow | boolean | Yes   | Whether the **Web** component can change the font weight according to the system settings.<br>The value **true** means that the **Web** component can change the font weight according to the system settings, and **false** means the opposite.<br>The default value is **false**.|

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
        Web({ src: "www.example.com", controller: this.controller })
          .enableFollowSystemFontWeight(true)
      }
    }
  }
  ```

## optimizeParserBudget<sup>15+</sup>

optimizeParserBudget(optimizeParserBudget: boolean)

Sets whether to enable segment-based HTML parsing optimization.

To avoid occupying too many main thread resources and enable progressive loading of web pages, the ArkWeb kernel uses the segment-based parsing policy when parsing the HTML files. By default, the ArkWeb kernel uses the parsing time as the segment point. When the parsing time exceeds the threshold, the parsing is interrupted and then the layout and rendering operations are performed.

After this optimization is enabled, the ArkWeb kernel checks whether the parsing time exceeds the limit and whether the number of parsed tokens (minimum parsing unit of HTML files, such as **\<div>** and **attr="xxx"**) exceeds the threshold specified by the kernel. If yes, the ArkWeb kernel decreases the threshold. When the First Contentful Paint (FCP) of the page is triggered, the default interrupt judgment logic is restored. In this way, the web page is parsed more frequently before the FCP is triggered, thereby the first-frame content may be parsed in advance and enter a rendering phase, effectively reducing the workload of first-frame rendering, and finally advancing the FCP.

When the FCP of a page is triggered, the default segment parsing logic is restored. Therefore, the segment-based HTML parsing optimization takes effect only for the first page loaded by each **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type   | Mandatory  | Description                  |
| ---------- | ------- | ---- | ---------------------- |
| optimizeParserBudget | boolean | Yes   | Whether to enable segment-based HTML parsing optimization.<br>The value **true** means to use the number of parsed records instead of the parsing time as the segment point for HTML segment parsing, and reduce the upper limit of the number of parsed records in each segment. The value **false** means to use the parsing time as the segment point for HTML segment parsing.<br>The default value is **false**.|


**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .optimizeParserBudget(true)
      }
    }
  }
  ```

## enableWebAVSession<sup>18+</sup>

enableWebAVSession(enabled: boolean)

Sets whether to support an application to connect to media controller.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type| Mandatory| Description          |
| ------- | -------- | ---- | ------------------ |
| enabled | boolean  | Yes  | Whether to support an application to connect to media controller.<br>The value **true** means to support an application to connect to media controller, and **false** means the opposite.<br>Default value: **true**|

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
          .enableWebAVSession(true)
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
      <title>Video Playback Page</title>
  </head>
  <body>
      <h1>Video Playback</h1>
      <video id="testVideo" controls>
          // Save an MP4 media file in the rawfile directory of resources and name it example.mp4.
          <source src="example.mp4" type="video/mp4">
      </video>
  </body>
  </html>
  ```

## nativeEmbedOptions<sup>16+</sup>

nativeEmbedOptions(options?: EmbedOptions)

Sets the same-layer rendering configuration. This attribute takes effect only when [enableNativeEmbedMode](#enablenativeembedmode11) is enabled and cannot be dynamically modified.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type                            | Mandatory| Description                               |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| options | [EmbedOptions](./arkts-basic-components-web-i.md#embedoptions16) | No   | Same-layer rendering configuration. The default value is **{supportDefaultIntrinsicSize: false}**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    options: EmbedOptions = {supportDefaultIntrinsicSize: true};

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .nativeEmbedOptions(this.options)
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
      <title>Same-Layer Rendered Fixed-Size HTML Test</title>
  </head>
  <body>
  <div>
      <embed id="input" type = "native/view" style = "background-color:red"/>
  </div>
  </body>
  </html>
  ```
## enableDataDetector<sup>20+</sup>

enableDataDetector(enable: boolean)

Sets whether to recognize special entities of web texts. This API depends on the text recognition capability at the bottom layer of the device. Otherwise, the setting is invalid.

If **enableDataDetector** is set to **true** and [dataDetectorConfig](#datadetectorconfig20) is not set, all types of entities will be recognized, and the **color** and **decoration** attributes of the recognized entities will be changed to the following styles:
<!--code_no_check-->
```ts
color: '#ff007dff'
decoration:{
  type: TextDecorationType.Underline,
  color: '#ff007dff',
  style: TextDecorationStyle.SOLID
}
```

Currently, full-text entity recognition is triggered only after the page is loaded. The filtering rules for entity recognition are as follows:

- Text entities in the text box and editable area are not processed.
- The text entity in the <a></a> tag is not processed.
- Text entities in cross-domain iframes and nested iframes are not processed.
- Cross-node entities are not recognized. For example, `<div>Satu</div><div>rday</div>`.


After a text entity on a web page is processed, it is converted into a hyperlink. When you touch or click the entity, the corresponding entity operation menu is displayed based on the entity type. Long-press, touch-drag, right-click, or mouse-drag on a hyperlink will trigger its default action.

If the calculation style of the page text element contains **user-select:none** or the page Javascript intercepts the **select** event, the **Select text** option in the entity menu is invalid, but the entity text can still be copied.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | --------------------------------- |
| enable  | boolean | Yes  | Whether to enable web text recognition. The value **true** means to enable web text recognition, and **false** means the opposite.<br>Default value: **false**.|

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
          .enableDataDetector(true)
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
      <title>Example enableDataDetector</title>;
  </head>
  <body>
      <p> Telephone: 400-123-4567 </p>
      <p>Email: example@example.com </p>
  </body>
  </html>
  ```

## dataDetectorConfig<sup>20+</sup>

dataDetectorConfig(config: TextDataDetectorConfig)

Configures text recognition settings.

This API must be used together with [enableDataDetector](#enabledatadetector20). It takes effect only when **enableDataDetector** is set to **true**.

When entities A and B overlap, the following rules are followed:

1. If A is a subset of B (A ⊂ B), then B is retained; otherwise, A is retained.

2. If A is not a subset of B (A ⊄ B) and B is not a subset of A (B ⊄ A), and if the starting point of A is earlier than that of B (A.start < B.start), then A is retained; otherwise, B is retained.


**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                                                       | Mandatory| Description                                                        |
| ------ | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [TextDataDetectorConfig](../apis-arkui/arkui-ts/ts-text-common.md#textdatadetectorconfig11)| Yes  | Text recognition configuration.|

> **NOTE**
> 
> The **onDetectResultUpdate** method in **TextDataDetectorConfig** is not supported in the **Web** component. The configured callback will not be called.

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
          .enableDataDetector(true)
          .dataDetectorConfig({
            types: [
              TextDataDetectorType.PHONE_NUMBER,
              TextDataDetectorType.EMAIL
            ],
            color: Color.Red,
            decoration: {
              type: TextDecorationType.LineThrough,
              color: Color.Green,
              style: TextDecorationStyle.WAVY
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
      <title>Example dataDetectorConfig</title>;
  </head>
  <body>
      <p> Telephone: 400-123-4567 </p>
      <p> Email: 12345678901@example.com </p>
      <p> Website: www.example.com (cannot be identified) </p>
  </body>
  </html>
  ```

## gestureFocusMode<sup>20+</sup>

gestureFocusMode(mode: GestureFocusMode)

Sets the gesture focus mode of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                             | Mandatory  | Description         |
| ------------------- | ------------------------------   | ------ | ------------- |
| mode | [GestureFocusMode](./arkts-basic-components-web-e.md#gesturefocusmode20) | Yes    | Gesture focus mode of the **Web** component.<br>Default value: **GestureFocusMode.DEFAULT**, indicating that the **Web** component is focused when any gesture is performed on it.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: GestureFocusMode = GestureFocusMode.DEFAULT;
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .gestureFocusMode(this.mode)
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

## password<sup>(deprecated)</sup>

password(password: boolean)

Sets whether to save the password. This API is an empty API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

## textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

Sets the text zoom ratio of the page.

**System capability**: SystemCapability.Web.Webview.Core

This API is deprecated since API version 9. You are advised to use [textZoomRatio<sup>9+</sup>](#textzoomratio9) instead.

**Parameters**

| Name         | Type  | Mandatory | Description                            |
| ------------ | ------ | ---- | -------------------------------- |
| textZoomAtio | number | Yes  | Text zoom ratio to set.<br>The value is a positive integer.<br>Default value: **100**|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State ratio: number = 150
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomAtio(this.ratio)
      }
    }
  }
  ```

## userAgent<sup>(deprecated)</sup>

userAgent(userAgent: string)

Sets the user agent.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [setCustomUserAgent](./arkts-apis-webview-WebviewController.md#setcustomuseragent10)<sup>10+</sup> instead.

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
    @State userAgent:string = 'Mozilla/5.0 (Phone; OpenHarmony 5.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile DemoApp';

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .userAgent(this.userAgent)
      }
    }
  }
  ```

## tableData<sup>(deprecated)</sup>

tableData(tableData: boolean)

Sets whether to save form data. This API is an empty API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

## wideViewModeAccess<sup>(deprecated)</sup>

wideViewModeAccess(wideViewModeAccess: boolean)

Sets whether to support the **viewport** attribute of the HTML \<meta> tag. This API is an empty API.

> **NOTE**
>
> This API is deprecated since API version 10, and no new API is provided as a substitute.

**System capability**: SystemCapability.Web.Webview.Core

## selectionMenuOptions<sup>(deprecated)</sup>

selectionMenuOptions(expandedMenuOptions: Array\<ExpandedMenuItemOptions>)

Sets the extended options of the custom context menu on selection, including the text content, icon, and callback.

The API only supports the selection of plain text; if the selected content contains images or other non-text elements, the **action** information may display garbled content.

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 20. You are advised to use [editMenuOptions<sup>12+</sup>](#editmenuoptions12) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                                                        | Mandatory  | Description         |
| ------------------- | ----------------------------------------------------------    | ---- | ------------- |
| expandedMenuOptions | Array<[ExpandedMenuItemOptions](./arkts-basic-components-web-i.md#expandedmenuitemoptions12)> | Yes   | Extended options of the custom context menu on selection.<br>The number of menu options, menu content size, and start icon size must be the same as those of the ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md) component.|

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
