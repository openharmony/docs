# PreviewOutput_Callbacks


## 概述

用于预览输出的回调。

参见[OH_PreviewOutput_RegisterCallback](_o_h___camera.md#oh_previewoutput_registercallback)。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)

**所在头文件：**[preview_output.h](preview__output_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PreviewOutput_OnFrameStart](_o_h___camera.md#oh_previewoutput_onframestart) [onFrameStart](#onframestart) | 预览输出帧开始事件。 | 
| [OH_PreviewOutput_OnFrameEnd](_o_h___camera.md#oh_previewoutput_onframeend) [onFrameEnd](#onframeend) | 预览输出帧结束事件。 | 
| [OH_PreviewOutput_OnError](_o_h___camera.md#oh_previewoutput_onerror) [onError](#onerror) | 预览输出错误事件。 | 


## 结构体成员变量说明


### onError

```
OH_PreviewOutput_OnError PreviewOutput_Callbacks::onError
```

**描述**

预览输出错误事件。


### onFrameEnd

```
OH_PreviewOutput_OnFrameEnd PreviewOutput_Callbacks::onFrameEnd
```

**描述**

预览输出帧结束事件。


### onFrameStart

```
OH_PreviewOutput_OnFrameStart PreviewOutput_Callbacks::onFrameStart
```

**描述**

预览输出帧开始事件。
