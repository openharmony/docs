# Common Stability Issues with Graphics Buffers (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=1f370dd3425411b659f906071e53860b94f0e2f1 translatedAt=2026-08-15T01:51:09.858Z pushedAt=2026-08-15T08:26:08.224Z -->

This section describes common issues that may arise during development with **NativeWindow**, **NativeBuffer**, and **NativeImage**, helping you avoid or locate these issues in a timely manner and improve app stability.

## OHNativeWindow and NativeWindowBuffer

**OHNativeWindow** and **NativeWindowBuffer** are passed between multiple system modules and apps, implementing a pseudo-smart pointer through NDK APIs that increment and decrement the reference count. Each module maintains its own reference count. Over 90% of issues are caused by mismatched reference count increment and decrement API calls.

APIs for incrementing the **NativeWindow** reference count:

```text
int32_t OH_NativeWindow_NativeObjectReference(void *obj)

int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)

OHNativeWindow* OH_NativeImage_AcquireNativeWindow(OH_NativeImage* image)

int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)
```

APIs for decrementing the **NativeWindow** reference count:

```text
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)

void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)

void OH_NativeImage_Destroy(OH_NativeImage** image)
```

APIs for incrementing the **NativeWindowBuffer** reference count:

```text
int32_t OH_NativeWindow_NativeObjectReference(void *obj)

int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])

OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)

int32_t OH_NativeImage_AcquireNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd)
```

APIs for decrementing the **NativeWindowBuffer** reference count:

```text
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)

void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)

int32_t OH_NativeImage_ReleaseNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd) // Decrement the reference count only when the API returns success.
```

## NativeWindow Lifecycle Issues

### Typical Crash Logs and Causes

Typical crash logs are as follows:

```text
**Typical crash log 1**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_DestroyNativeWindow())

**Typical crash log 2**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(...)
01 /system/lib64/chipset-sdk-sp/libsurface.z.so(...)
02 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeWindowHandleOpt)

**Typical crash log 3**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectUnreference())
```

Possible causes are as follows:

1. The **NativeWindow** reference count is incorrectly decremented once, causing the count to drop to zero and the **NativeWindow** to be released. Subsequent calls or further decrements on the released object then trigger a crash.

2. A **NativeWindow** obtained from an **XComponent** is passed to a child thread for use. When the **XComponent** is destroyed, the **NativeWindow** reference count is decremented by one. If the count reaches zero and the object is destructed while the child thread is still using it, a crash occurs.

### Typical Error Codes and Solutions

**Typical Error Code 1**

```c++
OH_NativeImage *image_ = OH_NativeImage_Create(textureId, GL_TEXTURE_2D);
OHNativeWindow *nativewindow_ = OH_NativeImage_AcquireNativeWindow(image_);

// Error: OH_NativeImage_Destroy decrements the OHNativeWindow reference count internally, so calling OH_NativeWindow_DestroyNativeWindow is unnecessary.
OH_NativeImage_Destroy(image_);
OH_NativeWindow_DestroyNativeWindow(nativewindow_);
```

**Analysis**

**OH_NativeImage_Destroy** reduces the **OHNativeWindow** reference count, so there is no need to call **OH_NativeWindow_DestroyNativeWindow**.

Solution: Delete **OH_NativeWindow_DestroyNativeWindow(nativewindow_)**, and set **image_** and **nativewindow_** to null immediately after **OH_NativeImage_Destroy** to prevent subsequent use of wild pointers.

```c++
OH_NativeImage *image_ = OH_NativeImage_Create(textureId, GL_TEXTURE_2D);
OHNativeWindow *nativewindow_ = OH_NativeImage_AcquireNativeWindow(image_);

// Set image_ and nativewindow_ to null when releasing NativeImage to prevent subsequent use of wild pointers.
OH_NativeImage_Destroy(image_);
image_ = nullptr;
nativewindow_ = nullptr;
```

**Typical Error Code 2**

```c++
void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
{
    uint64_t width = 0;
    uint64_t height = 0;
    int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);

    // Pass NativeWindow to a child thread without incrementing the reference count.
    NativeRender::GetInstance()->SetNativeWindow(nativewindow_, width, height);
}

void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
{
    if ((component == nullptr) || (window == nullptr)) {
        LOGE("OnSurfaceDestroyedCB: component or window is null");
        return;
    }

    // Error: The child thread is notified to stop, but no wait operation is performed. NativeWindow may be released after OnSurfaceDestroyedCB ends, and the child thread may crash while still using it.
    NativeRender::GetInstance()->Release();
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);
    // Error: Calling DestroyNativeWindow without incrementing the reference count of nativewindow_ causes it to be released prematurely, leading to a crash.
    OH_NativeWindow_DestroyNativeWindow(nativewindow_);
}
```

**Analysis**

After the **NativeWindow** is obtained from the **XComponent** and passed to a rendering subthread, when the page exits and the **XComponent** is destroyed, the reference count of the **NativeWindow** is decremented by one. If the app has not incremented the **NativeWindow** reference count, the **NativeWindow** is released while the subthread is still using it, which may cause a concurrent crash.

Solution 1: Before passing the **NativeWindow** to the subthread, increment its reference count by one. In this case, when the **XComponent** is destroyed, the **NativeWindow** is not released because the app holds a reference count on it. After the subthread finishes using it, decrement its reference count by one.

