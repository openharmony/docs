# Native子进程开发指导（C/C++）

本模块提供了两种创建子进程的方式，开发者可根据需要进行选择。
- [创建支持IPC回调的子进程](#创建支持ipc回调的子进程)：创建子进程，并在父子进程间建立IPC通道，适用于父子进程需要IPC通信的场景。对[IPCKit](../ipc/ipc-capi-development-guideline.md)存在依赖。
- [创建支持参数传递的子进程](#创建支持参数传递的子进程)：创建子进程，并传递字符串和fd句柄参数到子进程。适用于需要传递参数到子进程的场景。


## 创建支持IPC回调的子进程

### 场景介绍

本章节介绍如何在主进程中创建Native子进程，并在父子进程间建立IPC通道，方便开发者在Native层进行多进程编程。

### 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char *libName, [OH_Ability_OnNativeChildProcessStarted](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。 |

> **说明：**
>
> 当前仅支持2in1设备。
> 从API version 15开始，单个进程最多支持启动50个Native子进程。API version 14及之前版本，单个进程只能启动1个Native子进程。

### 开发步骤

基于已创建完成的Native应用开发工程，在此基础上介绍如何使用`AbilityKit`提供的C API接口，创建Native子进程，并同时在父子进程间建立IPC通道。

**动态库文件**

```txt
libipc_capi.so
libchild_process.so
```

**头文件**

```c++
#include <IPCKit/ipc_kit.h>
#include <AbilityKit/native_child_process.h>
```

1. 子进程-实现必要的导出方法。

    在子进程中，实现必要的两个函数**NativeChildProcess_OnConnect**及**NativeChildProcess_MainProc**并导出（假设代码所在的文件名为ChildProcessSample.cpp）。其中NativeChildProcess_OnConnect方法返回的OHIPCRemoteStub对象负责主进程进行IPC通信，具体实现方法请参考[IPC通信开发指导（C/C++)](../ipc/ipc-capi-development-guideline.md)，本文不再赘述。

    子进程启动后会先调用NativeChildProcess_OnConnect获取IPC Stub对象，之后再调用NativeChildProcess_MainProc移交主线程控制权，该函数返回后子进程随即退出。

    ```c++
    #include <IPCKit/ipc_kit.h>

    extern "C" {

    OHIPCRemoteStub* NativeChildProcess_OnConnect()
    {
        // ipcRemoteStub指向子进程实现的ipc stub对象，用于接收来自主进程的IPC消息并响应
        // 子进程根据业务逻辑控制其生命周期
        return ipcRemoteStub;
    }

    void NativeChildProcess_MainProc()
    {
        // 相当于子进程的Main函数，实现子进程的业务逻辑
        // ...
        // 函数返回后子进程随即退出
    }
    
    } // extern "C"
    ```

2. 子进程-编译为动态链接库。

    修改CMakeList.txt文件，编译为动态链接库（假设需要编译出的库文件名称为libchildprocesssample.so），并添加IPC动态库依赖。

    ```txt
    add_library(childprocesssample SHARED
        # 实现必要导出方法的源文件
        ChildProcessSample.cpp
        
        # 其它代码源文件
        # ...
    )

    target_link_libraries(childprocesssample PUBLIC
        # 添加依赖的IPC动态库
        libipc_capi.so
        
        # 其它所依赖的动态库
        # ...
    )
    ```

3. 主进程-实现子进程启动结果回调函数。

    ```c++
    #include <IPCKit/ipc_kit.h>

    static void OnNativeChildProcessStarted(int errCode, OHIPCRemoteProxy *remoteProxy)
    {
        if (errCode != NCP_NO_ERROR) {
            // 子进程未能正常启动时的异常处理
            // ...
            return;
        }

        // 保存remoteProxy对象，后续基于IPC Kit提供的API同子进程间进行IPC通信
        // 耗时操作建议转移到独立线程去处理，避免长时间阻塞回调线程
        // IPC对象使用完毕后，需要调用OH_IPCRemoteProxy_Destroy方法释放
        // ...
    }
    ```

    回调函数传递的第二个参数OHIPCRemoteProxy对象，会与子进程实现的**NativeChildProcess_OnConnect**方法返回的OHIPCRemoteStub对象间建立IPC通道，具体使用方法参考[IPC通信开发指导（C/C++)](../ipc/ipc-capi-development-guideline.md)，本文不再赘述；OHIPCRemoteProxy对象使用完毕后，需要调用[OH_IPCRemoteProxy_Destroy](../reference/apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)函数释放。

4. 主进程-启动Native子进程。

    调用API启动Native子进程，需要注意返回值为NCP_NO_ERROR仅代表成功调用native子进程启动逻辑，实际的启动结果通过第二个参数中指定的回调函数异步通知。需注意**仅允许在主进程中创建子进程**。

    ```c++
    #include <AbilityKit/native_child_process.h>

    // 第一个参数"libchildprocesssample.so"为实现了子进程必要导出方法的动态库文件名称
    int32_t ret = OH_Ability_CreateNativeChildProcess("libchildprocesssample.so", OnNativeChildProcessStarted);
    if (ret != NCP_NO_ERROR) {
        // 子进程未能正常启动时的异常处理
        // ...
    }
    ```

