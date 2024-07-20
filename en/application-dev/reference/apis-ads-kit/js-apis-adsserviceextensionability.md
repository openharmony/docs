# @ohos.advertising.AdsServiceExtensionAbility (ExtensionAbility for Ads)


The AdsServiceExtensionAbility module provides ExtensionAbilities for the ads service. Device vendors can implement the callbacks for ads requests.


> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { RespCallback } from '@kit.AdsKit';
```

## AdsServiceExtensionAbility.RespCallback

(respData: Map&lt;string, Array&lt;advertising.Advertisement&gt;&gt;): void;

Ad request callback.

**System capability**: SystemCapability.Advertising.Ads

**Since**: 11

**Parameters**


| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| respData | Map&lt;string, Array&lt;advertising.[Advertisement](js-apis-advertising.md#advertisement)&gt;&gt; | Yes| Data in the ad request callback.| 


**Example**
```ts
import { advertising, RespCallback } from '@kit.AdsKit';

function respDemo(respCallback: RespCallback) {
  const ads: Array<advertising.Advertisement> = [];
  const rewardVerifyConfig: Map<string, string> = new Map();
  ads.push({
    adType: 7,
    uniqueId: '111111',
    rewardVerifyConfig: rewardVerifyConfig,
    rewarded: false,
    shown: false,
    clicked: false
  })
  const slot: string = "test";
  const resMap: Map<string, Array<advertising.Advertisement>> = new Map();
  resMap.set(slot, ads);
  respCallback(resMap);
}
```
