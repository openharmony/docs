# Life Cycle of Web Components

## Overview

Developers can use web components to load local or online web pages.

Web components provide various component lifecycle callbacks. Through these callbacks, developers can detect the lifecycle state changes of web components and perform related service processing.

The status of a web component includes the following: The Controller is bound to the web component. The web page loading starts. The web page loading progress is complete. The web page is about to be visible.

Figure 1 Callback events during the normal loading of the web page of the web component

![web-event-sequence](figures/web-event-sequence.png)

## Web page loading status of the Web component

- [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear) function: executed after a new instance of a custom component is created and before its build function is executed. You are advised to set [setWebDebuggingAccess](../reference/apis-arkweb/js-apis-webview.md#setwebdebuggingaccess), [customizeSchemes](../reference/apis-arkweb/js-apis-webview.md#customizeschemes), and Cookie[configCookie](../reference/apis-arkweb/js-apis-webview.md#configcookie11-1) for the cross-domain request and fetch request of the web kernel customized protocol URL.

- [onControllerAttached](../reference/apis-arkweb/ts-basic-components-web.md#oncontrollerattached10) event: This callback is triggered when the Controller is successfully bound to the web component. You are advised to inject the JavaScript object [registerJavaScriptProxy](../reference/apis-arkweb/js-apis-webview.md#registerjavascriptproxy) and set the customized user agent [setCustomUserAgent](../reference/apis-arkweb/js-apis-webview.md#setcustomuseragent10) in this event. You can use interfaces irrelevant to web page operations, such as [loadUrl](../reference/apis-arkweb/js-apis-webview.md#loadurl) and [getWebId](../reference/apis-arkweb/js-apis-webview.md#getwebid), in the callback. However, the web page has not been loaded when the callback function is called. Therefore, web page operation interfaces, such as [zoomIn](../reference/apis-arkweb/js-apis-webview.md#zoomin) and [zoomOut](../reference/apis-arkweb/js-apis-webview.md#zoomout), cannot be used in the callback function.

- [onLoadIntercept](../reference/apis-arkweb/ts-basic-components-web.md#onloadintercept10) event: This callback event is triggered before the web component loads the URL to determine whether to block the access. which is allowed by default.

- [onOverrideUrlLoading](../reference/apis-arkweb/ts-basic-components-web.md#onoverrideurlloading12) event: When the URL is about to be loaded to the current web, the host application has the opportunity to obtain the control right. If the callback function returns true, the current web stops loading the URL. If the callback function returns false, the web continues to load the URL. The behavior of the onLoadIntercept interface is different from that of the onOverrideUrlLoading interface, and the triggering time is different. Therefore, the application scenarios of the two interfaces are different. When LoadUrl and iframe (HTML tag, indicating the HTML inline framework element, which is used to embed another page into the current page) are loaded, the onLoadIntercept event is normally called back to, but the onOverrideUrlLoading event is not called back to. For details, see the description of [onLoadIntercept](../reference/apis-arkweb/ts-basic-components-web.md#onloadintercept10) and [onOverrideUrlLoading](../reference/apis-arkweb/ts-basic-components-web.md#onoverrideurlloading12).

- [onInterceptRequest](../reference/apis-arkweb/ts-basic-components-web.md#oninterceptrequest9) event: This callback event is triggered before the web component loads the URL to intercept the URL and return response data.

- [onPageBegin](../reference/apis-arkweb/ts-basic-components-web.md#onpagebegin) event: This callback event is triggered when a web page starts to be loaded and is triggered only in the main frame (indicating an HTML element used to display the HTML element of the HTML page). This callback function is not triggered when the content of an iframe or frameset (used for HTML tags containing frames) is loaded. The multi-frame page may start loading at the same time. Even if the main frame has been loaded, the sub-frame may start loading or continue loading. This callback function is not triggered for navigation (such as segment and historical status) on the same page, navigation that fails before submission, or navigation that is canceled.

- [onProgressChange](../reference/apis-arkweb/ts-basic-components-web.md#onprogresschange) event: notifies the developer of the page loading progress. The multi-frame page or sub-frame may continue to be loaded while the main frame may have been loaded. Therefore, this event may still be received after the [onPageEnd](../reference/apis-arkweb/ts-basic-components-web.md#onpageend) event.

- [onPageEnd](../reference/apis-arkweb/ts-basic-components-web.md#onpageend) event: This callback function is triggered only in the main frame when the web page loading is complete. The multi-frame page may start loading at the same time. Even if the main frame has been loaded, the sub-frame may start loading or continue loading. This callback function is not triggered for navigation (such as segment and historical status) on the same page, navigation that fails before submission, or navigation that is canceled. You are advised to execute the JavaScript script [loadUrl](../reference/apis-arkweb/js-apis-webview.md#runjavascript) in this callback. Note that receiving this callback does not ensure that the next frame drawn by the web page reflects the DOM status.

- [onPageVisible](../reference/apis-arkweb/ts-basic-components-web.md#onpagevisible9) event: This callback is triggered when the body of an HTTP response starts to be loaded and a new page is about to be visible. This callback is triggered only in the main frame. This callback is triggered early in document loading, so linked resources such as online CSS and online images may not be available.

- [onRenderExited](../reference/apis-arkweb/ts-basic-components-web.md#onrenderexited9) event: This callback function is triggered when the application rendering process exits abnormally. Operations such as releasing system resources and saving data can be performed in this callback function. If the application wants to recover from an exception, the application needs to call the [loadUrl](../reference/apis-arkweb/js-apis-webview.md#loadurl) interface to reload the page.

- [onDisAppear](../reference/apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear) event: This callback function is triggered when the component is uninstalled. This event is a common event triggered when a component is uninstalled from the component tree.

Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { promptAction } from '@kit.ArkUI';

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
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onControllerAttached(() => {
            //You are advised to load the URL, set a user-defined proxy, and inject a JS object.
            console.log('onControllerAttached excute')
          })
          .onLoadIntercept((event) => {
            if (event) {
              console.log('onLoadIntercept url:' + event.data.getRequestUrl())
              console.log('url:' + event.data.getRequestUrl())
              console.log('isMainFrame:' + event.data.isMainFrame())
              console.log('isRedirect:' + event.data.isRedirect())
              console.log('isRequestGesture:' + event.data.isRequestGesture())
            }
            Returns **true** if the access is blocked; returns **false** otherwise.
            return true
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
            let length = this.heads.push(head1);
            length = this.heads.push(head2);
            this.responseWeb.setResponseHeader(this.heads);
            this.responseWeb.setResponseData(this.webData);
            this.responseWeb.setResponseEncoding('utf-8');
            this.responseWeb.setResponseMimeType('text/html');
            this.responseWeb.setResponseCode(200);
            this.responseWeb.setReasonMessage('OK');
            If response data is returned, the data is loaded based on the response data. If no response data is returned, null is returned, indicating that the data is loaded in the original mode.
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
            //You are advised to execute the JavaScript script in this event.
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
            promptAction.showToast({
              message: 'The web is hidden',
              duration: 2000
            })
          })
      }
    }
  }
  ```

Frontend index.html.

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
  <h1>Hello, ArkWeb</h1>
  </body>
  </html>
  ```

## Performance indicators of web page loading of web components

Pay attention to some important performance indicators during web page loading. For example, First Contentful Paint (FCP) is used for first content drawing, First Meaningful Paint (FMP) is used for first effective drawing, and Last Contentful Paint (LCP) is used for maximum content drawing. The web component provides the following interfaces to notify developers:

- [onFirstContentfulPaint](../reference/apis-arkweb/ts-basic-components-web.md#onfirstcontentfulpaint10) event: callback function for drawing the web page content for the first time. Time point when a text, image, non-blank Canvva, or SVG is drawn for the first time.

- [onFirstMeaningfulPaint](../reference/apis-arkweb/ts-basic-components-web.md#onfirstmeaningfulpaint12) event: callback function for drawing a web page for the first time. Time when the main content of the page is drawn for the first time.

- [onLargestContentfulPaint](../reference/apis-arkweb/ts-basic-components-web.md#onlargestcontentfulpaint12) event: callback function for drawing the maximum content on a web page. Time point when the visible element with the largest content in the visible area starts to appear on the page.
<!--no_check-->