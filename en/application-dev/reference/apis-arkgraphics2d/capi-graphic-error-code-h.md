# graphic_error_code.h

## Overview

Defines error codes.

**File to import**: <native_window/graphic_error_code.h>

**Library**: libnative_window.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Related module**: [NativeWindow](capi-nativewindow.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OHNativeErrorCode](#ohnativeerrorcode) | OHNativeErrorCode | Defines an enum for the error codes.|

## Enum Description

### OHNativeErrorCode

```
enum OHNativeErrorCode
```

**Description**

Defines an enum for the error codes.

**Since**: 12

| Value| Description|
| -- | -- |
| NATIVE_ERROR_OK = 0 | Operation successful.|
| NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000 | Memory operation error.<br>**Since**: 15|
| NATIVE_ERROR_INVALID_ARGUMENTS = 40001000 | An input parameter is invalid.|
| NATIVE_ERROR_NO_PERMISSION = 40301000 | You do not have the permission to perform the operation.|
| NATIVE_ERROR_NO_BUFFER = 40601000 | No buffer is available.|
| NATIVE_ERROR_NO_CONSUMER = 41202000 | The consumer does not exist.|
| NATIVE_ERROR_NOT_INIT = 41203000 | Not initialized.|
| NATIVE_ERROR_CONSUMER_CONNECTED = 41206000 | The consumer is connected.|
| NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000 | The buffer status does not meet the expectation.|
| NATIVE_ERROR_BUFFER_IN_CACHE = 41208000 | The buffer is already in the buffer queue.|
| NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000 | The queue is full.|
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000 | The buffer is not in the buffer queue.|
| NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000 | The consumer is disconnected.|
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000 | No listener is registered on the consumer side.|
| NATIVE_ERROR_UNSUPPORTED = 50102000 | The device or platform does not support the operation.|
| NATIVE_ERROR_UNKNOWN = 50002000 | Unknown error. Check the log.|
| NATIVE_ERROR_HDI_ERROR = 50007000 | Failed to call the HDI.|
| NATIVE_ERROR_BINDER_ERROR = 50401000 | Cross-process communication failed.|
| NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000 | The EGL environment is abnormal.|
| NATIVE_ERROR_EGL_API_FAILED = 60002000 | Failed to call the EGL APIs.|
