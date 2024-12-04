# 使用JSVM-API接口进行任务队列相关开发

## 简介

在虚拟机内部启动任务队列的运行，检查是否有微任务在队列中等待，这个任务队列可以由外部事件循环执行。

## 基本概念

- **任务队列**：管理异步任务的调度和执行，确保任务按顺序处理。
- **微任务**：微任务是一种任务调度机制，主要用于处理那些需要尽快执行的较小任务，它们通常具有较高的优先级。

## 接口说明

| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_PumpMessageLoop| 启动任务队列的运行 |
|OH_JSVM_PerformMicrotaskCheckpoint| 执行任务队列里的微任务 |
## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_PumpMessageLoop && OH_JSVM_PerformMicrotaskCheckpoint

启动任务队列，执行任务。

cpp代码

```cpp
#include "ark_runtime/jsvm.h"
#include <cassert>
#include <string.h>
#include "hilog/log.h"
#include <unistd.h>
#undef  LOG_TAG
#define LOG_TAG "log"
#undef  LOG_DOMAIN
#define LOG_DOMAIN 0x1

// 待执行的js代码
static const char *STR_TASK = R"JS( 
    // wasm 字节码 (以add 模块为例)
    // 以下 wasmBuffer 对应的 wasm 字节码文本格式如下所示，只包含了一个函数 add
    // (module
    //   (func $add (param $lhs i32) (param $rhs i32) (result i32)
    //     local.get $lhs
    //     local.get $rhs
    //     i32.add
    //   )
    //   (export "add" (func $add))
    // )
    var wasmBytes = new Uint8Array([0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x07, 0x01,
                                       0x60, 0x02, 0x7f, 0x7f, 0x01, 0x7f, 0x03, 0x02, 0x01, 0x00, 0x07,
                                       0x07, 0x01, 0x03, 0x61, 0x64, 0x64, 0x00, 0x00, 0x0a, 0x09, 0x01,
                                       0x07, 0x00, 0x20, 0x00, 0x20, 0x01, 0x6a, 0x0b]);    

    var p = WebAssembly.instantiate(wasmBytes, {});
    p.then((result) => {
        consoleinfo("Called with instance " + result);
    });
    p.finally(() => {
       consoleinfo("Called Finally");
    });
)JS";

// 保证js代码中的打印信息可以正常输出
static JSVM_Value ConsoleInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t logLength;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &logLength);
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

// 注册consoleinfo的方法
JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ConsoleInfo},
};
JSVM_PropertyDescriptor descriptor[] = {
    {"consoleinfo", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
};

static int32_t TestJSVM() {
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    if (g_aa == 0) {
        OH_JSVM_Init(&init_options);
        g_aa++;
    }
    // 创建JavaScript虚拟机实例,打开虚拟机作用域
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    CHECK(OH_JSVM_CreateVM(&options, &vm) == JSVM_OK);
    JSVM_VMScope vm_scope;
    CHECK(OH_JSVM_OpenVMScope(vm, &vm_scope) == JSVM_OK);
    
    JSVM_Env env;
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env) == JSVM_OK);
    JSVM_EnvScope envScope;
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    JSVM_HandleScope handlescope;
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handlescope));
    JSVM_Value sourcecodevalue;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, STR_TASK, strlen(STR_TASK), &sourcecodevalue));
    JSVM_Script script;
    CHECK_RET(OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script));
    JSVM_Value result;
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));
    bool rst = false;
    auto start = std::chrono::system_clock::now();
    while (true) {
        // 如果任务队列中没有任务启动，则rst设置为false
        CHECK_RET(OH_JSVM_PumpMessageLoop(vm, &rst)); 
        CHECK_RET(OH_JSVM_PerformMicrotaskCheckpoint(vm));
        // 定时退出
        auto now = std::chrono::system_clock::now();
        auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        if (cost > 100) {
            break;
        }
    }

    // 关闭并销毁环境和虚拟机
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handlescope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_DestroyEnv(env) == JSVM_OK);
    CHECK(OH_JSVM_CloseVMScope(vm, vm_scope) == JSVM_OK);
    CHECK(OH_JSVM_DestroyVM(vm) == JSVM_OK);
    return 0;
}

```
