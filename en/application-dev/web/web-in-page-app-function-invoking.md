# Invoking Application Functions on the Frontend Page


You can use the **Web** component to register application code with frontend pages. After the registration is done, frontend pages can use the registered object names to call application functions.


Two methods are available for registering the application code:<br>Call [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy) during **Web** component initialization.<br> Call [registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy) after **Web** component initialization.


The following example registers the **test()** function with the frontend page. This way, the **test()** function can be triggered and run on the frontend page.


- Sample code for using [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy):

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  class testClass {
    constructor() {
    }

    test(): string {
      return 'ArkTS Hello World!';
    }
  }

  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
    // Declare the object to be registered.
    @State testObj: testClass = new testClass();

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
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }
  
    test(): string {
      return "ArkUI Web Component";
    }
  
    toString(): void {
      console.log('Web Component toString');
    }
  }

  @Entry
  @Component
  struct Index {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
    @State testObj: testClass = new testClass();

    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            try {
              this.webviewController.refresh();
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Button('Register JavaScript To Window')
          .onClick(() => {
            try {
              this.webviewController.registerJavaScriptProxy(this.testObj, "testObjName", ["test", "toString"]);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
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


- Sample code for invoking application functions on the **index.html** frontend page:

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
          let str = testObjName.test();
          document.getElementById("demo").innerHTML = str;
          console.info('ArkTS Hello World! :' + str);
      }
  </script>
  </body>
  </html>
  ```
