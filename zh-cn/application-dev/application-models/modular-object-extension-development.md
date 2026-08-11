# 使用ModularObjectExtensionAbility实现模块化对象 (C/C++)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

从API版本26.0.0开始，系统提供ModularObjectExtensionAbility（相关C API定义见[modular_object_extension_ability.h](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md)）组件，支持应用将自身功能以模块化对象的形式开放给其他应用调用。本文将介绍如何实现ModularObjectExtensionAbility服务端和客户端。

> **说明**
>
> 有关模块化对象的介绍、基本概念和运行机制，请参考[模块化对象模型概述 (C/C++)](./modular-object-extension-overview.md)。

## 约束与限制

### 设备限制

ModularObjectExtensionAbility组件当前仅支持PC/2in1设备。

### 规格限制

- 客户端连接服务端时，客户端进程需要处于前台状态，服务端应用需要有正在运行的[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)或[UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)实例。
- 同一服务端应用下运行的Ability名称相同的ModularObjectExtensionAbility实例个数不能超过20个。
- 同一客户端进程，针对同一服务端应用下Ability名称相同的ModularObjectExtensionAbility，最多创建5个连接。
- 同一客户端应用，调用[OH_AbilityRuntime_ConnectModularObjectExtensionAbility](../reference/apis-ability-kit/capi-modular-object-extension-manager-h.md#oh_abilityruntime_connectmodularobjectextensionability)接口的频率不能超过20次每秒。

## ModularObjectExtensionAbility配置说明

ModularObjectExtensionAbility支持灵活的进程、线程模型以及其他属性配置，通过[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)中metadata设置。若metadata未配置或配置为无效值，则使用默认值。

| 名称 | 说明 | 可选值 | 默认值 |
| --- | --- | --- | --- |
| launchMode | 启动模式。决定了ModularObjectExtensionAbility是否允许跨进程启动。 | IN_PROCESS：表示ModularObjectExtensionAbility将在客户端进程中启动。此模式下，客户端与目标Ability必须属于同一应用。<br/>CROSS_PROCESS：表示ModularObjectExtensionAbility允许跨进程启动。 | IN_PROCESS |
| processMode | 进程模式。决定了多个ModularObjectExtensionAbility实例之间的进程共享策略，仅在launchMode配置为CROSS_PROCESS时生效。 | BUNDLE：表示同一应用下的所有ModularObjectExtensionAbility实例共享一个进程。<br/>TYPE：表示Ability名称相同的ModularObjectExtensionAbility实例共享一个进程。<br/>INSTANCE：表示每个ModularObjectExtensionAbility实例独占一个进程。 | BUNDLE |
| threadMode | 线程模式。决定了IPC请求的执行线程。<br/>**说明：**<br/>需要使用[OH_AbilityRuntime_ModObjExtensionContext_CreateIPCRemoteStub](../reference/apis-ability-kit/capi-modular-object-extension-context-h.md#oh_abilityruntime_modobjextensioncontext_createipcremotestub)接口创建[OHIPCRemoteStub](../reference/apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md)，threadMode才能生效，否则IPC请求将在IPC工作线程池中执行。详见[实现ModularObjectExtensionAbility服务端](#实现modularobjectextensionability服务端)中实现IPC Stub部分。 | BUNDLE：表示同一应用下的所有ModularObjectExtensionAbility实例共享一个线程。<br/>TYPE：表示Ability名称相同的ModularObjectExtensionAbility实例共享一个线程。<br/>INSTANCE：表示每个ModularObjectExtensionAbility实例独占一个线程。 | BUNDLE |
| isDisabled | 是否禁用该ExtensionAbility。 | true：禁用，只允许本应用连接该ExtensionAbility。<br/>false：不禁用，允许其他应用连接该ExtensionAbility。 | false |

## 实现ModularObjectExtensionAbility服务端

在DevEco Studio工程中新建一个ModularObjectExtensionAbility组件，具体步骤如下：

1. 在工程Module对应的main目录下，右键选择"New > Directory"，新建一个名为cpp的目录。后续将在cpp目录中创建以下文件：

    ```text
    ├── entry/src/main/cpp/
    │   ├── CMakeLists.txt
    │   ├── icalculator.h          # IPC 接口定义
    │   ├── calculator_stub.h       # IPC Stub头文件
    │   ├── calculator_stub.cpp     # IPC Stub实现
    │   └── moe_ability.cpp         # ModularObjectExtensionAbility Native实现，生命周期注册
    ```

2. 在cpp目录下创建CMakeLists.txt文件，配置编译选项、源文件和依赖库。

    ```cmake
    cmake_minimum_required(VERSION 3.5.0)
    project(ModularObjectExtensionService)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)

    add_library(entry SHARED
        moe_ability.cpp
        calculator_stub.cpp
    )
    target_link_libraries(entry PUBLIC
        libhilog_ndk.z.so
        libability_runtime.so
        libability_base_want.so
        libipc_capi.so
    )
    ```

3. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册ModularObjectExtensionAbility，type标签需要设置为"modularObject"，srcEntry标签设置为CMakeLists.txt中配置的编译后的so库名称。

    ```json5
    {
      "module": {
        // ...
        "extensionAbilities": [
          {
            "name": "SampleModularObjectExtAbility",
            "srcEntry": "libentry.so",
            "type": "modularObject",
            "exported": true,
            "metadata": [
              {
                "name": "launchMode",
                "value": "CROSS_PROCESS"
              },
              {
                "name": "processMode",
                "value": "BUNDLE"
              },
              {
                "name": "threadMode",
                "value": "BUNDLE"
              },
              {
                "name": "isDisabled",
                "value": "false"
              }
            ]
          }
        ]
      }
    }
    ```

4. 实现IPC Stub。在cpp目录下分别创建icalculator.h、calculator_stub.h和calculator_stub.cpp文件，以下以实现一个计算器接口（Add方法）为例说明。推荐使用Taihe编译器工具生成，请参考[使用Taihe实现ModularObjectExtensionAbility的IPC通信 (C/C++)](./modular-object-extension-ability-taihe.md)。

    icalculator.h定义了接口类ICalculator，包含接口描述符、命令码和方法业务声明。服务端和客户端都需要包含此头文件。

    <!-- @[modular_object_extension_icalculator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionService/entry/src/main/cpp/icalculator.h) -->
    
    ``` C
    class ICalculator {
    public:
        virtual ~ICalculator() = default;
        static const char* GetDescriptor() { return "com.samples.modularobjectextensionservice.ICalculator"; }
    
        enum class IpcCode : uint32_t {
            COMMAND_ADD = 1001,
        };
    
        virtual ErrCode Add(int32_t a, int32_t b, int32_t& result) = 0;
    };
    // ...
    ```

    calculator_stub.h和calculator_stub.cpp继承ICalculator接口，负责创建OHIPCRemoteStub，并处理客户端发送的IPC请求。

    <!-- @[modular_object_extension_stub_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionService/entry/src/main/cpp/calculator_stub.h) -->
    
    ``` C
    class CalculatorStub : public ICalculator {
    public:
        explicit CalculatorStub(OH_AbilityRuntime_ModObjExtensionContextHandle context);
        ~CalculatorStub() override;
    
        OHIPCRemoteStub *GetRemoteStub() const { return remoteStub_; }
    
        static int32_t OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData);
    
        ErrCode Add(int32_t a, int32_t b, int32_t &result) override;
    
    private:
        int32_t HandleAdd(const OHIPCParcel *data, OHIPCParcel *reply);
    
    private:
        OHIPCRemoteStub *remoteStub_ = nullptr;
        OH_AbilityRuntime_ModObjExtensionContextHandle context_ = nullptr;
    };
    // ...
    ```

    <!-- @[modular_object_extension_stub_impl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionService/entry/src/main/cpp/calculator_stub.cpp) -->
    
    ``` C++
    #include "calculator_stub.h"
    // ...
    
    CalculatorStub::CalculatorStub(OH_AbilityRuntime_ModObjExtensionContextHandle context)
        : context_(context), remoteStub_(OH_AbilityRuntime_ModObjExtensionContext_CreateIPCRemoteStub(
            context, ICalculator::GetDescriptor(), &CalculatorStub::OnRemoteRequest, nullptr, this)) {}
    
    CalculatorStub::~CalculatorStub()
    {
        if (remoteStub_ != nullptr) {
            OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub(context_, remoteStub_);
            remoteStub_ = nullptr;
        }
    }
    
    int32_t CalculatorStub::OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
    {
        // ...
    
        // 分发请求
        switch (static_cast<ICalculator::IpcCode>(code)) {
            case ICalculator::IpcCode::COMMAND_ADD:
                return stub->HandleAdd(data, reply);
            default:
                return OH_IPC_CHECK_PARAM_ERROR;
        }
    }
    
    int32_t CalculatorStub::HandleAdd(const OHIPCParcel *data, OHIPCParcel *reply)
    {
        // 读取入参
        int32_t a = 0;
        if (OH_IPCParcel_ReadInt32(data, &a) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_READ_ERROR;
        }
        int32_t b = 0;
        if (OH_IPCParcel_ReadInt32(data, &b) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_READ_ERROR;
        }
        int32_t result;
        // 调用业务函数
        ErrCode errCode = Add(a, b, result);
        // 写入errCode和result
        if (OH_IPCParcel_WriteInt32(reply, errCode) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_WRITE_ERROR;
        }
        if (OH_IPCParcel_WriteInt32(reply, result) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_WRITE_ERROR;
        }
    
        return OH_IPC_SUCCESS;
    }
    
    ErrCode CalculatorStub::Add(int32_t a, int32_t b, int32_t &result)
    {
        // 业务逻辑实现
        result = a + b;
        return OH_IPC_SUCCESS;
    }
    ```

5. 在cpp目录下创建moe_ability.cpp文件，实现[OH_AbilityRuntime_OnNativeExtensionCreate](../reference/apis-ability-kit/capi-extension-ability-h.md#oh_abilityruntime_onnativeextensioncreate)入口函数，在该函数中获取ModularObjectExtensionAbility实例并注册生命周期回调。在OnConnect回调中，创建CalculatorStub并返回[OHIPCRemoteStub](../reference/apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md)对象。

    <!-- @[modular_object_extension_moe_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionService/entry/src/main/cpp/moe_ability.cpp) -->
    
    ``` C++
    // ...
    
    #include "calculator_stub.h"
    // ...
    
    static std::map<OH_AbilityRuntime_ModObjExtensionInstanceHandle, OH_AbilityRuntime_ModObjExtensionContextHandle>
        g_contextMap;
    static std::map<OH_AbilityRuntime_ModObjExtensionInstanceHandle, CalculatorStub *> g_stubMap;
    
    static void OnCreate(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)
    {
        OH_LOG_INFO(LOG_APP, "OnCreate");
        // 获取context并保存
        OH_AbilityRuntime_ModObjExtensionContextHandle context = NULL;
        AbilityRuntime_ErrorCode err = OH_AbilityRuntime_ModObjExtensionAbility_GetContextFromInstance(instance, &context);
        if (context != NULL) {
            g_contextMap[instance] = context;
        }
    }
    
    static OHIPCRemoteStub *OnConnect(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)
    {
        OH_LOG_INFO(LOG_APP, "OnConnect");
        // 创建Stub并返回
        OH_AbilityRuntime_ModObjExtensionContextHandle context = g_contextMap.at(instance);
        if (context == nullptr) {
            return nullptr;
        }
        CalculatorStub *stub = new CalculatorStub(context);
        g_stubMap[instance] = stub;
        return stub->GetRemoteStub();
    }
    
    static void OnDisconnect(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)
    {
        OH_LOG_INFO(LOG_APP, "OnDisconnect");
        // 断连时清理Stub
        CalculatorStub *stub = g_stubMap.at(instance);
        if (stub != nullptr) {
            delete stub;
            g_stubMap.erase(instance);
        }
    }
    
    static void OnDestroy(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)
    {
        OH_LOG_INFO(LOG_APP, "OnDestroy");
        // 销毁时清理context
        g_contextMap.erase(instance);
    }
    
    EXTERN_C_START
    void OH_AbilityRuntime_OnNativeExtensionCreate(AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName)
    {
        // 获取实例
        OH_AbilityRuntime_ModObjExtensionInstanceHandle instance = NULL;
        AbilityRuntime_ErrorCode err = OH_AbilityRuntime_ModObjExtensionAbility_GetInstanceFromBase(handle, &instance);
        if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
            OH_LOG_ERROR(LOG_APP, "GetInstanceFromBase err:%{public}d", err);
            return;
        }
        // 注册回调函数
        OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnCreateFunc(instance, OnCreate);
        OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnConnectFunc(instance, OnConnect);
        OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDisconnectFunc(instance, OnDisconnect);
        OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDestroyFunc(instance, OnDestroy);
    }
    EXTERN_C_END
    ```

## 实现ModularObjectExtensionAbility客户端

介绍客户端应用如何连接ModularObjectExtensionAbility，并与服务端通信。客户端可通过Proxy对象进行静态调用，也可通过ModularObjectDispatcher进行动态调用。

### 连接ModularObjectExtensionAbility
<!-- @[modular_object_extension_connect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionClient/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static OHIPCRemoteProxy *g_remoteProxy = NULL;
static int64_t g_connectionId = -1;

static void OnConnectCallback(OH_AbilityRuntime_ConnectOptions *connectOptions, AbilityBase_Element *element,
                              OHIPCRemoteProxy *proxy)
{
    OH_LOG_INFO(LOG_APP, "OnConnectCallback");
    g_remoteProxy = proxy;
}

static void OnDisconnectCallback(OH_AbilityRuntime_ConnectOptions *connectOptions, AbilityBase_Element *element)
{
    OH_LOG_INFO(LOG_APP, "OnDisconnectCallback");
    g_remoteProxy = NULL;
}

static void OnFailedCallback(OH_AbilityRuntime_ConnectOptions *connectOptions, AbilityRuntime_ErrorCode code)
{
    OH_LOG_ERROR(LOG_APP, "OnFailedCallback, code: %{public}d", code);
}

static napi_value TestConnect(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "TestConnect");
    // 创建Want
    AbilityBase_Element element = {.bundleName = "com.samples.modularobjectextensionservice",
                                   .moduleName = "entry",
                                   .abilityName = "SampleModularObjectExtAbility"};
    AbilityBase_Want *want = OH_AbilityBase_CreateWant(element);
    if (want == NULL) {
        OH_LOG_ERROR(LOG_APP, "CreateWant failed");
        return nullptr;
    }

    // 创建ConnectOptions并注册回调
    OH_AbilityRuntime_ConnectOptions *options = OH_AbilityRuntime_CreateConnectOptions();
    OH_AbilityRuntime_ConnectOptions_SetOnConnectCallback(options, OnConnectCallback);
    OH_AbilityRuntime_ConnectOptions_SetOnDisconnectCallback(options, OnDisconnectCallback);
    OH_AbilityRuntime_ConnectOptions_SetOnFailedCallback(options, OnFailedCallback);

    // 发起连接
    int64_t connectionId = -1;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_ConnectModularObjectExtensionAbility(want, options, &connectionId);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "ConnectModularObjectExtensionAbility err:%{public}d", err);
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "ConnectModularObjectExtensionAbility id:%{public}ld", connectionId);
    // 保存连接ID,用于后续断开连接操作
    g_connectionId = connectionId;
    OH_AbilityBase_DestroyWant(want);
    return nullptr;
}
```

### 通过Proxy与服务端通信

1. 创建calculator_proxy.h和calculator_proxy.cpp文件，实现CalculatorProxy类。CalculatorProxy继承服务端提供的ICalculator接口，并封装OHIPCRemoteProxy。同时在Add方法中将参数序列化并通过OHIPCRemoteProxy发送给服务端，接收服务端返回的结果并反序列化。推荐使用Taihe编译器工具生成，请参考[使用Taihe实现ModularObjectExtensionAbility的IPC通信 (C/C++)](./modular-object-extension-ability-taihe.md)。

    <!-- @[modular_object_extension_proxy_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionClient/entry/src/main/cpp/calculator_proxy.h) -->
    
    ``` C
    class CalculatorProxy : public ICalculator {
    public:
        explicit CalculatorProxy(OHIPCRemoteProxy* remote) : remote_(remote) {}
        ~CalculatorProxy() override = default;
    
        OHIPCRemoteProxy* GetRemoteProxy() const
        {
            return remote_;
        }
    
        ErrCode Add(int32_t a, int32_t b, int32_t& result) override;
    
    private:
        OHIPCRemoteProxy* remote_ = nullptr;
    };
    // ...
    ```
    <!-- @[modular_object_extension_proxy_impl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionClient/entry/src/main/cpp/calculator_proxy.cpp) -->
    
    ``` C++
    #include "calculator_proxy.h"
    // ...
    
    ErrCode CalculatorProxy::Add(int32_t a, int32_t b, int32_t& result)
    {
        // ...
        // 写入参数
        if (OH_IPCParcel_WriteInt32(parcelData.get(), a) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_WRITE_ERROR;
        }
        if (OH_IPCParcel_WriteInt32(parcelData.get(), b) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_WRITE_ERROR;
        }
        // 发送请求，等待服务端返回结果
        OH_IPC_MessageOption option = { OH_IPC_REQUEST_MODE_SYNC, 0 };
        int32_t transportErr = OH_IPCRemoteProxy_SendRequest(
            remote_,
            static_cast<uint32_t>(ICalculator::IpcCode::COMMAND_ADD),
            parcelData.get(),
            parcelReply.get(),
            &option);
        if (transportErr != OH_IPC_SUCCESS) {
            return transportErr;
        }
    
        // 读取服务端返回的结果
        int32_t errCode = OH_IPC_SUCCESS;
        if (OH_IPCParcel_ReadInt32(parcelReply.get(), &errCode) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_READ_ERROR;
        }
    
        int32_t resultValue = 0;
        if (OH_IPCParcel_ReadInt32(parcelReply.get(), &resultValue) != OH_IPC_SUCCESS) {
            return OH_IPC_PARCEL_READ_ERROR;
        }
        result = resultValue;
    
        return errCode;
    }
    ```

2. 通过g_remoteProxy创建CalculatorProxy对象，并调用Add方法与服务端通信获取result。

    <!-- @[modular_object_extension_test_add](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionClient/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static OHIPCRemoteProxy *g_remoteProxy = NULL;
    // ...
    
    static napi_value TestAdd(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "TestAdd");
        if (g_remoteProxy == NULL) {
            OH_LOG_ERROR(LOG_APP, "Remote proxy is null, not connected");
            return nullptr;
        }
        CalculatorProxy proxy(g_remoteProxy);
        int32_t result = 0;
        ErrCode err = proxy.Add(10, 20, result);
        if (err != OH_IPC_SUCCESS) {
            OH_LOG_ERROR(LOG_APP, "CalculatorProxy::Add err:%{public}d", err);
            return nullptr;
        }
        OH_LOG_INFO(LOG_APP, "CalculatorProxy::Add(10, 20) result:%{public}d", result);
        return nullptr;
    }
    ```

### 通过ModularObjectDispatcher与服务端通信

除了上述基于Proxy的静态调用方式外，客户端还可以通过ModularObjectDispatcher实现动态调用。静态调用方式需要在编译期依赖服务端的接口定义，而动态调用方式允许客户端在运行时查询服务端的类型库元数据，并通过方法名发起调用，无需编译期绑定。

动态调用适用于运行时才能确定接口的场景，如通用脚本引擎、自动化测试框架和跨版本网关服务。完整开发流程请参考[使用ModularObjectDispatcher实现动态接口调用 (C/C++)](./modular-object-dispatcher-development.md)。

### 断连ModularObjectExtensionAbility

客户端通过[OH_AbilityRuntime_DisconnectModularObjectExtensionAbility](../reference/apis-ability-kit/capi-modular-object-extension-manager-h.md#oh_abilityruntime_disconnectmodularobjectextensionability)断开连接。断连成功后系统会触发[OH_AbilityRuntime_ConnectOptions_OnDisconnectCallback](../reference/apis-ability-kit/capi-connect-options-h.md#oh_abilityruntime_connectoptions_ondisconnectcallback)回调，在回调中清理保存的g_remoteProxy。
<!-- @[modular_object_extension_disconnect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionClient/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static OHIPCRemoteProxy *g_remoteProxy = NULL;
static int64_t g_connectionId = -1;

// ...

static void OnDisconnectCallback(OH_AbilityRuntime_ConnectOptions *connectOptions, AbilityBase_Element *element)
{
    OH_LOG_INFO(LOG_APP, "OnDisconnectCallback");
    g_remoteProxy = NULL;
}

// ...

static napi_value TestDisconnect(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "TestDisconnect");
    if (g_connectionId == -1) {
        OH_LOG_ERROR(LOG_APP, "Not connected");
        return nullptr;
    }
    AbilityRuntime_ErrorCode err =
        OH_AbilityRuntime_DisconnectModularObjectExtensionAbility(g_connectionId);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        OH_LOG_ERROR(LOG_APP, "DisconnectModularObjectExtensionAbility err:%{public}d", err);
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "DisconnectModularObjectExtensionAbility success");
    g_connectionId = -1;
    g_remoteProxy = NULL;
    return nullptr;
}
```
