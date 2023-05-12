# 订阅系统环境变量的变化

系统环境变量是指：在应用程序运行期间，终端设备的系统设置（例如系统的语言环境、屏幕方向等）发生变化。

开发者通过订阅系统环境变化，可以使应用程序及时感知这种变化，并作出相应处理，从而提供更好的用户体验。例如，用户更改系统语言设置时，应用程序可以自动根据新的语言设置更新用户界面的语言；当用户将设备旋转到横屏或者竖屏时，应用程序可以重新布局用户界面，以适应屏幕方向和尺寸。

系统配置的变化通常由“设置”中的选项或“控制中心”中的图标触发。订阅系统环境变量变化，可以使应用程序更加智能地响应系统环境变化，从而提供更好的用户体验。查看当前支持订阅变化的系统环境变量，请参见[Configuration](../reference/apis/js-apis-app-ability-configuration.md)。

基于OpenHarmony应用模型，可以通过以下几种方式来实现订阅系统环境变量的变化。

- [使用ApplicationContext订阅回调](#使用applicationcontext订阅回调)
- [在AbilityStage组件容器中订阅回调](#在abilitystage组件容器中订阅回调)
- [在UIAbility组件中订阅回调](#在uiability组件中订阅回调)
- [在ExtensionAbility组件中订阅回调](#在extensionability组件中订阅回调)

## 使用ApplicationContext订阅回调

[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md)提供了注册回调函数以订阅系统环境变量的变化，并且可以通过调用相应的方法来撤销该回调。这有助于在资源不再需要时释放相关资源，从而提高系统的可靠性和性能。

1. 使用`ApplicationContext.on(type: 'environment', callback: EnvironmentCallback)`方法，应用程序可以通过在非应用组件模块中订阅系统环境变量的变化来动态响应这些变化。例如，使用该方法在页面中监测系统语言的变化。

   ```ts
   import common from '@ohos.app.ability.common';
   
   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;
     private callbackId: number; // 注册订阅系统环境变化的ID
   
     subscribeConfigurationUpdate() {
       let systemLanguage: string = this.context.config.language; // 获取系统当前语言
   
       // 1.获取ApplicationContext
       let applicationContext = this.context.getApplicationContext();
   
       // 2.通过applicationContext订阅环境变量变化
       let environmentCallback = {
         onConfigurationUpdated(newConfig) {
           console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);
   
           if (this.systemLanguage !== newConfig.language) {
             console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
             systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
           }
         },
         onMemoryLevel(level) {
           console.info(`onMemoryLevel level: ${level}`);
         }
       }
   
       this.callbackId = applicationContext.on('environment', environmentCallback);
     }
   
     // 页面展示
     build() {
       ...
     }
   }
   ```

2. 在资源使用完成之后，可以通过调用`ApplicationContext.off(type: 'environment', callbackId: number)`方法释放相关资源。

   ```ts
   import common from '@ohos.app.ability.common';
   
   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;
     private callbackId: number; // 注册订阅系统环境变化的ID
   
     unsubscribeConfigurationUpdate() {
       let applicationContext = this.context.getApplicationContext();
       applicationContext.off('environment', this.callbackId);
     }
   
     // 页面展示
     build() {
       ...
     }
   }
   ```

## 在AbilityStage组件容器中订阅回调

使用[AbilityStage.onConfigurationUpdate()](../reference/apis/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate)回调方法订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息。可以进行相应的界面适配等操作，从而提高系统的灵活性和可维护性。

> **说明：**
>
> - DevEco Studio默认工程中未自动生成AbilityStage，AbilityStage文件的创建请参见[AbilityStage组件容器](abilitystage.md)。
> - 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着[AbilityStage](../reference/apis/js-apis-app-ability-abilityStage.md)的生命周期而存在，在Module销毁时一并销毁。

例如，在[AbilityStage.onConfigurationUpdate()](../reference/apis/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate)回调方法中实现监测系统语言的变化。

```ts
import AbilityStage from '@ohos.app.ability.AbilityStage';

let systemLanguage: string; // 系统当前语言

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    systemLanguage = this.context.config.language; // Module首次加载时，获取系统当前语言
    console.info(`systemLanguage is ${systemLanguage} `);
  }

  onConfigurationUpdate(newConfig) {
    console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
    }
  }
}
```

## 在UIAbility组件中订阅回调

UIAbility组件提供了`UIAbility.onConfigurationUpdate()`回调方法用于订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息，而无需重启UIAbility。

> **说明：**
>
> 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着UIAbility的生命周期而存在，在UIAbility销毁时一并销毁。

例如，在`onConfigurationUpdate()`回调方法中实现监测系统语言的变化。

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let systemLanguage: string; // 系统当前语言

export default class EntryAbility extends UIAbility {
  onCreate(want, launchParam) {
    systemLanguage = this.context.config.language; // UIAbility实例首次加载时，获取系统当前语言
    console.info(`systemLanguage is ${systemLanguage} `);
  }

  onConfigurationUpdate(newConfig) {
    console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // 将变化之后的系统语言保存，作为下一次变化前的系统语言
    }
  }

  ...
}
```

## 在ExtensionAbility组件中订阅回调

ExtensionAbility组件提供了`onConfigurationUpdate()`回调方法用于订阅系统环境变量的变化。当系统环境变量发生变化时，会调用该回调方法。在该方法中，通过[Configuration](../reference/apis/js-apis-app-ability-configuration.md)对象获取最新的系统环境配置信息。

> **说明：**
>
> 当使用回调方法订阅系统环境变量的变化时，该回调方法会随着ExtensionAbility的生命周期而存在，在ExtensionAbility销毁时一并销毁。

以FormExtensionAbility为例说明。例如，在`onConfigurationUpdate()`回调方法中实现系统环境变量的变化。

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class EntryFormAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig) {
    console.info(`newConfig is ${JSON.stringify(newConfig)}`);
  }

  ...
}
```
