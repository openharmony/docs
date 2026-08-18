# ArkUI_NativeNodeAPI_1
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_NativeNodeAPI_1
```

## Overview

Provides a collection of native-side Node type APIs provided by ArkUI. APIs related to the Node module must be called on the main thread.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_node.h](capi-native-node-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t version | Structure version, that is, the version number of the **ArkUI_NativeNodeAPI_1** structure. The version number is provided by the system and does not need to be modified.|


### Member Functions

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle (\*createNode)(ArkUI_NodeType type)](#createnode) | Creates a component based on [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) and returns the pointer to the component object.|
| [void (\*disposeNode)(ArkUI_NodeHandle node)](#disposenode) | Disposes of the component to which the specified pointer points.|
| [int32_t (\*addChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)](#addchild) | Attaches a component to a parent node.|
| [int32_t (\*removeChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)](#removechild) | Removes a component from its parent node.|
| [int32_t (\*insertChildAfter)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)](#insertchildafter) | Attaches a component to a parent node, with the position after the **sibling** node.|
| [int32_t (\*insertChildBefore)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)](#insertchildbefore) | Attaches a component to a parent node, with the position before the **sibling** node.|
| [int32_t (\*insertChildAt)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)](#insertchildat) | Attaches a component to a parent node, with the position specified by **position**.|
| [int32_t (\*setAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem* item)](#setattribute) | Sets component attributes.|
| [const ArkUI_AttributeItem* (\*getAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)](#getattribute) | Obtains attributes. The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to free the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.|
| [int32_t (\*resetAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)](#resetattribute) | Resets component attributes.|
| [int32_t (\*registerNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void* userData)](#registernodeevent) | Registers an event for the specified node.|
| [void (\*unregisterNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)](#unregisternodeevent) | Unregisters an event for the specified node.|
| [void (\*registerNodeEventReceiver)(void (\*eventReceiver)(ArkUI_NodeEvent* event))](#registernodeeventreceiver) | Registers a unified entry point for event callbacks. The ArkUI framework collects component events generated during processing and returns them through the registered **eventReceiver** API.<br> Repeated calls will override the previously registered API. Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeEventReceiver** function.<br>|
| [void (\*unregisterNodeEventReceiver)()](#unregisternodeeventreceiver) | Unregisters the unified entry point for event callbacks.|
| [void (\*markDirty)(ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)](#markdirty) | Forcibly marks the current node for re-measurement, re-layout, or re-drawing. Regarding updates to system attributes, the ArkUI framework automatically marks nodes and re-executes measurement, layout, or drawing; you do not need to call this API actively.|
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
| [ArkUI_IntOffset (\*getLayoutPosition)(ArkUI_NodeHandle node)](#getlayoutposition) | Obtains the offset of a node relative to its parent node after component layout is completed. The unit is px. The offset is the result after the parent container lays out the node. Therefore, the **offset** attribute that takes effect after the layout and the **position** attribute that does not participate in the layout do not affect the offset value.|
| [int32_t (\*measureNode)(ArkUI_NodeHandle node, ArkUI_LayoutConstraint* Constraint)](#measurenode) | Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement.|
| [int32_t (\*layoutNode)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)](#layoutnode) | Lays outs a node and specifies the expected position of the node relative to its parent node.|
| [int32_t (\*addNodeEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeEvent* event))](#addnodeeventreceiver) | Adds a component event callback function to a component to receive component events generated by it. Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this function is triggered before the global callback registered by **registerNodeEventReceiver**.<br> Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.<br>|
| [int32_t (\*removeNodeEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeEvent* event))](#removenodeeventreceiver) | Removes a registered component event callback function from a component.|
| [int32_t (\*addNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeCustomEvent* event))](#addnodecustomeventreceiver) | Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by it. Unlike the global registration function **registerNodeCustomEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this function is triggered before the global callback registered by **registerNodeCustomEventReceiver**.<br> Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.<br>|
| [int32_t (\*removeNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (\*eventReceiver)(ArkUI_NodeCustomEvent* event))](#removenodecustomeventreceiver) | Removes a registered custom event callback function from a component.|
| [int32_t (\*setUserData)(ArkUI_NodeHandle node, void* userData)](#setuserdata) | Saves custom data on a component.|
| [void* (\*getUserData)(ArkUI_NodeHandle node)](#getuserdata) | Obtains the custom data stored on a component.|
| [int32_t (\*setLengthMetricUnit)(ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)](#setlengthmetricunit) | Sets the unit of measurement for a component.|
| [ArkUI_NodeHandle (\*getParent)(ArkUI_NodeHandle node)](#getparent) | Obtains the parent node.|
| [int32_t (\*removeAllChildren)(ArkUI_NodeHandle parent)](#removeallchildren) | Removes all child nodes from the parent component.|

## Member Function Description

### createNode()

```c
ArkUI_NodeHandle (*createNode)(ArkUI_NodeType type)
```

**Description**


Creates a component based on [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) and returns the pointer to the component object.

**Since**: 12

**Parameters**

| Name                                                        | Description|
|-------------------------------------------------------------| -- |
| [ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype) type | Type of the component to create.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the created component. If the component fails to be created, **NULL** is returned. You need to manage the lifecycle of the returned component object pointer. Otherwise, issues such as Use After Free may cause process crashes or memory leaks. |

### disposeNode()

```c
void (*disposeNode)(ArkUI_NodeHandle node)
```

**Description**

Disposes of the component to which the specified pointer points. When calling this API on a non-main thread, special attention must be paid to the lifecycle of the component object to be destroyed. Improper lifecycle management may cause the application to crash; therefore, it is not recommended to call this API on non-main threads.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to a component object.|

### addChild()

```c
int32_t (*addChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```

**Description**


Attaches a component to a parent node. This API is used for node operations, and you are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|

**Return value**

| Type| Description                                                                                                                                                                                                                                                                                                                                    |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_NODE_IS_ADOPTED](capi-native-type-h.md#arkui_errorcode) if the node has been adopted as an affiliated node. This specification is supported since API version 22.|

### removeChild()

```c
int32_t (*removeChild)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```

**Description**


Removes a component from its parent node. This API is used for node operations, and you are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_ADAPTER_EXIST](capi-native-type-h.md#arkui_errorcode) if the NodeAdapter already exists.|

### insertChildAfter()

```c
int32_t (*insertChildAfter)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```

**Description**


Attaches a component to a parent node, with the position after the **sibling** node. This API is used for node operations, and you are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) sibling | Pointer to the sibling node after which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_NODE_IS_ADOPTED](capi-native-type-h.md#arkui_errorcode) if the node has been adopted as an affiliated node. This specification is supported since API version 22.|

### insertChildBefore()

```c
int32_t (*insertChildBefore)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```

**Description**


Attaches a component to a parent node, with the position before the **sibling** node. This API is used for node operations, and you are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) sibling | Pointer to the sibling node before which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_NODE_IS_ADOPTED](capi-native-type-h.md#arkui_errorcode) if the node has been adopted as an affiliated node. This specification is supported since API version 22.|

### insertChildAt()

```c
int32_t (*insertChildAt)(ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```

**Description**


Attaches a component to a parent node, with the position specified by **position**. This API is used for node operations, and you are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) parent | Pointer to the parent node.|
|  [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) child | Pointer to the child node.|
| int32_t position | Inserting position. The value range is [-2147483648, 2147483647]. If the value is a negative number or invalid, the component is inserted at the end of the parent node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_NODE_IS_ADOPTED](capi-native-type-h.md#arkui_errorcode) if the node has been adopted as an affiliated node. This specification is supported since API version 22.|

### setAttribute()

```c
int32_t (*setAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem* item)
```

**Description**


Sets attributes. You are advised to call this API in the main thread.

In actual service scenarios, if the attributes set for a component contain the heap memory you apply for, ensure that the component is no longer used before calling the corresponding release API. For example, **NODE_TEXT_CONTENT_WITH_STYLED_STRING** in [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype).

**Since**: 12

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                   | Node whose attribute needs to be set.|
| [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of attribute to set.|
| const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* item  | Attribute value to set.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the attribute is not supported.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.<br>             Returns [ARKUI_ERROR_CODE_ADAPTER_EXIST](capi-native-type-h.md#arkui_errorcode) if the NodeAdapter already exists.|

### getAttribute()

```c
const ArkUI_AttributeItem* (*getAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```

**Description**


Obtains attributes. The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to free the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.

**Since**: 12

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                   | Node whose attribute needs to be obtained.|
| [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of the attribute to obtain.|

**Return value**

| Type| Description|
| -- | -- |
| const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* | Attribute value. If the operation fails, a null pointer is returned.|

### resetAttribute()

```c
int32_t (*resetAttribute)(ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```

**Description**


Resets attributes. You are advised to call this API in the main thread.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node whose attribute needs to be reset.|
|  [ArkUI_NodeAttributeType](capi-native-node-h.md#arkui_nodeattributetype) attribute | Type of the attribute to reset.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the attribute is not supported.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.|

### registerNodeEvent()

```c
int32_t (*registerNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void* userData)
```

**Description**


Registers an event for the specified node.

**Since**: 12

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
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the event is not supported.<br>             Returns [ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the operation is not supported for the node created in ArkTS.|

### unregisterNodeEvent()

```c
void (*unregisterNodeEvent)(ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)
```

**Description**


Unregisters an event for the specified node.

**Since**: 12

**Parameters**

| Name                                                             | Description           |
|------------------------------------------------------------------|---------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_NodeEventType](capi-native-node-h.md#arkui_nodeeventtype) eventType                                | Type of the event to unregister.             |

### registerNodeEventReceiver()

```c
void (*registerNodeEventReceiver)(void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Registers a unified entry point for event callbacks. The ArkUI framework collects component events generated during processing and returns them through the registered **eventReceiver** API.<br> Repeated calls will override the previously registered API. Do not directly save the pointer to the [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) object. The data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the [addNodeEventReceiver](#addnodeeventreceiver) API.<br>

**Since**: 12

**Parameters**

| Name| Description|
|-----|----|
| void (*eventReceiver)([ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)\* event) | Unified entry point for event callbacks to register.  |

### unregisterNodeEventReceiver()

```c
void (*unregisterNodeEventReceiver)()
```

**Description**


Unregisters the unified entry point for event callbacks.

**Since**: 12

### markDirty()

```c
void (*markDirty)(ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```

**Description**


Forcibly marks the current node for re-measurement, re-layout, or re-drawing. Regarding updates to system attributes, the ArkUI framework automatically marks nodes and re-executes measurement, layout, or drawing; you do not need to call this API actively.

**Since**: 12

**Parameters**

| Name                                                                       | Description          |
|----------------------------------------------------------------------------|--------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node           | Node object that needs to be marked for re-measurement, re-layout, or re-drawing.|
| [ArkUI_NodeDirtyFlag](capi-native-node-h.md#arkui_nodedirtyflag) dirtyFlag | Type for re-measurement, re-layout, or re-drawing. |

### getTotalChildCount()

```c
uint32_t (*getTotalChildCount)(ArkUI_NodeHandle node)
```

**Description**


Obtains the number of child nodes.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Returns the number of child nodes; returns **0** if there is no child node.|

### getChildAt()

```c
ArkUI_NodeHandle (*getChildAt)(ArkUI_NodeHandle node, int32_t position)
```

**Description**


Obtains a child node.

**Since**: 12

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

```c
ArkUI_NodeHandle (*getFirstChild)(ArkUI_NodeHandle node)
```

**Description**


Obtains the first child node.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getLastChild()

```c
ArkUI_NodeHandle (*getLastChild)(ArkUI_NodeHandle node)
```

**Description**


Obtains the last child node.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getPreviousSibling()

```c
ArkUI_NodeHandle (*getPreviousSibling)(ArkUI_NodeHandle node)
```

**Description**


Obtains the previous sibling node.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### getNextSibling()

```c
ArkUI_NodeHandle (*getNextSibling)(ArkUI_NodeHandle node)
```

**Description**


Obtains the next sibling node.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### registerNodeCustomEvent()

```c
int32_t (*registerNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void* userData)
```

**Description**


Registers a custom event for a node. Triggered events are returned through the custom event entry point function registered using **registerNodeCustomEventReceiver**.

**Since**: 12

**Parameters**

| Name                                                                                   | Description|
|----------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                       | Target node.|
| ArkUI_NodeCustomEventType eventType | Type of the event to register.|
| int32_t targetId                                                                       | Custom event ID, which is passed in the callback of [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) when the event is triggered.|
| void* userData                                                                         | Custom event parameter, which is passed in the callback of [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) when the event is triggered.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>             Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) if the event is not supported.|

### unregisterNodeCustomEvent()

```c
void (*unregisterNodeCustomEvent)(ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)
```

**Description**


Unregisters a custom event for a node.

**Since**: 12

**Parameters**

| Name                                                                                   | Description           |
|----------------------------------------------------------------------------------------|---------------|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                       | Target node.|
| ArkUI_NodeCustomEventType eventType | Type of the event to unregister.             |

### registerNodeCustomEventReceiver()

```c
void (*registerNodeCustomEventReceiver)(void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Registers a unified entry point for custom node event callbacks. The ArkUI framework collects custom component events generated during processing and returns them through the custom event entry point function registered using **registerNodeCustomEventReceiver**.<br> Repeated calls will override the previously registered API.<br> Do not directly save the pointer to the [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) object. The data will be destroyed after the callback is complete.<br> To bind with a component instance, you can use the **addNodeCustomEventReceiver** function.<br>

**Since**: 12

**Parameters**

| Name| Description|
|-----|----|
| void (*eventReceiver)([ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md)\* event)  | Unified entry point for event callbacks to register.  |

### unregisterNodeCustomEventReceiver()

```c
void (*unregisterNodeCustomEventReceiver)()
```

**Description**


Unregisters the unified entry point function for custom node event callbacks.

**Since**: 12

### setMeasuredSize()

```c
int32_t (*setMeasuredSize)(ArkUI_NodeHandle node, int32_t width, int32_t height)
```

**Description**


Sets the width and height for a component after the measurement in the measurement callback function.

**Since**: 12

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

```c
int32_t (*setLayoutPosition)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```

**Description**

Sets the position of a component in the layout callback function. This API has a lower priority than [NODE_POSITION](capi-native-node-h-nodeattributetype-layoutattributes.md#node_position) in **ArkUI_NodeAttributeType**.

**Since**: 12

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

```c
ArkUI_IntSize (*getMeasuredSize)(ArkUI_NodeHandle node)
```

**Description**


Obtains the width and height of a component after measurement.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type               | Description|
|-------------------| -- |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | Width and height of the component, wrapped in an **ArkUI_IntSize** structure.|

### getLayoutPosition()

```c
ArkUI_IntOffset (*getLayoutPosition)(ArkUI_NodeHandle node)
```

**Description**

Obtains the offset of a node relative to its parent node after component layout is completed. The unit is px. The offset is the result after the parent container lays out the node. Therefore, the **offset** attribute that takes effect after the layout and the **position** attribute that does not participate in the layout do not affect the offset value.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type                 | Description|
|---------------------| -- |
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | Position of the component, wrapped in an **ArkUI_IntOffset** structure.|

### measureNode()

```c
int32_t (*measureNode)(ArkUI_NodeHandle node, ArkUI_LayoutConstraint* Constraint)
```

**Description**


Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement.

**Since**: 12

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

```c
int32_t (*layoutNode)(ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```

**Description**


Lays outs a node and specifies the expected position of the node relative to its parent node.

**Since**: 12

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

```c
int32_t (*addNodeEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Adds a component event callback function to a component to receive component events generated by it. Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this function is triggered before the global callback registered by **registerNodeEventReceiver**.<br> Do not directly save the pointer to the [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) object. The data will be destroyed after the callback is complete.<br>

**Since**: 12

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to add the event callback function.|
| void (*eventReceiver)([ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)\* event)                    | Event callback for the component.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### removeNodeEventReceiver()

```c
int32_t (*removeNodeEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeEvent* event))
```

**Description**


Removes a registered component event callback function from a component.

**Since**: 12

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to remove the event callback function.|
| void (*eventReceiver)([ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)* event)                    | Component event callback function to remove.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### addNodeCustomEventReceiver()

```c
int32_t (*addNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by it. Unlike the global registration function **registerNodeCustomEventReceiver**, this API allows multiple event receivers to be added to the same component.<br> The callback added by this function is triggered before the global callback registered by **registerNodeCustomEventReceiver**.<br> Do not directly save the pointer to the [ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md) object. The data will be destroyed after the callback is complete.<br>

**Since**: 12

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to add the custom event callback function.|
| void (*eventReceiver)([ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md)\* event)              | Custom event callback for the component.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### removeNodeCustomEventReceiver()

```c
int32_t (*removeNodeCustomEventReceiver)(ArkUI_NodeHandle node, void (*eventReceiver)(ArkUI_NodeCustomEvent* event))
```

**Description**


Removes a registered custom event callback function from a component.

**Since**: 12

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Component for which you want to remove the custom event callback function.|
| void (*eventReceiver)([ArkUI_NodeCustomEvent](capi-arkui-nativemodule-arkui-nodecustomevent.md)\* event)              | Custom event callback function to remove.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setUserData()

```c
int32_t (*setUserData)(ArkUI_NodeHandle node, void* userData)
```

**Description**


Saves custom data on a component.

**Since**: 12

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

```c
void* (*getUserData)(ArkUI_NodeHandle node)
```

**Description**


Obtains the custom data stored on a component.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target component.|

**Return value**

| Type| Description|
| -- | -- |
| void* | Custom data.|

### setLengthMetricUnit()

```c
int32_t (*setLengthMetricUnit)(ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the unit of measurement for a component.

**Since**: 12

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

```c
ArkUI_NodeHandle (*getParent)(ArkUI_NodeHandle node)
```

**Description**


Obtains the parent node.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Pointer to the node, or **NULL** if the node is not found.|

### removeAllChildren()

```c
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
