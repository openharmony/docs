# Date Picker Dialog Box

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

You can display a date or time picker in a dialog box to allow users to select a date or time from the given range.

## Required Permissions

None

## DatePickerDialog.show

show(options?: DatePickerDialogOption)

Shows a date or time picker in the given settings.

- DatePickerDialogOption parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | start | Date | No| Date('1970-1-1') | Start date of the picker.|
  | end | Date | No| Date('2100-12-31') | End date of the picker.|
  | selected | Date | No| Current system date or time| Date or time of the selected item in the picker. When **type** is set to **DatePickerType.Date**, this parameter indicates the date of the selected item. When **type** is set to **DatePickerType.Time**, this parameter indicates the time of the selected item.|
  | type | [DatePickerType](ts-basic-components-datepicker.md) | No| DatePickerType.Date | Picker type, which can be the date picker and time picker.|
  | lunar | boolean | No| false | Whether to display the lunar calendar.|
  | useMilitaryTime | boolean | No| false | Whether to display time in 24-hour format.|
  | onAccept | (value: [DatePickerResult](ts-basic-components-datepicker.md)) => void | No| - | Triggered when the OK button in the dialog box is clicked.|
  | onCancel | () => void | No| - | Triggered when the Cancel button in the dialog box is clicked.|
  | onChange | (value: [DatePickerResult](ts-basic-components-datepicker.md)) => void | No| - | Triggered when the selected item in the picker changes.|

## Example

### Date Picker Sample Code (With Lunar Calendar)
```
@Entry
@Component
struct DatePickerDialogExample01 {
  @State isLunar: boolean = true
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Date
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
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
```
@Entry
@Component
struct DatePickerDialogExample02 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Date
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
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
### Time Picker Sample Code (24-Hour Clock)
```
@Entry
@Component
struct DatePickerDialogExample03 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = true
  @State datePickerType: DatePickerType = DatePickerType.Time
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
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
### Time Picker Sample Code (12-Hour Clock)
```
@Entry
@Component
struct DatePickerDialogExample04 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Time
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
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
