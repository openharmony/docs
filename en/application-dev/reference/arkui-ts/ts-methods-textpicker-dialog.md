# Text Picker Dialog Box

> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

You can display a text picker in a dialog box to allow users to select text from the given range.

## Required Permissions

None

## TextPickerDialog.show

show(options: TextPickerDialogOptions)

Shows a text picker in the given settings.

- TextPickerDialogOptions
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | range | string[] | Yes | - | Data selection range of the picker. |
  | selected | number | No | First element | Index value of the selected item in the range. |
  | defaultPickerItemHeight | number | No | - | Height of the default selected item in the picker. |
  | onAccept | (value: TextPickerResult) => void | No | - | Callback invoked when the OK button in the dialog box is clicked. |
  | onCancel | () => void | No | - | Triggered when the Cancel button in the dialog box is clicked. |
  | onChange | (value: TextPickerResult) => void | No | - | Callback invoked when the selected item in the picker changes. |

- TextPickerResult
  | Name | Type | Description | 
  | -------- | -------- | -------- |
  | value | string | Text of the selected item. | 
  | index | number | Index value of the selected item in the range. | 

## Example

```
@Entry
@Component
struct TextPickerDialogExample {
  @State select: number = 1
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TextPickerDialog").onClick(() => {
        TextPickerDialog.show({
          range: this.fruits,
          selected: this.select,
          onAccept: (value: TextPickerResult) => {
            console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))
            this.select = value.index
          },
          onCancel: () => {
            console.info("TextPickerDialog:onCancel()")
          },
          onChange: (value: TextPickerResult) => {
            console.info("TextPickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
