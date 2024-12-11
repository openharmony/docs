# 在新窗口中打开页面


Web组件提供了在新窗口打开页面的能力，开发者可以通过[multiWindowAccess()](../reference/apis-arkweb/ts-basic-components-web.md#multiwindowaccess9)接口来设置是否允许网页在新窗口打开。当有新窗口打开时，应用侧会在[onWindowNew()](../reference/apis-arkweb/ts-basic-components-web.md#onwindownew9)接口中收到Web组件新窗口事件，开发者需要在此接口事件中，新建窗口来处理Web组件窗口请求。


> **说明：**
>
> - [allowWindowOpenMethod()](../reference/apis-arkweb/ts-basic-components-web.md#allowwindowopenmethod10)接口设置为true时，前端页面通过JavaScript函数调用的方式打开新窗口。
>
> - 如果开发者在[onWindowNew()](../reference/apis-arkweb/ts-basic-components-web.md#onwindownew9)接口通知中如果没有创建新窗口，需要将[ControllerHandler.setWebController()](../reference/apis-arkweb/ts-basic-components-web.md#setwebcontroller9)接口参数设置成null。


如下面的本地示例，当用户点击“新窗口中打开网页”按钮时，应用侧会在[onWindowNew()](../reference/apis-arkweb/ts-basic-components-web.md#onwindownew9)接口中收到Web组件新窗口事件。


- 应用侧代码。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // 在同一page页有两个Web组件。在WebComponent新开窗口时，会跳转到NewWebViewComp。
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
        Web({ src: $rawfile("window.html"), controller: this.controller })
          .javaScriptAccess(true)
            // 需要使能multiWindowAccess
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController })
            })
            this.dialogController.open();
            // 将新窗口对应WebviewController返回给Web内核。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            // 如果没有创建新窗口，调用event.handler.setWebController接口时设置成null，通知Web没有创建新窗口。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```


- window.html页面代码。

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" content="width=device-width"/>
      <title>WindowEvent</title>
  </head>
  <body>
  <input type="button" value="新窗口中打开网页" onclick="OpenNewWindow()">
  <script type="text/javascript">
      function OpenNewWindow()
      {
          var txt = '打开的窗口';
          let openedWindow = window.open("about:blank", "", "location=no,status=no,scrollvars=no");
          openedWindow.document.write("<p>" + "<br><br>" + txt.fontsize(10) + "</p>");
          openedWindow.focus();
      }
  </script>
  </body>
  </html>
  ```

**图1** 新窗口中打开页面效果图  

![web-open-in-new-window](figures/web-open-in-new-window.png)

  
## 相关实例

针对创建新窗口，有以下相关实例可供参考：

- [浏览器（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)