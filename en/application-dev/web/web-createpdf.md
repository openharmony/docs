# Saving a Frontend Page as a PDF File

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=e3a7710dfab09ed41d962e3ea310cc47a7d0f439 translatedAt=2026-08-14T03:43:23.380Z pushedAt=2026-08-14T07:34:54.504Z -->

Since API version 14, the **Web** component supports the [createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14) method for saving frontend pages as PDF files.

After generating an instance using [createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14), call the `pdfArrayBuffer` method to obtain the binary data stream, and then use the basic file I/O interface ([ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md)) to save the binary data stream as a PDF file. Users can save frontend page content as a PDF for sharing or storage. For example, generating reports, invoices, etc., facilitates saving and transmission for users.
> **NOTE**
>
> Through the [pdfConfiguration](../reference/apis-arkweb/arkts-apis-webview-i.md#pdfconfiguration14) settings, you can adjust the PDF page size, frontend page scaling ratio, and more. It is recommended to use a frontend page adaptation strategy and optimize PDF layout through CSS media queries (@media print).

## Required Permissions

To obtain network documents, you need to configure the network access permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

<!-- @[web_createpdf_permissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ArkWebCreatePdf/entry/src/main/module.json5) -->

``` JSON5
"requestPermissions": [
  {
    "name": "ohos.permission.INTERNET"
  }
],
```

## Saving a PDF File Using a Callback

Call the **createPdf** API through a callback, obtain the PDF binary stream through the **pdfArrayBuffer** API based on the obtained result, and use the **fileIo** method to save it as a PDF file.

<!-- @[web_createpdf_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ArkWebCreatePdf/entry/src/main/ets/pages/WebCreatePdfCallback.ets) -->

``` TypeScript
import { fileIo } from '@kit.CoreFileKit';
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
  };

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
                let filePath = context.filesDir + '/test.pdf';
                let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
                fileIo.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info('createPDF write data to file succeed and size is:' + writeLen);
                }).catch((err: BusinessError) => {
                  console.error('createPDF write data to file failed with error message: ' + err.message +
                      ', error code: ' + err.code);
                }).finally(() => {
                  // Close the file.
                  fileIo.closeSync(file);
                });
              } catch (resError) {
                console.error(
                  `ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            });
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## Saving a PDF File Using a Promise

Call the **createPdf** API through a promise, obtain the PDF binary stream through the **pdfArrayBuffer** API based on the obtained result, and use the **fileIo** method to save it as a PDF file.

<!-- @[web_createpdf_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ArkWebCreatePdf/entry/src/main/ets/pages/WebCreatePdfPromise.ets) -->

``` TypeScript
import { fileIo } from '@kit.CoreFileKit';
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
  };

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
                let filePath = context.filesDir + '/test.pdf';
                let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
                fileIo.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info('createPDF write data to file succeed and size is:' + writeLen);
                }).catch((err: BusinessError) => {
                  console.error('createPDF write data to file failed with error message: ' + err.message +
                      ', error code: ' + err.code);
                }).finally(() => {
                  // Close the file.
                  fileIo.closeSync(file);
                });
              } catch (resError) {
                console.error(
                  `ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            })
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```