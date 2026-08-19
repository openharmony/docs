# 子进程开发指导（C/C++）
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

在Native层多进程编程场景中，开发者常面临父子进程通信复杂、参数传递困难等问题。[Native子进程](../application-models/ability-terminology.md#native子进程)机制允许应用通过C API创建子进程，支持IPC通信和参数传递，适用于需要高性能进程隔离和跨进程通信的场景。本模块提供了创建Native子进程、获取启动参数、终止子进程、获取子进程退出信息等能力，两种创建方式的接口选型和能力差异请参见[子进程创建方式选择](#子进程创建方式选择)。

> **说明：** 
> 
> - 创建的子进程会随着父进程的退出而退出，无法脱离父进程独立运行。
> - 创建子进程前，可调用[OH_Ability_IsNativeChildProcessSupported](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_isnativechildprocesssupported)查询当前设备是否支持创建Native子进程。

## 子进程创建方式选择

| 对比项 | [创建支持IPC通信的Native子进程](#创建支持ipc通信的native子进程) | [创建支持参数传递的Native子进程](#创建支持参数传递的native子进程) |
| --- | --- | --- |
| 涉及接口 | [OH_Ability_CreateNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createnativechildprocesswithconfigs)<sup>20+</sup> | [OH_Ability_StartNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs)<sup>20+</sup> |
| 适用场景 | 适用于父子进程需要建立IPC通道通信的场景，如将高风险操作或独立业务逻辑隔离到子进程并通过IPC交互。 | 适用于需要向子进程传递参数（字符串、文件描述符）并由子进程执行计算任务的场景，如音视频编解码、数据处理等。 |
| 父子进程通信方式 | IPC通道（子进程通过NativeChildProcess_OnConnect返回IPC Stub，主进程通过OHIPCRemoteProxy通信） | 参数传递（通过[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)传入entryParams和fd列表，单向传参） |
| 子进程入口函数 | 需实现并导出NativeChildProcess_OnConnect和NativeChildProcess_MainProc两个函数 | 需实现并导出以[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)为参数的入口函数（函数名可自定义） |
| 启动结果获取 | 异步，通过onProcessStarted回调通知启动结果和IPC Proxy对象 | 同步，通过输出参数pid返回子进程号 |
| 是否依赖IPC Kit | 是 | 否 |
| 子进程销毁方式 | NativeChildProcess_MainProc返回后子进程退出 | 入口函数返回后子进程退出 |

## 创建支持IPC通信的Native子进程

通过[OH_Ability_CreateNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createnativechildprocesswithconfigs)接口异步创建Native子进程，子进程需实现并导出NativeChildProcess_OnConnect和NativeChildProcess_MainProc两个函数。子进程启动后先调用NativeChildProcess_OnConnect获取IPC Stub对象，再调用NativeChildProcess_MainProc移交主线程控制权，该函数返回后子进程随即退出。该方式对[IPC Kit](../ipc/ipc-rpc-overview.md)存在依赖。


1. 添加动态库文件和头文件引用。

    在CMakeLists.txt文件中添加动态库文件。

    ```txt
    libipc_capi.so
    libchild_process.so
    ```

    在源文件中引入头文件。

    <!-- @[child_process_head_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/ChildProcessSample.cpp) -->
    
    ``` C++
    #include <IPCKit/ipc_kit.h>
    #include <AbilityKit/native_child_process.h>
    ```

2. 在子进程中实现必要的导出方法。

    在子进程中，实现必要的两个函数**NativeChildProcess_OnConnect**及**NativeChildProcess_MainProc**并导出（假设代码所在的文件名为ChildProcessSample.cpp）。其中NativeChildProcess_OnConnect方法返回的OHIPCRemoteStub对象负责与主进程进行IPC通信，具体实现方法请参考[IPC通信开发指导（C/C++)](../ipc/ipc-capi-development-guideline.md)，本文不再赘述。

    子进程启动后会先调用NativeChildProcess_OnConnect获取IPC Stub对象，之后再调用NativeChildProcess_MainProc移交主线程控制权，该函数返回后子进程随即退出。
    
    <!-- @[child_process_must_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/ChildProcessSample.cpp) --> 
    
    ``` C++
    #include <IPCKit/ipc_kit.h>
    // ...
    #include <IPCKit/ipc_cremote_object.h>
    #include <IPCKit/ipc_cparcel.h>
    #include <IPCKit/ipc_error_code.h>
    
    class IpcCapiStubTest {
    public:
        explicit IpcCapiStubTest();
        ~IpcCapiStubTest();
        OHIPCRemoteStub *GetRemoteStub();
        static int OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData);
    
    private:
        OHIPCRemoteStub *stub_{nullptr};
    };
    
    IpcCapiStubTest::IpcCapiStubTest()
    {
        // 创建stub对象
        stub_ = OH_IPCRemoteStub_Create("testIpc", &IpcCapiStubTest::OnRemoteRequest, nullptr, this);
    }
    
    IpcCapiStubTest::~IpcCapiStubTest()
    {
        if (stub_ != nullptr) {
            OH_IPCRemoteStub_Destroy(stub_);
        }
    }
    
    OHIPCRemoteStub *IpcCapiStubTest::GetRemoteStub() { return stub_; }
    
    int IpcCapiStubTest::OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
    {
        return OH_IPC_SUCCESS;
    }
    
    IpcCapiStubTest g_ipcStubObj;
    
    extern "C" {
    OHIPCRemoteStub *NativeChildProcess_OnConnect()
    {
        // ipcRemoteStub指向子进程实现的ipc stub对象，用于接收来自主进程的IPC消息并响应
        // 子进程根据业务逻辑控制其生命周期
        return g_ipcStubObj.GetRemoteStub();
    }
    
    void NativeChildProcess_MainProc()
    {
        // 相当于子进程的Main函数，实现子进程的业务逻辑
        // ...
        // 函数返回后子进程随即退出
    }
    
    } // extern "C"
    ```


3. 编译动态链接库。

    修改CMakeLists.txt文件，编译动态链接库（假设需要编译出的库文件名称为libchildprocesssample.so），并添加IPC动态库依赖。

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

4. 在主进程中实现子进程启动结果回调函数。

    <!-- @[main_handle_child_start_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/MainProcessSample.cpp) -->
    
    ``` C++
    #include <IPCKit/ipc_kit.h>
    #include <AbilityKit/native_child_process.h>
    // ···
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
        // ···
    }
    ```

    回调函数传递的第二个参数OHIPCRemoteProxy对象，会与子进程实现的**NativeChildProcess_OnConnect**方法返回的OHIPCRemoteStub对象间建立IPC通道，具体使用方法参考[IPC通信开发指导（C/C++)](../ipc/ipc-capi-development-guideline.md)，本文不再赘述；OHIPCRemoteProxy对象使用完毕后，需要调用[OH_IPCRemoteProxy_Destroy](../reference/apis-ipc-kit/capi-ipc-cremote-object-h.md#oh_ipcremoteproxy_destroy)函数释放。

5. 在主进程中启动Native子进程。

    调用[OH_Ability_CreateNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createnativechildprocesswithconfigs)接口启动Native子进程，可通过[OH_Ability_CreateChildProcessConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createchildprocessconfigs)创建子进程配置信息对象，并按需设置进程名、隔离模式和uid隔离等。需注意返回值为NCP_NO_ERROR仅代表成功调用native子进程启动逻辑，实际的启动结果通过回调函数异步通知。需注意**仅允许在主进程中创建子进程**。

    <!-- @[main_processIpc_launch_native_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/MainProcessSample.cpp) -->
    
    ``` C++
    #include <IPCKit/ipc_kit.h>
    #include <AbilityKit/native_child_process.h>
    // ...
    int32_t g_result = -1;
    // ...
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
    
    void CreateNativeChildProcess()
    {
        // 创建子进程配置信息对象
        Ability_ChildProcessConfigs *configs = OH_Ability_CreateChildProcessConfigs();
        // 设置子进程的进程名
        OH_Ability_ChildProcessConfigs_SetProcessName(configs, "childprocess_ipc");
        // 第一个参数"libchildprocesssample.so"为实现了子进程必要导出方法的动态库文件名称
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_CreateNativeChildProcessWithConfigs("libchildprocesssample.so",
            configs, OnNativeChildProcessStarted);
        // configs对象使用完毕后需要销毁，避免内存泄漏
        OH_Ability_DestroyChildProcessConfigs(configs);
        if (ret != NCP_NO_ERROR) {
            // 子进程未能正常启动时的异常处理
            // ...
        }
        g_result = ret;
    }
    ```


6. 为主进程添加编译依赖项。

    修改CMakeLists.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的IPC及元能力动态库
        libipc_capi.so
        libchild_process.so
        
        # 其它依赖的动态库
        # ...
    )
    ```

## 创建支持参数传递的Native子进程

通过[OH_Ability_StartNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs)接口同步创建Native子进程，子进程需实现以[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)为参数的入口函数。通过NativeChildProcess_Args传入entryParams字符串和fd列表，入口函数返回后子进程自动退出。


1. 添加动态库文件和头文件引用。

    在CMakeLists.txt文件中添加动态库文件。

    ```txt
    libchild_process.so
    ```

    在源文件中引入头文件。

    <!-- @[create_native_child_param_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/ChildProcessFunc.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    ```

