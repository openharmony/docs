# LoadingProgress

用于显示加载动效的组件。

>  **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

LoadingProgress()

创建加载进展组件。

从API version 9开始，该接口支持在ArkTS卡片中使用。

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | 设置加载进度条前景色。<br/>默认值：'#99666666'。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| enableLoading<sup>10+</sup> | boolean | 设置LoadingProgress动画显示或者不显示。<br/>默认值：true。<br/>**说明：**<br/> LoadingProgress动画不显示时，该组件依旧占位。<br/>通用属性Visibility.Hidden隐藏的是包括border、padding等整个组件范围，而enableLoading=false只隐藏LoadingProgress本身动画内容，不包括border等。|

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

```ts
// xxx.ets
@Entry
@Component
struct LoadingProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Orbital LoadingProgress ').fontSize(9).fontColor(0xCCCCCC).width('90%')
      LoadingProgress()
        .color(Color.Blue)
        .layoutWeight(1)
    }.width('100%').margin({ top: 5 })
  }
}
```

![LoadingProgress](figures/LoadingProgress.gif)
