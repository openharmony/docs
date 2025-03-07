# ArkWeb_ProxyMethod


## 概述

注入的Proxy方法通用结构体。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [methodName](#methodname) | 注入的方法名。  | 
| [ArkWeb_OnJavaScriptProxyCallback](_web.md#arkweb_onjavascriptproxycallback) [callback](#callback) | Proxy方法执行的回调。  | 
| void \* [userData](#userdata) | 需要在回调中携带的自定义数据。  | 


## 结构体成员变量说明


### callback

```
ArkWeb_OnJavaScriptProxyCallback ArkWeb_ProxyMethod::callback
```
**描述：**

Proxy方法执行的回调。


### methodName

```
const char* ArkWeb_ProxyMethod::methodName
```
**描述：**

注入的方法名。


### userData

```
void* ArkWeb_ProxyMethod::userData
```
**描述：**

需要在回调中携带的自定义数据。
