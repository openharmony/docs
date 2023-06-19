# Opening Pages in a New Window


The **Web** component provides the capability of opening pages in a new window. You can call [multiWindowAccess()](../reference/arkui-ts/ts-basic-components-web.md#multiwindowaccess9) to specify whether to allow a web page to be opened in a new window. When a new window is opened in the **Web** component, the application will receive a window opening event through [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9). You need to add the code for processing the window opening request in the event callback.


> **NOTE**
>
> If you do not want to open a new window in [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9), set the return value of [ControllerHandler.setWebController()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9) to **null**.


In the following example, when a user clicks the **Open Page in New Window** button, the application receives a window opening event in the [onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9) callback.


- Application code:

  For details about how to create a window, see [Web Development Examples] (https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser).

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();
    build() {
      Column() {
        Web({ src:$rawfile("window.html"), controller: this.controller })
        .multiWindowAccess(true)
        .onWindowNew((event) => {
          console.info("onWindowNew...");
          var popController: web_webview.WebviewController = new web_webview.WebviewController();
          // Create a window, associate it with popController, and have popController returned to the Web component. If you do not need to open a new window, set the return value to event.handler.setWebController(null).
          event.handler.setWebController(popController);
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
          if (openedWindow) {
              openedWindow.document.body.write("<p>This is my window</p>");
          } else {
              log.innerHTML = "window.open failed";
          }
      }
  </script>
  </body>
  </html>
  ```
