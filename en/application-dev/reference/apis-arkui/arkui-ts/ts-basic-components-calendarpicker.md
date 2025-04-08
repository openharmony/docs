# CalendarPicker

The **CalendarPicker** component provides a drop-down calendar for users to select a date.

>  **NOTE**
>
>  This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported

## APIs

CalendarPicker(options?: CalendarOptions)

Creates a calendar picker.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                       | Mandatory| Description                      |
| ------- | ------------------------------------------- | ---- | -------------------------- |
| options | [CalendarOptions](#calendaroptions) | No  | Parameters of the calendar picker.|

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### edgeAlign

edgeAlign(alignType: CalendarAlign, offset?: Offset)

How the picker is aligned with the entry component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                   | Mandatory| Description                                                        |
| --------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| alignType | [CalendarAlign](#calendaralign) | Yes  | Alignment type.<br>Default value: **CalendarAlign.END**                |
| offset    | [Offset](ts-types.md#offset)            | No  | Offset of the picker relative to the entry component after alignment based on the specified alignment type.<br>Default value: **{dx: 0, dy: 0}**|

### edgeAlign<sup>16+</sup>

edgeAlign(alignType: Optional\<CalendarAlign>, offset?: Offset)

How the picker is aligned with the entry component. Compared to [edgeAlign](#edgealign), this API supports the **undefined** type for the **alignType** parameter.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| alignType | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[CalendarAlign](#calendaralign)> | Yes  | Alignment type.<br>If **alignType** is set to **undefined**, the default value **CalendarAlign.END** is used.|
| offset    | [Offset](ts-types.md#offset)                                 | No  | Offset of the picker relative to the entry component after alignment based on the specified alignment type.<br>Default value: **{dx: 0, dy: 0}**|

### textStyle

textStyle(value: PickerTextStyle)

Sets the font color, font size, and font weight in the entry area.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [PickerTextStyle](./ts-basic-components-datepicker.md#pickertextstyle10) | Yes  | Font color, font size, and font weight in the entry area.<br>Default value:<br>{<br>color: '#ff182431',<br>font: {<br>size: '16fp', <br>weight: FontWeight.Regular<br>}<br>} |

### textStyle<sup>16+</sup>

textStyle(style: Optional\<PickerTextStyle>)

Sets the font color, font size, and font weight in the entry area. Compared to [textStyle](#textstyle), this API supports the **undefined** type for the **style** parameter.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[PickerTextStyle](./ts-basic-components-datepicker.md#pickertextstyle10)> | Yes  | Font color, font size, and font weight in the entry area.<br>If **style** is set to **undefined**, the default value is used:<br>{<br>color: '#ff182431',<br>font: {<br>size: '16fp', <br>weight: FontWeight.Regular<br>}<br>} |

### markToday<sup>16+</sup>

markToday(enabled: boolean)

Sets whether to highlight the current system date.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| enabled  | boolean | Yes  | Whether to highlight the current system date.<br>Default value: **false**<br> The value **true** means to highlight the current system date, and **false** means the opposite.|

## Events

In addition to the [universal events](ts-component-general-events.md), the following events are supported.

### onChange

onChange(callback: Callback\<Date>)

Triggered when a date is selected.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| callback | [Callback](ts-types.md#callback12)\<Date> | Yes  | Selected date value|

### onChange<sup>16+</sup>

onChange(callback: Optional\<Callback\<Date>>)

Triggered when a date is selected. Compared to [onChange](#onchange), this API supports the **undefined** type for the **callback** parameter.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Callback](ts-types.md#callback12)\<Date>> | Yes  | Selected date value<br>If **callback** is set to **undefined**, the callback function is not used.|

##  CalendarOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type      | Mandatory       | Description                           |
| ----------- | ---------- | ------| --------------------------------- |
| hintRadius | number \| [Resource](ts-types.md#resource) | No   | Style of the background of the selected state.<br>Default value: The background is a circle.<br>**NOTE**<br>If the value is **0**, the background is a rectangle with square corners. If the value is in the 0–16 range, the background is a rectangle with rounded corners. If the value is greater than or equal to 16, the background is a circle.|
| selected | Date | No   | Date of the selected item. If the value is not set or does not comply with the date format specifications, the default value will be used.<br>Default value: current system date|
| start<sup>16+</sup> | Date | No   | Start date.|
| end<sup>16+</sup> | Date | No   | End date.|
| disabledDateRange<sup>16+</sup> | DateRange[] | No   | Disabled date range.<br>**NOTE**<br>1. If the start date or end date within a date range is invalid, the entire date range does not take effect.<br>2. If the end date is earlier than the start date within a date range, the entire date range does not take effect.<br>3. When users select a date and adjust it with the up or down arrow keys, the system skips over all dates in the disabled date range.|

**Rules for setting start and end**

| Scenario  | Description |
| -------- |  ------------------------------------------------------------ |
| The start date is later than the end date.   | Both start and end dates are invalid, and the selected date is the default value. |
| The selected date is earlier than the start date.   | The selected date is set to the start date. |
| The selected date is later than the end date.   | The selected date is set to the end date. |
| The start date is later than the current system date, and the selected date is not set.   | The selected date is set to the start date. |
| The end date is earlier than the current system date, and the selected date is not set.   | The selected date is set to the end date. |
| The set date is in invalid format, for example, **'1999-13-32'**.| The start or end date setting is invalid, and the selected date is the default value. |

## CalendarAlign

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Description                    |
| ------ | ------------------------ |
| START  | The picker is left aligned with the entry component.  |
| CENTER | The picker is center aligned with the entry component.|
| END    | The picker is right aligned with the entry component.  |

## Example
### Example 1: Implementing a Calendar Picker

This example shows how to implement a calendar picker component.

```ts
// xxx.ets
@Entry
@Component
struct CalendarPickerExample {
  private selectedDate: Date = new Date('2024-03-05')

  build() {
    Column() {
      Column() {
        CalendarPicker({ hintRadius: 10, selected: this.selectedDate })
          .edgeAlign(CalendarAlign.END)
          .textStyle({ color: "#ff182431", font: { size: 20, weight: FontWeight.Normal } })
          .margin(10)
          .onChange((value) => {
            console.info("CalendarPicker onChange:" + JSON.stringify(value))
          })
      }.alignItems(HorizontalAlign.End).width("100%")

      Text('Calendar picker').fontSize(30)
    }.width('100%').margin({ top: 350 })
  }
}
```

![CalendarPicker](figures/CalendarPicker.gif)

### Example 2: Setting Start and End Dates

This example demonstrates how to set the start and end dates for the calendar picker using **start** and **end**.

```ts
// xxx.ets
@Entry
@Component
struct CalendarPickerExample {
  private selectedDate: Date = new Date('2025-01-15')
  private startDate: Date = new Date('2025-01-05')
  private endDate: Date = new Date('2025-01-25')

  build() {
    Column() {
      Column() {
        CalendarPicker({ hintRadius: 10, selected: this.selectedDate, start: this.startDate, end: this.endDate })
          .edgeAlign(CalendarAlign.END)
          .textStyle({ color: "#ff182431", font: { size: 20, weight: FontWeight.Normal } })
          .margin(10)
          .onChange((value) => {
            console.info("CalendarPicker onChange:" + JSON.stringify(value))
          })
      }.alignItems(HorizontalAlign.End).width("100%")
    }.width('100%').margin({ top: 350 })
  }
}
```



### Example 3: Highlighting the Current System Date and Disabling a Specific Date Range

This example shows how to highlight the current system date using **markToday** and disable a specific date range using **disabledDateRange**.

```ts
// xxx.ets
@Entry
@Component
struct CalendarPickerExample {
  private disabledDateRange: DateRange[] = [
    { start: new Date('2025-01-01'), end: new Date('2025-01-02') },
    { start: new Date('2025-01-09'), end: new Date('2025-01-10') },
    { start: new Date('2025-01-15'), end: new Date('2025-01-16') },
    { start: new Date('2025-01-19'), end: new Date('2025-01-19') },
    { start: new Date('2025-01-22'), end: new Date('2025-01-25') }
  ]

  build() {
    Column() {
      CalendarPicker({ disabledDateRange: this.disabledDateRange })
        .margin(10)
        .markToday(true)
        .onChange((value) => {
          console.info("CalendarPicker onChange:" + JSON.stringify(value))
        })
    }.alignItems(HorizontalAlign.End).width('100%')
  }
}
```


