# Parallelizing UI Page Building Using Multi-threaded NDK APIs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @liujiang077-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

In versions earlier than API version 22, UI component creation and attribute setting must be performed in the application's UI thread. This means that when using NDK APIs, you must submit component creation and attribute setting tasks to the UI thread for execution. This limits both the flexibility of component creation and application performance.

As application functionality grows increasingly complex, numerous UI components need to be dynamically created on application pages. Executing all these component creation tasks in a single UI thread leads to slow application startup, animation frame drops, and page freezes, directly impacting user experience.

To address these issues, multi-threaded support has been introduced to NDK APIs starting from API version 22. This enhancement provides the following benefits:

- **Simplified calling process**: You no longer need to switch threads or submit component creation tasks through task queues. Instead, you can directly call APIs for creating components and setting attributes from any thread, reducing thread context switches and simplifying interaction logic between the UI framework and the application.

- **Optimized performance and experience**: Component creation and attribute setting APIs can be called concurrently across multiple threads, fully utilizing the device's multi-core CPU and reducing overall page creation time. The UI thread can then focus on animation rendering and user input, ensuring smooth UI interactions.

- **Enhanced flexibility for future expansion**: The capability to call component creation and attribute setting APIs from multiple threads not only resolves current performance bottlenecks but also provides room for developing more complex and demanding UI pages in the future, allowing for greater design flexibility.

In summary, multi-threaded NDK APIs deliver a high-performance UI page creation experience in complex service scenarios.
  
## Using Multi-threaded NDK APIs

- Before using multi-threaded NDK APIs, it is recommended that you read the [NDK API overview](ndk-build-ui-overview.md) document to master the basic concepts and foundational knowledge required for using NDK APIs.

