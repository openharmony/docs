# advertisement (广告内容)

本模块提供返回广告的能力。

> **说明：**<br/>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用说明

在使用[advertising](js-apis-advertising.md)的功能时，通过[Advertisement](js-apis-advertising.md#advertisement)获取请求返回的广告内容。

## Advertisement

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 名称               | 类型                      | 只读 | 可选 | 说明                                                                                                                    |
|--------------------|---------------------------|-----|-----|-----------------------------------------------------------------------------------------------------------------------|
| adType             | number                    | 否   | 否   | 广告类型。<br/>- 1：开屏广告。<br/>- 3：原生广告。<br/>- 7：激励广告。<br/>- 8：横幅广告。<br/>- 12：插屏广告。<br/>- 60：贴片广告。 |
| uniqueId           | string                    | 否   | 否   | 广告唯一标识。                                                                                                           |
| rewarded           | boolean                   | 否   | 否   | 广告是否获得奖励。<br/>- true：获得奖励。<br/>- false：没有获得奖励。                                                        |
| shown              | boolean                   | 否   | 否   | 广告是否展示。<br/>- true：展示。<br/>- false：未展示。                                                                      |
| clicked            | boolean                   | 否   | 否   | 广告是否被点击。<br/>- true：被点击。<br/>- false：未被点击。                                                                |
| rewardVerifyConfig | Map&lt;string, string&gt; | 否   | 否   | 服务器验证参数。                                                                                                         |
| [key: string]      | Object                    | 否   | 是   | 自定义参数。                                                                                                             |