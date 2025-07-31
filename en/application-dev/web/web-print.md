# Printing Frontend Pages

With the **Web** component, you can print HTML pages through W3C standards-compliant APIs or application APIs.

Before using the print capability, declare related permissions in the **module.json5** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.PRINT"
      }
    ]
  ```

## Initiating a Print Task Through the W3C Standards-compliant API
The printing process with W3C is as follows: A print adapter is created, the print application is started, the current web page content is rendered, and the PDF file generated after rendering is transferred to the print framework through the file descriptor (FD). Use the **window.print()** method to print the current document or open the print dialog box. This method does not have any parameter; simply call it in JavaScript.

You can use the frontend CSS styles, for example, **@media print**, to control the printed content. Then load the HTML page in the **Web** component.

- Sample code of the **print.html** page:

  Example 1:

  ```html
  <!DOCTYPE html>
  <html>

  <head>
      <meta charset="utf-8">
      <title>printTest</title>
      <style>
          @media print {
              h1 {
                  display: none;
              }
          }
      </style>
  </head>

  <body>
      <div>
          <h1><b>
                  <center>This is a test page for printing</center>
              </b>
              <hr color=#00cc00 width=95%>
          </h1>
          <button class="Button Button--outline" onclick="window.print();">Print</button>
          <p> content content content </p>
          <div id="printableTable">
              <table>
                  <thead>
                      <tr>
                          <td>Thing</td>
                          <td>Chairs</td>
                      </tr>
                  </thead>
                  <tbody>
                      <tr>
                          <td>1</td>
                          <td>blue</td>
                      </tr>
                      <tr>
                          <td>2</td>
                          <td>green</td>
                      </tr>
                  </tbody>
              </table>
          </div>
          <p> content content content </p>
          <p> content content content </p>
      </div>
  </body>
  ```
  
  Example 2 (nesting a page in an iframe):


  ```html
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Print Nested Page in an iframe</title>
  </head>
  <body>
      <button id="printIframe">Print nested page in an iframe</button>

      <script>
          function setPrint() {
              const closePrint = () => {
                  document.body.removeChild(this);
              };
              this.contentWindow.onbeforeunload = closePrint;
              this.contentWindow.onafterprint = closePrint;
              this.contentWindow.print();
          }

          document.getElementById("printIframe").addEventListener("click", () => {
              const hideFrame = document.createElement("iframe");
              hideFrame.onload = setPrint;
              hideFrame.style.display = "none"; // Hide iframe
              hideFrame.src = "example.pdf";
              document.body.appendChild(hideFrame);
          });

      </script>
  </body>
  </html>
  ```

- Application code:

  ```ts
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Row() {
        Column() {
          Web({ src: $rawfile("print.html"), controller: this.controller })
            .javaScriptAccess(true)
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

## Initiating a Print Task Through the Application API
On the application side, call [createWebPrintDocumentAdapter](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createwebprintdocumentadapter11) to create a print adapter and pass the adapter to the **print** API to initiate printing.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { print } from '@kit.BasicServicesKit'

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('createWebPrintDocumentAdapter')
        .onClick(() => {
          try {
            let webPrintDocadapter = this.controller.createWebPrintDocumentAdapter('example.pdf');
            print.print('example_jobid', webPrintDocadapter, null, this.getUIContext().getHostContext());
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
