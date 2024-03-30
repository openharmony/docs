# JSVM_CallbackStruct


## 概述

用户提供的native函数的回调函数指针和数据，这些函数通过JSVM-API接口暴露给JavaScript。

**起始版本：** 11

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| JSVM_Value(JSVM_CDECL* callback)(JSVM_Env env, [JSVM_CallbackInfo](_j_s_v_m.md#jsvm_callbackinfo) **info**);|  | 
| void \* [data](#data) | native函数相关数据。  | 


## 成员函数说明


### JSVM_Value()

```
JSVM_CallbackStruct::JSVM_Value (JSVM_CDECL * callback)
```
**描述**
回调函数指针。


## 结构体成员变量说明


### data

```
void* JSVM_CallbackStruct::data
```
**描述**
native函数相关数据。
