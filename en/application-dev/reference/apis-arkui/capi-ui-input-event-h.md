# ui_input_event.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Provides ArkUI event definitions on the native side.

**File to include**: <arkui/ui_input_event.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_EventModule](capi-arkui-eventmodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) | ArkUI_UIInputEvent | Defines the UI input event.|

### Enums

| Name                                                 | typedef Keyword| Description|
|-----------------------------------------------------| -- | -- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) | ArkUI_UIInputEvent_Type | Enumerates the UI input event types.|
| [anonymous1](#anonymous1)                       | - | Enumerates the action codes of the input event.|
| [anonymous2](#anonymous2)                       | - | Enumerates the tool types of the input event.|
| [anonymous3](#anonymous3)                       | - | Enumerates the source types of the input event.|
| [HitTestMode](#hittestmode)                         | HitTestMode | Enumerates the hit test modes.|
| [anonymous4](#anonymous4)                       | - | Enumerates the action codes of the mouse event.|
| [anonymous5](#anonymous5)                       | - | Enumerates the button types of the mouse event.|
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname)     | ArkUI_ModifierKeyName | Enumerates the modifier keys.|
| [anonymous6](#anonymous6)                       | - | Enumerates the axis types for focus axis events.|
| [ArkUI_InteractionHand](#arkui_interactionhand)     | ArkUI_InteractionHand | Defines whether the touch event is from the left or right hand.|
| [anonymous7](#anonymous7)                       | - | Enumerates the action types for axis events.|

### Functions

| Name| Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettype) | Obtains the type of a UI input event. Before accessing an **ArkUI_UIInputEvent** pointer, use this API to determine the type of the input event. This API returns a value from the [ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type) enum. It helps ensure compatibility with subsequent accessors. For example, if the event is a touch event, which is directional, you can use OH_ArkUI_UIInputEvent_GetXXX or OH_ArkUI_PointerEvent_GetXXX for access. Using OH_ArkUI_KeyEvent_GetXXX to access the event may produce undefined behavior. For unsupported event types, this API returns the default value **0**.                                                                                                                                                                                                                                                      |
| [int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getaction) | Obtains the action type of an input event. The action type defines the phase of a basic event (for example, start or end) and characterizes its behavior, such as touch down or touch up. Action types are specific to the event category: UI_TOUCH_EVENT_ACTION_XXX for touch events and UI_MOUSE_EVENT_ACTION_XXX for mouse events.                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getsourcetype) | Obtains the source type of a UI input event. The source represents the physical device, such as a touchscreen or mouse device, that generates the event. It is defined by the UI_INPUT_EVENT_SOURCE_TYPE_XXX enum. This is different from the input tool, which is the device used to interact with the source, for example, a finger or stylus. However, in certain cases, the input source and the input tool can be the same. For example, a mouse device acts as both the source and tool for click events.                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettooltype) | Obtains the tool type of a UI input event. The input tool is the device used to interact with the input source, such as a finger or stylus. These tools themselves do not generate events but can drive the input source device to continuously generate events. The returned type is defined by the enumerated value of UI_INPUT_EVENT_TOOL_TYPE_XXX.                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [int64_t OH_ArkUI_UIInputEvent_GetEventTime(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtime) | Obtains the time when a specified UI input event occurs. The unit is ns.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getpointercount) | Obtains the number of contact points from a pointer event (such as a touch, mouse, or axis event). Pointer events are typically events that carry position information, such as touch events, where the location of the event can be determined. Non-pointer events, such as key events, do not have position information and do not involve contact points, so this API is not applicable to key events. For touch events, this API returns the number of active touch points, for example, fingers on the screen. For mouse and axis events, this API always returns **1**, as they are single-pointer interactions.                                                                                                                                                                                                                                                                                                                                                                                 |
| [int32_t OH_ArkUI_PointerEvent_GetPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpointerid) | Obtains the unique ID of a contact point from a pointer event (such as a touch, mouse, or axis event). The ID distinguishes between multiple contact points from the same input device. The return value itself does not have any other meaning beyond identifying the contact point.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)](#oh_arkui_pointerevent_getchangedpointerid) | Obtains the ID of the touch pointer that triggers the current touch event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getx) | Obtains the x-coordinate relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getxbyindex) | Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gety) | Obtains the y-coordinate relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getybyindex) | Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowx) | Obtains the x-coordinate relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetWindowXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowxbyindex) | Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowy) | Obtains the y-coordinate relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetWindowYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowybyindex) | Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayx) | Obtains the x-coordinate relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayxbyindex) | Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayy) | Obtains the y-coordinate relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayybyindex) | Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayx) | Obtains the x-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayxbyindex) | Obtains the x-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayy) | Obtains the y-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayybyindex) | Obtains the y-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpressure) | Obtains the pressure applied to the touchscreen from a pointer event (for example, a touch event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettiltx) | Obtains the tilt angle relative to the YZ plane from a pointer event. The value range is [-90, 90], where positive values indicate a rightward tilt. This API is applicable only to stylus-based touch events from devices that support tilt angle reporting.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettilty) | Obtains the tilt angle relative to the XZ plane from a pointer event. The value range is [-90, 90], where positive values indicate a rightward tilt. This API is applicable only to stylus-based touch events from devices that support tilt angle reporting.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_PointerEvent_GetRollAngle(const ArkUI_UIInputEvent* event, double* rollAngle)](#oh_arkui_pointerevent_getrollangle) | Obtains the rotation angle of the stylus around the z-axis from a UI input event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareawidth) | Obtains the width of the contact area for a pointer event. This API is applicable only to finger-based touch events, and the return value typically represents the radius of a circular touch area.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareaheight) | Obtains the height of the contact area for a pointer event. This API is applicable only to finger-based touch events, and the return value typically represents the radius of a circular touch area.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhand) | Checks whether an event is triggered by a left-hand or right-hand tap. This API is only effective on some touch devices.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhandbyindex) | Checks whether an event is triggered by a left-hand or right-hand tap. This API is only effective on some touch devices.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gethistorysize) | Obtains the number of historical events from a pointer event (such as a touch event). Historical events are the raw events that occur between the current event and the previous event. This API is applicable only to move events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryeventtime) | Obtains the occurrence time of a historical event from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointercount) | Obtains the number of touch points in a specific historical event from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointerid) | Obtains the unique ID of a contact point from a historical event of a pointer event (such as a touch event). The ID distinguishes between multiple contact points from the same input device. The return value itself does not have any other meaning beyond identifying the contact point.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryx) | Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryy) | Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowx) | Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowy) | Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayx) | Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayy) | Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayx) | Obtains the x-coordinate relative to the global display for a specific touch point from historical events, based on the given pointer index and history index of an input event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayy) | Obtains the y-coordinate relative to the global display for a specific touch point from historical events, based on the given pointer index and history index of an input event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypressure) | Obtains the pressure applied to the touchscreen in a specific historical event from a pointer event (for example, a touch event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytiltx) | Obtains the angle relative to the YZ plane in a specific historical event from a pointer event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytilty) | Obtains the angle relative to the XZ plane in a specific historical event from a pointer event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareawidth) | Obtains the width of the touch area in a specific historical event from a pointer event (for example, a touch event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareaheight) | Obtains the height of the touch area in a specific historical event from a pointer event (for example, a touch event).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getverticalaxisvalue) | Obtains the value of the vertical scroll axis for this axis event. This value is typically generated by mouse wheel scrolling or two-finger vertical swiping on a touchpad. If the value is generated by mouse wheel scrolling: 1. The reported value is in degrees and represents the incremental angle of a single scroll, not the total scroll amount. 2. The reported value includes the user's scroll step configuration (see [OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)). 3. The sign of the value indicates the direction: positive for forward scrolling and negative for backward scrolling. If the value is generated by two-finger vertical swiping on a touchpad: 1. The reported value is in px and represents the incremental scroll amount, not the total scroll amount. 2. The reported value does not include the user's scroll step configuration [OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep). 3. The sign of the value indicates the direction: positive for swiping down and negative for swiping up. 4. The direction is affected by the system settings for natural scrolling. Under normal circumstances, vertical scroll axis events only drive vertical swipe gestures. However, if the mouse pointer is over a scrollable area where the scrollable directions are consistent, the vertical scroll axis event can drive the swipe gestures in this scrollable area, even if they are defined as horizontal.|
| [double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_gethorizontalaxisvalue) | Obtains the value of the horizontal scroll axis for this axis event. This value is generated by two-finger horizontal swiping on a touchpad.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getpinchaxisscalevalue) | Obtains the scale value of the pinch axis for this axis event. This value is generated by a two-finger pinch gesture on a touchpad. The reported scale value is relative to the initial state when the system first detects the pinch gesture, with an initial scale value of 1.0. During the pinch operation, the scale value decreases from 1.0 towards 0.0 when the user pinches inward and increases from 1.0 when the user spreads fingers outward.                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getaxisaction) | Obtains the action type of this axis event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)](#oh_arkui_pointerevent_setintercepthittestmode) | Sets how the component behaves during hit testing. This API only applies to scenarios raw input events are received, such as when **NODE_ON_TOUCH** is used for touch event handling. It cannot be used with **ArkUI_UIInputEvent** objects obtained from gesture events through [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent).                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_MouseEvent_GetMouseButton(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmousebutton) | Obtains the button type of a mouse event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_MouseEvent_GetMouseAction(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmouseaction) | Obtains the action type of a mouse event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_pointerevent_setstoppropagation) | Sets whether to stop event propagation. This API only applies to scenarios raw input events are received, such as when **NODE_ON_TOUCH** is used for touch event handling. It cannot be used with **ArkUI_UIInputEvent** objects obtained from gesture events through [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent).                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getdeviceid) | Obtains the ID of the input device that triggers a key event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_UIInputEvent_GetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t* length)](#oh_arkui_uiinputevent_getpressedkeys) | Obtains all pressed keys. Currently, only key events are supported.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [double OH_ArkUI_FocusAxisEvent_GetAxisValue(const ArkUI_UIInputEvent* event, int32_t axis)](#oh_arkui_focusaxisevent_getaxisvalue) | Obtains the axis value of a focus axis event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_focusaxisevent_setstoppropagation) | Sets whether to prevent a focus axis event from bubbling up.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)](#oh_arkui_uiinputevent_getmodifierkeystates) | Obtains the modifier key states for a UI input event. This API outputs the state of all modifier keys at the time of the event through the **keys** parameter. You can determine which keys are pressed by performing bitwise operations with the modifier key types defined in [ArkUI_ModifierKeyName](capi-ui-input-event-h.md#arkui_modifierkeyname).                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_AxisEvent_SetPropagation(const ArkUI_UIInputEvent* event, bool propagation)](#oh_arkui_axisevent_setpropagation) | Sets whether to enable axis event propagation (bubbling). By default, axis events do not bubble and are only sent to the first component that can respond to axis events. You can enable axis event bubbling when an axis event is received to allow the event to be passed to the next ancestor component in the response chain that can handle axis events. This API cannot be used on axis events obtained from gesture events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_AxisEvent_GetScrollStep(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getscrollstep) | Obtains the scroll step coefficient for a wheel-based axis event. This API returns the user-configured scroll scale factor.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetwidth) | Obtains the width of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetheight) | Obtains the height of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetpositionx) | Obtains the x-coordinate of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetpositiony) | Obtains the y-coordinate of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetglobalpositionx) | Obtains the global x-coordinate of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetglobalpositiony) | Obtains the global y-coordinate of the component hit by an event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpressedtimebyindex) | Obtains the press time of a specified touch point. This API is effective only for touch events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltax) | Obtains the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported x-coordinates when the mouse pointer is near the screen edge.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltay) | Obtains the y-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported y-coordinates when the mouse pointer is near the screen edge.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)](#oh_arkui_mouseevent_getpressedbuttons) | Obtains the pressed buttons from a mouse event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettargetdisplayid) | Obtains the ID of the screen where the UI input event occurs.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)](#oh_arkui_hoverevent_ishovered) | Checks whether the cursor is hovering over this component.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)](#oh_arkui_pointerevent_createclonedevent) | Creates a cloned event pointer based on an event pointer. This API is effective only for touch events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_destroyclonedevent) | Destroys a cloned event pointer.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_pointerevent_setclonedeventlocalposition) | Sets the x-coordinate and y-coordinate of a cloned event relative to the upper left corner of the current component.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) | Sets the x-coordinate and y-coordinate of a specific contact point of a cloned event relative to the upper left corner of the current component.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)](#oh_arkui_pointerevent_setclonedeventactiontype) | Sets the action type of a cloned event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)](#oh_arkui_pointerevent_setclonedeventchangedfingerid) | Sets the touch point ID of a cloned pointer event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventfingeridbyindex) | Sets the touch point ID of a specific contact point of a cloned event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_postclonedevent) | Posts a cloned event to a specific node.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()](#oh_arkui_uiinputevent_getlateststatus) | Obtains the result code of the most recent API call related to an **ArkUI_UIInputEvent** object. This API is typically unnecessary for normal operations, but can be used to verify ambiguous return values (for example, when **0.0** might be either a valid float result or an error). float x = OH_ArkUI_PointerEvent_GetX(event);if (ARKUI_ERROR_CODE_NO_ERROR != OH_Arkui_UIInputEvent_GetlatestStatus()) {// errorreturn;} The system automatically clears the previous status before each API call related to an **ArkUI_UIInputEvent** object, ensuring that this API always returns the latest execution status.                                                                                                                                                                                                                             |

## Enum Description

### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```

**Description**


Enumerates the UI input event types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_UIINPUTEVENT_TYPE_UNKNOWN = 0 | Unknown.|
| ARKUI_UIINPUTEVENT_TYPE_TOUCH = 1 | Touch event.|
| ARKUI_UIINPUTEVENT_TYPE_AXIS = 2 | Axis event.|
| ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3 | Mouse event.|
| ARKUI_UIINPUTEVENT_TYPE_KEY = 4 | Key event.<br>**Since**: 20|

### anonymous1

```
enum anonymous1
```

**Description**


Enumerates the action codes of the input event.

**Since**: 12

| Value| Description|
| -- | -- |
| UI_TOUCH_EVENT_ACTION_CANCEL = 0 | Cancellation of touch.|
| UI_TOUCH_EVENT_ACTION_DOWN = 1 | Pressing of touch.|
| UI_TOUCH_EVENT_ACTION_MOVE = 2 | Moving of touch.|
| UI_TOUCH_EVENT_ACTION_UP = 3 | Lifting of touch.|

### anonymous2

```
enum anonymous2
```

**Description**


Enumerates the tool types of the input event.

**Since**: 12

| Value| Description|
| -- | -- |
| UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0 | Unknown tool type.|
| UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1 | Finger.|
| UI_INPUT_EVENT_TOOL_TYPE_PEN = 2 | Stylus.|
| UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3 | Mouse.|
| UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4 | Touchpad.|
| UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5 | Joystick.|

### anonymous3

```
enum anonymous3
```

**Description**


Enumerates the source types of the input event.

**Since**: 12

| Value| Description|
| -- | -- |
| UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0 | Unknown source type.|
| UI_INPUT_EVENT_SOURCE_TYPE_MOUSE = 1 | Mouse.|
| UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN = 2 | Touchscreen.|

### HitTestMode

```
enum HitTestMode
```

**Description**


Enumerates the hit test modes.

**Since**: 12

| Value| Description|
| -- | -- |
| HTM_DEFAULT = 0 | Default hit test mode. The node itself and its child nodes respond to the hit test, but block the hit test of sibling nodes. It does not affect the hit test of ancestor nodes.|
| HTM_BLOCK | The node itself responds to the hit test and blocks the hit test of child nodes, sibling nodes, and ancestor nodes.|
| HTM_TRANSPARENT | Both the node itself and its child nodes respond to the hit test and do not block the hit test of sibling nodes and ancestor nodes.|
| HTM_NONE | The node itself does not respond to the hit test and does not block the hit test of child nodes, sibling nodes, and ancestor nodes.|
| HTM_BLOCK_HIERARCHY | The node itself and its child nodes respond to the hit test, preventing all sibling nodes and parent nodes with lower priority from participating in the hit test.<br>**Since**: 20|
| HTM_BLOCK_DESCENDANTS | The node itself does not respond to the hit test, and all its descendants (children, grandchildren, and more) also do not respond to the hit test. It does not affect the hit test of ancestor nodes.<br>**Since**: 20|

### anonymous4

```
enum anonymous4
```

**Description**


Enumerates the action codes of the mouse event.

**Since**: 12

| Value| Description|
| -- | -- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN = 0 | Unknown action.|
| UI_MOUSE_EVENT_ACTION_PRESS = 1 | The mouse button is pressed.|
| UI_MOUSE_EVENT_ACTION_RELEASE = 2 | The mouse button is released.|
| UI_MOUSE_EVENT_ACTION_MOVE = 3 | The mouse cursor moves.|
| UI_MOUSE_EVENT_ACTION_CANCEL = 13 | The mouse button action is canceled.<br>**Since**: 18|

### anonymous5

```
enum anonymous5
```

**Description**


Enumerates the button types of the mouse event.

**Since**: 12

| Value| Description|
| -- | -- |
| UI_MOUSE_EVENT_BUTTON_NONE = 0 | No button.|
| UI_MOUSE_EVENT_BUTTON_LEFT = 1 | Left button.|
| UI_MOUSE_EVENT_BUTTON_RIGHT = 2 | Right button.|
| UI_MOUSE_EVENT_BUTTON_MIDDLE = 3 | Middle button.|
| UI_MOUSE_EVENT_BUTTON_BACK = 4 | Back button on the left of the mouse.|
| UI_MOUSE_EVENT_BUTTON_FORWARD = 5 | Forward button on the left of the mouse.|

### ArkUI_ModifierKeyName

```
enum ArkUI_ModifierKeyName
```

**Description**


Enumerates the modifier keys.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_MODIFIER_KEY_CTRL = 1 << 0 | Ctrl. |
| ARKUI_MODIFIER_KEY_SHIFT = 1 << 1 | Shift. |
| ARKUI_MODIFIER_KEY_ALT = 1 << 2 | Alt. |
| ARKUI_MODIFIER_KEY_FN = 1 << 3 | Fn (for debugging purposes only; typically, the Fn key state is not reported)|

### anonymous6

```
enum anonymous6
```

**Description**


Enumerates the axis types for focus axis events.

**Since**: 15

| Value| Description|
| -- | -- |
| UI_FOCUS_AXIS_EVENT_ABS_X = 0 | Game controller x-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_Y = 1 | Game controller y-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_Z = 2 | Game controller z-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_RZ = 3 | Game controller rz-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_GAS = 4 | Game controller GAS-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_BRAKE = 5 | Game controller BRAKE-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_HAT0X = 6 | Game controller HAT0X-axis.|
| UI_FOCUS_AXIS_EVENT_ABS_HAT0Y = 7 | Game controller HAT0Y-axis.|

### ArkUI_InteractionHand

```
enum ArkUI_InteractionHand
```

**Description**


Defines whether the touch event is from the left or right hand.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_EVENT_HAND_NONE = 0 | Unknown.|
| ARKUI_EVENT_HAND_LEFT = 1 | Left hand.|
| ARKUI_EVENT_HAND_RIGHT = 2 | Right hand.|

### anonymous7

```
enum anonymous7
```

**Description**


Enumerates the action types for axis events.

**Since**: 15

| Value| Description|
| -- | -- |
| UI_AXIS_EVENT_ACTION_NONE = 0 | The axis event is abnormal.|
| UI_AXIS_EVENT_ACTION_BEGIN = 1 | The axis event begins.|
| UI_AXIS_EVENT_ACTION_UPDATE = 2 | The axis event is updated.|
| UI_AXIS_EVENT_ACTION_END = 3 | The axis event ends.|
| UI_AXIS_EVENT_ACTION_CANCEL = 4 | The axis event is canceled.|


## Function Description

### OH_ArkUI_UIInputEvent_GetType()

```
int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the type of a UI input event. Before accessing an **ArkUI_UIInputEvent** pointer, use this API to determine the type of the input event. This API returns a value from the [ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type) enum. It helps ensure compatibility with subsequent accessors. For example, if the event is a touch event, which is directional, you can use OH_ArkUI_UIInputEvent_GetXXX or OH_ArkUI_PointerEvent_GetXXX for access. Using OH_ArkUI_KeyEvent_GetXXX to access the event may produce undefined behavior. For unsupported event types, this API returns the default value **0**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Type of the UI input event. Returns **0** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetAction()

```
int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the action type of an input event. The action type defines the phase of a basic event (for example, start or end) and characterizes its behavior, such as touch down or touch up. Action types are specific to the event category: [UI_TOUCH_EVENT_ACTION_XXX](#anonymous1) for touch events and [UI_MOUSE_EVENT_ACTION_XXX](#anonymous4) for mouse events. For axis events, use [OH_ArkUI_AxisEvent_GetAxisAction](#oh_arkui_axisevent_getaxisaction) to obtain the action type, which returns [UI_AXIS_EVENT_ACTION_XXX](#anonymous7). For key events, use [OH_ArkUI_KeyEvent_GetType](./capi-native-key-event-h.md#oh_arkui_keyevent_gettype) instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Action type of the UI input event. Returns **-1** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetSourceType()

```
int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the source type of a UI input event. The source represents the physical device, such as a touchscreen or mouse device, that generates the event. It is defined by the UI_INPUT_EVENT_SOURCE_TYPE_XXX enum. This is different from the input tool, which is the device used to interact with the source, for example, a finger or stylus. However, in certain cases, the input source and the input tool can be the same. For example, a mouse device acts as both the source and tool for click events. For key events, obtaining the source type is not supported, and in such cases, the API will return an **unknown** value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Source type of the UI input event.|

### OH_ArkUI_UIInputEvent_GetToolType()

```
int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the tool type of a UI input event. The input tool is the device used to interact with the input source, such as a finger or stylus. These tools themselves do not generate events but can drive the input source device to continuously generate events. The returned type is defined by the enumerated value of UI_INPUT_EVENT_TOOL_TYPE_XXX. For key events, obtaining the tool type is not supported, and in such cases, the API will return an **unknown** value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Tool type of the UI input event.|

### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the time when a specified UI input event occurs. The unit is ns.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int64_t | Time when the UI input event occurs. Returns **0** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the number of contact points from a pointer event (such as a touch, mouse, or axis event). Pointer events are typically events that carry position information, such as touch events, where the location of the event can be determined. Non-pointer events, such as key events, do not have position information and do not involve contact points, so this API is not applicable to key events. For touch events, this API returns the number of active touch points, for example, fingers on the screen. For mouse and axis events, this API always returns **1**, as they are single-pointer interactions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Number of contact points for the current pointer event.|

### OH_ArkUI_PointerEvent_GetPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the unique ID of a contact point from a pointer event (such as a touch, mouse, or axis event). The ID distinguishes between multiple contact points from the same input device. The return value itself does not have any other meaning beyond identifying the contact point.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Unique ID of the specified contact point.|

### OH_ArkUI_PointerEvent_GetChangedPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)
```

**Description**


Obtains the ID of the touch pointer that triggers the current touch event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t* pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetX()

```
float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetXByIndex()

```
float OH_ArkUI_PointerEvent_GetXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetY()

```
float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetYByIndex()

```
float OH_ArkUI_PointerEvent_GetYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetWindowX()

```
float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-coordinate relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetWindowXByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetWindowY()

```
float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetWindowYByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetDisplayX()

```
float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-coordinate relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the x-coordinate of a specific contact point relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetDisplayY()

```
float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-coordinate relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the y-coordinate of a specific contact point relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event). For mouse and axis events, this API returns the default value of **0.0f** if the given index is greater than 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetGlobalDisplayX()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the global display, in px. Returns **0** if any parameter error occurs (for example, if the event does not contain position information).|

### OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the x-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.

**Since**: 20


**Parameters**

| Name| Description                                                                                                                 |
| -- |---------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.                                                                                                   |
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list. Valid value range: [0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) – 1]|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the global display, in px. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetGlobalDisplayY()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the global display, in px. Returns **0** if any parameter error occurs (for example, if the event does not contain position information).|

### OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the y-coordinate relative to the global display from a pointer event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.

**Since**: 20


**Parameters**

| Name| Description                                                                                 |
| -- |-------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.                                                                   |
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list. Valid value range: [0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) – 1]|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the global display, in px. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetPressure()

```
float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the pressure applied to the touchscreen from a pointer event (for example, a touch event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Pressure applied to the touchscreen. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetTiltX()

```
float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the tilt angle relative to the YZ plane from a pointer event. The value range is [-90, 90], where positive values indicate a rightward tilt. This API is applicable only to stylus-based touch events from devices that support tilt angle reporting.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Angle relative to the YZ plane.|

### OH_ArkUI_PointerEvent_GetTiltY()

```
float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the tilt angle relative to the XZ plane from a pointer event. The value range is [-90, 90], where positive values indicate a rightward tilt. This API is applicable only to stylus-based touch events from devices that support tilt angle reporting.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Angle relative to the XZ plane.|

### OH_ArkUI_PointerEvent_GetRollAngle()

```
int32_t OH_ArkUI_PointerEvent_GetRollAngle(const ArkUI_UIInputEvent* event, double* rollAngle)
```

**Description**


Obtains the rotation angle of the stylus around the z-axis from a UI input event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the current UI input event.|
| double* rollAngle | Rotation angle of the stylus around the z-axis, in deg.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the width of the contact area for a pointer event. This API is applicable only to finger-based touch events, and the return value typically represents the radius of a circular touch area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Width of the touch area, in px.|

### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the height of the contact area for a pointer event. This API is applicable only to finger-based touch events, and the return value typically represents the radius of a circular touch area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| float | Height of the touch area, in px.|

### OH_ArkUI_PointerEvent_GetInteractionHand()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)
```

**Description**


Checks whether an event is triggered by a left-hand or right-hand tap. This API is only effective on some touch devices. The value is not available immediately upon press. Until the system infers the result, this API will return **NONE**. Do not rely on the return value for critical functionality.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) *event | Pointer to the UI input event.|
| [ArkUI_InteractionHand](capi-ui-input-event-h.md#arkui_interactionhand) *hand | Whether the touch point is from the left or right hand.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetInteractionHandByIndex()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)
```

**Description**


Checks whether an event is triggered by a left-hand or right-hand tap. This API is only effective on some touch devices. The value is not available immediately upon press. Until the system infers the result, this API will return **NONE**. Do not rely on the return value for critical functionality.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) *event | Pointer to the UI input event.|
| int32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| [ArkUI_InteractionHand](capi-ui-input-event-h.md#arkui_interactionhand) *hand | Whether the touch point is from the left or right hand.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistorySize()

```
uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the number of historical events from a pointer event (such as a touch event). Historical events are the raw events that occur between the current event and the previous event. This API is applicable only to move events.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Number of historical events.|

### OH_ArkUI_PointerEvent_GetHistoryEventTime()

```
int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**Description**


Obtains the occurrence time of a historical event from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| int64_t | Time when the UI input event occurs, in ns. Returns **0** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**Description**


Obtains the number of touch points in a specific historical event from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Number of touch points in the specified historical event.|

### OH_ArkUI_PointerEvent_GetHistoryPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the unique ID of a contact point from a historical event of a pointer event (such as a touch event). The ID distinguishes between multiple contact points from the same input device. The return value itself does not have any other meaning beyond identifying the contact point.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | ID of the corresponding touch point in the specified historical event.|

### OH_ArkUI_PointerEvent_GetHistoryX()

```
float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryY()

```
float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current component, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryWindowX()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryWindowY()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current application window, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the x-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a pointer event (such as a touch, mouse, or axis event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the upper left corner of the current screen, in px. Returns **0.0f** if a parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the x-coordinate relative to the global display for a specific touch point from historical events, based on the given pointer index and history index of an input event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.

**Since**: 20


**Parameters**

| Name| Description                                                                                                                  |
| -- |----------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.                                                                                                    |
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list. Valid value range: [0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) – 1]|
| uint32_t historyIndex | Historical value to be returned. The value must be less than [OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize).|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate relative to the global display, in px. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the y-coordinate relative to the global display for a specific touch point from historical events, based on the given pointer index and history index of an input event (such as a touch, mouse, or axis event). Position information can only be obtained from UI input events. For mouse and axis events, if the provided **pointerIndex** is greater than 0, this API always returns the default value **0.0f**.

**Since**: 20


**Parameters**

| Name| Description                                                                                                                  |
| -- |----------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.                                                                                                    |
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list. Valid value range: [0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) – 1] |
| uint32_t historyIndex | Historical value to be returned. The value must be less than [OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize).|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate relative to the global display. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryPressure()

```
float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the pressure applied to the touchscreen in a specific historical event from a pointer event (for example, a touch event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Pressure applied to the touchscreen. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetHistoryTiltX()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the angle of a specific historical event relative to the YZ plane from a pointer event (such as a touch event). The value range is [–90, 90], in deg. A positive value indicates a rightward tilt.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Angle relative to the YZ plane.|

### OH_ArkUI_PointerEvent_GetHistoryTiltY()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the angle relative to the XZ plane in a historical event from a pointer event (for example, a touch event). The value range is [-90, 90], in deg. A positive value indicates a downward tilt.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Angle relative to the XZ plane.|

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the width of the touch area in a specific historical event from a pointer event (for example, a touch event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Width of the touch area, in px.|

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**Description**


Obtains the height of the touch area in a specific historical event from a pointer event (for example, a touch event).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|
| uint32_t historyIndex | Index of the target historical event.|

**Return value**

| Type| Description|
| -- | -- |
| float | Height of the touch area, in px.|

### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```
double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the value of the vertical scroll axis for this axis event. This value is typically generated by mouse wheel scrolling or two-finger vertical swiping on a touchpad. If the value is generated by mouse wheel scrolling: 1. The reported value is in degrees and represents the incremental angle of a single scroll, not the total scroll amount. 2. The reported value includes the user's scroll step configuration (see [OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)). 3. The sign of the value indicates the direction: positive for backward scrolling and negative for forward scrolling. If the value is generated by two-finger vertical swiping on a touchpad: 1. The reported value is in px and represents the incremental scroll amount, not the total scroll amount. 2. The reported value does not include the user's scroll step configuration [OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep). 3. The sign of the value indicates the direction: positive for swiping up and negative for swiping down. 4. The direction is affected by the system settings for natural scrolling. Under normal circumstances, vertical scroll axis events only drive vertical swipe gestures. However, if the mouse pointer is over a scrollable area where the scrollable directions are consistent, the vertical scroll axis event can drive the swipe gestures in this scrollable area, even if they are defined as horizontal.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| double | Value of the vertical scroll axis of the current axis event. Returns **0.0** if any parameter error occurs.|

### OH_ArkUI_AxisEvent_GetHorizontalAxisValue()

```
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the value of the horizontal scroll axis for this axis event. This value is generated by two-finger horizontal swiping on a touchpad. Note: 1. The reported value is in px and represents the incremental scroll amount, not the total scroll amount. 2. The reported value does not include the user's scroll step configuration [OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep). 3. The sign of the value indicates the direction: positive for swiping left and negative for swiping right. 4. The direction is affected by the system settings for natural scrolling.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| double | Value of the horizontal scroll axis of the current axis event. Returns **0.0** if any parameter error occurs.|

### OH_ArkUI_AxisEvent_GetPinchAxisScaleValue()

```
double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the scale value of the pinch axis for this axis event. This value is generated by a two-finger pinch gesture on a touchpad. The reported scale value is relative to the initial state when the system first detects the pinch gesture, with an initial scale value of 1.0. During the pinch operation, the scale value decreases from 1.0 towards 0.0 when the user pinches inward and increases from 1.0 when the user spreads fingers outward.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| double | Scale value of the pinch axis of the current axis event. Returns **0.0** if any parameter error occurs.|

### OH_ArkUI_AxisEvent_GetAxisAction()

```
int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the action type of this axis event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Action type of the current axis event.|

### OH_ArkUI_PointerEvent_SetInterceptHitTestMode()

```
int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)
```

**Description**


Sets how the component behaves during hit testing. This API only applies to scenarios raw input events are received, such as when **NODE_ON_TOUCH** is used for touch event handling. It cannot be used with **ArkUI_UIInputEvent** objects obtained from gesture events through [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| [HitTestMode](capi-ui-input-event-h.md#hittestmode) mode | Hit test mode. The parameter type is [HitTestMode](capi-ui-input-event-h.md#hittestmode).|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_ArkUI_MouseEvent_GetMouseButton()

```
int32_t OH_ArkUI_MouseEvent_GetMouseButton(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the button type of a mouse event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Mouse button type. The value **1** indicates the left button, **2** indicates the right button, **3** indicates the middle button, **4** indicates the back button, and **5** indicates the forward button.|

### OH_ArkUI_MouseEvent_GetMouseAction()

```
int32_t OH_ArkUI_MouseEvent_GetMouseAction(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the action type of a mouse event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Mouse action type. The value **1** indicates that the mouse button is pressed, **2** indicates that the mouse button is released, and **3** indicates that the mouse cursor moves.|

### OH_ArkUI_PointerEvent_SetStopPropagation()

```
int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**Description**


Sets whether to stop event propagation. This API only applies to scenarios raw input events are received, such as when **NODE_ON_TOUCH** is used for touch event handling, and does not apply to axis events. It cannot be used with **ArkUI_UIInputEvent** objects obtained from gesture events through [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| bool stopPropagation | Whether to stop event propagation. The value **true** means to stop event propagation, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code. Returns **0** if the operation is successful; returns **401** if the operation fails, possibly because a parameter error, for example, null pointer for the **event** parameter, occurs.|

### OH_ArkUI_UIInputEvent_GetDeviceId()

```
int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the ID of the input device that triggers a key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Device ID.|

### OH_ArkUI_UIInputEvent_GetPressedKeys()

```
int32_t OH_ArkUI_UIInputEvent_GetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t* length)
```

**Description**


Obtains all pressed keys. Currently, only key events are supported.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t* pressedKeyCodes | Array of all pressed keys. The caller is responsible for allocating the memory space to which the array points.|
| int32_t* length | Dual-purpose parameter: As input, it indicates the length of the provided **pressedKeyCodes** array; as output, it indicates the number of pressed keys.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-native-type-h.md#arkui_errorcode) if the memory is insufficient.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_FocusAxisEvent_GetAxisValue()

```
double OH_ArkUI_FocusAxisEvent_GetAxisValue(const ArkUI_UIInputEvent* event, int32_t axis)
```

**Description**


Obtains the axis value of a focus axis event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t axis | Axis type of the focus axis event.|

**Return value**

| Type| Description|
| -- | -- |
| double | Axis value of the focus axis event. Returns **0.0** if any parameter error occurs.|

### OH_ArkUI_FocusAxisEvent_SetStopPropagation()

```
int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**Description**


Sets whether to prevent a focus axis event from bubbling up.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| bool stopPropagation | Whether to stop event propagation. The value **true** means to stop event propagation, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)
```

**Description**


Obtains the modifier key states for a UI input event. This API outputs the state of all modifier keys at the time of the event through the **keys** parameter. You can determine which keys are pressed by performing bitwise operations with the modifier key types defined in [ArkUI_ModifierKeyName](capi-ui-input-event-h.md#arkui_modifierkeyname).

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| uint64_t* keys | Pointer to a variable where the current combination of pressed modifier keys will be returned. The application can use bitwise operations to determine the state of each modifier key.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AxisEvent_SetPropagation()

```
int32_t OH_ArkUI_AxisEvent_SetPropagation(const ArkUI_UIInputEvent* event, bool propagation)
```

**Description**


Sets whether to enable axis event propagation (bubbling). By default, axis events do not bubble and are only sent to the first component that can respond to axis events. You can enable axis event bubbling when an axis event is received to allow the event to be passed to the next ancestor component in the response chain that can handle axis events. This API cannot be used on axis events obtained from gesture events.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the UI input event.|
| bool propagation | Whether to enable event propagation. The value **true** means to enable event propagation, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AxisEvent_GetScrollStep()

```
int32_t OH_ArkUI_AxisEvent_GetScrollStep(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the scroll step coefficient for a wheel-based axis event. This API returns the user-configured scroll scale factor.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Scroll step configuration of the mouse wheel axis event.|

### OH_ArkUI_UIInputEvent_GetEventTargetWidth()

```
float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the width of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Width of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetEventTargetHeight()

```
float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the height of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Height of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetEventTargetPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-coordinate of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetEventTargetPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-coordinate of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the global x-coordinate of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Global x-coordinate of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the global y-coordinate of the component hit by an event.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Global y-coordinate of the component hit by the event. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_PointerEvent_GetPressedTimeByIndex()

```
int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**Description**


Obtains the press time of a specified touch point. This API is effective only for touch events.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| uint32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| int64_t | Press time of the specific touch point, in ns. Returns **0** if any parameter error occurs.|

### OH_ArkUI_MouseEvent_GetRawDeltaX()

```
float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported x-coordinates when the mouse pointer is near the screen edge.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-axis offset of the mouse pointer position relative to the position in the previously reported mouse event, in px. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_MouseEvent_GetRawDeltaY()

```
float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the y-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported y-coordinates when the mouse pointer is near the screen edge.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-axis offset of the mouse pointer position relative to the position in the previously reported mouse event, in px. Returns **0.0f** if any parameter error occurs.|

### OH_ArkUI_MouseEvent_GetPressedButtons()

```
int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)
```

**Description**


Obtains the pressed buttons from a mouse event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t* pressedButtons | Array of the pressed buttons. An int array must be created beforehand to store the pressed buttons.|
| int32_t* length | Total length of the array.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the given buffer size is insufficient.|

### OH_ArkUI_UIInputEvent_GetTargetDisplayId()

```
int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the ID of the screen where the UI input event occurs.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Screen ID. Returns **0** if any parameter error occurs.|

### OH_ArkUI_HoverEvent_IsHovered()

```
bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)
```

**Description**


Checks whether the cursor is hovering over this component.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the cursor is hovering over the current component.<br>        Returns **false** if the cursor is not hovering over the current component.|

### OH_ArkUI_PointerEvent_CreateClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```

**Description**


Creates a cloned event pointer based on an event pointer. This API is effective only for touch events.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)** clonedEvent | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PointerEvent_DestroyClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)
```

**Description**


Destroys a cloned event pointer.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**Description**


Sets the x-coordinate and y-coordinate of a cloned event relative to the upper left corner of the current component.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| float x | X-coordinate relative to the upper left corner of the current component, in px.|
| float y | Y-coordinate relative to the upper left corner of the current component, in px.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**Description**


Sets the x-coordinate and y-coordinate of a specific contact point of a cloned event relative to the upper left corner of the current component.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| float x | X-coordinate relative to the upper left corner of the current component, in px.|
| float y | Y-coordinate relative to the upper left corner of the current component, in px.|
| int32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_SetClonedEventActionType()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)
```

