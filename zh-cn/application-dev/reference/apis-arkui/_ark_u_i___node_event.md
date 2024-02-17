# ArkUI_NodeEvent


## 概述

定义组件事件的通用结构类型。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| int32_t [kind](#kind) | 事件类型。  |
| int32_t [eventId](#eventid) | 事件自定义标识ID。  |
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) [node](#node) | 触发该组件的组件对象。  |
| union {<br/>  [ArkUI_NodeTouchEvent](_ark_u_i___node_touch_event.md)  [touchEvent](#touchevent)<br>  [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) [componentEvent](#componentevent)<br>  [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) [stringEvent](#stringevent)<br>} | touchEvent：touch事件类型回调参数。<br>componentEvent：通用组件事件使用数字类型回调参数。<br>stringEvent：通用组件事件使用字符串类型回调参数。 |


## 结构体成员变量说明


### componentEvent

```
ArkUI_NodeComponentEvent ArkUI_NodeEvent::componentEvent
```
**描述：**

通用组件事件使用数字类型回调参数。


### eventId

```
int32_t ArkUI_NodeEvent::eventId
```
**描述：**

事件自定义标识ID。

该事件id在调用**registerNodeEvent**函数时作为参数传递进来，可应用于同一事件入口函数{**}分发逻辑。 **


### kind

```
int32_t ArkUI_NodeEvent::kind
```
**描述：**

事件类型。

**参见：**

[ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype)


### node

```
ArkUI_NodeHandle ArkUI_NodeEvent::node
```
**描述：**

触发该组件的组件对象。


### stringEvent

```
ArkUI_StringAsyncEvent ArkUI_NodeEvent::stringEvent
```
**描述：**

通用组件事件使用字符串类型回调参数。


### touchEvent

```
ArkUI_NodeTouchEvent ArkUI_NodeEvent::touchEvent
```
**描述：**

touch事件类型回调参数。
