# IPC与RPC通信开发指导(C/C++)
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

## 场景介绍

IPC让运行在不同进程间的Proxy和Stub实现互相通信。IPC CAPI是IPC Kit提供的C语言接口。

IPC CAPI接口不直接提供获取通信代理对象的能力，该功能由[Ability Kit](../application-models/abilitykit-overview.md)提供。

![图](./figures/_i_p_c_architecture_diagram.png)

进程间IPC通道的建立，请参考[子进程开发指导（C/C++）](../application-models/capi-nativechildprocess-development-guideline.md)。本文重点介绍IPC CAPI的使用。

## 接口说明

**表1** IPC CAPI侧关键接口

| 接口名                               | 描述                                                             |
| ------------------------------------ | ---------------------------------------------------------------- |
|typedef int (\*OH_OnRemoteRequestCallback)<br>(uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply,<br> void \*userData);|Stub端用于处理远端数据请求的回调函数。|
| OHIPCRemoteStub\* OH_IPCRemoteStub_Create<br>(const char \*descriptor, OH_OnRemoteRequestCallback requestCallback,<br>OH_OnRemoteDestroyCallback destroyCallback, void \*userData); | 创建OHIPCRemoteStub对象。 |
|int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy \*proxy,<br> uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply,<br> const OH_IPC_MessageOption \*option);|IPC消息发送函数。|
|struct OHIPCRemoteProxy;|用于向远端发送请求的OHIPCRemoteProxy对象，需要依赖元能力接口返回。|
|OHIPCDeathRecipient\* OH_IPCDeathRecipient_Create<br>(OH_OnDeathRecipientCallback deathRecipientCallback,<br> OH_OnDeathRecipientDestroyCallback destroyCallback,<br>void \*userData);|创建用于监听远端OHIPCRemoteStub对象死亡的通知对象（OHIPCDeathRecipient对象）。|
|int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy \*proxy,<br>OHIPCDeathRecipient \*recipient);|向OHIPCRemoteProxy对象注册死亡监听，用于接收远端OHIPCRemoteStub对象死亡时的回调通知。|

详细的接口说明请参考[IPCKit](../reference/apis-ipc-kit/capi-ipckit.md)。

## 开发步骤

先创建服务端Stub对象，通过元能力获取其客户端代理Proxy对象，然后用Proxy对象与服务端Stub对象进行IPC通信，同时再注册远端对象的死亡通知回调，用于Proxy侧感知服务端Stub对象所在进程的死亡状态。

阅读以下示例时，可按照“子进程创建Stub对象、主进程启动子进程并获取Proxy对象、Proxy端发送请求、Stub端处理请求并返回结果”的顺序理解。Proxy端和Stub端需要使用相同的`code`定义和接口描述符。

**动态库文件**

CMakeLists.txt中添加以下lib。

```txt
# ipc capi
libipc_capi.so
# 元能力，ability capi
libchild_process.so
```

**头文件**

<!-- @[child_process_head_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/ChildProcessSample.cpp) -->

``` C++
#include <IPCKit/ipc_kit.h>
#include <AbilityKit/native_child_process.h>
```

**子进程实现**

子进程创建Stub对象，并通过`NativeChildProcess_OnConnect`返回该对象，用于接收主进程发送的IPC请求。以下代码中的`OnRemoteRequest`仅展示回调函数的基本形式，具体的请求处理过程参见后文“Stub侧实现”。

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

**主进程实现**

主进程调用`OH_Ability_CreateNativeChildProcess`启动子进程。子进程启动成功后，通过`OnNativeChildProcessStarted`回调获取与子进程Stub对象对应的`remoteProxy`，后续可基于该对象向子进程发送IPC请求。

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
    // 第一个参数"libchildprocesssample.so"为实现了子进程必要导出方法的动态库文件名称
    int32_t ret = OH_Ability_CreateNativeChildProcess("libchildprocesssample.so", OnNativeChildProcessStarted);
    if (ret != NCP_NO_ERROR) {
        // 子进程未能正常启动时的异常处理
        // ...
    }
    g_result = ret;
}
```

**Proxy侧实现**

Proxy端用于向远端Stub发送IPC请求。以下示例展示了创建`OHIPCParcel`对象、写入接口描述符和请求数据、调用`OH_IPCRemoteProxy_SendRequest`发送请求，以及从回应数据对象中读取处理结果的过程。不同操作通过不同的`code`值进行区分。

<!-- @[proxy_implement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/IpcProxy.cpp) -->

``` C++
#include "IpcProxy.h"
#include <IPCKit/ipc_error_code.h>
#include "Ipchelper.h"

