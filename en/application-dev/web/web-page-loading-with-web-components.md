# Loading Pages by Using the Web Component


Page loading is a basic function of the **Web** component. Depending on the data source, page loading falls into three types: loading of network pages, loading of local pages, and loading of HTML rich text data.


If acquisition of network resources is involved in page loading, you need to declare the [ohos.permission.INTERNET](../security/accesstoken-guidelines.md) permission.


## Loading Network Pages

You can specify the default network page to be loaded when creating a **Web** component. After the default network page is loaded, call [loadUrl()](../reference/apis/js-apis-webview.md#loadurl) if you want to change the network page displayed by the **Web** component.


In the following example, after the **www.example.com** page is loaded by the **Web** component, **loadUrl** is called to change the displayed page to **www.example1.com**.



```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // Upon button clicking, call loadUrl to redirect to www.example1.com.
            this.webviewController.loadUrl('www.example1.com');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      // When creating a Web component, set the default network page to be loaded to www.example.com.
      Web({ src: 'www.example.com', controller: this.webviewController})
    }
  }
}
```


## Loading Local Pages

Local page files are stored in the application's **rawfile** directory. You can specify the local page to be loaded by default when creating a **Web** component. After page loading is complete, you can call [loadUrl()](../reference/apis/js-apis-webview.md#loadurl) to change the displayed page of the **Web** component.


The following example shows how to load a local page file.


- Local page file in the application's resources/rawfile directory:

    **Figure 1** Path of local page files 

    ![resource-path](figures/resource-path.png)


- Application code:

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            try {
              // Upon button clicking, call loadUrl to redirect to local1.html.
              this.webviewController.loadUrl($rawfile("local1.html"));
            } catch (error) {
              console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
            }
          })
        // When creating a Web component, load the local.html file through $rawfile.
        Web({ src: $rawfile("local.html"), controller: this.webviewController })
      }
    }
  }
  ```


- Code of the **local.html** page:

  ```html
  <!-- local.html -->
  <!DOCTYPE html>
  <html>
    <body>
      <p>Hello World</p>
    </body>
  </html>
  ```


## Loading HTML Rich Text Data

The **Web** component provides the [loadData()](../reference/apis/js-apis-webview.md#loaddata) API for you to load HTML rich text data. This API is applicable if you want to display some page sections instead of the entire page.



```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            // Upon button clicking, call loadData to load HTML rich text data.
            this.controller.loadData(
              '<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>',
              'text/html',
              'UTF-8'
            );
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      // When creating a Web component, set the default network page to be loaded to www.example.com.
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
