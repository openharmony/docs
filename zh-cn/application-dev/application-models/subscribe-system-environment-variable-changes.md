# 订阅系统环境变量的变化

系统环境变量是指：在应用程序运行期间，终端设备的系统设置（例如系统的语言环境、屏幕方向等）发生变化。

开发者通过订阅系统环境变化，可以使应用程序及时感知这种变化，并作出相应处理，从而提供更好的用户体验。例如，用户更改系统语言设置时，应用程序可以自动根据新的语言设置更新用户界面的语言；当用户将设备旋转到横屏或者竖屏时，应用程序可以重新布局用户界面，以适应屏幕方向和尺寸。

系统配置的变化通常由“设置”中的选项或“控制中心”中的图标触发。订阅系统环境变量变化，可以使应用程序更加智能地响应系统环境变化，从而提供更好的用户体验。查看当前支持订阅变化的系统环境变量，请参见[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)。

基于当前的应用模型，可以通过以下几种方式来实现订阅系统环境变量的变化。

- [使用ApplicationContext订阅回调](#使用applicationcontext订阅回调)
- [在AbilityStage组件容器中订阅回调](#在abilitystage组件容器中订阅回调)
- [在UIAbility组件中订阅回调](#在uiability组件中订阅回调)
- [在ExtensionAbility组件中订阅回调](#在extensionability组件中订阅回调)

## 使用ApplicationContext订阅回调

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)提供了注册回调函数以订阅系统环境变量的变化，并且可以通过调用相应的方法来撤销该回调。这有助于在资源不再需要时释放相关资源，从而提高系统的可靠性和性能。

1. 使用[on](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextonenvironment)方法，应用程序可以通过在非应用组件模块中订阅系统环境变量的变化来动态响应这些变化。例如，使用该方法在页面中监测系统语言的变化。

    ```ts
    import { common, EnvironmentCallback, Configuration } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = '[CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      private context = getContext(this) as common.UIAbilityContext;
      private callbackId: number = 0; // 注册订阅系统环境变化的ID

      subscribeConfigurationUpdate(): void {
        let systemLanguage: string | undefined = this.context.config.language; // 获取系统当前语言

        // 1.获取ApplicationContext
        let applicationContext = this.context.getApplicationContext();

        // 2.通过applicationContext订阅环境变量变化
        let environmentCallback: EnvironmentCallback = {
          onConfigurationUpdated(newConfig: Configuration) {
            hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);
            if (systemLanguage !== newConfig.language) {
              hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
              systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
            }
          },
          onMemoryLevel(level) {
            hilog.info(DOMAIN_NUMBER, TAG, `onMemoryLevel level: ${level}`);
          }
        }
        try {
          this.callbackId = applicationContext.on('environment', environmentCallback);
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to register applicationContext. Code is ${code}, message is ${message}`);
        }
      }

      // 页面展示
      build() {
        //...
      }
    }
    ```

2. 在资源使用完成之后，可以通过调用[off](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextoffenvironment-1)方法释放相关资源。

    ```ts
    import { common } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = '[CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      private context = getContext(this) as common.UIAbilityContext;
      private callbackId: number = 0; // 注册订阅系统环境变化的ID

      unsubscribeConfigurationUpdate() {
        let applicationContext = this.context.getApplicationContext();
        try {
          applicationContext.off('environment', this.callbackId);
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to unregister applicationContext. Code is ${code}, message is ${message}`);
        }
      }

      // 页面展示
      build() {
        //...
      }
    }
    ```

## 在AbilityStage组件容器中订阅回调

使用[AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate)回调方法订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息。可以进行相应的界面适配等操作，从而提高系统的灵活性和可维护性。

> **说明：**
>
> - DevEco Studio默认工程中未自动生成[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)，AbilityStage文件的创建请参见[AbilityStage组件容器](abilitystage.md)。
> - 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着AbilityStage的生命周期而存在，在Module销毁时一并销毁。

例如，在[AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate)回调方法中实现监测系统语言的变化。

```ts
import { AbilityStage, Configuration } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MyAbilityStage]';
const DOMAIN_NUMBER: number = 0xFF00;

let systemLanguage: string | undefined; // 系统当前语言

export default class MyAbilityStage extends AbilityStage {
  onCreate(): void {
    systemLanguage = this.context.config.language; // Module首次加载时，获取系统当前语言
    hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage is ${systemLanguage}`);
    //...
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdate, language: ${newConfig.language}`);
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
    }
  }
}
```

## 在UIAbility组件中订阅回调

[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)组件提供了[UIAbility.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)回调方法用于订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息，而无需重启UIAbility。

> **说明：**
>
> 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着UIAbility的生命周期而存在，在UIAbility销毁时一并销毁。

例如，在[onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)回调方法中实现监测系统语言的变化。

```ts
import { AbilityConstant, Configuration, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

let systemLanguage: string | undefined; // 系统当前语言

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    systemLanguage = this.context.config.language; // UIAbility实例首次加载时，获取系统当前语言
    hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage is ${systemLanguage}`);
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
    }
  }
  // ...
}
```

## 在ExtensionAbility组件中订阅回调

[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件提供了[onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)回调方法用于订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息。

> **说明：**
>
> 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着ExtensionAbility的生命周期而存在，在ExtensionAbility销毁时一并销毁。

以[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)为例说明。例如，在[onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)回调方法中实现系统环境变量的变化。

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Configuration } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class EntryFormAbility extends FormExtensionAbility {
  onConfigurationUpdate(config: Configuration) {
    hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
  }
  // ...
}
```