IpcProxy::IpcProxy(OHIPCRemoteProxy *ipcProxy)
    : ipcProxy_(ipcProxy)
{
}

IpcProxy::~IpcProxy()
{
    if (ipcProxy_ != nullptr) {
        OH_IPCRemoteProxy_Destroy(ipcProxy_);
    }
}

bool IpcProxy::RequestExitChildProcess(int32_t exitCode)
{
    if (ipcProxy_ == nullptr) {
        return false;
    }
    
    StdUniPtrIpcParcel data(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    StdUniPtrIpcParcel reply(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    if (data == nullptr || reply == nullptr) {
        return false;
    }
    
    if (!WriteInterfaceToken(data.get()) ||
        OH_IPCParcel_WriteInt32(data.get(), exitCode) != OH_IPC_SUCCESS) {
        return false;
    }
    
    OH_IPC_MessageOption ipcOpt;
    ipcOpt.mode = OH_IPC_REQUEST_MODE_SYNC;
    ipcOpt.timeout = 0;
    ipcOpt.reserved = nullptr;
    int ret = OH_IPCRemoteProxy_SendRequest(ipcProxy_, IPC_ID_REQUEST_EXIT_PROCESS, data.get(), reply.get(), &ipcOpt);
    if (ret != OH_IPC_SUCCESS) {
        return false;
    }
    
    return true;
}

int32_t IpcProxy::Add(int32_t a, int32_t b)
{
    if (ipcProxy_ == nullptr) {
        return INT32_MIN;
    }
    
    int32_t result = INT32_MIN;
    StdUniPtrIpcParcel data(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    StdUniPtrIpcParcel reply(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    if (data == nullptr || reply == nullptr) {
        return result;
    }
    
    if (!WriteInterfaceToken(data.get()) ||
        OH_IPCParcel_WriteInt32(data.get(), a) != OH_IPC_SUCCESS ||
        OH_IPCParcel_WriteInt32(data.get(), b) != OH_IPC_SUCCESS) {
        return result;
    }
    
    OH_IPC_MessageOption ipcOpt;
    ipcOpt.mode = OH_IPC_REQUEST_MODE_SYNC;
    ipcOpt.timeout = 0;
    ipcOpt.reserved = nullptr;
    int ret = OH_IPCRemoteProxy_SendRequest(ipcProxy_, IPC_ID_ADD, data.get(), reply.get(), &ipcOpt);
    if (ret != OH_IPC_SUCCESS) {
        return result;
    }
    
    OH_IPCParcel_ReadInt32(reply.get(), &result);
    return result;
}

int32_t IpcProxy::StartNativeChildProcess()
{
    if (ipcProxy_ == nullptr) {
        return INT32_MIN;
    }
    
    int32_t result = INT32_MIN;
    StdUniPtrIpcParcel data(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    StdUniPtrIpcParcel reply(OH_IPCParcel_Create(), OH_IPCParcel_Destroy);
    if (data == nullptr || reply == nullptr) {
        return result;
    }
    
    if (!WriteInterfaceToken(data.get())) {
        return result;
    }
    
    OH_IPC_MessageOption ipcOpt;
    ipcOpt.mode = OH_IPC_REQUEST_MODE_SYNC;
    ipcOpt.timeout = 0;
    ipcOpt.reserved = nullptr;
    int ret = OH_IPCRemoteProxy_SendRequest(
        ipcProxy_, IPC_ID_START_NATIVE_CHILD_PROCESS, data.get(), reply.get(), &ipcOpt);
    if (ret != OH_IPC_SUCCESS) {
        return result;
    }
    
    OH_IPCParcel_ReadInt32(reply.get(), &result);
    return result;
}

bool IpcProxy::WriteInterfaceToken(OHIPCParcel* data)
{
    return OH_IPCParcel_WriteInterfaceToken(data, interfaceToken_) == OH_IPC_SUCCESS;
}
```

**Stub侧实现**

Stub端通过`OnRemoteRequest`接收Proxy端发送的请求。该回调先读取并校验接口描述符，再根据`code`调用对应的处理方法。处理方法从请求数据对象`data`中读取数据，并将处理结果写入回应数据对象`reply`，返回给Proxy端。

<!-- @[stub_implement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessIpc/entry/src/main/cpp/IpcStub.cpp) -->

``` C++
#include "IpcStub.h"
#include <IPCKit/ipc_error_code.h>
#include <cstring>
#include <new>

IpcStub::IpcStub()
{
    ipcStub_ = OH_IPCRemoteStub_Create("NativeChildIPCStubSample",
        IpcStub::OnRemoteRequest, IpcStub::OnRemoteObjectDestroy, this);
}

IpcStub::~IpcStub()
{
    OH_IPCRemoteStub_Destroy(ipcStub_);
}

OHIPCRemoteStub* IpcStub::GetIpcStub()
{
    return ipcStub_;
}

void IpcStub::OnRemoteObjectDestroy(void *userData)
{
}

int IpcStub::OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
{
    if (userData == nullptr) {
        return OH_IPC_CHECK_PARAM_ERROR;
    }
    
    if (!CheckInterfaceToken(data)) {
        return OH_IPC_CHECK_PARAM_ERROR;
    }
    
    int ret;
    IpcStub *thiz = reinterpret_cast<IpcStub*>(userData);
    switch (code) {
        case IPC_ID_REQUEST_EXIT_PROCESS:
            ret = thiz->HandleRequestExitChildProcess(data, reply);
            break;
        
        case IPC_ID_ADD:
            ret = thiz->HandleAdd(data, reply);
            break;
        
        case IPC_ID_START_NATIVE_CHILD_PROCESS:
            ret = thiz->HandleStartNativeChildProcess(data, reply);
            break;
        
        default:
            ret = OH_IPC_CODE_OUT_OF_RANGE;
            break;
    }
    
    return ret;
}

void* IpcStub::OnIpcMemAlloc(int32_t len)
{
    // limit ipc memory alloc size to 128 bytes
    if (len > 128) {
        return nullptr;
    }

    return new (std::nothrow) char[len];
}

void IpcStub::ReleaseIpcMem(void* ipcMem)
{
    delete[] reinterpret_cast<char*>(ipcMem);
}

bool IpcStub::CheckInterfaceToken(const OHIPCParcel* data)
{
    char *token;
    int32_t tokenLen;
    int ret = OH_IPCParcel_ReadInterfaceToken(data, &token, &tokenLen, IpcStub::OnIpcMemAlloc);
    if (ret != OH_IPC_SUCCESS) {
        return false;
    }
    
    bool tokenCheckRes = strcmp(token, interfaceToken_) == 0;
    ReleaseIpcMem(token);
    return tokenCheckRes;
}

int IpcStub::HandleRequestExitChildProcess(const OHIPCParcel *data, OHIPCParcel *reply)
{
    int exitCode = 0;
    if (OH_IPCParcel_ReadInt32(data, &exitCode) != OH_IPC_SUCCESS) {
        return OH_IPC_PARCEL_READ_ERROR;
    }
    int32_t ret = RequestExitChildProcess(exitCode) ? 1 : 0;
    return OH_IPCParcel_WriteInt32(reply, ret);
}

int32_t IpcStub::HandleAdd(const OHIPCParcel *data, OHIPCParcel *reply)
{
    int32_t a = 0;
    int32_t b = 0;
    if (OH_IPCParcel_ReadInt32(data, &a) != OH_IPC_SUCCESS ||
        OH_IPCParcel_ReadInt32(data, &b) != OH_IPC_SUCCESS) {
        return OH_IPC_PARCEL_READ_ERROR;
    }
    
    int32_t result = Add(a, b);
    if (OH_IPCParcel_WriteInt32(reply, result) != OH_IPC_SUCCESS) {
        return OH_IPC_PARCEL_WRITE_ERROR;
    }
    
    return OH_IPC_SUCCESS;
}

int IpcStub::HandleStartNativeChildProcess(const OHIPCParcel *data, OHIPCParcel *reply)
{
    int32_t ret = StartNativeChildProcess();
    return OH_IPCParcel_WriteInt32(reply, ret);
}
```