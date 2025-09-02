# Invoking Frontend Page Functions on the Application

You can call [runJavaScript()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascript) and [runJavaScriptExt()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascriptext10) from the application side to invoke JavaScript functions of frontend pages.

The parameter types of [runJavaScript()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascript) and [runJavaScriptExt()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascriptext10) are different. [runJavaScriptExt()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascriptext10) supports parameters of the string and array buffer types, while [runJavaScript()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#runjavascript) supports only parameters of the string type.

In the following example, when a user clicks the **runJavaScript** button on the application, the **htmlTest()** API of the frontend page will be triggered.

- Frontend page code:

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <h1 id="text">This is test information. The default font color is black. After the runJavaScript method is called, the font color is yellow. After the runJavaScriptParam method is called, the font color is green. After the runJavaScriptCodePassed method is called, the font color is red.</h1>
  <script>
      // Function with parameters.
      var param = "param: JavaScript Hello World!";
      function htmlTestParam(param) {
          document.getElementById('text').style.color = 'green';
          console.log(param);
      }
      // Function without parameters.
      function htmlTest() {
          document.getElementById('text').style.color = 'yellow';
      }
      // Click the Click Me! button to trigger callArkTS() on the frontend page to execute the code passed in by JavaScript.
      function callArkTS() {
          changeColor();
      }
  </script>
  </body>
  </html>
  ```


- Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    webviewController: webview.WebviewController = new webview.WebviewController();

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
    }

    build() {
      Column() {
        Button('runJavaScriptParam')
          .onClick(() => {
            // Call the function with parameters of the frontend page.
            this.webviewController.runJavaScript('htmlTestParam(param)');
          })
        Button('runJavaScript')
          .onClick(() => {
            // Call the function without parameters of the frontend page.
            this.webviewController.runJavaScript('htmlTest()');
          })
        Button('runJavaScriptCodePassed')
          .onClick(() => {
            // Pass in code for runJavaScript.
            this.webviewController.runJavaScript(`function changeColor(){document.getElementById('text').style.color = 'red'}`);
          })
        Web({ src: $rawfile('index.html'), controller: this.webviewController })
      }
    }
  }
  ```

## Samples

The following samples are provided to help you better understand how to develop **Web** component:

- [JS Injection and Execution (ArkTS) (Full SDK) (API9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/RunJsInWeb)
