# JSVM_PropertyDescriptor


## Overview

Attribute descriptor.

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [utf8name](#utf8name) | Optional string that describes the attribute key value. The value is encoded in UTF8 format. Either utf8name or name must be provided for the property. | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value)[name](#name) | Optional JSVM_Value that points to a JavaScript string or symbol used as a property key. Either utf8name or name must be provided for the property. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback)[method](#method) | Setting this item makes the value property of the property descriptor object a JavaScript function represented by method. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback)[getter](#getter) | The function called when performing a fetch access to a property. | 
| [JSVM_Callback](_j_s_v_m.md#jsvm_callback)[setter](#setter) | Function called when the setting access of the execution property is performed. | 
| [JSVM_Value](_j_s_v_m.md#jsvm_value)[value](#value) | If the attribute is a data attribute, the retrieved value is accessed through the get of the attribute. | 
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes)[attributes](#attributes) | An attribute associated with a specific attribute. | 


## Member Variable Description


### attributes

```
JSVM_PropertyAttributes JSVM_PropertyDescriptor::attributes
```
**Description**
An attribute associated with a specific attribute.


### getter

```
JSVM_Callback JSVM_PropertyDescriptor::getter
```
**Description**
The function called when performing a fetch access to a property.


### method

```
JSVM_Callback JSVM_PropertyDescriptor::method
```
**Description**
Setting this item makes the value property of the property descriptor object a JavaScript function represented by method.


### name

```
JSVM_Value JSVM_PropertyDescriptor::name
```
**Description**
Optional JSVM_Value that points to a JavaScript string or symbol used as a property key. Either utf8name or name must be provided for the property.


### setter

```
JSVM_Callback JSVM_PropertyDescriptor::setter
```
**Description**
Function called when the setting access of the execution property is performed.


### utf8name

```
const char* JSVM_PropertyDescriptor::utf8name
```
**Description**
Optional string that describes the attribute key value. The value is encoded in UTF8 format. Either utf8name or name must be provided for the property.


### value

```
JSVM_Value JSVM_PropertyDescriptor::value
```
**Description**
If the attribute is a data attribute, the retrieved value is accessed through the get of the attribute.
