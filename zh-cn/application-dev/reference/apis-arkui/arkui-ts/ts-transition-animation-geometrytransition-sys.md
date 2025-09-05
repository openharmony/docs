# 组件内隐式共享元素转场 (geometryTransition)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @ge-yafang-->

在视图切换过程中提供丝滑的上下文传承过渡。通用transition机制提供了opacity、scale等转场效果，geometryTransition通过安排绑定的in/out组件（in指新视图、out指旧视图）的frame、position使得原本独立的transition动画在空间位置上发生联系，将视觉焦点由旧视图位置引导到新视图位置。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始生效。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> [geometryTransition](ts-transition-animation-geometrytransition.md)必须配合[animateTo](ts-explicit-animation.md)使用才有动画效果，动效时长、曲线跟随[animateTo](ts-explicit-animation.md)中的配置，不支持[animation](ts-animatorproperty.md)隐式动画。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[组件内隐式共享元素转场 (geometryTransition)](ts-transition-animation-geometrytransition.md)。

## GeometryTransitionOptions<sup>11+<sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                                                                  |
| ------ | -------- | ---- | ------------------------------------------------------------------------- |
| hierarchyStrategy<sup>12+<sup> | [TransitionHierarchyStrategy](#transitionhierarchystrategy12)  | 否   | <br>决定共享元素动画过程中in/out组件在组件树上层级位置的移动策略，默认值：TransitionHierarchyStrategy.ADAPTIVE。<br>实际影响绑定的in/out组件相对其他组件的前后重叠关系，常规情况下慎重修改。<br>建议在发现共享元素动画过程中出现组件前后重叠关系错误时需要调整再设置此参数。<br>**系统接口：** 此接口为系统接口。|

## TransitionHierarchyStrategy<sup>12+<sup>
共享元素动画过程中in/out组件层级位置移动策略枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| NONE  | 0 | 无层级提拉，in/out组件保持原来的层级位置，受父组件scale、position影响。 |
| ADAPTIVE | 1 | 有层级提拉，in/out组件中相对低层级的组件被提拉至组件树上in/out组件相对高层级的位置上。<br>此模式还会导致被提拉的组件与父组件解绑，不受父组件scale、position影响。<br>例如in组件层级高于out组件，开启层级提拉后会在动画过程中将out组件从自己的父组件处解耦，并提拉至in组件的层级位置处，in组件层级位置不变。|

## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State isShow: boolean = false

  build() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.isShow) {
        Image($r('app.media.pic'))
          .autoResize(false)
          .clip(true)
          .width(300)
          .height(400)
          .offset({ y: 100 })
          .geometryTransition("picture", { hierarchyStrategy: TransitionHierarchyStrategy.ADAPTIVE })
          .transition(TransitionEffect.OPACITY)
      } else {
        // geometryTransition此处绑定的是容器，那么容器内的子组件需设为相对布局跟随父容器变化，
        // 套多层容器为了说明相对布局约束传递
        Column() {
          Column() {
            Image($r('app.media.icon'))
              .width('100%').height('100%')
          }.width('100%').height('100%')
        }
        .width(80)
        .height(80)
        // geometryTransition会同步圆角，但仅限于geometryTransition绑定处，此处绑定的是容器
        // 则对容器本身有圆角同步而不会操作容器内部子组件的borderRadius
        .borderRadius(20)
        .clip(true)
        .geometryTransition("picture", { hierarchyStrategy: TransitionHierarchyStrategy.ADAPTIVE })
        // transition保证组件离场不被立即析构，可设置其他转场效果
        .transition(TransitionEffect.OPACITY)
      }
    }
    .onClick(() => {
      this.getUIContext()?.animateTo({ duration: 1000 }, () => {
        this.isShow = !this.isShow
      })
    })
  }
}
```