# ArkUI_NativeDialogAPI_1


## Overview

Provides the custom dialog box APIs for the native side.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle)(\* [create](#create) )() | Creates a custom dialog box and returns the pointer to the created dialog box. | 
| void(\* [dispose](#dispose) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | Destroys a custom dialog box. | 
| int32_t(\* [setContent](#setcontent) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) content) | Sets the content for a custom dialog box. | 
| int32_t(\* [removeContent](#removecontent) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | Removes the content of a custom dialog box. | 
| int32_t(\* [setContentAlignment](#setcontentalignment) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t alignment, float offsetX, float offsetY) | Sets the alignment mode for a custom dialog box. | 
| int32_t(\* [resetContentAlignment](#resetcontentalignment) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | Resets the alignment mode of a custom dialog box to its default settings. | 
| int32_t(\* [setModalMode](#setmodalmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool isModal) | Sets the modal mode for a custom dialog box. | 
| int32_t(\* [setAutoCancel](#setautocancel) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool autoCancel) | Specifies whether to allow users to touch the mask to dismiss the custom dialog box. | 
| int32_t(\* [setMask](#setmask) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t maskColor, const [ArkUI_Rect](_ark_u_i___rect.md) \*maskRect) | Sets the mask for a custom dialog box. | 
| int32_t(\* [setBackgroundColor](#setbackgroundcolor) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t backgroundColor) | Sets the background color for a custom dialog box. | 
| int32_t(\* [setCornerRadius](#setcornerradius) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float topLeft, float topRight, float bottomLeft, float bottomRight) | Sets the background corner radius for a custom dialog box. | 
| int32_t(\* [setGridColumnCount](#setgridcolumncount) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t gridCount) | Number of grid columns occupied by the dialog box. | 
| int32_t(\* [enableCustomStyle](#enablecustomstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableCustomStyle) | Specifies whether to use a custom style for the custom dialog box. | 
| int32_t(\* [enableCustomAnimation](#enablecustomanimation) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableCustomAnimation) | Specifies whether to use a custom animation for a custom dialog box. | 
| int32_t(\* [registerOnWillDismiss](#registeronwilldismiss) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_OnWillDismissEvent](_ark_u_i___native_module.md#arkui_onwilldismissevent) eventHandler) | Registers a callback for a custom dialog box so that the user can decide whether to close the dialog box after they touch the Back button or press the Esc key. | 
| int32_t(\* [show](#show) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool showInSubWindow) | Shows a custom dialog box. | 
| int32_t(\* [close](#close) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle) | Closes a custom dialog box. If the dialog box has been closed, this API does not take effect. | 
| int32_t(\* [registerOnWillDismissWithUserData](#registeronwilldismisswithuserdata) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void \*userData, void(\*callback)([ArkUI_DialogDismissEvent](_ark_u_i___native_module.md#arkui_dialogdismissevent) \*event)) | Registers a callback for the dismissal event of a custom dialog box. | 


## Member Variable Description


### close

```
int32_t(* ArkUI_NativeDialogAPI_1::close) (ArkUI_NativeDialogHandle handle)
```
**Description**

Closes a custom dialog box. If the dialog box has been closed, this API does not take effect.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### create

```
ArkUI_NativeDialogHandle(* ArkUI_NativeDialogAPI_1::create) ()
```
**Description**

Creates a custom dialog box and returns the pointer to the created dialog box.

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns the pointer to the created custom dialog box; returns a null pointer if the creation fails.


### dispose

```
void(* ArkUI_NativeDialogAPI_1::dispose) (ArkUI_NativeDialogHandle handle)
```
**Description**

Destroys a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 


### enableCustomAnimation

```
int32_t(* ArkUI_NativeDialogAPI_1::enableCustomAnimation) (ArkUI_NativeDialogHandle handle, bool enableCustomAnimation)
```
**Description**

Specifies whether to use a custom animation for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| enableCustomAnimation | Whether to use a custom animation. The value **true** means to use a custom animation, and **false** means to use the default animation. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### enableCustomStyle

```
int32_t(* ArkUI_NativeDialogAPI_1::enableCustomStyle) (ArkUI_NativeDialogHandle handle, bool enableCustomStyle)
```
**Description**

Specifies whether to use a custom style for the custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| enableCustomStyle | Whether to use a custom style for the dialog box.<br>**true**: The dialog box automatically adapts its width to the child components; the rounded corner is 0; the background color is transparent.<br>**false**: The dialog box automatically adapts its width to the grid system and its height to the child components; the rounded corner is 24 vp. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### registerOnWillDismiss

```
int32_t(* ArkUI_NativeDialogAPI_1::registerOnWillDismiss) (ArkUI_NativeDialogHandle handle, ArkUI_OnWillDismissEvent eventHandler)
```
**Description**

Registers a callback for a custom dialog box so that the user can decide whether to close the dialog box after they touch the Back button or press the Esc key.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| eventHandler | Callback to register. The parameter type is **OnWillDismissEvent**. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### registerOnWillDismissWithUserData

```
int32_t(* ArkUI_NativeDialogAPI_1::registerOnWillDismissWithUserData) (ArkUI_NativeDialogHandle handle, void *userData, void(*callback)(ArkUI_DialogDismissEvent *event))
```
**Description**

Registers a callback for the dismissal event of a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| userData | Pointer to user data. | 
| callback | Callback for the dismissal event of the custom dialog box. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### removeContent

```
int32_t(* ArkUI_NativeDialogAPI_1::removeContent) (ArkUI_NativeDialogHandle handle)
```
**Description**

Removes the content of a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### resetContentAlignment

```
int32_t(* ArkUI_NativeDialogAPI_1::resetContentAlignment) (ArkUI_NativeDialogHandle handle)
```
**Description**

Resets the alignment mode of a custom dialog box to its default settings.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setAutoCancel

```
int32_t(* ArkUI_NativeDialogAPI_1::setAutoCancel) (ArkUI_NativeDialogHandle handle, bool autoCancel)
```
**Description**

Specifies whether to allow users to touch the mask to dismiss the custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| autoCancel | Whether to allow users to touch the mask to dismiss the dialog box. The value **true** means to allow users to do so, and **false** means the opposite. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setBackgroundColor

```
int32_t(* ArkUI_NativeDialogAPI_1::setBackgroundColor) (ArkUI_NativeDialogHandle handle, uint32_t backgroundColor)
```
**Description**

Sets the background color for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| backgroundColor | Background color of the custom dialog box, in 0xARGB format. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setContent

```
int32_t(* ArkUI_NativeDialogAPI_1::setContent) (ArkUI_NativeDialogHandle handle, ArkUI_NodeHandle content)
```
**Description**

Sets the content for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| content | Pointer to the root node of the custom dialog box content. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setContentAlignment

```
int32_t(* ArkUI_NativeDialogAPI_1::setContentAlignment) (ArkUI_NativeDialogHandle handle, int32_t alignment, float offsetX, float offsetY)
```
**Description**

Sets the alignment mode for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| alignment | Alignment mode. The parameter type is **ArkUI_Alignment**. | 
| offsetX | Horizontal offset of the custom dialog box. The value is a floating point number. | 
| offsetY | Vertical offset of the custom dialog box. The value is a floating point number. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setCornerRadius

```
int32_t(* ArkUI_NativeDialogAPI_1::setCornerRadius) (ArkUI_NativeDialogHandle handle, float topLeft, float topRight, float bottomLeft, float bottomRight)
```
**Description**

Sets the background corner radius for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| topLeft | Radius of the upper left corner of the custom dialog box background. | 
| topRight | Radius of the upper right corner of the custom dialog box background. | 
| bottomLeft | Radius of the lower left corner of the custom dialog box background. | 
| bottomRight | Radius of the lower right corner of the custom dialog box background. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setGridColumnCount

```
int32_t(* ArkUI_NativeDialogAPI_1::setGridColumnCount) (ArkUI_NativeDialogHandle handle, int32_t gridCount)
```
**Description**

Sets the number of grid columns occupied by a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| gridCount | Number of grid columns occupied by the dialog box. The default value is subject to the window size, and the maximum value is the maximum number of columns supported by the system. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setMask

```
int32_t(* ArkUI_NativeDialogAPI_1::setMask) (ArkUI_NativeDialogHandle handle, uint32_t maskColor, const ArkUI_Rect *maskRect)
```
**Description**

Sets the mask for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| maskColor | Mask color, in 0xARGB format. | 
| maskRect | Pointer to the mask area. Events outside the mask area are transparently transmitted, and events within the mask area are not. The parameter type is [ArkUI_Rect](_ark_u_i___rect.md). | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setModalMode

```
int32_t(* ArkUI_NativeDialogAPI_1::setModalMode) (ArkUI_NativeDialogHandle handle, bool isModal)
```
**Description**

Sets the modal mode for a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| isModal | Whether the custom dialog box is a modal, which has a mask applied. The value **true** means that the custom dialog box is a modal, and **false** means the opposite. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### show

```
int32_t(* ArkUI_NativeDialogAPI_1::show) (ArkUI_NativeDialogHandle handle, bool showInSubWindow)
```
**Description**

Shows a custom dialog box.

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| showInSubWindow | Whether to show the dialog box in a subwindow. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful. Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.
