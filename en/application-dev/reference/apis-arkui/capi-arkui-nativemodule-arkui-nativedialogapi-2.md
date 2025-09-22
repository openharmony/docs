# ArkUI_NativeDialogAPI_2
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Provides a collection of native-side custom dialog box APIs provided by ArkUI.

**Since**: 15

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_dialog.h](capi-native-dialog-h.md)

## Summary

### Member Variables

| Name                                          | Description|
|----------------------------------------------| -- |
| [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md) nativeDialogAPI1 | Collection of native-side custom dialog box APIs provided by ArkUI, covering the scope of [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md).<br>**Since**: 15|


### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*setKeyboardAvoidDistance)(ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)](#setkeyboardavoiddistance) | Distance between the dialog box and the keyboard after keyboard avoidance is applied.|
| [int32_t (\*setLevelMode)(ArkUI_NativeDialogHandle handle, ArkUI_LevelMode levelMode)](#setlevelmode) | Sets the display level of a dialog box.|
| [int32_t (\*setLevelUniqueId)(ArkUI_NativeDialogHandle handle, int32_t uniqueId)](#setleveluniqueid) | Sets the ID of the node under the dialog box's display level.|
| [int32_t (\*setImmersiveMode)(ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMode immersiveMode)](#setimmersivemode) | Sets the display area of the embedded dialog box overlay.|

## Member Function Description

### setKeyboardAvoidDistance()

```
int32_t (*setKeyboardAvoidDistance)(ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)
```

**Description**

Distance between the dialog box and the keyboard after keyboard avoidance is applied.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 15

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| float distance                                                                     | Distance to avoid the keyboard, in vp by default.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit        | Unit of the avoidance distance. The parameter type is [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setLevelMode()

```
int32_t (*setLevelMode)(ArkUI_NativeDialogHandle handle, ArkUI_LevelMode levelMode)
```

**Description**


Sets the display level of a dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 15

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode) levelMode               | Display level to set, specified by an enumerated value of [ArkUI_LevelMode](capi-native-dialog-h.md#arkui_levelmode).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setLevelUniqueId()

```
int32_t (*setLevelUniqueId)(ArkUI_NativeDialogHandle handle, int32_t uniqueId)
```

**Description**


Sets the ID of the node under the dialog box's display level.

> **NOTE**
>
> This API must be called before the [setLevelMode](#setlevelmode) API is invoked.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  int32_t uniqueId | ID of the node under the dialog box's display level. The dialog box will be displayed on the same page as this node.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setImmersiveMode()

```
int32_t (*setImmersiveMode)(ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMode immersiveMode)
```

**Description**


Sets the display area of the embedded dialog box overlay.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 15

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode) immersiveMode   | Display area, specified by an enumerated value of [ArkUI_ImmersiveMode](capi-native-dialog-h.md#arkui_immersivemode).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
