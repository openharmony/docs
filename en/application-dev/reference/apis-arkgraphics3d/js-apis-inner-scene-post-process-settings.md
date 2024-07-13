# ScenePostProcessSettings
The ScenePostProcessSettings module provides image post-processing methods (for example, tone mapping) in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { ToneMappingType, ToneMappingSettings, PostProcessSettings } from '@kit.ArkGraphics3D';
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
| exposure | number | No| Yes| Exposure. The value is greater than 0. The default value is undefined.|

## PostProcessSettings
Describes the post-processing settings.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| toneMapping | [ToneMappingSettings](#tonemappingsettings) | No| Yes| Tone mapping settings. The default value is undefined.|
