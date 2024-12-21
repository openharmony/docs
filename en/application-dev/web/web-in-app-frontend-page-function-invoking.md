# Invoking Frontend Page Functions on the Application

You can call [runJavaScript()](../reference/apis-arkweb/js-apis-webview.md#runjavascript) and [runJavaScriptExt()](../reference/apis-arkweb/js-apis-webview.md#runjavascriptext10) on an application to call JavaScript functions of frontend pages.

The parameter types of [runJavaScript()](../reference/apis-arkweb/js-apis-webview.md#runjavascript) and [runJavaScriptExt()](../reference/apis-arkweb/js-apis-webview.md#runjavascriptext10) are different. In [runJavaScriptExt()](../reference/apis-arkweb/js-apis-webview.md#runjavascriptext10), the input parameter type can be **string** or **ArrayBuffer** (JavaScript script data obtained from files), and the execution result can be obtained through **AsyncCallback**.

In the following example, when a user clicks the **runJavaScript** button on the application, the **htmlTest()** API of the frontend page will be triggered.

- Frontend page code:

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <h1 id="text">This is a piece of test information. The font color is black by default. It turns green after runJavaScript() is called and red after runJavaScriptCodePassed() is called.</h1>
  <script>
      // Implement this function when a parameter is required.
      var param = "param: JavaScript Hello World!";
      function htmlTest(param) {
          document.getElementById('text').style.color = 'green';
          console.log(param);
      }
      // Implement this function when no parameter is required.
      function htmlTest() {
          document.getElementById('text').style.color = 'green';
      }
      // The Click Me! button triggers callArkTS() on the frontend page to execute the code passed in by JavaScript.
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
        Button('runJavaScript')
          .onClick(() => {
            // If no parameter is required for the functions in the frontend page, delete param.
            this.webviewController.runJavaScript('htmlTest(param)');
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

The following samples are provided to help you better understand how to develop the **Web** component:

- [JS Injection and Execution (ArkTS) (Full SDK) (API9)](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/BasicFeature/Web/RunJsInWeb)
