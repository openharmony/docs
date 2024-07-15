# ImageEffect_DataValue


## 概述

数据值联合体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：**[ImageEffect](_image_effect.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [int32Value](#int32value) | 整形值，对应[EFFECT_DATA_TYPE_INT32](_image_effect.md)。  | 
| float [floatValue](#floatvalue) | 单精度浮点值，对应[EFFECT_DATA_TYPE_FLOAT](_image_effect.md)。  | 
| double [doubleValue](#doublevalue) | 双精度浮点值，对应[EFFECT_DATA_TYPE_DOUBLE](_image_effect.md)。  | 
| char [charValue](#charvalue) | 字节值，对应[EFFECT_DATA_TYPE_CHAR](_image_effect.md)。  | 
| long [longValue](#longvalue) | 长整型值，对应[EFFECT_DATA_TYPE_LONG](_image_effect.md)。  | 
| bool [boolValue](#boolvalue) | 布尔值，对应[EFFECT_DATA_TYPE_BOOL](_image_effect.md)。  | 
| void \* [ptrValue](#ptrvalue) | 指针值，对应[EFFECT_DATA_TYPE_PTR](_image_effect.md)。  | 


## 结构体成员变量说明


### boolValue

```
bool ImageEffect_DataValue::boolValue
```
**描述**
布尔值，对应[EFFECT_DATA_TYPE_BOOL](_image_effect.md)。


### charValue

```
char ImageEffect_DataValue::charValue
```
**描述**
字节值，对应[EFFECT_DATA_TYPE_CHAR](_image_effect.md)。


### doubleValue

```
double ImageEffect_DataValue::doubleValue
```
**描述**
双精度浮点值，对应[EFFECT_DATA_TYPE_DOUBLE](_image_effect.md)。


### floatValue

```
float ImageEffect_DataValue::floatValue
```
**描述**
单精度浮点值，对应[EFFECT_DATA_TYPE_FLOAT](_image_effect.md)。


### int32Value

```
int32_t ImageEffect_DataValue::int32Value
```
**描述**
整形值，对应[EFFECT_DATA_TYPE_INT32](_image_effect.md)。


### longValue

```
long ImageEffect_DataValue::longValue
```
**描述**
长整型值，对应[EFFECT_DATA_TYPE_LONG](_image_effect.md)。


### ptrValue

```
void* ImageEffect_DataValue::ptrValue
```
**描述**
指针值，对应[EFFECT_DATA_TYPE_PTR](_image_effect.md)。
