# oh_axis_type.h

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

Defines the axis event structures and enumerations.

**File to include**: <multimodalinput/oh_axis_type.h>

**Library**: libohinput.so

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Related module**: [input](capi-input.md)

## Summary

### Enums

| **Name**| typedef Keyword| Description|
| -- | -- | -- |
| [InputEvent_AxisType](#inputevent_axistype) | InputEvent_AxisType | Provides axis types of the input device.|
| [InputEvent_AxisEventType](#inputevent_axiseventtype) | InputEvent_AxisEventType | Provides event types of the input device.|
| [InputEvent_AxisAction](#inputevent_axisaction) | InputEvent_AxisAction | Provides actions of the input device.|

## Enum Description

### InputEvent_AxisType

```
enum InputEvent_AxisType
```

**Description**

Defines the axis type of an input device.

**Since**: 12

| Enum| Description            |
| -- |----------------|
| AXIS_TYPE_UNKNOWN | Unknown axis type, which is usually used as the initial value.|
| AXIS_TYPE_SCROLL_VERTICAL | Vertical scroll axis. When you scroll the mouse wheel or slide with one or two fingers on the touchpad, the status of the vertical scroll axis changes.              |
| AXIS_TYPE_SCROLL_HORIZONTAL | Horizontal scroll axis. When you scroll the mouse wheel or slide with two fingers on the touchpad, the status of the horizontal scroll axis changes.              |
| AXIS_TYPE_PINCH | Pinch axis, which is used to describe a two-finger pinch gesture on the touchpad.              |
| AXIS_TYPE_ROTATE | Rotation axis, which is used to describe a two-finger rotation gesture on the touchpad.              |

### InputEvent_AxisEventType

```
enum InputEvent_AxisEventType
```

**Description**

Event type of the input device.

**Since**: 12

| Enum| Description|
| -- | -- |
| AXIS_EVENT_TYPE_PINCH = 1 | Two-finger pinch event. The value can be **AXIS_TYPE_PINCH** or **AXIS_TYPE_ROTATE**.		<br>**Since**: 12|
| AXIS_EVENT_TYPE_SCROLL = 2 | Scroll axis event. The value can be **AXIS_TYPE_SCROLL_VERTICAL** and **AXIS_TYPE_SCROLL_HORIZONTAL**. For mouse wheel events, the value can only be **AXIS_TYPE_SCROLL_VERTICAL**.		<br>**Since**: 12|

### InputEvent_AxisAction

```
enum InputEvent_AxisAction
```

**Description**

Action of the input device.

**Since**: 12

| Enum| Description|
| -- | -- |
| AXIS_ACTION_CANCEL = 0 | Cancellation of an axis input event.|
| AXIS_ACTION_BEGIN | Start of an axis input event.|
| AXIS_ACTION_UPDATE | Update of an axis input event.|
| AXIS_ACTION_END | End of an axis input event.|
