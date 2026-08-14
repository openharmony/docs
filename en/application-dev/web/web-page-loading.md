# Locating Web Page Loading Issues

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=7837ae684682097baf9f7ec77030bf59ebda9fcb translatedAt=2026-08-14T03:49:13.205Z pushedAt=2026-08-14T09:26:33.206Z -->

Web page loading failures can be caused by various factors. This topic lists troubleshooting methods for common issues to help you quickly locate the cause.

## Checking Permissions and Network Status

If the app does not have network or file access permissions enabled, or if the device network status is poor, the Web component will fail to load.

* Check the device network status: check whether the device is connected to the network, and verify whether the built-in browser can access web pages normally (applicable to online page scenarios).

* Add the network permission: ensure that the app has declared the ohos.permission.INTERNET permission (required for online pages).

    <!-- @[INTERNET](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/module.json5) -->

    ``` JSON5
    "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ],
    ```

* Enable the relevant permissions:

    | Value   | Description  |
    | ----   | -------------------------------- |
    | [domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) | Sets whether to enable the Document Object Model Storage API (DOM Storage API) permission. If disabled, localStorage cannot be used to store data, any code that calls localStorage becomes invalid, and features that depend on local storage will behave abnormally. |
    | [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) | Sets whether to enable access to the file system in the app. If disabled, file read/write is completely blocked, and modules that depend on files will crash. |
    | [imageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#imageaccess) | Sets whether to allow automatic loading of image resources. |
    | [onlineImageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onlineimageaccess) | Sets whether to allow loading image resources from the network (resources accessed over HTTP and HTTPS). |
    | [javaScriptAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#javascriptaccess) | Sets whether to allow execution of JavaScript scripts. |

    <!-- @[OpenPermissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/ets/pages/OpenPermissions.ets) -->

    ``` TypeScript
    import { webview } from '@kit.ArkWeb';
    
    @Entry
    @Component
    struct WebComponent {
      controller: webview.WebviewController = new webview.WebviewController();
    
      build() {
        Column() {
          Web({ src: 'www.example.com', controller: this.controller })
            .domStorageAccess(true)
            .fileAccess(true)
            .imageAccess(true)
            .onlineImageAccess(true)
            .javaScriptAccess(true)
        }
      }
    }
    ```

## Verifying Page Content with DevTools

Cross-origin errors and Service Worker request failures generally report ERR_FAILED. If ERR_FAILED occurs, use [DevTools to debug frontend pages](web-debugging-with-devtools.md) to identify the specific error type (cross-origin, resource 404, or JS exception).

1. Check the console to confirm whether there are exceptions caused by the Mixed Content policy or the CORS policy, or JS errors. For details, see [Resolving Cross-Origin Resource Access](web-cross-origin.md). To improve security, the ArkWeb kernel prohibits cross-origin requests through the file protocol and the resource protocol. Therefore, when the Web component loads local offline resources, it intercepts cross-origin access through the file protocol and the resource protocol. When the Web component cannot access local cross-origin resources, the DevTools console displays an error message:

    ```txt
    Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes:   http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
    ```

   If you confirm that the page resources are trusted, you can bypass the cross-origin check in either of the following two ways:

   **Method 1:**

      You should use HTTP or HTTPS instead of the file or resource protocol to ensure that the Web component can successfully access cross-origin resources. The replacement URL domain name should be custom-built and used only by an individual or organization to prevent conflicts with actual domain names on the Internet. In addition, you need to use the [onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9) method of the Web component to intercept and replace local resources accordingly.

      The following example shows how to use protocols such as HTTP or HTTPS to resolve the failure to access local resources across origins. In this example, the index.html and js/script.js files are placed in the rawfile directory of the project. When index.html is accessed through the resource protocol, the js/script.js file is blocked due to cross-origin restrictions and cannot be loaded. In the example, the original resource protocol is replaced with the https:\//www\.example.com/ domain name, and the onInterceptRequest API is used to replace resources, ensuring that the js/script.js file can be loaded successfully and thereby resolving the cross-origin blocking issue.

    ```ts
    // main/ets/pages/Index.ets
    import { webview } from '@kit.ArkWeb';

    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
      webviewController: webview.WebviewController = new webview.WebviewController();
      // Construct the mapping between domain names and local files.
      schemeMap = new Map([
        ["https://www.example.com/index.html", "index.html"],
        ["https://www.example.com/js/script.js", "js/script.js"],
      ])
      // Construct the mapping between local files and the returned mimeType format.
      mimeTypeMap = new Map([
        ["index.html", 'text/html'],
        ["js/script.js", "text/javascript"]
      ])

      build() {
        Row() {
          Column() {
            // For the local index.html, use HTTP or HTTPS instead of the file or resource protocol, and construct a custom domain name.
            // In this example, www.example.com is used as an example.
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
                // Match the local offline resources to load here, intercept and replace them to bypass cross-origin restrictions.
                if (this.schemeMap.has(event.request.getRequestUrl())) {
                  let rawfileName: string = this.schemeMap.get(event.request.getRequestUrl())!;
                  let mimeType = this.mimeTypeMap.get(rawfileName);
                  if (typeof mimeType === 'string') {
                    let response = new WebResourceResponse();
                    // Construct the response data. If the local file is under rawfile, set it as follows.
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
    <!DOCTYPE html>
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

    **Method 2 (resolving local resource cross-origin issues):**

    Use [setPathAllowingUniversalAccess](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setpathallowinguniversalaccess12) to set a path list. When resources in the list are accessed using the file protocol, cross-origin access to local files is allowed. In addition, once the path list is set, the file protocol is limited to accessing only the resources in the list (in this case, the behavior of [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) is overridden by the behavior of this API).

    Using setPathAllowingUniversalAccess to lift cross-origin access restrictions on directories is a high-risk operation. Based on the principle of least privilege, the paths opened for el1 and el2 are fixed, and each path in the path list must conform to one of the following path formats:

    1. The app file directory is obtained through [Context.filesDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#attribute). Examples of its subdirectories are as follows:

       * /data/storage/el2/base/files/example

       * /data/storage/el2/base/haps/entry/files/example

    2. The app resource directory is obtained through [Context.resourceDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#attribute). Examples of its subdirectories are as follows:

       * /data/storage/el1/bundle/entry/resources/resfile

       * /data/storage/el1/bundle/entry/resources/resfile/example

    3. Starting from API version 21, the app cache directory is also included, which is obtained through [Context.cacheDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#attribute). Its subdirectories are as follows:

       * /data/storage/el2/base/cache

       * /data/storage/el2/base/haps/entry/cache/example

       * The configured directory path must not contain cache/web; otherwise, exception code 401 is thrown. If the configured directory path is cache, cache/web is also inaccessible.

    4. Starting from API version 21, the app temporary directory obtained through [Context.tempDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#properties) is also included. Examples of its subdirectories are as follows:

       * /data/storage/el2/base/temp

       * /data/storage/el2/base/haps/entry/temp/example

    When any path in the path list does not meet the preceding conditions, the system throws exception code 401 and determines that the path list configuration has failed. If the path list is set to empty, the accessible scope of the file protocol follows the [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) rule. A specific example is as follows.

    <!-- @[SetPath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry2/src/main/ets/pages/SetPath.ets) -->

    ``` TypeScript
    import { webview } from '@kit.ArkWeb';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct WebComponent {
      controller: WebviewController = new webview.WebviewController();
      uiContext: UIContext = this.getUIContext();
    
      build() {
        Row() {
          Web({ src: '', controller: this.controller })
            .onControllerAttached(() => {
              try {
                // Set the list of paths that allow cross-origin access.
                this.controller.setPathAllowingUniversalAccess([
                  this.uiContext.getHostContext()!.resourceDir,
                  this.uiContext.getHostContext()!.filesDir + '/example'
                ])
                this.controller.loadUrl('file://' + this.uiContext.getHostContext()!.resourceDir + '/index.html')
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

HTML sample code:

    ```html
    <!-- main/resources/resfile/index.html -->
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="utf-8">
        <title>Demo</title>
        <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no, viewport-fit=cover">
        <script>
            function getFile() {
              var file = "file:///data/storage/el1/bundle/entry/resources/resfile/js/script.js";
              // Use the file protocol to access a local JS file across origins through XMLHttpRequest.
              var xmlHttpReq = new XMLHttpRequest();
              xmlHttpReq.onreadystatechange = function(){
              console.info("readyState:" + xmlHttpReq.readyState);
              console.info("status:" + xmlHttpReq.status);
              if(xmlHttpReq.readyState == 4){
                if (xmlHttpReq.status == 200) {
                   // If the path list is correctly set on the ETS side, the resource can be obtained here.
                  const element = document.getElementById('text');
                  element.textContent = "load " + file + " success";
                } else {
                    // If the path list is not set on the ETS side, a CORS cross-origin check error is triggered here.
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

## Viewing Error Information Through Callbacks

Check whether error reporting APIs such as onErrorReceive, onHttpErrorReceive, onSslErrorEvent, onHttpAuthRequest, and onClientAuthenticationRequest are called. Based on the returned error code, troubleshoot by referring to [@ohos.web.netErrorList(The List of ArkWeb Network Protocol Stack Errors)](../reference/apis-arkweb/arkts-apis-netErrorList.md).

| Name   | Description                                                       |                       
| ----   |----------------------------------------------------------|
| [onErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onerrorreceive) | This callback is reported when a resource fails to load. For example, accessing a scheme not supported by the kernel reports 302 (UNKNOWN_URL_SCHEME). |
| [onHttpErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttperrorreceive) | The server returns an HTTP error code. Such issues usually require joint debugging with the server.                           | 
| [onHttpAuthRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttpauthrequest9) | The server returns 407, requiring the device side to provide username and password authentication. If not handled correctly, loading exceptions or a blank screen may occur.              | 
| [onClientAuthenticationRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onclientauthenticationrequest9) | The server requests a certificate from the device side. If not handled correctly, page loading exceptions may occur.                            | 
| [onSslErrorEvent](../reference/apis-arkweb/arkts-basic-components-web-events.md#onsslerrorevent12) | A certificate error occurs. You need to troubleshoot based on the certificate error information, such as whether the certificate is configured incorrectly or has expired.                  | 

## Locating Web Page User-Agent Adaptation Issues

If a web page fails to load, use DevTools to switch the User-Agent to Android or Windows and reload the page to check whether it recovers.

1. Default User-Agent: Mozilla/5.0 (Phone;OpenHarmony 6.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.36 ArkWeb/6.0.0.42 Mobile.

2. Open the web page through inspect, view the network, select any request link, and check the User-Agent information in the request header.

3. Compare the app's custom User-Agent with the ArkWeb default User-Agent to check whether the app's custom User-Agent carries the OpenHarmony identifier. If the identifier is not carried when loading fails, set a custom User-Agent that carries the OpenHarmony identifier and check whether the page loads successfully. If the OpenHarmony identifier is carried when loading fails, set a custom User-Agent that carries another identifier such as Android and check whether the page loads successfully. If the page loads successfully, the third-party website has not adapted to OpenHarmony, and you should urge the third party to adapt. If you need to modify the User-Agent, clear the checkbox for **Use browser default settings**. Select **Custom User-Agent** and enter your own User-Agent.

4. Modify [UserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10) and then check whether the page returns to normal.

 <!-- @[ChangeUserAgent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/ets/pages/ChangeUserAgent.ets) -->

 ``` TypeScript
 import { webview } from '@kit.ArkWeb';
 import { BusinessError } from '@kit.BasicServicesKit';
 
 @Entry
 @Component
 struct WebComponent {
   controller: webview.WebviewController = new webview.WebviewController();
   @State customUserAgent: string = ' DemoApp';
 
   build() {
     Column() {
       Web({ src: 'www.example.com', controller: this.controller })
         .onControllerAttached(() => {
           console.info('onControllerAttached');
           try {
             let userAgent = this.controller.getUserAgent() + this.customUserAgent;
             this.controller.setCustomUserAgent(userAgent);
           } catch (error) {
             console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
           }
         })
     }
   }
 }
 ```

## Troubleshooting Common Cookie Issues

* If the SameSite attribute of a cookie is not explicitly specified, its default value is Lax. In this case, the cookie is sent only when the user navigates directly to the origin site, and is not transmitted in cross-site requests (for example, when the user is redirected through a third-party link). To allow cross-site requests to carry the cookie, set SameSite to None. You must also set the Secure attribute to ensure that the cookie is transmitted only over an encrypted HTTPS connection, preventing it from being stolen or tampered with over plaintext HTTP connections.

* Check whether [putAcceptThirdPartyCookieEnabled](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#putacceptthirdpartycookieenabled) is enabled. If it is not enabled, set [putAcceptThirdPartyCookieEnabled](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#putacceptthirdpartycookieenabled) to true so that the Web component instance can send and receive third-party cookies. Cookies are periodically saved to the disk every 30 seconds. If you exit the app within 30 seconds after setting a cookie, the cookie may be lost because it is not flushed to the disk in time. In this case, you can call [saveCookieAsync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#savecookieasync) to force the cookies to be flushed to the disk. (PC/2in1 and tablet devices do not persist session cookies; even if saveCookieAsync is called, session cookies are not written to the disk.)