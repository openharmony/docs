# TextTimer

The **\<TextTimer>** component displays timing information and is controlled in text format.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TextTimer(options?: { isCountDown?: boolean, count?: number, controller?: TextTimerController })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isCountDown | boolean | No| Whether to count down.<br/>Default value: **false** |
| count | number | No| Countdown time, in milliseconds. This parameter is valid only when **isCountDown** is set to **true**.<br>If the value of **count** is less than or equal to 0, the default value is used.<br>If the value of **count** is greater than 0, it is used.<br/>Default value: **60000** |
| controller | [TextTimerController](#texttimercontroller) | No| **\<TextTimer>** controller.|

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| format | string | Custom format. The value must contain at least one of the following keywords: **hh**, **mm**, **ss**, and **ms**.<br>Default value: **'hh:mm:ss.ms'** |


## Events

| Name| Description|
| -------- | -------- |
| onTimer(event: (utc: number, elapsedTime: number) =&gt; void) | Triggered when the time text changes.<br>**utc**: currently displayed time, in milliseconds.<br>**elapsedTime**: elapsed time of the timer, in milliseconds.|


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
  @State format: string = 'hh:mm:ss.ms'

  build() {
    Column() {
      TextTimer({controller: this.textTimerController})
        .format(this.format)
        .fontColor(Color.Black)
        .fontSize(50)
        .onTimer((utc: number, elapsedTime: number) => {
          console.info('textTimer notCountDown utc is: ' + utc + ', elapsedTime: ' + elapsedTime)
        })
      Row() {
        Button("start").onClick(() => {
          this.textTimerController.start();
        });
        Button("pause").onClick(() => {
          this.textTimerController.pause();
        });
        Button("reset").onClick(() => {
          this.textTimerController.reset();
        });
      }
    }
  }
}
```


![en-us_image_0000001257138345](figures/en-us_image_0000001257138345.gif)
