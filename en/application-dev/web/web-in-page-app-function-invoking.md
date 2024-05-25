# Invoking Application Functions on the Frontend Page


You can use the **\<Web>** component to register application code with frontend pages. After the registration is done, frontend pages can use the registered object names to call application functions.

Two methods are available for registering the application code:

- Call [javaScriptProxy()](../reference/apis-arkweb/ts-basic-components-web.md#javascriptproxy) during **\<Web>** component initialization.

- Call [registerJavaScriptProxy()](../reference/apis-arkweb/js-apis-webview.md#registerjavascriptproxy) after **\<Web>** component initialization.


The following example registers the **test()** function with the frontend page. This way, the **test()** function can be triggered and run on the frontend page.


- Sample code for using [javaScriptProxy()](../reference/apis-arkweb/ts-basic-components-web.md#javascriptproxy):

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


- Sample code for using [registerJavaScriptProxy()](../reference/apis-arkweb/js-apis-webview.md#registerjavascriptproxy):

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
  > If you use [registerJavaScriptProxy()](../reference/apis-arkweb/js-apis-webview.md#registerjavascriptproxy) to register a function, call [refresh()](../reference/apis-arkweb/js-apis-webview.md#refresh) for the function to take effect.


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
## Usage of Complex Types
- Sample code for passing arrays between the application side and the frontend page:
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
- Sample code for passing a Dictionary type object without functions between the application side and the frontend page:
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

- Sample code for invoking a callback of the frontend page from the application side:
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

- Sample code for calling the function in an object of the frontend page from the application side:
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
      // Method 1
      class Student {
          constructor(nameList) {
              this.methodNameListForJsProxy = nameList;
          }

          hello(param) {
              testObjName.toString(param)
          }
      }
      var st = new Student(["hello"])

      // Method 2
      // Create a constructor, with the first letter of the constructor capitalized.
      function Obj1(){
          this.methodNameListForJsProxy=["hello"];
          this.hello=function(param){
              testObjName.toString(param)
          };
      }
      // Use the constructor to create an object using the new keyword.
      var st1 = new Obj1();

      function callArkTS() {
          testObjName.test(st);
          testObjName.test(st1);
      }
  </script>
  </body>
  </html>
  ```

- Sample code for calling the function in an object of the application side from the frontend page:
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

- Examples of using a promise:<br>
  With the first method, a promise is created on the application side.
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  class testClass {
    constructor() {
    }

    test(): Promise<string> {
        let p: Promise<string> = new Promise((resolve, reject) => {  setTimeout(() => {console.log('Execution completed'); reject('fail');}, 10000);});
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
  With the first method, a promise is created on the frontend page.
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
