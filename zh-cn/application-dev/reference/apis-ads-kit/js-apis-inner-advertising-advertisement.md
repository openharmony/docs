# Advertisement

Advertisement 是 [advertising](js-apis-advertising.md#advertisement) 请求的广告内容。

> **说明：**
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { advertising } from '@kit.AdsKit';
```

## 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 名称                 | 类型                        | 只读 | 可选 | 说明                                                                                                                                                                                                                                                                           |
|--------------------|---------------------------|----|----|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| adType             | number                    | 否  | 否  | 广告类型。<br/>- 1：开屏广告。<br/>- 3：原生广告。<br/>- 7：激励广告。<br/>- 8：banner广告。<br/>- 12：插屏广告。<br/>- 60：贴片广告。<br/>不填默认为原生广告类型。                                                                                                                                                             |
| uniqueId           | string                    | 否  | 否  | 广告唯一标识。                                                                                                                                                                                                                                                                      |
| rewarded           | boolean                   | 否  | 否  | 广告是否获得奖励。<br/>- true：获得奖励。<br/>- false：没有获得奖励。                                                                                                                                                                                                                               |
| shown              | boolean                   | 否  | 否  | 广告是否展示。<br/>- true：展示。<br/>- false：未展示。                                                                                                                                                                                                                                      |
| clicked            | boolean                   | 否  | 否  | 广告是否被点击。<br/>- true：被点击。<br/>- false：未被点击。                                                                                                                                                                                                                                   |
| rewardVerifyConfig | Map&lt;string, string&gt; | 否  | 否  | 服务器验证参数。<br/>{<br/>customData: "test",<br/>userId: "12345"<br/>}                                                                                                                                                                                                             |
| [key: string]      | Object                    | 否  | 是  | 自定义参数。<br/>- isFullScreen：类型 boolean。开屏广告自定义参数，用于标识返回的广告是否为全屏，true 为全屏广告，false 为半屏广告。<br/>- biddingInfo：类型Object。用于获取实时竞价相关结果。biddingInfo.price：获取本条广告的eCPM出价（元/千次展示）。biddingInfo.cur：获取本条广告价格币种。biddingInfo.nurl：媒体回传竞价成功结果的URL。biddingInfo.lurl：媒体回传竞价失败通知其他DSP竞价成功结果的URL。 |
