# TimePicker

The **\<TimePicker>** component allows users to select a time from the given range.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TimePicker(options?: {selected?: Date})

Creates a time picker, which is in 24-hour format by default.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| selected | Date | No| Time of the selected item.<br>Default value: current system time|


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| useMilitaryTime | boolean | Whether to display time in 24-hour format. The value cannot be modified dynamically.<br>Default value: **false**|


## Events

| Name                                      | Description       |
| ---------------------------------------- | ----------- |
| onChange(callback: (value: TimePickerResult ) =&gt; void) | Triggered when a time is selected.|

## TimePickerResult

| Name    | Type  | Description     |
| ------ | ------ | ------- |
| hour   | number | Hour portion of the selected time.|
| minute | number | Minute portion of the selected time.|


## Example


### Time Picker

```ts
// xxx.ets
@Entry
@Component
struct TimePickerExample {
  @State isMilitaryTime: boolean = false
  private selectedTime: Date = new Date('2022-07-22T08:00:00')

  build() {
    Column() {
      Button ('Switch Time Format')
        .margin({ top: 30 })
        .onClick(() => {
          this.isMilitaryTime = !this.isMilitaryTime
        })
      TimePicker({
        selected: this.selectedTime,
      })
        .useMilitaryTime(this.isMilitaryTime)
        .onChange((value: TimePickerResult) => {
          this.selectedTime.setHours(value.hour, value.minute)
          console.info('select current date is: ' + JSON.stringify(value))
        })
    }.width('100%')
  }
}
```

![timePicker](figures/timePicker.gif)
