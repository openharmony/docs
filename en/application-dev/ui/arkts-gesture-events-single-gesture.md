# Single Gesture


## TapGesture


```ts
TapGesture(value?:{count?:number; fingers?:number})
```


Tap gestures support single tap and multiple taps. There are two optional parameters:


- **count**: number of consecutive taps recognized by the tap gesture. This parameter is optional. The default value is 1. If this parameter is set to an invalid value less than 1, the default value is used. If multiple clicks are configured, the timeout interval for the previous lift and next press is 300 ms.

- **fingers**: number of fingers that trigger the touch. The minimum value is 1, and the maximum value is 10. The default value is 1. This parameter is optional. When multi-finger is configured, if the number of fingers used for tap does not reach the specified number within 300 ms after the first finger is tapped, the gesture fails to be recognized. Gesture recognition fails if the number of fingers used for tap exceeds the configured number.
    For example, to bind a double-tap gesture (a tap gesture whose count value is 2) to the Text component, run the following command:

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Index {
    @State value: string = "";
    
    build() {
      Column() {
        Text('Click twice').fontSize(28)
          .gesture(
            //Bind the TapGesture whose count is 2.
            TapGesture({ count: 2 })
              .onAction((event: GestureEvent) => {
                this.value = JSON.stringify(event.fingerList[0]);
              }))
        Text(this.value)
      }
      .height(200)
      .width(250)
      .padding(20)
      .border({ width: 3 })
      .margin(30)
    }
  }
  ```

  ![tap](figures/tap.gif)


## LongPressGesture


```ts
LongPressGesture(value?:{fingers?:number; repeat?:boolean; duration?:number})
```


The touch-and-hold gesture is used to trigger a touch-and-hold gesture event. The minimum quantity of fingers that trigger the touch-and-hold gesture is 1, the minimum touch-and-hold event is 500 milliseconds, and has three optional parameters:


- **fingers**: minimum number of fingers required to trigger the touch and hold gesture. The minimum value is 1 and the maximum value is 10. The default value is 1. This parameter is optional.

- **repeat**: whether to continuously trigger event callback. The default value is false. This parameter is optional. 

- **duration**: minimum duration (in milliseconds) required for triggering a long press. The default value is 500. This parameter is optional. 


The following describes how to bind a touch and hold gesture that can be repeatedly triggered to the Text component:



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State count: number = 0;

  build() {
    Column() {
      Text('LongPress OnAction:' + this.count).fontSize(28)
        .gesture(
          // Bind the LongPressGesture that can be triggered repeatedly.
          LongPressGesture({ repeat: true })
            .onAction((event: GestureEvent) => {
              if (event.repeat) {
                this.count++;
              }
            })
            .onActionEnd(() => {
              this.count = 0;
            })
        )
    }
    .height(200)
    .width(250)
    .padding(20)
    .border({ width: 3 })
    .margin(30)
  }
}
```


![longPress](figures/longPress.gif)


## PanGesture


```ts
PanGestureOptions(value?:{ fingers?:number; direction?:PanDirection; distance?:number})
```


Drag gestures are used to trigger drag gesture events. When the sliding distance reaches the minimum sliding distance (5vp by default), drag gestures are successfully identified. There are three optional parameters:


- **fingers**: minimum number of fingers required to trigger a drag gesture. This parameter is optional. The minimum value is 1 and the maximum value is 10. The default value is 1.

- **direction**: direction of the gesture that triggers the drag. This parameter is optional. The enumerated values support the AND and OR operations. The default value is **Pandirection.All.**

- **distance**: specifies the minimum drag recognition distance for triggering drag. This parameter is optional. The unit is vp. The default value is 5.


