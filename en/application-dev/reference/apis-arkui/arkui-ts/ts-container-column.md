# Column

The **Column** component lays out child components vertically.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

### Column
Column(options?: ColumnOptions)

Creates a vertical linear layout container. You can set the spacing between child components, which can be of type number or string.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [ColumnOptions](#columnoptions14) | No| Vertical spacing between two adjacent child components.|

### Column<sup>16+</sup>
Column(options?: ColumnOptions | ColumnOptionsV2)

Creates a vertical linear layout container. You can set the spacing between child components, which can be of type number, string, or Resource.

**Widget capability**: This API can be used in ArkTS widgets since API version 16.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [ColumnOptions](#columnoptions14) \| [ColumnOptionsV2](#columnoptionsv216) | No| Vertical spacing between two adjacent child components.|

## ColumnOptions<sup>14+</sup>

Defines the spacing properties for child components used for constructing a **Column** component.

**Widget capability**: This API can be used in ArkTS widgets since API version 14.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| space | string \| number | No| Vertical spacing between two adjacent child components.<br>This parameter does not take effect if the value specified is a negative number, or if [justifyContent](ts-container-column.md#justifycontent8) is set to **FlexAlign.SpaceBetween**, **FlexAlign.SpaceAround**, or **FlexAlign.SpaceEvenly**<br>Default value: **0**<br>Unit: vp<br>**NOTE**<br>The value of **space** can be a number greater than or equal to 0 or a string that can be converted to a number.|

## ColumnOptionsV2<sup>16+</sup>

Defines the spacing properties for child components used for constructing a **Column** component.

**Widget capability**: This API can be used in ArkTS widgets since API version 16.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| space | [SpaceType](#spacetype16) | No| Vertical spacing between two adjacent child components.<br>This parameter does not take effect if the value specified is a negative number, or if **justifyContent** is set to **FlexAlign.SpaceBetween**, **FlexAlign.SpaceAround**, or **FlexAlign.SpaceEvenly**.<br>Default value: **0**, in vp<br>**NOTE**<br>The value of **space** can be a number greater than or equal to 0, a string that can be converted to a number, or a Resource type that can be converted to a number.|

## SpaceType<sup>16+</sup>

type SpaceType = number | string | Resource

Describes the supported data types for the **space** parameter in the constructors of **Row** and **Column** components. The type is a union of the following types.

|Type|Description|
|---|---|
|number|Represents a numeric value. It can take any numerical value.|
|string|Represents a string value. It can take any string value.|
|[Resource](ts-types.md#resource)|Represents a resource reference type. It can take values from system resources or application resources.|

**Atomic service API**: This API can be used in atomic services since API version 16.

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### alignItems

alignItems(value: HorizontalAlign)

Alignment mode of the child components in the horizontal direction.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [HorizontalAlign](ts-appendix-enums.md#horizontalalign) | Yes  | Alignment mode of child components in the horizontal direction.<br>Default value: **HorizontalAlign.Center**|

### justifyContent<sup>8+</sup>

justifyContent(value: FlexAlign)

Alignment mode of the child components in the vertical direction.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                       | Mandatory| Description                                                      |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| value  | [FlexAlign](ts-appendix-enums.md#flexalign) | Yes  | Alignment mode of child components in the vertical direction.<br>Default value: **FlexAlign.Start**|

>  **NOTE**
>
>  During column layout, child components do not shrink if [flexShrink](ts-universal-attributes-flex-layout.md#flexshrink) is not set for them. In this case, the total size of the child components on the main axis can exceed the size of the container on the main axis.

### reverse<sup>12+</sup>

reverse(isReversed: Optional\<boolean\>)

Sets whether to reverse the arrangement of child components on the main axis (vertical direction).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                       | Mandatory| Description                                                      |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| isReversed  | Optional\<boolean\> | Yes  | Whether to reverse the arrangement of child components on the main axis (vertical direction).<br>Default value: **true**|

>  **NOTE**
>
>  If the **reverse** attribute is not set, the arrangement on the main axis remains in the normal order. If the attribute is set to **undefined**, it defaults to **true**, which reverses the arrangement on the main axis.<br>The **direction** attribute only changes the cross axis direction of the column and does not impact the main axis direction. Therefore, it is independent of the **reverse** attribute.

## Events

The [universal events](ts-component-general-events.md) are supported.

## Example

This example demonstrates how to set horizontal layout properties, such as spacing and alignment, using the **Column** component.

```json
// resources/base/element/string.json
{
  "string": [
    {
      "name": "stringSpace",
      "value": "5"
    }
  ]
}
```

```ts
// xxx.ets
@Entry
@Component
struct ColumnExample {
  build() {
    Column({ space: 5 }) {
      // Set the vertical spacing between two adjacent child components to 5.
      Text('space').width('90%')
      Column({ space: 5 }) {
        Column().width('100%').height(30).backgroundColor(0xAFEEEE)
        Column().width('100%').height(30).backgroundColor(0x00FFFF)
      }.width('90%').height(100).border({ width: 1 })

      // Set the spacing between child elements using the Resource type.
      Text('Resource space').width('90%')
      Column({ space: $r("app.string.stringSpace") }) {
        Column().width('100%').height(30).backgroundColor(0xAFEEEE)
        Column().width('100%').height(30).backgroundColor(0x00FFFF)
      }.width('90%').height(100).border({ width: 1 })

      // Set the alignment mode of the child components in the horizontal direction.
      Text('alignItems(Start)').width('90%')
      Column() {
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)
        Column().width('50%').height(30).backgroundColor(0x00FFFF)
      }.alignItems(HorizontalAlign.Start).width('90%').border({ width: 1 })

      Text('alignItems(End)').width('90%')
      Column() {
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)
        Column().width('50%').height(30).backgroundColor(0x00FFFF)
      }.alignItems(HorizontalAlign.End).width('90%').border({ width: 1 })

      Text('alignItems(Center)').width('90%')
      Column() {
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)
        Column().width('50%').height(30).backgroundColor(0x00FFFF)
      }.alignItems(HorizontalAlign.Center).width('90%').border({ width: 1 })

      // Set the alignment mode of the child components in the vertical direction.
      Text('justifyContent(Center)').width('90%')
      Column() {
        Column().width('90%').height(30).backgroundColor(0xAFEEEE)
        Column().width('90%').height(30).backgroundColor(0x00FFFF)
      }.height(100).border({ width: 1 }).justifyContent(FlexAlign.Center)

      Text('justifyContent(End)').width('90%')
      Column() {
        Column().width('90%').height(30).backgroundColor(0xAFEEEE)
        Column().width('90%').height(30).backgroundColor(0x00FFFF)
      }.height(100).border({ width: 1 }).justifyContent(FlexAlign.End)
    }.width('100%').padding({ top: 5 })
  }
}
```

![column](figures/column.png)
