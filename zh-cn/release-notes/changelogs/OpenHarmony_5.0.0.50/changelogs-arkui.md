# ArkUI子系统Changelog

## cl.arkui.1 showCounter接口布局变更

**访问级别**

公开接口

**变更原因**

在大字体时，showCounter所属的TextInput组件的下侧Margin空间不足。

**变更影响**

该变更为不兼容变更。

变更前：在设置showCounter后，TextInput组件的下侧Margin大小为固定的22vp，showCounter的垂直偏移量为字体高度。

变更后：在设置showCounter后，TextInput组件的下侧Margin大小为16vp加上showCounter的字体高度，showCounter的垂直偏移量为8vp。

变更前后对比效果，如下图所示：
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

## cl.arkui.2 Image组件draggable接口默认值由false变更为true

**访问级别**

公开接口

**变更原因**

Image组件的draggable接口默认值由false变更为true，默认支持拖拽。

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
