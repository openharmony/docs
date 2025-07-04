# ArkUI_NativeDialogAPI_2


## Overview

Provides the custom dialog box APIs (version 2) for the native side.

**Since**: 15

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)

**Header file**: [native_dialog.h](native__dialog_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#arkui_nativedialogapi_1) nativeDialogAPI1 | A set of the custom dialog box APIs on the native side. | 
| int32_t(\* [setKeyboardAvoidDistance](#setkeyboardavoiddistance) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float distance, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Distance between the dialog box and the keyboard after keyboard avoidance is applied. | 
| int32_t(\* [setLevelMode](#setlevelmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) levelMode) | Sets the display level of the dialog box. | 
| int32_t(\* [setLevelUniqueId](#setleveluniqueid) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t uniqueId) | Sets the ID of the node under the dialog box's display level. | 
| int32_t(\* [setImmersiveMode](#setimmersivemode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) immersiveMode) | Sets the display area of the embedded dialog box overlay. | 



## Member Variable Description


### setKeyboardAvoidDistance

```
int32_t(* ArkUI_NativeDialogAPI_2::setKeyboardAvoidDistance) (ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the minimum distance between the dialog box and the keyboard after keyboard avoidance is applied. The default value is **16vp**, and the default unit is vp. This API takes effect only when **keyboardAvoidMode** is set to **DEFAULT**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| distance | Distance value between the dialog box and the keyboard.| 
| unit | Unit of the distance. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.

### setLevelMode

```
int32_t(* ArkUI_NativeDialogAPI_2::setLevelMode) (ArkUI_NativeDialogHandle handle, ArkUI_LevelMode levelMode)
```
**Description**

Sets the display level of the dialog box. This API must be called before **show**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| levelMode | Display level mode, specified by an enumeration value of type **ArkUI_LevelMode**.|

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.

### setLevelUniqueId

```
int32_t(* ArkUI_NativeDialogAPI_2::setLevelUniqueId) (ArkUI_NativeDialogHandle handle, int32_t uniqueId)
```
**Description**

Sets the ID of the node under the dialog box's display level. This API must be called before **setLevelMode**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| uniqueId | ID of the node under the dialog box's display level. The dialog box will be displayed on the same page as this node.|

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.

### setImmersiveMode

```
int32_t(* ArkUI_NativeDialogAPI_2::setImmersiveMode) (ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMode immersiveMode)
```
**Description**

Sets the display area of the embedded dialog box overlay. This API must be called before **show**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| immersiveMode | Display area, specified by an enumeration value of type **ArkUI_ImmersiveMode**.|

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
