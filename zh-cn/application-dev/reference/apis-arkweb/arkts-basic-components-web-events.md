# 事件
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

通用事件仅支持[onAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#onappear)、[onDisAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear)、[onBlur](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onblur)、[onFocus](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onfocus)、[onDragEnd](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragend10)、[onDragEnter](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragenter)、[onDragStart](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart)、[onDragMove](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragmove)、[onDragLeave](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave)、[onDrop](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop)、[onHover](../apis-arkui/arkui-ts/ts-universal-events-hover.md#onhover)、[onMouse](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onmouse)、[onKeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#onkeyevent)、[onTouch](../apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch)、[onVisibleAreaChange](../apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## onAlert

onAlert(callback: Callback\<OnAlertEvent, boolean\>)

网页触发alert()告警弹窗时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                   | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnAlertEvent](./arkts-basic-components-web-i.md#onalertevent12), boolean\>                | 是    | 网页触发alert()告警弹窗时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终确认结果。当回调返回false时，弹窗的处理结果会被视为取消。 |

**示例：**

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
              console.info("event.url:" + event.url);
              console.info("event.message:" + event.message);
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

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0">
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

即将完成页面刷新或关闭当前页面时触发此回调。

> **说明：**
>
> - 如果当前Web组件没有得到焦点，刷新或关闭当前页面时onBeforeUnload不会触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnBeforeUnloadEvent](./arkts-basic-components-web-i.md#onbeforeunloadevent12), boolean\>                | 是    | 即将完成页面刷新或关闭当前页面时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，函数中绘制的自定义弹窗无效。 |

**示例：**

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
              console.info("event.url:" + event.url);
              console.info("event.message:" + event.message);
              console.info("event.isReload:" + event?.isReload ?? 'false');
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

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0">
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

网页调用confirm()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnConfirmEvent](./arkts-basic-components-web-i.md#onconfirmevent12), boolean\>                | 是    | 网页调用confirm()告警时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终确认结果。当回调返回false时，弹窗的处理结果会被视为取消。 |

**示例：**

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
              console.info("event.url:" + event.url);
              console.info("event.message:" + event.message);
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

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0">
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

网页调用prompt()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnPromptEvent](./arkts-basic-components-web-i.md#onpromptevent12), boolean\>                | 是    | 网页调用prompt()告警时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认、取消和输入），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终处理结果。当回调返回false时，弹窗的处理结果会被视为取消。 |

**示例：**

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
            value: '取消',
            buttonStyle: ButtonStyleMode.TEXTUAL,
            action: () => {
              console.info('Callback when the button is clicked');
              this.result?.handleCancel()
            }
          },
          {
            value: '确认',
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

    // 自定义弹出框的内容区
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
              console.info("event.url:" + event.url);
              console.info("event.message:" + event.message);
              console.info("event.value:" + event.value);
              this.title = "来自" + event.url + "的消息";
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

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0">
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

通知宿主应用JavaScript console消息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                              | 必填   | 说明      |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnConsoleEvent](./arkts-basic-components-web-i.md#onconsoleevent12), boolean\> | 是    | 网页收到JavaScript控制台消息时触发。<br>返回值boolean。当返回true时，该条消息将不会再打印至hilog日志，返回false时仍会打印至hilog日志。 |

**示例：**

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
              console.info('getMessage:' + event.message.getMessage());
              console.info('getSourceId:' + event.message.getSourceId());
              console.info('getLineNumber:' + event.message.getLineNumber());
              console.info('getMessageLevel:' + event.message.getMessageLevel());
            }
            return false;
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <body>
  <script>
      function myFunction() {
          console.info("onconsole printf");
      }
  </script>
  </body>
  </html>
  ```

## onDownloadStart

onDownloadStart(callback: Callback\<OnDownloadStartEvent\>)

通知主应用开始下载一个文件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                | 类型   | 必填   | 说明                                |
| ------------------ | ------ | ---- | ----------------------------------- |
| callback           | Callback\<[OnDownloadStartEvent](./arkts-basic-components-web-i.md#ondownloadstartevent12)\> | 是    | 开始下载时触发。  |

**示例：**

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
              console.info('url:' + event.url)
              console.info('userAgent:' + event.userAgent)
              console.info('contentDisposition:' + event.contentDisposition)
              console.info('contentLength:' + event.contentLength)
              console.info('mimetype:' + event.mimetype)
            }
          })
      }
    }
  }
  ```

## onErrorReceive

onErrorReceive(callback: Callback\<OnErrorReceiveEvent\>)

