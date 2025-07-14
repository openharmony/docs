# Touchscreen Event


Touchscreen events are events triggered when a finger or stylus is placed on, moved along, or lifted from a component. They can be classified as [click event](#click-event), [drag event](arkts-common-events-drag-event.md), or [touch event](#touch-event).


**Figure 1** Touchscreen event principles


![en-us_image_0000001562700461](figures/en-us_image_0000001562700461.png)


## Click Event

A click event is triggered when a press and lift action is performed by using a finger or a stylus. When a click event occurs, the following callback is triggered:



```ts
onClick(event: (event?: ClickEvent) => void)
```


The **event** parameter provides the coordinates of the click relative to the window or component as well as the event source where the click occurs, for example, a button, a click on which shows or hides an image.

```ts
@Entry
@Component
struct IfElseTransition {
  @State flag: boolean = true;
  @State btnMsg: string = 'show';

  build() {
    Column() {
      Button(this.btnMsg).width(80).height(30).margin(30)
        .onClick(() => {
          if (this.flag) {
            this.btnMsg = 'hide';
          } else {
            this.btnMsg = 'show';
          }
          // Click the button to show or hide the image.
          this.flag = !this.flag;
        })
      if (this.flag) {
        Image($r('app.media.icon')).width(200).height(200)
      }
    }.height('100%').width('100%')
  }
}
```
**Figure 2** Controlling the image visibility through the click event of a button


![ClickEventControl.gif](figures/ClickEventControl.gif)



## Touch Event

A touch event is triggered when a finger or stylus is placed on, moved along, or lifted from a component.


```ts
onTouch(event: (event?: TouchEvent) => void)
```

- If **event.type** is **TouchType.Down**, the finger or stylus is placed on the component.

- If **event.type** is **TouchType.Up**, the finger or stylus is lifted from the component.

- If **event.type** is **TouchType.Move**, the finger or stylus is moved along the component.

- If **event.type** is **TouchType.Cancel**, the current finger operation is interrupted and canceled.

The touch event supports single- and multi-touch interactions. Through the **event** parameter, you can obtain information about the touch event, including the location of the finger that triggers the event, unique identifier of the finger, finger information changed, and the input device source.


```ts
// xxx.ets
@Entry
@Component
struct TouchExample {
  @State text: string = '';
  @State eventType: string = '';

  build() {
    Column() {
      Button('Touch').height(40).width(100)
        .onTouch((event?: TouchEvent) => {
          if(event){
            if (event.type === TouchType.Down) {
              this.eventType = 'Down';
            }
            if (event.type === TouchType.Up) {
              this.eventType = 'Up';
            }
            if (event.type === TouchType.Move) {
              this.eventType = 'Move';
            }
            this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
            + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
            + event.target.area.width + '\nheight:' + event.target.area.height
          }
        })
      Button('Touch').height(50).width(200).margin(20)
        .onTouch((event?: TouchEvent) => {
          if(event){
            if (event.type === TouchType.Down) {
              this.eventType = 'Down';
            }
            if (event.type === TouchType.Up) {
              this.eventType = 'Up';
            }
            if (event.type === TouchType.Move) {
              this.eventType = 'Move';
            }
            this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
            + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
            + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
            + event.target.area.width + '\nheight:' + event.target.area.height
          }
        })
      Text(this.text)
    }.width('100%').padding(30)
  }
}
```


![en-us_image_0000001511900468](figures/en-us_image_0000001511900468.gif)


## Preventing Event Bubbling

Basic events propagate through the response chain following a bubbling mechanism, where the innermost component processes the event first, and then the event propagates up to parent components layer by layer. Any component can terminate the further transmission of the event, that is, stop the bubbling. However, it should be noted that stopping the bubbling does not affect gesture recognition in parent components.

**stopPropagation** can terminate event bubbling. As shown in the figure below, when a touch event reaches component C and **stopPropagation()** is called, components B and root will no longer receive this event. However, gesture objects attached to component B can still process the touch event.

![stopPropagation](figures/raw_event_stop_propagation.png)

> **NOTE**
>
> When using **stopPropagation** to intervene in event bubbling, maintain consistent handling rules for all event types (including **Down**, **Move**, and **Up**) to avoid situations where upper-level nodes only receive partial types of events, resulting in incomplete event cycles. For example, if node B only receives the **Down** event but not the **Up** event, it will affect the integrity of events on node B. For press-type interactions, always ensure the integrity of events.

Below is an example where touch events are blocked from reaching the parent component when the child component is clicked.

```typescript
@Entry
@ComponentV2
struct Index {
  
  build() {
    RelativeContainer() {
      Column() { // Parent component
        Text("If you click me, the parent will not receive touch events")
          .fontColor(Color.White)
          .height("40%")
          .width("80%")
          .backgroundColor(Color.Brown)
          .alignSelf(ItemAlign.Center)
          .padding(10)
          .margin(20)
          .onTouch((event:TouchEvent)=>{
            event.stopPropagation() // Prevent the parent component from receiving the event.
          })
      }
      .justifyContent(FlexAlign.End)
      .backgroundColor(Color.Green)
      .height('100%')
      .width('100%')
      .onTouch((event:TouchEvent)=>{
        console.log("touch event received on parent")
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

> **NOTE**
>
> Controlling event bubbling does not affect gesture recognition. Both aspects need to be considered separately.


## Resampling and Historical Points

The reporting frequency of raw input events depends on the device type. For example, touchscreens typically report events every 5¨C7 ms, while high-precision mouse devices may report events every 1 ms. Since the ultimate purpose of processing these input events is to drive UI updates that respond to user actions, the system optimizes this process by resampling the raw input event stream. Between each display frame, the system collects all received input events and processes them through a resampling algorithm. This resampling occurs independently for each active touch point, ensuring that multi-touch interactions remain accurate.

![resample](figures/events-resample.png)

- Down events are reported immediately.
- Move events within a frame are resampled and merged before the next frame.
- Up events trigger immediate reporting, including any pending move events.

For each touch point within a single frame, multiple move events are merged and processed through an advanced algorithm. This generates optimized coordinates that represent the most accurate position for the current display frame. While these resampled coordinates may show minor deviations from the raw device-reported positions, this intentional processing delivers significant benefits. The resulting points exhibit improved temporal consistency and motion smoothness.

To maintain full data transparency, the system preserves all original touch points prior to resampling. You can access the complete historical dataset when needed through the **getHistoricalPoints(): Array** API.

The following is a simple example.

```typescript
@Entry
@ComponentV2
struct Index {
  build() {
    RelativeContainer() {
      Column()
        .backgroundColor(Color.Green)
        .height('100%')
        .width('100%')
        .onTouch((event: TouchEvent) => {
          // Obtain historical points from the event.
          let allHistoricalPoints = event.getHistoricalPoints();
          if (allHistoricalPoints.length != 0) {
            for (const point of allHistoricalPoints) {
              console.log("historical point: [" + point.touchObject.windowX + ", " + point.touchObject.windowY + "]")
            }
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## Multi-Touch Information

For multi-touch-capable devices, the reported events contain information about all touch points, which can be obtained through **touches** as follows:

```typescript
@Entry
@ComponentV2
struct Index {
  private currentFingerCount: number = 0
  private allFingerIds: number[] = []

  build() {
    RelativeContainer() {
      Column()
        .backgroundColor(Color.Green)
        .height('100%')
        .width('100%')
        .onTouch((event: TouchEvent) => {
          if (event.source != SourceType.TouchScreen) {
            return;
          }
          // Clear the array.
          this.allFingerIds.splice(0, this.allFingerIds.length)
          // Obtain all touch point information from the event.
          let allFingers = event.touches;
          if (allFingers.length > 0 && this.currentFingerCount == 0) {
            // The first finger is pressed.
            console.log("fingers start to press down")
            this.currentFingerCount = allFingers.length
          }
          if (allFingers.length != 0) {
            for (const finger of allFingers) {
              this.allFingerIds.push(finger.id)
            }
            console.log("current all fingers : " + this.allFingerIds.toString())
          }
          if (event.type == TouchType.Up && event.touches.length == 1) {
            // All fingers are lifted.
            console.log("all fingers already up")
            this.currentFingerCount = 0
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

Different touch points are distinguished by IDs. These IDs are assigned sequentially based on the order of contact with the screen and do not correspond to physical touch sources (fingers). When working with the **touches** array, note that the points are not sorted by their ID values, so do not rely on the array order for access. The ID allocation system maintains an efficient reuse policy: When a touch point is released (finger lifted), its ID becomes available for reassignment to new touch points that may occur before all current contacts are removed from the screen.

Below is the log output of the preceding example during the following operation sequence.

![finger ids](figures/finger_ids.png)

Press finger 1 -> Press finger 2 -> Press finger 3 -> Lift finger 2 -> Lift finger 3 -> Press finger 2 -> Lift finger 1 -> Lift finger 3

```
  fingers start to press down   // Press finger 1.
  current all fingers: 0
  ... ...
  current all fingers: 0,1      // Press finger 2.
  ... ...
  current all fingers: 0,1,2    // Press finger 3.
  ... ...
  current all fingers: 0,2      // Lift finger 2.
  ... ...
  current all fingers: 0        // Lift finger 3.
  ... ...
  current all fingers: 0,1      //  Press finger 3.
  ... ...
  current all fingers: 1        // Lift finger 1.
  ... ...
  all fingers already up        // Lift finger 3.
```


## Stylus Support

Stylus interactions with the touchscreen generate touch events similar to finger touches, but can be identified using the **sourceTool** property. Active capacitive styluses provide additional precision data, including tilt and orientation angles. For details, see [BaseEvent](../reference/apis-arkui/arkui-ts/ts-gesture-customize-judge.md#baseevent8).

- **tiltX**: angle between the projection of the stylus on the device plane and the x-axis.
- **tiltY**: angle between the projection of the stylus on the device plane and the y-axis.
- **rollAngle**: angle between the stylus and the device plane.


