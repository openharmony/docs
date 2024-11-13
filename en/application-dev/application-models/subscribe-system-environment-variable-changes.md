# Subscribing to System Environment Variable Changes

System environment variables are system settings (for example, the system language or screen orientation) of a device that may change during the running of an application.

By subscribing to the changes of system environment variables, the application can detect the changes in a timely manner and process the changes accordingly, providing better user experience. For example, when the system language changes, the application can display the UI in the new language; when the user rotates the device to landscape or portrait mode, the application can re-arrange the UI to adapt to the new screen orientation and size.

The system environment variable changes are usually triggered by options in **Settings** or icons in **Control Panel**.  For details about the system environment variables that support subscription, see [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md).

You can subscribe to system environment variable changes in the following ways:

- [Using ApplicationContext for Subscription](#using-applicationcontext-for-subscription)
- [Using AbilityStage for Subscription](#using-abilitystage-for-subscription)
- [Using UIAbility for Subscription](#using-uiability-for-subscription)
- [Using ExtensionAbility for Subscription](#using-extensionability-for-subscription)

## Using ApplicationContext for Subscription

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) provides an API for registering a callback function to subscribe to the system environment variable changes. It also provides an API for deregistration so you can release related resources when they are no longer needed.

1. Non-application components can call [on](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextonenvironment) to subscribe to changes in system environment variables. The code snippet below is used to subscribe to system language changes on a page.

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
      private callbackId: number = 0; // ID of the subscription for system environment variable changes.

      subscribeConfigurationUpdate(): void {
        let systemLanguage: string | undefined = this.context.config.language; // Obtain the system language in use.

        // 1. Obtain an ApplicationContext object.
        let applicationContext = this.context.getApplicationContext();

        // 2. Subscribe to system environment variable changes through ApplicationContext.
        let environmentCallback: EnvironmentCallback = {
          onConfigurationUpdated(newConfig: Configuration) {
            hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);
            if (this.systemLanguage !== newConfig.language) {
              hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
              systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
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

      // Page display.
      build() {
        //...
      }
    }
    ```

2. They can call [off](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextoffenvironment-1) to release the resources.

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
      private callbackId: number = 0; // ID of the subscription for system environment variable changes.

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

      // Page display.
      build() {
        //...
      }
    }
    ```

## Using AbilityStage for Subscription

The AbilityStage component provides the [AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate) callback for subscribing to system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object.  

> **NOTE**
>
> - [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is not automatically generated in the default project of DevEco Studio. For details about how to create an AbilityStage file, see [AbilityStage Component Container](abilitystage.md).
> - The callback used to subscribe to system environment variable changes has the same lifecycle as the AbilityStage instance and will be destroyed when the module is destroyed.

The code snippet below uses the [AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate) callback to subscribe to the system language changes.

```ts
import { AbilityStage, Configuration } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MyAbilityStage]';
const DOMAIN_NUMBER: number = 0xFF00;

let systemLanguage: string | undefined; // System language in use.

export default class MyAbilityStage extends AbilityStage {
  onCreate(): void {
    systemLanguage = this.context.config.language; // Obtain the system language in use when the module is loaded for the first time.
    hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage is ${systemLanguage}`);
    //...
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdate, language: ${newConfig.language}`);
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
    }
  }
}
```

## Using UIAbility for Subscription

The [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component provides the [UIAbility.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback for subscribing to system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object, without restarting the UIAbility.

> **NOTE**
>
> The callback used to subscribe to system environment variable changes has the same lifecycle as the UIAbility instance and will be destroyed when the instance is destroyed.

The code snippet below uses the [onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback to subscribe to the system language changes.

```ts
import { AbilityConstant, Configuration, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

let systemLanguage: string | undefined; // System language in use.

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    systemLanguage = this.context.config.language; // Obtain the system language in use when the UIAbility instance is loaded for the first time.
    hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage is ${systemLanguage}`);
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);

    if (systemLanguage !== newConfig.language) {
      hilog.info(DOMAIN_NUMBER, TAG, `systemLanguage from ${systemLanguage} changed to ${newConfig.language}`);
      systemLanguage = newConfig.language; // Save the new system language as the system language in use, which will be used for comparison.
    }
  }
  // ...
}
```

## Using ExtensionAbility for Subscription

The [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) component provides the [onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback for subscribing to system environment variable changes. This callback is invoked when a system environment variable changes. In this callback, the latest system environment configuration is obtained through the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object.

> **NOTE**
>
> The callback used to subscribe to system environment variable changes has the same lifecycle as the ExtensionAbility instance and will be destroyed when the instance is destroyed.

The code snippet below uses [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) as an example to describe how to use the [onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback to subscribe to system environment variable changes.

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
