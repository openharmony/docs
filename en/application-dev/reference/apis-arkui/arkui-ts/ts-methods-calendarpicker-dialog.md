# Calendar Picker Dialog Box (CalendarPickerDialog)

A calendar picker dialog box is a dialog box that allows users to select a date from a calendar picker.

> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](../js-apis-arkui-UIContext.md#uicontext).

## CalendarPickerDialog.show

static show(options?: CalendarDialogOptions)

Shows a calendar picker dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                   | Mandatory| Description                      |
| ------- | ------------------------------------------------------- | ---- | -------------------------- |
| options | [CalendarDialogOptions](#calendardialogoptions) | No  | Parameters of the calendar picker dialog box.|

## CalendarDialogOptions

Inherited from [CalendarOptions](ts-basic-components-calendarpicker.md#calendaroptions).

| Name      | Type                                           | Mandatory| Description                                                        |
| ---------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| onAccept   | (value: Date) => void                           | No  | Triggered when the OK button in the dialog box is clicked.<br>**value**: selected date value|
| onCancel   | () => void                                      | No  | Triggered when the Cancel button in the dialog box is clicked.                        |
| onChange   | (value: Date) => void                           | No  | Triggered when the selection in the picker changes the selected date.<br>**value**: selected date value|
| backgroundColor<sup>11+</sup> | [ResourceColor](ts-types.md#resourcecolor)  | No| Backplane color of the dialog box.<br>Default value: **Color.Transparent**|
| backgroundBlurStyle<sup>11+</sup> | [BlurStyle](ts-appendix-enums.md#blurstyle9) | No| Background blur style of the dialog box.<br>Default value: **BlurStyle.COMPONENT_ULTRA_THICK**|

## Example

```ts
// xxx.ets
@Entry
@Component
struct CalendarPickerDialogExample {
  private selectedDate: Date = new Date()
  build() {
    Column() {
      Button("Show CalendarPicker Dialog")
        .margin(20)
        .onClick(() => {
          console.info("CalendarDialog.show")
          CalendarPickerDialog.show({
            selected: this.selectedDate,
            onAccept: (value) => {
              console.info("calendar onAccept:" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("calendar onCancel")
            },
            onChange: (value) => {
              console.info("calendar onChange:" + JSON.stringify(value))
            }
          })
        })
    }.width('100%')
  }
}
```

![CalendarPickerDialog](figures/CalendarPickerDialog.gif)
