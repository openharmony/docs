# 设置深色模式


Web组件支持对前端页面进行深色模式配置。


- 通过[darkMode()](../reference/arkui-ts/ts-basic-components-web.md#darkmode9)接口可以配置不同的深色模式，[WebDarkMode.Off](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9)模式表示关闭深色模式。[WebDarkMode.On](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9)表示开启深色模式，并且深色模式跟随前端页面。[WebDarkMode.Auto](../reference/arkui-ts/ts-basic-components-web.md#webdarkmode9)表示开启深色模式，并且深色模式跟随系统。
    在下面的示例中, 通过[darkMode()](../reference/arkui-ts/ts-basic-components-web.md#darkmode9)接口将页面深色模式配置为跟随系统。

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


- 通过[forceDarkAccess()](../reference/arkui-ts/ts-basic-components-web.md#forcedarkaccess9)接口可将前端页面强制配置深色模式，且深色模式不跟随前端页面和系统。配置该模式时候，需要将深色模式配置成WebDarkMode.On。
    在下面的示例中, 通过[forceDarkAccess()](../reference/arkui-ts/ts-basic-components-web.md#forcedarkaccess9)接口将页面强制配置为深色模式。

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
