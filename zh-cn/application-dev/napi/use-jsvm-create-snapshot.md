# 使用JSVM-API接口进行虚拟机快照相关开发
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

JavaScript虚拟机（JSVM）的快照创建功能，将当前运行时的JavaScript程序状态保存为一个快照文件，这个快照文件包含了当前的堆内存、执行上下文、函数闭包等信息。

## 基本概念

- **虚拟机启动快照**：虚拟机在某个特定时间点的状态快照，包含了当前虚拟机的所有内部状态和数据。通过创建一个启动快照，可以在之后的时间点恢复虚拟机到相同的状态。

创建和使用虚拟机启动快照可以简化一些复杂的编程任务，提高JSVM中虚拟机的管理和维护效率，增强程序的灵活性和稳定性。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|-------------------------------|
| OH_JSVM_CreateSnapshot     | 用于创建虚拟机的启动快照        |
|OH_JSVM_CreateEnvFromSnapshot| 基于虚拟机的起始快照，创建一个新的环境 |
## 使用示例

### OH_JSVM_CreateSnapshot & OH_JSVM_CreateEnvFromSnapshot

用于创建和使用虚拟机的启动快照。

cpp部分代码：

**注意事项**: 需要在OH_JSVM_Init的时候，将JSVM对外部的依赖注册到initOptions.externalReferences中。
```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <fstream>

#define LOG_DOMAIN 0x0202
#define LOG_TAG "TEST_TAG"

static int g_aa = 0;

#define CHECK_RET(theCall)                                                                           \
    do {                                                                                             \
        JSVM_Status cond = theCall;                                                                  \
        if ((cond) != JSVM_OK) {                                                                     \
            const JSVM_ExtendedErrorInfo *info;                                                      \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                    \
            OH_LOG_ERROR(LOG_APP,                                                                    \
                "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                __FILE__,                                                                            \
                __LINE__,                                                                            \
                cond,                                                                                \
                info != nullptr ? info->errorMessage : "");                                          \
            return -1;                                                                               \
        }                                                                                            \
    } while (0)

#define CHECK(theCall)                                                                                              \
    do {                                                                                                            \
        JSVM_Status cond = theCall;                                                                                 \
        if ((cond) != JSVM_OK) {                                                                                    \
            OH_LOG_ERROR(                                                                                           \
                LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d", __FILE__, __LINE__, cond); \
            return -1;                                                                                              \
        }                                                                                                           \
    } while (0)

// 用于调用theCall并检查其返回值是否为JSVM_OK。
// 如果不是，则调用GET_AND_THROW_LAST_ERROR处理错误并返回retVal。
#define JSVM_CALL_BASE(env, theCall, retVal)                                                         \
    do {                                                                                             \
        JSVM_Status cond = theCall;                                                                  \
        if (cond != JSVM_OK) {                                                                       \
            const JSVM_ExtendedErrorInfo *info;                                                      \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                    \
            OH_LOG_ERROR(LOG_APP,                                                                    \
                "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                __FILE__,                                                                            \
                __LINE__,                                                                            \
                cond,                                                                                \
                info != nullptr ? info->errorMessage : "");                                          \
            return retVal;                                                                           \
        }                                                                                            \
    } while (0)

// JSVM_CALL_BASE的简化版本，返回nullptr
#define JSVM_CALL(theCall) JSVM_CALL_BASE(env, theCall, nullptr)

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
static void CreateVMSnapshot()
{
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
    OH_JSVM_CreateSnapshot(vm, 1, envs, &blobData, &blobSize);
    // 将snapshot保存到文件中
    // 保存快照数据，/data/storage/el2/base/files/test_blob.bin为沙箱路径
    // 以包名为com.example.jsvm为例，实际文件会保存到/data/app/el2/100/base/com.example.jsvm/files/test_blob.bin
    std::ofstream file(
        "/data/storage/el2/base/files/test_blob.bin", std::ios::out | std::ios::binary | std::ios::trunc);
    file.write(blobData, blobSize);
    file.close();
    // 关闭并销毁环境和虚拟机
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
}

static void RunVMSnapshot()
{
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
    char str[MAX_BUFFER_SIZE];
    OH_JSVM_GetValueStringUtf8(env, result, str, MAX_BUFFER_SIZE, nullptr);
    if (strcmp(str, "Hello world!") != 0) {
        OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d", __FILE__, __LINE__);
    }
    // 关闭并销毁环境和虚拟机
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
    return;
}

static JSVM_Value AdjustExternalMemory(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 在创建虚拟机快照时，如果存在对外部的依赖，需要在OH_JSVM_Init时，将外部依赖注册到initOptions.externalReferences中
    // 创建虚拟机快照并将快照保存到文件中
    CreateVMSnapshot();
    // snapshot可以记录下特定的js执行环境，可以跨进程通过snapshot快速还原出js执行上下文环境
    RunVMSnapshot();
    JSVM_Value result = nullptr;
    OH_JSVM_CreateInt32(env, 0, &result);
    return result;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = AdjustExternalMemory},
};
static JSVM_CallbackStruct *method = param;
// AdjustExternalMemory方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"adjustExternalMemory", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试JS
const char *srcCallNative = R"JS(adjustExternalMemory();)JS";

static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;
    // 初始化JavaScript引擎实例
    if (g_aa == 0) {
        g_aa++;
        initOptions.externalReferences = externals;
        int argc = 0;
        char **argv = nullptr;
        initOptions.argc = &argc;
        initOptions.argv = argv;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // 创建JSVM环境
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // 通过script调用测试函数
    JSVM_Script script;
    JSVM_Value jsSrc;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // 销毁JSVM环境
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}

static napi_value RunTest(napi_env env, napi_callback_info info)
{
    TestJSVM();
    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    OH_LOG_INFO(LOG_APP, "JSVM Init");
    napi_property_descriptor desc[] = {
        {"runTest", nullptr, RunTest, nullptr, nullptr, nullptr, napi_default, nullptr},
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```
<!-- @[oh_jsvm_create_snapshot_and_create_env_from_snapshot](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsOne/createsnapshot/src/main/cpp/hello.cpp) -->

ArkTS侧示例代码：

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // runtest
            napitest.runTest();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
执行结果
在LOG中输出：
```ts
Test JSVM RunVMSnapshot read file blobSize = : 300064
```
多次点击屏幕,LOG中输出:
```ts
Test JSVM RunVMSnapshot read file blobSize = : 300176
Test JSVM RunVMSnapshot read file blobSize = : 300064
Test JSVM RunVMSnapshot read file blobSize = : 300160
Test JSVM RunVMSnapshot read file blobSize = : 300032
Test JSVM RunVMSnapshot read file blobSize = : 300176
Test JSVM RunVMSnapshot read file blobSize = : 300048
```
上述执行结果是因为在读取快照文件时，blobSize 的值来源于快照文件的大小（通过 file.tellg() 获取）。快照文件的大小直接决定了 blobSize 的值，所以会输出不同的值。
