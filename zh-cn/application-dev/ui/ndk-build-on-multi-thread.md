# 使用多线程NDK接口并行化构建UI页面
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @liujiang077-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

在API version 22之前，UI组件的创建与属性设置等操作必须在应用的UI线程中执行。这导致开发者在使用NDK接口时，需将组件创建与属性设置等操作通过任务队列提交至UI线程执行，限制了组件创建过程的灵活性及应用的性能。

随着应用程序功能的日益复杂，应用页面内需要动态创建大量UI组件，这些组件的创建任务堆积在单一的UI线程中执行，会导致应用启动缓慢、动画丢帧及页面卡顿，直接影响用户体验。

针对这些问题，在API version 22，NDK接口引入了多线程支持能力，为开发者带来了以下提升：

- **简化调用流程：** 开发者无需通过任务队列将组件创建任务提交至UI线程执行，可以在任意线程中直接调用组件创建和属性设置等接口，减少线程上下文切换次数，简化UI框架与应用间的交互逻辑。

- **性能与体验显著优化：** 组件创建和属性设置等接口支持多线程并发调用，能够充分利用设备的多核CPU，降低页面创建阶段的总体耗时。UI线程专注于动画渲染与用户输入，确保界面流畅及交互及时。

- **为后续功能扩展提供更好的灵活性：** 组件创建和属性设置等接口支持多线程调用，不仅能够解决应用当前的性能瓶颈问题，还为未来开发更复杂、高负载的UI页面提供扩展空间，帮助开发者在设计时拥有更多的灵活性，为持续提升用户体验创造条件。

综上所述，在复杂业务场景中，多线程NDK接口将为开发者带来高性能的UI页面创建体验。
  
## 多线程NDK接口使用方式

- 在使用多线程NDK接口前，建议开发者先阅读[NDK接口概述](ndk-build-ui-overview.md)，掌握使用NDK接口必备的基本概念和基础知识。

