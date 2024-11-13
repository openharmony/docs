# NativeVsync


## Overview

The **NativeVsync** module provides the capabilities of native virtual synchronization (VSync).

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**

9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_vsync.h](native__vsync_8h.md) | Declares the functions for obtaining and using native VSync.<br>**File to include**: &lt;native_vsync/native_vsync.h&gt;<br>**Library**: libnative_vsync.so|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | Defines an enum for the error codes. | 
| typedef struct [OH_NativeVSync](#oh_nativevsync)  [OH_NativeVSync](#oh_nativevsync) | Provides the declaration of an **OH_NativeVSync** struct. | 
| typedef void(\* [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | Defines the pointer to a VSync callback function. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,<br>NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeVSync_Create](#oh_nativevsync_create) (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.|
| [OH_NativeVSync_Destroy](#oh_nativevsync_destroy) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync) | Destroys an **OH_NativeVSync** instance.|
| int [OH_NativeVSync_RequestFrame](#oh_nativevsync_requestframe) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked. If this function is called for multiple times in the same frame, only the last callback function is invoked.| 
| int [OH_NativeVSync_RequestFrameWithMultiCallback](#oh_nativevsync_requestframewithmulticallback) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked. If this function is called for multiple times in the same frame, every callback function is invoked.| 
| [OH_NativeVSync_GetPeriod](#oh_nativevsync_getperiod) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, long long \*period) |Obtains the VSync period.|

## Type Description


### OH_NativeVSync


```
typedef struct OH_NativeVSync OH_NativeVSync
```

**Description**

Provides the declaration of an **OH_NativeVSync** struct.


### OH_NativeVSync_FrameCallback


```
typedef void(* OH_NativeVSync_FrameCallback) (long long timestamp, void *data)
```

**Description**

Defines the pointer to a VSync callback function.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| timestamp | VSync timestamp.|
| data | User-defined data.|


### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```

**Description**

Defines an enum for the error codes.

**Since**: 12


## Enum Description


### OHNativeErrorCode

```
enum OHNativeErrorCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVE_ERROR_OK  | The operation is successful.  | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | An input parameter is invalid.  | 
| NATIVE_ERROR_NO_PERMISSION  | You do not have the permission to perform the operation.  | 
| NATIVE_ERROR_NO_BUFFER  | No buffer is available.  | 
| NATIVE_ERROR_NO_CONSUMER  | The consumer does not exist.  | 
| NATIVE_ERROR_NOT_INIT  | Not initialized.  | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | The consumer is connected.  | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | The buffer status does not meet the expectation.  | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | The buffer is already in the buffer queue.  | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | The queue is full.  | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | The buffer is not in the buffer queue.  | 
| NATIVE_ERROR_CONSUMER_DISCONNECTED | The consumer is disconnected.|
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | No listener is registered on the consumer side.|
| NATIVE_ERROR_UNSUPPORTED  | The device or platform does not support the operation.  | 
| NATIVE_ERROR_UNKNOWN  | Unknown error. Check the log.  | 
| NATIVE_ERROR_HDI_ERROR  | Failed to call the HDI.  | 
| NATIVE_ERROR_BINDER_ERROR  | Cross-process communication failed.  |  
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | The EGL environment is abnormal.  | 
| NATIVE_ERROR_EGL_API_FAILED  | Failed to call the EGL APIs.  | 

## Function Description

### OH_NativeVSync_GetPeriod()


```
int OH_NativeVSync_GetPeriod (OH_NativeVSync * nativeVsync, long long * period )
```

**Description**

Obtains the VSync period.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| period | Pointer to the VSync period.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

**Since**

10


### OH_NativeVSync_Create()


```
OH_NativeVSync* OH_NativeVSync_Create (const char * name, unsigned int length )
```

**Description**

Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Pointer to the name that associates with an **OH_NativeVSync** instance.|
| length | Length of the name.|

**Returns**

Returns the pointer to an **OH_NativeVSync** instance.


### OH_NativeVSync_Destroy()


```
void OH_NativeVSync_Destroy (OH_NativeVSync * nativeVsync)
```

**Description**

Destroys an **OH_NativeVSync** instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| nativeVsync | Pointer to an **OH_NativeVSync** instance.|


### OH_NativeVSync_RequestFrame()


```
int OH_NativeVSync_RequestFrame (OH_NativeVSync * nativeVsync, OH_NativeVSync_FrameCallback callback, void * data )
```

**Description**

Requests the next VSync signal. When the signal arrives, a callback function is invoked. If this function is called for multiple times in the same frame, only the last callback function is invoked.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| callback | Function pointer of the **OH_NativeVSync_FrameCallback** type. This function pointer will be called when the next VSync signal arrives.|
| data | Pointer to the user-defined data struct. The type is void\*.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeVSync_RequestFrameWithMultiCallback()

```
int OH_NativeVSync_RequestFrameWithMultiCallback (OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data )
```

**Description**

Requests the next VSync signal. When the signal arrives, a callback function is invoked. If this function is called for multiple times in the same frame, every callback function is invoked.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeVsync | Pointer to an **OH_NativeVSync** instance.| 
| callback | Function pointer of the **OH_NativeVSync_FrameCallback** type. This function pointer will be called when the next VSync signal arrives.| 
| data | Pointer to the user-defined data struct. The type is void\*.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.
