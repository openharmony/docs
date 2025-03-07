# native_dialog.h


## 概述

提供ArkUI在Native侧的自定义弹窗接口定义集合。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_dialog.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | ArkUI提供的Native侧自定义弹窗接口集合，范围为ArkUI_NativeDialogAPI_1。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_2](_ark_u_i___native_dialog_a_p_i__2.md) | ArkUI提供的Native侧自定义弹窗接口集合，范围为ArkUI_NativeDialogAPI_2。  |


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent)) (int32_t reason) | 弹窗关闭的回调函数。  | 
| typedef struct [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) | 定义弹窗关闭事件对象。  | 
| typedef struct [ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) [ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) | 定义自定义弹窗的内容对象。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { [DIALOG_DISMISS_BACK_PRESS](_ark_u_i___native_module.md) = 0, [DIALOG_DISMISS_TOUCH_OUTSIDE](_ark_u_i___native_module.md), [DIALOG_DISMISS_CLOSE_BUTTON](_ark_u_i___native_module.md), [DIALOG_DISMISS_SLIDE_DOWN](_ark_u_i___native_module.md) } | 弹窗关闭的触发方式。  | 
| [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) { [ARKUI_LEVEL_MODE_OVERLAY](_ark_u_i___native_module.md) = 0, [ARKUI_LEVEL_MODE_EMBEDDED](_ark_u_i___native_module.md) } | 设置弹窗显示层级。  |
| [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) { [ARKUI_IMMERSIVE_MODE_DEFAULT](_ark_u_i___native_module.md) = 0, [ARKUI_IMMERSIVE_MODE_EXTEND](_ark_u_i___native_module.md) } | 指定嵌入式弹窗的蒙层覆盖区域。  |


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_setshouldblockdismiss) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event, bool shouldBlockDismiss) | 设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为不关闭弹窗，false表示不屏蔽。  | 
| void \* [OH_ArkUI_DialogDismissEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getuserdata) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取弹窗关闭事件对象中的用户自定义数据指针。  | 
| int32_t [OH_ArkUI_DialogDismissEvent_GetDismissReason](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getdismissreason) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取交互式关闭事件指针中的关闭原因。  | 
| int32_t [OH_ArkUI_CustomDialog_OpenDialog](_ark_u_i___native_module.md#oh_arkui_customdialog_opendialog) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void (\*callback)(int32_t dialogId)) | 弹出自定义弹窗。  |
| int32_t [OH_ArkUI_CustomDialog_CloseDialog](_ark_u_i___native_module.md#oh_arkui_customdialog_closedialog) (int32_t dialogId) | 关闭自定义弹窗。  |
| ArkUI_CustomDialogOptions\* [OH_ArkUI_CustomDialog_CreateOptions](_ark_u_i___native_module.md#oh_arkui_customdialog_createoptions) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) content) | 创建自定义弹窗options。  |
| void [OH_ArkUI_CustomDialog_DisposeOptions](_ark_u_i___native_module.md#oh_arkui_customdialog_disposeoptions) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options) | 销毁自定义弹窗options。  |
| int32_t [OH_ArkUI_CustomDialog_SetLevelMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setlevelmode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) levelMode) | 设置弹窗的显示层级。  |
| int32_t [OH_ArkUI_CustomDialog_SetLevelUniqueId](_ark_u_i___native_module.md#oh_arkui_customdialog_setleveluniqueid) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, int32_t uniqueId) | 设置弹窗显示层级页面下的节点id。  |
| int32_t [OH_ArkUI_CustomDialog_SetImmersiveMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setimmersivemode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) immersiveMode) | 设置嵌入式弹窗蒙层的显示区域。  |
