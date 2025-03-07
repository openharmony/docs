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

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### edgeAlign

edgeAlign(alignType: CalendarAlign, offset?: Offset)

How the picker is aligned with the entry component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                   | Mandatory| Description                                                        |
| --------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| alignType | [CalendarAlign](#calendaralign) | Yes  | Alignment type.<br>Default value: **CalendarAlign.END**               |
| offset    | [Offset](ts-types.md#offset)            | No  | Offset of the picker relative to the entry component after alignment based on the specified alignment type.<br>Default value: **{dx: 0, dy: 0}**|

### textStyle

textStyle(value: PickerTextStyle)

Sets the font color, font size, and font weight in the entry area.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [PickerTextStyle](./ts-basic-components-datepicker.md#pickertextstyle10) | Yes  | Font color, font size, and font weight in the entry area.<br>Default value:<br>{<br>color: '#ff182431',<br>font: {<br>size: '16fp', <br>weight: FontWeight.Regular<br>}<br>} |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onChange

onChange(callback: (value: Date) => void)

Triggered when a date is selected.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| value  | Date | Yes  | Selected date value|

##  CalendarOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type      | Mandatory       | Description                           |
| ----------- | ---------- | ------| --------------------------------- |
| hintRadius | number \| [Resource](ts-types.md#resource) | No   | Style of the background of the selected state.<br>Default value: The background is a circle.<br>**NOTE**<br>If the value is **0**, the background is a rectangle with square corners. If the value is in the 0–16 range, the background is a rectangle with rounded corners. If the value is equal to or greater than 16, the background is a circle.|
| selected | Date | No   | Date of the selected item. If the value is not set or does not comply with the date format specifications, the default value will be used.<br>Default value: current system date|

## CalendarAlign

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Description                    |
| ------ | ------------------------ |
| START  | The picker is left aligned with the entry component.  |
| CENTER | The picker is center aligned with the entry component.|
| END    | The picker is right aligned with the entry component.  |

## Example

```ts
// xxx.ets
@Entry
@Component
struct CalendarPickerExample {
  private selectedDate: Date = new Date('2024-03-05')

  build() {
    Column() {
      Text('Calendar date picker').fontSize(30)
      Column() {
        CalendarPicker({ hintRadius: 10, selected: this.selectedDate })
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

![CalendarPicker](figures/CalendarPicker.gif)
