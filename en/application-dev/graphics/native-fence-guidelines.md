# GPU/CPU Memory Access Sync (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=1f370dd3425411b659f906071e53860b94f0e2f1 translatedAt=2026-08-15T01:51:26.591Z pushedAt=2026-08-15T08:26:29.838Z -->

## Overview

NativeFence is a module that manages the sync status of **fenceFd**. **fenceFd** is a file descriptor used to synchronize memory access between the GPU and CPU. When the GPU or CPU needs to access shared memory, synchronization is performed through **fenceFd**: one party creates a **fenceFd** and sets it to the blocking state, while the other party sends a sync signal to unblock it after completing its operation.

You can use its APIs to set the blocking time, block **fenceFd** permanently, close **fenceFd**, and check its validity.

## Available APIs

| Name| Description|
| -------- | -------- |
| OH_NativeFence_IsValid (int fenceFd) | Checks whether **fenceFd** is valid. |
| OH_NativeFence_Wait (int fenceFd, uint32_t timeout) | Blocks the input **fenceFd**. The timeout parameter specifies the maximum waiting time.|
| OH_NativeFence_WaitForever (int fenceFd) | Permanently blocks the input **fenceFd**.|
| OH_NativeFence_Close (int fenceFd) | Closes **fenceFd**.|

For details about the APIs, see [NativeFence](../reference/apis-arkgraphics2d/capi-nativefence.md).

## How to Develop

The following describes how to use the native APIs provided by `NativeFence`.

**Adding Dynamic Link Libraries**

Add the following library file to the **CMakeLists.txt** file.

```txt
libnative_fence.so
```

Header Files

```c++
#include <native_fence/native_fence.h>
#include <cstring>
#include <iostream>
#include <linux/sync_file.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <unistd.h>
```

1. Call **signalfd()** to create **fenceFd**.

    <!-- @[create_fencefd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeFence/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT); // Monitor SIGINT signal (Ctrl C)
    sigaddset(&mask, SIGURG); // Generated when urgent data or out of band data arrives at the socket
    sigprocmask(SIG_BLOCK, &mask, NULL);
    int sfd = signalfd(-1, &mask, 0);
    ```

2. Check whether the input **fenceFd** is valid.

    <!-- @[check_fence_invalid](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeFence/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    bool isValid = OH_NativeFence_IsValid(INVALID_FD);
    if (!isValid) {
        DRAWING_LOGW("fenceFd is invalid");
    }
    ```

3. Call the **OH_NativeFence_Wait** blocking API to wait for the fence to complete and then perform the next operation.

    <!-- @[wait_fence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeFence/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    constexpr uint32_t TIMEOUT_MS = 5000;
    // ...
    bool result = OH_NativeFence_Wait(INVALID_FD, TIMEOUT_MS);
    ```

4. Call the **OH_NativeFence_WaitForever** blocking API to wait for the fence to complete and then perform the next operation.

    <!-- @[wait_fence_forever](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeFence/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    bool result2 = false;
    auto startTime = std::chrono::steady_clock::now();
    result2 = OH_NativeFence_WaitForever(sfd);
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    if (result2) {
        DRAWING_LOGI("SyncFenceWaitForever has an event occurring result2 %{public}d, cost_time: %{public}d",
            result2, duration);
    } else {
        DRAWING_LOGI("SyncFenceWaitForever timeout with no event occurrence"
            "result2 %{public}d, cost_time: %{public}d", result2, duration);
    }
    ```

5. The GPU or CPU sends a sync signal to notify **fenceFd** of unblocking.

6. Close **fenceFd**.

    <!-- @[close_fence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeFence/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    OH_NativeFence_Close(sfd);
    ```

## Samples

The following sample is provided for NativeFence development:

- [Native Fence (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/NdkNativeFence)