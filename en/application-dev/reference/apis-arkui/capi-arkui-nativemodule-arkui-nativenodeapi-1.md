# ArkUI_NativeNodeAPI_1
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## Overview

Provides a collection of native-side Node type APIs provided by ArkUI. APIs related to the Node module must be called on the main thread.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_node.h](capi-native-node-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t version | Struct version.|


### Member Functions

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle (\*createNode)(ArkUI_NodeType type)](#createnode) | Creates a component based on [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) and returns the pointer to the component object.|
| [void (\*disposeNode)(ArkUI_NodeHandle node)](#disposenode) | Disposes the component to which the specified pointer points.|
| [int32_t (\*addChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)](#addchild) | Attaches a component to a parent node.|
| [int32_t (\*removeChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)](#removechild) | Removes a component from its parent node.|
| [int32_t (\*insertChildAfter)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)](#insertchildafter) | Attaches a component to a parent node, with the position after the **sibling** node.|
| [int32_t (\*insertChildBefore)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)](#insertchildbefore) | Attaches a component to a parent node, with the position before the **sibling** node.|
| [int32_t (\*insertChildAt)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)](#insertchildat) | Attaches a component to a parent node, with the position specified by **position**.|
| [int32_t (\*setAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem* item)](#setattribute) | Sets component attributes.|
| [const ArkUI_AttributeItem* (\*getAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)](#getattribute) | Obtains component attributes. The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to free the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.|
| [int32_t (\*resetAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)](#resetattribute) | Resets component attributes.|
| [int32_t (\*registerNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void* userData)](#registernodeevent) | Registers an event for the specified node.|
| [void (\*unregisterNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)](#unregisternodeevent) | Unregisters an event for the specified node.|
| [void (\*registerNodeEventReceiver)(void (\*eventReceiver)(ArkUI_NodeEvent* event))](#registernodeeventreceiver) | Registers a unified entry point for event callbacks. The ArkUI framework collects component events generated during processing and returns them through the registered **eventReceiver** API.<br> Repeated calls will override the previously registered API. Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeEventReceiver** function.<br>|
| [void (\*unregisterNodeEventReceiver)()](#unregisternodeeventreceiver) | Unregisters the unified entry point for event callbacks.|
| [void (\*markDirty)(ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)](#markdirty) | Forces a node to be marked for re-measurement, layout, or drawing. Regarding updates to system attributes, the ArkUI framework automatically marks dirty areas and re-executes measurement, layout, or drawing; you do not need to call this API actively.|
| [uint32_t (\*getTotalChildCount)(ArkUI_NodeHandle node)](#gettotalchildcount) | Obtains the number of child nodes.|
| [ArkUI_NodeHandle (\*getChildAt)(ArkUI_NodeHandle node, int32_t position)](#getchildat) | Obtains a child node.|
| [ArkUI_NodeHandle (\*getFirstChild)(ArkUI_NodeHandle node)](#getfirstchild) | Obtains the first child node.|
| [ArkUI_NodeHandle (\*getLastChild)(ArkUI_NodeHandle node)](#getlastchild) | Obtains the last child node.|
| [ArkUI_NodeHandle (\*getPreviousSibling)(ArkUI_NodeHandle node)](#getprevioussibling) | Obtains the previous sibling node.|
| [ArkUI_NodeHandle (\*getNextSibling)(ArkUI_NodeHandle node)](#getnextsibling) | Obtains the next sibling node.|
| [int32_t (\*registerNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void* userData)](#registernodecustomevent) | Registers a custom event for a node. Triggered events are returned through the custom event entry point function registered using **registerNodeCustomEventReceiver**.|
| [void (\*unregisterNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)](#unregisternodecustomevent) | Unregisters a custom event for a node.|
| [void (\*registerNodeCustomEventReceiver)(void (\*eventReceiver)(ArkUI_NodeCustomEvent* event))](#registernodecustomeventreceiver) | Registers a unified entry point for custom node event callbacks. The ArkUI framework collects custom component events generated during processing and returns them through the custom event entry point function registered using **registerNodeCustomEventReceiver**.<br> Repeated calls will override the previously registered API.<br> Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeCustomEventReceiver** function.<br>|
| [void (\*unregisterNodeCustomEventReceiver)()](#unregisternodecustomeventreceiver) | Unregisters the unified entry point function for custom node event callbacks.|
| [int32_t (\*setMeasuredSize)(ArkUI_NodeHandle node, int32_t width, int32_t height)](#setmeasuredsize) | Sets the width and height for a component after the measurement in the measurement callback function.|
| [int32_t (\*setLayoutPosition)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)](#setlayoutposition) | Sets the position of a component in the layout callback function.|
| [ArkUI_IntSize (\*getMeasuredSize)(ArkUI_NodeHandle node)](#getmeasuredsize) | Obtains the width and height of a component after measurement.|
| [ArkUI_IntOffset (\*getLayoutPosition)(ArkUI_NodeHandle node)](#getlayoutposition) | Obtains the position of a component after the layout is complete.|
| [int32_t (\*measureNode)(ArkUI_NodeHandle node, ArkUI_LayoutConstraint* Constraint)](#measurenode) | Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement.|
| [int32_t (\*layoutNode)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)](#layoutnode) | Lays outs a component and specifies the expected position of the component relative to its parent component.|
| [int32_t (\*addNodeEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeEvent* event))](#addnodeeventreceiver) | Adds a component event callback function to a component to receive component events generated by it. Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this API is triggered before the global callback registered by **registerNodeEventReceiver**.<br> Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br>|
| [int32_t (\*removeNodeEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeEvent* event))](#removenodeeventreceiver) | Removes a registered component event callback function from a component.|
| [int32_t (\*addNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeCustomEvent* event))](#addnodecustomeventreceiver) | Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by it. Unlike the global registration function **registerNodeCustomEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this API is triggered before the global callback registered by **registerNodeCustomEventReceiver**.<br> Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.<br>|
| [int32_t (\*removeNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeCustomEvent* event))](#removenodecustomeventreceiver) | Removes a registered custom event callback function from a component.|
| [int32_t (\*setUserData)(ArkUI_NodeHandle node, void* userData)](#setuserdata) | Saves custom data on a component.|
| [void* (\*getUserData)(ArkUI_NodeHandle node)](#getuserdata) | Obtains the custom data stored on a component.|
| [int32_t (\*setLengthMetricUnit)(ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)](#setlengthmetricunit) | Sets the unit of measurement for a component.|
| [ArkUI_NodeHandle (\*getParent)(ArkUI_NodeHandle node)](#getparent) | Obtains the parent node.|
| [int32_t (\*removeAllChildren)(ArkUI_NodeHandle parent)](#removeallchildren) | Removes all child nodes from the parent component.|

## Member Function Description

### createNode()

```
ArkUI_NodeHandle (*createNode)(ArkUI_NodeType type)
```

**Description**


Creates a component based on [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) and returns the pointer to the component object.

**Parameters**

| Name                                                        | Description|
|-------------------------------------------------------------| -- |
| [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) type | Type of the component to create.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the created component. If the component fails to be created, **NULL** is returned.|

### disposeNode()

```
void (*disposeNode)(ArkUI_NodeHandle node)
```

**Description**

Disposes the component to which the specified pointer points.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to a component object.|

### addChild()

```
int32_t (*addChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```

**Description**


Attaches a component to a parent node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|

**Return value**

| Type| Description                                                                                                                                                                                                                                                                                                                                    |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.|

### removeChild()

```
int32_t (*removeChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```

**Description**


Removes a component from its parent node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.<br>             Returns **ERROR_CODE_NATIVE_IMPL_NODE_ADAPTER_EXIST** if the NodeAdapter already exists.|

### insertChildAfter()

```
int32_t (*insertChildAfter)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```

**Description**


Attaches a component to a parent node, with the position after the **sibling** node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) sibling | Pointer to the sibling node after which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.|

### insertChildBefore()

```
int32_t (*insertChildBefore)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```

**Description**


Attaches a component to a parent node, with the position before the **sibling** node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) sibling | Pointer to the sibling node before which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.<br>             Returns **ERROR_CODE_NATIVE_IMPL_NODE_ADAPTER_EXIST** if the NodeAdapter already exists.|

### insertChildAt()

```
int32_t (*insertChildAt)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```

**Description**


Attaches a component to a parent node, with the position specified by **position**.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
| int32_t position | Position to which the target child node is to be inserted. If the value is a negative number or invalid, the node is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.<br>             Returns **ERROR_CODE_NATIVE_IMPL_NODE_ADAPTER_EXIST** if the NodeAdapter already exists.|

### setAttribute()

```
int32_t (*setAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem* item)
```

**Description**


Sets an attribute.

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                   | Node whose attribute needs to be set.|
| [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of attribute to set.|
| const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* item  | Attribute value to set.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the dynamic implementation library of the native API is not found.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.<br>             Returns **ERROR_CODE_NATIVE_IMPL_NODE_ADAPTER_EXIST** if the NodeAdapter already exists.|

### getAttribute()

```
const ArkUI_AttributeItem* (*getAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```

**Description**


Obtains an attribute. The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to free the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                   | Node whose attribute needs to be obtained.|
| [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of the attribute to obtain.|

**Return value**

| Type| Description|
| -- | -- |
| const ArkUI_AttributeItem* | Attribute value. If the operation fails, a null pointer is returned.|

### resetAttribute()

```
int32_t (*resetAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```

**Description**


Resets an attribute.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node whose attribute needs to be reset.|
|  [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of the attribute to reset.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the dynamic implementation library of the native API is not found.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.|

### registerNodeEvent()

```
int32_t (*registerNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void* userData)
```

**Description**


Registers an event for the specified node.

**Parameters**

| Name                                                                       | Description                                                                                     |
|----------------------------------------------------------------------------|-----------------------------------------------------------------------------------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node           | Target node.                                                                           |
| [ArkUI_NodeEventType](capi-native-node-h.md#arkui_nodeeventtype) eventType | Type of the event to register.                                                                             |
| int32_t targetId                                                           | Custom event ID, which is passed in the callback of [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) when the event is triggered.|
| void* userData                                                             | Custom event parameter, which is passed in the callback of [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) when the event is triggered.                                   |

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the dynamic implementation library of the native API is not found.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.|

### unregisterNodeEvent()

```
void (*unregisterNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)
```

**Description**


Unregisters an event for the specified node.

**Parameters**

| Name                                                             | Description           |
|------------------------------------------------------------------|---------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_NodeEventType](capi-native-node-h.md#arkui_nodeeventtype) eventType                                | Type of the event to unregister.             |

### registerNodeEventReceiver()

```
void (*registerNodeEventReceiver)(void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Registers a unified entry point for event callbacks. The ArkUI framework collects component events generated during processing and returns them through the registered **eventReceiver** API.<br> Repeated calls will override the previously registered API. Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeEventReceiver** function.<br>

| Name| Description|
|-----|----|
| eventReceiver | Unified entry point for event callbacks to register.  |

### unregisterNodeEventReceiver()

```
void (*unregisterNodeEventReceiver)()
```

**Description**


Unregisters the unified entry point for event callbacks.

### markDirty()

```
void (*markDirty)(ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```

**Description**


Forces a node to be marked for re-measurement, layout, or drawing. Regarding updates to system attributes, the ArkUI framework automatically marks dirty areas and re-executes measurement, layout, or drawing; you do not need to call this API actively.

**Parameters**

| Name                                                                       | Description          |
|----------------------------------------------------------------------------|--------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node           | Node for which you want to mark as dirty area.|
| [ArkUI_NodeDirtyFlag](capi-native-node-h.md#arkui_nodedirtyflag) dirtyFlag | Dirty area type. |

### getTotalChildCount()

```
uint32_t (*getTotalChildCount)(ArkUI_NodeHandle node)
```

**Description**


Obtains the number of child nodes.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Returns the number of child nodes; returns **0** if there is no child node.|

### getChildAt()

```
ArkUI_NodeHandle (*getChildAt)(ArkUI_NodeHandle node, int32_t position)
```

**Description**


Obtains a child node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
|  int32_t position | Position of the child node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getFirstChild()

```
ArkUI_NodeHandle (*getFirstChild)(ArkUI_NodeHandle node)
```

**Description**


Obtains the first child node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getLastChild()

```
ArkUI_NodeHandle (*getLastChild)(ArkUI_NodeHandle node)
```

**Description**


Obtains the last child node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getPreviousSibling()

```
ArkUI_NodeHandle (*getPreviousSibling)(ArkUI_NodeHandle node)
```

**Description**


Obtains the previous sibling node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getNextSibling()

```
ArkUI_NodeHandle (*getNextSibling)(ArkUI_NodeHandle node)
```

**Description**


Obtains the next sibling node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### registerNodeCustomEvent()

```
int32_t (*registerNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void* userData)
```

**Description**


Registers a custom event for a node. When the event is triggered, the value is returned through the entry point function registered by **registerNodeCustomEventReceiver**.

**Parameters**

| Name                                                                                   | Description|
|----------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                       | Target node.|
| [ArkUI_NodeCustomEventType](capi-native-node-h.md#arkui_nodecustomeventtype) eventType | Type of the event to register.|
| int32_t targetId                                                                       | Custom event ID, which is passed in the callback of [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) when the event is triggered.|
| void* userData                                                                         | Custom event parameter, which is passed in the callback of [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) when the event is triggered.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the dynamic implementation library of the native API is not found.|

### unregisterNodeCustomEvent()

```
void (*unregisterNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)
```

**Description**


Unregisters a custom event for a node.

**Parameters**

| Name                                                                                   | Description           |
|----------------------------------------------------------------------------------------|---------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                       | Target node.|
| [ArkUI_NodeCustomEventType](capi-native-node-h.md#arkui_nodecustomeventtype) eventType | Type of the event to unregister.             |

### registerNodeCustomEventReceiver()

```
void (*registerNodeCustomEventReceiver)(void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Registers a unified entry point for custom node event callbacks. The ArkUI framework collects custom component events generated during processing and returns them through the custom event entry point function registered using **registerNodeCustomEventReceiver**.<br> Repeated calls will override the previously registered API.<br> Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeCustomEventReceiver** function.<br>

| Name| Description|
|-----|----|
| eventReceiver  | Unified entry point for event callbacks to register.  |

### unregisterNodeCustomEventReceiver()

```
void (*unregisterNodeCustomEventReceiver)()
```

**Description**


Unregisters the unified entry point function for custom node event callbacks.

### setMeasuredSize()

```
int32_t (*setMeasuredSize)(ArkUI_NodeHandle node, int32_t width, int32_t height)
```

**Description**


Sets the width and height for a component after the measurement in the measurement callback function.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
|  int32_t width | Width to set.|
|  int32_t height | Height to set.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setLayoutPosition()

```
int32_t (*setLayoutPosition)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```

**Description**


Sets the position of a component in the layout callback function. The priority of this API is lower than that of **NODE_POSITION**.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
|  int32_t positionX | X-coordinate.|
|  int32_t positionY | Y-coordinate.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### getMeasuredSize()

```
ArkUI_IntSize (*getMeasuredSize)(ArkUI_NodeHandle node)
```

**Description**


Obtains the width and height of a component after measurement.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type               | Description|
|-------------------| -- |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | Width and height of the component, wrapped in an **ArkUI_IntSize** structure.|

### getLayoutPosition()

```
ArkUI_IntOffset (*getLayoutPosition)(ArkUI_NodeHandle node)
```

**Description**


Obtains the position of a component after the layout is complete.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type                 | Description|
|---------------------| -- |
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | Position of the component, wrapped in an **ArkUI_IntOffset** structure.|

### measureNode()

```
int32_t (*measureNode)(ArkUI_NodeHandle node, ArkUI_LayoutConstraint* Constraint)
```

**Description**


Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement.

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint                           | Size constraint.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### layoutNode()

```
int32_t (*layoutNode)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```

**Description**


Lays outs a component and specifies the expected position of the component relative to its parent component.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
|  int32_t positionX | X-coordinate.|
|  int32_t positionY | Y-coordinate.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### addNodeEventReceiver()

```
int32_t (*addNodeEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Adds a component event callback function to a component to receive component events generated by it. Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this API is triggered before the global callback registered by **registerNodeEventReceiver**.<br> Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br>

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to add the event callback function.|
| eventReceiver                                                    | Event callback for the component.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### removeNodeEventReceiver()

```
int32_t (*removeNodeEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Removes a registered component event callback function from a component.

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to remove the event callback function.|
| eventReceiver                                                    | Component event callback function to remove.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### addNodeCustomEventReceiver()

```
int32_t (*addNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by it. Unlike the global registration function **registerNodeCustomEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this API is triggered before the global callback registered by **registerNodeCustomEventReceiver**.<br> Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.<br>

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to add the custom event callback function.|
| eventReceiver                                                    | Custom event callback for the component.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### removeNodeCustomEventReceiver()

```
int32_t (*removeNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Removes a registered custom event callback function from a component.

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to remove the custom event callback function.|
| eventReceiver                                                    | Custom event callback function to remove.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setUserData()

```
int32_t (*setUserData)(ArkUI_NodeHandle node, void* userData)
```

**Description**


Saves custom data on a component.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component on which the custom data will be saved.|
|  void* userData | Custom data to be saved.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### getUserData()

```
void* (*getUserData)(ArkUI_NodeHandle node)
```

**Description**


Obtains the custom data stored on a component.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target component.|

**Return value**

| Type| Description|
| -- | -- |
| void* | Custom data.|

### setLengthMetricUnit()

```
int32_t (*setLengthMetricUnit)(ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the unit of measurement for a component.

**Parameters**

| Name                                                                        | Description|
|-----------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node            | Component for which you want to set the unit.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit type [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit). The default value is **ARKUI_LENGTH_METRIC_UNIT_DEFAULT**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### getParent()

```
ArkUI_NodeHandle (*getParent)(ArkUI_NodeHandle node)
```

**Description**


Obtains the parent node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### removeAllChildren()

```
int32_t (*removeAllChildren)(ArkUI_NodeHandle parent)
```

**Description**


Removes all child nodes from the parent component.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
