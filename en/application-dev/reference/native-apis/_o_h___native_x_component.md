# Native XComponent


## Overview

Describes the surface and touch event held by the ArkUI XComponent, which can be used for the EGL/OpenGL ES and media data input and displayed on the ArkUI XComponent.


**Since:**
8

## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | Declare the APIs used to access the native XComponent.<br>File to Include: <ace/xcomponent/native_interface_xcomponent.h>  | 


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) |  Describes the touch point of the touch event. | 
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | Describes the touch event.  | 
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | Describes the mouse event.  | 
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers a callback for the surface lifecycle and touch event.  | 
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | Registers a callback for the mouse event.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent](#oh_nativexcomponent)                  | Provides an encapsulated OH_NativeXComponent instance. |
| [OH_NativeXComponent_Callback](#oh_nativexcomponent_callback) | Registers a callback for the surface lifecycle and touch event. |
| [OH_NativeXComponent_MouseEvent_Callback](#oh_nativexcomponent_mouseevent_callback) | Registers a callback for the mouse event.   |


### Enums

| Name | Description | 
| -------- | -------- |
| {OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, <br>OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, <br/>OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 } | [Enumerates](#anonymous-enum) the API access states. |
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype) {  <br/>OH_NATIVEXCOMPONENT_DOWN = 0, <br/>OH_NATIVEXCOMPONENT_UP, <br/>OH_NATIVEXCOMPONENT_MOVE, <br/>OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN } | Enumerates the touch event types.   |
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) {<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS } | Enumerates the contact point tool types. | 
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) {<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK} | Enumerates the source types of the touch event. | 
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction) { <br/>OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, <br/>OH_NATIVEXCOMPONENT_MOUSE_PRESS, <br/>OH_NATIVEXCOMPONENT_MOUSE_RELEASE, <br/>OH_NATIVEXCOMPONENT_MOUSE_MOVE } | Enumerates the mouse event actions.        |
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton) {  <br/>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, <br/>OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, <br/>OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, <br/>OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,   <br/>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, <br/>OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10 } | Enumerates the mouse event buttons.   |


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_GetXComponentId](#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | Obtains the ID of the ArkUI XComponent.   |
| [OH_NativeXComponent_GetXComponentSize](#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | Obtains the size of the surface held by the ArkUI XComponent.  |
| [OH_NativeXComponent_GetXComponentOffset](#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | Obtains the offset of the ArkUI XComponent relative to the upper left vertex of the screen. |
| [OH_NativeXComponent_GetTouchEvent](#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | Obtains the touch event scheduled by the ArkUI XComponent.              |
| [OH_NativeXComponent_GetTouchPointToolType](#oh_nativexcomponent_gettouchpointtooltype) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) \*toolType) | Obtains the ArkUI XComponent touch point tool type. | 
| [OH_NativeXComponent_GetTouchPointTiltX](#oh_nativexcomponent_gettouchpointtiltx) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltX) | Obtains the angle between the tilt of the ArkUI XComponent touch point and the x-axis. | 
| [OH_NativeXComponent_GetTouchPointTiltY](#oh_nativexcomponent_gettouchpointtilty) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltY) | Obtains the angle between the tilt of the ArkUI XComponent touch point and the y-axis. | 
| [OH_NativeXComponent_GetMouseEvent](#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | Obtains the mouse event scheduled by ArkUI XComponent.   |
| [OH_NativeXComponent_RegisterCallback](#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | Registers a callback for this **OH_NativeXComponent** instance.  |
| [OH_NativeXComponent_RegisterMouseEventCallback](#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | Registers a mouse event callback for this **OH_NativeXComponent** instance.     |


### Variables

| Name | Description | 
| -------- | -------- |
| [OH_XCOMPONENT_ID_LEN_MAX](#oh_xcomponent_id_len_max) = 128  | Maximum length of an ArkUI XComponent ID.   |
| [OH_MAX_TOUCH_POINTS_NUMBER](#oh_max_touch_points_number) = 10 | Maximum number of identifiable touch points in a touch event. |
| [OH_NativeXComponent_TouchPoint::id](#id-12) = 0             | Unique identifier of the finger.  |
| [OH_NativeXComponent_TouchPoint::screenX](#screenx-13) = 0.0 | X coordinate of the touch point relative to the left edge of the screen.     |
| [OH_NativeXComponent_TouchPoint::screenY](#screeny-13) = 0.0 | Y coordinate of the touch point relative to the left edge of the screen.    |
| [OH_NativeXComponent_TouchPoint::x](#x-13) = 0.0             | X coordinate of the touch point relative to the left edge of the XComponent. |
| [OH_NativeXComponent_TouchPoint::y](#y-13) = 0.0             | Y coordinate of the touch point relative to the upper edge of the XComponent. |
| [OH_NativeXComponent_TouchPoint::type](#type-12) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.      |
| [OH_NativeXComponent_TouchPoint::size](#size-12) = 0.0       | Contact area between the finger pad and the screen. |
| [OH_NativeXComponent_TouchPoint::force](#force-12) = 0.0     | Pressure of the current touch event.    |
| [OH_NativeXComponent_TouchPoint::timeStamp](#timestamp-12) = 0 | Timestamp of the current touch event.     |
| [OH_NativeXComponent_TouchPoint::isPressed](#ispressed) = false | Whether the current point is pressed.      |
| [OH_NativeXComponent_TouchEvent::id](#id-22) = 0             | Unique identifier of the finger.   |
| [OH_NativeXComponent_TouchEvent::screenX](#screenx-23) = 0.0 | X coordinate of the touch point relative to the left edge of the screen.  |
| [OH_NativeXComponent_TouchEvent::screenY](#screeny-23) = 0.0 | Y coordinate of the touch point relative to the left edge of the screen.  |
| [OH_NativeXComponent_TouchEvent::x](#x-23) = 0.0             | X coordinate of the touch point relative to the left edge of the XComponent. |
| [OH_NativeXComponent_TouchEvent::y](#y-23) = 0.0             | Y coordinate of the touch point relative to the upper edge of the XComponent. |
| [OH_NativeXComponent_TouchEvent::type](#type-22) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.    |
| [OH_NativeXComponent_TouchEvent::size](#size-22) = 0.0       | Contact area between the finger pad and the screen.    |
| [OH_NativeXComponent_TouchEvent::force](#force-22) = 0.0     | Pressure of the current touch event.  |
| [OH_NativeXComponent_TouchEvent::deviceId](#deviceid) = 0    | ID of the device where the current touch event is triggered.  |
| [OH_NativeXComponent_TouchEvent::timeStamp](#timestamp-22) = 0 | Timestamp of the current touch event.  |
| [OH_NativeXComponent_TouchEvent::touchPoints](#touchpoints) [OH_MAX_TOUCH_POINTS_NUMBER] | Array of the current touch points.   |
| [OH_NativeXComponent_TouchEvent::numPoints](#numpoints) = 0  | Number of current touch points.    |
| [OH_NativeXComponent_MouseEvent::x](#x-33) = 0.0             | X coordinate of the clicked point relative to the upper left corner of the component. |
| [OH_NativeXComponent_MouseEvent::y](#y-33) = 0.0             | Y coordinate of the clicked point relative to the upper left corner of the component. |
| [OH_NativeXComponent_MouseEvent::screenX](#screenx-33) = 0.0 | X coordinate of the clicked point relative to the upper left corner of the screen.  |
| [OH_NativeXComponent_MouseEvent::screenY](#screeny-33) = 0.0 | Y coordinate of the clicked point relative to the upper left corner of the screen.  |
| [OH_NativeXComponent_MouseEvent::timestamp](#timestamp) = 0  | Timestamp of the current mouse event.  |
| [OH_NativeXComponent_MouseEvent::action](#action) = [OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE](#oh_nativexcomponent_mouseeventaction) | Current mouse event action.   |
| [OH_NativeXComponent_MouseEvent::button](#button) = [OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON](#oh_nativexcomponent_mouseeventbutton) | Mouse event button |
| [OH_NativeXComponent_Callback::OnSurfaceCreated](#onsurfacecreated) | Invoked when a surface is created.  |
| [OH_NativeXComponent_Callback::OnSurfaceChanged](#onsurfacechanged) | Invoked when the surface changes.    |
| [OH_NativeXComponent_Callback::OnSurfaceDestroyed](#onsurfacedestroyed) |  Invoked when the surface is destroyed.          |
| [OH_NativeXComponent_Callback::DispatchTouchEvent](#dispatchtouchevent) | Invoked when a touch event is triggered.  |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent](#dispatchmouseevent) | Invoked when a mouse event is triggered.     |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent](#dispatchhoverevent) | Invoked when a hover event is triggered.     |


## Type Description

### OH_NativeXComponent


```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**Description**

Provides an encapsulated OH_NativeXComponent instance.

**Since:**

8


### OH_NativeXComponent_Callback


```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**Description**

Registers a callback for the surface lifecycle and touch event.

**Since:**

8


### OH_NativeXComponent_MouseEvent_Callback


```
typedef struct OH_NativeXComponent_MouseEvent_Callback OH_NativeXComponent_MouseEvent_Callback
```

**Description**

Registers a callback for the mouse event.

**Since:**

9


## Enum Description

### anonymous enum


```
anonymous enum
```

**Description**

Enumerates the API access states.

| Name                                   | Description       |
| ---------------------------------------- | ---------- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS       | Success result. |
| OH_NATIVEXCOMPONENT_RESULT_FAILED        | Failure. |
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | Invalid parameter. |

**Since:**

8

### OH_NativeXComponent_EventSourceType

OH_NativeXComponent_EventSourceType

  
```
enum OH_NativeXComponent_EventSourceType
```

**Description**

Enumerates the source types of the touch event.

| Name | Description | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN | Unknown source type. | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE | Source that generates a mouse multi-touch event. | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | Source that generates a touchscreen multi-touch event. | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD | Source that generates a touchpad multi-touch event. | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK | Source that generates a joystick multi-touch event. | 

**Since:**

9

### OH_NativeXComponent_MouseEventAction


```
enum OH_NativeXComponent_MouseEventAction
```

**Description**

Enumerates the mouse event actions.

| Name                            | Description                             |
| --------------------------------- | -------------------------------- |
| OH_NATIVEXCOMPONENT_MOUSE_NONE    | Invalid mouse event.                  |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS   | The mouse event is triggered when a mouse button is pressed.    |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | The mouse event is triggered when a mouse button is released.     |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE    | The mouse event is triggered when the mouse moves on the screen. |

**Since:**

9


### OH_NativeXComponent_MouseEventButton


```
enum OH_NativeXComponent_MouseEventButton
```

**Description**

Enumerates the mouse event buttons.

| Name                             | Description                               |
| ---------------------------------- | ---------------------------------- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON    | The mouse event is triggered when no mouse button is pressed.     |
| OH_NATIVEXCOMPONENT_LEFT_BUTTON    | The mouse event is triggered when the left mouse button is pressed.  |
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON   | The mouse event is triggered when the right mouse button is pressed.       |
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON  | The mouse event is triggered when the middle mouse button is pressed.   |
| OH_NATIVEXCOMPONENT_BACK_BUTTON    | The mouse event is triggered when the back button on the left of the mouse is pressed. |
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON | The mouse event is triggered when the forward button on the left of the mouse is pressed. |

**Since:**

9


### OH_NativeXComponent_TouchEventType


```
enum OH_NativeXComponent_TouchEventType
```

**Description**

Enumerates the touch event types.

| Name                      | Description                                       |
| --------------------------- | ------------------------------------------ |
| OH_NATIVEXCOMPONENT_DOWN    | The touch event is triggered when a finger is pressed.    |
| OH_NATIVEXCOMPONENT_UP      | The touch event is triggered when a finger is lifted.  |
| OH_NATIVEXCOMPONENT_MOVE    | The touch event is triggered when a finger is pressed and moves on the screen.  |
| OH_NATIVEXCOMPONENT_CANCEL  | The event is triggered when a touch event is canceled.         |
| OH_NATIVEXCOMPONENT_UNKNOWN | Invalid touch type.       |

**Since:**

8

### OH_NativeXComponent_TouchPointToolType

  
```
enum OH_NativeXComponent_TouchPointToolType
```

**Description**

Enumerates the contact point tool types.

| Name | Description | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN | Unknown tool type. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER | Finger. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN | Stylus. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER | Eraser. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH | Brush. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL | Pencil. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | Air brush. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE | Mouse. | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS | Lens. | 

**Since:**

9


## Function Description


### OH_NativeXComponent_GetMouseEvent()


```
int32_t OH_NativeXComponent_GetMouseEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_MouseEvent * mouseEvent )
```

**Description**

Obtains the mouse event scheduled by ArkUI XComponent.

**Parameters**

| Name       | Description                                    |
| ---------- | --------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| window     | Indicates the pointer to a **NativeWindow** handle.                  |
| mouseEvent | Indicates the pointer to the current mouse event.     |

**Returns**

Returns the status code of the operation.

**Since:**

9


### OH_NativeXComponent_GetTouchEvent()


```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**Description**

Obtains the touch event scheduled by the ArkUI XComponent.

**Parameters**

| Name       | Description                                    |
| ---------- | --------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| window     | Indicates the pointer to a **NativeWindow** handle.                  |
| touchEvent | Indicates the pointer to the current touch event.           |

**Returns**

Returns the status code of the operation.

**Since:**

8

### OH_NativeXComponent_GetTouchPointTiltX()

  
```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltX )
```

**Description**

Obtains the angle between the tilt of the ArkUI XComponent touch point and the x-axis.

**Parameters**

| Name | Description | 
| -------- | -------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| pointIndex | Indicates the index of the pointer to a touch point. | 
| tiltX | Indicates the pointer to the tilt along the x-axis. | 

**Returns**

Returns the status code of the operation.

**Since:**

9


### OH_NativeXComponent_GetTouchPointTiltY()

  
```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltY )
```

**Description**

Obtains the angle between the tilt of the ArkUI XComponent touch point and the y-axis.

**Parameters**

| Name | Description | 
| -------- | -------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| pointIndex | Indicates the index of the pointer to a touch point. | 
| tiltY | Indicates the pointer to the tilt along the y-axis. | 

**Returns**

Returns the status code of the operation.

**Since:**

9


### OH_NativeXComponent_GetTouchPointToolType()

  
```
int32_t OH_NativeXComponent_GetTouchPointToolType (OH_NativeXComponent * component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType * toolType )
```

**Description**

Obtains the ArkUI XComponent touch point tool type.

**Parameters**

| Name | Description | 
| -------- | -------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| pointIndex | Indicates the index of the pointer to a touch point. | 
| toolType | Indicates the pointer to the tool type. | 

**Returns**

Returns the status code of the operation.

**Since:**

9


### OH_NativeXComponent_GetXComponentId()


```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**Description**

Obtains the ID of the ArkUI XComponent.

**Parameters**

| Name      | Description    |
| --------- | ------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| id        | Indicates the pointer to the character buffer used to hold the ID of the OH_NativeXComponent instance.<br>Note that the null terminator is attached to the character buffer, so the size of the character buffer should be at least one unit greater than the length of the real ID.<br>The recommended size of the character buffer is [OH_XCOMPONENT_ID_LEN_MAX + 1]. |
| size      | Indicates the pointer to the length of the ID.         |

**Returns**

Returns the status code of the operation.

**Since:**

8


### OH_NativeXComponent_GetXComponentOffset()


```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**Description**

Obtains the offset of the ArkUI XComponent relative to the upper left vertex of the screen.

**Parameters**

| Name      | Description                                    |
| --------- | --------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| window    | Indicates the pointer to a **NativeWindow** handle.  |
| x         | Indicates the pointer to the x coordinate of the current surface.    |
| y         | Indicates the pointer to the y coordinate of the current surface.      |

**Returns**

Returns the status code of the operation.

**Since:**

8


### OH_NativeXComponent_GetXComponentSize()


```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**Description**

Obtains the size of the surface held by the ArkUI XComponent.

**Parameters**

| Name      | Description                                    |
| --------- | --------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| window    | Indicates the pointer to a **NativeWindow** handle.  |
| width     | Indicates the pointer to the width of the current surface. |
| height    | Indicates the pointer to the height of the current surface.   |

**Returns**

Returns the status code of the operation.

**Since:**

8


### OH_NativeXComponent_RegisterCallback()


```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**Description**

Registers a callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name      | Description                                          |
| --------- | --------------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| callback  | Indicates the pointer to the surface lifecycle and touch event callback.|

**Returns**

Returns the status code of the operation.

**Since:**

8


### OH_NativeXComponent_RegisterMouseEventCallback()


```
int32_t OH_NativeXComponent_RegisterMouseEventCallback (OH_NativeXComponent * component, OH_NativeXComponent_MouseEvent_Callback * callback )
```

**Description**

Registers a mouse event callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name      | Description                                    |
| --------- | --------------------------------------- |
| component  | Indicates the pointer to an **OH_NativeXComponent** instance. |
| callback  | Indicates the pointer to the mouse event callback.    |

**Returns**

Returns the status code of the operation.

**Since:**

9


## Variable Description


### OH_XCOMPONENT_ID_LEN_MAX


```
const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128
```

**Description**

Maximum length of an ArkUI XComponent ID.

**Since:**

8


### OH_MAX_TOUCH_POINTS_NUMBER


```
const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10
```

**Description**

Maximum number of identifiable touch points in a touch event.

**Since:**

8


### action


```
OH_NativeXComponent_MouseEventAction OH_NativeXComponent_MouseEvent::action
```

**Description**

Current mouse event action.

**Since:**

8


### button


```
OH_NativeXComponent_MouseEventButton OH_NativeXComponent_MouseEvent::button
```

**Description**

Mouse event button

**Since:**

8


### deviceId


```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**Description**

ID of the device where the current touch event is triggered.

**Since:**

8


### DispatchHoverEvent


```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent) (OH_NativeXComponent *component, bool isHover)
```

**Description**

Invoked when a hover event is triggered.

**Since:**

8


### DispatchMouseEvent


```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a mouse event is triggered.

**Since:**

8


### DispatchTouchEvent


```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a touch event is triggered.

**Since:**

8


### force [1/2]


```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**Description**

Pressure of the current touch event.

**Since:**

8


### force [2/2]


```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**Description**

Pressure of the current touch event.

**Since:**

8


### id [1/2]


```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**Description**

Unique identifier of the finger.

**Since:**

8


### id [2/2]


```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**Description**

Unique identifier of the finger.

**Since:**

8


### isPressed


```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**Description**

Whether the current point is pressed.

**Since:**

8


### numPoints


```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**Description**

Number of current touch points.

**Since:**

8


### OnSurfaceChanged


```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when the surface changes.

**Since:**

8


### OnSurfaceCreated


```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a surface is created. 

**Since:**

8


### OnSurfaceDestroyed


```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when the surface is destroyed.

**Since:**

8


### screenX [1/3]


```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**Description**

X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since:**

8


### screenX [2/3]


```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**Description**

X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since:**

8


### screenX [3/3]


```
float OH_NativeXComponent_MouseEvent::screenX
```

**Description**

X coordinate of the clicked point relative to the upper left corner of the screen.

**Since:**

8


### screenY [1/3]


```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since:**

8


### screenY [2/3]


```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since:**

8


### screenY [3/3]


```
float OH_NativeXComponent_MouseEvent::screenY
```

**Description**

Y coordinate of the clicked point relative to the upper left corner of the screen.

**Since:**

8


### size [1/2]


```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**Description**

Contact area between the finger pad and the screen.

**Since:**

8


### size [2/2]


```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**Description**

Contact area between the finger pad and the screen.

**Since:**

8


### timeStamp [1/2]


```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**Description**

Timestamp of the current touch event.

**Since:**

8


### timeStamp [2/2]


```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**Description**

Timestamp of the current touch event.

**Since:**

8


### timestamp


```
int64_t OH_NativeXComponent_MouseEvent::timestamp
```

**Description**

Timestamp of the current mouse event.

**Since:**

8


### touchPoints


```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**Description**

Array of the current touch points.

**Since:**

8


### type [1/2]


```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description**

Touch type of the touch event.

**Since:**

8


### type [2/2]


```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description**

Touch type of the touch event.

**Since:**

8


### x [1/3]


```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**Description**

X coordinate of the touch point relative to the left edge of the XComponent.

**Since:**

8


### x [2/3]


```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**Description**

X coordinate of the touch point relative to the left edge of the XComponent.

**Since:**

8


### x [3/3]


```
float OH_NativeXComponent_MouseEvent::x
```

**Description**

X coordinate of the clicked point relative to the upper left corner of the component.

**Since:**

8


### y [1/3]


```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper edge of the XComponent.

**Since:**

8


### y [2/3]


```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper edge of the XComponent.

**Since:**

8


### y [3/3]


```
float OH_NativeXComponent_MouseEvent::y
```

**Description**

Y coordinate of the clicked point relative to the upper left corner of the component.

**Since:**

8