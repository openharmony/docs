# Text Picker Dialog Box

A text picker dialog box is a dialog box that allows users to select text from the given range.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## TextPickerDialog.show

show(options?: TextPickerDialogOptions)

Shows a text picker in the given settings.

- TextPickerDialogOptions
  | Name                    | Type                                     | Mandatory | Default Value | Description                              |
  | ----------------------- | ---------------------------------------- | --------- | ------------- | ---------------------------------------- |
  | range                   | string[] \| [Resource](ts-types.md#resource) | Yes       | -             | Data selection range of the picker.      |
  | selected                | number                                   | No        | 0             | Index of the selected item in the range. |
  | value                   | string                                   | No        | -             | Value of the selected item. This parameter does not take effect when the **selected** parameter is set. If the value is not within the range, the first item in the range is used instead. |
  | defaultPickerItemHeight | number \| string                         | No        | -             | Default height of an item in the picker. |
  | onAccept                | (value: TextPickerResult) => void        | No        | -             | Callback invoked when the OK button in the dialog box is clicked. |
  | onCancel                | () => void                               | No        | -             | Callback invoked when the Cancel button in the dialog box is clicked. |
  | onChange                | (value: TextPickerResult) => void        | No        | -             | Callback invoked when the selected item in the picker changes. |

- TextPickerResult
  | Name  | Type   | Description                              |
  | ----- | ------ | ---------------------------------------- |
  | value | string | Value of the selected item.              |
  | index | number | Index of the selected item in the range. |

## Example

```ts
// xxx.ets
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
