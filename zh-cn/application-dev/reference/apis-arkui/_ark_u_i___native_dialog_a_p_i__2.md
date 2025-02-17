# ArkUI_NativeDialogAPI_2


## 概述

ArkUI提供的Native侧自定义弹窗接口集合2。

**起始版本：** 15

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md#ArkUI_NativeDialogAPI_1) nativeDialogAPI1 | ArkUI提供的Native侧自定义弹窗接口集合  | 
| int32_t(\* [setKeyboardAvoidDistance](#setkeyboardavoiddistance) )([ArkUI_NativeDialogHandle](_ark_u_i___native_module.md#arkui_nativedialoghandle) handle, float distance, [ArkUI_LengthMetricUnit](_ark_u_i___native_module.md#arkui_lengthmetricunit) unit) | 弹窗避让键盘后，和键盘之间的距离。  | 


## 结构体成员变量说明


### setKeyboardAvoidDistance

```
int32_t(* ArkUI_NativeDialogAPI_2::setKeyboardAvoidDistance) (ArkUI_NativeDialogHandle handle, float distance, ArkUI_LengthMetricUnit unit)
```
**描述：**

弹窗避让键盘后，和键盘之间的距离，默认值为16vp，默认单位为vp，当且仅当keyboardAvoidMode属性设置为DEFAULT时生效。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 指向自定义弹窗控制器的指针。  | 
| distance | 弹窗避让键盘后，和键盘之间的距离数值。 | 
| ArkUI_LengthMetricUnit | 弹窗避让键盘后，和键盘之间的距离单位。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
