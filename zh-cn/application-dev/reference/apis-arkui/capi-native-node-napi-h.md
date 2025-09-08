# native_node_napi.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## 概述

提供ArkTS侧的FrameNode转换NodeHandle的方式。

**引用文件：** <arkui/native_node_napi.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)](#oh_arkui_getnodehandlefromnapivalue) | 获取ArkTS侧创建的FrameNode节点对象映射到Native侧的ArkUI_NodeHandle。 |
| [int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)](#oh_arkui_getcontextfromnapivalue) | 获取ArkTS侧创建的UIContext对象映射到Native侧的ArkUI_ContextHandle。 |
| [int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)](#oh_arkui_getnodecontentfromnapivalue) | 获取ArkTS侧创建的NodeContent对象映射到Native侧的ArkUI_NodeContentHandle。 |
| [int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromnapivalue) | 将ArkTS侧创建的DrawableDescriptor对象映射到Native侧的ArkUI_DrawableDescriptor。 |
| [int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) | 将ArkTS侧创建的$r资源对象映射到Native侧的ArkUI_DrawableDescriptor。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavigationid) | 获取当前节点所在的Navigation组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationname) | 获取当前节点所在的NavDestination组件的名称。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)](#oh_arkui_getnavstacklength) | 根据给定索引值，获取当前节点所在的Navigation栈的长度。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationnamebyindex) | 根据给定索引值，获取当前节点所在的Navigation栈中对应位置的页面名称。索引值从0开始计数，0为栈底。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationid) | 获取当前节点所在的NavDestination组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)](#oh_arkui_getnavdestinationstate) | 获取当前节点所在的NavDestination组件的状态。 |
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getnavdestinationindex) | 获取当前节点所在的NavDestination组件在页面栈的索引。 |
| [napi_value OH_ArkUI_GetNavDestinationParam(ArkUI_NodeHandle node)](#oh_arkui_getnavdestinationparam) | 获取当前节点所在的NavDestination组件的参数。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getrouterpageindex) | 获取当前节点所在页面在Router页面栈中的索引。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagename) | 获取当前节点所在页面的名称。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagepath) | 获取当前节点所在页面的Page组件的路径。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)](#oh_arkui_getrouterpagestate) | 获取当前节点所在页面的Page组件的状态。 |
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpageid) | 获取当前节点所在页面的Page组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)](#oh_arkui_initmoduleforarktsenv) | 初始化指定上下文环境的ArkUI相关接口。该函数禁止在非UI线程中调用，否则程序将主动abort。 |
| [void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)](#oh_arkui_notifyarktsenvdestroy) | 通知指定的上下文环境已销毁。该函数禁止在非UI线程中调用，否则程序将主动abort。 |
| [int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData,void (\*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))](#oh_arkui_postframecallback) | 注册一个回调函数，以便在下一帧渲染时执行。不允许在非UI线程调用，检查到非UI线程调用程序会主动中止。 |
| [int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData,void (\*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))](#oh_arkui_postidlecallback) | 注册一个回调函数，在下一帧渲染结束后如果距离下一个Vsync信号到来剩余时间大于1ms时，该回调函数将被执行；如果剩余时间小于1ms时，回调函数将被顺延至当某个下一帧的剩余时间大于1ms时再执行。如果当前没有下一帧，将自动请求下一帧。 |

## 函数说明

### OH_ArkUI_GetNodeHandleFromNapiValue()

```
int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)
```

**描述：**


获取ArkTS侧创建的FrameNode节点对象映射到Native侧的ArkUI_NodeHandle。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value frameNode | ArkTS侧创建的FrameNode对象。 |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* handle | ArkUI_NodeHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GetContextFromNapiValue()

```
int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)
```

**描述：**


获取ArkTS侧创建的UIContext对象映射到Native侧的ArkUI_ContextHandle。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | ArkTS侧创建的context对象。 |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md)* context | ArkUI_ContextHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GetNodeContentFromNapiValue()

```
int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)
```

**描述：**


获取ArkTS侧创建的NodeContent对象映射到Native侧的ArkUI_NodeContentHandle。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | ArkTS侧创建的NodeContent对象。 |
| content | ArkUI_NodeContentHandle指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**描述：**


将ArkTS侧创建的DrawableDescriptor对象映射到Native侧的ArkUI_DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | ArkTS侧创建的DrawableDescriptor对象。 |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**描述：**


将ArkTS侧创建的$r资源对象映射到Native侧的ArkUI_DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | ArkTS侧创建的$r资源对象。 |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GetNavigationId()

