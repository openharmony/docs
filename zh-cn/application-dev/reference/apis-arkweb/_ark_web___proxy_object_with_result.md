# ArkWeb_ProxyObjectWithResult


## 概述

注入的Proxy对象通用结构体。

**起始版本：** 14

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [objName](#objname) | 注入的对象名。  | 
| const [ArkWeb_ProxyMethodWithResult](_ark_web___proxy_method_with_result.md) \* [methodList](#methodlist) | 注入的对象携带的方法结构体数组。  | 
| size_t [size](#size) | 方法结构体数组的长度。  | 


## 结构体成员变量说明


### methodList

```
const ArkWeb_ProxyMethodWithResult* ArkWeb_ProxyObjectWithResult::methodList
```
**描述：**

注入的对象携带的方法结构体数组。


### objName

```
const char* ArkWeb_ProxyObjectWithResult::objName
```
**描述：**

注入的对象名。


### size

```
size_t ArkWeb_ProxyObjectWithResult::size
```
**描述：**

方法结构体数组的长度。
