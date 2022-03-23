# ConfigurationConstant

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Defines enumerated values of the configuration for the environment where the ability is running.


## Modules to Import

  
```js
import ConfigurationConstant from '@ohos.application.ConfigurationConstant';
```


## ConfigurationConstant.ColorMode

The value is obtained through the **ConfigurationConstant.ColorMode** API.

**Example**

```
ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| COLOR_MODE_NOT_SET | -1 | Unspecified color mode.| 
| COLOR_MODE_DARK | 0 | Dark mode.| 
| COLOR_MODE_LIGHT | 1 | Light mode.| 


## ConfigurationConstant.Direction

The value is obtained through the **ConfigurationConstant.Direction** API.

**Example**

```
ConfigurationConstant.Direction.DIRECTION_VERTICAL
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| DIRECTION_NOT_SET<sup>9+</sup> | -1 | Unspecified direction.| 
| DIRECTION_VERTICAL<sup>9+</sup> | 0 | Vertical direction.| 
| DIRECTION_HORIZONTAL<sup>9+</sup> | 1 | Horizontal direction.| 


## ConfigurationConstant.ScreenDensity

The value is obtained through the **ConfigurationConstant.ScreenDensity** API.

**Example**

```
ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_NOT_SET
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Value| Description| 
| -------- | -------- | -------- |
| SCREEN_DENSITY_NOT_SET<sup>9+</sup> | 0 | Unspecified screen resolution.| 
| SCREEN_DENSITY_SDPI<sup>9+</sup> | 120 | The screen resolution is sdpi.| 
| SCREEN_DENSITY_MDPI<sup>9+</sup> | 160 | The screen resolution is mdpi.| 
| SCREEN_DENSITY_LDPI<sup>9+</sup> | 240 | The screen resolution is ldpi.| 
| SCREEN_DENSITY_XLDPI<sup>9+</sup> | 320 | The screen resolution is xldpi.| 
| SCREEN_DENSITY_XXLDPI<sup>9+</sup> | 480 | The screen resolution is xxldpi.| 
| SCREEN_DENSITY_XXXLDPI<sup>9+</sup> | 640 | The screen resolution is xxxldpi.| 