5. 主进程-添加编译依赖项。

    修改CMaklist.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的IPC及元能力动态库
        libipc_capi.so
        libchild_process.so
        
        # 其它依赖的动态库
        # ...
    )
    ```

## 创建支持参数传递的子进程

### 场景介绍

本章节介绍如何创建Native子进程，并传递参数到子进程。

### 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess) (const char \*entry, [NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args) args, [NativeChildProcess_Options](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_options) options, int32_t *pid) | 启动子进程并返回子进程pid。 |

### 开发步骤


**动态库文件**

```txt
libchild_process.so
```

**头文件**

```c++
#include <AbilityKit/native_child_process.h>
```

1. 子进程-实现必要的导出方法。

    在子进程中，实现参数为[NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args)入口函数并导出（假设代码所在的文件名为ChildProcessSample.cpp）。子进程启动后会调用该入口函数，该函数返回后子进程随即退出。

    ```c++
    #include <AbilityKit/native_child_process.h>

    extern "C" {

    /**
     * 子进程的入口函数，实现子进程的业务逻辑
     * 函数名称可以自定义，在主进程调用OH_Ability_StartNativeChildProcess方法时指定，此示例中为Main
     * 函数返回后子进程退出
     */
    void Main(NativeChildProcess_Args args)
    {
        // 获取传入的entryPrams
        char *entryParams = args.entryParams;
        // 获取传入的fd列表
        NativeChildProcess_Fd *current = args.fdList.head;
        while (current != nullptr) {
            char *fdName = current->fdName;
            int32_t fd = current->fd;
            current = current->next;
            // 业务逻辑..
        }
    }
    } // extern "C"
    ```

2. 子进程-编译为动态链接库。

    修改CMakeList.txt文件，编译为动态链接库（假设需要编译出的库文件名称为libchildprocesssample.so），并添加元能力动态库依赖。

    ```txt
    add_library(childprocesssample SHARED
        # 实现必要导出方法的源文件
        ChildProcessSample.cpp
        
        # 其它代码源文件
        # ...
    )

    target_link_libraries(childprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so

        # 其它所依赖的动态库
        # ...
    )
    ```

3. 主进程-启动Native子进程。

    调用API启动Native子进程，返回值为NCP_NO_ERROR代表成功启动native子进程。

    ```c++
    #include <AbilityKit/native_child_process.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>

    void startNativeChildProcess()
    {
        // ...
        NativeChildProcess_Args args;
        // 设置entryParams，支持传输的最大数据量为150KB
        args.entryParams = (char*)malloc(sizeof(char) * 10);
        (void)strcpy(args.entryParams, "testParam");

        // 插入节点到链表头节点中
        args.fdList.head = (NativeChildProcess_Fd*)malloc(sizeof(NativeChildProcess_Fd));
        // fd关键字，最多不超过20个字符
        args.fdList.head->fdName = (char*)malloc(sizeof(char) * 4);
        (void)strcpy(args.fdList.head->fdName, "fd1");
        // 获取fd逻辑
        int32_t fd = open("/data/storage/el2/base/haps/entry/files/test.txt", O_RDWR | O_CREAT, 0644);
        args.fdList.head->fd = fd;
        // 此处只插入一个fd记录，根据需求可以插入更多fd记录到链表中，最多不超过16个
        args.fdList.head->next = NULL;
        NativeChildProcess_Options options = {
            .isolationMode = NCP_ISOLATION_MODE_ISOLATED
        };

        // 第一个参数"libchildprocesssample.so:Main"为实现了子进程Main方法的动态库文件名称和入口方法名
        int32_t pid = -1;
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_StartNativeChildProcess(
            "libchildprocesssample.so:Main", args, options, &pid);
        if (ret != NCP_NO_ERROR) {
            // 释放NativeChildProcess_Args中的内存空间防止内存泄漏
            // 子进程未能正常启动时的异常处理
            // ...
        }

        // 其他逻辑
        // ...

        // 释放NativeChildProcess_Args中的内存空间防止内存泄漏
    }
    ```

4. 主进程-添加编译依赖项。

    修改CMaklist.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so
        
        # 其它依赖的动态库
        # ...
    )
    ```

## 子进程获取启动参数

### 场景介绍

从API version 16开始，支持子进程获取启动参数。

### 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args)* [OH_Ability_GetCurrentChildProcessArgs](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)() | 返回子进程自身的启动参数。 |

### 开发步骤


**动态库文件**

```txt
libchild_process.so
```

**头文件**

```c++
#include <AbilityKit/native_child_process.h>
```

**获取启动参数**

[OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)创建子进程后，子进程内的任意so和任意子线程可以通过调用[OH_Ability_GetCurrentChildProcessArgs](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)()获取到子进程的启动参数[NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args)，便于操作相关的文件描述符。

```c++
#include <AbilityKit/native_child_process.h>
#include <thread>

extern "C" {

void ThreadFunc()
{
    // 获取子进程的启动参数
    NativeChildProcess_Args *args = OH_Ability_GetCurrentChildProcessArgs();
    // 获取启动参数失败时返回nullptr
    if (args == nullptr) {
        return;
    }
    // 获取启动参数中的entryPrams
    char *entryParams = args.entryParams;
    // 获取fd列表
    NativeChildProcess_Fd *current = args.fdList.head;
    while (current != nullptr) {
        char *fdName = current->fdName;
        int32_t fd = current->fd;
        current = current->next;
        // 业务逻辑..
    }
}

/**
 * 子进程的入口函数，实现子进程的业务逻辑
 * args是子进程的启动参数
 */
void Main(NativeChildProcess_Args args)
{
    // 业务逻辑..

    // 创建线程
    std::thread tObj(ThreadFunc);
}

} // extern "C"
```

