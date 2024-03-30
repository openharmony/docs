# ArkWeb子系统变更说明

## cl.arkweb.1 网络拦截支持获取POST请求post data相关接口变更。

**访问级别**

公开接口

**变更原因**

新增支持PUT请求的 request body。两种请求可以归一，删除原获取POST请求的post data的接口簇（*PostDataStream*），使用新的接口簇替代（*HttpBodyStream*）。

**变更影响**

该变更为非兼容性变更，需要使用新的接口替代。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.13开始。

**变更的接口/组件**


| 删除接口        | 替代接口               | 描述                   |
| -------------- | ---------------- | -------------------- |
| ArkWeb_PostDataStream  | ArkWeb_HttpBodyStream | 类型定义。 |
| OH_ArkWebResourceRequest_GetPostData | OH_ArkWebResourceRequest_GetHttpBodyStream | 获取POST、PUT请求的上传数据，该接口需要在IO线程使用。 |
| OH_ArkWebResourceRequest_DestroyPostData | OH_ArkWebResourceRequest_DestroyHttpBodyStream | 销毁ArkWeb_HttpBodyStream对象。 |
| OH_ArkWebPostDataStream_SetReadCallback | OH_ArkWebHttpBodyStream_SetReadCallback | 为 OH_ArkWebHttpBodyStream_Read 设置回调函数，OH_ArkWebHttpBodyStream_Read 的结果将通过 readCallback 通知给调用者。该回调函数将在与OH_ArkWebHttpBodyStream_Read 相同的线程中运行。 |
| ArkWeb_PostDataStreamInitCallback | ArkWeb_HttpBodyStreamInitCallback | ArkWeb_HttpBodyStream初始化操作完成时的回调。 |
| OH_ArkWebPostDataStream_SetUserData | OH_ArkWebHttpBodyStream_SetUserData | 将一个用户数据设置到ArkWeb_HttpBodyStream对象中。 |
| OH_ArkWebPostDataStream_GetUserData | OH_ArkWebHttpBodyStream_GetUserData | 从ArkWeb_HttpBodyStream获取用户数据。 |
| OH_ArkWebPostDataStream_Init | OH_ArkWebHttpBodyStream_Init | 初始化ArkWeb_HttpBodyStream。在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。 |
| OH_ArkWebPostDataStream_Read | OH_ArkWebHttpBodyStream_Read | 将数据读取到缓冲区。缓冲区的大小必须大于bufLen。我们将从工作线程读取数据到缓冲区，因此在回调函数返回之前，不应在其他线程中使用缓冲区，以避免并发问题。 |
| OH_ArkWebPostDataStream_GetSize | OH_ArkWebHttpBodyStream_GetSize | 获取ArkWeb_HttpBodyStream的大小，分块传输时总是返回零。 |
| OH_ArkWebPostDataStream_GetPosition | OH_ArkWebHttpBodyStream_GetPosition | 获取ArkWeb_HttpBodyStream当前的读取位置。 |
| OH_ArkWebPostDataStream_IsChunked | OH_ArkWebHttpBodyStream_IsChunked | 获取ArkWeb_HttpBodyStream是否采用分块传输。 |
| OH_ArkWebPostDataStream_IsEof | OH_ArkWebHttpBodyStream_IsEof | 判断ArkWeb_HttpBodyStream中的所有数据是否都已被读取。 |
| OH_ArkWebPostDataStream_IsInMemory | OH_ArkWebHttpBodyStream_IsInMemory | 判断ArkWeb_HttpBodyStream中的数据是否在内存中。 |

**适配指导**

请查阅[ArkWeb网络拦截](../../../application-dev/reference/apis-arkweb/arkweb_scheme_handler.md)文档进行适配。
