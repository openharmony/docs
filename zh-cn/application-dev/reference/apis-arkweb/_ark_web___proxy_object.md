# ArkWeb_ProxyObject


## 概述

注入的Proxy对象通用结构体。

**起始版本：** 12

**相关模块：**[Web](_web.md)

**所在头文件：** [arkweb_type.h](arkweb__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [objName](#objname) | 注入的对象名。  | 
| const [ArkWeb_ProxyMethod](_ark_web___proxy_method.md) \* [methodList](#methodlist) | 注入的对象携带的方法结构体数组。  | 
| size_t [size](#size) | 方法结构体数组的长度。  | 


## 结构体成员变量说明


### methodList

```
const ArkWeb_ProxyMethod* ArkWeb_ProxyObject::methodList
```
**描述：**

注入的对象携带的方法结构体数组。


### objName

```
const char* ArkWeb_ProxyObject::objName
```
**描述：**

注入的对象名。


### size

```
size_t ArkWeb_ProxyObject::size
```
**描述：**

方法结构体数组的长度。
