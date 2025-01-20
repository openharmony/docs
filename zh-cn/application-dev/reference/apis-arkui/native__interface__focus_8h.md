# native_interface_focus.h


## 概述

提供NativeFocus相关接口定义。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_interface_focus.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full 

**起始版本：** 16

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总

### 函数

| 名称 | 描述 | 
| -------- | -------- |
|[ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode)  OH_ArkUI_FocusRequest([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node); | 请求焦点。|
| void OH_ArkUI_FocusClear([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext); | 将当前焦点清除到根容器节点。 |
| void OH_ArkUI_FocusActivate([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, bool isActive, bool isAutoInactive); | 设置当前界面的焦点激活态，获焦节点显示焦点框。|
| void OH_ArkUI_FocusSetAutoTransfer([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, bool autoTransfer); | 设置页面切换时，焦点转移行为。 | 
