# ArkUI_NativeDialogAPI_1


## 概述

ArkUI提供的Native侧自定义弹窗接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [version](_ark_u_i___native_module.md#version) |  | 
| ArkUI_NativeDialogHandle(\* [create](_ark_u_i___native_module.md#create) )() | 创建自定义弹窗并返回指向自定义弹窗的指针。  | 
| void(\* [dispose](_ark_u_i___native_module.md#dispose) )(ArkUI_NativeDialogHandle handle) | 销毁自定义弹窗。  | 
| int32_t(\* [setContent](_ark_u_i___native_module.md#setcontent) )(ArkUI_NativeDialogHandle handle, ArkUI_NodeHandle content) | 挂载自定义弹窗内容。  | 
| int32_t(\* [removeContent](_ark_u_i___native_module.md#removecontent) )(ArkUI_NativeDialogHandle handle) | 卸载自定义弹窗内容。  | 
| int32_t(\* [setContentAlignment](_ark_u_i___native_module.md#setcontentalignment) )(ArkUI_NativeDialogHandle handle, int32_t alignment, float offsetX, float offsetY) | 为自定义弹窗设置对齐方式。  | 
| int32_t(\* [resetContentAlignment](_ark_u_i___native_module.md#resetcontentalignment) )(ArkUI_NativeDialogHandle handle) | 重置setContentAlignment方法设置的属性，使用系统默认的对齐方式。  | 
| int32_t(\* [setModalMode](_ark_u_i___native_module.md#setmodalmode) )(ArkUI_NativeDialogHandle handle, bool isModal) | 设置自定义弹窗是否开启模态样式的弹窗。  | 
| int32_t(\* [setAutoCancel](_ark_u_i___native_module.md#setautocancel) )(ArkUI_NativeDialogHandle handle, bool autoCancel) | 设置自定义弹窗是否允许点击遮罩层退出。  | 
| int32_t(\* [setMask](_ark_u_i___native_module.md#setmask) )(ArkUI_NativeDialogHandle handle, uint32_t maskColor, const ArkUI_Rect \*maskRect) | 设置自定义弹窗遮罩属性。  | 
| int32_t(\* [setBackgroundColor](_ark_u_i___native_module.md#setbackgroundcolor) )(ArkUI_NativeDialogHandle handle, uint32_t backgroundColor) | 设置弹窗背景色。  | 
| int32_t(\* [setCornerRadius](_ark_u_i___native_module.md#setcornerradius) )(ArkUI_NativeDialogHandle handle, float topLeft, float topRight, float bottomLeft, float bottomRight) | 设置弹窗背板圆角半径。  | 
| int32_t(\* [setGridColumnCount](_ark_u_i___native_module.md#setgridcolumncount) )(ArkUI_NativeDialogHandle handle, int32_t gridCount) | 弹窗宽度占栅格宽度的个数。  | 
| int32_t(\* [enableCustomStyle](_ark_u_i___native_module.md#enablecustomstyle) )(ArkUI_NativeDialogHandle handle, bool enableCustomStyle) | 弹窗容器样式是否自定义。  | 
| int32_t(\* [enableCustomAnimation](_ark_u_i___native_module.md#enablecustomanimation) )(ArkUI_NativeDialogHandle handle, bool enableCustomAnimation) | 弹窗容器是否使用自定义弹窗动画。  | 
| int32_t(\* [registerOnWillDismiss](_ark_u_i___native_module.md#registeronwilldismiss) )(ArkUI_NativeDialogHandle handle, [OnWillDismissEvent](_ark_u_i___native_module.md#onwilldismissevent) eventHandler) | 当触发系统定义的返回操作、键盘ESC关闭交互操作时，如果注册该回调函数，则不会立刻关闭弹窗，是否关闭由用户自行决定。  | 
| int32_t(\* [show](_ark_u_i___native_module.md#show) )(ArkUI_NativeDialogHandle handle, bool showInSubWindow) | 显示自定义弹窗。  | 
| int32_t(\* [close](_ark_u_i___native_module.md#close) )(ArkUI_NativeDialogHandle handle) | 关闭自定义弹窗，如已关闭，则不生效。  | 
