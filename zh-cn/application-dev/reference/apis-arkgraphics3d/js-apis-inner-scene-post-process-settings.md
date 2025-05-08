# ScenePostProcessSettings
本模块提供3D图形中的色调映射等图像后处理方法。

> **说明：** 
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。

## 导入模块
```ts
import { ToneMappingType, ToneMappingSettings, PostProcessSettings } from '@kit.ArkGraphics3D';
```

## ToneMappingType
色调映射类型枚举。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| ACES | 0 | ACES类型。 |
| ACES_2020 | 1 | ACES_2020类型。 |
| FILMIC | 2 | FILMIC类型。 |

## ToneMappingSettings
色调映射设置接口。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| type | [ToneMappingType](#tonemappingtype) | 否 | 是 | 色调映射类型，默认值为undefined。 |
| exposure | number | 否 | 是 | 曝光度，取值大于0，默认值为undefined。 |

## BloomSettings<sup>18+</sup>
泛光设置接口。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| thresholdHard | number | 否 | 是 | 硬阈值，取值范围是非负数，默认值为1.0。 |
| thresholdSoft | number | 否 | 是 | 软阈值，取值范围是非负数，默认值为2.0。 |
| scaleFactor | number | 否 | 是 | 缩放因子，取值范围大于0，默认值为1.0。 |
| scatter | number | 否 | 是 | 扩散量，取值范围大于0，默认值为1.0。 |

## PostProcessSettings
后处理设置。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| toneMapping | [ToneMappingSettings](#tonemappingsettings) | 否 | 是 | 色调映射，默认值为undefined。 |
| bloom<sup>18+</sup> | [BloomSettings](#bloomsettings18) | 否 | 是 | 泛光，默认值为undefined。 |
