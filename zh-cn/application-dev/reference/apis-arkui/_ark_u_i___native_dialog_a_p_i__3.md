# ArkUI_NativeDialogAPI_3


## 概述

ArkUI提供的Native侧自定义弹窗接口集合。

**起始版本：** 18

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#ArkUI_NativeDialogAPI_1) nativeDialogAPI1 | ArkUI提供的Native侧自定义弹窗接口集合。  | 
| [ArkUI_NativeDialogAPI_2](_ark_u_i___native_dialog_a_p_i__2.md#ArkUI_NativeDialogAPI_2) nativeDialogAPI2 | ArkUI提供的Native侧自定义弹窗接口集合2。  |
| int32_t(\* [setBorderWidth](#setborderwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float top, float right, float bottom, float left, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的边框宽度。  | 
| int32_t(\* [setBorderColor](#setbordercolor) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left) | 设置弹窗的边框颜色。  | 
| int32_t(\* [setBorderStyle](#setborderstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t top, int32_t right, int32_t bottom, int32_t left) | 设置弹窗的边框样式。  | 
| int32_t(\* [setWidth](#setwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float width, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的背板宽度。  | 
| int32_t(\* [setHeight](#setheight) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float height, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置弹窗的背板高度。  | 
| int32_t(\* [setShadow](#setshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_ShadowStyle](_ark_u_i___native_module.md#arkui_shadowstyle) shadow) | 设置弹窗的背板阴影。  | 
| int32_t(\* [setCustomShadow](#setcustomshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* customShadow) | 设置弹窗背板的自定义阴影。  | 
| int32_t(\* [setBackgroundBlurStyle](#setbackgroundblurstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_BlurStyle](_ark_u_i___native_module.md#arkui_blurstyle) blurStyle) | 设置弹窗的背板模糊材质。  | 
| int32_t(\* [setKeyboardAvoidMode](#setkeyboardavoidmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_KeyboardAvoidMode](_ark_u_i___native_module.md#arkui_keyboardavoidmode) keyboardAvoidMode) | 设置弹窗避让键盘模式。  | 
| int32_t(\* [enableHoverMode](#enablehovermode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableHoverMode) | 设置弹窗是否相应悬停态。  | 
| int32_t(\* [setHoverModeArea](#sethovermodearea) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_HoverModeAreaType](_ark_u_i___native_module.md#arkui_hovermodeareatype) hoverModeAreaType) | 设置悬停态下弹窗默认展示区域。  | 

## 结构体成员变量说明


### setBorderWidth

```
int32_t (*setBorderWidth)(ArkUI_NativeDialogHandle handle, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置弹窗的边框宽度。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| top | 上边框的宽度。  | 
| right | 右边框的宽度。  | 
| bottom | 下边框的宽度。  | 
| left | 左边框的宽度。  | 
| unit | 指定宽度单位，默认为vp。  | 

**注解：**

setBorderWidth方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setBorderColor

```
int32_t (*setBorderColor)(ArkUI_NativeDialogHandle handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```
**描述：**

设置弹窗的边框颜色。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| top | 上边框的颜色。  | 
| right | 右边框的颜色。  | 
| bottom | 下边框的颜色。  | 
| left | 左边框的颜色。  |

**注解：**

setBorderColor方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setBorderStyle

```
int32_t (*setBorderStyle)(ArkUI_NativeDialogHandle handle, int32_t top, int32_t right, int32_t bottom, int32_t left)
```
**描述：**

设置弹窗的边框样式。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| top | 上边框的样式。  | 
| right | 右边框的样式。  | 
| bottom | 下边框的样式。  | 
| left | 左边框的样式。  |

**注解：**

setBorderStyle方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setWidth

```
int32_t (*setWidth)(ArkUI_NativeDialogHandle handle, float width, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置弹窗的背板宽度。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| width | 背板宽度。  | 
| unit | 指定高度的单位，默认为vp。  | 

**注解：**

setWidth方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setHeight

```
int32_t (*setHeight)(ArkUI_NativeDialogHandle handle, float height, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置弹窗的背板高度。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| height | 背板高度。  | 
| unit | 指定高度的单位，默认为vp。  | 

**注解：**

setHeight方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setShadow

```
int32_t (*setShadow)(ArkUI_NativeDialogHandle handle, ArkUI_ShadowStyle shadow)
```
**描述：**

设置弹窗的背板阴影。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| shadow | 背板阴影样式，枚举值。  |

**注解：**

setShadow方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setCustomShadow

```
int32_t (*setCustomShadow)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* customShadow)
```
**描述：**

设置弹窗的自定义阴影。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| customShadow | 自定义阴影参数，格式与NODE_SHADOW属性一致。  |

**注解：**

setCustomShadow方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setBackgroundBlurStyle

```
int32_t (*setBackgroundBlurStyle)(ArkUI_NativeDialogHandle handle, ArkUI_BlurStyle blurStyle)
```
**描述：**

设置弹窗的背板模糊材质。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| blurStyle | 背板模糊材质，枚举值。  |

**注解：**

setBackgroundBlurStyle方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setKeyboardAvoidMode

```
int32_t (*setKeyboardAvoidMode)(ArkUI_NativeDialogHandle handle, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```
**描述：**

设置弹窗避让键盘模式。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| keyboardAvoidMode | 避让键盘模式，枚举值。  |

**注解：**

setKeyboardAvoidMode方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### enableHoverMode

```
int32_t (*enableHoverMode)(ArkUI_NativeDialogHandle handle, bool enableHoverMode)
```
**描述：**

设置弹窗是否相应悬停态。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| enableHoverMode | 是否相应悬停态，默认false。  |

**注解：**

enableHoverMode方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。


### setHoverModeArea

```
int32_t (*setHoverModeArea)(ArkUI_NativeDialogHandle handle, ArkUI_HoverModeAreaType hoverModeAreaType)
```
**描述：**

设置悬停态下弹窗默认展示区域。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 弹窗控制器的指针。  | 
| hoverModeAreaType | 悬停态区域，枚举值。  |

**注解：**

setHoverModeArea方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)正常。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)参数异常。