# drawing_error_code.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

声明与绘图模块中的错误码相关的函数。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** <native_drawing/drawing_error_code.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

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
| [OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet()](#oh_drawing_errorcodeget) | 获取本模块最近一次的错误码。<br>本模块的错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，在执行成功后不会被重置为OH_DRAWING_SUCCESS。可通过[OH_Drawing_ErrorCodeReset](#oh_drawing_errorcodereset)重置错误码。 |
| [void OH_Drawing_ErrorCodeReset(void)](#oh_drawing_errorcodereset) | 将本模块的错误码重置为OH_DRAWING_SUCCESS。<br>通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。 |

## 枚举类型说明

### OH_Drawing_ErrorCode

```c
enum OH_Drawing_ErrorCode
```

**描述**

枚举本模块可能产生的错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_DRAWING_SUCCESS = 0 | 操作成功完成。 |
| OH_DRAWING_ERROR_NO_PERMISSION = 201 | 权限校验失败。请检查是否已申请所需权限。 |
| OH_DRAWING_ERROR_INVALID_PARAMETER = 401 | 无效的输入参数，如参数中传入了NULL。请检查参数类型、取值范围或参数是否为空。 |
| OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001 | 输入参数不在有效的范围内。请检查参数值是否在接口文档规定的有效范围内。 |
| OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 | 内存分配失败。<br>**起始版本：** 13 |
| OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH = 26200003 | 输入属性id无匹配的函数。请检查属性id是否正确，确保使用有效的属性id。<br>**起始版本：** 21 |
| OH_DRAWING_ERROR_INCORRECT_PARAMETER = 26200004 | 输入参数不正确，例如入参的指针为空。请检查传入的参数是否正确，确保指针参数有效且不为空。<br>**起始版本：** 22 |
| OH_DRAWING_ERROR_FILE_NOT_FOUND = 26200005 | 文件未找到，指定的文件不存在或路径不正确。请检查文件路径是否正确，确保文件存在且路径格式有效。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_OPEN_FILE_FAILED = 26200006 | 打开文件失败，权限不足或I/O问题造成。请检查文件权限设置是否正确，或稍后重试。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_FILE_SEEK_FAILED = 26200007 | 文件定位失败。系统无法重新定位文件读取指针。请检查文件是否被其他进程占用，或重新打开文件后重试。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_GET_FILE_SIZE_FAILED = 26200008 | 获取文件大小失败，系统无法获取文件大小信息。请检查文件是否存在且可访问，确保文件未被损坏。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_READ_FILE_FAILED = 26200009 | 读取文件失败，文件无法完整读取或包含不可读数据。请检查文件是否完整且未被损坏，确保文件格式正确。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_EMPTY_FILE = 26200010 | 文件为空，指定的字体文件为空，不包含有效数据。请检查文件内容，确保使用包含有效数据的字体文件。<br>**起始版本：** 23 |
| OH_DRAWING_ERROR_FILE_CORRUPTED = 26200011 | 文件损坏，文件内容无效或损坏，无法解析。请检查文件是否完整，尝试重新获取或替换有效的文件。<br>**起始版本：** 23 |

## 函数说明

### OH_Drawing_ErrorCodeGet()

```c
OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet()
```

**描述**

获取本模块最近一次的错误码。<br>本模块的错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，在执行成功后不会被重置为OH_DRAWING_SUCCESS。可通过[OH_Drawing_ErrorCodeReset](#oh_drawing_errorcodereset)重置错误码。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) | 返回本模块最近一次的错误码。当函数成功运行后，本函数返回的错误码不会被修改。 |

### OH_Drawing_ErrorCodeReset()

```c
void OH_Drawing_ErrorCodeReset(void)
```

**描述**

将本模块的错误码重置为OH_DRAWING_SUCCESS。<br>通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


