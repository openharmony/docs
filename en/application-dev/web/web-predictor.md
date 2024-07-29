# Accelerating Web Page Access

When the web page loads slowly, you can use the capabilities of pre-connection, preloading, and prefetching POST requests to accelerate the access to the web page.

## Preparsing and Preconnecting

You can call [prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10) to preparse or preconnect to the page to be loaded.

  In the following example, the page to be loaded is preconnected in the **onAppear** callback of the **Web** component.

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          if (this.webviewController.accessBackward()) {
            this.webviewController.backward();
          }
        })
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
        .onAppear(() => {
            // The second parameter specifies whether to preconnect to a URL. The value false means that only DNS resolution is conducted on the URL.
            // The third parameter indicates the number of sockets to be preconnected. A maximum of six sockets are allowed.
            web_webview.WebviewController.prepareForPageLoad('https://www.example.com/', true, 2);
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
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        web_webview.WebviewController.initializeWebEngine();
        // Replace 'https://www.example.com' with the actual URL to be accessed.
        web_webview.WebviewController.prepareForPageLoad("https://www.example.com/", true, 2);
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
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
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
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: "https://www.example.com/", controller: this.webviewController})
        .onAppear(() => {
            // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
            web_webview.WebviewController.prefetchResource(
              {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
              [{headerKey:"c",
                headerValue:"z",},],
              "KeyX", 500);
        })
        .onPageEnd(() => {
            // Clear the cache of prefetched resources that are no longer used.
            web_webview.WebviewController.clearPrefetchedResource(["KeyX",]);
        })
    }
  }
}
```

If you can predict that a **Web** component is about to load a page or is about to navigate to a page that includes a POST request, you can use [prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12) to prefetch the POST request for the page.

  Here is an example of how you might initiate prefetching of a POST request for a page to visit, in the **onPageEnd** callback:

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
        .onPageEnd(() => {
            // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
            web_webview.WebviewController.prefetchResource(
              {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
              [{headerKey:"c",
                headerValue:"z",},],
              "KeyX", 500);
        })
    }
  }
}
```

You can also initialize the ArkWeb engine in advance using the [initializeBrowserEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine) API, and then call [prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12) to prefetch the POST request for the page that will be loaded soon. This approach is suitable for prefetching POST requests for the home page in advance.

  In the following example, the web engine is initialized in advance and the POST request of the home page is preobtained in **onCreate** of the ability,.

```ts
// xxx.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        web_webview.WebviewController.initializeWebEngine();
        // Replace https://www.example1.com/post?e=f&g=h with the actual URL of the POST request to prefetch.
        web_webview.WebviewController.prefetchResource(
          {url:"https://www.example1.com/post?e=f&g=h",
          method:"POST",
          formData:"a=x&b=y",},
          [{headerKey:"c",
            headerValue:"z",},],
          "KeyX", 500);
        AppStorage.setOrCreate("abilityWant", want);
        console.log("EntryAbility onCreate done");
    }
}
```
