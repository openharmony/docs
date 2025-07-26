# ArkUI_NativeDialogAPI_3


## Overview

Provides the native custom dialog box APIs of ArkUI.

**Since**: 19

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)

**Header file**: [native_dialog.h](native__dialog_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#arkui_nativedialogapi_1) nativeDialogAPI1 | Provides the primary set of native custom dialog box APIs of ArkUI. | 
| [ArkUI_NativeDialogAPI_2](_ark_u_i___native_dialog_a_p_i__2.md#arkui_nativedialogapi_2) nativeDialogAPI2 | Provides the secondary set of native custom dialog box APIs of ArkUI. |
| int32_t(\* [setLevelOrder](#setlevelorder) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, double levelOrder) | Sets the display order of the custom dialog box. | 
| int32_t(\* [registerOnWillAppear](#registeronwillappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | Registers a callback function that is triggered before the custom dialog box appears. | 
| int32_t(\* [registerOnDidAppear](#registerondidappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | Registers a callback function that is triggered after the custom dialog box appears. | 
| int32_t(\* [registerOnWillDisappear](#registeronwilldisappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | Registers a callback function that is triggered before the custom dialog box disappears. | 
| int32_t(\* [registerOnDidDisappear](#registerondiddisappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | Registers a callback function that is triggered after the custom dialog box disappears. | 
| int32_t(\* [setBorderWidth](#setborderwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float top, float right, float bottom, float left, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Sets the border width of the custom dialog box. | 
| int32_t(\* [setBorderColor](#setbordercolor) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left) | Sets the border color of the custom dialog box. | 
| int32_t(\* [setBorderStyle](#setborderstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t top, int32_t right, int32_t bottom, int32_t left) | Sets the border style of the custom dialog box. | 
| int32_t(\* [setWidth](#setwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float width, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Sets the backdrop width of the custom dialog box. | 
| int32_t(\* [setHeight](#setheight) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float height, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | Sets the backdrop height of the custom dialog box. | 
| int32_t(\* [setShadow](#setshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_ShadowStyle](_ark_u_i___native_module.md#arkui_shadowstyle) shadow) | Sets the shadow of the custom dialog box's backdrop. | 
| int32_t(\* [setCustomShadow](#setcustomshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* customShadow) | Sets a custom shadow for the custom dialog box's backdrop. | 
| int32_t(\* [setBackgroundBlurStyle](#setbackgroundblurstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_BlurStyle](_ark_u_i___native_module.md#arkui_blurstyle) blurStyle) | Sets the backdrop blur style of the custom dialog box. | 
| int32_t(\* [setKeyboardAvoidMode](#setkeyboardavoidmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_KeyboardAvoidMode](_ark_u_i___native_module.md#arkui_keyboardavoidmode) keyboardAvoidMode) | Sets the keyboard avoidance mode of the custom dialog box. | 
| int32_t(\* [enableHoverMode](#enablehovermode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableHoverMode) | Sets whether the enable the hover mode for the custom dialog box. | 
| int32_t(\* [setHoverModeArea](#sethovermodearea) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_HoverModeAreaType](_ark_u_i___native_module.md#arkui_hovermodeareatype) hoverModeAreaType) | Sets the default display area of the custom dialog box in hover mode. | 
| int32_t(\* [setFocusable](#setfocusable) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool focusable) | Sets whether the custom dialog box can gain focus. | 
| int32_t(\* [setBackgroundBlurStyleOptions](#setbackgroundblurstyleoptions) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* backgroundBlurStyleOptions) | Sets the background blur effect of the custom dialog box. | 
| int32_t(\* [setBackgroundEffect](#setbackgroundeffect) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* backgroundEffect) | Sets the background effect parameters of the custom dialog box. | 

## Member Variable Description


### setLevelOrder

```
int32_t (*setLevelOrder)(ArkUI_NativeDialogHandle handle, double levelOrder)
```
**Description**

Sets the display order of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| levelOrder | Display order of the custom dialog box.<br>Default value: **0**<br>Value range: [-100000.0, 100000.0]. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### registerOnWillAppear

```
int32_t (*registerOnWillAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**Description**

Registers a callback function that is triggered before the custom dialog box appears.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| userData | Custom data. | 
| callback | Callback function that is triggered before the custom dialog box appears. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.


### registerOnDidAppear

```
int32_t (*registerOnDidAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**Description**

Registers a callback function that is triggered after the custom dialog box appears.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| userData | Custom data. | 
| callback | Callback function that is triggered after the custom dialog box appears. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.


### registerOnWillDisappear

```
int32_t (*registerOnWillDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**Description**

Registers a callback function that is triggered before the custom dialog box disappears.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| userData | Custom data. | 
| callback | Callback function that is triggered before the custom dialog box disappears. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.


### registerOnDidDisappear

```
int32_t (*registerOnDidDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**Description**

Registers a callback function that is triggered after the custom dialog box disappears.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| userData | Custom data. | 
| callback | Callback function that is triggered after the custom dialog box disappears. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.


### setBorderWidth

```
int32_t (*setBorderWidth)(ArkUI_NativeDialogHandle handle, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the border width of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| top | Top border width. | 
| right | Right border width. | 
| bottom | Bottom border width. | 
| left | Left border width. | 
| unit | Unit of the width. The default value is vp. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setBorderColor

```
int32_t (*setBorderColor)(ArkUI_NativeDialogHandle handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```
**Description**

Sets the border color of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| top | Top border color. | 
| right | Right border color. | 
| bottom | Bottom border color. | 
| left | Left border color. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setBorderStyle

```
int32_t (*setBorderStyle)(ArkUI_NativeDialogHandle handle, int32_t top, int32_t right, int32_t bottom, int32_t left)
```
**Description**

Sets the border style of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| top | Upper border style. | 
| right | Right border style. | 
| bottom | Bottom border style. | 
| left | Left border style. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setWidth

```
int32_t (*setWidth)(ArkUI_NativeDialogHandle handle, float width, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the backdrop width of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| width | Backdrop width. | 
| unit | Unit of the height. The default value is vp. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setHeight

```
int32_t (*setHeight)(ArkUI_NativeDialogHandle handle, float height, ArkUI_LengthMetricUnit unit)
```
**Description**

Sets the backdrop height of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| height | Backdrop height. | 
| unit | Unit of the height. The default value is vp. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setShadow

```
int32_t (*setShadow)(ArkUI_NativeDialogHandle handle, ArkUI_ShadowStyle shadow)
```
**Description**

Sets the shadow of the custom dialog box's backdrop.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| shadow | Backdrop shadow style, specified by an enumerated value. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setCustomShadow

```
int32_t (*setCustomShadow)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* customShadow)
```
**Description**

Sets a custom shadow for the custom dialog box's backdrop.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| customShadow | Custom shadow parameter. The format is the same as that of the **NODE_SHADOW** property. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setBackgroundBlurStyle

```
int32_t (*setBackgroundBlurStyle)(ArkUI_NativeDialogHandle handle, ArkUI_BlurStyle blurStyle)
```
**Description**

Sets the backdrop blur style of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| blurStyle | Backdrop blur material, specified by an enumerated value. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setKeyboardAvoidMode

```
int32_t (*setKeyboardAvoidMode)(ArkUI_NativeDialogHandle handle, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```
**Description**

Sets the keyboard avoidance mode of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| keyboardAvoidMode | Keyboard avoidance mode, specified by an enumerated value. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### enableHoverMode

```
int32_t (*enableHoverMode)(ArkUI_NativeDialogHandle handle, bool enableHoverMode)
```
**Description**

Sets whether the enable the hover mode for the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| enableHoverMode | Whether to enable the hover mode. The default value is **false**. The value **true** means to enable the hover mode, and **false** means the opposite. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setHoverModeArea

```
int32_t (*setHoverModeArea)(ArkUI_NativeDialogHandle handle, ArkUI_HoverModeAreaType hoverModeAreaType)
```
**Description**

Sets the default display area of the custom dialog box in hover mode.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| hoverModeAreaType | Display area in hover mode, specified by an enumerated value. |

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.


### setFocusable

```
int32_t (*setFocusable)(ArkUI_NativeDialogHandle handle, bool focusable)
```
**Description**

Sets whether the custom dialog box can gain focus.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| focusable | Whether the custom dialog box can gain focus. The value **true** means that the custom dialog box can gain focus, and **false** means the opposite.<br>The preset value is **true**. | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.

### setBackgroundBlurStyleOptions

```
int32_t (*setBackgroundBlurStyleOptions)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```
**Description**

Sets the background blur effect of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| backgroundBlurStyleOptions | Options for customizing the background blur effect.<br>The [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) format is as follows:<br>.value[0].i32: color mode, specified by an enumerated value of [ArkUI_ColorMode](_ark_u_i___native_module.md#arkui_colormode).<br>.value[1]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](_ark_u_i___native_module.md#arkui_adaptivecolor).<br>.value[2]? .f32: blur degree. The value range is [0.0, 1.0].<br>.value[3]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>.value[4]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>.value[5]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](_ark_u_i___native_module.md).<br>.value[6]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed). | 

**NOTE**

This method must be called before the **show** method.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) if the operation is successful.
Returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) if a parameter error occurs.

### setBackgroundEffect

```
int32_t (*setBackgroundEffect)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundEffect);
```
**Description**

Sets the background effect parameters of the custom dialog box.

**Since**: 19

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the custom dialog box controller. | 
| backgroundEffect | Background effect parameters.<br>The [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) format is as follows:<br>.value[0].f32: blur radius, in vp.<br>.value[1]?.f32: saturation.<br>.value[2]?.f32: brightness.<br>.value[3]?.u32: color, in 0xARGB format.<br>.value[4]?.i32: adaptive color mode, specified by an enumerated value of [ArkUI_AdaptiveColor](_ark_u_i___native_module.md#arkui_adaptivecolor).<br>.value[5]?.u32: brightness of black in the grayscale blur. The value range is [0, 127].<br>.value[6]?.u32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>.value[7]?.i32: blur activation policy, specified by an enumeration value of [ArkUI_BlurStyleActivePolicy](_ark_u_i___native_module.md).<br>.value[8]?.u32: background color, in 0xARGB format, of the components within the window after the window loses focus (in which case, the blur effect on the components within the window is removed). | 

**NOTE**

This method must be called before the **show** method.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.
