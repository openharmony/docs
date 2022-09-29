# RelativeContainer

The **\<RelativeContainer>** component is used for element alignment in complex scenarios.

>  **NOTE**
>
>  This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Rules 

 * Components in a container are aligned horizontally or vertically. 
   * Alignment modes in the horizontal direction can be left, center, or right, achieved by the **HorizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** attributes of the container, respectively. 
   * Alignment modes in the vertical direction can be top, center, or bottom, achieved by the **VerticalAlign.Top**, **VerticalAlign.Center**, and **VerticalAlign.Bottom** attributes of the container, respectively.
 * A child component can set the container or another child component as the anchor point. 
   * An ID must be set for the child components in the **\<RelativeContainer>**. The container ID is fixed at **__container__**. 
   * By default, a child component without an ID is positioned in the upper left corner of the container. 
   * Three positions in a direction of the child component can use three positions in the same direction of the container or another child components as anchor points. When anchor points are set for more than two positions in the same direction, the third position is skipped. 
   * When anchor points are set for more than two positions in the same direction, the width and height of the child component do not take effect. 
   * If offset is required after the alignment, it can be set through **offset**. 
 * Exceptions
   * When a mutual or circular dependency occurs, all child components in the container are not drawn. 
   * If anchors are set for more than two positions in the same direction but the anchor positions are reversed, the size of the child component is 0, that is, the child component is not drawn. 

## Required Permissions

None


## Child Components

Multiple child components are supported.


## APIs

RelativeContainer()

## Example

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
