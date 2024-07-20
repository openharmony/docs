# PreviewOutput_Callbacks


## Overview

The PreviewOutput_Callbacks struct describes the callbacks related to preview output.

For details, see [OH_PreviewOutput_RegisterCallback](_o_h___camera.md#oh_previewoutput_registercallback).

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_PreviewOutput_OnFrameStart](_o_h___camera.md#oh_previewoutput_onframestart) [onFrameStart](#onframestart) | Callback to report preview output frame start events.| 
| [OH_PreviewOutput_OnFrameEnd](_o_h___camera.md#oh_previewoutput_onframeend) [onFrameEnd](#onframeend) | Callback to report preview output frame end events.| 
| [OH_PreviewOutput_OnError](_o_h___camera.md#oh_previewoutput_onerror) [onError](#onerror) | Callback to report preview output errors.| 


## Member Variable Description


### onError

```
OH_PreviewOutput_OnError PreviewOutput_Callbacks::onError
```

**Description**

Callback to report preview output errors.


### onFrameEnd

```
OH_PreviewOutput_OnFrameEnd PreviewOutput_Callbacks::onFrameEnd
```

**Description**

Callback to report preview output frame end events.


### onFrameStart

```
OH_PreviewOutput_OnFrameStart PreviewOutput_Callbacks::onFrameStart
```

**Description**

Callback to report preview output frame start events.
