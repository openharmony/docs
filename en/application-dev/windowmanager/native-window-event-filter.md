# Using NativeWindowEventFilter to Filter Multimodal Input Events (C/C++)

## When to Use

You can use the capability provided by the NativeWindowEventFilter module to intercept key events so that they are not distributed to internal components of your application.


## Available APIs

| API| Description| 
| -------- | -------- |
| OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter) | Registers a key event filter for a window.| 
| OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)| Unregisters the key event filter of a window.| 

## How to Develop
### Linking the Dynamic Library in the CMake Script
```
target_link_libraries(entry PUBLIC libnative_window_manager.so libohinput.so)
```

### Adding Header Files
```
#include "window_manager/oh_window_comm.h"
#include "window_manager/oh_window_event_filter.h"
#include "multimodalinput/oh_input_manager.h"
#include "multimodalinput/oh_key_code.h"
```

### API Usage Description
- After an application window is created, bind a key event filter to the window specified by the window ID.
- The application window can trigger the key event interception only when it receives the key event.
- The application window intercepts the event when the return value of the key event filter is **true**. If the return value is **false**, it does not intercept the event.
- Only one key event filter can be registered for the same window ID. The last registered key event filter overwrites the previously registered one. To filter a multi-key event, you are advised to process the multi-key combination in a filter.

## Example
The following sample code describes how to register and unregister a key event filter. The following uses the Esc key and number keys as an example.
```
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
