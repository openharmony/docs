# native_dialog.h

## 概述

提供ArkUI在Native侧的自定义弹窗接口定义集合。

**引用文件：** <arkui/native_dialog.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md) | ArkUI_NativeDialogAPI_1 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_NativeDialogAPI_2](capi-arkui-nativemodule-arkui-nativedialogapi-2.md) | ArkUI_NativeDialogAPI_2 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_NativeDialogAPI_3](capi-arkui-nativemodule-arkui-nativedialogapi-3.md) | ArkUI_NativeDialogAPI_3 | ArkUI提供的Native侧自定义弹窗接口集合。 |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md) | ArkUI_DialogDismissEvent | 定义弹窗关闭事件对象。 |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md) | ArkUI_CustomDialogOptions | 定义自定义弹窗的内容对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_DismissReason](#arkui_dismissreason) | ArkUI_DismissReason | 弹窗关闭的触发方式。 |
| [ArkUI_LevelMode](#arkui_levelmode) | ArkUI_LevelMode | 设置弹窗显示层级。 |
| [ArkUI_ImmersiveMode](#arkui_immersivemode) | ArkUI_ImmersiveMode | 指定嵌入式弹窗的蒙层覆盖区域。 |
| [ArkUI_DialogState](#arkui_dialogstate) | ArkUI_DialogState | 枚举对话框的状态。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef bool (\*ArkUI_OnWillDismissEvent)(int32_t reason)](#arkui_onwilldismissevent) | ArkUI_OnWillDismissEvent | 弹窗关闭的回调函数。 |
| [void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)](#oh_arkui_dialogdismissevent_setshouldblockdismiss) | - | 设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为不关闭弹窗，false表示不屏蔽。 |
| [void* OH_ArkUI_DialogDismissEvent_GetUserData(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getuserdata) | - | 获取弹窗关闭事件对象中的用户自定义数据指针。 |
| [int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getdismissreason) | - | 获取交互式关闭事件指针中的关闭原因。 |
| [int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (\*callback)(int32_t dialogId))](#oh_arkui_customdialog_opendialog) | - | 弹出自定义弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options)](#oh_arkui_customdialog_updatedialog) | - | 更新自定义弹窗。 |
| [int32_t OH_ArkUI_CustomDialog_CloseDialog(int32_t dialogId)](#oh_arkui_customdialog_closedialog) | - | 关闭自定义弹窗。 |
| [ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)](#oh_arkui_customdialog_createoptions) | - | 创建自定义弹窗options。 |
| [void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)](#oh_arkui_customdialog_disposeoptions) | - | 销毁自定义弹窗options. |
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

```
enum ArkUI_DismissReason
```

**描述：**


弹窗关闭的触发方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| DIALOG_DISMISS_BACK_PRESS = 0 | 系统定义的返回操作、键盘ESC触发。 |
| DIALOG_DISMISS_TOUCH_OUTSIDE | 点击遮障层触发。 |
| DIALOG_DISMISS_CLOSE_BUTTON | 点击关闭按钮。 |
| DIALOG_DISMISS_SLIDE_DOWN | 下拉关闭。 |

### ArkUI_LevelMode

```
enum ArkUI_LevelMode
```

**描述：**


设置弹窗显示层级。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LEVEL_MODE_OVERLAY = 0 | 显示在应用最上层。 |
| ARKUI_LEVEL_MODE_EMBEDDED | 嵌入式显示在应用的页面内。 |

### ArkUI_ImmersiveMode

```
enum ArkUI_ImmersiveMode
```

**描述：**


指定嵌入式弹窗的蒙层覆盖区域。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMMERSIVE_MODE_DEFAULT = 0 | 弹窗蒙层按照显示页面给定的布局约束显示。 |
| ARKUI_IMMERSIVE_MODE_EXTEND | 弹窗蒙层可扩展至覆盖状态栏和导航条。 |

### ArkUI_DialogState

```
enum ArkUI_DialogState
```

**描述：**


枚举对话框的状态。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| DIALOG_UNINITIALIZED = 0 | 未初始化，控制器未与dialog绑定时。 |
| DIALOG_INITIALIZED | 已初始化，控制器与dialog绑定后。 |
| DIALOG_APPEARING | 显示中，dialog显示动画过程中。 |
| DIALOG_APPEARED | 已显示，dialog显示动画结束。 |
| DIALOG_DISAPPEARING | 消失中，dialog消失动画过程中。 |
| DIALOG_DISAPPEARED | 已消失，dialog消失动画结束后。 |


## 函数说明

### ArkUI_OnWillDismissEvent()

```
typedef bool (*ArkUI_OnWillDismissEvent)(int32_t reason)
```

**描述：**


弹窗关闭的回调函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| reason | 触发弹窗关闭的原因。 |

### OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss()

```
void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)
```

**描述：**


设置是否需要屏蔽系统关闭弹窗行为，true表示屏蔽系统行为不关闭弹窗，false表示不屏蔽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | 弹窗关闭事件对象指针。 |
| bool shouldBlockDismiss | 实现需要屏蔽系统关闭弹窗行为。 |

### OH_ArkUI_DialogDismissEvent_GetUserData()

```
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
| void* | 用户自定义数据指针。 |

### OH_ArkUI_DialogDismissEvent_GetDismissReason()

```
int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)
```

**描述：**


获取交互式关闭事件指针中的关闭原因。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | 弹窗关闭事件对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 关闭原因，异常情况返回-1。<br>         [DIALOG_DISMISS_BACK_PRESS](capi-native-dialog-h.md#arkui_dismissreason) 对应点击三键back、侧滑（左滑/右滑）、键盘ESC关闭。<br>         [DIALOG_DISMISS_TOUCH_OUTSIDE](capi-native-dialog-h.md#arkui_dismissreason) 点击遮障层时。<br>         [DIALOG_DISMISS_CLOSE_BUTTON](capi-native-dialog-h.md#arkui_dismissreason) 点击关闭按钮。<br>         [DIALOG_DISMISS_SLIDE_DOWN](capi-native-dialog-h.md#arkui_dismissreason) 下拉关闭。 |

### OH_ArkUI_CustomDialog_OpenDialog()

```
int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))
```

**描述：**


弹出自定义弹窗。

**起始版本：** 19


**参数：**

| 参数项                                    | 描述 |
|----------------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| callback                               | 开启弹窗的回调，返回入参是弹窗ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_UpdateDialog()

```
int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options)
```

**描述：**


更新自定义弹窗。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_CloseDialog()

```
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
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_CreateOptions()

```
ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)
```

**描述：**


创建自定义弹窗options。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) content | 自定义弹窗的内容。 |

**返回：**

| 类型                             | 说明 |
|--------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* | 自定义弹窗options的指针。 |

### OH_ArkUI_CustomDialog_DisposeOptions()

```
void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)
```

**描述：**


销毁自定义弹窗options.

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 自定义弹窗options的指针. |

### OH_ArkUI_CustomDialog_SetLevelMode()

```
int32_t OH_ArkUI_CustomDialog_SetLevelMode(ArkUI_CustomDialogOptions* options, ArkUI_LevelMode levelMode)
```

**描述：**


设置弹窗的显示层级。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| [ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode) levelMode | 显示层级的枚举值， 类型为[ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetLevelUniqueId()

```
int32_t OH_ArkUI_CustomDialog_SetLevelUniqueId(ArkUI_CustomDialogOptions* options, int32_t uniqueId)
```

**描述：**


设置弹窗显示层级页面下的节点id。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| int32_t uniqueId | 指定节点id，会查找该节点所在页面，并将弹窗显示在该页面下。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetImmersiveMode()

```
int32_t OH_ArkUI_CustomDialog_SetImmersiveMode(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMode immersiveMode)
```

**描述：**


设置嵌入式弹窗蒙层的显示区域。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 指向自定义弹窗options的指针。 |
| [ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode) immersiveMode | 显示区域类型的枚举值， 类型为[ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundColor()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundColor(ArkUI_CustomDialogOptions* options, uint32_t backgroundColor)
```

**描述：**


设置弹窗的背景颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t backgroundColor | 弹窗背景颜色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetCornerRadius()

```
int32_t OH_ArkUI_CustomDialog_SetCornerRadius(ArkUI_CustomDialogOptions* options, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**描述：**


设置弹窗的圆角半径。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float topLeft | 弹窗左上角的圆角半径。 |
| float topRight | 弹窗右上角的圆角半径。 |
| float bottomLeft | 弹窗左下角的圆角半径。 |
| float bottomRight | 弹窗右下角的圆角半径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderWidth()

```
int32_t OH_ArkUI_CustomDialog_SetBorderWidth(ArkUI_CustomDialogOptions* options, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的边框宽度。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float top | 弹窗上边框的宽度。 |
| float right | 弹窗右边框的宽度。 |
| float bottom | 弹窗下边框的宽度。 |
| float left | 弹窗左边框的宽度。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定宽度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderColor()

```
int32_t OH_ArkUI_CustomDialog_SetBorderColor(ArkUI_CustomDialogOptions* options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```

**描述：**


设置弹窗的边框颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t top | 弹窗上边框的颜色。 |
| uint32_t right | 弹窗右边框的颜色。 |
| uint32_t bottom | 弹窗下边框的颜色。 |
| uint32_t left | 弹窗左边框的颜色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBorderStyle()

```
int32_t OH_ArkUI_CustomDialog_SetBorderStyle(ArkUI_CustomDialogOptions* options, int32_t top, int32_t right, int32_t bottom, int32_t left)
```

**描述：**


设置弹窗的边框样式。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| int32_t top | 弹窗上边框的样式。 |
| int32_t right | 弹窗右边框的样式。 |
| int32_t bottom | 弹窗下边框的样式。 |
| int32_t left | 弹窗左边框的样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetWidth()

```
int32_t OH_ArkUI_CustomDialog_SetWidth(ArkUI_CustomDialogOptions* options, float width, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的背板宽度。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float width | 弹窗的背板宽度。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定宽度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHeight()

```
int32_t OH_ArkUI_CustomDialog_SetHeight(ArkUI_CustomDialogOptions* options, float height, ArkUI_LengthMetricUnit unit)
```

**描述：**


设置弹窗的背板高度。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| float height | 弹窗的背板高度。 |
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | 指定高度的单位，默认为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetShadow()

```
int32_t OH_ArkUI_CustomDialog_SetShadow(ArkUI_CustomDialogOptions* options, ArkUI_ShadowStyle shadow)
```

**描述：**


设置弹窗的背板阴影。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_ShadowStyle](capi-native-type-h.md#arkui_shadowstyle) shadow | 弹窗的背板阴影样式，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetCustomShadow()

```
int32_t OH_ArkUI_CustomDialog_SetCustomShadow(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* customShadow)
```

**描述：**


设置弹窗的背板阴影。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* customShadow | 弹窗的自定义阴影参数，格式与NODE_CUSTOM_SHADOW属性一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyle()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyle(ArkUI_CustomDialogOptions* options, ArkUI_BlurStyle blurStyle)
```

**描述：**


设置弹窗的背板模糊材质。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_BlurStyle](capi-native-type-h.md#arkui_blurstyle) blurStyle | 弹窗的背板模糊材质，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetAlignment()

```
int32_t OH_ArkUI_CustomDialog_SetAlignment(ArkUI_CustomDialogOptions* options, int32_t alignment, float offsetX, float offsetY)
```

**描述：**


设置弹窗的对齐模式。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| int32_t alignment | 弹窗的对齐模式，参数类型[ArkUI_Alignment](capi-native-type-h.md#arkui_alignment)。 |
| float offsetX | 弹窗的水平偏移量，浮点型。 |
| float offsetY | 弹窗的垂直偏移量，浮点型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetModalMode()

```
int32_t OH_ArkUI_CustomDialog_SetModalMode(ArkUI_CustomDialogOptions* options, bool isModal)
```

**描述：**


设置自定义弹窗是否开启模态样式的弹窗。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool isModal | 设置是否开启模态窗口。模态窗口有蒙层,非模态窗口无蒙层。设置为true表示开启模态窗口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetAutoCancel()

```
int32_t OH_ArkUI_CustomDialog_SetAutoCancel(ArkUI_CustomDialogOptions* options, bool autoCancel)
```

**描述：**


设置自定义弹窗是否允许点击遮罩层退出。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool autoCancel | 设置是否允许点击遮罩层退出，true表示关闭弹窗，false表示不关闭弹窗。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetSubwindowMode()

```
int32_t OH_ArkUI_CustomDialog_SetSubwindowMode(ArkUI_CustomDialogOptions* options, bool showInSubwindow)
```

**描述：**


设置弹窗是否在子窗口显示此弹窗。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool showInSubwindow | 设置弹窗需要显示在主窗口之外时，是否在子窗口显示此弹窗。默认false，弹窗显示在应用内，而非独立子窗口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetMask()

```
int32_t OH_ArkUI_CustomDialog_SetMask(ArkUI_CustomDialogOptions* options, uint32_t maskColor, const ArkUI_Rect* maskRect)
```

**描述：**


设置自定义弹窗遮罩属性。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| uint32_t maskColor | 弹窗的遮罩颜色，0xargb格式。 |
| [const ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)* maskRect | 遮蔽层区域范围的指针，遮蔽层区域内的事件不透传，在遮蔽层区域外的事件透传。参数类型[ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetKeyboardAvoidMode()

```
int32_t OH_ArkUI_CustomDialog_SetKeyboardAvoidMode(ArkUI_CustomDialogOptions* options, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```

**描述：**


设置弹窗避让键盘的模式。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_KeyboardAvoidMode](capi-native-type-h.md#arkui_keyboardavoidmode) keyboardAvoidMode | 键盘避让模式，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHoverModeEnabled()

```
int32_t OH_ArkUI_CustomDialog_SetHoverModeEnabled(ArkUI_CustomDialogOptions* options, bool enabled)
```

**描述：**


设置弹窗是否响应悬停态。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| bool enabled | 是否响应悬停态，默认false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetHoverModeArea()

```
int32_t OH_ArkUI_CustomDialog_SetHoverModeArea(ArkUI_CustomDialogOptions* options, ArkUI_HoverModeAreaType hoverModeAreaType)
```

**描述：**


设置悬停态下弹窗默认展示区域。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [ArkUI_HoverModeAreaType](capi-native-type-h.md#arkui_hovermodeareatype) hoverModeAreaType | 悬停态区域，枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(ArkUI_DialogDismissEvent* event))
```

**描述：**


注册系统关闭自定义弹窗的监听事件。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| callback | 监听自定义弹窗关闭的回调事件。<br> - event: 回调函数的入参，捕获关闭原因。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗显示动效前的监听事件。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| callback | 弹窗显示动效前的事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗弹出时的监听事件。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| callback | 弹窗弹出时的事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗退出动效前的监听事件。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| callback | 弹窗退出动效前的事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**描述：**


注册自定义弹窗消失时的监听事件。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| void* userData | 用户自定义数据指针。 |
| callback | 弹窗消失时的事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_GetState()

```
int32_t OH_ArkUI_CustomDialog_GetState(ArkUI_NativeDialogHandle handle, ArkUI_DialogState* state)
```

**描述：**


获取弹窗的状态。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | 指向自定义弹窗控制器的指针。 |
| [ArkUI_DialogState](capi-native-dialog-h.md#arkui_dialogstate)* state | 自定义弹窗的状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```

**描述：**


设置弹窗的背景模糊效果。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundBlurStyleOptions | 弹窗的背景模糊效果。参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式：<br>        .value[0].i32 表示深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。<br>        .value[1]?.i32 表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。<br>        .value[2]?.f32 表示模糊效果程度，取[0.0,1.0]范围内的值。<br>        .value[3]?.u32 表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]。<br>        .value[4]?.u32 表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]。<br>        .value[5]?.i32 表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy)枚举值。<br>        .value[6]?.u32 表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xargb类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomDialog_SetBackgroundEffect()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundEffect(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundEffect)
```

**描述：**


设置弹窗的背景效果参数。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | 弹窗参数。 |
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundEffect | 弹窗的背景效果参数。参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式：<br>        .value[0].f32 表示模糊半径，单位为vp。<br>        .value[1]?.f32 表示饱和度。<br>        .value[2]?.f32 表示亮度。<br>        .value[3]?.u32 表示颜色，0xargb类型。<br>        .value[4]?.i32 表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。<br>        .value[5]?.u32 表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]。<br>        .value[6]?.u32 表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]。<br>        .value[7]?.i32 表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy)枚举值。<br>        .value[8]?.u32 表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xargb类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |


