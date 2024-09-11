# JSVM_PropertyHandlerConfigurationStruct


## Overview

Struct for triggering the corresponding callback when the getter, setter, deleter, or enumerator of an object is executed.

**Since**: 12

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Public Member Functions

| Name| Description| 
| -------- | -------- |
| [JSVM_Value](#jsvm_value-78) (JSVM_CDECL \*genericNamedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-88) (JSVM_CDECL \*genericNamedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-58) (JSVM_CDECL \*genericNamedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-68) (JSVM_CDECL \*genericNamedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-38) (JSVM_CDECL \*genericIndexedPropertyGetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-48) (JSVM_CDECL \*genericIndexedPropertySetterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-18) (JSVM_CDECL \*genericIndexedPropertyDeleterCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 
| [JSVM_Value](#jsvm_value-28) (JSVM_CDECL \*genericIndexedPropertyEnumeratorCallback)([JSVM_Env](_j_s_v_m.md#jsvm_env) env |  | 


### Member Variables

| Name| Description| 
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
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [namedPropertyData](#namedpropertydata) | Data used for name property callback | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [indexedPropertyData](#indexedpropertydata) | Data used for index property callback | 


## Member Function Description


### JSVM_Value() [1/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyDeleterCallback)
```
**Description**
Callback triggered by deleting the index property of an instance object.


### JSVM_Value() [2/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyEnumeratorCallback)
```
**Description**
Callback triggered by obtaining all index properties on an object.


### JSVM_Value() [3/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyGetterCallback)
```
**Description**
Callback triggered by obtaining the index property of an instance object.


### JSVM_Value() [4/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertySetterCallback)
```
**Description**
Callback triggered by setting the index property of an instance object.


### JSVM_Value() [5/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyDeleterCallback)
```
**Description**
Callback triggered by deleting the name property of an instance object.


### JSVM_Value() [6/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyEnumeratorCallback)
```
**Description**
Callback triggered by obtaining all name properties on an object.


### JSVM_Value() [7/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyGetterCallback)
```
**Description**
Callback triggered by obtaining the name property of an instance object.


### JSVM_Value() [8/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertySetterCallback)
```
**Description**
Callback triggered by setting the name property of an instance object.


## Member Variable Description


### indexedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::indexedPropertyData
```
**Description**
Data used for index property callback


### namedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::namedPropertyData
```
**Description**
Data used for name property callback
