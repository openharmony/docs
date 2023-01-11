# Time Picker Dialog Box

A time picker dialog box is a dialog box that allows users to select a time from the 24-hour range through scrolling.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## TimePickerDialog.show

show(options?: TimePickerDialogOptions)

Shows a time picker dialog box.

**TimePickerDialogOptions**


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| selected | Date | No| Selected time.<br>Default value: current system time|
| useMilitaryTime | boolean | No| Whether to display time in 24-hour format. The 12-hour format is used by default.<br>Default value: **false**|
| onAccept | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult)) => void | No| Callback invoked when the OK button in the dialog box is clicked.|
| onCancel | () => void | No| Callback invoked when the Cancel button in the dialog box is clicked.|
| onChange | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult)) => void | No| Callback invoked when the selected time changes.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample {
  private selectTime: Date = new Date('2020-12-25T08:30:00')

  build() {
    Column() {
      Button ("TimePickerDialog 12-hour format")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show({
            selected: this.selectTime,
            onAccept: (value: TimePickerResult) => {
              //Set selectTime to the time when the OK button is clicked. In this way, when the dialog box is displayed again, the selected time is the time when the operation was confirmed last time.
              this.selectTime.setHours(value.hour, value.minute)
              console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("TimePickerDialog:onCancel()")
            },
            onChange: (value: TimePickerResult) => {
              console.info("TimePickerDialog:onChange()" + JSON.stringify(value))
            }
          })
        })
      Button ("TimePickerDialog 24-hour format")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show({
            selected: this.selectTime,
            useMilitaryTime: true,
            onAccept: (value: TimePickerResult) => {
              this.selectTime.setHours(value.hour, value.minute)
              console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("TimePickerDialog:onCancel()")
            },
            onChange: (value: TimePickerResult) => {
              console.info("TimePickerDialog:onChange()" + JSON.stringify(value))
            }
          })
        })
    }.width('100%')
  }
}
```
