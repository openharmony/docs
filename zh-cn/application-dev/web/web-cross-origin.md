# 解决Web组件本地资源跨域问题
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## 拦截本地资源跨域

为了提高安全性，ArkWeb内核禁止file协议和resource协议访问跨域请求。因此，在使用Web组件加载本地离线资源的时候，Web组件会拦截file协议和resource协议的跨域访问。通过方法二设置一个路径列表，再使用file协议访问该路径列表中的资源，允许跨域访问本地文件。Web组件无法访问本地跨域资源时，DevTools控制台会显示报错信息：

```
Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes: http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
```

## 本地资源跨域问题解决方法

- 方法一

  开发者应使用http或https协议替代file或resource协议，使Web组件成功访问跨域资源。替代的URL域名为自定义构造，仅供个人或组织使用，避免与互联网上的实际域名冲突。同时，开发者需利用Web组件的[onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9)方法，对本地资源进行拦截和相应的替换。

  以下结合示例说明如何使用http或者https等协议解决本地资源跨域访问失败的问题。其中，index.html和js/script.js置于工程中的rawfile目录下。当使用resource协议访问index.html时，js/script.js将因跨域而被拦截，无法加载。在示例中，使用https:\//www\.example.com/域名替换了原本的resource协议，同时利用onInterceptRequest接口替换资源，使得js/script.js可以成功加载，从而解决了跨域拦截的问题。

  ```ts
  // main/ets/pages/Index.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
    @State message: string = 'Hello World';
    webviewController: webview.WebviewController = new webview.WebviewController();
    // 构造域名和本地文件的映射表
    schemeMap = new Map([
      ["https://www.example.com/index.html", "index.html"],
      ["https://www.example.com/js/script.js", "js/script.js"],
    ])
    // 构造本地文件和构造返回的格式mimeType
    mimeTypeMap = new Map([
      ["index.html", 'text/html'],
      ["js/script.js", "text/javascript"]
    ])

    build() {
      Row() {
        Column() {
          // 针对本地index.html,使用http或者https协议代替file协议或者resource协议，并且构造一个属于自己的域名。
          // 本例中构造www.example.com为例。
          Web({ src: "https://www.example.com/index.html", controller: this.webviewController })
            .javaScriptAccess(true)
            .fileAccess(true)
            .domStorageAccess(true)
            .geolocationAccess(true)
            .width("100%")
            .height("100%")
            .onInterceptRequest((event) => {
              if (!event) {
                return;
              }
              // 此处匹配自己想要加载的本地离线资源，进行资源拦截替换，绕过跨域
              if (this.schemeMap.has(event.request.getRequestUrl())) {
                let rawfileName: string = this.schemeMap.get(event.request.getRequestUrl())!;
                let mimeType = this.mimeTypeMap.get(rawfileName);
                if (typeof mimeType === 'string') {
                  let response = new WebResourceResponse();
                  // 构造响应数据，如果本地文件在rawfile下，可以通过如下方式设置
                  response.setResponseData($rawfile(rawfileName));
                  response.setResponseEncoding('utf-8');
                  response.setResponseMimeType(mimeType);
                  response.setResponseCode(200);
                  response.setReasonMessage('OK');
                  response.setResponseIsReady(true);
                  return response;
                }
              }
              return null;
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

  ```html
  <!-- main/resources/rawfile/index.html -->
  <html>
  <head>
  	<meta name="viewport" content="width=device-width,initial-scale=1">
  </head>
  <body>
  <script crossorigin src="./js/script.js"></script>
  </body>
  </html>
  ```

  ```js
  // main/resources/rawfile/js/script.js
  const body = document.body;
  const element = document.createElement('div');
  element.textContent = 'success';
  body.appendChild(element);
  ```

- 方法二

  通过[setPathAllowingUniversalAccess](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setpathallowinguniversalaccess12)设置一个路径列表。当使用file协议访问该列表中的资源时，允许进行跨域访问本地文件。此外，一旦设置了路径列表，file协议将仅限于访问列表内的资源(此时，[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)的行为将会被此接口行为覆盖)。路径列表中的路径应符合以下任一路径格式：

  1.应用文件目录通过[Context.filesDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

  * /data/storage/el2/base/files/example
  * /data/storage/el2/base/haps/entry/files/example

  2.应用资源目录通过[Context.resourceDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

  * /data/storage/el1/bundle/entry/resource/resfile
  * /data/storage/el1/bundle/entry/resource/resfile/example

  当路径列表中的任一路径不满足上述条件时，系统将抛出异常码401，并判定路径列表设置失败。如果路径列表设置为空，file协议的可访问范围将遵循[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)规则，具体示例如下。

  ```ts
  // main/ets/pages/index.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Row() {
        Web({ src: "", controller: this.controller })
          .onControllerAttached(() => {
            try {
              // 设置允许可以跨域访问的路径列表
              this.controller.setPathAllowingUniversalAccess([
                this.uiContext.getHostContext()!.resourceDir,
                this.uiContext.getHostContext()!.filesDir + "/example"
              ])
              this.controller.loadUrl("file://" + this.uiContext.getHostContext()!.resourceDir + "/index.html")
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
            }
          })
          .javaScriptAccess(true)
          .fileAccess(true)
          .domStorageAccess(true)
      }
    }
  }
  ```

  ```html
  <!-- main/resources/resfile/index.html -->
  <!DOCTYPE html>
  <html lang="en">

  <head>
      <meta charset="utf-8">
      <title>Demo</title>
      <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no,   viewport-fit=cover">
      <script>
  		function getFile() {
  			var file = "file:///data/storage/el1/bundle/entry/resources/resfile/js/script.js";
        // 使用file协议通过XMLHttpRequest跨域访问本地js文件。
  			var xmlHttpReq = new XMLHttpRequest();
  			xmlHttpReq.onreadystatechange = function(){
  			    console.log("readyState:" + xmlHttpReq.readyState);
  			    console.log("status:" + xmlHttpReq.status);
  				if(xmlHttpReq.readyState == 4){
  				    if (xmlHttpReq.status == 200) {
                  // 如果ets侧正确设置路径列表，则此处能正常获取资源
  				        const element = document.getElementById('text');
                          element.textContent = "load " + file + " success";
  				    } else {
                  // 如果ets侧不设置路径列表，则此处会触发CORS跨域检查错误
  				        const element = document.getElementById('text');
                          element.textContent = "load " + file + " failed";
  				    }
  				}
  			}
  			xmlHttpReq.open("GET", file);
  			xmlHttpReq.send(null);
  		}
      </script>
  </head>

  <body>
  <div class="page">
      <button id="example" onclick="getFile()">loadFile</button>
  </div>
  <div id="text"></div>
  </body>

  </html>
  ```

  ```javascript
  // main/resources/resfile/js/script.js
  const body = document.body;
  const element = document.createElement('div');
  element.textContent = 'success';
  body.appendChild(element);
  ```