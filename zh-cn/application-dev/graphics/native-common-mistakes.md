# 图形缓冲区常见稳定性问题 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

本文档主要针对NativeWindow、NativeBuffer和NativeImage开发过程中的常见问题进行说明，帮助开发者及时避免或定位对应问题，提高应用稳定性。

## OHNativeWindow与NativeWindowBuffer
OHNativeWindow与NativeWindowBuffer在系统多个模块与应用之间传递，通过增加与减少引用计数的NDK接口实现伪智能指针，由各模块维护自己的引用计数，超过90%的问题都是由于增减引用计数接口未匹配导致的。

增加NativeWindow引用计数的接口：
```text
int32_t OH_NativeWindow_NativeObjectReference(void *obj)

int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)

OHNativeWindow* OH_NativeImage_AcquireNativeWindow(OH_NativeImage* image)

int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)
```

减少NativeWindow引用计数的接口：
```text
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)

void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)

void OH_NativeImage_Destroy(OH_NativeImage** image)
```

增加NativeWindowBuffer引用计数的接口：
```text
int32_t OH_NativeWindow_NativeObjectReference(void *obj)

int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])

OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)

int32_t OH_NativeImage_AcquireNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd)
```

减少NativeWindowBuffer引用计数的接口：
```text
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)

void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)

int32_t OH_NativeImage_ReleaseNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd) // 仅接口返回成功时减少引用计数
```

## NativeWindow生命周期问题

### 典型崩溃日志及原因

典型崩溃日志如下：

```text
**典型崩溃日志1**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_DestroyNativeWindow())

**典型崩溃日志2**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(……)
01 /system/lib64/chipset-sdk-sp/libsurface.z.so(……)
02 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeWindowHandleOpt)

**典型崩溃日志3**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectUnreference())
```

可能原因如下：

1.错误地减少了一次NativeWindow引用计数，导致NativeWindow计数减为0释放后，其他地方调用或者再次减计数时崩溃。

2.从XComponent组件获取的NativeWindow，抛向子线程使用，XComponent组件销毁时将NativeWindow引用计数减一，若减为0析构后，子线程仍在使用会导致崩溃。

### 典型错误代码及解决方案

**典型错误代码1**

```c++
OH_NativeImage *image_ = OH_NativeImage_Create(textureId, GL_TEXTURE_2D);
OHNativeWindow *nativewindow_ = OH_NativeImage_AcquireNativeWindow(image_);

// 错误：OH_NativeImage_Destroy中会减少OHNativeWindow引用计数，无需再调用OH_NativeWindow_DestroyNativeWindow
OH_NativeImage_Destroy(image_);
OH_NativeWindow_DestroyNativeWindow(nativewindow_);
```

**具体解析**

OH_NativeImage_Destroy中会减少OHNativeWindow引用计数，无需再调用OH_NativeWindow_DestroyNativeWindow。

修改：删除OH_NativeWindow_DestroyNativeWindow(nativewindow_)，并在OH_NativeImage_Destroy后及时将image_和nativewindow_置空，防止后续使用野指针。


```c++
OH_NativeImage *image_ = OH_NativeImage_Create(textureId, GL_TEXTURE_2D);
OHNativeWindow *nativewindow_ = OH_NativeImage_AcquireNativeWindow(image_);

// 释放NativeImage时将image_和nativewindow_置空，防止后续使用野指针
OH_NativeImage_Destroy(image_);
image_ = nullptr;
nativewindow_ = nullptr;
```

**典型错误代码2**

```c++
void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
{
    uint64_t width = 0;
    uint64_t height = 0;
    int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);

    // 未对NativeWindow增加引用计数直接抛向子线程使用
    NativeRender::GetInstance()->SetNativeWindow(nativewindow_, width, height);
}

void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
{
    if ((component == nullptr) || (window == nullptr)) {
        LOGE("OnSurfaceDestroyedCB: component or window is null");
        return;
    }

    // 错误：通知子线程停止，但未做等待操作，OnSurfaceDestroyedCB结束后NativeWindow可能被释放，子线程正在使用可能崩溃
    NativeRender::GetInstance()->Release();
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);
    // 错误：未对nativewindow_引用计数加一的情况下调用DestroyNativeWindow会使nativewindow_提前释放，导致崩溃
    OH_NativeWindow_DestroyNativeWindow(nativewindow_);
}
```

**具体解析**

从XComponent组件获取NativeWindow后，传递给渲染子线程使用，当页面退出，XComponent组件销毁时，会将NativeWindow引用计数减一，应用未对NativeWindow引用加一的情况下NativeWindow会被释放，此时子线程仍在使用可能导致并发崩溃。

修改方案一：在将NativeWindow传递给子线程前，将其引用计数加一，此时XComponent组件销毁时，因应用持有NativeWindow引用计数，NativeWindow不会销毁，当子线程使用完成后将其引用计数减一。

