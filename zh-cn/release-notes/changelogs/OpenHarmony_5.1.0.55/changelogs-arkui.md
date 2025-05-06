# ArkUI子系统Changelog

## cl.arkui.1 selectDialog未选中radio样式变更

**访问级别**

公开接口

**变更原因**

弹窗内容风格优化，增强用户体验。

**变更影响**

此变更不涉及应用适配。

变更点1：selectDialog未选中radio样式变更。

| 变更前                                                                                       | 变更后                                                                        |
|-------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| selectDialog未选中时的radio为显示非高亮状态。<br>  ![变更前](figures/selectDialog/selectDialog_before.png) | selectDialog未选中时的radio不显示。<br>![变更后](figures/selectDialog/selectDialog_after.png) |


**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.1.0.55开始。

**变更的接口/组件**

advancedDialog.selectDialog

**适配指导**

默认行为变更，无需适配。系统弹窗默认规格优化演进，若开发者有其他布局、样式诉求，建议使用CustomDialog自定义实现。

## cl.arkui.2 修复blendMode接口离屏模式会影响组件设置的不透明度的问题

**访问级别**

公开接口

**变更原因**

blendMode离屏模式与不透明度属性（opacity）同时使用时，组件的不透明度并不等于设置的不透明度，效果异常。

**变更影响**

此变更涉及应用适配，仅针对组件设置了blendMode离屏模式且具有不透明度的场景。

变更前：组件设置了blendMode离屏模式，同时设置了opacity不透明度 A，则组件实际不透明度为 A * A

变更后：组件设置了blendMode离屏模式，同时设置了opacity不透明度 A，则组件实际不透明度为 A

变更前后效果如下:

|变更前|变更后|
|--|--|
|![](./figures/blendMode_before.png)|![](./figures/blendMode_after.png)|



**起始API Level**

API 11


**变更发生版本**

从 OpenHarmony SDK 5.1.0.55 开始。

**变更的接口/组件**

blendMode 接口

**适配指导**

如果开发者希望在同时使用blendMode离屏模式和opacity接口时保持组件的不透明度不变，则需要手动调整原本设定的不透明度。例如，在下方示例代码中，在 Stack()上额外设置.opacity(0.5)，以确保实际的不透明度为 0.5 * 0.5。

```ts
@Entry
@Component
struct Index {
  build() {
    Column() {
       Stack() {
       }
       .height('50%')
       .width('50%')
       .backgroundColor(0x0A59F7)
       .blendMode(BlendMode.SRC_OVER, BlendApplyType.OFFSCREEN)
       .opacity(0.5)  // 变更后需要额外设置0.5的不透明度保证实际不透明度为 0.5*0.5
    }
    .height('100%')
    .width('100%')
    .backgroundColor(0xFFFFFF)
    .opacity(0.5)
  }
}
```
