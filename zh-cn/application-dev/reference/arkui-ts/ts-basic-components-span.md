# Span

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


文本段落，只能作为Text子组件，呈现一段文本信息。


## 权限列表

无


## 子组件

无


## 接口

Span(content: string)

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | content | string | 是 | - | 文本内容。 | 


## 属性

通用属性方法仅支持通用文本样式，不支持触摸热区设置。

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| decoration | {<br/>type:&nbsp;[TextDecorationType](ts-appendix-enums.md#textdecorationtype枚举说明),<br/>color?:&nbsp;Color<br/>} | {<br/>type:&nbsp;TextDecorationType.None<br/>color：Color.Black<br/>} | 设置文本装饰线样式及其颜色。 |
| textCase | [TextCase](ts-appendix-enums.md#textcase枚举说明) | Normal | 设置文本大小写。 |


## 事件

通用事件仅支持点击事件。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 由于Span组件无尺寸信息，因此点击事件返回的ClickEvent对象的target属性无效。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct SpanExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }

      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Underline-span').decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am LineThrough-span').decoration({ type: TextDecorationType.LineThrough, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am Overline-span').decoration({ type: TextDecorationType.Overline, color: Color.Red }).fontSize(12)
      }

      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Lower-span').textCase(TextCase.LowerCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
      Text() {
        Span('I am Upper-span').textCase(TextCase.UpperCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![zh-cn_image_0000001219982709](figures/zh-cn_image_0000001219982709.gif)
