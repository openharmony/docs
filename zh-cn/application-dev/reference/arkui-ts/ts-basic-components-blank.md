# Blank

空白填充组件，在容器主轴方向上，空白填充组件具有自动填充容器空余部分的能力。仅当父组件为Row/Column时生效。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Blank(min?: number&nbsp;|&nbsp;string)

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| min | number&nbsp;\|&nbsp;string | 否 | 空白填充组件在容器主轴上的最小大小。<br/>默认值：0 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md) | 设置空白填充的填充颜色。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct BlankExample {
  build() {
    Column() {
      Row() {
        Text('Bluetooth').fontSize(18)
        Blank()
        Toggle({ type: ToggleType.Switch })
      }.width('100%').backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })
    }.backgroundColor(0xEFEFEF).padding(20)
  }
}
```

竖屏状态

![zh-cn_image_0000001219662649](figures/zh-cn_image_0000001219662649.gif)

横屏状态

![zh-cn_image_0000001174104388](figures/zh-cn_image_0000001174104388.gif)
