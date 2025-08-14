# Components

The **Web** component can be used to display web pages. It can be used with the [@ohos.web.webview](arkts-apis-webview.md) module, which provides APIs for web control.

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

To use online resources, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Child Components

Not supported

## APIs

Web(value: WebOptions)

> **NOTE**
>
> Transition animation is not supported.
>
> **Web** components on the same page must be bound to different **WebviewController** instances.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](./arkts-basic-components-web-i.md#weboptions)   | Yes   | Define web options.|

**Example**

Example of loading online web pages:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

Example of loading online web pages in incognito mode:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

Example of rendering the **Web** component in synchronous mode:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
      }
    }
  }
  ```

Example of using the **Web** component to specify the shared rendering process.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, sharedRenderProcessToken: "111" })
        Web({ src: 'www.w3.org', controller: this.controller, sharedRenderProcessToken: "111" })
      }
    }
  }
  ```

Example of loading local web pages using **$rawfile()**:

 
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through $rawfile.
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

Example of loading a link with the hash (#) route through the resource protocol in WebView:

When **$rawfile** is used to load a URL contains a number sign (#), the content following the number sign is treated as a fragment. To avoid this issue, you can use the **resource://rawfile/** protocol prefix instead.
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through the resource protocol.
        Web({ src: "resource://rawfile/index.html#home", controller: this.controller })
      }
    }
  }
  ```

Create an **index.html** file in **src/main/resources/rawfile**.
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<div id="content"></div>

<script>
	function loadContent() {
	  var hash = window.location.hash;
	  var contentDiv = document.getElementById('content');

	  if (hash === '#home') {
		contentDiv.innerHTML = '<h1>Home Page</h1><p>Welcome to the Home Page!</p>';
	  } else {
		contentDiv.innerHTML = '<h1>Default Page</h1><p>This is the default content.</p>';
	  }
	}

	// Load the UI.
	window.addEventListener('load', loadContent);

	// Update the UI when the hash changes.
	window.addEventListener('hashchange', loadContent);
</script>
</body>
</html>
```

To load the local resource file in the sandbox path, you need to configure the [fileAccess](./arkts-basic-components-web-attributes.md#fileaccess) permission of the file system in the application.

1. Obtain the sandbox path through the constructed singleton object **GlobalContext**.

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

   The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

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
