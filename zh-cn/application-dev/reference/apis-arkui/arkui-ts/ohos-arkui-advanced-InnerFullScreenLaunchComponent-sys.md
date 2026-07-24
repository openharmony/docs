# InnerFullScreenLaunchComponent (系统接口)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @qq_36417014-->
<!--Designer: @autojuan-->
<!--Tester: @tinygreyy-->
<!--Adviser: @zengyawen-->

非显式全屏启动原子化服务组件，拉起方可以选择拉起原子化服务的时机。当被拉起方授权使用方可以嵌入式运行原子化服务时，使用方全屏嵌入式运行原子化服务；未授权时，使用方跳出式拉起原子化服务。

> **说明：**
>
> 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。


## 导入模块

```ts
import { InnerFullScreenLaunchComponent, LaunchController } from '@kit.ArkUI';
```


## 子组件

无

## 属性

不支持[通用属性](ts-component-general-attributes.md)

## 事件

不支持[通用事件](ts-component-general-events.md)

## InnerFullScreenLaunchComponent

InnerFullScreenLaunchComponent({ content: Callback\<void>, controller: LaunchController, onReceive?: Callback<Record<string, Object>>, onError?: ErrorCallback, onTerminated?: Callback\<TerminationInfo> })

**装饰器类型：**[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | [\@BuilderParam](../../../ui/state-management/arkts-builderparam.md) | 组件显示内容。 |
| controller | [LaunchController](#launchcontroller) | 是 | - | 拉起原子化服务控制器。 |
| onReceive<sup>20+</sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record<string, Object>> | 否 | - | 被拉起的嵌入式运行原子化服务通过[@ohos.window (窗口)](../arkts-apis-window.md)调用API时，触发本回调。 |
| onError<sup>23+</sup> | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否 | - | 被拉起的嵌入式运行原子化服务在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。 |
| onTerminated<sup>23+</sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ts-container-embedded-component.md#terminationinfo)> | 否 | - | 被拉起的嵌入式运行原子化服务通过点击原子化服务退出按钮、手势侧滑、调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)正常退出时，触发本回调函数。|
  
> **说明：**
>
> - 若原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)退出，其携带的信息会传给回调函数的入参；
> - 若原子化服务通过调用[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"；
> - 从API版本26.0.0开始，原子化服务通过手势侧滑退出触发onTerminated回调。

## LaunchController

拉起原子化服务控制器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---------- | ------ |------ | -- |
|launchAtomicService | [LaunchAtomicServiceCallback](#launchatomicservicecallback) | 否 | 否 | 拉起原子化服务。 |

## LaunchAtomicServiceCallback

type LaunchAtomicServiceCallback = (appId: string, options?: AtomicServiceOptions) => void

拉起原子化服务触发的回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------------- | ------ |------ |------ |
|appId | string |是| 原子化服务的appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | 拉起原子化服务参数。 |

## 示例

> **说明：**
>
>由于嵌入式原子化服务运行在独立进程，其崩溃异常不会直接暴露在宿主的日志中。本地调试时可通过以下方式查看真实报错栈：  
>1. 打开DevEco Studio的HiLog面板。  
>2. 将左上角的模式切换为User logs of selected app。  
>3. 在右侧进程列表中，选择被拉起的原子化服务进程（被拉起原子化服务的包名，且后缀带有embeddable字样）。

```ts
import { InnerFullScreenLaunchComponent, LaunchController } from '@kit.ArkUI';

@Entry
@Component
struct Index {

  @Builder
  ColumnChild() {
    Column() {
      Text('InnerFullScreenLaunchComponent').fontSize(16).margin({top: 100})
      Button('start 日出日落')
        .onClick(()=>{
          let appId1: string = '576****************';
          this.controller.launchAtomicService(appId1, {});
        }).height(30).width('50%').margin({top: 50})
      Button('start 充值')
        .onClick(()=>{
          let appId2: string = '576****************';
          this.controller.launchAtomicService(appId2, {});
        }).height(30).width('50%').margin({top: 50})
    }.backgroundColor(Color.Pink).height('100%').width('100%')
  }
  controller: LaunchController = new LaunchController();

  build() {
    Column() {
      InnerFullScreenLaunchComponent({
          content: this.ColumnChild,
          controller: this.controller,
          onReceive: (data) => {
            console.info("onReceive, data: " + data['ohos.atomicService.window']);
          },
          onError: (err: Error) => {
            console.error("onError, err: " + JSON.stringify(err));
          },
          onTerminated: (info: TerminationInfo) => {
            console.info("onTerminated, info: " + JSON.stringify(info));
          }
        })
    }
    .width('100%').height('100%')
  }
}

```
