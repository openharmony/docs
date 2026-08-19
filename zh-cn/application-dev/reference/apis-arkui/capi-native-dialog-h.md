# native_dialog.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供ArkUI在Native侧的自定义弹窗接口定义集合，支持创建、显示、更新、关闭自定义弹窗，以及设置弹窗样式、背景、边框、阴影等属性，支持注册弹窗生命周期事件监听，适用于需要在Native侧实现灵活弹窗交互的场景。

**引用文件：** <arkui/native_dialog.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：**  <!--RP1-->[NativeDialogSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeDialogSample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md) | ArkUI_NativeDialogAPI_1 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_NativeDialogAPI_2](capi-arkui-nativemodule-arkui-nativedialogapi-2.md) | ArkUI_NativeDialogAPI_2 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_NativeDialogAPI_3](capi-arkui-nativemodule-arkui-nativedialogapi-3.md) | ArkUI_NativeDialogAPI_3 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md) | ArkUI_DialogDismissEvent | 定义弹窗关闭事件对象。 |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md) | ArkUI_CustomDialogOptions | 定义自定义弹窗的配置选项。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_DismissReason](#arkui_dismissreason) | ArkUI_DismissReason | 弹窗关闭的触发方式。 |
| [ArkUI_LevelMode](#arkui_levelmode) | ArkUI_LevelMode | 设置弹窗显示层级。 |
| [ArkUI_ImmersiveMode](#arkui_immersivemode) | ArkUI_ImmersiveMode | 指定嵌入式弹窗的蒙层覆盖区域。 |
| [OH_ArkUI_DialogDisplayModeInSubWindow](#oh_arkui_dialogdisplaymodeinsubwindow) | OH_ArkUI_DialogDisplayModeInSubWindow | 弹窗在子窗口中的显示模式。 |
| [ArkUI_DialogState](#arkui_dialogstate) | ArkUI_DialogState | 弹窗的状态。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef bool (\*ArkUI_OnWillDismissEvent)(int32_t reason)](#arkui_onwilldismissevent) | ArkUI_OnWillDismissEvent | 弹窗关闭的回调函数。 |
| [void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)](#oh_arkui_dialogdismissevent_setshouldblockdismiss) | - | 设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为，不关闭弹窗，false表示不屏蔽。 |
| [void* OH_ArkUI_DialogDismissEvent_GetUserData(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getuserdata) | - | 获取弹窗关闭事件对象中的用户自定义数据指针。 |
| [int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getdismissreason) | - | 获取弹窗关闭事件对象中的关闭原因。 |
| [int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (\*callback)(int32_t dialogId))](#oh_arkui_customdialog_opendialog) | - | 弹出自定义弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))](#oh_arkui_customdialog_updatedialog) | - | 更新自定义弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_CloseDialog(int32_t dialogId)](#oh_arkui_customdialog_closedialog) | - | 关闭自定义弹窗。 |
| [ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)](#oh_arkui_customdialog_createoptions) | - | 创建自定义弹窗配置。 |
| [void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)](#oh_arkui_customdialog_disposeoptions) | - | 销毁自定义弹窗配置。 |
| [int32_t OH_ArkUI_CustomDialog_SetLevelMode(ArkUI_CustomDialogOptions* options, ArkUI_LevelMode levelMode)](#oh_arkui_customdialog_setlevelmode) | - | 设置弹窗的显示层级。 |
| [int32_t OH_ArkUI_CustomDialog_SetLevelUniqueId(ArkUI_CustomDialogOptions* options, int32_t uniqueId)](#oh_arkui_customdialog_setleveluniqueid) | - | 设置弹窗显示层级页面下的节点id。 |
| [int32_t OH_ArkUI_CustomDialog_SetImmersiveMode(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMode immersiveMode)](#oh_arkui_customdialog_setimmersivemode) | - | 设置嵌入式弹窗蒙层的显示区域。 |
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundColor(ArkUI_CustomDialogOptions* options, uint32_t backgroundColor)](#oh_arkui_customdialog_setbackgroundcolor) | - | 设置弹窗的背景颜色。 |
| [int32_t OH_ArkUI_CustomDialog_SetCornerRadius(ArkUI_CustomDialogOptions* options, float topLeft, float topRight, float bottomLeft, float bottomRight)](#oh_arkui_customdialog_setcornerradius) | - | 设置弹窗的圆角半径。 |
| [int32_t OH_ArkUI_CustomDialog_SetBorderWidth(ArkUI_CustomDialogOptions* options, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setborderwidth) | - | 设置弹窗的边框宽度。 |
| [int32_t OH_ArkUI_CustomDialog_SetBorderColor(ArkUI_CustomDialogOptions* options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)](#oh_arkui_customdialog_setbordercolor) | - | 设置弹窗的边框颜色。 |
| [int32_t OH_ArkUI_CustomDialog_SetBorderStyle(ArkUI_CustomDialogOptions* options, int32_t top, int32_t right, int32_t bottom, int32_t left)](#oh_arkui_customdialog_setborderstyle) | - | 设置弹窗的边框样式。 |
| [int32_t OH_ArkUI_CustomDialog_SetWidth(ArkUI_CustomDialogOptions* options, float width, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setwidth) | - | 设置弹窗的背板宽度。 |
| [int32_t OH_ArkUI_CustomDialog_SetHeight(ArkUI_CustomDialogOptions* options, float height, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setheight) | - | 设置弹窗的背板高度。 |
| [int32_t OH_ArkUI_CustomDialog_SetShadow(ArkUI_CustomDialogOptions* options, ArkUI_ShadowStyle shadow)](#oh_arkui_customdialog_setshadow) | - | 设置弹窗的背板阴影。 |
| [int32_t OH_ArkUI_CustomDialog_SetCustomShadow(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* customShadow)](#oh_arkui_customdialog_setcustomshadow) | - | 设置弹窗的背板阴影。 |
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyle(ArkUI_CustomDialogOptions* options, ArkUI_BlurStyle blurStyle)](#oh_arkui_customdialog_setbackgroundblurstyle) | - | 设置弹窗的背板模糊材质。 |
| [int32_t OH_ArkUI_CustomDialog_SetAlignment(ArkUI_CustomDialogOptions* options, int32_t alignment, float offsetX, float offsetY)](#oh_arkui_customdialog_setalignment) | - | 设置弹窗的对齐模式。 |
| [int32_t OH_ArkUI_CustomDialog_SetModalMode(ArkUI_CustomDialogOptions* options, bool isModal)](#oh_arkui_customdialog_setmodalmode) | - | 设置自定义弹窗是否开启模态样式的弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_SetAutoCancel(ArkUI_CustomDialogOptions* options, bool autoCancel)](#oh_arkui_customdialog_setautocancel) | - | 设置自定义弹窗是否允许点击遮罩层退出。 |
| [int32_t OH_ArkUI_CustomDialog_SetSubwindowMode(ArkUI_CustomDialogOptions* options, bool showInSubwindow)](#oh_arkui_customdialog_setsubwindowmode) | - | 设置弹窗是否在子窗口显示此弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_SetDisplayModeInSubWindow(ArkUI_CustomDialogOptions* options, OH_ArkUI_DialogDisplayModeInSubWindow displayModeInSubWindow)](#oh_arkui_customdialog_setdisplaymodeinsubwindow) | - | 设置弹窗在子窗口中的显示模式。 |
| [int32_t OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterial(ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMaterialHandle material)](#oh_arkui_nativemodule_customdialog_setsystemmaterial) | - | 设置指定弹窗的沉浸式材质。|
| [int32_t OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterialInOptions(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMaterialHandle material)](#oh_arkui_nativemodule_customdialog_setsystemmaterialinoptions) | - | 设置弹窗参数的沉浸式材质属性。 |
| [int32_t OH_ArkUI_CustomDialog_SetMask(ArkUI_CustomDialogOptions* options, uint32_t maskColor, const ArkUI_Rect* maskRect)](#oh_arkui_customdialog_setmask) | - | 设置自定义弹窗遮罩属性。 |
| [int32_t OH_ArkUI_CustomDialog_SetKeyboardAvoidMode(ArkUI_CustomDialogOptions* options, ArkUI_KeyboardAvoidMode keyboardAvoidMode)](#oh_arkui_customdialog_setkeyboardavoidmode) | - | 设置弹窗避让键盘的模式。 |
| [int32_t OH_ArkUI_CustomDialog_SetHoverModeEnabled(ArkUI_CustomDialogOptions* options, bool enabled)](#oh_arkui_customdialog_sethovermodeenabled) | - | 设置弹窗是否响应悬停态。 |
| [int32_t OH_ArkUI_CustomDialog_SetHoverModeArea(ArkUI_CustomDialogOptions* options, ArkUI_HoverModeAreaType hoverModeAreaType)](#oh_arkui_customdialog_sethovermodearea) | - | 设置悬停态下弹窗默认展示区域。 |
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(ArkUI_DialogDismissEvent* event))](#oh_arkui_customdialog_registeronwilldismisscallback) | - | 注册系统关闭自定义弹窗的监听事件。 |
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registeronwillappearcallback) | - | 注册自定义弹窗显示动效前的监听事件。 |
| [int32_t OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registerondidappearcallback) | - | 注册自定义弹窗弹出时的监听事件。 |
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registeronwilldisappearcallback) | - | 注册自定义弹窗退出动效前的监听事件。 |
| [int32_t OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registerondiddisappearcallback) | - | 注册自定义弹窗消失时的监听事件。 |
| [int32_t OH_ArkUI_CustomDialog_GetState(ArkUI_NativeDialogHandle handle, ArkUI_DialogState* state)](#oh_arkui_customdialog_getstate) | - | 获取弹窗的状态。 |
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundBlurStyleOptions)](#oh_arkui_customdialog_setbackgroundblurstyleoptions) | - | 设置弹窗的背景模糊效果。 |
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundEffect(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundEffect)](#oh_arkui_customdialog_setbackgroundeffect) | - | 设置弹窗的背景效果参数。 |

## 枚举类型说明

### ArkUI_DismissReason

```c
enum ArkUI_DismissReason
```

**描述：**


弹窗关闭的触发方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| DIALOG_DISMISS_BACK_PRESS = 0 | 点击三键back、侧滑（左滑/右滑）、键盘ESC触发。 |
| DIALOG_DISMISS_TOUCH_OUTSIDE = 1 | 点击遮罩层触发。 |
| DIALOG_DISMISS_CLOSE_BUTTON = 2 | 点击关闭按钮。 |
| DIALOG_DISMISS_SLIDE_DOWN = 3 | 下拉关闭。 |

### ArkUI_LevelMode

```c
enum ArkUI_LevelMode
```

**描述：**


设置弹窗显示层级。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LEVEL_MODE_OVERLAY = 0 | 显示在应用最上层。 |
| ARKUI_LEVEL_MODE_EMBEDDED = 1 | 嵌入式显示在应用的页面内。 |

### ArkUI_ImmersiveMode

```c
enum ArkUI_ImmersiveMode
```

**描述：**


指定嵌入式弹窗的蒙层覆盖区域。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMMERSIVE_MODE_DEFAULT = 0 | 弹窗蒙层按照显示页面给定的布局约束显示。 |
| ARKUI_IMMERSIVE_MODE_EXTEND = 1 | 弹窗蒙层可扩展至覆盖状态栏和导航条。 |

### OH_ArkUI_DialogDisplayModeInSubWindow

```c
enum OH_ArkUI_DialogDisplayModeInSubWindow
```

**描述：**


弹窗在子窗口中的显示模式。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_DIALOG_DISPLAY_MODE_SCREEN_BASED = 0 | 弹窗在屏幕居中显示。 |
| OH_ARKUI_DIALOG_DISPLAY_MODE_WINDOW_BASED = 1 | 弹窗在应用窗口居中显示。 |

### ArkUI_DialogState

```c
enum ArkUI_DialogState
```

**描述：**


弹窗的状态。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| DIALOG_UNINITIALIZED = 0 | 未初始化，控制器未与dialog绑定时。 |
| DIALOG_INITIALIZED = 1 | 已初始化，控制器与dialog绑定后。 |
| DIALOG_APPEARING = 2 | 显示中，dialog显示动画过程中。 |
| DIALOG_APPEARED = 3 | 已显示，dialog显示动画结束。 |
| DIALOG_DISAPPEARING = 4 | 消失中，dialog消失动画过程中。 |
| DIALOG_DISAPPEARED = 5 | 已消失，dialog消失动画结束后。 |


## 函数说明

### ArkUI_OnWillDismissEvent()

```c
typedef bool (*ArkUI_OnWillDismissEvent)(int32_t reason)
```

**描述：**


弹窗关闭的回调函数。

**起始版本：** 12

**参数:**

| 参数项 | 描述 |
| -------- | -------- |
| int32_t reason | 触发弹窗关闭的原因，取值为[ArkUI_DismissReason](#arkui_dismissreason)枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回任意值都表示不关闭弹窗。 |

### OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss()

```c
void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)
```

**描述：**


设置是否需要屏蔽系统关闭弹窗行为。true表示屏蔽系统行为，不关闭弹窗；false表示不屏蔽。当弹窗中有用户未完成的重要操作（如表单填写未保存、支付确认等）时，可以通过设置shouldBlockDismiss为true来阻止用户通过点击三键back、侧滑、键盘ESC等系统方式关闭弹窗，强制用户完成操作或点击关闭按钮。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | 弹窗关闭事件对象指针。 |
| bool shouldBlockDismiss | 是否需要屏蔽系统关闭弹窗行为。true表示屏蔽系统行为，不关闭弹窗；false表示不屏蔽，允许系统关闭弹窗。 |

### OH_ArkUI_DialogDismissEvent_GetUserData()

```c
void* OH_ArkUI_DialogDismissEvent_GetUserData(ArkUI_DialogDismissEvent* event)
```

**描述：**


获取弹窗关闭事件对象中的用户自定义数据指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | 弹窗关闭事件对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 返回注册回调时传入的用户自定义数据指针，常用于在回调函数中获取上下文信息。 |

### OH_ArkUI_DialogDismissEvent_GetDismissReason()

```c
int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)
```

**描述：**


获取弹窗关闭事件对象中的关闭原因。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | 弹窗关闭事件对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 关闭原因，异常情况返回-1。<br>         [DIALOG_DISMISS_BACK_PRESS](#arkui_dismissreason) 点击三键back、侧滑（左滑/右滑）、键盘ESC触发。<br>         [DIALOG_DISMISS_TOUCH_OUTSIDE](#arkui_dismissreason) 点击遮罩层触发。<br>         [DIALOG_DISMISS_CLOSE_BUTTON](#arkui_dismissreason) 点击关闭按钮。<br>         [DIALOG_DISMISS_SLIDE_DOWN](#arkui_dismissreason) 下拉关闭。 |

### OH_ArkUI_CustomDialog_OpenDialog()

```c
int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))
```

**描述：**


弹出自定义弹窗。

**起始版本：** 19


**参数：**

| 参数项                                    | 描述 |
|----------------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void (*callback)(int32_t dialogId)                               | 开启弹窗的回调，返回弹窗ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_UpdateDialog()

```c
int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))
```

**描述：**


更新自定义弹窗。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void (*callback)(int32_t dialogId)                               | 更新弹窗的回调，返回弹窗ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_CloseDialog()

```c
int32_t OH_ArkUI_CustomDialog_CloseDialog(int32_t dialogId)
```

**描述：**


关闭自定义弹窗。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t dialogId | 需要关闭的弹窗ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_CreateOptions()

```c
ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)
```

**描述：**


创建自定义弹窗配置。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) content | 自定义弹窗的内容节点指针，类型为ArkUI_NodeHandle。 |

**返回：**

| 类型                             | 说明 |
|--------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* | 自定义弹窗配置的指针。 |

### OH_ArkUI_CustomDialog_DisposeOptions()

```c
void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)
```

**描述：**


销毁自定义弹窗配置。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 自定义弹窗配置的指针。 |

### OH_ArkUI_CustomDialog_SetLevelMode()

```c
int32_t OH_ArkUI_CustomDialog_SetLevelMode(ArkUI_CustomDialogOptions* options, ArkUI_LevelMode levelMode)
```

**描述：**


设置弹窗的显示层级。

> **说明：** 
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| [ArkUI_LevelMode](#arkui_levelmode) levelMode | 弹窗显示层级的枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetLevelUniqueId()

```c
int32_t OH_ArkUI_CustomDialog_SetLevelUniqueId(ArkUI_CustomDialogOptions* options, int32_t uniqueId)
```

**描述：**


设置弹窗显示层级页面下的节点id。

> **说明：** 
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| int32_t uniqueId | 指定节点id，会查找该节点所在页面，并将弹窗显示在该页面下。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetImmersiveMode()

```c
int32_t OH_ArkUI_CustomDialog_SetImmersiveMode(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMode immersiveMode)
```

**描述：**


设置嵌入式弹窗蒙层的显示区域。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| [ArkUI_ImmersiveMode](#arkui_immersivemode) immersiveMode | 嵌入式弹窗蒙层覆盖区域的枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundColor()

```c
int32_t OH_ArkUI_CustomDialog_SetBackgroundColor(ArkUI_CustomDialogOptions* options, uint32_t backgroundColor)
```

**描述：**


设置弹窗的背景颜色。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t backgroundColor | 弹窗背景颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetCornerRadius()

```c
int32_t OH_ArkUI_CustomDialog_SetCornerRadius(ArkUI_CustomDialogOptions* options, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**描述：**


设置弹窗的圆角半径。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float topLeft | 弹窗左上角的圆角半径，单位：vp。默认值：32vp。 |
| float topRight | 弹窗右上角的圆角半径，单位：vp。默认值：32vp。 |
| float bottomLeft | 弹窗左下角的圆角半径，单位：vp。默认值：32vp。 |
| float bottomRight | 弹窗右下角的圆角半径，单位：vp。默认值：32vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderWidth()

```c
int32_t OH_ArkUI_CustomDialog_SetBorderWidth(ArkUI_CustomDialogOptions* options, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的边框宽度。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float top | 弹窗上边框的宽度，单位：vp。 |
| float right | 弹窗右边框的宽度，单位：vp。 |
| float bottom | 弹窗下边框的宽度，单位：vp。 |
| float left | 弹窗左边框的宽度，单位：vp。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定宽度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderColor()

```c
int32_t OH_ArkUI_CustomDialog_SetBorderColor(ArkUI_CustomDialogOptions* options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```

**描述：**


设置弹窗的边框颜色。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t top | 弹窗上边框的颜色，0xARGB格式。 |
| uint32_t right | 弹窗右边框的颜色，0xARGB格式。 |
| uint32_t bottom | 弹窗下边框的颜色，0xARGB格式。 |
| uint32_t left | 弹窗左边框的颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderStyle()

```c
int32_t OH_ArkUI_CustomDialog_SetBorderStyle(ArkUI_CustomDialogOptions* options, int32_t top, int32_t right, int32_t bottom, int32_t left)
```

**描述：**


设置弹窗的边框样式。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| int32_t top | 弹窗上边框的样式，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| int32_t right | 弹窗右边框的样式，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| int32_t bottom | 弹窗下边框的样式，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| int32_t left | 弹窗左边框的样式，默认值为ARKUI_BORDER_STYLE_SOLID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetWidth()

```c
int32_t OH_ArkUI_CustomDialog_SetWidth(ArkUI_CustomDialogOptions* options, float width, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的背板宽度。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float width | 弹窗的背板宽度，单位：vp。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定宽度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHeight()

```c
int32_t OH_ArkUI_CustomDialog_SetHeight(ArkUI_CustomDialogOptions* options, float height, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的背板高度。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float height | 弹窗的背板高度，单位：vp。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定高度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetShadow()

```c
int32_t OH_ArkUI_CustomDialog_SetShadow(ArkUI_CustomDialogOptions* options, ArkUI_ShadowStyle shadow)
```

**描述：**


设置弹窗的背板阴影。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_ShadowStyle](capi-native-type-visual-h.md#arkui_shadowstyle) shadow | 弹窗的背板阴影样式，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetCustomShadow()

```c
int32_t OH_ArkUI_CustomDialog_SetCustomShadow(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* customShadow)
```

**描述：**


设置弹窗的背板阴影。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* customShadow | 弹窗的自定义阴影参数，格式与[ArkUI_NodeAttributeType](./capi-native-node-h.md#arkui_nodeattributetype)中的NODE_CUSTOM_SHADOW属性一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyle()

```c
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyle(ArkUI_CustomDialogOptions* options, ArkUI_BlurStyle blurStyle)
```

**描述：**


设置弹窗的背板模糊材质。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_BlurStyle](capi-native-type-visual-h.md#arkui_blurstyle) blurStyle | 弹窗的背板模糊材质，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetAlignment()

```c
int32_t OH_ArkUI_CustomDialog_SetAlignment(ArkUI_CustomDialogOptions* options, int32_t alignment, float offsetX, float offsetY)
```

**描述：**


设置弹窗的对齐模式。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| int32_t alignment | 弹窗的对齐模式，参数类型[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)。 |
| float offsetX | 弹窗的水平偏移量，浮点型，单位：vp。 |
| float offsetY | 弹窗的垂直偏移量，浮点型，单位：vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetModalMode()

```c
int32_t OH_ArkUI_CustomDialog_SetModalMode(ArkUI_CustomDialogOptions* options, bool isModal)
```

**描述：**


设置自定义弹窗是否开启模态窗口模式。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool isModal | 设置是否开启模态窗口模式。模态窗口模式有蒙层，非模态窗口模式无蒙层。设置为true表示开启模态窗口模式。设置为false表示关闭模态窗口模式。<br/>默认值：false |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetAutoCancel()

```c
int32_t OH_ArkUI_CustomDialog_SetAutoCancel(ArkUI_CustomDialogOptions* options, bool autoCancel)
```

**描述：**


设置是否允许通过点击遮罩层退出自定义弹窗。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool autoCancel | 是否允许点击遮罩层退出弹窗。true表示允许退出，false表示不允许退出。<br/>默认值：true |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetSubwindowMode()

```c
int32_t OH_ArkUI_CustomDialog_SetSubwindowMode(ArkUI_CustomDialogOptions* options, bool showInSubwindow)
```

**描述：**


设置弹窗是否在子窗口显示。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。
>
> 配合[OH_ArkUI_CustomDialog_SetDisplayModeInSubWindow](#oh_arkui_customdialog_setdisplaymodeinsubwindow)方法使用时，可进一步设置弹窗在子窗口中的显示模式。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool showInSubwindow | 是否在子窗口显示弹窗。值为true：弹窗可以显示在主窗口外，独立子窗口。值为false：弹窗显示在应用内，非独立子窗口。<br/>默认值：false|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterial()

```c
int32_t OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterial(ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMaterialHandle material)
```

**描述：**


设置指定弹窗的沉浸式材质。沉浸式材质根据设备算力等级分为不同等级。材质等级由[ArkUI_MaterialLevel](./capi-native-material-h.md#arkui_materiallevel)定义，可通过[OH_ArkUI_NativeModule_GetGlobalMaterialLevel](./capi-native-material-h.md#oh_arkui_nativemodule_getglobalmateriallevel)获取。在高算力和中算力设备上，会影响材质层的滤镜效果和阴影（[OH_ArkUI_CustomDialog_SetShadow](./capi-native-dialog-h.md#oh_arkui_customdialog_setshadow)或[OH_ArkUI_CustomDialog_SetCustomShadow](./capi-native-dialog-h.md#oh_arkui_customdialog_setcustomshadow)）、背景模糊[OH_ArkUI_CustomDialog_SetBackgroundBlurStyle](./capi-native-dialog-h.md#oh_arkui_customdialog_setbackgroundblurstyle)、背景效果[OH_ArkUI_CustomDialog_SetBackgroundEffect](./capi-native-dialog-h.md#oh_arkui_customdialog_setbackgroundeffect)效果。在低算力设备上，会影响背景颜色[OH_ArkUI_CustomDialog_SetBackgroundColor](./capi-native-dialog-h.md#oh_arkui_customdialog_setbackgroundcolor)、背景模糊[OH_ArkUI_CustomDialog_SetBackgroundBlurStyle](./capi-native-dialog-h.md#oh_arkui_customdialog_setbackgroundblurstyle)、背景效果[OH_ArkUI_CustomDialog_SetBackgroundEffect](./capi-native-dialog-h.md#oh_arkui_customdialog_setbackgroundeffect)、边框颜色[OH_ArkUI_CustomDialog_SetBorderColor](./capi-native-dialog-h.md#oh_arkui_customdialog_setbordercolor)、边框宽度[OH_ArkUI_CustomDialog_SetBorderWidth](./capi-native-dialog-h.md#oh_arkui_customdialog_setborderwidth)和阴影（[OH_ArkUI_CustomDialog_SetShadow](./capi-native-dialog-h.md#oh_arkui_customdialog_setshadow)或[OH_ArkUI_CustomDialog_SetCustomShadow](./capi-native-dialog-h.md#oh_arkui_customdialog_setcustomshadow)）效果。依据设备算力档位自动生效交互形变和流光效果，高算力设备生效交互形变和流光效果，中算力设备生效交互形变效果，低算力设备不生效。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | 指向自定义弹窗控制器的指针。 |
| [ArkUI_ImmersiveMaterialHandle](capi-arkui-nativemodule-arkui-immersivematerialhandle.md) material | 指向沉浸式材质对象的指针。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterialInOptions()

```c
int32_t OH_ArkUI_NativeModule_CustomDialog_SetSystemMaterialInOptions(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMaterialHandle material)
```

**描述：**


设置弹窗参数的沉浸式材质属性。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向弹窗参数对象的指针。 |
| [ArkUI_ImmersiveMaterialHandle](capi-arkui-nativemodule-arkui-immersivematerialhandle.md) material | 指向沉浸式材质对象的指针。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetDisplayModeInSubWindow()

```c
int32_t OH_ArkUI_CustomDialog_SetDisplayModeInSubWindow(ArkUI_CustomDialogOptions* options, OH_ArkUI_DialogDisplayModeInSubWindow displayModeInSubWindow)
```

**描述：**


设置弹窗在子窗口中的显示模式。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。
>
> 本方法仅在弹窗通过[OH_ArkUI_CustomDialog_SetSubwindowMode](#oh_arkui_customdialog_setsubwindowmode)设置为子窗口显示时生效。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [OH_ArkUI_DialogDisplayModeInSubWindow](#oh_arkui_dialogdisplaymodeinsubwindow) displayModeInSubWindow | 弹窗在子窗口中的显示模式，类型为[OH_ArkUI_DialogDisplayModeInSubWindow](#oh_arkui_dialogdisplaymodeinsubwindow)。<br/>默认值：OH_ARKUI_DIALOG_DISPLAY_MODE_SCREEN_BASED |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetMask()

```c
int32_t OH_ArkUI_CustomDialog_SetMask(ArkUI_CustomDialogOptions* options, uint32_t maskColor, const ArkUI_Rect* maskRect)
```

**描述：**


设置自定义弹窗遮罩属性。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t maskColor | 弹窗的遮罩颜色，0xARGB格式。 |
| [const ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)* maskRect | 遮罩层区域范围的指针，遮罩层区域内的事件不透传，在遮罩层区域外的事件透传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetKeyboardAvoidMode()

```c
int32_t OH_ArkUI_CustomDialog_SetKeyboardAvoidMode(ArkUI_CustomDialogOptions* options, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```

**描述：**


设置弹窗避让键盘的模式。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_KeyboardAvoidMode](capi-native-type-h.md#arkui_keyboardavoidmode) keyboardAvoidMode | 键盘避让模式，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHoverModeEnabled()

```c
int32_t OH_ArkUI_CustomDialog_SetHoverModeEnabled(ArkUI_CustomDialogOptions* options, bool enabled)
```

**描述：**


设置弹窗是否响应悬停态。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool enabled | 是否响应悬停态。true表示响应，false表示不响应。默认值：false |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHoverModeArea()

```c
int32_t OH_ArkUI_CustomDialog_SetHoverModeArea(ArkUI_CustomDialogOptions* options, ArkUI_HoverModeAreaType hoverModeAreaType)
```

**描述：**


设置悬停态下弹窗默认展示区域。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_HoverModeAreaType](capi-native-type-h.md#arkui_hovermodeareatype) hoverModeAreaType | 悬停态区域，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback()

```c
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(ArkUI_DialogDismissEvent* event))
```

**描述：**


注册系统关闭自定义弹窗的监听事件。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| void (\*callback)(ArkUI_DialogDismissEvent\* event) | 监听自定义弹窗关闭的回调事件。<br> - event: 回调函数的入参，捕获关闭原因。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback()

```c
int32_t OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗显示动效前的监听事件。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| void (\*callback)(void\* userData) | 弹窗显示动效前的事件回调。入参userData为用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback()

```c
int32_t OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗弹出时的监听事件。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| void (\*callback)(void\* userData) | 弹窗弹出后的事件回调。入参userData为用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback()

```c
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗退出动效前的监听事件。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| void (\*callback)(void\* userData) | 弹窗退出动效前的事件回调。入参userData为用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback()

```c
int32_t OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗消失时的监听事件。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| void (\*callback)(void\* userData) | 弹窗消失时的事件回调。入参userData为用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_GetState()

```c
int32_t OH_ArkUI_CustomDialog_GetState(ArkUI_NativeDialogHandle handle, ArkUI_DialogState* state)
```

**描述：**


获取弹窗的状态。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | 指向自定义弹窗控制器的指针。 |
| [ArkUI_DialogState](#arkui_dialogstate)* state | 自定义弹窗的状态指针，用于接收返回的状态值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions()

```c
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```

**描述：**


设置弹窗的背景模糊效果。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundBlurStyleOptions | 弹窗的背景模糊效果。参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式：<br>        .value[0].i32：表示深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。<br>        .value[1]?.i32：表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。<br>        .value[2]?.f32：表示模糊效果程度，取[0.0,1.0]范围内的值，超出有效值区间时，小于0.0取0.0，大于1.0取1.0。<br>        .value[3]?.u32：表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]，超出有效值范围，取0。<br>        .value[4]?.u32：表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]，超出有效值范围，取0。<br>        .value[5]?.i32：表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](capi-native-type-visual-h.md#arkui_blurstyleactivepolicy)枚举值。<br>        .value[6]?.u32：表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xARGB类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundEffect()

```c
int32_t OH_ArkUI_CustomDialog_SetBackgroundEffect(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundEffect)
```

**描述：**


设置弹窗的背景效果参数。

> **说明：**
>
> 本方法需要在调用[OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog)方法之前调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundEffect | 弹窗的背景效果参数。参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式：<br>        .value[0].f32：表示模糊半径，单位为vp。<br>        .value[1]?.f32：表示饱和度。<br>        .value[2]?.f32：表示亮度。<br>        .value[3]?.u32：表示颜色，0xARGB类型。<br>        .value[4]?.i32：表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。<br>        .value[5]?.u32：表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]，超出有效值范围，取0。<br>        .value[6]?.u32：表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]，超出有效值范围，取0。<br>        .value[7]?.i32：表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](capi-native-type-visual-h.md#arkui_blurstyleactivepolicy)枚举值。<br>        .value[8]?.u32：表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xARGB类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |


