# Interpolation Calculation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

  
```
import curves from '@ohos.curves'
```


## Required Permissions

None


## curves.init

init(curve?: Curve): Object


Implements initialization for the interpolation curve, which is used to create an interpolation curve object based on the input parameter.


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | curve | Curve | No | Linear | Curve&nbsp;object. | 

- Return values
  Curve object.


## curves.steps

steps(count: number, end: boolean): Object


Constructs a step curve object.


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | Yes | - | Number&nbsp;of&nbsp;steps.&nbsp;Must&nbsp;be&nbsp;a&nbsp;positive&nbsp;integer. | 
  | end | boolean | No | true | Step&nbsp;change&nbsp;at&nbsp;the&nbsp;start&nbsp;or&nbsp;end&nbsp;point&nbsp;of&nbsp;each&nbsp;interval.&nbsp;Defaults&nbsp;to&nbsp;**true**,&nbsp;indicating&nbsp;that&nbsp;the&nbsp;step&nbsp;change&nbsp;occurs&nbsp;at&nbsp;the&nbsp;end&nbsp;point. | 

- Return values
  Curve object.


## curves.cubicBezier

cubicBezier(x1: number, y1: number, x2: number, y2: number): Object


Constructs a third-order Bezier curve object. The curve value must be between 0 and 1.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | x1 | number | Yes | Horizontal&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;point&nbsp;on&nbsp;the&nbsp;Bezier&nbsp;curve. | 
  | y1 | number | Yes | Vertical&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;point&nbsp;on&nbsp;the&nbsp;Bezier&nbsp;curve. | 
  | x2 | number | Yes | Horizontal&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;point&nbsp;on&nbsp;the&nbsp;Bezier&nbsp;curve. | 
  | y2 | number | Yes | Vertical&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;point&nbsp;on&nbsp;the&nbsp;Bezier&nbsp;curve. | 

- Return values
  Curve object.


## curves.spring

spring(velocity: number, mass: number, stiffness: number, damping: number): Object


Constructs a spring curve object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | velocity | number | Yes | Initial&nbsp;velocity. | 
  | mass | number | Yes | Mass. | 
  | stiffness | number | Yes | Stiffness. | 
  | damping | number | Yes | Damping. | 

- Return values
  Curve object.


## Example

  
```
import Curves from '@ohos.curves'
let curve1 = Curves.init() // Create a default linear interpolation curve.
let curve2 = Curves.init(Curve.EaseIn) // Create an interpolation curve which is slow and then fast by default.
let curve3 = Curves.spring(100, 1, 228, 30) // Create a spring interpolation curve.
let curve3 = Curves.cubicBezier(0.1, 0.0, 0.1, 1.0) // Create a third-order Bezier curve.
```


  Curve objects can be created only by the preceding APIs.
  | API | Description | 
| -------- | -------- |
| interpolate(time:&nbsp;number):&nbsp;number | Calculation&nbsp;function&nbsp;of&nbsp;the&nbsp;interpolation&nbsp;curve.&nbsp;Passing&nbsp;a&nbsp;normalized&nbsp;time&nbsp;parameter&nbsp;to&nbsp;this&nbsp;function&nbsp;returns&nbsp;the&nbsp;current&nbsp;interpolation.<br/>**time**:&nbsp;indicates&nbsp;the&nbsp;current&nbsp;normalized&nbsp;time.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;1.<br/>The&nbsp;curve&nbsp;interpolation&nbsp;corresponding&nbsp;to&nbsp;the&nbsp;normalized&nbsp;time&nbsp;point&nbsp;is&nbsp;returned. | 


- Example
    
  ```
  import Curves from '@ohos.curves'
  let curve = Curves.init(Curve.EaseIn) // Create an interpolation curve which is slow and then fast by default.
  let value: number = curve.interpolate(0.5) // Calculate the interpolation for half of the time.
  ```


## Example

  
```
import Curves from '@ohos.curves'
@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200
  @State heightSize: number = 200
  build() {
    Column() {
      Text()
        .margin({top:100})
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(()=> {
          let curve = Curves.cubicBezier(0.25, 0.1, 0.25, 1.0);
          this.widthSize = curve.interpolate(0.5) * this.widthSize;
          this.heightSize = curve.interpolate(0.5) * this.heightSize;
        })
        .animation({duration: 2000 , curve: Curves.spring(0.25, 0.1, 0.25, 1.0)})
    }.width("100%").height("100%")
  }
}
```

![en-us_image_0000001212058456](figures/en-us_image_0000001212058456.gif)
