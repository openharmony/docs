# Gesture Conflict Handling
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

Gesture conflicts occur when multiple gesture recognizers compete for recognition on the same component or overlapping areas, resulting in unexpected behavior. Common conflict scenarios include:
- Multiple gestures on the same component (for example, both tap and long-press gestures on a button)
- Gesture recognizers of the same type on parent and child components
- Conflicts between system default gestures and custom gestures (for example, conflict between the scroll gesture and the click gesture of a child component)

Effective conflict resolution involves gesture intervention. Beyond controlling component response regions and hit test modes, there are three primary approaches: [Custom Gesture Judgment](#custom-gesture-judgment), [Parallel Gesture Dynamic Control](#parallel-gesture-dynamic-control), and [Gesture Recognition Prevention](#gesture-recognition-prevention).

## Custom Gesture Judgment

Custom gesture judgment enables applications to override system recognition decisions. When system thresholds are met, the application can determine whether to intercept the gesture (causing its recognition to fail) and prioritize other gestures instead.

**Figure 1** Custom gesture judgment process

![gesture_judge](figures/gesture_judge.png)

Custom gesture judgment involves the following APIs.

| API| Description|
| ------- | -------------- |
|[onGestureJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-customize-judge.md#ongesturejudgebegin)|Used for gesture interception as a universal event. Called when the gesture meets system trigger thresholds, allowing the application to determine whether to intercept the gesture.|
|[onGestureRecognizerJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ongesturerecognizerjudgebegin)|Called to implement gesture judgment, obtain gesture recognizers, and set their enabled state. It is an extension of **onGestureJudgeBegin** and can serve as its substitute.<br>When obtaining gesture recognizers, this API obtains all gesture recognizers in the response chain of the current interaction, as well as the recognizer about to be triggered successfully, allowing the enabled state of the gesture to be set.|

In the following example, the **Image** and **Stack** components are located in the same area. Long-pressing the upper half of the **Stack** component triggers the long-press gesture bound to the **Stack** component, while long-pressing the lower half of the **Stack** component triggers the drag operation of the **Image** component.

**Figure 2** Example

![gesture_judge_image_response_region](figures/gesture_judge_image_response_region.png)

1. Configure drag settings for the **Image** component.

   ```ts
   Image($r('sys.media.ohos_app_icon'))
     .draggable(true)
     .onDragStart(()=>{
       promptAction.showToast({ message: "Drag the lower blue area. The Image component responds." });
     })
     .width('200vp').height('200vp')
   ```

2. Set up gestures for the **Stack** component.

   ```ts
   Stack() {}
     .width('200vp')
     .height('200vp')
     .hitTestBehavior(HitTestMode.Transparent)
     .gesture(GestureGroup(GestureMode.Parallel,
       LongPressGesture()
         .onAction((event: GestureEvent) => {
           promptAction.showToast({ message: "Long-press the upper red area. The red area responds." });
         })
         .tag("longpress")
     ))
   ```

3. Set up gesture judgment for the **Stack** component.

   ```ts
   .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent) => {
     // If it is a long press gesture, determine whether the touch position is in the upper half area.
     if (gestureInfo.type == GestureControl.GestureType.LONG_PRESS_GESTURE) {
       if (event.fingerList.length > 0 && event.fingerList[0].localY < 100) {
         return GestureJudgeResult.CONTINUE;
       } else {
         return GestureJudgeResult.REJECT;
       }
     }
     return GestureJudgeResult.CONTINUE;
   })
   ```

4. Below is the complete code example.

   ```ts
   import { PromptAction } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct Index {
     scroller: Scroller = new Scroller();
     promptAction: PromptAction = this.getUIContext().getPromptAction();
   
     build() {
       Scroll(this.scroller) {
         Column({ space: 8 }) {
           Text("There are two layers of components, the upper layer component bound to a long press gesture, and the lower layer component bound to a drag. The lower half of the upper layer component is bound to gesture judgment, making this area respond to the drag gesture of the lower layer.").width('100%').fontSize(20).fontColor('0xffdd00')
           Stack({ alignContent: Alignment.Center }) {
             Column() {
               // Simulate the upper and lower half areas.
               Stack().width('200vp').height('100vp').backgroundColor(Color.Red)
               Stack().width('200vp').height('100vp').backgroundColor(Color.Blue)
             }.width('200vp').height('200vp')
             // The lower half of the Stack component is the image area bound to the drag gesture.
             Image($r('sys.media.ohos_app_icon'))
               .draggable(true)
               .onDragStart(()=>{
                 this.promptAction.showToast({ message: "Drag the lower blue area. The Image component responds." });
               })
               .width('200vp').height('200vp')
             // The upper half of the Stack component is the floating area bound to the long press gesture.
             Stack() {
             }
             .width('200vp')
             .height('200vp')
             .hitTestBehavior(HitTestMode.Transparent)
             .gesture(GestureGroup(GestureMode.Parallel,
               LongPressGesture()
                 .onAction((event: GestureEvent) => {
                   this.promptAction.showToast({ message: "Long-press the upper red area. The red area responds." });
                 })
                 .tag("longpress")
             ))
             .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent) => {
               // If it is a long press gesture, determine whether the touch position is in the upper half area.
               if (gestureInfo.type == GestureControl.GestureType.LONG_PRESS_GESTURE) {
                 if (event.fingerList.length > 0 && event.fingerList[0].localY < 100) {
                   return GestureJudgeResult.CONTINUE;
                 } else {
                   return GestureJudgeResult.REJECT;
                 }
               }
               return GestureJudgeResult.CONTINUE;
             })
           }.width('100%')
         }.width('100%')
       }
     }
   }
   ```

## Parallel Gesture Dynamic Control

Parallel gesture dynamic control allows you to manage whether a gesture callback should be executed, even after the gesture has been successfully recognized.

**Figure 3** Parallel gesture dynamic control process

![gesture_judge_controller](figures/gesture_judge_controller.png)
Parallel gesture dynamic control is based on the successful recognition of a gesture. If the gesture is not recognized, no callback response will be triggered.

1. Service gesture workflow: This refers to gestures that directly cause changes in the UI, such as **PanGesture** for scrolling pages or **TapGesture** for clicks.

2. Gesture listening workflow: This involves dynamically controlling the start and stop of gesture recognizers based on the current service state. For example, during nested scrolling, the listener can determine whether the component has reached the edge. This can be achieved using **PanGesture** with the [parallel gesture binding method](arkts-gesture-events-binding.md#parallelgesture-parallel-gesture-binding-method) or by using touch events.

3. Parallel gesture configuration: This step is optional. A typical use case is to set the scroll gesture of an outer component to be parallel with the scroll gesture of an inner component during nested scrolling.

4. Dynamic gesture control: This involves controlling whether gestures respond to user callbacks by using the **setEnable** API of gesture recognizers.

Parallel gesture dynamic control involves the following APIs.

| API| Description|
| ------- | -------------- |
|[shouldBuiltInRecognizerParallelWith](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#shouldbuiltinrecognizerparallelwith)|Used to set the built-in gestures to be parallel with other gestures.|
|[onGestureRecognizerJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ongesturerecognizerjudgebegin)|Called to implement gesture judgment, obtain gesture recognizers, and initialize and their enabled state.|
|[parallelGesture](arkts-gesture-events-binding.md#parallelgesture-parallel-gesture-binding-method)|Allows custom gestures to be parallel with gestures of higher priority.|

The following example demonstrates a nested scrolling scenario with two **Scroll** components, using gesture control APIs to manage the nested scrolling linkage between the outer and inner components.

1. Use the **shouldBuiltInRecognizerParallelWith** API to set the **PanGesture** of the outer **Scroll** component to be parallel with the **PanGesture** of the inner **Scroll** component.

   ```ts
   .shouldBuiltInRecognizerParallelWith((current: GestureRecognizer, others: Array<GestureRecognizer>) => {
     for (let i = 0; i < others.length; i++) {
       let target = others[i].getEventTargetInfo();
       if (target.getId() == "inner" && others[i].isBuiltIn() && others[i].getType() == GestureControl.GestureType.PAN_GESTURE) { // Identify the recognizer to work in parallel.
         this.currentRecognizer = current; // Save the recognizer of the current component.
         this.childRecognizer = others[i]; // Save the recognizer to work in parallel.
         return others[i]; // Return the recognizer to work in parallel with the current one.
       }
     }
     return undefined;
   })
   ```

2. Use the **onGestureRecognizerJudgeBegin** API to obtain the pan gesture recognizer of the **Scroll** component and to set the enabled state of the inner and outer gesture recognizers based on the boundary conditions of the **Scroll** components.

   ```ts
   .onGestureRecognizerJudgeBegin((event: BaseGestureEvent, current: GestureRecognizer, others: Array<GestureRecognizer>) => { // When gesture recognition is about to be successful, set the recognizer's enabled state based on the current component state.       
     let target = current.getEventTargetInfo();
     if (target && target.getId() == "outer" && current.isBuiltIn() && current.getType() == GestureControl.GestureType.PAN_GESTURE) {
       for (let i = 0; i < others.length; i++) {
         let target = others[i].getEventTargetInfo() as ScrollableTargetInfo;
         if (target instanceof ScrollableTargetInfo && target.getId() == "inner") { // Identify the recognizer to work in parallel on the response chain.
           let panEvent = event as PanGestureEvent;
           this.childRecognizer.setEnabled(true);
           this.currentRecognizer.setEnabled(false);
           if (target.isEnd()) { // Dynamically control the recognizer's enabled state based on the current component state and direction of movement.
             if (panEvent && panEvent.offsetY < 0) {
               this.childRecognizer.setEnabled(false);
               this.currentRecognizer.setEnabled(true);
             }
           } else if (target.isBegin()) {
             if (panEvent.offsetY > 0) {
               this.childRecognizer.setEnabled(false);
               this.currentRecognizer.setEnabled(true);
             }
           }
         }
       }
     }
     return GestureJudgeResult.CONTINUE;
   })
   ```

3. Set up a gesture listener to listen for the state changes of the **Scroll** component, dynamically adjust the enabled state of the gesture recognizers, and controls whether gesture callbacks are triggered, allowing you to manage scrolling.

   ```ts
   .parallelGesture ( // Bind a PanGesture as a dynamic controller.
     PanGesture()
       .onActionUpdate((event: GestureEvent)=>{
         if (this.childRecognizer.getState() != GestureRecognizerState.SUCCESSFUL || this.currentRecognizer.getState() != GestureRecognizerState.SUCCESSFUL) { // If neither recognizer is in the SUCCESSFUL state, no control is applied.
           return;
         }
         let target = this.childRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
         let currentTarget = this.currentRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
         if (target instanceof ScrollableTargetInfo && currentTarget instanceof ScrollableTargetInfo) {
           this.childRecognizer.setEnabled(true);
           this.currentRecognizer.setEnabled(false);
           if (target.isEnd()) { // Adjust the enabled state of the gesture recognizers based on the current component state during movement.
             if ((event.offsetY - this.lastOffset) < 0) {
               this.childRecognizer.setEnabled(false);
               if (currentTarget.isEnd()) {
                 this.currentRecognizer.setEnabled(false);
               } else {
                 this.currentRecognizer.setEnabled(true);
               }
             }
           } else if (target.isBegin()) {
             if ((event.offsetY - this.lastOffset) > 0) {
               this.childRecognizer.setEnabled(false);
               if (currentTarget.isBegin()) {
                 this.currentRecognizer.setEnabled(false);
               } else {
                 this.currentRecognizer.setEnabled(true);
               }
             }
           }
         }
         this.lastOffset = event.offsetY
     })
   )
   ```

4. Below is the complete code example.

   ```ts
   // xxx.ets
   @Entry
   @Component
   struct FatherControlChild {
     scroller: Scroller = new Scroller();
     scroller2: Scroller = new Scroller();
     private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
     private childRecognizer: GestureRecognizer = new GestureRecognizer();
     private currentRecognizer: GestureRecognizer = new GestureRecognizer();
     private lastOffset: number = 0;

     build() {
       Stack({ alignContent: Alignment.TopStart }) {
         Scroll(this.scroller) { // Outer scroll container.
           Column() {
             Text("Scroll Area")
               .width('90%')
               .height(150)
               .backgroundColor(0xFFFFFF)
               .borderRadius(15)
               .fontSize(16)
               .textAlign(TextAlign.Center)
               .margin({ top: 10 })
             Scroll(this.scroller2) { // Inner scroll container.
               Column() {
                 Text("Scroll Area2")
                   .width('90%')
                   .height(150)
                   .backgroundColor(0xFFFFFF)
                   .borderRadius(15)
                   .fontSize(16)
                   .textAlign(TextAlign.Center)
                   .margin({ top: 10 })
                 Column() {
                   ForEach(this.arr, (item: number) => {
                     Text(item.toString())
                       .width('90%')
                       .height(150)
                       .backgroundColor(0xFFFFFF)
                       .borderRadius(15)
                       .fontSize(16)
                       .textAlign(TextAlign.Center)
                       .margin({ top: 10 })
                   }, (item: string) => item)
                 }.width('100%')
               }
             }
             .id("inner")
             .width('100%')
             .height(800)
           }.width('100%')
         }
         .id("outer")
         .height(600)
         .scrollable(ScrollDirection.Vertical) // The scrollbar scrolls in the vertical direction.
         .scrollBar(BarState.On) // The scrollbar is always displayed.
         .scrollBarColor(Color.Gray) // The scrollbar color is gray.
         .scrollBarWidth(10) // The scrollbar width is 10.
         .edgeEffect(EdgeEffect.None)
         .shouldBuiltInRecognizerParallelWith((current: GestureRecognizer, others: Array<GestureRecognizer>) => {
           for (let i = 0; i < others.length; i++) {
             let target = others[i].getEventTargetInfo();
             if (target.getId() == "inner" && others[i].isBuiltIn() &&
               others[i].getType() == GestureControl.GestureType.PAN_GESTURE) { // Identify the recognizer that to be bound to parallelGesture.
               this.currentRecognizer = current; // Save the recognizer of the current component.
               this.childRecognizer = others[i]; // Save the recognizer to work in parallel.
               return others[i]; // Return the recognizer to work in parallel with the current one.
             }
           }
           return undefined;
         })
         .onGestureRecognizerJudgeBegin((event: BaseGestureEvent, current: GestureRecognizer,
           others: Array<GestureRecognizer>) => { // When the implementation is about to succeed, set the recognizer enabling state based on the current component state.
           let target = current.getEventTargetInfo();
           if (target && target.getId() == "outer" && current.isBuiltIn() &&
             current.getType() == GestureControl.GestureType.PAN_GESTURE) {
             for (let i = 0; i < others.length; i++) {
               let target = others[i].getEventTargetInfo() as ScrollableTargetInfo;
               if (target instanceof ScrollableTargetInfo && target.getId() == "inner") { // Identify the recognizer to work in parallel on the response chain.
                 let panEvent = event as PanGestureEvent;
                 this.childRecognizer.setEnabled(true);
                 this.currentRecognizer.setEnabled(false);
                 if (target.isEnd()) { // Dynamically control the recognizer's enabled state based on the current component state and direction of movement.
                   if (panEvent && panEvent.offsetY < 0) {
                     this.childRecognizer.setEnabled(false);
                     this.currentRecognizer.setEnabled(true);
                   }
                 } else if (target.isBegin()) {
                   if (panEvent.offsetY > 0) {
                     this.childRecognizer.setEnabled(false);
                     this.currentRecognizer.setEnabled(true);
                   }
                 }
               }
             }
           }
           return GestureJudgeResult.CONTINUE;
         })
         .parallelGesture ( // Bind a PanGesture as a dynamic controller.
           PanGesture()
             .onActionUpdate((event: GestureEvent) => {
               if (this.childRecognizer?.getState() != GestureRecognizerState.SUCCESSFUL ||
                 this.currentRecognizer?.getState() != GestureRecognizerState.SUCCESSFUL) { // If the recognizer is not in the SUCCESSFUL state, no control is applied.
                 return;
               }
               let target = this.childRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
               let currentTarget = this.currentRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
               if (target instanceof ScrollableTargetInfo && currentTarget instanceof ScrollableTargetInfo) {
                 this.childRecognizer.setEnabled(true);
                 this.currentRecognizer.setEnabled(false);
                 if (target.isEnd()) { // Adjust the enabled state of the gesture recognizers based on the current component state during movement.
                   if ((event.offsetY - this.lastOffset) < 0) {
                     this.childRecognizer.setEnabled(false);
                     if (currentTarget.isEnd()) {
                       this.currentRecognizer.setEnabled(false);
                     } else {
                       this.currentRecognizer.setEnabled(true);
                     }
                   }
                 } else if (target.isBegin()) {
                   if ((event.offsetY - this.lastOffset) > 0) {
                     this.childRecognizer.setEnabled(false)
                     if (currentTarget.isBegin()) {
                       this.currentRecognizer.setEnabled(false);
                     } else {
                       this.currentRecognizer.setEnabled(true);
                     }
                   }
                 }
               }
               this.lastOffset = event.offsetY;
             })
         )
       }.width('100%').height('100%').backgroundColor(0xDCDCDC)
     }
   }
   ```

## Gesture Recognition Prevention

Gesture recognition is based on the response chain results of [hit testing](./arkts-interaction-basic-principles.md#hit-testing). Therefore, it is efficient to dynamically intervene in gesture processing by controlling the participation status of gesture recognizers in the response chain when the user presses down.

This is achieved using the [onTouchTestDone](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ontouchtestdone20) API:

After hit testing is completed, the system returns all gesture recognizer objects through this API. Applications can filter recognizers by type, component ID, or associated component, and proactively disable specific recognizers by calling the [preventBegin](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#preventbegin20) API.

Disabling by gesture type:

```typescript
  .onTouchTestDone((event, recognizers) => {
    for (let i = 0; i < recognizers.length; i++) {
      let recognizer = recognizers[i];
      // Disable all pan gestures based on type.
      if (recognizer.getType() == GestureControl.GestureType.PAN_GESTURE) {
        recognizer.preventBegin();
      }
    }
  })
```

Disabling by associated component:

Components must be pre-configured with a component ID through the universal attribute [id](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#id).

```typescript
  .onTouchTestDone((event, recognizers) => {
    for (let i = 0; i < recognizers.length; i++) {
      let recognizer = recognizers[i];
      // Disable all gestures on the component with ID "myID."
      if (recognizer.getEventTargetInfo().getId() == "myID") {
        recognizer.preventBegin();
      }
    }
  })
```

Disabling system built-in gestures:

```typescript
  .onTouchTestDone((event, recognizers) => {
    for (let i = 0; i < recognizers.length; i++) {
      let recognizer = recognizers[i];
      //  Disable all system built-in gestures.
      if (recognizer.isBuiltIn()) {
        recognizer.preventBegin();
      }
    }
  })
```

Combine the preceding conditions based on specific scenarios.

> **NOTE**
>
> The system executes **onTouchTestDone** callbacks on nodes from innermost to outermost.

In the NDK, the corresponding APIs for **onTouchTestDone** and **preventBegin** are **OH_ArkUI_SetTouchTestDoneCallback** and **OH_ArkUI_PreventGestureRecognizerBegin**, respectively. Their usage and functionality are consistent with the ArkTS APIs.

The following example illustrates a simplified video player UI interaction.

The parent container (**video_layer**) has multiple bound gestures:
- Tap: controls the playback (pause/play).
- Double-tap: switches between full-screen and non-full-screen modes.
- Long press: fast-forwards.
- Vertical swipe: adjusts brightness.
- Horizontal swipe: seeks playback.

The inner **Slider** component (**progress_layer**) does not have a long-press gesture bound to it. This causes the parent container's fast-forward gesture to be triggered when the user long-presses the **Slider** component, which is unexpected behavior.

Solution: Register an **onTouchTestDone** callback on the **Slider** component. Use this callback to disable gesture recognizers not belonging to the **Slider** component, thereby resolving the conflict.

The following shows the complete sample code:

```typescript
@Entry
@ComponentV2
struct Index {
  @Local progress: number = 496000 // Initial progress, in seconds.
  @Local total: number = 27490000   // Total duration, in seconds.
  @Local currentWidth: string = '100%'
  @Local currentHeight: string = '100%'
  private currentPosX: number = 0
  private currentPosY: number = 0
  private currentFullScreenState: boolean = true
  private normalPlayTimer: number = -1;
  private isPlaying: boolean = true;
  private fastForwardTimer: number = -1;

  aboutToAppear(): void {
    // Start a periodic timer to refresh the progress every second.
    this.startNormalPlayTimer()
  }

  startNormalPlayTimer(): void {
    if (this.normalPlayTimer != -1) {
      this.stopNormalPlayTimer()
    }
    this.normalPlayTimer = setInterval(() => {
      this.progress = this.progress + 1000
    }, 1000)
  }

  stopNormalPlayTimer(): void {
    if (this.normalPlayTimer == -1) {
      return
    }
    clearInterval(this.normalPlayTimer)
    this.normalPlayTimer = -1
  }

  startFastForwardTimer(): void {
    if (this.fastForwardTimer != -1) {
      this.stopFastForwardTimer()
    }
    this.fastForwardTimer = setInterval(() => {
      this.progress = this.progress + 100000
    }, 100)
  }

  stopFastForwardTimer(): void {
    if (this.fastForwardTimer == -1) {
      return
    }
    clearInterval(this.fastForwardTimer)
    this.fastForwardTimer = -1
  }

  showMessage(message: string): void {
    this.getUIContext().getPromptAction().showToast({ message: message, alignment: Alignment.Center })
  }

  resetPosInfo(): void {
    this.currentPosX = 0
    this.currentPosY = 0
  }

  toggleFullScreenState(): void {
    this.currentFullScreenState = !this.currentFullScreenState
    if (this.currentFullScreenState) {
      this.currentWidth = '100%'
      this.currentHeight = '100%'
    } else {
      this.currentWidth = '100%'
      this.currentHeight = '50%'
    }
    this.showMessage(this.currentFullScreenState ? 'Full-screen playback' : 'Exit full-screen')
  }

  togglePlayAndPause(): void {
    this.isPlaying = !this.isPlaying
    if (!this.isPlaying) {
      this.stopNormalPlayTimer()
    } else {
      // Restart the timer.
      this.startNormalPlayTimer()
    }
    this.showMessage(this.isPlaying ? 'Pause playback' : 'Resume playback')
  }

  doFastForward(start: boolean): void {
    if (!start) { // Stop fast-forwarding and resume normal playback.
      this.stopFastForwardTimer()
      this.startNormalPlayTimer()
      this.showMessage('Cancel fast-forwarding')
      return
    }

    this.stopNormalPlayTimer()
    this.startFastForwardTimer()
    this.showMessage('Start fast-forwarding')
  }

  updateBrightness(start: boolean, event: BaseGestureEvent): void {
    let newY = event.fingerList[0].localY
    if (start) {
      this.currentPosY = newY
      this.showMessage('Start adjusting brightness')
      return
    }
    let offsetY = newY - this.currentPosY;
    if (offsetY > 10) {
      this.showMessage((offsetY > 0) ? 'Decrease brightness' : 'Increase brightness')
    }
    this.currentPosY = newY
  }

  updateProgress(start: boolean, event: BaseGestureEvent): void {
    let newX = event.fingerList[0].localX
    if (start) {
      this.currentPosX = newX
      this.showMessage('Start adjusting progress')
      return
    }
    let offsetX = newX - this.currentPosX;
    this.progress = Math.floor(this.progress + offsetX * 10000)
    this.currentPosX = newX
  }

  build() {
    Stack({ alignContent: Alignment.Center }) {
      Column() {
        Column() {
          Text("Playback progress: " + this.progress)
        }
          .width("100%").height("90%")
        Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
          Slider({
            value: this.progress,
            min: 0,
            max: this.total,
            style: SliderStyle.OutSet
          })
            .onChange((value: number, mode: SliderChangeMode) => {
              this.progress = value
            })
            .id("progress_layer")
            .onTouchTestDone((event, allRecognizers: Array<GestureRecognizer>) => {
              for (let i = 0; i < allRecognizers.length; i++) {
                let recognizer = allRecognizers[i];
                let inspectorInfo = recognizer.getEventTargetInfo().getId();
                if (inspectorInfo !== "progress_layer") {
                  // When the user interacts with the progress bar area, disable all gestures not belonging to progress_layer.
                  recognizer.preventBegin();
                }
              }
            })
            .margin({ left: 5 })
            .trackColor(Color.Red)
            .blockColor(Color.Yellow)
            .selectedColor(Color.Orange)
            .trackThickness(2)
            .flexShrink(1)
            .flexGrow(1)
        }
        .flexGrow(1)
        .flexShrink(1)
        .id('id_progress_view')
      }
    }
    .id('video_layer')
    .backgroundColor('#E0E0E0')
    .gesture(
      GestureGroup(GestureMode.Exclusive,
        PanGesture({ direction: PanDirection.Vertical, distance: 10 })
          .tag('pan_for_brightness_control')
          .onActionStart((event) => {
            this.updateBrightness(true, event)
          })
          .onActionUpdate((event) => {
            this.updateBrightness(false, event)
          }),
        PanGesture({ direction: PanDirection.Horizontal, distance: 10 })
          .tag('pan_for_play_progress_control')
          .onActionStart((event) => {
            this.updateProgress(true, event)
          })
          .onActionUpdate((event) => {
            this.updateProgress(false, event)
          }),

        LongPressGesture()
          .tag('long_press_for_fast_forward_control')
          .onAction(() => {
            this.doFastForward(true) // Start fast-forwarding.
          })
          .onActionEnd(() => {
            this.doFastForward(false) // Stop fast-forwarding.
          })
          .onActionCancel(() => {
            this.doFastForward(false)
          }),

        TapGesture({ count: 2 })
          .tag('double_tap_on_video')
          .onAction(() => {
            this.toggleFullScreenState()
          }),

        TapGesture()
          .tag('single_tap_on_video')
          .onAction(() => {
            this.togglePlayAndPause()
          })
      )
    )
    .width(this.currentWidth)
    .height(this.currentHeight)
  }
}
```
<!--no_check-->