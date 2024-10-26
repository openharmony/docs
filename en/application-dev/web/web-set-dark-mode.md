# Setting the Dark Mode


The **\<Web>** component allows you to set the dark mode for frontend pages.

- Call [darkMode()](../reference/apis-arkweb/ts-basic-components-web.md#darkmode9) to configure an expected dark mode, which is disabled by default. When it is enabled, the **\<Web>** component enables the dark theme defined for web pages if the theme has been defined in **prefers-color-scheme** of a media query, and remains unchanged otherwise. To forcibly enable the dark mode, you are advised to use this API with [forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9). [WebDarkMode.Off](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is disabled. [WebDarkMode.On](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is enabled and its setting follows the frontend page. [WebDarkMode.Auto](../reference/apis-arkweb/ts-basic-components-web.md#webdarkmode9) indicates that the dark mode is enabled and its setting follows the system.
    In the following example, the dark mode setting is configured to follow the system by using [darkMode()](../reference/apis-arkweb/ts-basic-components-web.md#darkmode9).

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


- Call [forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9) to forcibly set the dark mode for the frontend page. The color may be not converted as expected in forcible dark mode and its setting does not follow the frontend page or system. In this mode, you need to specify **WebDarkMode.On** when calling **darkMode()**.
    In the following example, [forceDarkAccess()](../reference/apis-arkweb/ts-basic-components-web.md#forcedarkaccess9) is used to forcibly set the dark mode for the frontend page.

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

- Code of the **index.html** page:

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
