# Web前进后退缓存

开启Web组件的前进后退缓存功能，在前进后退的场景达到秒开的效果。

## 开启前进后退缓存

可以通过[enableBackForwardCache()](../reference/apis-arkweb/js-apis-webview.md#enablebackforwardcache12)来开启Web组件使用前进后退缓存的功能。

需要在[initializeWebEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine)初始化内核之前调用。

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

可以通过[setBackForwardCacheOptions()](../reference/apis-arkweb/js-apis-webview.md#setbackforwardcacheoptions12)来设置每一个Web示例前进后退缓存的策略。

在下面的示例中，设置Web组件可以缓存的最大数量为10，每个页面在缓存中停留300s。
  
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
