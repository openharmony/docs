# RemoteWindow

远程控制窗口组件，可以通过此组件控制应用窗口，提供启动退出过程中控件动画和应用窗口联动动画的能力。

>  **说明：**
>  
>  该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  该组件为系统接口。

## 子组件

不可以包含子组件。

## 接口

RemoteWindow(target: WindowAnimationTarget)

通过窗口动画对象创建组件。

**参数:**
| 参数名 | 参数类型 | 必填  | 参数描述 |
| -------- | -------- | --------------- | -------- |
| target | [WindowAnimationTarget](#windowanimationtarget) | 是   | 需要控制的动画窗口的描述。 |

## WindowAnimationTarget
目标窗口，用来远程控制实现动画。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| bundleName  | string | 动画窗口所对应的进程。|
| abilityName | string | 动画窗口所对应的Ability。|
| windowBounds | [RRect](#rrect) | 动画窗口实际大小。|
| missionId  | number | 任务ID。|

## RRect
圆角矩形。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| left  | number | 动画窗口左上角相对于屏幕横坐标。|
| top | number | 动画窗口左上角相对于屏幕纵坐标。|
| width | number | 动画窗口宽度大小。|
| height | number | 动画窗口高度大小。|
| radius | number | 动画窗口圆角大小。|

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

```ts
// xxx.ets
@Entry
@Component
struct RemoteWindowExample {
  @State target: WindowAnimationTarget = undefined // 通过windowAnimationManager获取

  build() {
    Column() {
      RemoteWindow(this.target)
      	.translate({ x: 100, y: 200 })
      	.scale({ x: 0.5, y: 0.5 })
        .opacity(0.8)
      	.position({ x: px2vp(this.target?.windowBounds.left), y: px2vp(this.target?.windowBounds.top) })
      	.width(px2vp(this.target?.windowBounds.width))
      	.height(px2vp(this.target?.windowBounds.height))
     }
  }
}
```