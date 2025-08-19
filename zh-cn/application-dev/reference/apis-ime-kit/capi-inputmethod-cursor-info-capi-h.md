# inputmethod_cursor_info_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供光标信息对象的创建、销毁与读写方法。

**引用文件：** <inputmethod/inputmethod_cursor_info_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) | InputMethod_CursorInfo | 光标信息。光标的坐标位置、宽度和高度。 |

### 函数

| 名称 | 描述                                         |
| -- |--------------------------------------------|
| [InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)](#oh_cursorinfo_create) | 创建一个新的[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例。 |
| [void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)](#oh_cursorinfo_destroy) | 销毁一个[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例。      |
| [InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)](#oh_cursorinfo_setrect) | 设置光标信息内容。                                  |
| [InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)](#oh_cursorinfo_getrect) | 获取光标信息内容。                                  |

## 函数说明

### OH_CursorInfo_Create()

```
InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)
```

**描述**

创建一个新的[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| double left | 光标靠左点与物理屏幕左侧距离的绝对值。 |
| double top | 光标顶点与物理屏幕上侧距离的绝对值。 |
| double width | 宽度。 |
| double height | 高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例的指针。<br> 成功时返回实例。如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。 |

### OH_CursorInfo_Destroy()

```
void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)
```

**描述**

销毁一个[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | 表示指向即将被销毁的[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例的指针。 |

### OH_CursorInfo_SetRect()

```
InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)
```

**描述**

设置光标信息内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | 表示指向[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例的指针。 |
| double left | 光标靠左点与物理屏幕左侧距离的绝对值。 |
| double top | 光标顶点与物理屏幕上侧距离的绝对值。 |
| double width | 宽度。 |
| double height | 高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_CursorInfo_GetRect()

```
InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)
```

**描述**

获取光标信息内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | 表示指向[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例的指针。 |
| double *left | 靠左点与物理屏幕左侧距离的绝对值。 |
| double *top | 顶点与物理屏幕上侧距离的绝对值。 |
| double *width | 宽度。 |
| double *height | 高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


