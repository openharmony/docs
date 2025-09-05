# data_type.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Declares tensor data types.

**File to include**: <mindspore/data_type.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AI_DataType](#oh_ai_datatype) | OH_AI_DataType | Enumerates data types supported by MSTensor.|

## Enum Description

### OH_AI_DataType

```
enum OH_AI_DataType
```

**Description**

Enumerates data types supported by MSTensor.

**Since**: 9

| Enum Item| Description|
| -- | -- |
| OH_AI_DATATYPE_UNKNOWN = 0 | Unknown data type.|
| OH_AI_DATATYPE_OBJECTTYPE_STRING = 12 | String data.|
| OH_AI_DATATYPE_OBJECTTYPE_LIST = 13 | List data.|
| OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14 | Tuple data.|
| OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17 | TensorList data.|
| OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29 | Begin of the number type.|
| OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30 | Bool data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32 | Int8 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33 | Int16 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34 | Int32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35 | Int64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37 | UInt8 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38 | UInt16 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39 | UInt32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40 | UInt64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42 | Float16 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43 | Float32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44 | Float64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_END = 46 | End of the number type.|
| OH_AI_DataTypeInvalid = INT32_MAX | Invalid data type.|
