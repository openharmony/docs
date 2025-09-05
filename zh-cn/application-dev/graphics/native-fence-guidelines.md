# GPU/CPU内存访问同步操作开发指南 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 场景介绍

NativeFence是提供**同步管理fenceFd**的模块。开发者可以通过`NativeFence`接口实现对fenceFd阻塞指定时间、永久阻塞、关闭和检查fenceFd是否有效等操作。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| OH_NativeFence_IsValid (int fenceFd) | 检查fenceFd是否有效。 |
| OH_NativeFence_Wait (int fenceFd, uint32_t timeout) | 阻塞传入的fenceFd，最大阻塞时间由超时参数决定。 |
| OH_NativeFence_WaitForever (int fenceFd) | 永久阻塞传入的fenceFd。 |
| OH_NativeFence_Close (int fenceFd) | 关闭fenceFd。 |

详细的接口说明请参考[NativeFence](../reference/apis-arkgraphics2d/capi-nativefence.md)。

## 开发步骤

以下步骤描述了如何使用`NativeFence`提供的Native API接口。

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libnative_fence.so
```

**头文件**
```c++
#include <native_fence/native_fence.h>
#include <cstring>
#include <iostream>
#include <linux/sync_file.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <unistd.h>
```
1. **通过signalfd创建fenceFd**。
    ```c++
    sigset_t mask;
    sigemptyset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    int fenceFd = signalfd(-1, &mask, 0);
    ```

2. **判断传入的fenceFd是否合法**。
    ```c++
    // 检查fenceFd是否有效
    bool isValid = OH_NativeFence_IsValid(fenceFd);
    if (!isValid) {
        std::cout << "fenceFd is invalid" << std::endl;
    }
    ```

3. **调用OH_NativeFence_Wait阻塞接口**。
    ```c++
    constexpr uint32_t TIMEOUT_MS = 5000;
    bool resultWait = OH_NativeFence_Wait(fenceFd, TIMEOUT_MS);
    if (!resultWait) {
        std::cout << "OH_NativeFence_Wait Failed" << std::endl;
    }
    ```

4. **调用OH_NativeFence_WaitForever阻塞接口**。
    ```c++
    bool resultWaitForever = OH_NativeFence_WaitForever(fenceFd);
    if (!resultWaitForever) {
        std::cout << "OH_NativeFence_WaitForever Failed" << std::endl;
    }
    ```

5. **GPU或CPU进行信号触发signal，通知fenceFd解除阻塞**。

6. **关闭fenceFd**。
    ```c++
    OH_NativeFence_Close(fenceFd);
    ```