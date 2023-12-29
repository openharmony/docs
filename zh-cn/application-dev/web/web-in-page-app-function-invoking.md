# 前端页面调用应用侧函数


开发者使用Web组件将应用侧代码注册到前端页面中，注册完成之后，前端页面中使用注册的对象名称就可以调用应用侧的函数，实现在前端页面中调用应用侧方法。


注册应用侧代码有两种方式，一种在Web组件初始化调用，使用[javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)接口。另外一种在Web组件初始化完成后调用，使用[registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy)接口。


在下面的示例中，将test()方法注册在前端页面中， 该函数可以在前端页面触发运行。


- [javaScriptProxy()](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)接口使用示例如下。

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
    // 声明需要注册的对象
    @State testObj: testClass = new testClass();

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

  > **说明：**
  >
  > 使用[registerJavaScriptProxy()](../reference/apis/js-apis-webview.md#registerjavascriptproxy)接口注册方法时，注册后需调用[refresh()](../reference/apis/js-apis-webview.md#refresh)接口生效。


- index.html前端页面触发应用侧代码。

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
## 复杂类型使用方法
- 应用侧和前端页面之间传递Array。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(): Array<Number>{
      return [1, 2, 3, 4]
    }

    toString(param:String): void {
      console.log('Web Component toString' + param);
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
          testObjName.toString(testObjName.test());
      }
  </script>
  </body>
  </html>
  ```
- 应用侧和前端页面之间传递不带Function的Dictionary。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class student {
    name: string = ''
    age: string = ''
  }

  class testClass {
    constructor() {
    }

    test(): student {
      let st: student = {name:"jeck", age:"12"}
      return st
    }

    toString(param: ESObject): void {
      console.log('Web Component toString' + param["name"]);
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
          testObjName.toString(testObjName.test());
      }
  </script>
  </body>
  </html>
  ```

- 应用侧调用前端页面的Callback。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(param: Function): void {
      param("call callback");
    }

    toString(param:String): void {
      console.log('Web Component toString' + param);
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
          testObjName.test(function(param){testObjName.toString(param)});
      }
  </script>
  </body>
  </html>
  ```

- 应用侧调用前端页面Object里的Function。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(param: ESObject): void {
      param.hello("call obj func");
    }

    toString(param:String): void {
      console.log('Web Component toString' + param);
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      // 写法1
      class Student {
          constructor(nameList) {
              this.methodNameListForJsProxy = nameList;
          }

          hello(param) {
              testObjName.toString(param)
          }
      }
      var st = new Student(["hello"])

      // 写法2
      //创建一个构造器，构造函数首字母大写
      function Obj1(){
          this.methodNameListForJsProxy=["hello"];
          this.hello=function(param){
              testObjName.toString(param)
          };
      }
      //利用构造器，通过new关键字生成对象
      var st1 = new Obj1();

      function callArkTS() {
          testObjName.test(st);
          testObjName.test(st1);
      }
  </script>
  </body>
  </html>
  ```

- 前端页面调用应用侧Object里的Function。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class ObjOther {
      methodNameListForJsProxy: string[]

      constructor(list: string[]) {
          this.methodNameListForJsProxy = list
      }

      testOther(json:string): void {
          console.info(json)
      }
  }

  class testClass {
    ObjReturn:ObjOther
    constructor() {
      this.ObjReturn =  new ObjOther(["testOther"]);
    }

    test(): ESObject {
      return this.ObjReturn
    }

    toString(param: string): void {
      console.log('Web Component toString' + param);
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
        testObjName.test().testOther("call other object func");
      }
  </script>
  </body>
  </html>
  ```

- Promise场景。<br>
  第一种使用方法，在应用侧new Promise。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(): Promise<string> {
        let p: Promise<string> = new Promise((resolve, reject) => {  setTimeout(() => {console.log('执行完成'); reject('fail');}, 10000);});
        return p;
    }

    toString(param:String): void {
        console.log(" " + param)
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
        testObjName.test().then((param)=>{testObjName.toString(param)}).catch((param)=>{testObjName.toString(param)})
      }
  </script>
  </body>
  </html>
  ```
  第二种使用方法，在前端页面new Promise。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(param:Function): void {
        setTimeout( () => { param("suc") }, 10000)
    }

    toString(param:String): void {
        console.log(" " + param)
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

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <button type="button" onclick="callArkTS()">Click Me!</button>
  <p id="demo"></p>
  <script>
      function callArkTS() {
        let funpromise
        var p = new Promise(function(resolve, reject){funpromise=(param)=>{resolve(param)}})
        testObjName.test(funpromise)
        p.then((param)=>{testObjName.toString(param)})
      }
  </script>
  </body>
  </html>
  ```
