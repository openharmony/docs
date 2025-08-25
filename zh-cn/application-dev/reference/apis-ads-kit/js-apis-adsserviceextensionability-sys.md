# @ohos.advertising.AdsServiceExtensionAbility (广告扩展服务)(系统接口)

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--Designer: @zhansf1988-->
<!--Tester: @hongmei_may-->
<!--Adviser: @RayShih-->

本模块为设备厂商提供广告扩展能力，设备厂商可自主实现单广告位请求和多广告位请求的业务逻辑。

> **说明：**<br/>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br/>
> 本模块接口为系统接口。

## 导入模块

```ts
import { AdsServiceExtensionAbility } from '@kit.AdsKit';
```

## AdsServiceExtensionAbility.onLoadAd

onLoadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, respCallback: RespCallback)

单广告位请求业务实现方法，设备厂商需在该方法中实现广告请求业务逻辑并将结果回调给媒体。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型                                                                  | 必填 | 说明          |
|--------------|-----------------------------------------------------------------------|-----|-------------|
| adParam      | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams) | 是   | 广告请求参数。 |
| adOptions    | advertising.[AdOptions](js-apis-advertising.md#adoptions)             | 是   | 广告配置参数。 |
| respCallback | [RespCallback](js-apis-adsserviceextensionability.md#respcallback)    | 是   | 广告请求回调。 |

**示例：**

```ts
import { AdsServiceExtensionAbility, advertising, RespCallback } from '@kit.AdsKit';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAd(adParam: advertising.AdRequestParams, adOptions: advertising.AdOptions, respCallback: RespCallback) {
    const respData: Map<string, Array<advertising.Advertisement>> = new Map();
    // 设置广告返回数据
    // ...
    respCallback(respData);
  }
}
```

## AdsServiceExtensionAbility.onLoadAdWithMultiSlots

onLoadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions, respCallback: RespCallback)

多广告位请求业务实现方法，设备厂商需在该方法中实现广告请求业务逻辑并将结果回调给媒体。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型                                                                    | 必填 | 说明          |
|--------------|-------------------------------------------------------------------------|-----|-------------|
| adParams     | advertising.[AdRequestParams](js-apis-advertising.md#adrequestparams)[] | 是   | 广告请求参数。 |
| adOptions    | advertising.[AdOptions](js-apis-advertising.md#adoptions)               | 是   | 广告配置参数。 |
| respCallback | [RespCallback](js-apis-adsserviceextensionability.md#respcallback)      | 是   | 广告请求回调。 |

**示例：**

```ts
import { AdsServiceExtensionAbility, advertising, RespCallback } from '@kit.AdsKit';

export default class AdsExtensionAbility extends AdsServiceExtensionAbility {
  onLoadAdWithMultiSlots(adParams: advertising.AdRequestParams[], adOptions: advertising.AdOptions,
    respCallback: RespCallback) {
    const respData: Map<string, Array<advertising.Advertisement>> = new Map();
    // 设置广告返回数据
    // ...
    respCallback(respData);
  }
}
```