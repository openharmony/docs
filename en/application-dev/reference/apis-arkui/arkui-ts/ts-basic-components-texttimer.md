# TextTimer

The **\<TextTimer>** component displays timing information and is controlled in text format.

>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

TextTimer(options?: TextTimerOptions)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options |  [TextTimerOptions](#texttimeroptions)| No| Parameters of the **\<TextTimer>** component.|

## TextTimerOptions

| Name    | Type    | Mandatory | Description                  |
| ----------- | -------- | -------- | -------- |
| isCountDown | boolean  | No  | Whether to count down.<br>Default value: **false**|
| count       | number   | No  | Countdown time, in milliseconds. This parameter is valid only when **isCountDown** is set to **true**. The maximum value is 86400000 ms (24 hours). In the case of 0 < Value of **count** < 86400000, the value of **count** is used as the initial countdown value. In other cases, the default value is used as the initial countdown value.<br>Default value: **60000**|
| controller  | [TextTimerController](#texttimercontroller) | No | **\<TextTimer>** controller.|

## Attributes

Among the [universal attributes](ts-universal-attributes-size.md) and [universal text attributes](ts-universal-attributes-text-style.md), **fontColor**, **fontSize**, **fontStyle**, **fontWeight**, and **fontFamily** are supported. In addition, the following attributes are supported.

### format

format(value: string)

Sets the custom format. The value must contain at least one of the following keywords: **HH**, mm, **ss**, and **SS**. If the specified date format is yy, MM, or dd, the default value is used instead.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| value  | string | Yes  | Custom format<br>Default value: **'HH:mm:ss.SS'**|

### textShadow<sup>11+</sup>

textShadow(value: ShadowOptions | Array&lt;ShadowOptions&gt;)

Sets the text shadow. It supports input parameters in an array to implement multiple text shadows. This API does not work with the **fill** attribute or coloring strategy.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description          |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions) \| Array&lt;[ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions)> | Yes  | Text shadow.|

## Events

### onTimer

onTimer(event: (utc: number, elapsedTime: number) =&gt; void)

Triggered when the time text changes. This event is not triggered when the screen is locked or the application is running in the background.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| utc         | number | Yes  | Linux timestamp, which is the amount of time that has elapsed since January 1, 1970, in the minimum unit of the format.|
| elapsedTime | number | Yes  | Elapsed time of the timer, in the minimum unit of the format.                |

## TextTimerController

Implements the controller for controlling the **\<TextTimer>** component. A **\<TextTimer>** component can be bound to only one controller.

### Objects to Import

```
textTimerController: TextTimerController = new TextTimerController()

```

### start

start()

Starts the timer.

### pause

pause()

Pauses the timer.

### reset

reset()

Resets the timer.

## Example
### Example 1
```ts
// xxx.ets
@Entry
@Component
struct TextTimerExample {
  textTimerController: TextTimerController = new TextTimerController()
  @State format: string = 'mm:ss.SS'

  build() {
    Column() {
      TextTimer({ isCountDown: true, count: 30000, controller: this.textTimerController })
        .format(this.format)
        .fontColor(Color.Black)
        .fontSize(50)
        .onTimer((utc: number, elapsedTime: number) => {
          console.info('textTimer notCountDown utc is: ' + utc + ', elapsedTime: ' + elapsedTime)
        })
      Row() {
        Button("start").onClick(() => {
          this.textTimerController.start()
        })
        Button("pause").onClick(() => {
          this.textTimerController.pause()
        })
        Button("reset").onClick(() => {
          this.textTimerController.reset()
        })
      }
    }
  }
}
```


![en-us_image_0000001257138345](figures/en-us_image_0000001257138345.gif)

### Example 2
``` ts
@Entry
@Component
struct TextTimerExample {
  @State textShadows : ShadowOptions | Array<ShadowOptions> = [{ radius: 10, color: Color.Red, offsetX: 10, offsetY: 0 },{ radius: 10, color: Color.Black, offsetX: 20, offsetY: 0 },
      { radius: 10, color: Color.Brown, offsetX: 30, offsetY: 0 },{ radius: 10, color: Color.Green, offsetX: 40, offsetY: 0 },
      { radius: 10, color: Color.Yellow, offsetX: 100, offsetY: 0 }]
  build() {
    Column({ space: 8 }) {
      TextTimer().fontSize(50).textShadow(this.textShadows)
    }
  }
}
```
![TextshadowExample](figures/text_timer_textshadow.png)
