# TextClock

The **\<TextClock>** component displays the current system time in text format for different time zones. The time is accurate to seconds.

>**NOTE**
>
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

TextClock(options?: { timeZoneOffset?: number, controller?: TextClockController })

**Parameters**

| Name           | Type     | Mandatory    | Description                                                    |
| -------------- | -------- | ------ | --------------------------------------------------------------------------- |
| timeZoneOffset | number   | No    | Time zone offset.<br>The value range is [-14, 12], indicating UTC+12 to UTC-12. A negative value indicates Eastern Standard Time, and a positive value indicates Western Standard Time. For example, **-8** indicates UTC+8.<br>For countries or regions crossing the International Date Line, use -13 (UTC+13) and -14 (UTC+14) to ensure consistent time within the entire country or region. If the set value is not within the valid range, the time zone offset of the current system will be used.<br>Default value: time zone offset of the current system|
| controller     | [TextClockController](#textclockcontroller) | No     | Controller to control the status of the **<TextClock\>** component.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name  | Type| Description                                                        |
| ------ | -------- | ------------------------------------------------------------ |
| format | string   | Time format.<br>**y**: year<br>**M**: month<br>**d**: day<br>**E**: day of week (Prioritize the full name; use the abbreviation only when the space is insufficient.)<br>**H**: hour (0-23)<br>**h**: hour (1-12)<br>**m**: minute<br>**s**: second<br>**SS**: centisecond<br>**SSS**: millisecond<br>**a**: morning/afternoon (This parameter does not take effect when the hour part  is set to **H**.)<br>Separators: slashes (/), hyphens (-), dots (.), or any custom characters (which cannot be letters) used to separate the parts of the date<br>The parts of the date can be used alone or combined with each other as needed.<br>When an invalid letter is set, the letter is ignored.<br>Default value: **hh:mm:ss**|

The following table shows how different settings of **format** work out.

| Input Format             | Display Effect|
| ------------------------------------------------------------ | ------ |
| EEEE, M, d, yyyy      | Saturday, February 4, 2023|
| MMM d, yyyy           | February 4, 2023       |
| EEEE, M, d            | Saturday, February 4      |
| MMM dd                 | February 4             |
| MM/dd/yyyy              | 02/04/2023          |
| EEEE MM dd          | Saturday February 04    |
| yyyy       | 2023             |
| yy       | 23               |
| MM         | February               |
| M              | February|
| dd (complete date)| 04|
| d | 4|
| EEEE (full name)| Saturday|
| E, EE, EEE (abbreviation)| Sat|
| MMM d, yyyy| February 4, 2023|
| yyyy/M/d | 2023/2/4 |
| yyyy-M-d | 2023-2-4 |
| yyyy.M.d | 2023.2.4 |
| HH:mm:ss| 17:00:04 |
| aa hh:mm:ss| 5:00:04 AM|
| hh:mm:ss| 5:00:04 |
| HH:mm| 17:00 |
| aa hh:mm| 5:00 AM|
| hh:mm| 5:00 |
| mm:ss| 00:04 |
| mm:ss.SS| 00:04.91 |
| mm:ss.SSS| 00:04.536 |
| hh:mm:ss aa | 5:00:04 AM|
| HH | 17 |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                        | Description                                                    |
| -------------------------------------------- | ------------------------------------------------------------ |
| onDateChange(event: (value: number) => void) | Called when the time changes in seconds.<br>- **value**: Unix time stamp, which is the number of seconds that have elapsed since the Unix epoch.|

## TextClockController

Implements the controller of the **\<TextClock>** component. You can bind the controller to the component to control its start and stop. A **\<TextClock>** component can be bound to only one controller.

### Objects to Import

```ts
controller: TextClockController = new TextClockController();
```

### start

start()

Starts the **<TextClock\>** component.

### stop

stop()

Stops the **<TextClock\>** component.

## Example

```ts
@Entry
@Component
struct Second {
  @State accumulateTime: number = 0
  // Objects to import
  controller: TextClockController = new TextClockController()
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('Current milliseconds is ' + this.accumulateTime)
        .fontSize(20)
      // Display the system time in 12-hour format for the UTC+8 time zone, accurate to seconds.
      TextClock({ timeZoneOffset: -8, controller: this.controller })
        .format('aa hh:mm:ss')
        .onDateChange((value: number) => {
          this.accumulateTime = value
        })
        .margin(20)
        .fontSize(30)
      Button("start TextClock")
        .margin({ bottom: 10 })
        .onClick(() => {
          // Start the text clock.
          this.controller.start()
        })
      Button("stop TextClock")
        .onClick(() => {
          // Stop the text clock.
          this.controller.stop()
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
![text_clock](figures/text_clock.gif)
