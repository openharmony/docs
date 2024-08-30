# ArkUI子系统Changelog

## cl.arkui.1 新增圆角类型按钮

**访问级别**

公开接口

**变更原因**

新增圆角类型按钮，需修改ButtonOptions中type的默认值。

**变更影响**

该变更为兼容性变更。

变更前：ButtonOptions中type的默认值为ButtonType.Capsule。

变更后：ButtonOptions中type的默认值为ButtonType.ROUNDED_RECTANGLE

| 变更前 | 变更后 |
|---------|---------|
|![roundedRectButton_before](figures/roundedRectButton_before.png)|![figures/roundedRectButton_after.png](figures/roundedRectButton_after.png)|

**起始API Level**

API 13

**变更发生版本**

从OpenHarmony SDK 5.0.0.40开始。

**变更的接口/组件**

Button组件中ButtonOptions对象的type属性默认值。

**适配指导**

开发者在使用Button组件，创建默认类型的Button按钮时，Button按钮为ROUNDED_RECTANGLE类型。

```ts

@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Capsule button with rounded corners by default.').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Capsule')
          .type(ButtonType.Capsule)
          .backgroundColor(0x317aff)
          .height(60)
          .controlSize(ControlSize.NORMAL)
          .width(180)
      }
      Text('Rounded rectangle button with rounded corners by default.').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Rounded rectangle')
          .type(ButtonType.ROUNDED_RECTANGLE)
          .backgroundColor(0x317aff)
          .controlSize(ControlSize.NORMAL)
          .height(60)
          .width(180)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}

```

## cl.arkui.2 半模态顶部高度位置优化

**访问级别**

公开接口

**变更原因**

半模态顶部高度位置优化。

**变更影响**

该变更为不兼容变更。

变更前：

1. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、竖屏无状态栏时，最大高度为距离屏幕顶部8vp。
2. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、竖屏有状态栏时，最大高度为距离信号栏8vp。
3. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE，横屏有无状态栏，最大高度都为距离屏幕顶部8vp。


变更后：

1. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE，竖屏有无状态栏，最大高度都为距离信号栏8vp。
2. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、横屏无状态栏时，最大高度为距离屏幕顶部8vp。
3. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、横屏有状态栏时，最大高度为距离信号栏8vp。

**起始API Level**

14

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

bindSheet组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.3 在2in1设备上bindsheet视觉效果变更

**访问级别**

公开接口

**变更原因**

2in1设备上，半模态样式优化。

**变更影响**

该变更为兼容性变更。

| 变更前 | 变更后 |
|------ |--------|
|默认圆角为32vp|2in1设备中，默认圆角为16vp|
|关闭按钮默认有底板|2in1设备中，关闭按钮默认没有底板|
|默认没有阴影|2in1设备中，默认有阴影|
|默认没有内外描边|2in1设备中，默认有内外描边|

**起始API Level**

11

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

bindSheet属性。

**适配指导**

默认行为变更，无需适配。
