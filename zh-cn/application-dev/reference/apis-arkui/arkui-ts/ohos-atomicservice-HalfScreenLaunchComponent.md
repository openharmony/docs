# HalfScreenLaunchComponent

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @qq_36417014-->
<!--Designer: @autojuan-->
<!--Tester: @tinygreyy-->
<!--Adviser: @zengyawen-->

半屏嵌入式启动原子化服务组件，当被拉起方未授权嵌入式运行原子化服务时，宿主将使用跳出式拉起原子化服务。

> **说明：**
>
> 该组件从API version 18开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，原子化服务必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法确保原子化服务正常运行。

## 导入模块

```ts
import { HalfScreenLaunchComponent } from '@kit.ArkUI';
```

## 子组件

无

## 属性
不支持[通用属性](ts-component-general-attributes.md)

## HalfScreenLaunchComponent

HalfScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions, onError?: ErrorCallback, onTerminated?: Callback\<TerminationInfo>, onReceive?: Callback<Record<string, Object>> })

**装饰器类型：**[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | [\@BuilderParam](../../../ui/state-management/arkts-builderparam.md) | 组件显示内容。 |
| appId | string | 是 | - | 原子化服务appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | - | 拉起原子化服务参数，默认为空。 |
| onError |[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否 | - | 被拉起的原子化服务扩展在运行过程中发生异常时触发本回调。 |
| onTerminated | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ts-container-embedded-component.md#terminationinfo)> | 否 | - | 被拉起的嵌入式运行原子化服务通过点击原子化服务退出按钮、手势侧滑、调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)正常退出时，触发本回调函数。 |
| onReceive<sup>20+</sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record<string, Object>> | 否 | - | 被拉起的嵌入式运行原子化服务通过[@ohos.window (窗口)](../arkts-apis-window.md)调用API时，触发本回调。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

> **说明：**
>
> - 若原子化服务通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)退出，其携带的信息会传给回调函数的入参；
> - 若原子化服务通过调用[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)退出，上述回调函数的入参中，"code"取默认值"0"，"want"为"undefined"。

## 示例

该示例展示如何嵌入式拉起手机充值服务。

> **说明：**
>
>由于嵌入式原子化服务运行在独立进程，其崩溃异常不会直接暴露在宿主的日志中。本地调试时可通过以下方式查看真实报错栈：  
>1. 打开DevEco Studio的HiLog面板。  
>2. 将左上角的模式切换为User logs of selected app。  
>3. 在右侧进程列表中，选择被拉起的原子化服务进程（被拉起原子化服务的包名，且后缀带有embeddable字样）。

```ts
import { HalfScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  appId: string = "576****************"; // 原子化服务appId。

  build() {
    Column() {
      HalfScreenLaunchComponent({
        appId: this.appId,
        options: {},
        onTerminated:  (info:TerminationInfo)=> {
          console.info('onTerminated info = '+ info.want);
        },
        onError: (err) => {
          console.error(" onError code: " + err.code + ", message: ", err.message);
        },
        onReceive: (data) => {
          console.info("onReceive, data: " + data['ohos.atomicService.window']);
        }
      }) {
        Column() {
          Image($r('app.media.app_icon'))
          Text('拉起手机充值')
        }.width("80vp").height("80vp").margin({bottom:30})
      } // 通过尾随闭包形式传入content。
    }
  }

}
```
