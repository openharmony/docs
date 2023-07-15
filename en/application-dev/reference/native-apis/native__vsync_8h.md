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
| [OH_NativeVSync](_native_vsync.md#oh_nativevsync) | Provides the declaration of an **OH_NativeVSync** struct. |
| (\*[OH_NativeVSync_FrameCallback](_native_vsync.md#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | Defines the pointer to a VSync callback function.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeVSync_Create](_native_vsync.md#oh_nativevsync_create) (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.|
| [OH_NativeVSync_Destroy](_native_vsync.md#oh_nativevsync_destroy) (OH_NativeVSync \*nativeVsync) | Destroys an **OH_NativeVSync** instance.|
| [OH_NativeVSync_RequestFrame](_native_vsync.md#oh_nativevsync_requestframe) (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked.|
