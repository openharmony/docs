# Previewing PDF Files

The **Web** component provides the capability of previewing PDF files on web pages. An application can load a PDF file using the [src](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) parameter and [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API of the **Web** component. Based on the source, PDF files are classified into online PDF files, PDF files in the application sandbox, and local PDF files.

To obtain online PDF files, configure the network access permission in the **module.json5** file. For details, see [Declare Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```


In the following example, the online PDF file **www.example.com/test.pdf** is specified to be loaded by default when the **Web** component is created. Replace the example address with an accessible address in practice.

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

Specify the PDF file to be loaded by default when the **Web** component is created. When the default PDF file is loaded, if you want to change the PDF file displayed on the **Web** component, you can call the [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl) API to load the specified PDF file. The value of the first parameter **src** of the [Web component](../reference/apis-arkweb/arkts-basic-components-web.md) cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl).

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

In addition, you can set PDF file preview parameters to control the page status when the page is opened.

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
https://example.com/test.pdf#Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
https://example.com/test.pdf#pdfbackgroundcolor=ffffff
```
<!--RP1--><!--RP1End-->
