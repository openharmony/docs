# drawing_record_cmd.h


## Overview

The **drawing_record_cmd.h** file declares the functions related to a recording command object.

**File to include**: &lt;native_drawing/drawing_record_cmd.h&gt;

**Library**: libnative_drawing.so

**Since**: 13

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \* [OH_Drawing_RecordCmdUtilsCreate](_drawing.md#oh_drawing_recordcmdutilscreate) (void) | Creates an **OH_Drawing_RecordCmdUtils** object.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsDestroy](_drawing.md#oh_drawing_recordcmdutilsdestroy) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils) | Destroys an **OH_Drawing_RecordCmdUtils** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsBeginRecording](_drawing.md#oh_drawing_recordcmdutilsbeginrecording) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils, int32_t width, int32_t height, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*\*canvas) | Starts recording. This function must be used in pair with [OH_Drawing_RecordCmdUtilsFinishRecording](_drawing.md#oh_drawing_recordcmdutilsfinishrecording).<br>The **OH_Drawing_RecordCmdUtils** object generates a canvas object of the recording type and calls the interface of the drawing object to record all drawing commands.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsFinishRecording](_drawing.md#oh_drawing_recordcmdutilsfinishrecording) ([OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) \*recordCmdUtils, [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*\*recordCmd) | Ends recording. This function must be called after [OH_Drawing_RecordCmdUtilsBeginRecording](_drawing.md#oh_drawing_recordcmdutilsbeginrecording).<br>The **OH_Drawing_RecordCmdUtils** object ends recording and stores the drawing commands recorded by the canvas object of the recording type into the generated [OH_Drawing_RecordCmdUtilsBeginRecording](_drawing.md#oh_drawing_recordcmdutilsbeginrecording) object.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RecordCmdDestroy](_drawing.md#oh_drawing_recordcmddestroy) ([OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*recordCmd) | Destroys an **OH_Drawing_RecordCmd** object and reclaims the memory occupied by the object.| 
