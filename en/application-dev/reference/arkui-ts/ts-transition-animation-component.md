# Component Transition


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


Configure the component transition animations for when a component is inserted or deleted, which improves user experience. This feature takes effect only when **animateTo** is used. The animation duration, curve, and delay are the same as those configured in **animateTo**.


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| transition | Object | - | All&nbsp;parameters&nbsp;are&nbsp;optional.&nbsp;For&nbsp;details,&nbsp;see&nbsp;**transition**&nbsp;parameters. | 

- transition parameters
    | Name | Type | Default&nbsp;Value | Mandatory | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | type | TransitionType | TransitionType.All | No | Transition&nbsp;type,&nbsp;which&nbsp;includes&nbsp;component&nbsp;addition&nbsp;and&nbsp;deletion&nbsp;by&nbsp;default.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;If&nbsp;**type**&nbsp;is&nbsp;not&nbsp;specified,&nbsp;insertion&nbsp;and&nbsp;deletion&nbsp;use&nbsp;the&nbsp;same&nbsp;transition&nbsp;type. | 
  | opacity | number | 1 | No | Opacity&nbsp;effect&nbsp;during&nbsp;component&nbsp;transition,&nbsp;which&nbsp;is&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;of&nbsp;insertion&nbsp;and&nbsp;the&nbsp;end&nbsp;point&nbsp;of&nbsp;deletion. | 
  | translate | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number<br/>} | - | No | Translation&nbsp;effect&nbsp;during&nbsp;component&nbsp;transition,&nbsp;which&nbsp;is&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;of&nbsp;insertion&nbsp;and&nbsp;the&nbsp;end&nbsp;point&nbsp;of&nbsp;deletion. | 
  | scale | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number,<br/>centerY?&nbsp;:&nbsp;number<br/>} | - | No | Scaling&nbsp;effect&nbsp;during&nbsp;component&nbsp;transition,&nbsp;which&nbsp;is&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;of&nbsp;insertion&nbsp;and&nbsp;the&nbsp;end&nbsp;point&nbsp;of&nbsp;deletion. | 
  | rotate | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>angle?:&nbsp;Angle,<br/>centerX?:&nbsp;Length,<br/>centerY?:&nbsp;Length<br/>} | - | No | Rotation&nbsp;effect&nbsp;during&nbsp;component&nbsp;transition,&nbsp;which&nbsp;is&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;of&nbsp;insertion&nbsp;and&nbsp;the&nbsp;end&nbsp;point&nbsp;of&nbsp;deletion. | 

- TransitionType enums
    | Name | Description | 
  | -------- | -------- |
  | All | The&nbsp;transition&nbsp;takes&nbsp;effect&nbsp;in&nbsp;all&nbsp;scenarios. | 
  | Insert | The&nbsp;transition&nbsp;takes&nbsp;effect&nbsp;when&nbsp;a&nbsp;component&nbsp;is&nbsp;inserted. | 
  | Delete | The&nbsp;transition&nbsp;takes&nbsp;effect&nbsp;when&nbsp;a&nbsp;component&nbsp;is&nbsp;deleted. | 


## Example

The following example shows how to use a button to control the appearance and disappearance of another button, and how to configure the required transition animations.

  
```
@Entry
@Component
struct TransitionExample {
  @State btn1: boolean = false
  @State show: string = "show"
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center,}) {
      Button(this.show).width(80).height(30).backgroundColor(0x317aff).margin({bottom:50})
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.btn1 = !this.btn1
            if(this.btn1){
              this.show = "hide"
            }else{
              this.show = "show"
            }
          })
        })
      if (this.btn1) {
        // The insertion and deletion have different transition effects.
        Button() {
          Image($r('app.media.bg1')).width("80%").height(300)
        }.transition({ type: TransitionType.Insert, scale : {x:0,y:1.0} })
        .transition({ type: TransitionType.Delete, scale: { x: 1.0, y: 0.0 } })
      }
    }.height(400).width("100%").padding({top:100})
  }
}
```

![en-us_image_0000001211898498](figures/en-us_image_0000001211898498.gif)
