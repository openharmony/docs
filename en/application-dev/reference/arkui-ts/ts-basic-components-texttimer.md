# TextTimer

The **\<TextTimer>** component displays timing information and is controlled in text format.

>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

TextTimer(options?: { isCountDown?: boolean, count?: number, controller?: TextTimerController })

**Parameters**

| Name    | Type    | Mandatory | Description                  |
| ----------- | -------- | -------- | -------- |
| isCountDown | boolean  | No  | Whether to count down.<br>Default value: **false**|
| count       | number   | No  | Countdown time, in milliseconds. This parameter is valid only when **isCountDown** is set to **true**. The maximum value is 86400000 ms (24 hours). In the case of 0 < Value of **count** < 86400000, the value of **count** is used as the initial countdown value. In other cases, the default value is used as the initial countdown value.<br>Default value: **60000**|
| controller  | [TextTimerController](#texttimercontroller) | No | **\<TextTimer>** controller.|

## Attributes

| Name       | Type      | Description                            |
| -------- | ---------------------- | ---------------------- |
| format   | string   | Custom format. The value must contain at least one of the following keywords: **HH**, **mm**, **ss**, and **SS**. If the specified date format is yy, MM, or dd, the default value is used instead.<br>Default value: **'HH:mm:ss.SS'**|

## Events

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onTimer(event: (utc: number, elapsedTime: number) =&gt; void) | Triggered when the time text changes.<br>**utc**: Unix time stamp, which is the number of milliseconds that have elapsed since the Unix epoch.<br>**elapsedTime**: elapsed time of the timer, in milliseconds.|

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
