# @ohos.advertising.AdComponent (Non-Full-Screen Ad Component)


The AdComponent module provides the capability of displaying non-full-screen ads.


> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { AdComponent } from '@kit.AdsKit';
```


## AdComponent

AdComponent(ads: Array<advertising.Advertisement>, displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener, adRenderer:() => void): void

Component that displays a non-full-screen ad.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**


| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| ads | Array&lt;advertising.[Advertisement](js-apis-advertising.md#advertisement)&gt; | Yes| Array of ad objects.| 
| displayOptions | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions) | Yes| Ad display parameters.| 
| interactionListener | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | Yes| Ad status change callback.| 
| adRenderer<sup>12+</sup> | () => void | No| Ad self-rendering.| 

**Example**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
export struct ShowNonFullScreenAd {
  // Requested ad content.
  private ads: Array<advertising.Advertisement> = [];
  // Ad display parameters.
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // Whether to mute the ad. By default, the ad is not muted.
    mute: false,
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
Ad self-rendering is applicable only to native ads. To use self-rendering, the application must set **needSelfRendering** in **AdRequestParams**. In addition, the value of **canSelfRendering** in the returned **Advertisement** object is **true**, and the application's bundle name is in the self-rendering trustlist.
```

**Example of displaying a self-rendered ad:**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
export struct ShowSelfRenderAd {
  // Requested ad content.
  private ads: Array<advertising.Advertisement> = [];
  // Ad display parameters.
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // Whether to mute the ad. By default, the ad is not muted.
    mute: false,
  };
  // Video play control.
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
          // Ad status change callback.
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
