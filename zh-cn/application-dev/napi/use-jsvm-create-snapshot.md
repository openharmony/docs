# 使用JSVM-API接口进行虚拟机快照相关开发

## 简介

JavaScript虚拟机（JSVM）的快照创建功能，将当前运行时的JavaScript程序状态保存为一个快照文件，这个快照文件包含了当前的堆内存、执行上下文、函数闭包等信息。

## 基本概念

- **虚拟机启动快照**：虚拟机在某个特定时间点的状态快照，包含了当前虚拟机的所有内部状态和数据。通过创建一个启动快照，可以在之后的时间点恢复虚拟机到相同的状态。

创建虚拟机启动快照可以简化一些复杂的编程任务，使得在JSVM中管理和维护虚拟机更加便捷，使程序更加灵活与稳定。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|-------------------------------|
| OH_JSVM_CreateSnapshot     | 用于创建虚拟机的启动快照        |
|OH_JSVM_CreateEnvFromSnapshot| 基于虚拟机的起始快照，创建一个新的环境 |
## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_CreateSnapshot

用于创建和使用虚拟机的启动快照。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <fstream>

// CreateAndUseSnapshot注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateAndUseSnapshot},
};
static JSVM_CallbackStruct *method = param;
// CreateAndUseSnapshot方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createAndUseSnapshot", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

static const int MAX_BUFFER_SIZE = 128;
// CreateHelloString()函数需绑定到JSVM虚拟机, 用于OH_JSVM_CreateSnapshot虚拟机快照的正常创建
static JSVM_Value CreateHelloString(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value outPut;
    OH_JSVM_CreateStringUtf8(env, "Hello world!", JSVM_AUTO_LENGTH, &outPut);
    return outPut;
}
// 提供外部引用的方式以便JavaScript环境可以调用绑定的函数
static JSVM_CallbackStruct helloCb = {CreateHelloString, nullptr};
// 外部引用
static intptr_t externals[] = {
    (intptr_t)&helloCb,
    0,
};

static JSVM_Value RunVMScript(JSVM_Env env, std::string &src)
{
    // 打开handleScope作用域
    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    JSVM_Value jsStr = nullptr;
    OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsStr);
    // 编译JavaScript代码
    JSVM_Script script;
    OH_JSVM_CompileScript(env, jsStr, nullptr, 0, true, nullptr, &script);
    // 执行JavaScript代码
    JSVM_Value result = nullptr;
    OH_JSVM_RunScript(env, script, &result);
    // 关闭handleScope作用域
    OH_JSVM_CloseHandleScope(env, handleScope);
    return result;
}
// OH_JSVM_CreateSnapshot的样例方法
static void CreateVMSnapshot() {
    // 创建JavaScript虚拟机实例,打开虚拟机作用域
    JSVM_VM vm;
    JSVM_CreateVMOptions vmOptions;
    memset(&vmOptions, 0, sizeof(vmOptions));
    // isForSnapshotting设置该虚拟机是否用于创建快照
    vmOptions.isForSnapshotting = true;
    OH_JSVM_CreateVM(&vmOptions, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);
    // 创建JavaScript环境,打开环境作用域
    JSVM_Env env;
    // 将native函数注册成JavaScript可调用的方法
    JSVM_PropertyDescriptor descriptor[] = {
        {"createHelloString", nullptr, &helloCb, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    };
    OH_JSVM_CreateEnv(vm, 1, descriptor, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // 使用OH_JSVM_CreateSnapshot创建虚拟机的启动快照
    const char *blobData = nullptr;
    size_t blobSize = 0;
    JSVM_Env envs[1] = {env};
    JSVM_Status status = OH_JSVM_CreateSnapshot(vm, 1, envs, &blobData, &blobSize);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_CreateSnapshot success, blobSize = : %{public}ld", blobSize);
    }
    // 将snapshot保存到文件中
    // 保存快照数据，/data/storage/el2/base/files/test_blob.bin为沙箱路径
    // 以包名为com.example.jsvm为例，实际文件会保存到/data/app/el2/100/base/com.example.jsvm/files/test_blob.bin
    std::ofstream file("/data/storage/el2/base/files/test_blob.bin",
                       std::ios::out | std::ios::binary | std::ios::trunc);
    file.write(blobData, blobSize);
    file.close();
    // 关闭并销毁环境和虚拟机
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
}
static void RunVMSnapshot() {
    // blobData的生命周期不能短于vm的生命周期
    // 从文件中读取snapshot
    std::vector<char> blobData;
    std::ifstream file("/data/storage/el2/base/files/test_blob.bin", std::ios::in | std::ios::binary | std::ios::ate);
    size_t blobSize = file.tellg();
    blobData.resize(blobSize);
    file.seekg(0, std::ios::beg);
    file.read(blobData.data(), blobSize);
    file.close();
    OH_LOG_INFO(LOG_APP, "Test JSVM RunVMSnapshot read file blobSize = : %{public}ld", blobSize);
    // 使用快照数据创建虚拟机实例
    JSVM_VM vm;
    JSVM_CreateVMOptions vmOptions;
    memset(&vmOptions, 0, sizeof(vmOptions));
    vmOptions.snapshotBlobData = blobData.data();
    vmOptions.snapshotBlobSize = blobSize;
    OH_JSVM_CreateVM(&vmOptions, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);
    // 从快照中创建环境env
    JSVM_Env env;
    OH_JSVM_CreateEnvFromSnapshot(vm, 0, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // 执行js脚本，快照记录的env中定义了createHelloString()
    std::string src = "createHelloString()";
    JSVM_Value result = RunVMScript(env, src);
    // 环境关闭前检查脚本运行结果
    if (result == nullptr) {
        OH_JSVM_ThrowError(env, nullptr, "Test JSVM RunVMSnapshot-RunVMScript result is nullptr");
        return;
    }
    char str[MAX_BUFFER_SIZE];
    OH_JSVM_GetValueStringUtf8(env, result, str, MAX_BUFFER_SIZE, nullptr);
    OH_LOG_INFO(LOG_APP, "Test JSVM RunVMSnapshot-RunVMScript result is: %{public}s", str);
    // 关闭并销毁环境和虚拟机
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
    return;
}

static JSVM_Value CreateAndUseSnapshot(JSVM_Env env, JSVM_CallbackInfo info)
{
    // OH_JSVM_Init(&initOptions)需在开发流程中的RunJsVm()中第一次初始化（只能初始化一次）
    // JSVM_InitOptions initOptions 赋值是在开发流程中完成的
    // 创建虚拟机快照并将快照保存到文件中
    CreateVMSnapshot();
    // snapshot可以记录下特定的js执行环境，可以跨进程通过snapshot快速还原出js执行上下文环境
    RunVMSnapshot();
    JSVM_Value result = nullptr;
    OH_JSVM_CreateInt32(env, 0, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    createAndUseSnapshot()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createAndUseSnapshot: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createAndUseSnapshot error: %{public}s', error.message);
}
```
