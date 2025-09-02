# Obtaining/Setting Environment Variables

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy; @xuzhihao666-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

Environment variables encompass all configuration information that may affect the runtime environment of an application, including internal environment variables that the application can specify (such as font size, appearance, and language) and external environment variables that the application can detect (such as screen orientation).

Under normal circumstances, environment variables change with system settings.

## When to Use
|  Scenario  |  Description      |  Constraints | Example  |
|------------|-------------------|-------------|-----------------|
| [Obtaining Environment Variables](#obtaining-environment-variables)| You can use [getConfigurationSync](../reference/apis-localization-kit/js-apis-resource-manager.md#getconfigurationsync10) to proactively obtain the current environment variables, including dark/light color mode, screen orientation, locale, screen density, and device type.       | Currently, only synchronous retrieval is supported. For details about how to obtain them, see [ResourceManager.getConfigurationSync](../reference/apis-localization-kit/js-apis-resource-manager.md#getconfigurationsync10). |During the application running, you can obtain the dark/light color mode of the application to update UI display. |
| [Setting Environment Variables](#setting-environment-variables)| Currently, only the font size, dark/light color mode, and language can be customized.<br>- [Setting Font Size](#setting-font-size)<br>- [Setting Dark/Light Color Mode](#setting-darklight-color-mode)<br>- [Setting Application Language](#setting-application-language)|  Once the application sets environment variables, it will not be able to detect changes to these variables in the system through subscriptions.  |  Customize the font size of an application to enhance user experience.|
| [Subscribing to Environment Variables](#subscribing-to-environment-variables)| By subscribing to environment variables, you can promptly detect changes in the system environment. Supported variables include language, dark/light color mode, and screen orientation. For details, see [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md).                  |    If you configure environment variables to not follow system changes (by setting the corresponding field in the [configuration](../quick-start/app-configuration-file.md#configuration) tag to **nonFollowSystem**), the application will not be able to detect changes to these variables in the system through subscriptions.<br>- Background applications do not receive real-time notifications. The event is queued until the application returns to the foreground.| When a user rotates the device screen, the application can detect environmental changes through subscriptions and re-layout the UI to adapt to the screen orientation and size.|


## Obtaining Environment Variables

You can use [getConfigurationSync](../../application-dev/reference/apis-localization-kit/js-apis-resource-manager.md#getconfigurationsync10) to obtain the [current environment variables](../../application-dev/reference/apis-localization-kit/js-apis-resource-manager.md#configuration), including the dark/light color mode, screen orientation, locale, screen density, and device type. The information helps your application react instantly and deliver a better user experience.

  ```ts
  import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      try {
        let value = this.context.resourceManager.getConfigurationSync();
        // Screen orientation.
        let direction = value.direction;
        // Locale.
        let locale = value.locale;
      } catch (error) {
        console.error("getConfigurationSync error is " + error);
      }
    }
  }
  ```
  
## Setting Environment Variables

The following environment variables can be customized: [font size](#setting-font-size), [dark/light color mode](#setting-darklight-color-mode), and [application language](#setting-application-language). Other environment variables (such as the screen orientation) are read-only.

### Setting Font Size

By default, your application's font size does not change with the system. You can set **fontSizeScale** in [configuration](../quick-start/app-configuration-file.md#configuration) to **nonFollowSystem** to enable it to follow the system setting.

You can use [setFontSizeScale](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetfontsizescale13) to set the font size for the application. After the setting, the application's font size will not change with the system, and you will no longer be able to subscribe to system font size changes.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        return;
      }
    });
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setFontSizeScale(2);
  }
}
```

### Setting Dark/Light Color Mode

By default, your application's dark/light color mode follows the system. You can customize the dark/light color modes of your application or components.

The configuration takes effect in the following priority: UIAbility's or UIExtensionAbility's dark/light color mode > Application's dark/light color mode > System's dark/light color mode.

- **Application's dark/light color mode**: Use [setColorMode](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetcolormode11) of ApplicationContext to set the dark/light color mode of the application.

    ```ts
    import { UIAbility, ConfigurationConstant } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { window } from '@kit.ArkUI';

    export default class MyAbility extends UIAbility {
      onWindowStageCreate(windowStage: window.WindowStage) {
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            hilog.error(0x0000, 'testTag', 'Failed to load the content.');
            return;
          }
          let applicationContext = this.context.getApplicationContext();
          applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
        });
      }
    }
    ```

- **UIAbility's dark/light color mode**: Use [setColorMode](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#setcolormode18) of UIAbilityContext to set the dark/light color mode of the UIAbility.

    ```ts
    import { UIAbility, ConfigurationConstant } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { window } from '@kit.ArkUI';

    export default class MyAbility extends UIAbility {
      onWindowStageCreate(windowStage: window.WindowStage) {
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            hilog.error(0x0000, 'testTag', 'Failed to load the content.');
            return;
          }
          let uiAbilityContext = this.context;
          uiAbilityContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
        });
      }
    }
    ```

- **UIExtensionAbility's dark/light color mode**: Use [setColorMode](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md#setcolormode18) of UIExtensionContext to set the dark/light color mode of the UIExtensionAbility.

    ```ts
    // The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
    import { ShareExtensionAbility, ConfigurationConstant } from '@kit.AbilityKit';

    export default class MyAbility extends ShareExtensionAbility {
      onForeground() {
        let uiExtensionContext = this.context;
        uiExtensionContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
      }
    }
    ```

### Setting Application Language

By default, the application language changes with the system language. You can use [setLanguage](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetlanguage11) to set the application language. After the setting, you will no longer be able to subscribe to system language changes.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content.');
        return;
      }
      let applicationContext = this.context.getApplicationContext();
      applicationContext.setLanguage('zh-cn');
    });
  }
}
```

