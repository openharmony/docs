# Loading Web Pages


Page loading is a basic capability of the **Web** component. Depending on the data source, page loading falls into three types: loading of network pages, loading of local pages, and loading of HTML rich text data.


If you need to load online resources, declare the network access permission in the **module.json5** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## Loading Network Pages

You can specify the default network page to be loaded when creating a **Web** component. After the default network page is loaded, call [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) if you want to change the network page displayed by the **Web** component. The value of the first parameter **src** of the **Web** component cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl).


In the following example, after the **www.\example.com** page is loaded by the **Web** component, **loadUrl** is called to change the displayed page to **www\.example1.com**.



```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // Upon button clicking, call loadUrl to redirect to www.example1.com.
            this.controller.loadUrl('www.example1.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // When creating a Web component, set the default network page to be loaded to www.example.com.
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```


## Loading Local Pages

The following example shows how to load a local page file.

Local page files are stored in the application's **rawfile** directory. You can specify the local page to be loaded by default when creating a **Web** component. After page loading is complete, you can call [loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl) to change the displayed page of the **Web** component.

To reference a local CSS file when loading a local HTML file, perform the following steps:

```html
<link rel="stylesheet" href="resource://rawfile/xxx.css">
<link rel="stylesheet" href="file:// /data/storage/el2/base/haps/entry/cache/xxx.css">// Load the local CSS file in the sandbox path.
```

- Local page file in the application's resources/rawfile directory:

    **Figure 1** Path of local page files 

    ![resource-path](figures/resource-path.png)


- Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            try {
              // Upon button clicking, call loadUrl to redirect to local1.html.
              this.controller.loadUrl($rawfile("local1.html"));
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        // When creating a Web component, load the local.html file through $rawfile.
        Web({ src: $rawfile("local.html"), controller: this.controller })
      }
    }
  }
  ```


- Code of the **local.html** page:

  ```html
  <!-- local.html -->
  <!DOCTYPE html>
  <html>
    <body>
      <p>Hello World</p>
    </body>
  </html>
  ```

- Code of the **local1.html** page:

  ```html
  <!-- local1.html -->
  <!DOCTYPE html>
  <html>
    <body>
      <p>This is local1 page</p>
    </body>
  </html>
  ```

Example of loading local page files in the sandbox:

1. To obtain the sandbox path through the constructed singleton object **GlobalContext**, you need to enable [fileAccess](../reference/apis-arkweb/ts-basic-components-web.md#fileaccess) in the application.

   ```ts
   // GlobalContext.ets
   export class GlobalContext {
     private constructor() {}
     private static instance: GlobalContext;
     private _objects = new Map<string, Object>();

     public static getContext(): GlobalContext {
       if (!GlobalContext.instance) {
         GlobalContext.instance = new GlobalContext();
       }
       return GlobalContext.instance;
     }

     getObject(value: string): Object | undefined {
       return this._objects.get(value);
     }

     setObject(key: string, objectClass: Object): void {
       this._objects.set(key, objectClass);
     }
   }
   ```

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   let url = 'file://' + GlobalContext.getContext().getObject("filesDir") + '/index.html';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         // Load the files in the sandbox.
         Web({ src: url, controller: this.controller })
         .fileAccess(true)
       }
     }
   }
   ```

2. Modify the **EntryAbility.ets** file.

   The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // Data synchronization between the UIAbility component and UI can be implemented by binding filesDir to the GlobalContext object.
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
     }
   }
   ```

   HTML file to be loaded:

   ```html
   <!-- index.html -->
   <!DOCTYPE html>
   <html>
       <body>
           <p>Hello World</p>
       </body>
   </html>
   ```


## Loading HTML Rich Text Data

The **Web** component provides the [loadData()](../reference/apis-arkweb/js-apis-webview.md#loaddata) API for you to load HTML rich text data. If you need to display only some page fragments, you can use this feature to quickly load the page. To load a large number of HTML files, set **baseUrl** to data.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            // Upon button clicking, call loadData to load HTML rich text data.
            this.controller.loadData(
              "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              "text/html",
              "UTF-8"
            );
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // When creating a Web component, set the default network page to be loaded to www.example.com.
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

The **Web** component can load HTML strings using data urls.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  htmlStr: string = "data:text/html, <html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

  build() {
    Column() {
      // When creating a Web component, set the default network page to be loaded to htmlStr.
      Web({ src: this.htmlStr, controller: this.controller })
    }
  }
}
```

## Samples

The following samples are provided to help you better understand how to develop the **Web** component:

- [Browser (ArkTS) (Full SDK) (API9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)
