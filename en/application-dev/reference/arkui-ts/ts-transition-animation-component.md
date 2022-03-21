# Component Transition


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


Configure the component transition animations for when a component is inserted or deleted, which improves user experience. This feature takes effect only when **animateTo** is used. The animation duration, curve, and delay are the same as those configured in **animateTo**.


## Attributes

  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| transition | Object | - | All parameters are optional. For details, see **transition** parameters. | 

- transition parameters
    | Name | Type | Default Value | Mandatory | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | type | TransitionType | TransitionType.All | No | Transition type, which includes component addition and deletion by default.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> If **type** is not specified, insertion and deletion use the same transition type. | 
  | opacity | number | 1 | No | Opacity effect during component transition, which is the value of the start point of insertion and the end point of deletion. | 
  | translate | {<br/>x? : number,<br/>y? : number,<br/>z? : number<br/>} | - | No | Translation effect during component transition, which is the value of the start point of insertion and the end point of deletion. | 
  | scale | {<br/>x? : number,<br/>y? : number,<br/>z? : number,<br/>centerX? : number,<br/>centerY? : number<br/>} | - | No | Scaling effect during component transition, which is the value of the start point of insertion and the end point of deletion. | 
  | rotate | {<br/>x?: number,<br/>y?: number,<br/>z?: number,<br/>angle?: Angle,<br/>centerX?: Length,<br/>centerY?: Length<br/>} | - | No | Rotation effect during component transition, which is the value of the start point of insertion and the end point of deletion. | 

- TransitionType enums
    | Name | Description | 
  | -------- | -------- |
  | All | The transition takes effect in all scenarios. | 
  | Insert | The transition takes effect when a component is inserted. | 
  | Delete | The transition takes effect when a component is deleted. | 


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
