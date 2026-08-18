# TreeViewV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangrunsen-->
<!--Designer: @YanSanzo-->
<!--Tester: @ybhou1993-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=d6f5d099fffea3745e278ad02c31f7d59f3420cd translatedAt=2026-08-10T02:22:42.567Z pushedAt=2026-08-10T06:51:38.961Z -->

Defines the **TreeViewV2** component. As a hierarchically displayed list, the tree view is suitable for displaying nested structures. It has parent list items and child list items, and can be expanded or collapsed.

Used in productivity apps, such as the side navigation bar in memos, emails, and galleries.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can more flexibly control the data and state of the tree view through this component, achieving more efficient UI refresh.

> **NOTE**
>
> - This module's APIs can only be used in the stage model.
>
> - If [universal attributes](ts-component-general-attributes.md) and [universal events](ts-component-general-events.md) are set for **TreeViewV2**, the compilation toolchain will generate an additional node **__Common__** and mount the universal attributes or universal events on **__Common__**, rather than directly applying them to **TreeViewV2** itself. This may cause the set universal attributes or universal events to not take effect or behave unexpectedly. Therefore, it is not recommended to set universal attributes and universal events on **TreeViewV2**.

**Since:** 26.0.0

## Modules to Import

```ts
import { TreeViewV2 } from '@kit.ArkUI';
```

## Child Components

Not supported

## TreeViewV2

TreeViewV2({ treeControllerV2: TreeControllerV2 })

