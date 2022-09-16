# Mouse Event

If an action triggers multiple events, the order of these events is fixed. By default, mouse events are transmitted transparently.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name | Bubbling Supported | Description |
| -------- | -------- | -------- |
| onHover(callback: (isHover?: boolean) =&gt; void) | No | Triggered when the mouse cursor enters or leaves the component.<br/>**isHover**: whether the mouse cursor hovers over the component. The value **true** means that the mouse cursor enters the component, and the value **false** means that the mouse cursor leaves the component. |
| onMouse(callback: (event?: MouseEvent) =&gt; void) | Yes | Triggered when the component is clicked by a mouse button or the mouse cursor moves on the component. The **event** parameter indicates the timestamp, mouse button, action, coordinates of the clicked point on the entire screen, and coordinates of the clicked point relative to the component when the event is triggered. |


## MouseEvent

| Name | Type | Description |
| -------- | -------- | -------- |
| timestamp | number | Timestamp when the event is triggered. |
| screenX | number | X-coordinate of the clicked point relative to the upper left corner of the screen. |
| screenY | number | Y-coordinate of the clicked point relative to the upper left corner of the screen. |
| x | number | X-coordinate of the clicked point relative to the upper left corner of the component. |
| y | number | Y-coordinate of the clicked point relative to the upper left corner of the component. |
| button | [MouseButton](ts-appendix-enums.md#mousebutton) | Mouse button. |
| action | [MouseAction](ts-appendix-enums.md#mouseaction) | Event action. |

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
