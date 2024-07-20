# 解决Web组件本地资源跨域问题

## 拦截本地资源跨域
为了提高安全性，ArkWeb内核不允许file协议或者resource协议访问URL上下文中来自跨域的请求。因此，在使用Web组件加载本地离线资源的时候，Web组件会拦截file协议和resource协议的跨域访问。当Web组件无法访问本地跨域资源时，开发者可以在devtools控制台中看到类似以下报错信息：

```
Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes: http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
```

## 本地资源跨域问题解决方法
如果Web组件要成功访问这些跨域资源，开发者需要使用http或者https等协议替代原本使用的file协议或者resource协议进行加载。其中替代的url的域名为自己构造的仅供个人或者组织使用的域名，尽量不要和网络上真实存在的域名冲突。同时需要开发者使用Web组件的[onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9)对本地资源进行拦截替换。

以下结合示例说明如何解决本地资源跨域访问失败的问题。其中index.html和js/script.js置于工程中rawfile目录下。如果使用resource协议访问index.html，js/script.js将被跨域拦截无法加载。示例中使用https:\//www\.example.com/域名替换原本的resource协议，同时使用[onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9)接口替换资源，使得js/script.js可以成功加载，解决了跨域拦截的问题。


```ts
// main/ets/pages/index.ets
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