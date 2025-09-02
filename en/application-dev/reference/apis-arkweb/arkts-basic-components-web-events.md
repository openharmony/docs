# Events

The following universal events are supported: [onAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#onappear), [onDisAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear), [onBlur](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onblur), [onFocus](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onfocus), [onDragEnd](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragend10), [onDragEnter](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragenter), [onDragStart](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart), [onDragMove](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragmove), [onDragLeave](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave), [onDrop](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop), [onHover](../apis-arkui/arkui-ts/ts-universal-events-hover.md#onhover), [onMouse](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onmouse), [onKeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#onkeyevent), [onTouch](../apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch), [onVisibleAreaChange](../apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange)

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## onAlert

onAlert(callback: Callback\<OnAlertEvent, boolean\>)

Triggered when **alert()** is invoked to display an alert dialog box on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                  | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnAlertEvent](./arkts-basic-components-web-i.md#onalertevent12), boolean\>                | Yes   | Callback used when **alert()** is invoked to display an alert dialog box on the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **Web** component the confirmation result. If the callback returns **false**, the processing result of the dialog box is regarded as cancel.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onAlert((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              this.uiContext.showAlertDialog({
                title: 'onAlert',
                message: 'text',
                primaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body>
    <h1>WebView onAlert Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <script>
      function myFunction() {
        alert("Hello World");
      }
    </script>
  </body>
  </html>
  ```

## onBeforeUnload

onBeforeUnload(callback: Callback\<OnBeforeUnloadEvent, boolean\>)

Triggered when a user is about to leave, refresh, or close this page. This API takes effect only when the page has obtained focus.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnBeforeUnloadEvent](./arkts-basic-components-web-i.md#onbeforeunloadevent12), boolean\>                | Yes   | Callback triggered when the current page is about to be refreshed or closed.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **Web** component whether to exit the current page based on the user's operation. The value **false** means that the custom dialog box drawn in the function is ineffective.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onBeforeUnload((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              console.log("event.isReload:" + event?.isReload ?? 'false');
              this.uiContext.showAlertDialog({
                title: 'onBeforeUnload',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body onbeforeunload="return myFunction()">
    <h1>WebView onBeforeUnload Demo</h1>
    <a href="https://www.example.com">Click here</a>
    <script>
      function myFunction() {
        return "onBeforeUnload Event";
      }
    </script>
  </body>
  </html>
  ```

## onConfirm

onConfirm(callback: Callback\<OnConfirmEvent, boolean\>)

Triggered when **confirm()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnConfirmEvent](./arkts-basic-components-web-i.md#onconfirmevent12), boolean\>                | Yes   | Callback triggered when **confirm()** is invoked by the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **Web** component the confirmation result. If the callback returns **false**, the processing result of the dialog box is regarded as cancel.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onConfirm((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              this.uiContext.showAlertDialog({
                title: 'onConfirm',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onConfirm Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let x;
        let r = confirm("click button!");
        if (r == true) {
          x = "ok";
        } else {
          x = "cancel";
        }
        document.getElementById("demo").innerHTML = x;
      }
    </script>
  </body>
  </html>
  ```

## onPrompt<sup>9+</sup>

onPrompt(callback: Callback\<OnPromptEvent, boolean\>)

Triggered when **prompt()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                 | Mandatory  | Description           |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnPromptEvent](./arkts-basic-components-web-i.md#onpromptevent12), boolean\>                | Yes   | Callback used when **prompt()** is invoked by the web page.<br>Return value: boolean<br> If the callback returns **true**, the application can use the custom dialog box (allows the confirm, cancel, and input operations) and invoke the **JsResult** API to notify the **Web** component the processing result. If the callback returns **false**, the processing result of the dialog box is regarded as cancel.|

**Example**

  ```ts
  // xxx.ets
  import { CustomContentDialog } from '@kit.ArkUI';
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    @State message: string = 'Hello World';
    @State title: string = 'Hello World';
    @State result: JsResult | null = null;
    promptResult: string = '';
    webviewController: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController = new CustomDialogController({
      builder: CustomContentDialog({
        primaryTitle: this.title,
        contentBuilder: () => {
          this.buildContent();
        },
        buttons: [
          {
            value: 'Cancel',
            buttonStyle: ButtonStyleMode.TEXTUAL,
            action: () => {
              console.info('Callback when the button is clicked');
              this.result?.handleCancel()
            }
          },
          {
            value: 'OK',
            buttonStyle: ButtonStyleMode.TEXTUAL,
            action: () => {
              this.result?.handlePromptConfirm(this.promptResult);
            }
          }
        ],
      }),
      onWillDismiss: () => {
        this.result?.handleCancel();
        this.dialogController.close();
      }
    });

    // Content area of the custom dialog box
    @Builder
    buildContent(): void {
      Column() {
        Text(this.message)
        TextInput()
          .onChange((value) => {
            this.promptResult = value;
          })
          .defaultFocus(true)
      }
      .width('100%')
    }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.webviewController })
          .onPrompt((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              console.log("event.value:" + event.value);
              this.title = "Message from" + event.url + "";
              this.message = event.message;
              this.promptResult = event.value;
              this.result = event.result;
              this.dialogController.open();
            }
            return true;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onPrompt Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let message = prompt("Message info", "Hello World");
        if (message != null && message != "") {
          document.getElementById("demo").innerHTML = message;
        }
      }
    </script>
  </body>
  </html>
  ```

## onConsole

onConsole(callback: Callback\<OnConsoleEvent, boolean\>)

Triggered to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                             | Mandatory  | Description     |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnConsoleEvent](./arkts-basic-components-web-i.md#onconsoleevent12), boolean\> | Yes   | Callback used when the web page receives a JavaScript console message.<br>Return value: boolean<br> The value **true** means that the message will not be printed to HiLog logs, and **false** means the opposite.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Button('onconsole message')
          .onClick(() => {
            this.controller.runJavaScript('myFunction()');
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onConsole((event) => {
            if (event) {
              console.log('getMessage:' + event.message.getMessage());
              console.log('getSourceId:' + event.message.getSourceId());
              console.log('getLineNumber:' + event.message.getLineNumber());
              console.log('getMessageLevel:' + event.message.getMessageLevel());
            }
            return false;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <script>
      function myFunction() {
          console.log("onconsole printf");
      }
  </script>
  </body>
  </html>
  ```

## onDownloadStart

onDownloadStart(callback: Callback\<OnDownloadStartEvent\>)

Triggered to instruct the main application to start downloading a file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name               | Type  | Mandatory  | Description                               |
| ------------------ | ------ | ---- | ----------------------------------- |
| callback           | Callback\<[OnDownloadStartEvent](./arkts-basic-components-web-i.md#ondownloadstartevent12)\> | Yes   | Callback used when a download starts. |

**Example**

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
          .onDownloadStart((event) => {
            if (event) {
              console.log('url:' + event.url)
              console.log('userAgent:' + event.userAgent)
              console.log('contentDisposition:' + event.contentDisposition)
              console.log('contentLength:' + event.contentLength)
              console.log('mimetype:' + event.mimetype)
            }
          })
      }
    }
  }
  ```

## onErrorReceive

onErrorReceive(callback: Callback\<OnErrorReceiveEvent\>)

Triggered when an error occurs during web page loading. The error may occur on the main resource or sub-resource. You can use [isMainFrame](./arkts-basic-components-web-WebResourceRequest.md#ismainframe) to determine whether the error occurs on the main resource. For performance reasons, simplify the implementation logic in the callback. This API is called when there is no network connection.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description           |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | Callback\<[OnErrorReceiveEvent](./arkts-basic-components-web-i.md#onerrorreceiveevent12)\> | Yes   | Callback used when an error occurs during web page loading.     |

**Example**

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
          .onErrorReceive((event) => {
            if (event) {
              console.log('getErrorInfo:' + event.error.getErrorInfo());
              console.log('getErrorCode:' + event.error.getErrorCode());
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

## onHttpErrorReceive

onHttpErrorReceive(callback: Callback\<OnHttpErrorReceiveEvent\>)

Triggered when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type                                    | Mandatory  | Description      |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback  | Callback\<[OnHttpErrorReceiveEvent](./arkts-basic-components-web-i.md#onhttperrorreceiveevent12)\> | Yes   | Triggered when an HTTP error occurs during web page resource loading.|

**Example**

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
          .onHttpErrorReceive((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getResponseData:' + event.response.getResponseData());
              console.log('getResponseEncoding:' + event.response.getResponseEncoding());
              console.log('getResponseMimeType:' + event.response.getResponseMimeType());
              console.log('getResponseCode:' + event.response.getResponseCode());
              console.log('getReasonMessage:' + event.response.getReasonMessage());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
              let resph = event.response.getResponseHeader();
              console.log('The response header result size is ' + resph.length);
              for (let i of resph) {
                console.log('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

## onPageBegin

onPageBegin(callback: Callback\<OnPageBeginEvent\>)

Triggered when the web page starts to be loaded. This callback is called only for the main frame content, and not for the iframe or frameset content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageBeginEvent](./arkts-basic-components-web-i.md#onpagebeginevent12)\> | Yes   | Callback triggered when a web page loading starts.|

**Example**

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
          .onPageBegin((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onPageEnd

onPageEnd(callback: Callback\<OnPageEndEvent\>)

Triggered when the web page loading is complete. This callback is triggered only for the main frame content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageEndEvent](./arkts-basic-components-web-i.md#onpageendevent12)\> | Yes   | Callback used when the web page loading is complete.|

**Example**

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
          .onPageEnd((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onLoadStarted<sup>20+</sup>

onLoadStarted(callback: Callback\<OnLoadStartedEvent\>)

Triggered to notify the host application that the page loading starts. This method is called once each time the main frame content is loaded. Therefore, for pages that contain iframes or frameset, **onLoadStarted** is called only once for the main frame. This means that when the content of the embedded frame changes, for example, a link or a fragment navigation in the iframe is clicked (navigation to **#fragment_id**), **onLoadStarted** is not invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnLoadStartedEvent](./arkts-basic-components-web-i.md#onloadstartedevent20)\> | Yes   | Callback triggered when a web page loading starts.|

**Example**

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
          .onLoadStarted((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onLoadFinished<sup>20+</sup>

onLoadFinished(callback: Callback\<OnLoadFinishedEvent\>)

Triggered to notify the host application that the page has been loaded. This method is called only when the main frame loading is complete. For fragment navigations (navigations to **#fragment_id**), **onLoadFinished** is also triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnLoadFinishedEvent](./arkts-basic-components-web-i.md#onloadfinishedevent20)\> | Yes   | Callback triggered when the web page loading is complete.|

**Example**

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
          .onLoadFinished((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onProgressChange

onProgressChange(callback: Callback\<OnProgressChangeEvent\>)

Triggered when the web page loading progress changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type  | Mandatory  | Description                 |
| ----------- | ------ | ---- | --------------------- |
| callback | Callback\<[OnProgressChangeEvent](./arkts-basic-components-web-i.md#onprogresschangeevent12)\> | Yes   | Callback triggered when the page loading progress changes.|

**Example**

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
          .onProgressChange((event) => {
            if (event) {
              console.log('newProgress:' + event.newProgress);
            }
          })
      }
    }
  }
  ```

