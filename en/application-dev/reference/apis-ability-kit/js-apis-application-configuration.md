# @ohos.application.Configuration (Configuration)

The **Configuration** module defines environment change information. **Configuration** is an interface definition and is used only for field declaration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [@ohos.app.ability.Configuration](js-apis-app-ability-configuration.md) instead.

## Modules to Import

```ts
import Configuration from '@ohos.application.Configuration';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityBase

  | Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language<sup>8+</sup> | string | Yes| Yes| Language of the application, for example, **zh**.|
| colorMode<sup>8+</sup> | [ConfigurationConstant.ColorMode](js-apis-application-configurationConstant.md#colormode) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.|

For details about the fields, see the **ohos.application.Configuration.d.ts** file.

**Example**
  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import EnvironmentCallback from '@ohos.app.ability.EnvironmentCallback';
import Want from '@ohos.app.ability.Want';
import Window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    }

    onDestroy() {
    }

    onWindowStageCreate(windowStage: Window.WindowStage) {
        let envCallback: EnvironmentCallback = {
            onConfigurationUpdated(config) {
                console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`);
                let language = config.language;
                let colorMode = config.colorMode;
            },
            onMemoryLevel(level){
                console.log(`onMemoryLevel level: ${JSON.stringify(level)}`);
            }
        };

        let applicationContext = this.context.getApplicationContext();
        try {
            applicationContext.on('environment',envCallback);
        } catch (paramError) {
            console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
        }

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                console.error(`failed to load the content, error: ${JSON.stringify(err)}`);
                return;
            }
            console.info(`Succeeded in loading the content, data: ${JSON.stringify(data)}`);
        });
    }
}
  ```
