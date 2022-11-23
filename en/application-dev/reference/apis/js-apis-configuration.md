# Configuration

The **Configuration** module provides environment configuration information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import Configuration from '@ohos.application.Configuration';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

  | Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language | string | Yes| Yes| Language of the application.|
| colorMode | [ColorMode](js-apis-configurationconstant.md) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.|
| direction<sup>9+</sup> | Direction | Yes| No| Screen orientation, which can be **DIRECTION_HORIZONTAL** or **DIRECTION_VERTICAL**.|
| screenDensity<sup>9+</sup>  | ScreenDensity | Yes| No| Screen resolution, which can be **SCREEN_DENSITY_SDPI** (120), **SCREEN_DENSITY_MDPI** (160), **SCREEN_DENSITY_LDPI** (240), **SCREEN_DENSITY_XLDPI** (320), **SCREEN_DENSITY_XXLDPI** (480), or **SCREEN_DENSITY_XXXLDPI** (640).|
| displayId<sup>9+</sup>  | number | Yes| No| ID of the display where the application is located.|
| hasPointerDevice<sup>9+</sup>  | boolean | Yes| No| Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected.|
