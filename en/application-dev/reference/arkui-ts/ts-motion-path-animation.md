# Motion Path Animation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set the motion path of the component in a translation animation.


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| motionPath | {<br/>path:&nbsp;string,<br/>from?:&nbsp;number,<br/>to?:&nbsp;number,<br/>rotatable?:&nbsp;boolean<br/>}<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;In&nbsp;a&nbsp;path,&nbsp;**start**&nbsp;and&nbsp;**end**&nbsp;can&nbsp;be&nbsp;used&nbsp;to&nbsp;replace&nbsp;the&nbsp;start&nbsp;point&nbsp;and&nbsp;end&nbsp;point.&nbsp;Example:<br/>>&nbsp;<br/>>&nbsp;'Mstart.x&nbsp;start.y&nbsp;L50&nbsp;50&nbsp;Lend.x&nbsp;end.y&nbsp;Z' | {<br/>"",<br/>0.0,<br/>1.0,<br/>false<br/>} | Motion&nbsp;path&nbsp;of&nbsp;the&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameters&nbsp;are&nbsp;described&nbsp;as&nbsp;follows:<br/>-&nbsp;**path**:&nbsp;motion&nbsp;path&nbsp;of&nbsp;the&nbsp;translation&nbsp;animation.&nbsp;The&nbsp;**svg**&nbsp;path&nbsp;string&nbsp;is&nbsp;used.<br/>-&nbsp;**from**:&nbsp;start&nbsp;point&nbsp;of&nbsp;the&nbsp;motion&nbsp;path.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0.0**.<br/>-&nbsp;**to**:&nbsp;end&nbsp;point&nbsp;of&nbsp;the&nbsp;motion&nbsp;path.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**1.0**.<br/>-&nbsp;**rotatable**:&nbsp;whether&nbsp;to&nbsp;rotate&nbsp;along&nbsp;the&nbsp;path. | 


## Example

  
```
@Entry
@Component
struct MotionPathExample {
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State toggle: boolean = true

  build() {
    Column() {
      Button('click me')
        .motionPath({ path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y', from: 0.0, to: 1.0, rotatable: true })
        .onClick((event: ClickEvent) => {
          animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle = !this.toggle;
          })
        }).backgroundColor(0x317aff)
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![en-us_image_0000001212378420](figures/en-us_image_0000001212378420.gif)