## onTitleReceive

onTitleReceive(callback: Callback\<OnTitleReceiveEvent\>)

Triggered to notify the application that the document title of the page is changed. If the **<title\>** element is not set on the page to load, ArkWeb generates a title based on the URL and returns the title to the application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type  | Mandatory  | Description         |
| ----- | ------ | ---- | ------------- |
| callback | Callback\<[OnTitleReceiveEvent](./arkts-basic-components-web-i.md#ontitlereceiveevent12)\> | Yes   | Callback triggered when the document title of the application page is changed.|

**Example**

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
          .onTitleReceive((event) => {
            if (event) {
              console.log('title:' + event.title);
              console.log('isRealTitle:' + event.isRealTitle);
            }
          })
      }
    }
  }
  ```

## onRefreshAccessedHistory

onRefreshAccessedHistory(callback: Callback\<OnRefreshAccessedHistoryEvent\>)

Triggered for the application to update its access history when the web page loading is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name        | Type   | Mandatory  | Description                                    |
| ----------- | ------- | ---- | ---------------------------------------- |
| callback         | Callback\<[OnRefreshAccessedHistoryEvent](./arkts-basic-components-web-i.md#onrefreshaccessedhistoryevent12)\>  | Yes   | Callback triggered when the access history of the web page is refreshed.               |

**Example**

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
          .onRefreshAccessedHistory((event) => {
            if (event) {
              console.log('url:' + event.url + ' isReload:' + event.isRefreshed);
            }
          })
      }
    }
  }
  ```

## onRenderExited<sup>9+</sup>

onRenderExited(callback: Callback\<OnRenderExitedEvent\>)

Triggered when the rendering process exits abnormally.

A rendering process may be shared by multiple **Web** components. Each affected **Web** component triggers this callback.

You can call the bound **webviewController** APIs to restore the web page when this callback is triggered. For example, [refresh](./arkts-apis-webview-WebviewController.md#refresh) and [loadUrl](./arkts-apis-webview-WebviewController.md#loadurl).

For details about the component lifecycle, see [Lifecycle of the Web Components](../../web/web-event-sequence.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type                                    | Mandatory  | Description            |
| ---------------- | ---------------------------------------- | ---- | ---------------- |
| callback | Callback\<[OnRenderExitedEvent](./arkts-basic-components-web-i.md#onrenderexitedevent12)\> | Yes   | Callback triggered when the rendering process exits abnormally.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'chrome://crash/', controller: this.controller })
          .onRenderExited((event) => {
            if (event) {
              console.log('reason:' + event.renderExitReason);
            }
          })
      }
    }
  }
  ```
## onRenderProcessNotResponding<sup>12+</sup>

onRenderProcessNotResponding(callback: OnRenderProcessNotRespondingCallback)

Triggered when the rendering process does not respond. If the **Web** component cannot process the input event or navigate to a new URL within a proper time range, the web page process is considered unresponsive and the callback is triggered.

If the web page process does not respond, this callback may be triggered until the web page process responds again. In this case, [onRenderProcessResponding](#onrenderprocessresponding12) is triggered.

You can terminate the associated rendering process through [terminateRenderProcess](./arkts-apis-webview-WebviewController.md#terminaterenderprocess12), which may affect other **Web** components in the same rendering process.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                                        | Mandatory  | Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessNotRespondingCallback](./arkts-basic-components-web-t.md#onrenderprocessnotrespondingcallback12) | Yes   | Callback triggered when the rendering process does not respond.|

**Example**

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
          .onRenderProcessNotResponding((data) => {
            console.log("onRenderProcessNotResponding: [jsStack]= " + data.jsStack +
              ", [process]=" + data.pid + ", [reason]=" + data.reason);
          })
      }
    }
  }
  ```

## onRenderProcessResponding<sup>12+</sup>

onRenderProcessResponding(callback: OnRenderProcessRespondingCallback)

Triggered when the rendering process transitions back to a normal operating state from an unresponsive state. This callback indicates that the web page was not actually frozen.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                                                        | Mandatory  | Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessRespondingCallback](./arkts-basic-components-web-t.md#onrenderprocessrespondingcallback12) | Yes   | Callback triggered when the rendering process transitions back to a normal operating state from an unresponsive state.|

**Example**

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
          .onRenderProcessResponding(() => {
            console.log("onRenderProcessResponding again");
          })
      }
    }
  }
  ```

## onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: Callback\<OnShowFileSelectorEvent, boolean\>)

Triggered to process an HTML form whose input type is **file**. If this function is not called or returns **false**, the **Web** component provides the default **Select file** UI. If it returns **true**, the application can customize the response behavior for **Select file**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ---- | ----------------- |
| callback       | Callback\<[OnShowFileSelectorEvent](./arkts-basic-components-web-i.md#onshowfileselectorevent12), boolean\> | Yes   | Callback triggered to notify the **Web** component of the file selection result.<br>Return value: boolean<br> The value **true** means that you can invoke the system-provided dialog box. The value **false** means that the custom dialog box drawn in the function is ineffective.|

**Example**

1. Start the file selector.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             console.log('MyFileUploader onShowFileSelector invoked')
             const documentSelectOptions = new picker.DocumentSelectOptions();
             let uri: string | null = null;
             const documentViewPicker = new picker.DocumentViewPicker();
             documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
               uri = documentSelectResult[0];
               console.info('documentViewPicker.select to file succeed and uri is:' + uri);
               if (event) {
                 event.result.handleFileList([uri]);
               }
             }).catch((err: BusinessError) => {
               console.error(`Invoke documentViewPicker.select failed, code is ${err.code},  message is ${err.message}`);
             })
             return true;
           })
       }
     }
   }
   ```

2. Start the photo selector.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     async selectFile(result: FileSelectorResult): Promise<void> {
       let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
       let photoPicker = new photoAccessHelper.PhotoViewPicker();
       // Set the mime file type to IMAGE_VIDEO.
       photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
       // Set the maximum number of media files that can be selected.
       photoSelectOptions.maxSelectNumber = 5;
       let chooseFile: photoAccessHelper.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
       // Obtain the list of selected files.
       result.handleFileList(chooseFile.photoUris);
     }

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             if (event) {
               this.selectFile(event.result);
             }
             return true;
           })
       }
     }
   }
   ```

3. Start the camera picker.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { cameraPicker, camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';

   async function openCamera(callback: Callback<string>, uiContext: UIContext) {
    let mContext = uiContext.getHostContext() as common.Context;
     try {
       let pickerProfile: cameraPicker.PickerProfile = {
         cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK
       };
       let pickerResult: cameraPicker.PickerResult = await cameraPicker.pick(mContext,
         [cameraPicker.PickerMediaType.PHOTO, cameraPicker.PickerMediaType.VIDEO], pickerProfile);
       callback(pickerResult.resultUri);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`the pick call failed. error code: ${err.code}`);
     }
   }

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             openCamera((result) => {
               if (event) {
                 console.log('Title is ' + event.fileSelector.getTitle());
                 console.log('Mode is ' + event.fileSelector.getMode());
                 console.log('Accept types are ' + event.fileSelector.getAcceptType());
                 console.log('Capture is ' + event.fileSelector.isCapture());
                 console.log('Mime types are ' + event.fileSelector.getMimeTypes());
                 event.result.handleFileList([result]);
               }
             }, this.getUIContext())
             return true;
           })
       }
     }
   }
   ```

   HTML file to be loaded:
   ```html
   <!DOCTYPE html>
   <html>
   <head>
     <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
   </head>
   <body>
     <form id="upload-form" enctype="multipart/form-data">
       <input type="file" id="upload" name="upload" accept="image/*, video/*"/>
       </form>
   </body>
   </html>
   ```

