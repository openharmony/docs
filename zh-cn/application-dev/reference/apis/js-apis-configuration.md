# Configuration

Configuration模块提供环境变化信息的能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import Configuration from '@ohos.application.Configuration';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

  | 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language | string | 是 | 是 | 表示应用程序的当前语言。 |
| colorMode | [ColorMode](js-apis-configurationconstant.md) | 是 | 是 | 表示深浅色模式，取值范围：浅色模式（COLOR_MODE_LIGHT），深色模式（COLOR_MODE_DARK）。默认为浅色。 |
| direction<sup>9+</sup> | Direction | 是 | 否 | 表示屏幕方向，取值范围：水平方向（DIRECTION_HORIZONTAL），垂直方向（DIRECTION_VERTICAL）。 |
| screenDensity<sup>9+</sup>  | ScreenDensity | 是 | 否 | 表示屏幕分辨率，取值范围：SCREEN_DENSITY_SDPI（120）、SCREEN_DENSITY_MDPI（160）、SCREEN_DENSITY_LDPI（240）、SCREEN_DENSITY_XLDPI（320）、SCREEN_DENSITY_XXLDPI（480）、SCREEN_DENSITY_XXXLDPI（640）。 |
| displayId<sup>9+</sup>  | number | 是 | 否 | 表示应用所在的物理屏幕Id。 |
| hasPointerDevice<sup>9+</sup>  | boolean | 是 | 否 | 指示指针类型设备是否已连接，如键鼠、触控板等。 |

