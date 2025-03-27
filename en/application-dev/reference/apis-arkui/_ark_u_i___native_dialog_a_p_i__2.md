# ArkUI_NativeDialogAPI_2


## Overview

Provides the custom dialog box APIs (version 2) for the native side.

**Since**: 15

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#ArkUI_NativeDialogAPI_1) nativeDialogAPI1 | A set of the custom dialog box APIs on the native side. | 
| int32_t(\* [setKeyboardAvoidDistance](#setkeyboardavoiddistance) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float distance, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Sets the minimum distance between the dialog box and the keyboard after keyboard avoidance is applied. | 



## Member Variable Description


### setKeyboardAvoidDistance

```
int32_t(* ArkUI_NativeDialogAPI_2::setKeyboardAvoidDistance) (ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the minimum distance between the dialog box and the keyboard after keyboard avoidance is applied. The default value is **16vp**, and the default unit is vp. This API takes effect only when **keyboardAvoidMode** is set to **DEFAULT**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| distance | Distance value between the dialog box and the keyboard.| 
| ArkUI_LengthMetricUnit | Unit of the distance. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
