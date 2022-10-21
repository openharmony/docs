# TimePicker

The **\<TimePicker>** component allows users to select a time from the given range.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TimePicker(options?: {selected?: Date})

Creates a time picker whose default time range is from 00:00 to 23:59.

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

### TimePickerResult
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
  private selectedTime: Date = new Date('7/22/2022 8:00:00')

  build() {
    Column() {
      TimePicker({
        selected: this.selectedTime,
      })
      .useMilitaryTime(true)
      .onChange((date: TimePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![en-us_image_0000001251292933](figures/en-us_image_0000001251292933.gif)
