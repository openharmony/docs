# oh_axis_type.h


## Overview

Defines the axis event structures and enumerations.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Library**: libohinput.so

**Since**: 12

**Related module**: [Input](input.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [InputEvent_AxisType](input.md#inputevent_axistype) [InputEvent_AxisType](input.md#inputevent_axistype) | Axis type of the input device. | 
| typedef enum [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) | Event type of the input device. | 
| typedef enum [InputEvent_AxisAction](input.md#inputevent_axisaction) [InputEvent_AxisAction](input.md#inputevent_axisaction) | Action of the input device. | 


### Enum

| Name| Description| 
| -------- | -------- |
| [InputEvent_AxisType](input.md#inputevent_axistype) {<br>[AXIS_TYPE_UNKNOWN](input.md), [AXIS_TYPE_SCROLL_VERTICAL](input.md), [AXIS_TYPE_SCROLL_HORIZONTAL](input.md), [AXIS_TYPE_PINCH](input.md),<br>[AXIS_TYPE_ROTATE](input.md)<br>} | Axis type of the input device. | 
| [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) { [AXIS_EVENT_TYPE_PINCH](input.md) = 1, [AXIS_EVENT_TYPE_SCROLL](input.md) = 2 } | Event type of the input device. | 
| [InputEvent_AxisAction](input.md#inputevent_axisaction) { [AXIS_ACTION_CANCEL](input.md) = 0, [AXIS_ACTION_BEGIN](input.md), [AXIS_ACTION_UPDATE](input.md), [AXIS_ACTION_END](input.md) } | Action of the input device. | 
