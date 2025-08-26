# @ohos.app.ability.ConfigurationConstant (Constants Related to Environment Variables)

The ConfigurationConstant module provides preset enumerated values related to [Configuration](js-apis-app-ability-configuration.md) operations.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ConfigurationConstant } from '@kit.AbilityKit';
```

## ColorMode

Enumerates the dark/light color modes, which are used in the [Configuration.colorMode](../apis-ability-kit/js-apis-app-ability-configuration.md#configuration) field. You can use these predefined enumerated values to set or obtain the dark/light color mode of the system or application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| COLOR_MODE_NOT_SET | -1 | Unspecified color mode.| 
| COLOR_MODE_DARK | 0 | Dark mode.| 
| COLOR_MODE_LIGHT | 1 | Light mode.| 


## Direction

Enumerates the screen directions, which are used in the [Configuration.direction](../apis-ability-kit/js-apis-app-ability-configuration.md#configuration) field. You can use these predefined enumerated values to set or obtain the screen direction of the system or application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| DIRECTION_NOT_SET | -1 | Unspecified direction.| 
| DIRECTION_VERTICAL | 0 | Vertical direction.| 
| DIRECTION_HORIZONTAL | 1 | Horizontal direction.| 


## ScreenDensity

Enumerates the pixel densities of the screen, which are used in the [Configuration.screenDensity](../apis-ability-kit/js-apis-app-ability-configuration.md#configuration) field. You can use these predefined enumerated values to set or obtain the pixel density of the screen.<br>The font size is positively correlated with the screen pixel density. By monitoring changes in the screen pixel density, you can detect adjustments in the font size. Typically, for the same physical size, the higher the screen pixel density, the larger the font display effect.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| SCREEN_DENSITY_NOT_SET | 0 | The screen pixel density is not set.| 
| SCREEN_DENSITY_SDPI | 120 | The pixel density of the screen is 'SDPI'.| 
| SCREEN_DENSITY_MDPI | 160 | The pixel density of the screen is 'MDPI'.| 
| SCREEN_DENSITY_LDPI | 240 | The pixel density of the screen is 'LDPI'.| 
| SCREEN_DENSITY_XLDPI | 320 | The pixel density of the screen is 'XLDPI'.| 
| SCREEN_DENSITY_XXLDPI | 480 | The pixel density of the screen is 'XXLDPI'.| 
| SCREEN_DENSITY_XXXLDPI | 640 | The pixel density of the screen is 'XXXLDPI'.| 
