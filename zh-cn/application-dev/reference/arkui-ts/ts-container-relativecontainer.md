# RelativeContainer

相对布局组件，用于复杂场景中元素对齐的布局。

>  **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 规则说明  

 * 容器内子组件区分水平方向，垂直方向：  
   * 水平方向为left， middle， right，对应容器的HorizontalAlign.Start， HorizontalAlign.Center， HorizontalAlign.End。
   * 垂直方向为top， center， bottom，对应容器的VerticalAlign.Top， VerticalAlign.Center， VerticalAlign.Bottom。
 * 子组件可以将容器或者其他子组件设为锚点：  
   * 参与相对布局的容器内组件必须设置id，不设置id的组件不显示，容器id固定为__container__。
   * 此子组件某一方向上的三个位置可以将容器或其他子组件的同方向三个位置为锚点，同方向上设置两个以上锚点的优先级。水平方向Start和Center优先，垂直方向Top和Center优先。
   * 前端页面设置的子组件尺寸大小不会受到相对布局规则的影响。子组件某个方向上设置两个或以上alignRules时不建议设置此方向尺寸大小。
   * 对齐后需要额外偏移可设置offset。
 * 特殊情况
   * 互相依赖，环形依赖时容器内子组件全部不绘制。
   * 同方向上两个以上位置设置锚点但锚点位置逆序时此子组件大小为0，即不绘制。

## 子组件

支持多个子组件。


## 接口

RelativeContainer()

从API version 9开始，该接口支持在ArkTS卡片中使用。

## 示例

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {

      RelativeContainer() {
        Row().width(100).height(100)
          .backgroundColor("#FF3333")
          .alignRules({
            top: {anchor: "__container__", align: VerticalAlign.Top},
            left: {anchor: "__container__", align: HorizontalAlign.Start}
          })
          .id("row1")

        Row().width(100).height(100)
          .backgroundColor("#FFCC00")
          .alignRules({
            top: {anchor: "__container__", align: VerticalAlign.Top},
            right: {anchor: "__container__", align: HorizontalAlign.End}
          })
          .id("row2")

        Row().height(100)
          .backgroundColor("#FF6633")
          .alignRules({
            top: {anchor: "row1", align: VerticalAlign.Bottom},
            left: {anchor: "row1", align: HorizontalAlign.End},
            right: {anchor: "row2", align: HorizontalAlign.Start}
          })
          .id("row3")

        Row()
          .backgroundColor("#FF9966")
          .alignRules({
            top: {anchor: "row3", align: VerticalAlign.Bottom},
            bottom: {anchor: "__container__", align: VerticalAlign.Bottom},
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right: {anchor: "row1", align: HorizontalAlign.End}
          })
          .id("row4")

        Row()
          .backgroundColor("#FF66FF")
          .alignRules({
            top: {anchor: "row3", align: VerticalAlign.Bottom},
            bottom: {anchor: "__container__", align: VerticalAlign.Bottom},
            left: {anchor: "row2", align: HorizontalAlign.Start},
            right: {anchor: "__container__", align: HorizontalAlign.End}
          })
          .id("row5")
      }
      .width(300).height(300)
      .margin({left: 100})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer.png)