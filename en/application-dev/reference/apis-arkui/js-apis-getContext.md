# getContext

The **getContext** API enables you to obtain the context of the ability (either UIAbilityContext or ExtensionContext) on the current page.

> **NOTE**
> - This API is supported since API version 9.
> - This API applies only to the stage model.

getContext(component?: Object):Context

Obtains the **Context** object associated with an ability on the page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type         | Mandatory | Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| component  | Object | No  | Ability instance. If no component is passed in or the passed-in parameter type is invalid, the default context is returned. The default context is the context obtained by tracing the call chain of the API. If this API is used in an asynchronous callback or not initially called on the current page, the context of the instance may fail to be traced. In this case, **undefined** is returned.            |

**Return value**

| Type | Description                            |
| ------ | ------------------------------- |
| [Context](../../application-models/application-context-stage.md) | Context of the ability. The context type depends on the ability type. For example, if this API is called on a page of the UIAbility, the return value type is UIAbilityContext; if this API is called on a page of the ExtensionAbility, the return value type is ExtensionContext.   |

**Example**

Load a page by calling **windowStage.loadContent** in the UIAbility.

```ts
// EntryAbility.ets
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

  onWindowStageDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```
In **Index.ets**, **getContext** is used to obtain the context. In this example, the return value type is UIAbilityContext.

```ts
//pages/Index.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let context : Context = getContext(this) as Context
            console.info("CacheDir:" + context.cacheDir)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