网页加载遇到错误时触发该回调。主资源与子资源出错都会回调该接口，可以通过[isMainFrame](./arkts-basic-components-web-WebResourceRequest.md#ismainframe)来判断是否是主资源报错。出于性能考虑，建议此回调中尽量执行简单逻辑。在无网络的情况下，触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                     | 必填   | 说明            |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | Callback\<[OnErrorReceiveEvent](./arkts-basic-components-web-i.md#onerrorreceiveevent12)\> | 是    | 网页收到 Web 资源加载错误时触发。      |

**示例：**

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
              console.info('getErrorInfo:' + event.error.getErrorInfo());
              console.info('getErrorCode:' + event.error.getErrorCode());
              console.info('url:' + event.request.getRequestUrl());
              console.info('isMainFrame:' + event.request.isMainFrame());
              console.info('isRedirect:' + event.request.isRedirect());
              console.info('isRequestGesture:' + event.request.isRequestGesture());
              console.info('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString());
              let result = event.request.getRequestHeader();
              console.info('The request header result size is ' + result.length);
              for (let i of result) {
                console.info('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

## onHttpErrorReceive

onHttpErrorReceive(callback: Callback\<OnHttpErrorReceiveEvent\>)

网页加载资源遇到的HTTP错误（响应码>=400）时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型                                     | 必填   | 说明       |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback  | Callback\<[OnHttpErrorReceiveEvent](./arkts-basic-components-web-i.md#onhttperrorreceiveevent12)\> | 是    | 网页收到加载资源返回HTTP错误码时触发。 |

**示例：**

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
              console.info('url:' + event.request.getRequestUrl());
              console.info('isMainFrame:' + event.request.isMainFrame());
              console.info('isRedirect:' + event.request.isRedirect());
              console.info('isRequestGesture:' + event.request.isRequestGesture());
              console.info('getResponseData:' + event.response.getResponseData());
              console.info('getResponseEncoding:' + event.response.getResponseEncoding());
              console.info('getResponseMimeType:' + event.response.getResponseMimeType());
              console.info('getResponseCode:' + event.response.getResponseCode());
              console.info('getReasonMessage:' + event.response.getReasonMessage());
              let result = event.request.getRequestHeader();
              console.info('The request header result size is ' + result.length);
              for (let i of result) {
                console.info('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
              let resph = event.response.getResponseHeader();
              console.info('The response header result size is ' + resph.length);
              for (let i of resph) {
                console.info('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

## onPageBegin

onPageBegin(callback: Callback\<OnPageBeginEvent\>)

网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageBeginEvent](./arkts-basic-components-web-i.md#onpagebeginevent12)\> | 是    | 网页加载开始时触发。 |

**示例：**

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
              console.info('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onPageEnd

onPageEnd(callback: Callback\<OnPageEndEvent\>)

网页加载完成时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageEndEvent](./arkts-basic-components-web-i.md#onpageendevent12)\> | 是    | 网页加载结束时触发。 |

**示例：**

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
              console.info('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onLoadStarted<sup>20+</sup>

onLoadStarted(callback: Callback\<OnLoadStartedEvent\>)

通知宿主应用页面开始加载。此方法在每次主frame加载时调用一次，因此对于包含iframes或frameset的页面，onLoadStarted仅针对主frame调用一次。这意味着当嵌入式frame的内容发生变化时，如点击iframe中的链接或Fragment跳转（即跳转到#fragment_id的导航）等，不会调用onLoadStarted。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnLoadStartedEvent](./arkts-basic-components-web-i.md#onloadstartedevent20)\> | 是    | 网页加载开始时触发。 |

**示例：**

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
              console.info('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onLoadFinished<sup>20+</sup>

onLoadFinished(callback: Callback\<OnLoadFinishedEvent\>)

通知宿主应用页面已加载完成。此方法仅在主frame加载完成时被调用。对于片段跳转（即导航至#fragment_id），onLoadFinished同样会被触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnLoadFinishedEvent](./arkts-basic-components-web-i.md#onloadfinishedevent20)\> | 是    | 网页加载结束时触发。 |

**示例：**

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
              console.info('url:' + event.url);
            }
          })
      }
    }
  }
  ```

## onProgressChange

onProgressChange(callback: Callback\<OnProgressChangeEvent\>)

网页加载进度变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型   | 必填   | 说明                  |
| ----------- | ------ | ---- | --------------------- |
| callback | Callback\<[OnProgressChangeEvent](./arkts-basic-components-web-i.md#onprogresschangeevent12)\> | 是    | 页面加载进度变化时触发的回调。 |

**示例：**

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
              console.info('newProgress:' + event.newProgress);
            }
          })
      }
    }
  }
  ```

## onTitleReceive

onTitleReceive(callback: Callback\<OnTitleReceiveEvent\>)

当页面文档标题`<title>`元素发生变更时，触发回调。若当前页面未显示设置标题，ArkWeb将在加载完成前基于页面的URL生成标题并返回给应用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型   | 必填   | 说明          |
| ----- | ------ | ---- | ------------- |
| callback | Callback\<[OnTitleReceiveEvent](./arkts-basic-components-web-i.md#ontitlereceiveevent12)\> | 是    | 页面文档标题发生变更时触发。 |

**示例：**

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
              console.info('title:' + event.title);
              console.info('isRealTitle:' + event.isRealTitle);
            }
          })
      }
    }
  }
  ```

## onRefreshAccessedHistory

onRefreshAccessedHistory(callback: Callback\<OnRefreshAccessedHistoryEvent\>)

导航完成时触发该回调，用于应用更新其访问的历史链接。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明                                     |
| ----------- | ------- | ---- | ---------------------------------------- |
| callback         | Callback\<[OnRefreshAccessedHistoryEvent](./arkts-basic-components-web-i.md#onrefreshaccessedhistoryevent12)\>  | 是    | 在导航完成时触发。                |

**示例：**

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
              console.info('url:' + event.url + ' isReload:' + event.isRefreshed);
              console.info('isMainFrame:' + event.isMainFrame);
            }
          })
      }
    }
  }
  ```

## onRenderExited<sup>9+</sup>

onRenderExited(callback: Callback\<OnRenderExitedEvent\>)

应用渲染进程异常退出时触发该回调。

多个Web组件可能共享单个渲染进程，每个受影响的Web组件都会触发该回调。

应用处理该回调时，可以调用绑定的webviewController相关接口来恢复页面。例如[refresh](./arkts-apis-webview-WebviewController.md#refresh)、[loadUrl](./arkts-apis-webview-WebviewController.md#loadurl)等。

组件生命周期回调详情可参考[Web组件的生命周期](../../web/web-event-sequence.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                                     | 必填   | 说明             |
| ---------------- | ---------------------------------------- | ---- | ---------------- |
| callback | Callback\<[OnRenderExitedEvent](./arkts-basic-components-web-i.md#onrenderexitedevent12)\> | 是    | 渲染过程退出时触发。 |

**示例：**

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
              console.info('reason:' + event.renderExitReason);
            }
          })
      }
    }
  }
  ```
## onRenderProcessNotResponding<sup>12+</sup>

onRenderProcessNotResponding(callback: OnRenderProcessNotRespondingCallback)

渲染进程无响应时触发该回调函数。如果Web组件无法处理输入事件，或者无法在合理的时间范围内导航到新的URL，则认为网页进程无响应，并将触发该回调。

只要网页进程一直无响应，此回调仍可能会持续触发，直到网页进程再次响应，此时[onRenderProcessResponding](#onrenderprocessresponding12)将会触发。

应用可以通过WebviewController接口[terminateRenderProcess](./arkts-apis-webview-WebviewController.md#terminaterenderprocess12)来终止关联的渲染进程，这可能会影响同一渲染进程的其他Web组件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                                         | 必填   | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessNotRespondingCallback](./arkts-basic-components-web-t.md#onrenderprocessnotrespondingcallback12) | 是    | 渲染进程无响应时触发的回调。 |

**示例：**

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
            console.info("onRenderProcessNotResponding: [jsStack]= " + data.jsStack +
              ", [process]=" + data.pid + ", [reason]=" + data.reason);
          })
      }
    }
  }
  ```

## onRenderProcessResponding<sup>12+</sup>

onRenderProcessResponding(callback: OnRenderProcessRespondingCallback)

渲染进程由无响应状态变回正常运行状态时触发该回调函数，该回调表明该网页并非真正卡死。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                                         | 必填   | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessRespondingCallback](./arkts-basic-components-web-t.md#onrenderprocessrespondingcallback12) | 是    | 渲染进程由无响应状态变回正常运行状态时触发的回调。 |

**示例：**

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
            console.info("onRenderProcessResponding again");
          })
      }
    }
  }
  ```

## onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: Callback\<OnShowFileSelectorEvent, boolean\>)

调用此函数以处理具有“文件”输入类型的HTML表单。如果不调用此函数或返回false，Web组件会提供默认的“选择文件”处理界面。如果返回true，应用可以自定义“选择文件”的响应行为。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ---- | ----------------- |
| callback       | Callback\<[OnShowFileSelectorEvent](./arkts-basic-components-web-i.md#onshowfileselectorevent12), boolean\> | 是    | 用于通知Web组件文件选择的结果。<br>返回值boolean。当返回值为true时，用户可以调用系统提供的弹窗能力。当返回值为false时，函数中绘制的自定义弹窗无效。 |

**示例：**

1. 拉起文件选择器。

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
             console.info('MyFileUploader onShowFileSelector invoked')
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

2. 拉起图库选择器。

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     async selectFile(result: FileSelectorResult): Promise<void> {
       let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
       let photoPicker = new photoAccessHelper.PhotoViewPicker();
       // 过滤选择媒体文件类型为IMAGE_VIDEO
       photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
       // 设置最大选择数量
       photoSelectOptions.maxSelectNumber = 5;
       let chooseFile: photoAccessHelper.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
       // 获取选择的文件列表
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

3. 拉起相机选择器。

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
                 console.info('Title is ' + event.fileSelector.getTitle());
                 console.info('Mode is ' + event.fileSelector.getMode());
                 console.info('Accept types are ' + event.fileSelector.getAcceptType());
                 console.info('Capture is ' + event.fileSelector.isCapture());
                 console.info('Mime types are ' + event.fileSelector.getMimeTypes());
                 event.result.handleFileList([result]);
               }
             }, this.getUIContext())
             return true;
           })
       }
     }
   }
   ```

   加载的html文件。
   ```html
   <!DOCTYPE html>
   <html>
   <head>
     <meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0">
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

通知Web组件所加载的资源文件url信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnResourceLoadEvent](./arkts-basic-components-web-i.md#onresourceloadevent12)\> | 是 | 加载url时触发。 |

**示例：**

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
            console.info('onResourceLoad: ' + event.url);
          })
      }
    }
  }
  ```

