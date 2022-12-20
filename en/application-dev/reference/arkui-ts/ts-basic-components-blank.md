# Blank

The **\<Blank>** component is able to automatically fill the empty spaces in the container along the main axis. It is valid only when the parent container is **\<Row>** or **\<Column>**.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Blank(min?: number | string)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| min | number \| string | No| Minimum size of the **\<Blank>** component in the container along the main axis.<br>Default value: **0**|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | Color to fill the empty spaces.|


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
        Toggle({ type: ToggleType.Switch })
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
        Toggle({ type: ToggleType.Switch })
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })

      Row() {
        Text('Bluetooth').fontSize(18)
        // Set the minimum width to 160.
        Blank('160').color(Color.Yellow)
        Toggle({ type: ToggleType.Switch })
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })
      
    }.backgroundColor(0xEFEFEF).padding(20).width('100%')
  }
}
```
If the width of the parent container is not set, set **min** to specify the minimum width of the **\<Blank>** component. 

![blankmin](figures/blankmin.png)
