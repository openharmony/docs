# native_vsync.h

## Purpose

This file declares the functions for obtaining and using native virtual synchronization (VSync).
<!--RP1-->
**Sample**: [NDKNativeImage](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeImage)<!--RP1End-->

**File to include**: <native_vsync/native_vsync.h>

**Library**: libnative_vsync.so

**Since**: 9

**Related module**: [NativeVsync](capi-nativevsync.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeVSync_ExpectedRateRange](capi-nativevsync-oh-nativevsync-expectedraterange.md) | OH_NativeVSync_ExpectedRateRange | Provides the expected frame rate range.|
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md) | OH_NativeVSync | Provides the declaration of an **OH_NativeVSync** struct.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_NativeVSync_FrameCallback)(long long timestamp, void *data)](#oh_nativevsync_framecallback) | OH_NativeVSync_FrameCallback | Defines the pointer to a VSync callback function.|
| [OH_NativeVSync* OH_NativeVSync_Create(const char* name, unsigned int length)](#oh_nativevsync_create) | - | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.<br>This API must be used in pair with [OH_NativeVSync_Destroy](capi-native-vsync-h.md#oh_nativevsync_destroy). Otherwise, memory leak occurs.|
| [OH_NativeVSync* OH_NativeVSync_Create_ForAssociatedWindow(uint64_t windowID, const char* name, unsigned int length)](#oh_nativevsync_create_forassociatedwindow) | - | Creates an **OH_NativeVSync** instance to bind with a window. A new **OH_NativeVSync** instance is created each time this API is called.<br>The actual VSync period of the **OH_NativeVSync** instance created by calling this function may be different from the system's VSync period. The system adjusts the actual VSync period based on the window status.|
| [void OH_NativeVSync_Destroy(OH_NativeVSync* nativeVsync)](#oh_nativevsync_destroy) | - | Destroys an **OH_NativeVSync** instance.<br>Once the **OH_NativeVSync** pointer is destroyed, it should not be used, as this can result in dangling pointer problems. Pay special attention to the management of the **OH_NativeVSync** pointer in multithreaded scenarios.|
| [int OH_NativeVSync_RequestFrame(OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data)](#oh_nativevsync_requestframe) | - | Requests the next VSync signal. When the signal arrives, a callback function is invoked.<br>If this function is called for multiple times in the same frame, only the last callback function is invoked.<br>If this function and the [OH_NativeVSync_RequestFrameWithMultiCallback](capi-native-vsync-h.md#oh_nativevsync_requestframewithmulticallback) function are called in the same frame, the current function call does not take effect.|
| [int OH_NativeVSync_RequestFrameWithMultiCallback(OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data)](#oh_nativevsync_requestframewithmulticallback) | - | Requests the next VSync signal. When the signal arrives, a callback function is invoked.<br>If this function is called for multiple times in the same frame, every callback function is invoked.|
| [int OH_NativeVSync_GetPeriod(OH_NativeVSync* nativeVsync, long long* period)](#oh_nativevsync_getperiod) | - | Obtains the VSync period.<br>The VSync period is refreshed only when the **OH_NativeVSync_FrameCallback** callback is received following a request for a VSync signal via **OH_NativeVSync_RequestFrame**.<br>To obtain the VSync period for the first time using this function, you need to call **OH_NativeVSync_RequestFrame** to request a VSync signal. Once the **OH_NativeVSync_FrameCallback** callback is received, the vsync period can be obtained.|
| [int OH_NativeVSync_DVSyncSwitch(OH_NativeVSync* nativeVsync, bool enable)](#oh_nativevsync_dvsyncswitch) | - | Enables DVSync to improve the smoothness of self-drawing animations.<br>DVSync, short for Decoupled VSync, is a frame timing management policy that is decoupled from the hardware's VSync.<br>DVSync drives the early rendering of upcoming animation frames by sending VSync signals with future timestamps. These frames are stored in a frame buffer queue. This helps DVSync reduce potential frame drops and therefore enhances the smoothness of animations.<br>DVSync requires free self-drawing frame buffers to store these pre-rendered animation frames. Therefore, you must ensure that at least one free frame buffer is available. Otherwise, do not enable DVSync.<br>After DVSync is enabled, you must correctly respond to the early VSync signals and request the subsequent VSync after the animation frame associated with the previous VSync is complete. In addition, the self-drawing frames must carry timestamps that align with VSync.<br>After the animation ends, disable DVSync.<br>On a platform that does not support DVSync or if another application has enabled DVSync, the attempt to enable it will not take effect, and the application still receives normal VSync signals.|
| [int OH_NativeVSync_SetExpectedFrameRateRange(OH_NativeVSync* nativeVsync, OH_NativeVSync_ExpectedRateRange* range)](#oh_nativevsync_setexpectedframeraterange) | - | Sets the expected VSync frame rate and its range.|

## Function Description

### OH_NativeVSync_FrameCallback()

```
typedef void (*OH_NativeVSync_FrameCallback)(long long timestamp, void *data)
```

**Description**

Defines the pointer to a VSync callback function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| long long timestamp | System timestamp obtained by VSync using **CLOCK_MONOTONIC**, in nanoseconds.|
|  void *data | Pointer to user-defined data.|

### OH_NativeVSync_Create()

```
OH_NativeVSync* OH_NativeVSync_Create(const char* name, unsigned int length)
```

**Description**

Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this function is called.<br>This API must be used in pair with [OH_NativeVSync_Destroy](capi-native-vsync-h.md#oh_nativevsync_destroy). Otherwise, memory leak occurs.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const char* name | Pointer to the name that associates with the **OH_NativeVSync** instance.|
| unsigned int length | Length of the name (number of characters).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* | Returns the pointer to an **OH_NativeVSync** instance.|

### OH_NativeVSync_Create_ForAssociatedWindow()

```
OH_NativeVSync* OH_NativeVSync_Create_ForAssociatedWindow(uint64_t windowID, const char* name, unsigned int length)
```

**Description**

Creates an **OH_NativeVSync** instance to bind with a window. A new **OH_NativeVSync** instance is created each time this API is called.<br>The actual VSync period of the **OH_NativeVSync** instance created by calling this function may be different from the system's VSync period. The system adjusts the actual VSync period based on the window status.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t windowID | Window ID, which is the index identifier of the window child process and can be obtained through [OH_NativeWindow_GetSurfaceId](capi-external-window-h.md#oh_nativewindow_getsurfaceid).|
| const char* name | Pointer to the name that associates with the **OH_NativeVSync** instance.|
| unsigned int length | Length of the name (number of characters).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* | Returns the pointer to an **OH_NativeVSync** instance.|

### OH_NativeVSync_Destroy()

```
void OH_NativeVSync_Destroy(OH_NativeVSync* nativeVsync)
```

**Description**

Destroys an **OH_NativeVSync** instance.<br>Once the **OH_NativeVSync** pointer is destroyed, it should not be used, as this can result in dangling pointer problems. Pay special attention to the management of the **OH_NativeVSync** pointer in multithreaded scenarios.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an **OH_NativeVSync** instance.|

### OH_NativeVSync_RequestFrame()

```
int OH_NativeVSync_RequestFrame(OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data)
```

**Description**

Requests the next VSync signal. When the signal arrives, a callback function is invoked.<br>If this function is called for multiple times in the same frame, only the last callback function is invoked.<br>If this function and the [OH_NativeVSync_RequestFrameWithMultiCallback](capi-native-vsync-h.md#oh_nativevsync_requestframewithmulticallback) function are called in the same frame, the current function call does not take effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback | Function pointer of the **OH_NativeVSync_FrameCallback** type. This function pointer will be called when the next VSync signal arrives.|
| void* data | Pointer to the user-defined data struct. The type is void.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeVSync_RequestFrameWithMultiCallback()

```
int OH_NativeVSync_RequestFrameWithMultiCallback(OH_NativeVSync* nativeVsync, OH_NativeVSync_FrameCallback callback, void* data)
```

**Description**

Requests the next VSync signal. When the signal arrives, a callback function is invoked.<br>If this function is called for multiple times in the same frame, every callback function is invoked.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| [OH_NativeVSync_FrameCallback](#oh_nativevsync_framecallback) callback | Function pointer of the **OH_NativeVSync_FrameCallback** type. This function pointer will be called when the next VSync signal arrives.|
| void* data | Pointer to the user-defined data struct. The type is void.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeVSync_GetPeriod()

```
int OH_NativeVSync_GetPeriod(OH_NativeVSync* nativeVsync, long long* period)
```

**Description**

Obtains the VSync period.<br>The VSync period is refreshed only when the **OH_NativeVSync_FrameCallback** callback is received following a request for a VSync signal via **OH_NativeVSync_RequestFrame**.<br>To obtain the VSync period for the first time using this function, you need to call **OH_NativeVSync_RequestFrame** to request a VSync signal. Once the **OH_NativeVSync_FrameCallback** callback is received, the vsync period can be obtained.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| long long* period | Pointer to the VSync period.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeVSync_DVSyncSwitch()

```
int OH_NativeVSync_DVSyncSwitch(OH_NativeVSync* nativeVsync, bool enable)
```

**Description**

Enables DVSync to improve the smoothness of self-drawing animations.<br>DVSync, short for Decoupled VSync, is a frame timing management policy that is decoupled from the hardware's VSync.<br>DVSync drives the early rendering of upcoming animation frames by sending VSync signals with future timestamps. These frames are stored in a frame buffer queue. This helps DVSync reduce potential frame drops and therefore enhances the smoothness of animations.<br>DVSync requires free self-drawing frame buffers to store these pre-rendered animation frames. Therefore, you must ensure that at least one free frame buffer is available. Otherwise, do not enable DVSync.<br>After DVSync is enabled, you must correctly respond to the early VSync signals and request the subsequent VSync after the animation frame associated with the previous VSync is complete. In addition, the self-drawing frames must carry timestamps that align with VSync.<br>After the animation ends, disable DVSync.<br>On a platform that does not support DVSync or if another application has enabled DVSync, the attempt to enable it will not take effect, and the application still receives normal VSync signals.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an **OH_NativeVSync** instance.|
| bool enable | Whether to enable DVSync. The value **true** means to enable DVSync, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeVSync_SetExpectedFrameRateRange()

```
int OH_NativeVSync_SetExpectedFrameRateRange(OH_NativeVSync* nativeVsync, OH_NativeVSync_ExpectedRateRange* range)
```

**Description**

Sets the expected frame rate and its range. The actual frame rate may be different from the expected frame rate due to system power consumption, performance, and hardware specifications.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md)* nativeVsync | Pointer to an [OH_NativeVSync](capi-nativevsync-oh-nativevsync.md) instance.|
| [OH_NativeVSync_ExpectedRateRange](capi-nativevsync-oh-nativevsync-expectedraterange.md)* range | Pointer to an [OH_NativeVSync_ExpectedRateRange](capi-nativevsync-oh-nativevsync-expectedraterange.md) instance.<br>Valid expected frame rate range: 0 <= Minimum value <= Expected frame rate <= Maximum value <= 144.<br>The value **0** means that the expected frame rate is canceled.<br>You need to manage the lifecycle of this pointer.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **0** if successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|
