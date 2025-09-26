# Interaction Response Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

The ArkUI framework provides comprehensive interaction capabilities, supporting direct handling of basic input events, a gesture system built upon these events, and advanced interactions including drag-and-drop and focus management.

## Basic Input Event

When a user interacts with an input device (touchscreen, keyboard, mouse, or touchpad), the device driver generates signals that the system captures and delivers to the application. These signals are referred to as basic events.

Basic events are broadly categorized into two types: pointer and non-pointer events.

### Pointer Event

Pointer events carry location information indicating where the event occurred. The dispatch target is the component hit by the first event in the sequence (for example, **Down** or **Begin**).

Pointer events include [touch events](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md), [mouse events](../reference/apis-arkui/arkui-ts/ts-universal-mouse-key.md), and [axis events](../reference/apis-arkui/arkui-ts/ts-universal-events-axis.md).


### Non-pointer Event

Non-pointer events lack specific location information and do not depend on a particular operation location. The dispatch target is the currently focused component.

Non-pointer events include [key events](../reference/apis-arkui/arkui-ts/ts-universal-events-key.md), [crown events](../reference/apis-arkui/arkui-ts/ts-universal-events-crown.md), and [focus axis events](../reference/apis-arkui/arkui-ts/ts-universal-events-focus_axis.md).


### Additional Notes

Basic events typically begin with a start marker and end with an end marker, with multiple move or update events in between. For example: Touch event sequence: Down -> Move -> Move -> ... -> Up; Mouse wheel axis event sequence: Begin -> Update -> Update -> ... -> End.

Some basic events do not follow this pattern. For example, key events only have **Down** and **Up** states, with **Down** events reported continuously during sustained presses.

For pointer events, the system ensures that components participating in the response receive the complete event sequence, facilitating proper start/end timing management. For non-pointer events, this guarantee is not provided due to potential focus changes during the event sequence.

## Gesture System

A gesture is an interaction pattern recognized when a series of basic events meet specific characteristics. Example: A click is detected when a press and release occur within a short timeframe.

ArkUI built-in components (for example, buttons and lists) automatically recognize and handle common gestures. Applications can bind multiple gestures to a component, either implicitly (through default bindings) or explicitly. When a press occurs, all gestures registered on the hit component participate in recognition. They continue receiving input until one gesture is successfully recognized, after which only that gesture continues to process subsequent events.

Use exclusive gestures if two gestures must not both succeed. Use parallel gestures if gestures should coexist without conflict. For details, see [Combined Gestures](arkts-gesture-events-combined-gestures.md).

You can also dynamically decide which gestures can participate in processing only when the user presses down. For details, see [Gesture Conflict Handling](arkts-gesture-events-gesture-judge.md).


## Unified Drag-and-Drop

For details, see [Implementing Unified Drag and Drop](arkts-common-events-drag-event.md).

## Focus System

For details, see [Focus Event](arkts-common-events-focus-event.md).
