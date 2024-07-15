# image_effect_errors.h


## 概述

声明图片效果器错误码。

**库：** libimage_effect.so

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：**[ImageEffect](_image_effect.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode-1) [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) | 效果器错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode-1) {<br/>EFFECT_SUCCESS = 0, EFFECT_ERROR_PERMISSION_DENIED = 201,<br/>EFFECT_ERROR_PARAM_INVALID = 401, EFFECT_BUFFER_SIZE_NOT_MATCH = 29000001,<br/>EFFECT_COLOR_SPACE_NOT_MATCH = 29000002, EFFECT_INPUT_OUTPUT_NOT_MATCH = 29000101,<br/>EFFECT_EFFECT_NUMBER_LIMITED = 29000102, EFFECT_INPUT_OUTPUT_NOT_SUPPORTED = 29000103,<br/>EFFECT_ALLOCATE_MEMORY_FAILED = 29000104, EFFECT_PARAM_ERROR = 29000121,<br/>EFFECT_KEY_ERROR = 29000122, EFFECT_UNKNOWN = 29000199<br/>} | 效果器错误码。 | 
