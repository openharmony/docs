# VideoOutput_Callbacks


## 概述

用于录像输出的回调。

参见[OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback)。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart) [onFrameStart](#onframestart) | 录像输出帧启动事件。 | 
| [OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend) [onFrameEnd](#onframeend) | 录像输出帧结束事件。 | 
| [OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror) [onError](#onerror) | 录像输出错误事件。 | 


## 结构体成员变量说明


### onError

```
OH_VideoOutput_OnError VideoOutput_Callbacks::onError
```

**描述**

录像输出错误事件。


### onFrameEnd

```
OH_VideoOutput_OnFrameEnd VideoOutput_Callbacks::onFrameEnd
```

**描述**

录像输出帧结束事件。


### onFrameStart

```
OH_VideoOutput_OnFrameStart VideoOutput_Callbacks::onFrameStart
```

**描述**

录像输出帧启动事件。