```c++
void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
{
    uint64_t width = 0;
    uint64_t height = 0;
    int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);

    // Increment the reference count of nativeWindow before posting the task.
    OH_NativeWindow_NativeObjectReference(nativewindow_);
    NativeRender::GetInstance()->SetNativeWindow(nativewindow_, width, height);
}

void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
{
    if ((component == nullptr) || (window == nullptr)) {
        LOGE("OnSurfaceDestroyedCB: component or window is null");
        return;
    }

    // Notify the child thread to stop. Because the reference count was incremented earlier, NativeWindow will not be released when OnSurfaceDestroyedCB ends.
    // After the child thread finishes, call OH_NativeWindow_NativeObjectUnreference(nativewindow_) to decrement the reference count.
    NativeRender::GetInstance()->Release();
}
```

Solution 2: In the **OnSurfaceDestroyedCB** callback notification for **XComponent** destruction, notify the child thread to stop and wait until the child thread finishes, so as to prevent the child thread from continuing to use **NativeWindow** after it is destroyed.

```c++
void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
{
    uint64_t width = 0;
    uint64_t height = 0;
    int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);

    NativeRender::GetInstance()->SetNativeWindow(nativewindow_, width, height);
}

void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
{
    if ((component == nullptr) || (window == nullptr)) {
        LOGE("OnSurfaceDestroyedCB: component or window is null");
        return;
    }

    NativeRender::GetInstance()->Release();
    // After notifying the child thread to stop, wait for the child thread task to complete before ending OnSurfaceDestroyedCB.
    renderThread.join();
}
```

## NativeWindowBuffer Lifecycle Issues

### Typical Crash Logs and Causes

Typical crash logs are as follows:

```text
**Typical crash log 1**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_GetBufferHandleFromNative())

**Typical crash log 2**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectUnreference())

**Typical crash log 3**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectReference())
```

Possible causes are as follows:

The **NativeWindow** obtained from the **XComponent** is passed to a child thread for use. When the **XComponent** is destroyed, the reference count of the **NativeWindow** is decremented by one. When the **NativeWindow** is destroyed, the reference count of its internal **NativeWindowBuffer** is decremented by one. At this point, the child thread has just called **RequestBuffer** and is using the buffer, resulting in a crash.

### Typical Error Codes and Solutions

Same as the typical error codes and solutions for **NativeWindow** lifecycle issues described above.

## NativeWindowBuffer Freeze Issues

### Typical Freeze Log and Causes

A typical freeze log is as follows:

```text
/system/lib64/chipset-sdk-sp/libsurface.z.so(RequestBufferLocked())
```

Possible causes are as follows:

The app requested a buffer but did not return it, resulting in no available buffer for subsequent use and causing a freeze when requesting a buffer again.

**Typical Error Code**

```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// Error: The buffer is not returned in the exception branch. NativeWindow has a fixed number of buffers, which may cause a stall when no buffer is available later.
if (error) {
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
```

**Analysis**

The number of NativeWindowBuffer instances in NativeWindow is fixed. If a buffer is requested but not returned, the buffers in NativeWindow will be exhausted, causing a freeze when requesting a buffer again.

Fix: Ensure that every requested buffer is returned to NativeWindow. A buffer that has been successfully drawn can be returned through OH_NativeWindow_NativeWindowFlushBuffer, and a buffer that has not been drawn can be returned through OH_NativeWindow_NativeWindowAbortBuffer.

```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}

if (error) {
    // Return the buffer in the exception branch.
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
```

## Memory Leak Issues

### Typical Memory Leak Causes

A memory leak can occur when an API that increments the reference count is called without a corresponding call to the API that decrements the reference count.

### Typical Error Codes and Solutions

**Typical Error Code 1**

```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// Error: The reference count of the buffer is incremented, but the drawing process enters the exception branch where the reference count is not correspondingly decremented, causing a leak.
if (error) {
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
OH_NativeWindow_NativeObjectReference(buffer);
```

**Analysis**

After the buffer is obtained, its reference count is incremented to extend its lifecycle, but the reference count is not decremented correspondingly, preventing the buffer from being released.

Solution: Ensure that each reference count increment is paired with a corresponding call to the reference count decrement API.

```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

if (error) {
    // Decrement the reference count in the error branch.
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    OH_NativeWindow_NativeObjectUnreference(buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
OH_NativeWindow_NativeObjectUnreference(buffer);
```

**Typical Error Code 2**

```c++
auto ret = OH_NativeImage_AcquireNativeWindowBuffer(nativeimage, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// Error: The Release failure scenario is not handled. AcquireNativeWindowBuffer increments the buffer reference count on success, but ReleaseNativeWindowBuffer does not decrement it on failure.
OH_NativeImage_ReleaseNativeWindowBuffer(nativeimage, buffer, fence);
OH_NativeWindow_NativeObjectUnreference(buffer);
```

**Analysis**

The buffer obtained through the **OH_NativeImage_AcquireNativeWindowBuffer** API increments the reference count. The **OH_NativeImage_ReleaseNativeWindowBuffer** API decrements the reference count only upon success. Failure to handle the return value will result in a memory leak.

Solution: When the return value of **OH_NativeImage_ReleaseNativeWindowBuffer** is not **NATIVE_ERROR_OK**, call **OH_NativeWindow_NativeObjectUnreference** to decrement the reference count once.

```c++
auto ret = OH_NativeImage_AcquireNativeWindowBuffer(nativeimage, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// Handle the exception when OH_NativeImage_ReleaseNativeWindowBuffer fails.
ret = OH_NativeImage_ReleaseNativeWindowBuffer(nativeimage, buffer, fence);
if (ret != NATIVE_ERROR_OK) {
    OH_NativeWindow_NativeObjectUnreference(buffer);
}
OH_NativeWindow_NativeObjectUnreference(buffer);
```