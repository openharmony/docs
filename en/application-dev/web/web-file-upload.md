# Uploading Files


The **Web** component supports file uploading on a frontend page. You can use [onShowFileSelector()](../reference/arkui-ts/ts-basic-components-web.md#onshowfileselector9) to process file upload requests sent from a frontend page.


In the following example, when a user clicks the **Upload** button on the frontend page, the application receives a file upload request through [onShowFileSelector()](../reference/arkui-ts/ts-basic-components-web.md#onshowfileselector9), which carries the path of the local file to be uploaded.


- Application code:
  
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        // Load the local.html page.
        Web({ src: $rawfile('local.html'), controller: this.controller })
          .onShowFileSelector((event) => {
              // Set the path of the local file to be uploaded.
             let fileList: Array<string> = [
                'xxx/test.png',
             ]
             event.result.handleFileList(fileList)
             return true;
          })
      }
    }
  }
  ```


- Code of the **local.html** page:
  
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>Document</title>
  </head>
  
  <body>
  <!-- Click the Upload button -->
  <input type="file" value="file"></br>
  </body>
  </html>
  ```
