# native_dialog.h


## 概述

提供ArkUI在Native侧的自定义弹窗接口定义集合。

**库：** libace_ndk.z.so

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


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { [DIALOG_DISMISS_BACK_PRESS](_ark_u_i___native_module.md) = 0, [DIALOG_DISMISS_TOUCH_OUTSIDE](_ark_u_i___native_module.md) } | 弹窗关闭的触发方式。  | 
