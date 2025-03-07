# @ohos.app.ability.ConfigurationConstant (ConfigurationConstant)

ConfigurationConstant模块提供配置信息枚举值定义的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { ConfigurationConstant } from '@kit.AbilityKit';
```

## ColorMode

表示颜色模式的枚举。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| COLOR_MODE_NOT_SET | -1 | 未设置颜色模式。 | 
| COLOR_MODE_DARK | 0 | 深色模式。 | 
| COLOR_MODE_LIGHT | 1 | 浅色模式。 | 


## Direction

表示屏幕方向的枚举。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| DIRECTION_NOT_SET | -1 | 未设置方向。 | 
| DIRECTION_VERTICAL | 0 | 垂直方向。 | 
| DIRECTION_HORIZONTAL | 1 | 水平方向。 | 


## ScreenDensity

表示屏幕像素的枚举。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| SCREEN_DENSITY_NOT_SET | 0 | 未设置屏幕像素密度。 | 
| SCREEN_DENSITY_SDPI | 120 | 屏幕像素密度为'SDPI'。 | 
| SCREEN_DENSITY_MDPI | 160 | 屏幕像素密度为'MDPI'。 | 
| SCREEN_DENSITY_LDPI | 240 | 屏幕像素密度为'LDPI'。 | 
| SCREEN_DENSITY_XLDPI | 320 | 屏幕像素密度为'XLDPI'。 | 
| SCREEN_DENSITY_XXLDPI | 480 | 屏幕像素密度为'XXLDPI'。 | 
| SCREEN_DENSITY_XXXLDPI | 640 | 屏幕像素密度为'XXXLDPI'。 | 
