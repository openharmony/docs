# CaptureSession_Callbacks


## Overview

The **CaptureSession_Callbacks** struct defines the callbacks used for session capture.

For details, see [OH_CaptureSession_RegisterCallback](_o_h___camera.md#oh_capturesession_registercallback).

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_CaptureSession_OnFocusStateChange](_o_h___camera.md#oh_capturesession_onfocusstatechange) [onFocusStateChange](#onfocusstatechange) | Callback to report a session focus status change.| 
| [OH_CaptureSession_OnError](_o_h___camera.md#oh_capturesession_onerror) [onError](#onerror) | Callback to report a session error.| 


## Member Variable Description


### onError

```
OH_CaptureSession_OnError CaptureSession_Callbacks::onError
```

**Description**

Callback to report a session error.


### onFocusStateChange

```
OH_CaptureSession_OnFocusStateChange CaptureSession_Callbacks::onFocusStateChange
```

**Description**

Callback to report a session focus status change.
