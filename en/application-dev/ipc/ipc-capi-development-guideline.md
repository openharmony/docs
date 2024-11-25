# IPC Development (C/C++)


## When to Use

Inter-Process Communication (IPC) allows the proxy and stub in different processes to communicate with each other using C/C++ APIs.
The IPC C APIs do not provide the cross-process communication capability. The IPC channel depends on [Ability Kit](../application-models/abilitykit-overview.md).

![](./figures/_i_p_c_architecture_diagram.png)

For details about how to set up an IPC channel, see [Native Child Process Development (C/C++)](../application-models/capi_nativechildprocess_development_guideline.md). This document focuses on the usage of IPC C APIs.

## Available APIs

**Table 1** IPC C APIs

| API                              | Description                                                            |
| ------------------------------------ | ---------------------------------------------------------------- |
|typedef int (\*OH_OnRemoteRequestCallback)<br>(uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply,<br> void \*userData);|Called to process the peer request at the stub.|
| OHIPCRemoteStub\* OH_IPCRemoteStub_Create<br>(const char \*descriptor, OH_OnRemoteRequestCallback requestCallback,<br>OH_OnRemoteDestroyCallback destroyCallback, void \*userData); | Creates an **OHIPCRemoteStub** object.|
|int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy \*proxy,<br> uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply,<br> const OH_IPC_MessageOption \*option);|Sends an IPC message.|
|struct OHIPCRemoteProxy;|Defines an **OHIPCRemoteProxy** object, which is used to send requests to the peer end.<br>The **OHIPCRemoteProxy** object is returned by an ability API. |
|OHIPCDeathRecipient\* OH_IPCDeathRecipient_Create<br>(OH_OnDeathRecipientCallback deathRecipientCallback,<br> OH_OnDeathRecipientDestroyCallback destroyCallback,<br>void \*userData);|Creates an **OHIPCDeathRecipient** object, which triggers a notification when the **OHIPCRemoteStub** object dies unexpectedly.|
|int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy \*proxy,<br>OHIPCDeathRecipient \*recipient);|Adds a recipient to the **OHIPCRemoteProxy** object to receive notifications of the death of the peer **OHIPCRemoteStub** object.|

For details about the APIs, see [IPC Kit](../reference/apis-ipc-kit/_i_p_c_kit.md).


## How to Develop

The following steps you through on how to use the C APIs provided by [IPC Kit](../reference/apis-ipc-kit/_i_p_c_kit.md) to create a remote stub, set up communication between the stub and a client proxy, and receive death notifications of the remote stub.

### 1. Adding Dynamic Link Libraries

Add the following libraries to **CMakeLists.txt**.

```txt
# ipc capi
libipc_capi.so
# Ability C/C++ APIs
libchild_process.so
```

### 2. Adding Header Files

```c++
// IPC C/C++ APIs
#include <IPCKit/ipc_kit.h>
// Ability C/C++ APIs
#include <AbilityKit/native_child_process.h>
```

### 3. Implementing IPC
#### Common Data and Functions

```c++
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <IPCKit/ipc_kit.h>
#include <AbilityKit/native_child_process.h>
#include <hilog/log.h>
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x0201
#define LOG_TAG "IPCCApiSample"

enum RequestCode {
    ASYNC_ADD_CODE = 1,
    REQUEST_EXIT_CODE = 2,
    OTHER_CODE
};
static constexpr int MAX_MEMORY_SIZE = 204800;
static const std::string INTERFACE_DESCRIPTOR = "INTERFACE_DESCRIPTOR";
static const std::string NATIVE_REMOTE_STUB_TEST_TOKEN = "native.remote.stub";
static const std::string NATIVE_REMOTE_STUB_ASYNC_CALL_TEST_TOKEN = "native.remote.stub.async.call";

// Define the memory allocation function.
static void* LocalMemoryAllocator(int32_t len) {
    if (len < 0 || len > MAX_MEMORY_SIZE ) {
        return nullptr;
    }
    void *buffer = malloc(len);
    if (buffer == nullptr) {
        return nullptr;
    }
    memset(buffer, 0, len);
    return buffer;
}
```
#### Server Object IpcCApiStubTest

