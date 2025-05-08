# PhotoOutput_Callbacks


## Overview

The PhotoOutput_Callbacks struct describes the callbacks related to photo output.

For details, see [OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback).

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)

**Header file**: [photo_output.h](photo__output_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart) [onFrameStart](#onframestart) | Callback to report photo output frame start events.| 
| [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter) [onFrameShutter](#onframeshutter) | Callback to report frame shutter events.| 
| [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend) [onFrameEnd](#onframeend) | Callback to report photo output frame end events.| 
| [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror) [onError](#onerror) | Callback to report photo output errors.| 


## Member Variable Description


### onError

```
OH_PhotoOutput_OnError PhotoOutput_Callbacks::onError
```

**Description**

Callback to report photo output errors.


### onFrameEnd

```
OH_PhotoOutput_OnFrameEnd PhotoOutput_Callbacks::onFrameEnd
```

**Description**

Callback to report photo output frame end events.


### onFrameShutter

```
OH_PhotoOutput_OnFrameShutter PhotoOutput_Callbacks::onFrameShutter
```

**Description**

Callback to report frame shutter events.


### onFrameStart

```
OH_PhotoOutput_OnFrameStart PhotoOutput_Callbacks::onFrameStart
```

**Description**

Callback to report photo output frame start events.
