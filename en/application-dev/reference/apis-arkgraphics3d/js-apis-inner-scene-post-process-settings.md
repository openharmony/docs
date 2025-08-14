# ScenePostProcessSettings
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

The module provides image post-processing methods (for example, tone mapping) in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { ToneMappingType, ToneMappingSettings, BloomSettings, PostProcessSettings } from '@kit.ArkGraphics3D';
```

## ToneMappingType
Enumerates the tone mapping types.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Value| Description|
| ---- | ---- | ---- |
| ACES | 0 | Academy Color Encoding System (ACES).|
| ACES_2020 | 1 | ACES_2020.|
| FILMIC | 2 | Filmic.|

## ToneMappingSettings
Describes the tone mapping settings.
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| type | [ToneMappingType](#tonemappingtype) | No| Yes| Tone mapping type. The default value is undefined.|
| exposure | number | No| Yes| Exposure. The value must be greater than 0. The default value is undefined.|

## BloomSettings<sup>18+</sup>
Describes the bloom settings.
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| thresholdHard | number | No| Yes| Hard threshold. The value is a non-negative number. The default value is **1.0**.|
| thresholdSoft | number | No| Yes| Soft threshold. The value is a non-negative number. The default value is **2.0**.|
| scaleFactor | number | No| Yes| Scale factor. The value must be greater than 0. The default value is **1.0**.|
| scatter | number | No| Yes| Scatter amount. The value must be greater than 0. The default value is **1.0**.|

## PostProcessSettings
Describes the post-processing settings.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| toneMapping | [ToneMappingSettings](#tonemappingsettings) | No| Yes| Tone mapping. The default value is undefined.|
| bloom<sup>18+</sup> | [BloomSettings](#bloomsettings18) | No| Yes| Bloom. The default value is undefined.|
