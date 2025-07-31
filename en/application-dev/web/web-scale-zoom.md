# Zooming Web Pages

ArkWeb supports gesture zoom, mouse wheel zoom, and keyboard zoom, allowing users to adjust the display to a comfortable size. It also provides the capability of listening for and controlling the page zoom ratio for applications to achieve personalized visual effects.

## Setting Web Page Zoom

### Setting Gesture Zoom

You can use the [zoomAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#zoomaccess) attribute to set the web page zoom functionality. When this attribute is set to **false**, the web page cannot be zoomed in or out using gestures.

When **<meta name="viewport" id="viewport" content="user-scalable=no">** is set for the HTML web page, the web page cannot be zoomed in or out using gestures.

Gestures can be used to zoom in or out only when both the **zoomAccess** and **viewport** tags are set to allow zooming.

> **NOTE**
>
> On a PC or 2-in-1 device, the **viewport** tag does not take effect. You can only set **zoomAccess** to **false** to disable gesture zoom.
> 
> The preceding tags can only be used to enable or disable the zoom functionality. If **minimum-scale** and **maximum-scale** are set in the **viewport** tag, the zoom range is also restricted by the two attributes. When the maximum and minimum values are the same, the web page cannot be zoomed in or out. Currently, ArkWeb does not provide the capability of forcibly zooming in or out a page.

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
        .zoomAccess(false)
    }
  }
}
```

Loaded HTML:
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="user-scalable=yes">
    <title>Document</title>
</head>
<body>
    <p>this is a test page</p>
</body>
</html>
```

### Setting Keyboard and Mouse Wheel Zoom

By default, ArkWeb supports zooming by pressing the **Ctrl**+**'-'/'+'** keys or using the mouse wheel with the **Ctrl** key. An application can intercept keyboard events to disable keyboard zoom. Currently, the application cannot disable mouse wheel zoom.

Example of intercepting keyboard events to disable keyboard zoom:

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { KeyCode } from '@kit.InputKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .zoomAccess(true)
        .onKeyPreIme((event) => {
          if (event.type == KeyType.Down &&
              event.getModifierKeyState &&
              event.getModifierKeyState(['Ctrl']) &&
              (event.keyCode == KeyCode.KEYCODE_MINUS || event.keyCode == KeyCode.KEYCODE_EQUALS) ||
               event.keyCode == KeyCode.KEYCODE_NUMPAD_SUBTRACT || event.keyCode == KeyCode.KEYCODE_NUMPAD_ADD) {
            return true;
          }
          return false;
        })
    }
  }
}
```

## Listening for Page Zoom Ratio Changes

An application can listen for page zoom ratio changes through the [onScaleChange](../reference/apis-arkweb/arkts-basic-components-web-events.md#onscalechange9) API.
This API event corresponds to the gesture event (zoom with two fingers). **event.newScale** corresponds to the web page attribute **visualViewport.scale**.

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

## Controlling the Page Zoom Ratio

You can call the [zoom](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoom), [zoomIn](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomin) and [zoomOut](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomout) APIs to control the page zoom ratio.

 > **NOTE**
 >
 > When the **zoom** class APIs are used to control page zooming, you must set **zoomAccess** to **true**. Otherwise, the **zoom** class APIs throw exception 17100004.

### Zooming at Fixed Ratios

You can use **zoomIn** to zoom in the current web page by 25% or **zoomOut** to zoom out the current web page by 20%.

```ts
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
      Button('zoomOut')
        .onClick(() => {
          try {
            this.controller.zoomOut();
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

### Controlling Zoom Ratios Based on Input Values

You can use **zoom** to zoom in or out on the current web page. When the input parameter is set to **1**, the default page size is used. When the input parameter is set to a value less than 1, the page is zoomed out. When the input parameter is set to a value greater than 1, the page is zoomed in. The value must be greater than 0.

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
      TextInput()
        .type(InputType.NUMBER_DECIMAL)
        .onChange((value)=>{
            this.factor = Number(value);
        })
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
![zoom-by-step](./figures/zoom-by-step.gif)

### Zooming to Target Ratios

You can call the **onScaleChange** API to obtain the current page zoom ratio, and then call the **zoom** API to zoom in or out the page to the specified ratio. You can calculate the input parameter of **zoom** based on **pageFactor** and **targetFactor** as follows:

```
factor = 100 * targetFactor / pageFactor
```

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State targetFactor: number = 1;
  @State pageFactor: number = 100;

  build() {
    Column() {
      TextInput()
        .type(InputType.NUMBER_DECIMAL)
        .onChange((value)=>{
          this.targetFactor = Number(value);
        })
      Button('zoom')
        .onClick(() => {
          try {
            let factor = this.targetFactor * 100 / this.pageFactor;
            this.controller.zoom(factor);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .zoomAccess(true)
        .onScaleChange((event) => {
          console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale);
          this.pageFactor = event.newScale;
        })
    }
  }
}
```
![zoom-to-target](./figures/zoom-to-target.gif)
