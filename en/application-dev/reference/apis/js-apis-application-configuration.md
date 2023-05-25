# @ohos.application.Configuration (Configuration)

The **Configuration** module defines environment change information. **Configuration** is an interface definition and is used only for field declaration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [@ohos.app.ability.Configuration](js-apis-app-ability-configuration.md) instead.

## Modules to Import

```ts
import Configuration from '@ohos.app.application.Configuration';
```

**System capability**: SystemCapability.Ability.AbilityBase

  | Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language<sup>8+</sup> | string | Yes| Yes| Language of the application.|
| colorMode<sup>8+</sup> | [ColorMode](js-apis-application-configurationConstant.md#configurationconstantcolormode) | Yes| Yes| Color mode, which can be **COLOR_MODE_LIGHT** or **COLOR_MODE_DARK**. The default value is **COLOR_MODE_LIGHT**.|

For details about the fields, see the **ohos.application.Configuration.d.ts** file.

**Example**
    
  ```ts
import Ability from '@ohos.app.ability.UIAbility';
import Window from '@ohos.window'

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
    }

    onDestroy() {
    }

    onWindowStageCreate(windowStage: Window.WindowStage) {
        let envCallback = {
            onConfigurationUpdated(config) {
                console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`);
                let language = config.language;
                let colorMode = config.colorMode;
            },
            onMemoryLevel(level){
                console.log('onMemoryLevel level: ${JSON.stringify(level)}');
            }
        };

        let applicationContext = this.context.getApplicationContext();
        applicationContext.on('environment',envCallback);

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                console.error('failed to load the content, error: + ${JSON.stringify(err)}');
                return;
            }
            console.info('Succeeded in loading the content, data: + ${JSON.stringify(data)}');
        });
    }
}
  ```
