# avrecorder.h


## 概述

定义AVRecorder接口。应用可使用Media AVRecorder提供的接口录制媒体数据。

**库：** libavrecorder.so

**引用文件：** &lt;multimedia/player_framework/avrecorder.h&gt;

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 16

**相关模块：**[AVRecorder](_a_v_recorder.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \* [OH_AVRecorder_Create](_a_v_recorder.md#oh_avrecorder_create) (void) | 创建AVRecorder实例。调用成功之后进入AVRECORDER_IDLE状态。 | 
| OH_AVErrCode [OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*config) | 配置AVRecorder参数，准备录制。必须在[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_PREPARED状态。 | 
| OH_AVErrCode [OH_AVRecorder_GetAVRecorderConfig](_a_v_recorder.md#oh_avrecorder_getavrecorderconfig) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*\*config) | 获取当前的录制参数。此接口必须在录制准备完成后调用。传入的 \*config 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 | 
| OH_AVErrCode [OH_AVRecorder_GetInputSurface](_a_v_recorder.md#oh_avrecorder_getinputsurface) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, OHNativeWindow \*\*window) | 获取输入Surface。必须在[OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_UpdateRotation](_a_v_recorder.md#oh_avrecorder_updaterotation) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, int32_t rotation) | 更新视频旋转角度。必须在[OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 开始录制。必须在[OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare)成功触发之后调用，调用成功之后进入AVRECORDER_STARTED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Pause](_a_v_recorder.md#oh_avrecorder_pause) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 暂停录制。必须在[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)成功触发之后，处于AVRECORDER_STARTED状态时调用，调用成功之后进入AVRECORDER_PAUSED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Resume](_a_v_recorder.md#oh_avrecorder_resume) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 恢复录制。必须在[OH_AVRecorder_Pause](_a_v_recorder.md#oh_avrecorder_pause)成功触发之后，处于PAUSED状态时调用，调用成功之后重新进入AVRECORDER_STARTED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Stop](_a_v_recorder.md#oh_avrecorder_stop) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 停止录制。必须在[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_STOPPED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Reset](_a_v_recorder.md#oh_avrecorder_reset) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 重置录制状态。必须在非AVRECORDER_RELEASED状态下调用，调用成功之后进入AVRECORDER_IDLE状态。 | 
| OH_AVErrCode [OH_AVRecorder_Release](_a_v_recorder.md#oh_avrecorder_release) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | 释放录制资源。调用成功之后进入AVRECORDER_RELEASED状态。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。 | 
| OH_AVErrCode [OH_AVRecorder_GetAvailableEncoder](_a_v_recorder.md#oh_avrecorder_getavailableencoder) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) \*\*info, int32_t \*length) | 获取 AVRecorder 可用的编码器和编码器信息。参数 \*info 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 | 
| OH_AVErrCode [OH_AVRecorder_SetStateCallback](_a_v_recorder.md#oh_avrecorder_setstatecallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnStateChange](_a_v_recorder.md#oh_avrecorder_onstatechange) callback, void \*userData) | 设置状态回调函数，以便应用能够响应AVRecorder生成的状态变化事件。此接口必须在[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)调用之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_SetErrorCallback](_a_v_recorder.md#oh_avrecorder_seterrorcallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnError](_a_v_recorder.md#oh_avrecorder_onerror) callback, void \*userData) | 设置错误回调函数，以便应用能够响应AVRecorder生成的错误事件。此接口必须在[OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start)调用之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_SetUriCallback](_a_v_recorder.md#oh_avrecorder_seturicallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnUri](_a_v_recorder.md#oh_avrecorder_onuri) callback, void \*userData) | 设置 URI 回调函数，以便应用能够响应AVRecorder生成的 URI 事件。此接口必须在 [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) 调用之前调用。 | 
