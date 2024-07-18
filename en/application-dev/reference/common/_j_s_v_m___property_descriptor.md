# JSVM_PropertyDescriptor

## Overview

Property descriptor.

**Starting Version:** 11

**Related Module:** [JSVM](_j_s_v_m.md)

## Summary

### Member Variables

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const char * [utf8name](#utf8name)                           | An optional string in UTF-8 encoding that describes the property key. One of utf8name or name must be provided for the property. |
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [name](#name)           | An optional JSVM_Value pointing to a JavaScript string or symbol used as the property key. One of utf8name or name must be provided for the property. |
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [method](#method) | Setting this makes the value property of the property descriptor object a JavaScript function represented by method. |
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [getter](#getter) | A function called when an access to the property is retrieved. |
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback) [setter](#setter) | A function called when an access to the property is set.     |
| [JSVM_Value](_j_s_v_m.md#jsvm_value) [value](#value)         | The value retrieved by a get access to the property if the property is a data property. |
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) [attributes](#attributes) | The attributes associated with a specific property.          |

## Description of Struct Member Variables

### attributes

```
JSVM_PropertyAttributes JSVM_PropertyDescriptor::attributes
```
**Description**
The attributes associated with a specific property.

### getter

```
JSVM_Callback JSVM_PropertyDescriptor::getter
```
**Description**
A function called when an access to the property is retrieved.

### method

```
JSVM_Callback JSVM_PropertyDescriptor::method
```
**Description**
Setting this makes the value property of the property descriptor object a JavaScript function represented by method.

### name

```
JSVM_Value JSVM_PropertyDescriptor::name
```
**Description**
An optional JSVM_Value pointing to a JavaScript string or symbol used as the property key. One of utf8name or name must be provided for the property.

### setter

```
JSVM_Callback JSVM_PropertyDescriptor::setter
```
**Description**
A function called when an access to the property is set.

### utf8name

```
const char* JSVM_PropertyDescriptor::utf8name
```
**Description**
An optional string in UTF-8 encoding that describes the property key. One of utf8name or name must be provided for the property.

### value

```
JSVM_Value JSVM_PropertyDescriptor::value
```
**Description**
The value retrieved by a get access to the property if the property is a data property.