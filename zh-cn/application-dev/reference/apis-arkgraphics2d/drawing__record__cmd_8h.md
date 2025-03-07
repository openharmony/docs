# drawing_record_cmd.h


## 概述

文件中定义了与录制指令对象相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_record_cmd.h&gt;

**库：** libnative_drawing.so

**起始版本：** 13

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \* [OH_Drawing_RecordCmdUtilsCreate](_drawing.md#oh_drawing_recordcmdutilscreate) (void) | 创建一个录制指令工具对象。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsDestroy](_drawing.md#oh_drawing_recordcmdutilsdestroy) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils) | 销毁一个录制指令工具对象，并回收该对象占有的内存。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsBeginRecording](_drawing.md#oh_drawing_recordcmdutilsbeginrecording) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils, int32_t width, int32_t height, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*\*canvas) | 开始录制。此接口需要与[OH_Drawing_RecordCmdUtilsFinishRecording](_drawing.md#oh_drawing_recordcmdutilsfinishrecording)接口成对使用。<br/>指令录制工具生成录制类型的画布对象，可调用drawing的绘制接口，记录接下来所有的绘制指令。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsFinishRecording](_drawing.md#oh_drawing_recordcmdutilsfinishrecording) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils, [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*\*recordCmd) | 结束录制。在调用此接口前，需要先调用[OH_Drawing_RecordCmdUtilsBeginRecording](_drawing.md#oh_drawing_recordcmdutilsbeginrecording)接口。<br/>指令录制工具结束录制指令，将录制类型画布对象记录的绘制指令存入生成的录制指令对象。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdDestroy](_drawing.md#oh_drawing_recordcmddestroy) ([OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*recordCmd) | 销毁录制指令对象，并回收该对象占有的内存。 | 
