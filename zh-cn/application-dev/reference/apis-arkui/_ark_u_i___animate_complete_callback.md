# ArkUI_AnimateCompleteCallback


## 概述

动画播放完成回调类型。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_FinishCallbackType](_ark_u_i___native_module.md#arkui_finishcallbacktype) [type](#type) | 在动画中定义onFinish回调的类型。  | 
| void(\* [callback](#callback) )(void \*[userData](#userdata)) | 动画播放完成回调。  | 
| void \* [userData](#userdata) | 自定义类型。  | 


## 结构体成员变量说明


### callback

```
void(* ArkUI_AnimateCompleteCallback::callback) (void *userData)
```
**描述：**

动画播放完成回调。


### type

```
ArkUI_FinishCallbackType ArkUI_AnimateCompleteCallback::type
```
**描述：**

在动画中定义onFinish回调的类型。


### userData

```
void* ArkUI_AnimateCompleteCallback::userData
```
**描述：**

自定义类型。
