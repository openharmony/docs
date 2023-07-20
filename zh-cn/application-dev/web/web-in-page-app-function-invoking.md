# 前端页面调用应用侧函数


开发者使用Web组件将应用侧代码注册到前端页面中，注册完成之后，前端页面中使用注册的对象名称就可以调用应用侧的函数，实现在前端页面中调用应用侧方法。


注册应用侧代码有两种方式，一种在Web组件初始化使用调用，使用[javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)接口。另外一种在Web组件初始化完成后调用，使用[registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy)接口。


在下面的示例中，将test()方法注册在前端页面中， 该函数可以在前端页面触发运行。


- [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)接口使用示例如下。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();
    // 声明需要注册的对象
    testObj = {
      test: () => {
        return 'ArkTS Hello World!';
      }
    }

    build() {
      Column() {
        // web组件加载本地index.html页面
        Web({ src: $rawfile('index.html'), controller: this.webviewController})
          // 将对象注入到web端
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


- 应用侧使用registerJavaScriptProxy()接口注册。

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

  > **说明：**
  >
  > 使用[registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy)接口注册方法时，注册后需调用[refresh()](../reference/apis/js-apis-webview.md#refresh)接口生效。


- index.htm前端页面触发应用侧代码。

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
