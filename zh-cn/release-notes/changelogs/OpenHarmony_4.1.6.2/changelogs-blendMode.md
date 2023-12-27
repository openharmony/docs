# BlendMode接口ChangeLog

## cl.blendMode.1 blendMode接口变更

**访问级别**

公开接口

**变更原因**

之前接口行为不够通用，难以满足三方应用多场景需求实现。当前有三方场景无法满足诉求变更。

**变更影响**

该变更为不兼容变更。</br>
1、使用blendMode接口时，开发者调用接口枚举发生变化。枚举NORMAL变为NONE，SOURCE_IN变为SRC_IN, DESTINATION_IN变为DST_IN。</br>
2、接口行为由将当前控件背景与子节点内容进行混合改为将当前控件内容（含子节点内容）与下方画布（可能为离屏画布）已有内容进行混合。

**API Level**

11

**变更发生版本**

从Openharmony SDK 4.1.6.2 开始

**变更的接口/组件**

blendMode接口枚举和接口行为进行改变。

**适配指导**

1、开发者需将原先调用枚举由NORMAL改为NONE，SOURCE_IN改为SRC_IN，DESTINATION_IN改为DST_IN。</br>
2、由于接口行为发生改变，之前的接口内含两次离屏，第一次离屏用来绘制控件背景，第二次离屏用来绘制子节点内容。当前接口仅可有一次离屏，需调用OFFSCREEN来触发离屏。接口调用两次来保持两次离屏。</br>
示例代码：
```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text("test")
        .fontSize(144)
        .fontWeight(FontWeight.Bold)
        .fontColor('#ffff0101')
        .blendMode(SRC_IN, OFFSCREEN)
    }
    .blendMode(SRC_OVER, OFFSCREEN)
    .height('100%')
    .width('100%')
    .backgroundColor('#ff08ff00')
  }
}
```