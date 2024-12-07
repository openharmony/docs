# JSVM_CallbackStruct


## Overview

Pointer to and data of the native callbacks provided by the user. These functions are exposed to JavaScript via JSVM-API.

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Public Member Functions

| Name| Description| 
| -------- | -------- |
| [JSVM_Value](#jsvm_value) (JSVM_CDECL \*callback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 


### Member Variables

| Name| Description| 
| -------- | -------- |
| [JSVM_CallbackInfo](_j_s_v_m.md#jsvm_callbackinfo)**info** |  | 
| void \* [data](#data) | Data of the native callbacks provided by the user. | 


## Member Function Description


### JSVM_Value()

```
JSVM_CallbackStruct::JSVM_Value (JSVM_CDECL * callback)
```
**Description**
Pointer to the native callbacks provided by the user.


## Member Variable Description


### data

```
void* JSVM_CallbackStruct::data
```
**Description**
Data of the native callbacks provided by the user.
