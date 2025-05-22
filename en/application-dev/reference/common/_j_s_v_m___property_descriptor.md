# JSVM_PropertyDescriptor


## Overview

Property descriptor.

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [utf8name](#utf8name) | Property key value, which is an optional character string in UTF8 encoding. Either **utf8name** or **name** must be provided for a property. | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [name](#name) | Optional JSVM_Value, which points to the JavaScript string or symbol used as the property key. Either **utf8name** or **name** must be provided for a property. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [method](#method) | Method as the **value** property of the property descriptor object. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [getter](#getter) | Callback for getting a property. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [setter](#setter) | Callback for setting a property. | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [value](#value) | Value retrieved by **getter** of the data property. | 
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) [attributes](#attributes) | Attributes associated with a specific property. | 


## Member Variable Description


### attributes

```
JSVM_PropertyAttributes JSVM_PropertyDescriptor::attributes
```
**Description**
Attributes associated with a specific property.


### getter

```
JSVM_Callback JSVM_PropertyDescriptor::getter
```
**Description**
Callback for getting a property.


### method

```
JSVM_Callback JSVM_PropertyDescriptor::method
```
**Description**
Method as the **value** property of the property descriptor object.


### name

```
JSVM_Value JSVM_PropertyDescriptor::name
```
**Description**
Optional JSVM_Value, which points to the JavaScript string or symbol used as the property key. Either **utf8name** or **name** must be provided for a property.


### setter

```
JSVM_Callback JSVM_PropertyDescriptor::setter
```
**Description**
Callback for setting a property.


### utf8name

```
const char* JSVM_PropertyDescriptor::utf8name
```
**Description**
Property key value, which is an optional character string in UTF8 encoding. Either **utf8name** or **name** must be provided for a property.


### value

```
JSVM_Value JSVM_PropertyDescriptor::value
```
**Description**
Value retrieved by **getter** of the data property.
