# Input_InterceptorEventCallback


## Overview

Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events.

**Since**: 12

**Related module**: [Input](input.md)

**Header file**: [oh_input_manager.h](oh__input__manager_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Input_MouseEventCallback](input.md#input_mouseeventcallback) [mouseCallback](#mousecallback) | Callback for mouse events. | 
| [Input_TouchEventCallback](input.md#input_toucheventcallback) [touchCallback](#touchcallback) | Callback for touch events. | 
| [Input_AxisEventCallback](input.md#input_axiseventcallback) [axisCallback](#axiscallback) | Callback for axis events. | 


## Member Variable Description


### axisCallback

```
Input_AxisEventCallback Input_InterceptorEventCallback::axisCallback
```
**Description**

Callback for axis events.

**Since**: 12


### mouseCallback

```
Input_MouseEventCallback Input_InterceptorEventCallback::mouseCallback
```
**Description**

Callback for mouse events.

**Since**: 12


### touchCallback

```
Input_TouchEventCallback Input_InterceptorEventCallback::touchCallback
```
**Description**

Callback for touch events.

**Since**: 12
