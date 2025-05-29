# drawing_error_code.h

## 概述

声明与绘图模块中的错误码相关的函数。

**引用文件：** native_drawing/drawing_error_code.h

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) | OH_Drawing_ErrorCode | 枚举本模块可能产生的错误码。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet()](#oh_drawing_errorcodeget) | 获取本模块的错误码。 |
| [void OH_Drawing_ErrorCodeReset(void)](#oh_drawing_errorcodereset) | 将本模块的错误码重置为OH_DRAWING_SUCCESS。<br>通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。 |

## 枚举类型说明

### OH_Drawing_ErrorCode

```
enum OH_Drawing_ErrorCode
```

**描述**

枚举本模块可能产生的错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_DRAWING_SUCCESS = 0 | 操作成功完成。 |
| OH_DRAWING_ERROR_NO_PERMISSION = 201 | 权限校验失败。 |
| OH_DRAWING_ERROR_INVALID_PARAMETER = 401 | 无效的输入参数，如参数中传入了NULL。 |
| OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001 | 输入参数不在有效的范围内。 |
| OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 |  内存分配失败。<br>**起始版本：** 13 |


## 函数说明

### OH_Drawing_ErrorCodeGet()

```
OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet()
```

**描述**

获取本模块的错误码。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) | 获取本模块的最近一次的错误码。当函数成功运行后，本函数返回的错误码不会被修改。 |

### OH_Drawing_ErrorCodeReset()

```
void OH_Drawing_ErrorCodeReset(void)
```

**描述**

将本模块的错误码重置为OH_DRAWING_SUCCESS。<br>通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


