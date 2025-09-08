# Using WindowManager to Manage Multimodal Input Events (C/C++)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @stupidb-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## When to Use

[WindowManager](../reference/apis-arkui/capi-windowmanager.md) provides the capability to manage application windows and can be used to handle multimodal input events.

Currently, WindowManager supports filtering multimodal input events and injecting multimodal touch events into target windows. The specific development steps are detailed below.

## Filtering Multimodal Input Events

You can use the capability provided by the WindowManager module to intercept key events so that they are not distributed to internal components of your application.

### Linking the Dynamic Library in the CMake Script
```
target_link_libraries(entry PUBLIC libnative_window_manager.so libohinput.so)
```

### Adding Header Files
```c++
#include "multimodalinput/oh_input_manager.h"
#include "multimodalinput/oh_key_code.h"
#include "window_manager/oh_window_comm.h"
#include "window_manager/oh_window_event_filter.h"
```

### Available APIs

| API                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter) | Registers a key event filter for a window.|
| OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId) | Unregisters the key event filter of a window.              |

- After an application window is created, bind a key event filter using the window ID.
- The key event filter is triggered only when the application window receives a key event.
- If the callback function returns **true**, the event is intercepted; if it returns **false**, the event is not intercepted.
- Only one key event filter can be registered for the same window ID. The last registered key event filter overwrites the previously registered one. To filter a multi-key event, you are advised to process the multi-key combination in a filter.

### Example

The following sample code describes how to register and unregister a key event filter. The following uses the Esc key and number keys as an example.
```c++
#include "napi/native_api.h"
#include "window_manager/oh_window_comm.h"
#include "window_manager/oh_window_event_filter.h"
#include "multimodalinput/oh_input_manager.h"
#include "multimodalinput/oh_key_code.h"

// Set a filter.
static bool filterFunc(Input_KeyEvent *event) {
  auto keyCode = OH_Input_GetKeyEventKeyCode(event);
  auto action = OH_Input_GetKeyEventAction(event);
  // Case1: Implement the event filter for the Esc key.
  // return keyCode == Input_KeyCode::KEYCODE_ESCAPE;

  // Case 2: Implement the event filter for the number keys only when they are pressed.
  // return keyCode >= Input_KeyCode::KEYCODE_0 && keyCode <= Input_KeyCode::KEYCODE_9
  //  && action == Input_KeyEventAction::KEY_ACTION_DOWN;
  
  // Implement the event filter for the combination of the Esc key and a pressed-down number key. (Case1 || Case2).
  return (keyCode >= Input_KeyCode::KEYCODE_0 && keyCode <= Input_KeyCode::KEYCODE_9
     && action == Input_KeyEventAction::KEY_ACTION_DOWN) || (keyCode == Input_KeyCode::KEYCODE_ESCAPE);
}

static napi_value registerFilter(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1] = {nullptr};
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
  
  int32_t windowId;
  napi_get_value_int32(env, args[0], &windowId);
  
  // Register the filter for the window specified by the window ID.
  auto res = OH_NativeWindowManager_RegisterKeyEventFilter(windowId, filterFunc);
  
  napi_value errCode;
  napi_create_int32(env, res, &errCode);
  return errCode;
}

static napi_value clearFilter(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1] = {nullptr};
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  int32_t windowId;
  napi_get_value_int32(env, args[0], &windowId);

  auto res = OH_NativeWindowManager_UnregisterKeyEventFilter(windowId);
  napi_value errCode;
  napi_create_int32(env, res, &errCode);
  return errCode;

}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor desc[] = {
    {"registerFilter", nullptr, registerFilter, nullptr, nullptr, nullptr, napi_default, nullptr},
    {"clearFilter", nullptr, clearFilter, nullptr, nullptr, nullptr, napi_default, nullptr}};
  napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
  return exports;
}
EXTERN_C_END
```

## Injecting Multimodal Touch Events

You can use the capability provided by the WindowManager module to inject touch events into a specified window. This operation is supported only for windows within the same process. It does not trigger changes in window focus, z-order, or dragging. Instead, the events are directly sent to ArkUI.


### Linking the Dynamic Library in the CMake Script

```
target_link_libraries(entry PUBLIC libnative_window_manager.so libohinput.so)
```

### Adding Header Files

```c++
#include "multimodalinput/oh_input_manager.h"
#include "window_manager/oh_window.h"
#include "napi/native_api.h"
```

### Available APIs

| API                                                      | Description                      |
| ------------------------------------------------------------ | -------------------------- |
| OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY) | Injects a touch event into the specified window.|

- Construct event parameters and inject the event to the window with the specified window ID.

- Only windows within the same process are supported. Injection does not trigger changes in window focus, z-order, or dragging. Events are directly sent to ArkUI.

- The API must be called after the specified window has completed its UI loading.

