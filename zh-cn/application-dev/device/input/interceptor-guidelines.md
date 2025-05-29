# 事件拦截开发指导（C/C++）

## 功能介绍

多模为应用提供了创建和删除按键、输入事件（鼠标、触摸和轴事件）拦截的能力。使用场景例如：云桌面应用需要拦截按键、鼠标、触摸和轴事件。

## 接口说明

创建和删除事件拦截相关接口如下表所示，接口详细介绍请参考[Input文档](../../reference/apis-input-kit/capi-input.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option) |创建按键事件拦截。  |
| Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback, Input_InterceptorOptions *option) |创建输入事件拦截，包含鼠标、触摸和轴事件。  |
| Input_Result OH_Input_RemoveKeyEventInterceptor() |删除按键事件拦截。  |
| Input_Result OH_Input_RemoveInputEventInterceptor() |删除输入事件拦截，包含鼠标、触摸和轴事件。  |

## 开发步骤

### 链接动态库

调用创建和删除事件拦截前，需链接相关动态库。链接动态库的方法是，在CMakeList.txt文件中做下面例子所示的配置：

```txt
target_link_libraries(entry PUBLIC libohinput.so)
```

### 申请所需权限

应用需要在module.json5中添加下面权限的配置，详细的配置方法参考[声明权限文档](../../security/AccessToken/declare-permissions.md)。

```json
"requestPermissions": [
    {
        "name": "ohos.permission.INTERCEPT_INPUT_EVENT"
    }
]
```

### 创建事件拦截

#### 按键事件

```c++
#include "multimodalinput/oh_input_manager.h"

struct KeyEvent {
    int32_t action;
    int32_t keyCode;
    int64_t actionTime { -1 };
};

//定义按键事件回调函数
void OnKeyEventCallback(const Input_KeyEvent* keyEvent)
{
    KeyEvent event;
    //Input_KeyEvent的生命周期仅在回调函数内，出了回调函数会被销毁
    event.action = OH_Input_GetKeyEventAction(keyEvent);
    event.keyCode = OH_Input_GetKeyEventKeyCode(keyEvent);
    event.actionTime = OH_Input_GetKeyEventActionTime(keyEvent);
}

void TestInterceptor()
{
    //添加按键事件拦截
    Input_Result ret = OH_Input_AddKeyEventInterceptor(OnKeyEventCallback, nullptr);
    //移除按键事件监听
    ret = OH_Input_RemoveKeyEventInterceptor();
}
```

#### 输入拦截（鼠标、触摸和轴事件）

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

//定义鼠标事件回调函数
void OnMouseEventCallback(const Input_MouseEvent* mouseEvent)
{
    MouseEvent event;
    //Input_MouseEvent的生命周期仅在回调函数内，出了回调函数会被销毁
    event.action = OH_Input_GetMouseEventAction(mouseEvent);
    event.displayX = OH_Input_GetMouseEventDisplayX(mouseEvent);
    event.displayY = OH_Input_GetMouseEventDisplayY(mouseEvent);
    event.button = OH_Input_GetMouseEventButton(mouseEvent);
    event.axisType = OH_Input_GetMouseEventAxisType(mouseEvent);
    event.axisValue = OH_Input_GetMouseEventAxisValue(mouseEvent);
    event.actionTime = OH_Input_GetMouseEventActionTime(mouseEvent);
}

//定义触摸事件回调函数
void OnTouchEventCallback(const Input_TouchEvent* touchEvent)
{
    TouchEvent event;
    //Input_TouchEvent的生命周期仅在回调函数内，出了回调函数会被销毁
    event.action = OH_Input_GetTouchEventAction(touchEvent);
    event.id = OH_Input_GetTouchEventFingerId(touchEvent);
    event.displayX = OH_Input_GetTouchEventDisplayX(touchEvent);
    event.displayY = OH_Input_GetTouchEventDisplayY(touchEvent);
    event.actionTime = OH_Input_GetTouchEventActionTime(touchEvent);
}

//定义轴事件回调函数
void OnAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    //Input_AxisEvent的生命周期仅在回调函数内，出了回调函数会被销毁
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

//输入事件回调函数结构体
Input_InterceptorEventCallback g_eventCallback;

void TestInterceptor()
{
    //设置鼠标事件回调函数
    g_eventCallback.mouseCallback = OnMouseEventCallback;
    //设置触摸事件回调函数
    g_eventCallback.touchCallback = OnTouchEventCallback;
    //设置轴事件回调函数
    g_eventCallback.axisCallback = OnAxisEventCallback;

    //添加输入事件拦截
    Input_Result ret = OH_Input_AddInputEventInterceptor(&g_eventCallback, nullptr);
    //移除输入事件监听
    ret = OH_Input_RemoveInputEventInterceptor();
}
```
