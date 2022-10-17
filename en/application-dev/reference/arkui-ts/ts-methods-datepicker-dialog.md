# Date Picker Dialog Box

A date picker dialog box is a dialog box that allows users to select a date from the given range.

>  **NOTE**
>
>  The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## DatePickerDialog.show

show(options?: DatePickerDialogOptions)

Shows a date picker dialog box.

- DatePickerDialogOptions
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | start | Date | No| Date('1970-1-1') | Start date of the picker.|
  | end | Date | No| Date('2100-12-31') | End date of the picker.|
  | selected | Date | No| Current system date| Date of the selected item.|
  | lunar | boolean | No| false | Whether to display the lunar calendar.|
  | onAccept | (value: [DatePickerResult](ts-basic-components-datepicker.md#DatePickerResult)) => void | No| - | Callback invoked when the OK button in the dialog box is clicked.|
  | onCancel | () => void | No| - | Callback invoked when the Cancel button in the dialog box is clicked.|
  | onChange | (value: [DatePickerResult](ts-basic-components-datepicker.md#DatePickerResult)) => void | No| - | Callback invoked when the selected item in the picker changes.|

## Example

### Date Picker Sample Code (With Lunar Calendar)
```ts
// xxx.ets
@Entry
@Component
struct DatePickerDialogExample01 {
  @State isLunar: boolean = true
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          lunar: this.isLunar,
          onAccept: (value: DatePickerResult) => {
            this.selectedDate.setFullYear(value.year, value.month, value.day)
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
### Date Picker Sample Code (No Lunar Calendar)
```ts
// xxx.ets
@Entry
@Component
struct DatePickerDialogExample02 {
  @State isLunar: boolean = false
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          lunar: this.isLunar,
          onAccept: (value: DatePickerResult) => {
            this.selectedDate.setFullYear(value.year, value.month, value.day)
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
