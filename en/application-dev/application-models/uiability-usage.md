# UIAbility Component Usage


When using the UIAbility component, you must specify a startup page and obtain the context, [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md).


## Specifying the Startup Page of UIAbility

If no startup page is specified, a white screen occurs after the application is started. You can use **loadContent()** of [WindowStage](../reference/apis/js-apis-window.md#windowstage9) to set the startup page in the **onWindowStageCreate()** callback of the UIAbility instance.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created. Set a main page for this ability.
    windowStage.loadContent('pages/Index', (err, data) => {
      ...
    });
  }

  ...
}
```

> **NOTE**
>
> When you create UIAbility in DevEco Studio, the UIAbility instance loads the **Index** page by default. Therefore, you only need to replace the **Index** page path with the required startup page path.


## Obtaining the Context of UIAbility

The UIAbility class has its own context, which is an instance of the [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) class. The UIAbilityContext class has attributes such as **abilityInfo** and **currentHapModuleInfo**. UIAbilityContext can be used to obtain the UIAbility configuration information, such as the bundle code path, bundle name, ability name, and environment status required by the application. It can also be used to obtain methods to operate the UIAbility instance, such as **startAbility()**, **connectServiceExtensionAbility()**, and **terminateSelf()**.

- You can use **this.context** to obtain the context of a UIAbility instance.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
      // Obtain the context of the UIAbility instance.
      let context = this.context;
      ...
    }
  }
  ```
  
- Import the context module and define the **context** variable in the component.
  
  ```ts
  import common from '@ohos.app.ability.common';
  
  @Entry
  @Component
  struct Index {
    private context = getContext(this) as common.UIAbilityContext;
  
    startAbilityTest() {
      let want = {
        // Want parameter information.
      };
      this.context.startAbility(want);
    }
  
    // Page display.
    build() {
      ...
    }
  }
  ```

  You can also define variables after importing the context module but before using [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md).

  
  ```ts
  import common from '@ohos.app.ability.common';
  
  @Entry
  @Component
  struct Index {
  
    startAbilityTest() {
      let context = getContext(this) as common.UIAbilityContext;
      let want = {
        // Want parameter information.
      };
      context.startAbility(want);
    }
  
    // Page display.
    build() {
      ...
    }
  }
  ```
