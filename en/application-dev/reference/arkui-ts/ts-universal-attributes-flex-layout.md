# Flex Layout

>  **NOTE**
>  - The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - The flex layout is valid only when the parent component is a **\<Flex>**, **\<Column>**, or **\<Row>** component.


## Attributes

| Name        | Type                                    | Description                                      |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| flexBasis  | string \| number             | Base size of a component in the main axis of the parent container.<br>Default value: **'auto'** (indicating that the base size of the component in the main axis is the original size of the component)|
| flexGrow   | number                                   | Percentage of the parent container's remaining space that is allocated to the component.<br>Default value: **0**      |
| flexShrink | number                                   | Percentage of the parent container's shrink size that is allocated to the component.<br>Default value: **1**    |
| alignSelf  | [ItemAlign](ts-appendix-enums.md#itemalign) | he default **alignItems** configuration in the parent container.<br>Default value: **ItemAlign.Auto** |


## Example

```ts
// xxx.ets
@Entry
@Component
struct FlexExample {

  build() {
    Column({ space: 5 }) {
      Text('flexBasis').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Base size in the main axis
      // The value of flexBasis() can be 'auto' or a number, which is equivalent to .width()/.height().
      Flex() {
        Text('flexBasis(100)')
          .flexBasis('100')
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('flexBasis("auto")')
          .flexBasis('auto')
          .width('60%')
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexGrow').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Percentage of the remaining space
      // flexGrow() specifies the percentage of the remaining space allocated to the component.
      Flex() {
        Text('flexGrow(2)')
          .flexGrow(2)
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('flexGrow(1)')
          .flexGrow(1)
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexShrink').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // flexShrink() specifies the percentage of the shrink size allocated to the component.
      // The ratio of text1 is 0, and the default values of other parameters are 1. If the components cannot be completely displayed, the last two components are shrunk proportionally. The first component is not shrunk.
      Flex({ direction: FlexDirection.Row }) {
        Text('flexShrink(0)')
          .flexShrink(0)
          .width('50%')
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('no flexShrink')
          .width('40%')
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
        Text('flexShrink(2)')
          .flexShrink(2)
          .width('40%')
          .height(100)
          .lineHeight(70)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('alignSelf').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // alignSelf() overwrites the default alignItems configuration in the flex layout.
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center }) {
        Text('no alignSelf,height:80').width('33%').height(80)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('alignSelf stretch')
          .alignSelf(ItemAlign.Stretch)
          .width('33%')
          .height(80)
          .lineHeight(70)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
        Text('no alignSelf,height:100').width('34%').height(100)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212378394](figures/en-us_image_0000001212378394.png)
