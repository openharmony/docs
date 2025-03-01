# Accelerating Web Page Access

When the web page loads slowly, you can use the capabilities of pre-connection, preloading, and prefetching POST requests to accelerate the access to the web page.

## Preparsing and Preconnecting

You can call [prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10) to preparse or preconnect to the page to be loaded.

  In the following example, the page to be loaded is preconnected in the **onAppear** callback of the **Web** component.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  webviewController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          if (this.webviewController.accessBackward()) {
            this.webviewController.backward();
          }
        })
      Web({ src: 'https://www.example.com/', controller: this.webviewController })
        .onAppear(() => {
          // The second parameter specifies whether to preconnect to a URL. The value false means that only DNS resolution is conducted on the URL.
          // The third parameter indicates the number of sockets to be preconnected. A maximum of six sockets are allowed.
          webview.WebviewController.prepareForPageLoad('https://www.example.com/', true, 2);
        })
    }
  }
}
```

You can also use [initializeBrowserEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine) to initialize the web kernel in advance, and then call
[prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10) after the kernel is initialized. This method is applicable to preparsing and preconnecting of the home page.
.

  In the following example, the web kernel is initialized in advance and the home page is preconnected in **onCreate** of the UIAbility.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Replace 'https://www.example.com' with the actual URL to be accessed.
    webview.WebviewController.prepareForPageLoad("https://www.example.com/", true, 2);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

## Prefetching

Based on predictions as to what page is to be loaded or visited, you can use [prefetchPage()](../reference/apis-arkweb/js-apis-webview.md#prefetchpage10) for prefetching.

Prefetching downloads all resources required by the page, including the main resources and subresources, but does not execute the JavaScript code of the page. Before calling **prefetchPage()**, you must create a **WebviewController** instance bound to the **Web** component.

In the following example, prefetching of a page is triggered in **onPageEnd**.
  
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  webviewController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController })
        .onPageEnd(() => {
          // Prefetch the page at https://www.iana.org/help/example-domains.
          this.webviewController.prefetchPage('https://www.iana.org/help/example-domains');
        })
    }
  }
}
```

## Prefetching a POST Request

You can prefetch POST requests in the page that is about to be loaded using the [prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12) API. At the end of the page load, you can clear the cache of the prefetched requests that are no longer needed using the [clearPrefetchedResource()](../reference/apis-arkweb/js-apis-webview.md#clearprefetchedresource12) API.

  The following is an example: In the **onAppear** event of the **Web** component, prefetch the POST request for the page that is about to be loaded; in the **onPageEnd** event, you can clear the cache of the prefetched POST request that is no longer needed.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  webviewController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: "https://www.example.com/", controller: this.webviewController })
        .onAppear(() => {
          // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
          webview.WebviewController.prefetchResource(
            {
              url: "https://www.example1.com/post?e=f&g=h",
              method: "POST",
              formData: "a=x&b=y",
            },
            [{
              headerKey: "c",
              headerValue: "z",
            },],
            "KeyX", 500);
        })
        .onPageEnd(() => {
          // Clear the cache of prefetched resources that are no longer used.
          webview.WebviewController.clearPrefetchedResource(["KeyX",]);
        })
    }
  }
}
```

If you can predict that a **\<Web>** component is about to load a page or is about to navigate to a page that includes a POST request, you can use [prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12) to prefetch the POST request for the page.

  Here is an example of how you might initiate prefetching of a POST request for a page to visit, in the **onPageEnd** callback:

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  webviewController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController })
        .onPageEnd(() => {
          // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
          webview.WebviewController.prefetchResource(
            {
              url: "https://www.example1.com/post?e=f&g=h",
              method: "POST",
              formData: "a=x&b=y",
            },
            [{
              headerKey: "c",
              headerValue: "z",
            },],
            "KeyX", 500);
        })
    }
  }
}
```

