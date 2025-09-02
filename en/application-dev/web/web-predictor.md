# Accelerating Web Page Access

When the web page loads slowly, you can use the capabilities of pre-connection, preloading, and prefetching POST requests to accelerate the access to the web page.
For details about how to optimize the web page loading performance, see [Performance Optimization for Web Page Loading](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-web-develop-optimization#section128761465256).

## Preparsing and Preconnecting

You can preparse or preconnect to the page to be loaded using [prepareForPageLoad()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prepareforpageload10), which is used for domain name-level optimization. This method only performs DNS resolution on URLs and establishes TCP connections, but does not obtain main resources and subresources.

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

You can also use [initializeWebEngine()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine) to initialize the web kernel in advance, and then call
[prepareForPageLoad()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prepareforpageload10) after the kernel is initialized. This method is applicable to preparsing and preconnecting of the home page.
 

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

This method is used for resource-level optimization. Based on predictions as to what page is to be loaded or visited, you can use [prefetchPage()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prefetchpage10) for prefetching.

Prefetching downloads the resources required by the page in advance, including main resources and subresources, to avoid blocking page rendering. However, the JavaScript code of the web page is not executed. Before calling **prefetchPage()**, you must create a **WebviewController** instance bound to the **Web** component.

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

This method is used for request-level optimization. You can use [prefetchResource()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prefetchresource12) to prefetch a POST request on the page to be loaded. When the page loading is complete, you can use [clearPrefetchedResource()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#clearprefetchedresource12) to clear the cached prefetched resources that are no longer used.

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

If you can predict that a **Web** component is about to load a page or is about to navigate to a page that includes a POST request, you can use [prefetchResource()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prefetchresource12) to prefetch the POST request on the page to be loaded.

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

You can also use [initializeWebEngine()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine) to initialize the kernel in advance, and then call [prefetchResource()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#prefetchresource12) to prefetch the POST request on the page to be loaded after the kernel is initialized. This approach is suitable for prefetching POST requests for the home page in advance.

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

You can use [precompileJavaScript()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#precompilejavascript12) to generate the compilation cache of the script file before page loading.

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
     context: UIContext;
   }

   let storage : LocalStorage | undefined = undefined;

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>, context: UIContext) {
       storage = context.getSharedLocalStorage();
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

       const uiContext: UIContext = storage!.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder, data.context);
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
         precompile(data.controller, configs, data.context);
       })
       .fileAccess(true)
   }

   export const precompileWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export const precompile = async (controller: WebviewController, configs: Array<Config>, context: UIContext) => {
     for (const config of configs) {
       let content = await readRawFile(config.localPath, context);

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

   async function readRawFile(path: string, context: UIContext) {
     try {
       return await context.getHostContext()!.resourceManager.getRawFileContent(path);;
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
         { url: "https://www.example.com/empty.html", controller: this.precompileController, context: this.getUIContext()});
     }

     build() {
       Column() {
         // Load the service Web component at a proper time. In this example, the Web component is used in a button onclick event.
         Button ("Loading page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url:  "https://www.example.com/business.html",
               controller: this.businessController,
               context: this.getUIContext()
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
You can use [injectOfflineResources()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#injectofflineresources12) to inject images, style sheets, or script resources to the memory cache of applications before page loading.

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
     context: UIContext;
   }

   let storage : LocalStorage | undefined = undefined;

   export class NodeControllerImpl extends NodeController {
     private rootNode: BuilderNode<BuilderData[]> | null = null;
     private wrappedBuilder: WrappedBuilder<BuilderData[]> | null = null;

     constructor(wrappedBuilder: WrappedBuilder<BuilderData[]>,  context: UIContext) {
      storage = context.getSharedLocalStorage();
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

       const uiContext: UIContext = storage!.get<UIContext>("uiContext") as UIContext;
       if (!uiContext) {
         return;
       }
       this.rootNode = new BuilderNode(uiContext);
       this.rootNode.build(this.wrappedBuilder, { url: url, controller: controller });
     }
   }

   export const createNode = (wrappedBuilder: WrappedBuilder<BuilderData[]>, data: BuilderData) => {
     const baseNode = new NodeControllerImpl(wrappedBuilder, data.context);
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
           data.controller.injectOfflineResources(await getData (data.context));
         } catch (err) {
           console.error("error: " + err.code + " " + err.message);
         }
       })
       .fileAccess(true)
   }

   export const injectWebview = wrapBuilder<BuilderData[]>(WebBuilder);

   export async function getData(context: UIContext) {
     const resourceMapArr: Array<webview.OfflineResourceMap> = [];

     // Read the configuration, and read the file content from the rawfile directory.
     for (let config of resourceConfigs) {
       let buf: Uint8Array = new Uint8Array(0);
       if (config.localPath) {
         buf = await readRawFile(config.localPath, context);
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

   export async function readRawFile(url: string, context: UIContext) {
     try {
       return await context.getHostContext()!.resourceManager.getRawFileContent(url);
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
         // Used in <script crossorigin="anonymous"/> mode to provide additional response headers.
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
           { url: "https://www.example.com/empty.html", controller: this.injectController, context: this.getUIContext()});
     }

     build() {
       Column() {
         // Load the service Web component at a proper time. In this example, the Web component is used in a button onclick event.
         Button ("Loading page")
           .onClick(() => {
             this.businessNode = createNode(businessWebview, {
               url: "https://www.example.com/business.html",
               controller: this.businessController,
               context: this.getUIContext()
             });
           })
         // The Web component used for the service.
         NodeContainer(this.businessNode);
       }
     }
   }
   ```

7. Example of a loaded HTML web page:

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
