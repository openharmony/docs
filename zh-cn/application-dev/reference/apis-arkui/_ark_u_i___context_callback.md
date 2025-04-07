# ArkUI_ContextCallback


## 概述

事件回调类型。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_type.h](native__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| void \* [userData](#userdata) | 自定义类型。  | 
| void(\* [callback](#callback) )(void \*[userData](#userdata)) | 事件回调。  | 


## 结构体成员变量说明


### callback

```
void(* ArkUI_ContextCallback::callback) (void *userData)
```
**描述：**

事件回调。


### userData

```
void* ArkUI_ContextCallback::userData
```
**描述：**

自定义类型。
