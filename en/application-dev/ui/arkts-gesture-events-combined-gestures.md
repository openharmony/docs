# Combined Gestures

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b25be4a3a7c309443271c4d1da44080f20a23712 translatedAt=2026-08-01T00:26:43.144Z pushedAt=2026-08-01T02:39:49.545Z -->

A combined gesture is composed of multiple single gestures. Its type is declared by using different [GestureMode](../reference/apis-arkui/arkui-ts/ts-combined-gestures.md#gesturemode) values in [GestureGroup](../reference/apis-arkui/arkui-ts/ts-combined-gestures.md), and three types are supported: [sequential recognition](#sequential-recognition), [parallel recognition](#parallel-recognition), and [exclusive recognition](#exclusive-recognition).

```ts
GestureGroup(mode:GestureMode, gesture:GestureType[])
```

- **mode**: recognition mode of combined gestures. The value belongs to the **GestureMode** enumeration class.

- **gesture**: array of multiple gestures.  

## Sequential Recognition

For sequential recognition, the value of **GestureMode** is **Sequence**. In this gesture recognition mode, gestures are recognized in the order in which they were registered until they are all recognized successfully. If any of the registered gestures fails to be recognized, subsequent gestures will also fail. Only the last gesture recognized responds to the [onActionEnd](../reference/apis-arkui/arkui-ts/ts-gesturehandler.md#onactionend) event.

In the following example, the combined gestures for sequential recognition are the long press gesture and pan gesture.

The [translate](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#translate) attribute is bound to a **Column** component. You can set the attribute to translate the component. Then, bind [LongPressGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md) and [PanGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md) to the component in the **Sequence** recognition mode. When a long press gesture is recognized, the displayed number is updated. When the user drags the component after the long press gesture, the component is dragged based on the callback function of the pan gesture.

  <!-- @[sequence_identification](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/GestureGroup/entry/src/main/ets/pages/Sequence.ets) -->

  ``` TypeScript
  // xxx.ets
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const DOMAIN = 0x0001;
  const TAG = 'Sample_gesturegroup';
  
  @Entry
  @Component
  struct sequenceIdentification {
    @State offsetX: number = 0;
    @State offsetY: number = 0;
    @State count: number = 0;
    @State positionX: number = 0;
    @State positionY: number = 0;
    @State borderStyles: BorderStyle = BorderStyle.Solid;
  
    build() {
      Column() {
        Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX +
          '\n' + 'Y: ' + this.offsetY)
          .fontSize(28)
      }
      .margin(10)
      .borderWidth(1)
      // Bind the translate attribute to translate the component.
      .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
      .height(250)
      .width(300)
      // The following combined gestures are recognized in sequence. When the long press gesture event is not triggered correctly, the pan gesture event is not triggered.
      .gesture(
        // Set the gesture mode to Sequence.
        GestureGroup(GestureMode.Sequence,
          // The first gesture recognized in the combined gestures is the long press gesture, which can be responded to for multiple times.
          LongPressGesture({ repeat: true })
          // When the long press gesture is successfully recognized, the value of count displayed on the Text component increments.
            .onAction((event: GestureEvent | undefined) => {
              if (event) {
                if (event.repeat) {
                  this.count++;
                }
              }
              hilog.info(DOMAIN, TAG, 'LongPress onAction');
            })
            .onActionEnd(() => {
              hilog.info(DOMAIN, TAG, 'LongPress end');
            }),
          // The pan gesture is triggered when the component is dragged after the long press gesture is recognized.
          PanGesture()
            .onActionStart(() => {
              this.borderStyles = BorderStyle.Dashed;
              hilog.info(DOMAIN, TAG, 'pan start');
            })
            // When the gesture is triggered, the pan distance is obtained based on the callback, and the displacement distance of the component is modified. In this way, the component is translated.
            .onActionUpdate((event: GestureEvent | undefined) => {
              if (event) {
                this.offsetX = (this.positionX + event.offsetX);
                this.offsetY = this.positionY + event.offsetY;
              }
              hilog.info(DOMAIN, TAG, 'pan update');
            })
            .onActionEnd(() => {
              this.positionX = this.offsetX;
              this.positionY = this.offsetY;
              this.borderStyles = BorderStyle.Solid;
            })
        )
          .onCancel(() => {
            hilog.info(DOMAIN, TAG, 'sequence gesture canceled');
          })
      )
    }
  }
  ```

![sequence](figures/sequence.gif)

>**NOTE**
>
>The drag event is a typical use case of sequential recognition on the long press gesture and pan gesture. It is triggered only when the user performs a pan gesture within the preset time frame after a long press gesture is recognized. If the long press gesture is not recognized or the pan gesture is not performed within the preset time frame, the drag event will not be triggered.

## Parallel Recognition

For parallel recognition, the value of **GestureMode** is **Parallel**. In this gesture recognition mode, gestures registered in the combined gestures will be recognized at the same time until they are all recognized successfully. The gestures are recognized in parallel without affecting each other.

For example, if the tap gesture and the double-tap gesture are bound to the **Column** component in parallel recognition mode, they can be recognized at the same time, and the recognition of these two gestures does not interfere with each other. 

  <!-- @[parallel_recognition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/GestureGroup/entry/src/main/ets/pages/Parallel.ets) -->

  ``` TypeScript
  // xxx.ets
  @Entry
  @Component
  struct parallelRecognition {
    @State count1: number = 0;
    @State count2: number = 0;
  
    build() {
      Column() {
        Text('Parallel gesture\n' + 'tapGesture count is 1:' + this.count1 + '\ntapGesture count is 2:' + this.count2 +
          '\n')
          .fontSize(28);
      }
      .height(200)
      .width('100%')
      // The following combined gestures are recognized in parallel mode. After a tap gesture is recognized successfully, if another tap gesture is recognized within the specified time frame, a double-tap gesture will also be recognized.
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
> - After a tap gesture and a double-tap gesture are combined for parallel recognition, when taps are performed in an area, the tap gesture and the double-tap gesture are recognized at the same time.
>
> - When there is only a single tap, the tap gesture is recognized, but the double-tap gesture fails to be recognized.
>
> - When there are two taps and the interval between the two taps is within a specified period (300 ms by default), two tap events and one double-tap event are triggered.
>
> - When there are two taps, but the interval between the two taps exceeds the specified time, two tap events are triggered but the double-tap event is not triggered.

## Exclusive Recognition

For exclusive recognition, the value of **GestureMode** is **Exclusive**. In this gesture recognition mode, all registered gestures are recognized at once. Once any of the gestures is recognized successfully, the gesture recognition ends, and all other gestures fail to be recognized.

For example, consider a Column component bound with both a tap gesture and a double‑tap gesture in an exclusive recognition combination. If the tap gesture is bound before the double‑tap, the double‑tap cannot be triggered because the tap requires only a single tap to fire, whereas the double‑tap requires two; each tap event is consumed by the tap gesture and never accumulates into a double‑tap. Conversely, if the double‑tap is bound first, the double‑tap is recognized and the tap gesture is not triggered.

  <!-- @[mutual_exclusion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/GestureGroup/entry/src/main/ets/pages/Exclusive.ets) -->

  ``` TypeScript
  // xxx.ets
  @Entry
  @Component
  struct MutualExclusion {
    @State count1: number = 0;
    @State count2: number = 0;
  
    build() {
      Column() {
        Text('Exclusive gesture\n' + 'tapGesture count is 1:' + this.count1 + '\ntapGesture count is 2:' + this.count2 +
          '\n')
          .fontSize(28)
      }
      .height(200)
      .width('100%')
      // The following combined gestures are mutually exclusive. After the tap gesture is recognized successfully, the double-tap gesture fails to be recognized.
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
> - After a tap gesture and a double-tap gesture are combined for exclusive recognition, when taps are performed in an area, the tap gesture and the double-tap gesture are recognized at the same time.
>
> - When there is only a single tap, the tap gesture is recognized, but the double-tap gesture fails to be recognized.
>
> - When there are two taps, the gesture response depends on the order of gesture binding. If you bind the tap gesture first, followed by the double-tap gesture, the tap gesture will be recognized on the first tap, causing the double-tap gesture to fail. Even if the second tap is performed within the specified time, the double-tap gesture event is not responded to. Instead, another tap gesture event is triggered. Conversely, if you bind the double-tap gesture first, it will be recognized without triggering the tap gesture.

## Example Scenario

The following example implements a child component bound to both a long press gesture and a pan gesture. These two gestures can trigger in parallel, but when the long press gesture is not successfully recognized, the built‑in pan gesture of the parent **Swiper** component should take effect. Because the child's pan gesture competes with the parent's built‑in pan gesture and has higher priority, dynamic control is required to decide whether the child's pan gesture should be triggered.

  <!-- @[scene_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/GestureGroup/entry/src/main/ets/pages/SceneExample.ets) -->

  ``` TypeScript
  // xxx.ets
  import { PromptAction } from '@kit.ArkUI';
  
  @Entry
  @Component
  struct CombinedGestureDemo {
    @State isLongPress: boolean = false;
    promptAction: PromptAction = this.getUIContext().getPromptAction();
  
    build() {
      Swiper() {
        // Page 1
        Row()
          .width('100%')
          .height('100%')
          .backgroundColor(Color.Grey)
          .borderRadius(12)
          // Use a custom gesture judgment callback to reject the child's pan gesture when the long press gesture fails, allowing the parent Swiper component's swipe gesture to succeed.
          .onGestureRecognizerJudgeBegin(
            (event: BaseGestureEvent, current: GestureRecognizer, others: Array<GestureRecognizer>) => {
              if (current.getType() !== GestureControl.GestureType.PAN_GESTURE) {
                return GestureJudgeResult.CONTINUE;
              }
              if (this.isLongPress) {
                return GestureJudgeResult.CONTINUE;
              }
              return GestureJudgeResult.REJECT;
            })
          .gesture(
            // Bind a parallel gesture group to allow long press and pan gestures to trigger simultaneously.
            GestureGroup(GestureMode.Parallel,
              LongPressGesture()
                .onAction(() => {
                  this.isLongPress = true;
                  this.promptAction.showToast({ message: 'LongPress trigger' });
                })
                .onActionEnd(() => {
                  this.isLongPress = false;
                }),
              PanGesture()
                .onActionStart(() => {
                  this.promptAction.showToast({ message: 'child pan start' });
                })
            )
          )
        // Page 2
        Row()
          .width('100%')
          .height('100%')
          .backgroundColor(Color.Pink)
          .borderRadius(12)
      }
      .borderWidth(2)
      .width('100%')
      .height(300)
      .padding(20)
    }
  }
  ```

![combined-gesture](figures/combined-gesture.gif)