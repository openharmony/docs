# Size

The size attributes set the width, height, and margins of a component.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  When a component's size is set by percentage, the actual size is calculated based on the size of the nearest ancestor node with a fixed size.

## width

width(value: Length): T

Sets the width of the component. By default, the width required to fully hold the component content is used. If the width of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| value | [Length](ts-types.md#length) | Yes   | Width of the component to set.<br>Unit: vp|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

>  **NOTE**
>
>  - In the [TextInput](./ts-basic-components-textinput.md) component, setting **width** to **auto** means that the width adapts to the width of the text content.
>
>  - In the [AlphabetIndexer](./ts-container-alphabet-indexer.md) component, setting **width** to **auto** means that the width adapts to the maximum width of index entries.

## height

height(value: Length): T

Sets the height of the component. By default, the height required to fully hold the component content is used. If the height of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| value | [Length](ts-types.md#length) | Yes   | Height of the component to set.<br>Unit: vp|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

>  **NOTE**
>
>  In the [Row](./ts-container-row.md), [Column](./ts-container-column.md), and [RelativeContainer](./ts-container-relativecontainer.md) components, setting **width** and **height** to **auto** means that the size adapts to the size of their child components.

## width<sup>15+</sup>

width(widthValue: Length | LayoutPolicy): T

Sets the width of the component or its horizontal layout policy. By default, the component uses the width required for its content. If the width of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

**Widget capability**: This API can be used in ArkTS widgets since API version 15.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| widthValue | [Length](ts-types.md#length) \|  [LayoutPolicy](ts-types.md#layoutpolicy15) | Yes   | Width of the component to set.<br>Unit: vp<br>The [Flex](./ts-container-flex.md), [Row](./ts-container-row.md), [Column](./ts-container-column.md) and [Stack](./ts-container-stack.md) components support all parameters in [LayoutPolicy](ts-types.md#layoutpolicy15).<br> The [RelativeContainer](./ts-container-relativecontainer.md), [FolderStack](./ts-container-folderstack.md), [Divider](./ts-basic-components-divider.md), and [Blank](./ts-basic-components-blank.md) components support the **matchParent** parameter in [LayoutPolicy](ts-types.md#layoutpolicy15).|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## height<sup>15+</sup>

height(heightValue: Length | LayoutPolicy): T

Sets the height of the component or its vertical layout policy. By default, the component uses the height required for its content. If the height of the component is greater than that of the parent container, the component will be drawn beyond the parent container scope.

**Widget capability**: This API can be used in ArkTS widgets since API version 15.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                          | Mandatory  | Description                 |
| ----- | ---------------------------- | ---- | ------------------- |
| heightValue | [Length](ts-types.md#length) \|  [LayoutPolicy](ts-types.md#layoutpolicy15) | Yes   | Height of the component to set.<br>Unit: vp<br>The [Flex](./ts-container-flex.md), [Row](./ts-container-row.md), [Column](./ts-container-column.md) and [Stack](./ts-container-stack.md) components support all parameters in [LayoutPolicy](ts-types.md#layoutpolicy15).<br> The [RelativeContainer](./ts-container-relativecontainer.md), [FolderStack](./ts-container-folderstack.md), [Divider](./ts-basic-components-divider.md), and [Blank](./ts-basic-components-blank.md) components support the **matchParent** parameter in [LayoutPolicy](ts-types.md#layoutpolicy15).<br> The [GridRow](./ts-container-gridrow.md) and [GridCol](./ts-container-gridcol.md) components support the **fixAtIdealSize** parameter in [LayoutPolicy](ts-types.md#layoutpolicy15).|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## size

size(value: SizeOptions): T

Sets the width and height of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                             | Mandatory  | Description               |
| ----- | ------------------------------- | ---- | ----------------- |
| value | [SizeOptions](#sizeoptions) | Yes   | Size of the component to set.<br>Unit: vp|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## padding

padding(value: Padding | Length | LocalizedPadding): T

Sets the padding of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| value | [Padding](ts-types.md#padding) \|  [Length](ts-types.md#length) \|   [LocalizedPadding](ts-types.md#localizedpadding12)<sup>12+</sup>| Yes   | Padding of the component to set.<br>When the parameter is of the **Length** type, the four paddings take effect.<br>Default value: **0**<br>Unit: vp<br>When **padding** is set to a percentage, the width of the parent container is used as the basic value.|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## margin

margin(value: Margin | Length | LocalizedMargin): T

Sets the margin of the component.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory    | Description                                                        |
| ------ | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| value  | [Margin](ts-types.md#margin) \| [Length](ts-types.md#length) \| [LocalizedMargin](ts-types.md#localizedmargin12)<sup>12+</sup> | Yes| Margin of the component to set.<br>When the parameter is of the **Length** type, the four margins take effect.<br>Default value: **0**<br>Unit: vp<br>When **margin** is set to a percentage, the width of the parent container is used as the basic value. When child components are laid out along the cross axis of the [Row](./ts-container-row.md), [Column](./ts-container-column.md), or [Flex](./ts-container-flex.md) container, the cross axis size of the child components and the margins add up to the total size of the container.<br>For example, if the width of the **Column** container is 100, the width of the child component is 50, the left margin is 10, and the right margin is 20, then the actual horizontal offset of the child component is 10.|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## safeAreaPadding<sup>14+</sup>

safeAreaPadding(paddingValue: Padding | LengthMetrics | LocalizedPadding): T

Sets the safe area padding. This allows the container to add a component-level safe area for its child components to extend into. This attribute can be dynamically set using [attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier).

**Widget capability**: This API can be used in ArkTS widgets since API version 14.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| paddingValue | [Padding](ts-types.md#padding) \|  [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) \|   [LocalizedPadding](ts-types.md#localizedpadding12)| Yes   | Safe area padding.<br>Default value: **0**<br>Unit: vp|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

> **NOTE**
> 
> When parent and ancestor containers define component-level safe areas, child components can detect and utilize these areas, referred to as Accumulated Safe Area Expansion (SAE), which represents the maximum extendable length in each direction. When ancestor containers have contiguous **safeAreaPadding** (undivided by margin, border, or padding), SAE accumulates recursively outward until no adjacent outer **safeAreaPadding** exists or the recursion extends beyond the page container. System-level avoid areas (status bar, navigation bar, notch areas, and more**) are treated as the page container's inherent safeAreaPadding** and participate in SAE calculations. For details about the avoid areas, see [expandSafeArea](./ts-universal-attributes-expand-safe-area.md).
>
>These component-level safe areas can be leveraged by combining with other attributes. For example, setting the [ignoreLayoutSafeArea](./ts-universal-attributes-expand-safe-area.md) attribute on a child component allows it to extend its layout into the SAE region.

## layoutWeight

layoutWeight(value: number | string): T

Sets the weight of the component during layout. A component with this attribute set is allocated space along the main axis of its parent container ([Row](./ts-container-row.md), [Column](./ts-container-column.md), or [Flex](./ts-container-flex.md)) based on its specified weight.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                        | Mandatory     | Description                                      |
| ----- | -------------------------- | ------- | ---------------------------------------- |
| value | number \| string | Yes| Layout weight of the component.<br>When the parent container size is determined:<br>Elements without **layoutWeight** or with **layoutWeight** set to **0** take precedence in occupying space.<br> The remaining space on the main axis is then allocated proportionally among elements with a **layoutWeight** value greater than 0, ignoring their own size settings.<br>Default value: **0**<br>**NOTE**<br>This parameter is only effective in [Row](./ts-container-row.md), [Column](./ts-container-column.md), and [Flex](./ts-container-flex.md) container components.<br>The value can be a number greater than or equal to 0 or a string that can be converted to a number.<br>If any child component in a container has the **layoutWeight** attribute set to a value greater than 0, then child components will no longer be laid out based on **flexShrink** and **flexGrow**.|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

## constraintSize

constraintSize(value: ConstraintSizeOptions): T

Sets the constraint size of the component, which is used to limit the size range during component layout.

Since API version 10, this API supports the calc calculation feature.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| value | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Yes   | Constraint size of the component to set. **constraintSize** takes precedence over **width** and **height**. See **Impact of constraintSize on width/height**.<br>Default value:<br>{<br>minWidth: 0,<br>maxWidth: Infinity,<br>minHeight: 0,<br>maxHeight: Infinity<br>}<br>Unit: vp<br>|

**Return value**

| Type| Description|
| --- | --- |
|  T | Current component.|

**Impact of constraintSize(minWidth/maxWidth/minHeight/maxHeight) on width/height**

| Default Value                                     | Result                                      |
| ---------------------------------------- | ---------------------------------------- |
| \ | width=MAX(minWidth,MIN(maxWidth,width))<br>height=MAX(minHeight,MIN(maxHeight,height)) |
| maxWidth, maxHeight| width=MAX(minWidth,width)<br>height=MAX(minHeight,height) |
| minWidth, minHeight| width=MIN(maxWidth,width)<br>height=MIN(maxHeight,height) |
| width, height| If minWidth < maxWidth, the layout logic of the component takes effect, and the value range of **width** is [minWidth, maxWidth]. Otherwise, width = MAX(minWidth, maxWidth).<br>If minHeight < maxHeight, the layout logic of the component takes effect, and the value range of **height** is [minHeight, maxHeight]. Otherwise, height = MAX (minHeight, maxHeight).|
| width and maxWidth; height and maxHeight| width = minWidth<br>height = minHeight |
| width and minWidth; and height and minHeight| The layout logic of the component takes effect, and the value of **width** cannot be greater than that of **maxWidth**.<br>The layout logic of the component takes effect, and the value of **height** cannot be greater than that of **maxHeight**.|
| minWidth and maxWidth; minHeight and maxHeight| The width of the component is initially determined by the value of **width**, and it may be adjusted based on other layout attributes.<br>The height of the component is initially determined by the value of **height**, and it may be adjusted based on other layout attributes.|
| width, minWidth, and maxWidth| The layout restrictions passed by the parent container are used for layout.|
| height, minHeight, and maxHeight| The layout restrictions passed by the parent container are used for layout.|

## SizeOptions

Describes the width and height of a component during layout.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type                                      | Mandatory  | Description                                      |
| ----- | ---------------------------------------- | ---- | ---------------------------------------- |
| width  | [Length](ts-types.md#length) | No| Component width.|
| height | [Length](ts-types.md#length) | No| Component height.|

## ConstraintSizeOptions

Describes the size constraints of a component during layout.

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
>  In the [Row](./ts-container-row.md), [Column](./ts-container-column.md), and [RelativeContainer](./ts-container-relativecontainer.md) components, setting **width** and **height** to **auto** means that the size adapts to the size of their child components. In the [TextInput](./ts-basic-components-textinput.md) component, setting **width** to **auto** means that the width adapts to the width of the text content.

## Example

### Example 1: Setting the Component Width, Height, Margin, and Padding

This example demonstrates how to set the width, height, padding, and margin of a component.

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
          Row()
          .size({ width: '100%', height: '100%' })
          .backgroundColor(Color.Yellow)
        }
        .width(80)
        .height(80)
        .padding({ top: 5, left: 10, bottom: 15, right: 20 })
        .margin(20)
        .backgroundColor(Color.White)
      }.backgroundColor(Color.Blue)

      Text('constraintSize')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
      Text('this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text.this is a Text')
        .width('90%')
        .constraintSize({ maxWidth: 200 })

      Text('layoutWeight')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
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
      }
      .size({ width: '90%', height: 140 })
      .backgroundColor(0xAFEEEE)
      // calc calculation feature
      Text('calc:')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
      Text('calc test')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .backgroundColor(0xFFFAF0)
        .textAlign(TextAlign.Center)
        .margin('calc(25vp*2)')
        // If width or height is set to a percentage, the width or height of the parent container are used as the basic value.
        .size({ width: 'calc(90%)', height: 'calc(50vp + 10%)' })
    }
    .width('100%')
    .margin({ top: 5 })
  }
}
```

![size](figures/size.png)

### Example 2: Using LocalizedPadding and LocalizedMargin Types

This example demonstrates how to use **LocalizedPadding** and **LocalizedMargin** types to define the **padding** and **margin** attributes.

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI'

@Entry
@Component
struct SizeExample {
  build() {
    Column({ space: 10 }) {
      Text('margin and padding:')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
      Row() {
        // Set the width to 80, height to 80, top, bottom, start, and end paddings to 40, 20, 30, and 10, respectively (blue area), and top, bottom, start, and end margins to 5, 15, 10, and 20, respectively (white area).
        Row() {
          Row()
            .size({ width: '100%', height: '100%' })
            .backgroundColor(Color.Yellow)
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
      }
      .backgroundColor(Color.Blue)
    }
    .width('100%')
    .margin({ top: 5 })
  }
}
```

The following shows how the example is represented with left-to-right scripts.

![size](figures/size-ltr.png)

The following shows how the example is represented with right-to-left scripts.

![size](figures/size-rtl.png)

### Example 3: Setting Safe Area

This example demonstrates how to set a component-level safe area for a container.

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct SafeAreaPaddingExample {
  build() {
    Column() {
      Column() {
        Column()
          .width("100%")
          .height("100%")
          .backgroundColor(Color.Pink)
      }
      .width(200)
      .height(200)
      .backgroundColor(Color.Yellow)
      .borderWidth(10)
      .padding(10)
      .safeAreaPadding(LengthMetrics.vp(40))
    }
    .height('100%')
    .width('100%')
  }
}
```

![safeAreaPaddingExample](figures/safeAreaPaddingExample.png)

### Example 4: Using attributeModifier to Dynamically Set a Safe Area

This example demonstrates how to use **attributeModifier** to dynamically set a component-level safe area for a container.

```ts
// xxx.ets
class MyModifier implements AttributeModifier<CommonAttribute> {
  applyNormalAttribute(instance: CommonAttribute): void {
    instance.safeAreaPadding({
      left: 10,
      top: 20,
      right: 30,
      bottom: 40
    })
  }
}

@Entry
@Component
struct SafeAreaPaddingExample {
  @State modifier: MyModifier = new MyModifier()

  build() {
    Column() {
      Column() {
        Column()
          .width("100%")
          .height("100%")
          .backgroundColor(Color.Pink)
      }
      .width(200)
      .height(200)
      .backgroundColor(Color.Yellow)
      .borderWidth(10)
      .padding(10)
      .attributeModifier(this.modifier)
    }
    .height('100%')
    .width('100%')
  }
}
```

![safeAreaPaddingModifierExample](figures/safeAreaPaddingModifierExample.png)

### Example 5: Setting the Layout Policy

This example demonstrates how to set the layout policy for a container's size.

```ts
// xxx.ets
@Entry
@Component
struct LayoutPolicyExample {
  build() {
    Column() {
      Column() {
        // When matchParent is effective, the current component's size is equal to its parent component's content area size (180x180 vp) and not subject to its own constraintSize (150x150 vp), so the current component's size is 180x180 vp.
        Text("matchParent")
        Flex()
          .backgroundColor('rgb(0, 74, 175)')
          .width(LayoutPolicy.matchParent)
          .height(LayoutPolicy.matchParent)
          .constraintSize({ maxWidth: 150, maxHeight: 150 })

        // When wrapContent is effective, the current component's size is equal to its child component size (300x300 vp), but it cannot exceed the parent component's content size (180x180 vp) and is subject to its own constraintSize (250x250 vp), so the current component's size is 180x180 vp.
        Text("wrapContent")
        Row() {
          Flex()
            .width(300)
            .height(300)
        }
        .backgroundColor('rgb(39, 135, 217)')
        .width(LayoutPolicy.wrapContent)
        .height(LayoutPolicy.wrapContent)
        .constraintSize({ maxWidth: 250, maxHeight: 250 })

        // When fixAtIdealSize is effective, the current component's size is equal to its child component size (300x300 vp), it can exceed the parent component's content size (180x180 vp) but is subject to its own constraintSize (250x250 vp), so the current component's size is 250x250 vp.
        Text("fixAtIdealSize")

        Row() {
          Flex()
            .width(300)
            .height(300)
        }
        .backgroundColor('rgb(240, 250, 255)')
        .width(LayoutPolicy.fixAtIdealSize)
        .height(LayoutPolicy.fixAtIdealSize)
        .constraintSize({ maxWidth: 250, maxHeight: 250 })
      }
      .width(200)
      .height(200)
      .padding(10)
    }
    .width("100%")
    .height("100%")
  }
}
```

![layoutPolicyExample](figures/layoutPolicy_demo.jpg)
