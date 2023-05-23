# @ohos.application.Configuration (Configuration)

定义环境变化信息。Configuration是接口定义，仅做字段声明。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块从API version 9废弃，替换模块为[@ohos.app.ability.Configuration (Configuration)](js-apis-app-ability-configuration.md)

## 导入模块

```ts
import Configuration from '@ohos.app.application.Configuration';
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

  | 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language<sup>8+</sup> | string | 是 | 是 | 表示应用程序的当前语言。 |
| colorMode<sup>8+</sup> | [ColorMode](js-apis-application-configurationConstant.md#configurationconstantcolormode) | 是 | 是 | 表示深浅色模式，取值范围：浅色模式（COLOR_MODE_LIGHT），深色模式（COLOR_MODE_DARK）。默认为浅色。 |

具体字段描述参考ohos.application.Configuration.d.ts文件

**示例：**
    
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

