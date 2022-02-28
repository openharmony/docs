# Configuration

- [导入模块](#导入模块)
- [属性](#属性)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。


环境变化信息。


## 导入模块

  
```
import Configuration from '@ohos.application.Configuration';
```


## 属性

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| language | string | 是 | 是 | 表示应用程序的当前语言。 | 
| colorMode | [ColorMode](js-apis-configurationconstant.md) | 是 | 是 | 表示深浅色模式，取值范围：浅色模式（COLOR_MODE_LIGHT），深色模式（COLOR_MODE_DARK）。默认为浅色。 | 
| direction | Direction | 是 | 否 | 表示屏幕方向，取值范围：水平方向（DIRECTION_HORIZONTAL），垂直方向（DIRECTION_VERTICAL）。 | 
| screenDensity | ScreenDensity | 是 | 否 | 表示屏幕分辨率，取值范围：SCREEN_DENSITY_SDPI（120）、SCREEN_DENSITY_MDPI（160）、SCREEN_DENSITY_LDPI（240）、SCREEN_DENSITY_XLDPI（320）、SCREEN_DENSITY_XXLDPI（480）、SCREEN_DENSITY_XXXLDPI（640）。 | 
| displayId | number | 是 | 否 | 表示应用所在的displayId。 | 
