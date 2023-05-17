# 应用侧调用前端页面函数


应用侧可以通过[runJavaScript()](../reference/apis/js-apis-webview.md#runjavascript)方法调用前端页面的JavaScript相关函数。


在下面的示例中，点击应用侧的“runJavaScript”按钮时，来触发前端页面的htmlTest()方法。


- 前端页面代码。
  
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <script>
      function htmlTest() {
          console.info('JavaScript Hello World! ');
      }
  </script>
  </body>
  </html>
  ```


- 应用侧代码。
  
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  
  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.webviewController})
        Button('runJavaScript')
          .onClick(() => {
             this.webviewController.runJavaScript('htmlTest()');
          })
      }
    }
  }
  ```
