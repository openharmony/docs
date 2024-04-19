# RelativeContainer

The **\<RelativeContainer>** component is used for element alignment in complex scenarios.

>  **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Rules

 * Components in a container are aligned horizontally or vertically.
   * Alignment modes in the horizontal direction can be left, middle, or right, achieved by the **HorizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** attributes of the container, respectively.
   * Alignment modes in the vertical direction can be top, center, or bottom, achieved by the **VerticalAlign.Top**, **VerticalAlign.Center**, and **VerticalAlign.Bottom** attributes of the container, respectively.
 * A child component can have its container, guideline, barrier, or another child component as the anchor.
   * To show in the **\<RelativeContainer>**, child components must have a non-null, unique ID. The container ID is fixed at **__container__**. 
   * A child component can have anchors for three positions in one direction (left, middle, and right in the horizontal direction and top, center, and bottom in the vertical direction). These anchors can be positions in the container or other child components in the same direction: **horizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** in the horizontal direction and **verticalAlign.Top**, **VerticalAlign.Center**, and **VerticalAlign.Bottom** in the vertical direction. If more than two anchors are set in the same direction, **Start** and **Center** in the horizontal direction are preferred, and **Top** and **Center** in the vertical direction are preferred. For example, when the left, middle, and right positions of a component in the horizontal direction use **HorizontalAlign.Start**, **HorizontalAlign.Center**, and **HorizontalAlign.End** of the container as the anchors, respectively, then: if the widths of the component and its container cannot meet these rules at the same time, the rules for Start and Center are followed.
   * If both the child component size and relative layout rules are set:<br>In API versions earlier than 11, the child component size is bound by the relative layout rules.<br> Since API version 11, the child component size set from frontend pages is used.
   * If offset is required after the alignment, it can be set through [bias](ts-universal-attributes-location.md#bias) (available since API version 11) or **offset** (not recommended).
   * Since API version 11, if **\<RelativeContainer>** has its **width** and **height** attributes set to **auto**, it adapts its width and height to its child components.
   *If the container's child component uses the container as an anchor in the horizontal direction, the **auto** value of **width** has no effect. The same rule applies to the vertical direction.
   * For a child component of the container, **margin** has a different meaning from the universal attribute **margin**. It indicates the distance to the anchor in the respective direction. If there is no anchor in the respective direction, **margin** in that direction does not take effect.
   * If the position of the guideline is not declared or the declared value is invalid (for example, **undefine**), the position of **start: 0** is used. Either **start** or **end** can be declared for the position. If both of them are declared, only **start** takes effect.
   * If the size of the container in a direction is declared as **auto**, the position of the guideline in the direction must be declared in **start** mode (the value cannot be in percentage).
   * A guideline or barrier in the vertical direction can only be used as the anchor of the component in the horizontal direction, and the value is **0** when it is used as the anchor in the vertical direction. A guideline or barrier in the horizontal direction can only be used as the anchor of the component in the vertical direction, and the value is **0** when it is used as the anchor in the horizontal direction.
   * The formation of a chain depends on the dependency between components. For example, the minimum horizontal chain formed by component A and component B requires the following dependency: Anchor 1 <- Component A <--> Component B -> Anchor 2. That is, A has a left anchor, B has a right anchor, the right anchor of A is **HorizontalAlign.Start** of B, and the left anchor of B is **HorizontalAlign.End** of A.
   * The direction and format of the chain are declared in the [chainMode](ts-universal-attributes-location.md#chainmode11) API of the chain head component. The **bias** attributes of all elements in the chain are ineffective, and the bias of the chain head element takes effect as the bias of the entire chain.
   * If the size of all elements in a chain exceeds the anchor constraint of the chain, the excess part is evenly distributed on both sides of the chain. In the [Packed](ts-appendix-enums.md#chainstyle11) chain, the distribution of the excess part can be set through [bias](ts-universal-attributes-location.md#bias).
 * Exceptions
   * If the size of a child component cannot be determined based on the rules and its own **size** attribute, the child component is not drawn.
   * When a mutual or circular dependency occurs, none of the child components in the container are drawn. 
   * If anchors are set for two or more positions in a single direction but the anchor positions are reversed, the size of the child component is 0, which means that the child component is not drawn. 

## Child Components

Multiple child components are supported.


## APIs

RelativeContainer()

Since API version 9, this API is supported in ArkTS widgets.

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### guideLine<sup>11+</sup>

guideLine(value: Array&lt;GuideLineStyle&gt;)

Sets the guidelines in the **\<RelativeContainer>** component. The value is an array, each element of which is a guideline.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                            |
| ------ | ------------------------------------------ | ---- | -------------------------------- |
| value  | Array<[GuideLineStyle](#guidelinestyle11)> | Yes  | Guidelines in the **\<RelativeContainer>** component.|

### barrier<sup>11+</sup>

barrier(value: Array&lt;BarrierStyle&gt;)

Sets the barriers in the **\<RelativeContainer>** component. The value is an array, each element of which is a barrier.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                  | Mandatory| Description                          |
| ------ | -------------------------------------- | ---- | ------------------------------ |
| value  | Array<[BarrierStyle](#barrierstyle11)> | Yes  | Barriers in the **\<RelativeContainer>** component.|


## GuideLineStyle<sup>11+</sup>

Defines the ID, direction, and position of a guideline.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| id  | string  | Yes   | ID of the guideline, which must be unique and cannot be the same as the name of any component in the container.  |
| direction | [Axis](ts-appendix-enums.md#axis) | Yes   | Direction of the guideline.<br>Default value: **Axis.Vertical**|
| position | [GuideLinePosition](#guidelineposition11) | Yes   | Position of the guideline.<br>Default value:<br>{<br>start: 0<br>} |

## GuideLinePosition<sup>11+</sup>

Defines the position of a guideline.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| start  | [Dimension](ts-types.md#dimension10)  | No   | Distance between the guideline and the left or top of the container.  |
| end | [Dimension](ts-types.md#dimension10) | No   | Distance between the guideline and the right or bottom of the container.|

## BarrierStyle<sup>11+</sup>

Defines the ID, direction, and referenced components of a barrier.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| id  | string  | Yes   | ID of the barrier, which must be unique and cannot be the same as the name of any component in the container.  |
| direction | [BarrierDirection](ts-appendix-enums.md#barrierdirection11) | Yes   | Direction of the barrier.<br>Default value: **BarrierDirection.LEFT**|
| referencedId | Array\<string> | Yes   | Referenced components of the barrier.|

## Example

### Example 1

This example shows how to use containers and components in the containers as anchors for layout.

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

### Example 2

This example shows how to set margins for child components in the container.

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
          .margin(10)

        Row().width(100).height(100)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(100).height(100)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Bottom}
          })
          .id("row3")

        Row().width(100).height(100)
          .backgroundColor("#FF9966")
          .alignRules({
            left: {anchor: "row3", align: HorizontalAlign.End},
            top: {anchor: "row2", align: VerticalAlign.Bottom}
          })
          .id("row4")
          .margin(10)
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer1.png)

### Example 3

This example shows how to configure the container to adapt its size to content (**size** declared as **"auto"**).

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(100).height(100)
          .backgroundColor("#FF3333")
          .id("row1")

        Row().width(100).height(100)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(100).height(100)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Bottom}
          })
          .id("row3")

        Row().width(100).height(100)
          .backgroundColor("#FF9966")
          .alignRules({
            left: {anchor: "row3", align: HorizontalAlign.End},
            top: {anchor: "row2", align: VerticalAlign.Bottom}
          })
          .id("row4")
      }
      .width("auto").height("auto")
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}
```
![relative container](figures/relativecontainer2.png)

### Example 4

This example shows the usage of **bias**.

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
            bottom : {anchor : "__container__", align : VerticalAlign.Bottom},
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right : {anchor : "__container__", align: HorizontalAlign.End},
            bias : {vertical : 0.3}
          })
          .id("row1")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer3.png)

### Example 5

This example shows how to declare a guideline and use it as an anchor.

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
            left: {anchor: "guideline1", align: HorizontalAlign.End},
            top: {anchor: "guideline2", align: VerticalAlign.Top}
          })
          .id("row1")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
      .guideLine([{id:"guideline1", direction: Axis.Vertical, position:{start:50}},
        {id:"guideline2", direction: Axis.Horizontal, position:{start:50}}])
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer4.png)

### Example 6

This example shows how to declare a barrier and use it as an anchor.

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(100).height(100)
          .backgroundColor("#FF3333")
          .id("row1")

        Row().width(100).height(100)
          .backgroundColor("#FFCC00")
          .alignRules({
            middle: {anchor: "row1", align: HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Bottom}
          })
          .id("row2")

        Row().width(100).height(100)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "barrier1", align: HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row3")

        Row().width(50).height(50)
          .backgroundColor("#FF9966")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.Start},
            top: {anchor: "barrier2", align: VerticalAlign.Bottom}
          })
          .id("row4")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
      .barrier([{id: "barrier1", direction: BarrierDirection.RIGHT, referencedId:["row1", "row2"]},
        {id: "barrier2", direction: BarrierDirection.BOTTOM, referencedId:["row1", "row2"]}])
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer5.png)

### Example 7

This example shows how to use **chainMode** to implement the horizontal **SPREAD** chain.

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(80).height(80)
          .backgroundColor("#FF3333")
          .alignRules({
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right: {anchor: "row2", align : HorizontalAlign.Start},
            center: {anchor: "__container__", align: VerticalAlign.Center}
          })
          .id("row1")
          .chainMode(Axis.Horizontal, ChainStyle.SPREAD)

        Row().width(80).height(80)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            right: {anchor: "row3", align : HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(80).height(80)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row2", align: HorizontalAlign.End},
            right: {anchor: "__container__", align : HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row3")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer6.png)

### Example 8

This example shows how to use **chainMode** to implement the horizontal **SPREAD_INSIDE** chain.

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(80).height(80)
          .backgroundColor("#FF3333")
          .alignRules({
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right: {anchor: "row2", align : HorizontalAlign.Start},
            center: {anchor: "__container__", align: VerticalAlign.Center}
          })
          .id("row1")
          .chainMode(Axis.Horizontal, ChainStyle.SPREAD_INSIDE)

        Row().width(80).height(80)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            right: {anchor: "row3", align : HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(80).height(80)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row2", align: HorizontalAlign.End},
            right: {anchor: "__container__", align : HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row3")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer7.png)

### Example 9

This example shows how to use **chainMode** to implement the horizontal **PACKED** chain.

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(80).height(80)
          .backgroundColor("#FF3333")
          .alignRules({
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right: {anchor: "row2", align : HorizontalAlign.Start},
            center: {anchor: "__container__", align: VerticalAlign.Center}
          })
          .id("row1")
          .chainMode(Axis.Horizontal, ChainStyle.PACKED)

        Row().width(80).height(80)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            right: {anchor: "row3", align : HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(80).height(80)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row2", align: HorizontalAlign.End},
            right: {anchor: "__container__", align : HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row3")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer8.png)

### Example 10

This example shows how to use **chainMode** and **bias** to implement the horizontal **PACKED** chain with a bias.

```ts
@Entry
@Component
struct Index {
  build() {
    Row() {
      RelativeContainer() {
        Row().width(80).height(80)
          .backgroundColor("#FF3333")
          .alignRules({
            left: {anchor: "__container__", align: HorizontalAlign.Start},
            right: {anchor: "row2", align : HorizontalAlign.Start},
            center: {anchor: "__container__", align: VerticalAlign.Center},
            bias : {horizontal : 0}
          })
          .id("row1")
          .chainMode(Axis.Horizontal, ChainStyle.PACKED)

        Row().width(80).height(80)
          .backgroundColor("#FFCC00")
          .alignRules({
            left: {anchor: "row1", align: HorizontalAlign.End},
            right: {anchor: "row3", align : HorizontalAlign.Start},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row2")

        Row().width(80).height(80)
          .backgroundColor("#FF6633")
          .alignRules({
            left: {anchor: "row2", align: HorizontalAlign.End},
            right: {anchor: "__container__", align : HorizontalAlign.End},
            top: {anchor: "row1", align: VerticalAlign.Top}
          })
          .id("row3")
      }
      .width(300).height(300)
      .margin({left: 50})
      .border({width:2, color: "#6699FF"})
    }
    .height('100%')
  }
}

```
![relative container](figures/relativecontainer9.png)
