# Uploading Files


The **Web** component supports file uploading on a frontend page. You can use [onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9) to process file upload requests sent from a frontend page.


In the following example, when a user clicks the **Upload** button on the frontend page, the application receives a file upload request through [onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9), which carries the path of the local file to be uploaded.


- Application code:
  
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import picker from '@ohos.file.picker';
  import { BusinessError } from '@ohos.base';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile('local.html'), controller: this.controller })
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
              console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
            })
            return true
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
  <meta name="viewport" content="width=device-width" />
  </body>
  </html>
  ```
