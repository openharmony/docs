# RelativeContainer

相对布局组件，用于复杂场景中元素对齐的布局。

>  **说明：**
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 规则说明  

 * 容器内子组件区分水平方向，垂直方向:  
   * 水平方向为left, middle, right，对应容器的HorizontalAlign.Start, HorizontalAlign.Center, HorizontalAlign.End  
   * 垂直方向为top, center, bottom, right，对应容器的VerticalAlign.Top, VerticalAlign.Center, VerticalAlign.Bottom
 * 子组件可以将容器或者其他子组件设为锚点:  
   * 参与相对布局的容器内组件必须设置id，容器id固定为__container__  
   * 无id的子组件位置设置默认为容器左上方  
   * 此子组件某一方向上的三个位置可以将容器或其他子组件的同方向三个位置为锚点，同方向上两个以上位置设置锚点以后会跳过第三个  
   * 同方向上两个以上位置设置锚点时此子组件额外设置width, height不生效  
   * 对齐后需要额外偏移可设置offset  
 * 特殊情况
   * 互相依赖，环形依赖时容器内子组件全部不绘制  
   * 同方向上两个以上位置设置锚点但锚点位置逆序时此子组件大小为0，即不绘制  

## 权限列表

无


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
        RelativeContainer() {
          Button("Button 1").width(120).height(30)
            .alignRules({
              middle: { anchor: "__container__", align: HorizontalAlign.Center },
            })
            .id("bt1").borderWidth(1).borderColor(Color.Black)
          Text("This is text 2").fontSize(20).padding(10)
            .alignRules({
              bottom: { anchor: "__container__", align: VerticalAlign.Bottom },
              top: { anchor: "bt1", align: VerticalAlign.Bottom },
              right:{ anchor: "bt1", align: HorizontalAlign.Center }
            }).id("tx2").borderWidth(1).borderColor(Color.Black).height(30)

          LoadingProgress().color(Color.Blue)
            .alignRules({
              left: { anchor: "bt1", align: HorizontalAlign.End },
              top: { anchor: "tx2", align: VerticalAlign.Center },
              bottom: { anchor: "__container__", align: VerticalAlign.Bottom }
            }).id("lp3").borderWidth(1).borderColor(Color.Black)
          .height(30).width(30)

          Gauge({ value: 50, min: 0, max: 100 })
            .startAngle(210).endAngle(150)
            .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1], [0xD94838, 1]])
            .strokeWidth(20)
            .width(50).height(50)
            .alignRules({
              left: { anchor: "tx2", align: HorizontalAlign.End },
              right:{ anchor: "__container__", align: HorizontalAlign.End },
              top: { anchor: "__container__", align: VerticalAlign.Top },
              bottom: { anchor: "lp3", align: VerticalAlign.Top }
            }).id("g4").borderWidth(1).borderColor(Color.Black)

        }
        .width(200).height(200)
        .backgroundColor(Color.Orange)

    }
    .height('100%')
  }
}
```
![relative container](figures/relativecontainer.png)