Defines a hierarchical list used for displaying tree-structured components.

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Mandatory | Decorator | Description |
| -------- | -------- | -------- | -------- | -------- |
| treeControllerV2 | [TreeControllerV2](#treecontrollerv2) | Yes | @Param | Controller of the tree view node. |

## TreeControllerV2

Defines the controller of the tree view component. This object can be bound to a tree view component to control the node information of the tree. The same controller cannot control multiple tree view components.

### addNode

addNode(nodeParam?: NodeParamV2): TreeControllerV2

Called to add a child node after a node is tapped.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name  | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| nodeParam | [NodeParamV2](#nodeparamv2) | No | Node information, used to specify the attributes of the new node. If this parameter is not passed, a node titled "Add a folder" is added under the currently selected node. |

**Return value** 

| Type                              | Description                 |
| --------------------------------- | -------------------- |
| [TreeControllerV2](#treecontrollerv2) | Controller of the tree view component. |

### removeNode

removeNode(): void

Called to trigger deletion of the node after a node is tapped.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

### modifyNode

modifyNode(): void

Called to trigger modification of the node after a node is tapped, and the node enters the editing state.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

### buildDone

buildDone(): void

Builds a tree view. After all nodes are added, this method must be called to trigger the saving of tree information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

### refreshNode

refreshNode(parentId: number, parentSubTitle: ResourceStr, currentSubtitle: ResourceStr): void

Updates the tree view. This method is called to update the information of the current node.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| parentId | number | Yes | Parent node ID.<br />Value range: greater than or equal to -1. |
| parentSubTitle | [ResourceStr](ts-types.md#resourcestr) | Yes | Subtitle of the parent node. |
| currentSubtitle | [ResourceStr](ts-types.md#resourcestr) | Yes | Subtitle of the current node. |

## NodeParamV2

Defines the node parameter API, which is used to configure the properties of a tree node.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- |---|---|--------------------------------------------------------------------------------------------------------------------------------------------------|
| parentNodeId | number | No | Yes | Parent node ID.<br />Value range: greater than or equal to -1.<br />Default value: **-1**, which is the root node ID. If the value is set to less than -1, the node is invalid and will not be displayed on the tree view. |
| currentNodeId | number | No | Yes | Current child node ID.<br />Value range: greater than or equal to -1.<br />Cannot be the root node ID or null; otherwise, an exception will be thrown. Two identical **currentNodeId** values cannot be set.<br />Default value: **-1** |
| isFolder | boolean | No | Yes | Whether the node is a folder.<br />Default value: **false**<br />The value **true** indicates a folder, and **false** indicates not a folder. |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon.<br/>Default value: empty string. |
| symbolIconStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon style. The display priority is higher than that of **icon**. If both **symbolIconStyle** and icon are set, only the symbol icon is displayed.<br/>Default value: **undefined**, indicating that the symbol icon is not displayed. |
| selectedIcon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Selected icon.<br/>Default value: empty string. |
| symbolSelectedIconStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol selected icon style. The priority is higher than that of **selectedIcon**.<br/>Default value: **undefined**, indicating that the selected state displays the same as the unselected state. |
| editIcon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Edit icon.<br/>Default value: empty string. |
| symbolEditIconStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol edit icon style. The priority is higher than that of **editIcon**.<br/>Default value: **undefined**, indicating that the editing state displays the same as the non-editing state. |
| primaryTitle | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Primary title.<br/>Default value: empty string. |
| secondaryTitle | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Secondary title.<br/>Default value: empty string. |
| container | [OnContainerCallback](#oncontainercallback) | No | Yes | Right-click child component bound to the node. The child component is decorated by **@Builder**.<br/>Default value: **() =&gt; void** |

## TreeListenerManagerV2

Defines a listener manager for the tree view component. You can bind this object to a tree view component and then manage changes to tree view listeners through it. The same listener manager cannot control multiple tree view components.

### getInstance

static getInstance(): TreeListenerManagerV2

Obtains the singleton object of the tree view component listener manager.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Return value**

| Type              | Description               |
| --------------- |------------------|
| [TreeListenerManagerV2](#treelistenermanagerv2) | Singleton object of the tree view component listener manager. |

### getTreeListener

getTreeListener(): TreeListenerV2

Obtains a tree view listener instance.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Return value**

| Type           | Description         |
| ------------ |------------|
| [TreeListenerV2](#treelistenerv2) | Tree view listener instance obtained. |

## TreeListenerV2

Defines a listener for the tree view component. You can bind this object to a tree view component and then listen for node changes in the tree view through it. The same tree view listener cannot control multiple tree view components.

### onNodeClick

onNodeClick(callback: OnChangedCallback): void

Registers a node click event listener to continuously listen for node click events. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback invoked when a node is clicked. |

### onceNodeClick

onceNodeClick(callback: OnChangedCallback): void

Registers a node click event listener, which is automatically destroyed after being triggered once. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node click event. |

### offNodeClick

offNodeClick(callback?: OnChangedCallback): void

Unregisters the node click event listener. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | No | Callback for the node click event. If passed, cancels the corresponding listener; otherwise, cancels all node click listeners. |

### onNodeAdd

onNodeAdd(callback: OnChangedCallback): void

Registers a listener for the node add event, which continuously listens for node add events. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node add event. |

### onceNodeAdd

onceNodeAdd(callback: OnChangedCallback): void

Registers a node add event listener, which is automatically destroyed after being triggered once. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node add event. |

### offNodeAdd

offNodeAdd(callback?: OnChangedCallback): void

Unregisters the node add event listener. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | No | Callback for the node add event. When passed, cancels the corresponding listener; otherwise, cancels all node add listeners. |

### onNodeDelete

onNodeDelete(callback: OnChangedCallback): void

Registers a listener for node deletion events, continuously listening for node deletion events. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback invoked when a node is deleted. |

### onceNodeDelete

onceNodeDelete(callback: OnChangedCallback): void

Registers a node deletion event listener. The listener is automatically destroyed after being triggered once. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback invoked when a node is deleted. |

### offNodeDelete

offNodeDelete(callback?: OnChangedCallback): void

Unregisters from the node deletion event. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name  | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | No | Callback for the node deletion event. If this parameter is passed in, the corresponding listener is canceled; otherwise, all node deletion listeners are canceled. |

### onNodeModify

onNodeModify(callback: OnChangedCallback): void

Registers a node modification event listener to continuously listen for node modification events. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node modification event. |

### onceNodeModify

onceNodeModify(callback: OnChangedCallback): void

Registers a node modification event listener, which is automatically destroyed after being triggered once. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback invoked when a node is modified. |

### offNodeModify

offNodeModify(callback?: OnChangedCallback): void

Cancels the node modification event listener. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | No | Callback for the node modification event. When passed, cancels the corresponding listener; otherwise, cancels all node modification listeners. |

### onNodeMove

onNodeMove(callback: OnChangedCallback): void

Registers a node move event listener to continuously listen for node move events. Node move is triggered by drag operations. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node move event. |

### onceNodeMove

onceNodeMove(callback: OnChangedCallback): void

Registers a node move event listener, which is auto-destroyed after one trigger. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | Yes | Callback for the node move event. |

### offNodeMove

offNodeMove(callback?: OnChangedCallback): void

Cancels the node move event listener. This API uses a callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | [OnChangedCallback](#onchangedcallback) | No | Node move callback function. If passed, cancels the corresponding listener; otherwise, cancels all node move listeners. |

## OnChangedCallback

type OnChangedCallback = (callbackParam: CallbackParamV2) => void

Defines the node event callback function.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type      | Mandatory | Description                                            |
| :------ |:--------| :- | :-------------------------------------------------- |
| callbackParam | [CallbackParamV2](#callbackparamv2) | Yes  | Node callback parameter, used to pass the parameter information of the node event callback. |

## CallbackParamV2

Defines the node callback parameter API, used to pass parameter information of node event callbacks.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- |---|---|------------------------------------------|
| currentNodeId | number | No | No | Current child node ID.<br />Value range: greater than or equal to 0. |
| parentNodeId | number | No | Yes | Current parent node ID.<br />Value range: greater than or equal to -1.<br />Default value: **-1** |
| childIndex | number | No | Yes | Child index.<br />Value range: greater than or equal to -1.<br />Default value: **-1**<br />This parameter is valid only in node move events, indicating the position index after the move. |

## OnContainerCallback

type OnContainerCallback = () => void

Defines a container callback function type, which is used to define child component callbacks bound to tree nodes.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

## Events

The [universal events](ts-component-general-events.md) are not supported.

## Examples

### Example 1: Configuring a Tree View

Since API version 26.0.0, the following example supports adding, deleting, and renaming nodes in a tree view through the controller API of the tree view component.

```ts
import {
  TreeControllerV2,
  TreeListenerV2,
  TreeListenerManagerV2,
  NodeParamV2,
  TreeViewV2,
  CallbackParamV2
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct TreeViewV2Demo {
  // Create a tree view controller.
  private treeControllerV2: TreeControllerV2 = new TreeControllerV2();
  // Create a tree view listener.
  private treeListenerV2: TreeListenerV2 = TreeListenerManagerV2.getInstance().getTreeListener();
  // Record the ID of the currently clicked node.
  @Local clickNodeId: number = 0;

  // Cancel all listeners when the component is destroyed.
  aboutToDisappear(): void {
    this.treeListenerV2.offNodeClick();
    this.treeListenerV2.offNodeAdd();
    this.treeListenerV2.offNodeDelete();
    this.treeListenerV2.offNodeModify();
    this.treeListenerV2.offNodeMove();
  }

  // When the component is initialized, register listeners and build the tree structure.
  aboutToAppear(): void {
    // Register the node click listener.
    this.treeListenerV2.onNodeClick((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node add listener.
    this.treeListenerV2.onNodeAdd((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node delete listener.
    this.treeListenerV2.onNodeDelete((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node move listener.
    this.treeListenerV2.onceNodeMove((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
      console.info(`Node moved to index: ${callbackParam.childIndex}`);
    })

    let normalResource: Resource = $r('sys.media.ohos_ic_normal_white_grid_folder');
    let selectedResource: Resource = $r('sys.media.ohos_ic_public_select_all');
    let editResource: Resource = $r('sys.media.ohos_ic_public_edit');

    let nodeParam: NodeParamV2 = {
      parentNodeId: -1,
      currentNodeId: 1,
      isFolder: true,
      icon: normalResource,
      selectedIcon: selectedResource,
      editIcon: editResource,
      primaryTitle: 'Directory 1',
      secondaryTitle: '6'
    };

    // Build the tree structure.
    this.treeControllerV2
      .addNode(nodeParam)
      .addNode({
        parentNodeId: 1,
        currentNodeId: 2,
        isFolder: false,
        primaryTitle: 'Item 1_1'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 7,
        isFolder: true,
        primaryTitle: 'Directory 2'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 23,
        isFolder: true,
        icon: normalResource,
        selectedIcon: selectedResource,
        editIcon: editResource,
        primaryTitle: 'Directory 3'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 24,
        isFolder: false,
        primaryTitle: 'Item 4'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 31,
        isFolder: true,
        icon: normalResource,
        selectedIcon: selectedResource,
        editIcon: editResource,
        primaryTitle: 'Directory 5',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 32,
        isFolder: true,
        icon: normalResource,
        selectedIcon: selectedResource,
        editIcon: editResource,
        primaryTitle: 'Directory 6',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: 32,
        currentNodeId: 35,
        isFolder: true,
        icon: normalResource,
        selectedIcon: selectedResource,
        editIcon: editResource,
        primaryTitle: 'Directory 6-1',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 33,
        isFolder: true,
        icon: normalResource,
        selectedIcon: selectedResource,
        editIcon: editResource,
        primaryTitle: 'Directory 7',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: 33,
        currentNodeId: 34,
        isFolder: false,
        primaryTitle: 'Item 8'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 36,
        isFolder: false,
        primaryTitle: 'Item 9'
      })
      .buildDone();

    this.treeControllerV2.refreshNode(-1, 'Parent node', 'Child node');
  }

  build(): void {
    Column() {
      SideBarContainer(SideBarContainerType.Embed) {
        // Tree view component.
        TreeViewV2({ treeControllerV2: this.treeControllerV2 })
        Row() {
          Divider().vertical(true).strokeWidth(2).color(0x000000).lineCap(LineCapStyle.Round)
          Column({ space: 30 }) {
            Text('ClickNodeId=' + this.clickNodeId).fontSize('16fp')
            Button('Add', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(90)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.addNode();
              })
            Button('Modify', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(90)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.modifyNode();
              })
            Button('Remove', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(120)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.removeNode();
              })
          }.height('100%').width('70%').alignItems(HorizontalAlign.Start).margin(10)
        }
      }
      .focusable(true)
      .showControlButton(false)
      .showSideBar(true)
    }
  }
}
```

![Example 1](figures/image-treeviewv2-demo-01.png)

### Example 2: Setting a Symbol Icon

Since API version 26.0.0, the following example demonstrates how to customize symbol icons in the tree view by setting the attribute APIs such as **symbolIconStyle**, **symbolEditIconStyle**, and **symbolSelectedIconStyle** of [NodeParamV2](#nodeparamv2).

```ts
import {
  TreeControllerV2,
  TreeListenerV2,
  TreeListenerManagerV2,
  NodeParamV2,
  TreeViewV2,
  CallbackParamV2,
  SymbolGlyphModifier
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct TreeViewV2Demo {
  // Create a tree view controller.
  private treeControllerV2: TreeControllerV2 = new TreeControllerV2();
  // Create a tree view listener.
  private treeListenerV2: TreeListenerV2 = TreeListenerManagerV2.getInstance().getTreeListener();
  // Record the ID of the currently clicked node.
  @Local clickNodeId: number = 0;

  // Cancel all listeners when the component is destroyed.
  aboutToDisappear(): void {
    this.treeListenerV2.offNodeClick();
    this.treeListenerV2.offNodeAdd();
    this.treeListenerV2.offNodeDelete();
    this.treeListenerV2.offNodeModify();
    this.treeListenerV2.offNodeMove();
  }

  // Register listeners and build the tree structure when the component is initialized.
  aboutToAppear(): void {
    // Register the node click listener.
    this.treeListenerV2.onNodeClick((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node add listener.
    this.treeListenerV2.onNodeAdd((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node deletion listener.
    this.treeListenerV2.onNodeDelete((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
    })
    // Register the node move listener.
    this.treeListenerV2.onceNodeMove((callbackParam: CallbackParamV2) => {
      this.clickNodeId = callbackParam.currentNodeId;
      console.info(`Node moved to parent: ${callbackParam.parentNodeId}, index: ${callbackParam.childIndex}`);
    })

    let normalResource: Resource = $r('sys.symbol.house');
    let selectedResource: Resource = $r('sys.symbol.car');
    let editResource: Resource = $r('sys.symbol.calendar');

    let normalSymbolResource: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.bell'))
      .fontColor([Color.Red]);
    let selectedSymbolResource: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.heart'))
      .fontColor([Color.Blue]);
    let editSymbolResource: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.cake'))
      .fontColor([Color.Pink]);

    let nodeParam: NodeParamV2 = {
      parentNodeId: -1,
      currentNodeId: 1,
      isFolder: true,
      icon: normalResource,
      selectedIcon: selectedResource,
      editIcon: editResource,
      primaryTitle: 'Directory 1',
      secondaryTitle: '6'
    };

    // Build the tree structure.
    this.treeControllerV2
      .addNode(nodeParam)
      .addNode({
        parentNodeId: 1,
        currentNodeId: 2,
        isFolder: false,
        primaryTitle: 'Item 1_1'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 7,
        isFolder: true,
        primaryTitle: 'Directory 2'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 23,
        isFolder: true,
        icon: normalResource,
        symbolIconStyle: normalSymbolResource,
        selectedIcon: selectedResource,
        symbolSelectedIconStyle: selectedSymbolResource,
        editIcon: editResource,
        symbolEditIconStyle: editSymbolResource,
        primaryTitle: 'Directory 3'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 24,
        isFolder: false,
        primaryTitle: 'Item 4'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 31,
        isFolder: true,
        icon: normalResource,
        symbolIconStyle: normalSymbolResource,
        selectedIcon: selectedResource,
        symbolSelectedIconStyle: selectedSymbolResource,
        editIcon: editResource,
        symbolEditIconStyle: editSymbolResource,
        primaryTitle: 'Directory 5',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 32,
        isFolder: true,
        icon: normalResource,
        symbolIconStyle: normalSymbolResource,
        selectedIcon: selectedResource,
        symbolSelectedIconStyle: selectedSymbolResource,
        editIcon: editResource,
        symbolEditIconStyle: editSymbolResource,
        primaryTitle: 'Directory 6',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: 32,
        currentNodeId: 35,
        isFolder: true,
        icon: normalResource,
        symbolIconStyle: normalSymbolResource,
        selectedIcon: selectedResource,
        symbolSelectedIconStyle: selectedSymbolResource,
        editIcon: editResource,
        symbolEditIconStyle: editSymbolResource,
        primaryTitle: 'Directory 6-1',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 33,
        isFolder: true,
        icon: normalResource,
        symbolIconStyle: normalSymbolResource,
        selectedIcon: selectedResource,
        symbolSelectedIconStyle: selectedSymbolResource,
        editIcon: editResource,
        symbolEditIconStyle: editSymbolResource,
        primaryTitle: 'Directory 7',
        secondaryTitle: '0'
      })
      .addNode({
        parentNodeId: 33,
        currentNodeId: 34,
        isFolder: false,
        primaryTitle: 'Item 8'
      })
      .addNode({
        parentNodeId: -1,
        currentNodeId: 36,
        isFolder: false,
        primaryTitle: 'Item 9'
      })
      .buildDone();

    this.treeControllerV2.refreshNode(-1, 'Parent node', 'child node');
  }

  build(): void {
    Column() {
      SideBarContainer(SideBarContainerType.Embed) {
        // Tree view component
        TreeViewV2({ treeControllerV2: this.treeControllerV2 })
        Row() {
          Divider().vertical(true).strokeWidth(2).color(0x000000).lineCap(LineCapStyle.Round)
          Column({ space: 30 }) {
            Text('ClickNodeId=' + this.clickNodeId).fontSize('16fp')
            Button('Add', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(90)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.addNode();
              })
            Button('Modify', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(90)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.modifyNode();
              })
            Button('Remove', { type: ButtonType.Normal, stateEffect: true })
              .borderRadius(8).backgroundColor(0x317aff).width(120)
              .onClick((event: ClickEvent) => {
                this.treeControllerV2.removeNode();
              })
          }.height('100%').width('80%').alignItems(HorizontalAlign.Start).margin(10)
        }
      }
      .focusable(true)
      .showControlButton(false)
      .showSideBar(true)
    }
  }
}
```

![Example 2](figures/image-treeviewv2-demo-02.png)
<!--no_check-->