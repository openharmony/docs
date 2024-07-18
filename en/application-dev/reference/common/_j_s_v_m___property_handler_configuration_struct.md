# JSVM_PropertyHandlerConfigurationStruct


## Overview

When the getter, setter, deleter, or enumerator operation is performed on an object, the corresponding function callback in the structure is triggered.

**Since**: 12

Related module: [JSVM](_j_s_v_m.md)


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
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [namedPropertyData](#namedpropertydata) | Data Used for Naming Attribute Callback | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [indexedPropertyData](#indexedpropertydata) | Data used for index attribute callback | 


## Member Function Description


### JSVM_Value() [1/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyDeleterCallback)
```
**Description**
Callback function triggered by deleting the index attribute of an instance object.


### JSVM_Value() [2/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyEnumeratorCallback)
```
**Description**
Callback function triggered by obtaining all index attributes on an object.


### JSVM_Value() [3/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertyGetterCallback)
```
**Description**
Callback function triggered by obtaining the index attribute of an instance object.


### JSVM_Value() [4/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericIndexedPropertySetterCallback)
```
**Description**
Callback function triggered by setting the index attribute of an instance object.


### JSVM_Value() [5/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyDeleterCallback)
```
**Description**
Callback function triggered by deleting the named attribute of an instance object.


### JSVM_Value() [6/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyEnumeratorCallback)
```
**Description**
A callback function that is triggered by obtaining all named attributes on an object.


### JSVM_Value() [7/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertyGetterCallback)
```
**Description**
Callback function triggered by obtaining the naming attribute of an instance object.


### JSVM_Value() [8/8]

```
JSVM_PropertyHandlerConfigurationStruct::JSVM_Value (JSVM_CDECL * genericNamedPropertySetterCallback)
```
**Description**
Callback function triggered by setting the naming attribute of an instance object.


## Member Variable Description


### indexedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::indexedPropertyData
```
**Description**
Data used for index attribute callback


### namedPropertyData

```
JSVM_Value JSVM_PropertyHandlerConfigurationStruct::namedPropertyData
```
**Description**
Data Used for Naming Attribute Callback
