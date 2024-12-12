# ArkUI子系统Changelog

## cl.arkui.1 TextInput组件在非标准字体场景下showCounter接口布局变更

**访问级别**

公开接口

**变更原因**

在大字体时，showCounter所属的TextInput组件的下侧Margin空间不足。

**变更影响**

该变更为不兼容变更。

变更前：在设置showCounter后，TextInput组件的下侧Margin大小为固定的22vp，showCounter的垂直偏移量为字体高度。

变更后：在设置showCounter后，标准字体下，TextInput组件的下侧Margin以及垂直偏移量和变更前保持一致。非标准字体设置下，TextInput组件的下侧Margin大小为16vp加上showCounter的字体高度，垂直偏移量为8vp。

设置非标准字体时，变更前后对比效果如下图所示：
| 变更前 | 变更后 |
|---------|---------|
|![超长错误文本变更前样式](figures/textInputBeforeModi.png)|![超长错误文本变更后样式](figures/textInputAfterModi.png)|

示例：

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Column() {
      TextInput({text: "输入文字1"})
        .showCounter(true)
        .maxLength(10)
      TextInput({text: "输入文字2"})
    }
    .height('100%')
    .width('100%')
  }
}
```

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.50开始。

**变更的接口/组件**

TextInput组件showCounter接口。

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.2 当Image组件的draggable接口接收到异常值时，其默认值将由false更改为true

**访问级别**

公开接口

**变更原因**

当Image组件的draggable接口接收到异常参数，如undefined或null时，其默认值将从false更改为true，从而默认启用拖拽功能。

**变更影响**

该变更为不兼容变更。

变更前：Image组件的draggable接口默认值为true，当传入异常值时，draggable为false，Image组件不可拖拽。

变更后：Image组件的draggable接口默认值为true，当传入异常值时，draggable为true，Image组件可拖拽。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.50开始。

**变更的接口/组件**

Image组件draggable接口。

**适配指导**

如果为Image组件设置了可拖拽（draggable）接口并传入了异常值，想要保持该组件不可拖拽，应将draggable设置为false。

示例：

```ts
@Entry
@Component
struct Index {
  build() {
    Column() {
      Image($r("app.media.startIcon"))
        .draggable(undefined)
    }
    .height('100%')
    .width('100%')
  }
}
```

## cl.arkui.3 GestureGroupGestureHandlerOptions参数mode默认值变更

**访问级别**

公开接口

**变更原因**

为了与GestureGroupInterface接口行为保持一致，GestureGroupGestureHandlerOptions参数mode默认值由GestureMode.Exclusive变更为GestureMode.Sequence。

**变更影响**

该变更为不兼容变更。

变更前：GestureGroupGestureHandlerOptions参数mode默认值为GestureMode.Exclusive，当开发者未设置该参数时，默认GestureGroup下的多个手势组成互斥手势组。

变更后：GestureGroupGestureHandlerOptions参数mode默认值为GestureMode.Sequence，当开发者未设置该参数时，默认GestureGroup下的多个手势组成顺序手势组。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.50开始。

**变更的接口/组件**

gesture.d.ts文件GestureGroupGestureHandlerOptions接口。

**适配指导**

如果使用了GestureGroupGestureHandlerOptions接口并传入了异常值，想要保持手势组中手势为互斥手势，则需要将mode设置为GestureMode.Exclusive；否则，可以保持其原有状态。

示例：

```ts
class MyModifierGestureGroup implements GestureModifier {
  applyGesture(event: UIGestureEvent): void {
    event.addGesture(
      new GestureGroupHandler({ mode: GestureMode.Exclusive, gestures: [
        new LongPressGestureHandler()
              .onAction(() => {}),
        new PanGestureHandler()
              .onActionStart(() => {})
              .onActionEnd(() => {})
      ] })
    )
  }
}

@Entry
@Component
struct ModifierGesture {
  @State modifierGroup: MyModifierGestureGroup = new MyModifierGestureGroup()
  build() {
    Column() {
      Text("Modifier手势组")
      .width(150)
      .height(150)
      .gestureModifier(this.modifierGroup as MyModifierGestureGroup)
    }
  }
}
```

## cl.arkui.4 PanGestureInterface参数distance效果变更

**访问级别**

公开接口

**变更原因**

为了参数distance设置特殊值时行为逻辑与正常值行为逻辑保持一致，当参数distance设置为0时行为逻辑发生变化。

**变更影响**

该变更为不兼容变更。

变更前：当PanGestureInterface参数distance设置为0时，手指触摸后（手指未发生移动），组件不触发PanGesture的回调。

变更后：当PanGestureInterface参数distance设置为0时，手指触摸后（手指未发生移动），组件触发PanGesture的回调。


**起始API Level**

API 7

**变更发生版本**

从OpenHarmony SDK 5.0.0.50开始。

**变更的接口/组件**

gesture.d.ts文件GestureGroupGestureHandlerOptions接口。

**适配指导**

如果使用了PanGestureInterface接口，当手指移动距离达到设置的distance时，将触发PanGesture的回调。如果想要保持手指触摸后组件不触发PanGesture的回调，可以将distance设置为大于0的值。

示例：

```ts
@Entry
@Component
struct PanGesture {
  build() {
    Column() {
      Text("PanGesture")
      .width(150)
      .height(150)
      .gesture(
        PanGesture({distance: 5})
          .onActionStart(() => {})
      )
    }
  }
}
```

## cl.arkui.5 TextClock、TextTimer使用start、end参数设置borderColor、margin、padding行为更改

**访问级别**

公开接口

**变更原因**

TextClock、TextTimer使用start、end参数设置borderColor、margin、padding未生效。

**变更影响**

该变更为不兼容变更。

| 变更前                                                                                                                     | 变更后                                                                                                                   |
| -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| 使用start、end参数设置borderColor、margin、padding不生效。<br>![textclock_before](figures/textclock_before.png)| 使用start、end参数设置borderColor、margin、padding生效。<br>![textclock_after](figures/textclock_after.png) |

**起始API Level**

12

**变更发生版本**

从OpenHarmony 5.0.0.50 版本开始。

**变更的接口/组件**

TextClock、TextTimer。

**适配指导**

正确使用start、end参数设置borderColor、margin、padding。

示例：
```
import { LengthMetrics } from '@kit.ArkUI'
@Entry
@Component
struct Index {
  
  build() {
    Column(){
      TextClock().borderWidth(50)
        .borderColor({start: "#D5D5D5", end: "#D5D5D5", top: "#D5D5D5", bottom: "#D5D5D5"})
        .padding({start: LengthMetrics.vp(20), end: LengthMetrics.vp(40)})
        .margin({start: LengthMetrics.vp(20), end: LengthMetrics.vp(40)})
    }
  }
}
```