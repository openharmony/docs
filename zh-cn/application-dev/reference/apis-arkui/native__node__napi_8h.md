# native_node_napi.h


## 概述

提供ArkTS侧的FrameNode转换NodeHandle的方式。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*handle) | 获取ArkTS侧创建的FrameNode节点对象映射到native侧的ArkUI_NodeHandle。  | 
| int32_t [OH_ArkUI_GetContextFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getcontextfromnapivalue) (napi_env env, napi_value value, [ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle) \*context) | 获取ArkTS侧创建的UIContext对象映射到native侧的ArkUI_ContextHandle。  | 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromNapiValue](_ark_u_i___native_module.md#oh_arkui_getdrawabledescriptorfromnapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*\*drawableDescriptor) |  | 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue](_ark_u_i___native_module.md#oh_arkui_getdrawabledescriptorfromresourcenapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*\*drawableDescriptor) |  | 
