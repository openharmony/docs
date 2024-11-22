# Implementing Content Scrolling

**Webview.WebviewController** in ArkWeb provides the **scrollTo** and **scrollBy** APIs.

When the size of the content displayed on the web page is much greater than the component size, you can use **scrollTo** and **scrollBy** to scroll the content that is not displayed on the web page. In addition, you can generate a scrolling animation. Currently, the animation effect cannot be interrupted by gestures. You can forcibly interrupt the animation by executing an animation whose duration is about 0.

> **NOTE**
>
> - The content can be scrolled when the length or width of the web page is greater than that of the display area.

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
        .margin(10)
      Button('scrollBy')
        .onClick(() => {
          try {
            this.controller.scrollBy(50, 50, 500);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .margin(10)        
      Button('scrollStop')
        .onClick(() => {
          try {
            this.controller.scrollBy(0, 0, 1);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .margin(10)        
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

```html
<!-- main/resources/rawfile/index.html -->
<html>
<head>
    <title>Demo</title>
    <style>
        body {
            width:2000px;
            height:2000px;
            padding-right:170px;
            padding-left:170px;
            border:25px solid blueviolet
            back
        }
        .scroll-text {
        font-size: 75px; 
        }
    </style>
</head>
<body>
<div class="scroll-text">Scroll Text</div> 
</body>
</html>
```
![web-content-scrolling](figures/web-content-scrolling.gif)
