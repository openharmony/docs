# Click Event

A click event is triggered when a component is clicked.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                      | Bubbling Supported| Description                             |
| ---------------------------------------- | ---- | --------------------------------- |
| onClick(event: (event?: ClickEvent) =&gt; void) | No   | Called when a click event occurs. For details about **event**, see **ClickEvent**.<br>Since API version 9, this API is supported in ArkTS widgets.|

## ClickEvent

Since API version 9, this API is supported in ArkTS widgets.

| Name           | Type                                | Description                                                    |
| ------------------- | ------------------------------------ | -------------------------------------------------------- |
| screenX             | number                               | X coordinate of the click relative to the upper left corner of the application window.                     |
| screenY             | number                               | Y coordinate of the click relative to the upper left corner of the application window.                     |
| x                   | number                               | X coordinate of the click relative to the upper left corner of the component being clicked.                   |
| y                   | number                               | Y coordinate of the click relative to the upper left corner of the component being clicked.                   |
| timestamp<sup>8+</sup> | number | Timestamp of the event. It is the interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
| target<sup>8+</sup> | [EventTarget](#eventtarget8) | Display area of the object that triggers the event.|
| source<sup>8+</sup> | [SourceType](ts-gesture-settings.md#sourcetype)| Event input device.|

## EventTarget<sup>8+</sup>

Since API version 9, this API is supported in ArkTS widgets.

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
      Row({ space: 20 }) {
        Button('Click').width(100).height(40)
          .onClick((event: ClickEvent) => {
            this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
            + '\n  x:' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\n  width:'
            + event.target.area.width + '\n  height:' + event.target.area.height + '\ntimestamp' + event.timestamp;
          })
        Button('Click').width(200).height(50)
          .onClick((event: ClickEvent) => {
            this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
            + '\n  x:' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\n  width:'
            + event.target.area.width + '\n  height:' + event.target.area.height + '\ntimestamp' + event.timestamp;
          })
      }.margin(20)

      Text(this.text).margin(15)
    }.width('100%')
  }
}
```


![en-us_image_0000001256858383](figures/en-us_image_0000001256858383.gif)