## onScaleChange<sup>9+</sup>

onScaleChange(callback: Callback\<OnScaleChangeEvent\>)

当页面显示比例发生变化时，触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScaleChangeEvent](./arkts-basic-components-web-i.md#onscalechangeevent12)\> | 是 | 当页面显示比例发生变化时，触发该回调。 |

**示例：**

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
            console.info('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale);
          })
      }
    }
  }
  ```

## onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: Callback<OnInterceptRequestEvent, WebResourceResponse>)

当Web组件加载URL之前触发该回调，用于拦截URL并返回响应数据。`onInterceptRequest`可拦截所有跳转请求并返回响应数据，但无法访问POST请求体（Body）内容，且不支持分片缓冲（buffer）类型数据获取。此类场景需改用[WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md)实现，依据具体业务需求进行判断。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnInterceptRequestEvent](./arkts-basic-components-web-i.md#oninterceptrequestevent12), [WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md)\> | 是 | 当Web组件加载url之前触发。<br>返回值[WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md)。返回响应数据则按照响应数据加载，无响应数据则返回null表示按照原来的方式加载。 |

**示例：**

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
              console.info('url:' + event.request.getRequestUrl());
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
            console.info('The response header result length is :' + length);
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
              console.info("prepare response ready");
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

通知收到http auth认证请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnHttpAuthRequestEvent](./arkts-basic-components-web-i.md#onhttpauthrequestevent12), boolean\> | 是 | 当浏览器需要用户的凭据时触发。<br>返回值boolean。返回true表示http auth认证成功，返回false表示http auth认证失败。   |

**示例：**

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

通知用户加载资源时发生SSL错误，只支持主资源。
如果需要支持子资源，请使用[OnSslErrorEvent](./arkts-basic-components-web-events.md#onsslerrorevent12)接口。

> **说明：**
>
> - 主资源：浏览器加载网页的入口文件，通常是HTML文档。  
> - 子资源：主资源中引用的依赖文件，由主资源解析过程中遇到特定标签时触发加载。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSslErrorEventReceiveEvent](./arkts-basic-components-web-i.md#onsslerroreventreceiveevent12)\> | 是 | 当网页收到SSL错误时触发。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { cert } from '@kit.DeviceCertificateKit';
  
  function LogCertInfo(certChainData : Array<Uint8Array> | undefined) {
    if (!(certChainData instanceof Array)) {
      console.error('failed, cert chain data type is not array');
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
          console.info('createX509Cert success');
          console.info(ParseX509CertInfo(x509Cert));
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

通知用户加载资源（主资源+子资源）时发生SSL错误，如果只想处理主资源的SSL错误，请用[isMainFrame](./arkts-basic-components-web-WebResourceRequest.md#ismainframe)字段进行区分。

> **说明：**
>
> - 主资源：浏览器加载网页的入口文件，通常是HTML文档。  
> - 子资源：主资源中引用的依赖文件，由主资源解析过程中遇到特定标签时触发加载。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnSslErrorEventCallback](./arkts-basic-components-web-t.md#onsslerroreventcallback12) | 是 | 通知用户加载资源时发生SSL错误。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { cert } from '@kit.DeviceCertificateKit';

  function LogCertInfo(certChainData : Array<Uint8Array> | undefined) {
    if (!(certChainData instanceof Array)) {
      console.error('failed, cert chain data type is not array');
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
          console.info('createX509Cert success');
          console.info(ParseX509CertInfo(x509Cert));
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
            console.info("onSslErrorEvent url: " + event.url);
            console.info("onSslErrorEvent error: " + event.error);
            console.info("onSslErrorEvent originalUrl: " + event.originalUrl);
            console.info("onSslErrorEvent referrer: " + event.referrer);
            console.info("onSslErrorEvent isFatalError: " + event.isFatalError);
            console.info("onSslErrorEvent isMainFrame: " + event.isMainFrame);
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
                  // true表示停止加载页面，停留在当前页面，使用false表示继续加载页面，并展示错误页面
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

通知用户收到SSL客户端证书请求事件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnClientAuthenticationEvent](./arkts-basic-components-web-i.md#onclientauthenticationevent12)\> | 是 | 当需要用户提供的SSL客户端证书时触发的回调。  |

  **示例：**

安装私有凭证以实现双向认证。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { common } from '@kit.AbilityKit';
import { certificateManager } from '@kit.DeviceCertificateKit';
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  controller: WebviewController = new webview.WebviewController();
  uiContext : UIContext = this.getUIContext();
  context : Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
  uri: string = ''

  aboutToAppear(): void {
    webview.WebviewController.setRenderProcessMode(webview.RenderProcessMode.MULTIPLE)
  }

  build() {
    Column() {
      Button("installPrivateCertificate").onClick(() => {
        if (!this.context) {
          return;
        }

        //注：badssl.com-client.p12需要替换为实际使用的证书文件
        let value: Uint8Array = this.context.resourceManager.getRawFileContentSync("badssl.com-client.p12");
        certificateManager.installPrivateCertificate(value, 'badssl.com', "1",
          async (err: BusinessError, data: certificateManager.CMResult) => {
            console.info(`installPrivateCertificate, uri==========${JSON.stringify(data.uri)}`)
            if (!err && data.uri) {
              this.uri = data.uri;
            }
          });
      })
      Button('加载需要客户端SSL证书的网站')
        .onClick(() => {
          this.controller.loadUrl("https://client.badssl.com")
        })
      Web({
        src: "https://www.bing.com/",
        controller: this.controller,
      }).domStorageAccess(true)
        .fileAccess(true)
        .onPageBegin(event => {
          console.info("extensions onpagebegin url " + event.url);
        })
        .onClientAuthenticationRequest((event) => {
          console.info("onClientAuthenticationRequest ");
          event.handler.confirm(this.uri);
          return true;
        })
        .onSslErrorEventReceive(e => {
          console.info(`onSslErrorEventReceive->${e.error.toString()}`);
        })
        .onErrorReceive((event) => {
          if (event) {
            this.getUIContext().getPromptAction().showToast({
              message: `ErrorCode: ${event.error.getErrorCode()}, ErrorInfo: ${event.error.getErrorInfo()}`,
              alignment: Alignment.Center
            })
            console.info('getErrorInfo:' + event.error.getErrorInfo());
            console.info('getErrorCode:' + event.error.getErrorCode());
            console.info('url:' + event.request.getRequestUrl());
          }
        })
        .onTitleReceive(event  => {
          console.info("title received " + event.title);
        })

    }
  }
}
```

对接证书管理，实现双向认证功能。
  
1. 构造 `GlobalContext` 单例对象。
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

