# ArkWeb_JavaScriptObject


## 概述

注入的JavaScript结构体。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const uint8_t \* [buffer](#buffer) | 注入的JavaScript代码。  | 
| size_t [size](#size) | JavaScript代码长度。  | 
| [ArkWeb_OnJavaScriptCallback](_web.md#arkweb_onjavascriptcallback) [callback](#callback) | JavaScript执行完成的回调。  | 
| void \* [userData](#userdata) | 需要在回调中携带的自定义数据。  | 


## 结构体成员变量说明


### buffer

```
const uint8_t* ArkWeb_JavaScriptObject::buffer
```
**描述：**

注入的JavaScript代码。


### callback

```
ArkWeb_OnJavaScriptCallback ArkWeb_JavaScriptObject::callback
```
**描述：**

JavaScript执行完成的回调。


### size

```
size_t ArkWeb_JavaScriptObject::size
```
**描述：**

JavaScript代码长度。


### userData

```
void* ArkWeb_JavaScriptObject::userData
```
**描述：**

需要在回调中携带的自定义数据。
