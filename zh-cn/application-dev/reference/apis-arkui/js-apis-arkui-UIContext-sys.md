# @ohos.arkui.UIContext (UIContext)(系统接口)

在Stage模型中，WindowStage/Window可以通过loadContent接口加载页面并创建UI的实例，并将页面内容渲染到关联的窗口中，所以UI实例和窗口是一一关联的。一些全局的UI接口是和具体UI实例的执行上下文相关的，在当前接口调用时，通过追溯调用链跟踪到UI的上下文，来确定具体的UI实例。若在非UI页面中或者一些异步回调中调用这类接口，可能无法跟踪到当前UI的上下文，导致接口执行失败。

@ohos.window在API version 10 新增[getUIContext](./js-apis-window.md#getuicontext10)接口，获取UI上下文实例UIContext对象，使用UIContext对象提供的替代方法，可以直接作用在对应的UI实例上。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前IDE预览器不支持。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.arkui.UIContext (UIContext)](js-apis-arkui-UIContext.md)。

## UIContext

以下API需先使用ohos.window中的[getUIContext()](./js-apis-window.md#getuicontext10)方法获取UIContext实例，再通过此实例调用对应方法。本文中UIContext对象以uiContext表示。

### setDynamicDimming<sup>12+<sup>

setDynamicDimming(id: string, value: number): void

通过该方法设置组件的压暗程度。


> **说明：**
>
> 设置该属性后设置其他效果类属性会导致效果冲突。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| id | string | 是 | 组件id。 |
| value | number | 是 | 组件压暗程度取值范围[0,1], 由0到1逐渐变亮。 |

**示例：**

```ts
@Entry
@Component
struct Index {
  @State
  myCount : number = 100

  build() {
    Column(){
      Image($r('app.media.testImage')).width(500).height(800).id("test")
    }.width("100%").height("100%").onClick(()=>{
      this.getUIContext().setDynamicDimming("test",1)
      animateTo({duration:5000 },()=>{
        this.getUIContext().setDynamicDimming("test",0)
      })
    })
  }
}
```
![api-switch-overview](../apis-arkui/figures/dynamicDinning.gif)

