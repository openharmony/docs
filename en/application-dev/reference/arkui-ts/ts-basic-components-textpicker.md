# TextPicker

The **\<TextPicker>** component allows users to scroll to select text.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TextPicker(options?: {range: string[]|Resource, selected?: number, value?: string})

Creates a text picker based on the selection range specified by **range**.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| range | string[] \| [Resource](ts-types.md#resource) | Yes| Data selection range of the picker. This parameter cannot be set to an empty array. If it is dynamically changed to an empty array, the current value remains displayed.|
| selected | number | No| Index of the default item in the range.<br>Default value: **0**|
| value | string | No| Value of the default item in the range. The priority of this parameter is lower than that of **selected**.<br>Default value: value of the first item|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| defaultPickerItemHeight | number \| string | Height of each item in the picker.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name| Description|
| -------- | -------- |
| onAccept(callback: (value: string, index: number) => void) | Triggered when the OK button in the dialog box is clicked.<br><br>- **value**: value of the selected item.<br>- **index**: index of the selected item.<br>**NOTE**<br>This event can be triggered only in the [text picker dialog box](ts-methods-textpicker-dialog.md).|
| onCancel(callback: () => void) | Triggered when the Cancel button in the dialog box is clicked.<br>**NOTE**<br>This event can be triggered only in the [text picker dialog box](ts-methods-textpicker-dialog.md).|
| onChange(callback: (value: string, index: number) =&gt; void) | Triggered when an item in the picker is selected.<br>- **value**: value of the selected item.<br>**NOTE**<br>For a text list or a list consisting of text and images, **value** indicates the text value of the selected item. For an image list, **value** is empty.<br>- **index**: index of the selected item.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct TextPickerExample {
  private select: number = 1
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']

  build() {
    Column() {
      TextPicker({ range: this.fruits, selected: this.select })
        .onChange((value: string, index: number) => {
          console.info('Picker item changed, value: ' + value + ', index: ' + index)
        })
    }
  }
}
```

![en-us_image_0000001257058417](figures/en-us_image_0000001257058417.png)