2. 在子进程中实现必要的导出方法。

    在子进程中，实现参数为[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)的入口函数并导出（假设代码所在的文件名为ChildProcessSample.cpp）。子进程启动后会调用该入口函数，该函数返回后子进程随即退出。

    <!-- @[child_process_necessary_export_impl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/ChildProcessFunc.cpp) --> 
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    extern "C" {
    /**
     * 子进程的入口函数，实现子进程的业务逻辑
     * 函数名称可以自定义，在主进程调用OH_Ability_StartNativeChildProcessWithConfigs方法时指定，此示例中为Main
     * 函数返回后子进程退出
     */
    void Main(NativeChildProcess_Args args)
    {
        // 获取传入的entryParams
        char *entryParams = args.entryParams;
        // 获取传入的fd列表
        NativeChildProcess_Fd *current = args.fdList.head;
        while (current != nullptr) {
            char *fdName = current->fdName;
            int32_t fd = current->fd;
            current = current->next;
            // 实现业务逻辑
        }
    }
    } // extern "C"
    ```


3. 编译动态链接库。

    修改CMakeLists.txt文件，编译为动态链接库（假设需要编译出的库文件名称为libchildprocesssample.so），并添加元能力动态库依赖。

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

4. 在主进程中启动Native子进程。

    调用[OH_Ability_StartNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs)接口启动Native子进程，可通过[OH_Ability_CreateChildProcessConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createchildprocessconfigs)创建子进程配置信息对象，并按需设置进程名、隔离模式和uid隔离等。返回值为NCP_NO_ERROR代表成功启动native子进程。

    <!-- @[main_process_launch_native_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/MainProcessFunc.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    #include <cstdlib>
    #include <cstring>
    #include <fcntl.h>
    // ...
    int32_t g_fdNameMaxLength = 20;
    
    void StartNativeChildProcess()
    {
        NativeChildProcess_Args args;
        // 设置entryParams
        const size_t entryParamsSize = 10;
        args.entryParams = (char *)malloc(sizeof(char) * entryParamsSize);
        if (args.entryParams != nullptr) {
            (void)strlcpy(args.entryParams, "testParam", entryParamsSize);
        }
    
        // 插入节点到链表头节点中
        args.fdList.head = (NativeChildProcess_Fd *)malloc(sizeof(NativeChildProcess_Fd));
        // fd关键字，最多不超过20个字符
        args.fdList.head->fdName = (char *)malloc(sizeof(char) * g_fdNameMaxLength);
        if (args.fdList.head->fdName != nullptr) {
            (void)strlcpy(args.fdList.head->fdName, "fd1", g_fdNameMaxLength);
        }
        // 获取fd逻辑
        int32_t fd = open("/data/storage/el2/base/haps/entry/files/test.txt", O_RDWR | O_CREAT, 0644);
        args.fdList.head->fd = fd;
        // 此处只插入一个fd记录，根据需求可以插入更多fd记录到链表中，最多不超过16个
        args.fdList.head->next = NULL;
        // 创建子进程配置信息对象
        Ability_ChildProcessConfigs *configs = OH_Ability_CreateChildProcessConfigs();
        // 设置子进程的进程名
        OH_Ability_ChildProcessConfigs_SetProcessName(configs, "child");

        // 第一个参数"libchildprocesssample.so:Main"为实现了子进程Main方法的动态库文件名称和入口方法名
        int32_t pid = -1;
        Ability_NativeChildProcess_ErrCode ret =
            OH_Ability_StartNativeChildProcessWithConfigs("libchildprocesssample.so:Main", args, configs, &pid);
        // configs对象使用完毕后需要销毁，避免内存泄漏
        OH_Ability_DestroyChildProcessConfigs(configs);
        if (ret != NCP_NO_ERROR) {
            // 释放NativeChildProcess_Args中的内存空间防止内存泄漏
            // 子进程未能正常启动时的异常处理
            // ...
        }
        // ...
        // 释放NativeChildProcess_Args中的内存空间防止内存泄漏
    }
    ```

