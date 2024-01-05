# ContainerSpan

[Text](ts-basic-components-text.md)组件的子组件，用于统一管理多个[Span](ts-basic-components-span.md)、[ImageSpan](ts-basic-components-imagespan.md)的背景色及圆角弧度。

> **说明：**
>
> 该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

可以包含[Span](ts-basic-components-span.md)、[ImageSpan](ts-basic-components-imagespan.md) 子组件。

## 接口

ContainerSpan()

## 属性

仅支持以下属性: [TextBackgroundStyle](#textbackgroundstyle对象说明)

| 名称                                       | 参数类型                                 | 描述                                                                                                                                                |
| ------------------------------------------ | ---------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| textBackgroundStyle | [TextBackgroundStyle](#textbackgroundstyle) | 文本背景样式。<br />默认值：<br />{<br />  color: Color.Transparent,<br />  radius: 0<br />} <br/>**说明：**<br/>子组件在不设置该属性时，将继承此属性值。 |

## TextBackgroundStyle对象说明

| 名称   | 参数类型                                                                 | 必填 | 描述         |
| ------ | ------------------------------------------------------------------------ | ---- | ------------ |
| color  | [ResourceColor](ts-types.md#resourcecolor)                                  | 否   | 文本背景色。 |
| radius | [Dimension](ts-types.md#dimension10) \| [BorderRadiuses](ts-universal-attributes-border.md#borderradiuses9对象说明) | 否   | 文本背景圆角。 |

## 事件

不支持[通用事件](ts-universal-events-click.md)。

## 示例

### 示例1

```ts
// xxx.ets
@Component
@Entry
struct Index {
  build() {
    Column() {
      Text() {
        ContainerSpan() {
          ImageSpan($r('app.media.app_icon'))
            .width('40vp')
            .height('40vp')
            .verticalAlign(ImageSpanAlignment.CENTER)
          Span('   Hello World !   ').fontSize('16fp').fontColor(Color.White)
        }.textBackgroundStyle({color: "#7F007DFF", radius: "12vp"})
      }
    }.width('100%').alignItems(HorizontalAlign.Center)
  }
}
```

![imagespan](figures/container_span.png)
