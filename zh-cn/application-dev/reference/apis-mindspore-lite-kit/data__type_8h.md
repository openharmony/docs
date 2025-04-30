# data_type.h


## 概述

声明了张量的数据的类型。

**引用文件：** <mindspore/data_type.h>

**库：** libmindspore_lite_ndk.so

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：** [MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_DataType](_mind_spore.md#oh_ai_datatype-1) | MSTensor保存的数据支持的类型。 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_AI_DataType](_mind_spore.md#oh_ai_datatype-1) {<br/>OH_AI_DATATYPE_UNKNOWN = 0,<br/>OH_AI_DATATYPE_OBJECTTYPE_STRING = 12, <br/>OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, <br/>OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14, <br/>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17,<br/>OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29, <br/>OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39,<br/>OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44, <br/>OH_AI_DATATYPE_NUMBERTYPE_END = 46,<br/>OH_AI_DataTypeInvalid = INT32_MAX } | MSTensor保存的数据支持的类型。 |