## onResourceLoad<sup>9+</sup>

onResourceLoad(callback: Callback\<OnResourceLoadEvent\>)

Triggered to notify the **Web** component of the URL of the resource file to load.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnResourceLoadEvent](./arkts-basic-components-web-i.md#onresourceloadevent12)\> | Yes| Callback triggered when a URL is loaded.|

**Example**

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
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url);
          })
      }
    }
  }
  ```

## onScaleChange<sup>9+</sup>

onScaleChange(callback: Callback\<OnScaleChangeEvent\>)

Triggered when the display scale of this page changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScaleChangeEvent](./arkts-basic-components-web-i.md#onscalechangeevent12)\> | Yes| Callback invoked when the display scale of the page changes.|

**Example**

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
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale);
          })
      }
    }
  }
  ```

## onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: Callback<OnInterceptRequestEvent, WebResourceResponse>)

Triggered when the **Web** component is about to access a URL. This API is used to block the URL and return the response data. This API can intercept all URLs, which needs to be determined based on specific services.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnInterceptRequestEvent](./arkts-basic-components-web-i.md#oninterceptrequestevent12), [WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md)\> | Yes| Callback invoked when the **Web** component is about to load a URL.<br>The return value is [WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md). If response data is returned, the data is loaded based on the response data. If no response data is returned, null is returned, indicating that the data is loaded in the original mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    responseWeb: WebResourceResponse = new WebResourceResponse();
    heads: Header[] = new Array();
    webData: string = "<!DOCTYPE html>\n" +
      "<html>\n" +
      "<head>\n" +
      "<title>intercept test</title>\n" +
      "</head>\n" +
      "<body>\n" +
      "<h1>intercept test</h1>\n" +
      "</body>\n" +
      "</html>";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
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
            const promise: Promise<String> = new Promise((resolve: Function, reject: Function) => {
              this.responseWeb.setResponseHeader(this.heads);
              this.responseWeb.setResponseData(this.webData);
              this.responseWeb.setResponseEncoding('utf-8');
              this.responseWeb.setResponseMimeType('text/html');
              this.responseWeb.setResponseCode(200);
              this.responseWeb.setReasonMessage('OK');
              resolve("success");
            })
            promise.then(() => {
              console.log("prepare response ready");
              this.responseWeb.setResponseIsReady(true);
            })
            this.responseWeb.setResponseIsReady(false);
            return this.responseWeb;
          })
      }
    }
  }
  ```

## onHttpAuthRequest<sup>9+</sup>

onHttpAuthRequest(callback: Callback\<OnHttpAuthRequestEvent, boolean\>)

Triggered when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnHttpAuthRequestEvent](./arkts-basic-components-web-i.md#onhttpauthrequestevent12), boolean\> | Yes| Callback invoked when the browser requires user credentials.<br>Return value: boolean<br> The value **true** means that the HTTP authentication is successful, and **false** means the opposite.  |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();
    httpAuth: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpAuthRequest((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
                title: 'onHttpAuthRequest',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.handler.cancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    this.httpAuth = event.handler.isHttpAuthInfoSaved();
                    if (this.httpAuth == false) {
                      webview.WebDataBase.saveHttpAuthCredentials(
                        event.host,
                        event.realm,
                        "2222",
                        "2222"
                      )
                      event.handler.cancel();
                    }
                  }
                },
                cancel: () => {
                  event.handler.cancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```
## onSslErrorEventReceive<sup>9+</sup>

onSslErrorEventReceive(callback: Callback\<OnSslErrorEventReceiveEvent\>)

