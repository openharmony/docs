# native_dialog.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Declares a set of custom dialog box APIs of ArkUI on the native side.

**File to include**: <arkui/native_dialog.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md) | ArkUI_NativeDialogAPI_1 | Defines a struct for the custom dialog box APIs on the native side.|
| [ArkUI_NativeDialogAPI_2](capi-arkui-nativemodule-arkui-nativedialogapi-2.md) | ArkUI_NativeDialogAPI_2 | Defines a struct for the custom dialog box APIs on the native side.|
| [ArkUI_NativeDialogAPI_3](capi-arkui-nativemodule-arkui-nativedialogapi-3.md) | ArkUI_NativeDialogAPI_3 | Defines a struct for the custom dialog box APIs on the native side.|
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md) | ArkUI_DialogDismissEvent | Defines a struct for a dialog box dismiss event.|
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md) | ArkUI_CustomDialogOptions | Defines a struct for custom dialog box options.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_DismissReason](#arkui_dismissreason) | ArkUI_DismissReason | Enumerates the actions for triggering closure of the dialog box.|
| [ArkUI_LevelMode](#arkui_levelmode) | ArkUI_LevelMode | Enumerates the display levels of the dialog box.|
| [ArkUI_ImmersiveMode](#arkui_immersivemode) | ArkUI_ImmersiveMode | Enumerates the display areas of the embedded dialog box overlay.|
| [ArkUI_DialogState](#arkui_dialogstate) | ArkUI_DialogState | Enumerates the dialog box status.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef bool (\*ArkUI_OnWillDismissEvent)(int32_t reason)](#arkui_onwilldismissevent) | ArkUI_OnWillDismissEvent | Defines a pointer to the callback invoked when the dialog box is closed.|
| [void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)](#oh_arkui_dialogdismissevent_setshouldblockdismiss) | - | Sets whether to block the system behavior of dismissing a dialog box.|
| [void* OH_ArkUI_DialogDismissEvent_GetUserData(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getuserdata) | - | Obtains the pointer to user data in a dialog box dismiss event object.|
| [int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)](#oh_arkui_dialogdismissevent_getdismissreason) | - | Obtains the dismissal reason from a dialog box dismiss event object.|
| [int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (\*callback)(int32_t dialogId))](#oh_arkui_customdialog_opendialog) | - | Displays a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))](#oh_arkui_customdialog_updatedialog) | - | Updates a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_CloseDialog(int32_t dialogId)](#oh_arkui_customdialog_closedialog) | - | Closes a custom dialog box.|
| [ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)](#oh_arkui_customdialog_createoptions) | - | Creates options for a custom dialog.|
| [void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)](#oh_arkui_customdialog_disposeoptions) | - | Destroys custom dialog box options.|
| [int32_t OH_ArkUI_CustomDialog_SetLevelMode(ArkUI_CustomDialogOptions* options, ArkUI_LevelMode levelMode)](#oh_arkui_customdialog_setlevelmode) | - | Sets the display level of the dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetLevelUniqueId(ArkUI_CustomDialogOptions* options, int32_t uniqueId)](#oh_arkui_customdialog_setleveluniqueid) | - | Sets the ID of the node under the dialog box's display level.|
| [int32_t OH_ArkUI_CustomDialog_SetImmersiveMode(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMode immersiveMode)](#oh_arkui_customdialog_setimmersivemode) | - | Sets the display area of the embedded dialog box overlay.|
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundColor(ArkUI_CustomDialogOptions* options, uint32_t backgroundColor)](#oh_arkui_customdialog_setbackgroundcolor) | - | Sets the background color of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetCornerRadius(ArkUI_CustomDialogOptions* options, float topLeft, float topRight, float bottomLeft, float bottomRight)](#oh_arkui_customdialog_setcornerradius) | - | Sets the corner radius for a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetBorderWidth(ArkUI_CustomDialogOptions* options, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setborderwidth) | - | Sets the border width of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetBorderColor(ArkUI_CustomDialogOptions* options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)](#oh_arkui_customdialog_setbordercolor) | - | Sets the border color of the dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetBorderStyle(ArkUI_CustomDialogOptions* options, int32_t top, int32_t right, int32_t bottom, int32_t left)](#oh_arkui_customdialog_setborderstyle) | - | Sets the border style of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetWidth(ArkUI_CustomDialogOptions* options, float width, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setwidth) | - | Sets the width of the dialog box background.|
| [int32_t OH_ArkUI_CustomDialog_SetHeight(ArkUI_CustomDialogOptions* options, float height, ArkUI_LengthMetricUnit unit)](#oh_arkui_customdialog_setheight) | - | Sets the height of the dialog box background.|
| [int32_t OH_ArkUI_CustomDialog_SetShadow(ArkUI_CustomDialogOptions* options, ArkUI_ShadowStyle shadow)](#oh_arkui_customdialog_setshadow) | - | Sets the shadow of the dialog box background.|
| [int32_t OH_ArkUI_CustomDialog_SetCustomShadow(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* customShadow)](#oh_arkui_customdialog_setcustomshadow) | - | Sets the shadow of the dialog box background.|
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyle(ArkUI_CustomDialogOptions* options, ArkUI_BlurStyle blurStyle)](#oh_arkui_customdialog_setbackgroundblurstyle) | - | Sets the background blur style of the dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetAlignment(ArkUI_CustomDialogOptions* options, int32_t alignment, float offsetX, float offsetY)](#oh_arkui_customdialog_setalignment) | - | Sets the alignment mode of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetModalMode(ArkUI_CustomDialogOptions* options, bool isModal)](#oh_arkui_customdialog_setmodalmode) | - | Sets the modal mode for a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetAutoCancel(ArkUI_CustomDialogOptions* options, bool autoCancel)](#oh_arkui_customdialog_setautocancel) | - | Specifies whether to allow users to touch the mask to dismiss the custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetSubwindowMode(ArkUI_CustomDialogOptions* options, bool showInSubwindow)](#oh_arkui_customdialog_setsubwindowmode) | - | Sets whether to display the dialog box in a subwindow.|
| [int32_t OH_ArkUI_CustomDialog_SetMask(ArkUI_CustomDialogOptions* options, uint32_t maskColor, const ArkUI_Rect* maskRect)](#oh_arkui_customdialog_setmask) | - | Sets the mask for a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetKeyboardAvoidMode(ArkUI_CustomDialogOptions* options, ArkUI_KeyboardAvoidMode keyboardAvoidMode)](#oh_arkui_customdialog_setkeyboardavoidmode) | - | Sets the keyboard avoidance mode of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetHoverModeEnabled(ArkUI_CustomDialogOptions* options, bool enabled)](#oh_arkui_customdialog_sethovermodeenabled) | - | Sets whether to enable the hover mode for a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetHoverModeArea(ArkUI_CustomDialogOptions* options, ArkUI_HoverModeAreaType hoverModeAreaType)](#oh_arkui_customdialog_sethovermodearea) | - | Sets the default display area of a dialog box in hover mode.|
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(ArkUI_DialogDismissEvent* event))](#oh_arkui_customdialog_registeronwilldismisscallback) | - | Registers a callback for the dismissal event of a custom dialog box.|
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registeronwillappearcallback) | - | Registers a callback to be invoked when the specified custom dialog box is about to appear.|
| [int32_t OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registerondidappearcallback) | - | Registers a callback to be invoked when the specifiedcustom dialog box appears.|
| [int32_t OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registeronwilldisappearcallback) | - | Registers a callback to be invoked when the specified custom dialog box is about to disappear.|
| [int32_t OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (\*callback)(void* userData))](#oh_arkui_customdialog_registerondiddisappearcallback) | - | Registers a callback to be invoked when the specified custom dialog box disappears.|
| [int32_t OH_ArkUI_CustomDialog_GetState(ArkUI_NativeDialogHandle handle, ArkUI_DialogState* state)](#oh_arkui_customdialog_getstate) | - | Obtains the state of a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundBlurStyleOptions)](#oh_arkui_customdialog_setbackgroundblurstyleoptions) | - | Sets the background blur effect for a dialog box.|
| [int32_t OH_ArkUI_CustomDialog_SetBackgroundEffect(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundEffect)](#oh_arkui_customdialog_setbackgroundeffect) | - | Sets the background effect parameters for a dialog box.|

## Enum Description

### ArkUI_DismissReason

```
enum ArkUI_DismissReason
```

**Description**


Enumerates the actions for triggering closure of the dialog box.

**Since**: 12

| Value| Description|
| -- | -- |
| DIALOG_DISMISS_BACK_PRESS = 0 | Touching the system-defined Back button or pressing the Esc key.|
| DIALOG_DISMISS_TOUCH_OUTSIDE | Touching the mask.|
| DIALOG_DISMISS_CLOSE_BUTTON | Touching the Close button.|
| DIALOG_DISMISS_SLIDE_DOWN | Sliding down.|

### ArkUI_LevelMode

```
enum ArkUI_LevelMode
```

**Description**


Enumerates the display level modes of the dialog box.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_LEVEL_MODE_OVERLAY = 0 | The dialog box is displayed on top of all other application content.|
| ARKUI_LEVEL_MODE_EMBEDDED | The dialog box is embedded within the application's page content.|

### ArkUI_ImmersiveMode

```
enum ArkUI_ImmersiveMode
```

**Description**


Enumerates the display areas of the embedded dialog box overlay.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_IMMERSIVE_MODE_DEFAULT = 0 | The dialog box overlay follows the layout constraints of its parent node.|
| ARKUI_IMMERSIVE_MODE_EXTEND | The dialog box overlay can extend to cover the status bar and navigation bar for a more immersive look.|

### ArkUI_DialogState

```
enum ArkUI_DialogState
```

**Description**


Enumerates the dialog box status.

**Since**: 20

| Value| Description|
| -- | -- |
| DIALOG_UNINITIALIZED = 0 | State before the controller is bound to the dialog box.|
| DIALOG_INITIALIZED | State after the controller is bound to the dialog box.|
| DIALOG_APPEARING | State during the dialog box appearance animation.|
| DIALOG_APPEARED | State after the dialog display appearance ends.|
| DIALOG_DISAPPEARING | State during the dialog box disappearance animation.|
| DIALOG_DISAPPEARED | State after the dialog box disappearance animation ends.|


## Function Description

### ArkUI_OnWillDismissEvent()

```
typedef bool (*ArkUI_OnWillDismissEvent)(int32_t reason)
```

**Description**


Defines a pointer to the callback invoked when the dialog box is closed.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| reason | Reason for dialog box dismissal.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Any return value indicates that the dialog box will not be closed.|

### OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss()

```
void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss(ArkUI_DialogDismissEvent* event, bool shouldBlockDismiss)
```

**Description**


Sets whether to block the system behavior of dismissing a dialog box.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | Pointer to a dialog box dismiss event object.|
| bool shouldBlockDismiss | Whether to block the system behavior of dismissing the dialog box. The value **true** means to block the system behavior, and **false** means the opposite.|

### OH_ArkUI_DialogDismissEvent_GetUserData()

```
void* OH_ArkUI_DialogDismissEvent_GetUserData(ArkUI_DialogDismissEvent* event)
```

**Description**


Obtains the pointer to user data in a dialog box dismiss event object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | Pointer to a dialog box dismiss event object.|

**Returns**

| Type| Description|
| -- | -- |
| void* | Pointer to user data.|

### OH_ArkUI_DialogDismissEvent_GetDismissReason()

```
int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason(ArkUI_DialogDismissEvent* event)
```

**Description**


Obtains the dismissal reason from a dialog box dismiss event object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DialogDismissEvent](capi-arkui-nativemodule-arkui-dialogdismissevent.md)* event | Pointer to a dialog box dismiss event object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Dismissal reason, or **-1** if an exception occurs.<br>         [DIALOG_DISMISS_BACK_PRESS](capi-native-dialog-h.md#arkui_dismissreason): touching the back button, swiping left or right on the screen, or pressing the Esc key.<br>         [DIALOG_DISMISS_TOUCH_OUTSIDE](capi-native-dialog-h.md#arkui_dismissreason): touching the mask.<br>         [DIALOG_DISMISS_CLOSE_BUTTON](capi-native-dialog-h.md#arkui_dismissreason): touching the close button.<br>         [DIALOG_DISMISS_SLIDE_DOWN](capi-native-dialog-h.md#arkui_dismissreason): swiping down.|

### OH_ArkUI_CustomDialog_OpenDialog()

```
int32_t OH_ArkUI_CustomDialog_OpenDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))
```

**Description**


Displays a custom dialog box.

**Since**: 19


**Parameters**

| Name                                   | Description|
|----------------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| callback                               | Callback invoked when the dialog box is displayed. The parameter is the dialog box ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_UpdateDialog()

```
int32_t OH_ArkUI_CustomDialog_UpdateDialog(ArkUI_CustomDialogOptions* options, void (*callback)(int32_t dialogId))
```

**Description**


Updates a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| callback                               | Callback invoked when the dialog box is updated. The parameter is the dialog box ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_CloseDialog()

```
int32_t OH_ArkUI_CustomDialog_CloseDialog(int32_t dialogId)
```

**Description**


Closes a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| int32_t dialogId | ID of the dialog box to close.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_CreateOptions()

```
ArkUI_CustomDialogOptions* OH_ArkUI_CustomDialog_CreateOptions(ArkUI_NodeHandle content)
```

**Description**


Creates options for a custom dialog.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) content | Content of the custom dialog box.|

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* | Pointer to the custom dialog box options.|

### OH_ArkUI_CustomDialog_DisposeOptions()

```
void OH_ArkUI_CustomDialog_DisposeOptions(ArkUI_CustomDialogOptions* options)
```

**Description**


Destroys custom dialog box options.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Pointer to the custom dialog box options.|

### OH_ArkUI_CustomDialog_SetLevelMode()

```
int32_t OH_ArkUI_CustomDialog_SetLevelMode(ArkUI_CustomDialogOptions* options, ArkUI_LevelMode levelMode)
```

**Description**


Sets the display level of the dialog box.

> **NOTE**
>
> This API must be called before the [OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog) API is invoked.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Pointer to the custom dialog box options.|
| [ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode) levelMode | Display level to set, specified by an enumerated value of [ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetLevelUniqueId()

```
int32_t OH_ArkUI_CustomDialog_SetLevelUniqueId(ArkUI_CustomDialogOptions* options, int32_t uniqueId)
```

**Description**


Sets the ID of the node under the dialog box's display level.

> **NOTE**
>
> This API must be called before the [OH_ArkUI_CustomDialog_OpenDialog](#oh_arkui_customdialog_opendialog) API is invoked.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Pointer to the custom dialog box options.|
| int32_t uniqueId | ID of the node under the dialog box's display level. The dialog box will be displayed on the same page as this node.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetImmersiveMode()

```
int32_t OH_ArkUI_CustomDialog_SetImmersiveMode(ArkUI_CustomDialogOptions* options, ArkUI_ImmersiveMode immersiveMode)
```

**Description**


Sets the display area of the embedded dialog box overlay.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Pointer to the custom dialog box options.|
| [ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode) immersiveMode | Display area, specified by an enumerated value of [ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBackgroundColor()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundColor(ArkUI_CustomDialogOptions* options, uint32_t backgroundColor)
```

**Description**


Sets the background color of a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| uint32_t backgroundColor | Background color of the dialog box.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetCornerRadius()

```
int32_t OH_ArkUI_CustomDialog_SetCornerRadius(ArkUI_CustomDialogOptions* options, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**Description**


Sets the corner radius for a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| float topLeft | Radius of the upper left corner of the dialog box.|
| float topRight | Radius of the upper right corner of the dialog box.|
| float bottomLeft | Radius of the lower left corner of the dialog box.|
| float bottomRight | Radius of the lower right corner of the dialog box.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBorderWidth()

```
int32_t OH_ArkUI_CustomDialog_SetBorderWidth(ArkUI_CustomDialogOptions* options, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the border width of a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| float top | Width of the top border of the dialog box.|
| float right | Width of the right border of the dialog box.|
| float bottom | Width of the bottom border of the dialog box.|
| float left | Width of the left border of the dialog box.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit of the width. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBorderColor()

```
int32_t OH_ArkUI_CustomDialog_SetBorderColor(ArkUI_CustomDialogOptions* options, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```

**Description**


Sets the border color of the dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| uint32_t top | Color of the top border of the dialog box.|
| uint32_t right | Color of the right border of the dialog box.|
| uint32_t bottom | Color of the bottom border of the dialog box.|
| uint32_t left | Color of the left border of the dialog box.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBorderStyle()

```
int32_t OH_ArkUI_CustomDialog_SetBorderStyle(ArkUI_CustomDialogOptions* options, int32_t top, int32_t right, int32_t bottom, int32_t left)
```

**Description**


Sets the border style of a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| int32_t top | Style of the top border of the dialog box.|
| int32_t right | Style of the right border of the dialog box.|
| int32_t bottom | Style of the bottom border of the dialog box.|
| int32_t left | Style of the left border of the dialog box.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetWidth()

```
int32_t OH_ArkUI_CustomDialog_SetWidth(ArkUI_CustomDialogOptions* options, float width, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the width of the dialog box background.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| float width | Width of the dialog box background.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit of the width. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetHeight()

```
int32_t OH_ArkUI_CustomDialog_SetHeight(ArkUI_CustomDialogOptions* options, float height, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the height of the dialog box background.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| float height | Width of the dialog box background.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit of the height. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetShadow()

```
int32_t OH_ArkUI_CustomDialog_SetShadow(ArkUI_CustomDialogOptions* options, ArkUI_ShadowStyle shadow)
```

**Description**


Sets the shadow of the dialog box background.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [ArkUI_ShadowStyle](capi-native-type-h.md#arkui_shadowstyle) shadow | Shadow style of the background, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetCustomShadow()

```
int32_t OH_ArkUI_CustomDialog_SetCustomShadow(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* customShadow)
```

**Description**


Sets the shadow of the dialog box background.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* customShadow | Custom shadow parameters. The format is consistent with the **NODE_CUSTOM_SHADOW** property in [ArkUI_NodeAttributeType](./capi-native-node-h.md#arkui_nodeattributetype).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyle()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyle(ArkUI_CustomDialogOptions* options, ArkUI_BlurStyle blurStyle)
```

**Description**


Sets the background blur style of the dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [ArkUI_BlurStyle](capi-native-type-h.md#arkui_blurstyle) blurStyle | Background blur style, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetAlignment()

```
int32_t OH_ArkUI_CustomDialog_SetAlignment(ArkUI_CustomDialogOptions* options, int32_t alignment, float offsetX, float offsetY)
```

**Description**


Sets the alignment mode of a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| int32_t alignment | Alignment mode of the dialog box. The parameter type is [ArkUI_Alignment](capi-native-type-h.md#arkui_alignment).|
| float offsetX | Horizontal offset of the custom dialog box. The value is a floating point number.|
| float offsetY | Vertical offset of the custom dialog box. The value is a floating point number.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetModalMode()

```
int32_t OH_ArkUI_CustomDialog_SetModalMode(ArkUI_CustomDialogOptions* options, bool isModal)
```

**Description**


Sets the modal mode for a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| bool isModal | Whether the dialog box is a modal. A modal dialog box has a mask applied, while a non-modal dialog box does not. The value **true** means that the dialog box is a modal, and **false** means the opposite.<br>Default value: **false**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetAutoCancel()

```
int32_t OH_ArkUI_CustomDialog_SetAutoCancel(ArkUI_CustomDialogOptions* options, bool autoCancel)
```

**Description**


Specifies whether to allow users to touch the mask to dismiss the custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| bool autoCancel | Whether to allow users to touch the mask to dismiss the dialog box. The value **true** means to allow users to do so, and **false** means the opposite.<br>Default value: **true**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetSubwindowMode()

```
int32_t OH_ArkUI_CustomDialog_SetSubwindowMode(ArkUI_CustomDialogOptions* options, bool showInSubwindow)
```

**Description**


Sets whether to display the dialog box in a subwindow.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| bool showInSubwindow | Whether to show the dialog box in a subwindow when the dialog box needs to be displayed outside the main window. The default value is **false**, meaning the dialog box is displayed within the application, not in a separate subwindow. The value **true** means that dialog box can be displayed outside the main window.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetMask()

```
int32_t OH_ArkUI_CustomDialog_SetMask(ArkUI_CustomDialogOptions* options, uint32_t maskColor, const ArkUI_Rect* maskRect)
```

**Description**


Sets the mask for a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| uint32_t maskColor | Mask color, in 0xargb format.|
| [const ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)* maskRect | Pointer to the mask area. Events outside the mask area are transparently transmitted, and events within the mask area are not. The parameter type is [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetKeyboardAvoidMode()

```
int32_t OH_ArkUI_CustomDialog_SetKeyboardAvoidMode(ArkUI_CustomDialogOptions* options, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```

**Description**


Sets the keyboard avoidance mode of a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [ArkUI_KeyboardAvoidMode](capi-native-type-h.md#arkui_keyboardavoidmode) keyboardAvoidMode | Keyboard avoidance mode, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetHoverModeEnabled()

```
int32_t OH_ArkUI_CustomDialog_SetHoverModeEnabled(ArkUI_CustomDialogOptions* options, bool enabled)
```

**Description**


Sets whether to enable the hover mode for a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| bool enabled | Whether to respond when the device is in semi-folded mode. The default value is **false**. The value **true** means to respond when the device is in semi-folded mode, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetHoverModeArea()

```
int32_t OH_ArkUI_CustomDialog_SetHoverModeArea(ArkUI_CustomDialogOptions* options, ArkUI_HoverModeAreaType hoverModeAreaType)
```

**Description**


Sets the default display area of a dialog box in hover mode.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [ArkUI_HoverModeAreaType](capi-native-type-h.md#arkui_hovermodeareatype) hoverModeAreaType | Display area in hover mode, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDismissCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(ArkUI_DialogDismissEvent* event))
```

**Description**


Registers a callback for the dismissal event of a custom dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| void* userData | Pointer to user data.|
| callback | Callback for the dismissal event of the custom dialog box.<br> - **event**: input parameter of the callback, which captures the reason for dismissal.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback to be invoked when the specified custom dialog box is about to appear.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| void* userData | Pointer to user data.|
| callback | Event callback before the dialog box appearance animation.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnDidAppearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback to be invoked when the specifiedcustom dialog box appears.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| void* userData | Pointer to user data.|
| callback | Event callback when the dialog box appears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnWillDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback to be invoked when the specified custom dialog box is about to disappear.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| void* userData | Pointer to user data.|
| callback | Event callback before the dialog box disappearance animation.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback()

```
int32_t OH_ArkUI_CustomDialog_RegisterOnDidDisappearCallback(ArkUI_CustomDialogOptions* options, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback to be invoked when the specified custom dialog box disappears.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| void* userData | Pointer to user data.|
| callback | Event callback when the dialog box disappears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_GetState()

```
int32_t OH_ArkUI_CustomDialog_GetState(ArkUI_NativeDialogHandle handle, ArkUI_DialogState* state)
```

**Description**


Obtains the state of a dialog box.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_DialogState](capi-native-dialog-h.md#arkui_dialogstate)* state | Enumerates states of the custom dialog box.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundBlurStyleOptions(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```

**Description**


Sets the background blur effect for a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundBlurStyleOptions | Background blur effect for the dialog box. The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter is as follows:<br>        .value[0].i32: color mode, specified by an enumerated value of [ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode).<br>        .value[1]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor).<br>        .value[2]? .f32: blur degree. The value range is [0.0, 1.0].<br>        .value[3]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>        .value[4]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>        .value[5]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy).<br>        .value[6]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CustomDialog_SetBackgroundEffect()

```
int32_t OH_ArkUI_CustomDialog_SetBackgroundEffect(ArkUI_CustomDialogOptions* options, const ArkUI_AttributeItem* backgroundEffect)
```

**Description**


Sets the background effect parameters for a dialog box.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomDialogOptions](capi-arkui-nativemodule-arkui-customdialogoptions.md)* options | Dialog box parameters.|
| [const ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundEffect | Background effect of the dialog box. The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter is as follows:<br>        .value[0].f32: blur radius, in vp.<br>        .value[1]?.f32: saturation.<br>        .value[2]?.f32: brightness.<br>        .value[3]?.u32: color, in 0xARGB format.<br>        .value[4]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor).<br>        .value[5]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>        .value[6]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>        .value[7]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy).<br>        .value[8]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