## Subscribing to Environment Variables

System configuration changes are usually triggered by options in Settings or icons in Control Panel. Subscribing to environment variable changes enables applications to respond to system environment changes more intelligently, providing better user experience. For details about the environment variables that support subscription, see [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md).

You can subscribe to environment variable changes in the following ways:

- [Using ApplicationContext for Subscription](#using-applicationcontext-for-subscription)
- [Using AbilityStage for Subscription](#using-abilitystage-for-subscription)
- [Using UIAbility for Subscription](#using-uiability-for-subscription)
- [Using ExtensionAbility for Subscription](#using-extensionability-for-subscription)

### Using ApplicationContext for Subscription

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) provides an API for registering a callback function to subscribe to the environment variable changes. It also provides an API for deregistration so you can release related resources when they are no longer needed.

1. Non-application components can call [on](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextonenvironment) to subscribe to changes in environment variables. The code snippet below is used to subscribe to system language changes on a page.

    ```ts
    import { common, EnvironmentCallback, Configuration } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = '[MyAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      private callbackId: number = 0; // ID of the subscription for system environment variable changes.

      subscribeConfigurationUpdate(): void {
        let systemLanguage: string | undefined = this.context.config.language; // Obtain the system language in use.

        // 1. Obtain an ApplicationContext object.
        let applicationContext = this.context.getApplicationContext();

        // 2. Subscribe to environment variable changes through ApplicationContext.
        let environmentCallback: EnvironmentCallback = {
          onConfigurationUpdated(newConfig: Configuration) {
            hilog.info(DOMAIN_NUMBER, TAG, `onConfigurationUpdated systemLanguage is ${systemLanguage}, newConfig: ${JSON.stringify(newConfig)}`);
            if (systemLanguage !== newConfig.language) {
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

    const TAG: string = '[MyAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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

### Using AbilityStage for Subscription

The AbilityStage component provides the [AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onconfigurationupdate) callback for subscribing to environment variable changes. This callback is invoked when an environment variable changes. In this callback, the latest environment variable information is obtained through a [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object. You can perform operations such as UI adaptation to improve system flexibility and maintainability.

> **NOTE**
>
> - [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is not automatically generated in the default project of DevEco Studio. For details about how to create an AbilityStage file, see [AbilityStage Component Container](abilitystage.md#how-to-develop).
> - The callback used to subscribe to system environment variable changes has the same lifecycle as the AbilityStage instance and will be destroyed when the module is destroyed.

The code snippet below uses the [AbilityStage.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onconfigurationupdate) callback to subscribe to the system language changes.

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

### Using UIAbility for Subscription

The [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) provides the [UIAbility.onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback for subscribing to environment variable changes. This callback is invoked when an environment variable changes. In this callback, the latest environment variable information is obtained through the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object, without restarting the UIAbility.

> **NOTE**
>
> - When an application subscribes to environment variable changes through a callback, the subscription remains valid throughout the lifecycle of the hosting UIAbility. Once the UIAbility is destroyed, all previously registered callback subscriptions become invalid, and the application will no longer receive any callback notifications.
> - If this API is used to listen for screen orientation changes, you need to set **orientation** to **auto_rotation** in [abilities](../quick-start/module-configuration-file.md#abilities) of the **module.json5** file.

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

### Using ExtensionAbility for Subscription

The [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) provides the [onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) callback for subscribing to environment variable changes. This callback is invoked when an environment variable changes. In this callback, the latest environment variable information is obtained through a [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) object.

> **NOTE**
>
> When an application subscribes to environment variable changes through a callback, the subscription remains valid throughout the lifecycle of the hosting ExtensionAbility. Once the ExtensionAbility is destroyed, all previously registered callback subscriptions become invalid, and the application will no longer receive any callback notifications.

The code snippet below uses [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) as an example to describe how to use the [onConfigurationUpdate()](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonconfigurationupdate) callback to subscribe to environment variable changes.

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Configuration } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class EntryFormAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(newConfig));
  }
  // ...
}
```
