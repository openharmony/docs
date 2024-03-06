# @ohos.advertising (Ads Service Framework)


The advertising module provides APIs for requesting and displaying ads.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import advertising from '@ohos.advertising';
```


## constructor

constructor(context?: common.Context);

Constructor.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | common.[Context](js-apis-inner-application-context.md) | No| Context of the ability or application.|

**Example**

For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md#overview).

```ts
import advertising from '@ohos.advertising';
import common from '@ohos.app.ability.common';

function createConstructor(context: common.Context): void {
  const load: advertising.AdLoader = new advertising.AdLoader(context);
}
```


## advertising.loadAd

loadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, listener: advertising.AdLoadListener): void

Loads an ad.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adParam | advertising.[AdRequestParams](#adrequestparams) | Yes| Ad request parameters.|
| adOptions | advertising.[AdOptions](#adoptions) | Yes| Ad configuration.|
| listener | advertising.[AdLoadListener](#adloadlistener) | Yes| Ad request callback.|

**Error codes**

For details about the following error codes, see [Ads Service Framework Error Codes](../errorcodes/errorcode-ads.md).

| ID| Error Message|
| -------- | -------- |
| 21800001 | System internal error. |
| 21800003 | Failed to load the ad request. |

**Example**

For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md#overview).

```ts
import advertising from '@ohos.advertising';
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog'; 

function requestAd(context: common.Context): void {
  const adRequestParam: advertising.AdRequestParams = {
    // Ad type.
    adType: 3,
    // Ad ID.
    adId: "test1", 
  };
  const adOptions: advertising.AdOptions = {
    // Set the maximum ad content rating.
    adContentClassification: 'A',
  };
  // Listener for the ad loading status.
  const adLoaderListener: advertising.AdLoadListener = {
    // Called when the ad request fails.
    onAdLoadFailure: (errorCode: number, errorMsg: string) => {
      hilog.error(0x0000, 'testTag', '%{public}s', `request single ad errorCode is: ${errorCode}, errorMsg is: ${errorMsg}`);
    },
    // Called when the ad request is successful.
    onAdLoadSuccess: (ads: Array<advertising.Advertisement>) => {
      hilog.info(0x0000, 'testTag', '%{public}s', 'request single ad success!');
      // Save the requested ad content for display.
      const returnAds = ads;
    }
  };
  // Create an AdLoader object.
  const load: advertising.AdLoader = new advertising.AdLoader(context);
  // Load the ad.
  hilog.info(0x0000, 'testTag', '%{public}s', 'request single ad!');
  load.loadAd(adRequestParam, adOptions, adLoaderListener);
}
```


## advertising.loadAdWithMultiSlots

loadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions, listener: advertising.MultiSlotsAdLoadListener): void

Loads multiple ads.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adParams | advertising.[AdRequestParams](#adrequestparams)[] | Yes| Ad request parameters.|
| adOptions | advertising.[AdOptions](#adoptions) | Yes| Ad configuration.|
| listener | advertising.[MultiSlotsAdLoadListener](#multislotsadloadlistener) | Yes| Ad request callback.|

**Error codes**

For details about the following error codes, see [Ads Service Framework Error Codes](../errorcodes/errorcode-ads.md).

| ID| Error Message|
| -------- | -------- |
| 21800001 | System internal error. |
| 21800003 | Failed to load the ad request. |

**Example**

For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md#overview).

```ts
import advertising from '@ohos.advertising';
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog'; 

