# @ohos.advertising (Ads Service Framework)


The advertising module provides APIs for requesting and displaying ads.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import advertising from '@ohos.advertising';
```
## AdLoader

Provides the APIs for loading ads.

**System capability**: SystemCapability.Advertising.Ads

### constructor

constructor(context: common.Context);

Constructor.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | common.[Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes| Context of the ability or application.|

**Example**

For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md#overview).

```ts
import advertising from '@ohos.advertising';
import common from '@ohos.app.ability.common';

function createConstructor(context: common.Context): void {
  const load: advertising.AdLoader = new advertising.AdLoader(context);
}
```


### loadAd

loadAd(adParam: AdRequestParams, adOptions: AdOptions, listener: AdLoadListener): void

Loads an ad.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| adParam | [AdRequestParams](#adrequestparams) | Yes| Ad request parameters.| 
| adOptions | [AdOptions](#adoptions) | Yes| Ad configuration.| 
| listener | [AdLoadListener](#adloadlistener) | Yes| Ad request callback.| 

**Error codes**

For details about the following error codes, see [Ads Service Framework Error Codes](errorcode-ads.md).

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
    adId: "testy63txaom8", 
  };
  const adOptions: advertising.AdOptions = {
    // Set the maximum ad content rating.
    adContentClassification: 'A',
    // Optional custom parameter, which specifies whether the ad can be downloaded while mobile data is in use. The value 1 means that the ad can be downloaded while mobile data is in use, and 0 means the opposite.
    allowMobileTraffic: 0,
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


### loadAdWithMultiSlots

loadAdWithMultiSlots(adParams: AdRequestParams[], adOptions: AdOptions, listener: MultiSlotsAdLoadListener): void

Loads multiple ads.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| adParams | [AdRequestParams](#adrequestparams)[] | Yes| Ad request parameters.| 
| adOptions | [AdOptions](#adoptions) | Yes| Ad configuration.| 
| listener | [MultiSlotsAdLoadListener](#multislotsadloadlistener) | Yes| Ad request callback.| 

**Error codes**

For details about the following error codes, see [Ads Service Framework Error Codes](errorcode-ads.md).

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
      adId: "testy63txaom8",
    } as advertising.AdRequestParams,
    {
      // Ad type.
      adType: 3,
      // Ad ID.
      adId: "testy63txaom8", 
    } as advertising.AdRequestParams
  ];
  const adOptions: advertising.AdOptions = {
    // Set the maximum ad content rating.
    adContentClassification: 'A',
    // Optional custom parameter, which specifies whether the ad can be downloaded while mobile data is in use. The value 1 means that the ad can be downloaded while mobile data is in use, and 0 means the opposite.
    allowMobileTraffic: 0,
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


## showAd

showAd(ad: Advertisement, options: AdDisplayOptions, context?: common.UIAbilityContext): void

Shows a full-screen ad.

**System capability**: SystemCapability.Advertising.Ads

**Parameters**


| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| ad | [Advertisement](#advertisement) | Yes| Ad object.| 
| options | [AdDisplayOptions](#addisplayoptions) | Yes| Ad display parameters.| 
| context | common.[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | No| Context of the UIAbility. If this parameter is not set, the value is obtained from @ohos.app.ability.common.| 


**Error codes**


For details about the following error codes, see [Ads Service Framework Error Codes](errorcode-ads.md).


| ID| Error Message| 
| -------- | -------- |
| 21800001 | System internal error. | 
| 21800004 | Failed to display the ad. | 


**Example**

```ts
import advertising from '@ohos.advertising';
import hilog from '@ohos.hilog'; 
import common from '@ohos.app.ability.common';

@Entry
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
| tagForChildProtection | number | No| Whether you want the ad content to be treated as COPPA-compliant.<br>- **-1**: You do not want to specify whether the ad content needs to be treated as COPPA-compliant.<br>- **0**: You do not want the ad content to be treated as COPPA-compliant.<br>- **1**: You want the ad content to be treated as COPPA-compliant (no ad will be returned for this ad request).| 
| adContentClassification | string | No| Maximum ad content rating.<br>- **W**: content suitable for toddlers and older audiences.<br>- **PI**: content suitable for kids and older audiences.<br>- **J**: content suitable for teenagers and older audiences.<br>- **A**: content only suitable for adults.| 
| nonPersonalizedAd | number | No| Whether to request only non-personalized ads.<br>- **0**: request for personalized and non-personalized ads.<br>- **1**: request for only non-personalized ads.| 
| [key: string] | number \| boolean \| string \| undefined | No| Custom parameters.<br> - **totalDuration**: The value is of the number type, in seconds. This parameter is mandatory for roll ads and is used to set the total duration of roll ads.<br> - **placementAdCountDownDesc**: The value is of the string type. This parameter is optional for roll ads and is used to set the countdown description of roll ads. This parameter must be encoded using the **encodeURI()** API. If this parameter is set, the countdown description is displayed. Otherwise, only the countdown is displayed.<br> - **allowMobileTraffic**: The value is of the number type. This parameter is optional. It specifies whether ads can be downloaded while mobile data is in use. The value **1** means that ads can be downloaded while mobile data is in use, and **0** means the opposite.|


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

### onAdLoadFailure

onAdLoadFailure(errorCode: number, errorMsg: string): void

Called when an ad request fails.

**System capability**: SystemCapability.Advertising.Ads

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| errorCode | number | Yes| Result code indicating the ad request failure.| 
| errorMsg | string | Yes| Error message about the ad request failure.| 


