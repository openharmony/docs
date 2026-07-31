# drawing_record_cmd.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了与录制指令对象相关的功能函数。用于录制和回放绘制指令序列，支持创建录制画布、记录绘制操作、生成可回放的指令对象。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** <native_drawing/drawing_record_cmd.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_RecordCmdUtils* OH_Drawing_RecordCmdUtilsCreate(void)](#oh_drawing_recordcmdutilscreate) | 创建一个指令录制工具对象。 |
| [OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsDestroy(OH_Drawing_RecordCmdUtils* recordCmdUtils)](#oh_drawing_recordcmdutilsdestroy) | 销毁一个指令录制工具对象，并回收该对象占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsBeginRecording(OH_Drawing_RecordCmdUtils* recordCmdUtils,int32_t width, int32_t height, OH_Drawing_Canvas** canvas)](#oh_drawing_recordcmdutilsbeginrecording) | 开始录制。此接口需要与[OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording)接口成对使用。<br>指令录制工具生成录制类型的画布对象，可调用drawing的绘制接口，记录接下来所有的绘制指令。 |
| [OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsFinishRecording(OH_Drawing_RecordCmdUtils* recordCmdUtils,OH_Drawing_RecordCmd** recordCmd)](#oh_drawing_recordcmdutilsfinishrecording) | 结束录制。在调用此接口前，需要先调用[OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording)接口。<br>指令录制工具结束录制指令，将录制类型画布对象记录的绘制指令存入生成的录制指令对象。 |
| [OH_Drawing_ErrorCode OH_Drawing_RecordCmdDestroy(OH_Drawing_RecordCmd* recordCmd)](#oh_drawing_recordcmddestroy) | 销毁录制指令对象，并回收该对象占用的内存。 |

## 函数说明

### OH_Drawing_RecordCmdUtilsCreate()

```c
OH_Drawing_RecordCmdUtils* OH_Drawing_RecordCmdUtilsCreate(void)
```

**描述**

创建一个指令录制工具对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)* | 返回用于录制指令的工具对象。 |

### OH_Drawing_RecordCmdUtilsDestroy()

```c
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsDestroy(OH_Drawing_RecordCmdUtils* recordCmdUtils)
```

**描述**

销毁一个指令录制工具对象，并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)* recordCmdUtils | 指向指令录制工具对象[OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmdUtils为空。 |

### OH_Drawing_RecordCmdUtilsBeginRecording()

```c
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsBeginRecording(OH_Drawing_RecordCmdUtils* recordCmdUtils, int32_t width, int32_t height, OH_Drawing_Canvas** canvas)
```

**描述**

开始录制。此接口需要与[OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording)接口成对使用。<br>指令录制工具生成录制类型的画布对象，可调用drawing的绘制接口，记录接下来所有的绘制指令。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)* recordCmdUtils | 指向指令录制工具对象[OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)的指针。 |
| int32_t width | 画布的宽度，必须大于0。 |
| int32_t height | 画布的高度，必须大于0。 |
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)** canvas | 指向画布对象[OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)的二级指针，作为出参，开发者无需释放。<br>该画布对象不支持嵌套调用[OH_Drawing_CanvasDrawRecordCmd](capi-drawing-canvas-h.md#oh_drawing_canvasdrawrecordcmd)接口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmdUtils或者canvas为空。<br> 当width和height小于等于0时，也会返回OH_DRAWING_ERROR_INVALID_PARAMETER。<br> 返回OH_DRAWING_ERROR_ALLOCATION_FAILED，表示系统内存不足。 |

### OH_Drawing_RecordCmdUtilsFinishRecording()

```c
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsFinishRecording(OH_Drawing_RecordCmdUtils* recordCmdUtils, OH_Drawing_RecordCmd** recordCmd)
```

**描述**

结束录制。在调用此接口前，需要先调用[OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording)接口。<br>指令录制工具结束录制指令，将录制类型画布对象记录的绘制指令存入生成的录制指令对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)* recordCmdUtils | 指向指令录制工具对象[OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md)的指针，不能为空。 |
| [OH_Drawing_RecordCmd](capi-drawing-oh-drawing-recordcmd.md)** recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](capi-drawing-oh-drawing-recordcmd.md)的二级指针，作为出参，开发者调用[OH_Drawing_CanvasDrawRecordCmd](capi-drawing-canvas-h.md#oh_drawing_canvasdrawrecordcmd)接口绘制该对象。需要调用[OH_Drawing_RecordCmdDestroy](capi-drawing-record-cmd-h.md#oh_drawing_recordcmddestroy)接口释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmdUtils或者recordCmd为空。<br> 返回OH_DRAWING_ERROR_ALLOCATION_FAILED，表示系统内存不足。 |

### OH_Drawing_RecordCmdDestroy()

```c
OH_Drawing_ErrorCode OH_Drawing_RecordCmdDestroy(OH_Drawing_RecordCmd* recordCmd)
```

**描述**

销毁录制指令对象，并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RecordCmd](capi-drawing-oh-drawing-recordcmd.md)* recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](capi-drawing-oh-drawing-recordcmd.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmd为空。 |


