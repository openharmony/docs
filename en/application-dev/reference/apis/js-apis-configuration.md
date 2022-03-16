# Configuration

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides the configuration for the environment where the ability is running.


## Modules to Import

  
```
import Configuration from '@ohos.application.Configuration';
```


## Attributes

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| language | string | Yes| Yes| Language of the application.| 
| colorMode | [ColorMode](js-apis-configurationconstant.md) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.| 
| direction | Direction | Yes| No| Screen orientation, which can be **DIRECTION_HORIZONTAL** or **DIRECTION_VERTICAL**.| 
| screenDensity | ScreenDensity | Yes| No| Screen resolution, which can be **SCREEN_DENSITY_SDPI** (120), **SCREEN_DENSITY_MDPI** (160), **SCREEN_DENSITY_LDPI** (240), **SCREEN_DENSITY_XLDPI** (320), **SCREEN_DENSITY_XXLDPI** (480), or **SCREEN_DENSITY_XXXLDPI** (640).| 
| displayId | number | Yes| No| ID of the display where the application is located.| 