Triggered to notify the host application when an SSL error occurs while loading the main-frame resource.
To support errors for loading subframe resources, use the [OnSslErrorEvent](./arkts-basic-components-web-events.md#onsslerrorevent12) API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSslErrorEventReceiveEvent](./arkts-basic-components-web-i.md#onsslerroreventreceiveevent12)\> | Yes| Callback invoked when the web page receives an SSL error.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { cert } from '@kit.DeviceCertificateKit';
  
  function LogCertInfo(certChainData : Array<Uint8Array> | undefined) {
    if (!(certChainData instanceof Array)) {
      console.log('failed, cert chain data type is not array');
      return;
    }

    for (let i = 0; i < certChainData.length; i++) {
      let encodeBlobData: cert.EncodingBlob = {
        data: certChainData[i],
        encodingFormat: cert.EncodingFormat.FORMAT_DER
      }
      cert.createX509Cert(encodeBlobData, (error, x509Cert) => {
        if (error) {
          console.error('Index : ' + i + ',createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('createX509Cert success');
          console.log(ParseX509CertInfo(x509Cert));
        }
      });
    }
    return;
  }
  
  function Uint8ArrayToString(dataArray: Uint8Array) {
    let dataString = '';
    for (let i = 0; i < dataArray.length; i++) {
      dataString += String.fromCharCode(dataArray[i]);
    }
    return dataString;
  }

  function ParseX509CertInfo(x509Cert: cert.X509Cert) {
    let res: string = 'getCertificate success, '
      + 'issuer name = '
      + Uint8ArrayToString(x509Cert.getIssuerName().data) + ', subject name = '
      + Uint8ArrayToString(x509Cert.getSubjectName().data) + ', valid start = '
      + x509Cert.getNotBeforeTime()
      + ', valid end = ' + x509Cert.getNotAfterTime();
    return res;
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSslErrorEventReceive((event) => {
            LogCertInfo(event.certChainData);
            this.uiContext.showAlertDialog({
              title: 'onSslErrorEventReceive',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel();
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

## onSslErrorEvent<sup>12+</sup>

onSslErrorEvent(callback: OnSslErrorEventCallback)

Triggered to notify users when an SSL error occurs during the loading of main-frame or subframe resources. To handle SSL errors for loading the main-frame resources, use the [isMainFrame](./arkts-basic-components-web-WebResourceRequest.md#ismainframe) field to distinguish.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnSslErrorEventCallback](./arkts-basic-components-web-t.md#onsslerroreventcallback12) | Yes| Callback invoked when an SSL error occurs during resource loading.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { cert } from '@kit.DeviceCertificateKit';

  function LogCertInfo(certChainData : Array<Uint8Array> | undefined) {
    if (!(certChainData instanceof Array)) {
      console.log('failed, cert chain data type is not array');
      return;
    }

    for (let i = 0; i < certChainData.length; i++) {
      let encodeBlobData: cert.EncodingBlob = {
        data: certChainData[i],
        encodingFormat: cert.EncodingFormat.FORMAT_DER
      }
      cert.createX509Cert(encodeBlobData, (error, x509Cert) => {
        if (error) {
          console.error('Index : ' + i + ',createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('createX509Cert success');
          console.log(ParseX509CertInfo(x509Cert));
        }
      });
    }
    return;
  }

  function Uint8ArrayToString(dataArray: Uint8Array) {
    let dataString = '';
    for (let i = 0; i < dataArray.length; i++) {
      dataString += String.fromCharCode(dataArray[i]);
    }
    return dataString;
  }

  function ParseX509CertInfo(x509Cert: cert.X509Cert) {
    let res: string = 'getCertificate success, '
      + 'issuer name = '
      + Uint8ArrayToString(x509Cert.getIssuerName().data) + ', subject name = '
      + Uint8ArrayToString(x509Cert.getSubjectName().data) + ', valid start = '
      + x509Cert.getNotBeforeTime()
      + ', valid end = ' + x509Cert.getNotAfterTime();
    return res;
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSslErrorEvent((event: SslErrorEvent) => {
            console.log("onSslErrorEvent url: " + event.url);
            console.log("onSslErrorEvent error: " + event.error);
            console.log("onSslErrorEvent originalUrl: " + event.originalUrl);
            console.log("onSslErrorEvent referrer: " + event.referrer);
            console.log("onSslErrorEvent isFatalError: " + event.isFatalError);
            console.log("onSslErrorEvent isMainFrame: " + event.isMainFrame);
            LogCertInfo(event.certChainData);
            this.uiContext.showAlertDialog({
              title: 'onSslErrorEvent',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  // The value true indicates that the page loading is stopped and the current page is displayed. The value false indicates that the page loading is continued and an error page is displayed.
                  event.handler.handleCancel(true);
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

## onClientAuthenticationRequest<sup>9+</sup>

onClientAuthenticationRequest(callback: Callback\<OnClientAuthenticationEvent\>)

Triggered when an SSL client certificate request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnClientAuthenticationEvent](./arkts-basic-components-web-i.md#onclientauthenticationevent12)\> | Yes| Callback invoked when an SSL client certificate is required. |

  **Example**

  This example shows two-way authentication when interconnection with certificate management is not supported.

  ```ts
  // xxx.ets API9
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onClientAuthenticationRequest((event) => {
            this.uiContext.showAlertDialog({
              title: 'onClientAuthenticationRequest',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.confirm("/system/etc/user.pk8", "/system/etc/chain-user.pem");
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel();
                }
              },
              cancel: () => {
                event.handler.ignore();
              }
            })
          })
      }
    }
  }
  ```

  This example shows two-way authentication when interconnection with certificate management is supported.

  1. Construct a singleton object **GlobalContext**.

     ```ts
     // GlobalContext.ets
     export class GlobalContext {
       private constructor() {}
       private static instance: GlobalContext;
       private _objects = new Map<string, Object>();

       public static getContext(): GlobalContext {
         if (!GlobalContext.instance) {
           GlobalContext.instance = new GlobalContext();
         }
         return GlobalContext.instance;
       }

       getObject(value: string): Object | undefined {
         return this._objects.get(value);
       }

       setObject(key: string, objectClass: Object): void {
         this._objects.set(key, objectClass);
       }
     }
     ```


  2. Implement two-way authentication.

     ```ts
     // xxx.ets API10
     import { webview } from '@kit.ArkWeb';
     import { common, Want, bundleManager } from '@kit.AbilityKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { GlobalContext } from '../GlobalContext';

     let uri = "";

     export default class CertManagerService {
       private static sInstance: CertManagerService;
       private authUri = "";
       private appUid = "";

       public static getInstance(): CertManagerService {
         if (CertManagerService.sInstance == null) {
           CertManagerService.sInstance = new CertManagerService();
         }
         return CertManagerService.sInstance;
       }

       async grantAppPm(callback: (message: string) => void) {
         let message = '';
         let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION;
         // Note: Replace com.example.myapplication with the actual application name.
         try {
           bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
             console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
            this.appUid = data.appInfo.uid.toString();
           }).catch((err: BusinessError) => {
             console.error('getBundleInfoForSelf failed. Cause: %{public}s', err.message);
           });
         } catch (err) {
           let message = (err as BusinessError).message;
           console.error('getBundleInfoForSelf failed: %{public}s', message);
         }

         // Note: Add GlobalContext.getContext().setObject("AbilityContext", this.context) to the onCreate function in the MainAbility.ts file.
         let abilityContext = GlobalContext.getContext().getObject("AbilityContext") as common.UIAbilityContext
         await abilityContext.startAbilityForResult(
           {
             bundleName: "com.ohos.certmanager",
             abilityName: "MainAbility",
             uri: "requestAuthorize",
             parameters: {
               appUid: this.appUid, // Pass the UID of the requesting application.
             }
           } as Want)
           .then((data: common.AbilityResult) => {
             if (!data.resultCode && data.want) {
               if (data.want.parameters) {
                 this.authUri = data.want.parameters.authUri as string; // Obtain the returned authUri after successful authorization.
               }
             }
           })
         message += "after grantAppPm authUri: " + this.authUri;
         uri = this.authUri;
         callback(message)
       }
     }

     @Entry
     @Component
     struct WebComponent {
       controller: webview.WebviewController = new webview.WebviewController();
       @State message: string = 'Hello World' // message is used for debugging and observation.
       certManager = CertManagerService.getInstance();
       uiContext: UIContext = this.getUIContext();

       build() {
         Row() {
           Column() {
             Row() {
               // Step 1: Perform authorization to obtain the URI.
               Button('GrantApp')
                 .onClick(() => {
                   this.certManager.grantAppPm((data) => {
                     this.message = data;
                   });
                 })
               // Step 2: After the authorization, in two-way authentication, the onClientAuthenticationRequest callback is used to send the URI to the web server for authentication.
               Button("ClientCertAuth")
                 .onClick(() => {
                   this.controller.loadUrl('https://www.example2.com'); // Server website that supports two-way authentication.
                 })
             }

             Web({ src: 'https://www.example1.com', controller: this.controller })
               .fileAccess(true)
               .javaScriptAccess(true)
               .domStorageAccess(true)
               .onlineImageAccess(true)

               .onClientAuthenticationRequest((event) => {
                 this.uiContext.showAlertDialog({
                   title: 'ClientAuth',
                   message: 'Text',
                   confirm: {
                     value: 'Confirm',
                     action: () => {
                       event.handler.confirm(uri);
                     }
                   },
                   cancel: () => {
                     event.handler.cancel();
                   }
                 })
               })
           }
         }
         .width('100%')
         .height('100%')
       }
     }
     ```

## onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: Callback\<OnPermissionRequestEvent\>)

Triggered when a permission request is received. To call this API, you need to declare the **ohos.permission.CAMERA** and **ohos.permission.MICROPHONE** permissions.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnPermissionRequestEvent](./arkts-basic-components-web-i.md#onpermissionrequestevent12)\> | Yes| Callback invoked when a permission request is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl } from '@kit.AbilityKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(this.uiContext.getHostContext(), ['ohos.permission.CAMERA', 'ohos.permission.MICROPHONE'])
        .then((data) => {
          console.info('data:' + JSON.stringify(data));
          console.info('data permissions:' + data.permissions);
          console.info('data authResults:' + data.authResults);
        }).catch((error: BusinessError) => {
        console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
      })
    }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onPermissionRequest((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
                title: 'title',
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.request.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.request.grant(event.request.getAccessibleResource());
                  }
                },
                cancel: () => {
                  event.request.deny();
                }
              })
            }
          })
      }
    }
  }
  ```

  HTML file to be loaded:
 ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
  <video id="video" width="500px" height="500px" autoplay="autoplay"></video>
  <canvas id="canvas" width="500px" height="500px"></canvas>
  <br>
  <input type="button" title="HTML5 Camera" value="Enable Camera" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // Obtain the video camera area.
      let video = document.getElementById("video");
      // Returned Promise object.
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then() is asynchronous. Invoke the MediaStream object as a parameter.
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      });
    }
  </script>
  </body>
  </html>
 ```

## onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: Callback\<OnContextMenuShowEvent, boolean\>)

Triggered when a context menu is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnContextMenuShowEvent](./arkts-basic-components-web-i.md#oncontextmenushowevent12), boolean\> | Yes| Callback invoked during a call to allow for the display of a custom context menu.<br>Return value: boolean<br> The value **true** means that a custom menu is triggered, and **false** means that the custom menu is ineffective.    |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { pasteboard } from '@kit.BasicServicesKit';

  const TAG = 'ContextMenu';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    private result: WebContextMenuResult | undefined = undefined;
    @State linkUrl: string = '';
    @State offsetX: number = 0;
    @State offsetY: number = 0;
    @State showMenu: boolean = false;
    uiContext: UIContext = this.getUIContext();

    @Builder
    // Build and trigger a custom menu.
    MenuBuilder() {
      // A component that is used to present a vertical list of items to the user.
      Menu() {
        // A component that is used to represent an item in a menu.
        MenuItem({
          content: 'Cancel',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.undo();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Redo',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.redo();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Paste as plain text',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.pasteAndMatchStyle();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Copy image',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copyImage();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Cut',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.cut();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Copy',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copy();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Paste',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.paste();
            this.showMenu = false;
          })
        MenuItem({
          content: 'Copy link',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            let pasteData = pasteboard.createData('text/plain', this.linkUrl);
            pasteboard.getSystemPasteboard().setData(pasteData, (error) => {
              if (error) {
                return;
              }
            })
            this.showMenu = false;
          })
        MenuItem({
          content: 'Select all',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.selectAll();
            this.showMenu = false;
          })
      }
      .width(150)
      .height(450)
    }

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          // Trigger a custom dialog box.
          .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result
              console.info("x coord = " + event.param.x());
              console.info("link url = " + event.param.getLinkUrl());
              this.linkUrl = event.param.getLinkUrl();
            }
            console.info(TAG, `x: ${this.offsetX}, y: ${this.offsetY}`);
            this.showMenu = true;
            this.offsetX = 0;
            this.offsetY = Math.max(this.uiContext!.px2vp(event?.param.y() ?? 0) - 0, 0);
            return true;
          })
          .bindPopup(this.showMenu,
            {
              builder: this.MenuBuilder(),
              enableArrow: false,
              placement: Placement.LeftTop,
              offset: { x: this.offsetX, y: this.offsetY },
              mask: false,
              onStateChange: (e) => {
                if (!e.isVisible) {
                  this.showMenu = false;
                  this.result!.closeContextMenu();
                }
              }
            })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html lang="en">
  <body>
    <h1>onContextMenuShow</h1>
    <a href="http://www.example.com" style="font-size:27px">URL www.example.com</a>
    <!-- Place any image in the rawfile directory and name it example.png. -->
    <div><img src="example.png"></div>
    <p>Right-click text to display the context menu</p>
  </body>
  </html>
  ```

## onContextMenuHide<sup>11+</sup>

onContextMenuHide(callback: OnContextMenuHideCallback)

Triggered when a context menu is hidden after the user clicks the right mouse button or long presses a specific element, such as an image or a link.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnContextMenuHideCallback](./arkts-basic-components-web-t.md#oncontextmenuhidecallback11) | Yes| Callback related to menus.    |

**Example**

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
          .onContextMenuHide(() => {
            console.log("onContextMenuHide callback");
          })
      }
    }
  }
  ```

## onScroll<sup>9+</sup>

onScroll(callback: Callback\<OnScrollEvent\>)

Triggered to notify the global scrolling position of the web page.

> **NOTE**
>
> The change of the partial scrolling position cannot trigger this callback.
>
> To determine whether a page is globally scrolled, print **window.pagYOffset** or **window.pagXOffset** before and after scrolling.
>
> If the web page is scrolled globally, the value of **window.pagYOffset** or **window.pagXOffset** changes after the web page is scrolled. Otherwise, the value does not change.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScrollEvent](./arkts-basic-components-web-i.md#onscrollevent12)\> | Yes| Callback invoked when the scrollbar scrolls to a specified position.|

**Example**

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
          .onScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

## onGeolocationShow

onGeolocationShow(callback: Callback\<OnGeolocationShowEvent\>)

Triggered to notify the application when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback      | Callback\<[OnGeolocationShowEvent](./arkts-basic-components-web-i.md#ongeolocationshowevent12)\>  | Yes| Callback invoked when a request to obtain the geolocation information is received.    |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
                title: 'title',
                message: 'text',
                confirm: {
                  value: 'onConfirm',
                  action: () => {
                    event.geolocation.invoke(event.origin, true, true);
                  }
                },
                cancel: () => {
                  event.geolocation.invoke(event.origin, false, true);
                }
              })
            }
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!DOCTYPE html>
  <html>
  <body>
  <p id="locationInfo">Location information</p>
  <button onclick="getLocation()">Obtain location</button>
  <script>
  var locationInfo=document.getElementById("locationInfo");
  function getLocation(){
    if (navigator.geolocation) {
      <!-- Access the device location on the frontend page -->
      navigator.geolocation.getCurrentPosition(showPosition);
    }
  }
  function showPosition(position){
    locationInfo.innerHTML="Latitude: " + position.coords.latitude + "<br />Longitude: " + position.coords.longitude;
  }
  </script>
  </body>
  </html>
  ```

## onGeolocationHide

onGeolocationHide(callback: () => void)

Triggered to notify the user that the request for obtaining the geolocation information received when [onGeolocationShow](#ongeolocationshow) is called has been canceled.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the request for obtaining geolocation information has been canceled. |

**Example**

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
          .geolocationAccess(true)
          .onGeolocationHide(() => {
            console.log("onGeolocationHide...");
          })
      }
    }
  }
  ```

## onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: OnFullScreenEnterCallback)

Triggered when the **Web** component enters full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFullScreenEnterCallback](./arkts-basic-components-web-t.md#onfullscreenentercallback12) | Yes| Callback invoked when the **Web** component enters full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenEnter((event) => {
            console.log("onFullScreenEnter videoWidth: " + event.videoWidth +
              ", videoHeight: " + event.videoHeight);
            // The application can proactively exit fullscreen mode by calling this.handler.exitFullScreen().
            this.handler = event.handler;
          })
      }
    }
  }
  ```

## onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

Triggered when the **Web** component exits full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the component exits full screen mode.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenExit(() => {
            console.log("onFullScreenExit...")
            if (this.handler) {
              this.handler.exitFullScreen();
            }
          })
          .onFullScreenEnter((event) => {
            this.handler = event.handler;
          })
      }
    }
  }
  ```

## onWindowNew<sup>9+</sup>

onWindowNew(callback: Callback\<OnWindowNewEvent\>)

Triggered to notify the user of a new window creation request, when **multiWindowAccess** is enabled.
If the [setWebController](./arkts-basic-components-web-ControllerHandler.md#setwebcontroller9) API is not called, the render process will be blocked.
If no new window is created, set this parameter to **null** when invoking the [setWebController](./arkts-basic-components-web-ControllerHandler.md#setwebcontroller9) API to notify the **Web** component that no new window is created.

The new window cannot be directly overlaid on the original **Web** component, and its URL (for example, address bar) must be clearly displayed in the same way as the main page to prevent confusion. If visible management of trusted URLs cannot be implemented, consider prohibiting the creation of new windows.
Note that the source of a new window request cannot be reliably traced. The request may be initiated by a third-party iframe. By default, the application needs to take defense measures such as sandbox isolation and permission restriction to ensure security.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | Callback\<[OnWindowNewEvent](./arkts-basic-components-web-i.md#onwindownewevent12)\>           | Yes| Callback invoked when the web page requests the user to create a window.   |

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // There are two Web components on the same page. When the WebComponent object opens a new window, the NewWebViewComp object is displayed.
  @CustomDialog
  struct NewWebViewComp {
    controller?: CustomDialogController;
    webviewController1: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: "www.example.com", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            console.info("NewWebViewComp onWindowExit");
            if (this.controller) {
              this.controller.close();
            }
          })
      }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController | null = null;

    build() {
      Column() {
        Web({ src: $rawfile("window.html"), controller: this.controller })
          .javaScriptAccess(true)
          // MultiWindowAccess needs to be enabled.
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close();
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController })
            })
            this.dialogController.open();
            // Return the WebviewController object corresponding to the new window to the web kernel.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            // If no new window is created, set the value of event.handler.setWebController to null to notify the Web component that no new window is created.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

  ```html
  <!-- Code of the window.html page -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
  <a href="#" onclick="openNewWindow('https://www.example.com')">Open a new page</a>
  <script type="text/javascript">
      function openNewWindow(url) {
        window.open(url, 'example');
        return false;
      }
  </script>
  </body>
  </html>
  ```

## onActivateContent<sup>20+</sup>

onActivateContent(callback: Callback\<void>)

Triggered to notify the application of displaying the bound **Web** instance to the frontend. Whether a bound **Web** instance exists is checked based on the name when a web page **triggers window.open(url, name)**. If a bound **Web** instance does not exist, [onWindowNew](#onwindownew9) is triggered to notify the application of creating a new **Web** instance. 

> **NOTE**
>
> - Binding a **Web** instance by name: Call the **event.handler.setWebController** method in the [onWindowNew] (#onwindownew9) callback and transfer the controller of the new **Web** instance.
> - The name must comply with the regular expression **[a-zA-Z0-9_]+**. When the name is used as the value of the **target** attribute of the \<a> or \<form> tag, the bound **Web** instance also triggers this callback function.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type            | Mandatory| Description                             |
| ------------- | ---------------- | ---- | --------------------------------- |
| callback | Callback\<void> | Yes  | Callback triggered on a new page after **window.open** is triggered on the original page.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // There are two Web components on the same page. When the WebComponent object opens a new window, the NewWebViewComp object is displayed.
  @CustomDialog
  struct NewWebViewComp {
    controller?: CustomDialogController;
    webviewController1: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: "https://www.example.com", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            if (this.controller) {
              this.controller.close();
            }
          })
          .onActivateContent(() => {
            //The Web component needs to be displayed in the front. It is recommended that the application switch between tabs or windows to display the Web component.
            console.log("NewWebViewComp onActivateContent")
          })
      }.height("50%")
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController | null = null;

    build() {
      Column() {
        Web({ src: $rawfile("window.html"), controller: this.controller })
          .javaScriptAccess(true)
          .allowWindowOpenMethod(true)
          // MultiWindowAccess needs to be enabled.
          .multiWindowAccess(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController }),
              isModal: false
            })
            this.dialogController.open();
            // Return the WebviewController object corresponding to the new window to the web kernel.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

  ```html
  <!-- Code of the window.html page -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>ActivateContentEvent</title>
  </head>
  <body>
  <a href="#" onclick="openNewWindow('https://www.example.com')">Open a new page</a>
  <script type="text/javascript">
      function openNewWindow(url) {
        window.open(url, 'example');
        return false;
      }
  </script>
  </body>
  </html>
  ```

## onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

Triggered when this window is closed. This API works in the same way as [onWindowNew](#onwindownew9). For security, applications should notify users that the pages they interact with are closed.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the window is closed.|

**Example**

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
          .onWindowExit(() => {
            console.log("onWindowExit...");
          })
      }
    }
  }
  ```

## onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: Callback\<OnSearchResultReceiveEvent\>)

Triggered to notify the caller of the search result on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSearchResultReceiveEvent](./arkts-basic-components-web-i.md#onsearchresultreceiveevent12)\>  | Yes| Callback invoked to notify the caller of the search result on the web page.        |

**Example**

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
          .onSearchResultReceive(ret => {
            if (ret) {
              console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
                "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
            }
          })
      }
    }
  }
  ```

## onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: Callback\<OnDataResubmittedEvent\>)

Triggered when the web form data can be resubmitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnDataResubmittedEvent](./arkts-basic-components-web-i.md#ondataresubmittedevent12)\> | Yes| Callback invoked when the web form data can be resubmitted.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // After you click Submit on the web page, you can click Refresh to trigger the function again.
        Button('refresh')
          .onClick(() => {
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
          })
      }
    }
  }
  ```

 HTML file to be loaded:
 ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    <form action="http://httpbin.org/post" method="post">
      <input type="text" name="username">
      <input type="submit" name="Submit">
    </form>
  </body>
  </html>
 ```

## onPageVisible<sup>9+</sup>

onPageVisible(callback: Callback\<OnPageVisibleEvent\>)

Triggered when the old page is not displayed and the new page is about to be visible.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnPageVisibleEvent](./arkts-basic-components-web-i.md#onpagevisibleevent12)\> | Yes| Callback invoked when the old page is not displayed and the new page is about to be visible.|

**Example**

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
          .onPageVisible((event) => {
            console.log('onPageVisible url:' + event.url);
          })
      }
    }
  }
  ```

## onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

Triggered when the key event is intercepted and before it is consumed by the webview.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | (event:[KeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent)) => boolean| Yes| Key event that is triggered.<br>The return value is of the Boolean type. The value **true** means to pass the **KeyEvent** to the web kernel, and **false** means the opposite.|

**Example**

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
          .onInterceptKeyEvent((event) => {
            if (event.keyCode == 2017 || event.keyCode == 2018) {
              console.info(`onInterceptKeyEvent get event.keyCode ${event.keyCode}`);
              return true;
            }
            return false;
          })
      }
    }
  }
  ```

## onTouchIconUrlReceived<sup>9+</sup>

onTouchIconUrlReceived(callback: Callback\<OnTouchIconUrlReceivedEvent\>)

