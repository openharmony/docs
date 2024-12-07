# Event Interception Development (C/C++)

## Introduction

The multimodal module provides applications with the ability to create and delete keystrokes and intercept input events. For example, you can intercept key, mouse, touch, and axis events.

## Available APIs

The following table lists the APIs for event interception. For details, see [Input](../../reference/apis-input-kit/input.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option) |Creates a key event interceptor. |
| Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback, Input_InterceptorOptions *option) |Creates an input event interceptor. Input events include mouse, touch, and axis events. |
| Input_Result OH_Input_RemoveKeyEventInterceptor() |Removes a key event interceptor. |
| Input_Result OH_Input_RemoveInputEventInterceptor() |Removes an input event interceptor. |

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

### Creating an Event Interceptor

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

void TestInterceptor()
{
    // Add the key event interceptor.
    Input_Result ret = OH_Input_AddKeyEventInterceptor(OnKeyEventCallback, nullptr);
    // Remove the key event interceptor.
    ret = OH_Input_RemoveKeyEventInterceptor();
}
```

#### Input Events

```c++
#include "multimodalinput/oh_input_manager.h"
#include <map>

struct MouseEvent {
    int32_t action;
    int32_t displayX;
    int32_t displayY;
    int32_t button { -1 };
    int32_t axisType { -1 };
    float axisValue { 0.0f };
    int64_t actionTime { -1 };
};

struct TouchEvent {
    int32_t action;
    int32_t id;
    int32_t displayX;
    int32_t displayY;
    int64_t actionTime { -1 };
};

struct AxisEvent {
    int32_t axisAction;
    float displayX;
    float displayY;
    std::map<int32_t, double> axisValues;
    int64_t actionTime { -1 };
    int32_t sourceType;
    int32_t axisEventType { -1 };
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

// Define the axis event callback function.
void OnAxisEventCallback(const Input_AxisEvent* axisEvent)
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

// Structure of the input event callback function
Input_InterceptorEventCallback g_eventCallback;

void TestInterceptor()
{
    // Set the mouse event callback function.
    g_eventCallback.mouseCallback = OnMouseEventCallback;
    // Set the touch event callback function.
    g_eventCallback.touchCallback = OnTouchEventCallback;
    // Set the axis event callback function.
    g_eventCallback.axisCallback = OnAxisEventCallback;

    // Add the input event interceptor.
    Input_Result ret = OH_Input_AddInputEventInterceptor(&g_eventCallback, nullptr);
    // Remove the input event interceptor.
    ret = OH_Input_RemoveInputEventInterceptor();
}
```
