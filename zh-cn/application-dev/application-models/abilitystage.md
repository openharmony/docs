# AbilityStage组件管理器

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## 概述

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)是一个[Module](../quick-start/application-package-overview.md#应用的多module设计机制)级别的组件管理器，应用的[HAP](../quick-start/hap-package.md)在首次加载时会创建一个AbilityStage实例，可以对该Module进行初始化等操作。AbilityStage与Module一一对应，即一个Module拥有一个AbilityStage。

AbilityStage拥有[onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate)、[onDestroy()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#ondestroy12)生命周期回调和[onAcceptWant()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onacceptwant)、[onConfigurationUpdate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onconfigurationupdate)、[onMemoryLevel()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel)、[onNewProcessRequest()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11)、[onPrepareTermination()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onpreparetermination15)等事件回调。

- onCreate()生命周期回调：在开始加载对应Module的第一个应用组件（如[UIAbility组件](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)或具体扩展能力的[ExtensionAbility组件](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)）实例之前会先创建AbilityStage，并在AbilityStage创建完成之后执行其onCreate()生命周期回调。AbilityStage模块提供在Module加载的时候，通知开发者，可以在此进行该Module的初始化（如资源预加载、线程创建等）。

- onAcceptWant()事件回调：UIAbility[指定实例模式（specified）](uiability-launch-type.md#specified启动模式)启动时候触发的事件回调，具体使用请参见[UIAbility启动模式综述](uiability-launch-type.md)。

- onConfigurationUpdate()事件回调：当系统环境变量（例如系统语言、深浅色等）发生变更时触发的事件回调，配置项均定义在[Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)类中。

- onMemoryLevel()事件回调：当系统调整内存时触发的事件回调。应用被切换到后台时，系统会将在后台的应用保留在缓存中。即使应用处于缓存中，也会影响系统整体性能。当系统资源不足时，系统会通过多种方式从应用中回收内存，必要时会完全停止应用，从而释放内存用于执行关键任务。为了进一步保持系统内存的平衡，避免系统停止用户的应用进程，可以在AbilityStage中的onMemoryLevel()生命周期回调中订阅系统内存的变化情况，释放不必要的资源。

- onNewProcessRequest()事件回调：UIAbility启动时触发的事件回调。通过该回调，开发者可以指定每个UIAbility启动时是否在独立的进程中创建。该回调返回一个开发者自定义字符串标识，如果返回的字符串标识为开发者曾创建的，则复用该标识所对应的进程，否则创建新的进程。需要注意该回调需要配合在module.json5中声明[isolationProcess](../quick-start/module-configuration-file.md#abilities标签)字段为true。

- onPrepareTermination()事件回调：当应用被用户关闭时调用，可用于询问用户选择立即执行操作还是取消操作。开发者通过在回调中返回[AbilityConstant.PrepareTermination](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#preparetermination15)中定义的枚举类型通知系统是否继续执行关闭动作。

- onDestroy()生命周期回调：当对应Module的最后一个Ability实例退出后触发。此方法仅在应用正常销毁时触发。当应用程序异常退出或被终止时，将不会调用此方法。


## 开发步骤

### 创建AbilityStage文件

DevEco Studio默认工程中未自动生成AbilityStage，如需要使用AbilityStage的能力，可以手动新建一个AbilityStage文件，具体步骤如下。


1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为myabilitystage。

2. 在myabilitystage目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为MyAbilityStage.ets。

3. 打开MyAbilityStage.ets文件，导入AbilityStage的依赖包，自定义类继承AbilityStage并加上需要的生命周期回调，示例中增加了一个[onCreate()](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#oncreate)生命周期回调。

    ```ts
    import { AbilityStage, Want } from '@kit.AbilityKit';
    
    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        // 应用HAP首次加载时触发，可以在此执行该Module的初始化操作（例如资源预加载、线程创建等）。
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

### 监听系统环境变量的变化

下面以监听系统环境变量的变化的开发场景为例，介绍AbilityStage组件回调函数的使用。

- 在onCreate()生命周期中，通过EnvironmentCallback来监听系统环境变化，例如系统语言、深浅色模式、屏幕方向、字体大小缩放比例、字体粗细缩放比例等信息。

- 当系统环境变量发生变更时，会触发EnvironmentCallback中的onConfigurationUpdated()回调，并打印相关信息。

- 通过关闭应用进程，可以触发AbilityStage的onDestroy()生命周期回调。

    ```ts
    import { EnvironmentCallback, AbilityStage } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        console.info('AbilityStage onCreate');
        let envCallback: EnvironmentCallback = {
          onConfigurationUpdated(config) {
            console.info(`envCallback onConfigurationUpdated success: ${JSON.stringify(config)}`);
            let language = config.language; //应用程序的当前语言
            let colorMode = config.colorMode; //深浅色模式
            let direction = config.direction; //屏幕方向
            let fontSizeScale = config.fontSizeScale; //字体大小缩放比例
            let fontWeightScale = config.fontWeightScale; //字体粗细缩放比例
          },
          onMemoryLevel(level) {
            console.info(`onMemoryLevel level: ${level}`);
          }
        };
        try {
          let applicationContext = this.context.getApplicationContext();
          let callbackId = applicationContext.on('environment', envCallback);
          console.info(`callbackId: ${callbackId}`);
        } catch (paramError) {
          console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
        }
      }

      onDestroy(): void {
        // 通过onDestroy()方法，可以监听到Ability的销毁事件。
        console.info('AbilityStage onDestroy');
      }
    }
    ```