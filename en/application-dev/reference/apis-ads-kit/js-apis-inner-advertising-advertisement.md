# Advertisement

This module provides the capability of returning ads.

> **NOTE**
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## How to Use

When using the [advertising](js-apis-advertising.md) function, you can obtain the returned ad through [Advertisement](js-apis-advertising.md#advertisement).

## Advertisement

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Advertising.Ads

| Name              | Type                     | Read-Only| Optional| Description                                                                                                                   |
|--------------------|---------------------------|-----|-----|-----------------------------------------------------------------------------------------------------------------------|
| adType             | number                    | No  | No  | Ad type.<br>- **1**: splash ad.<br>- **3**: native ad.<br>- **7**: rewarded ad.<br>- **8**: banner ad.<br>- **12**: interstitial ad.<br>- **60**: roll ad.|
| uniqueId           | string                    | No  | No  | Unique ID of the ad.                                                                                                          |
| rewarded           | boolean                   | No  | No  | Whether users get rewarded for watching or clicking the ad.<br>- **true**: Users get rewarded.<br>- **false**: Users do not get rewarded.                                                       |
| shown              | boolean                   | No  | No  | Whether the ad is shown.<br>- **true**: The ad is shown.<br>- **false**: The ad is not shown.                                                                     |
| clicked            | boolean                   | No  | No  | Whether the ad is clicked.<br>- **true**: The ad is clicked.<br>- **false**: The ad is not clicked.                                                               |
| rewardVerifyConfig | Map&lt;string, string&gt; | No  | No  | Server verification parameter.                                                                                                        |
| [key: string]      | Object                    | No  | Yes  | Custom parameter.                                                                                                            |
