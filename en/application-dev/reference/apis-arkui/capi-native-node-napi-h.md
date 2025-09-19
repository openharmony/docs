# native_node_napi.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the functions used to convert FrameNodes on the ArkTS side into NodeHandles.

**File to include**: <arkui/native_node_napi.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)](#oh_arkui_getnodehandlefromnapivalue) | Obtains an **ArkUI_NodeHandle** object on the native side mapped from the **FrameNode** object created on the ArkTS side.|
| [int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)](#oh_arkui_getcontextfromnapivalue) | Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side.|
| [int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)](#oh_arkui_getnodecontentfromnapivalue) | Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side.|
| [int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromnapivalue) | Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.|
| [int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) | Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavigationid) | Obtains the ID of the **Navigation** component where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationname) | Obtains the name of the **Navigation** component where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)](#oh_arkui_getnavstacklength) | Obtains the length of the navigation stack where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationnamebyindex) | Obtains the page name that matches the specified index in the navigation stack where the specified node is located. The index starts from 0, which indicates the bottom of the stack.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getnavdestinationid) | Obtains the ID of the **NavDestination** component where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)](#oh_arkui_getnavdestinationstate) | Obtains the state of the **NavDestination** component where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getnavdestinationindex) | Obtains the index of the **NavDestination** component where the specified node is located in the navigation stack.|
| [napi_value OH_ArkUI_GetNavDestinationParam(ArkUI_NodeHandle node)](#oh_arkui_getnavdestinationparam) | Obtains the parameters of the **NavDestination** component where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)](#oh_arkui_getrouterpageindex) | Obtains the index of the page where the specified node is located in the page stack for routing.|
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagename) | Obtains the name of the page where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpagepath) | Obtains the path to the page where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)](#oh_arkui_getrouterpagestate) | Obtains the state of the page where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_getrouterpageid) | Obtains the ID of the page where the specified node is located.|
| [ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)](#oh_arkui_initmoduleforarktsenv) | Initializes ArkUI-related APIs for the specified context environment. This function must not be called from a non-UI thread; otherwise, the program will actively abort.|
| [void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)](#oh_arkui_notifyarktsenvdestroy) | Notifies that the specified context environment has been destroyed. This function must not be called from a non-UI thread; otherwise, the program will actively abort.|
| [int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData,void (\*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))](#oh_arkui_postframecallback) | Registers a callback function to be executed during the next frame rendering. This function must not be called from a non-UI thread; otherwise, the program will actively abort.|
| [int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData,void (\*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))](#oh_arkui_postidlecallback) | Registers a callback function that will be executed after the next frame rendering is completed if there is more than 1 ms of idle time remaining before the next VSync signal arrives. If the remaining time is less than 1 ms, the callback will be deferred until a subsequent frame where more than 1 ms of idle time is available. If there is no next frame scheduled, one will be automatically requested.|

## Function Description

### OH_ArkUI_GetNodeHandleFromNapiValue()

```
int32_t OH_ArkUI_GetNodeHandleFromNapiValue(napi_env env, napi_value frameNode, ArkUI_NodeHandle* handle)
```

**Description**


Obtains an **ArkUI_NodeHandle** object on the native side mapped from the **FrameNode** object created on the ArkTS side.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|
| napi_value frameNode | **FrameNode** object created on the ArkTS side.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* handle | Pointer to the **ArkUI_NodeHandle**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_GetContextFromNapiValue()

```
int32_t OH_ArkUI_GetContextFromNapiValue(napi_env env, napi_value value, ArkUI_ContextHandle* context)
```

**Description**


Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|
| napi_value value | **UIContext** object created on the ArkTS side.|
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md)* context | Pointer to the **ArkUI_ContextHandle**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_GetNodeContentFromNapiValue()

```
int32_t OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)
```

**Description**


Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|
| napi_value value | **NodeContent** object created on the ArkTS side.|
| content | Pointer to the **ArkUI_NodeContentHandle**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**Description**


Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|
| napi_value value | **DrawableDescriptor** object created on the ArkTS side.|
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | Double pointer used to receive the **ArkUI_DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue(napi_env env, napi_value value, ArkUI_DrawableDescriptor** drawableDescriptor)
```

**Description**


Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|
| napi_value value | **$r** resource object created on the ArkTS side.|
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)** drawableDescriptor | Double pointer used to receive the **ArkUI_DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_GetNavigationId()

```
ArkUI_ErrorCode OH_ArkUI_GetNavigationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the ID of the **Navigation** component where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained ID is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetNavDestinationName()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the name of the **Navigation** component where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained name is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetNavStackLength()

```
ArkUI_ErrorCode OH_ArkUI_GetNavStackLength(ArkUI_NodeHandle node, int32_t* length)
```

**Description**


Obtains the length of the navigation stack where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| int32_t* length | Length of the navigation stack. The result, if obtained successfully, is written back to this parameter.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.|

