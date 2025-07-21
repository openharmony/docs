# native_node_ani.h


## 概述

提供ArkTS1.2的FrameNode转换NodeHandle的方式。

> **说明：**
>
> 本模块仅适用于ArkTS1.2。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_node_ani.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 20

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_NativeModule_GetNodeHandleFromAniValue](_ark_u_i___native_module.md#oh_arkui_nativemodule_getnodehandlefromanivalue) (ani_env* env, ani_object frameNode, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*handle) | 获取ArkTS侧创建的FrameNode节点对象映射到Native侧的ArkUI_NodeHandle。  | 
| int32_t [OH_ArkUI_NativeModule_GetContextFromAniValue](_ark_u_i___native_module.md#oh_arkui_nativemodule_getcontextfromanivalue) (ani_env* env, ani_object context, [ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) \*handle) | 获取ArkTS侧创建的UIContext对象映射到Native侧的ArkUI_ContextHandle。  | 