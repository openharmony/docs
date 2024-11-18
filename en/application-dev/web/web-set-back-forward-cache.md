# Setting Back-forward Cache

By enabling the back-forward cache for **Web** components, you can navigate through the visited pages smoother and faster. 

## Enabling Back-forward Cache

You can use [enableBackForwardCache()](../reference/apis-arkweb/js-apis-webview.md#enablebackforwardcache12) to enable the back-forward cache for the **Web** component.

This API must be called before calling [initializeWebEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine) to initialize the kernel.

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

You can use [setBackForwardCacheOptions()](../reference/apis-arkweb/js-apis-webview.md#setbackforwardcacheoptions12) to set the back-forward cache options for each **Web** component.

In the following example, the maximum number of pages that can be cached in the **Web** component is set to **10**, and each page is cached for 300s.
  
```ts
// xxx.ts
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
