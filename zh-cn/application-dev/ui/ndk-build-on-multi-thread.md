# NDK支持多线程创建组件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @lightningHo-->
<!--Tester: @liujiang077-->
<!--Adviser: @HelloCrease-->

## 概述

在API version 21之前，UI组件的创建与属性设置等操作必须在应用的UI线程中执行。这导致开发者在对接NDK接口时，需将组件创建与属性设置等任务提交至UI线程执行，不仅增加了应用代码的复杂性，也限制了组件创建过程的灵活性及应用的性能。

随着应用程序功能的日益复杂，应用页面内需动态创建大量组件，这些组件的创建任务堆积在单一的UI线程中执行，会导致应用启动缓慢、动画丢帧及页面卡顿，直接影响用户体验。

针对这些问题，在API version 21，NDK接口引入了多线程支持能力，为开发者带来了以下提升：

- **简化调用流程：** 开发者无需主动切换线程或通过任务队列将组件创建任务提交至UI线程执行，可在任意线程中直接调用组件创建接口，减少线程上下文切换次数，简化UI框架与应用间的交互逻辑。

- **性能与体验显著优化：** 组件创建和属性设置等接口支持多线程并发调用，能够充分利用设备的多核CPU，降低页面创建阶段的总体耗时。UI线程专注于动画渲染与用户输入，确保界面流畅及交互及时。

-  **为后续功能扩展提供更好的灵活性：** 组件创建和属性设置等接口支持多线程调用，不仅能够解决应用当前的性能瓶颈问题，还为未来开发更复杂、高负载的UI页面提供扩展空间，帮助开发者在设计时拥有更多的灵活性，为持续提升用户体验创造条件。

通过此次优化，开发者能够专注于自身业务逻辑的实现，无需关注线程切换等底层细节。在复杂业务场景中，开发者将获得高性能的UI页面创建体验。
  
## 多线程NDK接口使用方式

