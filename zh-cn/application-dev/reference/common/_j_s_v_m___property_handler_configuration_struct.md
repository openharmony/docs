# JSVM_PropertyHandlerConfigurationStruct


## 概述

当执行对象的getter、setter、deleter和enumerator作时，该结构体中的对应的函数回调将会触发。

**起始版本：** 12

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](_j_s_v_m.md#jsvm_value)(JSVM_CDECL\* genericNamedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env,[JSVM_Value](_j_s_v_m.md#jsvm_value) name,[JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过获取实例对象的命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericNamedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) property, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过设置实例对象的命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericNamedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) name, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过删除实例对象的命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericNamedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过获取对象上的所有命名属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericIndexedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) index, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过获取实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericIndexedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) index, [JSVM_Value](_j_s_v_m.md#jsvm_value) property, [JSVM_Value](_j_s_v_m.md#jsvm_value) thisArg); | 通过设置实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericIndexedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_Value](_j_s_v_m.md#jsvm_value) index, [JSVM_Value](_j_s_v_m.md#jsvm_value)thisArg); | 通过设置实例对象的索引属性而触发的回调函数。 | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) (JSVM_CDECL \*genericIndexedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, JSVM_Value thisArg); | 通过获取对象上的所有索引属性而触发的回调函数。 | 
