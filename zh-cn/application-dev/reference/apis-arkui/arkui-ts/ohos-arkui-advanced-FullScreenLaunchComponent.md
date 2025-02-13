# FullScreenLaunchComponent


全屏启动原子化服务组件，当被拉起方授权使用方可以嵌入式运行原子化服务时，使用方全屏嵌入式运行原子化服务；未授权时，使用方跳出式拉起原子化服务。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。


## 导入模块

```
import { FullScreenLaunchComponent } from '@kit.ArkUI'
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**装饰器类型：**\@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 组件显示内容。 |
| appId | string | 是 | - | 原子化服务appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | - | 拉起原子化服务参数。 |

## 事件
不支持[通用事件](ts-universal-events-click.md)，仅支持以下事件。

### onError<sup>16+<sup>

onError(callback: ErrorCallback)

被拉起的原子化服务扩展在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| callback                     | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 报错信息。    |

### onTerminated<sup>16+<sup>

onTerminated(callback: Callback&lt;TerminationInfo&gt;)

被拉起的原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)正常退出时，触发本回调函数。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 说明                                                                                     |
| -------  | ------ | ---------------------------------------------------------------------------------------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ohos-arkui-advanced-FullScreenLaunchComponent.md#terminationinfo16)> | 回调函数，入参用于接收原子化服务的返回结果，类型为[TerminationInfo](ohos-arkui-advanced-FullScreenLaunchComponent.md#terminationinfo16)。 |

> **说明：**
>
> - 若原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)退出，其携带的信息会传给回调函数的入参；
> - 若原子化服务通过调用[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

## TerminationInfo<sup>16+<sup>

用于表示被拉起的原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)正常退出时的返回结果。

### 属性

| 名称 | 类型                                                       | 必填 | 说明                               |
| ---- | ---------------------------------------------------------- | ---- | --------------------------------- |
| code | number                                                     | 是   | 被拉起原子化服务退出时返回的结果码。 |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 被拉起原子化服务退出时返回的数据。   |

## 示例

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State appId: string = '6918661953712445909';

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