function requestMultiAd(context: common.Context): void {
  const adRequestParamArray: advertising.AdRequestParams[] = [{
      // Ad type.
      adType: 3,
      // Ad ID.
      adId: "test1",
    } as advertising.AdRequestParams,
    {
      // Ad type.
      adType: 3,
      // Ad ID.
      adId: "test2", 
    } as advertising.AdRequestParams
  ];
  const adOptions: advertising.AdOptions = {
    // Set the maximum ad content rating.
    adContentClassification: 'A',
  };
  // Listener for the ad loading status.
  const multiSlotsAdLoaderListener: advertising.MultiSlotsAdLoadListener = {
    // Called when the ad request fails.
    onAdLoadFailure: (errorCode: number, errorMsg: string) => {
      hilog.error(0x0000, 'testTag', '%{public}s', `request multi ads errorCode is: ${errorCode}, errorMsg is: ${errorMsg}`);
    },
    // Called when the ad request is successful.
    onAdLoadSuccess: (ads: Map<string, Array<advertising.Advertisement>>) => {
      hilog.info(0x0000, 'testTag', '%{public}s', 'request multi ads success!');
      // Save the requested ad content for display.
      let returnAds: Array<advertising.Advertisement> = [];
      ads.forEach((adsArray) => returnAds.push(...adsArray));
    }
  };
  // Create an AdLoader object.
  const load: advertising.AdLoader = new advertising.AdLoader(context);
  // Load the ad.
  hilog.info(0x0000, 'testTag', '%{public}s', 'request multi ads!');
  load.loadAdWithMultiSlots(adRequestParamArray, adOptions, multiSlotsAdLoaderListener);
}
```


## advertising.showAd

showAd(ad: advertising.Advertisement, options: advertising.AdDisplayOptions, context?: common.UIAbilityContext): void

Shows a full-screen ad.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| ad | advertising.[Advertisement](#advertisement) | Yes| Ad object.|
| options | advertising.[AdDisplayOptions](#addisplayoptions) | Yes| Ad display parameters.|
| context | common.[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | No| UIAbility context.|


**Error codes**


For details about the following error codes, see [Ads Service Framework Error Codes](../errorcodes/errorcode-ads.md).


| ID| Error Message|
| -------- | -------- |
| 21800001 | System internal error. |
| 21800004 | Failed to display the ad. |


**Example**

```ts
import advertising from '@ohos.advertising';
import hilog from '@ohos.hilog'; 
import common from '@ohos.app.ability.common';

