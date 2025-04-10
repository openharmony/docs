# getContext

如果需要在页面中获得当前Ability的Context，可调用getContext接口获取当前页面关联的UIAbilityContext或ExtensionContext。

> **说明：**
> - 该接口从API version 9开始支持，从API version 18开始废弃，建议使用[UIContext](js-apis-arkui-UIContext.md#uicontext)中的[getHostContext](js-apis-arkui-UIContext.md#gethostcontext12)替代。
> - 该接口仅限Stage模型使用。

## getContext<sup>(deprecated)</sup>

getContext(component?: Object):Context

获取与页面上下文组件关联的Context对象。

> **说明：**
> 
> 从API version 18开始废弃，建议使用[UIContext](js-apis-arkui-UIContext.md#uicontext)中的[getHostContext](js-apis-arkui-UIContext.md#gethostcontext12)替代。
>
> 从API version 12开始，可以通过使用[UIContext](js-apis-arkui-UIContext.md#uicontext)中的[getHostContext](js-apis-arkui-UIContext.md#gethostcontext12)来明确UI的执行上下文。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ----------- | ---- | ------------------------------- |
| component  | Object | 否   | 当前自定义组件的实例。未传入component或传入的参数类型非法，则返回默认上下文。默认上下文是指通过追溯当前方法的调用链所跟踪到的Context。在异步调用的回调方法中使用该接口，或者该接口的起始调用不在当前页面，将可能导致无法跟踪到该实例的Context，则会返回undefined。             |

**返回值：**

| 类型 | 说明                             |
| ------ | ------------------------------- |
| [Context](../../application-models/application-context-stage.md#应用上下文context)  | 返回当前组件所在Ability的Context，Context的具体类型为当前Ability关联的Context对象。例如：在UIAbility窗口中的页面调用该接口，返回类型为UIAbilityContext。在ExtensionAbility窗口中的页面调用该接口，返回类型为ExtensionContext。    |

**示例：**

在UIAbility中通过windowStage.loadContent加载具体页面。

> **说明：**
> 
> 直接使用getContext可能导致实例不明确的问题，建议使用[getUIContext](js-apis-arkui-UIContext.md#uicontext)获取UIContext实例，并使用[getHostContext](js-apis-arkui-UIContext.md#gethostcontext12)调用绑定实例的getContext。

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
            // 建议使用this.getUIContext().getHostContext()
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
