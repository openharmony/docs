# Previewing PDF Files

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @shulssins-->
<!--Designer: @shulssins-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=f0524ade16836279b29e1c928b6b7514bb1a1dfd translatedAt=2026-08-14T03:48:54.888Z pushedAt=2026-08-14T09:29:29.746Z -->

The [Web](../reference/apis-arkweb/arkts-basic-components-web.md) component supports previewing PDF files in web pages. However, due to performance limitations, frame drops may occur in some scenarios. If smoothness is required, use [PdfView](https://developer.huawei.com/consumer/en/doc/harmonyos-references/pdf-arkts-pdfview-component) or the third-party parsing library [PDF.js](https://github.com/mozilla/pdf.js). An app loads a PDF document through the src parameter of [WebOptions](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) and the [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API. Specific scenarios include network PDF documents, PDF documents in the app sandbox, and local PDF documents.

To obtain network documents, you need to configure the network access permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

<!-- @[web_module_preview_pdf](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ProcessWebPageCont/entry/src/main/module.json5) --> 

``` JSON5
"requestPermissions":[
  // ...
  {
    "name" : "ohos.permission.INTERNET"
  }
],
```

## Loading Different PDF Files

In the following example, the network PDF document `https://www.example.com/test.pdf` is specified as the default PDF document to be loaded when the **Web** component is created. Replace it with an actual accessible URL.

<!-- @[web_module_create_load_pdf](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ProcessWebPageCont/entry/src/main/ets/pages/PreviewPDF.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({
        src:
        'https://www.example.com/test.pdf',                     // Method 1: Load a network PDF file.
          // this.getUIContext().getHostContext()!.filesDir + '/test.pdf', // Method 2: Load a PDF file from the local application sandbox.
          // 'resource://rawfile/test.pdf',                         // Method 3: Load a local PDF file (format 1).
          // $rawfile('test.pdf'),                                 // Method 3: Load a local PDF file (format 2).
          controller: this.controller
      })
        .domStorageAccess(true)
    }
  }
}
```

The PDF preview page uses **window.localStorage** to record the expansion status of the navigation bar based on user operations. Therefore, you need to declare the [domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) permission.

  ```ts
  Web().domStorageAccess(true)
  ```

When creating the [Web](../reference/apis-arkweb/arkts-basic-components-web.md) component, specify the default PDF document to be loaded. After the default PDF document is loaded, if you need to change the PDF document displayed by the **Web** component, call the [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API to load the specified PDF document. The first parameter variable src of [WebOptions](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) cannot be dynamically changed through a state variable (for example, [@State](../ui/state-management/arkts-state.md)). To change the address, reload it through [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl).

There are three scenarios for loading and previewing PDF files:

- Preview and load an online PDF file.

  ```ts
  Web({ 
    src: "https://www.example.com/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```

- To preview and load a PDF file in the application sandbox, you need to configure the [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) permission of the file system in the application.

  ```ts
  Web({ 
    src: this.getUIContext().getHostContext()!.filesDir + "/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
    .fileAccess(true)
  ```

- Preview and load a local PDF file.

  ```ts
  Web({ 
    src: "resource://rawfile/test.pdf",            // Format 1: Load a local PDF file.
    // src: $rawfile('test.pdf'),                  // Format 2: Load a local PDF file.
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```

## Controlling the PDF File Preview Page Status

The following parameters are supported:

| Syntax| Description|
| --------- | ---------- |
| nameddest=destination |  Specifies a naming destination in a PDF file.|
| page=pagenum | Specifies the page number with an integer. The **pagenum** value of the first page of the file is **1**.|
| zoom=scale,left,top | Sets the zoom and scroll factors using floating-point or integer values. For example, a zoom value of 100 indicates a zoom factor of 100%. The left and top scroll values are in a coordinate system where 0,0 represents the top-left corner of the visible page, regardless of how the document is rotated. scale is a required parameter. left and top are optional parameters. |
| toolbar=1 or 0 | 1 indicates that the top toolbar is displayed. 0 indicates that the top toolbar is hidden. |
| navpanes=1 or 0 | 1 indicates that the side navigation pane is displayed. 0 indicates that the side navigation pane is hidden. |
| pdfbackgroundcolor=color | Specifies the background color of a PDF file. The value of color is a six-digit hexadecimal number in RGB format. The value ranges from 000000 to ffffff. For example, **ffffff** indicates white. This parameter is supported since OpenHarmony 6.0.|

URL example:

```txt
https://example.com/test.pdf#nameddest=Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
https://example.com/test.pdf#pdfbackgroundcolor=ffffff
```

## Using the PDF File Preview Callback

Since API version 20, PDF document preview supports two callback functions: the loading success/failure callback and the callback triggered when the page scrolls to the bottom.

In the following example, the network PDF document `https://www.example.com/test.pdf` is specified as the default PDF document to be loaded when the **Web** component is created. Replace it with an actual accessible URL.

- **onPdfLoadEvent** is triggered when the loading succeeds or fails.

  ```ts
  Web({ 
    src: 'https://www.example.com/test.pdf',
    controller: this.controller 
  })
    .onPdfLoadEvent(
      (eventInfo: OnPdfLoadEvent) => {
        console.info(`Load event callback called. url: ${eventInfo.url}, result: ${eventInfo.result}.`)
      }
    )
  ```

- Callback triggered when the page scrolls to the bottom.

  ```ts
  Web({ 
    src: 'https://www.example.com/test.pdf',
    controller: this.controller 
  })
    .onPdfScrollAtBottom(
      (eventInfo: OnPdfScrollEvent) => {
        console.info(`Scroll at bottom callback called. url: ${eventInfo.url}.`)
      }
    ) 
  ```

<!--RP1--><!--RP1End-->