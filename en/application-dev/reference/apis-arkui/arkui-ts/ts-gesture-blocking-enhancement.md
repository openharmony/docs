# Gesture Blocking Enhancement

Gesture blocking enhancement offers components the capability to block gestures. You can handle built-in gestures in parallel with gestures that have a higher priority as needed, and can dynamically control the triggering of gesture events.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## shouldBuiltInRecognizerParallelWith
shouldBuiltInRecognizerParallelWith(callback: ShouldBuiltInRecognizerParallelWithCallback): T

**Parameters**
| Name       | Type                   | Mandatory | Description                         |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [ShouldBuiltInRecognizerParallelWithCallback](#shouldbuiltinrecognizerparallelwithcallback) | Yes  |  Callback used to set the parallel relationship between the system's built-in gestures and the gestures of other components within the response chain. When the current component undergoes touch collision detection, a custom callback is triggered to establish the gesture parallel relationship.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

## ShouldBuiltInRecognizerParallelWithCallback

type ShouldBuiltInRecognizerParallelWithCallback = (current: GestureRecognizer, others: Array\<GestureRecognizer\>) => GestureRecognizer

Represents the callback used to set the parallel relationship between the system's built-in gestures and the gestures of other components within the response chain.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| current | [GestureRecognizer](#gesturerecognizer) | Yes  | Built-in gesture recognizer of the current component. Currently only a built-in gesture recognizer of the [PAN_GESTURE](ts-gesture-customize-judge.md#gesturejudgeresult11) type is supported.|
| others | Array\<[GestureRecognizer](#gesturerecognizer)\> | Yes  | Other gesture recognizers of the same category from components with higher priority in the response chain.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureRecognizer](#gesturerecognizer) | Gesture recognizer that is bound in parallel with the current recognizer.|

## GestureRecognizer

Defines a gesture recognizer object.

### getTag

getTag(): string

Obtains the tag of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Tag of the current gesture recognizer.|

### getType

getType(): GestureControl.GestureType

Obtains the type of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureControl.GestureType](ts-gesture-customize-judge.md#gesturetype11) | Type of the current gesture recognizer.|

### isBuiltIn

isBuiltIn(): boolean

Obtains whether this gesture recognizer is a built-in gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether this gesture recognizer is a built-in gesture.|

### setEnabled

setEnabled(isEnabled: boolean): void

Sets the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name    | Type                          | Mandatory  | Description |
| ------- | ---------------------------------- | ---- | ----- |
| isEnabled   | boolean         | Yes   | Enabled state to set.|

### isEnabled

isEnabled(): boolean

Obtains the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Enabled state of the gesture recognizer.|

### getState

getState(): GestureRecognizerState

Obtains the state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureRecognizerState](#gesturerecognizerstate) | State of the gesture recognizer.|

### getEventTargetInfo

getEventTargetInfo(): EventTargetInfo

Obtains the information about the component corresponding to this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo) | Information about the component corresponding to the current gesture recognizer.|

## GestureRecognizerState

Enumerates the gesture recognizer states.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name   | Value  | Description                              |
| ------- | ---- | ---------------------------------- |
| READY | 0    | Ready.|
| DETECTING    | 1    | Detecting.|
| PENDING    | 2    | Pending.|
| BLOCKED    | 3    | Blocked.|
| SUCCESSFUL    | 4    | Successful.|
| FAILED    | 5    | Failed.|

## EventTargetInfo

Provides the information about the component corresponding to the gesture recognizer.

### getId

getId(): string

Obtains the ID of this component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | [ID](./ts-universal-attributes-component-id.md#id) of the current component.|

## ScrollableTargetInfo

Provides the information about the scroll container component corresponding to the gesture recognizer. It inherits from [EventTargetInfo](#eventtargetinfo).

### isBegin

isBegin(): boolean

Checks whether this scroll container is scrolled to the top. If the container is a **Swiper** component and is in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current scroll container is scrolled to the top.|

### isEnd

isEnd(): boolean

Checks whether this scroll container is scrolled to the bottom. If the container is a **Swiper** component and is in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the scroll container is scrolled to the bottom.|

## PanRecognizer

Defines a pan gesture recognizer object. It inherits from [GestureRecognizer](#gesturerecognizer).

### getPanGestureOptions

getPanGestureOptions(): PanGestureOptions

Obtains the properties of this pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanGestureOptions](./ts-basic-gestures-pangesture.md#pangestureoptions) | Properties of the current pan gesture recognizer.|

## onGestureRecognizerJudgeBegin

onGestureRecognizerJudgeBegin(callback: GestureRecognizerJudgeBeginCallback): T

**Parameters**
| Name       | Type                   | Mandatory | Description                         |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [GestureRecognizerJudgeBeginCallback](#gesturerecognizerjudgebegincallback) | Yes    |  Custom gesture recognizer judgment callback to bind to the component. When the gesture bound to the current component is accepted, a custom callback is triggered to obtain the result.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

## GestureRecognizerJudgeBeginCallback

type GestureRecognizerJudgeBeginCallback = (event: BaseGestureEvent, current: GestureRecognizer, recognizers: Array\<GestureRecognizer\>) => GestureJudgeResult

Represents a custom gesture recognizer judgment callback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| event | [BaseGestureEvent](./ts-gesture-customize-judge.md#basegestureevent) | Yes  | Information about the current basic gesture event.|
| current | [GestureRecognizer](#gesturerecognizer) | Yes  | Gesture recognizer object that is about to respond.|
| others | Array\<[GestureRecognizer](#gesturerecognizer)\> | Yes  | Other gesture recognizer objects in the response chain.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureJudgeResult](ts-gesture-customize-judge.md#gesturejudgeresult11) | Result of whether the gesture judgment is successful.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct FatherControlChild {
  scroller: Scroller = new Scroller()
  scroller2: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  private childRecognizer: GestureRecognizer = new GestureRecognizer()
  private currentRecognizer: GestureRecognizer = new GestureRecognizer()
  private lastOffset: number = 0

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) { // External scroll container.
        Column() {
          Text("Scroll Area")
            .width('90%')
            .height(150)
            .backgroundColor(0xFFFFFF)
            .borderRadius(15)
            .fontSize(16)
            .textAlign(TextAlign.Center)
            .margin({ top: 10 })
          Scroll(this.scroller2) { // Internal scroll container.
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
          if (target) {
            if (target.getId() == "inner" && others[i].isBuiltIn() && others[i].getType() == GestureControl.GestureType.PAN_GESTURE) { // Find the recognizer that will form the parallel gesture recognition.
              this.currentRecognizer = current; // Save the recognizer of the current component.
              this.childRecognizer = others[i]; // Save the recognizer that will form the parallel gesture recognition.
              return others[i]; // Return the recognizer that will form the parallel gesture recognition.
            }
          }
        }
        return undefined;
      })
      .onGestureRecognizerJudgeBegin((event: BaseGestureEvent, current: GestureRecognizer, others: Array<GestureRecognizer>) => { // When the recognizer is about to succeed, set the enabled state of the recognizer based on the current component state.
        if (current) {
          let target = current.getEventTargetInfo();
          if (target) {
            if (target.getId() == "outer" && current.isBuiltIn() && current.getType() == GestureControl.GestureType.PAN_GESTURE) {
              if (others) {
                for (let i = 0; i < others.length; i++) {
                  let target = others[i].getEventTargetInfo() as ScrollableTargetInfo;
                  if (target instanceof ScrollableTargetInfo && target.getId() == "inner") { // Find the corresponding parallel recognizer in the response chain.
                    let panEvent = event as PanGestureEvent;
                    if (target.isEnd()) {// Dynamically control the enabled state of the recognizer based on the current component state and movement direction.
                      if (panEvent && panEvent.offsetY < 0) {
                        this.childRecognizer.setEnabled(false)
                        this.currentRecognizer.setEnabled(true)
                      } else {
                        this.childRecognizer.setEnabled(true)
                        this.currentRecognizer.setEnabled(false)
                      }
                    } else if (target.isBegin()) {
                      if (panEvent.offsetY > 0) {
                        this.childRecognizer.setEnabled(false)
                        this.currentRecognizer.setEnabled(true)
                      } else {
                        this.childRecognizer.setEnabled(true)
                        this.currentRecognizer.setEnabled(false)
                      }
                    } else {
                      this.childRecognizer.setEnabled(true)
                      this.currentRecognizer.setEnabled(false)
                    }
                  }
                }
              }
            }
          }
        }
        return GestureJudgeResult.CONTINUE;
      })
      .parallelGesture( // Bind a pan gesture as a dynamic controller.
        PanGesture()
          .onActionUpdate((event: GestureEvent)=>{
            if (this.childRecognizer.getState() != GestureRecognizerState.SUCCESSFUL || this.currentRecognizer.getState() != GestureRecognizerState.SUCCESSFUL) { // If the recognizer's state is not SUCCESSFUL, do not perform control.
              return;
            }
            let target = this.childRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
            let currentTarget = this.currentRecognizer.getEventTargetInfo() as ScrollableTargetInfo;
            if (target instanceof ScrollableTargetInfo && currentTarget instanceof ScrollableTargetInfo) {
              if (target.isEnd()) { // Based on the component state during the movement, control the enabled state of the recognizer.
                if ((event.offsetY - this.lastOffset) < 0) {
                  this.childRecognizer.setEnabled(false)
                  if (currentTarget.isEnd()) {
                    this.currentRecognizer.setEnabled(false)
                  } else {
                    this.currentRecognizer.setEnabled(true)
                  }
                } else {
                  this.childRecognizer.setEnabled(true)
                  this.currentRecognizer.setEnabled(false)
                }
              } else if (target.isBegin()) {
                if ((event.offsetY - this.lastOffset) > 0) {
                  this.childRecognizer.setEnabled(false)
                  if (currentTarget.isBegin()) {
                    this.currentRecognizer.setEnabled(false)
                  } else {
                    this.currentRecognizer.setEnabled(true)
                  }
                } else {
                  this.childRecognizer.setEnabled(true)
                  this.currentRecognizer.setEnabled(false)
                }
              } else {
                this.childRecognizer.setEnabled(true)
                this.currentRecognizer.setEnabled(false)
              }
            }
            this.lastOffset = event.offsetY
          })
      )
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```
