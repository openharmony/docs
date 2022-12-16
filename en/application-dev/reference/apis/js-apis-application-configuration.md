# @ohos.application.Configuration

The **Configuration** module defines environment change information.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [@ohos.app.ability.Configuration](js-apis-app-ability-configuration.md) instead.

## Modules to Import

```ts
import Configuration from '@ohos.application.Configuration'
```

**System capability**: SystemCapability.Ability.AbilityBase

  | Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language<sup>8+</sup> | string | Yes| Yes| Language of the application.|
| colorMode<sup>8+</sup> | [ColorMode](js-apis-application-configurationConstant.md#configurationconstantcolormode) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.|
| direction<sup>9+</sup> | [Direction](js-apis-application-configurationConstant.md#configurationconstantdirection9) | Yes| No| Screen orientation, which can be **DIRECTION_HORIZONTAL** or **DIRECTION_VERTICAL**.|
| screenDensity<sup>9+</sup>  | [ScreenDensity](js-apis-application-configurationConstant.md#configurationconstantscreendensity9) | Yes| No| Screen resolution, which can be **SCREEN_DENSITY_SDPI** (120), **SCREEN_DENSITY_MDPI** (160), **SCREEN_DENSITY_LDPI** (240), **SCREEN_DENSITY_XLDPI** (320), **SCREEN_DENSITY_XXLDPI** (480), or **SCREEN_DENSITY_XXXLDPI** (640).|
| displayId<sup>9+</sup>  | number | Yes| No| ID of the display where the application is located.|
| hasPointerDevice<sup>9+</sup>  | boolean | Yes| No| Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected.|

For details about the fields, see the **ohos.application.Configuration.d.ts** file.

**Example**
    
  ```ts
import hilog from '@ohos.hilog';
import Ability from '@ohos.application.Ability'
import Window from '@ohos.window'

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
    }

    onDestroy() {
    }

    onWindowStageCreate(windowStage: Window.WindowStage) {
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

        let applicationContext = this.context.getApplicationContext();
        applicationContext.registerEnvironmentCallback(envCallback);

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.ERROR);
                hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
                return;
            }
            hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
            hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
        });
    }
}
  ```