2. 构造 `CertManagerService` 对象以对接证书管理。
<!--code_no_check-->
    ```ts
    // CertMgrService.ets
    import { bundleManager, common, Want } from "@kit.AbilityKit";
    import { BusinessError } from "@kit.BasicServicesKit";
    import { GlobalContext } from './GlobalContext';

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

      async grantAppPm(): Promise<string> {
        let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION;
        // 注：com.example.myapplication需要写实际应用名称
        try {
          const data = await bundleManager.getBundleInfoForSelf(bundleFlags)
            .catch((err: BusinessError) => {
              console.error('getBundleInfoForSelf failed. Cause: %{public}s', err.message);
              return null;
            });
          this.appUid = data?.appInfo?.uid?.toString() ?? '';
          console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
        } catch (err) {
          let message = (err as BusinessError).message;
          console.error('getBundleInfoForSelf failed: %{public}s', message);
        }

        // 注：需要在MainAbility.ts文件的onCreate函数里添加GlobalContext.getContext().setObject("AbilityContext", this.context)
        let abilityContext = GlobalContext.getContext().getObject("AbilityContext") as common.UIAbilityContext;
        await abilityContext.startAbilityForResult(
          {
            bundleName: "com.ohos.certmanager",
            abilityName: "MainAbility",
            uri: "requestAuthorize",
            parameters: {
              appUid: this.appUid, // 传入申请应用的appUid
            }
          } as Want)
          .then((data: common.AbilityResult) => {
            if (!data.resultCode && data.want) {
              if (data.want.parameters) {
                this.authUri = data.want.parameters.authUri as string; // 授权成功后获取返回的authUri
              }
            }
          })
        return this.authUri;
      }
    }
    ```
3. 实现双向认证功能。
<!--code_no_check-->
    ```ts
    import { webview } from '@kit.ArkWeb';
    import CertManagerService from './CertMgrService';
    import { promptAction } from '@kit.ArkUI';

    @Entry
    @Component
    struct Index {
      controller: WebviewController = new webview.WebviewController();
      certManager = CertManagerService.getInstance();

      aboutToAppear(): void {
        webview.WebviewController.setRenderProcessMode(webview.RenderProcessMode.MULTIPLE)
      }

      build() {
        Column() {
          Button('加载需要客户端SSL证书的网站')
            .onClick(() => {
              this.controller.loadUrl("https://client.badssl.com")
            })
          Web({
            src: "https://www.bing.com/",
            controller: this.controller,
          }).domStorageAccess(true)
            .fileAccess(true)
            .onPageBegin(event => {
              console.info("extensions onpagebegin url " + event.url);
            })
            .onClientAuthenticationRequest((event) => {
              console.info("onClientAuthenticationRequest ");

              this.certManager.grantAppPm().then(result => {
                console.info(`grantAppPm, URI==========${result}`);
                event.handler.confirm(result);
              })
              return true;
            })
            .onSslErrorEventReceive(e => {
              console.info(`onSslErrorEventReceive->${e.error.toString()}`);
            })
            .onErrorReceive((event) => {
              if (event) {
                this.getUIContext().getPromptAction().showToast({
                  message: `ErrorCode: ${event.error.getErrorCode()}, ErrorInfo: ${event.error.getErrorInfo()}`,
                  alignment: Alignment.Center
                })
                console.info('getErrorInfo:' + event.error.getErrorInfo());
                console.info('getErrorCode:' + event.error.getErrorCode());
                console.info('url:' + event.request.getRequestUrl());
              }
            })
            .onTitleReceive(event  => {
              console.info("title received " + event.title);
            })

        }
      }
    }
    ```

## onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: Callback\<OnPermissionRequestEvent\>)

通知收到获取权限请求，需配置"ohos.permission.CAMERA"、"ohos.permission.MICROPHONE"权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnPermissionRequestEvent](./arkts-basic-components-web-i.md#onpermissionrequestevent12)\> | 是 | 通知收到获取权限请求触发。 |

**示例：**

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
      // 配置Web开启调试模式
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

  加载的html文件。
 ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
  <video id="video" width="500px" height="500px" autoplay></video>
  <canvas id="canvas" width="500px" height="500px"></canvas>
  <br>
  <input type="button" title="HTML5摄像头" value="开启摄像头" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // 获取video摄像头区域
      let video = document.getElementById("video");
      // 返回的Promise对象
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then()异步，调用MediaStream对象作为参数
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      }).catch(function(error) {
        console.error("Error accessing media devices.", error);
      });
    }
  </script>
  </body>
  </html>
 ```

## onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: Callback\<OnContextMenuShowEvent, boolean\>)

长按特定元素（例如图片，链接）或鼠标右键，跳出菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnContextMenuShowEvent](./arkts-basic-components-web-i.md#oncontextmenushowevent12), boolean\> | 是 | 调用时触发的回调，以允许自定义显示上下文菜单。<br>返回值boolean。返回true表示触发自定义菜单，返回false表示触发的自定义菜单无效。     |

**示例：**

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
    // 构建自定义菜单及触发功能接口
    MenuBuilder() {
      // 以垂直列表形式显示的菜单。
      Menu() {
        // 展示菜单Menu中具体的item菜单项。
        MenuItem({
          content: '撤销',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.undo();
            this.showMenu = false;
          })
        MenuItem({
          content: '重做',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.redo();
            this.showMenu = false;
          })
        MenuItem({
          content: '粘贴为纯文本',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.pasteAndMatchStyle();
            this.showMenu = false;
          })
        MenuItem({
          content: '复制图片',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copyImage();
            this.showMenu = false;
          })
        MenuItem({
          content: '剪切',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.cut();
            this.showMenu = false;
          })
        MenuItem({
          content: '复制',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copy();
            this.showMenu = false;
          })
        MenuItem({
          content: '粘贴',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.paste();
            this.showMenu = false;
          })
        MenuItem({
          content: '复制链接',
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
          content: '全选',
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
          // 触发自定义弹窗
          .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result
              console.info(TAG + "x coord = " + event.param.x());
              console.info(TAG + "link url = " + event.param.getLinkUrl());
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

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html lang="en">
  <body>
    <h1>onContextMenuShow</h1>
    <a href="http://www.example.com" style="font-size:27px">链接www.example.com</a>
    <!-- rawfile下放任意一张图片命名为example.png -->
    <div><img src="example.png"></div>
    <p>选中文字鼠标右键弹出菜单</p>
  </body>
  </html>
  ```

## onContextMenuHide<sup>11+</sup>

onContextMenuHide(callback: OnContextMenuHideCallback)

长按特定元素（例如图片，链接）或鼠标右键，隐藏菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnContextMenuHideCallback](./arkts-basic-components-web-t.md#oncontextmenuhidecallback11) | 是 | 菜单相关回调。     |

**示例：**

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
            console.info("onContextMenuHide callback");
          })
      }
    }
  }
  ```

## onScroll<sup>9+</sup>

onScroll(callback: Callback\<OnScrollEvent\>)

通知网页全局滚动位置。

> **说明：**
>
> 通知的是页面全局滚动位置，局部滚动位置的变化是无法触发此回调。
>
> 判断页面是否是全局滚动，在滚动前后打印window.pagYOffset或者window.pagXOffset。
>
> 如果是全局滚动，window.pagYOffset或者window.pagXOffset的值在滚动前后会有变化，反之没有变化。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScrollEvent](./arkts-basic-components-web-i.md#onscrollevent12)\> | 是 | 当页面滑动到指定位置时触发。 |

**示例：**

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

通知用户收到地理位置信息获取请求，需配置"ohos.permission.LOCATION"、"ohos.permission.APPROXIMATELY_LOCATION"权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback      | Callback\<[OnGeolocationShowEvent](./arkts-basic-components-web-i.md#ongeolocationshowevent12)\>  | 是 | 请求显示地理位置权限时触发。     |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl, common } from '@kit.AbilityKit';

  let atManager = abilityAccessCtrl.createAtManager();

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    // 组件的声明周期函数，创建组件实例后触发
    aboutToAppear(): void {
      let context : Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
      if (!context) {
        console.error("context is undefined");
        return;
      }
      // 向用户请求位置权限
      atManager.requestPermissionsFromUser(context, ["ohos.permission.LOCATION", "ohos.permission.APPROXIMATELY_LOCATION"]).then((data) => {
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
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
                title: 'title',
                message: 'text',
                confirm: {
                  value: 'onConfirm',
                  action: () => {
                    // invoke的第三个参数表示是否记住当前弹窗的选择状态，如果传入true，则下次不再弹出对话框
                    event.geolocation.invoke(event.origin, true, false);
                  }
                },
                cancel: () => {
                  // invoke的第三个参数表示是否记住当前弹窗的选择状态，如果传入true，则下次不再弹出对话框
                  event.geolocation.invoke(event.origin, false, false);
                }
              })
            }
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!DOCTYPE html>
  <html>
  <body>
  <p id="locationInfo">位置信息</p>
  <button onclick="getLocation()">获取位置</button>
  <script>
  var locationInfo=document.getElementById("locationInfo");
  function getLocation(){
    if (navigator.geolocation) {
      // 前端页面访问设备地理位置
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

通知用户先前被调用[onGeolocationShow](#ongeolocationshow)时收到地理位置信息获取请求已被取消。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 地理位置信息获取请求已被取消的回调函数。 |

**示例：**

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
            console.info("onGeolocationHide...");
          })
      }
    }
  }
  ```

## onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: OnFullScreenEnterCallback)

通知开发者Web组件进入全屏模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFullScreenEnterCallback](./arkts-basic-components-web-t.md#onfullscreenentercallback12) | 是 | Web组件进入全屏时的回调信息。 |

**示例：**

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
            console.info("onFullScreenEnter videoWidth: " + event.videoWidth +
              ", videoHeight: " + event.videoHeight);
            // 应用可以通过 this.handler.exitFullScreen() 主动退出全屏。
            this.handler = event.handler;
          })
      }
    }
  }
  ```

## onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

通知开发者Web组件退出全屏模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 退出全屏模式时的回调函数。 |

**示例：**

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
            console.info("onFullScreenExit...")
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

使能multiWindowAccess情况下，通知用户新建窗口请求。
若不调用[setWebController](./arkts-basic-components-web-ControllerHandler.md#setwebcontroller9)接口，会造成render进程阻塞。
如果没有创建新窗口，调用[setWebController](./arkts-basic-components-web-ControllerHandler.md#setwebcontroller9)接口时设置成null，通知Web没有创建新窗口。

新窗口需避免直接覆盖在原Web组件上，且应与主页面以相同形式明确显示其URL（如地址栏）以防止用户混淆。若无法实现可信的URL可视化管理，则需考虑禁止创建新窗口。
需注意：新窗口请求来源无法可靠追溯，可能由第三方iframe发起，应用需默认采取沙箱隔离、限制权限等防御性措施以确保安全。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | Callback\<[OnWindowNewEvent](./arkts-basic-components-web-i.md#onwindownewevent12)\>           | 是 | 网页要求用户创建窗口时触发的回调。    |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // 在同一page页有两个Web组件。在WebComponent新开窗口时，会跳转到NewWebViewComp。
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
          // 需要使能multiWindowAccess
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
            // 将新窗口对应WebviewController返回给Web内核。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            // 如果没有创建新窗口，调用event.handler.setWebController接口时设置成null，通知Web没有创建新窗口。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

  ```html
  <!-- window.html页面代码 -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
  <a href="#" onclick="openNewWindow('https://www.example.com')">打开新页面</a>
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

当Web页面触发window.open(url, name)时，会根据name查找是否存在已绑定的Web实例。若存在，该实例将收到此回调以通知应用需将其展示至前端；若不存在，则通过[onWindowNew](#onwindownew9)通知应用创建新Web实例。

> **说明：**
>
> - 通过name绑定Web实例‌：需在[onWindowNew](#onwindownew9)回调中调用event.handler.setWebController方法，并传入新Web实例的controller，以完成绑定。
> - name‌命名需符合正则表达式[a-zA-Z0-9_]+。当该name被用作\<a>或\<form>标签的target属性值时，已绑定的Web实例同样会触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数**

| 参数名        | 类型             | 必填 | 说明                              |
| ------------- | ---------------- | ---- | --------------------------------- |
| callback | Callback\<void> | 是   | 再次在原页面触发window.open后，在已打开的新页面触发该回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // 在同一page页有两个Web组件。在WebComponent新开窗口时，会跳转到NewWebViewComp。
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
            //该Web需要展示到前面，建议应用在这里进行tab或window切换的动作展示此web
            console.info("NewWebViewComp onActivateContent")
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
          // 需要使能multiWindowAccess
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
            // 将新窗口对应WebviewController返回给Web内核。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

  ```html
  <!-- window.html页面代码 -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>ActivateContentEvent</title>
  </head>
  <body>
  <a href="#" onclick="openNewWindow('https://www.example.com')">打开新页面</a>
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

通知用户窗口关闭请求。和[onWindowNew](#onwindownew9)一样，从安全角度讲，应用应该确保用户可以知道他们交互的页面已关闭。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 窗口请求关闭的回调函数。 |

**示例：**

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
            console.info("onWindowExit...");
          })
      }
    }
  }
  ```

## onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: Callback\<OnSearchResultReceiveEvent\>)

回调通知调用方网页页内查找的结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSearchResultReceiveEvent](./arkts-basic-components-web-i.md#onsearchresultreceiveevent12)\>  | 是 | 通知调用方网页页内查找的结果。         |

**示例：**

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
              console.info("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
                "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
            }
          })
      }
    }
  }
  ```

## onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: Callback\<OnDataResubmittedEvent\>)

设置网页表单可以重新提交时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnDataResubmittedEvent](./arkts-basic-components-web-i.md#ondataresubmittedevent12)\> | 是 | 网页表单可以重新提交时触发。 |

**示例：**

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
        // 在网页中点击提交之后，点击refresh按钮可以重新提交时的触发函数。
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
            console.info('onDataResubmitted');
            event.handler.resend();
          })
      }
    }
  }
  ```

 加载的html文件。
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
      <input type="submit" name="提交">
    </form>
  </body>
  </html>
 ```

## onPageVisible<sup>9+</sup>

onPageVisible(callback: Callback\<OnPageVisibleEvent\>)

设置旧页面不再呈现，新页面即将可见时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnPageVisibleEvent](./arkts-basic-components-web-i.md#onpagevisibleevent12)\> | 是 | 旧页面不再呈现，新页面即将可见时触发的回调函数。 |

**示例：**

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
            console.info('onPageVisible url:' + event.url);
          })
      }
    }
  }
  ```

## onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

设置键盘事件的回调函数，该回调在被Webview使用前触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event:[KeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent对象说明)) => boolean | 是 | 触发的KeyEvent事件。<br>返回值为boolean类型，true表示将该KeyEvent传入Webview内核，false表示不将该KeyEvent传入ArkWeb内核。 |

**示例：**

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

设置接收到apple-touch-icon url地址时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnTouchIconUrlReceivedEvent](./arkts-basic-components-web-i.md#ontouchiconurlreceivedevent12)\>  | 是 | 接收到的apple-touch-icon url地址时触发。 |

**示例：**

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
            console.info('onTouchIconUrlReceived:' + JSON.stringify(event));
          })
      }
    }
  }
  ```

## onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: Callback\<OnFaviconReceivedEvent\>)

设置应用为当前页面接收到新的favicon时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnFaviconReceivedEvent](./arkts-basic-components-web-i.md#onfaviconreceivedevent12)\> | 是 | 当前页面接收到新的favicon时触发。 |

**示例：**

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
            console.info('onFaviconReceived');
            this.icon = event.favicon;
          })
      }
    }
  }
  ```

## onAudioStateChanged<sup>10+</sup>

onAudioStateChanged(callback: Callback\<OnAudioStateChangedEvent\>)

