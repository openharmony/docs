# Combined Gestures


A combined gesture consists of multiple single gestures. Different GestureModes are used in GestureGroup to declare the type of the combined gesture. [Continuous recognition](#continuous-recognition), [parallel recognition](#parallel-recognition), and [exclusive recognition](#exclusive-recognition) are supported for a group of gestures.



```ts
GestureGroup(mode:GestureMode, ...gesture:GestureType[])
```


- **mode**:  declare a type of the combined gesture. This parameter is mandatory and belongs to the GestureMode enumeration class.

- **gesture**: array consisting of multiple gestures. This parameter is mandatory.  .


## Continuous Recognition

For continuous recognition, **GestureMode** corresponding to the combined gesture is **Sequence**. Continuous recognition of combined gestures will recognize gestures according to the registration sequence of gestures until all gestures are recognized successfully. When one gesture in the continuously recognized combined gestures fails to be recognized, all gestures fail to be recognized.

A continuous gesture formed by combining a touch-and-hold gesture and a drag gesture is used as an example.

The translate attribute is bound to a Column component. You can modify the attribute to move the component. Then, bind the sequence gesture combined by LongPressGesture and PanGesture to the component. When LongPressGesture is triggered, the displayed number is updated. When a user drags a widget after touching and holding the widget, the widget is dragged based on the callback function of the drag gesture.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State count: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;
  @State borderStyles: BorderStyle = BorderStyle.Solid

  build() {
    Column() {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
        .fontSize(28)
    }
    //Bind the translate attribute to move the component.
    .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
    .height(250)
    .width(300)
    // The following combined gestures are identified in sequence. When the touch and hold gesture event is not triggered normally, the drag gesture event is not triggered.
    .gesture(
      // Declare that the type of the combined gesture is the Sequence type.
      GestureGroup(GestureMode.Sequence,
        // The first gesture triggered by the combined gesture is a touch-and-hold gesture, and the touch-and-hold gesture can be responded to for multiple times.
        LongPressGesture({ repeat: true })
          // Increase the count displayed on the Text component when the touch and hold gesture is successfully recognized.
          .onAction((event: GestureEvent) => {
            if (event.repeat) {
              this.count++;
            }
            console.info('LongPress onAction');
          })
          .onActionEnd(() => {
            console.info('LongPress end');
          }),
        // The PanGesture gesture is triggered when you drag the slider after touching and holding the slider.
        PanGesture()
          .onActionStart(() => {
            this.borderStyles = BorderStyle.Dashed;
            console.info('pan start');
          })
            // When the gesture is triggered, the dragging distance is obtained according to the callback, and the displacement distance of the component is modified to move the component.
          .onActionUpdate((event: GestureEvent) => {
            this.offsetX = this.positionX + event.offsetX;
            this.offsetY = this.positionY + event.offsetY;
            console.info('pan update');
          })
          .onActionEnd(() => {
            this.positionX = this.offsetX;
            this.positionY = this.offsetY;
            this.borderStyles = BorderStyle.Solid;
          })
      )
    )
  }
}
```


![sequence](figures/sequence.gif)


>**NOTE**
>
>The drag event is a typical continuous recognition combined gesture event, and is formed by combining a touch and hold gesture event and a slide gesture event. The drag event is triggered only when the user touches and holds the gesture for a preset period of time. If the touch and hold event is not reached or the slider is not performed after the touch and hold event, the drag event fails to be identified.


## Parallel Recognition

For parallel recognition, **GestureMode** corresponding to the combined gesture is **Parallel**. Parallel recognition of gestures registered in the combined gestures will be recognized at the same time until all gestures are recognized. The gestures in the gesture combination are recognized in parallel without affecting each other.

For example, a parallel recognition gesture formed by a tap gesture and a double-tap gesture is bound to a Column component. Because the tap gesture and the double-tap gesture are recognized in parallel, the two gestures may be recognized at the same time, and the two gestures do not interfere with each other.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State count1: number = 0;
  @State count2: number = 0;

  build() {
    Column() {
      Text('parallel gesture\n' + 'tapGesture count is 1:' + this.count1 + '\ntapGesture count is 2:' + this.count2 + '\n')
        .fontSize(28)
    }
    .height(200)
    .width(250)
    // The following combined gestures are parallel. After the tap gesture is recognized successfully, if you tap the gesture again within the specified time, the double-tap gesture will also be recognized successfully.
    .gesture(
      GestureGroup(GestureMode.Parallel,
        TapGesture({ count: 1 })
          .onAction(() => {
            this.count1++;
          }),
        TapGesture({ count: 2 })
          .onAction(() => {
            this.count2++;
          })
      )
    )
  }
}
```


![parallel](figures/parallel.gif)


>**NOTE**
>
>After a tap gesture and a double-tap gesture form a parallel recognition combined gesture, when a tap is performed in an area, the tap gesture and the double-tap gesture are recognized at the same time.
>
>When there is only a single tap, the tap gesture is recognized successfully, but the double-tap gesture fails to be recognized.
>
>When there are two clicks, if the interval between the two clicks is within a specified period (300 ms by default), two click events and one double-click event are triggered.
>
>When there are two clicks, if the interval between the two clicks exceeds the specified time, the two clicks are triggered but the double-click event is not triggered.


## Exclusive Recognition

For exclusive recognition, **GestureMode** corresponding to the combined gesture is **Exclusive**. The gestures registered in the mutually exclusive recognition combination gesture are recognized at the same time. If one gesture is recognized successfully, the gesture recognition ends, and all other gestures fail to be recognized.

A mutually exclusive recognition combination gesture formed by binding a click gesture and a double-tap gesture to a Column component is used as an example. Because a click gesture can be triggered only once and a double-tap gesture needs to be triggered twice, each click event is consumed by the click gesture and cannot be accumulated into a double-tap gesture, the double-tap gesture cannot be triggered.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State count1: number = 0;
  @State count2: number = 0;

  build() {
    Column() {
      Text('parallel gesture\n' + 'tapGesture count is 1:' + this.count1 + '\ntapGesture count is 2:' + this.count2 + '\n')
        .fontSize(28)
    }
    .height(200)
    .width(250)
    //The following combined gestures are mutually exclusive. After the tap gesture is recognized successfully, the double-tap gesture fails to be recognized.
    .gesture(
      GestureGroup(GestureMode.Exclusive,
        TapGesture({ count: 1 })
          .onAction(() => {
            this.count1++;
          }),
        TapGesture({ count: 2 })
          .onAction(() => {
            this.count2++;
          })
      )
    )
  }
}
```


![exclusive](figures/exclusive.gif)


>**NOTE**
>
>After the tapping gesture and the double-tap gesture form a mutually exclusive recognition combination gesture, when tapping is performed in the area, the tapping gesture and the double-tap gesture are recognized at the same time.
>
>When there is only a single tap, the tap gesture is recognized successfully, but the double-tap gesture fails to be recognized.
>
>When there are two taps, the tap gesture declares that the recognition is successful when the tap gesture is tapped for the first time. In this case, the double-tap gesture has failed. Even if the second tap is performed within the specified time, the double-tap gesture event is not responded. In this case, the second recognition success of the tap gesture event is triggered.
