# Event Listening Development (C/C++)

## Introduction

The multimodal module provides applications with the ability to listen for key and input events (mouse, touch, and axis events). Currently, event listening is available only for screen recording applications. For example, when a user starts screen recording, your application can listen for key, mouse, touch, and axis events of the device.

## Available APIs

The following table lists the APIs for event listening. For details, see [Input](../../reference/apis-input-kit/input.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback) |Creates a key event listener. |
| Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback) |Creates a mouse event listener. |
| Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback) |Creates a touch event listener. |
| Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback) |Creates a listener for all axis events. |
| Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback) |Creates a listener for the specified type of axis events. |
| Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback) |Removes a key event listener. |
| Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback) |Removes a mouse event listener. |
| Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback) |Removes a touch event listener. |
| Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback) |Removes a listener for all axis events. |
| Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback) |Removes a listener for the specified type of axis events. |

## How to Develop

### Linking a Dynamic Library

Before calling interception-related APIs, you need to link the related dynamic library. You can do this by editing the **CMakeList.txt** file as follows:

```txt
target_link_libraries(entry PUBLIC libohinput.so)
```

### Applying for Required Permissions

Declare the required permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md).

```json
"requestPermissions": [
    {
        "name": "ohos.permission.INTERCEPT_INPUT_EVENT"
    }
]
```

### Creating an Event Listener

#### Key Events

```c++
#include "multimodalinput/oh_input_manager.h"

struct KeyEvent {
    int32_t action;
    int32_t keyCode;
    int64_t actionTime { -1 };
};

// Define the key event callback function.
void OnKeyEventCallback(const Input_KeyEvent* keyEvent)
{
    KeyEvent event;
    // The lifecycle of Input_KeyEvent is limited to the callback function. Input_KeyEvent will be destroyed if it is called outside of the callback function.
    event.action = OH_Input_GetKeyEventAction(keyEvent);
    event.keyCode = OH_Input_GetKeyEventKeyCode(keyEvent);
    event.actionTime = OH_Input_GetKeyEventActionTime(keyEvent);
}

void TestMonitor()
{
    // Add a key event listener.
    Input_Result ret = OH_Input_AddKeyEventMonitor(OnKeyEventCallback);
    // Remove the key event listener.
    ret = OH_Input_RemoveKeyEventMonitor(OnKeyEventCallback);
}
```

#### Mouse Events

```c++
#include "multimodalinput/oh_input_manager.h"

struct MouseEvent {
    int32_t action;
    int32_t displayX;
    int32_t displayY;
    int32_t button { -1 };
    int32_t axisType { -1 };
    float axisValue { 0.0f };
    int64_t actionTime { -1 };
};

// Define the mouse event callback function.
void OnMouseEventCallback(const Input_MouseEvent* mouseEvent)
{
    MouseEvent event;
    // The lifecycle of Input_MouseEvent is limited to the callback function. Input_MouseEvent will be destroyed if it is called outside of the callback function.
    event.action = OH_Input_GetMouseEventAction(mouseEvent);
    event.displayX = OH_Input_GetMouseEventDisplayX(mouseEvent);
    event.displayY = OH_Input_GetMouseEventDisplayY(mouseEvent);
    event.button = OH_Input_GetMouseEventButton(mouseEvent);
    event.axisType = OH_Input_GetMouseEventAxisType(mouseEvent);
    event.axisValue = OH_Input_GetMouseEventAxisValue(mouseEvent);
    event.actionTime = OH_Input_GetMouseEventActionTime(mouseEvent);
}

void TestMonitor()
{
    // Add a mouse event listener.
    Input_Result ret = OH_Input_AddMouseEventMonitor(OnMouseEventCallback);
    // Remove the mouse event listener.
    ret = OH_Input_RemoveMouseEventMonitor(OnMouseEventCallback);
}
```

#### Touch Events

