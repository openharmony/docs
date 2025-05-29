# Resolving Cross-Origin Resource Access

## Background

For security purposes, the ArkWeb kernel does not allow for cross-origin requests using the file or resource protocol in the URL context. As such, the **Web** component blocks such requests when loading local offline resources. To allow cross-origin requests using the file, you can use method 2 to set a path list. When cross-origin requests from the **Web** component are blocked, an error message similar to the following is displayed on the DevTools console:

```
Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes: http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
```

## Solutions to Local Cross-Origin Resource Access

- Method 1

  For the **Web** component to load local resources across origins, use HTTP or HTTPS, instead of file or resource, as the protocol. The domain name of the URL to use should be one that you customize for individuals or organizations. Make sure it does not conflict with any existing domain name in the real world. You also need to use the [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9) API of the **Web** component to intercept and replace local resources.

  In the following example, the **index.html** and **js/script.js** files are stored in the **rawfile** folder of the project directory. If the resource protocol is used to access **index.html**, loading **js/script.js** will fail due to cross-origin blocking. To resolve this issue, the HTTPS protocol is used instead, as in **https:\//www\.example.com/**, and the [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9) API is used to replace resources. In this way, **js/script.js** can be successfully loaded.

  ```ts
  // main/ets/pages/Index.ets
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

- Method 2

  Use [setPathAllowingUniversalAccess](../reference/apis-arkweb/js-apis-webview.md#setpathallowinguniversalaccess12) to set a path list for cross-origin access to local files using the file protocol. Note that only the resources in the path list can be accessed by the file protocol when this method is used. In this case, the behavior of [fileAccess](../reference/apis-arkweb/ts-basic-components-web.md#fileaccess) is overwritten. The paths in the list must be any of the following directories:

  1. The application file directory and its subdirectories, which can be obtained through [Context.filesDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context), such as:

  * /data/storage/el2/base/files/example
  * /data/storage/el2/base/haps/entry/files/example

  2. The application resource directory and its subdirectories, which can be obtained through [Context.resourceDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context), such as:

  * /data/storage/el1/bundle/entry/resource/resfile
  * /data/storage/el1/bundle/entry/resource/resfile/example

  If a path is not any of the preceding paths, an error code 401 is reported and the path list fails to be set. When the path list is empty, the accessible files for the file protocol are subject to the behavior of [fileAccess](../reference/apis-arkweb/ts-basic-components-web.md#fileaccess). The following is an example:

  ```ts
  // main/ets/pages/Index.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: WebviewController = new webview.WebviewController();

    build() {
      Row() {
        Web({ src: "", controller: this.controller })
          .onControllerAttached(() => {
            try {
              // Set the list of paths that allow cross-domain access.
              this.controller.setPathAllowingUniversalAccess([
                getContext().resourceDir,
                getContext().filesDir + "/example"
              ])
              this.controller.loadUrl("file://" + getContext().resourceDir + "/index.html")
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as   BusinessError).message}`);
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
  <!-- main/resource/rawfile/index.html -->
  <!DOCTYPE html>
  <html lang="en">

  <head>
      <meta charset="utf-8">
      <title>Demo</title>
      <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no,   viewport-fit=cover">
      <script>
  		function getFile() {
  			var file = "file:///data/storage/el1/bundle/entry/resources/resfile/js/script.js";
        // Use the file protocol to access the local JS file through XMLHttpRequest.
  			var xmlHttpReq = new XMLHttpRequest();
  			xmlHttpReq.onreadystatechange = function(){
  			    console.log("readyState:" + xmlHttpReq.readyState);
  			    console.log("status:" + xmlHttpReq.status);
  				if(xmlHttpReq.readyState == 4){
  				    if (xmlHttpReq.status == 200) {
                  // If the path list is set on eTS, resources can be obtained.
  				        const element = document.getElementById('text');
                          element.textContent = "load " + file + " success";
  				    } else {
                  // If the path list is not set on eTS, a CORS error is triggered.
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
      <button id="example" onclick="getFile()">stealFile</button>
  </div>
  <div id="text"></div>
  </body>

  </html>
  ```

  ```javascript
  // main/resources/rawfile/js/script.js
  const body = document.body;
  const element = document.createElement('div');
  element.textContent = 'success';
  body.appendChild(element);
  ```
