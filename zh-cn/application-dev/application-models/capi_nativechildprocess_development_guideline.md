# Native子进程开发指导（C/C++)

>**说明：**
><br>本模块首批接口从API version 12开始支持，并对[IPCKit](../ipc/ipc-capi-development-guideline.md)存在依赖。

## 场景介绍

本章节介绍如何在主进程中创建Native子进程，并在父子进程间建立IPC通道，方便开发者在Native层进行多进程编程。

## 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char *libName, [OH_Ability_OnNativeChildProcessStarted](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。 |

> **说明：**
>
> 当前仅支持2in1设备，且单个进程只能启动一个Native子进程。

## 开发步骤

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

### 1. 子进程-实现必要的导出方法

在子进程中，实现必要的两个函数**NativeChildProcess_OnConnect**及**NativeChildProcess_MainProc**并导出（假设代码所在的文件名为ChildProcessSample.cpp）。其中NativeChildProcess_OnConnect方法返回的OHIPCRemoteStub对象负责主进程进行IPC通信，具体实现方法请参考[IPC通信开发指导（C/C++)](../ipc/ipc-capi-development-guideline.md)，本文不再赘述。子进程启动后会先调用NativeChildProcess_OnConnect获取IPC Stub对象，之后再调用NativeChildProcess_MainProc移交主线程控制权，该函数返回后子进程随即退出。

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

### 2. 子进程-编译为动态链接库

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

### 3. 主进程-实现子进程启动结果回调函数

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

### 4. 主进程-启动Native子进程

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

### 5. 主进程-添加编译依赖项

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

