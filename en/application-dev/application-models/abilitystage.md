# AbilityStage Component Manager

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is a component manager at the [module](../quick-start/application-package-overview.md#multi-module-design-mechanism) level. When the [HAP](../quick-start/hap-package.md) of an application is loaded for the first time, an AbilityStage instance is created. You can perform operations such as initialization on the instance. An AbilityStage instance corresponds to a module.

AbilityStage has the lifecycle callbacks [onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate) and [onDestroy()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#ondestroy12) and the event callbacks [onAcceptWant()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onacceptwant), [onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onconfigurationupdate), [onMemoryLevel()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel), [onNewProcessRequest()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11), and [onPrepareTermination()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onpreparetermination15).

- **onCreate()** lifecycle callback: Before the first application component (such as the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) or the [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)) instance of the corresponding module is loaded, an AbilityStage instance is created. This callback is invoked when the AbilityStage instance is created. The AbilityStage module notifies you of when you can perform module initialization such as resource pre-loading and thread creation during module loading.

- **onAcceptWant()** event callback: triggered when the UIAbility is started in [specified mode](uiability-launch-type.md#specified). For details, see [UIAbility Component Launch Type](uiability-launch-type.md).

- **onConfigurationUpdate()** event callback: triggered when a system environment variable changes. The system environment variables, such as the system language and theme, are defined in the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) class before project configuration.

- **onMemoryLevel()** event callback: triggered when the system adjusts the memory. When an application is switched to the background, it is cached in the background. This adversely affects the overall system performance. When system resources are insufficient, the system reclaims memory from applications in multiple ways. For example, the system may stop applications to release memory for executing key tasks. To further maintain the balance of the system memory and prevent the system from stopping application processes, you can subscribe to the system memory changes in the **onMemoryLevel()** lifecycle callback of AbilityStage to release unnecessary resources.

- **onNewProcessRequest()** event callback: triggered when the UIAbility is started. You can use this callback to specify whether each UIAbility should be created in a separate process. The callback returns a custom string identifier. If the returned string matches an existing identifier, the corresponding process is reused; otherwise, a new process is created. Note that this callback must be used in conjunction with the [isolationProcess](../quick-start/module-configuration-file.md#abilities) field set to **true** in the **module.json5** file.

- **onPrepareTermination()** event callback: triggered when the application is closed by the user, allowing the user to choose between immediate termination or cancellation. You can notify the system whether to continue with the shutdown action by returning an enumerated value defined in [AbilityConstant.PrepareTermination](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#preparetermination15) within the callback.

- **onDestroy()** lifecycle callback: triggered when the last Ability instance of the corresponding module exits. This callback is triggered only when the application is destroyed normally. It is not triggered if the application exits abnormally or is terminated.


## How to Develop

### Creating an AbilityStage File

AbilityStage is not automatically generated in the default project of DevEco Studio. To use AbilityStage, you can manually create an AbilityStage file. The procedure is as follows:


1. In the **ets** directory of the **Module** project, right-click and choose **New > Directory** to create a directory named **myabilitystage**.

2. In the **myabilitystage** directory, right-click and choose **New > ArkTS File** to create a file named **MyAbilityStage.ets**.

3. Open the **MyAbilityStage.ets** file, and import the dependency package of AbilityStage. Customize a class that inherits from AbilityStage, and add the required lifecycle callbacks. The following code snippet adds the [onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate) lifecycle callback.

    ```ts
    import { AbilityStage, Want } from '@kit.AbilityKit';
    
    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        // This callback is triggered when the HAP is loaded for the first time. In this callback, you can initialize the module (for example, pre-load resources and create threads).
      }

      onAcceptWant(want: Want): string {
        // Triggered only for the UIAbility with the specified launch type.
        return 'MyAbilityStage';
      }
    }
    ```

4. In the [module.json5 file](../quick-start/module-configuration-file.md), set **srcEntry** to specify the code path of the module as the entry for loading the HAP.

    ```json
    {
      "module": {
        "name": "entry",
        "type": "entry",
        "srcEntry": "./ets/myabilitystage/MyAbilityStage.ets",
        // ...
      }
    }
    ```

### Listening for System Environment Variable Changes

Here is an example of how to use the callback functions of the AbilityStage component to track changes in system environment variables.

- In the **onCreate()** lifecycle, use **EnvironmentCallback** to listen for system environment changes, such as the system language, light/dark mode, screen orientation, font size scaling factor, and font weight scaling factor.

- When a system environment variable changes, the **onConfigurationUpdated()** callback in **EnvironmentCallback** is triggered and related information is logged.

- When the application process is terminated, the **onDestroy()** callback of the AbilityStage component is triggered.

    ```ts
    import { EnvironmentCallback, AbilityStage } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        console.log('AbilityStage onCreate');
        let envCallback: EnvironmentCallback = {
          onConfigurationUpdated(config) {
            console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`);
            let language = config.language; // Current language of the application.
            let colorMode = config.colorMode; // Dark/Light mode.
            let direction = config.direction; // Screen orientation.
            let fontSizeScale = config.fontSizeScale; // Font size scaling factor.
            let fontWeightScale = config.fontWeightScale; // Font weight scaling factor.
          },
          onMemoryLevel(level) {
            console.log(`onMemoryLevel level: ${level}`);
          }
        };
        try {
          let applicationContext = this.context.getApplicationContext();
          let callbackId = applicationContext.on('environment', envCallback);
          console.log(`callbackId: ${callbackId}`);
        } catch (paramError) {
          console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
        }
      }

      onDestroy(): void {
        // Use onDestroy() to listen for the ability destruction event.
        console.log('AbilityStage onDestroy');
      }
    }
    ```
