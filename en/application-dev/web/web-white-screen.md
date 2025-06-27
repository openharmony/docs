# Troubleshooting White Screen Issues on Web Pages

There are many reasons for white screen issues on web pages. This topic describes how to troubleshoot common white screen issues.

1. Check the permissions and network status.
2. Locate the error type (cross-origin issues, 404 errors, or JS exceptions) by referring to [Debugging Frontend Pages by Using DevTools](web-debugging-with-devtools.md).
3. In complex layout scenarios, check the rendering mode and component constraints.
4. Handle the compatibility problem of the HTML5 code.
5. Check the keywords related to the lifecycle and network loading in the log.

## Checking Permissions and Network Status
If the network or file access permission is not added for the application, or the network status of the device is poor, the **Web** component will fail to be loaded or page elements will be missing, resulting in a white screen.
* Check the network status of the device, including whether the device is connected to the network and whether the built-in browser of the device can access web pages.
* Ensure that the network permission **ohos.permission.INTERNET** is added to the application (mandatory for accessing online pages).
  ```
  // Add the required permission in module.json5.
  "requestPermissions":[
     {
        "name" : "ohos.permission.INTERNET"
     }
  ]
  ```
* The following table lists attributes used to enable related permissions.
    | Attribute  | Description |                       
    | ----   | -------------------------------- |
    | [domStorageAccess](../reference/apis-arkweb/ts-basic-components-web-attributes.md#domstorageaccess) | Sets whether to enable the local storage. If this permission is not enabled, local storage cannot be used to store data, any code that calls local storage will become invalid, and functionalities that depend on local storage will be abnormal.|
    | [fileAccess](../reference/apis-arkweb/ts-basic-components-web-attributes.md#fileaccess) | Sets whether to enable the file read/write functionality. If the file read/write functionality is not enabled, the file-dependent modules will crash.| 
    | [imageAccess](../reference/apis-arkweb/ts-basic-components-web-attributes.md#imageaccess) | Sets whether to enable automatic image loading.| 
    | [onlineImageAccess](../reference/apis-arkweb/ts-basic-components-web-attributes.md#onlineimageaccess) | Sets whether to enable online image loading (through HTTP and HTTPS).|
    | [javaScriptAccess](../reference/apis-arkweb/ts-basic-components-web-attributes.md#javascriptaccess) | Sets whether to enable JavaScript script execution.| 


  ```ts
  // xxx.ets
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
* Modify the [UserAgent](../reference/apis-arkweb/js-apis-webview-WebviewController.md#setcustomuseragent10) and check whether the page is restored.

  ```ts
  // xxx.ets
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
          console.log("onControllerAttached");
          try {
            let userAgent = this.controller.getUserAgent() + this.  customUserAgent;
            this.controller.setCustomUserAgent(userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      }
    }
  }
  ```
## Debugging Pages by Using DevTools
If a white screen issue persists after the network and permission configurations are correctly configured, use DevTools to debug the frontend page and listen for the web-related error reporting APIs to locate the error type.

1. Check the error information on the console to locate the resource loading failure. If resource loading fails, page elements may be missing, the layout may be disordered, and images and animations may become invalid. In severe cases, the rendering process may break down and the white screen issue may occur. As shown in the following figure, check the following items in sequence:<br>
  1. Whether the elements are complete and whether the HTML elements and structure are correct.<br> 2. Whether there are errors reported on the console.<br>3. Whether the resource loading time is long.<br>
   ![web-white-devtools](figures/web-white-devtools.PNG)

2. Check the console to see if there are any exceptions caused by the Mixed Content policy or CORS policy, or JS errors. For details, see [Resolving Cross-Origin Resource Access](web-cross-origin.md). Cross-origin problems frequently occur in Vue/React projects because the ArkWeb kernel does not allow the **file://** or **resource://** protocol to load cross-origin resources (for example, local file requests in the Vue project).

    Solution:
    * Use HTTP or HTTPS to load the main page (the local server must support this).
    * If local files are required, intercept resource requests through [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web-events.md#oninterceptrequest9) and replace them with local resources.
   ```c
   // Intercept the request and return the local resource in the Web component.
   Web({
       src: 'http://your-domain/indexl.html',
       controller: this.controller
   })
   .onInterceptRequest((event) => {
       if (event.request.url.endWith('.js')) {
           // Read the local file and return the response.
           const data = fs.readSync('/path/to/local/file.js');
           return {
               responseCode: 200,
               responseData: { data: data },
               header: { 'Content-Type': 'application/javascript' }
           };
       }
    return null; //Do not intercept other requests.
   })
   ```

3. Check whether error reporting APIs, such as **onErrorReceive**, **onHttpErrorReceive**, **onSslErrorEvent**, **onHttpAuthRequest**, and **onClientAuthenticationRequest**, are called.

    | API  | Description |                       
    | ----   | -------------------------------- |
    | [onErrorReceive](../reference/apis-arkweb/ts-basic-components-web-events.md#onerrorreceive) | Called when resources fail to be loaded. For example, 302(**UNKNOWN_URL_SCHEME**) is reported when a scheme that is not supported by the kernel is accessed.|
    | [onHttpErrorReceive](../reference/apis-arkweb/ts-basic-components-web-events.md#onhttperrorreceive) | Called when the server returns an HTTP error code, which requires joint commissioning with the server.| 
    | [onHttpAuthRequest](../reference/apis-arkweb/ts-basic-components-web-events.md#onhttpauthrequest9) | Called when the server returns 407, indicating that the device needs to provide the user name and password for authentication. If the processing is incorrect, the loading may be abnormal and a white screen may occur.| 
    | [onClientAuthenticationRequest](../reference/apis-arkweb/ts-basic-components-web-events.md#onclientauthenticationrequest9) | Called when the server requests a certificate from the device. If the request is not processed correctly, the page loading will be abnormal.| 
    | [onSslErrorEvent](../reference/apis-arkweb/ts-basic-components-web-events.md#onsslerrorevent12) | Called when the certificate is incorrect. The application needs to check whether the certificate is incorrectly configured or has expired based on the certificate error information.| 


## Resolving White Screen Issues Caused by Complex Layout and Rendering Modes
If a page uses a complex layout or rendering mode, pay attention to its application scenarios and constraints. Improper use of the layout or rendering mode may cause layout disorder or white screen. For example, when [layoutMode](../reference/apis-arkweb/ts-basic-components-web-attributes.md#layoutmode11) is used, you should:

- Set the synchronous rendering mode through **webSetting({renderingMode: WebRenderingMode.SYNCHRONOUS})**.
- Disable the scrolling effect through **webSetting({overScrollMode: OverScrollMode.NEVER})**.
- Do not dynamically adjust the component height in this mode to ensure that the page height is fixed.
- Do not enable the **RESIZE_CONTENT** attribute in **FIT_CONTENT** mode to avoid layout invalidation.

## Handling the Compatibility of HTML5 Code
To avoid white screen issues, you can handle the compatibility issue as follows:
* Intercept special protocols.
* If a white screen is displayed due to the **tel:** or **mailto:** protocol invoked by the HTML5 page, intercept the protocol and invoke the system dialing capability through **onInterceptRequest**.
   ```c
   .onInterceptRequest((event) => {
       if (event.request.url.startWith('tel:')) {
           // Invoke the system dialing capability.
           call.makeCall({ phoneNumber: '123456' });
           return { responseCode: 404 }; // Prevent the default behavior.
       }
       return null;  
   })
   ```
## Monitoring Memory and Lifecycle
If the memory usage reaches the threshold, the rendering process will be terminated, causing a white screen. Similarly, a white screen will occur if the rendering process fails to start or is abnormally terminated. You can check the cause in logs. For example, check whether the **Web** component is correctly bound to the **WebController** or whether the white screen occurs because the **Web** component is released too early. Check the information related to the render process in the log, for example, whether a memory leak causes insufficient rendering memory. The keyword **MEMORY_PRESSURE_LEVEL_CRITICAL** indicates that the memory usage has reached the threshold. In this case, the web page may encounter exceptions such as black screen, artifacts, or flicker. You need to check whether a memory leak occurs and whether the render process is successfully started or exits abnormally.

The following table lists log keywords and the corresponding descriptions.

| Keyword  | Description |                       
| ----   | -------------------------------- |
| StartRenderProcess failed | The rendering process fails to be started.|
| MEMORY_PRESSURE_LEVEL_CRITICAL | The device memory pressure reaches the threshold. If the device continues to be used, a black screen, screen flickering, or white screen may occur.|
| crashpad SandboxedHandler::HandlerCrash, received signo = xxx | The render process crashes, causing problems such as white screen and **Web** component suspension.|
| SharedContextState context lost via Skia OOM | The shared memory is insufficient, which may cause the application to crash, produce artifacts, or become suspended.
| CreateNativeViewGLSurfaceEGLOhos::normal surface | The EGL surface is successfully created. If this log is not displayed, a white screen occurs.|
| INFO: request had no response within 5 seconds | Network timeout.|
| final url: ***, error_code xxx(net::ERR_XXX) | An error is reported during the main resource loading.|

The following figure shows the key points contained during the **Web** component loading process. The following table lists the log keywords during the **Web** component loading process.
![web-white-page-load](figures/web-white-page-load.PNG)

| Keyword  | Description |                       
| ----   | -------------------------------- |
| NWebRenderMain start  | The child process starts.|
| RendererMain startup,<br> render thread init | The child process initialization starts.|
| event_message: WillProcessNavigationResponse source_id xxx navigation_handle id: xxx| The response of the main resource is received.|
| event_message: commit navigation in main frame, routing_id: 4, url: *** | The navigation is committed to the child process.
| RenderFrameImpl::CommitNavigation,<br> event_message: page load start | The child process receives the commit message.|
| NWebHandlerDelegate::OnNavigationEntryCommitted,<br> event_message: Commit source_id xxx | The main process receives **DidCommitNavigation**.|
| event_message: load_timing_info errpr_code:0,...| The main resource loading is complete, and the time required for each phase is displayed.|
| event_message: MarkFirstContentfulPaint| The tag identifies an element with displayable content.|
| NWebHandlerDelegate::OnPageVisible| The first frame is displayed.|
| NWebHandlerDelegate::OnFirstContentfulPaint| The first frame content is displayed.|
| event_message: content load finished | The page content parsing is complete.|
| event_message: page load finished,<br> NWebHandlerDelegate::OnLoadEnd,<br> NWebHandlerDelegate::MainFrame OnLoadEnd,<br> NWebHandlerDelegate::OnFirstMeaningfulPaint | The page and sub-resources are loaded.|
