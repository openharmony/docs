# 使用NativeWindowEventFilter过滤多模输入事件（C/C++）

## 场景介绍

开发者可以NativeWindowEventFilter模块提供的能力去拦截按键事件，让按键事件不往应用内部组件分发。


## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter); | 为指定的窗口注册过滤回调函数keyEventFilter。 | 
| OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)| 取消指定窗口上的过滤回调函数。 | 

## 开发步骤
### 在CMake脚本中链接动态库
```
target_link_libraries(entry PUBLIC libnative_window_manager.so libohinput.so)
```

### 添加头文件
```
#include "window_manager/oh_window_comm.h"
#include "window_manager/oh_window_event_filter.h"
#include "multimodalinput/oh_input_manager.h"
#include "multimodalinput/oh_key_code.h"
```

### 接口使用说明
- 应用窗口创建后，通过窗口ID去绑定窗口的按键事件过滤函数。
- 应用窗口需要收到按键事件时，窗口才可触发按键事件的拦截。
- 当回调函数返回值为true表示拦截，为false不拦截。
- 同一个窗口ID注册的回调函数只允许一个，最后注册的回调函数会覆盖之前注册过的回调函数。如需过滤多个按键的组合场景，建议在一个回调函数里面处理。

## 示例代码
以下示例代码中介绍了如何注册过滤函数和取消过滤函数，以过滤ESC退出按键和数字按键为例。
```
#include "napi/native_api.h"
#include "window_manager/oh_window_comm.h"
#include "window_manager/oh_window_event_filter.h"
#include "multimodalinput/oh_input_manager.h"
#include "multimodalinput/oh_key_code.h"

// 设置过滤函数
static bool filterFunc(Input_KeyEvent *event) {
  auto keyCode = OH_Input_GetKeyEventKeyCode(event);
  auto action = OH_Input_GetKeyEventAction(event);
  // case1: 过滤escape
  // return keyCode == Input_KeyCode::KEYCODE_ESCAPE;

  // case2: 过滤数字键的按下，抬起不过滤
  // return keyCode >= Input_KeyCode::KEYCODE_0 && keyCode <= Input_KeyCode::KEYCODE_9
  //  && action == Input_KeyEventAction::KEY_ACTION_DOWN;
  
  // 过滤escape和数字键的按下(case1 || case2)
  return (keyCode >= Input_KeyCode::KEYCODE_0 && keyCode <= Input_KeyCode::KEYCODE_9
     && action == Input_KeyEventAction::KEY_ACTION_DOWN) || (keyCode == Input_KeyCode::KEYCODE_ESCAPE);
}

static napi_value registerFilter(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1] = {nullptr};
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
  
  int32_t windowId;
  napi_get_value_int32(env, args[0], &windowId);
  
  // 向windowId对应的窗口注册filterFunc的过滤函数
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