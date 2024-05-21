# ArkUI_NativeAnimateAPI_1


## 概述

ArkUI提供的Native侧动画接口集合。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t(\* [animateTo](#animateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle) context, [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ContextCallback](_ark_u_i___context_callback.md) \*update, [ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) \*complete) | 显式动画接口  | 


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

返回错误码，0 - 成功， 401 - 参数错误。
