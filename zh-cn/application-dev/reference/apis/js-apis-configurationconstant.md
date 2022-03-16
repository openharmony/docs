# ConfigurationConstant

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


配置信息枚举值定义。


## 导入模块

  
```js
import ConfigurationConstant from '@ohos.application.ConfigurationConstant';
```


## ConfigurationConstant.ColorMode

使用时通过ConfigurationConstant.ColorMode获取。

**示例：**

```
ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT。
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| COLOR_MODE_NOT_SET | -1 | 未设置颜色模式。 | 
| COLOR_MODE_DARK | 0 | 深色模式。 | 
| COLOR_MODE_LIGHT | 1 | 浅色模式。 | 


## ConfigurationConstant.Direction

使用时通过ConfigurationConstant.Direction获取。

**示例：**

```
ConfigurationConstant.Direction.DIRECTION_VERTICAL。
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| DIRECTION_NOT_SET<sup>9+</sup> | -1 | 未设置方向。 | 
| DIRECTION_VERTICAL<sup>9+</sup> | 0 | 垂直方向。 | 
| DIRECTION_HORIZONTAL<sup>9+</sup> | 1 | 水平方向。 | 


## ConfigurationConstant.ScreenDensity

使用时通过ConfigurationConstant.ScreenDensity获取。

**示例：**

```
ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_NOT_SET。
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| SCREEN_DENSITY_NOT_SET<sup>9+</sup> | 0 | 未设置屏幕分辨率。 | 
| SCREEN_DENSITY_SDPI<sup>9+</sup> | 120 | 屏幕分辨率为"sdpi"。 | 
| SCREEN_DENSITY_MDPI<sup>9+</sup> | 160 | 屏幕分辨率为"mdpi"。 | 
| SCREEN_DENSITY_LDPI<sup>9+</sup> | 240 | 屏幕分辨率为"ldpi"。 | 
| SCREEN_DENSITY_XLDPI<sup>9+</sup> | 320 | 屏幕分辨率为"xldpi"。 | 
| SCREEN_DENSITY_XXLDPI<sup>9+</sup> | 480 | 屏幕分辨率为"xxldpi"。 | 
| SCREEN_DENSITY_XXXLDPI<sup>9+</sup> | 640 | 屏幕分辨率为"xxxldpi"。 | 
