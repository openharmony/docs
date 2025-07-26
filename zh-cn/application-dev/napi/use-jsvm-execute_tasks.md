# 使用JSVM-API接口进行任务队列相关开发

## 简介

在虚拟机内启动任务队列，检查队列中是否有待处理的微任务。任务队列可由外部事件循环执行。

## 基本概念

- **任务队列**：用于管理异步任务的调度和执行，确保任务按顺序处理。
- **微任务**：微任务是一种任务调度机制，主要用于处理那些需要尽快执行的较小任务，它们通常具有较高的优先级。

## 接口说明

| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_PumpMessageLoop| 启动任务队列的运行 |
|OH_JSVM_PerformMicrotaskCheckpoint| 执行任务队列里的微任务 |
| OH_JSVM_SetMicrotaskPolicy | 设置微任务执行策略 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++相关代码。
权限要求：Wasm字节码需要应用拥有JIT权限才能执行，可参考[JSVM 申请JIT权限指导](jsvm-apply-jit-profile.md)申请对应权限。
运行限制：当前 JSVM 版本在坚盾守护模式下将禁用 WebAssembly 全部功能模块。开发者需针对此限制进行应用兼容性评估，具体技术规范详见[JSVM 坚盾守护模式](jsvm-secure-shield-mode.md)。
### OH_JSVM_PumpMessageLoop && OH_JSVM_PerformMicrotaskCheckpoint

启动任务队列，执行任务。

cpp部分代码：

```cpp
#include <chrono>
#include <string.h>


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
    size_t logLength = 0;
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
    CHECK(OH_JSVM_CreateVM(&options, &vm));
    JSVM_VMScope vm_scope;
    CHECK(OH_JSVM_OpenVMScope(vm, &vm_scope));
    
    JSVM_Env env;
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
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
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_CloseVMScope(vm, vm_scope));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}

```
<!-- @[oh_jsvm_pump_message_loop_and_perform_microtask_checkpoint](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsOne/pumpmessageloop/src/main/cpp/hello.cpp) -->
预期输出结果：
```
JSVM API TEST: Called with instance [object Object]
JSVM API TEST: Called Finally
```
### OH_JSVM_SetMicrotaskPolicy
修改微任务执行策略，通过该接口，用户可以将策略设置为 JSVM_MicrotaskPolicy::JSVM_MICROTASK_EXPLICIT 或 JSVM_MicrotaskPolicy::JSVM_MICROTASK_AUTO。默认模式下，微任务的执行策略为 JSVM_MicrotaskPolicy::JSVM_MICROTASK_AUTO。

微任务策略：
- JSVM_MicrotaskPolicy::JSVM_MICROTASK_EXPLICIT ： 微任务在用户调用 OH_JSVM_PerformMicrotaskCheckpoint 后执行
- JSVM_MicrotaskPolicy::JSVM_MICROTASK_AUTO： 微任务在 JS 调用栈为空时自动执行

cpp 部分代码

```cpp
// OH_JSVM_SetMicrotaskPolicy的样例方法
static int SetMicrotaskPolicy(JSVM_VM vm, JSVM_Env env) {
    // 默认或将策略设置为 JSVM_MICROTASK_AUTO 的行为
    const char *scriptEvalMicrotask = R"JS(
        evaluateMicrotask = false;
        Promise.resolve().then(()=>{
            evaluateMicrotask = true;
        });
    )JS";
    JSVM_Script script;
    JSVM_Value jsSrc;
    JSVM_Value result;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, scriptEvalMicrotask, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));
    JSVM_Value global;
    CHECK_RET(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value hasEvaluateMicrotask;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "evaluateMicrotask", &hasEvaluateMicrotask));
    bool val = false;
    CHECK_RET(OH_JSVM_GetValueBool(env, hasEvaluateMicrotask, &val));

    OH_LOG_INFO(LOG_APP, "Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask : %{public}d", val);

    // 策略设置为 JSVM_MICROTASK_EXPLICIT 的行为
    CHECK_RET(OH_JSVM_SetMicrotaskPolicy(vm, JSVM_MicrotaskPolicy::JSVM_MICROTASK_EXPLICIT));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "evaluateMicrotask", &hasEvaluateMicrotask));
    CHECK_RET(OH_JSVM_GetValueBool(env, hasEvaluateMicrotask, &val));
    OH_LOG_INFO(
        LOG_APP,
        "Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask before calling OH_JSVM_PerformMicrotaskCheckpoint: %{public}d",
        val);

    CHECK_RET(OH_JSVM_PerformMicrotaskCheckpoint(vm));
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "evaluateMicrotask", &hasEvaluateMicrotask));
    CHECK_RET(OH_JSVM_GetValueBool(env, hasEvaluateMicrotask, &val));
    OH_LOG_INFO(
        LOG_APP,
        "Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask after calling OH_JSVM_PerformMicrotaskCheckpoint: %{public}d",
        val);

    return 0;
}

static void RunDemo(JSVM_VM vm, JSVM_Env env) {
    if (SetMicrotaskPolicy(vm, env) != 0) {
        OH_LOG_INFO(LOG_APP, "Run Microtask Policy failed");
    }
}

static int32_t TestJSVM() {
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
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // 创建JSVM环境
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, 0, nullptr, &env));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // 通过script调用测试函数
    RunDemo(vm, env);

    // 销毁JSVM环境
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```

预期输出结果：
```
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask : 1
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask before calling OH_JSVM_PerformMicrotaskCheckpoint: 0
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask after calling OH_JSVM_PerformMicrotaskCheckpoint: 1
```
