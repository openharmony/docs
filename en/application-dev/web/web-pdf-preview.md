# Previewing PDF Files
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @Yuan_ss-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

The **Web** component allows users to preview PDF files on web pages. An application can use the [src](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) parameter and [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API of the **Web** component to load PDF files, including network PDF files, PDF files in the application sandbox, and local PDF files.

To obtain network documents, you need to configure the network access permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## Loading Different PDF Files

In the following example, the network PDF file **https://www.example.com/test.pdf** is specified as the default PDF file to be loaded when the **Web** component is created. Replace it with an actual accessible address.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ 
      	src: 
      	"https://www.example.com/test.pdf",                                    // Method 1: Load an online PDF file.
      	// this.getUIContext().getHostContext()!.filesDir + "/test.pdf", // Method 2: Load a PDF file from the local application sandbox.
      	// "resource://rawfile/test.pdf", 						// Method 3: Load a local PDF file (format 1).
      	// $rawfile('test.pdf'), 								// Method 3: Load a local PDF file (format 2).
      	controller: this.controller 
      })
        .domStorageAccess(true)
    }
  }
}
```

The PDF preview page uses **window.localStorage** to record the expansion status of the navigation bar based on user operations. Therefore, you need to declare the [domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) permission.

  ```
  Web().domStorageAccess(true)
  ```

When creating a **Web** component, specify the PDF file to be loaded by default. When the default PDF file is loaded, if you want to change the PDF file displayed on the **Web** component, call the [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API to load the specified PDF file. The value of the first parameter **src** of the [Web component](../reference/apis-arkweb/arkts-basic-components-web.md) cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl).

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

Currently, the following parameters are supported:

| Syntax	| Description|
| --------- | ---------- |
| nameddest=destination 	|  Specifies a naming destination in a PDF file.|
| page=pagenum 	| Specifies the page number with an integer. The **pagenum** value of the first page of the file is **1**.| 
| zoom=scale    zoom=scale,left,top	| Sets the scaling and scrolling coefficients using a floating or integer value. For example, the scaling value **100** indicates 100%. The left and up scrolling values are located in the coordinate system. **0,0** indicates the upper left corner of the visible page, regardless of how the document is rotated.|
| toolbar=1 \| 0 	| Opens or closes the top toolbar.| 
| navpanes=1 \| 0 	| Opens or closes the side navigation pane.| 
| pdfbackgroundcolor=color 	| Specifies the background color of a PDF file. The value of **color** is a six-digit hexadecimal number in RGB format. The value ranges from 000000 to ffffff. For example, **ffffff** indicates white.|


URL Examples:
```
https://example.com/test.pdf#nameddest=Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
https://example.com/test.pdf#pdfbackgroundcolor=ffffff
```

## Using the PDF File Preview Callback

Since API version 20, PDF file preview supports the loading success/failure callback and the callback that triggered when the page scrolls to the bottom.

In the following example, the network PDF file **https://www.example.com/test.pdf** is specified as the default PDF file to be loaded when the **Web** component is created. Replace it with an actual accessible address.

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

- **onPdfScrollAtBottom** is triggered when the user scrolls to the bottom.
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