```
ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在的Navigation组件的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，NavigationID写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavDestinationName()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在的NavDestination组件的名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，被查询的NavDestination名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavStackLength()

```
ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)
```

**描述：**


根据给定索引值，获取当前节点所在的Navigation栈的长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* length | 栈的长度。查询成功后将结果写回该参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。 |

### OH_ArkUI_GetNavDestinationNameByIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


根据给定索引值，获取当前节点所在的Navigation栈中对应位置的页面名称。索引值从0开始计数，0为栈底。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t index | 被查询NavDestination在栈中的索引。 |
| char* buffer | 缓冲区，被查询页面的名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_NODE_INDEX_INVALID](capi-native-type-h.md#arkui_errorcode) index为非法值。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavDestinationId()

```
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
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetNavDestinationState()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)
```

**描述：**


获取当前节点所在的NavDestination组件的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| [ArkUI_NavDestinationState](capi-native-type-h.md#arkui_navdestinationstate)* state | NavDestination的状态值写回该参数中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。 |

### OH_ArkUI_GetNavDestinationIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)
```

**描述：**


获取当前节点所在的NavDestination组件在页面栈的索引。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* index | 索引值，从0开始计数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。 |

### OH_ArkUI_GetNavDestinationParam()

```
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

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)
```

**描述：**


获取当前节点所在页面在Router页面栈中的索引。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| int32_t* index | 索引值，从1开始计数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 指定的节点或传递的索引异常。<br>[ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败，可能因为当前节点不在Navigation中。 |

### OH_ArkUI_GetRouterPageName()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在页面的名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，页面名称写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetRouterPagePath()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在页面的Page组件的路径。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，Page Path写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_GetRouterPageState()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)
```

**描述：**


获取当前节点所在页面的Page组件的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| [ArkUI_RouterPageState](capi-native-type-h.md#arkui_routerpagestate)* state | Router Page的状态值写回该参数中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败。 |

### OH_ArkUI_GetRouterPageId()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述：**


获取当前节点所在页面的Page组件的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 指定的节点。 |
| char* buffer | 缓冲区，Page Id写入该内存区域。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 在返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)时表示实际写入到缓冲区的字符串长度。                     在返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)时表示可以容纳目标的最小缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) 查询信息失败。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 给定的buffer size小于可以容纳目标的最小缓冲区大小。 |

### OH_ArkUI_InitModuleForArkTSEnv()

```
ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)
```

**描述：**


初始化指定上下文环境的ArkUI相关接口。该函数禁止在非UI线程中调用，否则程序将主动abort。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数无效（如env为null或设置白名单失败）。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) CAPI初始化错误。 |

### OH_ArkUI_NotifyArkTSEnvDestroy()

```
void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)
```

**描述：**


通知指定的上下文环境已销毁。该函数禁止在非UI线程中调用，否则程序将主动abort。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Node-API的环境指针。 |

### OH_ArkUI_PostFrameCallback()

```
int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData,void (*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))
```

**描述：**


注册一个回调函数，以便在下一帧渲染时执行。不允许在非UI线程调用，检查到非UI线程调用程序会主动中止。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| ArkUI_ContextHandle uiContext | UIContext对象，用以绑定实例。 |
|  void* userData | 自定义事件参数，当事件触发时在回调参数中携带回来。 |
| callback | 自定义回调函数。 |
| uint64_t nanoTimestamp | 帧信号的时间戳。 |
|  uint32_t frameCount | 帧号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) CAPI初始化错误。<br>         [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-native-type-h.md#arkui_errorcode) uiContext对象无效。<br>         [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-native-type-h.md#arkui_errorcode) 回调函数无效。 |

### OH_ArkUI_PostIdleCallback()

```
int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData,void (*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))
```

**描述：**


注册一个回调函数，在下一帧渲染结束后如果距离下一个Vsync信号到来剩余时间大于1ms时，该回调函数将被执行；如果剩余时间小于1ms时，回调函数将被顺延至当某个下一帧的剩余时间大于1ms时再执行。如果当前没有下一帧，将自动请求下一帧。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| ArkUI_ContextHandle uiContext | UIContext对象，用以绑定实例。 |
|  void* userData | 自定义事件参数，当自定义回调函数触发时在回调参数中携带回来。 |
| callback | 自定义回调函数，会在下一帧事件结束后剩余时间大于1ms时回调执行。 |
| uint64_t nanoTimeLeft | 下一帧渲染后的剩余时间。 |
|  uint32_t frameCount | 帧号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) CAPI初始化错误。<br>         [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-native-type-h.md#arkui_errorcode) uiContext对象无效。<br>         [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-native-type-h.md#arkui_errorcode) 回调函数无效。 |


