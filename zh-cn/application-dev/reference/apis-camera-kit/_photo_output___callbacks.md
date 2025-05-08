# PhotoOutput_Callbacks


## 概述

拍照输出的回调。

参见[OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback)。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)

**所在头文件：**[photo_output.h](photo__output_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart) [onFrameStart](#onframestart) | 拍照输出帧启动事件。 | 
| [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter) [onFrameShutter](#onframeshutter) | 拍照输出框快门事件。 | 
| [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend) [onFrameEnd](#onframeend) | 拍照输出帧结束事件。 | 
| [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror) [onError](#onerror) | 拍照输出错误事件。 | 


## 结构体成员变量说明


### onError

```
OH_PhotoOutput_OnError PhotoOutput_Callbacks::onError
```

**描述**

拍照输出错误事件。


### onFrameEnd

```
OH_PhotoOutput_OnFrameEnd PhotoOutput_Callbacks::onFrameEnd
```

**描述**

拍照输出帧结束事件。


### onFrameShutter

```
OH_PhotoOutput_OnFrameShutter PhotoOutput_Callbacks::onFrameShutter
```

**描述**

拍照输出框快门事件。


### onFrameStart

```
OH_PhotoOutput_OnFrameStart PhotoOutput_Callbacks::onFrameStart
```

**描述**

拍照输出帧启动事件。
