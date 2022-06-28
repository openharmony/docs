# SwipeGesture


> **NOTE**<br>
> This gesture is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10. |
  | direction | SwipeDirection | No | SwipeDirection.All | Swipe direction. |
  | speed | number | No | 100 | Minimum speed of the swipe gesture (100 vp/s). |

- SwipeDirection enums
  | Name | Description |
  | -------- | -------- |
  | All | All directions. |
  | Horizontal | Horizontal direction. |
  | Vertical | Vertical direction. |


## Events

| Name | Description |
| -------- | -------- |
| onAction(callback:(event?: GestureEvent) =&gt; void) | Callback invoked when a swipe gesture is recognized. |


- GestureEvent attributes related to the swipe gesture  
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | angle | number | Angle of the swipe gesture.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE**<br/>>&nbsp;Angle calculation method: After the swipe gesture is identified, a line connecting the two fingers is identified as the initial line. As the fingers swipe, the line between the fingers rotates. Based on the coordinates of the initial line's and current line's end points, an arc tangent function is used to calculate the respective included angle of the points relative to the horizontal direction. Rotation angle = arctan2(cy2-cy1,cx2-cx1) - arctan2(y2-y1,x2-x1). The initial line is used as the coordinate system. The clockwise rotation is 0 to 180 degrees, and the counter-clockwise rotation is –180 to 0 degrees. |
  | speed | number | Speed of the swipe gesture. |

![en-us_image_0000001231374559](figures/en-us_image_0000001231374661.png)

## Example


```
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle : number = 0
  @State speed : number = 1

  build() {
    Column() {
      Text("SwipGesture speed : " + this.speed)
      Text("SwipGesture angle : " + this.rotateAngle)
    }
    .position({x: 80, y: 200})
    .border({width:2})
    .width(260).height(260)
    .rotate({x: 0, y: 0, z: 1, angle: this.rotateAngle})
    .gesture(
      SwipeGesture({fingers: 1, direction:SwipeDirection.Vertical})
        .onAction((event: GestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![en-us_image_0000001231374559](figures/en-us_image_0000001231374559.gif)
