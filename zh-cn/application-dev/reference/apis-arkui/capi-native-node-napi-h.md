# native_node_napi.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供ArkTS侧[FrameNode](js-apis-arkui-frameNode.md)、[UIContext](arkts-apis-uicontext-uicontext.md)、NodeContent、DrawableDescriptor等对象与Native侧对象的转换，以及Navigation、Router页面信息查询、帧回调/空闲回调注册和事件直通启用或禁用等能力，适用于ArkTS与Native侧进行ArkUI节点、上下文、资源和页面状态联动的场景。

**引用文件：** `<arkui/native_node_napi.h>`

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_node_napi](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeNodeNapi/native_node_napi)<!--RP1End-->

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)](#oh_arkui_getnodehandlefromnapivalue) | 将ArkTS侧创建的FrameNode节点对象映射为Native侧的ArkUI_NodeHandle，适用于Native侧需要操作或管理ArkTS侧FrameNode节点的场景。 |
| [int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)](#oh_arkui_getcontextfromnapivalue) | 将ArkTS侧创建的[UIContext](arkts-apis-uicontext-uicontext.md)对象映射为Native侧的ArkUI_ContextHandle，适用于Native侧需要基于UIContext调用ArkUI能力的场景。 |
| [int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)](#oh_arkui_getnodecontentfromnapivalue) | 将ArkTS侧创建的NodeContent对象映射为Native侧的ArkUI_NodeContentHandle，适用于Native侧需要操作或挂载ArkTS侧NodeContent内容的场景。 |
| [int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromnapivalue) | 将ArkTS侧创建的[DrawableDescriptor](arkui-ts/ts-basic-components-image.md#drawabledescriptor10)对象映射到Native侧的[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)，适用于Native侧需要使用ArkTS侧图片资源描述对象的场景。 |
| [int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) | 将ArkTS侧通过$r()获取的资源对象转换为Native侧可使用的[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)对象，适用于Native侧需要使用ArkTS资源对象作为图片资源描述的场景。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavigationid) | 获取当前节点所在的Navigation组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationname) | 获取当前节点所在的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)组件的名称。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)](#oh_arkui_getnavstacklength) | 获取当前节点所在的Navigation栈的长度。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationnamebyindex) | 根据给定索引值，获取当前节点所在的Navigation栈中对应位置的页面名称。索引值从0开始计数，0为栈底。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationid) | 获取当前节点所在的NavDestination组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)](#oh_arkui_getnavdestinationstate) | 获取当前节点所在的NavDestination组件的状态。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getnavdestinationindex) | 获取当前节点所在的NavDestination组件在页面栈中的索引。 |
| [napi_value OH_ArkUI_GetNavDestinationParam(ArkUI_NodeHandle node)](#oh_arkui_getnavdestinationparam) | 获取当前节点所在的NavDestination组件的参数。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getrouterpageindex) | 获取当前节点所在页面在Router页面栈中的索引。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagename) | 获取当前节点所在页面的名称。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagepath) | 获取当前节点所在页面的Page组件的路径。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)](#oh_arkui_getrouterpagestate) | 获取当前节点所在页面的Page组件的状态。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpageid) | 获取当前节点所在页面的Page组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)](#oh_arkui_initmoduleforarktsenv) | 初始化指定上下文环境的ArkUI相关接口，适用于在Native侧使用ArkUI相关接口前进行上下文环境初始化的场景。该函数禁止在非UI线程中调用，否则程序将主动中止。使用该函数初始化指定上下文环境后，在对应环境销毁时调用[OH_ArkUI_NotifyArkTSEnvDestroy()](#oh_arkui_notifyarktsenvdestroy)通知环境已销毁。 |
| [void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)](#oh_arkui_notifyarktsenvdestroy) | 通知指定的上下文环境已销毁，适用于ArkTS上下文环境销毁时在Native侧同步清理相关状态的场景。使用[OH_ArkUI_InitModuleForArkTSEnv()](#oh_arkui_initmoduleforarktsenv)初始化上下文环境后，应在该环境销毁时调用此函数。该函数禁止在非UI线程中调用，否则程序将主动中止。 |
| [int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData, void (\*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))](#oh_arkui_postframecallback) | 注册一个回调函数，以便在下一帧渲染时执行，适用于Native侧在下一帧执行界面刷新或渲染相关任务的场景。不允许在非UI线程调用；如果检查到在非UI线程调用，程序会主动中止。 |
| [int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData, void (\*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))](#oh_arkui_postidlecallback) | 注册一个回调函数，适用于需要在Native侧利用帧间空闲时间处理非紧急任务的场景。下一帧渲染结束后，如果距离该帧之后的下一个VSync信号到来的剩余时间大于1ms，该回调函数将被执行；如果剩余时间小于1ms，回调函数将顺延至后续某一帧渲染结束后剩余时间大于1ms时执行。如果当前没有下一帧，将自动请求下一帧。不允许在非UI线程调用；如果检查到在非UI线程调用，程序会主动中止。 |
| [ArkUI_ErrorCode OH_ArkUI_EnableEventPassthrough(ArkUI_ContextHandle uiContext, bool enabled, ArkUI_RawInputEventType type)](#oh_arkui_enableeventpassthrough) | 启用或禁用事件直通。事件直通表示在事件分发过程中，不经过[重采样](../../ui/arkts-interaction-development-guide-touch-screen.md#重采样与历史点)直接下发给组件。 |

## 函数说明

### OH_ArkUI_GetNodeHandleFromNapiValue()

```c
int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)
```

**描述：**


将ArkTS侧创建的FrameNode节点对象映射为Native侧的ArkUI_NodeHandle，适用于Native侧需要操作或管理ArkTS侧FrameNode节点的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |
| napi_value frameNode | ArkTS侧创建的FrameNode对象。 |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* handle | ArkUI_NodeHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，请检查传入的env、frameNode和handle是否有效。 |

### OH_ArkUI_GetContextFromNapiValue()

```c
int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)
```

**描述：**


将ArkTS侧创建的[UIContext](arkts-apis-uicontext-uicontext.md)对象映射为Native侧的ArkUI_ContextHandle，适用于Native侧需要基于UIContext调用ArkUI能力的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |
| napi_value value | ArkTS侧创建的UIContext对象。 |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md)* context | ArkUI_ContextHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，请检查传入的env、value和context是否有效。 |

### OH_ArkUI_GetNodeContentFromNapiValue()

```c
int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)
```

**描述：**


将ArkTS侧创建的NodeContent对象映射为Native侧的ArkUI_NodeContentHandle，适用于Native侧需要操作或挂载ArkTS侧NodeContent内容的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |
| napi_value value | ArkTS侧创建的NodeContent对象。 |
| [ArkUI_NodeContentHandle](capi-arkui-nativemodule-arkui-nodecontent8h.md)* content | ArkUI_NodeContentHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，请检查传入的env、value和content是否有效。 |

### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```c
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**描述：**


将ArkTS侧创建的[DrawableDescriptor](arkui-ts/ts-basic-components-image.md#drawabledescriptor10)对象映射到Native侧的[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)，适用于Native侧需要使用ArkTS侧图片资源描述对象的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |
| napi_value value | ArkTS侧创建的[DrawableDescriptor](arkui-ts/ts-basic-components-image.md#drawabledescriptor10)对象。 |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，请检查传入的env、value和drawableDescriptor是否有效。 |

### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```c
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**描述：**


将ArkTS侧通过$r()获取的资源对象转换为Native侧可使用的[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)对象，适用于Native侧需要使用ArkTS资源对象作为图片资源描述的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |
| napi_value value | ArkTS侧通过$r()获取的资源对象。 |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，请检查传入的env、value和drawableDescriptor是否有效。 |

### OH_ArkUI_GetNavigationId()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在的[Navigation](arkui-ts/ts-basic-components-navigation.md)组件的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，NavigationID写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 数据大小超过指定的缓冲区大小。 |

### OH_ArkUI_GetNavDestinationName()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)组件的名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，被查询的NavDestination名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavStackLength()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)
```

**描述：**


获取当前节点所在的Navigation栈的长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* length | 栈的长度。查询成功后将结果写回该参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。 |

### OH_ArkUI_GetNavDestinationNameByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


根据给定索引值，获取当前节点所在的Navigation栈中的页面名称。索引值从0开始计数，0为栈底。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t index | 被查询NavDestination在栈中的索引。 |
| char* buffer | 缓冲区，被查询页面的名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_NODE_INDEX_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) index为非法值。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavDestinationId()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在的NavDestination组件的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，NavDestinationID写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 数据大小超过指定的缓冲区大小。 |

### OH_ArkUI_GetNavDestinationState()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)
```

**描述：**


获取当前节点所在的NavDestination组件的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| [ArkUI_NavDestinationState](capi-navigation-router-h.md#arkui_navdestinationstate)* state | NavDestination的状态值写回该参数中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。 |

### OH_ArkUI_GetNavDestinationIndex()

```c
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)
```

**描述：**


获取当前节点所在的NavDestination组件在页面栈中的索引。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* index | 索引值，从0开始计数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。 |

### OH_ArkUI_GetNavDestinationParam()

```c
napi_value OH_ArkUI_GetNavDestinationParam(ArkUI_NodeHandle node)
```

**描述：**


获取当前节点所在的NavDestination组件的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| napi_value | 参数对象。如返回为空，则说明参数不存在或指定的节点为空。|

### OH_ArkUI_GetRouterPageIndex()

```c
ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)
```

**描述：**


获取当前节点所在[Router](arkts-apis-uicontext-router.md)页面栈中的索引。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* index | 索引值，从1开始计数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 指定的节点或传递的索引异常。<br>[ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点未挂载在页面下。 |

### OH_ArkUI_GetRouterPageName()

```c
ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在Router页面的名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，页面名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetRouterPagePath()

```c
ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在Router页面的路径。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，页面路径写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetRouterPageState()

```c
ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)
```

**描述：**


获取当前节点所在Router页面的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| [ArkUI_RouterPageState](capi-navigation-router-h.md#arkui_routerpagestate)* state | Router页面的状态值写回该参数中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败。 |

### OH_ArkUI_GetRouterPageId()

```c
ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在Router页面的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，页面ID写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 数据大小超过指定的缓冲区大小。 |

### OH_ArkUI_InitModuleForArkTSEnv()

```c
ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)
```

**描述：**


初始化指定上下文环境的ArkUI相关接口，适用于在Native侧使用ArkUI相关接口前进行上下文环境初始化的场景。该函数禁止在非UI线程中调用，否则程序将主动中止。使用该函数初始化指定上下文环境后，在对应环境销毁时调用[OH_ArkUI_NotifyArkTSEnvDestroy()](#oh_arkui_notifyarktsenvdestroy)通知环境已销毁。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数无效，可能原因是env为空或设置白名单失败；请检查env是否有效后重试。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) CAPI初始化错误，请确认当前运行环境支持ArkUI Native接口并重试。 |

### OH_ArkUI_NotifyArkTSEnvDestroy()

```c
void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)
```

**描述：**


通知指定的上下文环境已销毁，适用于ArkTS上下文环境销毁时在Native侧同步清理相关状态的场景。使用[OH_ArkUI_InitModuleForArkTSEnv()](#oh_arkui_initmoduleforarktsenv)初始化上下文环境后，应在该环境销毁时调用此函数。该函数禁止在非UI线程中调用，否则程序将主动中止。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |

### OH_ArkUI_PostFrameCallback()

```c
int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData, void (*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))
```

**描述：**


注册一个回调函数，以便在下一帧渲染时执行，适用于Native侧在下一帧执行界面刷新或渲染相关任务的场景。不允许在非UI线程调用；如果检查到在非UI线程调用，程序会主动中止。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | [UIContext](arkui-ts/ts-custom-component-api.md#uicontext)对象指针，用以绑定实例。 |
| void* userData | 自定义事件参数，当事件触发时在回调参数中携带回来。 |
| void (\*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void\* userData) | 自定义回调函数，签名为void (\*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void\* userData)，用于在下一帧渲染时执行。其中nanoTimestamp表示帧信号的时间戳，frameCount表示帧号，userData表示注册时传入并在回调触发时携带回来的自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) CAPI初始化错误，请确认ArkUI Native接口运行环境已完成初始化后重试。<br>         [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) uiContext对象无效，请检查uiContext是否为空或是否来自有效的UIContext对象。<br>         [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 回调函数无效，请检查callback是否为空。 |

### OH_ArkUI_PostIdleCallback()

```c
int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData, void (*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))
```

**描述：**


注册一个回调函数，适用于需要在Native侧利用帧间空闲时间处理非紧急任务的场景。下一帧渲染结束后，如果距离该帧之后的下一个VSync信号到来的剩余时间大于1ms，该回调函数将被执行；如果剩余时间小于1ms，回调函数将顺延至后续某一帧渲染结束后剩余时间大于1ms时执行。如果当前没有下一帧，将自动请求下一帧。不允许在非UI线程调用；如果检查到在非UI线程调用，程序会主动中止。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UIContext对象指针，用以绑定实例。 |
| void* userData | 自定义事件参数，当自定义回调函数触发时在回调参数中携带回来。 |
| void (\*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void\* userData) | 自定义回调函数，签名为void (\*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void\* userData)，用于在下一帧渲染结束后，剩余时间大于1ms时执行。其中nanoTimeLeft表示距离当前帧截止时间的剩余时间，frameCount表示帧号，userData表示注册时传入并在回调触发时携带回来的自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) CAPI初始化错误，请确认ArkUI Native接口运行环境已完成初始化后重试。<br>         [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) uiContext对象无效，请检查uiContext是否为空或是否来自有效的UIContext对象。<br>         [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 回调函数无效，请检查callback是否为空。 |

### OH_ArkUI_EnableEventPassthrough()

```c
ArkUI_ErrorCode OH_ArkUI_EnableEventPassthrough(ArkUI_ContextHandle uiContext, bool enabled, ArkUI_RawInputEventType type)
```

**描述：**

启用或禁用事件直通。事件直通表示在事件分发过程中，不经过[重采样](../../ui/arkts-interaction-development-guide-touch-screen.md#重采样与历史点)直接下发给组件。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | [UIContext](arkts-apis-uicontext-uicontext.md)对象，用以绑定实例。 |
| bool enabled | 启用或禁用事件直通。true表示启用事件直通，false表示禁用事件直通。 |
| [ArkUI_RawInputEventType](capi-common-attributes-h.md#arkui_rawinputeventtype) type | 指定启用或禁用事件直通的原始输入事件类型[ArkUI_RawInputEventType](capi-common-attributes-h.md#arkui_rawinputeventtype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) UIContext对象无效。 |
