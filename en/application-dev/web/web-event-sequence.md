# Lifecycle of the Web Component
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @weixin_41848015-->
<!--Designer: @libing23232323-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

You can use **Web** components to load local or online web pages.

The **Web** component provides lifecycle callbacks for detecting status changes and processing services.

The statuses of a **Web** component include binding a controller to it, the start, progress, and end of page loading, and the state when the page is about to be displayed.

For details about how to keep web pages alive, see [Using Offline Web Components](../web/web-offline-mode.md).

If the [aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear) function is executed when a custom component is destructed, the **Web** component is destroyed and unbound from the WebviewController, and the JS running environment is also destroyed.

**Figure 1** Callback events during the normal web page loading of the **Web** component

![web-event-sequence](figures/web-event-sequence.png)

## Statuses of the Normal Web Page Loading

- [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear): executed before its build function when a new instance of a custom component is created. You are advised to set the web debug mode and customize protocol URL permissions and cookies at this status.

- [onControllerAttached](../reference/apis-arkweb/arkts-basic-components-web-events.md#oncontrollerattached10): triggered when the controller is successfully bound to the **Web** component. Do not call APIs related to the **Web** component before this callback. Otherwise, a js-error exception will be thrown. You are advised to inject a JS object, set a custom user agent, and use APIs irrelevant to web page operations in this event. However, the web page is not loaded when this callback is called. Therefore, APIs for web page operation, such as [zoomIn](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomin) and [zoomOut](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomout), cannot be used in this callback.

- [onLoadIntercept](../reference/apis-arkweb/arkts-basic-components-web-events.md#onloadintercept10): triggered before the **Web** component loads a URL, which is used to determine whether to block the access. By default, the loading is allowed.

- [onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9): triggered before the **Web** component loads a URL, which is used to intercept the URL and return response data.

- [onPageBegin](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpagebegin): triggered when a web page starts loading and only in the main frame (an HTML element used to display the HTML page). This callback is not triggered when the content of an **iframe** or **frameset** (an HTML tag used to include frames) is loaded. Multiple-frame pages may be loaded at the same time. When the main frame is loaded, subframes may still be loaded. This callback will not be triggered for the navigation to the same page or the failed navigation.

- [onProgressChange](../reference/apis-arkweb/arkts-basic-components-web-events.md#onprogresschange): triggered to notify the page loading progress. The multi-frame page or subframes may continue to be loaded while the main frame has been loaded. Therefore, this event may be received after the [onPageEnd](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpageend) event.

- [onPageEnd](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpageend): triggered only in the main frame when a web page is already loaded. Multi-frame pages may start to be loaded at the same time. Even if the main frame is already loaded, the sub-frames may start to be loaded or continue to be loaded. This callback will not be triggered for the navigation to the same page or the failed navigation. You are advised to execute the JavaScript script in this callback. Note that even if this callback function is received, the next frame may not reflect the DOM status.

## Statuses of the Abnormal Web Page Loading
- [onOverrideUrlLoading](../reference/apis-arkweb/arkts-basic-components-web-events.md#onoverrideurlloading12): triggered for the host application to obtain control when a URL is about to be loaded to the current web page. The value **true** means to stop loading the URL, and the value **false** means to continue loading the URL. The behavior of **onLoadIntercept()** is different from that of the **onOverrideUrlLoading()** and they are triggered in different timing. Therefore, the two APIs are used in different scenarios. The **onLoadIntercept** event is triggered when **loadUrl** and iframe are loaded, but the **onOverrideUrlLoading** event is not triggered when **loadUrl** and specific iframe are loaded.

- [onPageVisible](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpagevisible9): web callback event, which is triggered when the body of an HTTP response starts to be loaded and a new page is about to be displayed in the rendering process. In this case, the document loading is still in the early stage, so the linked resources such as online CSS and images may not be available.

- [onRenderExited](../reference/apis-arkweb/arkts-basic-components-web-events.md#onrenderexited9): triggered when an application rendering process exits abnormally. You can release system resources and save data in this callback. If you want to recover the application, call the [loadUrl](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API to reload the page. For details, see [How can I prevent page suspension when the Web component's rendering child process exits unexpectedly](#how-can-i-prevent-page-suspension-when-the-web-components-rendering-child-process-exits-unexpectedly).

- [onDisAppear](../reference/apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear): triggered when a component is uninstalled from the component tree, This event is triggered when a component is uninstalled.

Codes on the application side:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    responseWeb: WebResourceResponse = new WebResourceResponse();
    heads: Header[] = new Array();
    @State webData: string = "<!DOCTYPE html>\n" +
      "<html>\n" +
      "<head>\n" +
      "<title>intercept test</title>\n" +
      "</head>\n" +
      "<body>\n" +
      "<h1>intercept test</h1>\n" +
      "</body>\n" +
      "</html>";

    aboutToAppear(): void {
      try {
        webview.WebviewController.setWebDebuggingAccess(true);
      } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
      }
    }

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onControllerAttached(() => {
            // You are advised to use **loadUrl**, set a custom user agent, and inject a JS object.
            console.log('onControllerAttached execute')
          })
          .onLoadIntercept((event) => {
            if (event) {
              console.log('onLoadIntercept url:' + event.data.getRequestUrl())
              console.log('url:' + event.data.getRequestUrl())
              console.log('isMainFrame:' + event.data.isMainFrame())
              console.log('isRedirect:' + event.data.isRedirect())
              console.log('isRequestGesture:' + event.data.isRequestGesture())
            }
            // If true is returned, the loading is blocked. Otherwise, the loading is allowed.
            return false;
          })
          .onOverrideUrlLoading((webResourceRequest: WebResourceRequest) => {
            if (webResourceRequest && webResourceRequest.getRequestUrl() == "about:blank") {
              return true;
            }
            return false;
          })
          .onInterceptRequest((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
            }
            let head1: Header = {
              headerKey: "Connection",
              headerValue: "keep-alive"
            }
            let head2: Header = {
              headerKey: "Cache-Control",
              headerValue: "no-cache"
            }
            // Add a new element to the end of the array and return the length of the new array.
            let length = this.heads.push(head1);
            length = this.heads.push(head2);
            console.log('The response header result length is :' + length);
            this.responseWeb.setResponseHeader(this.heads);
            this.responseWeb.setResponseData(this.webData);
            this.responseWeb.setResponseEncoding('utf-8');
            this.responseWeb.setResponseMimeType('text/html');
            this.responseWeb.setResponseCode(200);
            this.responseWeb.setReasonMessage('OK');
            // If response data is returned, the data is loaded based on the response data. If no response data is returned, null is returned, indicating that the data is loaded in the original mode.
            return this.responseWeb;
          })
          .onPageBegin((event) => {
            if (event) {
              console.log('onPageBegin url:' + event.url);
            }
          })
          .onFirstContentfulPaint(event => {
            if (event) {
              console.log("onFirstContentfulPaint:" + "[navigationStartTick]:" +
              event.navigationStartTick + ", [firstContentfulPaintMs]:" +
              event.firstContentfulPaintMs);
            }
          })
          .onProgressChange((event) => {
            if (event) {
              console.log('newProgress:' + event.newProgress);
            }
          })
          .onPageEnd((event) => {
            // You are advised to execute the JavaScript script in this event.
            if (event) {
              console.log('onPageEnd url:' + event.url);
            }
          })
          .onPageVisible((event) => {
            console.log('onPageVisible url:' + event.url);
          })
          .onRenderExited((event) => {
            if (event) {
              console.log('onRenderExited reason:' + event.renderExitReason);
            }
          })
          .onDisAppear(() => {
            this.getUIContext().getPromptAction().showToast({
              message: 'The web is hidden',
              duration: 2000
            })
          })
      }
    }
  }
  ```


## Performance Indicators of Web Component Page Loading

Pay attention to some important performance indicators during web page loading. Such as First Contentful Paint (FCP), First Meaningful Paint (FMP), and Largest Contentful Paint (LCP). The **Web** component provides the following APIs for notifying you these indicators of online non-PDF web pages. Local web pages and PDF web pages are not supported.

- [onFirstContentfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onfirstcontentfulpaint10): triggered to notify the time when the web page content such as a text, image, non-blank Canvas, or SVG is drawn for the first time.

- [onFirstMeaningfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onfirstmeaningfulpaint12): triggered when the first meaningful paint is drawn.

- [onLargestContentfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onlargestcontentfulpaint12): triggered when the largest content, such as the image, text block, or video, is drawn in the visible area.

## How can I prevent page suspension when the Web component's rendering child process exits unexpectedly

ArkWeb is a **Web** component platform designed to display web page content for applications and provide capabilities such as page loading, interaction, and debugging. When an ArkWeb application is used, the page may be suspended due to various reasons. For example, the ArkWeb child rendering process crashes due to front-end exceptions, or the background ArkWeb child rendering process is terminated due to insufficient system resources. In this case, you need to open the page again or restart the application.

If the web page is suspended when the ArkWeb child process exits abnormally, the application can listen for the [onRenderExited](../reference/apis-arkweb/arkts-basic-components-web-events.md#onrenderexited9) event to obtain the specific exit cause [RenderExitReason](../reference/apis-arkweb/arkts-basic-components-web-e.md#renderexitreason9) and handle the exception in the callback correspondingly.

**Development in Practice**
```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  needReloadWhenVisible: boolean = false ;  // When the Web component is invisible, the page reloading is blocked after the render process exits. When the Web component is visible, the page is reloaded.
  webIsVisible: boolean = false;            // Check whether the Web component is visible.

  // The child process crash is distinguished from other exceptions. You can refine the exception handling policy based on the actual service.
  renderReloadMaxForCrashed: number = 5;    // Set the maximum number of retries for reloading after a crash. The application can set this parameter based on service characteristics.
  renderReloadCountForCrashed: number = 0;  // Number of reload times after a crash.
  renderReloadMaxForOthers: number = 10;    // Set the maximum number of retry times for exiting due to other exceptions. The application can set this parameter based on service characteristics.
  renderReloadCountForOthers: number = 0;   // Number of reload times after exit due to other exceptions.

  // Create a Web component.
  controller: webview.WebviewController = new webview.WebviewController();

  // Specify the page to be loaded.
  url: string = "www.example.com";
  build() {
    Column() {
      Web({ src: this.url, controller: this.controller })
        .onVisibleAreaChange([0, 1.0], (isVisible) => {
          this.webIsVisible = isVisible;
          if (isVisible && this.needReloadWhenVisible) { // Reload the page when the Web component is visible.
            this.needReloadWhenVisible = false;
            this.controller.loadUrl(this.url);
          }
        })
        // The application listens for the callback triggered when the child rendering process exits abnormally and handles the exception.
        .onRenderExited((event) => {
          if (!event) {
            return;
          }
          if (event.renderExitReason == RenderExitReason.ProcessCrashed) {
            if (this.renderReloadCountForCrashed >= this.renderReloadMaxForCrashed) {
              // Set the maximum number of reload times to prevent the page from being cyclically loaded.
              return;
            }
            console.log('renderReloadCountForCrashed: ' + this.renderReloadCountForCrashed);
            this.renderReloadCountForCrashed++;
          } else {
            if (this.renderReloadCountForOthers >= this.renderReloadMaxForOthers) {
              // Set the maximum number of reload times to prevent the page from being cyclically loaded.
              return;
            }
            console.log('renderReloadCountForOthers: ' + this.renderReloadCountForOthers);
            this.renderReloadCountForOthers++;
          }
          if (this.webIsVisible) {
            // Reload the page immediately when the Web component is visible.
            this.controller.loadUrl(this.url);
            return;
          }
          // Do not reload the page immediately when the Web component is invisible.
          this.needReloadWhenVisible = true;
        })
    }
  }
}
```
