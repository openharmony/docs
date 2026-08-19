# http_interceptor.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=66333f405b8ba85b102d9221d24e54901f6cfbf8 translatedAt=2026-06-25T01:49:31.784Z pushedAt=2026-06-26T03:00:41.274Z -->

## Overview

Defines the APIs of the HTTP global interceptor module, which includes read-only interceptors and writable interceptors. With global read-only interceptors, you can monitor all HTTP requests initiated by the application through supported system network components to implement the logging feature. With global writable interceptors, you can add custom logic to modify the request headers, response headers, and response bodies of HTTP requests initiated by the application through supported system network components.

- Read-only interceptors are supported since API version 24. Writable interceptors are supported since API version 26.0.0.

- **Restrictions on read-only interceptors**: Do not modify the request and response content or release the pointer in a read-only interceptor. Even if you modify the content, the modification will not take effect on the request, but may affect the subsequent read-only interceptors' reading of the data packet content. In addition, setting **OH_ABORT** in a read-only interceptor will not take effect.

- **Supported components**:

  - Read-only interceptors currently support [@ohos.net.http](../../reference/apis-network-kit/js-apis-http.md), [net_http.h](capi-net-http-h.md), [rcp](https://developer.huawei.com/consumer/en/doc/harmonyos-references/remote-communication-rcp), and [@ohos.request.cacheDownload](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md).

  - Writable interceptors currently support [@ohos.net.http](../../reference/apis-network-kit/js-apis-http.md) and [net_http.h](capi-net-http-h.md).

- **Trigger conditions**:

  - The intermediate process of automatic redirection is not intercepted (only the final response is exposed).

  - The response when a cache hit occurs is not intercepted (because there is no actual network request).

**Header file**: <network/netstack/http_interceptor.h>

**Library**: libhttp_interceptor.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 24

**Related module**: [netstack](capi-netstack.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [int32_t OH_Http_AddReadOnlyInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_addreadonlyinterceptor) | Adds a global read-only HTTP interceptor.|
| [int32_t OH_Http_AddWritableInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_addwritableinterceptor) | Adds a global writable interceptor for HTTP. |
| [int32_t OH_Http_RemoveInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_removeinterceptor) | Removes a specified global HTTP interceptor.|
| [int32_t OH_Http_RemoveAllInterceptors(int32_t groupId)](#oh_http_removeallinterceptors) | Removes all HTTP interceptors of a specified group ID.|
| [int32_t OH_Http_StartAllInterceptors(int32_t groupId)](#oh_http_startallinterceptors) | Enables all HTTP interceptors of a specified group ID.|
| [int32_t OH_Http_StopAllInterceptors(int32_t groupId)](#oh_http_stopallinterceptors) | Disables all HTTP interceptors of a specified group ID.|

## Function Description

### OH_Http_AddReadOnlyInterceptor()

```c
int32_t OH_Http_AddReadOnlyInterceptor(struct OH_Http_Interceptor *interceptor)
```

**Description**

Adds a global read-only HTTP interceptor.

- Currently, only the read-only response interceptor (**OH_STAGE_RESPONSE**) is supported.

- After an interceptor is added, it takes effect continuously. You need to explicitly call APIs to release resources. You can call [OH_Http_RemoveInterceptor](#oh_http_removeinterceptor) to remove a single interceptor, or call [OH_Http_RemoveAllInterceptors](#oh_http_removeallinterceptors) to remove an entire interceptor group to release resources.

- On-demand startup control is supported. If the **enabled** property of the interceptor [OH_Http_Interceptor](capi-netstack-http-interceptor.md) is set to **0**, the interceptor will not start immediately after the add API is called. You need to call [OH_Http_StartAllInterceptors](#oh_http_startallinterceptors) later to enable the interceptor. If the **enabled** property is set to **1**, you can also call [OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors) to disable the interceptor.

**System capability**: SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | Pointer to the [OH_Http_Interceptor](capi-netstack-http-interceptor.md) struct, which is the interceptor to add. |

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. If the return value is **401**, the parameter is incorrect (for example, the pointer is **nullptr**, or the added interceptor type is not supported). For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode), [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode), and [OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode). |

### OH_Http_AddWritableInterceptor()

```c
int32_t OH_Http_AddWritableInterceptor(struct OH_Http_Interceptor *interceptor)
```

**Description**

Adds a global writable HTTP interceptor.

- After an interceptor is added, it takes effect continuously. You need to explicitly call APIs to release resources. You can call [OH_Http_RemoveInterceptor](#oh_http_removeinterceptor) to remove a single interceptor, or call [OH_Http_RemoveAllInterceptors](#oh_http_removeallinterceptors) to remove an entire interceptor group to release resources.

- On-demand startup control is supported. If the **enabled** property of the interceptor [OH_Http_Interceptor](capi-netstack-http-interceptor.md) is set to **0**, the interceptor will not start immediately after the add API is called. You need to call [OH_Http_StartAllInterceptors](#oh_http_startallinterceptors) later to enable the interceptor. If the **enabled** property is set to **1**, you can also call [OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors) to disable the interceptor.

**System capability:** SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | Pointer to the [OH_Http_Interceptor](capi-netstack-http-interceptor.md) struct to be added.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. If the return value is **401**, the parameter is incorrect (for example, the pointer is **nullptr** or the added interceptor type is not supported). For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode), [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode), and [OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode).|

### OH_Http_RemoveInterceptor()

```c
int32_t OH_Http_RemoveInterceptor(struct OH_Http_Interceptor *interceptor)
```

**Description**

Removes a specified global HTTP interceptor.

**System capability**: SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | Pointer to the [OH_Http_Interceptor](capi-netstack-http-interceptor.md) struct to be removed.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. If the return value is **401**, the parameter is incorrect (for example, the pointer is **nullptr**). For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode), [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode), and [OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode).|

### OH_Http_RemoveAllInterceptors()

```c
int32_t OH_Http_RemoveAllInterceptors(int32_t groupId)
```

**Description**

Removes all HTTP interceptors of a specified group ID.

- The group ID is allocated and managed by the application when the interceptors are created.

- If multiple modules in the application use interceptors, you must properly set group IDs to avoid conflicts.

- If a group ID conflict occurs, interceptors of other modules may be deleted unexpectedly when this function is called.

**System capability**: SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| int32_t groupId | Interceptor group ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode) and [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode).|

### OH_Http_StartAllInterceptors()

```c
int32_t OH_Http_StartAllInterceptors(int32_t groupId)
```

**Description**

Enables all HTTP interceptors of a specified group ID.

- Call [OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors) to stop the interceptors.

**System capability**: SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| int32_t groupId | Interceptor group ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode) and [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode).|

### OH_Http_StopAllInterceptors()

```c
int32_t OH_Http_StopAllInterceptors(int32_t groupId)
```

**Description**

Disables all HTTP interceptors of a specified group ID.

- Call [OH_Http_StartAllInterceptors](#oh_http_startallinterceptors) to enable the interceptors again.

**System capability**: SystemCapability.Communication.NetStack

**Required permissions:** ohos.permission.INTERNET

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| int32_t groupId | Interceptor group ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | If the return value is **0**, the execution is successful. If the return value is **201**, the permission is denied. For details about the error codes, see [OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode) and [OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode).|