- To minimize adaptation costs, the method for obtaining and using multi-threaded NDK APIs remains the same as existing NDK APIs. Simply call the [OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface) API with [ARKUI_MULTI_THREAD_NATIVE_NODE](../reference/apis-arkui/capi-native-interface-h.md#arkui_nativeapivariantkind) as the input parameter to obtain the multi-threaded NDK API set. Example:

  ``` cpp
  ArkUI_NativeNodeAPI_1 *multiThreadNodeAPI = nullptr;
  // Obtain the multi-threaded NDK API set.
  OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, multiThreadNodeAPI);

  if (!multiThreadNodeAPI) {
    return;
  }
  // Call the multi-threaded createNode API in the set to create a UI component.
  auto node = multiThreadNodeAPI->createNode(ARKUI_NODE_COLUMN);
  ```

For the complete list of NDK APIs supporting multi-threading, see [Multi-threaded NDK API Set Specifications](#multi-threaded-ndk-api-set-specifications).

You can use the multi-thread NDK API to create a UI component and set its attributes in any thread. However, the UI component must be mounted to the main UI tree in the UI thread. The following APIs can be used to dispatch and execute multi-thread UI component creation tasks.

- For tasks that can be executed in non-UI threads (such as component creation and attribute setting), use the [OH_ArkUI_PostAsyncUITask](https://../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask) API to schedule them to the system thread pool, and then submit the component mounting task to the UI thread for execution.

- When creating UI components in custom non-UI threads, use the [OH_ArkUI_PostUITask](https://../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask) API to submit the component mounting task to the UI thread.
  
- When executing UI-thread-only tasks during multi-threaded UI component creation, use the [OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait) API to submit the task to the UI thread. Note that this API may block the calling thread if the UI thread is heavily loaded, potentially affecting multi-threading performance gains. Use this API sparingly.

## Multi-threaded NDK API Adaptation

1. Multi-threaded NDK APIs are suitable for high-load, performance-sensitive scenarios like page navigation and list scrolling, where UI thread component creation tasks take milliseconds to tens of milliseconds. Split these tasks into subtasks and distribute them across multiple threads for concurrent execution to reduce UI thread load and improve page startup and update smoothness.

2. When creating UI components in your own threads, it is recommended that you limit concurrent threads to no more than four, based on the device's CPU core count, to avoid thread scheduling overhead.

3. Pre-create common component trees in non-UI threads to enhance user experience in performance-sensitive scenarios.

## Multi-threaded NDK API Calling Specifications

UI components are classified into two states: free and attached.

UI components created using the multi-threaded [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API are in the free state by default and can transition between the free and attached states. UI components created using other methods are initially in the attached state and this state is immutable.

> **NOTE**
>
> - You can use multi-threaded NDK APIs to operate free components in any thread. To ensure normal application functions and thread safety, the following usage constraints must be observed:
>   - Do not operate the same free component or component tree in multiple threads at the same time. A free component is lock-free, and stability issues may occur if multiple threads access this component at the same time.
>   - Do not use any NDK APIs other than the APIs from [Multi-threaded NDK API Set Specifications](#multi-threaded-ndk-api-set-specifications) to operate a free component. You must first change the component to the attached state before using NDK APIs in the UI thread. Otherwise, the APIs will function abnormally.
>
> - To balance performance, the framework side does not perform runtime checks for the above constraints; you must ensure compliance.
>
> - To ensure multi-threaded safety of APIs, some attributes of a free component cannot be read immediately by calling [getAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute) after being set by calling [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute). You need to change the component to the attached state before reading the correct attribute values.

The UI component state changes from free to attached after the following operations are performed:

- After the multi-threaded [markDirty](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#markdirty), [measureNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#measurenode), or [layoutNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#layoutnode) API is called to mark, measure, or lay out a free component, all other free components in the same component tree are changed to the attached state.
- After a multi-threaded [component tree operation](#component-tree-operations) API is called to mount a free component as a child component of an attached component, all other free components in the same component tree are changed to the attached state.
- After a multi-threaded API for [operating a component tree](#component-tree-operations) is called to mount an attached component as a child component of a free component, all other free components in the same component tree are changed to the attached state.

The UI component state changes from attached to free after the following operations are performed:

- A component is removed from the component tree by using the multi-threaded [component tree operation](#component-tree-operations) API, and this component tree does not contain any attached component whose state cannot be changed. In this case, all components in the component tree are changed to the free state.

According to the preceding state transition rules, all components in each UI component tree are in the same state.

## Errors and Exceptions of Multi-threaded NDK APIs

For multi-thread NDK API calling specifications, see [Multi-threaded NDK API Set Specifications](#multi-threaded-ndk-api-set-specifications). When calling multi-threaded NDK APIs, you must check the return values. The APIs return the error code [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) in the following situations:

- An API that does not support multi-threaded operations is called in a non-UI thread.

- A multi-threaded NDK API is called in a non-UI thread to operate an attached component.

For common issues during multi-threaded NDK adaptation, see [FAQs About UI Parallelization](multi-thread-ui-build-faq.md).

## Multi-threaded NDK API Set Specifications

The following APIs support multi-threaded calls: [component creation and destruction](#component-creation-and-destruction), [component attribute read/write](#component-attribute-readwrite), [component event registration and deregistration](#component-event-registration-and-deregistration), [component tree operations](#component-tree-operations), and [custom component data read/write](#custom-component-data-readwrite).

The following APIs are UI-thread only: [global event registration and deregistration](#global-event-registration-and-deregistration) and [component measurement and layout](#component-measurement-and-layout).

### Component Creation and Destruction

| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- |  
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) )([ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) type) | Creates a free node based on [ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) and returns the free node object pointer. | Supported| Callable from any thread.|
| void(\* [disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Destroys the node object to which the node pointer points. | Supported| Ineffective if called from a non-UI thread on an attached node.|

### Component Attribute Read/Write

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*item) | Sets node attributes.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*(\* [getAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | Obtains node attributes.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|
| int32_t(\* [resetAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | Resets node attributes to default values. | Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [setLengthMetricUnit](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LengthMetricUnit](../reference/apis-arkui/capi-native-type-h.md#arkui_lengthmetricunit) unit) | Sets the node unit.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|

### Component Event Registration and Deregistration

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| int32_t(\* [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | Registers an event with a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| void(\* [unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType) | Unregisters an event from a node.| Supported| Ineffective if called from a non-UI thread on an attached node.|
| int32_t(\* [registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-node-attributes-custom-attributes-h.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | Registers a custom event with a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| void(\* [unregisterNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-node-attributes-custom-attributes-h.md#arkui_nodecustomeventtype) eventType) | Deregisters a custom event from a node.| Supported| Ineffective if called from a non-UI thread on an attached node.|
| int32_t(\* [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | Registers an event callback function with a node to receive component events generated by the component.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | Removes the event callback function registered on a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [addNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | Registers a custom event callback function with a node to receive custom events (such as layout events and drawing events) generated by the component.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [removeNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | Removes the custom event callback function registered on a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|

### Component Tree Operations

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| int32_t(\* [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | Adds a child node to the child node list of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [removeChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removechild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | Removes a child node from the child node list of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [insertChildAfter](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildafter) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | Inserts a child node after a sibling node in the child node list of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [insertChildBefore](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildbefore) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | Inserts a child node before a sibling node in the child node list of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [insertChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, int32_t position) | Inserts a child node at the specified position in the child node list of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getParent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getparent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the parent node of a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| int32_t(\* [removeAllChildren](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removeallchildren) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent) | Removes all child nodes of a parent node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| uint32_t(\* [getTotalChildCount](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#gettotalchildcount) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the number of child nodes of a node.| Supported| Returns **0** if called from a non-UI thread on an attached node.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t position) | Obtains the pointer to the child node at the specified position.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getFirstChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getfirstchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the pointer to the first child node of a node.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getLastChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlastchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the pointer to the last child node of a node.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getPreviousSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getprevioussibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the pointer to the previous sibling node of a node.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getNextSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getnextsibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the pointer to the next sibling node of a node.| Supported| Returns a null pointer if called from a non-UI thread on an attached node.|

### Custom Component Data Read/Write

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void \*userData) | Sets node data for a node.| Supported| Returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if any attempt is made to operate an attached node from a non-UI thread.|
| void \*(\* [getUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the custom data stored on a node.| Supported|  Returns a null pointer if called from a non-UI thread on an attached node.|

### Global Event Registration and Deregistration

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| void(\* [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | Registers a unified entry point for node event callbacks.| Not supported| UI thread only.|
|  void(\* [unregisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver) )() | Unregisters the unified entry point for node event callbacks.| Not supported| UI thread only.|
| void(\* [registerNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) |  Registers a unified entry point for custom node event callbacks.| Not supported| UI thread only.|
|  void(\* [unregisterNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomeventreceiver) )() |  Unregisters the unified entry point for custom node event callbacks.| Not supported| UI thread only.|

### Component Measurement and Layout

<!--Table: 25%; 35%; 15%; 25%-->
| API| Description| Non-UI Thread| Multi-thread Specifications|
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t width, int32_t height) | Sets the width and height for a component after the measurement in the measurement callback function.| Not supported| Applies to UI threads only, and returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if called from a non-UI thread.|
| int32_t(\* [setLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | Sets the position of a component in the layout callback function.| Not supported| Applies to UI threads only, and returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if called from a non-UI thread.|
| [ArkUI_IntSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intsize.md)(\* [getMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the width and height of a node after measurement.| Not supported| UI thread only. Returns the default value if called from a non-UI thread.|
| [ArkUI_IntOffset](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intoffset.md)(\* [getLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | Obtains the position of a node after the layout is complete.| Not supported| UI thread only. Returns the default value if called from a non-UI thread.|
| int32_t(\* [measureNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#measurenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LayoutConstraint](../reference/apis-arkui/capi-arkui-nativemodule-arkui-layoutconstraint.md) \*Constraint) | Measures a node. You can use the **getMeasuredSize** API to obtain the size after the measurement. The state of all free nodes in the component tree where the node is located is changed to attached.| Not supported| Applies to UI threads only, and returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if called from a non-UI thread.|
| int32_t(\* [layoutNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#layoutnode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | Lays out a node and specifies the expected position of the node relative to its parent. The state of all free nodes in the component tree where the node is located is changed to attached.| Not supported| Applies to UI threads only, and returns [ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if called from a non-UI thread.|
| void(\* [markDirty](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#markdirty) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeDirtyFlag](../reference/apis-arkui/capi-native-node-h.md#arkui_nodedirtyflag) dirtyFlag) | Forces the node to be marked for re-measurement, re-layout, or redrawing. The state of all free nodes in the component tree where the node is located is changed to attached.| Not supported| UI thread only.|

## Example

This example demonstrates how to create buttons in non-UI threads.

Click **CreateNodeTree** to create **Button** components concurrently across multiple non-UI threads, and then mount them to the main UI tree in the UI thread for display. Click **DisposeNodeTree** to unmount and destroy the created components, clearing the page.

![build_on_multi_thread](figures/build_on_multi_thread.gif)

The example shows how to obtain and use multi-threaded NDK APIs, and utilize [OH_ArkUI_PostAsyncUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask), [OH_ArkUI_PostUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask), and [OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait) to distribute component creation and attribute setting tasks across multiple threads.

To simplify programming, **ArkUI_NodeHandle** is encapsulated as an ArkUINode object on the native side using object-oriented principles, following the [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) guide.

``` ts
// index.ets
import { NodeContent } from '@kit.ArkUI';
import entry from 'libentry.so';

@Component
struct CAPIComponent {
  private rootSlot = new NodeContent();

  aboutToAppear(): void {
    // Create native components in multiple threads before page display.
    entry.createNodeTreeOnMultiThread(this.rootSlot, this.getUIContext());
  }

  aboutToDisappear(): void {
    // Release created native components before page destruction.
    entry.disposeNodeTreeOnMultiThread(this.rootSlot);
  }

  build() {
    Column() {
      // Native component mount point.
      ContentSlot(this.rootSlot)
    }
  }
}

@Entry
@Component
struct Index {
  @State isShow: boolean = false;
  @State message: string = "CreateNodeTree";

  build() {
    Flex() {
      Column() {
        Text('CreateNodeTreeOnMultiThread')
          .fontSize(18)
          .fontWeight(FontWeight.Bold)
        Button(this.message)
          .onClick(() => {
            this.isShow = !this.isShow;
            if (this.isShow) {
              this.message = "DisposeNodeTree"
            } else {
              this.message = "CreateNodeTree"
            }
          })
        if (this.isShow) {
          CAPIComponent()
        }
      }.width('100%')
    }.width('100%')
  }
}

```

``` ts
// index.d.ts
// entry/src/main/cpp/types/libentry/Index.d.ts
export const createNativeRoot: (content: Object) => void;
export const destroyNativeRoot: () => void;
export const createNodeTreeOnMultiThread: (content1: Object, content2: Object) => void;
export const disposeNodeTreeOnMultiThread: (content1: Object) => void;
```

``` cpp
# CMakeLists.txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(ndk_build_on_multi_thread)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED napi_init.cpp NativeEntry.cpp NativeModule.h ArkUIBaseNode.h ArkUINode.h ArkUIListNode.h ArkUIListItemNode.h ArkUITextNode.h NormalTextListExample.h CreateNode.h CreateNode.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so libhilog_ndk.z.so)
```

``` cpp
// NativeModule.h
#ifndef MYAPPLICATION_NATIVEMODULE_H
#define MYAPPLICATION_NATIVEMODULE_H

#include <arkui/native_node.h>
#include <arkui/native_interface.h>
#include <cassert>

namespace NativeModule {

class NativeModuleInstance {
public:
    static NativeModuleInstance *GetInstance() {
        static NativeModuleInstance instance;
        return &instance;
    }

    NativeModuleInstance() {
        // Obtain the function pointer struct of the multi-threaded NDK API for subsequent operations.
        OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi_);
        assert(arkUINativeNodeApi_);
    }
    // Expose it for use by other modules.
    ArkUI_NativeNodeAPI_1 *GetNativeNodeAPI() { return arkUINativeNodeApi_; }

private:
    ArkUI_NativeNodeAPI_1 *arkUINativeNodeApi_ = nullptr;
};
} // namespace NativeModule

#endif // MYAPPLICATION_NATIVEMODULE_H
```

``` cpp
// CreateNode.h
#ifndef MYAPPLICATION_CREATENODE_H
#define MYAPPLICATION_CREATENODE_H

// Encapsulate the ArkUINode object. For details, see the guide for integrating with ArkTS page.
#include "ArkUINode.h"

#include <js_native_api.h>

namespace NativeModule {
// Encapsulate the Button component.
class ArkUIButtonNode: public ArkUINode {
public:
    ArkUIButtonNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_BUTTON)) {}
    int32_t SetLabel(ArkUI_AttributeItem& label_item) {
        return nativeModule_->setAttribute(handle_, NODE_BUTTON_LABEL, &label_item);
    }
    int32_t SetMargin(ArkUI_AttributeItem& item) {
        return nativeModule_->setAttribute(handle_, NODE_MARGIN, &item);
    }
};

// Encapsulate the Row component.
class ArkUIRowNode: public ArkUINode {
public:
    ArkUIRowNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_ROW)) {}
};

// Encapsulate the Scroll component.
class ArkUIScrollNode: public ArkUINode {
public:
    ArkUIScrollNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_SCROLL)) {}
};

// Encapsulate the Column component.
class ArkUIColumnNode: public ArkUINode {
public:
    ArkUIColumnNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_COLUMN)) {}
};

// Create components using multiple threads.
napi_value CreateNodeTreeOnMultiThread(napi_env env, napi_callback_info info);
// Release components created using multiple threads.
napi_value DisposeNodeTreeOnMultiThread(napi_env env, napi_callback_info info);
} // namespace NativeModule

#endif // MYAPPLICATION_CREATENODE_H
```

``` cpp
// CreateNode.cpp
#include "CreateNode.h"

#include <cstdint>
#include <hilog/log.h>
#include <map>
#include <string>
#include <thread>
#include <napi/native_api.h>
#include <arkui/native_node_napi.h>

namespace NativeModule {
#define FRAMEWORK_NODE_TREE_NUMBER 4 // Number of component trees created in framework threads.
#define USER_NODE_TREE_NUMBER 3 // Number of component trees created in developer threads.
struct AsyncData {
    std::shared_ptr<ArkUINode> parent = nullptr;
    std::shared_ptr<ArkUINode> child = nullptr;
    std::string label = "";
};

// Save the mapping between the NodeContent pointer on the ArkTS side and the node tree root node on the native side.
std::map<ArkUI_NodeContentHandle, std::shared_ptr<ArkUIBaseNode>> g_nodeMap;
ArkUI_ContextHandle g_contextHandle = nullptr;

// Create a component tree.
void CreateNodeTree(void *asyncUITaskData) {
    auto asyncData = static_cast<AsyncData*>(asyncUITaskData);
    if (!asyncData) {
        return;
    }
    // Create the root node of the component tree.
    auto rowNode = std::make_shared<ArkUIRowNode>();
    asyncData->child = rowNode;
    
    // Create a button component.
    auto buttonNode1 = std::make_shared<ArkUIButtonNode>();
    ArkUI_AttributeItem label_item = { .string = asyncData->label.c_str() };
    // Set the label attribute of the button component.
    int32_t result = buttonNode1->SetLabel(label_item);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetLabel Failed %{public}d", result);
    }
    ArkUI_NumberValue value[] = {{.f32 = 5}, {.f32 = 5}, {.f32 = 5}, {.f32 = 5}};
    ArkUI_AttributeItem item = {value, 4};
    // Set the margin attribute of the button component.
    result = buttonNode1->SetMargin(item);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetMargin Failed %{public}d", result);
    }
    // Set the width attribute of the button component.
    buttonNode1->SetWidth(150);
   
   // Create another button component.
    auto buttonNode2 = std::make_shared<ArkUIButtonNode>();
    ArkUI_AttributeItem label_item2 = { .string = asyncData->label.c_str() };
    // Set the label attribute of the button component.
    result = buttonNode2->SetLabel(label_item2);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetLabel Failed %{public}d", result);
    }
    ArkUI_NumberValue value2[] = {{.f32 = 5}, {.f32 = 5}, {.f32 = 5}, {.f32 = 5}};
    ArkUI_AttributeItem item2 = {value2, 4};
    // Set the margin attribute of the button component.
    result = buttonNode2->SetMargin(item2);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetMargin Failed %{public}d", result);
    }
    // Set the width attribute of the button component.
    buttonNode2->SetWidth(150);

    // Mount the component to the component tree.
    rowNode->AddChild(buttonNode1);
    rowNode->AddChild(buttonNode2);
}

// Mount the component tree to the main UI tree.
void MountNodeTree(void *asyncUITaskData) {
    auto asyncData = static_cast<AsyncData*>(asyncUITaskData);
    if (!asyncData) {
        return;
    }
    auto parent = asyncData->parent;
    auto child = asyncData->child;
    // Mount the component tree to the main UI tree.
    parent->AddChild(child);
    delete asyncData;
}

void CreateNodeOnFrameworkThread(ArkUI_ContextHandle contextHandle, std::shared_ptr<ArkUIColumnNode> parent) {
    for (int i = 0; i < FRAMEWORK_NODE_TREE_NUMBER; i++) {
        // Create the subtree root node on the UI thread to maintain the scroll child order.
        auto columnItem = std::make_shared<ArkUIColumnNode>();
        parent->AddChild(columnItem);
        AsyncData* asyncData = new AsyncData();
        asyncData->parent = columnItem;
        asyncData->label = "OnFwkThread";
        // Create a component tree using the framework-provided non-UI thread. After the component tree is created, return to the UI thread and mount the component tree to the main UI tree.
        int32_t result = OH_ArkUI_PostAsyncUITask(contextHandle, asyncData, CreateNodeTree, MountNodeTree);
        if (result != ARKUI_ERROR_CODE_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "OH_ArkUI_PostAsyncUITask Failed %{public}d", result);
            delete asyncData;
        }
    }
}

void CreateNodeOnUserThread(ArkUI_ContextHandle contextHandle, std::shared_ptr<ArkUIColumnNode> parent) {
    auto columnItem = std::make_shared<ArkUIColumnNode>();
    parent->AddChild(columnItem);
    // Create a component tree using the developer-created non-UI thread.
    std::thread userThread([columnItem, contextHandle]() {
        for (int i = 0; i < USER_NODE_TREE_NUMBER; i++) {
            AsyncData* asyncData = new AsyncData();
            asyncData->parent = columnItem;
            asyncData->label = "OnUserThread1";
            CreateNodeTree(asyncData);
            // After the component tree is created, return to the UI thread and mount the component tree to the main UI tree.
            int32_t result = OH_ArkUI_PostUITask(contextHandle, asyncData, MountNodeTree);
            if (result != ARKUI_ERROR_CODE_NO_ERROR) {
                OH_LOG_ERROR(LOG_APP, "OH_ArkUI_PostUITask Failed %{public}d", result);
                delete asyncData;
            }
        }
    });
    userThread.detach();
}

void CreateNodeOnUserThreadAndWait(ArkUI_ContextHandle contextHandle, std::shared_ptr<ArkUIColumnNode> parent) {
    auto columnItem = std::make_shared<ArkUIColumnNode>();
    parent->AddChild(columnItem);
    // Create a component tree using the developer-created non-UI thread.
    std::thread userThread([columnItem, contextHandle]() {
        for (int i = 0; i < USER_NODE_TREE_NUMBER; i++) {
            AsyncData* asyncData = new AsyncData();
            asyncData->parent = columnItem;
            asyncData->label = "OnUserThread2";
            CreateNodeTree(asyncData);
            // After the component tree is created, return to the UI thread and mount the component tree to the main tree. After the mounting is complete, continue to create the remaining components.
            int32_t result = OH_ArkUI_PostUITaskAndWait(contextHandle, asyncData, MountNodeTree);
            if (result != ARKUI_ERROR_CODE_NO_ERROR) {
                OH_LOG_ERROR(LOG_APP, "OH_ArkUI_PostUITask Failed %{public}d", result);
                delete asyncData;
            }
        }
    });
    userThread.detach();
}

napi_value CreateNodeTreeOnMultiThread(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = { nullptr, nullptr };
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain the mount point of the component on the ArkTS side.
    ArkUI_NodeContentHandle contentHandle;
    int32_t result = OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_GetNodeContentFromNapiValue Failed %{public}d", result);
        return nullptr;
    }
    
    // Obtain the context object pointer.
    if (!g_contextHandle) {
        result = OH_ArkUI_GetContextFromNapiValue(env, args[1], &g_contextHandle);
        if (result != ARKUI_ERROR_CODE_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "OH_ArkUI_GetContextFromNapiValue Failed %{public}d", result);
            delete g_contextHandle;
            g_contextHandle = nullptr;
            return nullptr;
        }
    }
    
    // Create the root node of the component tree on the native side.
    auto scrollNode = std::make_shared<ArkUIScrollNode>();
    // Mount the root node of the component tree on the native side to the main UI tree.
    result = OH_ArkUI_NodeContent_AddNode(contentHandle, scrollNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_AddNode Failed %{public}d", result);
        return nullptr;
    }
    // Save the component tree on the native side.
    g_nodeMap[contentHandle] = scrollNode;
    
    auto columnNode = std::make_shared<ArkUIColumnNode>();
    scrollNode->AddChild(columnNode);
    // Create a component using the framework-provided thread pool.
    CreateNodeOnFrameworkThread(g_contextHandle,columnNode);
    // Create a component using the developer-created non-UI thread.
    CreateNodeOnUserThread(g_contextHandle,columnNode);
    CreateNodeOnUserThreadAndWait(g_contextHandle,columnNode);
    return nullptr;
}

napi_value DisposeNodeTreeOnMultiThread(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = { nullptr };
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain the mount point of the component on the ArkTS side.
    ArkUI_NodeContentHandle contentHandle;
    int32_t result = OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_GetNodeContentFromNapiValue Failed %{public}d", result);
        return nullptr;
    }
    
    auto it = g_nodeMap.find(contentHandle);
    if (it == g_nodeMap.end()) {
        return nullptr;
    }
    auto rootNode = it->second;
    // Unmount the root node of the component tree on the native side from the main UI tree.
    result = OH_ArkUI_NodeContent_RemoveNode(contentHandle, rootNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_RemoveNode Failed %{public}d", result);
        return nullptr;
    }
    // Release the component tree on the native side.
    g_nodeMap.erase(contentHandle);
    return nullptr;
}
} // namespace NativeModule
```

``` cpp
// napi_init.cpp
#include "napi/native_api.h"
#include "NativeEntry.h"
#include "CreateNode.h"

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // Bind the native creation and destruction of components.
    napi_property_descriptor desc[] = {
        {"createNativeRoot", nullptr,
        NativeModule::CreateNativeRoot, nullptr, nullptr,
        nullptr, napi_default, nullptr},
        
        {"destroyNativeRoot", nullptr,
        NativeModule::DestroyNativeRoot, nullptr, nullptr,
        nullptr, napi_default, nullptr},
        
        {"createNodeTreeOnMultiThread", nullptr,
        NativeModule::CreateNodeTreeOnMultiThread, nullptr, nullptr,
        nullptr, napi_default, nullptr},
        
        {"disposeNodeTreeOnMultiThread", nullptr,
        NativeModule::DisposeNodeTreeOnMultiThread, nullptr, nullptr,
        nullptr, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```

## Samples

The following example demonstrates how to use multi‑threaded NDK APIs in high‑load component creation scenarios to split component creation tasks into multiple subtasks and dispatch them to multiple threads for concurrent execution, thereby optimizing both the response latency and completion latency during page navigation.

<!--RP1-->
[Building UI Components Using the Multi-threaded NDK APIs](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/NdkBuildOnMultiThread)
<!--RP1End-->


<!--no_check-->