@Component
export struct ShowAd {
  private context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
  // Requested ad content.
  private ad?: advertising.Advertisement;
  // Ad display parameters.
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // Whether to mute the ad. By default, the ad is not muted.
    mute: false,
  }

  build() {
    Column() {
        Button ('Show Ad')
          .onClick(() => {
            try {
              // Show the ad.
              advertising.showAd(this.ad, this.adDisplayOptions, this.context);
            } catch (err) {
              hilog.error(0x0000, 'testTag', '%{public}s', `show ad catch error: ${err.code} ${err.message}`);
            }
          });
    }
    .width('100%')
    .height('100%')
  }
}
```


## AdOptions

Defines the ad configuration.

**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tagForChildProtection | number | No| Whether to process the ad request according to the Children's Online Privacy Protection Act (COPPA).<br>- **-1**: You do not want to specify whether the ad content needs to be COPPA-compliant.<br>- **0**: The ad content does not need to be COPPA-compliant.<br>- **1**: The ad content must be COPPA-compliant (no ad will be returned for this ad request).|
| adContentClassification | string | No| Maximum ad content rating.<br>- **W**: content suitable for toddlers and older audiences.<br>- **PI**: content suitable for kids and older audiences.<br>- **J**: content suitable for teenagers and older audiences.<br>- **A**: content only suitable for adults.|
| nonPersonalizedAd | number | No| Whether to request non-personalized ads.<br>- **0**: request for personalized and non-personalized ads.<br>- **1**: request for non-personalized ads.|
| [key: string] | number \| boolean \| string \| undefined | No| Custom parameters.<br> - **totalDuration**: The value is of the number type, in seconds. This parameter is mandatory for roll ads and is used to set the total duration of roll ads.<br> - **placementAdCountDownDesc**: The value is of the string type. This parameter is optional for roll ads and is used to set the countdown description of roll ads. This parameter must be encoded using the **encodeURI()** API. If this parameter is set, the countdown description is displayed. Otherwise, only the countdown is displayed.|


## AdRequestParams

Defines the ad request parameters.

**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adId | string | Yes| Ad ID|
| adType | number | No| Type of the requested ad.<br>- **1**: splash ad.<br>- **3**: native ad.<br>- **7**: rewarded ad.<br>- **8**: banner ad.<br>- **12**: interstitial ad.<br>- **60**: roll ad.|
| adCount | number | No| Number of ads requested.|
| adWidth | number | No| Ad width.|
| adHeight | number | No| Ad height.|
| adSearchKeyword | string | No| Ad keyword.|
| [key: string] | number \| boolean \| string \| undefined | No| Custom parameters.|


## AdLoadListener

Enumerates the callbacks used for the request for loading an ad.

**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| onAdLoadFailure | function(errorCode: number, errorMsg: string): void | Yes| Called when the ad request fails.|
| onAdLoadSuccess | function(ads: Array&lt;advertising.[Advertisement](#advertisement)&gt;): void | Yes| Called when the ad request is successful.|


## MultiSlotsAdLoadListener

Enumerates the callbacks used for the request for loading multiple ads.

**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| onAdLoadFailure | function(errorCode: number, errorMsg: string): void | Yes| Called when the ad request fails.|
| onAdLoadSuccess | function(adsMap: Map&lt;string, Array&lt;advertising.[Advertisement](#advertisement)&gt;&gt;): void | Yes| Called when the ad request is successful.|


## Advertisement


Defines the requested ad content.


**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adType | number | Yes| Ad type.|
| uniqueId | string | Yes| Unique ID of the ad.|
| rewarded | boolean | No| Whether users get rewarded for watching or clicking the ad.<br>- **true**: Users get rewarded.<br>- **false**: Users do not get rewarded. |
| shown | boolean | No| Whether the ad is shown.<br>- **true**: The ad is shown.<br>- **false**: The ad is not shown.|
| clicked | boolean | No| Whether the ad is clicked.<br>- **true**: The ad is clicked.<br>- **false**: The ad is not clicked.|
| rewardVerifyConfig | Map&lt;string, string&gt; | No| Server verification parameter.<br>{<br>customData: "test",<br>userId: "12345"<br>} |
| [key: string] | Object | No| Custom parameter.<br>- **isFullScreen**: The value is of the Boolean type. This parameter is used for splash ads to specify whether such an ad is in full-screen mode. The value **true** means that the ad is in full-screen mode, and **false** means that the ad is in half-screen mode.|


## AdDisplayOptions


Defines the ad display parameters.


**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| customData | string | No| Custom media data. It is used by the server to notify the media server that a user should be rewarded for interacting with the ad, so as to avoid spoofing.|
| userId | string | No| User ID. It is used by the server to notify the media server that a user should be rewarded for interacting with the ad, so as to avoid spoofing.|
| useMobileDataReminder | boolean | No| Whether to display a dialog box to notify users when they use mobile data to play videos or download applications.<br>- **true**: A dialog box is displayed.<br>- **false**: No dialog box is displayed.|
| mute | boolean | No| Whether to mute the ad video.<br>- **true**: The ad video is muted.<br>- **false**: The ad video is not muted.|
| audioFocusType | number | No| Type of the scenario where the audio focus is obtained during video playback.<br>- **0**: The focus is obtained when the video is played in mute or non-mute mode.<br>- **1**: The focus is not obtained when the video is played in mute mode.<br>- **2**: The focus is not obtained when the video is played in mute or non-mute mode. |
| [key: string] | number \| boolean \| string \| undefined | No| Custom parameter.<br>- **refreshTime**: The value is of the number type, in ms. The value is in the range [30000, 120000]. This parameter is optional for the AutoAdComponent module and specifies the interval at which the ads rotate. If this parameter is set, ads are rotated at the interval specified by this parameter. Otherwise, ads are not rotated and only the first ad in the ad response is displayed.|


## AdInteractionListener


Defines the ad status change callback.

**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| onStatusChanged | function(status: string, ad: advertising.[Advertisement](#advertisement), data: string): void | Yes| Ad display callback.<br>1. **status**: ad display status, which can be<br>**onAdOpen**, **onAdClose**, **onAdReward**, **onAdClick**, **onVideoPlayBegin**, or **onVideoPlayEnd**.<br>2. **ad**: content of the ad.<br>3. **data**: additional information. |