Binding a drag gesture to a Text component is used as an example. You can drag a component by modifying the layout position information of the component in the callback function of the drag gesture.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;

  build() {
    Column() {
      Text('PanGesture Offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
        .fontSize(28)
        .height(200)
        .width(300)
        .padding(20)
        .border({ width: 3 })
          //Bind the layout position information to the component.
        .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
        .gesture(
          //Bind drag gestures.
          PanGesture()
            .onActionStart((event: GestureEvent) => {
              console.info('Pan start');
            })
              //When the drag gesture is triggered, modify the layout position information of the component based on the callback function.
            .onActionUpdate((event: GestureEvent) => {
              this.offsetX = this.positionX + event.offsetX;
              this.offsetY = this.positionY + event.offsetY;
            })
            .onActionEnd(() => {
              this.positionX = this.offsetX;
              this.positionY = this.offsetY;
            })
        )
    }
    .height(200)
    .width(250)
  }
}
```


![pan](figures/pan.gif)


>**NOTE**
>
>Most sliding components, such as List, Grid, Scroll, and Tab, slide through PanGesture. Bind [Drag gesture (PanGesture)] (#Drag gesture pangesture) to subcomponents in the components. [SwipeGesture](#SwipeGesture swipegesture) will cause gesture competition.
>
>When a subcomponent is bound to PanGesture, sliding in the subcomponent area triggers only PanGesture of the subcomponent. If the parent component needs to respond, you need to modify the gesture binding method or transfer messages from the child component to the parent component, or modify the PanGesture parameter distance of the parent and child components to make the dragging more sensitive. When a subcomponent is bound to SwipeGesture, you need to modify the parameters of PanGesture and SwipeGesture to achieve the required effect because the triggering conditions of PanGesture and SwipeGesture are different.


## PinchGesture


```ts
PinchGesture(value?:{fingers?:number; distance?:number})
```


The pinch gesture is used to trigger a pinch gesture event. A minimum quantity of fingers that trigger the pinch gesture is two fingers, a maximum quantity of fingers that trigger the pinch gesture is five fingers, a minimum recognition distance is 3vp, and there are two optional parameters:


- fingers: specifies the minimum number of fingers required to trigger a pinch gesture. This parameter is optional. The minimum value is 2 and the maximum value is 5. The default value is 2.

- distance: specifies the minimum distance for triggering the pinch gesture. This parameter is optional. The unit is vp. The default value is 3.


For example, to bind a three-finger pinch gesture to the Column component, you can obtain the zoom ratio from the function callback of the pinch gesture to zoom out or zoom in the component.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State scaleValue: number = 1;
  @State pinchValue: number = 1;
  @State pinchX: number = 0;
  @State pinchY: number = 0;

  build() {
    Column() {
      Column() {
        Text('PinchGesture scale:\n' + this.scaleValue)
        Text('PinchGesture center:\n(' + this.pinchX + ',' + this.pinchY + ')')
      }
      .height(200)
      .width(300)
      .border({ width: 3 })
      .margin({ top: 100 })
      // Bind the zoom ratio to the component. You can change the zoom ratio to zoom out or zoom in the component.
      .scale({ x: this.scaleValue, y: this.scaleValue, z: 1 })
      .gesture(
        // Bind the pinch gesture triggered by three fingers to the widget.
        PinchGesture({ fingers: 3 })
          .onActionStart((event: GestureEvent) => {
            console.info('Pinch start');
          })
            // When the pinch gesture is triggered, the callback function can be used to obtain the zoom ratio to change the zoom ratio of the component.
          .onActionUpdate((event: GestureEvent) => {
            this.scaleValue = this.pinchValue * event.scale;
            this.pinchX = event.pinchCenterX;
            this.pinchY = event.pinchCenterY;
          })
          .onActionEnd(() => {
            this.pinchValue = this.scaleValue;
            console.info('Pinch end');
          })
      )
    }
  }
}
```


![pinch](figures/pinch.png)


## RotationGesture


```ts
RotationGesture(value?:{fingers?:number; angle?:number})
```


