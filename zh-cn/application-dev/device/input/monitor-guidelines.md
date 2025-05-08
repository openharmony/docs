# 事件监听开发指导（C/C++）

## 功能介绍

多模为应用提供了按键、输入事件（鼠标、触屏和轴事件）监听能力，当前仅支持录屏类应用。使用场景例如：用户在录屏应用开启录屏时，监听设备的按键、鼠标、触摸和轴事件。

## 接口说明

创建和删除事件监听相关接口如下表所示，接口详细介绍请参考[Input文档](../../reference/apis-input-kit/input.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback) |创建按键事件监听。  |
| Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback) |创建鼠标事件监听。  |
| Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback) |创建触摸事件监听。  |
| Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback) |创建所有类型轴事件监听。  |
| Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback) |创建指定类型轴事件监听。  |
| Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback) |删除按键事件监听。  |
| Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback) |删除鼠标事件监听。  |
| Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback) |删除触摸事件监听。  |
| Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback) |删除所有类型轴事件监听。  |
| Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback) |删除指定类型轴事件监听。  |

## 开发步骤

### 链接动态库

调用创建和删除事件拦截前，需链接相关动态库。链接动态库的方法是，在CMakeList.txt文件中新增如下配置：

```txt
target_link_libraries(entry PUBLIC libohinput.so)
```

### 申请所需权限

应用需要在module.json5中添加下面权限的配置，详细的配置方法参考声明[声明权限文档](../../security/AccessToken/declare-permissions.md)。

```json
"requestPermissions": [
    {
        "name": "ohos.permission.INPUT_MONITORING"
    }
]
```

### 创建事件监听

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
    //Input_KeyEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
    event.action = OH_Input_GetKeyEventAction(keyEvent);
    event.keyCode = OH_Input_GetKeyEventKeyCode(keyEvent);
    event.actionTime = OH_Input_GetKeyEventActionTime(keyEvent);
}

void TestMonitor()
{
    //添加按键事件监听
    Input_Result ret = OH_Input_AddKeyEventMonitor(OnKeyEventCallback);
    //移除按键事件监听
    ret = OH_Input_RemoveKeyEventMonitor(OnKeyEventCallback);
}
```

#### 鼠标事件

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

//定义鼠标事件回调函数
void OnMouseEventCallback(const Input_MouseEvent* mouseEvent)
{
    MouseEvent event;
    //Input_MouseEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
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
    //添加鼠标事件监听
    Input_Result ret = OH_Input_AddMouseEventMonitor(OnMouseEventCallback);
    //移除鼠标事件监听
    ret = OH_Input_RemoveMouseEventMonitor(OnMouseEventCallback);
}
```

#### 触摸事件

```c++
#include "multimodalinput/oh_input_manager.h"

struct TouchEvent {
    int32_t action;
    int32_t id;
    int32_t displayX;
    int32_t displayY;
    int64_t actionTime { -1 };
};

//定义触摸事件回调函数
void OnTouchEventCallback(const Input_TouchEvent* touchEvent)
{
    TouchEvent event;
    //Input_TouchEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
    event.action = OH_Input_GetTouchEventAction(touchEvent);
    event.id = OH_Input_GetTouchEventFingerId(touchEvent);
    event.displayX = OH_Input_GetTouchEventDisplayX(touchEvent);
    event.displayY = OH_Input_GetTouchEventDisplayY(touchEvent);
    event.actionTime = OH_Input_GetTouchEventActionTime(touchEvent);
}

void TestMonitor()
{
    //添加触摸事件监听
    Input_Result ret = OH_Input_AddTouchEventMonitor(OnTouchEventCallback);
    //移除触摸事件监听
    ret = OH_Input_RemoveTouchEventMonitor(OnTouchEventCallback);
}
```

#### 轴事件

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

//定义所有类型轴事件回调函数
void OnAllAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    //Input_AxisEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
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

//定义捏合类型轴事件回调函数
void OnPinchAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    //Input_AxisEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
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

//定义滚轮类型轴事件回调函数
void OnScrollAxisEventCallback(const Input_AxisEvent* axisEvent)
{
    AxisEvent event;
    
    //Input_AxisEvent的生命周期仅限于回调函数内，回调函数执行完毕后会被自动销毁
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
    //添加所有类型轴事件监听
    Input_Result ret = OH_Input_AddAxisEventMonitorForAll(OnAllAxisEventCallback);
    //移除所有类型轴事件监听
    ret = OH_Input_RemoveAxisEventMonitorForAll(OnAllAxisEventCallback);

    //添加捏合类型轴事件监听
    ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);
    //移除捏合类型轴事件监听
    ret = OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_PINCH, OnPinchAxisEventCallback);

    //添加滚轮类型轴事件监听
    ret = OH_Input_AddAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
    //移除滚轮类型轴事件监听
    ret = OH_Input_RemoveAxisEventMonitor(AXIS_EVENT_TYPE_SCROLL, OnScrollAxisEventCallback);
}
```
