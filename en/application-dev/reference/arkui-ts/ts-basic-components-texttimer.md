# TextTimer


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextTimer&gt;** component supports custom time formats.


## Required Permissions

None


## Child Components

None


## APIs

TextTimer(options: { isCountDown?: boolean, count?: number, controller?: TextTimerController })

- Parameters
    | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | isCountDown | boolean | No | false | Whether to count down. | 
  | count | number | No | 60000 | Countdown time, in milliseconds. This parameter is valid only when **isCountDown** is set to **true**.<br/>- If the value of **count** is less than or equal to 0, the default value is used.<br/>- If the value of **count** is greater than 0, it is used. | 
  | controller | [TextTimerController](#texttimercontroller) | No | null | **&lt;TextTimer&gt;** controller. | 


### TextTimerController

Defines the controller for controlling the **&lt;TextTimer&gt;** component.

  | Name | Description | 
| -------- | -------- |
| start() | Starts the timer. | 
| pause() | Pauses the timer. | 
| reset() | Resets the timer. | 


## Attributes

  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| format | string | 'hh:mm:ss.ms' | Custom format. The value must contain at least one of the following keywords: **hh**, **mm**, **ss**, and **ms**. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onTimer(callback: (utc: number, elapsedTime: number) =&gt; void) | Triggered when the time text changes.<br/>**utc**: currently displayed time, in milliseconds.<br/>**elapsedTime**: elapsed time of the timer, in milliseconds. | 


## Example


```
@Entry
@Component
struct TextTimerExample {
  myTimerController: TextTimerController = new TextTimerController()
  @State format: string = 'hh:mm:ss.ms'

  build() {
    Column() {
      TextTimer({controller: this.myTimerController})
        .format(this.format)
        .fontColor(Color.Black)
        .fontSize(this.textSize)
        .onTimer((utc: number, elapsedTime: number) => {
          console.info('textTimer notCountDown utc is:' + utc + ', elapsedTime: ' + elapsedTime)
        })
      Row() {
        Button("start").onClick(() => {
          this.myTimerController.start();
        });
        Button("pause").onClick(() => {
          this.myTimerController.pause();
        });
        Button("reset").onClick(() => {
          this.myTimerController.reset();
        });
      }
    }
  }
}
```


![en-us_image_0000001257138345](figures/en-us_image_0000001257138345.gif)