- 调用[OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)接口，入参传入[ARKUI_MULTI_THREAD_NATIVE_NODE](../reference/apis-arkui/capi-native-interface-h.md#arkui_nativeapivariantkind)以获取多线程NDK接口集合。例如：

  ```cpp
  ArkUI_NativeNodeAPI_1 *multiThreadNodeAPI = nullptr;
  // 获取多线程NDK接口集合。
  OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, multiThreadNodeAPI);

  if (!multiThreadNodeAPI) {
    return;
  }
  // 调用集合中支持多线程的createNode接口创建UI组件。
  multiThreadNodeAPI->createNode(ARKUI_NODE_COLUMN);
  ```

  支持多线程调用的全量NDK接口请参考[多线程NDK接口集合规格](#多线程ndk接口集合规格)。

- 对于可以在非UI线程执行的任务（如组件创建、属性设置等），可以使用[OH_ArkUI_PostAsyncUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask)接口，将组件创建和属性设置等任务调度到系统线程池中执行，之后将组件挂载到主树的任务提交到UI线程执行。

- 当开发者需要在自己创建的非UI线程中创建UI组件时，使用[OH_ArkUI_PostUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask)接口将组件挂载到主树的任务提交到UI线程执行。
  
- 当开发者在多线程创建组件的过程中需要调用只支持UI线程的函数时，使用[OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait)接口将函数提交到UI线程执行，调用此接口的非UI线程等待函数执行完成后继续创建组件。当UI线程负载很高时，调用此接口的非UI线程可能长时间阻塞，会影响多线程创建UI组件的性能收益，不建议频繁使用。

## 多线程NDK接口调用规范与线程安全

- 多线程NDK接口调用规范请参考[多线程NDK接口集合规格](#多线程ndk接口集合规格)。调用多线程NDK接口时必须检查接口返回值。

- 在非UI线程中调用集合中不支持多线程的接口，接口将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。

- 使用多线程NDK接口在多个线程同时操作不同组件是线程安全的；多个线程中同时操作同一个组件或同一个组件树是非线程安全的，可能产生不可预测的结果。

- 使用多线程NDK接口创建的安全组件有以下两种状态：

  - **Free（游离状态）：** 组件未挂载到UI主树，开发者可以在任意线程使用多线程NDK接口操作此组件。
  - **Attached（已挂载状态）：** 组件已挂载到UI主树，交由UI流水线管理，开发者必须在UI线程使用多线程NDK接口操作此组件，否则将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。

- 使用非多线程NDK接口创建的不安全组件（如ArkTS组件）由UI流水线管理，开发者必须在UI线程使用多线程NDK接口操作此组件，否则将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。非必要场景下不建议使用多线程NDK接口操作此类组件。

- 开发者可以在UI线程使用多线程[组件树操作](#组件树操作)接口给组件挂载不安全的ArkTS组件，但之后不可以继续在非UI线程操作这个挂载有ArkTS组件的组件，以避免在非UI线程中操作组件时访问到不安全的ArkTS组件导致应用崩溃。

- 开发者需要在UI线程移除组件挂载的所有ArkTS组件后才可以继续在非UI线程操作这个组件，ArkUI框架会在组件从UI主树卸载前检查其是否挂载有ArkTS组件，并打印如下日志提示：

    ```
    CheckIsThreadSafeNodeTree failed. thread safe node tree contains unsafe node: ${nodeid}
    ```

## 多线程NDK接口的错误与异常

- 在非UI线程调用集合中不支持多线程的接口将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。
- 组件挂载到UI主树后，在非UI线程调用接口操作组件将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。
- 在非UI线程调用接口操作非多线程NDK接口创建的组件将返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。


## 多线程NDK接口适配说明

1. 将[OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)接口入参从[ARKUI_NATIVE_NODE](../reference/apis-arkui/capi-native-interface-h.md#arkui_nativeapivariantkind)修改为[ARKUI_MULTI_THREAD_NATIVE_NODE](../reference/apis-arkui/capi-native-interface-h.md#arkui_nativeapivariantkind)即可获得多线程能力。

   ```cpp
   ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
   OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
   ```

2. 建议将原先在UI线程中执行的组件创建任务拆分成更细粒度任务，分派给多个线程并发执行，以降低UI线程负载，提高页面启动与更新流畅度。

3. 预先在后台线程中创建常用组件树，为性能敏感场景提供更好的用户体验。

## 多线程NDK接口集合规格

集合中支持多线程调用的接口包括：[组件创建销毁](#组件创建销毁)，[组件属性读写](#组件属性读写)，[组件事件注册解注册](#组件事件注册解注册)，[组件树操作](#组件树操作)和[组件自定义数据读写](#组件自定义数据读写)。

集合中仅支持UI线程调用的接口包括：[全局事件注册解注册](#全局事件注册解注册)和[组件测算布局](#组件测算布局)。

### 组件创建销毁

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- |  
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) )([ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) type) | 基于[ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype)生成对应的节点并返回节点对象指针。  | 支持 | 支持在任意线程调用。 |
| void(\* [disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 销毁节点指针指向的节点对象。  | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口调用无效。 |

### 组件属性读写

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*item) | 设置node节点的属性。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*(\* [getAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | 获取node节点的属性。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |
| int32_t(\* [resetAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | 重置node节点的属性为默认值。  | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [setLengthMetricUnit](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LengthMetricUnit](../reference/apis-arkui/capi-native-type-h.md#arkui_lengthmetricunit) unit) | 指定node节点的单位。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |

### 组件事件注册解注册

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | 向node节点注册事件。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| void(\* [unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType) | node节点解注册事件。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口调用无效。 |
| int32_t(\* [registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | 向node节点注册自定义事件。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| void(\* [unregisterNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodecustomeventtype) eventType) | node节点解注册自定义事件。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口调用不生效。 |
| int32_t(\* [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 向node节点注册事件回调函数，用于接收该组件产生的组件事件。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 删除node节点上注册的事件回调函数。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [addNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | 向node节点注册自定义事件回调函数，用于接收该组件产生的自定义事件（如布局事件，绘制事件）。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [removeNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | 删除node节点上注册的自定义事件回调函数。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |

### 组件树操作

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | 将child节点挂载到parent节点的子节点列表中。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [removeChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removechild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | 将child节点从parent节点的子节点列表中移除。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildAfter](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildafter) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | 将child节点挂载到parent节点的子节点列表中，挂载位置在sibling节点之后。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildBefore](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildbefore) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | 将child节点挂载到parent节点的子节点列表中，挂载位置在sibling节点之前。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, int32_t position) | 将child节点挂载到parent节点的子节点列表中，挂载位置由position指定。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getParent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getparent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的父节点。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [removeAllChildren](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removeallchildren) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent) | 移除node节点的所有子节点。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| uint32_t(\* [getTotalChildCount](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#gettotalchildcount) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的子节点个数。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回0。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t position) | 获取node节点的子节点指针，位置由position指定。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getFirstChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getfirstchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的第一个子节点指针。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getLastChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlastchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的最后一个子节点指针。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getPreviousSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getprevioussibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的上一个兄弟节点指针。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getNextSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getnextsibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的下一个兄弟节点指针。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |

### 组件自定义数据读写

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void \*userData) | 在node节点上保存自定义数据。 | 支持 | 在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| void \*(\* [getUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点上保存的自定义数据。 | 支持 |  在非UI线程调用函数操作已挂载到UI树上的节点时，接口返回空指针。 |

### 全局事件注册解注册

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| void(\* [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 注册节点事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
|  void(\* [unregisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver) )() | 解注册节点事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
| void(\* [registerNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) |  注册节点自定义事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
|  void(\* [unregisterNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomeventreceiver) )() |  解注册节点自定义事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |

### 组件测算布局

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t width, int32_t height) | 在测算回调函数中设置组件测算完成后的宽和高。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [setLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | 在布局回调函数中设置组件的位置。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| [ArkUI_IntSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intsize.md)(\* [getMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点测算完成后的宽高尺寸。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回默认值。 |
| [ArkUI_IntOffset](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intoffset.md)(\* [getLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点布局完成后的位置。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回默认值。 |
| int32_t(\* [measureNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#measurenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LayoutConstraint](../reference/apis-arkui/capi-arkui-nativemodule-arkui-layoutconstraint.md) \*Constraint) | 对node节点进行测算，可以通过getMeasuredSize获取测算后的大小。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| int32_t(\* [layoutNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#layoutnode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | 对node节点进行布局并传递该组件相对父组件的期望位置。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-native-type-h.md#arkui_errorcode)。 |
| void(\* [markDirty](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#markdirty) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeDirtyFlag](../reference/apis-arkui/capi-native-node-h.md#arkui_nodedirtyflag) dirtyFlag) | 强制标记node节点需要重新测算、布局或绘制。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口调用不生效。 |

## 场景示例

如下示例展示了如何获取和使用多线程NDK接口，并使用[OH_ArkUI_PostAsyncUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask)、[OH_ArkUI_PostUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask)和[OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait)等接口将组件创建和属性设置等任务分发到多线程并行执行。

为简化编程和工程管理，在开始编写并行化组件创建代码前，请先参考[接入ArkTS页面](ndk-access-the-arkts-page.md)指导文档，在native侧使用面向对象的方式对将ArkUI_NodeHandle封装为ArkUINode对象。

```ts
// index.ets
import { NodeContent } from '@kit.ArkUI';
import entry from 'libentry.so';

@Component
struct CAPIComponent {
  private rootSlot = new NodeContent();

  aboutToAppear(): void {
    // 页面显示前多线程创建Native组件。
    entry.CreateNodeTreeOnMultiThread(this.rootSlot, this.getUIContext());
  }

  aboutToDisappear(): void {
    // 页面销毁前释放已创建的Native组件。
    entry.DisposeNodeTreeOnMultiThread(this.rootSlot);
  }

  build() {
    Column() {
      // Native组件挂载点。
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

```cpp
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
        // 获取多线程NDK接口的函数指针结构体对象，用于后续操作。
        OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi_);
        assert(arkUINativeNodeApi_);
    }
    // 暴露给其他模块使用。
    ArkUI_NativeNodeAPI_1 *GetNativeNodeAPI() { return arkUINativeNodeApi_; }

private:
    ArkUI_NativeNodeAPI_1 *arkUINativeNodeApi_ = nullptr;
};
} // namespace NativeModule

#endif // MYAPPLICATION_NATIVEMODULE_H
```

```cpp
// CreateNode.h
#ifndef MYAPPLICATION_CREATENODE_H
#define MYAPPLICATION_CREATENODE_H

#include "common/ArkUINode.h"

#include <js_native_api.h>

namespace NativeModule {
// 封装Button组件。
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

// 封装Row组件。
class ArkUIRowNode: public ArkUINode {
public:
    ArkUIRowNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_ROW)) {}
};

// 封装Scroll组件。
class ArkUIScrollNode: public ArkUINode {
public:
    ArkUIScrollNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_SCROLL)) {}
};

// 封装Column组件。
class ArkUIColumnNode: public ArkUINode {
public:
    ArkUIColumnNode() :
        ArkUINode(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_COLUMN)) {}
};

// 多线程创建组件。
napi_value CreateNodeTreeOnMultiThread(napi_env env, napi_callback_info info);
// 释放多线程创建的组件。
napi_value DisposeNodeTreeOnMultiThread(napi_env env, napi_callback_info info);
} // namespace NativeModule

#endif //MYAPPLICATION_CREATENODE_H
```
 

```cpp
// CreateNode.cpp
#include "node/CreateNode.h"

#include <cstdint>
#include <map>
#include <napi/native_api.h>
#include <arkui/native_node_napi.h>

namespace NativeModule {
#define FRAMEWORK_NODE_TREE_NUMBER 4 // 在框架线程创建组件树的数量。
#define USER_NODE_TREE_NUMBER 3 // 在开发者线程创建组件树的数量。
struct AsyncData {
    napi_env env;
    std::shared_ptr<ArkUINode> parent = nullptr;
    std::shared_ptr<ArkUINode> child = nullptr;
    std::string label = "";
};

// 保存ArkTs侧NodeContent指针与Native侧节点树根节点的对应关系。
std::map<ArkUI_NodeContentHandle, std::shared_ptr<ArkUIBaseNode>> g_nodeMap;
ArkUI_ContextHandle g_contextHandle = nullptr;

// 创建组件树。
void CreateNodeTree(void *asyncUITaskData) {
    auto asyncData = static_cast<AsyncData*>(asyncUITaskData);
    if (!asyncData) {
        return;
    }
    // 创建组件树根节点。
    auto rowNode = std::make_shared<ArkUIRowNode>();
    asyncData->child = rowNode;
    
    // 创建button组件。
    auto buttonNode1 = std::make_shared<ArkUIButtonNode>();
    ArkUI_AttributeItem label_item = { .string = asyncData->label.c_str() };
    // 设置button组件的label属性。
    int32_t result = buttonNode1->SetLabel(label_item);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetLabel Failed %{public}d", result);
    }
    ArkUI_NumberValue value[] = {{.f32 = 5}, {.f32 = 5}, {.f32 = 5}, {.f32 = 5}};
    ArkUI_AttributeItem item = {value, 4};
    // 设置button组件的margin属性。
    result = buttonNode1->SetMargin(item);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetMargin Failed %{public}d", result);
    }
    // 设置button组件的width属性。
    buttonNode1->SetWidth(150);
   
   // 创建button组件。
    auto buttonNode2 = std::make_shared<ArkUIButtonNode>();
    ArkUI_AttributeItem label_item2 = { .string = asyncData->label.c_str() };
    // 设置button组件的label属性。
    result = buttonNode2->SetLabel(label_item2);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetLabel Failed %{public}d", result);
    }
    ArkUI_NumberValue value2[] = {{.f32 = 5}, {.f32 = 5}, {.f32 = 5}, {.f32 = 5}};
    ArkUI_AttributeItem item2 = {value2, 4};
    // 设置button组件的margin属性。
    result = buttonNode1->SetMargin(item2);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "Button SetMargin Failed %{public}d", result);
    }
    // 设置button组件的width属性。
    buttonNode2->SetWidth(150);

    // 把组件挂载到组件树上。
    rowNode->AddChild(buttonNode1);
    rowNode->AddChild(buttonNode2);
}

// 把组件树挂载到UI组件主树上。
void MountNodeTree(void *asyncUITaskData) {
    auto asyncData = static_cast<AsyncData*>(asyncUITaskData);
    if (!asyncData) {
        return;
    }
    auto parent = asyncData->parent;
    auto child = asyncData->child;
    // 把组件树挂载到UI组件主树上。
    parent->AddChild(child);
    delete asyncData;
}

void CreateNodeOnFrameworkThread(ArkUI_ContextHandle contextHandle, std::shared_ptr<ArkUIColumnNode> parent) {
    for (int i = 0; i < FRAMEWORK_NODE_TREE_NUMBER; i++) {
        // UI线程创建子树根节点，保证scroll的子节点顺序。
        auto columnItem = std::make_shared<ArkUIColumnNode>();
        parent->AddChild(columnItem);
        AsyncData* asyncData = new AsyncData();
        asyncData->parent = columnItem;
        asyncData->label = "OnFwkThread";
        // 使用框架提供的非UI线程创建组件树，创建完成后回到UI线程挂载到主树上。
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
    // 在开发者创建的非UI线程上创建组件树。
    std::thread userThread([columnItem, contextHandle]() {
        for (int i = 0; i < USER_NODE_TREE_NUMBER; i++) {
            AsyncData* asyncData = new AsyncData();
            asyncData->parent = columnItem;
            asyncData->label = "OnUserThread1";
            CreateNodeTree(asyncData);
            // 组件树创建完成后回到UI线程挂载到主树上。
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
    // 在开发者创建的非UI线程上创建组件树。
    std::thread userThread([columnItem, contextHandle]() {
        for (int i = 0; i < USER_NODE_TREE_NUMBER; i++) {
            AsyncData* asyncData = new AsyncData();
            asyncData->parent = columnItem;
            asyncData->label = "OnUserThread2";
            CreateNodeTree(asyncData);
            // 组件树创建完成后回到UI线程挂载到主树上，等待挂载完成后继续创建剩余组件。
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

    // 获取ArkTs侧组件挂载点。
    ArkUI_NodeContentHandle contentHandle;
    int32_t result = OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_GetNodeContentFromNapiValue Failed %{public}d", result);
        return nullptr;
    }
    
    // 获取上下文对象指针。
    if (!g_contextHandle) {
        result = OH_ArkUI_GetContextFromNapiValue(env, args[1], &g_contextHandle);
        if (result != ARKUI_ERROR_CODE_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "OH_ArkUI_GetContextFromNapiValue Failed %{public}d", result);
            delete g_contextHandle;
            g_contextHandle = nullptr;
            return nullptr;
        }
    }
    
    // 创建native侧组件树根节点。
    auto scrollNode = std::make_shared<ArkUIScrollNode>();
    // 将native侧组件树根节点挂载到UI主树上。
    result = OH_ArkUI_NodeContent_AddNode(contentHandle, scrollNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_AddNode Failed %{public}d", result);
        return nullptr;
    }
    // 保存native侧组件树。
    g_nodeMap[contentHandle] = scrollNode;
    
    auto columnNode = std::make_shared<ArkUIColumnNode>();
    scrollNode->AddChild(columnNode);
    // 在框架提供的线程池中创建组件。
    CreateNodeOnFrameworkThread(g_contextHandle,columnNode);
    // 在开发者创建的非UI线程中创建组件。
    CreateNodeOnUserThread(g_contextHandle,columnNode);
    CreateNodeOnUserThreadAndWait(g_contextHandle,columnNode);
    return nullptr;
}

napi_value DisposeNodeTreeOnMultiThread(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = { nullptr };
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 获取ArkTs侧组件挂载点。
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
    // 将native侧组件树根节点从UI主树上卸载。
    result = OH_ArkUI_NodeContent_RemoveNode(contentHandle, rootNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_RemoveNode Failed %{public}d", result);
        return nullptr;
    }
    // 释放native侧组件树。
    g_nodeMap.erase(contentHandle);
    return nullptr;
}
} // namespace NativeModule
```
![build_on_multi_thread](figures/build_on_multi_thread.gif)

## 相关实例

如下示例展示了如何通过多线程创建UI组件来优化页面跳转场景的响应时延和完成时延。

[使用NDK多线程创建UI组件](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/NdkBuildOnMultiThread)
