# VideoOutput_Callbacks


## Overview

The VideoOutput_Callbacks struct describes the callbacks related to video output.

For details, see [OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback).

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart) [onFrameStart](#onframestart) | Callback to report video output frame start events.| 
| [OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend) [onFrameEnd](#onframeend) | Callback to report video output frame end events.| 
| [OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror) [onError](#onerror) | Callback to report video output errors.| 


## Member Variable Description


### onError

```
OH_VideoOutput_OnError VideoOutput_Callbacks::onError
```

**Description**

Callback to report video output errors.


### onFrameEnd

```
OH_VideoOutput_OnFrameEnd VideoOutput_Callbacks::onFrameEnd
```

**Description**

Callback to report video output frame end events.


### onFrameStart

```
OH_VideoOutput_OnFrameStart VideoOutput_Callbacks::onFrameStart
```

**Description**

Callback to report video output frame start events.
