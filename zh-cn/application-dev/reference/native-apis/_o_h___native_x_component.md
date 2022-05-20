# Native XComponent


## **Overview**

**Description:**

Describes the surface and touch event held by the ArkUI XComponent, which can be used for the EGL/OpenGLES and media data input and displayed on the ArkUI XComponent.

**Since:**

8

**Version:**

1.0


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | Declares&nbsp;APIs&nbsp;for&nbsp;accessing&nbsp;a&nbsp;Native&nbsp;XComponent. | 


### Classes

  | Classe&nbsp;Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) |  | 
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) |  | 
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers&nbsp;the&nbsp;surface&nbsp;lifecycle&nbsp;and&nbsp;touch&nbsp;event&nbsp;callbacks. | 


### Macros

  | Macro&nbsp;Name&nbsp;and&nbsp;Value | Description | 
| -------- | -------- |
| **OH_NATIVE_XCOMPONENT_OBJ**&nbsp;&nbsp;&nbsp;("__NATIVE_XCOMPONENT_OBJ__") |  | 


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| OH_NativeXComponent | typedef&nbsp;struct&nbsp;OH_NativeXComponent<br/>Provides&nbsp;an&nbsp;encapsulated&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| OH_NativeXComponent_Callback | typedef&nbsp;struct&nbsp;OH_NativeXComponent_Callback<br/>Registers&nbsp;the&nbsp;surface&nbsp;lifecycle&nbsp;and&nbsp;touch&nbsp;event&nbsp;callbacks. | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| {&nbsp;OH_NATIVEXCOMPONENT_RESULT_SUCCESS&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_RESULT_FAILED&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER&nbsp;=&nbsp;-2&nbsp;} | Enumerates&nbsp;the&nbsp;API&nbsp;access&nbsp;states. | 
| OH_NativeXComponent_TouchEventType&nbsp;{&nbsp;&nbsp;&nbsp;OH_NATIVEXCOMPONENT_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_UP,&nbsp;OH_NATIVEXCOMPONENT_MOVE,&nbsp;OH_NATIVEXCOMPONENT_CANCEL,&nbsp;&nbsp;&nbsp;OH_NATIVEXCOMPONENT_UNKNOWN&nbsp;} |  | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_NativeXComponent_GetXComponentId&nbsp;(OH_NativeXComponent&nbsp;\*component,&nbsp;char&nbsp;\*id,&nbsp;uint64_t&nbsp;\*size) | int32_t<br/>Obtains&nbsp;the&nbsp;ID&nbsp;of&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| OH_NativeXComponent_GetXComponentSize&nbsp;(OH_NativeXComponent&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;uint64_t&nbsp;\*width,&nbsp;uint64_t&nbsp;\*height) | int32_t<br/>Obtains&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;surface&nbsp;held&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| OH_NativeXComponent_GetXComponentOffset&nbsp;(OH_NativeXComponent&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;double&nbsp;\*x,&nbsp;double&nbsp;\*y) | int32_t<br/>Obtains&nbsp;the&nbsp;offset&nbsp;of&nbsp;the&nbsp;surface&nbsp;held&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| OH_NativeXComponent_GetTouchEvent&nbsp;(OH_NativeXComponent&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;OH_NativeXComponent_TouchEvent&nbsp;\*touchEvent) | int32_t<br/>Obtains&nbsp;the&nbsp;touch&nbsp;event&nbsp;dispatched&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| OH_NativeXComponent_RegisterCallback&nbsp;(OH_NativeXComponent&nbsp;\*component,&nbsp;OH_NativeXComponent_Callback&nbsp;\*callback) | int32_t<br/>Registers&nbsp;a&nbsp;callback&nbsp;for&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 


## **Details**


## **Typedef**


### OH_NativeXComponent

  
```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**Description:**

Provides an encapsulated **OH_NativeXComponent** instance.


### OH_NativeXComponent_Callback

  
```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**Description:**

Registers the surface lifecycle and touch event callbacks.


## **Enumeration Type**


### anonymous enum

  
```
anonymous enum
```

**Description:**

Enumerates the API access states.

  | Enumerator | Description | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS | Success&nbsp;result. | 
| OH_NATIVEXCOMPONENT_RESULT_FAILED | Failed&nbsp;result. | 
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | Invalid&nbsp;parameters. | 


### OH_NativeXComponent_TouchEventType

  
```
enum OH_NativeXComponent_TouchEventType
```

  | Enumerator | Description | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_DOWN | Trigger&nbsp;a&nbsp;touch&nbsp;event&nbsp;when&nbsp;a&nbsp;finger&nbsp;is&nbsp;pressed. | 
| OH_NATIVEXCOMPONENT_UP | Trigger&nbsp;a&nbsp;touch&nbsp;event&nbsp;when&nbsp;a&nbsp;finger&nbsp;is&nbsp;lifted. | 
| OH_NATIVEXCOMPONENT_MOVE | Trigger&nbsp;a&nbsp;touch&nbsp;event&nbsp;when&nbsp;a&nbsp;finger&nbsp;moves&nbsp;on&nbsp;the&nbsp;screen&nbsp;in&nbsp;pressed&nbsp;state. | 
| OH_NATIVEXCOMPONENT_CANCEL | Trigger&nbsp;an&nbsp;event&nbsp;when&nbsp;a&nbsp;touch&nbsp;event&nbsp;is&nbsp;canceled. | 
| OH_NATIVEXCOMPONENT_UNKNOWN | Invalid&nbsp;touch&nbsp;type. | 


