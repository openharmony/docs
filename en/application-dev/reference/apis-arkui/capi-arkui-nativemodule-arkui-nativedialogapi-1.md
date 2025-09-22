# ArkUI_NativeDialogAPI_1
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Provides a collection of native-side custom dialog box APIs provided by ArkUI.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_dialog.h](capi-native-dialog-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle (\*create)()](#create) | Creates a custom dialog box and returns the pointer to the created dialog box.|
| [void (\*dispose)(ArkUI_NativeDialogHandle handle)](#dispose) | Destroys a custom dialog box.|
| [int32_t (\*setContent)(ArkUI_NativeDialogHandle handle, ArkUI_NodeHandle content)](#setcontent) | Sets the content for a custom dialog box.|
| [int32_t (\*removeContent)(ArkUI_NativeDialogHandle handle)](#removecontent) | Removes the content of a custom dialog box.|
| [int32_t (\*setContentAlignment)(ArkUI_NativeDialogHandle handle, int32_t alignment, float offsetX, float offsetY)](#setcontentalignment) | Sets the alignment mode of a custom dialog box.|
| [int32_t (\*resetContentAlignment)(ArkUI_NativeDialogHandle handle)](#resetcontentalignment) | Resets the alignment mode of a custom dialog box to its default settings.|
| [int32_t (\*setModalMode)(ArkUI_NativeDialogHandle handle, bool isModal)](#setmodalmode) | Sets the modal mode for a custom dialog box.|
| [int32_t (\*setAutoCancel)(ArkUI_NativeDialogHandle handle, bool autoCancel)](#setautocancel) | Specifies whether to allow users to touch the mask to dismiss a custom dialog box.|
| [int32_t (\*setMask)(ArkUI_NativeDialogHandle handle, uint32_t maskColor, const ArkUI_Rect* maskRect)](#setmask) | Sets the mask for a custom dialog box.|
| [int32_t (\*setBackgroundColor)(ArkUI_NativeDialogHandle handle, uint32_t backgroundColor)](#setbackgroundcolor) | Sets the background color for a custom dialog box.|
| [int32_t (\*setCornerRadius)(ArkUI_NativeDialogHandle handle, float topLeft, float topRight,float bottomLeft, float bottomRight)](#setcornerradius) | Sets the background corner radius for a custom dialog box.|
| [int32_t (\*setGridColumnCount)(ArkUI_NativeDialogHandle handle, int32_t gridCount)](#setgridcolumncount) | Sets the number of grid columns occupied by a custom dialog box.|
| [int32_t (\*enableCustomStyle)(ArkUI_NativeDialogHandle handle, bool enableCustomStyle)](#enablecustomstyle) | Specifies whether to use a custom style for the custom dialog box.|
| [int32_t (\*enableCustomAnimation)(ArkUI_NativeDialogHandle handle, bool enableCustomAnimation)](#enablecustomanimation) | Specifies whether to use a custom animation for a custom dialog box.|
| [int32_t (\*registerOnWillDismiss)(ArkUI_NativeDialogHandle handle, ArkUI_OnWillDismissEvent eventHandler)](#registeronwilldismiss) | Registers a callback for a custom dialog box so that the user can decide whether to close the dialog box after they touch the back button or press the Esc key.|
| [int32_t (\*show)(ArkUI_NativeDialogHandle handle, bool showInSubWindow)](#show) | Shows a custom dialog box.|
| [int32_t (\*close)(ArkUI_NativeDialogHandle handle)](#close) | Closes a custom dialog box. If the dialog box has been closed, this API does not take effect.|
| [int32_t (\*registerOnWillDismissWithUserData)(ArkUI_NativeDialogHandle handle, void* userData, void (\*callback)(ArkUI_DialogDismissEvent* event))](#registeronwilldismisswithuserdata) | Registers a callback for the dismissal event of a custom dialog box.|

## Member Function Description

### create()

```
ArkUI_NativeDialogHandle (*create)()
```

**Description**

Creates a custom dialog box and returns the pointer to the created dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) | Pointer to the custom dialog box, or a null pointer if the creation fails.|

### dispose()

```
void (*dispose)(ArkUI_NativeDialogHandle handle)
```

**Description**


Destroys a custom dialog box.

### setContent()

```
int32_t (*setContent)(ArkUI_NativeDialogHandle handle, ArkUI_NodeHandle content)
```

**Description**

Sets the content for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) content                                                       | Pointer to the root node of the custom dialog box content.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### removeContent()

```
int32_t (*removeContent)(ArkUI_NativeDialogHandle handle)
```

**Description**

Removes the content of a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setContentAlignment()

```
int32_t (*setContentAlignment)(ArkUI_NativeDialogHandle handle, int32_t alignment, float offsetX, float offsetY)
```

**Description**

Sets the alignment mode of a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  int32_t alignment | Alignment mode. The parameter type is **ArkUI_Alignment**.|
|  float offsetX | Horizontal offset of the custom dialog box. The value is a floating point number.|
|  float offsetY | Vertical offset of the custom dialog box. The value is a floating point number.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### resetContentAlignment()

```
int32_t (*resetContentAlignment)(ArkUI_NativeDialogHandle handle)
```

**Description**

Resets the alignment mode of a custom dialog box to its default settings.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setModalMode()

```
int32_t (*setModalMode)(ArkUI_NativeDialogHandle handle, bool isModal)
```

**Description**

Sets the modal mode for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool isModal | Whether the custom dialog box is a modal, which has a mask applied. The value **true** means that the custom dialog box is a modal, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setAutoCancel()

```
int32_t (*setAutoCancel)(ArkUI_NativeDialogHandle handle, bool autoCancel)
```

**Description**

Specifies whether to allow users to touch the mask to dismiss a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool autoCancel | Whether to allow users to touch the mask to dismiss the dialog box. The value **true** means to allow users to do so, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setMask()

```
int32_t (*setMask)(ArkUI_NativeDialogHandle handle, uint32_t maskColor, const ArkUI_Rect* maskRect)
```

**Description**

Sets the mask for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| uint32_t maskColor                                                                 | Mask color, in 0xARGB format.|
| const [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)* maskRect                                                     | Pointer to the mask area. Events outside the mask area are transparently transmitted, and events within the mask area are not. The parameter type is [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBackgroundColor()

```
int32_t (*setBackgroundColor)(ArkUI_NativeDialogHandle handle, uint32_t backgroundColor)
```

**Description**

Sets the background color for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  uint32_t backgroundColor | Background color of the custom dialog box, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setCornerRadius()

```
int32_t (*setCornerRadius)(ArkUI_NativeDialogHandle handle, float topLeft, float topRight,float bottomLeft, float bottomRight)
```

**Description**

Sets the background corner radius for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  float topLeft | Radius of the upper left corner of the custom dialog box background.|
|  float topRight | Radius of the upper right corner of the custom dialog box background.|
| float bottomLeft | Radius of the lower left corner of the custom dialog box background.|
|  float bottomRight | Radius of the lower right corner of the custom dialog box background.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setGridColumnCount()

```
int32_t (*setGridColumnCount)(ArkUI_NativeDialogHandle handle, int32_t gridCount)
```

**Description**

Sets the number of grid columns occupied by a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  int32_t gridCount | Number of grid columns occupied by the dialog box. The default value is subject to the window size, and the maximum value is the maximum number of columns supported by the system.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### enableCustomStyle()

```
int32_t (*enableCustomStyle)(ArkUI_NativeDialogHandle handle, bool enableCustomStyle)
```

**Description**

Specifies whether to use a custom style for the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool enableCustomStyle | Whether to use a custom style for the dialog box.<br>**true**: The dialog box automatically adapts its width to the child components; the rounded corner is 0; the background color is transparent.<br>**false**: The dialog box automatically adapts its width to the grid system and its height to the child components; the rounded corner is 24 vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### enableCustomAnimation()

```
int32_t (*enableCustomAnimation)(ArkUI_NativeDialogHandle handle, bool enableCustomAnimation)
```

**Description**

Specifies whether to use a custom animation for a custom dialog box.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool enableCustomAnimation | Whether to use a custom animation. The value **true** means to use a custom animation, and **false** means to use the default animation.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnWillDismiss()

```
int32_t (*registerOnWillDismiss)(ArkUI_NativeDialogHandle handle, ArkUI_OnWillDismissEvent eventHandler)
```

**Description**

Registers a callback for a custom dialog box so that the user can decide whether to close the dialog box after they touch the back button or press the Esc key.

> **NOTE**
>
> This API must be called before the [show](#show) API is invoked.

**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle        | Pointer to the custom dialog box controller.|
| [ArkUI_OnWillDismissEvent](capi-native-dialog-h.md#arkui_onwilldismissevent) eventHandler | Callback for dialog box dismissal.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### show()

```
int32_t (*show)(ArkUI_NativeDialogHandle handle, bool showInSubWindow)
```

**Description**

Shows a custom dialog box.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool showInSubWindow | Whether to show the dialog box in a subwindow. **true**: The dialog box is shown in a subwindow. **false**: The dialog box is not shown in a subwindow.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### close()

```
int32_t (*close)(ArkUI_NativeDialogHandle handle)
```

**Description**


Closes a custom dialog box. If the dialog box has been closed, this API does not take effect.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnWillDismissWithUserData()

```
int32_t (*registerOnWillDismissWithUserData)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(ArkUI_DialogDismissEvent* event))
```

**Description**


Registers a callback for the dismissal event of a custom dialog box.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| void* userData | Pointer to user data.|
| callback | Callback for the dismissal event of the custom dialog box.<br> - **event**: input parameter of the callback, which captures the reason for dismissal.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
