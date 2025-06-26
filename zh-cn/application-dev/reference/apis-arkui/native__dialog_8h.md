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
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_3](_ark_u_i___native_dialog_a_p_i__3.md) | ArkUI提供的Native侧自定义弹窗接口集合，范围为ArkUI_NativeDialogAPI_3。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent)) (int32_t reason) | 弹窗关闭的回调函数。  |
| typedef struct [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) | 定义弹窗关闭事件对象。  |
| typedef struct [ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) [ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) | 定义自定义弹窗的内容对象。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { DIALOG_DISMISS_BACK_PRESS = 0, DIALOG_DISMISS_TOUCH_OUTSIDE, DIALOG_DISMISS_CLOSE_BUTTON, DIALOG_DISMISS_SLIDE_DOWN } | 弹窗关闭的触发方式。  |
| [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) { ARKUI_LEVEL_MODE_OVERLAY = 0, ARKUI_LEVEL_MODE_EMBEDDED } | 设置弹窗显示层级。  |
| [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) { ARKUI_IMMERSIVE_MODE_DEFAULT = 0, ARKUI_IMMERSIVE_MODE_EXTEND } | 指定嵌入式弹窗的蒙层覆盖区域。  |
| [ArkUI_DialogState](_ark_u_i___native_module.md#arkui_dialogstate) { DIALOG_UNINITIALIZED = 0, DIALOG_INITIALIZED, DIALOG_APPEARING, DIALOG_APPEARED, DIALOG_DISAPPEARING, DIALOG_DISAPPEARED } | 枚举对话框的状态。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| void [OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_setshouldblockdismiss) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event, bool shouldBlockDismiss) | 设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为不关闭弹窗，false表示不屏蔽。  |
| void \* [OH_ArkUI_DialogDismissEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getuserdata) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取弹窗关闭事件对象中的用户自定义数据指针。  |
| int32_t [OH_ArkUI_DialogDismissEvent_GetDismissReason](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getdismissreason) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | 获取交互式关闭事件指针中的关闭原因。  |
| int32_t [OH_ArkUI_CustomDialog_OpenDialog](_ark_u_i___native_module.md#oh_arkui_customdialog_opendialog) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void (\*callback)(int32_t dialogId)) | 弹出自定义弹窗。  |
| int32_t [OH_ArkUI_CustomDialog_UpdateDialog](_ark_u_i___native_module.md#oh_arkui_customdialog_updatedialog) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void (\*callback)(int32_t dialogId)) | 更新自定义弹窗。  |
| int32_t [OH_ArkUI_CustomDialog_CloseDialog](_ark_u_i___native_module.md#oh_arkui_customdialog_closedialog) (int32_t dialogId) | 关闭自定义弹窗。  |
| ArkUI_CustomDialogOptions\* [OH_ArkUI_CustomDialog_CreateOptions](_ark_u_i___native_module.md#oh_arkui_customdialog_createoptions) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) content) | 创建自定义弹窗options。  |
| void [OH_ArkUI_CustomDialog_DisposeOptions](_ark_u_i___native_module.md#oh_arkui_customdialog_disposeoptions) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options) | 销毁自定义弹窗options。  |
| int32_t [OH_ArkUI_CustomDialog_SetLevelMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setlevelmode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) levelMode) | 设置弹窗的显示层级。  |
| int32_t [OH_ArkUI_CustomDialog_SetLevelUniqueId](_ark_u_i___native_module.md#oh_arkui_customdialog_setleveluniqueid) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, int32_t uniqueId) | 设置弹窗显示层级页面下的节点id。  |
| int32_t [OH_ArkUI_CustomDialog_SetImmersiveMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setimmersivemode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) immersiveMode) | 设置嵌入式弹窗蒙层的显示区域。  |
| int32_t [OH_ArkUI_CustomDialog_SetBackgroundColor](_ark_u_i___native_module.md#oh_arkui_customdialog_setbackgroundcolor) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, uint32_t backgroundColor) | 设置弹窗的背景颜色。  |
| int32_t [OH_ArkUI_CustomDialog_SetCornerRadius](_ark_u_i___native_module.md#oh_arkui_customdialog_setcornerradius) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, float topLeft, float topRight, float bottomLeft, float bottomRight) | 设置弹窗的圆角半径。  |
| int32_t [OH_ArkUI_CustomDialog_SetBorderWidth](_ark_u_i___native_module.md#oh_arkui_customdialog_setborderwidth) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, float top, float right, float bottom, float left, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的边框宽度。  |
| int32_t [OH_ArkUI_CustomDialog_SetBorderColor](_ark_u_i___native_module.md#oh_arkui_customdialog_setbordercolor) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left) | 设置弹窗的边框颜色。  |
| int32_t [OH_ArkUI_CustomDialog_SetBorderStyle](_ark_u_i___native_module.md#oh_arkui_customdialog_setborderstyle) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, int32_t top, int32_t right, int32_t bottom, int32_t left) | 设置弹窗的边框样式。  |
| int32_t [OH_ArkUI_CustomDialog_SetWidth](_ark_u_i___native_module.md#oh_arkui_customdialog_setwidth) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, float width, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的背板宽度。  |
| int32_t [OH_ArkUI_CustomDialog_SetHeight](_ark_u_i___native_module.md#oh_arkui_customdialog_setheight) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, float height, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的背板高度。  |
| int32_t [OH_ArkUI_CustomDialog_SetShadow](_ark_u_i___native_module.md#oh_arkui_customdialog_setshadow) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_ShadowStyle](_ark_u_i___native_module.md#arkui_shadowstyle) shadow) | 设置弹窗的背板阴影。  |
| int32_t [OH_ArkUI_CustomDialog_SetCustomShadow](_ark_u_i___native_module.md#oh_arkui_customdialog_setcustomshadow) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem) \*customShadow) | 设置弹窗的自定义阴影。  |
| int32_t [OH_ArkUI_CustomDialog_SetBackgroundBlurStyle](_ark_u_i___native_module.md#oh_arkui_customdialog_setbackgroundblurstyle) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_BlurStyle](_ark_u_i___native_module.md#arkui_blurstyle) blurStyle) | 设置弹窗的背板模糊材质。  |
| int32_t [OH_ArkUI_CustomDialog_SetAlignment](_ark_u_i___native_module.md#oh_arkui_customdialog_setalignment) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, int32_t alignment, float offsetX, float offsetY) | 设置弹窗的对齐模式。  |
| int32_t [OH_ArkUI_CustomDialog_SetModalMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setmodalmode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, bool isModal) | 设置自定义弹窗是否开启模态样式的弹窗。  |
| int32_t [OH_ArkUI_CustomDialog_SetAutoCancel](_ark_u_i___native_module.md#oh_arkui_customdialog_setautocancel) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, bool autoCancel) | 设置自定义弹窗是否允许点击遮罩层退出。  |
| int32_t [OH_ArkUI_CustomDialog_SetSubwindowMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setsubwindowmode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, bool showInSubwindow) | 设置弹窗是否在子窗口显示此弹窗。  |
| int32_t [OH_ArkUI_CustomDialog_SetMask](_ark_u_i___native_module.md#oh_arkui_customdialog_setmask) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, uint32_t maskColor, const [ArkUI_Rect](_ark_u_i___rect.md#arkui_rect) \*maskRect) | 设置自定义弹窗遮罩属性。  |
| int32_t [OH_ArkUI_CustomDialog_SetKeyboardAvoidMode](_ark_u_i___native_module.md#oh_arkui_customdialog_setkeyboardavoidmode) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_KeyboardAvoidMode](_ark_u_i___native_module.md#arkui_keyboardavoidmode) keyboardAvoidMode) | 设置弹窗避让键盘的模式。  |
| int32_t [OH_ArkUI_CustomDialog_SetHoverModeEnabled](_ark_u_i___native_module.md#oh_arkui_customdialog_sethovermodeenabled) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, bool enabled) | 设置弹窗是否响应悬停态。  |
| int32_t [OH_ArkUI_CustomDialog_SetHoverModeArea](_ark_u_i___native_module.md#oh_arkui_customdialog_sethovermodearea) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, [ArkUI_HoverModeAreaType](_ark_u_i___native_module.md#arkui_hovermodeareatype) hoverModeAreaType) | 设置悬停态下弹窗默认展示区域。  |
| int32_t [OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback](_ark_u_i___native_module.md#oh_arkui_customdialog_registeronwilldismisscallback) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void\* userData, void (\*callback)([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event)) | 注册系统关闭自定义弹窗的监听事件。  |
| int32_t [OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback](_ark_u_i___native_module.md#oh_arkui_customdialog_registeronwillappearcallback) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void\* userData, void (\*callback)(void\* userData)) | 注册自定义弹窗显示动效前的监听事件。  |
| int32_t [OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback](_ark_u_i___native_module.md#oh_arkui_customdialog_registerondidappearcallback) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void\* userData, void (\*callback)(void\* userData)) | 注册自定义弹窗弹出时的监听事件。  |
| int32_t [OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback](_ark_u_i___native_module.md#oh_arkui_customdialog_registeronwilldisappearcallback) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void\* userData, void (\*callback)(void\* userData)) | 注册自定义弹窗退出动效前的监听事件。  |
| int32_t [OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback](_ark_u_i___native_module.md#oh_arkui_customdialog_registerondiddisappearcallback) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, void\* userData, void (\*callback)(void\* userData)) | 注册自定义弹窗消失时的监听事件。  |
| int32_t [OH_ArkUI_CustomDialog_GetState](_ark_u_i___native_module.md#oh_arkui_customdialog_getstate) ([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) \handle, [ArkUI_DialogState](_ark_u_i___native_module.md#arkui_dialogstate) \*state) | 获取弹窗的状态。  |
| int32_t [OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions](_ark_u_i___native_module.md#oh_arkui_customdialog_setbackgroundblurstyleoptions) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem) \*backgroundBlurStyleOptions) | 设置弹窗的背景模糊效果。  |
| int32_t [OH_ArkUI_CustomDialog_SetBackgroundEffect](_ark_u_i___native_module.md#oh_arkui_customdialog_setbackgroundeffect) ([ArkUI_CustomDialogOptions](_ark_u_i___native_module.md#arkui_customdialogoptions) \*options, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem) \*backgroundEffect) | 设置弹窗的背景效果参数。 |