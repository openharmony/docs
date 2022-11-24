# Mouse Event

If an action triggers multiple events, the order of these events is fixed. By default, mouse events are transmitted transparently.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                                        | Bubbling Supported| Description                                                        |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| onHover(event: (isHover: boolean) =&gt; void) | No      | Triggered when the mouse cursor enters or leaves the component.<br>**isHover**: whether the mouse cursor hovers over the component. The value **true** means that the mouse cursor enters the component, and the value **false** means that the mouse cursor leaves the component.|
| onMouse(event: (event?: MouseEvent) =&gt; void) | Yes      | Triggered when the component is clicked by a mouse button or the mouse cursor moves on the component. The **event** parameter indicates the timestamp, mouse button, action, coordinates of the clicked point on the entire screen, and coordinates of the clicked point relative to the component when the event is triggered.|


## MouseEvent

| Name     | Type                           | Description                  |
| --------- | ------------------------------- | -------------------- |
| screenX   | number                          | X coordinate of the click point relative to the upper left corner of the application window.|
| screenY   | number                          | Y coordinate of the click point relative to the upper left corner of the application window.|
| x         | number                          | X coordinate of the click point relative to the upper left corner of the component being clicked.|
| y         | number                          | Y coordinate of the click point relative to the upper left corner of the component being clicked.|
| button    | [MouseButton](ts-appendix-enums.md#mousebutton) | Mouse button.               |
| action    | [MouseAction](ts-appendix-enums.md#mouseaction) | Event action.               |
| stopPropagation      | () => void | Stops the event from bubbling upwards or downwards.                        |
| timestamp<sup>8+</sup> | number | Timestamp of the event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.         |
| target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md) | Display area of the component that triggers the event.|
| source<sup>8+</sup> | [SourceType](ts-gesture-settings.md) | Event input device.          |

## Example

```ts
// xxx.ets
@Entry
@Component
struct MouseEventExample {
  @State hoverText: string = 'no hover'
  @State mouseText: string = 'MouseText'
  @State color: Color = Color.Blue

  build() {
    Column({ space:20 }) {
      Button(this.hoverText)
        .onHover((isHover: boolean) => {
          if (isHover) {
            this.hoverText = 'on hover'
            this.color = Color.Pink
          } else {
            this.hoverText = 'no hover'
            this.color = Color.Blue
          }
        })
        .backgroundColor(this.color)
      Button('onMouse')
        .onMouse((event: MouseEvent) => {
          console.log(this.mouseText = 'onMouse:\nButton = ' + event.button + 
          '\nAction = ' + event.action + '\nlocalXY=(' + event.x + ',' + event.y + ')' + 
          '\nscreenXY=(' + event.screenX + ',' + event.screenY + ')')
        })
      Text(this.mouseText)
    }.padding({ top: 20 }).width('100%')
  }
}
```
