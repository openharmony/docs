# Size

The size attributes set the width, height, and margin of a component.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## width

width(value: Length)

Sets the width of the component. By default, the width required to fully hold the component content is used. If the width of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| value | [Length](ts-types.md#length) | Yes   | Width of the component to set.<br>Unit: vp|

>  **NOTE**
>
>  - For the **\<TextInput>** component, the **auto** option of **width** means to adapt to the text width.
>  
>  - For the **\<AlphabetIndexer>** component, the **auto** option of **width** means to adapt to the maximum width of index entries.

## height

height(value: Length)

Sets the height of the component. By default, the height required to fully hold the component content is used. If the height of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| value | [Length](ts-types.md#length) | Yes   | Height of the component to set.<br>Unit: vp|

>  **NOTE**
>
>  For the **\<Row>**, **\<Column>**, and **\<RelativeContainer>** components, the **auto** option of **width** and **height** means to adapt to their child components.

## size

size(value: SizeOptions)

Sets the size of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                             | Mandatory  | Description               |
| ----- | ------------------------------- | ---- | ----------------- |
| value | [SizeOptions](#sizeoptions) | Yes   | Size of the component to set.<br>Unit: vp|

## padding

padding(value: Padding | Length | LocalizedPadding)

Sets the padding of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| value | [Padding](ts-types.md#padding) \|  [Length](ts-types.md#length) \|   [LocalizedPadding](ts-types.md#localizedpadding12)<sup>12+</sup>| Yes   | Padding of the component to set.<br>When the parameter is of the **Length** type, the four paddings take effect.<br>Default value: **0**<br>Unit: vp<br>When **padding** is set to a percentage, the width of the parent container is used as the basic value.|

## margin

margin(value: margin | Length | LocalizedMargin)

Sets the margin of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory    | Description                                                        |
| ------ | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| value  | [Margin](ts-types.md#margin) \| [Length](ts-types.md#length) \| [LocalizedMargin](ts-types.md#localizedmargin12)<sup>12+</sup> | Yes| Margin of the component to set.<br>When the parameter is of the **Length** type, the four margins take effect.<br>Default value: **0**<br>Unit: vp<br>When **margin** is set to a percentage, the width of the parent container is used as the basic value. When child components are laid out along the cross axis of the **\<Row>**, **\<Column>**, or **\<Flex>** container, the cross axis size of the child components and the margins add up to the total size of the container.<br>For example, if the width of the **\<Column>** container is 100, the width of the child component is 50, the left margin is 10, and the right margin is 20, then the actual horizontal offset of the child component is 10.|

## layoutWeight

layoutWeight(value: number | string)

Sets the weight of the component during layout.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                        | Mandatory     | Description                                      |
| ----- | -------------------------- | ------- | ---------------------------------------- |
| value | number \| string | Yes| Weight of the component during layout. When the container size is determined, the container space is allocated along the main axis among the component and sibling components based on the layout weight, and the component size setting is ignored.<br>Default value: **0**<br>**NOTE**<br>This attribute is valid only for the **\<Row>**, **\<Column>**, and **\<Flex>** layouts.<br>The value can be a number greater than or equal to 0 or a string that can be converted to a number.|

## constraintSize

constraintSize(value: ConstraintSizeOptions)

Sets the constraint size of the component, which is used to limit the size range during component layout.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| value | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Yes   | Constraint size of the component to set. **constraintSize** takes precedence over **width** and **height**. See **Impact of constraintSize on width/height**.<br>Default value:<br>{<br>minWidth: 0,<br>maxWidth: Infinity,<br>minHeight: 0,<br>maxHeight: Infinity<br>}<br>Unit: vp<br>|

**Impact of constraintSize on width/height**

| Default Value                                     | Result                                      |
| ---------------------------------------- | ---------------------------------------- |
| /                                        | max(minWidth/minHeight, min(maxWidth/maxHeight, width/height)) |
| maxWidth/maxHeight                       | max(minWidth/minHeight, width/height)    |
| minWidth/minHeight                       | min(maxWidth/maxHeight, width/height)    |
| width/height                             | In the case of maxWidth/maxHeight > minWidth/minHeight, the layout logic of the component is used,<br>and the result is between maxWidth/maxHeight and minWidth/minHeight.<br> In other cases, the result is max(minWidth/minHeight, maxWidth/maxHeight).|
| maxWidth/maxHeight && width/height       | minWidth/minHeight                       |
| minWidth/minHeight && width/height       | The layout logic of the component is used. The final result does not exceed maxWidth/maxHeight.    |
| maxWidth/maxHeight && minWidth/minHeight | Width/Height, which may be stretched or compressed based on other layout attributes.          |
| maxWidth/maxHeight && minWidth/minHeight && width/height | The layout restrictions passed by the parent container are used for layout.                       |

## SizeOptions

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| width  | [Length](ts-types.md#length) | No| Component width.|
| height | [Length](ts-types.md#length) | No| Component height.|

## ConstraintSizeOptions

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| minWidth  | [Length](ts-types.md#length) | No| Minimum width of the component.|
| maxWidth  | [Length](ts-types.md#length) | No| Maximum width of the component.|
| minHeight | [Length](ts-types.md#length) | No| Minimum height of the component.|
| maxHeight | [Length](ts-types.md#length) | No| Maximum height of the component.|

>  **NOTE**
>
>  For the **\<Row>**, **\<Column>**, and **\<RelativeContainer>** components, the **auto** option of **width** and **height** means to adapt to their child components. For the **\<TextInput>** component, the **auto** option of **width** means to adapt to the text width.

## Example
### Example 1

```ts
// xxx.ets
@Entry
@Component
struct SizeExample {
  build() {
    Column({ space: 10 }) {
      Text('margin and padding:').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row() {
        // Width: 80; height: 80; margin: 20 (blue area); top, bottom, left, and right paddings: 5, 15, 10, and 20 (white area)
        Row() {
          Row().size({ width: '100%', height: '100%' }).backgroundColor(Color.Yellow)
        }
        .width(80)
        .height(80)
        .padding({ top: 5, left: 10, bottom: 15, right: 20 })
        .margin(20)
        .backgroundColor(Color.White)
      }.backgroundColor(Color.Blue)

      Text('constraintSize').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Text('this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text')
        .width('90%')
        .constraintSize({ maxWidth: 200 })

      Text('layoutWeight').fontSize(12).fontColor(0xCCCCCC).width('90%')
      // When the container size is determined, the component occupies the space along the main axis based on the layout weight, and the component size setting is ignored.
      Row() {
        // Weight 1: The component occupies 1/3 of the remaining space along the main axis.
        Text('layoutWeight(1)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xFFEFD5).textAlign(TextAlign.Center)
          .layoutWeight(1)
        // Weight 2: The component occupies 2/3 of the remaining space along the main axis.
        Text('layoutWeight(2)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
          .layoutWeight(2)
        // If layoutWeight is not set, the component is rendered based on its own size setting.
        Text('no layoutWeight')
          .size({ width: '30%', height: 110 }).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.size({ width: '90%', height: 140 }).backgroundColor(0xAFEEEE)
      // calc calculation feature
      Text('calc:').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Text('calc test')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .backgroundColor(0xFFFAF0)
        .textAlign(TextAlign.Center)
        .margin('calc(25vp*2)')
        // If width or height is set to a percentage, the width or height of the parent container are used as the basic value.
        .size({ width: 'calc(90%)', height: 'calc(50vp + 10%)' })
    }.width('100%').margin({ top: 5 })
  }
}
```

![size](figures/size.png)

### Example 2
```ts
// xxx.ets
// In the following, the padding and margin attributes are of the LocalizedPadding and LocalizedMargin types, respectively.

import { LengthMetrics } from '@kit.ArkUI'

@Entry
@Component
struct SizeExample {
  build() {
    Column({ space: 10 }) {
      Text('margin and padding:').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row() {
        // Set the width to 80, height to 80, top, bottom, start, and end paddings to 40, 20, 30, and 10, respectively (blue area), and top, bottom, start, and end margins to 5, 15, 10, and 20, respectively (white area).
        Row() {
          Row().size({ width: '100%', height: '100%' }).backgroundColor(Color.Yellow)
        }
        .width(80)
        .height(80)
        .padding({
          top: LengthMetrics.vp(5),
          bottom: LengthMetrics.vp(15),
          start: LengthMetrics.vp(10),
          end: LengthMetrics.vp(20)
        })
        .margin({
          top: LengthMetrics.vp(40),
          bottom: LengthMetrics.vp(20),
          start: LengthMetrics.vp(30),
          end: LengthMetrics.vp(10)
        })
        .backgroundColor(Color.White)
      }.backgroundColor(Color.Blue)
    }.width('100%').margin({ top: 5 })
  }
}
```

The following shows how the example is represented with left-to-right scripts.

![size](figures/size-ltr.png)

The following shows how the example is represented with right-to-left scripts.

![size](figures/size-rtl.png)
