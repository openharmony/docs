# Subscribing to System Environment Variable Changes

System environment variables are system settings (for example, the system language or screen direction) of a device that may change during the running of an application.

By subscribing to the changes of system environment variables, the application can detect the changes in a timely manner and process the changes accordingly, providing better user experience. For example, when the system language changes, the application can display the UI in the new language; when the user rotates the device to landscape or portrait mode, the application can re-arrange the UI to adapt to the new screen orientation and size.

The system environment variable changes are usually triggered by options in **Settings** or icons in **Control Panel**. For details about the system environment variables that support subscription, see [Configuration](../reference/apis/js-apis-app-ability-configuration.md).

In OpenHarmony, you can subscribe to system environment variable changes in the following ways:

- [Using ApplicationContext for Subscription](#using-applicationcontext-for-subscription)
- [Using AbilityStage for Subscription](#using-abilitystage-for-subscription)
- [Using UIAbility for Subscription](#using-uiability-for-subscription)
- [Using ExtensionAbility for Subscription](#using-extensionability-for-subscription)

## Using ApplicationContext for Subscription

[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md) provides an API for registering a callback function to subscribe to the system environment variable changes. It also provides an API for deregistration so you can release related resources when they are no longer needed.

1. Call **ApplicationContext.on(type: 'environment', callback: EnvironmentCallback)** to subscribe to changes in system environment variables. The code snippet below is used to subscribe to system language changes on a page.

   ```ts
   import common from '@ohos.app.ability.common';
   
   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;
     private callbackId: number; // ID of the subscription for system environment variable changes.
   
     subscribeConfigurationUpdate() {
       let systemLanguage: string = this.context.config.language; // Obtain the system language in use.
   
       // 1. Obtain an ApplicationContext object.
       let applicationContext = this.context.getApplicationContext();
   
       // 2. Subscribe to system environment variable changes through ApplicationContext.
       let environmentCallback = {
         onConfigurationUpdated(newConfig) {
           console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);
   
           if (this.systemLanguage !== newConfig.language) {
             console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
             systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
           }
         },
         onMemoryLevel(level) {
           console.info(`onMemoryLevel level: ${level}`);
         }
       }
   
       this.callbackId = applicationContext.on('environment', environmentCallback);
     }
   
     // Page display.
     build() {
       ...
     }
   }
   ```

2. Call **ApplicationContext.off(type: 'environment', callbackId: number)** to release the resources.

   ```ts
   import common from '@ohos.app.ability.common';
   
   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;
     private callbackId: number; // ID of the subscription for system environment variable changes.
   
     unsubscribeConfigurationUpdate() {
       let applicationContext = this.context.getApplicationContext();
       applicationContext.off('environment', this.callbackId);
     }
   
     // Page display.
     build() {
       ...
     }
   }
   ```

## Using AbilityStage for Subscription

The AbilityStage component provides the [AbilityStage.onConfigurationUpdate()](../reference/apis/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate) callback for subscribing to system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis/js-apis-app-ability-configuration.md) object.  

> **NOTE**
>
> - AbilityStage is not automatically generated in the default project of DevEco Studio. For details about how to create an AbilityStage file, see [AbilityStage Component Container](abilitystage.md).
> - The callback used to subscribe to system environment variable changes has the same lifecycle as the [AbilityStage](../reference/apis/js-apis-app-ability-abilityStage.md) instance and will be destroyed when the instance is destroyed.

The code snippet below uses the [AbilityStage.onConfigurationUpdate()](../reference/apis/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate) callback to subscribe to the system language changes.

```ts
import AbilityStage from '@ohos.app.ability.AbilityStage';

let systemLanguage: string; // System language in use.

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    systemLanguage = this.context.config.language; // Obtain the system language in use when the AbilityStage instance is loaded for the first time.
    console.info(`systemLanguage is ${systemLanguage} `);
  }

  onConfigurationUpdate(newConfig) {
    console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
    }
  }
}
```

## Using UIAbility for Subscription

The UIAbility component provides the **UIAbility.onConfigurationUpdate()** callback for subscribing to system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis/js-apis-app-ability-configuration.md) object, without restarting the UIAbility.

> **NOTE**
>
> The callback used to subscribe to system environment variable changes has the same lifecycle as the UIAbility instance and will be destroyed when the instance is destroyed.

The code snippet below uses the **onConfigurationUpdate()** callback to subscribe to the system language changes.

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let systemLanguage: string; // System language in use.

export default class EntryAbility extends UIAbility {
  onCreate(want, launchParam) {
    systemLanguage = this.context.config.language; // Obtain the system language in use when the UIAbility instance is loaded for the first time.
    console.info(`systemLanguage is ${systemLanguage} `);
  }

  onConfigurationUpdate(newConfig) {
    console.info(`onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      console.info(`systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
    }
  }

  ...
}
```

## Using ExtensionAbility for Subscription

The ExtensionAbility component provides the **onConfigurationUpdate()** callback for subscribing system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis/js-apis-app-ability-configuration.md) object.

> **NOTE**
>
> The callback used to subscribe to system environment variable changes has the same lifecycle as the ExtensionAbility instance and will be destroyed when the instance is destroyed.

The code snippet below uses FormExtensionAbility as an example to describe how to use the **onConfigurationUpdate()** callback to subscribe to system environment variable changes.

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class EntryFormAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig) {
    console.info(`newConfig is ${JSON.stringify(newConfig)}`);
  }

  ...
}
```
