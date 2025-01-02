# Resolving Cross-Origin Resource Access

## Background
For security purposes, the ArkWeb kernel does not allow for cross-origin requests using the file or resource protocol in the URL context. As such, the **Web** component blocks such requests when loading local offline resources, and an error message similar to the following is displayed on the DevTools console:

```
Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes: http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
```

## Solutions to Local Cross-Origin Resource Access
For the **Web** component to load local resources across origins, use HTTP or HTTPS, instead of file or resource, as the protocol. The domain name of the URL to use should be one that you customize for individuals or organizations. Make sure it does not conflict with any existing domain name in the real world. You also need to use the [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9) API of the **Web** component to intercept and replace local resources.

In the following example, the **index.html** and **js/script.js** files are stored in the **rawfile** folder of the project directory. If the resource protocol is used to access **index.html**, loading **js/script.js** will fail due to cross-origin blocking. To resolve this issue, the HTTPS protocol is used instead, as in **https:\//www\.example.com/**, and the [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9) API is used to replace resources. In this way, **js/script.js** can be successfully loaded.


```ts
// main/ets/pages/index.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  webviewController: webview.WebviewController = new webview.WebviewController();
  // Construct a mapping table between domain names and local files.
  schemeMap = new Map([
    ["https://www.example.com/index.html", "index.html"],
    ["https://www.example.com/js/script.js", "js/script.js"],
  ])
  // Construct the local file and construct the return value format mimeType.
  mimeTypeMap = new Map([
    ["index.html", 'text/html'],
    ["js/script.js", "text/javascript"]
  ])

  build() {
    Row() {
      Column() {
        // For the local index.html file, use HTTP or HTTPS in place of file or resource as the protocol and construct a custom domain name.
        // In this example, www.example.com is constructed.
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
            // Search for the local offline resource to be loaded, and then intercept and replace the resource.
            if (this.schemeMap.has(event.request.getRequestUrl())) {
              let rawfileName: string = this.schemeMap.get(event.request.getRequestUrl())!;
              let mimeType = this.mimeTypeMap.get(rawfileName);
              if (typeof mimeType === 'string') {
                let response = new WebResourceResponse();
                // Construct the response data. If the local file is in rawfile, you can set the response data as follows:
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