```c++
class IpcCApiStubTest {
public:
    explicit IpcCApiStubTest();
    ~IpcCApiStubTest();
    void MainProc();
    OHIPCRemoteStub* GetRemoteStub();
    static int OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData);
private:
    int AsyncAdd(const OHIPCParcel *data);
    int RequestExitChildProcess();
private:
    OHIPCRemoteStub *stub_{ nullptr };
    std::mutex childMutex_;
    std::condition_variable childCondVar_;
};

IpcCApiStubTest::IpcCApiStubTest() {
    stub_ = OH_IPCRemoteStub_Create(INTERFACE_DESCRIPTOR.c_str(), &IpcCApiStubTest::OnRemoteRequest,
        nullptr, this);
}

IpcCApiStubTest::~IpcCApiStubTest() {
    if (stub_ != nullptr) {
        OH_IPCRemoteStub_Destroy(stub_);
    }
}

void IpcCApiStubTest::MainProc() {
    std::unique_lock<std::mutex> autoLock(childMutex_);
    childCondVar_.wait(autoLock);
}

OHIPCRemoteStub* IpcCApiStubTest::GetRemoteStub() {
    return stub_;
}

int IpcCApiStubTest::OnRemoteRequest(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData) {
    int readLen = 0;
    char *token = nullptr;
    // Interface verification
    if (OH_IPCParcel_ReadInterfaceToken(data, &token, &readLen, LocalMemoryAllocator) != OH_IPC_SUCCESS
        || NATIVE_REMOTE_STUB_TEST_TOKEN != token) {
        if (token != nullptr) {
            OH_LOG_ERROR(LOG_APP, "check InterfaceToken failed");
            free(token);
        }
        return OH_IPC_PARCEL_WRITE_ERROR;
    }
    free(token);
    auto *stubTest = reinterpret_cast<IpcCApiStubTest *>(userData);
    if (stubTest == nullptr) {
        return OH_IPC_CHECK_PARAM_ERROR;
    }
    auto rqCode = RequestCode(code);
    switch (rqCode) {
        case ASYNC_ADD_CODE: {
            return stubTest->AsyncAdd(data);
        }
        case REQUEST_EXIT_CODE: {
            return stubTest->RequestExitChildProcess();
        }
        default:
            break;
    }
    return OH_IPC_SUCCESS;
}

int IpcCApiStubTest::AsyncAdd(const OHIPCParcel *data) {
    int a = 0;
    int b = 0;
    OH_LOG_INFO(LOG_APP, "start async add a=%d,b=%d", a, b);
    if ((OH_IPCParcel_ReadInt32(data, &a) != OH_IPC_SUCCESS)
        || (OH_IPCParcel_ReadInt32(data, &b) != OH_IPC_SUCCESS)) {
        return OH_IPC_PARCEL_READ_ERROR;
    }
    auto proxyCallBack = OH_IPCParcel_ReadRemoteProxy(data);
    if (proxyCallBack == nullptr) {
        return OH_IPC_PARCEL_READ_ERROR;
    }
    OH_LOG_INFO(LOG_APP, "start create sendCallBack thread!");
    // Define asynchronous thread processing and use proxyCallBack to respond to asynchronous results. To implement synchronous calls, use replyData to write the response result.
    std::thread th([proxyCallBack, a, b] {
        auto data = OH_IPCParcel_Create();
        if (data == nullptr) {
            OH_IPCRemoteProxy_Destroy(proxyCallBack);
            return;
        }
        auto reply = OH_IPCParcel_Create();
        if (reply == nullptr) {
            OH_IPCParcel_Destroy(data);
            OH_IPCRemoteProxy_Destroy(proxyCallBack);
            return;
        }
        if (OH_IPCParcel_WriteInt32(data, a + b) != OH_IPC_SUCCESS) {
            OH_IPCParcel_Destroy(data);
            OH_IPCParcel_Destroy(reply);
            OH_IPCRemoteProxy_Destroy(proxyCallBack);
            return;
        }
        // The asynchronous thread processing result is returned to the service requester in IPC synchronous calls.
        OH_IPC_MessageOption option = { OH_IPC_REQUEST_MODE_SYNC, 0 };
        OH_LOG_INFO(LOG_APP, "thread start sendCallBack!");
        int ret = OH_IPCRemoteProxy_SendRequest(proxyCallBack, ASYNC_ADD_CODE, data, reply, &option);
        OH_LOG_INFO(LOG_APP, "thread sendCallBack ret = %d", ret);
        if (ret != OH_IPC_SUCCESS) {
            OH_IPCParcel_Destroy(data);
            OH_IPCParcel_Destroy(reply);
            OH_IPCRemoteProxy_Destroy(proxyCallBack);
            return;
        }
        OH_IPCRemoteProxy_Destroy(proxyCallBack);
        OH_IPCParcel_Destroy(data);
        OH_IPCParcel_Destroy(reply);
    });
    th.detach();
    return OH_IPC_SUCCESS;
}

int IpcCApiStubTest::RequestExitChildProcess() {
    std::unique_lock<std::mutex> autoLock(childMutex_);
    childCondVar_.notify_all();
    return OH_IPC_SUCCESS;
}
```