```c++
void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
{
    uint64_t width = 0;
    uint64_t height = 0;
    int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
    OHNativeWindow* nativewindow_ = static_cast<OHNativeWindow*>(window);

    // 抛任务前将nativeWindow引用计数加一
    OH_NativeWindow_NativeObjectReference(nativewindow_);
    NativeRender::GetInstance()->SetNativeWindow(nativewindow_, width, height);
}

void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
{
    if ((component == nullptr) || (window == nullptr)) {
        LOGE("OnSurfaceDestroyedCB: component or window is null");
        return;
    }

    // 通知子线程停止，因为前面有对引用计数加一，OnSurfaceDestroyedCB结束时不会释放
    // 当子线程使用完毕后执行OH_NativeWindow_NativeObjectUnreference(nativewindow_)对引用计数减一
    NativeRender::GetInstance()->Release();
}
```

修改方案二：在XComponent组件销毁的OnSurfaceDestroyedCB回调通知中，通知子线程停止并等待，直到子线程结束，避免NativeWindow销毁后子线程还在使用。

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
    // 通知子线程停止后等待子线程任务结束再结束OnSurfaceDestroyedCB
    renderThread.join();
}
```

## NativeWindowBuffer生命周期问题

### 典型崩溃日志及原因

典型崩溃日志如下：

```text
**典型崩溃日志1**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_GetBufferHandleFromNative())

**典型崩溃日志2**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectUnreference())

**典型崩溃日志3**
00 /system/lib64/chipset-sdk-sp/libsurface.z.so(OH_NativeWindow_NativeObjectReference())
```

可能原因如下：

从XComponent组件获取的NativeWindow，抛向子线程使用，XComponent组件销毁时将NativeWindow计数减一，NativeWindow销毁时对内部的NativeWindowBuffer引用计数减一，此时子线程刚RequestBuffer拿到buffer正在使用导致崩溃。

### 典型错误代码及解决方案

同上述NativeWindow生命周期问题的典型错误代码及解决方案。

## NativeWindowBuffer卡死问题

### 典型卡死日志及原因

典型卡死日志如下：
```text
/system/lib64/chipset-sdk-sp/libsurface.z.so(RequestBufferLocked())
```

可能原因如下：

应用申请了buffer，但未归还，导致后续无可用buffer，再次申请buffer时卡住。

**典型错误代码**
```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// 错误：异常分支未归还buffer，NativeWindow内buffer数量固定，可能导致后续无buffer可用卡死
if (error) {
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
```

**具体解析**

NativeWindow中的NativeWindowBuffer数量固定，当只申请buffer未归还，会导致NativeWindow内buffer耗尽，再次申请buffer时卡死。

修改：确保申请的buffer一定会归还到NativeWindow中，成功绘制的可通过OH_NativeWindow_NativeWindowFlushBuffer归还，未绘制的可通过OH_NativeWindow_NativeWindowAbortBuffer归还。

```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}

if (error) {
    // 异常分支归还buffer
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
```

## 内存泄漏问题

### 典型内存泄漏原因

额外执行了增加引用计数接口，未配套执行减少引用计数接口导致泄漏。

### 典型错误代码及解决方案

**典型错误代码1**
```c++
auto ret = OH_NativeWindow_NativeWindowRequestBuffer(nativewindow_, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// 错误：对buffer增加了引用计数，绘制流程走到异常分支，异常分支未相应减少引用计数，导致泄漏
if (error) {
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
OH_NativeWindow_NativeObjectReference(buffer);
```

**具体解析**

申请buffer后增加引用计数延长其生命周期，未配套减少引用计数，导致该buffer无法被释放。

修改：确保增加引用计数后有配套调用减少引用计数接口。

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
    // 异常分支配套减少引用计数
    OH_NativeWindow_NativeWindowAbortBuffer(nativewindow_, buffer);
    OH_NativeWindow_NativeObjectUnreference(buffer);
    return;
}

OH_NativeWindow_NativeWindowFlushBuffer(nativewindow_, buffer, fence, region);
OH_NativeWindow_NativeObjectUnreference(buffer);
```

**典型错误代码2**
```c++
auto ret = OH_NativeImage_AcquireNativeWindowBuffer(nativeimage, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// 错误：未对Release失败场景处理，AcquireNativeWindowBuffer成功会对buffer引用计数加一，ReleaseNativeWindowBuffer失败不会减一
OH_NativeImage_ReleaseNativeWindowBuffer(nativeimage, buffer, fence);
OH_NativeWindow_NativeObjectUnreference(buffer);
```

**具体解析**

OH_NativeImage_AcquireNativeWindowBuffer接口获取的buffer会增加引用计数，OH_NativeImage_ReleaseNativeWindowBuffer接口只在成功时减少引用计数，未对返回值做处理会导致内存泄漏。

修改：OH_NativeImage_ReleaseNativeWindowBuffer接口返回不为NATIVE_ERROR_OK时，额外调用OH_NativeWindow_NativeObjectUnreference减少一次引用计数。

```c++
auto ret = OH_NativeImage_AcquireNativeWindowBuffer(nativeimage, &buffer, &fence);
if (ret != NATIVE_ERROR_OK) {
    return;
}
ret = OH_NativeWindow_NativeObjectReference(buffer);
if (ret != NATIVE_ERROR_OK) {
    return;
}

// 对OH_NativeImage_ReleaseNativeWindowBuffer失败做异常处理
ret = OH_NativeImage_ReleaseNativeWindowBuffer(nativeimage, buffer, fence);
if (ret != NATIVE_ERROR_OK) {
    OH_NativeWindow_NativeObjectUnreference(buffer);
}
OH_NativeWindow_NativeObjectUnreference(buffer);
```