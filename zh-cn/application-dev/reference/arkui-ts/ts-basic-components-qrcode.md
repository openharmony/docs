# QRCode

用于显示单个二维码的组件。

>  **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 
> 二维码组件的像素点数量与内容有关，当组件尺寸过小时，可能出现无法展示内容的情况，此时需要适当调整组件尺寸。


## 子组件

无


## 接口

QRCode(value: string)

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数:**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 二维码内容字符串。最大支持256个字符，若超出，则截取前256个字符。<br/>**说明：** <br/>该字符串内容确保有效，不支持null、undefined以及空内容。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性。

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | 设置二维码颜色。<br/>默认值：Color.Black <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。|
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 设置二维码背景颜色。<br/>默认值：Color.White <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>当设置[通用属性backgroundColor](./ts-universal-attributes-background.md)时，设置二维码内容区的背景颜色，而不是组件的背景颜色。 |


## 事件

通用事件支持[点击事件](ts-universal-events-click.md)、[触摸事件](ts-universal-events-touch.md)、[挂载卸载事件](ts-universal-events-show-hide.md)。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct QRCodeExample {
  private value: string = 'hello world'
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)
      QRCode(this.value).width(200).height(200)

      // 设置二维码颜色
      Text('color').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)
      QRCode(this.value).color(0xF7CE00).width(200).height(200)

      // 设置二维码背景色
      Text('backgroundColor').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)
      QRCode(this.value).width(200).height(200).backgroundColor(Color.Orange)
    }.width('100%').margin({ top: 5 })
  }
}
```

![qrcode](figures/qrcode.png)
