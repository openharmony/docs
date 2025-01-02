# ArkUI_AttributeItem


## Overview

Defines the general input parameter structure of the **setAttribute** function.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const [ArkUI_NumberValue](union_ark_u_i___number_value.md) \* [value](#value) | Numeric array. | 
| int32_t [size](#size) | Size of the numeric array. | 
| const char \* [string](#string) | String type. | 
| void \* [object](#object) | Object type. | 


## Member Variable Description


### object

```
void* ArkUI_AttributeItem::object
```
**Description**

Object type.


### size

```
int32_t ArkUI_AttributeItem::size
```
**Description**

Size of the numeric array.


### string

```
const char* ArkUI_AttributeItem::string
```
**Description**

String type.


### value

```
const ArkUI_NumberValue* ArkUI_AttributeItem::value
```
**Description**

Numeric array.
<!--no_check-->