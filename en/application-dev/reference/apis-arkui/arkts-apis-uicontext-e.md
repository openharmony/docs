# Enums

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## KeyboardAvoidMode<sup>11+</sup>

Enumerates the modes in which the layout responds when the keyboard is displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| OFFSET | 0    | The layout moves up.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| RESIZE | 1    | The layout is resized.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| OFFSET_WITH_CARET<sup>14+</sup>  | 2 | The layout moves up, and this adjustment also occurs if the caret position in the text box changes.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| RESIZE_WITH_CARET<sup>14+</sup>  | 3 | The layout is resized, and this adjustment also occurs if the caret position in the text box changes.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| NONE<sup>14+</sup>  | 4 | The layout is not adjusted to avoid the keyboard.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## SwiperDynamicSyncSceneType<sup>12+</sup>

Enumerates the dynamic sync scene types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Value  | Description                  |
| -------- | ---- | ---------------------- |
| GESTURE | 0   | Gesture operation.|
| ANIMATION | 1   | Animation transition.|

## MarqueeDynamicSyncSceneType<sup>14+</sup>

Enumerates the dynamic sync scene types for the **Marquee** component.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Value  | Description                  |
| -------- | ---- | ---------------------- |
| ANIMATION | 1   | Animation transition.|

## NodeRenderState<sup>20+</sup>

Enumerates component rendering states.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value|Description|
| -------- | ------- | -------- |
| ABOUT_TO_RENDER_IN | 0 | The node has been attached to the render tree and will generally be rendered in the next frame. Under normal cases, it may be visible, but "being scheduled for rendering" does not equate to "guaranteed visibility".|
| ABOUT_TO_RENDER_OUT | 1 | The node has been removed from the render tree and will generally not be rendered in the next frame. Users will no longer see this node.|

## GestureActionPhase<sup>20+</sup>

Enumerates triggering phases of gesture callbacks, corresponding to the action callbacks defined in **gesture.d.ts**. However, different gesture types support different phases (for example, **SwipeGesture** only includes the **WILL_START** enumerated value).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| WILL_START | 0 | The gesture has been successfully recognized by the system, and the **onActionStart** or **onAction** callback will be triggered immediately. If the gesture is bound to **onActionStart**, the callback is triggered at **onActionStart**. If the gesture is bound to **onAction**, the callback is triggered at **onAction**. If both are bound, the callback is triggered at **onActionStart** with priority. If neither is bound, no callback will be triggered. Some containers (for example, scrollable containers) have built-in gestures bound to callbacks, which support the above callback triggering mechanism by default. For these containers, callbacks can be triggered without explicit binding.|
|  WILL_END | 1 | The gesture has been determined to be in an ended state (typically occurring when the user lifts their finger to terminate the interaction). The **onActionEnd** callback will be triggered immediately, but the gesture must be explicitly bound to **onActionEnd**. Some containers (for example, scrollable containers) have built-in gestures bound to callbacks, which support this end-state determination by default. For these containers, the **onActionEnd** callback can be triggered without explicit binding.|

## GestureListenerType<sup>20+</sup>

Enumerates the types of gestures to be listened for.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| TAP | 0 | Tap gesture.|
| LONG_PRESS | 1 | Long press gesture.|
| PAN  | 2 | Pan gesture.|
| PINCH | 3 | Pinch gesture.|
| SWIPE | 4| Swipe gesture.|
| ROTATION| 5 | Rotation gesture.|