5. 为主进程添加编译依赖项。

    修改CMakeLists.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so
        
        # 其它依赖的动态库
        # ...
    )
    ```

## 子进程获取启动参数

从API version 17开始，支持子进程获取启动参数。

1. 添加动态库文件和头文件引用。

    在CMakeLists.txt文件中添加动态库文件。

    ```txt
    libchild_process.so
    ```

    在源文件中引入头文件。

    <!-- @[child_get_start_params_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/ChildGetStartParams.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    ```

2. 在子进程中获取启动参数。

    [OH_Ability_StartNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs)创建子进程后，子进程内的任意so和任意子线程可以通过调用[OH_Ability_GetCurrentChildProcessArgs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_getcurrentchildprocessargs)()获取到子进程的启动参数[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)，便于操作相关的文件描述符。

    <!-- @[child_get_start_params_main](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/ChildGetStartParams.cpp) --> 
    
    ``` C++
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
        // 获取启动参数中的entryParams
        char *entryParams = args->entryParams;
        // 获取fd列表
        NativeChildProcess_Fd *current = args->fdList.head;
        while (current != nullptr) {
            char *fdName = current->fdName;
            int32_t fd = current->fd;
            current = current->next;
            // 实现业务逻辑
        }
    }
    
    /**
     * 子进程的入口函数，实现子进程的业务逻辑
     * args是子进程的启动参数
     */
    void Main(NativeChildProcess_Args args)
    {
        // 实现业务逻辑
    
        // 创建线程
        std::thread tObj(ThreadFunc);
    }
    
    } // extern "C"
    ```

