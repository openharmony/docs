# @ohos.advertising.AdsServiceExtensionAbility (ExtensionAbility for Ads) (System API)


The AdsServiceExtensionAbility module provides ExtensionAbilities for the ads service. Device vendors can implement the service logic of requesting one or multiple ads.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import { AdsServiceExtensionAbility } from '@kit.AdsKit';
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
| respCallback | [RespCallback](js-apis-adsserviceextensionability#adsserviceextensionabilityrespcallback) | Yes| Ad request callback.| 

**Example**
```ts
import { AdsServiceExtensionAbility, advertising, RespCallback } from '@kit.AdsKit';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, respCallback: RespCallback) {
    const adType: number | undefined = adParam.adType;
    const ads: Array<advertising.Advertisement> = [];
    const rewardVerifyConfig: Map<string, string> = new Map();
    ads.push({
      adType: adType as number,
      uniqueId: '111111',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
    ads.push({
      adType: adType as number,
      uniqueId: '222222',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
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

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| adParams | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams)[] | Yes| Ad request parameters.| 
| adOptions | advertising.[AdOptions](js-apis-advertising.md#adoptions) | Yes| Ad configuration.| 
| respCallback | [RespCallback](js-apis-adsserviceextensionability#adsserviceextensionabilityrespcallback) | Yes| Ad request callback.| 

**Example**
```ts
import { AdsServiceExtensionAbility, advertising, RespCallback } from '@kit.AdsKit';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions,
    respCallback: RespCallback) {
    const adType1: number = adParams[0].adType as number;
    const ads1: Array<advertising.Advertisement> = [];
    const rewardVerifyConfig: Map<string, string> = new Map();
    ads1.push({
      adType: adType1,
      uniqueId: '111111',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
    ads1.push({
      adType: adType1,
      uniqueId: '222222',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
    const slot1: string = 'test1';
    const adType2: number = adParams[1].adType as number;
    const ads2: Array<advertising.Advertisement> = [];
    ads2.push({
      adType: adType2,
      uniqueId: '333333',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
    ads2.push({
      adType: adType2,
      uniqueId: '444444',
      rewardVerifyConfig: rewardVerifyConfig,
      rewarded: false,
      shown: false,
      clicked: false
    });
    const slot2: string = 'test2';
    const resMap: Map<string, Array<advertising.Advertisement>> = new Map();
    resMap.set(slot1, ads1);
    resMap.set(slot2, ads2);
    respCallback(resMap);
  }
}
```