Triggered when an apple-touch-icon URL is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnTouchIconUrlReceivedEvent](./arkts-basic-components-web-i.md#ontouchiconurlreceivedevent12)\>  | Yes| Callback invoked when an apple-touch-icon URL is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.baidu.com', controller: this.controller })
          .onTouchIconUrlReceived((event) => {
            console.log('onTouchIconUrlReceived:' + JSON.stringify(event));
          })
      }
    }
  }
  ```

## onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: Callback\<OnFaviconReceivedEvent\>)

Triggered when this web page receives a new favicon.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnFaviconReceivedEvent](./arkts-basic-components-web-i.md#onfaviconreceivedevent12)\> | Yes| Callback invoked when the current web page receives a new favicon.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { image } from '@kit.ImageKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State icon: image.PixelMap | undefined = undefined;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFaviconReceived((event) => {
            console.log('onFaviconReceived');
            this.icon = event.favicon;
          })
      }
    }
  }
  ```

## onAudioStateChanged<sup>10+</sup>

onAudioStateChanged(callback: Callback\<OnAudioStateChangedEvent\>)

Triggered when the audio playback status on the web page changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnAudioStateChangedEvent](./arkts-basic-components-web-i.md#onaudiostatechangedevent12)\> | Yes| Callback invoked when the audio playback status on the web page changes.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State playing: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onAudioStateChanged(event => {
            this.playing = event.playing;
            console.debug('onAudioStateChanged playing: ' + this.playing);
          })
      }
    }
  }
  ```

## onFirstContentfulPaint<sup>10+</sup>

 onFirstContentfulPaint(callback: Callback\<OnFirstContentfulPaintEvent\>)

Triggered when the first content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback    | Callback\<[OnFirstContentfulPaintEvent](./arkts-basic-components-web-i.md#onfirstcontentfulpaintevent12)\> | Yes| Callback invoked when the first content paint occurs on the web page.         |

**Example**

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
          .onFirstContentfulPaint(event => {
            if (event) {
              console.log("onFirstContentfulPaint:" + "[navigationStartTick]:" +
              event.navigationStartTick + ", [firstContentfulPaintMs]:" +
              event.firstContentfulPaintMs);
            }
          })
      }
    }
  }
  ```

## onFirstMeaningfulPaint<sup>12+</sup>

onFirstMeaningfulPaint(callback: [OnFirstMeaningfulPaintCallback](./arkts-basic-components-web-t.md#onfirstmeaningfulpaintcallback12))

Triggered when the first meaningful paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFirstMeaningfulPaintCallback](./arkts-basic-components-web-t.md#onfirstmeaningfulpaintcallback12) | Yes| Callback invoked when the First Meaningful Paint occurs on the web page.|

**Example**

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
          .onFirstMeaningfulPaint((details) => {
            console.log("onFirstMeaningfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [firstMeaningfulPaintTime]=" + details.firstMeaningfulPaintTime);
          })
      }
    }
  }
  ```

## onLargestContentfulPaint<sup>12+</sup>

onLargestContentfulPaint(callback: [OnLargestContentfulPaintCallback](./arkts-basic-components-web-t.md#onlargestcontentfulpaintcallback12))

Triggered when the largest content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnLargestContentfulPaintCallback](./arkts-basic-components-web-t.md#onlargestcontentfulpaintcallback12) | Yes| Callback invoked when the largest content paint occurs on the web page.|

**Example**

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
          .onLargestContentfulPaint((details) => {
            console.log("onLargestContentfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [largestImagePaintTime]=" + details.largestImagePaintTime +
              ", [largestTextPaintTime]=" + details.largestTextPaintTime +
              ", [largestImageLoadStartTime]=" + details.largestImageLoadStartTime +
              ", [largestImageLoadEndTime]=" + details.largestImageLoadEndTime +
              ", [imageBPP]=" + details.imageBPP);
          })
      }
    }
  }
  ```

## onLoadIntercept<sup>10+</sup>

onLoadIntercept(callback: Callback\<OnLoadInterceptEvent, boolean\>)

Triggered when the **Web** component is about to access a URL. This API is used to determine whether to block the access.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnLoadInterceptEvent](./arkts-basic-components-web-i.md#onloadinterceptevent12), boolean\> | Yes| Callback invoked when the **Web** component is about to access a URL.<br>The return value is of the Boolean type. If **true** is returned, the access is blocked. Otherwise, the access is allowed.<br>Default value: **true**.|

**Example**

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
          .onLoadIntercept((event) => {
            console.log('url:' + event.data.getRequestUrl());
            console.log('isMainFrame:' + event.data.isMainFrame());
            console.log('isRedirect:' + event.data.isRedirect());
            console.log('isRequestGesture:' + event.data.isRequestGesture());
            return true;
          })
      }
    }
  }
  ```

## onRequestSelected

onRequestSelected(callback: () => void)

Triggered when the **Web** component obtains the focus.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback triggered when a web page obtains the focus.|

**Example**

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
          .onRequestSelected(() => {
            console.log('onRequestSelected');
          })
      }
    }
  }
  ```
## onScreenCaptureRequest<sup>10+</sup>

onScreenCaptureRequest(callback: Callback\<OnScreenCaptureRequestEvent\>)

Triggered when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScreenCaptureRequestEvent](./arkts-basic-components-web-i.md#onscreencapturerequestevent12)\> | Yes| Callback invoked when a screen capture request is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onScreenCaptureRequest((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
                title: 'title: ' + event.handler.getOrigin(),
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.handler.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.handler.grant({ captureMode: WebCaptureMode.HOME_SCREEN });
                  }
                },
                cancel: () => {
                  event.handler.deny();
                }
              })
            }
          })
      }
    }
  }
  ```

## onOverScroll<sup>10+</sup>

onOverScroll(callback: Callback\<OnOverScrollEvent\>)

Triggered when the web page is overscrolled. It is used to notify the application of the overscroll offset.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnOverScrollEvent](./arkts-basic-components-web-i.md#onoverscrollevent12)\> | Yes| Callback invoked when the web page is overscrolled.|

**Example**

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
          .onOverScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

## onControllerAttached<sup>10+</sup>

onControllerAttached(callback: () => void)

Triggered when the controller is successfully bound to the **Web** component. The controller must be **WebviewController**. Do not call APIs related to the **Web** component before this callback event. Otherwise, a js-error exception will be thrown.
The web page has not been loaded when the callback is called. Therefore, APIs related to web page operations, such as [zoomIn](./arkts-apis-webview-WebviewController.md#zoomin), [zoomOut](./arkts-apis-webview-WebviewController.md#zoomout), cannot be used in the callback. You can use APIs irrelevant to web page operations, such as [loadUrl](./arkts-apis-webview-WebviewController.md#loadurl), [getWebId](./arkts-apis-webview-WebviewController.md#getwebid).

For details about the component lifecycle, see [Lifecycle of the Web Component](../../web/web-event-sequence.md).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | Yes| Callback invoked when the ArkWeb controller is successfully initialized.|

**Example**

The following example uses **loadUrl** in the callback to load the web page.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: '', controller: this.controller })
          .onControllerAttached(() => {
            this.controller.loadUrl($rawfile("index.html"));
          })
      }
    }
  }
  ```

The following example uses **getWebId** in the callback.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onControllerAttached(() => {
            try {
              let id = this.controller.getWebId();
              console.log("id: " + id);
            } catch (error) {
              let code = (error as BusinessError).code;
              let message = (error as BusinessError).message;
              console.error(`ErrorCode: ${code},  Message: ${message}`);
            }
          })
      }
    }
  }
  ```
  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <body>
          <p>Hello World</p>
      </body>
  </html>
  ```

## onNavigationEntryCommitted<sup>11+</sup>

onNavigationEntryCommitted(callback: [OnNavigationEntryCommittedCallback](./arkts-basic-components-web-t.md#onnavigationentrycommittedcallback11))

Triggered when a web page redirection request is submitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNavigationEntryCommittedCallback](./arkts-basic-components-web-t.md#onnavigationentrycommittedcallback11) | Yes| Callback invoked when a web page redirection request is submitted.|

**Example**

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
          .onNavigationEntryCommitted((details) => {
            console.log("onNavigationEntryCommitted: [isMainFrame]= " + details.isMainFrame +
              ", [isSameDocument]=" + details.isSameDocument +
              ", [didReplaceEntry]=" + details.didReplaceEntry +
              ", [navigationType]=" + details.navigationType +
              ", [url]=" + details.url);
          })
      }
    }
  }
  ```

## onSafeBrowsingCheckResult<sup>11+</sup>

onSafeBrowsingCheckResult(callback: OnSafeBrowsingCheckResultCallback)

Callback invoked when the safe browsing check result is received.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnSafeBrowsingCheckResultCallback](./arkts-basic-components-web-t.md#onsafebrowsingcheckresultcallback11) | Yes| Callback invoked when the safe browsing check result is received.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  export enum ThreatType {
    UNKNOWN = -1,
    THREAT_ILLEGAL = 0,
    THREAT_FRAUD = 1,
    THREAT_RISK = 2,
    THREAT_WARNING = 3,
  }

  export class OnSafeBrowsingCheckResultCallback {
    threatType: ThreatType = ThreatType.UNKNOWN;
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSafeBrowsingCheckResult((callback) => {
            let jsonData = JSON.stringify(callback);
            let json: OnSafeBrowsingCheckResultCallback = JSON.parse(jsonData);
            console.log("onSafeBrowsingCheckResult: [threatType]= " + json.threatType);
          })
      }
    }
  }
  ```

## onNativeEmbedLifecycleChange<sup>11+</sup>

onNativeEmbedLifecycleChange(callback: (event: NativeEmbedDataInfo) => void)