#### Proxy Object IpcCApiProxyTest

```cpp
// Customize error codes.
static constexpr int OH_IPC_CREATE_OBJECT_ERROR = OH_IPC_USER_ERROR_CODE_MIN + 1;

class IpcCApiProxyTest {
public:
    explicit IpcCApiProxyTest(OHIPCRemoteProxy *proxy);
    ~IpcCApiProxyTest();
public:
    int AsyncAdd(int a, int b, int &result);
    int RequestExitChildProcess();
    void ClearResource();
private:
    void SendAsyncReply(int &replyValue);
    int WaitForAsyncReply(int timeOut);
    static int OnRemoteRequest(uint32_t code, const OHIPCParcel *data,
        OHIPCParcel *reply, void *userData);
    static void OnDeathRecipientCB(void *userData);
private:
    int asyncReply_{};
    std::mutex mutex_;
    std::condition_variable cv_;
    OHIPCRemoteProxy *proxy_{ nullptr };
    OHIPCRemoteStub *replyStub_{ nullptr };
    OHIPCDeathRecipient *deathRecipient_{ nullptr };
};

IpcCApiProxyTest::IpcCApiProxyTest(OHIPCRemoteProxy *proxy) {
    if (proxy == nullptr) {
        OH_LOG_ERROR(LOG_APP, "proxy is nullptr");
        return;
    }
    proxy_ = proxy;
    replyStub_ = OH_IPCRemoteStub_Create(NATIVE_REMOTE_STUB_ASYNC_CALL_TEST_TOKEN.c_str(), OnRemoteRequest,
        nullptr, this);
    if (replyStub_ == nullptr) {
        OH_LOG_ERROR(LOG_APP, "crete reply stub failed!");
        return;
    }
    deathRecipient_ = OH_IPCDeathRecipient_Create(OnDeathRecipientCB, nullptr, this);
    if (deathRecipient_ == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_IPCDeathRecipient_Create failed!");
        return;
    }
    OH_IPCRemoteProxy_AddDeathRecipient(proxy_, deathRecipient_);
}

IpcCApiProxyTest::~IpcCApiProxyTest() {
    if (proxy_ != nullptr) {
        OH_IPCRemoteProxy_Destroy(proxy_);
    }
    if (deathRecipient_ != nullptr) {
        OH_IPCDeathRecipient_Destroy(deathRecipient_);
    }
    if (replyStub_ != nullptr) {
        OH_IPCRemoteStub_Destroy(replyStub_);
    }
}

int IpcCApiProxyTest::AsyncAdd(int a, int b, int &result) {
    OH_LOG_INFO(LOG_APP, "start %d + %d", a, b);
    auto data = OH_IPCParcel_Create();
    if (data == nullptr) {
        return OH_IPC_CREATE_OBJECT_ERROR;
    }
    // Write the interface token for verification.
    if (OH_IPCParcel_WriteInterfaceToken(data, NATIVE_REMOTE_STUB_TEST_TOKEN.c_str()) != OH_IPC_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_IPCParcel_WriteInterfaceToken failed!");
        OH_IPCParcel_Destroy(data);
        return OH_IPC_PARCEL_WRITE_ERROR;
    }
    if (OH_IPCParcel_WriteInt32(data, a) != OH_IPC_SUCCESS
        || OH_IPCParcel_WriteInt32(data, b) != OH_IPC_SUCCESS
        || OH_IPCParcel_WriteRemoteStub(data, replyStub_) != OH_IPC_SUCCESS) {
        OH_IPCParcel_Destroy(data);
        return OH_IPC_PARCEL_WRITE_ERROR;
    }
    // Use replyStub_ to receive responses in asynchronous transmission. In asynchronous processing, the OHIPCRemoteStub object for receiving the result needs to be written.
    OH_IPC_MessageOption option = { OH_IPC_REQUEST_MODE_ASYNC, 0 };
    int ret = OH_IPCRemoteProxy_SendRequest(proxy_, RequestCode::ASYNC_ADD_CODE, data, nullptr, &option);
    if (ret != OH_IPC_SUCCESS) {
        OH_IPCParcel_Destroy(data);
        OH_LOG_ERROR(LOG_APP, "OH_IPCRemoteProxy_SendRequest failed!");
        return ret;
    }
    static constexpr int TIMEOUT = 3;
    WaitForAsyncReply(TIMEOUT);
    OH_LOG_INFO(LOG_APP, "asyncReply_:%d", asyncReply_);
    result = asyncReply_;
    OH_IPCParcel_Destroy(data);
    OH_IPCParcel_Destroy(reply);
    return OH_IPC_SUCCESS;
}

int IpcCApiProxyTest::RequestExitChildProcess() {
    auto data = OH_IPCParcel_Create();
    if (data == nullptr) {
        return OH_IPC_CREATE_OBJECT_ERROR;
    }
    auto reply = OH_IPCParcel_Create();
    if (reply == nullptr) {
        OH_IPCParcel_Destroy(data);
        return OH_IPC_CREATE_OBJECT_ERROR;
    }
    if (OH_IPCParcel_WriteInterfaceToken(data, NATIVE_REMOTE_STUB_TEST_TOKEN.c_str()) != OH_IPC_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_IPCParcel_WriteInterfaceToken failed!");
        OH_IPCParcel_Destroy(data);
        OH_IPCParcel_Destroy(reply);
        return OH_IPC_PARCEL_WRITE_ERROR;
    }
    OH_IPC_MessageOption option = { OH_IPC_REQUEST_MODE_SYNC, 0 };
    int ret = OH_IPCRemoteProxy_SendRequest(proxy_, RequestCode::REQUEST_EXIT_CODE, data, reply, &option);
    if (ret != OH_IPC_SUCCESS) {
        OH_IPCParcel_Destroy(data);
        OH_IPCParcel_Destroy(reply);
        OH_LOG_ERROR(LOG_APP, "OH_IPCRemoteProxy_SendRequest failed!");
        return ret;
    }
    OH_IPCParcel_Destroy(data);
    OH_IPCParcel_Destroy(reply);
    return OH_IPC_SUCCESS;
}

void IpcCApiProxyTest::SendAsyncReply(int &replyValue) {
    std::unique_lock<std::mutex> lck(mutex_);
    asyncReply_ = replyValue;
    cv_.notify_all();
}

int IpcCApiProxyTest::WaitForAsyncReply(int timeOut) {
    asyncReply_ = 0;
    std::unique_lock<std::mutex> lck(mutex_);
    cv_.wait_for(lck, std::chrono::seconds(timeOut), [&] {
        return asyncReply_ != 0;
    });
    return asyncReply_;
}

int IpcCApiProxyTest::OnRemoteRequest(uint32_t code, const OHIPCParcel *data,
        OHIPCParcel *reply, void *userData) {
    OH_LOG_INFO(LOG_APP, "start %u", code);
    auto *proxyTest = reinterpret_cast<IpcCApiProxyTest *>(userData);
    if (proxyTest == nullptr || code != static_cast<uint32_t>(RequestCode::ASYNC_ADD_CODE)) {
        OH_LOG_ERROR(LOG_APP, "check param failed!");
        return OH_IPC_CHECK_PARAM_ERROR;
    }
    int32_t val = -1;
    if (OH_IPCParcel_ReadInt32(data, &val) != OH_IPC_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_IPCParcel_ReadInt32 failed!");
        return OH_IPC_PARCEL_READ_ERROR;
    }
    proxyTest->SendAsyncReply(val);
    return OH_IPC_SUCCESS;
}

void IpcCApiProxyTest::ClearResource() {
    // clear resource;
}

void IpcCApiProxyTest::OnDeathRecipientCB(void *userData) {
    auto *proxyTest = reinterpret_cast<IpcCApiProxyTest *>(userData);
    if (proxyTest != nullptr) {
        proxyTest->ClearResource();
    }
    OH_LOG_INFO(LOG_APP, "the stub is dead!");
}
```
#### libipcCapiDemo.so for Server Calls

