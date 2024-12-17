# ArkWeb_ProxyMethodWithResult


## 概述

注入的Proxy方法通用结构体。

**起始版本：** 14

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [methodName](#methodname) | 注入的方法名。  | 
| [ArkWeb_OnJavaScriptProxyCallbackWithResult](_web.md#arkweb_onjavascriptproxycallbackwithresult) [callback](#callback) | Proxy方法执行的回调。  | 
| void \* [userData](#userdata) | 需要在回调中携带的自定义数据。  | 


## 结构体成员变量说明


### callback

```
ArkWeb_OnJavaScriptProxyCallbackWithResult ArkWeb_ProxyMethodWithResult::callback
```
**描述：**

Proxy方法执行的回调。


### methodName

```
const char* ArkWeb_ProxyMethodWithResult::methodName
```
**描述：**

注入的方法名。


### userData

```
void* ArkWeb_ProxyMethodWithResult::userData
```
**描述：**

需要在回调中携带的自定义数据。
