# Click Event

A click event is triggered when a component is clicked.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                      | Bubbling Supported| Description                             |
| ---------------------------------------- | ---- | --------------------------------- |
| onClick(event: (event?: ClickEvent) =&gt; void) | No   | Called when a click event occurs. For details about the event parameters, see **ClickEvent**.|

## ClickEvent
| Name           | Type                                | Description                                                    |
| ------------------- | ------------------------------------ | -------------------------------------------------------- |
| screenX             | number                               | X coordinate of the click relative to the upper left corner of the application window.                     |
| screenY             | number                               | Y coordinate of the click relative to the upper left corner of the application window.                     |
| x                   | number                               | X coordinate of the click relative to the upper left corner of the component being clicked.                   |
| y                   | number                               | Y coordinate of the click relative to the upper left corner of the component being clicked.                   |
| target<sup>8+</sup> | [EventTarget](#eventtarget8) | Target element that is clicked.                                        |
| timestamp           | number                               | Timestamp of the event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|

## EventTarget<sup>8+</sup>

| Name  | Type                     | Description        |
| ---- | ------------------------- | ---------- |
| area | [Area](ts-types.md#area8) | Area information of the target element.|



## Example

```ts
// xxx.ets
@Entry
@Component
struct ClickExample {
  @State text: string = ''

  build() {
    Column() {
      Button('Click').backgroundColor(0x2788D9).width(100).height(40)
        .onClick((event: ClickEvent) => {
          console.info(this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
          + '\n  x:' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\n  width:'
          + event.target.area.width + '\n  height:' + event.target.area.height)
        })
      Text(this.text).padding(15)
    }.height(350).width('100%').padding(10)
  }
}
```


![en-us_image_0000001256858383](figures/en-us_image_0000001256858383.gif)
