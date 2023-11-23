# Touch Event

A touch event is triggered when a finger is pressed, slides, or is lifted from a component.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                                        | Bubbling Supported| Description                                                    |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| onTouch(event: (event?: TouchEvent) =&gt; void) | Yes      | Invoked when a touch event is triggered. For details about **event**, see [TouchEvent](#touchevent).|


## TouchEvent

| Name               | Type                                      | Description          |
| ------------------- | ---------------------------------------- | ------------ |
| type                | [TouchType](ts-appendix-enums.md#touchtype)      | Type of the touch event.    |
| touches             | Array&lt;[TouchObject](#touchobject)&gt; | All finger information.     |
| changedTouches      | Array&lt;[TouchObject](#touchobject)&gt; | Finger information changed.|
| stopPropagation      | () => void | Stops the event from bubbling upwards or downwards.|
| timestamp<sup>8+</sup> | number | Timestamp of the event. It is the interval between the time when the event is triggered and the time when the system starts, in nanoseconds.<br>For example, if the system starts at 2023/10/12 11:33 and the touch event is triggered at 2023/10/12 11:34, then the returned timestamp value is 60,000,000,000 ns.|
| target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md#eventtarget8) | Display area of the element that triggers the gesture event.|
| source<sup>8+</sup> | [SourceType](ts-gesture-settings.md#sourcetype)| Event input device.|
| getHistoricalPoints<sup>10+</sup> | Array&lt;[HistoricalPoint](#historicalpoint10)&gt;| All historical points of the current frame. The touch event frequency of a frame varies by device, and all touch events of the current frame are referred to as its historical points.|


## TouchObject

| Name   | Type                                       | Description                                 |
| ------- | ------------------------------------------- | ------------------------------------- |
| type    | [TouchType](ts-appendix-enums.md#touchtype) | Type of the touch event.                     |
| id      | number                                      | Unique identifier of a finger.                     |
| x       | number                                      | X coordinate of the touch point relative to the upper left corner of the original area of the touched element.|
| y       | number                                      | Y coordinate of the touch point relative to the upper left corner of the original area of the touched element.|
| windowX<sup>10+</sup>  | number                       | X coordinate of the touch point relative to the upper left corner of the application window.  |
| windowY<sup>10+</sup>  | number                       | Y coordinate of the touch point relative to the upper left corner of the application window.  |
| displayX<sup>10+</sup> | number                       | X coordinate of the touch point relative to the upper left corner of the application screen.  |
| displayY<sup>10+</sup> | number                       | Y coordinate of the touch point relative to the upper left corner of the application screen.  |
| screenX<sup>(deprecated)</sup> | number               | X coordinate of the touch point relative to the upper left corner of the application window.<br>This API is deprecated since API version 10. You are advised to use **windowX** instead.  |
| screenY<sup>(deprecated)</sup> | number               | Y coordinate of the touch point relative to the upper left corner of the application window.<br>This API is deprecated since API version 10. You are advised to use **windowY** instead.  |

## HistoricalPoint<sup>10+</sup>

| Name        | Type                                | Description                                                                        |
| ----------- | ----------------------------------- | ----------------------------------------------------------------------------- |
| touchObject | [TouchObject](#touchobject)  | Basic information of the historical point.                                                  |
| size        | number                              | Size of the contact area between the finger and screen for the historical point.<br>Default value: **0**                                    |
| force       | number                              | Touch force of the historical point.<br>Default value: **0**<br>Value range: [0,1]. A larger value indicates a greater touch force.<br>The support for this API varies by device. Currently, it is only available on tablets.|
| timestamp   | number                              | Timestamp of the historical point. It is the interval between the time when the event is triggered and the time when the system starts.<br>Unit: ms            |
## Example

```ts
// xxx.ets
@Entry
@Component
struct TouchExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Column() {
      Button('Touch').height(40).width(100)
        .onTouch((event?: TouchEvent) => {
          if(event){
            if (event.type === TouchType.Down) {
              this.eventType = 'Down'
            }
            if (event.type === TouchType.Up) {
              this.eventType = 'Up'
            }
            if (event.type === TouchType.Move) {
              this.eventType = 'Move'
            }
            this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
            + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
            + event.target.area.width + '\nheight:' + event.target.area.height
          }
        })
      Button('Touch').height(50).width(200).margin(20)
        .onTouch((event?: TouchEvent) => {
          if(event){
            if (event.type === TouchType.Down) {
              this.eventType = 'Down'
            }
            if (event.type === TouchType.Up) {
              this.eventType = 'Up'
            }
            if (event.type === TouchType.Move) {
              this.eventType = 'Move'
            }
            this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
            + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
            + event.target.area.width + '\nheight:' + event.target.area.height
          }
        })
      Text(this.text)
    }.width('100%').padding(30)
  }
}
```

![en-us_image_0000001209874754](figures/en-us_image_0000001209874754.gif)
