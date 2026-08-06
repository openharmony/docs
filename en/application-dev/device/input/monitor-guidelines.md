# Event Listening Development (C/C++)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=c557fc878b00a6eb2a3211f12739d2d4a9bfd804 translatedAt=2026-07-28T02:35:32.646Z pushedAt=2026-07-28T03:14:27.050Z -->

## When to Use

Since API version 12, the multimodal module provides applications with the ability to listen for key and input events (including mouse, touch, and axis events). Currently, event listening is available only for screen recording applications. For example, when a user starts screen recording, your application can listen for key, mouse, touch, and axis events of the device.

## Available APIs

The following table lists the APIs for creating and deleting event listeners. For details, see [input](../../reference/apis-input-kit/capi-input.md).

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

### Linking Dynamic Libraries

Before calling listener-related APIs, you need to link the related dynamic libraries. To link dynamic libraries, add the following configuration to the **CMakeList.txt** file:

```txt
target_link_libraries(entry PUBLIC libohinput.so)
```

### Applying for Required Permissions

Declare the required permission in the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md).

```json
"requestPermissions": [
    {
        "name": "ohos.permission.INPUT_MONITORING"
    }
]
```

### Creating an Event Listener

- **Key event**

<!-- @[key_event_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventMonitor/entry/src/main/cpp/napi_init.cpp) -->

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

static napi_value AddKeyEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddKeyEventMonitor(OnKeyEventCallback);
    // ...
}

static napi_value RemoveKeyEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveKeyEventMonitor(OnKeyEventCallback);
    // ...
}
```

- **Mouse event**

<!-- @[mouse_event_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventMonitor/entry/src/main/cpp/napi_init.cpp) -->

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

// Define the mouse event callback.
void OnMouseEventCallback(const Input_MouseEvent* mouseEvent)
{
    MouseEvent event;
    // The lifecycle of Input_MouseEvent is limited to the callback. It is automatically destroyed after the callback execution completes.
    event.action = OH_Input_GetMouseEventAction(mouseEvent);
    event.displayX = OH_Input_GetMouseEventDisplayX(mouseEvent);
    event.displayY = OH_Input_GetMouseEventDisplayY(mouseEvent);
    event.button = OH_Input_GetMouseEventButton(mouseEvent);
    event.axisType = OH_Input_GetMouseEventAxisType(mouseEvent);
    event.axisValue = OH_Input_GetMouseEventAxisValue(mouseEvent);
    event.actionTime = OH_Input_GetMouseEventActionTime(mouseEvent);
    // ...
}

static napi_value AddMouseEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddMouseEventMonitor(OnMouseEventCallback);
    // ...
}

static napi_value RemoveMouseEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveMouseEventMonitor(OnMouseEventCallback);
    // ...
}
```

- **Touch event**

<!-- @[touch_event_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventMonitor/entry/src/main/cpp/napi_init.cpp) -->

``` C++
struct TouchEvent {
    int32_t action;
    int32_t id;
    int32_t displayX;
    int32_t displayY;
    int64_t actionTime { -1 };
};

void OnTouchEventCallback(const Input_TouchEvent* touchEvent)
{
    TouchEvent event;
    // Input_TouchEvent is only valid within the callback function and is automatically destroyed after the callback completes.
    event.action = OH_Input_GetTouchEventAction(touchEvent);
    event.id = OH_Input_GetTouchEventFingerId(touchEvent);
    event.displayX = OH_Input_GetTouchEventDisplayX(touchEvent);
    event.displayY = OH_Input_GetTouchEventDisplayY(touchEvent);
    event.actionTime = OH_Input_GetTouchEventActionTime(touchEvent);
    // ...
}

static napi_value AddTouchEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddTouchEventMonitor(OnTouchEventCallback);
    // ...
}

static napi_value RemoveTouchEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveTouchEventMonitor(OnTouchEventCallback);
    // ...
}
```

- **Axis event**

<!-- @[axis_event_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/NDKInputEventMonitor/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
struct AxisEvent {
    int32_t axisAction;
    float displayX;
    float displayY;
    std::map<int32_t, double> axisValues;
    int64_t actionTime { -1 };
    int32_t sourceType;
    int32_t axisEventType { -1 };
};

void OnAllAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    // The lifecycle of Input_AxisEvent is limited to the callback function. It is automatically destroyed after the callback function completes.
    InputEvent_AxisAction action = static_cast<InputEvent_AxisAction>(0);
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType = static_cast<InputEvent_SourceType>(0);
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType = static_cast<InputEvent_AxisEventType>(-1);
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

// Define the pinch-type axis event callback function.
void OnPinchAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    // The lifecycle of Input_AxisEvent is limited to the callback function. It is automatically destroyed after the callback function completes.
    InputEvent_AxisAction action = static_cast<InputEvent_AxisAction>(0);
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType = static_cast<InputEvent_SourceType>(0);
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType = static_cast<InputEvent_AxisEventType>(-1);
    ret = OH_Input_GetAxisEventType(axisEvent, &axisEventType);
    event.axisEventType = axisEventType;
    double value = 0;
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_PINCH, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_PINCH, value));
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_ROTATE, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_ROTATE, value));
    // ...
}

void OnScrollAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    // The lifecycle of Input_AxisEvent is limited to the callback function. It is automatically destroyed after the callback function completes.
    InputEvent_AxisAction action = static_cast<InputEvent_AxisAction>(0);
    Input_Result ret = OH_Input_GetAxisEventAction(axisEvent, &action);
    event.axisAction = action;
    ret = OH_Input_GetAxisEventDisplayX(axisEvent, &event.displayX);
    ret = OH_Input_GetAxisEventDisplayY(axisEvent, &event.displayY);
    ret = OH_Input_GetAxisEventActionTime(axisEvent, &event.actionTime);
    InputEvent_SourceType sourceType = static_cast<InputEvent_SourceType>(0);
    ret = OH_Input_GetAxisEventSourceType(axisEvent, &sourceType);
    event.sourceType = sourceType;
    InputEvent_AxisEventType axisEventType = static_cast<InputEvent_AxisEventType>(-1);
    ret = OH_Input_GetAxisEventType(axisEvent, &axisEventType);
    event.axisEventType = axisEventType;
    double value = 0;
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_VERTICAL, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_VERTICAL, value));
    ret = OH_Input_GetAxisEventAxisValue(axisEvent, AXIS_TYPE_SCROLL_HORIZONTAL, &value);
    event.axisValues.insert(std::make_pair(AXIS_TYPE_SCROLL_HORIZONTAL, value));
    // ...
}

static napi_value AddAxisEventMonitorForAll(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddAxisEventMonitorForAll(OnAllAxisEventCallback);
    // ...
}

static napi_value RemoveAxisEventMonitorForAll(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveAxisEventMonitorForAll(OnAllAxisEventCallback);
    // ...
}

static napi_value AddPinchAxisEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);
    // ...
}

static napi_value RemovePinchAxisEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);
    // ...
}

static napi_value AddScrollAxisEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
    // ...
}

static napi_value RemoveScrollAxisEventMonitor(napi_env env, napi_callback_info info)
{
    Input_Result ret =  OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
    // ...
}
```