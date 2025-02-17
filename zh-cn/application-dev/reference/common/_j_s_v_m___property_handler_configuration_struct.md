# JSVM_PropertyHandlerConfigurationStruct


## 概述

当执行对象的getter、setter、deleter和enumerator操作时，该结构体中对应的函数回调将会触发。

**起始版本：** 12

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericNamedPropertyGetterCallback](#genericnamedpropertygettercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过获取实例对象的命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericNamedPropertySetterCallback](#genericnamedpropertysettercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过设置实例对象的命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericNamedPropertyDeleterCallback](#genericnamedpropertydeletercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过删除实例对象的命名属性而触发的回调函数。| 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericNamedPropertyEnumeratorCallback](#genericnamedpropertyenumeratorcallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过获取对象上的所有命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericIndexedPropertyGetterCallback](#genericindexedpropertygettercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过获取实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericIndexedPropertySetterCallback](#genericindexedpropertysettercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过设置实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericIndexedPropertyDeleterCallback](#genericindexedpropertydeletercallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过删除实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*[genericIndexedPropertyEnumeratorCallback](#genericindexedpropertyenumeratorcallback))([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg, [JSVM_Value](_j_s_v_m.md#jsvm_value) namedPropertyData) | 通过获取对象上的所有索引属性而触发的回调函数。 | 


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [namedPropertyData](#namedpropertydata) | 命名属性回调使用的数据  | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [indexedPropertyData](#indexedpropertydata) | 索引属性回调使用的数据  | 


## 成员函数说明

### genericNamedPropertyGetterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyGetterCallback)
```
**描述**
通过获取实例对象的命名属性而触发的回调函数。


### genericNamedPropertySetterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertySetterCallback)
```
**描述**
通过设置实例对象的命名属性而触发的回调函数。


### genericNamedPropertyDeleterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyDeleterCallback)
```
**描述**
通过删除实例对象的命名属性而触发的回调函数。


### genericNamedPropertyEnumeratorCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyEnumeratorCallback)
```
**描述**
通过获取对象上的所有命名属性而触发的回调函数。


### genericIndexedPropertyGetterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyGetterCallback)
```
**描述**
通过获取实例对象的索引属性而触发的回调函数。


### genericIndexedPropertySetterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertySetterCallback)
```
**描述**
通过设置实例对象的索引属性而触发的回调函数。


### genericIndexedPropertyDeleterCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyDeleterCallback)
```
**描述**
通过删除实例对象的索引属性而触发的回调函数。


### genericIndexedPropertyEnumeratorCallback

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyEnumeratorCallback)
```
**描述**
通过获取对象上的所有索引属性而触发的回调函数。

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