You can also initialize the ArkWeb engine in advance using the [initializeBrowserEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine) API, and then call [prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12) to prefetch the POST request for the page that will be loaded soon. This approach is suitable for prefetching POST requests for the home page in advance.

  In the following example, the web engine is initialized in advance and the POST request of the home page is preobtained in **onCreate()** of the ability.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log("EntryAbility onCreate");
    webview.WebviewController.initializeWebEngine();
    // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
    webview.WebviewController.prefetchResource(
      {
        url: "https://www.example1.com/post?e=f&g=h",
        method: "POST",
        formData: "a=x&b=y",
      },
      [{
        headerKey: "c",
        headerValue: "z",
      },],
      "KeyX", 500);
    AppStorage.setOrCreate("abilityWant", want);
    console.log("EntryAbility onCreate done");
  }
}
```

## Precompiling for the Compilation Cache

You can use [precompileJavaScript()](../reference/apis-arkweb/js-apis-webview.md#precompilejavascript12) to generate the compilation cache of the script file before page loading.

You are advised to use this function together with dynamic components, use offline **Web** components to generate bytecode caches, and load the service **Web** component at the appropriate time to use the bytecode caches. The example code is as follows:

1. Save **UIContext** to **localStorage** in **EntryAbility**.

   ```ts
   // EntryAbility.ets
   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';

   const localStorage: LocalStorage = new LocalStorage('uiContext');

   export default class EntryAbility extends UIAbility {
     storage: LocalStorage = localStorage;

     onWindowStageCreate(windowStage: window.WindowStage) {
       windowStage.loadContent('pages/Index', this.storage, (err, data) => {
         if (err.code) {
           return;
         }

         this.storage.setOrCreate<UIContext>("uiContext", windowStage.getMainWindowSync().getUIContext());
       });
     }
   }
   ```

2. Compile the basic code of the dynamic component.

   ```ts
   // DynamicComponent.ets
   import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

   export interface BuilderData {
     url: string;
     controller: WebviewController;
   }

   const storage = LocalStorage.getShared();

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>) {
       super();
       this.wrappedBuilder = wrappedBuilder;
     }

     makeNode(): FrameNode | null {
       if (this.rootNode != null) {
         return this.rootNode.getFrameNode();
       }
       return null;
     }

     initWeb(url: string, controller: WebviewController) {
       if(this.rootNode != null) {
         return;
       }

       const uiContext: UIContext = storage.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder);
     baseNode.initWeb(data.url, data.controller);
     return baseNode;
   }
   ```

3. Compile the component for generating the bytecode cache. In this example, the local Javascript resource reads the local file in the **rawfile** directory through **readRawFile()**.

   ```ts
   // PrecompileWebview.ets
   import { BuilderData } from "./DynamicComponent";
   import { Config, configs } from "./PrecompileConfig";

   @Builder
   function WebBuilder(data: BuilderData) {
     Web({ src: data.url, controller: data.controller })
       .onControllerAttached(() => {
         precompile(data.controller, configs);
       })
       .fileAccess(true)
   }

   export const precompileWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export const precompile = async (controller: WebviewController, configs: Array<Config>) => {
     for (const config of configs) {
       let content = await readRawFile(config.localPath);

       try {
         controller.precompileJavaScript(config.url, content, config.options)
           .then(errCode => {
             console.error("precompile successfully! " + errCode);
           }).catch((errCode: number) => {
             console.error("precompile failed. " + errCode);
         });
       } catch (err) {
         console.error("precompile failed. " + err.code + " " + err.message);
       }
     }
   }

   async function readRawFile(path: string) {
     try {
       return await getContext().resourceManager.getRawFileContent(path);;
     } catch (err) {
       return new Uint8Array(0);
     }
   }
   ```

JavaScript resources can also be obtained through [Data Request](../reference/apis-network-kit/js-apis-http.md). However, the format of HTTP response header obtained using this method is not standard. Additional steps are required to convert the response header into the standard HTTP response header format before use. If the response header obtained through a network request is **e-tag**, convert it to **E-Tag** before using it.

4. Compile the code of the service component.

   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // The component can be extended as required.
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. Edit the resource configuration information.

   ```ts
   // PrecompileConfig.ets
   import { webview } from '@kit.ArkWeb'

   export interface Config {
     url:  string,
     localPath: string, // Local resource path.
     options: webview.CacheOptions
   }

   export let configs: Array<Config> = [
     {
       url: "https://www.example.com/example.js",
       localPath: "example.js",
       options: {
         responseHeaders: [
           { headerKey: "E-Tag", headerValue: "aWO42N9P9dG/5xqYQCxsx+vDOoU="},
           { headerKey: "Last-Modified", headerValue: "Wed, 21 Mar 2024 10:38:41 GMT"}
         ]
       }
     }
   ]
   ```

6. Use the components on the page.

   ```ts
   // Index.ets
   import { webview } from '@kit.ArkWeb';
   import { NodeController } from '@kit.ArkUI';
   import { createNode } from "./DynamicComponent"
   import { precompileWebview } from "./PrecompileWebview"
   import { businessWebview } from "./BusinessWebview"
   
   @Entry
   @Component
   struct Index {
     @State precompileNode: NodeController | undefined = undefined;
     precompileController: webview.WebviewController = new webview.WebviewController();
   
     @State businessNode: NodeController | undefined = undefined;
     businessController: webview.WebviewController = new webview.WebviewController();
   
     aboutToAppear(): void {
       // Initialize the Web component used to inject local resources.
       this.precompileNode = createNode(precompileWebview,
         { url: "https://www.example.com/empty.html", controller: this.precompileController});
     }

     build() {
       Column() {
         // Load the service Web component at a proper time. In this example, the Web component is used in a button onclick event.
         Button ("Loading page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url:  "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

If you want to update the local generated compiled bytecode, edit the value of **E-Tag** or **Last-Modified** in the **responseHeaders** parameter of **cacheOptions**, and call the API again.

## Injecting Offline Resources Without Interception
You can use [injectOfflineResources()](../reference/apis-arkweb/js-apis-webview.md#injectofflineresources12) to inject images, style sheets, or script resources to the memory cache of applications before page loading.

You are advised to use this function together with dynamic components, use offline **Web** components to inject resources into the memory cache of the kernel, and load the service **Web** component at the appropriate time to use these resources. The example code is as follows:

1. Save **UIContext** to **localStorage** in **EntryAbility**.

   ```ts
   // EntryAbility.ets
   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';

   const localStorage: LocalStorage = new LocalStorage('uiContext');

   export default class EntryAbility extends UIAbility {
     storage: LocalStorage = localStorage;

     onWindowStageCreate(windowStage: window.WindowStage) {
       windowStage.loadContent('pages/Index', this.storage, (err, data) => {
         if (err.code) {
           return;
         }

         this.storage.setOrCreate<UIContext>("uiContext", windowStage.getMainWindowSync().getUIContext());
       });
     }
   }
   ```

2. Compile the basic code of the dynamic component.

   ```ts
   // DynamicComponent.ets
   import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

   export interface BuilderData {
     url: string;
     controller: WebviewController;
   }

   const storage = LocalStorage.getShared();

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>) {
       super();
       this.wrappedBuilder = wrappedBuilder;
     }

     makeNode(): FrameNode | null {
       if (this.rootNode != null) {
         return this.rootNode.getFrameNode();
       }
       return null;
     }

     initWeb(url: string, controller: WebviewController) {
       if(this.rootNode != null) {
         return;
       }

       const uiContext: UIContext = storage.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder);
     baseNode.initWeb(data.url, data.controller);
     return baseNode;
   }
   ```

3. Compile the component code for injecting resources. In this example, the local resource reads the local file in the **rawfile** directory through **readRawFile()**.

   <!--code_no_check-->
   ```ts
   // InjectWebview.ets
   import { webview } from '@kit.ArkWeb';
   import { resourceConfigs } from "./Resource";
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     Web({ src: data.url, controller: data.controller })
       .onControllerAttached(async () => {
         try {
           data.controller.injectOfflineResources(await getData ());
         } catch (err) {
           console.error("error: " + err.code + " " + err.message);
         }
       })
       .fileAccess(true)
   }

   export const injectWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export async function getData() {
     const resourceMapArr: Array<webview.OfflineResourceMap> = [];

     // Read the configuration, and read the file content from the rawfile directory.
     for (let config of resourceConfigs) {
       let buf: Uint8Array = new Uint8Array(0);
       if (config.localPath) {
         buf = await readRawFile(config.localPath);
       }

       resourceMapArr.push({
         urlList: config.urlList,
         resource: buf,
         responseHeaders: config.responseHeaders,
         type: config.type,
       })
     }

     return resourceMapArr;
   }

   export async function readRawFile(url: string) {
     try {
       return await getContext().resourceManager.getRawFileContent(url);
     } catch (err) {
       return new Uint8Array(0);
     }
   }
   ```

4. Compile the code of the service component.

   <!--code_no_check-->
   ```ts
   // BusinessWebview.ets
   import { BuilderData } from "./DynamicComponent";

   @Builder
   function WebBuilder(data: BuilderData) {
     // The component can be extended as required.
     Web({ src: data.url, controller: data.controller })
       .cacheMode(CacheMode.Default)
   }

   export const businessWebview = wrapBuilder<BuilderData[]>(WebBuilder);
   ```

5. Edit the resource configuration information.

   ```ts
   // Resource.ets
   import { webview } from '@kit.ArkWeb';

   export interface ResourceConfig {
     urlList: Array<string>,
     type: webview.OfflineResourceType,
     responseHeaders: Array<Header>,
     localPath: string, // The path for storing local resources in the rawfile directory.
   }

   export const resourceConfigs: Array<ResourceConfig> = [
     {
       localPath: "example.png",
       urlList: [
         "https://www.example.com/",
         "https://www.example.com/path1/example.png",
         "https://www.example.com/path2/example.png",
       ],
       type: webview.OfflineResourceType.IMAGE,
       responseHeaders: [
         { headerKey: "Cache-Control", headerValue: "max-age=1000" },
         { headerKey: "Content-Type", headerValue: "image/png" },
       ]
     },
     {
       localPath: "example.js",
       urlList: [ // Only one URL is provided. This URL is used as both the resource origin and the network request address of the resource.
         "https://www.example.com/example.js",
       ],
       type: webview.OfflineResourceType.CLASSIC_JS,
       responseHeaders: [
         // Used in <script crossorigin="anoymous" /> mode to provide additional response headers.
         { headerKey: "Cross-Origin", headerValue:"anonymous" }
       ]
     },
   ];
   ```

6. Use the components on the page.
   ```ts
   // Index.ets
   import { webview } from '@kit.ArkWeb';
   import { NodeController } from '@kit.ArkUI';
   import { createNode } from "./DynamicComponent"
   import { injectWebview } from "./InjectWebview"
   import { businessWebview } from "./BusinessWebview"

   @Entry
   @Component
   struct Index {
     @State injectNode: NodeController | undefined = undefined;
     injectController: webview.WebviewController = new webview.WebviewController();

     @State businessNode: NodeController | undefined = undefined;
     businessController: webview.WebviewController = new webview.WebviewController();

     aboutToAppear(): void {
       // Initialize the Web component used to inject local resources and provide an empty HTML page as the URL.
       this.injectNode = createNode(injectWebview,
           { url: "https://www.example.com/empty.html", controller: this.injectController});
     }

     build() {
       Column() {
         // Load the service Web component at a proper time. In this example, the Web component is used in a button onclick event.
         Button ("Loading page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url: "https://www.example.com/business.html",
               controller: this.businessController
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

7. The example of a loaded HTML web page is as follows.

   ```HTML
   <!DOCTYPE html>
   <html lang="en">
   <head></head>
   <body>
     <img src="https://www.example.com/path1/request.png" />
     <img src="https://www.example.com/path2/request.png" />
     <script src="https://www.example.com/example.js" crossorigin="anonymous"></script>
   </body>
   </html>
   ```