### onAdLoadSuccess

onAdLoadSuccess(ads: Array&lt;advertising.[Advertisement](#advertisement)&gt;): void

Called when an ad request is successful.

**System capability**: SystemCapability.Advertising.Ads

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| ads | Array&lt;advertising.[Advertisement](#advertisement)&gt; | Yes| Ad data.| 


**Example**

```ts
import advertising from '@ohos.advertising';

let adLoaderListener: advertising.AdLoadListener = {
  onAdLoadFailure: (errorCode: number, errorMsg: string) => {

  },
  onAdLoadSuccess: (ads: Array<advertising.Advertisement>): void {

  }
}

```


## MultiSlotsAdLoadListener

Enumerates the callbacks used for the request for loading multiple ads.

**System capability**: SystemCapability.Advertising.Ads

### onAdLoadFailure

onAdLoadFailure(errorCode: number, errorMsg: string): void

Called when a request for loading multiple ads fails.

**System capability**: SystemCapability.Advertising.Ads

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| errorCode | number | Yes| Result code indicating the ad request failure.| 
| errorMsg | string | Yes| Error message about the ad request failure.| 


### onAdLoadSuccess

onAdLoadSuccess(adsMap: Map&lt;string, Array&lt;advertising.[Advertisement](#advertisement)&gt;&gt;): void

Called when a request for loading multiple ads is successful.

**System capability**: SystemCapability.Advertising.Ads

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| adsMap |  Map&lt;string, Array&lt;advertising.[Advertisement](#advertisement)&gt;&gt;| Yes| Ad data.| 


**Example**

```ts
import advertising from '@ohos.advertising';

let adLoaderListener: advertising.MultiSlotsAdLoadListener = {
  onAdLoadFailure: (errorCode: number, errorMsg: string) => {

  },
  onAdLoadSuccess: (ads: Map<string, Array<advertising.Advertisement>>): void {

  }
}
```


## Advertisement


Defines the requested ad content.


**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adType | number | Yes| Ad type.| 
| uniqueId | string | Yes| Unique ID of the ad.| 
| rewarded | boolean | Yes| Whether users get rewarded for watching or clicking the ad.<br>- **true**: Users get rewarded.<br>- **false**: Users do not get rewarded.| 
| shown | boolean | Yes| Whether the ad is shown.<br>- **true**: The ad is shown.<br>- **false**: The ad is not shown.| 
| clicked | boolean | Yes| Whether the ad is clicked.<br>- **true**: The ad is clicked.<br>- **false**: The ad is not clicked.| 
| rewardVerifyConfig | Map&lt;string, string&gt; | Yes| Server verification parameter.<br>{<br>customData: "test",<br>userId: "12345"<br>} | 
| [key: string] | Object | Yes| Custom parameters.<br>- **isFullScreen**: The value is of the Boolean type. This parameter is used for splash ads to specify whether such an ad is in full-screen mode. The value **true** means that the ad is in full-screen mode, and **false** means that the ad is in half-screen mode.|


## AdDisplayOptions


Ad display parameters.


**System capability**: SystemCapability.Advertising.Ads


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| customData | string | No| Custom media data. It is used by the server to notify the media server that a user should be rewarded for interacting with the ad, so as to avoid spoofing.| 
| userId | string | No| User ID. It is used by the server to notify the media server that a user should be rewarded for interacting with the ad, so as to avoid spoofing.| 
| useMobileDataReminder | boolean | No| Whether to display a dialog box to notify users when they use mobile data to play videos or download applications.<br>- **true**: A dialog box is displayed.<br>- **false**: No dialog box is displayed.| 
| mute | boolean | No| Whether to mute the ad video.<br>- **true**: The ad video is muted.<br>- **false**: The ad video is not muted.| 
| audioFocusType | number | No| Type of the scenario where the audio focus is obtained during video playback.<br>- **0**: The focus is obtained when the video is played in mute or non-mute mode.<br>- **1**: The focus is not obtained when the video is played in mute mode.<br>- **2**: The focus is not obtained when the video is played in mute or non-mute mode.| 
| [key: string] | number \| boolean \| string \| undefined | No| Custom parameters.<br>- **refreshTime**: The value is of the number type, in ms. The value is in the range [30000, 120000]. This parameter is optional for the AutoAdComponent module and specifies the interval at which the ads rotate. If this parameter is set, ads are rotated at the interval specified by this parameter. Otherwise, ads are not rotated and only the first ad in the ad response is displayed.|


## AdInteractionListener


Defines the ad status change callback.


**System capability**: SystemCapability.Advertising.Ads

### onStatusChanged

onStatusChanged(status: number, ad: advertising.[Advertisement](#advertisement), data: string)

Called when the ad display status changes.

**System capability**: SystemCapability.Advertising.Ads

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| status | string | Yes| **status**: ad display status, which can be<br>**onAdOpen**, **onAdClose**, **onAdClick**, **onVideoPlayBegin**, **onVideoPlayEnd**, **onAdLoad**, **onAdFail**, **onMediaProgress**, **onMediaStart**, **onMediaPause**, **onMediaStop**, **onMediaComplete**, **onMediaError**, **onLandscape**, **onPortrait**, **onAdReward**, **onMediaCountDown**, or **onBackClicked**.| 
| ad | advertising.[Advertisement](#advertisement) | Yes| Content of the ad.| 
| data | string | Yes| Extended information.| 

**Example**

```ts
import advertising from '@ohos.advertising';

let adInteractionListener: advertising.AdInteractionListener = {
  onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {

  }
}
```
