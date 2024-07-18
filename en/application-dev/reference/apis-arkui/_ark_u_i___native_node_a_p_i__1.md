# ArkUI_NativeNodeAPI_1


## Overview

Declares a collection of native node APIs provided by ArkUI.

* The APIs related to the native node must be called in the main thread.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| int32_t [version](#version) | /** Struct version. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [createNode](#createnode) )([ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) type) | Generates the corresponding component based on [ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) and returns the component object pointer. | 
| void(\* [disposeNode](#disposenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Destroys the component to which the specified pointer points. | 
| int32_t(\* [addChild](#addchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | Adds a component to a parent node. | 
| int32_t(\* [removeChild](#removechild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child) | Removes a component from its parent node. | 
| int32_t(\* [insertChildAfter](#insertchildafter) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | Mounts a component to a parent node after the sibling node. | 
| int32_t(\* [insertChildBefore](#insertchildbefore) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) sibling) | Mount the component to a parent node before the sibling node. | 
| int32_t(\* [insertChildAt](#insertchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) parent, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) child, int32_t position) | Mounts a component to a parent node. The mounting position is specified by position. | 
| int32_t(\* [setAttribute](#setattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*item) | Attribute setting function. | 
| const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) \*(\* [getAttribute](#getattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | Attribute obtaining function. | 
| int32_t(\* [resetAttribute](#resetattribute) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeAttributeType](_ark_u_i___native_module.md#arkui_nodeattributetype) attribute) | Resets attributes. | 
| int32_t(\* [registerNodeEvent](#registernodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | Registers the node event function. | 
| void(\* [unregisterNodeEvent](#unregisternodeevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeEventType](_ark_u_i___native_module.md#arkui_nodeeventtype) eventType) | Unregisters an event for the specified node. | 
| void(\* [registerNodeEventReceiver](#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent) \*event)) | Registers an event receiver. | 
|  void(\* [unregisterNodeEventReceiver](#unregisternodeeventreceiver) )() | Unregisters the event receiver. | 
| void(\* [markDirty](#markdirty) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeDirtyFlag](_ark_u_i___native_module.md#arkui_nodedirtyflag) dirtyFlag) | Forcibly marks the current node that needs to be measured, laid out, or rendered again. | 
| uint32_t(\* [getTotalChildCount](#gettotalchildcount) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the number of child nodes. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getChildAt](#getchildat) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t position) | // Obtain the subnode. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getFirstChild](#getfirstchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the first subnode. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getLastChild](#getlastchild) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the last subnode. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getPreviousSibling](#getprevioussibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the previous sibling node. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getNextSibling](#getnextsibling) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the next sibling node. | 
| int32_t(\* [registerNodeCustomEvent](#registernodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | Registers the customized node event function. When an event is triggered, the value is returned through the customized event entry function registered by registerNodeCustomEventReceiver. | 
| void(\* [unregisterNodeCustomEvent](#unregisternodecustomevent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NodeCustomEventType](_ark_u_i___native_module.md#arkui_nodecustomeventtype) eventType) | Deregisters the customized node event function. | 
| void(\* [registerNodeCustomEventReceiver](#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Registers the unified entry function for customized node event callback. | 
|  void(\* unregisterNodeCustomEventReceiver )() | Unregisters the unified entry function for customized node event callback. | 
| int32_t(\* [setMeasuredSize](#setmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t width, int32_t height) | Set the width and height of the component after the calculation is complete in the calculation callback function. | 
| int32_t(\* [setLayoutPosition](#setlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | Set the position of the widget in the layout callback function. | 
| [ArkUI_IntSize](_ark_u_i___int_size.md)(\* [getMeasuredSize](#getmeasuredsize) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the width and height of the PV module after calculation. | 
| [ArkUI_IntOffset](_ark_u_i___int_offset.md)(\* [getLayoutPosition](#getlayoutposition) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the position of the widget after the layout is complete. | 
| int32_t(\* [measureNode](#measurenode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LayoutConstraint](_ark_u_i___native_module.md#arkui_layoutconstraint) \*Constraint) | To calculate the size of a specific component, you can use the getMeasuredSize interface to obtain the calculated size. | 
| int32_t(\* [layoutNode](#layoutnode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t positionX, int32_t positionY) | Layouts a particular component and passes the expected position of the component relative to the parent component. | 
| int32_t(\* [addNodeEventReceiver](#addnodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent) \*event)) | Add a component event callback function to the component to receive component events generated by the component. | 
| int32_t(\* [removeNodeEventReceiver](#removenodeeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent) \*event)) | Deletes the registered component event callback function from the component. | 
| int32_t(\* [addNodeCustomEventReceiver](#addnodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Add a customized event callback function to the widget to receive customized events (such as layout events and drawing events) generated by the widget. | 
| int32_t(\* [removeNodeCustomEventReceiver](#removenodecustomeventreceiver) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](_ark_u_i___native_module.md#arkui_nodecustomevent) \*event)) | Delete the registered customized event callback function from the component. | 
| int32_t(\* [setUserData](#setuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData) | Save user-defined data on the component. | 
| void \*(\* [getUserData](#getuserdata) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the user-defined data saved on the component. | 
| int32_t(\* [setLengthMetricUnit](#setlengthmetricunit) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Specifies the unit of a component. | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle)(\* [getParent](#getparent) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains a parent node. | 


## Member Variable Description


### addChild

```
int32_t(* ArkUI_NativeNodeAPI_1::addChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**Description**

Adds a component to a parent node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### addNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Add a customized event callback function to the widget to receive customized events (such as layout events and drawing events) generated by the widget.

* Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.

* The callback added by this API is triggered before the global callback registered by **registerNodeEventReceiver**.

* Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.

**Parameters**

| Event | Description | 
| -------- | -------- |
| node | This method is used to add the object of the customized event callback function of the widget. | 
| eventReceiver | Customized event callback function of the widget. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### addNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::addNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Add a component event callback function to the component to receive component events generated by the component.

* Unlike the global registration function **registerNodeEventReceiver**, this API allows multiple event receivers to be added to the same component.

* The callback added by this API is triggered before the global callback registered by **registerNodeEventReceiver**.

* Do not directly save the **ArkUI_NodeEvent** object pointer. The data will be destroyed after the callback is complete.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Used to add the object of the widget event callback function. | 
| eventReceiver | Component event callback function. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### createNode

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::createNode) (ArkUI_NodeType type)
```
**Description**

Generates the corresponding component based on [ArkUI_NodeType](_ark_u_i___native_module.md#arkui_nodetype) and returns the component object pointer.

**Parameters**

| Name | Description | 
| -------- | -------- |
| type | This API is used to create a UI component node of a specified type. | 

**Returns**

Returns the pointer to the created component. If the component fails to be created, NULL is returned.


### disposeNode

```
void(* ArkUI_NativeNodeAPI_1::disposeNode) (ArkUI_NodeHandle node)
```
**Description**

Destroys the component to which the specified pointer points.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Component pointer object. | 


### getAttribute

```
const ArkUI_AttributeItem*(* ArkUI_NativeNodeAPI_1::getAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**Description**

Attribute obtaining function.

* The pointer returned by this API is an internal buffer pointer of the ArkUI framework. As such, you do not need to call **delete** to release the memory. However, the pointer must be used before this API is called next time. Otherwise, the pointer may be overwritten by other values.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object whose attributes need to be obtained. | 
| attribute | Type of the attribute to be obtained. | 

**Returns**

Returns the attribute value. If the operation fails, a null pointer is returned.


### getChildAt

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getChildAt) (ArkUI_NodeHandle node, int32_t position)
```
**Description**

// Obtain the subnode.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 
| position | Location of a child component. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getFirstChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getFirstChild) (ArkUI_NodeHandle node)
```
**Description**

Obtains the first subnode.

**Parameters**

| Name | Description of the component. | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getLastChild

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getLastChild) (ArkUI_NodeHandle node)
```
**Description**

Obtains the last subnode.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getLayoutPosition

```
ArkUI_IntOffset(* ArkUI_NativeNodeAPI_1::getLayoutPosition) (ArkUI_NodeHandle node)
```
**Description**

Obtains the position of the widget after the layout is complete.

**Parameters**

| Name | **Description** | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Location of the [ArkUI_IntOffset](_ark_u_i___int_offset.md) component.


### getMeasuredSize

```
ArkUI_IntSize(* ArkUI_NativeNodeAPI_1::getMeasuredSize) (ArkUI_NodeHandle node)
```
**Description**

Obtains the width and height of the PV module after calculation.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Width and height of the [ArkUI_IntSize](_ark_u_i___int_size.md) component.


### getNextSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getNextSibling) (ArkUI_NodeHandle node)
```
**Description**

Obtains the next sibling node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getParent

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getParent) (ArkUI_NodeHandle node)
```
**Description**

Obtains a parent node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getPreviousSibling

```
ArkUI_NodeHandle(* ArkUI_NativeNodeAPI_1::getPreviousSibling) (ArkUI_NodeHandle node)
```
**Description**

Obtains the previous sibling node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the pointer to the subnode if the subnode exists; returns **NULL** otherwise.


### getTotalChildCount

```
uint32_t(* ArkUI_NativeNodeAPI_1::getTotalChildCount) (ArkUI_NodeHandle node)
```
**Description**

Obtains the number of child nodes.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 

**Returns**

Returns the number of subnodes; returns **0** if there is no subnode.


### getUserData

```
void*(* ArkUI_NativeNodeAPI_1::getUserData) (ArkUI_NodeHandle node)
```
**Description**

Obtains the user-defined data saved on the component.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | A component that stores user-defined data. | 

**Returns**

Custom data.


### insertChildAfter

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAfter) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**Description**

Mounts a component to a parent node after the sibling node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| sibling | * @param sibling Indicates the pointer to the sibling node after which the target node is to be inserted. If the value is null, the node is inserted at the start of the parent node. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### insertChildAt

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildAt) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, int32_t position)
```
**Description**

Mounts a component to a parent node. The mounting position is specified by position.

**Parameters**

| Name | Description | 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| postion | * @param position Indicates the position to which the target child node is to be inserted. If the value is a negative number or invalid, the node is inserted at the end of the parent node. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### insertChildBefore

```
int32_t(* ArkUI_NativeNodeAPI_1::insertChildBefore) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child, ArkUI_NodeHandle sibling)
```
**Description**

Mount the component to a parent node before the sibling node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 
| sibling | * @param sibling Indicates the pointer to the sibling node before which the target node is to be inserted. If the value is null, the node is inserted at the end of the parent node. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### layoutNode

```
int32_t(* ArkUI_NativeNodeAPI_1::layoutNode) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**Description**

Layouts a particular component and passes the expected position of the component relative to the parent component.

**Parameters**

| Parameter | Description | 
| -------- | -------- |
| node | Target node object. | 
| positionX | X-coordinate. | 
| positionY | Y-coordinate. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### markDirty

```
void(* ArkUI_NativeNodeAPI_1::markDirty) (ArkUI_NodeHandle node, ArkUI_NodeDirtyFlag dirtyFlag)
```
**Description**

Forcibly marks the current node that needs to be measured, laid out, or rendered again.

* Regarding updates to system attributes, the ArkUI framework automatically marks the dirty area and performs measuring, layout, or rendering again. In this case, you do not need to call this API.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object whose dirty area needs to be marked. | 
| dirtyFlag | Dirty area type. | 


### measureNode

```
int32_t(* ArkUI_NativeNodeAPI_1::measureNode) (ArkUI_NodeHandle node, ArkUI_LayoutConstraint *Constraint)
```
**Description**

To calculate the size of a specific component, you can use the getMeasuredSize interface to obtain the calculated size.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 
| Constraint | Size constraint. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### registerNodeCustomEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType, int32_t targetId, void *userData)
```
**Description**

Registers the customized node event function. When an event is triggered, the value is returned through the customized event entry function registered by registerNodeCustomEventReceiver.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object for which an event needs to be registered. | 
| eventType | Type of the event to be registered. | 
| targetId | Customized event ID, which is carried in the callback parameter ArkUI_NodeCustomEvent when an event is triggered.| 
| userData | Customized event parameter, which is carried in the callback parameter ArkUI_NodeCustomEvent when an event is triggered. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106102 if the dynamic implementation library of the native API was not found.


### registerNodeCustomEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeCustomEventReceiver) (void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Registers the unified entry function for customized node event callback.

* The ArkUI framework collects component events generated during the process and calls back the events through the registered event receiver.

* A new call to this API will overwrite the previously registered event receiver.

* Do not directly save the **ArkUI_NodeCustomEvent** object pointer. The data will be destroyed after the callback is complete.

* TTo bind with a component instance, you can use the **addNodeEventReceiver** function.

**Parameters**

| Name | Description | 
| -------- | -------- |
| eventReceiver | Unified entry function for event callback. | 


### registerNodeEvent

```
int32_t(* ArkUI_NativeNodeAPI_1::registerNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType, int32_t targetId, void *userData)
```
**Description**

Registers the node event function.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object for which an event needs to be registered. | 
| eventType | Type of the event to be registered. | 
| targetId | Customized event ID, which is carried in the callback parameter ArkUI_NodeEvent when an event is triggered.| 
| userData | Customized event parameter, which is carried in the callback parameter ArkUI_NodeEvent when an event is triggered. | 

**Returns**

 0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106102 if the dynamic implementation library of the native API was not found. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes. 



### registerNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::registerNodeEventReceiver) (void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Registers an event receiver.

* The ArkUI framework collects component events generated during the process and calls back the events through the registered event receiver.

* A new call to this API will overwrite the previously registered event receiver.

* Do not directly save the **ArkUI_NodeEvent** object pointer. The data will be destroyed after the callback is complete.

* TTo bind with a component instance, you can use the **addNodeEventReceiver** function.

**Parameters**

| Name | Description | 
| -------- | -------- |
| eventReceiver | Unified entry function for event callback. | 


### unregisterNodeEventReceiver

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEventReceiver) ()
```
**Description**

Unregisters the event receiver. 


### removeChild

```
int32_t(* ArkUI_NativeNodeAPI_1::removeChild) (ArkUI_NodeHandle parent, ArkUI_NodeHandle child)
```
**Description**

Removes a component from its parent node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| parent | Pointer to the parent node. | 
| child | Pointer to the child node. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### removeNodeCustomEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeCustomEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeCustomEvent *event))
```
**Description**

Delete the registered customized event callback function from the component.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | This API is used to delete the object of the customized event callback function of a widget. | 
| eventReceiver | Customized event callback function of the widget to be deleted. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### removeNodeEventReceiver

```
int32_t(* ArkUI_NativeNodeAPI_1::removeNodeEventReceiver) (ArkUI_NodeHandle node, void(*eventReceiver)(ArkUI_NodeEvent *event))
```
**Description**

Deletes the registered component event callback function from the component.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Deletes the object of the widget event callback function. | 
| eventReceiver | Event callback function of the widget to be deleted. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### resetAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::resetAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute)
```
**Description**

Resets attributes.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object whose attributes need to be reset. | 
| attribute | Type of the attribute to be reset. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106102 if the dynamic implementation library of the native API was not found. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### setAttribute

```
int32_t(* ArkUI_NativeNodeAPI_1::setAttribute) (ArkUI_NodeHandle node, ArkUI_NodeAttributeType attribute, const ArkUI_AttributeItem *item)
```
**Description**

Attribute setting function.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object whose attributes need to be set. | 
| attribute | Type of the attribute to be set. | 
| item | Value of the attribute to be set. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs. * Returns 106102 if the dynamic implementation library of the native API was not found. * Returns 106103 if the following operations are not allowed on BuilderNode generated nodes: setting or resetting attributes, setting events, or adding or editing subnodes.


### setLayoutPosition

```
int32_t(* ArkUI_NativeNodeAPI_1::setLayoutPosition) (ArkUI_NodeHandle node, int32_t positionX, int32_t positionY)
```
**Description**

Set the position of the widget in the layout callback function.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Target node object. | 
| positionX | X-coordinate. | 
| positionY | Y-coordinate. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### setLengthMetricUnit

```
int32_t(* ArkUI_NativeNodeAPI_1::setLengthMetricUnit) (ArkUI_NodeHandle node, ArkUI_LengthMetricUnit unit)
```
**Description**

Specifies the unit of a component.

**Parameters**

| Parameter | Description | 
| -------- | -------- |
| node | This parameter specifies the component of a unit. | 
| unit | The unit type is [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit). The default value is ARKUI_LENGTH_METRIC_UNIT_DEFAULT. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### setMeasuredSize

```
int32_t(* ArkUI_NativeNodeAPI_1::setMeasuredSize) (ArkUI_NodeHandle node, int32_t width, int32_t height)
```
**Description**

Set the width and height of the component after the calculation is complete in the calculation callback function.

**Parameters**

| Event | Description | 
| -------- | -------- |
| node | Target node object. | 
| width | Indicates the configured width. | 
| height | Indicates the configured height. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### setUserData

```
int32_t(* ArkUI_NativeNodeAPI_1::setUserData) (ArkUI_NodeHandle node, void *userData)
```
**Description**

Save user-defined data on the component.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | A component used to store user-defined data. | 
| userData | User-defined data to be saved. | 

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### unregisterNodeCustomEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeCustomEvent) (ArkUI_NodeHandle node, ArkUI_NodeCustomEventType eventType)
```
**Description**

Deregisters the customized node event function.

**Parameters**

| Name | **Description** | 
| -------- | -------- |
| node | Node object whose event needs to be deregistered. | 
| eventType | Type of the event to be deregistered. | 


### unregisterNodeEvent

```
void(* ArkUI_NativeNodeAPI_1::unregisterNodeEvent) (ArkUI_NodeHandle node, ArkUI_NodeEventType eventType)
```
**Description**

Unregisters an event for the specified node.

**Parameters**

| Name | Description | 
| -------- | -------- |
| node | Node object whose event needs to be deregistered. | 
| eventType | Type of the event to be deregistered. | 


### version

```
int32_t ArkUI_NativeNodeAPI_1::version
```
**Description**

/** Struct version.
