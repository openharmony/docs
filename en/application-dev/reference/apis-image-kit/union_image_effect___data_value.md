# ImageEffect_DataValue


## Overview

The **ImageEffect_DataValue** union describes the data values.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](_image_effect.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| int32_t [int32Value](#int32value) | Integer value, corresponding to [EFFECT_DATA_TYPE_INT32](_image_effect.md). |
| float [floatValue](#floatvalue) | Single-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_FLOAT](_image_effect.md). |
| double [doubleValue](#doublevalue) | Double-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_DOUBLE](_image_effect.md). |
| char [charValue](#charvalue) | Byte value, corresponding to [EFFECT_DATA_TYPE_CHAR](_image_effect.md). |
| long [longValue](#longvalue) | Long integer value, corresponding to [EFFECT_DATA_TYPE_LONG](_image_effect.md). |
| bool [boolValue](#boolvalue) | Boolean value, corresponding to [EFFECT_DATA_TYPE_BOOL](_image_effect.md). |
| void \* [ptrValue](#ptrvalue) | Pointer value, corresponding to [EFFECT_DATA_TYPE_PTR](_image_effect.md). |


## Member Variable Description


### boolValue

```
bool ImageEffect_DataValue::boolValue
```
**Description**

Boolean value, corresponding to [EFFECT_DATA_TYPE_BOOL](_image_effect.md).


### charValue

```
char ImageEffect_DataValue::charValue
```
**Description**

Byte value, corresponding to [EFFECT_DATA_TYPE_CHAR](_image_effect.md).


### doubleValue

```
double ImageEffect_DataValue::doubleValue
```
**Description**

Double-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_DOUBLE](_image_effect.md).


### floatValue

```
float ImageEffect_DataValue::floatValue
```
**Description**

Single-precision floating-point value, corresponding to [EFFECT_DATA_TYPE_FLOAT](_image_effect.md).


### int32Value

```
int32_t ImageEffect_DataValue::int32Value
```
**Description**

Integer value, corresponding to [EFFECT_DATA_TYPE_INT32](_image_effect.md).


### longValue

```
long ImageEffect_DataValue::longValue
```
**Description**

Long integer value, corresponding to [EFFECT_DATA_TYPE_LONG](_image_effect.md).


### ptrValue

```
void* ImageEffect_DataValue::ptrValue
```
**Description**

Pointer value, corresponding to [EFFECT_DATA_TYPE_PTR](_image_effect.md).