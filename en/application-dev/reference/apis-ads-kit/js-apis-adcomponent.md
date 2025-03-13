# @ohos.advertising.AdComponent (Non-Full-Screen Ad Component)

The AdComponent module provides the capability of displaying non-full-screen ads.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { AdComponent } from '@kit.AdsKit';
```

## AdComponent

AdComponent(ads: advertising.Advertisement[], displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener, @BuilderParam adRenderer?: () => void, @Prop rollPlayState?: number): void

Component that displays a non-full-screen ad.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**

| Name                        | Type                                                                               | Mandatory| Description                                                      | 
|-----------------------------|-----------------------------------------------------------------------------------|----|----------------------------------------------------------|
| ads                         | advertising.[Advertisement](js-apis-advertising.md#advertisement)[]               | Yes | Array of ad objects.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  | 
| displayOptions              | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions)           | Yes | Ad display parameters.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  | 
| interactionListener         | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | Yes | Ad status change callback.<br>**Atomic service API**: This API can be used in atomic services since API version 12.| 
| adRenderer<sup>12+</sup>    | () => void                                                                        | No | Ad self-rendering.                                              | 
| rollPlayState<sup>15+</sup> | number                                                                            | No | Roll ad state. The value **1** means that the roll ad is played, and the value **2** means that the roll ad is paused. Other values are invalid and the previous playback state is not changed.          | 

**Example**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct ShowNonFullScreenAd {
  // Requested ad content.
  private ads: Array<advertising.Advertisement> = [];
  // Ad display parameters.
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // Whether to mute the ad. By default, the ad is not muted.
    mute: false
  }

  build() {
    Column() {
      // The AdComponent is used to show a non-full-screen ad.
      AdComponent({
        ads: this.ads, displayOptions: this.adDisplayOptions,
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
