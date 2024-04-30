# @ohos.app.ability.Configuration (Configuration)

The **Configuration** module defines environment change information. **Configuration** is an interface definition and is used only for field declaration.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import Configuration from '@ohos.app.ability.Configuration';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| language | string | No| No| Language of the application, for example, **zh**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| colorMode | [ColorMode](js-apis-app-ability-configurationConstant.md#configurationconstantcolormode) | No| No| Color mode. The default value is **COLOR_MODE_LIGHT**. The options are as follows:<br>- **COLOR_MODE_NOT_SET**: The color mode is not set.<br>- **COLOR_MODE_LIGHT**: light mode.<br>- **COLOR_MODE_DARK**: dark mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| direction | [Direction](js-apis-app-ability-configurationConstant.md#configurationconstantdirection) | No| No| Screen orientation. The options are as follows:<br>- **DIRECTION_NOT_SET**: The screen orientation is not set.<br>- **DIRECTION_HORIZONTAL**: horizontal direction.<br>- **DIRECTION_VERTICAL**: vertical direction.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| screenDensity  | [ScreenDensity](js-apis-app-ability-configurationConstant.md#configurationconstantscreendensity) | No| No| Pixel density of the screen. The options are as follows:<br>- **SCREEN_DENSITY_NOT_SET**: The pixel density is not set.<br>- **SCREEN_DENSITY_SDPI**: 120.<br>- **SCREEN_DENSITY_MDPI**: 160.<br>- **SCREEN_DENSITY_LDPI**: 240.<br>- **SCREEN_DENSITY_XLDPI**: 320.<br>- **SCREEN_DENSITY_XXLDPI**: 480.<br>- **SCREEN_DENSITY_XXXLDPI**: 640.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayId  | number | No| No| ID of the display where the application is located.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| hasPointerDevice  | boolean | No| No| Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fontSizeScale<sup>12+<sup> | number | No| No| Scale factor for the font size. The value ranges from 0 to 3.2.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fontWeightScale<sup>12+<sup> | number | No| No| Scale factor for the font weight. The value ranges from 0 to 1.25.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

For details about the fields, see the **ohos.app.ability.Configuration.d.ts** file.

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import EnvironmentCallback from '@ohos.app.ability.EnvironmentCallback';
import Want from '@ohos.app.ability.Want';

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
            console.error(`error: ${paramError.code}, ${paramError.message}`);
        }
    }
}
  ```
