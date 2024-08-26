# AbilityStage组件容器


[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)是一个[Module](../quick-start/application-package-structure-stage.md)级别的组件容器，应用的[HAP](../quick-start/hap-package.md)在首次加载时会创建一个AbilityStage实例，可以对该Module进行初始化等操作。


AbilityStage与Module一一对应，即一个Module拥有一个AbilityStage。


DevEco Studio默认工程中未自动生成AbilityStage，如需要使用AbilityStage的能力，可以手动新建一个AbilityStage文件，具体步骤如下。


1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为myabilitystage。

2. 在myabilitystage目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为MyAbilityStage.ets。

3. 打开MyAbilityStage.ets文件，导入AbilityStage的依赖包，自定义类继承AbilityStage并加上需要的生命周期回调，示例中增加了一个[onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageoncreate)生命周期回调。
   
    ```ts
    import { AbilityStage, Want } from '@kit.AbilityKit';
    
    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        // 应用的HAP在首次加载的时，为该Module初始化操作
      }

      onAcceptWant(want: Want): string {
        // 仅specified模式下触发
        return 'MyAbilityStage';
      }
    }
    ```
   
4. 在[module.json5配置文件](../quick-start/module-configuration-file.md)中，通过配置 `srcEntry` 参数来指定模块对应的代码路径，以作为HAP加载的入口。

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

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)拥有[onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageoncreate)生命周期回调和[onAcceptWant()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonacceptwant)、[onConfigurationUpdated()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonconfigurationupdate)、[onMemoryLevel()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonmemorylevel)事件回调。


- onCreate()生命周期回调：在开始加载对应Module的第一个[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)实例之前会先创建AbilityStage，并在AbilityStage创建完成之后执行其onCreate()生命周期回调。AbilityStage模块提供在Module加载的时候，通知开发者，可以在此进行该Module的初始化（如资源预加载，线程创建等）能力。

- onAcceptWant()事件回调：UIAbility[指定实例模式（specified）](uiability-launch-type.md#specified启动模式)启动时候触发的事件回调，具体使用请参见[UIAbility启动模式综述](uiability-launch-type.md)。

- onConfigurationUpdated()事件回调：当系统全局配置发生变更时触发的事件，系统语言、深浅色等，配置项目前均定义在[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)类中。

- onMemoryLevel()事件回调：当系统调整内存时触发的事件。

应用被切换到后台时，系统会将在后台的应用保留在缓存中。即使应用处于缓存中，也会影响系统整体性能。当系统资源不足时，系统会通过多种方式从应用中回收内存，必要时会完全停止应用，从而释放内存用于执行关键任务。为了进一步保持系统内存的平衡，避免系统停止用户的应用进程，可以在AbilityStage中的onMemoryLevel()生命周期回调中订阅系统内存的变化情况，释放不必要的资源。


  ```ts
  import { AbilityStage, AbilityConstant } from '@kit.AbilityKit';

  export default class MyAbilityStage extends AbilityStage {
    onMemoryLevel(level: AbilityConstant.MemoryLevel): void {
      // 根据系统可用内存的变化情况，释放不必要的内存
    }
  }
  ```
