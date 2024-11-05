# 应用侧调用前端页面函数


应用侧可以通过[runJavaScript()](../reference/apis-arkweb/js-apis-webview.md#runjavascript)方法调用前端页面的JavaScript相关函数。


在下面的示例中，点击应用侧的“runJavaScript”按钮时，来触发前端页面的htmlTest()方法。

- 前端页面代码。
  
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <h1 id="text">这是一个测试信息，默认字体为黑色，调用runJavaScript方法后字体为绿色，调用runJavaScriptCodePassed方法后字体为红色</h1>
  <script>
      // 调用有参函数时实现。
      var param = "param: JavaScript Hello World!";
      function htmlTest(param) {
          document.getElementById('text').style.color = 'green';
          console.log(param);
      }
      // 调用无参函数时实现。
      function htmlTest() {
          document.getElementById('text').style.color = 'green';
      }
      // Click Me！触发前端页面callArkTS()函数执行JavaScript传递的代码。
      function callArkTS() {
          changeColor();
      }
  </script>
  </body>
  </html>
  ```


- 应用侧代码。
  
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    webviewController: webview.WebviewController = new webview.WebviewController();

    aboutToAppear() {
      // 配置Web开启调试模式
      webview.WebviewController.setWebDebuggingAccess(true);
    }

    build() {
      Column() {
        Button('runJavaScript')
          .onClick(() => {
            // 前端页面函数无参时，将param删除。
            this.webviewController.runJavaScript('htmlTest(param)');
          })
        Button('runJavaScriptCodePassed')
          .onClick(() => {
            // 传递runJavaScript侧代码方法。
            this.webviewController.runJavaScript(`function changeColor(){document.getElementById('text').style.color = 'red'}`);
          })
        Web({ src: $rawfile('index.html'), controller: this.webviewController })
      }
    }
  }
  ```

## 相关实例

针对Web组件开发，有以下相关实例可供参考：

- [JS注入与执行（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/BasicFeature/Web/RunJsInWeb)