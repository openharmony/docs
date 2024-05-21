# RelativeContainer

The **\<RelativeContainer>** component is used for element alignment in complex scenarios.

>  **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.



## Rules 

 * Components in a container are aligned horizontally or vertically. 
   * Alignment modes in the horizontal direction can be left, middle, or right, achieved by the **HorizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** attributes of the container, respectively.
   * Alignment modes in the vertical direction can be top, center, or bottom, achieved by the **VerticalAlign.Top**, **VerticalAlign.Center**, and **VerticalAlign.Bottom** attributes of the container, respectively.
 * A child component can set the container or another child component as the anchor. 
   * To show in the **\<RelativeContainer>**, child components must have an ID. The container ID is fixed at **__container__**.
   * A child component can have anchors for three positions in one direction (left, middle, and right in the horizontal direction and top, center, and bottom in the vertical direction). These anchors can be positions in the container or other child components in the same direction: **horizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** in the horizontal direction and **verticalAlign.Top**, **VerticalAlign.Center**, and **VerticalAlign.Bottom** in the vertical direction. If more than two anchors are set in the same direction, **Start** and **Center** in the horizontal direction are preferred, and **Top** and **Center** in the vertical direction are preferred. For example, when the left, middle, and right positions of a component in the horizontal direction use **HorizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** of the container as the anchors, respectively, then: if the widths of the component and its container cannot meet these rules at the same time, the rules for Start and Center are followed.
   * If both the child component size and relative layout rules are set:<br>In API versions earlier than 11, the child component size is bound by the relative layout rules.<br> Since API version 11, the child component size set from frontend pages is used.
   * If offset is required after the alignment, it can be set through **offset** (in API versions earlier than 11) or **bias** (supported since API version 11).
   * Since API version 11, if **\<RelativeContainer>** has its **width** and **height** attributes set to **auto**, it adapts its width and height to its child components.
   *If the component's child component uses it as the anchor in the horizontal direction, the **auto** value of **width** has no effect. The same rule applies to the vertical direction.
 * Exceptions
   * If the size of a child component cannot be determined based on the rules and its own **size** attribute, the child component is not drawn.
   * When a mutual or circular dependency occurs, none of the child components in the container are drawn. 
   * If anchors are set for two or more positions in a single direction but the anchor positions are reversed, the size of the child component is 0, which means that the child component is not drawn. 

## Child Components

Multiple child components are supported.


## APIs

RelativeContainer()

This API can be used in ArkTS widgets since API version 9.

## Example

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
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer.png)
