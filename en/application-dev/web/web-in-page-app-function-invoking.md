# Invoking Application Functions on the Frontend Page


You can use the **Web** component to register application code with frontend pages. After the registration is done, frontend pages can use the registered object names to call application functions.


Two methods are available for registering the application code:<br>Call [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy) during **Web** component initialization.<br> Call [registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy) after **Web** component initialization.


The following example registers the **test()** function with the frontend page. This way, the **test()** function can be triggered and run on the frontend page.


- Sample code for using [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy):

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
    // Declare the object to be registered.
    testObj = {
      test: () => {
        return 'ArkTS Hello World!';
      }
    }

    build() {
      Column() {
        // Load the local index.html page.
        Web({ src: $rawfile('index.html'), controller: this.webviewController})
          // Inject the object to the web client.
          .javaScriptProxy({
            object: this.testObj,
            name: "testObjName",
            methodList: ["test"],
            controller: this.webviewController
          })
      }
    }
  }
  ```


- Sample code for using [registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy):

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct Index {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
    testObj = {
      test: (data) => {
        return "ArkUI Web Component";
      },
      toString: () => {
        console.info('Web Component toString');
      }
    }

    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            try {
              this.webviewController.refresh();
            } catch (error) {
              console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
            }
          })
        Button('Register JavaScript To Window')
          .onClick(() => {
            try {
              this.webviewController.registerJavaScriptProxy(this.testObj, "objName", ["test", "toString"]);
            } catch (error) {
              console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.webviewController })
      }
    }
  }
  ```

  > **NOTE**
  >
  > If you use [registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy) to register a function, call [refresh()](../reference/apis/js-apis-webview.md#refresh) for the function to take effect.


- Sample code for invoking application functions on the **index.htm** page:

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
          let str = objName.test();
          document.getElementById("demo").innerHTML = str;
          console.info('ArkTS Hello World! :' + str);
      }
  </script>
  </body>
  </html>
  ```