## 终止子进程

从API version 22开始，支持根据传入的pid终止当前进程创建的[Native子进程](../application-models/ability-terminology.md#native子进程)或[ArkTS子进程](../application-models/ability-terminology.md#arkts子进程)。

1. 添加动态库文件和头文件引用。

    在CMakeLists.txt文件中添加动态库文件。

    ```txt
    libchild_process.so
    ```

    在源文件中引入头文件。

    <!-- @[kill_child_process_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/KillChildProcess/entry/src/main/cpp/MainProcessFile.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    ```

2. 实现终止子进程。

    通过[native_child_process](../reference/apis-ability-kit/capi-native-child-process-h.md)和[childProcessManager](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md)（非SELF_FORK模式）中的接口创建子进程后，主进程可以调用[OH_Ability_KillChildProcess](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_killchildprocess)(int32_t pid)根据传入的pid终止相应的子进程。

    <!-- @[kill_child_process_main](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/KillChildProcess/entry/src/main/cpp/MainProcessFile.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    // ...
    void KillChildProcess(int32_t pid)
    {
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_KillChildProcess(pid);
        if (ret != NCP_NO_ERROR) {
            // 子进程未成功杀死的异常处理
        }
        // ...
    }
    ```

## 获取Native子进程退出信息

从API version 20开始，支持父进程通过注册回调函数监听子进程，获取子进程异常退出信息，以便父进程做后续优化处理。这里支持监听的子进程必须为[OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess)、[OH_Ability_StartNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs)或[startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)接口创建的子进程。

1. 添加动态库文件和头文件引用。

    在CMakeLists.txt文件中添加动态库文件。

    ```txt
    libchild_process.so
    ```

    在源文件中引入头文件。

    <!-- @[native_child_process_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessExit/entry/src/main/cpp/MainProcessFile.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    ```

2. 注册和解注册Native子进程异常退出回调。

    调用[OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_registernativechildprocessexitcallback)注册Native子进程，如果返回值为NCP_NO_ERROR表示注册成功。

    调用[OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_unregisternativechildprocessexitcallback)解注册Native子进程，如果返回值为NCP_NO_ERROR表示解注册成功。

    <!-- @[register_native_child_process_exit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessExit/entry/src/main/cpp/MainProcessFile.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    #include <hilog/log.h>
    
    // ...
    
    void OnNativeChildProcessExit(int32_t pid, int32_t signal)
    {
        OH_LOG_INFO(LOG_APP, "pid: %{public}d, signal: %{public}d", pid, signal);
    }
    
    void RegisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret =
            OH_Ability_RegisterNativeChildProcessExitCallback(OnNativeChildProcessExit);
        if (ret != NCP_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "register failed.");
        }
        // ...
    }
    
    void UnregisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret =
            OH_Ability_UnregisterNativeChildProcessExitCallback(OnNativeChildProcessExit);
        if (ret != NCP_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "unregister failed.");
        }
        // ...
    }
    ```

3. 添加编译依赖项。

    修改CMakeLists.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so

        # 其它依赖的动态库
        # ...
    )
    ```
