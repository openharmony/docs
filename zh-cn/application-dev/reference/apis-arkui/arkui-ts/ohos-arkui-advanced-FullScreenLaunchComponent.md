# FullScreenLaunchComponent


全屏启动原子化服务组件，当被拉起方授权使用方可以嵌入式运行原子化服务时，使用方全屏嵌入式运行原子化服务；未授权时，使用方跳出式拉起原子化服务。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。


## 导入模块

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI'
```


## 子组件

无

## 属性
不支持[通用属性](ts-component-general-attributes.md)。

## 事件
不支持[通用事件](ts-component-general-events.md)。

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions, onError?: ErrorCallback, onTerminated?: Callback\<TerminationInfo> })

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 可以使用组件组合来自定义拉起原子化服务前的占位图标，实现类似大桌面应用图标的效果。点击占位组件后，将拉起原子化服务。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| appId | string | 是 | - |  需要拉起的原子化服务appId，appId是原子化服务的唯一标识。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<!--RP1--><!--RP1End-->|
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | - | 拉起原子化服务参数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| onError<sup>18+<sup> | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否 | - | 被拉起的嵌入式运行原子化服务在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| onTerminated<sup>18+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ts-container-embedded-component.md#terminationinfo)> | 否 | - | 被拉起的嵌入式运行原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)正常退出时，触发本回调函数。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

> **说明：**
>
> - 若原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)退出，其携带的信息会传给回调函数的入参；
> - 若原子化服务通过调用[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

## 示例

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State appId: string = '6918661953712445909'; // 原子化服务appId

  build() {
    Row() {
      Column() {
        FullScreenLaunchComponent({
          content: ColumChild,
          appId: this.appId,
          options: {},
          onTerminated: (info) => {
            console.info("onTerminated code: " + info.code.toString());
          },
          onError: (err) => {
            console.error("onError code: " + err.code + ", message: ", err.message);
          }
        }).width("80vp").height("80vp")
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Builder
function ColumChild() {
  Column() {
    Image($r('app.media.icon'))
    Text('test')
  }
}
```