- 为降低开发者适配多线程NDK接口的成本，多线程NDK接口的获取和使用方式与现有NDK接口保持一致。只需要调用[OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)接口，入参传入[ARKUI_MULTI_THREAD_NATIVE_NODE](../reference/apis-arkui/capi-native-interface-h.md#arkui_nativeapivariantkind)即可获取多线程NDK接口集合。例如：

  ``` cpp
  ArkUI_NativeNodeAPI_1 *multiThreadNodeAPI = nullptr;
  // 获取多线程NDK接口集合。
  OH_ArkUI_GetModuleInterface(ARKUI_MULTI_THREAD_NATIVE_NODE, ArkUI_NativeNodeAPI_1, multiThreadNodeAPI);

  if (!multiThreadNodeAPI) {
    return;
  }
  // 调用集合中支持多线程的createNode接口创建UI组件。
  auto node = multiThreadNodeAPI->createNode(ARKUI_NODE_COLUMN);
  ```

支持多线程调用的全量NDK接口请参考[多线程NDK接口集合规格](#多线程ndk接口集合规格)。

开发者可以使用多线程NDK接口在任意线程创建UI组件并设置属性，但是必须在UI线程中，把UI组件挂载到UI主树上。可以通过如下接口完成多线程UI组件创建任务的分发和执行。

- 对于可以在非UI线程执行的任务（如组件创建、属性设置等），可以使用[OH_ArkUI_PostAsyncUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask)接口，将组件创建和属性设置等任务调度到系统线程池中执行，之后将组件挂载到主树的任务提交到UI线程执行。

- 当开发者需要在自己创建的非UI线程中创建UI组件时，使用[OH_ArkUI_PostUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask)接口将组件挂载到主树的任务提交到UI线程执行。
  
- 开发者在多线程创建UI组件的过程中需要执行只支持UI线程的任务时，使用[OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait)接口将任务提交到UI线程执行，调用此接口的非UI线程等待函数执行完成后继续创建组件。当UI线程负载很高时，调用此接口的非UI线程可能长时间阻塞，会影响多线程创建UI组件的性能收益，不建议频繁使用。

## 多线程NDK接口适配说明

1. 多线程NDK接口适用于页面跳转和列表滑动等高负载且性能敏感的场景，此类场景下UI线程需要执行耗时从几ms到几十ms的组件创建任务，开发者可以将组件创建任务拆分成多个子任务，分派给多个线程并发执行，以降低UI线程负载，提高页面启动与更新流畅度。

2. 当开发者在自己创建的线程中创建UI组件时，基于设备CPU核数等客观条件，建议并行的线程数量不要超过4个，以避免线程调度带来的性能开销。

3. 开发者可以在非UI线程预创建常用组件树，为性能敏感场景提供更好的用户体验。

## 多线程NDK接口调用规范

框架将UI组件划分为Free（游离）和Attached（已挂载）两种状态。

使用多线程[createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)接口创建的UI组件初始为Free状态，且可以在Free和Attached两种状态间进行转换，使用其他方式创建的UI组件初始为Attached状态且状态不可转换。

> **说明：**
>
> - 开发者可以在任意线程使用多线程NDK接口操作处于Free状态的组件，为保证应用功能正常和线程安全，需遵守如下使用约束：
>   - 禁止多线程同时操作同一个处于Free状态的组件或组件树，处于Free状态的组件内部是无锁的，多线程同时访问会出现稳定性问题。
>   - 禁止使用[多线程NDK接口集合](#多线程ndk接口集合规格)外的其他NDK接口操作处于Free状态的组件，需先将组件转换为Attached状态后才可以在UI线程使用其他NDK接口，否则接口功能会出现异常。
>
> - 为兼顾性能，上述约束框架侧无运行时校验，需要开发者自行保证。
>
> - 为保证接口多线程安全，处于Free状态的组件的一部分属性通过[setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)设置后，无法立即通过[getAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)接口读取到，需要将组件转换为Attached状态后才能读取到正确的属性值。

当开发者进行如下操作后，UI组件状态从Free转换为Attached：

- 使用多线程[markDirty](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#markdirty)、[measureNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#measurenode)或[layoutNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#layoutnode)接口对Free组件进行标脏、测量或布局后，此组件所在组件树内所有处于Free状态的组件转换为Attached状态。
- 使用多线程[组件树操作](#组件树操作)接口将处于Free状态的组件挂载为Attached组件的子组件，此组件所在组件树内所有处于Free状态的组件转换为Attached状态。
- 使用多线程[组件树操作](#组件树操作)接口把Attached组件挂载为处于Free状态的组件的子组件，此组件所在组件树内所有处于Free状态的组件转换为Attached状态。

对于状态可转换的Attached组件，当开发者进行如下操作后，UI组件状态从Attached转换为Free：

- 使用多线程[组件树操作](#组件树操作)接口将组件从组件树上移除，且移除后的组件所在组件树不包含不可转换的Attached组件，此组件所在组件树内所有组件转换为Free状态。

基于上述状态转换规则，每个UI组件树内所有组件都处于相同状态。

## 多线程NDK接口的错误与异常

多线程NDK接口调用规范请参考[多线程NDK接口集合规格](#多线程ndk接口集合规格)。调用多线程NDK接口时必须检查接口返回值，如下两种情况接口会返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。

- 在非UI线程中调用集合中不支持多线程的接口。

- 在非UI线程调用多线程NDK接口操作处于Attached状态的组件。

多线程NDK适配过程中遇到的更多问题可以参考[UI并行化常见问题](multi-thread-ui-build-faq.md)。

## 多线程NDK接口集合规格

集合中支持多线程调用的接口包括：[组件创建销毁](#组件创建销毁)，[组件属性读写](#组件属性读写)，[组件事件注册解注册](#组件事件注册解注册)，[组件树操作](#组件树操作)和[组件自定义数据读写](#组件自定义数据读写)。

集合中仅支持UI线程调用的接口包括：[全局事件注册解注册](#全局事件注册解注册)和[组件测算布局](#组件测算布局)。

### 组件创建销毁

| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- |  
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) )([ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) type) | 基于[ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype)生成对应的Free节点并返回Free节点对象指针。  | 支持 | 支持在任意线程调用。 |
| void(\* [disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 销毁节点指针指向的节点对象。  | 支持 | 在非UI线程调用函数操作Attached节点时，接口调用无效。 |

### 组件属性读写

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute, const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*item) | 设置node节点的属性。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| const [ArkUI_AttributeItem](../reference/apis-arkui/capi-arkui-nativemodule-arkui-attributeitem.md) \*(\* [getAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | 获取node节点的属性。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |
| int32_t(\* [resetAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype) attribute) | 重置node节点的属性为默认值。  | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [setLengthMetricUnit](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LengthMetricUnit](../reference/apis-arkui/capi-native-type-h.md#arkui_lengthmetricunit) unit) | 指定node节点的单位。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### 组件事件注册解注册

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType, int32_t targetId, void \*userData) | 向node节点注册事件。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void(\* [unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) eventType) | node节点解注册事件。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口调用无效。 |
| int32_t(\* [registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-node-attributes-custom-attributes-h.md#arkui_nodecustomeventtype) eventType, int32_t targetId, void \*userData) | 向node节点注册自定义事件。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void(\* [unregisterNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomevent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeCustomEventType](../reference/apis-arkui/capi-native-node-node-attributes-custom-attributes-h.md#arkui_nodecustomeventtype) eventType) | node节点解注册自定义事件。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口调用不生效。 |
| int32_t(\* [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 向node节点注册事件回调函数，用于接收该组件产生的组件事件。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 删除node节点上注册的事件回调函数。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [addNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | 向node节点注册自定义事件回调函数，用于接收该组件产生的自定义事件（如布局事件，绘制事件）。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [removeNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodecustomeventreceiver) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) | 删除node节点上注册的自定义事件回调函数。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### 组件树操作

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | 将child节点挂载到parent节点的子节点列表中。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [removeChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removechild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child) | 将child节点从parent节点的子节点列表中移除。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildAfter](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildafter) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | 将child节点挂载到parent节点的子节点列表中，挂载位置在sibling节点之后。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildBefore](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildbefore) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) sibling) | 将child节点挂载到parent节点的子节点列表中，挂载位置在sibling节点之前。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [insertChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#insertchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent, [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) child, int32_t position) | 将child节点挂载到parent节点的子节点列表中，挂载位置由position指定。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getParent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getparent) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的父节点。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [removeAllChildren](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removeallchildren) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) parent) | 移除parent节点的所有子节点。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| uint32_t(\* [getTotalChildCount](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#gettotalchildcount) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的子节点个数。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回0。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getChildAt](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getchildat) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t position) | 获取node节点的子节点指针，位置由position指定。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getFirstChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getfirstchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的第一个子节点指针。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getLastChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlastchild) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的最后一个子节点指针。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getPreviousSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getprevioussibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的上一个兄弟节点指针。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |
| [ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)(\* [getNextSibling](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getnextsibling) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点的下一个兄弟节点指针。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回空指针。 |

### 组件自定义数据读写

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, void \*userData) | 在node节点上保存自定义数据。 | 支持 | 在非UI线程调用函数操作Attached节点时，接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void \*(\* [getUserData](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getuserdata) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点上保存的自定义数据。 | 支持 |  在非UI线程调用函数操作Attached节点时，接口返回空指针。 |

### 全局事件注册解注册

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| void(\* [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeevent.md) \*event)) | 注册节点事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
|  void(\* [unregisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver) )() | 解注册节点事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
| void(\* [registerNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomeventreceiver) )(void(\*eventReceiver)([ArkUI_NodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodecustomevent.md) \*event)) |  注册节点自定义事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |
|  void(\* [unregisterNodeCustomEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodecustomeventreceiver) )() |  解注册节点自定义事件回调统一入口函数。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口不生效。 |

### 组件测算布局

<!--Table: 25%; 35%; 15%; 25%-->
| 接口名 | 描述 | 非UI线程调用 | 多线程规格 |
| -------- | ------- | ------- | ------- | 
| int32_t(\* [setMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t width, int32_t height) | 在测算回调函数中设置组件测算完成后的宽和高。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [setLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | 在布局回调函数中设置组件的位置。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_IntSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intsize.md)(\* [getMeasuredSize](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getmeasuredsize) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点测算完成后的宽高尺寸。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回默认值。 |
| [ArkUI_IntOffset](../reference/apis-arkui/capi-arkui-nativemodule-arkui-intoffset.md)(\* [getLayoutPosition](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getlayoutposition) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node) | 获取node节点布局完成后的位置。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回默认值。 |
| int32_t(\* [measureNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#measurenode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_LayoutConstraint](../reference/apis-arkui/capi-arkui-nativemodule-arkui-layoutconstraint.md) \*Constraint) | 对node节点进行测算，可以通过getMeasuredSize获取测算后的大小。节点所在组件树内所有Free节点的状态转换为Attached。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t(\* [layoutNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#layoutnode) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, int32_t positionX, int32_t positionY) | 对node节点进行布局并传递该组件相对父组件的期望位置。节点所在组件树内所有Free节点的状态转换为Attached。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口返回错误码[ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD](../reference/apis-arkui/capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void(\* [markDirty](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#markdirty) )([ArkUI_NodeHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) node, [ArkUI_NodeDirtyFlag](../reference/apis-arkui/capi-native-node-h.md#arkui_nodedirtyflag) dirtyFlag) | 强制标记node节点重新执行测量、布局或者绘制的区域。节点所在组件树内所有Free节点的状态转换为Attached。 | 不支持 | 只支持UI线程调用，在非UI线程调用接口调用不生效。 |

## 多线程NDK接口使用示例

此示例构造了一个多线程创建UI组件的场景，页面显示的Button组件在非UI线程被并行创建。

点击CreateNodeTree按钮触发在多个非UI线程并行创建Button组件，之后在UI线程将创建完成的Button组件挂载到UI主树上，使组件显示在页面上。点击DisposeNodeTree按钮将已创建的组件从UI主树上卸载并销毁，清空页面。

![build_on_multi_thread](figures/build_on_multi_thread.gif)

示例主要展示了如何获取和使用多线程NDK接口，并使用[OH_ArkUI_PostAsyncUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postasyncuitask)、[OH_ArkUI_PostUITask](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitask)和[OH_ArkUI_PostUITaskAndWait](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_postuitaskandwait)等接口将组件创建和属性设置等任务分发到多线程并行执行。

为简化编程和工程管理，在开始编写并行化组件创建代码前，请先参考[接入ArkTS页面](ndk-access-the-arkts-page.md)指导文档，在Native侧使用面向对象的方式将ArkUI_NodeHandle封装为ArkUINode对象。

``` ts
// index.ets
import { NodeContent } from '@kit.ArkUI';
import entry from 'libentry.so';

@Component
struct CAPIComponent {
  private rootSlot = new NodeContent();

  aboutToAppear(): void {
    // 页面显示前多线程创建Native组件。
    entry.createNodeTreeOnMultiThread(this.rootSlot, this.getUIContext());
  }

  aboutToDisappear(): void {
    // 页面销毁前释放已创建的Native组件。
    entry.disposeNodeTreeOnMultiThread(this.rootSlot);
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

``` cpp
// CreateNode.h
#ifndef MYAPPLICATION_CREATENODE_H
#define MYAPPLICATION_CREATENODE_H

// 封装的ArkUINode对象，参考接入ArkTS页面指导文档。
#include "ArkUINode.h"

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
#define FRAMEWORK_NODE_TREE_NUMBER 4 // 在框架线程创建组件树的数量。
#define USER_NODE_TREE_NUMBER 3 // 在开发者线程创建组件树的数量。
struct AsyncData {
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
    result = buttonNode2->SetMargin(item2);
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
    
    // 创建Native侧组件树根节点。
    auto scrollNode = std::make_shared<ArkUIScrollNode>();
    // 将Native侧组件树根节点挂载到UI主树上。
    result = OH_ArkUI_NodeContent_AddNode(contentHandle, scrollNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_AddNode Failed %{public}d", result);
        return nullptr;
    }
    // 保存Native侧组件树。
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
    // 将Native侧组件树根节点从UI主树上卸载。
    result = OH_ArkUI_NodeContent_RemoveNode(contentHandle, rootNode->GetHandle());
    if (result != ARKUI_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_RemoveNode Failed %{public}d", result);
        return nullptr;
    }
    // 释放Native侧组件树。
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
    // 绑定Native侧的创建组件和销毁组件。
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

## 示例代码

如下实例展示了在高负载组件创建场景下如何使用多线程NDK接口，将组件创建任务拆分成多个子任务，分派给多个线程并发执行来优化页面跳转场景的响应时延和完成时延。

<!--RP1-->
[使用NDK多线程创建UI组件](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/NdkBuildOnMultiThread)
<!--RP1End-->
