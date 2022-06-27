# Click Event


> **NOTE**<br>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name | Bubble Supported | Description |
| -------- | -------- | -------- |
| onClick(callback: (event?: ClickEvent) =&gt; void) | No | Called when a click event occurs. For details about the event parameters, see [ClickEvent](#clickevent). |


### ClickEvent

| Name | Type | Description |
| -------- | -------- | -------- |
| screenX | number | X coordinate of the click relative to the left edge of the screen. |
| screenY | number | Y coordinate of the click relative to the upper edge of the screen. |
| x | number | X coordinate of the click relative to the left edge of the component being clicked. |
| y | number | Y coordinate of the click relative to the upper edge of the component being clicked. |
| target<sup>8+</sup> | EventTarget | Target element that is clicked. |
| timestamp | number | Timestamp of the event. |

- EventTarget<sup>8+</sup> attributes

    | Name | Type | Description |
    | -------- | -------- | -------- |
    | area | Area | Area information of the target element.|

- Area<sup>8+</sup> attributes

    | Name | Type | Description |
    | -------- | -------- | -------- |
    | width | number | Width of the target element, in vp. |
    | height | number | Height of the target element, in vp. |
    | position | Position | Position of the upper left corner of the target element relative to that of the parent element. |
    | globalPosition | Position | Position of the upper left corner of the target element relative to that of the page. |

- Position<sup>8+</sup> attributes

    | Name | Type | Description |
    | -------- | -------- | -------- |
    | x | number | X-coordinate, in vp. |
    | y | number | Y-coordinate, in vp. |


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
