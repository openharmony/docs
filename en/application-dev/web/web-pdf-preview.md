# Previewing PDF Document Using Web Components

The Web component provides the capability of previewing PDF files on web pages. Applications can use the [src](../reference/apis-arkweb/ts-basic-components-web.md#web) parameter of the web component and the [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) interface to transfer PDF files to load PDF files. Based on the source of PDF documents, there are three common scenarios: loading network PDF documents, loading local PDF documents, and loading in-application resource PDF documents.

If network documents need to be obtained during PDF document preview and loading, you need to configure the [ohos.permission.INTERNET](../security/AccessToken/declare-permissions.md) network access permission.


In the following example, the network PDF file **www.example.com/test.pdf** to be loaded by default is specified when the web component is created. This address is an example. Replace it with the actual accessible address.

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
      	"https://www.example.com/test.pdf", // Method 1: Loading Network PDF Files
      	// "file://" + getContext(this).filesDir + "/test.pdf", //Method 2: Load the PDF file in the local application sandbox.
      	// "resource://rawfile/test.pdf", //Method 3: PDF file of resources in the application
      	// $rawfile('test.pdf'), //Method 4: PDF file of resources in the application
      	controller: this.controller 
      })
        .domStorageAccess(true)
    }
  }
}
```

In the preceding example, whether the side navigation bar is expanded on the PDF preview page is recorded persistently using **window.localStorage** based on user operations. Therefore, you need to enable the [domStorageAccess](../reference/apis-arkweb/ts-basic-components-web.md#domstorageaccess) permission for document object model storage.

  ```
  Web().domStorageAccesss(true)
  ```

Specifies the PDF document to be loaded by default when the Web component is created. After the default PDF document is loaded, if you want to change the PDF document displayed on the web component, you can call the [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) interface to load the specified PDF document. The address of the first parameter variable src of [Web Component] (../reference/apis-arkweb/ts-basic-components-web.md#web) cannot be dynamically changed through a state variable (for example, @State). To change the address, reload the variable through [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl).

There are three PDF document loading and preview scenarios:
- Preview Load Network PDF File

  ```
  Web({ 
    src: "https://www.example.com/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- Previewing and Loading PDF Files in the App Sandbox

  ```
  Web({ 
    src: "file://" + getContext(this).filesDir + "/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- Preview and load PDF resource files in the application in either of the following ways: The preview parameters described below cannot be specified in the **$rawfile('test.pdf')** format.

  ```
  Web({ 
    src: "resource://rawfile/test.pdf" //or $rawfile ('test.pdf')
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```

In addition, you can set PDF file preview parameters to control the page status when the preview function is enabled.

Currently, the following parameters are supported: 

| Syntax:	| Description |
| --------- 	| ---------- |
| nameddest=destination 	|  Specifying a Naming Target in a PDF Document |
| page=pagenum 	| Use an integer to specify the page number in the document. The pagenum value of the first page of the document is 1.| 
| zoom=scale    zoom=scale,left,top	| Sets the scaling and scrolling coefficients using floating-point or integer values. For example, the scaling value 100 indicates that the scaling value is 100%. The left and up scrolling values are located in the coordinate system. 0,0 indicates the upper left corner of the visible page, regardless of how the document is rotated. |
| toolbar=1\|0 	| Opens or closes the toolbar on the top. | 
| navpanes=1\|0 	| Opens or closes the side navigation pane. | 


URL Example 
```
https://example.com/test.pdf#Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
```
