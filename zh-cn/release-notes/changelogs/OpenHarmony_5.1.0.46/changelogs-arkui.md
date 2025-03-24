# ArkUI子系统Changelog

## cl.arkui.1 TextInput、TextArea、Search组件onChange事件参数内容变更

**访问级别**

公开接口

**变更原因**

在预上屏输入功能启用时，当先选中一段文本再进行输入，onChange回调中的value字段将仅反映实际显示的上屏文本，不再包含原先选中的文本内容，以此确保value字段与用户界面显示的文本一致。

**变更影响**

此变更不涉及应用适配。

运行如下示例代码：

```ts
// Index.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  onPageShow(): void {
    setTimeout(() => {
      this.controller.setTextSelection(0,3);
    }, 10);
  }
  build() {
    Column() {
      TextInput({ text:"12345",  controller: this.controller })
        .width(380)
        .height(60)
        .defaultFocus(true)
        .onChange((value: string) => {
          console.log("value is" + value)
        })
    }
  }
}
```
变更前：
开启预上屏输入，输入过程中，onChange回调的值为“12345”

变更后：
开启预上屏输入，输入过程中，onChange回调的值为“45”

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.46开始。

**变更的接口/组件**

TextInput组件onChange事件的EditableTextOnChangeCallback参数

TextArea组件onChange事件的EditableTextOnChangeCallback参数

Search组件onChange事件的EditableTextOnChangeCallback参数

**适配指导**

变更后value参数的内容将与实际显示内容保持一致，无需进行额外的适配。若开发者希望获取全部文本内容，可利用onEditChange等事件，在输入开始前进行获取并记录。

## cl.arkui.2 Text的minFontSize、maxFontSize在子组件span或属性字符串场景下，文本自适应字号设置生效

**访问级别**

公开接口

**变更原因**

能力增强，方便开发者对不同文字样式的文字做字号的适应。

**变更影响**

此变更涉及应用适配。

变更前，Text的minFontSize、maxFontSize在子组件Span或属性字符串场景下，文本自适应字号设置不生效。

变更后，Text的minFontSize、maxFontSize在子组件Span或属性字符串场景下，文本自适应字号设置生效。

如下是属性字符串和Span子组件场景变更前后效果对比：

|               变更前                |              变更后               |
| :---------------------------------: | :-------------------------------: |
|![](figures/before_span_adapter.png)|![](figures/after_span_adapter.png)|

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony SDK 5.1.0.46开始。

**变更的接口/组件**

Text组件的minFontSize、maxFontSize接口。

**适配指导**

如果在Text使用子组件或属性字符串场景下，设置了minFontSize、maxFontSize，变更后自适应字号生效，导致字号变化，如果需要保持之前的字号，可以删除minFontSize、maxFontSize属性设置。

## cl.arkui.3 FrameNode被UINode包裹时isVisible接口返回值发生变更

**访问级别**

公开接口

**变更原因**

用户使用FrameNode的isVisible接口时，节点会依次向上层父节点查询可见性，如果父节点不可见，子节点也不可见。但如果子节点被UINode类型节点（如IfElse、ForEach、LazyForEach等）包裹，则向上查找过程被阻塞，无法继续查询父节点可见性。

**变更影响**

此变更不涉及应用适配。

变更前：父节点设为不可见、子节点设为可见时，如果子节点被UINode类型节点包裹，子节点调用isVisible结果为true。

变更后：父节点设为不可见、子节点设为可见时，如果子节点被UINode类型节点包裹，子节点调用isVisible结果为false。

父节点设为不可见、子节点设为可见时，如果子节点被UINode类型节点包裹，调用isVisible接口返回值结果变更前后会不一致，例如：
```ts
import { FrameNode } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  private stackNode: FrameNode | null = null
  private columnNode: FrameNode | null = null

  build() {
    Column() {
      Stack() {
        if (true) {
          Column()
            .id("column")
            .visibility(Visibility.Visible)
        }
      }
      .id("stack")
      .visibility(Visibility.Hidden)

      Button("print")
        .onClick(() => {
          this.stackNode = this.getUIContext().getFrameNodeById("stack")
          this.columnNode = this.getUIContext().getFrameNodeById("column")
          if (this.stackNode) {
            // Stack节点的可见性，为false
            console.log("stackNode.isVisible:", this.stackNode.isVisible())
          }
          if (this.columnNode) {
            // Column节点的可见性，变更前为true，变更后为false
            console.log("columnNode.isVisible:", this.columnNode.isVisible())
          }
        })
    }
  }
}
```

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.46开始。

**变更的接口/组件**

FrameNode.d.ts文件isVisible接口。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.4 Search组件searchButton属性行为变更，设置为undefined后，获取searchButton属性的值为空
**访问级别**

公开接口

**变更原因**

Search组件searchButton属性设置为undefined后，变更前获取searchButton属性值会取得上一次设置的值，此行为非预期行为，变更后改为获取到空值。

**变更影响**

此变更不涉及应用适配。

| 变更前 | 变更后 |
|------ |--------|
|Search组件searchButton属性设置为undefined后，获取属性值为上一次设置的值，且会导致分隔线不消失。<br>![search_button_before](figures/search_button_before.png)|Search组件searchButton属性设置为undefined后，获取属性值为空，分隔线隐藏<br>![search_button_after](figures/search_button_after.png)|

**起始API Level**

7

**变更发生版本**

从OpenHarmony 5.1.0.46 版本开始。

**变更的接口/组件**

search.d.ts文件searchButton接口。

**适配指导**

默认行为变更，无需适配。
