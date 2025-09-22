# @ohos.app.ability.Configuration (环境变量)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义了应用运行时的环境变量，包含语言、深浅色、屏幕方向、字体等。开发者可以通过订阅环境变量，适配不同用户偏好，提升交互体验。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { Configuration } from '@kit.AbilityKit';
```

## Configuration

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language | string | 否 | 是 | 表示应用当前语言，例如“zh"(中文)，“en”（英文）。<br>支持开发者[设置应用语言](../../application-models/subscribe-system-environment-variable-changes.md#设置应用语言)。<br>取值范围参考[获取系统支持的语言列表](../apis-localization-kit/js-apis-i18n.md#getsystemlanguages9)。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | 否 | 是 | 表示应用深浅色模式，默认为浅色。<br>支持开发者[设置应用或组件深浅色](../../application-models/subscribe-system-environment-variable-changes.md#设置深浅色模式)。<br>取值范围：<br />- COLOR_MODE_NOT_SET：未设置<br />- COLOR_MODE_LIGHT：浅色模式<br />- COLOR_MODE_DARK：深色模式<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| direction | [ConfigurationConstant.Direction](js-apis-app-ability-configurationConstant.md#direction) | 否 | 是 | 表示应用屏幕方向。<br>取值范围：<br />- DIRECTION_NOT_SET：未设置<br />- DIRECTION_HORIZONTAL：水平方向<br />- DIRECTION_VERTICAL：垂直方向 <br />该环境变量支持在[UIAbility](./js-apis-app-ability-uiAbility.md)组件和[UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md)组件中订阅，不支持在[ApplicationContext](./js-apis-inner-application-applicationContext.md)和[AbilityStage](./js-apis-app-ability-abilityStage.md)组件容器中订阅。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| screenDensity  | [ConfigurationConstant.ScreenDensity](js-apis-app-ability-configurationConstant.md#screendensity) | 否 | 是 | 表示屏幕显示密度。<br>取值范围：<br />- SCREEN_DENSITY_NOT_SET：未设置<br />- SCREEN_DENSITY_SDPI：120<br />- SCREEN_DENSITY_MDPI：160<br />- SCREEN_DENSITY_LDPI：240<br />- SCREEN_DENSITY_XLDPI：320<br />- SCREEN_DENSITY_XXLDPI：480<br />- SCREEN_DENSITY_XXXLDPI：640 <br>字体显示大小与屏幕像素密度呈正相关关系。通过监听屏幕像素密度变化，可以感知字体显示大小的调整。通常情况下，对于相同的物理尺寸，屏幕像素密度越高，字体显示效果越大。 <br />该环境变量支持在[UIAbility](./js-apis-app-ability-uiAbility.md)组件和[UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md)组件中订阅，不支持在[ApplicationContext](./js-apis-inner-application-applicationContext.md)和[AbilityStage](./js-apis-app-ability-abilityStage.md)组件容器中订阅。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| displayId  | number | 否 | 是 | 表示应用所在的物理屏幕ID。<br />该环境变量支持在[UIAbility](./js-apis-app-ability-uiAbility.md)组件和[UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md)组件中订阅，不支持在[ApplicationContext](./js-apis-inner-application-applicationContext.md)和[AbilityStage](./js-apis-app-ability-abilityStage.md)组件容器中订阅。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| hasPointerDevice  | boolean | 否 | 是 | 表示指针设备是否已连接，如键鼠、触控板等。true表示设备已连接，false表示设备未连接。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| fontId<sup>14+<sup> | string | 否 | 是 | 表示应用字体的唯一ID。<br>**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。 |
| fontSizeScale<sup>12+<sup> | number | 否 | 是 | 表示字体大小缩放比例，取值为非负数，默认值为1。<br>支持开发者[设置应用字体大小](../../application-models/subscribe-system-environment-variable-changes.md#设置字体大小)。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| fontWeightScale<sup>12+<sup> | number | 否 | 是 | 表示字体粗细缩放比例，取值为非负数，默认值为1。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| mcc<sup>12+<sup> | string | 否  | 是 | 表示移动设备国家代码。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| mnc<sup>12+<sup> | string | 否  | 是 | 表示移动设备网络代码。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| locale<sup>20+<sup> | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | 否  | 是 | 表示区域设置。<br>应用会根据当前的区域设置自动调整其行为，以符合用户的本地化需求。该属性可以通过设置系统语言、设置系统地区和设置应用偏好语言等方式设置。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

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
        let fontId = config.fontId;
        let fontSizeScale = config.fontSizeScale;
        let fontWeightScale = config.fontWeightScale;
        let mcc = config.mcc;
        let mnc = config.mnc;
        let locale = config.locale;
      },
      onMemoryLevel(level) {
        console.info(`onMemoryLevel level: ${level}`);
      }
    };
    try {
      let applicationContext = this.context.getApplicationContext();
      let callbackId = applicationContext.on('environment', envCallback);
      console.info(`callbackId: ${callbackId}`);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```
