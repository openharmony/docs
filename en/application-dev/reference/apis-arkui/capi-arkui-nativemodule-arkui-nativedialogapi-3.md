# ArkUI_NativeDialogAPI_3
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Provides a collection of native-side custom dialog box APIs provided by ArkUI.

**Since**: 19

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_dialog.h](capi-native-dialog-h.md)

## Summary

### Member Variables

| Name                                                                                            | Description|
|------------------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md) nativeDialogAPI1 | Collection of native-side custom dialog box APIs provided by ArkUI, covering the scope of [ArkUI_NativeDialogAPI_1](capi-arkui-nativemodule-arkui-nativedialogapi-1.md).<br>**Since**: 19|
| [ArkUI_NativeDialogAPI_2](capi-arkui-nativemodule-arkui-nativedialogapi-2.md) nativeDialogAPI2                                                   | Collection of native-side custom dialog box APIs provided by ArkUI, covering the scope of [ArkUI_NativeDialogAPI_2](capi-arkui-nativemodule-arkui-nativedialogapi-2.md).<br>**Since**: 19|


### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*setLevelOrder)(ArkUI_NativeDialogHandle handle, double levelOrder)](#setlevelorder) | Sets the display order of the custom dialog box.|
| [int32_t (\*registerOnWillAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (\*callback)(void* userData))](#registeronwillappear) | Registers a callback function that is triggered before the custom dialog box appears.|
| [int32_t (\*registerOnDidAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (\*callback)(void* userData))](#registerondidappear) | Registers a callback function that is triggered after the custom dialog box appears.|
| [int32_t (\*registerOnWillDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (\*callback)(void* userData))](#registeronwilldisappear) | Registers a callback function that is triggered before the custom dialog box disappears.|
| [int32_t (\*registerOnDidDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (\*callback)(void* userData))](#registerondiddisappear) | Registers a callback function that is triggered after the custom dialog box disappears.|
| [int32_t (\*setBorderWidth)(ArkUI_NativeDialogHandle handle, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)](#setborderwidth) | Sets the border width of the custom dialog box.|
| [int32_t (\*setBorderColor)(ArkUI_NativeDialogHandle handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)](#setbordercolor) | Sets the border color of the custom dialog box.|
| [int32_t (\*setBorderStyle)(ArkUI_NativeDialogHandle handle, int32_t top, int32_t right, int32_t bottom, int32_t left)](#setborderstyle) | Sets the border style of the custom dialog box.|
| [int32_t (\*setWidth)(ArkUI_NativeDialogHandle handle, float width, ArkUI_LengthMetricUnit unit)](#setwidth) | Sets the backdrop width of the custom dialog box.|
| [int32_t (\*setHeight)(ArkUI_NativeDialogHandle handle, float height, ArkUI_LengthMetricUnit unit)](#setheight) | Sets the backdrop height of the custom dialog box.|
| [int32_t (\*setShadow)(ArkUI_NativeDialogHandle handle, ArkUI_ShadowStyle shadow)](#setshadow) | Sets the shadow of the custom dialog box's backdrop.|
| [int32_t (\*setCustomShadow)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* customShadow)](#setcustomshadow) | Sets the shadow of the custom dialog box's backdrop.|
| [int32_t (\*setBackgroundBlurStyle)(ArkUI_NativeDialogHandle handle, ArkUI_BlurStyle blurStyle)](#setbackgroundblurstyle) | Sets the backdrop blur style of the custom dialog box.|
| [int32_t (\*setKeyboardAvoidMode)(ArkUI_NativeDialogHandle handle, ArkUI_KeyboardAvoidMode keyboardAvoidMode)](#setkeyboardavoidmode) | Sets the keyboard avoidance mode of the custom dialog box.|
| [int32_t (\*enableHoverMode)(ArkUI_NativeDialogHandle handle, bool enableHoverMode)](#enablehovermode) | Sets whether the enable the hover mode for the custom dialog box.|
| [int32_t (\*setHoverModeArea)(ArkUI_NativeDialogHandle handle, ArkUI_HoverModeAreaType hoverModeAreaType)](#sethovermodearea) | Sets the default display area of the custom dialog box in hover mode.|
| [int32_t (\*setFocusable)(ArkUI_NativeDialogHandle handle, bool focusable)](#setfocusable) | Sets whether the custom dialog box can gain focus.|
| [int32_t (\*setBackgroundBlurStyleOptions)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundBlurStyleOptions)](#setbackgroundblurstyleoptions) | Sets the background blur effect of the custom dialog box.|
| [int32_t (\*setBackgroundEffect)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundEffect)](#setbackgroundeffect) | Sets the background effect parameters of the custom dialog box.|

## Member Function Description

### setLevelOrder()

```
int32_t (*setLevelOrder)(ArkUI_NativeDialogHandle handle, double levelOrder)
```

**Description**


Sets the display order of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                | Description|
|-------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| double levelOrder                   | Display order of the custom dialog box. Default value: **0**. Value range: [-100000.0, 100000.0].|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnWillAppear()

```
int32_t (*registerOnWillAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback function that is triggered before the custom dialog box appears.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                | Description|
|-------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| void* userData                      | Custom data.|
| callback                            | Callback function that is triggered before the custom dialog box appears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnDidAppear()

```
int32_t (*registerOnDidAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback function that is triggered after the custom dialog box appears.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| void* userData | Custom data.|
| callback | Callback function that is triggered after the custom dialog box appears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnWillDisappear()

```
int32_t (*registerOnWillDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback function that is triggered before the custom dialog box disappears.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| void* userData | Custom data.|
| callback | Callback function that is triggered before the custom dialog box disappears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### registerOnDidDisappear()

```
int32_t (*registerOnDidDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```

**Description**


Registers a callback function that is triggered after the custom dialog box disappears.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| void* userData | Custom data.|
| callback | Callback function that is triggered after the custom dialog box disappears.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBorderWidth()

```
int32_t (*setBorderWidth)(ArkUI_NativeDialogHandle handle, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the border width of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| float top                                                                          | Top border width.|
| float right                                                                        | Right border width.|
| float bottom                                                                       | Bottom border width.|
| float left                                                                         | Left border width.|
| [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit        | Unit of the width. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBorderColor()

```
int32_t (*setBorderColor)(ArkUI_NativeDialogHandle handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```

**Description**


Sets the border color of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  uint32_t top | Top border color.|
|  uint32_t right | Right border color.|
|  uint32_t bottom | Bottom border color.|
|  uint32_t left | Left border color.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBorderStyle()

```
int32_t (*setBorderStyle)(ArkUI_NativeDialogHandle handle, int32_t top, int32_t right, int32_t bottom, int32_t left)
```

**Description**


Sets the border style of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  int32_t top | Upper border style.|
|  int32_t right | Right border style.|
|  int32_t bottom | Bottom border style.|
|  int32_t left | Left border style.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setWidth()

```
int32_t (*setWidth)(ArkUI_NativeDialogHandle handle, float width, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the backdrop width of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  float width | Backdrop width.|
|  [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit of the width. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setHeight()

```
int32_t (*setHeight)(ArkUI_NativeDialogHandle handle, float height, ArkUI_LengthMetricUnit unit)
```

**Description**


Sets the backdrop height of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  float height | Backdrop height.|
|  [ArkUI_LengthMetricUnit](capi-native-type-h.md#arkui_lengthmetricunit) unit | Unit of the height. The default value is vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setShadow()

```
int32_t (*setShadow)(ArkUI_NativeDialogHandle handle, ArkUI_ShadowStyle shadow)
```

**Description**


Sets the shadow of the custom dialog box's backdrop.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_ShadowStyle](capi-native-type-h.md#arkui_shadowstyle) shadow                | Backdrop shadow style, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setCustomShadow()

```
int32_t (*setCustomShadow)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* customShadow)
```

**Description**


Sets the shadow of the custom dialog box's backdrop.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* customShadow                                        | Custom shadow parameters. The format is consistent with the **NODE_SHADOW** property in [ArkUI_NodeAttributeType](./capi-native-node-h.md#arkui_nodeattributetype).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBackgroundBlurStyle()

```
int32_t (*setBackgroundBlurStyle)(ArkUI_NativeDialogHandle handle, ArkUI_BlurStyle blurStyle)
```

**Description**


Sets the backdrop blur style of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
| [ArkUI_BlurStyle](capi-native-type-h.md#arkui_blurstyle) blurStyle                 | Backdrop blur material, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setKeyboardAvoidMode()

```
int32_t (*setKeyboardAvoidMode)(ArkUI_NativeDialogHandle handle, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```

**Description**


Sets the keyboard avoidance mode of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                                       | Description|
|--------------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle         | Pointer to the custom dialog box controller.|
| [ArkUI_KeyboardAvoidMode](capi-native-type-h.md#arkui_keyboardavoidmode) keyboardAvoidMode | Keyboard avoidance mode, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### enableHoverMode()

```
int32_t (*enableHoverMode)(ArkUI_NativeDialogHandle handle, bool enableHoverMode)
```

**Description**


Sets whether the enable the hover mode for the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool enableHoverMode | Whether to respond when the device is in semi-folded mode. The default value is **false**. The value **true** means to enable the hover mode, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setHoverModeArea()

```
int32_t (*setHoverModeArea)(ArkUI_NativeDialogHandle handle, ArkUI_HoverModeAreaType hoverModeAreaType)
```

**Description**


Sets the default display area of the custom dialog box in hover mode.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name                                                                                       | Description|
|--------------------------------------------------------------------------------------------| -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle         | Pointer to the custom dialog box controller.|
| [ArkUI_HoverModeAreaType](capi-native-type-h.md#arkui_hovermodeareatype) hoverModeAreaType | Display area in hover mode, specified by an enumerated value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setFocusable()

```
int32_t (*setFocusable)(ArkUI_NativeDialogHandle handle, bool focusable)
```

**Description**


Sets whether the custom dialog box can gain focus.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  bool focusable | Whether the custom dialog box can gain focus. The value **true** means that the custom dialog box can gain focus, and **false** means the opposite. The preset value is **true**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBackgroundBlurStyleOptions()

```
int32_t (*setBackgroundBlurStyleOptions)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```

**Description**


Sets the background blur effect of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundBlurStyleOptions | Options for customizing the background blur effect. The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter is as follows:<br>        .value[0].i32: color mode, specified by an enumerated value of [ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode).<br>        .value[1]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor).<br>        .value[2]? .f32: blur degree. The value range is [0.0, 1.0].<br>        .value[3]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>        .value[4]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>        .value[5]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy).<br>        .value[6]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### setBackgroundEffect()

```
int32_t (*setBackgroundEffect)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundEffect)
```

**Description**


Sets the background effect parameters of the custom dialog box.

> **NOTE**
>
> This API must be called before the [show](capi-arkui-nativemodule-arkui-nativedialogapi-1.md#show) API is invoked.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeDialogHandle](capi-arkui-nativemodule-arkui-nativedialog8h.md) handle | Pointer to the custom dialog box controller.|
|  const [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)* backgroundEffect | Background effect parameters. The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter is as follows:<br>        .value[0].f32: blur radius, in vp.<br>        .value[1]?.f32: saturation.<br>        .value[2]?.f32: brightness.<br>        .value[3]?.u32: color, in 0xARGB format.<br>        .value[4]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor).<br>        .value[5]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>        .value[6]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>        .value[7]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](capi-native-type-h.md#arkui_blurstyleactivepolicy).<br>        .value[8]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>             Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>             Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
