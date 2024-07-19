# native_dialog.h


## Overview

Declares a set of custom dialog box APIs of ArkUI on the native side.

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | Defines a struct for the custom dialog box APIs on the native side. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent)) (int32_t reason) | Invoked when the dialog box is closed. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { [DIALOG_DISMISS_BACK_PRESS](_ark_u_i___native_module.md) = 0, [DIALOG_DISMISS_TOUCH_OUTSIDE](_ark_u_i___native_module.md) } | Enumerates the actions for triggering closure of the dialog box. | 
