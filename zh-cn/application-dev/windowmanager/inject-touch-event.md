# 使用OH_WindowManager_InjectTouchEvent将多模触摸事件注入给目标窗口（C/C++）

## 场景介绍

开发者可以WindowManager模块提供的能力去将多模触摸事件注入给目标窗口，仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。该接口需要在指定窗口加载UI之后调用。


## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY) | 为指定的窗口注入触摸事件。 | 

## 开发步骤
### 在CMake脚本中链接动态库
```
target_link_libraries(entry PUBLIC libnative_window_manager.so libohinput.so)
```

### 添加头文件
```
#include "window_manager/oh_window.h"
#include "multimodalinput/oh_input_manager.h"
```

### 接口使用说明
- 应用通过构造相应的事件参数，向绑定的注入窗口ID注入事件。
- 窗口和多模校验构造事件参数正确性后，才可触发事件注入到ArkUI，具体参数说明如下：

| 参数名 | 描述 | 
| -------- | -------- |
| windowId | 目标窗口ID，限制同进程窗口，否则返回错误码1300002；且该窗口需完成加载UI，否则返回错误码1300003。 | 
| touchEvent | 多模触摸事件，具体可见[Input_TouchEvent](../reference/apis-input-kit/capi-input-input-touchevent.md)，事件定义在oh_input_manager.h中。调用[OH_Input_CreateTouchEvent](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_createtouchevent)接口可以创建touchevent对象，使用完需要调用[OH_Input_DestroyTouchEvent](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_createtouchevent)接口销毁touchEvent对象。touchEvent包含多个参数，在下表会展开说明。 |
| windowX | 注入事件相对于注入窗口的落点横坐标。该参数应为大于等于0的整数，否则返回错误码1300003。 |
| windowY | 注入事件相对于注入窗口的落点纵坐标。该参数应为大于等于0的整数，否则返回错误码1300003。 |

- touchEvent多模触摸事件具体参数说明如下：

| 参数名 | 方法 | 描述 | 默认值 | 限制 |
| -------- | -------- | -------- | -------- | -------- |
| action | [OH_Input_SetTouchEventAction](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventaction) | 事件行为 | 0 | 当前只支持0-3的行为，分别为0:cancel，1:down，2:move，3:up，其他行为会返回错误码1300003。 |
| id | [OH_Input_SetTouchEventFingerId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventfingerid) | 手指ID | 0 | 应为大于等于0的整数，否则返回错误码1300003。 |
| displayX | [OH_Input_SetTouchEventDisplayX](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayx) | 相对于屏幕的事件落点横坐标 | 0 | 应为大于等于0的整数，否则返回错误码1300003。应该尽量保证与windowX(相对于窗口的事件落点横坐标)有相互对应关系，即使不一致也不会返回错误码，仅校验入参合法范围。转换方法推荐使用[getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)方法获取windowRect属性，用displayX减去windowRect中窗口左上角横坐标即可得到对应的windowX。 |
| displayY | [OH_Input_SetTouchEventDisplayY](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayy) | 相对于屏幕的事件落点纵坐标 | 0 | 应为大于等于0的整数，否则返回错误码1300003。应该尽量保证与windowY(相对于窗口的事件落点纵坐标)有相互对应关系，即使不一致也不会返回错误码，仅校验入参合法范围。转换方法推荐使用[getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)方法获取windowRect属性，用displayY减去windowRect中窗口左上角纵坐标即可得到对应的windowY。 |
| actionTime | [OH_Input_SetTouchEventActionTime](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventactiontime) | 时间戳 | -1 | 应为大于等于0的整数，否则返回错误码1300003。 |
| windowId | [OH_Input_SetTouchEventWindowId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventwindowid) | 事件注入窗口ID | -1 | 若该参数不为默认值且不等于 [OH_WindowManager_InjectTouchEvent](../reference/reference/apis-arkui/capi-oh-window-h.md#oh_windowmanager_injecttouchevent)接口参数windowId，校验传入参数错误。 |
| displayId | [OH_Input_SetTouchEventDisplayId](../reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_settoucheventdisplayid) | 事件注入屏幕ID | -1 | 无限制，但是应该尽量保证与接口参数windowId有相互对应关系，推荐使用[getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)方法获取displayId属性。 |

- 仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。
- 该接口需要在指定窗口加载UI之后调用。

## 示例代码
以下示例代码中介绍了如何将多模触摸事件注入给目标窗口，以注入一次事件为例。
```
#include "window_manager/oh_window.h"
#include "multimodalinput/oh_input_manager.h"

static napi_value injectEvent(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1] = {nullptr};
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
  
  // 构造多模事件touchEvent
  Input_TouchEvent* touchEvent = OH_Input_CreateTouchEvent();
  OH_Input_SetTouchEventAction(touchEvent, action);
  OH_Input_SetTouchEventFingerId(touchEvent, fingerId);
  OH_Input_SetTouchEventDisplayX(touchEvent, displayX);
  OH_Input_SetTouchEventDisplayY(touchEvent, displayY);
  OH_Input_SetTouchEventActionTime(touchEvent, actionTime);
  OH_Input_SetTouchEventWindowId(touchEvent, TE_WindowId);
  OH_Input_SetTouchEventDisplayId(touchEvent, displayId);

  // 向windowId对应的窗口注入多模触摸事件
  auto res = OH_WindowManager_InjectTouchEvent(windowId, touchEvent, windowX, windowY);

  // 使用完touchEvent后销毁对象
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