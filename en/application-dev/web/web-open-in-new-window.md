# Opening Pages in a New Window
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @weixin_41848015-->
<!--Designer: @libing23232323-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->


The **Web** component provides the capability of opening pages in a new window. You can call [multiWindowAccess()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#multiwindowaccess9) to specify whether to allow a web page to be opened in a new window. When a new window is opened in the **Web** component, the application will receive a new window event through [onWindowNew()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onwindownew9). You need to create a window for processing the window opening request in the event callback.


> **NOTE**
>
> - If [allowWindowOpenMethod()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#allowwindowopenmethod10) is set to **true**, you can open a new window in the frontend page by invoking its JavaScript functions.
>
> - When a web page calls **window.open(url, name)** to open a new window, the ArkWeb kernel checks whether a bound **Web** component exists based on **name**. If yes, the **Web** component will receive a notification from the [onActivateContent()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onactivatecontent20) API so that the application can display it in the foreground. If no, the ArkWeb kernel will notify the application of creating a new window through the **onWindowNew()** API.
>
> - If a new window is created in the **onWindowNew()** notification and the parameter of the **ControllerHandler.setWebController()** API is set to the **WebviewController** of the new **Web** component, the ArkWeb kernel will bind the **name** with the new **Web** component.
>
> - If you do not create a window in **onWindowNew()**, set the parameter of the **ControllerHandler.setWebController()** API to null.


In the following example, when a user clicks the **Open Page in New Window** button, the application receives a window opening event in the **onWindowNew()** callback.
> **NOTE**
> - When a web page requires the user to create a window, the [OnWindowNewEvent()](../reference/apis-arkweb/arkts-basic-components-web-i.md#onwindownewevent12) callback is triggered. In this callback, the value **true** of the **isUserTrigger** parameter indicates that the window is triggered by the user, and **false** indicates the opposite.


- Application code:

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
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            console.info("NewWebViewComp onWindowExit");
            if (this.controller) {
              this.controller.close();
            }
          })
          .onActivateContent(() => {
            // To display the web page to the foreground, the application should perform a tab or window switch.
            console.log("NewWebViewComp onActivateContent")
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
            // Enable the multi-window permission.
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController }),
              // Set isModal to false to prevent the new window from being destroyed, so that the onActivateContent callback can be triggered.
              isModal: false
            })
            this.dialogController.open();
            // Return the WebviewController object corresponding to the new window to the <Web> kernel.
            // If the event.handler.setWebController API is not called, the render process will be blocked.
            // If no new window is created, set the value of event.handler.setWebController to null to notify the Web component that no new window is created.
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```


- Code of the **window.html** page:

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" content="width=device-width"/>
      <title>WindowEvent</title>
  </head>
  <body>
  <input type="button" value="Open Page in New Window" onclick="OpenNewWindow()">
  <script type="text/javascript">
      function OpenNewWindow()
      {
          var txt ='Opened window'
          let openedWindow = window.open("about:blank", "", "location=no,status=no,scrollbars=no");
          openedWindow.document.write("<p>" + "<br><br>" + txt + "</p>");
          openedWindow.focus();
      }
  </script>
  </body>
  </html>
  ```

**Figure 1** Effect of opening a page in a new window 

![web-open-in-new-window](figures/web-open-in-new-window.png)

  
## Samples

The following samples are provided to help you better understand how to create a window:

- [Browser (ArkTS) (Full SDK) (API9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)
