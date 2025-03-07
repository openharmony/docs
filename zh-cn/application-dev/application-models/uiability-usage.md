# UIAbility组件基本用法


[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)组件的基本用法包括：指定UIAbility的启动页面以及获取UIAbility的上下文[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。


## 指定UIAbility的启动页面

应用中的[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)在启动过程中，需要指定启动页面，否则应用启动后会因为没有默认加载页面而导致白屏。可以在UIAbility的[onWindowStageCreate()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate)生命周期回调中，通过[WindowStage](../reference/apis-arkui/js-apis-window.md#windowstage9)对象的[loadContent()](../reference/apis-arkui/js-apis-window.md#loadcontent9)方法设置启动页面。


```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    windowStage.loadContent('pages/Index', (err, data) => {
      // ...
    });
  }
  // ...
}
```

> **说明：**
> 在DevEco Studio中创建的UIAbility中，该UIAbility实例默认会加载Index页面，根据需要将Index页面路径替换为需要的页面路径即可。


## 获取UIAbility的上下文信息

[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)类拥有自身的上下文信息，该信息为[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)类的实例，[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)类拥有abilityInfo、currentHapModuleInfo等属性。通过UIAbilityContext可以获取UIAbility的相关配置信息，如包代码路径、Bundle名称、Ability名称和应用程序需要的环境状态等属性信息，以及可以获取操作UIAbility实例的方法（如[startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)、[connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)、[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)等）。
如果需要在页面中获得当前Ability的Context，可调用[getContext](../reference/apis-arkui/js-apis-getContext.md#getcontext)接口获取当前页面关联的UIAbilityContext或[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)。

- 在UIAbility中可以通过`this.context`获取UIAbility实例的上下文信息。
  
  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // 获取UIAbility实例的上下文
      let context = this.context;
      // ...
    }
  }
  ```
  
- 在页面中获取UIAbility实例的上下文信息，包括导入依赖资源context模块和在组件中定义一个context变量两个部分。
  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_EventHub {
    private context = getContext(this) as common.UIAbilityContext;

    startAbilityTest(): void {
      let want: Want = {
        // Want参数信息
      };
      this.context.startAbility(want);
    }

    // 页面展示
    build() {
      // ...
    }
  }
  ```

  也可以在导入依赖资源context模块后，在具体使用[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)前进行变量定义。

  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    startAbilityTest(): void {
      let context = getContext(this) as common.UIAbilityContext;
      let want: Want = {
        // Want参数信息
      };
      context.startAbility(want);
    }

    // 页面展示
    build() {
      // ...
    }
  }
  ```

- 当业务完成后，开发者如果想要终止当前[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)实例，可以通过调用[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)方法实现。

  ```ts
  import { common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    // 页面展示
    build() {
      Column() {
        //...
        Button('FuncAbilityB')
          .onClick(() => {
            let context = getContext(this) as common.UIAbilityContext;
            try {
              context.terminateSelf((err: BusinessError) => {
                if (err.code) {
                  // 处理业务逻辑错误
                  console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
                  return;
                }
                // 执行正常业务
                console.info('terminateSelf succeed');
              });
            } catch (err) {
              // 捕获同步的参数错误
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
            }
          })
      }
    }
  }
  ```
