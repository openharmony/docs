# TextTimer


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextTimer&gt;** component supports custom time formats.


## Required Permissions

None


## Child Components

None


## APIs

TextTimer(options: { isCountDown?: boolean, count?: number, controller?: TextTimerController })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | isCountDown | boolean | No | false | Whether&nbsp;to&nbsp;count&nbsp;down. | 
  | count | number | No | 60000 | Countdown&nbsp;time,&nbsp;in&nbsp;milliseconds.&nbsp;This&nbsp;parameter&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;**isCountDown**&nbsp;is&nbsp;set&nbsp;to&nbsp;**true**.<br/>-&nbsp;If&nbsp;the&nbsp;value&nbsp;of&nbsp;**count**&nbsp;is&nbsp;less&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0,&nbsp;the&nbsp;default&nbsp;value&nbsp;is&nbsp;used.<br/>-&nbsp;If&nbsp;the&nbsp;value&nbsp;of&nbsp;**count**&nbsp;is&nbsp;greater&nbsp;than&nbsp;0,&nbsp;it&nbsp;is&nbsp;used. | 
  | controller | [TextTimerController](#texttimercontroller) | No | null | **&lt;TextTimer&gt;**&nbsp;controller. | 


### TextTimerController

Defines the controller for controlling the **&lt;TextTimer&gt;** component.

  | Name | Description | 
| -------- | -------- |
| start() | Starts&nbsp;the&nbsp;timer. | 
| pause() | Pauses&nbsp;the&nbsp;timer. | 
| reset() | Resets&nbsp;the&nbsp;timer. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| format | string | 'hh:mm:ss.ms' | Custom&nbsp;format.&nbsp;The&nbsp;value&nbsp;must&nbsp;contain&nbsp;at&nbsp;least&nbsp;one&nbsp;of&nbsp;the&nbsp;following&nbsp;keywords:&nbsp;**hh**,&nbsp;**mm**,&nbsp;**ss**,&nbsp;and&nbsp;**ms**. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onTimer(callback:&nbsp;(utc:&nbsp;number,&nbsp;elapsedTime:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;time&nbsp;text&nbsp;changes.<br/>**utc**:&nbsp;currently&nbsp;displayed&nbsp;time,&nbsp;in&nbsp;milliseconds.<br/>**elapsedTime**:&nbsp;elapsed&nbsp;time&nbsp;of&nbsp;the&nbsp;timer,&nbsp;in&nbsp;milliseconds. | 


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
