# @ohos.advertising.AdComponent (Non-Full-Screen Ad Component)


The AdComponent module provides the capability of displaying non-full-screen ads.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { AdComponent } from '@ohos.advertising.AdComponent';
```


## AdComponent

AdComponent(ads: Array&lt;advertising.Advertisement&gt;, displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener): void

Shows a non-full-screen ad.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11


**Parameters**


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| ads | Array&lt;advertising.[Advertisement](js-apis-advertising.md#advertisement)&gt; | Yes| Array of ad objects.|
| displayOptions | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions) | Yes| Ad display parameters.|
| interactionListener | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | Yes| Ad status change callback.|

**Example**

```ts
import advertising from '@ohos.advertising';
import { AdComponent } from '@ohos.advertising.AdComponent';
import hilog from '@ohos.hilog';

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
      // The AdComponent is used to show the non-full-screen ad.
      AdComponent({ ads: this.ads, displayOptions: this.adDisplayOptions,
        interactionListener: {
          // Ad status change callback.
          onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {
            switch(status) {
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
          }}})
        .width('100%')
        .height('100%')
    }.width('100%').height('100%')
  }
}
```
