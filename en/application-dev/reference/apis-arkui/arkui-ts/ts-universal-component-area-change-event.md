# Component Area Change Event

The area change event is triggered when the component's size, position, or any other attribute that may affect its display area changes.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> The **onAreaChange** callback is specific to the current component only. There is no strict execution order or guarantee of constraints for the **onAreaChange** callbacks on ancestor or descendant components.

## onAreaChange

onAreaChange(event: (oldValue: Area, newValue: Area) => void): T

Triggered when the component area changes in size or position due to layout updates. This event is not triggered for render attribute changes caused by re-rendering, such as changes of [translate](ts-universal-attributes-transformation.md#translate) and [offset](ts-types.md#offset).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| oldValue | [Area](ts-types.md#area8) | Yes  | Width and height of the target element as well as its coordinates relative to the parent element and the upper left corner of the page before the change.|
| newValue | [Area](ts-types.md#area8) | Yes  | Width and height of the target element as well as its coordinates relative to the parent element and the upper left corner of the page after the change.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct AreaExample {
  @State value: string = 'Text'
  @State sizeValue: string = ''

  build() {
    Column() {
      Text(this.value)
        .backgroundColor(Color.Green)
        .margin(30)
        .fontSize(20)
        .onClick(() => {
          this.value = this.value + 'Text'
        })
        .onAreaChange((oldValue: Area, newValue: Area) => {
          console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
          this.sizeValue = JSON.stringify(newValue)
        })
      Text('new area is: \n' + this.sizeValue).margin({ right: 30, left: 30 })
    }
    .width('100%').height('100%').margin({ top: 30 })
  }
}
```

![en-us_image_0000001189634870](figures/en-us_image_0000001189634870.gif)
