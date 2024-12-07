# AbilityStage Component Container


[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is a component container at the [module](../quick-start/application-package-structure-stage.md) level. When the [HAP](../quick-start/hap-package.md) of an application is loaded for the first time, an AbilityStage instance is created. You can perform operations such as initialization on the instance.


An AbilityStage instance corresponds to a module.


AbilityStage is not automatically generated in the default project of DevEco Studio. To use AbilityStage, you can manually create an AbilityStage file. The procedure is as follows:


1. In the **ets** directory of the **Module** project, right-click and choose **New > Directory** to create a directory named **myabilitystage**.

2. In the **myabilitystage** directory, right-click and choose **New > ArkTS File** to create a file named **MyAbilityStage.ets**.

3. Open the **MyAbilityStage.ets** file, and import the dependency package of AbilityStage. Customize a class that inherits from AbilityStage, and add the required lifecycle callbacks. The following code snippet adds the [onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageoncreate) lifecycle callback.
   
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

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) has the lifecycle callback [onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageoncreate) and the event callbacks [onAcceptWant()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonacceptwant), [onConfigurationUpdated()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate), and [onMemoryLevel()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonmemorylevel).


- **onCreate()** lifecycle callback: Before the first [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) instance of a module is loaded, an AbilityStage instance is created. This callback is invoked when the AbilityStage instance is created. The AbilityStage module notifies you of when you can perform module initialization such as resource pre-loading and thread creation during module loading.

- **onAcceptWant()** event callback: triggered when the UIAbility is started in [specified mode](uiability-launch-type.md#specified). For details, see [UIAbility Component Launch Type](uiability-launch-type.md).

- **onConfigurationUpdated()** event callback: triggered when the global system configuration changes. The global system configuration, such as the system language and theme, are defined in the [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md) class before project configuration.

- **onMemoryLevel()** event callback: triggered when the system adjusts the memory.

When an application is switched to the background, it is cached in the background. This adversely affects the overall system performance. When system resources are insufficient, the system reclaims memory from applications in multiple ways. For example, the system may stop applications to release memory for executing key tasks. To further maintain the balance of the system memory and prevent the system from stopping application processes, you can subscribe to the system memory changes in the **onMemoryLevel()** lifecycle callback of AbilityStage to release unnecessary resources.


  ```ts
  import { AbilityStage, AbilityConstant } from '@kit.AbilityKit';

  export default class MyAbilityStage extends AbilityStage {
    onMemoryLevel(level: AbilityConstant.MemoryLevel): void {
      // Release unnecessary memory based on the change of available system memory.
    }
  }
  ```
