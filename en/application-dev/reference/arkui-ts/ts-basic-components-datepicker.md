# DatePicker


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;DatePicker&gt;** component allows users to select date and time.


## Required Permissions

None


## Child Component

None


## APIs

DatePicker(value:{start?: Date, end?: Date, selected?: Date, type?: DatePickerType})

Creates a date picker that allows users to select a date or time within the specified range.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | start | Date | No | Date('1970-1-1') | Start&nbsp;date&nbsp;of&nbsp;the&nbsp;date&nbsp;picker. | 
  | end | Date | No | Date('2100-12-31') | End&nbsp;date&nbsp;of&nbsp;the&nbsp;date&nbsp;picker. | 
  | selected | Date | No | Current&nbsp;system&nbsp;date&nbsp;or&nbsp;time | Selected&nbsp;date&nbsp;when&nbsp;**type**&nbsp;is&nbsp;set&nbsp;to&nbsp;**DatePickerType.Date**&nbsp;and&nbsp;selected&nbsp;time&nbsp;when&nbsp;**type**&nbsp;is&nbsp;set&nbsp;to&nbsp;**DatePickerType.Time**. | 
  | type | DatePickerType | No | DatePickerType.Date | Picker&nbsp;type,&nbsp;which&nbsp;can&nbsp;be&nbsp;date&nbsp;picker&nbsp;and&nbsp;time&nbsp;picker.&nbsp;The&nbsp;date&nbsp;picker&nbsp;is&nbsp;used&nbsp;by&nbsp;default. | 

- DatePickerType enums
    | Name | Description | 
  | -------- | -------- |
  | Date | Date&nbsp;picker. | 
  | Time | Time&nbsp;picker. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- |-------- |
| lunar | boolean | false | Whether&nbsp;to&nbsp;display&nbsp;the&nbsp;lunar&nbsp;calendar.<br/>-&nbsp;**true**:&nbsp;The&nbsp;lunar&nbsp;calendar&nbsp;is&nbsp;displayed.<br/>-&nbsp;**false**:&nbsp;The&nbsp;lunar&nbsp;calendar&nbsp;is&nbsp;not&nbsp;displayed. | 
| useMilitaryTime | boolean | false | Whether&nbsp;the&nbsp;display&nbsp;time&nbsp;is&nbsp;in&nbsp;24-hour&nbsp;format. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;DatePickerResult)&nbsp;=&gt;&nbsp;void) | This&nbsp;event&nbsp;is&nbsp;triggered&nbsp;when&nbsp;a&nbsp;date&nbsp;or&nbsp;time&nbsp;is&nbsp;selected. | 

- DatePickerResult object description
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | year | number | Year&nbsp;of&nbsp;the&nbsp;selected&nbsp;date&nbsp;(when&nbsp;**type**&nbsp;is&nbsp;**DatePickerType.Date**). | 
  | month | number | Month&nbsp;of&nbsp;the&nbsp;selected&nbsp;date&nbsp;(when&nbsp;**type**&nbsp;is&nbsp;**DatePickerType.Date**). | 
  | day | number | Date&nbsp;of&nbsp;the&nbsp;selected&nbsp;date&nbsp;(when&nbsp;**type**&nbsp;is&nbsp;**DatePickerType.Date**). | 
  | hour | number | Hour&nbsp;portion&nbsp;of&nbsp;the&nbsp;selected&nbsp;time&nbsp;(when&nbsp;**type**&nbsp;is&nbsp;**DatePickerType.Time**). | 
  | minute | number | Minute&nbsp;portion&nbsp;of&nbsp;the&nbsp;selected&nbsp;time&nbsp;(when&nbsp;**type**&nbsp;is&nbsp;**DatePickerType.Time**). | 


## Example


### Date Picker (with Lunar Calendar)


```
@Entry
@Component
struct DatePickerExample01 {
  private selectedDate: Date = new Date('2021-08-08')

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2200-1-1'),
        selected: this.selectedDate,
        type: DatePickerType.Date
      })
      .lunar(true)
      .onChange((date: DatePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![en-us_image_0000001211898486](figures/en-us_image_0000001211898486.gif)


### Date Picker (Without Lunar Calendar)


```
@Entry
@Component
struct DatePickerExample02 {
  private selectedDate: Date = new Date('2021-08-08')

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2200-1-1'),
        selected: this.selectedDate,
        type: DatePickerType.Date
      })
      .lunar(false)
      .onChange((date: DatePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![en-us_image_0000001257138355](figures/en-us_image_0000001257138355.gif)


### Time Picker


```
@Entry
@Component
struct DatePickerExample03 {
  private selectedTime: Date = new Date('2021-9-29 08:00:00')

  build() {
    Column() {
      DatePicker({
        start: new Date('00:00:00'),
        end: new Date('23:59:59'),
        selected: this.selectedTime,
        type: DatePickerType.Time
      })
      .useMilitaryTime(true)
      .onChange((date: DatePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![en-us_image_0000001256858401](figures/en-us_image_0000001256858401.gif)
