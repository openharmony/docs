# UIAbility Usage


When using the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component, you must specify a startup page and obtain the context, [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).


## Specifying the Startup Page of UIAbility

If no startup page is specified, a white screen occurs after the application is started. You can use [loadContent()](../reference/apis-arkui/js-apis-window.md#loadcontent9) of [WindowStage](../reference/apis-arkui/js-apis-window.md#windowstage9) to set the startup page in the [onWindowStageCreate()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate) callback of the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) instance.


```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created. Set a main page for this ability.
    windowStage.loadContent('pages/Index', (err, data) => {
      // ...
    });
  }
  // ...
}
```

> **NOTE**
>
> When you create UIAbility in DevEco Studio, the UIAbility instance loads the **Index** page as its startup page. Therefore, you only need to replace the **Index** page path with the required startup page path.


## Obtaining the Context of UIAbility

The [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) class has its own context, which is an instance of the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) class. The [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) class has attributes such as **abilityInfo** and **currentHapModuleInfo**. UIAbilityContext can be used to obtain the UIAbility configuration information, such as the code path, bundle name, ability name, and environment status required by the application. It can also be used to obtain methods to operate the UIAbility instance, such as [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability), [connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability), and [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself).

The [getContext](../reference/apis-arkui/js-apis-getContext.md#getcontext) API enables you to obtain the context of the ability (either UIAbilityContext or [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)) on the current page.

- You can use **this.context** to obtain the context of a UIAbility instance.
  
  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // Obtain the context of the UIAbility instance.
      let context = this.context;
      // ...
    }
  }
  ```
  
- Import the context module and define the **context** variable in the component.
  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_EventHub {
    private context = getContext(this) as common.UIAbilityContext;

    startAbilityTest(): void {
      let want: Want = {
        // Want parameter information.
      };
      this.context.startAbility(want);
    }

    // Page display.
    build() {
      // ...
    }
  }
  ```

  You can also define variables after importing the context module but before using [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).

  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    startAbilityTest(): void {
      let context = getContext(this) as common.UIAbilityContext;
      let want: Want = {
        // Want parameter information.
      };
      context.startAbility(want);
    }

    // Page display.
    build() {
      // ...
    }
  }
  ```

- To stop the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) instance after the service is not needed, call [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself).

  ```ts
  import { common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    // Page display.
    build() {
      Column() {
        //...
        Button('FuncAbilityB')
          .onClick(() => {
            let context = getContext(this) as common.UIAbilityContext;
            try {
              context.terminateSelf((err: BusinessError) => {
                if (err.code) {
                  // Process service logic errors.
                  console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
                  return;
                }
                // Carry out normal service processing.
                console.info('terminateSelf succeed');
              });
            } catch (err) {
              // Capture the synchronization parameter error.
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
            }
          })
      }
    }
  }
  ```
