# Setting Backward-Forward Cache

The **Web** component provides the function of enabling and configuring the back-forward cache (BFCache), which can significantly improve the speed of returning to the previous web page, especially for users with poor network conditions.

After BFCache is enabled, the **Web** component saves the snapshot of the current page in the memory when the user leaves the current page. When the user accesses the same page again within a short period of time, the page can be quickly restored to avoid repeated HTTP requests.

## Enabling BFCache

You need to call [enableBackForwardCache()](../reference/apis-arkweb/js-apis-webview.md#enablebackforwardcache12) to enable BFCache before calling [initializeWebEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine) to initialize the ArkWeb kernel. The **enableBackForwardCache** function receives the [BackForwardCacheSupportedFeatures](../reference/apis-arkweb/js-apis-webview.md#backforwardcachesupportedfeatures12) parameter, which is used to control whether to allow pages with the same-layer rendering feature and video takeover feature to enter the BFCache.

```ts
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        let features = new webview.BackForwardCacheSupportedFeatures();
        features.nativeEmbed = true;
        features.mediaTakeOver = true;
        webview.WebviewController.enableBackForwardCache(features);
        webview.WebviewController.initializeWebEngine();
        AppStorage.setOrCreate("abilityWant", want);
    }
}
```

## Setting the Size and Live Time of Cached pages

By default, BFCache can store only one page, and the page can be stored for 600 seconds. You can call [setBackForwardCacheOptions()](../reference/apis-arkweb/js-apis-webview.md#setbackforwardcacheoptions12) to set the BFCache policies for each **Web** instance. The maximum number of pages in the BFCache can be adjusted so that it can hold more pages. In this way, BFCache can provide faster loading speed when users perform forward and backward operations continuously. In addition, you can prolong the duration of each page in the BFCache to improve user experience.

In the following example, the maximum number of pages that can be cached in the **Web** component is set to **10**, and each page is cached for 300s.
  
```ts
// Index.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button("Add options").onClick((event: ClickEvent) => {
          let options = new webview.BackForwardCacheOptions();
          options.size = 10;
          options.timeToLive = 300;
          this.controller.setBackForwardCacheOptions(options);
        })
        Button("Backward").onClick((event: ClickEvent) => {
          this.controller.backward();
        })
        Button("Forward").onClick((event: ClickEvent) => {
          this.controller.forward();
        })
      }
      Web({ src: "https://www.example.com", controller: this.controller })
    }
    .height('100%')
    .width('100%')
  }
}
```
