# Web组件的生命周期
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @weixin_41848015-->
<!--Designer: @libing23232323-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

## 概述

开发者可以使用Web组件加载本地或者在线网页。

Web组件提供生命周期回调接口，用于感知状态变化和处理业务。

Web组件的状态主要包括：Controller绑定到Web组件、网页加载开始、网页加载进度、网页加载结束、页面即将可见。

Web页面保活可以参考[使用离线Web组件](../web/web-offline-mode.md)。

自定义组件析构销毁时执行[aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear)函数，Web组件会被销毁，Web组件与WebviewController解绑，js运行环境也会一并销毁。

**图1**  Web组件网页正常加载过程中的回调事件

![web-event-sequence](figures/web-event-sequence.png)

## Web组件网页正常加载过程所涉及的状态说明 

- [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear)函数：在创建自定义组件的新实例后，在执行其build函数前执行。建议在此设置WebDebug调试模式、自定义协议URL的权限、Cookie等。

- [onControllerAttached](../reference/apis-arkweb/arkts-basic-components-web-events.md#oncontrollerattached10)事件：当Controller成功绑定到Web组件时触发该回调，且禁止在该事件回调前调用Web组件相关的接口，否则会抛出js-error异常。建议在此事件中注入JS对象、设置自定义用户代理，使用操作网页不相关的接口。但因该回调调用时网页还未加载，因此无法在回调中使用有关操作网页的接口，例如[zoomIn](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomin)、[zoomOut](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#zoomout)等。

- [onLoadIntercept](../reference/apis-arkweb/arkts-basic-components-web-events.md#onloadintercept10)事件：当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。默认允许加载。

- [onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9)事件：当Web组件加载url之前触发该回调，用于拦截url并返回响应数据。

- [onPageBegin](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpagebegin)事件：网页开始加载时触发该回调，且只在主frame（表示一个HTML元素，用于展示HTML页面的HTML元素）触发。如果是iframe或者frameset（用于包含frame的HTML标签）的内容加载时则不会触发此回调。多frame页面可能同时加载，主frame加载结束时子frame可能仍在加载。同一页面导航或失败的导航不会触发该回调。

- [onProgressChange](../reference/apis-arkweb/arkts-basic-components-web-events.md#onprogresschange)事件：告知开发者当前页面加载的进度。多frame页面或者子frame可能还在继续加载而主frame已经加载结束，所以在[onPageEnd](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpageend)事件后仍可能收到该事件。

- [onPageEnd](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpageend)事件：网页加载完成时触发该回调，且只在主frame触发。多frame页面有可能同时开始加载，即使主frame已经加载结束，子frame也有可能才开始或者继续加载中。同一页面导航或失败的导航不会触发该回调。建议在此回调中执行JavaScript脚本。注意，收到该回调不能保证下一帧反映DOM状态。

## Web组件网页异常加载过程所涉及的状态说明 
- [onOverrideUrlLoading](../reference/apis-arkweb/arkts-basic-components-web-events.md#onoverrideurlloading12)事件：当URL将要加载到当前Web中时，让宿主应用程序有机会获得控制权，回调函数返回true将导致当前Web中止加载URL，而返回false则会导致Web继续照常加载URL。onLoadIntercept接口和onOverrideUrlLoading接口行为不一致，触发时机也不同，所以在应用场景上存在一定区别。onLoadIntercept事件在LoadUrl和iframe加载时触发，但onOverrideUrlLoading事件在LoadUrl和特定iframe加载时不会触发。

- [onPageVisible](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpagevisible9)事件：Web回调事件。渲染流程中当HTTP响应的主体开始加载，新页面即将可见时触发该回调。此时文档加载还处于早期，因此链接的资源比如在线CSS、在线图片等可能尚不可用。

- [onRenderExited](../reference/apis-arkweb/arkts-basic-components-web-events.md#onrenderexited9)事件：应用渲染进程异常退出时触发该回调，可以在此回调中进行系统资源的释放、数据的保存等操作。如果应用希望异常恢复，需要调用[loadUrl](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl)接口重新加载页面。详细用法参考[应用如何避免Web组件渲染子进程异常退出导致的页面卡死问题](#应用如何避免web组件渲染子进程异常退出导致的页面卡死问题)。

- [onDisAppear](../reference/apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear)事件：组件卸载消失时触发此回调。该事件在组件卸载时触发。

应用侧代码。

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
            // 推荐在此loadUrl、设置自定义用户代理、注入JS对象等
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
            // 返回true表示阻止此次加载，否则允许此次加载
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
            // 将新元素追加到数组的末尾，并返回数组的新长度。
            let length = this.heads.push(head1);
            length = this.heads.push(head2);
            console.log('The response header result length is :' + length);
            this.responseWeb.setResponseHeader(this.heads);
            this.responseWeb.setResponseData(this.webData);
            this.responseWeb.setResponseEncoding('utf-8');
            this.responseWeb.setResponseMimeType('text/html');
            this.responseWeb.setResponseCode(200);
            this.responseWeb.setReasonMessage('OK');
            // 返回响应数据则按照响应数据加载，无响应数据则返回null表示按照原来的方式加载
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
            // 推荐在此事件中执行JavaScript脚本
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


## Web组件网页加载的性能指标

网页加载过程中需要关注一些重要的性能指标。例如，FCP(First Contentful Paint)首次内容绘制，FMP(First Meaningful Paint)首次有效绘制，LCP(Largest Contentful Paint)最大内容绘制等。Web组件提供了如下接口来通知开发者，接口仅支持在线非PDF网页，不支持本地网页和PDF网页。

- [onFirstContentfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onfirstcontentfulpaint10)事件：网页首次内容绘制的回调函数。首次绘制文本、图像、首次绘制文本、图像、非空白Canvas或SVG的时间点。

- [onFirstMeaningfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onfirstmeaningfulpaint12)事件：网页绘制页面主要内容的回调函数。首次绘制主要内容的时间点。

- [onLargestContentfulPaint](../reference/apis-arkweb/arkts-basic-components-web-events.md#onlargestcontentfulpaint12)事件：网页绘制页面最大内容的回调函数。绘制可视区域内最大图片、文本块或视频的时间点。

## 应用如何避免Web组件渲染子进程异常退出导致的页面卡死问题

ArkWeb（方舟Web）是一个Web组件平台，旨在为应用程序提供展示Web页面内容的功能，并向开发者提供一系列的能力，如页面加载、交互和调试等功能。使用ArkWeb相关应用时，可能因各种原因（例如前端偶现异常导致ArkWeb渲染子进程崩溃，或是打开的应用较多，系统资源紧张导致后台ArkWeb渲染子进程被终止）而出现页面卡死的问题，这时需要重新打开页面或重启应用来解决。

在ArkWeb渲染子进程异常退出导致页面卡死后，应用可通过监听[onRenderExited](../reference/apis-arkweb/arkts-basic-components-web-events.md#onrenderexited9)事件来获取具体的退出原因[RenderExitReason](../reference/apis-arkweb/arkts-basic-components-web-e.md#renderexitreason9)，并在异常回调中根据退出的具体原因，执行相应的异常处理。

**开发实践案例**
```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  needReloadWhenVisible: boolean = false ;  // Web组件不可见时render退出后阻止重新加载页面，在可见时重新加载页面。
  webIsVisible: boolean = false;            // 判断Web组件是否可见。

  // 此处是将子进程异常崩溃和其它异常原因做了区分，应用开发者可根据实际业务特点，细化对应异常的处理策略。
  renderReloadMaxForCrashed: number = 5;    // 设置因为异常崩溃后重新加载的最大重试次数，应用可根据业务特点，自行设置试错上限。
  renderReloadCountForCrashed: number = 0;  // 异常崩溃后重新加载的次数。
  renderReloadMaxForOthers: number = 10;    // 设置因为其它异常原因退出的最大重试次数，应用可根据业务特点，自行设置试错上限。
  renderReloadCountForOthers: number = 0;   // 其它异常原因退出后重新加载的次数。

  // 创建Web组件。
  controller: webview.WebviewController = new webview.WebviewController();

  // 指定加载的页面。
  url: string = "www.example.com";
  build() {
    Column() {
      Web({ src: this.url, controller: this.controller })
        .onVisibleAreaChange([0, 1.0], (isVisible) => {
          this.webIsVisible = isVisible;
          if (isVisible && this.needReloadWhenVisible) { // Web组件可见时重新加载页面。
            this.needReloadWhenVisible = false;
            this.controller.loadUrl(this.url);
          }
        })
        // 应用监听渲染子进程异常退出回调，并进行异常处理。
        .onRenderExited((event) => {
          if (!event) {
            return;
          }
          if (event.renderExitReason == RenderExitReason.ProcessCrashed) {
            if (this.renderReloadCountForCrashed >= this.renderReloadMaxForCrashed) {
              // 设置重试次数上限保护，避免必现问题导致页面被循环加载。
              return;
            }
            console.log('renderReloadCountForCrashed: ' + this.renderReloadCountForCrashed);
            this.renderReloadCountForCrashed++;
          } else {
            if (this.renderReloadCountForOthers >= this.renderReloadMaxForOthers) {
              // 设置重试次数上限保护, 避免必现问题导致页面被循环加载。
              return;
            }
            console.log('renderReloadCountForOthers: ' + this.renderReloadCountForOthers);
            this.renderReloadCountForOthers++;
          }
          if (this.webIsVisible) {
            // Web组件可见则立即重新加载。
            this.controller.loadUrl(this.url);
            return;
          }
          // Web组件不可见时不立即重新加载。
          this.needReloadWhenVisible = true;
        })
    }
  }
}
```
