# PhotoOutput_Callbacks


## Overview

The **PhotoOutput_Callbacks** struct defines the callbacks used for photo output.

**See**

[OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback)

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [onFrameStart](#onframestart) | Callback to report photo output frame start events.| 
| [onFrameShutter](#onframeshutter) | Callback to report frame shutter events.| 
| [onFrameEnd](#onframeend) | Callback to report photo output frame end events.| 
| [onError](#onerror) | Callback to report photo output errors.| 


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