Triggered when the lifecycle of the same-layer tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11)) => void | Yes| Callback invoked when the lifecycle of the same-layer tag changes.|

**Example**

```ts
// EntryAbility.ets

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    // Added in API version 12: feature to enable the back/forward cache for same-layer rendering.
    let features = new webview.BackForwardCacheSupportedFeatures();
    features.nativeEmbed = true;
    features.mediaTakeOver = true;
    webview.WebviewController.enableBackForwardCache(features);
    webview.WebviewController.initializeWebEngine();
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    @State embedStatus: string = '';
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Default behavior: Click the button to navigate to a new page, close the index page, and destroy the same-layer tag.
        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking the button navigates to a new page, closes the index page, and puts the same-layer tag into BFCache.
        Button('Destroy')
        .onClick(() => {
          try {
            this.controller.loadUrl("www.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking the button to return to the page causes the same-layer tag to exit BFCache.
        Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // Added in API version 12: When BFCache is enabled for the page that supports same-layer rendering, clicking a button to advance to the next page causes the same-layer tag to enter BFCache.
        Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })


        // Added in API version 12: The web kernel does not allow web pages loaded with non-HTTP and non-HTTPS protocols to enter BFCache.
        // Therefore, to test the ENTER_BFCACHE/LEAVE_BFCACHE states, you need to place the index.html on a web server and load it using the HTTP or HTTPS protocol. Example:
        // Web({ src: "http://xxxx/index.html", controller: this.controller })
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .onNativeEmbedLifecycleChange((event) => {
            // The Create event is triggered when the same-layer tag is detected on the loaded page.
            if (event.status == NativeEmbedStatus.CREATE) {
              this.embedStatus = 'Create';
            }
            // The Update event is triggered when the same-layer tag on the page is moved or scaled.
            if (event.status == NativeEmbedStatus.UPDATE) {
              this.embedStatus = 'Update';
            }
            // The Destroy event is triggered when a user exit the page.
            if (event.status == NativeEmbedStatus.DESTROY) {
              this.embedStatus = 'Destroy';
            }
            // The Enter BFCache event is triggered when the page with the same-layer tag enters BFCache.
            if (event.status == NativeEmbedStatus.ENTER_BFCACHE) {
              this.embedStatus = 'Enter BFCache';
            }
            // The Leave BFCache event is triggered when the page with the same-layer tag leaves BFCache.
            if (event.status == NativeEmbedStatus.LEAVE_BFCACHE) {
              this.embedStatus = 'Leave BFCache';
            }
            console.log("status = " + this.embedStatus);
            console.log("surfaceId = " + event.surfaceId);
            console.log("embedId = " + event.embedId);
            if (event.info) {
              console.log("id = " + event.info.id);
              console.log("type = " + event.info.type);
              console.log("src = " + event.info.src);
              console.log("width = " + event.info.width);
              console.log("height = " + event.info.height);
              console.log("url = " + event.info.url);
            }
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!Document>
  <html>
  <head>
      <title>Same-Layer Rendering Test HTML</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test? params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onNativeEmbedGestureEvent<sup>11+</sup>

onNativeEmbedGestureEvent(callback: (event: NativeEmbedTouchInfo) => void)

Triggered when a finger touches a same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedTouchInfo](./arkts-basic-components-web-i.md#nativeembedtouchinfo11)) => void | Yes| Callback invoked when a finger touches a same-layer tag.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class NodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: NodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State eventType: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: this.uiContext!.px2vp(embed.info?.width),
                  height: this.uiContext!.px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedGestureEvent((event) => {
              if (event && event.touchEvent) {
                if (event.touchEvent.type == TouchType.Down) {
                  this.eventType = 'Down'
                }
                if (event.touchEvent.type == TouchType.Up) {
                  this.eventType = 'Up'
                }
                if (event.touchEvent.type == TouchType.Move) {
                  this.eventType = 'Move'
                }
                if (event.touchEvent.type == TouchType.Cancel) {
                  this.eventType = 'Cancel'
                }
                let ret = this.nodeController.postEvent(event.touchEvent)
                if (event.result) {
                  event.result.setGestureEventResult(ret, true);
                }
                console.log("embedId = " + event.embedId);
                console.log("touchType = " + this.eventType);
                console.log("x = " + event.touchEvent.touches[0].x);
                console.log("y = " + event.touchEvent.touches[0].y);
                console.log("Component globalPos:(" + event.touchEvent.target.area.globalPosition.x + "," + event.touchEvent.target.area.globalPosition.y + ")");
                console.log("width = " + event.touchEvent.target.area.width);
                console.log("height = " + event.touchEvent.target.area.height);
              }
            })
        }
      }
    }
  }
  ```
HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!Document>
  <html>
  <head>
      <title>Same-Layer Rendering Test HTML</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
         <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onIntelligentTrackingPreventionResult<sup>12+</sup>

onIntelligentTrackingPreventionResult(callback: OnIntelligentTrackingPreventionCallback)

