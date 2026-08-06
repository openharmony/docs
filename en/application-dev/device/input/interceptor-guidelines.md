# Event Interception Development (C/C++)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=c557fc878b00a6eb2a3211f12739d2d4a9bfd804 translatedAt=2026-07-28T02:35:27.530Z pushedAt=2026-07-28T03:02:26.214Z -->

## Introduction

Since API version 12, the multimodal module provides applications with the ability to create and delete keys and intercept input events (including mouse, touch, and axis events). For example, you can intercept key, mouse, touch, and axis events.

## Available APIs

The following table lists the APIs for creating and deleting event interception. For details, see [input](../../reference/apis-input-kit/capi-input.md).

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

- **Key event**

<!-- @[key_event_interceptor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventInterceptor/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
struct KeyEvent {
    int32_t action;
    int32_t keyCode;
    int64_t actionTime { -1 };
};

// Define the key event callback function.
void OnKeyEventCallback(const Input_KeyEvent* keyEvent)
{
    KeyEvent event;
    // The lifecycle of Input_KeyEvent is limited to the callback function. It is automatically destroyed after the callback function finishes executing.
    event.action = OH_Input_GetKeyEventAction(keyEvent);
    event.keyCode = OH_Input_GetKeyEventKeyCode(keyEvent);
    event.actionTime = OH_Input_GetKeyEventActionTime(keyEvent);
    // ...
}

static napi_value AddKeyEventInterceptor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddKeyEventInterceptor(OnKeyEventCallback, nullptr);
    // ...
}

static napi_value RemoveKeyEventInterceptor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveKeyEventInterceptor();
    // ...
}
```

- **Input Events (Mouse, Touch, and Axis Events)**

<!-- @[input_event_interceptor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventInterceptor/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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
    // The lifecycle of Input_MouseEvent is limited to the callback function. It is destroyed when the callback ends.
    event.action = OH_Input_GetMouseEventAction(mouseEvent);
    event.displayX = OH_Input_GetMouseEventDisplayX(mouseEvent);
    event.displayY = OH_Input_GetMouseEventDisplayY(mouseEvent);
    event.button = OH_Input_GetMouseEventButton(mouseEvent);
    event.axisType = OH_Input_GetMouseEventAxisType(mouseEvent);
    event.axisValue = OH_Input_GetMouseEventAxisValue(mouseEvent);
    event.actionTime = OH_Input_GetMouseEventActionTime(mouseEvent);
    // ...
}

// Define the touch event callback function.
void OnTouchEventCallback(const Input_TouchEvent* touchEvent)
{
    TouchEvent event;
    // The lifecycle of Input_TouchEvent is limited to the callback function. It is destroyed when the callback ends.
    event.action = OH_Input_GetTouchEventAction(touchEvent);
    event.id = OH_Input_GetTouchEventFingerId(touchEvent);
    event.displayX = OH_Input_GetTouchEventDisplayX(touchEvent);
    event.displayY = OH_Input_GetTouchEventDisplayY(touchEvent);
    event.actionTime = OH_Input_GetTouchEventActionTime(touchEvent);
    // ...
}

// Define the axis event callback function.
void OnAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    // The lifecycle of Input_AxisEvent is limited to the callback function. It is destroyed when the callback ends.
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
    // ...
}

// Input event callback function struct.
Input_InterceptorEventCallback g_eventCallback;

static napi_value AddEventInterceptor(napi_env env, napi_callback_info info)
{
    // Set the mouse event callback function.
    g_eventCallback.mouseCallback = OnMouseEventCallback;
    // Set the touch event callback function.
    g_eventCallback.touchCallback = OnTouchEventCallback;
    // Set the axis event callback function.
    g_eventCallback.axisCallback = OnAxisEventCallback;
    Input_Result ret = OH_Input_AddInputEventInterceptor(&g_eventCallback, nullptr);
    // ...
}

static napi_value RemoveEventInterceptor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveInputEventInterceptor();
    // ...
}
```

## Samples

- [NDKInputEventInterceptor (C/C++)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/InputKit/NDKInputEventInterceptor)