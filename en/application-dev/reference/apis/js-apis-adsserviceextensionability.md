# @ohos.advertising.AdsServiceExtensionAbility (ExtensionAbility for Ads)


The AdsServiceExtensionAbility module provides ExtensionAbilities for the ads service. Device vendors can implement the service logic of requesting one or multiple ads.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import AdsServiceExtensionAbility from '@ohos.advertising.AdsServiceExtensionAbility';
```


## AdsServiceExtensionAbility.onLoadAd

onLoadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, respCallback: RespCallback);

Called when the media application starts to load an ad. The device vendor needs to implement the ad request service logic in this API and send the result to the media application through a call back.

**System API**: This is a system API.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adParam | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams) | Yes| Ad request parameters.|
| adOptions | advertising.[AdOptions](js-apis-advertising.md#adoptions) | Yes| Ad configuration.|
| respCallback | [RespCallback](#adsserviceextensionabilityrespcallback) | Yes| Ad request callback.|

**Example**
```ts
import advertising from '@ohos.advertising';
import AdsServiceExtensionAbility from '@ohos.advertising.AdsServiceExtensionAbility';
import { RespCallback } from '@ohos.advertising.AdsServiceExtensionAbility';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, respCallback: RespCallback) {
    const adType: number = adParam.adType;
    const ads: Array<advertising.Advertisement> = [];
    ads.push({adType: adType, uniqueId: '111111', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    ads.push({adType: adType, uniqueId: '222222', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    const slot: string = 'test';
    const resMap: Map<string, Array<advertising.Advertisement>> = new Map();
    resMap.set(slot, ads);
    respCallback(resMap);
  }
}
```


## AdsServiceExtensionAbility.onLoadAdWithMultiSlots

onLoadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions, respCallback: RespCallback);

Called when the media application starts to load multiple ads. The device vendor needs to implement the ad request service logic in this API and send the result to the media application through a call back.

**System API**: This is a system API.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

Parameters

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| adParams | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams)[] | Yes| Ad request parameters.|
| adOptions | advertising.[AdOptions](js-apis-advertising.md#adoptions) | Yes| Ad configuration.|
| respCallback | [RespCallback](#adsserviceextensionabilityrespcallback) | Yes| Ad request callback.|

**Example**
```ts
import advertising from '@ohos.advertising';
import AdsServiceExtensionAbility from '@ohos.advertising.AdsServiceExtensionAbility';
import { RespCallback } from '@ohos.advertising.AdsServiceExtensionAbility';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions, respCallback: RespCallback) {
    const adType1: number = adParams[0].adType; 
    const ads1: Array<advertising.Advertisement> = [];
    ads1.push({adType: adType1, uniqueId: '111111', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    ads1.push({adType: adType1, uniqueId: '222222', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    const slot1: string = 'test1';
    const adType2: number = adParams[1].adType; 
    const ads2: Array<advertising.Advertisement> = [];
    ads2.push({adType: adType2, uniqueId: '333333', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    ads2.push({adType: adType2, uniqueId: '444444', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false});
    const slot2: string = 'test2';
    const resMap: Map<string, Array<advertising.Advertisement>> = new Map();
    resMap.set(slot1, ads1);
    resMap.set(slot2, ads2);
    respCallback(resMap);
  }
}
```


## AdsServiceExtensionAbility.RespCallback

(respData: Map&lt;string, Array&lt;advertising.Advertisement&gt;&gt;): void;

Defines the ad request callback.

**System API**: This is a system API.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

Parameters


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| respData | Map&lt;string, Array&lt;advertising.[Advertisement](js-apis-advertising.md#advertisement)&gt;&gt; | Yes| Data in the ad request callback.|


**Example**
```ts
import advertising from '@ohos.advertising';
import { RespCallback } from '@ohos.advertising.AdsServiceExtensionAbility';

function respDemo(respCallback: RespCallback) {
  const ads: Array<advertising.Advertisement> = [];
  ads.push({adType: 7, uniqueId: '111111', rewardVerifyConfig: null, rewarded: false, shown: false,  clicked: false})
  const slot: string = "test";
  const resMap: Map<string, Array<advertising.Advertisement>> = new Map();
  resMap.set(slot, ads);
  respCallback(resMap);
}
```
