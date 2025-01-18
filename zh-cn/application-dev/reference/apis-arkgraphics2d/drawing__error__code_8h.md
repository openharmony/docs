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
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode-1) { OH_DRAWING_SUCCESS = 0, OH_DRAWING_ERROR_NO_PERMISSION = 201, OH_DRAWING_ERROR_INVALID_PARAMETER = 401, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001,OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 } | 枚举本模块可能产生的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode)  [OH_Drawing_ErrorCodeGet](_drawing.md#oh_drawing_errorcodeget) () | 获取本模块的最近一次的错误码。当函数成功运行后，本函数返回的错误码不会被修改。 | 
| void [OH_Drawing_ErrorCodeReset](_drawing.md#oh_drawing_errorcodereset) (void) | 将本模块的错误码重置为OH_DRAWING_SUCCESS。<br/>通过[OH_Drawing_ErrorCodeGet](_drawing.md#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br/>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。 | 