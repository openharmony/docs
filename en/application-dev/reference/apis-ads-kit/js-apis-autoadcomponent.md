# @ohos.advertising.AutoAdComponent (Carousel Ad Component)


The AutoAdComponent module provides the capability of displaying carousel ads.


> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { AutoAdComponent } from '@kit.AdsKit';
```


## AutoAdComponent

AutoAdComponent(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener): void

Component used to automatically play ads.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Advertising.Ads


**Parameters**


| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| adParam | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams) | Yes| Ad request parameters.| 
| adOptions | advertising.[AdOptions](js-apis-advertising.md#adoptions) | Yes| Ad configuration.| 
| displayOptions | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions) | Yes| Ad display parameters.| 
| interactionListener | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | Yes| Ad status change callback.| 


**Example**
```ts
import { AutoAdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
export struct ShowCarouselAd {
  private adRequestParam: advertising.AdRequestParams = {
    // Ad type.
    adType: 8,
    // Ad ID.
    adId: "test1"
  };
  private adOptions: advertising.AdOptions = {
    // Set the maximum ad content rating.
    adContentClassification: 'A'
  };
  // Ad display parameters.
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // Whether to mute the ad. By default, the ad is not muted.
    mute: false,
    // Interval at which the carousel items rotate, in ms. The value range is [30000, 120000].
    refreshTime: 30000
  }

  build() {
    Column() {
      // The AutoAdComponent is used to show the carousel ad in non-full-screen mode.
      AutoAdComponent({
        adParam: this.adRequestParam,
        adOptions: this.adOptions,
        displayOptions: this.adDisplayOptions,
        interactionListener: {
          // Ad status change callback.
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
