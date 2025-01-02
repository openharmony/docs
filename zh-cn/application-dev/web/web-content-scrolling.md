# Web页面显示内容滚动

ArkWeb中的Webview.WebviewController提供scrollTo和scrollBy接口。

当Web显示的内容大小远远大于组件大小时，用户可以通过scrollTo和scrollBy对Web页面中显示的内容进行滚动来显示没有显示的部分，且可以生成动画滚动效果。目前动画效果不支持手势打断，可以通过再次执行一个时间约为0的动画进行强制打断。

> **说明：**
>
> - 支持滚动的条件： Web页面的长度或宽度大于显示区域的长度或宽度。

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