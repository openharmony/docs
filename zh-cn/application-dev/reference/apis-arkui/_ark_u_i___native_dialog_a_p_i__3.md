# ArkUI_NativeDialogAPI_3


## 概述

ArkUI提供的Native侧自定义弹窗接口集合。

**起始版本：** 19

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_dialog.h](native__dialog_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#arkui_nativedialogapi_1) nativeDialogAPI1 | ArkUI提供的Native侧自定义弹窗接口集合。  | 
| [ArkUI_NativeDialogAPI_2](_ark_u_i___native_dialog_a_p_i__2.md#arkui_nativedialogapi_2) nativeDialogAPI2 | ArkUI提供的Native侧自定义弹窗接口集合2。  |
| int32_t(\* [setLevelOrder](#setlevelorder) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, double levelOrder) | 设置自定义弹窗显示的顺序。  | 
| int32_t(\* [registerOnWillAppear](#registeronwillappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | 注册自定义弹窗显示之前的回调函数。  | 
| int32_t(\* [registerOnDidAppear](#registerondidappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | 注册自定义弹窗显示之后的回调函数。  | 
| int32_t(\* [registerOnWillDisappear](#registeronwilldisappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | 注册自定义弹窗关闭之前的回调函数。  | 
| int32_t(\* [registerOnDidDisappear](#registerondiddisappear) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, void* userData, void (* callback)(void* userData)) | 注册自定义弹窗关闭之后的回调函数。  | 
| int32_t(\* [setBorderWidth](#setborderwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float top, float right, float bottom, float left, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置自定义弹窗的边框宽度。  | 
| int32_t(\* [setBorderColor](#setbordercolor) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left) | 设置自定义弹窗的边框颜色。  | 
| int32_t(\* [setBorderStyle](#setborderstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t top, int32_t right, int32_t bottom, int32_t left) | 设置自定义弹窗的边框样式。  | 
| int32_t(\* [setWidth](#setwidth) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float width, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置自定义弹窗的背板宽度。  | 
| int32_t(\* [setHeight](#setheight) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float height, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 设置自定义弹窗的背板高度。  | 
| int32_t(\* [setShadow](#setshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_ShadowStyle](_ark_u_i___native_module.md#arkui_shadowstyle) shadow) | 设置自定义弹窗的背板阴影。  | 
| int32_t(\* [setCustomShadow](#setcustomshadow) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* customShadow) | 设置自定义弹窗背板的自定义阴影。  | 
| int32_t(\* [setBackgroundBlurStyle](#setbackgroundblurstyle) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_BlurStyle](_ark_u_i___native_module.md#arkui_blurstyle) blurStyle) | 设置自定义弹窗的背板模糊材质。  | 
| int32_t(\* [setKeyboardAvoidMode](#setkeyboardavoidmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_KeyboardAvoidMode](_ark_u_i___native_module.md#arkui_keyboardavoidmode) keyboardAvoidMode) | 设置自定义弹窗避让键盘模式。  | 
| int32_t(\* [enableHoverMode](#enablehovermode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool enableHoverMode) | 设置自定义弹窗是否相应悬停态。  | 
| int32_t(\* [setHoverModeArea](#sethovermodearea) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_HoverModeAreaType](_ark_u_i___native_module.md#arkui_hovermodeareatype) hoverModeAreaType) | 设置悬停态下自定义弹窗默认展示区域。  | 
| int32_t(\* [setFocusable](#setfocusable) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, bool focusable) | 设置自定义弹窗是否获取焦点。  | 
| int32_t(\* [setBackgroundBlurStyleOptions](#setbackgroundblurstyleoptions) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* backgroundBlurStyleOptions) | 设置自定义弹窗的背景模糊效果。  | 
| int32_t(\* [setBackgroundEffect](#setbackgroundeffect) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, const [ArkUI_AttributeItem](_ark_u_i___attribute_item.md#arkui_attributeitem)\* backgroundEffect) | 设置自定义弹窗的背景效果参数。  | 

## 结构体成员变量说明


### setLevelOrder

```
int32_t (*setLevelOrder)(ArkUI_NativeDialogHandle handle, double levelOrder)
```
**描述：**

设置自定义弹窗显示的顺序。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| levelOrder | 自定义弹窗显示的顺序。<br />默认值：0<br/>取值范围：[-100000.0, 100000.0]  | 

**注解：**

setLevelOrder方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### registerOnWillAppear

```
int32_t (*registerOnWillAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**描述：**

注册自定义弹窗显示之前的回调函数。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| userData | 用户自定义数据。  | 
| callback | 自定义弹窗显示之前的回调函数。  | 

**注解：**

registerOnWillAppear方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### registerOnDidAppear

```
int32_t (*registerOnDidAppear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**描述：**

注册自定义弹窗显示之后的回调函数。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| userData | 用户自定义数据。  | 
| callback | 自定义弹窗显示之后的回调函数。  | 

**注解：**

registerOnDidAppear方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### registerOnWillDisappear

```
int32_t (*registerOnWillDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**描述：**

注册自定义弹窗关闭之前的回调函数。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| userData | 用户自定义数据。  | 
| callback | 自定义弹窗关闭之前的回调函数。  | 

**注解：**

registerOnWillDisappear方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### registerOnDidDisappear

```
int32_t (*registerOnDidDisappear)(ArkUI_NativeDialogHandle handle, void* userData, void (*callback)(void* userData))
```
**描述：**

注册自定义弹窗关闭之后的回调函数。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| userData | 用户自定义数据。  | 
| callback | 自定义弹窗关闭之后的回调函数。  | 

**注解：**

registerOnDidDisappear方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode)成功。 
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode)函数参数异常。


### setBorderWidth

```
int32_t (*setBorderWidth)(ArkUI_NativeDialogHandle handle, float top, float right, float bottom, float left, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置自定义弹窗的边框宽度。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| top | 上边框的宽度。  | 
| right | 右边框的宽度。  | 
| bottom | 下边框的宽度。  | 
| left | 左边框的宽度。  | 
| unit | 指定宽度单位，默认为vp。  | 

**注解：**

setBorderWidth方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setBorderColor

```
int32_t (*setBorderColor)(ArkUI_NativeDialogHandle handle, uint32_t top, uint32_t right, uint32_t bottom, uint32_t left)
```
**描述：**

设置自定义弹窗的边框颜色。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| top | 上边框的颜色。  | 
| right | 右边框的颜色。  | 
| bottom | 下边框的颜色。  | 
| left | 左边框的颜色。  |

**注解：**

setBorderColor方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setBorderStyle

```
int32_t (*setBorderStyle)(ArkUI_NativeDialogHandle handle, int32_t top, int32_t right, int32_t bottom, int32_t left)
```
**描述：**

设置自定义弹窗的边框样式。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| top | 上边框的样式。  | 
| right | 右边框的样式。  | 
| bottom | 下边框的样式。  | 
| left | 左边框的样式。  |

**注解：**

setBorderStyle方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setWidth

```
int32_t (*setWidth)(ArkUI_NativeDialogHandle handle, float width, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置自定义弹窗的背板宽度。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| width | 背板宽度。  | 
| unit | 指定高度的单位，默认为vp。  | 

**注解：**

setWidth方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setHeight

```
int32_t (*setHeight)(ArkUI_NativeDialogHandle handle, float height, ArkUI_LengthMetricUnit unit)
```
**描述：**

设置自定义弹窗的背板高度。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| height | 背板高度。  | 
| unit | 指定高度的单位，默认为vp。  | 

**注解：**

setHeight方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setShadow

```
int32_t (*setShadow)(ArkUI_NativeDialogHandle handle, ArkUI_ShadowStyle shadow)
```
**描述：**

设置自定义弹窗的背板阴影。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| shadow | 背板阴影样式，枚举值。  |

**注解：**

setShadow方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setCustomShadow

```
int32_t (*setCustomShadow)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* customShadow)
```
**描述：**

设置自定义弹窗的自定义阴影。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| customShadow | 自定义阴影参数，格式与NODE_SHADOW属性一致。  |

**注解：**

setCustomShadow方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setBackgroundBlurStyle

```
int32_t (*setBackgroundBlurStyle)(ArkUI_NativeDialogHandle handle, ArkUI_BlurStyle blurStyle)
```
**描述：**

设置自定义弹窗的背板模糊材质。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| blurStyle | 背板模糊材质，枚举值。  |

**注解：**

setBackgroundBlurStyle方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setKeyboardAvoidMode

```
int32_t (*setKeyboardAvoidMode)(ArkUI_NativeDialogHandle handle, ArkUI_KeyboardAvoidMode keyboardAvoidMode)
```
**描述：**

设置自定义弹窗避让键盘模式。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| keyboardAvoidMode | 避让键盘模式，枚举值。  |

**注解：**

setKeyboardAvoidMode方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### enableHoverMode

```
int32_t (*enableHoverMode)(ArkUI_NativeDialogHandle handle, bool enableHoverMode)
```
**描述：**

设置自定义弹窗是否相应悬停态。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| enableHoverMode | 是否相应悬停态，默认false。true表示响应悬停态，false表示不响应悬停态。  |

**注解：**

enableHoverMode方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setHoverModeArea

```
int32_t (*setHoverModeArea)(ArkUI_NativeDialogHandle handle, ArkUI_HoverModeAreaType hoverModeAreaType)
```
**描述：**

设置悬停态下自定义弹窗默认展示区域。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| hoverModeAreaType | 悬停态区域，枚举值。  |

**注解：**

setHoverModeArea方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。


### setFocusable

```
int32_t (*setFocusable)(ArkUI_NativeDialogHandle handle, bool focusable)
```
**描述：**

设置自定义弹窗是否获取焦点。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| focusable | 自定义弹窗是否获取焦点。true表示自动获取焦点，false表示不自动获取焦点。<br />默认值：true  | 

**注解：**

setFocusable方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。

### setBackgroundBlurStyleOptions

```
int32_t (*setBackgroundBlurStyleOptions)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundBlurStyleOptions)
```
**描述：**

设置自定义弹窗的背景模糊效果。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| backgroundBlurStyleOptions | 背景模糊效果。<br/>参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示深浅色模式，取[ArkUI_ColorMode](_ark_u_i___native_module.md#arkui_colormode)枚举值。<br/>.value[1]?.i32 表示取色模式，取[ArkUI_AdaptiveColor](_ark_u_i___native_module.md#arkui_adaptivecolor)枚举值。<br/>.value[2]?.f32 表示模糊效果程度，取[0.0,1.0]范围内的值。<br/>.value[3]?.u32 表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]。<br/>.value[4]?.u32 表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]。<br/>.value[5]?.i32 表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](_ark_u_i___native_module.md#arkui_blurstyleactivepolicy)枚举值。<br/>.value[6]?.u32 表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xargb类型。  | 

**注解：**

setBackgroundBlurStyleOptions方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。

### setBackgroundEffect

```
int32_t (*setBackgroundEffect)(ArkUI_NativeDialogHandle handle, const ArkUI_AttributeItem* backgroundEffect);
```
**描述：**

设置自定义弹窗的背景效果参数。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| backgroundEffect | 背景效果参数。<br/>参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示模糊半径，单位为vp。<br/>.value[1]?.f32 表示饱和度。<br/>.value[2]?.f32 表示亮度。<br/>.value[3]?.u32 表示颜色，0xargb类型。<br/>.value[4]?.i32 表示取色模式，取[ArkUI_AdaptiveColor](_ark_u_i___native_module.md#arkui_adaptivecolor)枚举值。<br/>.value[5]?.u32 表示灰阶模糊参数，对黑色的提亮程度，有效值范围为[0,127]。<br/>.value[6]?.u32 表示灰阶模糊参数，对白色的压暗程度，有效值范围为[0,127]。<br/>.value[7]?.i32 表示模糊激活策略，取[ArkUI_BlurStyleActivePolicy](_ark_u_i___native_module.md#arkui_blurstyleactivepolicy)枚举值。<br/>.value[8]?.u32 表示窗口失焦后，窗口内控件模糊效果会被移除，此时控件背板的颜色，0xargb类型。  | 

**注解：**

setBackgroundEffect方法需要在调用show方法之前调用。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) 函数参数异常。