- Check the window and multimodal touch event to ensure the event parameters are correct before sending the event to ArkUI. The specific parameter descriptions are as follows:

  | Name    | Description                                                        |
  | ---------- | ------------------------------------------------------------ |
  | windowId   | ID of the target window. Only windows within the same process are supported. Otherwise, error code 1300002 is returned. The window must have completed UI loading. Otherwise, error code 1300003 is returned.|
  | touchEvent | Pointer to the multimodal touch event. For details, see [Input_TouchEvent](../reference/apis-input-kit/capi-input-input-touchevent.md). The event is defined in **oh_input_manager.h**. Call [OH_Input_CreateTouchEvent](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_createtouchevent) to create a touchEvent object, and call [OH_Input_DestroyTouchEvent](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_destroytouchevent) to destroy the object after use. For specific parameter details, see the table below.|
  | windowX    | X coordinate of the event relative to the target window. The parameter must be a non-negative integer; otherwise, error code 1300003 is returned.|
  | windowY    | Y coordinate of the event relative to the target window. The parameter must be a non-negative integer; otherwise, error code 1300003 is returned.|

  The following table describes the parameters of the **touchEvent** event.

  | Name    | API                                                        | Description                                                        |
  | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | action     | [OH_Input_SetTouchEventAction](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventaction) | Event action. The default value is **0**.<br>Only the following actions are supported:<br>- **0**: cancel, indicating a cancel event.<br>- **1**: down, indicating a press-down event.<br>- **2**: move, indicating a move event.<br>- **3**: up, indicating a lift event.<br>- For other actions, error code 1300003 is returned.|
  | id         | [OH_Input_SetTouchEventFingerId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventfingerid) | Finger ID. The default value is **0**.<br>The parameter must be a non-negative integer; otherwise, error code 1300003 is returned.|
  | displayX   | [OH_Input_SetTouchEventDisplayX](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayx) | X coordinate of the event relative to the screen. The default value is **0**.<br>The parameter must be a non-negative integer; otherwise, error code 1300003 is returned. It is recommended that the value of this parameter be the same as that of **windowX**, although inconsistency will not return an error code. Only the input parameter's range is verified. You are advised to use [getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9) to obtain the **windowRect** property and calculate the corresponding **windowX** by subtracting the horizontal coordinate of the window's upper-left corner in **windowRect** from **displayX**.|
  | displayY   | [OH_Input_SetTouchEventDisplayY](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayy) | Y coordinate of the event relative to the screen. The default value is **0**.<br>The parameter must be a non-negative integer; otherwise, error code 1300003 is returned. It is recommended that the value of this parameter be the same as that of **windowY**, although inconsistency will not return an error code. Only the input parameter's range is verified. You are advised to use [getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9) to obtain the **windowRect** property and calculate the corresponding **windowY** by subtracting the horizontal coordinate of the window's upper-left corner in **windowRect** from **displayY**.|
  | actionTime | [OH_Input_SetTouchEventActionTime](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventactiontime) | Timestamp. The default value is **-1**. The parameter must be a non-negative integer; otherwise, error code 1300003 is returned.|
  | windowId   | [OH_Input_SetTouchEventWindowId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventwindowid) | Window ID for event injection. The default value is **-1**. If the parameter is not the default value and does not match **windowId** in [OH_WindowManager_InjectTouchEvent](../reference/apis-arkui/capi-oh-window-h.md#oh_windowmanager_injecttouchevent), the input parameter is considered invalid.|
  | displayId  | [OH_Input_SetTouchEventDisplayId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayid) | Display ID for event injection. The default value is **-1**. There are no restrictions, but you are advised to ensure that the display ID matches the window ID in [OH_WindowManager_InjectTouchEvent](../reference/apis-arkui/capi-oh-window-h.md#oh_windowmanager_injecttouchevent). You are advised to call [getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9) to obtain the **displayId** property.|

### Example

The following sample code describes how to inject a multimodal touch event into the target window, using a single event injection as an example.

```c++
#include "window_manager/oh_window.h"
#include "multimodalinput/oh_input_manager.h"
#include "napi/native_api.h"

static napi_value injectEvent(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[10] = {nullptr};
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
  
  int32_t windowId;
  napi_get_value_int32(env, args[0], &windowId);

  int32_t displayId;
  napi_get_value_int32(env, args[1], &displayId);

  int32_t windowX;
  napi_get_value_int32(env, args[2], &windowX);

  int32_t windowY;
  napi_get_value_int32(env, args[3], &windowY);

  int32_t action;
  napi_get_value_int32(env, args[4], &action);

  int32_t fingerId;
  napi_get_value_int32(env, args[5], &fingerId);

  int32_t displayX;
  napi_get_value_int32(env, args[6], &displayX);

  int32_t displayY;
  napi_get_value_int32(env, args[7], &displayY);

  int32_t actionTime;
  napi_get_value_int32(env, args[8], &actionTime);

  int32_t TE_WindowId;
  napi_get_value_int32(env, args[9], &TE_WindowId);
  
  // Construct a multimodal touch event.
  Input_TouchEvent* touchEvent = OH_Input_CreateTouchEvent();
  OH_Input_SetTouchEventAction(touchEvent, action);
  OH_Input_SetTouchEventFingerId(touchEvent, fingerId);
  OH_Input_SetTouchEventDisplayX(touchEvent, displayX);
  OH_Input_SetTouchEventDisplayY(touchEvent, displayY);
  OH_Input_SetTouchEventActionTime(touchEvent, actionTime);
  OH_Input_SetTouchEventWindowId(touchEvent, TE_WindowId);
  OH_Input_SetTouchEventDisplayId(touchEvent, displayId);

  // Inject the multimodal touch event to the window with the specified windowId.
  auto res = OH_WindowManager_InjectTouchEvent(windowId, touchEvent, windowX, windowY);

  // Destroy the touchEvent object after using it.
  OH_Input_DestroyTouchEvent(&touchEvent);
  
  napi_value errCode;
  napi_create_int32(env, res, &errCode);
  return errCode;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor desc[] = {
    {"injectEvent", nullptr, injectEvent, nullptr, nullptr, nullptr, napi_default, nullptr}};
  napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
  return exports;
}
EXTERN_C_END
```