Triggered when the intelligent tracking prevention feature is enabled and the tracker cookie is blocked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback    | [OnIntelligentTrackingPreventionCallback](./arkts-basic-components-web-t.md#onintelligenttrackingpreventioncallback12) | Yes| Callback invoked when the intelligent tracking prevention feature is enabled and the tracker cookie is blocked.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // The onIntelligentTrackingPreventionResult callback is triggered only when the intelligent tracking prevention feature is enabled.
        Button('enableIntelligentTrackingPrevention')
          .onClick(() => {
            try {
              this.controller.enableIntelligentTrackingPrevention(true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .onIntelligentTrackingPreventionResult((details) => {
            console.log("onIntelligentTrackingPreventionResult: [websiteHost]= " + details.host +
              ", [trackerHost]=" + details.trackerHost);
          })
      }
    }
  }
  ```

## onOverrideUrlLoading<sup>12+</sup>

onOverrideUrlLoading(callback: OnOverrideUrlLoadingCallback)

Triggered to enable the host application to obtain control when the URL is about to be loaded to this **Web** component. If the callback returns **true**, the **Web** component stops loading the URL. If the callback returns **false**, the **Web** component continues to load the URL.

POST requests do not trigger this callback.

This callback is triggered when an **iframe** loads the redirection of a non-HTTP(s) protocol, but is not triggered when an **iframe** loads the HTTP(s) protocol or **about:blank** or for the redirection triggered by **loadUrl(String)**.

Do not use the same URL to call the **loadUrl(String)** API and then return **true**. Doing so would unnecessarily cancel the current loading and start a new load with the same URL. The correct way to continue loading the given URL is to simply return **false**, rather than calling **loadUrl(String)**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnOverrideUrlLoadingCallback](./arkts-basic-components-web-t.md#onoverrideurlloadingcallback12) | Yes| Callback for **onOverrideUrlLoading**.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onOverrideUrlLoading((webResourceRequest: WebResourceRequest) => {
            if (webResourceRequest && webResourceRequest.getRequestUrl() == "about:blank") {
              return true;
            }
            return false;
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <title>Test Web Page</title>
  </head>
  <body>
    <h1>onOverrideUrlLoading Demo</h1>
    <a href="about:blank">Click here</a>// to visit about:blank.
  </body>
  </html>
  ```

## onViewportFitChanged<sup>12+</sup>

onViewportFitChanged(callback: OnViewportFitChangedCallback)

Triggered when the **viewport-fit** configuration in the web page's **meta** tag changes. The application can adapt its layout to the viewport within this callback.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [OnViewportFitChangedCallback](./arkts-basic-components-web-t.md#onviewportfitchangedcallback12) | Yes| Callback invoked when the **viewport-fit** configuration in the web page's **meta** tag changes.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onViewportFitChanged((data) => {
            let jsonData = JSON.stringify(data);
            let viewportFit: ViewportFit = JSON.parse(jsonData).viewportFit;
            if (viewportFit === ViewportFit.COVER) {
              // The index.html web page supports immersive layout. You can call expandSafeArea to adjust the Web component layout viewport to cover the safe area (status bar or navigation bar).
            } else if (viewportFit === ViewportFit.CONTAINS) {
              // The index.html web page does not support immersive layout. You can call expandSafeArea to adjust the Web component layout viewport as a safe area.
            } else {
              // Default value. No processing is required.
            }
          })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
    <head>
      <meta name="viewport" content="width=device-width,viewport-fit=cover">
    </head>
    <body>
      <div style="position: absolute; bottom: 0; margin-bottom: env(safe-area-inset-bottom)"></div>
    </body>
  </html>
  ```

## onInterceptKeyboardAttach<sup>12+</sup>

onInterceptKeyboardAttach(callback: WebKeyboardCallback)

Triggered before any editable element (such as the **input** tag) on the web page invokes the soft keyboard. The application can use this API to intercept the display of the system's soft keyboard and configure a custom soft keyboard. (With this API, the application can determine whether to use the system's default soft keyboard, a system soft keyboard with a custom Enter key, or a completely application-defined soft keyboard).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | [WebKeyboardCallback](./arkts-basic-components-web-t.md#webkeyboardcallback12) | Yes| Callback invoked for intercepting the soft keyboard started by the web page.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { inputMethodEngine } from '@kit.IMEKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    webKeyboardController: WebKeyboardController = new WebKeyboardController()
    inputAttributeMap: Map<string, number> = new Map([
        ['UNSPECIFIED', inputMethodEngine.ENTER_KEY_TYPE_UNSPECIFIED],
        ['GO', inputMethodEngine.ENTER_KEY_TYPE_GO],
        ['SEARCH', inputMethodEngine.ENTER_KEY_TYPE_SEARCH],
        ['SEND', inputMethodEngine.ENTER_KEY_TYPE_SEND],
        ['NEXT', inputMethodEngine.ENTER_KEY_TYPE_NEXT],
        ['DONE', inputMethodEngine.ENTER_KEY_TYPE_DONE],
        ['PREVIOUS', inputMethodEngine.ENTER_KEY_TYPE_PREVIOUS]
      ])

      /**
       * Builder for a custom keyboard component.
       */
      @Builder
      customKeyboardBuilder() {
          // Implement a custom keyboard component and connect it to WebKeyboardController to implement operations such as input, deletion, and close.
        Row() {
          Text("Finish")
            .fontSize(20)
            .fontColor(Color.Blue)
            .onClick(() => {
              this.webKeyboardController.close();
            })
          // Insert characters.
          Button("insertText").onClick(() => {
            this.webKeyboardController.insertText('insert ');
          }).margin({
            bottom: 200,
          })
          // Delete characters from the end to the beginning for the length specified by the length parameter.
          Button("deleteForward").onClick(() => {
            this.webKeyboardController.deleteForward(1);
          }).margin({
            bottom: 200,
          })
          // Delete characters from the beginning to the end for the length specified by the length parameter.
          Button("deleteBackward").onClick(() => {
            this.webKeyboardController.deleteBackward(1);
          }).margin({
            left: -220,
          })
          // Insert a function key.
          Button("sendFunctionKey").onClick(() => {
            this.webKeyboardController.sendFunctionKey(6);
          })
        }
      }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .onInterceptKeyboardAttach((KeyboardCallbackInfo) => {
          // Initialize option. By default, the default keyboard is used.
          let option: WebKeyboardOptions = {
            useSystemKeyboard: true,
          };
          if (!KeyboardCallbackInfo) {
            return option;
          }

          // Save the WebKeyboardController. When a custom keyboard is used, this handler is required to control behaviors such as input, deletion, and closing of the keyboard.
          this.webKeyboardController = KeyboardCallbackInfo.controller
          let attributes: Record<string, string> = KeyboardCallbackInfo.attributes
          // Traverse attributes.
          let attributeKeys = Object.keys(attributes)
          for (let i = 0; i < attributeKeys.length; i++) {
            console.log('WebCustomKeyboard key = ' + attributeKeys[i] + ', value = ' + attributes[attributeKeys[i]])
          }

          if (attributes) {
            if (attributes['data-keyboard'] == 'customKeyboard') {
              // Determine the soft keyboard to use based on the attributes of editable HTML elements. For example, if the attribute includes data-keyboard and its value is customKeyboard, custom keyboard is used.
              console.log('WebCustomKeyboard use custom keyboard')
              option.useSystemKeyboard = false;
              // Set the custom keyboard builder.
              option.customKeyboard = () => {
                this.customKeyboardBuilder()
              }
              return option;
            }

            if (attributes['keyboard-return'] != undefined) {
              // Determine the soft keyboard to use based on the attributes of editable HTML elements. For example, if the attribute includes keyboard-return, use the system keyboard and specify the type of the system soft keyboard's Enter key.
              option.useSystemKeyboard = true;
              let enterKeyType: number | undefined = this.inputAttributeMap.get(attributes['keyboard-return'])
              if (enterKeyType != undefined) {
                option.enterKeyType = enterKeyType
              }
              return option;
            }
          }

          return option;
        })
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
    <!DOCTYPE html>
    <html>

    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width,minimum-scale=1.0,maximum-scale=1.0">
    </head>

    <body>

    <p style="font-size:12px">input tag. Original default behavior: </p>
    <input type="text" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as UNSPECIFIED: </p>
    <input type="text" keyboard-return="UNSPECIFIED" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as GO: </p>
    <input type="text" keyboard-return="GO" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as SEARCH: </p>
    <input type="text" keyboard-return="SEARCH" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as SEND: </p>
    <input type="text" keyboard-return="SEND" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as NEXT: </p>
    <input type="text" keyboard-return="NEXT" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as DONE: </p>
    <input type="text" keyboard-return="DONE" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. System keyboard with enterKeyType as PREVIOUS: </p>
    <input type="text" keyboard-return="PREVIOUS" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input tag. Custom keyboard: </p>
    <input type="text" data-keyboard="customKeyboard" style="width: 300px; height: 20px"><br>

    </body>

    </html>
  ```

## onNativeEmbedVisibilityChange<sup>12+</sup>

onNativeEmbedVisibilityChange(callback: OnNativeEmbedVisibilityChangeCallback)

Triggered when the visibility of a same-layer tag (such as an **Embed** tag or an **Object** tag) on a web page changes in the viewport. Same-layer tags are invisible by default. If a tag is visible when the page is loaded for the first time, it is reported. If a tag is invisible, it is not reported. Same-layer tags are considered invisible only when they are all invisible. Partially visible or all visible tags are considered visible. To obtain the visible status change caused by the CSS attributes (including visibility, display, and size change) of the same-layer tag, configure [nativeEmbedOptions](./arkts-basic-components-web-attributes.md#nativeembedoptions16) and set **supportCssDisplayChange** in [EmbedOptions](./arkts-basic-components-web-i.md#embedoptions16) to **true**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNativeEmbedVisibilityChangeCallback](./arkts-basic-components-web-t.md#onnativeembedvisibilitychangecallback12) | Yes| Callback invoked when the visibility of a same-layer tag changes.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class NodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: NodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State embedVisibility: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: this.uiContext!.px2vp(embed.info?.width),
                  height: this.uiContext!.px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedVisibilityChange((embed) => {
              if (embed.visibility) {
                this.embedVisibility = 'Visible';
              } else {
                this.embedVisibility = 'Hidden';
              }
              console.log("embedId = " + embed.embedId);
              console.log("visibility = " + embed.visibility);
            })
        }
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <title>Same-Layer Rendering Test HTML</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onNativeEmbedMouseEvent<sup>20+</sup>

onNativeEmbedMouseEvent(callback: MouseInfoCallback)

Callback triggered when the following operations are performed on the same-layer tag:

- Tapping or holding with the left, middle, or right mouse button.
- Tapping or holding the left, middle, or right mouse button using the touchpad.


**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback       | [MouseInfoCallback](./arkts-basic-components-web-t.md#mouseinfocallback20) | Yes| Callback triggered when a same-layer tag is clicked using the mouse or touchpad.|

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class NodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: NodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postInputEvent(event: TouchEvent | MouseEvent | undefined): boolean {
      return this.rootNode?.postInputEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State mouseAction: string = '';
    @State mouseButton: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: this.uiContext!.px2vp(embed.info?.width),
                  height: this.uiContext!.px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedMouseEvent((event) => {
              if (event && event.mouseEvent) {
                let ret = this.nodeController.postInputEvent(event.mouseEvent)
                if (event.result) {
                  event.result.setMouseEventResult(ret, true);
                }
              }
            })
        }
      }
    }
  }
  ```
HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!Document>
  <html>
  <head>
      <title>Same-Layer Rendering Test</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type ="native/button" width="800" height="800" style="background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onOverrideErrorPage<sup>20+</sup>

onOverrideErrorPage(callback: OnOverrideErrorPageCallback)

Triggered when an error occurs during web page loading of main resources. You can use this API to customize the error display page.

In addition, this feature takes effect only after the default error page is enabled by calling the [setErrorPageEnabled](./arkts-apis-webview-WebviewController.md#seterrorpageenabled20) API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description           |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | [OnOverrideErrorPageCallback](./arkts-basic-components-web-t.md#onoverrideerrorpagecallback20) | Yes   | Callback triggered when an error occurs during web page loading.     |

**Example**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  build() {
    Column() {
      Web({ src: "www.error-test.com", controller: this.controller })
       .onControllerAttached(() => {
            this.controller.setErrorPageEnabled(true);
            if (!this.controller.getErrorPageEnabled()) {
                this.controller.setErrorPageEnabled(true);
            }
        })
        .onOverrideErrorPage(event => {
              let htmlStr = "<html><h1>error occur : ";
              htmlStr += event.error.getErrorCode();
              htmlStr += "</h1></html>";
              return htmlStr;
        })
    }
  }
}
  ```

## onSslErrorReceive<sup>(deprecated)</sup>

onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void)

Triggered when an SSL error occurs during resource loading.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [onSslErrorEventReceive<sup>9+</sup>](#onsslerroreventreceive9) instead.

**System capability**: SystemCapability.Web.Webview.Core

## onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

Triggered to process an HTML form whose input type is **file**, in response to the tapping of the **Select File** button.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [onShowFileSelector<sup>9+</sup>](#onshowfileselector9) instead.

**System capability**: SystemCapability.Web.Webview.Core

## onUrlLoadIntercept<sup>(deprecated)</sup>

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

Triggered when the **Web** component is about to access a URL. This API is used to determine whether to block the access.
This API is deprecated since API version 10. You are advised to use [onLoadIntercept<sup>10+</sup>](#onloadintercept10) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { data:string \| [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) }) => boolean | Yes| URL information.<br>The return value is of the Boolean type. If **true** is returned, the access is blocked. Otherwise, the access is allowed.|

**Example**

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
          .onUrlLoadIntercept((event) => {
            if (event) {
              console.log('onUrlLoadIntercept ' + event.data.toString());
            }
            return true
          })
      }
    }
  }
  ```
