# ArkUI_AttributeItem


## 概述

定义setAttribute函数通用入参结构。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_node.h](native__node_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const [ArkUI_NumberValue](union_ark_u_i___number_value.md) \* [value](#value) | 数字类型数组。  | 
| int32_t [size](#size) | 数字类型数组大小。  | 
| const char \* [string](#string) | 字符串类型。  | 
| void \* [object](#object) | 对象类型。  | 


## 结构体成员变量说明


### object

```
void* ArkUI_AttributeItem::object
```
**描述：**

对象类型。


### size

```
int32_t ArkUI_AttributeItem::size
```
**描述：**

数字类型数组大小。


### string

```
const char* ArkUI_AttributeItem::string
```
**描述：**

字符串类型。


### value

```
const ArkUI_NumberValue* ArkUI_AttributeItem::value
```
**描述：**

数字类型数组。
