# Opening Pages in a New Window


The **Web** component provides the capability of opening pages in a new window. You can call [multiWindowAccess()](../reference/arkui-ts/ts-basic-components-web.md#multiwindowaccess9) to specify whether to allow a web page to be opened in a new window. When a new window is opened in the **Web** component, the application will receive a window opening event through [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9). You need to add the code for processing the window opening request in the event callback.


> **NOTE**
>
> If you do not want to open a new window in [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9), set the return value of [ControllerHandler.setWebController()](../reference/arkui-ts/ts-basic-components-web.md#setwebcontroller9) to **null**.


In the following example, when a user clicks the **Open Page in New Window** button, the application receives a window opening event in the [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9) callback.


- Application code:

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  // There are two Web components on the same page. When a new window is opened in WebComponent, NewWebViewComp is displayed.
  @CustomDialog
  struct NewWebViewComp {
  controller?: CustomDialogController
  webviewController1: web_webview.WebviewController = new web_webview.WebviewController()
  build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(()=> {
            console.info("NewWebViewComp onWindowExit")
            if (this.controller) {
              this.controller.close()
            }
          })
        }
    }
  }

  @Entry
  @Component
  struct WebComponent {
      controller: web_webview.WebviewController = new web_webview.WebviewController()
      dialogController: CustomDialogController | null = null
      build() {
        Column() {
          Web({ src:$rawfile("window.html"), controller: this.controller })
            .javaScriptAccess(true)
           // Enable MultiWindowAccess.
            .multiWindowAccess(true)
            .allowWindowOpenMethod(true)
            .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController:web_webview.WebviewController = new web_webview.WebviewController()
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({webviewController1: popController})
            })
            this.dialogController.open()
            // Return the WebviewController corresponding to the new window to the web kernel.
            // If you do not need to open a new window, call event.handler.setWebController and set the value to null.
            // If event.handler.setWebController is not called, the render process will be blocked.
            event.handler.setWebController(popController)
          })
      }
    }
  }
  ```


- Code of the **window.html** page:

  ```html
   <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>WindowEvent</title>
  </head>
  <body>
  <input type="button" value="Open Page in New Window" onclick="OpenNewWindow()">
  <script type="text/javascript">
      function OpenNewWindow()
      {
          let openedWindow = window.open("about:blank", "", "location=no,status=no,scrollvars=no");

          openedWindow.document.write (" <p>This is my window </p>");
          openedWindow.focus();

      }
  </script>
  </body>
  </html>
  ```
