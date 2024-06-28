# 组件内隐式共享元素转场 (geometryTransition)(系统接口)

在视图切换过程中提供丝滑的上下文传承过渡。通用transition机制提供了opacity、scale等转场效果，geometryTransition通过安排绑定的in/out组件(in指新视图、out指旧视图)的frame、position使得原本独立的transition动画在空间位置上发生联系，将视觉焦点由旧视图位置引导到新视图位置。

> **说明：**
>
> 从API Version 7开始支持，从API Version 10开始生效。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
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
| hierarchyStrategy<sup>12+<sup> | [TransitionHierarchyStrategy](#transitionhierarchystrategy)  | 否   | 决定共享元素动画过程中in/out组件在组件树上层级位置移动策略，默认值：TransitionHierarchyStrategy.ADAPTIVE。<br>实际影响绑定的in/out组件相对其他组件的前后重叠关系，常规情况下慎重修改。<br>建议在发现共享元素动画过程中出现组件前后重叠关系错误时需要调整再设置此参数。|

## 示例

```ts
Image($r('app.media.icon'))
    .width('100%')
    .aspectRatio(1)
    // 不设置hierarchyStrategy时，默认值：TransitionHierarchyStrategy.ADAPTIVE
    .geometryTransition("picture", {hierarchyStrategy: TransitionHierarchyStrategy.NONE})
```

## TransitionHierarchyStrategy<sup>12+<sup>
共享元素动画期间in/out组件层级移动策略枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| NONE  | 0 | 无层级提拉，in/out组件保持原来的层级位置，受父组件scale、position影响。 |
| ADAPTIVE | 1 | 有层级提拉，in/out组件中相对低层级的组件被提拉至组件树上in/out组件相对高的层级处。<br>还会导致被提拉的组件与父组件解绑，不受父组件scale、position影响。<br>例如in组件层级高于out组件，开启层级提拉后会在动画过程中将out组件从自己的父组件处解耦，并提拉至in组件的层级位置处，in组件不变。|
