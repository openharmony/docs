# ArkUI_NativeDialogAPI_2


## 概述

ArkUI提供的Native侧自定义弹窗接口集合2。

**起始版本：** 15

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_dialog.h](native__dialog_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#ArkUI_NativeDialogAPI_1) nativeDialogAPI1 | ArkUI提供的Native侧自定义弹窗接口集合  | 
| int32_t(\* [setKeyboardAvoidDistance](#setkeyboardavoiddistance) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float distance, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 弹窗避让键盘后，和键盘之间的最小距离。  | 
| int32_t(\* [setLevelMode](#setlevelmode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_LevelMode](_ark_u_i___native_module.md#arkui_levelmode) levelMode) | 设置弹窗的显示层级。  | 
| int32_t(\* [setLevelUniqueId](#setleveluniqueid) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, int32_t uniqueId) | 设置弹窗显示层级页面下的节点id。  | 
| int32_t(\* [setImmersiveMode](#setimmersivemode) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, [ArkUI_ImmersiveMode](_ark_u_i___native_module.md#arkui_immersivemode) immersiveMode) | 设置嵌入式弹窗蒙层的显示区域。  | 



## 结构体成员变量说明


### setKeyboardAvoidDistance

```
int32_t(* ArkUI_NativeDialogAPI_2::setKeyboardAvoidDistance) (ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)
```
**描述：**

弹窗避让键盘后，和键盘之间的距离，默认值为16vp，默认单位为vp，当且仅当keyboardAvoidMode属性设置为DEFAULT时生效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| distance | 弹窗避让键盘后，和键盘之间的距离数值。 | 
| unit | 弹窗避让键盘后，和键盘之间的距离单位。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。

### setLevelMode

```
int32_t(* ArkUI_NativeDialogAPI_2::setLevelMode) (ArkUI_NativeDialogHandle handle, ArkUI_LevelMode levelMode)
```
**描述：**

设置弹窗的显示层级，该方法需要在调用show方法之前调用。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| levelMode | 显示层级的枚举值，参数类型ArkUI_LevelMode。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。

### setLevelUniqueId

```
int32_t(* ArkUI_NativeDialogAPI_2::setLevelUniqueId) (ArkUI_NativeDialogHandle handle, int32_t uniqueId)
```
**描述：**

设置弹窗显示层级页面下的节点id，该方法需要在调用setLevelMode方法之前调用。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| uniqueId | 指定节点id，会查找该节点所在页面，并将弹窗显示在该页面下。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。

### setImmersiveMode

```
int32_t(* ArkUI_NativeDialogAPI_2::setImmersiveMode) (ArkUI_NativeDialogHandle handle, ArkUI_ImmersiveMode immersiveMode)
```
**描述：**

设置嵌入式弹窗蒙层的显示区域，该方法需要在调用show方法之前调用。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| immersiveMode | 显示区域类型的枚举值， 类型为ArkUI_ImmersiveMode。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
