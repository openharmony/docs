# ArkWeb_ComponentAPI


## 概述

Component相关的Native API结构体。

**起始版本：** 12

**相关模块：**[Web](_web.md)

**所在头文件：** [arkweb_type.h](arkweb__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| void(\* [onControllerAttached](#oncontrollerattached) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | 当Controller成功绑定到Web组件时触发该回调。  | 
| void(\* [onPageBegin](#onpagebegin) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | 网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。  | 
| void(\* [onPageEnd](#onpageend) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | 网页加载完成时触发该回调，且只在主frame触发。  | 
| void(\* [onDestroy](#ondestroy) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | 当前Web组件销毁时触发该回调。  | 


## 结构体成员变量说明


### onControllerAttached

```
void(* ArkWeb_ComponentAPI::onControllerAttached) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**描述：**

当Controller成功绑定到Web组件时触发该回调。


### onDestroy

```
void(* ArkWeb_ComponentAPI::onDestroy) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**描述：**

当前Web组件销毁时触发该回调。


### onPageBegin

```
void(* ArkWeb_ComponentAPI::onPageBegin) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**描述：**

网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。


### onPageEnd

```
void(* ArkWeb_ComponentAPI::onPageEnd) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**描述：**

网页加载完成时触发该回调，且只在主frame触发。


### size

```
size_t ArkWeb_ComponentAPI::size
```
**描述：**

结构体的大小。