The rotation gesture is used to trigger a rotation gesture event. A minimum quantity of fingers that trigger the rotation gesture is two fingers, a maximum quantity of fingers that trigger the rotation gesture is five fingers, a minimum change degree is one degree, and there are two optional parameters:


- **fingers**: minimum number of fingers required to trigger a rotation gesture. This parameter is optional. The minimum value is 2 and the maximum value is 5. The default value is 2.

- **angle**: minimum change degree for triggering the rotation gesture. This parameter is optional. The unit is deg. The default value is 1.


For example, a rotation gesture is bound to a **\<Text>** component to implement rotation of the component. A rotation angle may be obtained from a callback function of the rotation gesture, so as to implement rotation of the component:



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State angle: number = 0;
  @State rotateValue: number = 0;

  build() {
    Column() {
      Text('RotationGesture angle:' + this.angle).fontSize(28)
        // Bind the rotation layout to the component. You can change the rotation angle to rotate the component.
        .rotate({ angle: this.angle })
        .gesture(
          RotationGesture()
            .onActionStart((event: GestureEvent) => {
              console.info('RotationGesture is onActionStart');
            })
              // When the rotation gesture takes effect, the rotation angle is obtained by using the callback function of the rotation gesture, so as to modify the rotation angle of the component.
            .onActionUpdate((event: GestureEvent) => {
              this.angle = this.rotateValue + event.angle;
              console.info('RotationGesture is onActionEnd');
            })
              // Angle of the fixed component at the end of the rotation when the rotation ends and the handle is raised
            .onActionEnd(() => {
              this.rotateValue = this.angle;
              console.info('RotationGesture is onActionEnd');
            })
            .onActionCancel(() => {
              console.info('RotationGesture is onActionCancel');
            })
        )
    }
    .height(200)
    .width(250)
  }
}
```


![rotation](figures/rotation.png)


## SwipeGesture


```ts
SwipeGesture(value?:{fingers?:number; direction?:SwipeDirection; speed?:number})
```


Swipe gestures are used to trigger swipe events. A swipe gesture is recognized when the swipe speed is 100 vp/s or higher. There are three optional parameters:


- **fingers**: minimum number of fingers required to trigger a swipe gesture. This parameter is optional. The minimum value is 1 and the maximum value is 10. The default value is 1.

- **direction**: Swipe direction. This parameter is optional. The enumerated values support the AND and OR operations. The default value is **SwipeDirection.All**.

- **speed**: minimum speed of the swipe gesture, in vp/s.This parameter is optional. The default value is 100.


The following describes how to bind a sliding gesture to the Column component to rotate the component:



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State rotateAngle: number = 0;
  @State speed: number = 1;

  build() {
    Column() {
      Column() {
        Text("SwipeGesture speed\n" + this.speed)
        Text("SwipeGesture angle\n" + this.rotateAngle)
      }
      .border({ width: 3 })
      .width(300)
      .height(200)
      .margin(100)
      // Bind rotation to the Column component and change the rotation angle based on the sliding speed and angle of the sliding gesture.
      .rotate({ angle: this.rotateAngle })
      .gesture(
        // Bind the sliding gesture and restrict it to be triggered only when the user slides in the vertical direction.
        SwipeGesture({ direction: SwipeDirection.Vertical })
          //When the sliding gesture is triggered, obtain the sliding speed and angle to modify the layout parameters of the component.
          .onAction((event: GestureEvent) => {
            this.speed = event.speed;
            this.rotateAngle = event.angle;
          })
      )
    }
  }
}
```


![swipe](figures/swipe.gif)


>**NOTE**
>
>When SwipeGesture and PanGesture are bound at the same time, competition occurs if they are bound in default mode or mutually exclusive mode. The trigger condition of SwipeGesture is that the sliding speed reaches 100 vp/s. The trigger condition of PanGesture is that the sliding distance reaches 5 vp and the trigger condition is met first. You can modify the parameters of SwipeGesture and PanGesture to achieve different effects.
