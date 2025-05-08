# Advertisement

Advertisement is the ad content requested by [advertising](js-apis-advertising.md#advertisement).

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { advertising } from '@kit.AdsKit';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Advertising.Ads

| Name                | Type                       | Read-Only| Optional| Description                                                                                                                                                                                                                                                                          |
|--------------------|---------------------------|----|----|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| adType             | number                    | No | No | Ad type.<br>- **1**: splash ad.<br>- **3**: native ad.<br>- **7**: rewarded ad.<br>- **8**: banner ad.<br>- **12**: interstitial ad.<br>- **60**: roll ad.<br>If this parameter is left empty, the native ad is used by default.                                                                                                                                                            |
| uniqueId           | string                    | No | No | Unique ID of the ad.                                                                                                                                                                                                                                                                     |
| rewarded           | boolean                   | No | No | Whether users get rewarded for watching or clicking the ad.<br>- **true**: Users get rewarded.<br>- **false**: Users do not get rewarded.                                                                                                                                                                                                                              |
| shown              | boolean                   | No | No | Whether the ad is shown.<br>- **true**: The ad is shown.<br>- **false**: The ad is not shown.                                                                                                                                                                                                                                     |
| clicked            | boolean                   | No | No | Whether the ad is clicked.<br>- **true**: The ad is clicked.<br>- **false**: The ad is not clicked.                                                                                                                                                                                                                                  |
| rewardVerifyConfig | Map&lt;string, string&gt; | No | No | Server verification parameter.<br>{<br>customData: "test",<br>userId: "12345"<br>}                                                                                                                                                                                                             |
| [key: string]      | Object                    | No | Yes | Custom parameter.<br>- **isFullScreen**: The value is of the Boolean type. It specifies whether a splash ad is in full-screen mode. The value **true** means that the ad is in full-screen mode, and **false** means that the ad is in half-screen mode.<br>- **biddingInfo**: An object containing ad information. It is used to obtain real-time bidding results. **biddingInfo.price**: the Effective Cost Per Mille (eCPM) of an ad. **biddingInfo.cur**: the currency of an ad. **biddingInfo.nurl**: URL used to specify the successful bidding results returned by the media. **biddingInfo.lurl**: URL used to notify other Demand-Side Platforms (DSPs) of the bidding success result when the bidding fails.|