```c++
#include "multimodalinput/oh_input_manager.h"

struct TouchEvent {
    int32_t action;
    int32_t id;
    int32_t displayX;
    int32_t displayY;
    int64_t actionTime { -1 };
};

// Define the touch event callback function.
void OnTouchEventCallback(const Input_TouchEvent* touchEvent)
{
    TouchEvent event;
    // The lifecycle of Input_TouchEvent is limited to the callback function. Input_TouchEvent will be destroyed if it is called outside of the callback function.
    event.action = OH_Input_GetTouchEventAction(touchEvent);
    event.id = OH_Input_GetTouchEventFingerId(touchEvent);
    event.displayX = OH_Input_GetTouchEventDisplayX(touchEvent);
    event.displayY = OH_Input_GetTouchEventDisplayY(touchEvent);
    event.actionTime = OH_Input_GetTouchEventActionTime(touchEvent);
}

void TestMonitor()
{
    // Add a touch event listener.
    Input_Result ret = OH_Input_AddTouchEventMonitor(OnTouchEventCallback);
    // Remove the touch event listener.
    ret = OH_Input_RemoveTouchEventMonitor(OnTouchEventCallback);
}
```

#### Axis Events

```c++
#include "multimodalinput/oh_input_manager.h"
#include <map>

struct AxisEvent {
    int32_t axisAction;
    float displayX;
    float displayY;
    std::map<int32_t, double> axisValues;
    int64_t actionTime { -1 };
    int32_t sourceType;
    int32_t axisEventType { -1 };
};

// Define the callback function for all axis events.
void OnAllAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    // The lifecycle of Input_AxisEvent is limited to the callback function. Input_AxisEvent will be destroyed if it is called outside of the callback function.
    InputEvent_AxisAction action;
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType;
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType;
    ret = OH_Input_GetAxisEventType(axisEvent, &axisEventType);
    event.axisEventType = axisEventType;
    if (event.axisEventType == AXIS_EVENT_TYPE_PINCH) {
        double value = 0;
        ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_PINCH, &value);
        event.axisValues.insert(std::make_pair(AXIS_TYPE_PINCH, value));
        ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_ROTATE, &value);
        event.axisValues.insert(std::make_pair(AXIS_TYPE_ROTATE, value));
    } else if (event.axisEventType == AXIS_EVENT_TYPE_SCROLL) {
        double value = 0;
        ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_VERTICAL, &value);
        event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_VERTICAL, value));
        ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_HORIZONTAL, &value);
        event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_HORIZONTAL, value));
    }
}

// Define the callback function for pinch-type axis events.
void OnPinchAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    // The lifecycle of Input_AxisEvent is limited to the callback function. Input_AxisEvent will be destroyed if it is called outside of the callback function.
    InputEvent_AxisAction action;
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType;
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType;
    ret = OH_Input_GetAxisEventType(axisEvent, &axisEventType);
    event.axisEventType = axisEventType;
    double value = 0;
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_PINCH, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_PINCH, value));
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_ROTATE, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_ROTATE, value));
}

// Define the callback function for scroll wheel-type axis events.
void OnScrollAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    // The lifecycle of Input_AxisEvent is limited to the callback function. Input_AxisEvent will be destroyed if it is called outside of the callback function.
    InputEvent_AxisAction action;
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType;
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType;
    ret = OH_Input_GetAxisEventType(axisEvent, &axisEventType);
    event.axisEventType = axisEventType;
    double value = 0;
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_VERTICAL, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_VERTICAL, value));
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_HORIZONTAL, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_HORIZONTAL, value));
}

void TestMonitor()
{
    // Add a listener for all axis events.
    Input_Result ret = OH_Input_AddAxisEventMonitorForAll(OnAllAxisEventCallback);
    // Remove the listener for all axis events.
    ret = OH_Input_RemoveAxisEventMonitorForAll(OnAllAxisEventCallback);

    // Add a listener for pinch-type axis events.
    ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);
    // Remove the listener for pinch-type axis events.
    ret = OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);

    // Add a listener for scroll wheel-type axis events.
    ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
    // Remove the listener for scroll wheel-type axis events.
    ret = OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
}
```
