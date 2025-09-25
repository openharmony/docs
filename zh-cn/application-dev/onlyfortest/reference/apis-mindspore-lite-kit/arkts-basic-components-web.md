# 组件描述
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

The **Web** component can be used to display web pages. It can be used with thewhich provides APIs for web control.

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

This module provides the following common functionalities related to web page display:

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

To load the local resource file in the sandbox path, you need to configure the permission of the file system in the application.

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

   The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see Obtaining Application File Paths

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
