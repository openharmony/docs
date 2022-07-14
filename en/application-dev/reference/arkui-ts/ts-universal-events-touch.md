# Touch Event

A touch event is triggered when a finger is pressed, slides, or is lifted from a component.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name                                      | Bubbling Supported| Description                                    |
| ---------------------------------------- | ---- | ---------------------------------------- |
| onTouch(callback:&nbsp;(event?:&nbsp;TouchEvent)&nbsp;=&gt;&nbsp;void) | Yes   | Invoked when a touch action is triggered. For details about **event**, see [TouchEvent](#touchevent).|


## TouchEvent

- Attributes
  | Name               | Type                                      | Description          |
  | ------------------- | ---------------------------------------- | ------------ |
  | type                | TouchType                                | Type of the touch event.    |
  | touches             | Array&lt;[TouchObject](#touchobject)&gt; | All finger information.     |
  | changedTouches      | Array&lt;[TouchObject](#touchobject)&gt; | Finger information changed.|
  | timestamp           | number                                   | Timestamp of the event.      |
  | target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md#eventtarget8) | Target of the event.    |


- APIs
  | Name                  | Description   |
  | ---------------------- | ------- |
  | stopPropagation(): void| Stops the event from bubbling upwards or downwards.|


## TouchObject
| Name   | Type                         | Description                 |
| ------- | --------------------------- | ------------------- |
| type    | [TouchType](#touchtype-enums) | Type of the touch event.           |
| id      | number                      | Unique identifier of a finger.           |
| screenX | number                      | X-coordinate of the touch point relative to the left edge of the screen. |
| screenY | number                      | Y-coordinate of the touch point relative to the upper edge of the device screen. |
| x       | number                      | X-coordinate of the touch point relative to the left edge of the element being touched. |
| y       | number                      | Y-coordinate of the touch point relative to the upper edge of the element being touched. |


## TouchType Enums
| Name    | Description             |
| ------ | --------------- |
| Down   | A finger is pressed.       |
| Up     | A finger is lifted.       |
| Move   | A finger moves on the screen in pressed state.|
| Cancel | A touch event is canceled.     |


## Example

```ts
// xxx.ets
@Entry
@Component
struct TouchExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Button('Touch').backgroundColor(0x2788D9).height(40).width(80)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === TouchType.Up) {
            this.eventType = 'Up'
          }
          if (event.type === TouchType.Move) {
            this.eventType = 'Move'
          }
          console.info(this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
          + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\ncomponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height)
        })
      Text(this.text)
    }.height(200).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001212058464](figures/en-us_image_0000001212058464.gif)
