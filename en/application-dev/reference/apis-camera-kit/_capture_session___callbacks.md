# CaptureSession_Callbacks


## Overview

The CaptureSession_Callbacks struct describes the callbacks related to a capture session.

For details, see [OH_CaptureSession_RegisterCallback](_o_h___camera.md#oh_capturesession_registercallback).

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_CaptureSession_OnFocusStateChange](_o_h___camera.md#oh_capturesession_onfocusstatechange) [onFocusStateChange](#onfocusstatechange) | Callback to report a focus status change of a capture session.| 
| [OH_CaptureSession_OnError](_o_h___camera.md#oh_capturesession_onerror) [onError](#onerror) | Callback to report a capture session error.| 


## Member Variable Description


### onError

```
OH_CaptureSession_OnError CaptureSession_Callbacks::onError
```

**Description**

Callback to report a capture session error.


### onFocusStateChange

```
OH_CaptureSession_OnFocusStateChange CaptureSession_Callbacks::onFocusStateChange
```

**Description**

Callback to report a focus status change of a capture session.
