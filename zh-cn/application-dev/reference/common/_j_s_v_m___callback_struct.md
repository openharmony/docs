# JSVM_CallbackStruct


## 概述

用户提供的native回调函数的指针和数据，这些函数通过JSVM-API接口暴露给JavaScript。

**起始版本：** 11

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_Value](#jsvm_value) (JSVM_CDECL \*callback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_CallbackInfo] (_j_s_v_m.md#jsvm_callbackinfo)**info** |  | 
| void \* [data](#data) | 用户提供的native回调函数的数据。  | 


## 成员函数说明


### JSVM_Value()

```
JSVM_CallbackStruct::JSVM_Value (JSVM_CDECL * callback)
```
**描述**
用户提供的native回调函数的指针。


## 结构体成员变量说明


### data

```
void* JSVM_CallbackStruct::data
```
**描述**
用户提供的native回调函数的数据。