设置网页上的音频播放状态发生改变时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnAudioStateChangedEvent](./arkts-basic-components-web-i.md#onaudiostatechangedevent12)\> | 是 | 网页上的音频播放状态发生改变时触发。 |

**示例：**

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
            console.info('onAudioStateChanged playing: ' + this.playing);
          })
      }
    }
  }
  ```

## onFirstContentfulPaint<sup>10+</sup>

 onFirstContentfulPaint(callback: Callback\<OnFirstContentfulPaintEvent\>)

设置网页首次内容绘制回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback    | Callback\<[OnFirstContentfulPaintEvent](./arkts-basic-components-web-i.md#onfirstcontentfulpaintevent12)\> | 是 | 网页首次内容绘制回调函数。       |

**示例：**

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
              console.info("onFirstContentfulPaint:" + "[navigationStartTick]:" +
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

设置网页绘制页面主要内容回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFirstMeaningfulPaintCallback](./arkts-basic-components-web-t.md#onfirstmeaningfulpaintcallback12) | 是 | 网页绘制页面主要内容度量信息的回调。 |

**示例：**

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

设置网页绘制页面最大内容回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnLargestContentfulPaintCallback](./arkts-basic-components-web-t.md#onlargestcontentfulpaintcallback12) | 是 | 网页绘制页面最大内容度量信息的回调。 |

**示例：**

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
            console.info("onLargestContentfulPaint: [navigationStartTime]= " + details.navigationStartTime +
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

当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnLoadInterceptEvent](./arkts-basic-components-web-i.md#onloadinterceptevent12), boolean\> | 是 | 导航触发时的回调包括iframe导航，在回调中可以选择允许或者取消此次导航。<br>返回值为boolean类型。返回true表示取消此次导航，false表示允许此次导航。<br>返回undefined或null时为false。 |

**示例：**

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
            console.info('url:' + event.data.getRequestUrl());
            console.info('isMainFrame:' + event.data.isMainFrame());
            console.info('isRedirect:' + event.data.isRedirect());
            console.info('isRequestGesture:' + event.data.isRequestGesture());
            return true;
          })
      }
    }
  }
  ```

## onRequestSelected

onRequestSelected(callback: () => void)

当Web组件获取焦点时触发回调。如果组件在未获焦状态下加载网页并成功获取焦点，将触发两次回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 当网页获取焦点时触发的回调。 |

**示例：**

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
            console.info('onRequestSelected');
          })
      }
    }
  }
  ```
## onScreenCaptureRequest<sup>10+</sup>

onScreenCaptureRequest(callback: Callback\<OnScreenCaptureRequestEvent\>)

通知收到屏幕捕获请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScreenCaptureRequestEvent](./arkts-basic-components-web-i.md#onscreencapturerequestevent12)\> | 是 | 通知收到屏幕捕获请求。 |

**示例：**

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

该接口在网页过度滚动时触发，用于通知网页过度滚动的偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnOverScrollEvent](./arkts-basic-components-web-i.md#onoverscrollevent12)\> | 是 | 网页过度滚动时触发。 |

**示例：**

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

当Controller成功绑定到Web组件时触发该回调，并且该Controller必须为WebviewController，且禁止在该事件回调前调用Web组件相关的接口，否则会抛出js-error异常。
因该回调调用时网页还未加载，无法在回调中使用有关操作网页的接口，例如[zoomIn](./arkts-apis-webview-WebviewController.md#zoomin)、[zoomOut](./arkts-apis-webview-WebviewController.md#zoomout)等，可以使用[loadUrl](./arkts-apis-webview-WebviewController.md#loadurl)、[getWebId](./arkts-apis-webview-WebviewController.md#getwebid)等操作网页不相关的接口。

组件生命周期详情可参考[Web组件的生命周期](../../web/web-event-sequence.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 当ArkWeb控制器初始化成功时触发的回调。 |

**示例：**

在该回调中使用loadUrl加载网页
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

在该回调中使用getWebId
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
              console.info("id: " + id);
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
  加载的html文件。
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

当网页跳转提交时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNavigationEntryCommittedCallback](./arkts-basic-components-web-t.md#onnavigationentrycommittedcallback11) | 是 | 网页跳转提交时触发的回调。 |

**示例：**

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
            console.info("onNavigationEntryCommitted: [isMainFrame]= " + details.isMainFrame +
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

收到网站安全风险检查结果时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnSafeBrowsingCheckResultCallback](./arkts-basic-components-web-t.md#onsafebrowsingcheckresultcallback11) | 是 | 收到网站安全风险检查结果时触发的回调。|

**示例：**

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
            console.info("onSafeBrowsingCheckResult: [threatType]= " + json.threatType);
          })
      }
    }
  }
  ```

## onSafeBrowsingCheckFinish<sup>21+</sup>

onSafeBrowsingCheckFinish(callback: OnSafeBrowsingCheckResultCallback)

网站安全风险检查结束时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnSafeBrowsingCheckResultCallback](./arkts-basic-components-web-t.md#onsafebrowsingcheckresultcallback11) | 是 | 收到网站安全风险检查结果时触发的回调。|

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  export enum ThreatType {
    UNKNOWN = -1,
    THREAT_ILLEGAL = 0,
    THREAT_FRAUD = 1,
    THREAT_RISK = 2,
    THREAT_WARNING = 3,
    THREAT_NONE = 4,
    THREAT_UNPROCESSED = 5,
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
          .onSafeBrowsingCheckFinish((callback) => {
            let jsonData = JSON.stringify(callback);
            let json: OnSafeBrowsingCheckResultCallback = JSON.parse(jsonData);
            console.info("onSafeBrowsingCheckFinish: [threatType]= " + json.threatType);
          })
      }
    }
  }
  ```

## onNativeEmbedLifecycleChange<sup>11+</sup>

onNativeEmbedLifecycleChange(callback: (event: NativeEmbedDataInfo) => void)

当同层标签生命周期变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedDataInfo](./arkts-basic-components-web-i.md#nativeembeddatainfo11)) => void | 是 | 同层标签生命周期变化时触发该回调。|

**示例：**

```ts
// EntryAbility.ets

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    // API12新增：开启同层渲染BFCache开关
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
        // 默认行为：点击按钮跳转页面，关闭index页面，使同层标签销毁。
        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮跳转页面，关闭index页面，使同层标签进入BFCache。
        Button('Destroy')
        .onClick(() => {
          try {
            this.controller.loadUrl("www.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮返回页面，使同层标签离开BFCache。
        Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮前进页面，使同层标签进入BFCache。
        Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })


        // API12新增同层标签进入离开BFCache状态：非http与https协议加载的网页，Web内核不支持进入BFCache;
        // 因此如果要测试ENTER_BFCACHE/LEAVE_BFCACHE状态，需要将index.html放到Web服务器上，使用http或者https协议加载，如：
        // Web({ src: "http://xxxx/index.html", controller: this.controller })
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .onNativeEmbedLifecycleChange((event) => {
            // 当加载页面中有同层标签会触发Create。
            if (event.status == NativeEmbedStatus.CREATE) {
              this.embedStatus = 'Create';
            }
            // 当页面中同层标签移动或者缩放时会触发Update。
            if (event.status == NativeEmbedStatus.UPDATE) {
              this.embedStatus = 'Update';
            }
            // 退出页面时会触发Destroy。
            if (event.status == NativeEmbedStatus.DESTROY) {
              this.embedStatus = 'Destroy';
            }
            // 同层标签所在的页面进入BFCache时，会触发Enter BFCache。
            if (event.status == NativeEmbedStatus.ENTER_BFCACHE) {
              this.embedStatus = 'Enter BFCache';
            }
            // 同层标签所在的页面离开BFCache时，会触发Leave BFCache。
            if (event.status == NativeEmbedStatus.LEAVE_BFCACHE) {
              this.embedStatus = 'Leave BFCache';
            }
            console.info("status = " + this.embedStatus);
            console.info("surfaceId = " + event.surfaceId);
            console.info("embedId = " + event.embedId);
            if (event.info) {
              console.info("id = " + event.info.id);
              console.info("type = " + event.info.type);
              console.info("src = " + event.info.src);
              console.info("width = " + event.info.width);
              console.info("height = " + event.info.height);
              console.info("url = " + event.info.url);
            }
          })
      }
    }
  }
  ```

  加载的html文件
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染测试html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test? params1=1" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onNativeEmbedGestureEvent<sup>11+</sup>

onNativeEmbedGestureEvent(callback: (event: NativeEmbedTouchInfo) => void)

当手指触摸到同层标签时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedTouchInfo](./arkts-basic-components-web-i.md#nativeembedtouchinfo11)) => void | 是 | 手指触摸到同层标签时触发该回调。 |

**示例：**

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
                console.info("embedId = " + event.embedId);
                console.info("touchType = " + this.eventType);
                console.info("x = " + event.touchEvent.touches[0].x);
                console.info("y = " + event.touchEvent.touches[0].y);
                console.info("Component globalPos:(" + event.touchEvent.target.area.globalPosition.x + "," + event.touchEvent.target.area.globalPosition.y + ")");
                console.info("width = " + event.touchEvent.target.area.width);
                console.info("height = " + event.touchEvent.target.area.height);
              }
            })
        }
      }
    }
  }
  ```
