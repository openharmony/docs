# Interpolation Calculation


> **NOTE**
>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import curves from '@ohos.curves'
```


## Required Permissions

N/A


## curves.init

init(curve?: Curve): Object


Implements initialization for the interpolation curve, which is used to create an interpolation curve object based on the input parameter.


- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | curve | Curve | No | Linear | Curve object. |

- Return value
  
  Curve object.


## curves.steps

steps(count: number, end: boolean): Object


Constructs a step curve object.


- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | Yes | - | Number of steps. Must be a positive integer. |
  | end | boolean | Yes | true | Step change at the start or end point of each interval. Defaults to **true**, indicating that the step change occurs at the end point. |

- Return value
  
  Curve object.


## curves.cubicBezier

cubicBezier(x1: number, y1: number, x2: number, y2: number): Object


Constructs a third-order Bezier curve object. The curve value must be between 0 and 1.


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | x1 | number | Yes | Horizontal coordinate of the first point on the Bezier curve. |
  | y1 | number | Yes | Vertical coordinate of the first point on the Bezier curve. |
  | x2 | number | Yes | Horizontal coordinate of the second point on the Bezier curve. |
  | y2 | number | Yes | Vertical coordinate of the second point on the Bezier curve. |

- Return value
  
  Curve object.


## curves.spring

spring(velocity: number, mass: number, stiffness: number, damping: number): Object


Constructs a spring curve object.


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | velocity | number | Yes | Initial velocity. |
  | mass | number | Yes | Mass. |
  | stiffness | number | Yes | Stiffness. |
  | damping | number | Yes | Damping. |

- Return value
  
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
| interpolate(time: number): number | Calculation function of the interpolation curve. Passing a normalized time parameter to this function returns the current interpolation.<br/>**time**: indicates the current normalized time. The value ranges from 0 to 1.<br/>The curve interpolation corresponding to the normalized time point is returned. |


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
