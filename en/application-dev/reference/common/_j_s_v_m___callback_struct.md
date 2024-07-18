# JSVM_CallbackStruct


## Overview

Pointer to and data of user-provided native callback functions, which are exposed to JavaScript through the JSVM-API.

**Starting Version:** 11

**Related Module:** [JSVM](_j_s_v_m.md)


## Summary


### Public Member Functions

| Name                                                         | Description |
| ------------------------------------------------------------ | ----------- |
| [JSVM_Value](#jsvm_value) (JSVM_CDECL *callback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |             |


### Member Variables

| Name                                                        | Description                                      |
| ----------------------------------------------------------- | ------------------------------------------------ |
| [JSVM_CallbackInfo] (_j_s_v_m.md#jsvm_callbackinfo)**info** |                                                  |
| void * [data](#data)                                        | Data of user-provided native callback functions. |


## Member Function Description


### JSVM_Value()

```
JSVM_CallbackStruct::JSVM_Value (JSVM_CDECL * callback)
```
**Description**
Pointer to user-provided native callback functions.


## Structure Member Variable Description


### data

```
void* JSVM_CallbackStruct::data
```
**Description**
Data of user-provided native callback functions.