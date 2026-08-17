# DatePickerComponent

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e3759c69d65e24a59d611c9befe1266734e11881 translatedAt=2026-07-27T11:06:24.154Z pushedAt=2026-07-28T06:53:26.456Z -->

The **DatePickerComponent** is used to select dates (year, month, and day) and times (hour, minute, and second).

**Since:** 26.0.0

## Modules to Import

```ts
import { DatePickerComponent, DatePickerComponentOptions, DisplayMode, DateMode, TimeFormat, DatePickerComponentResult } from '@kit.ArkUI';
```

## Child Components

None

## DatePickerComponent

DatePickerComponent({ options: DatePickerComponentOptions })

Defines a date and time picker component.

**Since:** 26.0.0

**Decorator:** @Component

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Mandatory | Decorator Type | Description |
| ---- | ---- | ---- | ---------- | ---- |
| options | [DatePickerComponentOptions](#datepickercomponentoptions) | Yes | @Prop | Options of the date and time picker component. |

## DatePickerComponentOptions

Defines the options of the date and time picker component.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| displayMode | [DisplayMode](#displaymode) | No | Yes | Display mode of the picker.<br>Default value: **DisplayMode.DATE**<br>**NOTE**<br>- **DATE**: Displays only the date using **dateOptions**. This value is applicable to scenarios where only the date needs to be selected, such as birthday selection and schedule date setting.<br>- **TIME**: Displays only the time using **timeOptions**. This value is applicable to scenarios where only the time needs to be selected, such as alarm setting and reminder time setting.<br>- **DATE_TIME**: Displays both the date and time, with **dateOptions** and **timeOptions** taking effect simultaneously. This value is applicable to scenarios where both the date and time need to be selected, such as event scheduling and meeting time setting. |
| dateOptions | [DateOptions](#dateoptions) | No | Yes | Date options. |
| timeOptions | [TimeOptions](#timeoptions) | No | Yes | Time options. |

## DisplayMode

Enumerates the display modes of the picker.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Value | Description |
| ---- | -- | ---- |
| DATE | 0 | Date only. |
| TIME | 1 | Time only. |
| DATE_TIME | 2 | Both date and time. |

## DateMode

Enumerates the modes of the date picker.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Value | Description |
| ---- | -- | ---- |
| DATE | 0 | Three columns: year, month, and day. |
| YEAR_AND_MONTH | 1 | Two columns: year and month. |
| MONTH_AND_DAY | 2 | Two columns: month and day. In this mode, the year is specified by **selected** and remains unchanged; if **selected** is not specified, the current system year is used. When the month changes from December to January, the year does not increment. When the month changes from January to December, the year does not decrement. When scrolling through months causes the day to exceed the valid range, the day is automatically adjusted to the last day of that month. |

## TimeFormat

Enumerates the formats of the time picker.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Value | Description |
| ---- | -- | ---- |
| HOUR_MINUTE | 0 | Hours and minutes. |
| HOUR_MINUTE_SECOND | 1 | Hours, minutes, and seconds. |

## DatePickerComponentResult

Defines the selection result of the date and time picker, including the year, month, day, hour, minute, and second selected by the user. It is used to pass the specific date and time values in the **onChange** and **onScrollStop** callbacks.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| year | number | No | Yes | Year of the selected date. |
| month | number | No | Yes | Month index of the selected date, starting from 0. The value **0** indicates January, and **11** indicates December. |
| day | number | No | Yes | Day of the selected date. |
| hour | number | No | Yes | Hour of the selected time. |
| minute | number | No | Yes | Minute of the selected time. |
| second | number | No | Yes | Second of the selected time. |

## CommonOptions

Defines the common options of the date and time picker.

> **NOTE**
>
> - The parameter order of the **Date** constructor is: year, month index (0-11), day, hour, minute, second. Note: The year parameter must be greater than 99 or less than 0 to avoid 1900s mapping.
> - For the usage of **Date**, see [TimePickerOptions](ts-basic-components-timepicker.md#timepickeroptions). Note that when you need to set a year between 1 and 99, do not use the **new Date(1, 0, 1)** syntax. The JavaScript **new Date(year, month, day)** constructor has special handling for years 1-99: it automatically adds 1900 to the input year, which results in the year 1901 instead of the intended year 1. In this case, use the **new Date('0001-01-01')** syntax instead.
> - The text font size of **DatePickerComponent** varies with the total number of displayed columns. When the number of columns is 6 or more, the font size is 14 vp; otherwise, it is 16 vp. Text truncation may occur when the component width is too narrow.
> - When a parameter is omitted or set to **undefined**, the default value is used.
> - When **start**, **end**, and **selected** in [DateOptions](#dateoptions) are set, only the date part (year, month, day) takes effect. When they are set in [TimeOptions](#timeoptions), only the time part (hour, minute, second) takes effect. The system automatically filters the corresponding parts of the **Date** object and applies constraints based on the configured **displayMode** and the corresponding **Options** type.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| start | Date | No | Yes | Start date or time of the picker.<br>Default value: **Date('1970-01-01T00:00:00')**<br>Value range: \[Date('0001-01-01T00:00:00'), Date('9999-12-31T23:59:59')]<br>**NOTE**<br>When **start** is set to a valid value, **loop** does not take effect.|
| end | Date | No | Yes | End date or time of the picker.<br>Default value: **Date('2100-12-31T23:59:59')**<br>Value range: \[Date('0001-01-01T00:00:00'), Date('9999-12-31T23:59:59')]<br>**NOTE**<br>When **end** is set to a valid value, **loop** does not take effect.|
| selected | Date | No | Yes | Selected date or time, displayed as the initial selected value after being set.<br>Default value: current system date or time.<br>**NOTE**<br>In the **DateMode.MONTH_AND_DAY** mode, only the **month** and **day** fields can be selected. The **year** field is specified by **selected**; if no value is specified, the current system year is used and remains unchanged during scrolling. |
| loop | boolean | No | Yes | Whether to enable loop mode.<br>- **true**: Loop mode is enabled, allowing continuous cyclic selection when scrolling to the boundary.<br>- **false**: Loop mode is disabled, and scrolling stops at the boundary.<br>Default value: **true**<br>**Use scenarios:**<br>Loop mode is applicable to scenarios requiring continuous scrolling selection, such as quickly browsing years and months. Non-loop mode is applicable to scenarios requiring clear boundary ranges.<br>**NOTE**<br>When [start](#commonoptions) or [end](#commonoptions) is set to a valid value, this parameter does not take effect. |
| onChange | [Callback](ts-types.md#callback12)<[DatePickerComponentResult](#datepickercomponentresult)> | No | Yes | Callback triggered when a date or time is selected. |
| onScrollStop | [Callback](ts-types.md#callback12)<[DatePickerComponentResult](#datepickercomponentresult)> | No | Yes | Callback triggered when the picker item is selected and scrolling stops. |
| enableHapticFeedback | boolean | No | Yes | Whether to enable haptic feedback.<br>Default value: **true**<br>- **true**: Haptic feedback is enabled, applicable to scenarios where enhanced user interaction experience is needed, such as gaming and musical instrument applications.<br>- **false**: Haptic feedback is disabled, applicable to scenarios where haptic feedback is not required or device resources need to be conserved.<br>**NOTE**<br>1. When this parameter is set to **true**, whether it takes effect depends on whether the system hardware supports it.<br>2. To enable haptic feedback, configure the **requestPermissions** field in the [module.json5](../../../quick-start/module-configuration-file.md) file of the project to request the vibration permission. The configuration is as follows:<br>**"requestPermissions": [{"name": "ohos.permission.VIBRATE"}]** |

> **NOTE**
>
> - **onChange** is triggered when the user selects a date or time, and is used to respond to the user's selection.
> - **onScrollStop** is triggered after scrolling completely stops, and returns the current selected item regardless of whether the value has changed.
> - Both can be used together or separately as needed: **onChange** is used for immediate response to user selection, and **onScrollStop** is used to obtain the stable result after scrolling stops.

**Exception handling for the start date, end date, and selected date**

| Exception Scenario   | Result  |
| -------- |  ------------------------------------------------------------ |
| The start date is later than the end date, and the selected date is not set.    | The start date, end date, and selected date all use the default values. |
| The start date is later than the end date, and the selected date is earlier than the default start date.    | The start date and end date use the default values, and the selected date uses the default start date.  |
| The start date is later than the end date, and the selected date is later than the default end date.    | The start date and end date use the default values, and the selected date uses the default end date.  |
| The start date is later than the end date, and the selected date is within the range of the default start date and default end date.    | The start date and end date use the default values, and the selected date uses the set value. |
| The selected date is earlier than the start date.    | The selected date is set to the start date.  |
| The selected date is later than the end date.    | The selected date is set to the end date.  |
| The start date is later than the current system date, and the selected date is not set.    | The selected date is set to the start date.  |
| The end date is earlier than the current system date, and the selected date is not set.    | The selected date is set to the end date.  |
| The **Date** object constructor parameters are invalid or non-compliant, for example, the year, month, or day parameters are out of the valid range, or an invalid string is passed, resulting in an invalid date.   | The default value is used.  |
| The start date or end date is earlier than the minimum value of the valid range.    | The start date or end date uses the default start date. |
| The start date or end date is later than the maximum value of the valid range.    | The start date or end date uses the default end date. |
| Both the start date and end date are earlier than the minimum value of the valid range. | The start date and end date use the earliest date in the system valid range. |
| Both the start date and end date are later than the maximum value of the valid range. | The start date and end date use the latest date in the system valid range. |

**Exception handling for the start time and end time**

| Exception Scenario   | Result  |
| -------- |  ------------------------------------------------------------ |
| The start time is later than the end time.    | The start time and end time both use the default values.  |
| The selected time is earlier than the start time.   | The selected time is set to the start time.  |
| The selected time is later than the end time.    | The selected time is set to the end time.  |
| The start time is later than the current system time, and the selected time is not set.    | The selected time is set to the start time. |
| The end time is earlier than the current system time, and the selected time is not set.    | The selected time is set to the end time.  |
| The **Date** object constructor parameters are invalid or non-compliant, for example, the hour, minute, or second parameters are out of the valid range, or an invalid string is passed, resulting in an invalid date.   | The default value is used.  |

## DateOptions

Defines the options of the date picker.

This API inherits from [CommonOptions](#commonoptions).

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| mode | [DateMode](#datemode) | No | Yes | Mode of the date picker.<br>Default value: DateMode.DATE |
| lunar | boolean | No | Yes | Whether to display the lunar calendar.<br>- **true**: The lunar calendar is displayed. This is applicable to scenarios where the traditional lunar calendar is required, such as traditional festivals, lunar birthdays, and lunar anniversaries.<br>- **false**: The lunar calendar is not displayed. This is applicable to scenarios where the Gregorian calendar is used.<br>Default value: **false**<br>**NOTE**<br>This attribute takes effect only in the simplified Chinese and traditional Chinese language environments. It has no effect in other language environments. |

## TimeOptions

Defines the options of the time picker.

This API inherits from [CommonOptions](#commonoptions).

> **NOTE**
>
> If the **start** or **end** parameter is set to a valid value, the **loop** parameter will not take effect. For details, see the parameter description of [CommonOptions](#commonoptions).

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| format | [TimeFormat](#timeformat) | No | Yes | Format of the time picker.<br>Default value: **TimeFormat.HOUR_MINUTE** |
| useMilitaryTime | boolean | No | Yes | Whether to display time in 24-hour format.<br>- **true**: The time is displayed in 24-hour format, applicable to international applications and professional scenarios that require precise time expression (such as healthcare, transportation, and military).<br>- **false**: The time is displayed in 12-hour format, applicable to daily application scenarios targeting general users, which better aligns with users' everyday reading habits.<br>Default value: **false** |

## Examples

### Example 1: Date Picker

This example implements a date picker by setting **displayMode** in [DatePickerComponentOptions](#datepickercomponentoptions) to **DisplayMode.DATE**.

Since API version 26.0.0, the [DatePickerComponentOptions](#datepickercomponentoptions) parameter is added.

```ts
import { DatePickerComponent, DisplayMode, DateMode } from '@kit.ArkUI';

@Entry
@Component
struct DatePickerExample {
  @State selectedYear: number = 2026
  @State selectedMonth: number = 0
  @State selectedDay: number = 1

  build() {
    Column() {
      DatePickerComponent({
        options: {
          displayMode: DisplayMode.DATE,
          dateOptions: {
            mode: DateMode.DATE,
            selected: new Date(this.selectedYear, this.selectedMonth, this.selectedDay),
            start: new Date('2020-03-01'),
            end: new Date('2030-10-31'),
            enableHapticFeedback: true,
            onChange: (result) => {
              console.info('Selected date: ' + (result.year ?? 0) + '-' + ((result.month ?? 0) + 1) + '-' + (result.day ?? 0));
              if (result.year !== undefined) {
                this.selectedYear = result.year
              }
              if (result.month !== undefined) {
                this.selectedMonth = result.month
              }
              if (result.day !== undefined) {
                this.selectedDay = result.day
              }
            },
            onScrollStop: (result) => {
              console.info('Scroll stop: ' + (result.year ?? 0) + '-' + ((result.month ?? 0) + 1) + '-' + (result.day ?? 0));
            }
          }
        }
      })
    }
  }
}

```

<!--Del--> <!--DelEnd-->

### Example 2: Time Picker

This example implements a time picker by setting **displayMode** in [DatePickerComponentOptions](#datepickercomponentoptions) to **DisplayMode.TIME**.

Since API version 26.0.0, the [DatePickerComponentOptions](#datepickercomponentoptions) parameter is added.

```ts
import { DatePickerComponent, DisplayMode, TimeFormat } from '@kit.ArkUI';

@Entry
@Component
struct TimePickerExample {
  build() {
    Column() {
      DatePickerComponent({
        options: {
          displayMode: DisplayMode.TIME,
          timeOptions: {
            format: TimeFormat.HOUR_MINUTE,
            useMilitaryTime: true,
            enableHapticFeedback: true,
            onChange: (result) => {
              console.info('Selected time: ' + (result.hour ?? 0) + ':' + (result.minute ?? 0));
            },
            onScrollStop: (result) => {
              console.info('Scroll stop: ' + (result.hour ?? 0) + ':' + (result.minute ?? 0));
            }
          }
        }
      })
    }
  }
}
```

<!--Del--> <!--DelEnd-->

### Example 3: Date and Time Picker

This example sets **displayMode** in [DatePickerComponentOptions](#datepickercomponentoptions) to **DisplayMode.DATE_TIME** to select both date and time.

Since API version 26.0.0, the [DatePickerComponentOptions](#datepickercomponentoptions) parameter is added.

```ts
import { DatePickerComponent, DisplayMode, DateMode, TimeFormat } from '@kit.ArkUI';

@Entry
@Component
struct DateTimePickerExample {
  build() {
    Column() {
      DatePickerComponent({
        options: {
          displayMode: DisplayMode.DATE_TIME,
          dateOptions: {
            mode: DateMode.DATE,
            lunar: false,
            enableHapticFeedback: true,
            onChange: (result) => {
              console.info('Selected: ' + JSON.stringify(result));
            },
            onScrollStop: (result) => {
              console.info('Scroll stop: ' + JSON.stringify(result));
            }
          },
          timeOptions: {
            format: TimeFormat.HOUR_MINUTE_SECOND,
            useMilitaryTime: false,
            onChange: (result) => {
              console.info('Selected: ' + JSON.stringify(result));
            },
            onScrollStop: (result) => {
              console.info('Scroll stop: ' + JSON.stringify(result));
            }
          }
        }
      })
    }
  }
}
```

<!--Del--> <!--DelEnd-->

### Example 4: Disabling Loop Mode

This example disables the loop scrolling mode of the picker by setting **loop** in [DateOptions](#dateoptions) to **false**.

Since API version 26.0.0, the [DateOptions](#dateoptions) parameter is added.

```ts
import { DatePickerComponent, DisplayMode, DateMode } from '@kit.ArkUI';

@Entry
@Component
struct NoLoopPickerExample {
  build() {
    Column() {
      DatePickerComponent({
        options: {
          displayMode: DisplayMode.DATE,
          dateOptions: {
            mode: DateMode.DATE,
            selected: new Date(),
            start: new Date('2020-01-01'),
            end: new Date('2030-12-31'),
            loop: false,
            onChange: (result) => {
              console.info('Selected date: ' + (result.year ?? 0) + '-' + ((result.month ?? 0) + 1) + '-' + (result.day ?? 0));
            }
          }
        }
      })
    }
  }
}
```

<!--Del--> <!--DelEnd-->