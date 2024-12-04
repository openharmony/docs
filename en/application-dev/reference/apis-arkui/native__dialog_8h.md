# native_dialog.h


## Overview

Declares a set of custom dialog box APIs of ArkUI on the native side.

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | Defines a struct for the custom dialog box APIs on the native side. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent)) (int32_t reason) | Invoked when the dialog box is closed. | 
| typedef struct [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) [ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) | Defines a struct for a dialog box dismiss event. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkUI_DismissReason](_ark_u_i___native_module.md#arkui_dismissreason) { [DIALOG_DISMISS_BACK_PRESS](_ark_u_i___native_module.md) = 0, [DIALOG_DISMISS_TOUCH_OUTSIDE](_ark_u_i___native_module.md), [DIALOG_DISMISS_CLOSE_BUTTON](_ark_u_i___native_module.md), [DIALOG_DISMISS_SLIDE_DOWN](_ark_u_i___native_module.md) } | Enumerates the actions for triggering closure of the dialog box. | 


### Functions

| Name| Description| 
| -------- | -------- |
| void [OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_setshouldblockdismiss) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event, bool shouldBlockDismiss) | Sets whether to block the system behavior of dismissing a dialog box. | 
| void \* [OH_ArkUI_DialogDismissEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getuserdata) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | Obtains the pointer to user data in a dialog box dismiss event object. | 
| int32_t [OH_ArkUI_DialogDismissEvent_GetDismissReason](_ark_u_i___native_module.md#oh_arkui_dialogdismissevent_getdismissreason) ([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event) | Obtains the dismissal reason from a dialog box dismiss event object. | 
