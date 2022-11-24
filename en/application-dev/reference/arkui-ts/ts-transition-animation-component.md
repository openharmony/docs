# Component Transition

Configure the component transition animations for when a component is inserted or deleted. This feature takes effect only when [animateTo](ts-explicit-animation.md) is used. The animation duration, curve, and delay are the same as those configured in **animateTo**.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name| Type| Description|
| -------- | -------- | -------- |
| transition | Object | Transition parameters, which are all optional. For details, see **transition**. |

- transition

  | Name      | Type                                                         | Mandatory | Description                                                  |
  | --------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
  | type      | [TransitionType](ts-appendix-enums.md#transitiontype)        | No        | Transition type, which includes component addition and deletion by default.<br>Default value: **TransitionType.All**<br>**NOTE**<br>If **type** is not specified, insertion and deletion use the same transition type. |
  | opacity   | number                                                       | No        | Opacity of the component during transition, which is the value of the start point of insertion and the end point of deletion.<br>Default value: **1** |
  | translate | {<br>x? : number,<br>y? : number,<br>z? : number<br>}        | No        | Translation of the component during transition, which is the value of the start point of insertion and the end point of deletion.<br>-**x**: distance to translate along the x-axis.<br>-**y**: distance to translate along the y-axis.<br>-**z**: distance to translate along the z-axis. |
  | scale     | {<br>x? : number,<br>y? : number,<br>z? : number,<br>centerX? : number,<br>centerY? : number<br>} | No        | Scaling of the component during transition, which is the value of the start point of insertion and the end point of deletion.<br>- **x**: scale factor along the x-axis.<br>- **y**: scale factor along the y-axis.<br>- **z**: scale factor along the z-axis.<br>- **centerX** and **centerY**: x coordinate and y coordinate of the scale center, respectively.<br>- If the center point is 0, it indicates the upper left corner of the component.<br> |
  | rotate    | {<br>x?: number,<br>y?: number,<br>z?: number,<br>angle?: Angle,<br>centerX?: Length,<br>centerY?: Length<br>} | No        | Rotation of the component during transition, which is the value of the start point of insertion and the end point of deletion.<br>- **x**: rotation vector along the x-axis.<br>- **y**: rotation vector along the y-axis.<br>- **z**: rotation vector along the z-axis.<br>- **centerX** and **centerY**: x coordinate and y coordinate of the rotation center, respectively.<br>- If the center point is (0, 0), it indicates the upper left corner of the component. |


## Example

The following example shows how to use a button to control the appearance and disappearance of another button, and how to configure the required transition animations.

```ts
// xxx.ets
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
