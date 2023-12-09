# getContext

如果需要在页面中获得当前Ability的Context，可调用getContext接口获取当前页面关联的UIAbilityContext或ExtensionContext。

> **说明：**
> - 该接口从API version 9开始支持。
> - 该接口仅限Stage模型使用。

getContext(component?: Object):Context

**参数：**

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ----------- | ---- | ------------------------------- |
| component  | Object | 否   | 当前自定义组件的实例。未传入component或传入的参数类型非法，则返回默认上下文。默认上下文是指通过追溯当前方法的调用链所跟踪到的Context。在异步调用的回调方法中使用该接口，或者该接口的起始调用不在当前页面，将可能导致无法跟踪到该实例的Context，则会返回undifined。             |

**返回值：**

| 类型 | 说明                             |
| ------ | ------------------------------- |
| [Context](../../application-models/application-context-stage.md#应用上下文context)  | 返回当前组件所在Ability的Context，Context的具体类型为当前Ability关联的Context对象。例如：在UIAbility窗口中的页面调用该接口，返回类型为UIAbilityContext。在ExtensionAbility窗口中的页面调用该接口，返回类型为ExtensionAbilityContext。    |

**示例：**

在UIAbility中通过windowStage.loadContent加载具体页面。

```ts
// EntryAbility.ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';

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
在具体的Index.ets中可以通过getContext接口获取Context上下文，本示例返回的Context类型为UIAbilityContext。

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
