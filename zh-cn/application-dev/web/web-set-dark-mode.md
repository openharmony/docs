# 设置深色模式


Web组件支持对前端页面进行深色模式配置。

- 通过[darkMode()](../reference/apis-arkweb/ts-basic-components-web.md#darkmode9)接口可以配置不同的深色模式，默认关闭。当深色模式开启时，Web将启用媒体查询prefers-color-scheme中网页所定义的深色样式，若网页未定义深色样式，则保持原状。如需开启强制深色模式，建议配合[forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9)使用。[WebDarkMode.Off](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9枚举说明)模式表示关闭深色模式。[WebDarkMode.On](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9枚举说明)表示开启深色模式，并且深色模式跟随前端页面。[WebDarkMode.Auto](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9枚举说明)表示开启深色模式，并且深色模式跟随系统。
    在下面的示例中，通过[darkMode()](../reference/apis-arkweb/ts-basic-components-web.md#darkmode9)接口将页面深色模式配置为跟随系统。

    ```ts
    // xxx.ets
    import { webview } from '@kit.ArkWeb';
      
    @Entry
    @Component
    struct WebComponent {
      controller: webview.WebviewController = new webview.WebviewController();
      @State mode: WebDarkMode = WebDarkMode.Auto;

      build() {
        Column() {
          Web({ src: $rawfile('index.html'), controller: this.controller })
            .darkMode(this.mode)
        }
      }
    }
    ```


- 通过[forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9)接口可将前端页面强制配置深色模式，强制深色模式无法保证所有颜色转换符合预期，且深色模式不跟随前端页面和系统。配置该模式时候，需要将深色模式配置成WebDarkMode.On。
    在下面的示例中，通过[forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9)接口将页面强制配置为深色模式。

    ```ts
    // xxx.ets
    import { webview } from '@kit.ArkWeb';

    @Entry		
    @Component
    struct WebComponent {
      controller: webview.WebviewController = new webview.WebviewController();
      @State mode: WebDarkMode = WebDarkMode.On;
      @State access: boolean = true;

      build() {
        Column() {
          Web({ src: $rawfile('index.html'), controller: this.controller })
            .darkMode(this.mode)
            .forceDarkAccess(this.access)
        }
      }
    }
    ```

- index.html页面代码。

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" content="width=device-width,
                                      initial-scale=1.0,
                                      maximum-scale=1.0,
                                      user-scalable=no">
      <style type="text/css">
          @media (prefers-color-scheme: dark) {
              .contentCss{ background:  #000000; color: white; }
              .hrefCss{ color: #317AF7; }
          }
      </style>
  </head>
  <body class="contentCss">
  <div style="text-align:center">
      <p>Dark mode debug page</p>
  </div>
  </body>
  </html>
  ```
