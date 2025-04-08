# ArkWeb_JavaScriptValueAPI


## 概述

定义了ArkWeb原生JavaScriptValue接口。 在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。

**起始版本：** 14

**相关模块：**[Web](_web.md)

**所在头文件：** [arkweb_type.h](arkweb__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| [ArkWeb_JavaScriptValuePtr](_web.md#arkweb_javascriptvalueptr)(\* [createJavaScriptValue](#createjavascriptvalue) )([ArkWeb_JavaScriptValueType](_web.md#arkweb_javascriptvaluetype) type, void \*data, size_t dataLength) | 创建一个JavaScript值，用于返回给HTML。  | 


## 结构体成员变量说明


### createJavaScriptValue

```
ArkWeb_JavaScriptValuePtr(* ArkWeb_JavaScriptValueAPI::createJavaScriptValue) (ArkWeb_JavaScriptValueType type, void *data, size_t dataLength)
```
**描述：**

创建一个JavaScript值，用于返回给HTML。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | JavaScript值的类型。  | 
| data | JavaScript值的数据缓冲区。  | 
| dataLength | JavaScript值的缓冲区大小。  | 

**返回：**

创建出来的JavaScript值。


### size

```
size_t ArkWeb_JavaScriptValueAPI::size
```
**描述：**

结构体的大小。
