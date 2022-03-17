# Mouse Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

  | Name | Bubble&nbsp;Supported | Description | 
| -------- | -------- | -------- |
| onHover(callback:&nbsp;(isHover:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) | No | Triggered&nbsp;when&nbsp;the&nbsp;mouse&nbsp;cursor&nbsp;enters&nbsp;or&nbsp;leaves&nbsp;the&nbsp;component.<br/>**isHover**:&nbsp;whether&nbsp;the&nbsp;mouse&nbsp;cursor&nbsp;hovers&nbsp;over&nbsp;the&nbsp;component.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;that&nbsp;the&nbsp;mouse&nbsp;cursor&nbsp;enters&nbsp;the&nbsp;component,&nbsp;and&nbsp;the&nbsp;value&nbsp;**false**&nbsp;means&nbsp;that&nbsp;the&nbsp;mouse&nbsp;cursor&nbsp;leaves&nbsp;the&nbsp;component. | 
| onMouse(callback:&nbsp;(event?:&nbsp;MouseEvent)&nbsp;=&gt;&nbsp;void) | Yes | Triggered&nbsp;when&nbsp;the&nbsp;component&nbsp;is&nbsp;clicked&nbsp;by&nbsp;a&nbsp;mouse&nbsp;button&nbsp;or&nbsp;the&nbsp;mouse&nbsp;cursor&nbsp;moves&nbsp;on&nbsp;the&nbsp;component.&nbsp;The&nbsp;**event**&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;timestamp,&nbsp;mouse&nbsp;button,&nbsp;action,&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;on&nbsp;the&nbsp;entire&nbsp;screen,&nbsp;and&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;component&nbsp;when&nbsp;the&nbsp;event&nbsp;is&nbsp;triggered. | 


### MouseEvent

- Attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | timestamp | number | Timestamp&nbsp;when&nbsp;the&nbsp;event&nbsp;is&nbsp;triggered. | 
  | screenX | number | X-coordinate&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;screen. | 
  | screenY | number | Y-coordinate&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;screen. | 
  | x | number | X-coordinate&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 
  | y | number | Y-coordinate&nbsp;of&nbsp;the&nbsp;clicked&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 
  | button | MouseButton | Mouse&nbsp;button. | 
  | action | MouseAction | Event&nbsp;action. | 


- MouseButton attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | Left | number | Left&nbsp;mouse&nbsp;button. | 
  | Right | number | Right&nbsp;mouse&nbsp;button. | 
  | Middle | number | Middle&nbsp;mouse&nbsp;button. | 
  | Back | number | Back&nbsp;button&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;mouse. | 
  | Forward | number | Forward&nbsp;button&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;mouse. | 
  | None | number | No&nbsp;button. | 

- MouseAction attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | Press | number | The&nbsp;mouse&nbsp;button&nbsp;is&nbsp;pressed. | 
  | Release | number | The&nbsp;mouse&nbsp;button&nbsp;is&nbsp;released. | 
  | Move | number | The&nbsp;mouse&nbsp;cursor&nbsp;moves. | 


## Example

  
```
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
