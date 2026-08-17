# Setting the Backward-Forward Cache

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=d20d6855ac78addb0cb6074894aeba9f67de158d translatedAt=2026-08-14T03:51:33.447Z pushedAt=2026-08-14T09:45:23.125Z -->

The **Web** component provides the function of enabling and configuring the back-forward cache (BFCache), which can significantly improve the speed of returning to the previous web page, especially for users with poor network conditions.

After BFCache is enabled, the **Web** component saves the snapshot of the current page in the memory when the user leaves the current page. When the user accesses the same page again within a short period of time, the page can be quickly restored to avoid repeated HTTP requests.

## Enabling BFCache

Before calling [initializeWebEngine()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine) to initialize the ArkWeb kernel, you need to call [enableBackForwardCache()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enablebackforwardcache12) to enable BFCache. The **enableBackForwardCache** function receives the [BackForwardCacheSupportedFeatures](../reference/apis-arkweb/arkts-apis-webview-BackForwardCacheSupportedFeatures.md) parameter, which is used to control whether to allow pages with the same-layer rendering feature and video takeover feature to enter the BFCache.

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

After BFCache is enabled, only one page can be stored by default, and a page that enters BFCache in the **Web** component can remain alive for 600 seconds by default. You can call [setBackForwardCacheOptions()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setbackforwardcacheoptions12) to set the back-forward cache policy for each **Web** instance. This includes adjusting the maximum number of pages in the cache so that BFCache can hold more pages, providing faster loading when the user performs consecutive back and forward operations. In addition, you can modify the retention time of each page in the cache to extend how long pages stay in BFCache, thereby optimizing the browsing experience.

In the following example, the maximum number of pages that can be cached in the **Web** component is set to **10**, and each page is cached for 300s.

<!-- @[web_module_page_set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageLoadBrowse/NetReqInterceptCacheWinOps/entry2/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Row() {
        Button('Add options').onClick((event: ClickEvent) => {
          let options = new webview.BackForwardCacheOptions();
          options.size = 10;
          options.timeToLive = 300;
          this.controller.setBackForwardCacheOptions(options);
        })
        Button('Backward').onClick((event: ClickEvent) => {
          this.controller.backward();
        })
        Button('Forward').onClick((event: ClickEvent) => {
          this.controller.forward();
        })
      }
      Web({ src: 'https://www.example.com', controller: this.controller })
    }
    .height('100%')
    .width('100%')
  }
}
```