# drawing_error_code.h


## 概述

声明与绘图模块中的错误码相关的函数。

**引用文件：**&lt;native_drawing/drawing_error_code.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode)  [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) | 枚举本模块可能产生的错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) { OH_DRAWING_SUCCESS = 0, OH_DRAWING_ERROR_NO_PERMISSION = 201, OH_DRAWING_ERROR_INVALID_PARAMETER = 401, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001,OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 } | 枚举本模块可能产生的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode)  [OH_Drawing_ErrorCodeGet](_drawing.md#oh_drawing_errorcodeget) () | 获取本模块的最近一次的错误码。当函数成功运行后，本函数返回的错误码不会被修改。 | 
