# Time Picker Dialog Box

A time picker dialog box is a dialog box that allows users to select a time from the given range, which is from 00:00 to 23:59 by default.

>  **NOTE**
>
>  The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None

## TimePickerDialog.show

show(options?: TimePickerDialogOptions)

Shows a time picker dialog box.

- TimePickerDialogOptions
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | selected | Date | No| Current system time| Time of the selected item.|
  | useMilitaryTime | boolean | No| false | Whether to display time in 24-hour format.|
  | onAccept | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult)) => void | No| - | Callback invoked when the OK button in the dialog box is clicked.|
  | onCancel | () => void | No| - | Callback invoked when the Cancel button in the dialog box is clicked.|
  | onChange | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult)) => void | No| - | Callback invoked when the selected item in the picker changes.|

## Example

### Time Picker Sample Code (24-Hour Clock)
```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample01 {
  @State isUseMilitaryTime: boolean = true

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TimePickerDialog").onClick(() => {
        TimePickerDialog.show({
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: TimePickerResult) => {
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
    }
  }
}
```
### Time Picker Sample Code (12-Hour Clock)
```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample02 {
  @State isUseMilitaryTime: boolean = false

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TimePickerDialog").onClick(() => {
        TimePickerDialog.show({
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: TimePickerResult) => {
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
    }
  }
}
```
