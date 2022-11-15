# Configuration

表示环境变化信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

  | 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language<sup>8+</sup> | string | 是 | 是 | 表示应用程序的当前语言。 |
| colorMode<sup>8+</sup> | [ColorMode](js-apis-configurationconstant.md) | 是 | 是 | 表示深浅色模式，取值范围：浅色模式（COLOR_MODE_LIGHT），深色模式（COLOR_MODE_DARK）。默认为浅色。 |
| direction<sup>9+</sup> | Direction | 是 | 否 | 表示屏幕方向，取值范围：水平方向（DIRECTION_HORIZONTAL），垂直方向（DIRECTION_VERTICAL）。 |
| screenDensity<sup>9+</sup>  | ScreenDensity | 是 | 否 | 表示屏幕分辨率，取值范围：SCREEN_DENSITY_SDPI（120）、SCREEN_DENSITY_MDPI（160）、SCREEN_DENSITY_LDPI（240）、SCREEN_DENSITY_XLDPI（320）、SCREEN_DENSITY_XXLDPI（480）、SCREEN_DENSITY_XXXLDPI（640）。 |
| displayId<sup>9+</sup>  | number | 是 | 否 | 表示应用所在的物理屏幕Id。 |
| hasPointerDevice<sup>9+</sup>  | boolean | 是 | 否 | 指示指针类型设备是否已连接，如键鼠、触控板等。 |

**示例：**
    
  ```ts
  let envCallback = {
     onConfigurationUpdated(config) {
       console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`)
       let language = config.language;
       let colorMode = config.colorMode;
       let direction = config.direction;
       let screenDensity = config.screenDensity;
       let displayId = config.displayId;
       let hasPointerDevice = config.hasPointerDevice;
    }
  };
  var callbackId = applicationContext.registerEnvironmentCallback(envCallback);
  ```