加载的html文件
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染测试html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
         <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onIntelligentTrackingPreventionResult<sup>12+</sup>

onIntelligentTrackingPreventionResult(callback: OnIntelligentTrackingPreventionCallback)

智能防跟踪功能使能时，当追踪者cookie被拦截时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback    | [OnIntelligentTrackingPreventionCallback](./arkts-basic-components-web-t.md#onintelligenttrackingpreventioncallback12) | 是 | 智能防跟踪功能使能时，当追踪者cookie被拦截时触发的回调。 |

**示例：**

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
        // 需要打开智能防跟踪功能，才会触发onIntelligentTrackingPreventionResult回调
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
            console.info("onIntelligentTrackingPreventionResult: [websiteHost]= " + details.host +
              ", [trackerHost]=" + details.trackerHost);
          })
      }
    }
  }
  ```

## onOverrideUrlLoading<sup>12+</sup>

onOverrideUrlLoading(callback: OnOverrideUrlLoadingCallback)

当URL将要加载到当前Web中时触发该回调，让宿主应用程序有机会获得控制权，判断是否阻止Web加载URL。

> **说明：**
>
> - POST请求不会触发该回调。  
> - iframe加载HTTP(s)协议或about:blank时不会触发该回调，而加载非HTTP(s)协议的跳转会触发；调用loadUrl(url: string)主动触发的跳转不会触发该回调。   
> - 不要在回调中使用相同的URL调用loadUrl(url: string)方法，然后返回true。 这样会不必要地中止当前加载，并用相同的URL发起一次新的加载。 要继续加载当前请求URL的正确做法是直接返回false，而不是调用loadUrl(url: string)。 

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnOverrideUrlLoadingCallback](./arkts-basic-components-web-t.md#onoverrideurlloadingcallback12) | 是 | onOverrideUrlLoading的回调。<br>返回值boolean。返回true表示中止加载URL，返回false表示继续在Web中加载URL。  |

**示例：**

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

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <title>测试网页</title>
  </head>
  <body>
    <h1>onOverrideUrlLoading Demo</h1>
    <a href="about:blank">Click here</a>// 访问about:blank。
  </body>
  </html>
  ```

## onViewportFitChanged<sup>12+</sup>

onViewportFitChanged(callback: OnViewportFitChangedCallback)

网页meta中viewport-fit配置项更改时触发该回调，应用可在此回调中自适应布局视口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnViewportFitChangedCallback](./arkts-basic-components-web-t.md#onviewportfitchangedcallback12) | 是 | 网页meta中viewport-fit配置项更改时触发的回调。 |

**示例：**

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
              // index.html网页支持沉浸式布局，可调用expandSafeArea调整web控件布局视口覆盖避让区域(状态栏或导航条)。
            } else if (viewportFit === ViewportFit.CONTAINS) {
              // index.html网页不支持沉浸式布局，可调用expandSafeArea调整web控件布局视口为安全区域。
            } else {
              // 默认值，可不作处理。
            }
          })
      }
    }
  }
  ```

  加载的html文件。
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

网页中可编辑元素（如input标签）拉起软键盘之前会回调该接口，应用可以使用该接口拦截系统软键盘的弹出，配置应用定制的软键盘（应用根据该接口可以决定使用系统默认软键盘/定制enter键的系统软键盘/全部由应用自定义的软键盘）。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [WebKeyboardCallback](./arkts-basic-components-web-t.md#webkeyboardcallback12) | 是 | 拦截网页拉起软键盘回调。 |

**示例：**

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
       * 自定义键盘组件Builder
       */
      @Builder
      customKeyboardBuilder() {
          // 这里实现自定义键盘组件，对接WebKeyboardController实现输入、删除、关闭等操作。
        Row() {
          Text("完成")
            .fontSize(20)
            .fontColor(Color.Blue)
            .onClick(() => {
              this.webKeyboardController.close();
            })
          // 插入字符。
          Button("insertText").onClick(() => {
            this.webKeyboardController.insertText('insert ');
          }).margin({
            bottom: 200,
          })
          // 从后往前删除length参数指定长度的字符。
          Button("deleteForward").onClick(() => {
            this.webKeyboardController.deleteForward(1);
          }).margin({
            bottom: 200,
          })
          // 从前往后删除length参数指定长度的字符。
          Button("deleteBackward").onClick(() => {
            this.webKeyboardController.deleteBackward(1);
          }).margin({
            left: -220,
          })
          // 插入功能按键。
          Button("sendFunctionKey").onClick(() => {
            this.webKeyboardController.sendFunctionKey(6);
          })
        }
      }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .onInterceptKeyboardAttach((KeyboardCallbackInfo) => {
          // option初始化，默认使用系统默认键盘
          let option: WebKeyboardOptions = {
            useSystemKeyboard: true,
          };
          if (!KeyboardCallbackInfo) {
            return option;
          }

          // 保存WebKeyboardController，使用自定义键盘时候，需要使用该handler控制输入、删除、软键盘关闭等行为
          this.webKeyboardController = KeyboardCallbackInfo.controller
          let attributes: Record<string, string> = KeyboardCallbackInfo.attributes
          // 遍历attributes
          let attributeKeys = Object.keys(attributes)
          for (let i = 0; i < attributeKeys.length; i++) {
            console.log('WebCustomKeyboard key = ' + attributeKeys[i] + ', value = ' + attributes[attributeKeys[i]])
          }

          if (attributes) {
            if (attributes['data-keyboard'] == 'customKeyboard') {
              // 根据html可编辑元素的属性，判断使用不同的软键盘，例如这里如果属性包含有data-keyboard，且值为customKeyboard，则使用自定义键盘
              console.info('WebCustomKeyboard use custom keyboard')
              option.useSystemKeyboard = false;
              // 设置自定义键盘builder
              option.customKeyboard = () => {
                this.customKeyboardBuilder()
              }
              return option;
            }

            if (attributes['keyboard-return'] != undefined) {
              // 根据html可编辑元素的属性，判断使用不同的软键盘，例如这里如果属性包含有keyboard-return，使用系统键盘，并且指定系统软键盘enterKey类型
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

  加载的html文件。
  ```html
  <!-- index.html -->
    <!DOCTYPE html>
    <html>

    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width,minimum-scale=1.0,maximum-scale=1.0">
    </head>

    <body>

    <p style="font-size:12px">input标签，原有默认行为：</p>
    <input type="text" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key UNSPECIFIED：</p>
    <input type="text" keyboard-return="UNSPECIFIED" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key GO：</p>
    <input type="text" keyboard-return="GO" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key SEARCH：</p>
    <input type="text" keyboard-return="SEARCH" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key SEND：</p>
    <input type="text" keyboard-return="SEND" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key NEXT：</p>
    <input type="text" keyboard-return="NEXT" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key DONE：</p>
    <input type="text" keyboard-return="DONE" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key PREVIOUS：</p>
    <input type="text" keyboard-return="PREVIOUS" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，应用自定义键盘：</p>
    <input type="text" data-keyboard="customKeyboard" style="width: 300px; height: 20px"><br>

    </body>

    </html>
  ```

## onNativeEmbedVisibilityChange<sup>12+</sup>

onNativeEmbedVisibilityChange(callback: OnNativeEmbedVisibilityChangeCallback)

当网页中同层标签（例如<embed\>标签或<object\>标签）在视口内的可见性发生变化时，将触发该回调。同层标签默认不可见，若在页面首次加载时已可见，则会上报；若不可见，则不会上报。同层标签全部不可见才视为不可见，部分可见或全部可见则视为可见。若要获取因同层标签CSS属性（包括visibility、display以及尺寸变化）导致的可见状态变化，需配置[nativeEmbedOptions](./arkts-basic-components-web-attributes.md#nativeembedoptions16)，并将[EmbedOptions](./arkts-basic-components-web-i.md#embedoptions16)中的supportCssDisplayChange参数设为true。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNativeEmbedVisibilityChangeCallback](./arkts-basic-components-web-t.md#onnativeembedvisibilitychangecallback12) | 是 | 同层标签可见性变化时触发该回调。 |

**示例：**

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
              console.info("embedId = " + embed.embedId);
              console.info("visibility = " + embed.visibility);
            })
        }
      }
    }
  }
  ```

  加载的html文件
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染测试html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## onNativeEmbedMouseEvent<sup>20+</sup>

