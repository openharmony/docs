# 多态样式

设置组件不同状态下的样式。

>  **说明：**
>
>  从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| stateStyles | StateStyles | 设置组件不同状态的样式。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

## StateStyles接口说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| normal | ()=&gt;void | 否 | 组件无状态时的样式。 |
| pressed | ()=&gt;void | 否 | 组件按下状态的样式。 |
| disabled | ()=&gt;void | 否 | 组件禁用状态的样式。 |
| focused | ()=&gt;void | 否 | 组件获焦状态的样式。 |
| clicked | ()=&gt;void | 否 | 组件点击状态的样式。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct StyleExample {
  @State isEnable: boolean = true

  @Styles pressedStyles() {
        .backgroundColor("#ED6F21")
        .borderRadius(10)
        .borderStyle(BorderStyle.Dashed)
        .borderWidth(2)
        .borderColor("#33000000")
        .width(120)
        .height(30)
        .opacity(1)
  }

  @Styles disabledStyles() {
        .backgroundColor("#E5E5E5")
        .borderRadius(10)
        .borderStyle(BorderStyle.Solid)
        .borderWidth(2)
        .borderColor("#2a4c1919")
        .width(90)
        .height(25)
        .opacity(1)
  }

  @Styles normalStyles() {
        .backgroundColor("#0A59F7")
        .borderRadius(10)
        .borderStyle(BorderStyle.Solid)
        .borderWidth(2)
        .borderColor("#33000000")
        .width(100)
        .height(25)
        .opacity(1)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center }) {
      Text("normal")
        .fontSize(14)
        .fontColor(Color.White)
        .opacity(0.5)
        .stateStyles({
          normal: this.normalStyles,
        })
        .margin({ bottom: 20 })
        .textAlign(TextAlign.Center)
      Text("pressed")
        .backgroundColor("#0A59F7")
        .borderRadius(20)
        .borderStyle(BorderStyle.Dotted)
        .borderWidth(2)
        .borderColor(Color.Red)
        .width(100)
        .height(25)
        .opacity(1)
        .fontSize(14)
        .fontColor(Color.White)
        .stateStyles({
          pressed: this.pressedStyles,
        })
        .margin({ bottom: 20 })
        .textAlign(TextAlign.Center)
      Text(this.isEnable == true ? "effective" : "disabled")
        .backgroundColor("#0A59F7")
        .borderRadius(20)
        .borderStyle(BorderStyle.Solid)
        .borderWidth(2)
        .borderColor(Color.Gray)
        .width(100)
        .height(25)
        .opacity(1)
        .fontSize(14)
        .fontColor(Color.White)
        .enabled(this.isEnable)
        .stateStyles({
          disabled: this.disabledStyles,
        })
        .textAlign(TextAlign.Center)
      Text("control disabled")
        .onClick(() => {
          this.isEnable = !this.isEnable
          console.log(`${this.isEnable}`)
        })
    }
    .width(350).height(300)
  }
}
```

![zh-cn_image_0000001188742468](figures/zh-cn_image_0000001188742468.gif)
