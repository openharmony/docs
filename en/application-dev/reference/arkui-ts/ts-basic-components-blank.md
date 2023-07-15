# Blank

The **\<Blank>** component is able to automatically fill the empty spaces in the container along the main axis. It works only when the parent component is **\<Row>**, **\<Column>**, or **\<Flex>**.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Blank(min?: number | string)

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| min | number \| string | No| Minimum size of the **\<Blank>** component in the container along the main axis.<br>Default value: **0**<br>**NOTE**<br>This parameter cannot be set in percentage. If the value is negative, the default value is used. If the minimum size is larger than the available space of the container, it is used as the component size, and the component extends beyond the container.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | Color to fill the empty spaces.<br>Default value: **Color.Transparent**<br>Since API version 9, this API is supported in ArkTS widgets.|

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example

### Example 1
The sample below shows how the **\<Blank>** component fills the empty spaces in the container in landscape and portrait modes.
```ts
// xxx.ets
@Entry
@Component
struct BlankExample {
  build() {
    Column() {
      Row() {
        Text('Bluetooth').fontSize(18)
        Blank()
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })
      }.width('100%').backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })
    }.backgroundColor(0xEFEFEF).padding(20)
  }
}
```

Portrait mode

![en-us_image_0000001256858407](figures/en-us_image_0000001256858407.gif)

Landscape mode

![en-us_image_0000001212378418](figures/en-us_image_0000001212378418.gif)


### Example 2
Set the **min** parameter when the width of the parent container of the **\<Blank>** component is not set.

```ts
// xxx.ets
@Entry
@Component
struct BlankExample {
  build() {
    Column({ space: 20 }) {
      // If the width of the parent container is not set, the \<Blank> component becomes invalid. In this case, you can set min to specify the minimum width of the \<Blank> component.
      Row() {
        Text('Bluetooth').fontSize(18)
        Blank().color(Color.Yellow)
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })

      Row() {
        Text('Bluetooth').fontSize(18)
        // Set the minimum width to 160.
        Blank('160').color(Color.Yellow)
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })

    }.backgroundColor(0xEFEFEF).padding(20).width('100%')
  }
}
```
If the width of the parent container is not set, set **min** to specify the minimum width of the **\<Blank>** component.

![blankmin](figures/blankmin.png)