```C++
IpcCApiStubTest g_ipcStubObj;

#ifdef __cplusplus
extern "C" {

// The following functions need to be implemented for the server. For details, see the Ability APIs.
OHIPCRemoteStub* NativeChildProcess_OnConnect() {
    OH_LOG_INFO(LOG_APP, "NativeChildProcess_OnConnect");
    return g_ipcStubObj.GetRemoteStub();
}

void NativeChildProcess_MainProc() {
    OH_LOG_INFO(LOG_APP, "NativeChildProcess_MainProc");
    g_ipcStubObj.MainProc();
    OH_LOG_INFO(LOG_APP, "NativeChildProcess_MainProc End");
}

}
#endif
```

#### Client Invocation Entry

```c++
IpcCApiProxyTest *g_ipcProxy = nullptr;

// Callback to be invoked when the IPC channel is set up via the ability.
void OnNativeChildProcessStarted(int errCode, OHIPCRemoteProxy *remoteProxy) {
    OH_LOG_INFO(LOG_APP, "OnNativeChildProcessStarted proxy=%{public}p err=%{public}d", remoteProxy, errCode);
    if (remoteProxy == nullptr) {
        return;
    }
    g_ipcProxy = new (std::nothrow) IpcCApiProxyTest(remoteProxy);
    if (g_ipcProxy == nullptr) {
        OH_IPCRemoteProxy_Destroy(remoteProxy);
        OH_LOG_ERROR(LOG_APP, "Alloc IpcCApiProxyTest object failed");
        return;
    }
}

int main(int argc, char *argv[]) {
    int32_t ret = OH_Ability_CreateNativeChildProcess("libipcCapiDemo.so", OnNativeChildProcessStarted);
    if (ret != 0) {
        return -1;        
    }
    if (g_ipcProxy == nullptr) {
        return -1;        
    }
    int a = 2;
    int b = 3;
    int result = 0;    
    ret = g_ipcProxy->AsyncAdd(a, b, result);
    OH_LOG_INFO(LOG_APP, "AsyncAdd: %d + %d = %d, ret=%d", a, b, result, ret);

    // kill the stub.
    ret = g_ipcProxy->RequestExitChildProcess();
    // Output on the console: the stub is dead!
    if (g_ipcProxy != nullptr) {
        delete g_ipcProxy;
        g_ipcProxy = nullptr;
    }
    return 0;
}
```
