# RelativeContainer

相对布局组件，用于复杂场景中元素对齐的布局。

>  **说明：**
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 规则说明  

 * 容器内子组件区分水平方向，垂直方向：  
   * 水平方向为left， middle， right，对应容器的HorizontalAlign.Start， HorizontalAlign.Center， HorizontalAlign.End。  
   * 垂直方向为top， center， bottom，对应容器的VerticalAlign.Top， VerticalAlign.Center， VerticalAlign.Bottom。
 * 子组件使用[alignRules](ts-universal-attributes-location.md)属性设置其上中下，左中右边界与外层容器或者设置了id的其他子组件的上中下，左中右对齐方式，具体参考示例。
 * 子组件可以将容器或者其他子组件设为锚点：  
   * 参与相对布局的容器内组件必须设置id，容器RelativeContainer的id固定为'__container__'。
   * 无id的子组件位置设置默认为容器左上方。
   * 此子组件某一方向上的三个位置可以将容器或其他子组件的同方向三个位置为锚点，同方向上两个以上位置设置锚点以后会跳过第三个。  
   * 同方向上两个以上位置设置锚点时此子组件额外设置width，height不生效。  
   * 对齐后需要额外偏移可设置offset。  
 * 特殊情况
   * 互相依赖，环形依赖时容器内子组件全部不绘制。  
   * 同方向上两个以上位置设置锚点但锚点位置逆序时此子组件大小为0，即不绘制。  
   

## 子组件

支持多个子组件。


## 接口

RelativeContainer()

## 示例

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      Button("Extra button").width(100).height(50)

      // 外层容器的id默认为为'__container__'
      RelativeContainer() {
        Button("Button 1")
          .width(120)
          .height(30)
          .alignRules({
            middle: { anchor: "__container__", align: HorizontalAlign.Center }, // 水平方向上，组件中部与容器中间对齐，即组件在容器中水平居中
          })
          .id("bt1") // id设置为bt1
          .borderWidth(1)
          .borderColor(Color.Black)

        Text("This is text 2")
          .fontSize(20)
          .padding(10)
          .borderWidth(1)
          .borderColor(Color.Black)
          .height(30)
          .id("tx2") // id设置为tx2
          .alignRules({
            bottom: { anchor: "__container__", align: VerticalAlign.Bottom }, // 组件下边与容器下边对齐
            top: { anchor: "bt1", align: VerticalAlign.Bottom }, // 组件上边与button1底部对齐
            right: { anchor: "bt1", align: HorizontalAlign.Center } //  组件右侧与button1中间点对齐
          })

        LoadingProgress()
          .color(Color.Blue)
          .borderWidth(1)
          .borderColor(Color.Black)
          .height(30)
          .width(30)
          .id("lp3") // id设置为lp3
          .alignRules({
            left: { anchor: "bt1", align: HorizontalAlign.End }, // 组件左边对齐容器bt1的右边
            top: { anchor: "tx2", align: VerticalAlign.Center }, // 组件上边对齐容器tx2的中间
            bottom: { anchor: "__container__", align: VerticalAlign.Bottom } // 组件下边对齐最外层容器的底边
          })

        Gauge({ value: 50, min: 0, max: 100 })
          .startAngle(210)
          .endAngle(150)
          .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1], [0xD94838, 1]])
          .strokeWidth(20)
          .width(50)
          .height(50)
          .alignRules({
            left: { anchor: "tx2", align: HorizontalAlign.End }, // 组件左边对齐容器tx2的右边
            right: { anchor: "__container__", align: HorizontalAlign.End }, // 组件右边对齐最外层容器的右边
            top: { anchor: "__container__", align: VerticalAlign.Top }, // 组件上边对齐最外层容器的上边
            bottom: { anchor: "lp3", align: VerticalAlign.Top } // 组件下边对齐容器lp3的上边
          })
          .id("g4")
          .borderWidth(1)
          .borderColor(Color.Black)
      }
      .width(200).height(200)
      .backgroundColor(Color.Orange)
    }.height('100%')
  }
}
```
![relative container](figures/relativecontainer.png)