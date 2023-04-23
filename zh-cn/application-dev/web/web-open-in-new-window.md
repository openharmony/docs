# 在新窗口中打开页面


Web组件提供了在新窗口打开页面的能力，开发者可以通过[multiWindowAccess()](../reference/arkui-ts/ts-basic-components-web.md#multiwindowaccess9)接口来设置是否允许网页在新窗口打开。当有新窗口打开时，应用侧会在[onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9)接口中收到Web组件新窗口事件，开发者需要在此接口事件中，新建窗口来处理Web组件窗口请求。


> **说明：**
>
> 如果开发者在[onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9)接口通知中不需要打开新窗口，需要将[ControllerHandler.setWebController()](../reference/arkui-ts/ts-basic-components-web.md##setwebcontroller9)接口返回值设置成null。


如下面的本地示例，当用户点击“新窗口中打开网页”按钮时，应用侧会在[onWindowNew()](../reference/arkui-ts/ts-basic-components-web.md#onwindownew9)接口中收到Web组件新窗口事件。


- 应用侧代码。

  创建新窗口的方法可参考[Web开发相关例子](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)。

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
          // 开发者需要在此处新建窗口,跟popController关联，并且将popController返回给Web组件。如果不需要打开新窗口请将返回值设置为event.handler.setWebController(null);
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
      <meta charset="utf-8">
      <title>WindowEvent</title>
  </head>

  <body>
  <input type="button" value="新窗口中打开网页" onclick="OpenNewWindow()">
  <script type="text/javascript">
      function OpenNewWindow()
      {
          let openedWindow = window.open("about:blank", "", "location=no,status=no,scrollvars=no");
          if (openedWindow) {
              openedWindow.document.body.write("<p>这是我的窗口</p>");
          } else {
              log.innerHTML = "window.open failed";
          }
      }
  </script>
  </body>
  </html>
  ```