## **Function**


### OH_NativeXComponent_GetTouchEvent()

  
```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**Description:**

Obtains the touch event dispatched by the ArkUI XComponent.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| component | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| window | Indicates&nbsp;the&nbsp;native&nbsp;window&nbsp;handler. | 
| touchEvent | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;current&nbsp;touch&nbsp;event. | 

**Returns:**

Returns the status code of the execution.


### OH_NativeXComponent_GetXComponentId()

  
```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**Description:**

Obtains the ID of the ArkUI XComponent.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| component | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| id | Indicates&nbsp;the&nbsp;char&nbsp;buffer&nbsp;to&nbsp;keep&nbsp;the&nbsp;ID&nbsp;of&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance.&nbsp;Note&nbsp;that&nbsp;a&nbsp;null-terminator&nbsp;will&nbsp;be&nbsp;appended&nbsp;to&nbsp;the&nbsp;char&nbsp;buffer,&nbsp;so&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;char&nbsp;buffer&nbsp;should&nbsp;be&nbsp;at&nbsp;least&nbsp;as&nbsp;large&nbsp;as&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;real&nbsp;id&nbsp;length&nbsp;plus&nbsp;1.&nbsp;It&nbsp;is&nbsp;recommended&nbsp;that&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;char&nbsp;buffer&nbsp;be&nbsp;[OH_XCOMPONENT_ID_LEN_MAX&nbsp;+&nbsp;1]. | 
| size | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;length&nbsp;of&nbsp;**id**,&nbsp;which&nbsp;you&nbsp;can&nbsp;set&nbsp;and&nbsp;receive. | 

**Returns:**

Returns the status code of the execution.


### OH_NativeXComponent_GetXComponentOffset()

  
```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**Description:**

Obtains the offset of the surface held by the ArkUI XComponent.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| component | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| window | Indicates&nbsp;the&nbsp;native&nbsp;window&nbsp;handler. | 
| x | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;x&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;current&nbsp;surface. | 
| y | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;current&nbsp;surface. | 

**Returns:**

Returns the status code of the execution.


### OH_NativeXComponent_GetXComponentSize()

  
```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**Description:**

Obtains the size of the surface held by the ArkUI XComponent.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| component | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| window | Indicates&nbsp;the&nbsp;native&nbsp;window&nbsp;handler. | 
| width | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;width&nbsp;of&nbsp;the&nbsp;current&nbsp;surface. | 
| height | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;current&nbsp;surface. | 

**Returns:**

Returns the status code of the execution.


### OH_NativeXComponent_RegisterCallback()

  
```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**Description:**

Registers a callback for this **OH_NativeXComponent** instance.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| component | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| callback | Indicates&nbsp;the&nbsp;pointer&nbsp;to&nbsp;a&nbsp;surface&nbsp;lifecycle&nbsp;and&nbsp;touch&nbsp;event&nbsp;callback. | 

**Returns:**

Returns the status code of the execution.


## **Variable**


### deviceId

  
```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**Description:**

ID of the device where the current touch event is generated.


### DispatchTouchEvent

  
```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**Description:**

Called when a touch event is triggered.


### force [1/2]

  
```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**Description:**

Pressure of the current touch event.


### force [2/2]

  
```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**Description:**

Pressure of the current touch event.


### id [1/2]

  
```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**Description:**

Unique identifier of a finger.


### id [2/2]

  
```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**Description:**

Unique identifier of a finger.


### isPressed

  
```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**Description:**

Whether the current point is pressed.


### numPoints

  
```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**Description:**

Number of current touch points.


### OnSurfaceChanged

  
```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**Description:**

Called when the surface is changed. This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.


### OnSurfaceCreated

  
```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**Description:**

Called when the surface is created.


### OnSurfaceDestroyed

  
```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**Description:**

Called when the surface is destroyed.


### screenX [1/2]

  
```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**Description:**

X coordinate of the touch point relative to the left edge of the screen.


### screenX [2/2]

  
```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**Description:**

X coordinate of the touch point relative to the left edge of the screen.


### screenY [1/2]

  
```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**Description:**

Y coordinate of the touch point relative to the upper edge of the screen.


### screenY [2/2]

  
```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**Description:**

Y coordinate of the touch point relative to the upper edge of the screen.


### size [1/2]

  
```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**Description:**

Contact area between the finger pad and the screen.


### size [2/2]

  
```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**Description:**

Contact area between the finger pad and the screen.


### timeStamp [1/2]

  
```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**Description:**

Timestamp of the current touch event.


### timeStamp [2/2]

  
```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**Description:**

Timestamp of the current touch event.


### touchPoints

  
```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**Description:**

Array of the current touch points.


### type [1/2]

  
```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description:**

Touch type of the touch event.


### type [2/2]

  
```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description:**

Touch type of the touch event.


### x [1/2]

  
```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**Description:**

X coordinate of the touch point relative to the left edge of the element to touch.


### x [2/2]

  
```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**Description:**

X coordinate of the touch point relative to the left edge of the element to touch.


### y [1/2]

  
```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**Description:**

Y coordinate of the touch point relative to the upper edge of the element to touch.


### y [2/2]

  
```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**Description:**

Y coordinate of the touch point relative to the upper edge of the element to touch.
