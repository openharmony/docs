# Binding Basic Input Events

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e2e68a0f64c4bfd46ed17299bdcf92e994092ae8 translatedAt=2026-08-05T01:27:46.469Z pushedAt=2026-08-05T06:42:30.464Z -->

NDK APIs provide the capability of listening to and processing basic input events. You can bind click events ([NODE_ON_CLICK_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), touch events ([NODE_TOUCH_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), mouse events ([NODE_ON_MOUSE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), hover events ([NODE_ON_HOVER_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), axis events ([NODE_ON_AXIS](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), and key events ([NODE_ON_KEY_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)), and then obtain event details through the callback in the event receiver.

The following examples are based on [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md). For detals, see [Full Example](#full-example).

## Click Event

A click event is triggered when a user clicks a component. Information such as the click position, number of touch points, pointer ID, and pressure value can be obtained. The following handler can be bound to a node.

<!-- @[handle_click_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process a click event.
void HandleClickEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto pos = GetPointerPosition(inputEvent);
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
    auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
    auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);

    // Obtain the pointer position information by index (multi-touch supported).
    auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
    auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
    auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
    auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
    auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
    auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Click: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
        "windowX=%{public}f, windowY=%{public}f, xByIndex=%{public}f, yByIndex=%{public}f, "
        "displayXByIndex=%{public}f, displayYByIndex=%{public}f, windowXByIndex=%{public}f, "
        "windowYByIndex=%{public}f, pointerCount=%{public}d, pointerId=%{public}d, "
        "pressure=%{public}f, action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
        eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
        xByIndex, yByIndex, displayXByIndex, displayYByIndex, windowXByIndex, windowYByIndex,
        pointerCount, pointerId, pressure, baseInfo.action, baseInfo.eventTime,
        baseInfo.sourceType, baseInfo.type);
}
```

Starting from API version 18, the [NODE_ON_CLICK_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) enumeration is added. The node itself can register a **NODE_ON_CLICK_EVENT** event listener to respond to the handler described above.

<!-- @[register_click_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, this);
```

## Touch Event

A touch event is triggered when a user touches the screen. In addition to the click event information, the width and height of the touch area can also be obtained. The following handler can be bound to a node.

<!-- @[handle_touch_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process a touch event.
void HandleTouchEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto pos = GetPointerPosition(inputEvent);
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
    auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
    auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);
    auto touchAreaWidth = OH_ArkUI_PointerEvent_GetTouchAreaWidth(inputEvent, 0);
    auto touchAreaHeight = OH_ArkUI_PointerEvent_GetTouchAreaHeight(inputEvent, 0);

    // Obtain the pointer position information by index (multi-touch supported).
    auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
    auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
    auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
    auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
    auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
    auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Touch: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
        "windowX=%{public}f, windowY=%{public}f, xByIndex=%{public}f, yByIndex=%{public}f, "
        "displayXByIndex=%{public}f, displayYByIndex=%{public}f, windowXByIndex=%{public}f, "
        "windowYByIndex=%{public}f, pointerCount=%{public}d, pointerId=%{public}d, "
        "pressure=%{public}f, touchAreaWidth=%{public}f, touchAreaHeight=%{public}f, "
        "action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
        eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
        xByIndex, yByIndex, displayXByIndex, displayYByIndex, windowXByIndex, windowYByIndex,
        pointerCount, pointerId, pressure, touchAreaWidth, touchAreaHeight, baseInfo.action,
        baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
}
```

The node itself must register a [NODE_TOUCH_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event listener to respond to the handler described above.

<!-- @[register_touch_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, this);
```

## Mouse Event

A mouse event is triggered when a mouse operation is performed. Information such as the mouse button type, mouse action type, and scroll wheel delta can be obtained. The following handler can be bound to a node.

<!-- @[handle_mouse_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process a mouse event.
void HandleMouseEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto pos = GetPointerPosition(inputEvent);
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto button = OH_ArkUI_MouseEvent_GetMouseButton(inputEvent);
    auto mouseAction = OH_ArkUI_MouseEvent_GetMouseAction(inputEvent);
    auto rawDeltaX = OH_ArkUI_MouseEvent_GetRawDeltaX(inputEvent);
    auto rawDeltaY = OH_ArkUI_MouseEvent_GetRawDeltaY(inputEvent);
    auto buttonCount = GetPressedButtonsCount(inputEvent);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Mouse: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
        "windowX=%{public}f, windowY=%{public}f, button=%{public}d, mouseAction=%{public}d, "
        "pressedButtonsCount=%{public}d, rawDeltaX=%{public}f, rawDeltaY=%{public}f, "
        "action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
        eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
        button, mouseAction, buttonCount, rawDeltaX, rawDeltaY, baseInfo.action,
        baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
}
```

The node itself must register a [NODE_ON_MOUSE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event listener to respond to the handler described above.

<!-- @[register_mouse_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
nativeModule_->registerNodeEvent(handle_, NODE_ON_MOUSE, 0, this);
```

## Hover Event

A hover event is triggered when the mouse pointer moves over or away from a component. The hover state can be obtained. The following handler can be bound to a node.

<!-- @[handle_hover_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process a hover event.
void HandleHoverEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto pos = GetPointerPosition(inputEvent);
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto isHovered = OH_ArkUI_HoverEvent_IsHovered(inputEvent);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Hover: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
        "windowX=%{public}f, windowY=%{public}f, isHovered=%{public}d, action=%{public}d, "
        "eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
        eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
        isHovered, baseInfo.action, baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
}
```

Starting from API version 17, the [NODE_ON_HOVER_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) enumeration is added. The node itself can register a **NODE_ON_HOVER_EVENT** event listener to respond to the handler described above.

<!-- @[register_hover_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
nativeModule_->registerNodeEvent(handle_, NODE_ON_HOVER_EVENT, 0, this);
```

## Axis Event

An axis event is triggered by devices such as the mouse scroll wheel and game analog stick. Information such as the axis action type, vertical axis value, horizontal axis value, pinch scale, and scroll step can be obtained. The following handler can be bound to a node.

<!-- @[handle_axis_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process the axis event.
void HandleAxisEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto axisAction = OH_ArkUI_AxisEvent_GetAxisAction(inputEvent);
    auto verticalAxis = OH_ArkUI_AxisEvent_GetVerticalAxisValue(inputEvent);
    auto horizontalAxis = OH_ArkUI_AxisEvent_GetHorizontalAxisValue(inputEvent);
    auto pinchAxisScale = OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(inputEvent);
    auto scrollStep = OH_ArkUI_AxisEvent_GetScrollStep(inputEvent);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Axis: axisAction=%{public}d, verticalAxis=%{public}f, horizontalAxis=%{public}f, "
        "pinchAxisScale=%{public}f, scrollStep=%{public}d, action=%{public}d, "
        "eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
        eventName_.c_str(), axisAction, verticalAxis, horizontalAxis, pinchAxisScale, scrollStep,
        baseInfo.action, baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
}
```

Starting from API version 17, the [NODE_ON_AXIS](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) enumeration is added. The node itself can register a **NODE_ON_AXIS** event listener to respond to the handler described above.

<!-- @[register_axis_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
nativeModule_->registerNodeEvent(handle_, NODE_ON_AXIS, 0, this);
```

## Key Event

A key event is triggered when a user presses or releases a key on the keyboard. Information such as the key type, key action, pressed key, modifier key status, and device ID can be obtained. A component must first gain focus before it can respond to key events. The following handler can be bound to a node.

<!-- @[handle_key_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Process a key event.
void HandleKeyEvent(ArkUI_UIInputEvent *inputEvent)
{
    auto type = OH_ArkUI_KeyEvent_GetType(inputEvent);
    auto baseInfo = GetBaseEventInfo(inputEvent);
    auto deviceId = OH_ArkUI_UIInputEvent_GetDeviceId(inputEvent);
    auto keyInfo = GetKeyInfo(inputEvent);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
        "[%{public}s] Key: type=%{public}d, action=%{public}d, pressedKey=%{public}d, "
        "modifierKeys=%{public}llu, deviceId=%{public}d, eventTime=%{public}lld, sourceType=%{public}d",
        eventName_.c_str(), type, baseInfo.action, keyInfo.pressedKey, keyInfo.modifierKeys,
        deviceId, baseInfo.eventTime, baseInfo.sourceType);
}
```

Set the node to be focusable, bind a click event to it, and request focus upon a click. In addition, the node itself must register a [NODE_ON_KEY_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event listener to respond to the handler described above.

<!-- @[register_key_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// Set as focusable to receive key events.
ArkUI_NumberValue focusable[] = {1};
ArkUI_AttributeItem focusableItem = {focusable, 1};
nativeModule_->setAttribute(handle_, NODE_FOCUSABLE, &focusableItem);

// Register the click event and request focus on click.
nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, this);

// Register the key event.
nativeModule_->registerNodeEvent(handle_, NODE_ON_KEY_EVENT, 0, this);
```

## Full Example

1. Define the data structure of a basic input event.

   <!-- @[Cpp_InputEventTypes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/InputEventTypes.h) -->

   ``` C
   // InputEventTypes.h
   // Type definitions and helper functions related to input events.
   
   #ifndef MYAPPLICATION_INPUTEVENTTYPES_H
   #define MYAPPLICATION_INPUTEVENTTYPES_H
   
   #include <cstdint>
   
   namespace NativeModule {
   
   // Basic event information structure.
   struct BaseEventInfo {
       int32_t action;
       int64_t eventTime;
       int32_t sourceType;
       int32_t type;
   };
   
   // Pointer coordinate information structure.
   struct PointerPosition {
       float x;
       float y;
       float displayX;
       float displayY;
       float windowX;
       float windowY;
   };
   
   // Key information structure.
   struct KeyInfo {
       int32_t pressedKey;
       uint64_t modifierKeys;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_INPUTEVENTTYPES_H
   ```

2. Register various basic input events and implement listeners for the corresponding events.

   <!-- @[Cpp_InputEventListExample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkBindInputEvent/entry/src/main/cpp/NormalTextListExample.h) -->

   ``` C
   // NormalTextListExample.h
   // Input event example, demonstrating the binding and handling of basic input events.
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include "InputEventTypes.h"
   #include <arkui/native_key_event.h>
   #include <hilog/log.h>
   #include <string>
   
   namespace NativeModule {
   
   // Define constants.
   const unsigned int LOG_PRINT_DOMAIN = 0xF811;
   const unsigned int ITEM_HEIGHT = 100;
   const unsigned int FONT_SIZE = 16;
   
   // Custom list item class, which is used to process different types of input events.
   class InputEventListItem : public ArkUIListItemNode {
   public:
       enum EventType {
           CLICK_EVENT,
           TOUCH_EVENT,
           MOUSE_EVENT,
           HOVER_EVENT,
           AXIS_EVENT,
           KEY_EVENT
       };
   
       InputEventListItem(const std::string& eventName, uint32_t bgColor, EventType eventType)
           : eventName_(eventName), eventType_(eventType)
       {
           SetPercentWidth(1);
           SetHeight(ITEM_HEIGHT);
           SetBackgroundColor(bgColor);
   
           auto textNode = std::make_shared<ArkUITextNode>();
           textNode->SetTextContent(eventName);
           textNode->SetFontSize(FONT_SIZE);
           textNode->SetFontColor(0xFFFFFFFF);
           textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
           textNode->SetPercentWidth(1);
           AddChild(textNode);
   
           // Register an event listener.
           RegisterEventReceiver();
       }
   
   private:
       // Register an event receiver and callback.
       void RegisterEventReceiver()
       {
           if (!handle_) {
               return;
           }
           nativeModule_->addNodeEventReceiver(handle_, [](ArkUI_NodeEvent *event) {
               auto *item = static_cast<InputEventListItem*>(OH_ArkUI_NodeEvent_GetUserData(event));
               if (item) {
                   item->HandleEvent(event);
               }
           });
           RegisterEventByType();
       }
   
       // Register a specific event based on the event type.
       void RegisterEventByType()
       {
           switch (eventType_) {
               case CLICK_EVENT:
                   RegisterClickEvent();
                   break;
               case TOUCH_EVENT:
                   RegisterTouchEvent();
                   break;
               case MOUSE_EVENT:
                   RegisterMouseEvent();
                   break;
               case HOVER_EVENT:
                   RegisterHoverEvent();
                   break;
               case AXIS_EVENT:
                   RegisterAxisEvent();
                   break;
               case KEY_EVENT:
                   RegisterKeyEvent();
                   break;
           }
       }
   
       // Register a click event.
       void RegisterClickEvent()
       {
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, this);
       }
   
       // Register a touch event.
       void RegisterTouchEvent()
       {
           nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, this);
       }
   
       // Register a mouse event.
       void RegisterMouseEvent()
       {
           // Mouse event (click, move, release, etc.)
           nativeModule_->registerNodeEvent(handle_, NODE_ON_MOUSE, 0, this);
       }
   
       // Register a hover event.
       void RegisterHoverEvent()
       {
           nativeModule_->registerNodeEvent(handle_, NODE_ON_HOVER_EVENT, 0, this);
       }
   
       // Register an axis event.
       void RegisterAxisEvent()
       {
           // Axis event: triggered when the mouse scroll wheel is scrolled.
           nativeModule_->registerNodeEvent(handle_, NODE_ON_AXIS, 0, this);
       }
   
       // Register a key event.
       void RegisterKeyEvent()
       {
           // Set the component to be focusable to receive key events.
           ArkUI_NumberValue focusable[] = {1};
           ArkUI_AttributeItem focusableItem = {focusable, 1};
           nativeModule_->setAttribute(handle_, NODE_FOCUSABLE, &focusableItem);
   
           // Register a click event to request focus when the component is clicked.
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, this);
   
           // Register a key event.
           nativeModule_->registerNodeEvent(handle_, NODE_ON_KEY_EVENT, 0, this);
       }
   
       // Distribute and process the event.
       void HandleEvent(ArkUI_NodeEvent *event)
       {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
           auto uiType = OH_ArkUI_UIInputEvent_GetType(inputEvent);
   
           DispatchEvent(eventType, uiType, inputEvent);
       }
   
       // Distribute the event to the specific processing function based on the event type.
       void DispatchEvent(int32_t eventType, int32_t uiType, ArkUI_UIInputEvent *inputEvent)
       {
           switch (eventType_) {
               case CLICK_EVENT:
                   if (eventType == NODE_ON_CLICK_EVENT) {
                       HandleClickEvent(inputEvent);
                   }
                   break;
               case TOUCH_EVENT:
                   if (eventType == NODE_TOUCH_EVENT && uiType == ARKUI_UIINPUTEVENT_TYPE_TOUCH) {
                       HandleTouchEvent(inputEvent);
                   }
                   break;
               case MOUSE_EVENT:
                   // Mouse event (click, move, release, etc.)
                   if (eventType == NODE_ON_MOUSE && uiType == ARKUI_UIINPUTEVENT_TYPE_MOUSE) {
                       HandleMouseEvent(inputEvent);
                   }
                   break;
               case HOVER_EVENT:
                   if (eventType == NODE_ON_HOVER_EVENT) {
                       HandleHoverEvent(inputEvent);
                   }
                   break;
               case AXIS_EVENT:
                   // Triggered when the mouse scroll wheel is scrolled or a touchpad gesture is performed.
                   if (eventType == NODE_ON_AXIS && uiType == ARKUI_UIINPUTEVENT_TYPE_AXIS) {
                       HandleAxisEvent(inputEvent);
                   }
                   break;
               case KEY_EVENT:
                   if (eventType == NODE_ON_CLICK_EVENT) {
                       // Request focus when the component is clicked.
                       ArkUI_NumberValue requestFocus[] = {1};
                       ArkUI_AttributeItem requestFocusItem = {requestFocus, 1};
                       nativeModule_->setAttribute(handle_, NODE_FOCUS_STATUS, &requestFocusItem);
   
                       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
                           "[%{public}s] Focus requested", eventName_.c_str());
                   } else if (eventType == NODE_ON_KEY_EVENT && uiType == ARKUI_UIINPUTEVENT_TYPE_KEY) {
                       // Process a key event.
                       HandleKeyEvent(inputEvent);
                   }
                   break;
           }
       }
   
       // Obtain the basic event information.
       BaseEventInfo GetBaseEventInfo(ArkUI_UIInputEvent *inputEvent)
       {
           BaseEventInfo info;
           info.action = OH_ArkUI_UIInputEvent_GetAction(inputEvent);
           info.eventTime = OH_ArkUI_UIInputEvent_GetEventTime(inputEvent);
           info.sourceType = OH_ArkUI_UIInputEvent_GetSourceType(inputEvent);
           info.type = OH_ArkUI_UIInputEvent_GetType(inputEvent);
           return info;
       }
   
       // Obtain the event position information.
       PointerPosition GetPointerPosition(ArkUI_UIInputEvent *inputEvent)
       {
           PointerPosition pos;
           pos.x = OH_ArkUI_PointerEvent_GetX(inputEvent);
           pos.y = OH_ArkUI_PointerEvent_GetY(inputEvent);
           pos.displayX = OH_ArkUI_PointerEvent_GetDisplayX(inputEvent);
           pos.displayY = OH_ArkUI_PointerEvent_GetDisplayY(inputEvent);
           pos.windowX = OH_ArkUI_PointerEvent_GetWindowX(inputEvent);
           pos.windowY = OH_ArkUI_PointerEvent_GetWindowY(inputEvent);
           return pos;
       }
   
       // Record the event position information.
       void LogPointerPosition(const char *eventName, const PointerPosition &pos)
       {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
               "windowX=%{public}f, windowY=%{public}f",
               eventName, pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY);
       }
   
       // Process a click event.
       void HandleClickEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto pos = GetPointerPosition(inputEvent);
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
           auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
           auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);
   
           // Obtain the pointer position information by index (multi-touch supported).
           auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
           auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
           auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
           auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
           auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
           auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Click: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
               "windowX=%{public}f, windowY=%{public}f, xByIndex=%{public}f, yByIndex=%{public}f, "
               "displayXByIndex=%{public}f, displayYByIndex=%{public}f, windowXByIndex=%{public}f, "
               "windowYByIndex=%{public}f, pointerCount=%{public}d, pointerId=%{public}d, "
               "pressure=%{public}f, action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
               eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
               xByIndex, yByIndex, displayXByIndex, displayYByIndex, windowXByIndex, windowYByIndex,
               pointerCount, pointerId, pressure, baseInfo.action, baseInfo.eventTime,
               baseInfo.sourceType, baseInfo.type);
       }
   
       // Process a touch event.
       void HandleTouchEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto pos = GetPointerPosition(inputEvent);
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
           auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
           auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);
           auto touchAreaWidth = OH_ArkUI_PointerEvent_GetTouchAreaWidth(inputEvent, 0);
           auto touchAreaHeight = OH_ArkUI_PointerEvent_GetTouchAreaHeight(inputEvent, 0);
   
           // Obtain the pointer position information by index (multi-touch supported).
           auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
           auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
           auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
           auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
           auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
           auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Touch: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
               "windowX=%{public}f, windowY=%{public}f, xByIndex=%{public}f, yByIndex=%{public}f, "
               "displayXByIndex=%{public}f, displayYByIndex=%{public}f, windowXByIndex=%{public}f, "
               "windowYByIndex=%{public}f, pointerCount=%{public}d, pointerId=%{public}d, "
               "pressure=%{public}f, touchAreaWidth=%{public}f, touchAreaHeight=%{public}f, "
               "action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
               eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
               xByIndex, yByIndex, displayXByIndex, displayYByIndex, windowXByIndex, windowYByIndex,
               pointerCount, pointerId, pressure, touchAreaWidth, touchAreaHeight, baseInfo.action,
               baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
       }
   
       // Process a mouse event.
       void HandleMouseEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto pos = GetPointerPosition(inputEvent);
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto button = OH_ArkUI_MouseEvent_GetMouseButton(inputEvent);
           auto mouseAction = OH_ArkUI_MouseEvent_GetMouseAction(inputEvent);
           auto rawDeltaX = OH_ArkUI_MouseEvent_GetRawDeltaX(inputEvent);
           auto rawDeltaY = OH_ArkUI_MouseEvent_GetRawDeltaY(inputEvent);
           auto buttonCount = GetPressedButtonsCount(inputEvent);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Mouse: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
               "windowX=%{public}f, windowY=%{public}f, button=%{public}d, mouseAction=%{public}d, "
               "pressedButtonsCount=%{public}d, rawDeltaX=%{public}f, rawDeltaY=%{public}f, "
               "action=%{public}d, eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
               eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
               button, mouseAction, buttonCount, rawDeltaX, rawDeltaY, baseInfo.action,
               baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
       }
   
       // Obtain the number of mouse buttons that are pressed.
       int32_t GetPressedButtonsCount(ArkUI_UIInputEvent *inputEvent)
       {
           int32_t pressedButtons[5] = {};
           int32_t length = 5;
           OH_ArkUI_MouseEvent_GetPressedButtons(inputEvent, pressedButtons, &length);
           return length;
       }
   
       // Process a hover event.
       void HandleHoverEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto pos = GetPointerPosition(inputEvent);
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto isHovered = OH_ArkUI_HoverEvent_IsHovered(inputEvent);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Hover: x=%{public}f, y=%{public}f, displayX=%{public}f, displayY=%{public}f, "
               "windowX=%{public}f, windowY=%{public}f, isHovered=%{public}d, action=%{public}d, "
               "eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
               eventName_.c_str(), pos.x, pos.y, pos.displayX, pos.displayY, pos.windowX, pos.windowY,
               isHovered, baseInfo.action, baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
       }
   
       // Process the axis event.
       void HandleAxisEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto axisAction = OH_ArkUI_AxisEvent_GetAxisAction(inputEvent);
           auto verticalAxis = OH_ArkUI_AxisEvent_GetVerticalAxisValue(inputEvent);
           auto horizontalAxis = OH_ArkUI_AxisEvent_GetHorizontalAxisValue(inputEvent);
           auto pinchAxisScale = OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(inputEvent);
           auto scrollStep = OH_ArkUI_AxisEvent_GetScrollStep(inputEvent);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Axis: axisAction=%{public}d, verticalAxis=%{public}f, horizontalAxis=%{public}f, "
               "pinchAxisScale=%{public}f, scrollStep=%{public}d, action=%{public}d, "
               "eventTime=%{public}lld, sourceType=%{public}d, type=%{public}d",
               eventName_.c_str(), axisAction, verticalAxis, horizontalAxis, pinchAxisScale, scrollStep,
               baseInfo.action, baseInfo.eventTime, baseInfo.sourceType, baseInfo.type);
       }
   
       // Process a key event.
       void HandleKeyEvent(ArkUI_UIInputEvent *inputEvent)
       {
           auto type = OH_ArkUI_KeyEvent_GetType(inputEvent);
           auto baseInfo = GetBaseEventInfo(inputEvent);
           auto deviceId = OH_ArkUI_UIInputEvent_GetDeviceId(inputEvent);
           auto keyInfo = GetKeyInfo(inputEvent);
   
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
               "[%{public}s] Key: type=%{public}d, action=%{public}d, pressedKey=%{public}d, "
               "modifierKeys=%{public}llu, deviceId=%{public}d, eventTime=%{public}lld, sourceType=%{public}d",
               eventName_.c_str(), type, baseInfo.action, keyInfo.pressedKey, keyInfo.modifierKeys,
               deviceId, baseInfo.eventTime, baseInfo.sourceType);
       }
   
       // Obtain key information.
       KeyInfo GetKeyInfo(ArkUI_UIInputEvent *inputEvent)
       {
           KeyInfo info;
           int32_t pressedKeys[10] = {};
           int32_t length = 10;
           OH_ArkUI_UIInputEvent_GetPressedKeys(inputEvent, pressedKeys, &length);
           info.pressedKey = length > 0 ? pressedKeys[0] : -1;
   
           uint64_t modifierKeys = 0;
           OH_ArkUI_UIInputEvent_GetModifierKeyStates(inputEvent, &modifierKeys);
           info.modifierKeys = modifierKeys;
   
           return info;
       }
   
       std::string eventName_;
       EventType eventType_;
   };
   
   // Create a list item.
   std::shared_ptr<InputEventListItem> CreateEventListItem(
       const std::string& name, uint32_t color, InputEventListItem::EventType type)
   {
       return std::make_shared<InputEventListItem>(name, color, type);
   }
   
   // Create a button for triggering key events.
   ArkUI_NodeHandle CreateKeyEventButton(const char* name, uint32_t bgColor)
   {
       auto* nodeAPI = NativeModule::NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
       ArkUI_NodeHandle buttonHandle = nodeAPI->createNode(ARKUI_NODE_BUTTON);
   
       // Set the button attributes.
       ArkUI_AttributeItem idItem = {.string = "keyEventButton"};
       nodeAPI->setAttribute(buttonHandle, NODE_ID, &idItem);
   
       ArkUI_NumberValue typeValue[] = {{.i32 = 0}};
       ArkUI_AttributeItem typeItem = {typeValue, 1};
       nodeAPI->setAttribute(buttonHandle, NODE_BUTTON_TYPE, &typeItem);
   
       ArkUI_NumberValue widthValue[] = {{.f32 = 1.0f}};
       ArkUI_AttributeItem widthItem = {widthValue, 1};
       nodeAPI->setAttribute(buttonHandle, NODE_WIDTH_PERCENT, &widthItem);
   
       ArkUI_NumberValue heightValue[] = {{.f32 = 100.0f}};
       ArkUI_AttributeItem heightItem = {heightValue, 1};
       nodeAPI->setAttribute(buttonHandle, NODE_HEIGHT, &heightItem);
   
       ArkUI_NumberValue bgValue[] = {{.u32 = bgColor}};
       ArkUI_AttributeItem bgItem = {bgValue, 1};
       nodeAPI->setAttribute(buttonHandle, NODE_BACKGROUND_COLOR, &bgItem);
   
       ArkUI_AttributeItem labelItem = {.string = name};
       nodeAPI->setAttribute(buttonHandle, NODE_BUTTON_LABEL, &labelItem);
   
       ArkUI_NumberValue focusable[] = {{.i32 = 1}};
       ArkUI_AttributeItem focusableItem = {focusable, 1};
       nodeAPI->setAttribute(buttonHandle, NODE_FOCUSABLE, &focusableItem);
   
       // Register events.
       nodeAPI->registerNodeEvent(buttonHandle, NODE_ON_CLICK_EVENT, 0, buttonHandle);
       nodeAPI->registerNodeEvent(buttonHandle, NODE_ON_KEY_EVENT, 0, buttonHandle);
   
       return buttonHandle;
   }
   
   // Handle the click event of a key.
   void HandleKeyEventButtonClick(ArkUI_NodeEvent *event)
   {
       ArkUI_NumberValue requestFocus[] = {{.i32 = 1}};
       ArkUI_AttributeItem requestFocusItem = {requestFocus, 1};
       auto* nativeModule = NativeModule::NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
       nativeModule->setAttribute(
           OH_ArkUI_NodeEvent_GetNodeHandle(event), NODE_FOCUS_STATUS, &requestFocusItem);
   
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
           "[Key Event Button] Focus requested via click");
   }
   
   // Handle the key event of a key.
   void HandleKeyEventButtonKey(ArkUI_NodeEvent *event)
   {
       auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
       auto type = OH_ArkUI_KeyEvent_GetType(inputEvent);
       auto action = OH_ArkUI_UIInputEvent_GetAction(inputEvent);
       auto deviceId = OH_ArkUI_UIInputEvent_GetDeviceId(inputEvent);
   
       int32_t pressedKeys[10] = {};
       int32_t length = 10;
       OH_ArkUI_UIInputEvent_GetPressedKeys(inputEvent, pressedKeys, &length);
       auto pressedKey = length > 0 ? pressedKeys[0] : -1;
   
       uint64_t modifierKeys = 0;
       OH_ArkUI_UIInputEvent_GetModifierKeyStates(inputEvent, &modifierKeys);
   
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[NdkBindInputEvent]",
           "[Key Event Button] Key: type=%{public}d, action=%{public}d, pressedKey=%{public}d, "
           "modifierKeys=%{public}llu, deviceId=%{public}d",
           type, action, pressedKey, modifierKeys, deviceId);
   }
   
   // Register the event receiver for a key.
   void RegisterKeyEventButtonReceiver(ArkUI_NodeHandle buttonHandle)
   {
       auto* nodeAPI = NativeModule::NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
       nodeAPI->addNodeEventReceiver(buttonHandle, [](ArkUI_NodeEvent *event) {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           auto uiType = OH_ArkUI_UIInputEvent_GetType(OH_ArkUI_NodeEvent_GetInputEvent(event));
   
           if (eventType == NODE_ON_CLICK_EVENT) {
               HandleKeyEventButtonClick(event);
           } else if (eventType == NODE_ON_KEY_EVENT && uiType == ARKUI_UIINPUTEVENT_TYPE_KEY) {
               HandleKeyEventButtonKey(event);
           }
       });
   }
   
   // Add all event items to the list.
   void AddEventListItems(std::shared_ptr<ArkUIListNode> list)
   {
       auto* nodeAPI = NativeModule::NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
   
       // Click event.
       list->AddChild(CreateEventListItem("Click Event - Tap to test", 0xFF1976D2,
           InputEventListItem::CLICK_EVENT));
       // Touch event.
       list->AddChild(CreateEventListItem("Touch Event - Touch to test", 0xFF9E9E9E,
           InputEventListItem::TOUCH_EVENT));
       // Mouse event.
       list->AddChild(CreateEventListItem("Mouse Event - Mouse over/click to test", 0xFF1976D2,
           InputEventListItem::MOUSE_EVENT));
       // Hover event.
       list->AddChild(CreateEventListItem("Hover Event - Hover to test", 0xFF9E9E9E,
           InputEventListItem::HOVER_EVENT));
       // Axis event.
       list->AddChild(CreateEventListItem("Axis Event - Use mouse wheel", 0xFF1976D2,
           InputEventListItem::AXIS_EVENT));
       // Key event.
       ArkUI_NodeHandle keyButton = CreateKeyEventButton("Key Event - Click to focus, then press keys", 0xFF9E9E9E);
       RegisterKeyEventButtonReceiver(keyButton);
       nodeAPI->addChild(list->GetHandle(), keyButton);
   }
   
   // Main function for creating an input event list.
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample()
   {
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       list->SetScrollBarState(true);
       // Add all event lists.
       AddEventListItems(list);
       return list;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   ```

   Because the log printing API [OH_LOG_Print](../reference/apis-performance-analysis-kit/capi-log-h.md#oh_log_print) is used, you need to add the reference to **libhilog_ndk.z.so** in the **CMakeLists.txt** file.

   ```text
   add_library(entry SHARED napi_init.cpp NativeEntry.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so libhilog_ndk.z.so)
   ```