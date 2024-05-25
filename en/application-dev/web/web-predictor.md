# Accelerating Web Page Access with Preconnecting and Prefetching

## Preparsing and Preconnecting

You can call [prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10) to preparse or preconnect to the page to be loaded.

  In the following example, the page to be loaded is preconnected in the **onAppear** callback of the **\<Web>** component.

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

Prefetching downloads all resources required by the page, including the main resources and subresources, but does not execute the JavaScript code of the page. Before calling **prefetchPage()**, you must create a **WebviewController** instance bound to the **\<Web>** component.

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
