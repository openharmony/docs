# JSVM_PropertyDescriptor


## 概述

属性描述符。

**起始版本：** 11

**相关模块：** [JSVM](_j_s_v_m.md)

**所在头文件：** [jsvm_types.h](jsvm__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [utf8name](#utf8name) | 描述属性键值的可选字符串，UTF8编码。 必须为属性提供utf8name或name之一。  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [name](#name) | 可选的JSVM_Value，指向用作属性键的JavaScript字符串或符号。 必须为属性提供utf8name或name之一。  | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [method](#method) | 设置此项使属性描述符对象的value属性成为method表示的JavaScript函数。  | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [getter](#getter) | 执行对属性的获取访问时调用的函数。  | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [setter](#setter) | 执行属性的设置访问时调用的函数。  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [value](#value) | 如果属性是数据属性，则通过属性的get访问检索到的值。  | 
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) [attributes](#attributes) | 与特定属性关联的属性。  | 


## 结构体成员变量说明


### attributes

```
JSVM_PropertyAttributes JSVM_PropertyDescriptor::attributes
```
**描述**
与特定属性关联的属性。


### getter

```
JSVM_Callback JSVM_PropertyDescriptor::getter
```
**描述**
执行对属性的获取访问时调用的函数。


### method

```
JSVM_Callback JSVM_PropertyDescriptor::method
```
**描述**
设置此项使属性描述符对象的value属性成为method表示的JavaScript函数。


### name

```
JSVM_Value JSVM_PropertyDescriptor::name
```
**描述**
可选的JSVM_Value，指向用作属性键的JavaScript字符串或符号。 必须为属性提供utf8name或name之一。


### setter

```
JSVM_Callback JSVM_PropertyDescriptor::setter
```
**描述**
执行属性的设置访问时调用的函数。


### utf8name

```
const char* JSVM_PropertyDescriptor::utf8name
```
**描述**
描述属性键值的可选字符串，UTF8编码。 必须为属性提供utf8name或name之一。


### value

```
JSVM_Value JSVM_PropertyDescriptor::value
```
**描述**
如果属性是数据属性，则通过属性的get访问检索到的值。
