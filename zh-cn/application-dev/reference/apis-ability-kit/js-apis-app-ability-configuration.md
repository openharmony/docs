# @ohos.app.ability.Configuration (Configuration)

定义环境变化信息。Configuration是接口定义，仅做字段声明。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { Configuration } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language | string | 否 | 是 | 表示应用程序的当前语言，例如“zh"。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | 否 | 是 | 表示深浅色模式，默认为浅色。取值范围：<br />- COLOR_MODE_NOT_SET：未设置<br />- COLOR_MODE_LIGHT：浅色模式<br />- COLOR_MODE_DARK：深色模式<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| direction | [ConfigurationConstant.Direction](js-apis-app-ability-configurationConstant.md#direction) | 否 | 是 | 表示屏幕方向，取值范围：<br />- DIRECTION_NOT_SET：未设置<br />- DIRECTION_HORIZONTAL：水平方向<br />- DIRECTION_VERTICAL：垂直方向<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| screenDensity  | [ConfigurationConstant.ScreenDensity](js-apis-app-ability-configurationConstant.md#screendensity) | 否 | 是 | 表示屏幕像素密度，取值范围：<br />- SCREEN_DENSITY_NOT_SET：未设置<br />- SCREEN_DENSITY_SDPI：120<br />- SCREEN_DENSITY_MDPI：160<br />- SCREEN_DENSITY_LDPI：240<br />- SCREEN_DENSITY_XLDPI：320<br />- SCREEN_DENSITY_XXLDPI：480<br />- SCREEN_DENSITY_XXXLDPI：640<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayId  | number | 否 | 是 | 表示应用所在的物理屏幕ID。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| hasPointerDevice  | boolean | 否 | 是 | 指示指针类型设备是否已连接，如键鼠、触控板等。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fontSizeScale<sup>12+<sup> | number | 否 | 是 | 字体大小缩放比例，取值为非负数，默认值为1。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| fontWeightScale<sup>12+<sup> | number | 否 | 是 | 字体粗细缩放比例，取值为非负数，默认值为1。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mcc<sup>12+<sup> | string | 否  | 是 | 移动设备网络代码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mnc<sup>12+<sup> | string | 否  | 是 | 移动设备国家代码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

**示例：**

  ```ts
import { UIAbility, AbilityConstant, EnvironmentCallback, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let envCallback: EnvironmentCallback = {
      onConfigurationUpdated(config) {
        console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`);
        let language = config.language;
        let colorMode = config.colorMode;
        let direction = config.direction;
        let screenDensity = config.screenDensity;
        let displayId = config.displayId;
        let hasPointerDevice = config.hasPointerDevice;
        let fontSizeScale = config.fontSizeScale;
        let fontWeightScale = config.fontWeightScale;
        let mcc = config.mcc;
        let mnc = config.mnc;
      },
      onMemoryLevel(level) {
        console.log('onMemoryLevel level: ${level}');
      }
    };
    try {
      let applicationContext = this.context.getApplicationContext();
      let callbackId = applicationContext.on('environment', envCallback);
      console.log(`callbackId: ${callbackId}`);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
  ```

