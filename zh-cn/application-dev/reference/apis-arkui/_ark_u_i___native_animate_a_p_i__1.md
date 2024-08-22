# ArkUI_NativeAnimateAPI_1


## 概述

ArkUI提供的Native侧动画接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t(\* [animateTo](#animateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ContextCallback](_ark_u_i___context_callback.md) \*update, [ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) \*complete) | 显式动画接口  | 
| int32_t(\* [keyframeAnimateTo](#keyframeanimateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option) | 关键帧动画接口  | 
| [ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle)(\* [createAnimator](#createanimator) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 创建animator动画对象  | 
| void(\* [disposeAnimator](#disposeanimator) )([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 销毁animator动画对象。  | 


## 结构体成员变量说明


### animateTo

```
int32_t(* ArkUI_NativeAnimateAPI_1::animateTo) (ArkUI_ContextHandle context, ArkUI_AnimateOption *option, ArkUI_ContextCallback *update, ArkUI_AnimateCompleteCallback *complete)
```
**描述：**

显式动画接口

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | UIContext实例。  | 
| option | 设置动画效果相关参数。  | 
| update | 指定动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。  | 
| complete | 设置动画播放完成回调参数。  | 

**注解：**

event闭包中要设置的组件属性，必须在其之前设置过。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### createAnimator

```
ArkUI_AnimatorHandle(* ArkUI_NativeAnimateAPI_1::createAnimator) (ArkUI_ContextHandle context, ArkUI_AnimatorOption *option)
```
**描述：**

创建animator动画对象

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | UIContext实例。  | 
| option | animator动画参数。  | 

**返回：**

animator动画对象指针。函数参数异常时返回NULL。


### disposeAnimator

```
void(* ArkUI_NativeAnimateAPI_1::disposeAnimator) (ArkUI_AnimatorHandle animator)
```
**描述：**

销毁animator动画对象。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| animator | animator动画对象。  | 


### keyframeAnimateTo

```
int32_t(* ArkUI_NativeAnimateAPI_1::keyframeAnimateTo) (ArkUI_ContextHandle context, ArkUI_KeyframeAnimateOption *option)
```
**描述：**

关键帧动画接口

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | UIContext实例。  | 
| option | 关键帧动画参数。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