### OH_ArkUI_GetNavDestinationNameByIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex(ArkUI_NodeHandle node, int32_t index, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the page name that matches the specified index in the navigation stack where the specified node is located. The index starts from 0, which indicates the bottom of the stack.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| int32_t index | Index of the target page in the navigation stack.|
| char* buffer | Buffer to which the obtained name is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_NODE_INDEX_INVALID](capi-native-type-h.md#arkui_errorcode) if the index is invalid.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetNavDestinationId()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the ID of the **NavDestination** component where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained ID is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetNavDestinationState()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState(ArkUI_NodeHandle node, ArkUI_NavDestinationState* state)
```

**Description**


Obtains the state of the **NavDestination** component where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_NavDestinationState](capi-native-type-h.md#arkui_navdestinationstate)* state | State of the **NavDestination** component. The result, if obtained successfully, is written back to this parameter.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.|

### OH_ArkUI_GetNavDestinationIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex(ArkUI_NodeHandle node, int32_t* index)
```

**Description**


Obtains the index of the **NavDestination** component where the specified node is located in the navigation stack.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| int32_t* index | Zero-based index.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.|

### OH_ArkUI_GetNavDestinationParam()

```
napi_value OH_ArkUI_GetNavDestinationParam(ArkUI_NodeHandle node)
```

**Description**


Obtains the parameters of the **NavDestination** component where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| napi_value | Parameter object. Returns an empty value if the parameters do not exist or the specified node is null.|

### OH_ArkUI_GetRouterPageIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex(ArkUI_NodeHandle node, int32_t* index)
```

**Description**


Obtains the index of the page where the specified node is located in the page stack for routing.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| int32_t* index | One-based index.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if the node or index specified is invalid.<br>Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained, possibly because the specified node is not in the navigation stack.|

### OH_ArkUI_GetRouterPageName()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageName(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the name of the page where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained name is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetRouterPagePath()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the path to the page where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained path is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_GetRouterPageState()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageState(ArkUI_NodeHandle node, ArkUI_RouterPageState* state)
```

**Description**


Obtains the state of the page where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_RouterPageState](capi-native-type-h.md#arkui_routerpagestate)* state | State of the page. The result, if obtained successfully, is written back to this parameter.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained.|

### OH_ArkUI_GetRouterPageId()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageId(ArkUI_NodeHandle node, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**


Obtains the ID of the page where the specified node is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| char* buffer | Buffer to which the obtained ID is written.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Length of the string written to the buffer when [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned;                     Minimum size of the buffer required to hold the target when [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_GET_INFO_FAILED](capi-native-type-h.md#arkui_errorcode) if information fails to be obtained.<br>        Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the specified buffer size is smaller than the minimum buffer size required to hold the target.|

### OH_ArkUI_InitModuleForArkTSEnv()

```
ArkUI_ErrorCode OH_ArkUI_InitModuleForArkTSEnv(napi_env env)
```

**Description**


Initializes ArkUI-related APIs for the specified context environment. This function must not be called from a non-UI thread; otherwise, the program will actively abort.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if the parameter is invalid. Examples of invalid parameters include a null env pointer or failure to configure the trustlist.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.|

### OH_ArkUI_NotifyArkTSEnvDestroy()

```
void OH_ArkUI_NotifyArkTSEnvDestroy(napi_env env)
```

**Description**


Notifies that the specified context environment has been destroyed. This function must not be called from a non-UI thread; otherwise, the program will actively abort.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the Node-API environment.|

### OH_ArkUI_PostFrameCallback()

```
int32_t OH_ArkUI_PostFrameCallback(ArkUI_ContextHandle uiContext, void* userData,void (*callback)(uint64_t nanoTimestamp, uint32_t frameCount, void* userData))
```

**Description**


Registers a callback function to be executed during the next frame rendering. This function must not be called from a non-UI thread; otherwise, the program will actively abort.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| ArkUI_ContextHandle uiContext | **UIContext** object used to bind the instance.|
|  void* userData | Custom event parameter, which is passed in the callback when the event is triggered.|
| callback | Custom callback function.|
| uint64_t nanoTimestamp | Timestamp of the frame signal.|
|  uint32_t frameCount | Frame number.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-native-type-h.md#arkui_errorcode) if the **uiContext** object is invalid.<br>         Returns [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-native-type-h.md#arkui_errorcode) if the callback function is invalid.|

### OH_ArkUI_PostIdleCallback()

```
int32_t OH_ArkUI_PostIdleCallback(ArkUI_ContextHandle uiContext, void* userData,void (*callback)(uint64_t nanoTimeLeft, uint32_t frameCount, void* userData))
```

**Description**


Registers a callback function that will be executed after the next frame rendering is completed if there is more than 1 ms of idle time remaining before the next VSync signal arrives. If the remaining time is less than 1 ms, the callback will be deferred until a subsequent frame where more than 1 ms of idle time is available. If there is no next frame scheduled, one will be automatically requested.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| uiContext | **UIContext** object used to bind the instance.|
|  void* userData | Custom event parameter, which is passed in the callback when the event is triggered.|
| callback | Custom callback function.|
| uint64_t nanoTimeLeft | Remaining idle time before the next VSync signal.|
|  uint32_t frameCount | Frame number.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t (ArkUI_ContextHandle uiContext, void* userData,void (*callback) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_UI_CONTEXT_INVALID](capi-native-type-h.md#arkui_errorcode) if the **uiContext** object is invalid.<br>         Returns [ARKUI_ERROR_CODE_CALLBACK_INVALID](capi-native-type-h.md#arkui_errorcode) if the callback function is invalid.|
