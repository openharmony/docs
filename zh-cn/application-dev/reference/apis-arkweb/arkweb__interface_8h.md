# arkweb_interface.h


## 概述

提供ArkWeb在Native侧获取API的接口，及基础Native API类型。

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | 定义基础Native API类型。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) {<br/>[ARKWEB_NATIVE_COMPONENT](_web.md), [ARKWEB_NATIVE_CONTROLLER](_web.md), [ARKWEB_NATIVE_WEB_MESSAGE_PORT](_web.md), [ARKWEB_NATIVE_WEB_MESSAGE](_web.md),<br/>[ARKWEB_NATIVE_COOKIE_MANAGER](_web.md)<br/>} | 定义Native API的类型枚举。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* [OH_ArkWeb_GetNativeAPI](_web.md#oh_arkweb_getnativeapi) ([ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) type) | 根据传入的API类型，获取对应的Native API结构体。  | 
