# Date Picker Dialog Box (DatePickerDialog)

A date picker dialog box is a dialog box that allows users to select a date from the given range.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [showDatePickerDialog](../apis/js-apis-arkui-UIContext.md#showdatepickerdialog) API in [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext) to obtain the UI context.

## DatePickerDialog.show

show(options?: DatePickerDialogOptions)

Shows a date picker dialog box.

**DatePickerDialogOptions**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| start | Date | No| Start date of the picker.<br>Default value: **Date('1970-1-1')**|
| end | Date | No| End date of the picker.<br>Default value: **Date('2100-12-31')**|
| selected | Date | No| Selected date.<br>Default value: current system date|
| lunar | boolean | No| Whether to display the lunar calendar.<br>Default value: **false**|
| showTime<sup>10+</sup> | boolean | No| Whether to display the time item.<br>Default value: **false**|
| useMilitaryTime<sup>10+</sup> | boolean | No| Whether to display time in 24-hour format.<br>Default value: **false**<br>**NOTE**<br>When in the 12-hour format, the AM/PM zone does not change depending on the hour portion.|
| disappearTextStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width for the top and bottom items.<br>Default value:<br>{<br>color: '#ff182431',<br>font: {<br>size: '14fp', <br>weight: FontWeight.Regular<br>}<br>} |
| textStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width of all items except the top, bottom, and selected items.<br>Default value:<br>{<br>color: '#ff182431',<br>font: {<br>size: '16fp', <br>weight: FontWeight.Regular<br>}<br>} |
| selectedTextStyle<sup>10+</sup> | [PickerTextStyle](ts-basic-components-datepicker.md#pickertextstyle10) | No| Font color, font size, and font width of the selected item.<br>Default value:<br>{<br>color: '#ff007dff',<br>font: {<br>size: '20vp', <br>weight: FontWeight.Medium<br>}<br>} |
| alignment<sup>10+</sup>  | [DialogAlignment](ts-methods-alert-dialog-box.md#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset<sup>10+</sup>     | [Offset](ts-types.md#offset) | No    | Offset of the dialog box based on the **alignment** settings.<br>Default value: **{ dx: 0 , dy: -56 }**|
| maskRect<sup>10+</sup>| [Rectangle](ts-methods-alert-dialog-box.md#rectangle10) | No    | Mask area of the dialog box. Events outside the mask area are transparently transmitted, and events within the mask area are not.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**|
| onAccept<sup>(deprecated)</sup> | (value: [DatePickerResult](ts-basic-components-datepicker.md#DatePickerResult)) => void | No| Callback invoked when the OK button in the dialog box is clicked.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 10. You are advised to use **onDateAccept** instead.|
| onCancel | () => void | No| Callback invoked when the Cancel button in the dialog box is clicked.|
| onChange<sup>(deprecated)</sup> | (value: [DatePickerResult](ts-basic-components-datepicker.md#DatePickerResult)) => void | No| Callback invoked when the selected item in the picker changes.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 10. You are advised to use **onDateChange** instead.|
| onDateAccept<sup>10+</sup> | (value:  Date) => void | No| Callback invoked when the OK button in the dialog box is clicked.<br>**NOTE**<br>When **showTime** is set to **true**, the hour and minute in the value returned by the callback are the hour and minute selected in the picker. Otherwise, the hour and minute are the hour and minute of the system time.|
| onDateChange<sup>10+</sup> | (value:  Date) => void | No| Callback invoked when the selected item in the picker changes.<br>**NOTE**<br>When **showTime** is set to **true**, the hour and minute in the value returned by the callback are the hour and minute selected in the picker. Otherwise, the hour and minute are the hour and minute of the system time.|

**Handling in the case of exceptions**

| Exception  | Result |
| -------- |  ------------------------------------------------------------ |
| The start date is later than the end date, and the selected date is not set.   | The start date, end date, and selected date are set to the default values. |
| The start date is later than the end date, and the selected date is earlier than the default start date.   | The start date and end date are set to the default values, and the selected date is set to the default start date. |
| The start date is later than the end date, and the selected date is later than the default end date.   | The start date and end date are set to the default values, and the selected date is set to the default end date. |
| The start date is later than the end date, and the selected date is within the range of the default start date and end date.   | The start date and end date are set to the default values, and the selected date is set to the specified value.|
| The selected date is earlier than the start date.   | The selected date is set to the start date. |
| The selected date is later than the end date.   | The selected date is set to the end date. |
| The start date is later than the current system date, and the selected date is not set.   | The selected date is set to the start date. |
| The end date is earlier than the current system date, and the selected date is not set.   | The selected date is set to the end date. |
| The set date is in invalid format, for example, **'1999-13-32'**.  | The default value is used. |
| The start date or end date is earlier than the valid date range.   | The start date or end date is set to the earliest date in the valid date range. |
| The start date or end date is later than the valid date range.   | The start date or end date is set to the latest date in the valid date range. |

The valid date range is from 1900-1-31 to 2100-12-31.

The exception detection and handling with the selected date comes after that with the start date and end date.

## Example

```ts
// xxx.ets
@Entry
@Component
struct DatePickerDialogExample {
  selectedDate: Date = new Date("2010-1-1")

  build() {
    Column() {
      Button("DatePickerDialog")
        .margin(20)
        .onClick(() => {
          DatePickerDialog.show({
            start: new Date("2000-1-1"),
            end: new Date("2100-12-31"),
            selected: this.selectedDate,
            showTime:true,
            useMilitaryTime:false,
            disappearTextStyle: {color: Color.Pink, font: {size: '22fp', weight: FontWeight.Bold}},
            textStyle: {color: '#ff00ff00', font: {size: '18fp', weight: FontWeight.Normal}},
            selectedTextStyle: {color: '#ff182431', font: {size: '14fp', weight: FontWeight.Regular}},
            onDateAccept: (value: Date) => {
              // Use the setFullYear method to set the date when the OK button is touched. In this way, when the date picker dialog box is displayed again, the selected date is the date last confirmed.
              this.selectedDate = value
              console.info("DatePickerDialog:onDateAccept()" + value.toString())
            },
            onCancel: () => {
              console.info("DatePickerDialog:onCancel()")
            },
            onDateChange: (value: Date) => {
              console.info("DatePickerDialog:onDateChange()" + value.toString())
            }
          })
        })

      Button("Lunar DatePickerDialog")
        .margin(20)
        .onClick(() => {
          DatePickerDialog.show({
            start: new Date("2000-1-1"),
            end: new Date("2100-12-31"),
            selected: this.selectedDate,
            lunar: true,
            disappearTextStyle: {color: Color.Pink, font: {size: '22fp', weight: FontWeight.Bold}},
            textStyle: {color: '#ff00ff00', font: {size: '18fp', weight: FontWeight.Normal}},
            selectedTextStyle: {color: '#ff182431', font: {size: '14fp', weight: FontWeight.Regular}},
            onDateAccept: (value: Date) => {
              this.selectedDate = value
              console.info("DatePickerDialog:onDateAccept()" + value.toString())
            },
            onCancel: () => {
              console.info("DatePickerDialog:onCancel()")
            },
            onDateChange: (value: Date) => {
              console.info("DatePickerDialog:onDateChange()" + value.toString())
            }
          })
        })
    }.width('100%')
  }
}
```

![DataPickerDialog](figures/DatePickerDialogApi10.gif)
