# JSVM_PropertyHandlerConfigurationStruct


## 概述

当执行对象的getter、setter、deleter和enumerator操作时，该结构体中对应的函数回调将会触发。

**起始版本：** 12

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](#jsvm_value-78) (JSVM_CDECL \*genericNamedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-88) (JSVM_CDECL \*genericNamedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-58) (JSVM_CDECL \*genericNamedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-68) (JSVM_CDECL \*genericNamedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-38) (JSVM_CDECL \*genericIndexedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-48) (JSVM_CDECL \*genericIndexedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-18) (JSVM_CDECL \*genericIndexedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-28) (JSVM_CDECL \*genericIndexedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](_j_s_v_m.md#jsvm_value)**name** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**thisArg** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**namedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**property** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**thisArg** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**namedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value)**thisArg** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**namedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value)**index** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**indexedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**indexedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [JSVM_Value](_j_s_v_m.md#jsvm_value)**indexedPropertyData** |  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [namedPropertyData](#namedpropertydata) | 命名属性回调使用的数据  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [indexedPropertyData](#indexedpropertydata) | 索引属性回调使用的数据  | 


## 成员函数说明


### JSVM_Value() [1/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyDeleterCallback)
```
**描述**
通过删除实例对象的索引属性而触发的回调函数。


### JSVM_Value() [2/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyEnumeratorCallback)
```
**描述**
通过获取对象上的所有索引属性而触发的回调函数。


### JSVM_Value() [3/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyGetterCallback)
```
**描述**
通过获取实例对象的索引属性而触发的回调函数。


### JSVM_Value() [4/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertySetterCallback)
```
**描述**
通过设置实例对象的索引属性而触发的回调函数。


### JSVM_Value() [5/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyDeleterCallback)
```
**描述**
通过删除实例对象的命名属性而触发的回调函数。


### JSVM_Value() [6/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyEnumeratorCallback)
```
**描述**
通过获取对象上的所有命名属性而触发的回调函数。


### JSVM_Value() [7/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyGetterCallback)
```
**描述**
通过获取实例对象的命名属性而触发的回调函数。


### JSVM_Value() [8/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertySetterCallback)
```
**描述**
通过设置实例对象的命名属性而触发的回调函数。


## 结构体成员变量说明


### indexedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::indexedPropertyData
```
**描述**
索引属性回调使用的数据


### namedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::namedPropertyData
```
**描述**
命名属性回调使用的数据
