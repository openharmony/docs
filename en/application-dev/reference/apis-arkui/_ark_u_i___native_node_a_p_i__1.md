# ArkUI_NativeNodeAPI_1


## Overview

Defines a struct for node APIs of ArkUI on the native side.

The APIs related to the native node must be called in the main thread.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [version](#version) | Specifies the struct version. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [createNode](#createnode) )([ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) type) | Creates a component based on [ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) and returns the pointer to the component object. | 
| void(\* [disposeNode](#disposenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Disposes of the component to which the specified pointer points. | 
| int32_t(\* [addChild](#addchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | Adds a component to a parent node. | 
| int32_t(\* [removeChild](#removechild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | Removes a component from its parent node. | 
| int32_t(\* [insertChildAfter](#insertchildafter) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | Mounts this component to a parent node, with the mount position after the specified sibling node. | 
| int32_t(\* [insertChildBefore](#insertchildbefore) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | Mounts this component to a parent node, with the mount position before the specified sibling node. | 
| int32_t(\* [insertChildAt](#insertchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, int32_t position) | Mounts this component to a parent node, with the mount position specified by **position**. | 
| int32_t(\* [setAttribute](#setattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*item) | Sets an attribute. | 
| const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*(\* [getAttribute](#getattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | Obtains an attribute. | 
| int32_t(\* [resetAttribute](#resetattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | Resets an attribute. | 
| int32_t(\* [registerNodeEvent](#registernodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | Registers an event for the specified node. | 
| void(\* [unregisterNodeEvent](#unregisternodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType) | Unregisters an event for the specified node. | 
| void(\* [registerNodeEventReceiver](#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | Registers an event receiver. | 
|  void(\* [unregisterNodeEventReceiver](#unregisternodeeventreceiver) )() | Unregisters this event receiver. | 
| void(\* [markDirty](#markdirty) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeDirtyFlag](_ark_u_i___native_module.md#arkui_nodedirtyflag) dirtyFlag) | Forcibly marks the current node that needs to be measured, laid out, or rendered again. | 
| uint32_t(\* [getTotalChildCount](#gettotalchildcount) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the number of child nodes. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getChildAt](#getchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t position) | Obtains a child node. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getFirstChild](#getfirstchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the first child node. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getLastChild](#getlastchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the last child node. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getPreviousSibling](#getprevioussibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the previous sibling node. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getNextSibling](#getnextsibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the next sibling node. | 
| int32_t(\* [registerNodeCustomEvent](#registernodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | Registers a custom event for a node. When the event is triggered, the value is returned through the entry point function registered by **registerNodeCustomEventReceiver**. | 
| void(\* [unregisterNodeCustomEvent](#unregisternodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType) | Unregisters a custom event for a node. | 
| void(\* [registerNodeCustomEventReceiver](#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Registers a unified entry point function for custom node event callbacks. | 
|  void(\* [unregisterNodeCustomEventReceiver](#unregisternodecustomeventreceiver) )() | Unregisters the unified entry point function for custom node event callbacks. | 
| int32_t(\* [setMeasuredSize](#setmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t width, int32_t height) | Sets the width and height for a component after the measurement. | 
| int32_t(\* [setLayoutPosition](#setlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | Sets the position for a component. | 
| [ArkUI_IntSize](_ark_u_i___int_size.md)(\* [getMeasuredSize](#getmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the width and height of a component after measurement. | 
| [ArkUI_IntOffset](_ark_u_i___int_offset.md)(\* [getLayoutPosition](#getlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the position of a component after the layout is complete. | 
| int32_t(\* [measureNode](#measurenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LayoutConstraint](_ark_u_i___native_module.md#arkui_layoutconstraint) \*Constraint) | Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement. | 
| int32_t(\* [layoutNode](#layoutnode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | Lays outs a component and passes the expected position of the component relative to its parent component. | 
| int32_t(\* [addNodeEventReceiver](#addnodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | Adds a component event callback function to a component to receive component events generated by the component. | 
| int32_t(\* [removeNodeEventReceiver](#removenodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*event)) | Removes the registered component event callback function from a component. | 
| int32_t(\* [addNodeCustomEventReceiver](#addnodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by the component. | 
| int32_t(\* [removeNodeCustomEventReceiver](#removenodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Removes a registered custom event callback function from a component. | 
| int32_t(\* [setUserData](#setuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData) | Saves custom data on the specified component. | 
| void \*(\* [getUserData](#getuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the custom data saved on the specified component. | 
| int32_t(\* [setLengthMetricUnit](#setlengthmetricunit) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Sets the unit for a component. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getParent](#getparent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the parent node. | 
| int32_t(\* [removeAllChildren](#removeallchildren) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent) | Removes all child nodes from the parent component. | 


## Member Variable Description


### addChild

```
int32_t(* ArkUI_NativeNodeAPI_1::addChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**Description**

Adds a component to a parent node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### addNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Adds a custom event callback function to a component to receive custom events (such as layout and drawing events) generated by the component.

Unlike the global registration function **registerNodeCustomEventReceiver**, this API allows multiple event receivers to be added to the same component.

The callback added by this API is triggered before the global callback registered by **registerNodeCustomEventReceiver**.

Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component for which you want to add the custom event callback function. | 
| eventReceiver | Custom event callback for the component. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### addNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Adds a component event callback function to a component to receive component events generated by the component.

Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.

The callback added by this API is triggered before the global callback registered by **registerNodeEventReceiver**.

Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component for which you want to add the event callback function. | 
| eventReceiver | Event callback for the component. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### createNode

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::createNode) (ArkUI_NodeType type)
```
**Description**

Creates a component based on [ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) and returns the pointer to the component object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Type of the component to create. | 

**Returns**

Returns the pointer to the created component. If the component fails to be created, **NULL** is returned.


### disposeNode

```
void(* ArkUI_NativeNodeAPI_1::disposeNode) (ArkUI_NodeHandle node)
```
**Description**

Disposes of the component to which the specified pointer points.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Pointer to a component object. | 


### getAttribute

```
const ArkUI_AttributeItem*(* ArkUI_NativeNodeAPI_1::getAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**Description**

Obtains an attribute.

The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to release the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Node whose attribute needs to be obtained. | 
| attribute | Type of the attribute to obtain. | 

**Returns**

Returns the attribute value. If the operation fails, a null pointer is returned.


### getChildAt

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getChildAt) (ArkUI_NodeHandle node, int32_t position)
```
**Description**

Obtains a child node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| position | Position of the child node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getFirstChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getFirstChild) (ArkUI_NodeHandle node)
```
**Description**

Obtains the first child node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getLastChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getLastChild) (ArkUI_NodeHandle node)
```
**Description**

Obtains the last child node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getLayoutPosition

```
ArkUI_IntOffset(* ArkUI_NativeNodeAPI_1::getLayoutPosition) (ArkUI_NodeHandle node)
```
**Description**

Obtains the position of a component after the layout is complete.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the position of the component, that is, [ArkUI_IntOffset](_ark_u_i___int_offset.md).


### getMeasuredSize

```
ArkUI_IntSize(* ArkUI_NativeNodeAPI_1::getMeasuredSize) (ArkUI_NodeHandle node)
```
**Description**

Obtains the width and height of a component after measurement.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the width and height of the component, that is, [ArkUI_IntSize](_ark_u_i___int_size.md).


### getNextSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getNextSibling) (ArkUI_NodeHandle node)
```
**Description**

Obtains the next sibling node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getParent

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getParent) (ArkUI_NodeHandle node)
```
**Description**

Obtains the parent node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getPreviousSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getPreviousSibling) (ArkUI_NodeHandle node)
```
**Description**

Obtains the previous sibling node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### getTotalChildCount

```
uint32_t(* ArkUI_NativeNodeAPI_1::getTotalChildCount) (ArkUI_NodeHandle node)
```
**Description**

Obtains the number of child nodes.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 

**Returns**

Returns the number of child nodes; returns **0** if there is no child node.


### getUserData

```
void*(* ArkUI_NativeNodeAPI_1::getUserData) (ArkUI_NodeHandle node)
```
**Description**

Obtains the custom data saved on the specified component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target component. | 

**Returns**

Returns the custom data.


### insertChildAfter

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAfter) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**Description**

Mounts this component to a parent node, with the mount position after the specified sibling node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| sibling | Pointer to the sibling node after which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### insertChildAt

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAt) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```
**Description**

Mounts this component to a parent node, with the mount position specified by **position**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| position| Position to which the target child node is to be inserted. If the value is a negative number or invalid, the node is inserted at the end of the parent node. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### insertChildBefore

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildBefore) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**Description**

Mounts this component to a parent node, with the mount position before the specified sibling node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| sibling | Pointer to the sibling node before which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### layoutNode

```
int32_t(* ArkUI_NativeNodeAPI_1::layoutNode) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**Description**

Lays outs a component and passes the expected position of the component relative to its parent component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| positionX | X-coordinate. | 
| positionY | Y-coordinate. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### markDirty

```
void(* ArkUI_NativeNodeAPI_1::markDirty) (ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```
**Description**

Forcibly marks the current node that needs to be measured, laid out, or rendered again.

Regarding updates to system attributes, the ArkUI framework automatically marks the dirty area and performs measuring, layout, or rendering again. In this case, you do not need to call this API.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Node for which you want to mark as dirty area. | 
| dirtyFlag | Dirty area type. | 


### measureNode

```
int32_t(* ArkUI_NativeNodeAPI_1::measureNode) (ArkUI_NodeHandle node, ArkUI_LayoutConstraint *Constraint)
```
**Description**

Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| Constraint | Size constraint. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### registerNodeCustomEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void *userData)
```
**Description**

Registers a custom event for a node. When the event is triggered, the value is returned through the entry point function registered by **registerNodeCustomEventReceiver**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| eventType | Type of the event to register. | 
| targetId | Custom event ID, which is passed in the callback of [ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) when the event is triggered. | 
| userData | Custom event parameter, which is passed in the callback of [ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) when the event is triggered. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode) if the dynamic implementation library of the native API was not found.


### registerNodeCustomEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeCustomEventReceiver) (void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Registers a unified entry point function for custom node event callbacks.

The ArkUI framework collects custom component events generated during the process and calls back the events through the registered <b>registerNodeCustomEventReceiver</b>.

A new call to this API will overwrite the previously registered event receiver.

Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.

To bind with a component instance, you can use the **addNodeCustomEventReceiver** function.

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventReceiver | Event receiver to register. | 


### registerNodeEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void *userData)
```
**Description**

Registers an event for the specified node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| eventType | Type of the event to register. | 
| targetId | Custom event ID, which is passed in the callback of [ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) when the event is triggered. | 
| userData | Custom event parameter, which is passed in the callback of [ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) when the event is triggered. |

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode) if the dynamic implementation library of the native API was not found. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### registerNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeEventReceiver) (void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Registers an event receiver.

The ArkUI framework collects component events generated during the process and calls back the events through the registered event receiver.

A new call to this API will overwrite the previously registered event receiver.

Avoid directly saving pointers to **ArkUI_NodeEvent** objects, as the data will be destroyed after the callback is complete.

To bind with a component instance, you can use the **addNodeEventReceiver** function.

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventReceiver | Event receiver to register. | 


### removeAllChildren

```
int32_t(* ArkUI_NativeNodeAPI_1::removeAllChildren) (ArkUI_NodeHandle parent)
```
**Description**

Removes all child nodes from the parent component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Target node. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.

### unregisterNodeCustomEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeCustomEventReceiver) ()
```
**Description**

Unregisters the unified entry point function for custom node event callbacks.


### unregisterNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEventReceiver) ()
```
**Description**

Unregisters this event receiver.


### removeChild

```
int32_t(* ArkUI_NativeNodeAPI_1::removeChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**Description**

Removes a component from its parent node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### removeNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Removes a registered custom event callback function from a component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component for which you want to remove the custom event callback function. | 
| eventReceiver | Custom event callback function to remove. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### removeNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Removes the registered component event callback function from a component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component for which you want to add the event callback function. | 
| eventReceiver | Event callback function to remove. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### resetAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::resetAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**Description**

Resets an attribute.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Node whose attribute needs to be reset. | 
| attribute | Type of the attribute to reset. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode) if the dynamic implementation library of the native API was not found. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### setAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::setAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem *item)
```
**Description**

Sets an attribute.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Node whose attribute needs to be set. | 
| attribute | Type of the attribute to set. | 
| item | Value of the attribute to be set. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs. Returns [ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](_ark_u_i___native_module.md#arkui_errorcode) if the dynamic implementation library of the native API was not found. Returns [ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE](_ark_u_i___native_module.md#arkui_errorcode) if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing child nodes.


### setLayoutPosition

```
int32_t(* ArkUI_NativeNodeAPI_1::setLayoutPosition) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**Description**

Sets the position for a component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| positionX | X-coordinate. | 
| positionY | Y-coordinate. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setLengthMetricUnit

```
int32_t(* ArkUI_NativeNodeAPI_1::setLengthMetricUnit) (ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the unit for a component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component for which you want to set the unit. | 
| unit | Unit, which is an enumerated value of [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit). The default value is **ARKUI_LENGTH_METRIC_UNIT_DEFAULT**. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setMeasuredSize

```
int32_t(* ArkUI_NativeNodeAPI_1::setMeasuredSize) (ArkUI_NodeHandle node, int32_t width, int32_t height)
```
**Description**

Sets the width and height for a component after the measurement.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| width | Width to set. | 
| height | Height to set. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setUserData

```
int32_t(* ArkUI_NativeNodeAPI_1::setUserData) (ArkUI_NodeHandle node, void *userData)
```
**Description**

Saves custom data on the specified component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Component on which the custom data will be saved. | 
| userData | Custom data to be saved. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### unregisterNodeCustomEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)
```
**Description**

Unregisters a custom event for a node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| eventType | Type of the event to unregister. | 


### unregisterNodeEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)
```
**Description**

Unregisters an event for the specified node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Target node. | 
| eventType | Type of the event to unregister. | 


### version

```
int32_t ArkUI_NativeNodeAPI_1::version
```
**Description**

Specifies the struct version.
