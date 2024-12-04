# native_node_napi.h


## Overview

Declares the functions used to convert FrameNodes on the ArkTS side into NodeHandles.

**Library**: libace_ndk.z.so

**File to include**: <arkui/native_node_napi.h>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*handle) | Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side. | 
| int32_t [OH_ArkUI_GetContextFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getcontextfromnapivalue) (napi_env env, napi_value value, [ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) \*context) | Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side. | 
| int32_t [OH_ArkUI_GetNodeContentFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getnodecontentfromnapivalue) (napi_env env, napi_value value, [ArkUI_NodeContentHandle](_ark_u_i___native_module.md#arkui_nodecontenthandle) \*content) | Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side. | 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getdrawabledescriptorfromnapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side. | 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue](_ark_u_i___native_module.md#oh_arkui_getdrawabledescriptorfromresourcenapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavigationId](_ark_u_i___native_module.md#oh_arkui_getnavigationid) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the **Navigation** component where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavDestinationName](_ark_u_i___native_module.md#oh_arkui_getnavdestinationname) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the name of the **Navigation** component where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavStackLength](_ark_u_i___native_module.md#oh_arkui_getnavstacklength) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t \*length) | Obtains the length of the navigation stack where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavDestinationNameByIndex](_ark_u_i___native_module.md#oh_arkui_getnavdestinationnamebyindex) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t index, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the page name that matches the specified index in the navigation stack where the specified node is located. The index starts from 0, which indicates the bottom of the stack. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavDestinationId](_ark_u_i___native_module.md#oh_arkui_getnavdestinationid) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the **NavDestination** component where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavDestinationState](_ark_u_i___native_module.md#oh_arkui_getnavdestinationstate) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_NavDestinationState](_ark_u_i___native_module.md#arkui_navdestinationstate) \*state) | Obtains the state of the **NavDestination** component where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetNavDestinationIndex](_ark_u_i___native_module.md#oh_arkui_getnavdestinationindex) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t \*index) | Obtains the index of the **NavDestination** component where the specified node is located in the navigation stack. | 
| napi_value [OH_ArkUI_GetNavDestinationParam](_ark_u_i___native_module.md#oh_arkui_getnavdestinationparam) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains the parameters of the **NavDestination** component where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetRouterPageIndex](_ark_u_i___native_module.md#oh_arkui_getrouterpageindex) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, int32_t \*index) | Obtains the index of the page where the specified node is located in the page stack for routing. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetRouterPageName](_ark_u_i___native_module.md#oh_arkui_getrouterpagename) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the name of the page where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetRouterPagePath](_ark_u_i___native_module.md#oh_arkui_getrouterpagepath) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the path to the page where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetRouterPageState](_ark_u_i___native_module.md#oh_arkui_getrouterpagestate) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_RouterPageState](_ark_u_i___native_module.md#arkui_routerpagestate) \*state) | Obtains the state of the page where the specified node is located. | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_GetRouterPageId](_ark_u_i___native_module.md#oh_arkui_getrouterpageid) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the page where the specified node is located. | 