**Description**


Sets the action type of a cloned event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t actionType | Action type of the cloned event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)
```

**Description**


Sets the touch point ID of a cloned pointer event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t fingerId | ID of the touch point that triggers the event.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)
```

**Description**


Sets the touch point ID of a specific contact point of a cloned event.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| int32_t fingerId | Touch point ID of the specific contact point.|
| int32_t pointerIndex | Index of the target touch point in the multi-touch data list.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.|

### OH_ArkUI_PointerEvent_PostClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)
```

**Description**


Posts a cloned event to a specific node.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-native-type-h.md#arkui_errorcode) if the input event pointer is not a cloned event pointer.<br>         Returns [ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](capi-native-type-h.md#arkui_errorcode) if the component status is abnormal.<br>         Returns [ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT](capi-native-type-h.md#arkui_errorcode) if no component is hit to respond to the event.|

### OH_ArkUI_UIInputEvent_GetLatestStatus()

```
ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()
```

**Description**


Obtains the result code of the most recent API call related to an **ArkUI_UIInputEvent** object. This API is typically unnecessary for normal operations, but can be used to verify ambiguous return values (for example, when **0.0** might be either a valid float result or an error). float x = OH_ArkUI_PointerEvent_GetX(event);if (ARKUI_ERROR_CODE_NO_ERROR != OH_Arkui_UIInputEvent_GetlatestStatus()) {// errorreturn;} The system automatically clears the previous status before each API call related to an **ArkUI_UIInputEvent** object, ensuring that this API always returns the latest execution status.

**Since**: 20

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code of the most recent API call related to the **ArkUI_UIInputEvent** object.|
