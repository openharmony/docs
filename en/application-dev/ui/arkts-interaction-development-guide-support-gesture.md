# Implementing Gesture Responses

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c8954d33bacbdec6df88d8586db7cc9b9d8a799e translatedAt=2026-08-01T00:30:48.256Z pushedAt=2026-08-03T01:45:12.158Z -->

When a user action matches the predefined characteristics of a gesture, the system recognizes it as that gesture. This process is called gesture recognition. To respond to a gesture, you need to attach a gesture object to a component so the system can collect and process the gesture input.

## Basic Gestures and Features

| Gesture                                                                                                                                                    | Operation Feature                                                                                     | Triggering Example                                                                                                                    |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| [TapGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-tapgesture.md)             | Quick press and release (≤ 300 ms by default).                                                          | Tap with a finger or stylus on a touchscreen; left-click with a mouse; single tap on a touchpad.                                                                          |
| [LongPressGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md) | Press and hold for a sustained duration.                                                                       | Long press with a finger or stylus; hold down the left mouse button; long press on a touchpad.                                                                                |
| [PanGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md)             | Press and drag (displacement-based movement).                                                                           | Drag with a finger or stylus; move the mouse while holding the left button; swipe with two fingers on a touchpad; scroll the mouse wheel over a scrollable component.|
| [PinchGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md)         | Pinch (moving two fingers inward to pinch or outward to expand after pressing down)                                                              | Pinching with two fingers on the touchscreen, pinching with two fingers on the touchpad, or scrolling the mouse wheel while pressing the Ctrl key on the physical keyboard when the mouse pointer points to a component that responds to the pinch gesture.                   |
| [RotationGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md)   | Rotate two fingers around a central point.                                                                       | Rotate gesture using two fingers on a touchscreen.                                                                                                                  |
| [SwipeGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-swipegesture.md)         | Speed-based directional swipe (triggered on release velocity). The key distinction between **PanGesture** and **SwipeGesture** lies in their recognition criteria: **PanGesture** is triggered based on movement distance while the pointer is still active; **SwipeGesture** is triggered based on release velocity after the pointer is lifted.| Quick swipe with one finger on a touchscreen; two-finger swipe on a touchpad; fast scroll with a mouse wheel.                                                                    |

## Gesture Response Rules

Basic Rules

- Gesture recognition is based on the component hit at a specific location and time.

- If multiple components define the same gesture type, the gesture on the child component takes precedence over the parent.

- For gestures with different recognition conditions, the gesture that meets its condition first is triggered.

- If no parallel gestures are defined, once one gesture succeeds, others are excluded from recognition during that interaction.

- When a gesture of the same type succeeds on a child component, the same gesture type on the parent component is also considered successful.

- Built-in gestures (automatically bound by the framework) have higher priority than developer-defined gestures of the same type, unless you explicitly set a higher priority using the **priority** binding mode.

The following scenarios illustrate these rules in practice:

**Scenario 1**:

![Scenario 1](figures/gesture-scenario-01.png)

Pan A and Pan B are defined with identical threshold conditions. Pan B is bound to a child component, while Pan A is bound to the parent. As a result, Pan B is triggered first due to child component precedence.

**Scenario 2**:

![Scenario 2](figures/gesture-scenario-02.png)

Pan A and Pan B are defined with different threshold conditions. Pan B is on a child component and has higher structural priority. However, Pan A has a lower threshold and may succeed first under normal movement speed. If the movement speed is high, both gestures may succeed due to spacing between report points. In this case, Pan B wins in contention because it processes the report point first.

**Scenario 3**:

![Scenario 3](figures/gesture-scenario-03.png)

The gesture that matches the actual user operation is triggered.

Example: If the user lifts their finger before the pan gesture threshold is met, a tap gesture is recognized instead.

## Intervention in Gesture Processing

While the ArkUI gesture framework handles gesture recognition based on predefined rules, applications often require dynamic control over gesture behavior. This allows you to intervene in the recognition process to achieve specific interaction outcomes, as long as the standard response rules are respected.

Gesture recognition is still initiated based on [hit testing](./arkts-interaction-basic-principles.md#hit-testing), and any method used to intervene in basic event processing can also be applied to gestures. In addition, ArkUI offers several advanced APIs for gesture-level intervention:

| Method              | Purpose                                                            | API                                                                                                                                       | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| ------------------ | ---------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Custom gesture judgment    | Allows applications to conditionally approve or reject a gesture before the system finalizes recognition.  | [onGestureJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-customize-judge.md#ongesturejudgebegin)                                      | Invoked when a gesture is about to be recognized as successful. The application can override the system's decision by returning a rejection, allowing other gestures to compete for recognition.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Enhanced gesture judgment| Allows applications to conditionally approve or reject a gesture before the system finalizes recognition.| [onGestureRecognizerJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ongesturerecognizerjudgebegin13)           | 1. Works similarly to **onGestureJudgeBegin**, but with higher priority.<br>2. If this API is bound, **onGestureJudgeBegin** becomes ineffective.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Gesture Parallel Dynamic Control | Controls the linkage between PAN gestures of parent and child (ancestor and descendant) components to implement nested scrolling. | [shouldBuiltInRecognizerParallelWith](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#shouldbuiltinrecognizerparallelwith) | 1. Triggered when the user presses down and the system starts collecting all gesture objects at the current position that need to participate in gesture processing.<br/>2. When the callback is triggered, it provides the built-in system gesture on the current component (currently only the pan gesture is supported), along with gesture objects of the same type (pan gestures) that the system has already collected before the current component. These gestures form an array and generally come from child components, so they have a higher response priority than the same-type gesture on the current component. Under normal circumstances, the gesture on the current component cannot compete with the gestures from child components.<br/>3. This callback method gives the app an opportunity to forcibly specify that its own lower-priority gesture of the same type (pan gesture) runs in parallel with the higher-priority gesture of the same type on the child component. That is, when the higher-priority gesture of the same type on the child component succeeds, the gesture on the current component can also be successfully triggered and thus respond.<br/>4. The returned gesture object provides an interface for controlling gesture response enablement. Therefore, after the gestures run in parallel, the app can independently control the response behavior of the two parallel gestures, thereby achieving a nested scrolling effect (one scrolls first, and when it reaches the bottom, the other is triggered to continue scrolling).<br/>**Note:**<br/>When using this method, ensure that the bound component has a built-in system gesture (such as List or Swiper). Otherwise, using this method has no effect and is meaningless. |
| Gesture recognition prevention  | Prevents specific gestures from participating in recognition before they are processed. | [preventBegin](../reference/apis-arkui/arkui-ts/ts-gesture-common.md#preventbegin20) | 1. Triggered during the [onTouchTestDone](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ontouchtestdone20) callback when the user presses the screen.<br>2. Returns all gesture recognizers eligible for processing at the current position.<br>3. You can selectively call **preventBegin** on recognizers to exclude them from recognition, helping avoid gesture conflicts.<br>This capability is supported since API version 20.|

For details, see [Gesture Conflict Handling](arkts-gesture-events-gesture-judge.md).