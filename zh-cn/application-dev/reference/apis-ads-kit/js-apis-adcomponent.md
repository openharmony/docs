# @ohos.advertising.AdComponent (非全屏广告展示组件)


本模块提供展示非全屏广告的能力。


> **说明：**
> 本模块首批接口从API Version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { AdComponent } from '@kit.AdsKit';
```


## AdComponent

AdComponent(ads: Array<advertising.Advertisement>, displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener, adRenderer:() => void): void

展示非全屏广告。

**元服务API：** 从API version12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**


| **参数名** | **类型** | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| ads | Array&lt;advertising.[Advertisement](js-apis-advertising.md#advertisement)&gt; | 是 | 广告对象数组。 | 
| displayOptions | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions) | 是 | 广告展示参数。 | 
| interactionListener | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | 是 | 广告状态变化回调。 | 
| adRenderer<sup>12+</sup> | () => void | 否 | 应用自渲染广告样式。 | 

**示例：**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
export struct ShowNonFullScreenAd {
  // 请求到的广告内容
  private ads: Array<advertising.Advertisement> = [];
  // 广告展示参数
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // 是否静音，默认不静音
    mute: false,
  }

  build() {
    Column() {
      // AdComponent组件用于展示非全屏广告
      AdComponent({
        ads: this.ads, displayOptions: this.adDisplayOptions,
        interactionListener: {
          // 广告状态变化回调
          onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {
            switch (status) {
              case 'onAdOpen':
                hilog.info(0x0000, 'testTag', '%{public}s', 'onAdOpen');
                break;
              case 'onAdClick':
                hilog.info(0x0000, 'testTag', '%{public}s', 'onAdClick');
                break;
              case 'onAdClose':
                hilog.info(0x0000, 'testTag', '%{public}s', 'onAdClose');
                break;
            }
          }
        }
      })
        .width('100%')
        .height('100%')
    }.width('100%').height('100%')
  }
}
```
应用自渲染广告仅限原生广告，应用要在AdRequestParams中设置needSelfRendering。返回的Advertisement中带有canSelfRendering为true，且应用的包名在应用自渲染白名单中才能正常展示。
```

**展示应用自渲染广告示例：**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
export struct ShowSelfRenderAd {
  // 请求到的广告内容
  private ads: Array<advertising.Advertisement> = [];
  // 广告展示参数
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // 是否静音，默认不静音
    mute: false,
  };
  // 视频播放控制器
  private controller: VideoController | undefined;

  @Builder
  componentBuilder() {
    Column() {
      Video({
        src: "xxx.mp4",
        controller: this.controller,

      }).autoPlay(true)
        .width('100%')
        .height('100%')
    }
  }

  build() {
    Column() {
      AdComponent({
        ads: this.ads,
        displayOptions: this.adDisplayOptions,
        interactionListener: {
          // 广告状态变化回调
          onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {
            switch(status) {
              case 'onAdClick':
                hilog.info(0x0000, 'testTag', '%{public}s', 'onAdClick');
                break;
              default:
            }
          }
        },
        adRenderer: this.componentBuilder
      })
        .width('100%')
        .height('100%')
    }.width('100%').height('100%')
  }
}
```
