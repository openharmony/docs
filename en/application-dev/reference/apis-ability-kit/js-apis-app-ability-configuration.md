# @ohos.app.ability.Configuration (Environment Variables)

The module defines the environment variables for the application runtime, including language, dark/light color mode, screen orientation, and font size. You can subscribe to these environment variables to adapt to different user preferences and enhance the interaction experience.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { Configuration } from '@kit.AbilityKit';
```

## Configuration

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| language | string | No| Yes| Current language of the application, for example, **zh** (Chinese) or **en** (English).<br>You can [set the application language](../../application-models/subscribe-system-environment-variable-changes.md#setting-application-language).<br>For details about the value range, see [getSystemLanguages](../apis-localization-kit/js-apis-i18n.md#getsystemlanguages9).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | No| Yes| Dark/Light color mode of the application. The light color mode is used by default.<br>You can [set the dark/light color mode for an application or a component](../../application-models/subscribe-system-environment-variable-changes.md#setting-darklight-color-mode).<br>The options are as follows:<br>- **COLOR_MODE_NOT_SET**: The color mode is not set.<br>- **COLOR_MODE_LIGHT**: light mode.<br>- **COLOR_MODE_DARK**: dark mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| direction | [ConfigurationConstant.Direction](js-apis-app-ability-configurationConstant.md#direction) | No| Yes| Screen orientation of the application.<br>The options are as follows:<br>- **DIRECTION_NOT_SET**: The screen orientation is not set.<br>- **DIRECTION_HORIZONTAL**: horizontal direction.<br>- **DIRECTION_VERTICAL**: vertical direction.<br>You can subscribe to changes to this environment variable in the [UIAbility](./js-apis-app-ability-uiAbility.md) and [UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md), but not in the [ApplicationContext](./js-apis-inner-application-applicationContext.md) or [AbilityStage](./js-apis-app-ability-abilityStage.md).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| screenDensity  | [ConfigurationConstant.ScreenDensity](js-apis-app-ability-configurationConstant.md#screendensity) | No| Yes| Screen density.<br>The options are as follows:<br>- **SCREEN_DENSITY_NOT_SET**: The pixel density is not set.<br>- **SCREEN_DENSITY_SDPI**: 120.<br>- **SCREEN_DENSITY_MDPI**: 160.<br>- **SCREEN_DENSITY_LDPI**: 240.<br>- **SCREEN_DENSITY_XLDPI**: 320.<br>- **SCREEN_DENSITY_XXLDPI**: 480.<br>- **SCREEN_DENSITY_XXXLDPI**: 640.<br>The font size is positively correlated with the screen pixel density. By monitoring changes in the screen pixel density, you can detect adjustments in the font size. Typically, for the same physical size, the higher the screen pixel density, the larger the font display effect.<br>You can subscribe to changes to this environment variable in the [UIAbility](./js-apis-app-ability-uiAbility.md) and [UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md), but not in the [ApplicationContext](./js-apis-inner-application-applicationContext.md) or [AbilityStage](./js-apis-app-ability-abilityStage.md).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayId  | number | No| Yes| ID of the display where the application is located.<br>You can subscribe to changes to this environment variable in the [UIAbility](./js-apis-app-ability-uiAbility.md) and [UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md), but not in the [ApplicationContext](./js-apis-inner-application-applicationContext.md) or [AbilityStage](./js-apis-app-ability-abilityStage.md).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| hasPointerDevice  | boolean | No| Yes| Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected. **true** if connected, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fontId<sup>14+<sup> | string | No| Yes| Unique ID of the font.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| fontSizeScale<sup>12+<sup> | number | No| Yes| Font size scale ratio. The value is a non-negative number. The default value is **1**.<br>You can [set the font size for an application](../../application-models/subscribe-system-environment-variable-changes.md#setting-font-size).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fontWeightScale<sup>12+<sup> | number | No| Yes| Font weight scale ratio. The value is a non-negative number. The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| mcc<sup>12+<sup> | string | No | Yes| Mobile country code.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| mnc<sup>12+<sup> | string | No | Yes| Mobile network code.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| locale<sup>20+<sup> | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No | Yes| Locale.<br>The application automatically adjusts its behavior based on the current locale to meet the localization requirements of users. This property can be set by configuring the system language, system region, and application preferred language.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

**Example**

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
        console.log(`onMemoryLevel level: ${level}`);
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
