# 设置Web组件前进后退缓存

Web组件为开发者提供了启用和配置前进后退缓存（以下简称BFCache）的功能。启用此功能后，能够显著提升用户返回至先前浏览网页的速度，尤其对于网络条件不佳的用户，可提供更为流畅的浏览体验。

BFCache功能启用后，Web组件会在用户离开当前页面时在内存中保存该页面的快照。当用户在短期内通过Web组件的前进或后退功能重新访问同一页面时，能够迅速恢复页面状态，避免重复发起HTTP请求。

## Web组件开启BFCache

开发者需要在调用[initializeWebEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine)初始化ArkWeb内核之前调用[enableBackForwardCache()](../reference/apis-arkweb/js-apis-webview.md#enablebackforwardcache12)来开启BFCache。enableBackForwardCache可以接收一个[BackForwardCacheSupportedFeatures](../reference/apis-arkweb/js-apis-webview.md#backforwardcachesupportedfeatures12)参数，用于控制是否允许具备同层渲染特性和视频托管特性的页面进入BFCache。

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

## 设置缓存的页面数量和页面留存的时间

启用BFCache后仅能存储一个页面，Web组件默认进入BFCache的页面可保持存活状态600秒。开发者可通过调用[setBackForwardCacheOptions()](../reference/apis-arkweb/js-apis-webview.md#setbackforwardcacheoptions12)设置每个Web实例的前进后退缓存策略。包括调整缓存中页面的最大数量，使BFCache能够容纳更多页面，从而在用户连续进行前进后退操作时，提供更快的加载速度。同时，开发者还能修改每个页面在缓存中的停留时间，延长页面在BFCache中的驻留期限，进而优化用户的浏览体验。

在下面的示例中，设置Web组件可以缓存的最大数量为10，每个页面在缓存中停留300s。
  
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
