# native_vsync.h


## Overview

The **native_vsync.h** file declares the functions for obtaining and using native virtual synchronization (VSync).

**Since**

9

**Related Modules**

[NativeVsync](_native_vsync.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode) [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode) | Defines an enum for the error codes. | 
| typedef struct [OH_NativeVSync](_native_vsync.md#oh_nativevsync) [OH_NativeVSync](_native_vsync.md#oh_nativevsync) | Provides the declaration of an **OH_NativeVSync** struct. | 
| typedef void(\* [OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | Defines the pointer to a VSync callback function. | 

### Enums

| Name| Description| 
| -------- | -------- |
| [OHNativeErrorCode](_native_vsync.md#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_UNSUPPORT = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 

### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeVSync_Create](_native_vsync.md#oh_nativevsync_create) (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.|
| [OH_NativeVSync_Destroy](_native_vsync.md#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | Destroys an **OH_NativeVSync** instance.|
| [OH_NativeVSync_RequestFrame](_native_vsync.md#oh_nativevsync_requestframe) (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked.|
| [OH_NativeVSync_GetPeriod](_native_vsync.md#oh_nativevsync_getperiod) (OH_NativeVSync \*nativeVsync, long long \*period) |Obtains the VSync period.|
