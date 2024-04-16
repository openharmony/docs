# ArkUI_NativeNodeAPI_1


## 概述

ArkUI提供的Native侧Node类型接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| int32_t [version](#version) | 结构体版本。  |
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [createNode](#createnode) )([ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) type) | 基于[ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype)生成对应的组件并返回组件对象指针。  |
| void(\* [disposeNode](#disposenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 销毁组件指针指向的组件对象。  |
| int32_t(\* [addChild](#addchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | 将组件挂载到某个父节点之下。  |
| int32_t(\* [removeChild](#removechild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | 将组件从父节点中移除。  |
| int32_t(\* [insertChildAfter](#insertchildafter) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | 将组件挂载到某个父节点之下，挂载位置在**sibling**节点之后。  |
| int32_t(\* [insertChildBefore](#insertchildbefore) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | 将组件挂载到某个父节点之下，挂载位置在**sibling**节点之前。  |
| int32_t(\* [insertChildAt](#insertchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, int32_t position) | 将组件挂载到某个父节点之下，挂载位置由**position**指定。  |
| int32_t(\* [setAttribute](#setattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*item) | 属性设置函数。  |
| const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*(\* [getAttribute](#getattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | 属性获取函数。  |
| int32_t(\* [resetAttribute](#resetattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | 重置属性函数。  |
| int32_t(\* [registerNodeEvent](#registernodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType, int32_t eventId) | 注册节点事件函数。  |
| void(\* [unregisterNodeEvent](#unregisternodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType) | 反注册节点事件函数。  |
| void(\* [registerNodeEventReceiver](#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___node_event.md) \*event)) | 注册事件回调统一入口函数。  |
|  void(\* [unregisterNodeEventReceiver](#unregisternodeeventreceiver) )() | 反注册事件回调统一入口函数。  |
| void(\* [markDirty](#markdirty) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeDirtyFlag](_ark_u_i___native_module.md#arkui_nodedirtyflag) dirtyFlag) | 强制标记当前节点需要重新测算，布局或者绘制。  |


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

0：成功。 

401：函数参数异常。


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


### insertChildAfter

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAfter) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置在**sibling**节点之后。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| parent | 父节点指针。  |
| child | 子节点指针。  |
| sibling | 前一个兄弟节点指针，如果为空则插入位置在最前面。  |

**返回：**

0：成功。 

401：函数参数异常。


### insertChildAt

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAt) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置由**position**指定。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| parent | 父节点指针。  |
| child | 子节点指针。  |
| postion | 插入位置，如果插入位置为负数或者不存在，则默认插入位置在最后面。  |

**返回：**

0：成功。 

401：函数参数异常。


### insertChildBefore

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildBefore) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**描述：**

将组件挂载到某个父节点之下，挂载位置在**sibling**节点之前。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| parent | 父节点指针。  |
| child | 子节点指针。  |
| sibling | 后一个兄弟节点指针，如果为空则插入位置在最后面。  |

**返回：**

0：成功。 

401：函数参数异常。


### markDirty

```
void(* ArkUI_NativeNodeAPI_1::markDirty) (ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```
**描述：**

强制标记当前节点需要重新测算，布局或者绘制。

系统属性设置更新场景下ArkUI框架会自动标记藏区并重新执行测算，布局或者绘制，不需要开发者主动调用该函数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 需要标记藏区的节点对象。  |
| dirtyFlag | 藏区类型。  |


### registerNodeEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t eventId)
```
**描述：**

注册节点事件函数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 需要注册事件的节点对象。  |
| eventType | 需要注册的事件类型。  |
| eventId | 自定义事件ID，当事件触发时在回调参数ArkUI_NodeEvent中携带回来。 |

**返回：**

0 - 成功。 401 - 函数参数异常。 106102 - 系统中未找到Native接口的动态实现库。


### registerNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeEventReceiver) (void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**描述：**

注册事件回调统一入口函数。

ArkUI框架会统一收集过程中产生的组件事件并通过注册的eventReceiver函数回调给开发者。

重复调用时会覆盖前一次注册的函数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| eventReceiver | 事件回调统一入口函数。  |


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

0：成功。 

401：函数参数异常。


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

0：成功。 

401：函数参数异常。 

106102：系统中未找到Native接口的动态实现库。


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

0：成功。 

401：函数参数异常。 

106102：系统中未找到Native接口的动态实现库。


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
