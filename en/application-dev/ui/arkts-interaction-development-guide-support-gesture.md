# Implementing Gesture Responses
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

When a user's action matches the predefined characteristics of a gesture, the system interprets it as a recognized gesture. This process is known as gesture recognition. To respond to gestures, you must bind the appropriate gesture object to a component. This enables the system to detect, interpret, and dispatch gesture events accordingly.

## Overview of Basic Gestures

| Gesture                                                                                                                                                    | Operation Characteristics                                                                                     | Triggering Example                                                                                                                    |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| [TapGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-tapgesture.md)             | A quick press and release (≤ 300 ms by default).                                                          | Tap with a finger or stylus on a touchscreen; left-click with a mouse; single tap on a touchpad.                                                                          |
| [LongPressGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md) | Long press for a sustained duration.                                                                       | Long press with a finger or stylus; hold down the left mouse button; long press on a touchpad.                                                                                |
| [PanGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md)             | Press and drag (displacement-based movement).                                                                           | Drag with a finger or stylus; move the mouse while holding the left button; swipe with two fingers on a touchpad; scroll the mouse wheel over a scrollable component.|
| [PinchGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md)         | Pinch inward or outward using two fingers.                                                             | Pinch gesture on touchscreen or touchpad; scroll the mouse wheel while holding **Ctrl** over a pinch-enabled component.                  |
| [RotationGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md)   | Rotate two fingers around a central point.                                                                       | Rotate gesture using two fingers on a touchscreen.                                                                                                                  |
| [SwipeGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-swipegesture.md)         | Speed-based directional swipe (triggered on release velocity). The key distinction between **PanGesture** and **SwipeGesture** lies in their recognition criteria: **PanGesture** is triggered based on movement distance while the pointer is still active; **SwipeGesture** is triggered based on release velocity after the pointer is lifted.| Quick swipe with one finger on a touchscreen; two-finger swipe on a touchpad; fast scroll with a mouse wheel.                                                                    |


## Gesture Response Rules

Basic Rules
- Gesture recognition is based on the component hit at a specific location and time.
- If multiple components define the same gesture type, the gesture on the child component takes precedence over the parent.
- For gestures with different recognition conditions, the gesture that meets its condition first is triggered.
- If no parallel gestures are defined, once one gesture succeeds, others are excluded from recognition during that interaction.
- When a gesture of the same type succeeds on a child component, the same gesture type on the parent component is also considered successful.
- Built-in gestures (automatically bound by the framework) have higher priority than developer-defined gestures of the same type, unless you explicitly sets a higher priority using the **priority** binding mode.

The following scenarios illustrate these rules in practice:

**Scenario 1**:

![Scenario 1](figures/gesture-senario-01.png)

Pan A and Pan B are defined with identical threshold conditions. Pan B is bound to a child component, while Pan A is bound to the parent. As a result, Pan B is triggered first due to child component precedence.

**Scenario 2**:

![Scenario 2](figures/gesture-senario-02.png)

Pan A and Pan B are defined with different threshold conditions. Pan B is on a child component and has higher structural priority. However, Pan A has a lower threshold and may succeed first under normal movement speed. If the movement speed is high, both gestures may succeed due to spacing between report points. In this case, Pan B wins in contention because it processes the report point first.

**Scenario 3**:

![Scenario 3](figures/gesture-senario-03.png)

The gesture that matches the actual user operation is triggered.
Example: If the user lifts their finger before the pan gesture threshold is met, a tap gesture is recognized instead.


## Intervention in Gesture Processing

While the ArkUI gesture framework automatically handles gesture recognition based on predefined rules, applications often require dynamic control over gesture behavior. This allows you to intervene in the recognition process to achieve specific interaction outcomes, as long as the standard response rules are respected.

Gesture recognition is still initiated based on [hit testing](./arkts-interaction-basic-principles.md#hit-testing), and any method used to intervene in basic event processing can also be applied to gestures. In addition, ArkUI offers several advanced APIs for gesture-level intervention:

| Method              | Purpose                                                            | API                                                                                                                                       | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| ------------------ | ---------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Custom gesture judgment    | Allows applications to conditionally approve or reject a gesture before the system finalizes recognition.  | [onGestureJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-customize-judge.md#ongesturejudgebegin)                                      | Invoked when a gesture is about to be recognized as successful. The application can override the system's decision by returning a rejection, allowing other gestures to compete for recognition.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Enhanced gesture judgment| Provides higher-priority control over gesture recognition.| [onGestureRecognizerJudgeBegin](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ongesturerecognizerjudgebegin13)           | 1. Works similarly to **onGestureJudgeBegin**, but with higher priority.<br>2. If this API is bound, **onGestureJudgeBegin** becomes ineffective.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Parallel gesture control  | Enables concurrent gesture recognition between parent and child components, which is useful for nested scrolling. | [shouldBuiltInRecognizerParallelWith](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#shouldbuiltinrecognizerparallelwith) | 1. Triggered when the user presses a component and the system begins collecting gesture objects.<br>2. Returns built-in gestures (currently only **PanGesture**) on the current component and previously collected gestures of the same type from child components. By default, child gestures have higher priority and override parent gestures.<br>3. This API allows you to force parallel recognition, enabling both parent and child gestures to respond.<br>4. The returned gesture object includes APIs for controlling response behavior, allowing you to implement nested scrolling (for example, the child scrolls first, and then the parent scrolls when the child reaches the boundary).<br>**NOTE**<br>This API only applies to components with built-in gestures (for example, **List** and **Swiper**). It has no effect otherwise.|
| Gesture recognition prevention  | Prevents specific gestures from participating in recognition before they are processed. | [preventBegin](../reference/apis-arkui/arkui-ts/ts-gesture-common.md#preventbegin20) | 1. Triggered during the [onTouchTestDone](../reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#ontouchtestdone20) callback when the user presses the screen.<br>2. Returns all gesture recognizers eligible for processing at the current position.<br>3. You can selectively call **preventBegin** on recognizers to exclude them from recognition, helping avoid gesture conflicts.|


For details, see [Gesture Conflict Handling](arkts-gesture-events-gesture-judge.md).
