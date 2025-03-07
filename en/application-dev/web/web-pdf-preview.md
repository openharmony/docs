# Previewing PDF Files

The **Web** component provides the capability of previewing PDF files on web pages. The [src](../reference/apis-arkweb/ts-basic-components-web.md#web) parameter of the **Web** component and the [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) API can be used to transfer and load PDF files on the application side. Based on the source of PDF files, there are three common scenarios: loading online PDF files, loading local PDF files, and loading in-application resource PDF files.

When preview and load an online PDF file, declare the network access permission in the **module.json5** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

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
      	"https://www.example.com/test.pdf",                                    // Method 1: Load online PDF Files.
      	// getContext(this).filesDir + "/test.pdf", // Method 2: Load the PDF files from the local application sandbox.
      	// "resource://rawfile/test.pdf",                                              // Method 3: Load the PDF files from application resource 
      	// $rawfile('test.pdf'),                                                              // Method 4: Load the PDF files from application resource 
      	controller: this.controller 
      })
        .domStorageAccess(true)
    }
  }
}
```

In the preceding example, whether the side navigation bar is expanded on the PDF preview page is recorded based on user operations using **window.localStorage**. Therefore, you need to enable the DOM Storage API using [domStorageAccess](../reference/apis-arkweb/ts-basic-components-web.md#domstorageaccess).

  ```
  Web().domStorageAccess(true)
  ```

Specify the PDF file to be loaded by default when the **Web** component is created. When the default PDF file is loaded, if you want to change the PDF file displayed on the **Web** component, you can call the [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) API to load the specified PDF file. The address of the first parameter variable *src* of [Web](../reference/apis-arkweb/ts-basic-components-web.md#web) component cannot be dynamically changed through a state variable (for example, *@State*). To change the address, reload the variable using [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl).

There are three scenarios for loading and previewing PDF files:
- To preview and load an online PDF file:

  ```ts
  Web({ 
    src: "https://www.example.com/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- To preview and load PDF files in the application sandbox, you need to configure the [fileAccess](../reference/apis-arkweb/ts-basic-components-web.md#fileaccess) permission of the file system in the application:

  ```ts
  Web({ 
    src: getContext(this).filesDir + "/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
    .fileAccess(true)
  ```
- To preview and load a PDF file from an application in either of the following ways (Specifying the following preview parameters is not supported in the **$rawfile('test.pdf')** format):

  ```ts
  Web({ 
    src: "resource://rawfile/test.pdf" // or $rawfile ('test.pdf')
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


URL Example 
```
https://example.com/test.pdf#Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
```
<!--RP1--><!--RP1End-->
