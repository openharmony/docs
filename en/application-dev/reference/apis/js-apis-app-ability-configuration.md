# @ohos.app.ability.Configuration (Configuration)

The **Configuration** module defines environment change information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import Configuration from '@ohos.app.ability.Configuration'
```

**System capability**: SystemCapability.Ability.AbilityBase

  | Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language | string | Yes| Yes| Language of the application, for example, **zh**.|
| colorMode | [ColorMode](js-apis-app-ability-configurationConstant.md#configurationconstantcolormode) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.|
| direction | [Direction](js-apis-app-ability-configurationConstant.md#configurationconstantdirection) | Yes| No| Screen orientation, which can be **DIRECTION_HORIZONTAL** or **DIRECTION_VERTICAL**.|
| screenDensity  | [ScreenDensity](js-apis-app-ability-configurationConstant.md#configurationconstantscreendensity) | Yes| No| Screen resolution, which can be **SCREEN_DENSITY_SDPI** (120), **SCREEN_DENSITY_MDPI** (160), **SCREEN_DENSITY_LDPI** (240), **SCREEN_DENSITY_XLDPI** (320), **SCREEN_DENSITY_XXLDPI** (480), or **SCREEN_DENSITY_XXXLDPI** (640).|
| displayId  | number | Yes| No| ID of the display where the application is located.|
| hasPointerDevice  | boolean | Yes| No| Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected.|

For details about the fields, see the **ohos.app.ability.Configuration.d.ts** file.

**Example**
    
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
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
      try {
        let applicationContext = this.context.getApplicationContext();
        let callbackId = applicationContext.on("environment", envCallback);
        console.log("callbackId: " + callbackId);
      } catch (paramError) {
        console.log("error: " + paramError.code + ", " + paramError.message);
      }
    }
  }
  ```
