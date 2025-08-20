# status.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Provides the status codes of MindSpore Lite.

**File to include**: <mindspore/status.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Enums

| Name                               | typedef Keyword| Description           |
|-----------------------------------|---|---------------|
| [OH_AI_CompCode](#oh_ai_compcode) | - | Defines MindSpore component codes.              |
| [OH_AI_Status](#oh_ai_status)     | OH_AI_Status  | Defines MindSpore status codes.|


## Enum Description

### OH_AI_CompCode

```
enum OH_AI_CompCode
```

**Description**

Defines MindSpore component codes. 

**Since**: 9

| Enum Item                              | Description                   |
|-----------------------------------|-----------------------|
| OH_AI_COMPCODE_CORE = 0x00000000u | MindSpore Core code.|
| OH_AI_COMPCODE_MD = 0x10000000u   | MindSpore MindData code.|
| OH_AI_COMPCODE_ME = 0x20000000u   | MindSpore MindExpression code.|
| OH_AI_COMPCODE_MC = 0x30000000u   | MindSpore code.|
| OH_AI_COMPCODE_LITE = 0xF0000000u | MindSpore Lite code.   |


### OH_AI_Status

```
enum OH_AI_Status
```

**Description**

Defines MindSpore status codes.

**Since**: 9

| Enum Item                                                                               | Description                          |
|------------------------------------------------------------------------------------|------------------------------|
| OH_AI_STATUS_SUCCESS = 0                                                           | Success.                   |
| OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1                              | MindSpore Core failure.       |
| OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -1)                 | MindSpore Lite error.       |
| OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -2)               | MindSpore Lite null pointer.      |
| OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -3)         | MindSpore Lite invalid parameters.     |
| OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -4)             | MindSpore Lite no change.      |
| OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -5)          | MindSpore Lite exit without errors.|
| OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -6)         | MindSpore Lite memory allocation failure.  |
| OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -7)           | MindSpore Lite function not supported.   |
| OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -8)      | MindSpore Lite thread pool error.    |
| OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -9)     | MindSpore Lite uninitialized.     |
| OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -100) | MindSpore Lite tensor overflow.  |
| OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -101)  | MindSpore Lite input tensor error.  |
| OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -102)     | MindSpore Lite reentry error.    |
| OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -200)    | MindSpore Lite file error.     |
| OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -300)         | MindSpore Lite operator not found.   |
| OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -301)     | MindSpore Lite invalid operators.     |
| OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -302)     | MindSpore Lite invalid operator hyperparameters.  |
| OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -303)  | MindSpore Lite operator execution failure.  |
| OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -400)        | MindSpore Lite tensor format error.   |
| OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -500)         | MindSpore Lite shape inference error.   |
| OH_AI_STATUS_LITE_INFER_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -501)       | MindSpore Lite invalid shape inference. |
| OH_AI_STATUS_LITE_INPUT_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF & -600) | MindSpore Lite invalid input parameters.|
