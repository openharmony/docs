# Setting the Dark Mode


The **Web** component allows you to set the dark mode for frontend pages.


- Call [darkMode()](../reference/arkui-ts/ts-basic-components-web.md#darkmode9) to configure an expected dark mode.

    [WebDarkMode.Off](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is disabled. [WebDarkMode.On](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is enabled and its setting follows the frontend page. [WebDarkMode.Auto](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is enabled and its setting follows the system.

    In the following example, the dark mode setting is configured to follow the system by using [darkMode()](../reference/arkui-ts/ts-basic-components-web.md#darkmode9).

    ```ts
    // xxx.ets
    import web_webview from '@ohos.web.webview';
      
    @Entry
    @Component
    struct WebComponent {
      controller: web_webview.WebviewController = new web_webview.WebviewController();
      @State mode: WebDarkMode = WebDarkMode.Auto;
      build() {
        Column() {
          Web({ src: 'www.example.com', controller: this.controller })
            .darkMode(this.mode)
        }
      }
    }
    ```


- Call [forceDarkAccess()](../reference/arkui-ts/ts-basic-components-web.md#forcedarkaccess9) to forcibly set the dark mode for the frontend page and configure the dark mode not to follow the frontend page or system setting. 

    In this mode, you need to specify **WebDarkMode.On** when calling **darkMode()**.

    In the following example, [forceDarkAccess()](../reference/arkui-ts/ts-basic-components-web.md#forcedarkaccess9) is used to forcibly set the dark mode for the frontend page.

    ```ts
    // xxx.ets
    import web_webview from '@ohos.web.webview';

    @Entry		
    @Component
    struct WebComponent {
      controller: web_webview.WebviewController = new web_webview.WebviewController();
      @State mode: WebDarkMode = WebDarkMode.On;
      @State access: boolean = true;
      build() {
        Column() {
          Web({ src: 'www.example.com', controller: this.controller })
            .darkMode(this.mode)
            .forceDarkAccess(this.access)
        }
      }
    }
    ```