onNativeEmbedMouseEvent(callback: MouseInfoCallback)

在同层标签上执行以下行为时触发该回调：

- 使用鼠标左键、中键、右键进行点击或长按。
- 使用触摸板进行对应鼠标左键、中键、右键点击长按的操作。


**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [MouseInfoCallback](./arkts-basic-components-web-t.md#mouseinfocallback20) | 是 | 当鼠标/触摸板点击到同层标签时触发该回调。 |

**示例：**

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
加载的html文件
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染测试</title>
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

## onNativeEmbedObjectParamChange<sup>21+</sup>

onNativeEmbedObjectParamChange(callback: OnNativeEmbedObjectParamChangeCallback)

当同层渲染object标签内嵌param元素变化时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNativeEmbedObjectParamChangeCallback](./arkts-basic-components-web-t.md#onnativeembedobjectparamchangecallback21) | 是 | 增加、修改或删除同层渲染object标签内嵌param元素时触发此回调。 |

**示例：**

```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from '@kit.ArkUI';

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
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();
    uiContext: UIContext = this.getUIContext();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile('index.html'), controller: this.controller })
            .enableNativeEmbedMode(true)
            .registerNativeEmbedRule("object", "native")
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
            .onNativeEmbedObjectParamChange((event) => {
              console.log("embed id: " + event.embedId);
              let paramItems = event.paramItems;
              if (paramItems) {
                for (let i = 0; i < paramItems.length; ++i) {
                  console.log("param info: " + JSON.stringify(paramItems[i]));
                }
              }
            })
        }
      }
    }
  }
  ```

加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染测试</title>
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <object id="nativeButton" type ="native/button" width="300" height="300" style="background-color:red">
            <param id="param-1" name="name-1" value="value1"/>
          </object>
      </div>
  </div>
  </body>
  </html>
  ```

## onOverrideErrorPage<sup>20+</sup>

onOverrideErrorPage(callback: OnOverrideErrorPageCallback)

网页加载遇到错误时触发，只有主资源出错才会回调该接口，可以使用该接口自定义错误展示页。

此外，该功能需通过调用[setErrorPageEnabled](./arkts-apis-webview-WebviewController.md#seterrorpageenabled20)接口启用默认错误页后，才会生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                     | 必填   | 说明            |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | [OnOverrideErrorPageCallback](./arkts-basic-components-web-t.md#onoverrideerrorpagecallback20) | 是    | 网页加载遇到错误时触发。      |

**示例：**

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

通知用户加载资源时发生SSL错误。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[onSslErrorEventReceive<sup>9+</sup>](#onsslerroreventreceive9)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { handler: Function, error: object }) => void | 是 | 当网页检测到SSL错误时触发的回调。 |

## onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

调用此函数以处理具有“文件”输入类型的HTML表单，以响应用户按下的“选择文件”按钮。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[onShowFileSelector<sup>9+</sup>](#onshowfileselector9)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { callback: Function, fileSelector: object }) => void | 是 | 当触发文件选择器时需要执行的回调。 |


## onUrlLoadIntercept<sup>(deprecated)</sup>

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。
从API version 10开始不再维护，建议使用[onLoadIntercept<sup>10+</sup>](#onloadintercept10)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { data:string \| [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) }) => boolean | 是 | url的相关信息。<br>返回值：boolean，true表示阻止此次加载，false表示允许此次加载。 |

**示例：**

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
              console.info('onUrlLoadIntercept ' + event.data.toString());
            }
            return true
          })
      }
    }
  }
  ```

## onPdfLoadEvent<sup>20+</sup>

onPdfLoadEvent(callback: Callback\<OnPdfLoadEvent\>)

通知用户PDF页面加载状态，包括成功或失败。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                              | 必填   | 说明      |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnPdfLoadEvent](./arkts-basic-components-web-i.md#onpdfloadevent20)\> | 是    | 当PDF加载成功或失败时，会触发回调，通知用户PDF页面加载状态。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 使用时需将'https://www.example.com/xxx.pdf'替换为真实可访问的地址
        Web({ src: 'https://www.example.com/xxx.pdf', controller: this.controller })
          .onPdfLoadEvent((eventInfo: OnPdfLoadEvent) => {
            console.info(`Load event callback called. url: ${eventInfo.url}, result: ${eventInfo.result}.`)
          })
      }
    }
  }
  ```

## onPdfScrollAtBottom<sup>20+</sup>

onPdfScrollAtBottom(callback: Callback\<OnPdfScrollEvent\>)

通知用户PDF页面已滚动到底。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                              | 必填   | 说明      |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnPdfScrollEvent](./arkts-basic-components-web-i.md#onpdfscrollevent20)\> | 是    | 当PDF滚动到垂直方向底部时，会触发回调，通知用户PDF页面已滚动到底。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 使用时需将'https://www.example.com/xxx.pdf'替换为真实可访问的地址
        Web({ src: 'https://www.example.com/xxx.pdf', controller: this.controller })
          .onPdfScrollAtBottom((eventInfo: OnPdfScrollEvent) => {
            console.info(`Scroll at bottom callback called. url: ${eventInfo.url}.`)
          })
      }
    }
  }
  ```
