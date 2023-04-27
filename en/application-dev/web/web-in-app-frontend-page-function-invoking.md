# Invoking Frontend Page Functions on the Application


You can call [runJavaScript()](../reference/apis/js-apis-webview.md#runjavascript) on an application to call JavaScript functions of frontend pages.


In the following example, when a user clicks the **runJavaScript** button on the application, the **htmlTest()** API of the frontend page will be triggered.


- Frontend page code:
  
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


- Application code:
  
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
