# ArkUI_NativeNodeAPI_1


## 概述

ArkUI提供的Native侧Node类型接口集合。

Node模块相关接口需要在主线程上调用。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_node.h](native__node_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [version](#version) | 结构体版本。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [createNode](#createnode) )([ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) type) | 基于[ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype)生成对应的组件并返回组件对象指针。  | 
| void(\* [disposeNode](#disposenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 销毁组件指针指向的组件对象。  | 
| int32_t(\* [addChild](#addchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | 将组件挂载到某个父节点之下。  | 
| int32_t(\* [removeChild](#removechild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | 将组件从父节点中移除。  | 
| int32_t(\* [insertChildAfter](#insertchildafter) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | 将组件挂载到某个父节点之下，挂载位置在sibling节点之后。  | 
| int32_t(\* [insertChildBefore](#insertchildbefore) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | 将组件挂载到某个父节点之下，挂载位置在sibling节点之前。  | 
| int32_t(\* [insertChildAt](#insertchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, int32_t position) | 将组件挂载到某个父节点之下，挂载位置由position指定。  | 
| int32_t(\* [setAttribute](#setattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*item) | 属性设置函数。  | 
| const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*(\* [getAttribute](#getattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | 属性获取函数。  | 
| int32_t(\* [resetAttribute](#resetattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | 重置属性函数。  | 
| int32_t(\* [registerNodeEvent](#registernodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | 注册节点事件函数。  | 
| void(\* [unregisterNodeEvent](#unregisternodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType) | 反注册节点事件函数。  | 
| void(\* [registerNodeEventReceiver](#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | 注册事件回调统一入口函数。  | 
|  void(\* [unregisterNodeEventReceiver](#unregisternodeeventreceiver) )() | 反注册事件回调统一入口函数。  | 
| void(\* [markDirty](#markdirty) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeDirtyFlag](_ark_u_i___native_module.md#arkui_nodedirtyflag) dirtyFlag) | 强制标记当前节点需要重新测算，布局或者绘制。  | 
| uint32_t(\* [getTotalChildCount](#gettotalchildcount) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取子节点的个数。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getChildAt](#getchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t position) | 获取子节点。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getFirstChild](#getfirstchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取第一个子节点。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getLastChild](#getlastchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取最后一个子节点。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getPreviousSibling](#getprevioussibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取上一个兄弟节点。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getNextSibling](#getnextsibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取下一个兄弟节点。  | 
| int32_t(\* [registerNodeCustomEvent](#registernodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | 注册自定义节点事件函数。事件触发时通过registerNodeCustomEventReceiver注册的自定义事件入口函数返回。  | 
| void(\* [unregisterNodeCustomEvent](#unregisternodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType) | 反注册自定义节点事件函数。  | 
| void(\* [registerNodeCustomEventReceiver](#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | 注册自定义节点事件回调统一入口函数。  | 
|  void(\* [unregisterNodeCustomEventReceiver](#unregisternodecustomeventreceiver) )() | 反注册自定义节点事件回调统一入口函数。  | 
| int32_t(\* [setMeasuredSize](#setmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t width, int32_t height) | 在测算回调函数中设置组件的测算完成后的宽和高。  | 
| int32_t(\* [setLayoutPosition](#setlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | 在布局回调函数中设置组件的位置。  | 
| [ArkUI_IntSize](_ark_u_i___int_size.md)(\* [getMeasuredSize](#getmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取组件测算完成后的宽高尺寸。  | 
| [ArkUI_IntOffset](_ark_u_i___int_offset.md)(\* [getLayoutPosition](#getlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取组件布局完成后的位置。  | 
| int32_t(\* [measureNode](#measurenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LayoutConstraint](_ark_u_i___native_module.md#arkui_layoutconstraint) \*Constraint) | 对特定组件进行测算，可以通过getMeasuredSize接口获取测算后的大小。  | 
| int32_t(\* [layoutNode](#layoutnode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | 对特定组件进行布局并传递该组件相对父组件的期望位置。  | 
| int32_t(\* [addNodeEventReceiver](#addnodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | 在组件上添加组件事件回调函数，用于接受该组件产生的组件事件。  | 
| int32_t(\* [removeNodeEventReceiver](#removenodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | 在组件上删除注册的组件事件回调函数。  | 
| int32_t(\* [addNodeCustomEventReceiver](#addnodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | 在组件上添加自定义事件回调函数，用于接受该组件产生的自定义事件（如布局事件，绘制事件）。  | 
| int32_t(\* [removeNodeCustomEventReceiver](#removenodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | 在组件上删除注册的自定义事件回调函数。  | 
| int32_t(\* [setUserData](#setuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData) | 在组件上保存自定义数据。  | 
| void \*(\* [getUserData](#getuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取在组件上保存的自定义数据。  | 
| int32_t(\* [setLengthMetricUnit](#setlengthmetricunit) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 指定组件的单位。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getParent](#getparent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 获取父节点。  | 
| int32_t(\* [removeAllChildren](#removeallchildren) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent) | 从父组件上卸载所有子节点。  | 


## 结构体成员变量说明


### addChild

```
int32_t(* ArkUI_NativeNodeAPI_1::addChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**描述：**

将组件挂载到某个父节点之下。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 父节点指针。  | 
| child | 子节点指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### addNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**描述：**

在组件上添加自定义事件回调函数，用于接受该组件产生的自定义事件（如布局事件，绘制事件）。

不同于registerNodeCustomEventReceiver的全局注册函数，该函数允许在同一个组件上添加多个事件接受器。

该函数添加的监听回调函数触发时机会先与registerNodeCustomEventReceiver注册的全局回调函数。

避免直接保存ArkUI_NodeCustomEvent对象指针，数据会在回调结束后销毁。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于添加组件自定义事件回调函数的对象。  | 
| eventReceiver | 组件自定义事件回调函数。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### addNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**描述：**

在组件上添加组件事件回调函数，用于接受该组件产生的组件事件。

不同于registerNodeEventReceiver的全局注册函数，该函数允许在同一个组件上添加多个事件接受器。

该函数添加的监听回调函数触发时机会先与registerNodeEventReceiver注册的全局回调函数。

避免直接保存ArkUI_NodeEvent对象指针，数据会在回调结束后销毁。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于添加组件事件回调函数的对象。  | 
| eventReceiver | 组件事件回调函数。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### createNode

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::createNode) (ArkUI_NodeType type)
```
**描述：**

基于[ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype)生成对应的组件并返回组件对象指针。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 创建指定类型的UI组件节点。  | 

**返回：**

返回创建完成的组件操作指针，如果创建失败返回NULL。


### disposeNode

```
void(* ArkUI_NativeNodeAPI_1::disposeNode) (ArkUI_NodeHandle node)
```
**描述：**

销毁组件指针指向的组件对象。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 组件指针对象。  | 


### getAttribute

```
const ArkUI_AttributeItem*(* ArkUI_NativeNodeAPI_1::getAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**描述：**

属性获取函数。

该接口返回的指针是ArkUI框架内部的缓冲区指针，不需要开发者主动调用delete释放内存，但是需要在该函数下一次被调用前使用，否则可能会被其他值所覆盖。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要获取属性的节点对象。  | 
| attribute | 需要获取的属性类型。  | 

**返回：**

当前属性类型的属性值，失败返回空指针。


### getChildAt

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getChildAt) (ArkUI_NodeHandle node, int32_t position)
```
**描述：**

获取子节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 
| position | 子组件的位置。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getFirstChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getFirstChild) (ArkUI_NodeHandle node)
```
**描述：**

获取第一个子节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getLastChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getLastChild) (ArkUI_NodeHandle node)
```
**描述：**

获取最后一个子节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getLayoutPosition

```
ArkUI_IntOffset(* ArkUI_NativeNodeAPI_1::getLayoutPosition) (ArkUI_NodeHandle node)
```
**描述：**

获取组件布局完成后的位置。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

[ArkUI_IntOffset](_ark_u_i___int_offset.md) 组件的位置。


### getMeasuredSize

```
ArkUI_IntSize(* ArkUI_NativeNodeAPI_1::getMeasuredSize) (ArkUI_NodeHandle node)
```
**描述：**

获取组件测算完成后的宽高尺寸。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

[ArkUI_IntSize](_ark_u_i___int_size.md) 组件的宽高。


### getNextSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getNextSibling) (ArkUI_NodeHandle node)
```
**描述：**

获取下一个兄弟节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getParent

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getParent) (ArkUI_NodeHandle node)
```
**描述：**

获取父节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getPreviousSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getPreviousSibling) (ArkUI_NodeHandle node)
```
**描述：**

获取上一个兄弟节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

返回组件的指针，如果没有返回NULL


### getTotalChildCount

```
uint32_t(* ArkUI_NativeNodeAPI_1::getTotalChildCount) (ArkUI_NodeHandle node)
```
**描述：**

获取子节点的个数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 

**返回：**

子节点的个数, 如果没有返回0。


### getUserData

```
void*(* ArkUI_NativeNodeAPI_1::getUserData) (ArkUI_NodeHandle node)
```
**描述：**

获取在组件上保存的自定义数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 保存了自定义数据的组件。  | 

**返回：**

自定义数据。


### insertChildAfter

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAfter) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置在sibling节点之后。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 父节点指针。  | 
| child | 子节点指针。  | 
| sibling | 前一个兄弟节点指针，如果为空则插入位置在最后面。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### insertChildAt

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAt) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置由position指定。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 父节点指针。  | 
| child | 子节点指针。  | 
| position | 插入位置，如果插入位置为负数或者不存在，则默认插入位置在最后面。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### insertChildBefore

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildBefore) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置在sibling节点之前。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 父节点指针。  | 
| child | 子节点指针。  | 
| sibling | 后一个兄弟节点指针，如果为空则插入位置在最后面。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### layoutNode

```
int32_t(* ArkUI_NativeNodeAPI_1::layoutNode) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**描述：**

对特定组件进行布局并传递该组件相对父组件的期望位置。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 
| positionX | x轴坐标。  | 
| positionY | y轴坐标。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### markDirty

```
void(* ArkUI_NativeNodeAPI_1::markDirty) (ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```
**描述：**

强制标记当前节点需要重新测算，布局或者绘制。

系统属性设置更新场景下ArkUI框架会自动标记脏区并重新执行测算，布局或者绘制，不需要开发者主动调用该函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要标记脏区的节点对象。  | 
| dirtyFlag | 脏区类型。  | 


### measureNode

```
int32_t(* ArkUI_NativeNodeAPI_1::measureNode) (ArkUI_NodeHandle node, ArkUI_LayoutConstraint *Constraint)
```
**描述：**

对特定组件进行测算，可以通过getMeasuredSize接口获取测算后的大小。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 
| Constraint | 约束尺寸。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### registerNodeCustomEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void *userData)
```
**描述：**

注册自定义节点事件函数。事件触发时通过registerNodeCustomEventReceiver注册的自定义事件入口函数返回。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要注册事件的节点对象。  | 
| eventType | 需要注册的事件类型。  | 
| targetId | 自定义事件ID，当事件触发时在回调参数[ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) 中携带回来。  | 
| userData | 自定义事件参数，当事件触发时在回调参数[ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) 中携带回来。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode)系统中未找到Native接口的动态实现库。


### registerNodeCustomEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeCustomEventReceiver) (void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**描述：**

注册自定义节点事件回调统一入口函数。

ArkUI框架会统一收集过程中产生的自定义组件事件并通过注册的registerNodeCustomEventReceiver函数回调给开发者。

重复调用时会覆盖前一次注册的函数。

避免直接保存ArkUI_NodeCustomEvent对象指针，数据会在回调结束后销毁。

如果需要和组件实例绑定，可以使用addNodeCustomEventReceiver函数接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventReceiver | 事件回调统一入口函数。  | 


### registerNodeEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void *userData)
```
**描述：**

注册节点事件函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要注册事件的节点对象。  | 
| eventType | 需要注册的事件类型。  | 
| targetId | 自定义事件ID，当事件触发时在回调参数[ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) 中携带回来。  | 
| userData | 自定义事件参数，当事件触发时在回调参数[ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) 中携带回来。  |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode)系统中未找到Native接口的动态实现库。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### registerNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeEventReceiver) (void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**描述：**

注册事件回调统一入口函数。

ArkUI框架会统一收集过程中产生的组件事件并通过注册的eventReceiver函数回调给开发者。

重复调用时会覆盖前一次注册的函数。

避免直接保存ArkUI_NodeEvent对象指针，数据会在回调结束后销毁。

如果需要和组件实例绑定，可以使用addNodeEventReceiver函数接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventReceiver | 事件回调统一入口函数。  | 


### removeAllChildren

```
int32_t(* ArkUI_NativeNodeAPI_1::removeAllChildren) (ArkUI_NodeHandle parent)
```
**描述：**

从父组件上卸载所有子节点。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 目标节点对象。  | 

**返回：**

0 - 成功。 401 - 函数参数异常。

### unregisterNodeCustomEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeCustomEventReceiver) ()
```
**描述：**

反注册自定义节点事件回调统一入口函数。


### unregisterNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEventReceiver) ()
```
**描述：**

反注册事件回调统一入口函数。


### removeChild

```
int32_t(* ArkUI_NativeNodeAPI_1::removeChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**描述：**

将组件从父节点中移除。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parent | 父节点指针。  | 
| child | 子节点指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### removeNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**描述：**

在组件上删除注册的自定义事件回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于删除组件自定义事件回调函数的对象。  | 
| eventReceiver | 待删除的组件自定义事件回调函数。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### removeNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**描述：**

在组件上删除注册的组件事件回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于删除组件事件回调函数的对象。  | 
| eventReceiver | 待删除的组件事件回调函数。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### resetAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::resetAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**描述：**

重置属性函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要重置属性的节点对象。  | 
| attribute | 需要重置的属性类型。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode)系统中未找到Native接口的动态实现库。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### setAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::setAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem *item)
```
**描述：**

属性设置函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要设置属性的节点对象。  | 
| attribute | 需要设置的属性类型。  | 
| item | 需要设置的属性值。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。 [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode)系统中未找到Native接口的动态实现库。 [ARKUI_ERROR_CODE_NOT_SUPPORTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode)禁止对BuilderNode生成的节点， 进行设置属性、重置属性、设置事件与新增或修改子节点操作。


### setLayoutPosition

```
int32_t(* ArkUI_NativeNodeAPI_1::setLayoutPosition) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**描述：**

在布局回调函数中设置组件的位置。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 
| positionX | x轴坐标。  | 
| positionY | y轴坐标。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### setLengthMetricUnit

```
int32_t(* ArkUI_NativeNodeAPI_1::setLengthMetricUnit) (ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)
```
**描述：**

指定组件的单位。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于指定单位的组件。  | 
| unit | 单位类型[ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit)，默认为 ARKUI_LENGTH_METRIC_UNIT_DEFAULT。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### setMeasuredSize

```
int32_t(* ArkUI_NativeNodeAPI_1::setMeasuredSize) (ArkUI_NodeHandle node, int32_t width, int32_t height)
```
**描述：**

在测算回调函数中设置组件的测算完成后的宽和高。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 目标节点对象。  | 
| width | 设置的宽。  | 
| height | 设置的高。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### setUserData

```
int32_t(* ArkUI_NativeNodeAPI_1::setUserData) (ArkUI_NodeHandle node, void *userData)
```
**描述：**

在组件上保存自定义数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 用于保存自定义数据的组件。  | 
| userData | 要保存的自定义数据。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### unregisterNodeCustomEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)
```
**描述：**

反注册自定义节点事件函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要反注册事件的节点对象。  | 
| eventType | 需要反注册的事件类型。  | 


### unregisterNodeEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)
```
**描述：**

反注册节点事件函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| node | 需要反注册事件的节点对象。  | 
| eventType | 需要反注册的事件类型。  | 


### version

```
int32_t ArkUI_NativeNodeAPI_1::version
```
**描述：**

结构体版本。
