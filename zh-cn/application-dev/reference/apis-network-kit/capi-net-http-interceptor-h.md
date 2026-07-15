# http_interceptor.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 概述

定义HTTP全局拦截器模块的接口，分为只读拦截器与可修改拦截器两类。通过全局只读拦截器，开发者可以监控应用内部通过所支持的系统网络组件发起的所有HTTP请求，实现日志记录功能，也可以在全局可修改拦截器中添加自定义逻辑，修改应用内部通过所支持的系统网络组件发起的HTTP请求的请求头、响应头、响应体。

- API version 24开始支持只读拦截器。API version 26.0.0开始支持可修改拦截器。
- **只读拦截器限制**：请勿在只读拦截器中修改请求和响应的内容或释放指针。即使进行修改，该修改也不会对请求生效，但可能会影响后续只读拦截器对数据包内容的读取。此外，在只读拦截器中设置 `OH_ABORT` 也不会生效。
- **支持的组件**：
  - 只读拦截器目前支持 [@ohos.net.http](../../reference/apis-network-kit/js-apis-http.md)、[net_http.h](capi-net-http-h.md)、[rcp](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/remote-communication-rcp)、[@ohos.request.cacheDownload](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md)。
  - 可修改拦截器目前支持 [@ohos.net.http](../../reference/apis-network-kit/js-apis-http.md)、[net_http.h](capi-net-http-h.md)。

- **触发条件**：
  - 不拦截自动重定向的中间过程(仅暴露最终响应)。
  - 不拦截缓存命中时的响应(因无实际网络请求)。

**引用文件：** `<network/netstack/http_interceptor.h>`

**库：** libhttp_interceptor.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 24

**相关模块：** [netstack](capi-netstack.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_Http_AddReadOnlyInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_addreadonlyinterceptor) | 添加一个HTTP全局只读拦截器。 |
| [int32_t OH_Http_AddWritableInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_addwritableinterceptor) | 添加一个HTTP全局可修改拦截器。 |
| [int32_t OH_Http_RemoveInterceptor(struct OH_Http_Interceptor *interceptor)](#oh_http_removeinterceptor) | 删除指定的HTTP全局拦截器。 |
| [int32_t OH_Http_RemoveAllInterceptors(int32_t groupId)](#oh_http_removeallinterceptors) | 删除指定组ID的所有HTTP拦截器。 |
| [int32_t OH_Http_StartAllInterceptors(int32_t groupId)](#oh_http_startallinterceptors) | 启用指定组ID的所有HTTP拦截器。 |
| [int32_t OH_Http_StopAllInterceptors(int32_t groupId)](#oh_http_stopallinterceptors) | 停用指定组ID的所有HTTP拦截器。 |

## 函数说明

### OH_Http_AddReadOnlyInterceptor()

```c
int32_t OH_Http_AddReadOnlyInterceptor(struct OH_Http_Interceptor *interceptor)
```
**描述**

添加一个HTTP全局只读拦截器。

- 当前仅支持只读响应（OH_STAGE_RESPONSE）拦截器。
- 拦截器添加后将持续生效，开发者需显式调用接口释放资源。可调用[OH_Http_RemoveInterceptor](#oh_http_removeinterceptor)移除单个拦截器，或调用[OH_Http_RemoveAllInterceptors](#oh_http_removeallinterceptors)移除整组拦截器以释放资源。
- 支持按需启动控制。若拦截器[OH_Http_Interceptor](capi-netstack-http-interceptor.md)的 `enabled` 属性设为 0，调用添加接口后拦截器不会立即启动，后续需调用[OH_Http_StartAllInterceptors](#oh_http_startallinterceptors)接口以启用拦截器。若`enabled` 属性设为 1，也可调用[OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors)接口以停用拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 24

**参数：**
| 参数项 | 描述 |
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | 待添加的拦截器，指向[OH_Http_Interceptor](capi-netstack-http-interceptor.md)结构体的指针。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝；返回值为401表示参数错误（如指针为nullptr，或不支持所添加的拦截器类型）。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)、[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode)。 |

### OH_Http_AddWritableInterceptor()

```c
int32_t OH_Http_AddWritableInterceptor(struct OH_Http_Interceptor *interceptor)
```
**描述**

添加一个HTTP全局可修改拦截器。

- 拦截器添加后将持续生效，开发者需显式调用接口释放资源。可调用[OH_Http_RemoveInterceptor](#oh_http_removeinterceptor)移除单个拦截器，或调用[OH_Http_RemoveAllInterceptors](#oh_http_removeallinterceptors)移除整组拦截器以释放资源。
- 支持按需启动控制。若拦截器[OH_Http_Interceptor](capi-netstack-http-interceptor.md)的 `enabled` 属性设为 0，调用添加接口后拦截器不会立即启动，后续需调用[OH_Http_StartAllInterceptors](#oh_http_startallinterceptors)接口以启用拦截器。若`enabled` 属性设为 1，也可调用[OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors)接口以停用拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 26.0.0

**参数：**
| 参数项 | 描述 |
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | 待添加的拦截器，指向[OH_Http_Interceptor](capi-netstack-http-interceptor.md)结构体的指针。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝；返回值为401表示参数错误（如指针为nullptr，或不支持所添加的拦截器类型）。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)、[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode)。 |

### OH_Http_RemoveInterceptor()

```c
int32_t OH_Http_RemoveInterceptor(struct OH_Http_Interceptor *interceptor)
```
**描述**

删除指定的HTTP全局拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 24

**参数：**
| 参数项 | 描述 |
| -- | -- |
| [struct OH_Http_Interceptor](capi-netstack-http-interceptor.md) *interceptor | 待删除的拦截器，指向[OH_Http_Interceptor](capi-netstack-http-interceptor.md)结构体的指针。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝；返回值为401表示参数错误（如指针为 nullptr）。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)、[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PARAMETER_ERROR](capi-net-http-type-h.md#http_errcode)。 |

### OH_Http_RemoveAllInterceptors()

```c
int32_t OH_Http_RemoveAllInterceptors(int32_t groupId)
```
**描述**

删除指定组ID的所有HTTP拦截器。

- 组ID由应用在创建拦截器时自行分配和管理。
- 若应用内部多个模块使用拦截器，必须合理规划组ID，避免冲突。
- 组ID冲突可能导致调用此函数时意外删除其他模块的拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 24

**参数：**
| 参数项 | 描述 |
| -- | -- |
| int32_t groupId | 拦截器组ID。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)。 |

### OH_Http_StartAllInterceptors()

```c
int32_t OH_Http_StartAllInterceptors(int32_t groupId)
```
**描述**

启用指定组ID的所有HTTP拦截器。

- 调用[OH_Http_StopAllInterceptors](#oh_http_stopallinterceptors)停止拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 24

**参数：**
| 参数项 | 描述 |
| -- | -- |
| int32_t groupId | 拦截器组ID。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)。 |

### OH_Http_StopAllInterceptors()

```c
int32_t OH_Http_StopAllInterceptors(int32_t groupId)
```
**描述**

停用指定组ID的所有HTTP拦截器。

- 调用[OH_Http_StartAllInterceptors](#oh_http_startallinterceptors)重新启用拦截器。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 24

**参数：**
| 参数项 | 描述 |
| -- | -- |
| int32_t groupId | 拦截器组ID。 |

**返回：**
| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功；返回值为201表示权限被拒绝。详细错误码请参考[OH_HTTP_RESULT_OK](capi-net-http-type-h.md#http_errcode)和[OH_HTTP_PERMISSION_DENIED](capi-net-http-type-h.md#http_errcode)。 |

