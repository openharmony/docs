# VideoOutput_Callbacks


## Overview

The **VideoOutput_Callbacks** struct defines the callbacks used for video output.

**See**

[OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback)

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [onFrameStart](#onframestart) | Callback to report video output frame start events.| 
| [onFrameEnd](#onframeend) | Callback to report video output frame end events.| 
| [onError](#onerror) | Callback to report video output errors.| 


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
