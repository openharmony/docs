# Saving a Frontend Page as a PDF File
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Since API version 14, the **Web** component supports the [createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14) method for saving frontend pages as PDF files.

After an instance is generated using [createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14), obtain the binary stream using the **pdfArrayBuffer** method, and save it as a PDF file using the **fileIo** method. In this way, users can save frontend page content such as reports and invoices as PDF files for sharing.

## Required Permissions
To obtain network documents, you need to configure the network access permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```


## Saving a PDF File Using a Callback
Call the **createPdf** API through a callback, obtain the PDF binary stream through the **pdfArrayBuffer** API based on the obtained result, and use the **fileIo** method to save it as a PDF file.
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';


@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }


  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          // Ensure that the page rendering is complete before triggering PDF file generation. You can use the onPageEnd event for listening.
          this.controller.createPdf(
            this.pdfConfig,
            (error, result: webview.PdfData) => {
              try {
                // Use the pdfArrayBuffer API to obtain the PDF binary stream and the fileIo API to save it as a PDF file.
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  // Close the file.
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            });
        })
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

## Saving a PDF File Using a Promise
Call the **createPdf** API through a promise, obtain the PDF binary stream through the **pdfArrayBuffer** API based on the obtained result, and use the **fileIo** method to save it as a PDF file.
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';


@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }


  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          // Ensure that the page rendering is complete before triggering PDF file generation. You can use the onPageEnd event for listening.
          this.controller.createPdf(this.pdfConfig)
            .then((result: webview.PdfData) => {
              try {
                // Use the pdfArrayBuffer API to obtain the PDF binary stream and the fileIo API to save it as a PDF file.
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  // Close the file.
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            })
        })
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```
