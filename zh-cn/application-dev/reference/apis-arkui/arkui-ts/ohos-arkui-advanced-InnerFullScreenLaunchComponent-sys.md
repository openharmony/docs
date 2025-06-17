# InnerFullScreenLaunchComponent (系统接口)


非显式全屏启动原子化服务组件，拉起方可以选择拉起原子化服务的时机。当被拉起方授权使用方可以嵌入式运行原子化服务时，使用方全屏嵌入式运行原子化服务；未授权时，使用方跳出式拉起原子化服务。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。


## 导入模块

```ts
import { InnerFullScreenLaunchComponent, LauncherController } from '@kit.ArkUI';
```


## 子组件

无

## 属性
不支持[通用属性](ts-component-general-attributes.md)

## InnerFullScreenLaunchComponent

InnerFullScreenLaunchComponent({ content: Callback\<void>, controller: LaunchController })

**装饰器类型：**\@Component

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 组件显示内容。 |
| controller | [LaunchController](#launchcontroller) | 是 | - | 拉起原子化服务控制器。 |

## LaunchController

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|launchAtomicService | [LaunchAtomicServiceCallback](#launchatomicservicecallback) | 是 | 拉起原子化服务。 |

## LaunchAtomicServiceCallback

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| --------------- | ------ |------ |------ |
|appId | string |是| 原子化服务的appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | 拉起原子化服务参数。 |

## 事件
不支持[通用事件](ts-component-general-events.md)

## 示例

```ts
import { InnerFullScreenLaunchComponent, LaunchController } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  appId1: string = '5765880207853275505';
  appId2: string = '5765880207854372375';

  @Builder
  ColumChild() {
    Column() {
      Text('InnerFullScreenLaunchComponent').fontSize(16).margin({top: 100})
      Button('start 日出日落')
        .onClick(()=>{
          let appId2: string = '5765880207854372375';
          this.controller.launchAtomicService(appId2, {});
        }).height(30).width('50%').margin({top: 50})
      Button('start 充值')
        .onClick(()=>{
          let appId2: string = '5765880207853275489';
          this.controller.launchAtomicService(appId2, {});
        }).height(30).width('50%').margin({top: 50})
    }.backgroundColor(Color.Pink).height('100%').width('100%')
  }
  controller: LaunchController = new LaunchController();

  build() {
    Column() {
      InnerFullScreenLaunchComponent({
          content: this.ColumChild,
          controller: this.controller,
        })
    }
    .width('100%').height('100%')
  }
}

```
