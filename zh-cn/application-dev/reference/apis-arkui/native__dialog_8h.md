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
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | ArkUI提供的Native侧自定义弹窗接口集合。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent)) (int32_t reason) | 弹窗关闭的回调函数。  | 
| typedef struct [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) | 定义弹窗关闭事件对象。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { [DIALOG_DISMISS_BACK_PRESS](_ark_u_i___native_module.md) = 0, [DIALOG_DISMISS_TOUCH_OUTSIDE](_ark_u_i___native_module.md), [DIALOG_DISMISS_CLOSE_BUTTON](_ark_u_i___native_module.md), [DIALOG_DISMISS_SLIDE_DOWN](_ark_u_i___native_module.md) } | 弹窗关闭的触发方式。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_setshouldblockdismiss) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event, bool shouldBlockDismiss) | 设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为不关闭弹窗，false表示不屏蔽。  | 
| void \* [OH_ArkUI_DialogDismissEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getuserdata) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取弹窗关闭事件对象中的用户自定义数据指针。  | 
| int32_t [OH_ArkUI_DialogDismissEvent_GetDismissReason](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getdismissreason) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取交互式关闭事件指针中的关闭原因。  | 
