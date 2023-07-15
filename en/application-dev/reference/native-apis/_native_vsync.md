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
| [native_vsync.h](native__vsync_8h.md) | Declares the functions for obtaining and using native VSync.<br>File to include: &lt;native_vsync/native_vsync.h&gt;|


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeVSync](#oh_nativevsync) | Provides the declaration of an **OH_NativeVSync** struct. |
| (\*[OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback)) (long long timestamp, void \*data) | Defines the pointer to a VSync callback function.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeVSync_Create](#oh_nativevsync_create) (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.|
| [OH_NativeVSync_Destroy](#oh_nativevsync_destroy) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync) | Destroys an **OH_NativeVSync** instance.|
| [OH_NativeVSync_RequestFrame](#oh_nativevsync_requestframe) ([OH_NativeVSync](#oh_nativevsync) \*nativeVsync, [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked.|


## Type Description


### OH_NativeVSync


```
typedef struct OH_NativeVSync OH_NativeVSync
```

**Description**

Provides the declaration of a **OH_NativeVSync** struct.


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


## Function Description


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

Requests the next VSync signal. When the signal arrives, a callback function is invoked.

\@syscap SystemCapability.Graphic.Graphic2D.NativeVsync

**Parameters**

| Name| Description|
| -------- | -------- |
| nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| callback | Function pointer of the **OH_NativeVSync_FrameCallback** type. This function pointer will be called when the next VSync signal arrives.|
| data | Pointer to the user-defined data struct. The type is void\*.|

**Returns**

Returns **0** if the operation is successful.
