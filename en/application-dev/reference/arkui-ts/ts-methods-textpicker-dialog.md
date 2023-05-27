# Text Picker Dialog Box

A text picker dialog box is a dialog box that allows users to select text from the given range.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## TextPickerDialog.show

show(options?: TextPickerDialogOptions)

Shows a text picker in the given settings.

**TextPickerDialogOptions**

| Name| Type| Mandatory|  Description|
| -------- | -------- | -------- |  -------- |
| range | string[] \| [Resource](ts-types.md#resource)\|[TextPickerRangeContent](ts-basic-components-textpicker.md#textpickerrangecontent10)[]<sup>10+</sup> | Yes|  Data selection range of the picker. This parameter cannot be set to an empty array. If set to an empty array, it will not be displayed.|
| selected | number | No|  Index of the selected item.<br>Default value: **0**|
| value       | string           | No   | Text of the selected item. This parameter does not take effect when the **selected** parameter is set. If the value is not within the range, the first item in the range is used instead.|
| defaultPickerItemHeight | number \| string | No| Height of the picker item.|
| disappearTextStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width for the top and bottom items.|
| textStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width of all items except the top, bottom, and selected items.|
| selectedTextStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width of the selected item.|
| onAccept | (value: [TextPickerResult](#textpickerresult)) => void | No|  Callback invoked when the OK button in the dialog box is clicked.|
| onCancel | () => void | No| Callback invoked when the Cancel button in the dialog box is clicked.|
| onChange | (value: [TextPickerResult](#textpickerresult)) => void | No|  Callback invoked when the selected item changes.|

## TextPickerResult

| Name| Type| Description|
| -------- | -------- | -------- |
| value | string | Text of the selected item.<br>**NOTE**<br>For a text list or a list consisting of text and images, **value** indicates the text value of the selected item.<br>For an image list, **value** is empty.|
| index | number | Index of the selected item in the range.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct TextPickerDialogExample {
  @State select: number = 2
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4', 'banana5']

  build() {
    Column() {
      Button("TextPickerDialog")
        .margin(20)
        .onClick(() => {
          TextPickerDialog.show({
            range: this.fruits,
            selected: this.select,
            onAccept: (value: TextPickerResult) => {
              // Set select to the index of the item selected when the OK button is touched. In this way, when the text picker dialog box is displayed again, the selected item is the one last confirmed.
              this.select = value.index
              console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("TextPickerDialog:onCancel()")
            },
            onChange: (value: TextPickerResult) => {
              console.info("TextPickerDialog:onChange()" + JSON.stringify(value))
            }
          })
        })
    }.width('100%')
  }
}
```
