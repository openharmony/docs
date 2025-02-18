# Working with Tasks Using JSVM-API

## Introduction

JSVM-API provides APIs for processing and dispatching the tasks that are queued up for execution. You can use the APIs to start the running of a task queue in a JSVM and check whether there are micro tasks waiting in the queue. The task queue can be executed cyclically by external events.

## Basic Concepts

- Task queue: a mechanism used to manage the scheduling and execution of asynchronous tasks to ensure that tasks are processed in sequence.
- Micro task: a small task that needs to be executed as soon as possible. Micro tasks usually have a higher priority.

## Available APIs

| API| Description|
| -------- | -------- |
|OH_JSVM_PumpMessageLoop| Starts running a task queue.|
|OH_JSVM_PerformMicrotaskCheckpoint| Executes micro tasks in a task queue.|
| OH_JSVM_SetMicrotaskPolicy | Sets the execution policy for micro tasks.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in task queue development.
> **NOTE**<br>To run the WebAssembly (Wasm) bytecode, the application must have the JIT permission. For details about how to apply for the permission, see [Requesting the JIT Permission](jsvm-apply-jit-profile.md).
### OH_JSVM_PumpMessageLoop and OH_JSVM_PerformMicrotaskCheckpoint

Call **OH_JSVM_PumpMessageLoop** to start running a task queue.

CPP code:

```cpp
#include <chrono>
#include <string.h>


// JS code to be executed.
static const char *STR_TASK = R"JS( 
    // Wasm bytecode (using the add module as an example)
    // The following is the text format of the Wasm bytecode corresponding to wasmBuffer, which contains only the add function.
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

// Ensure normal printing of the JS code information.
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

// Register the consoleinfo callback.
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
    // Create a JSVM instance and open the VM scope.
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
        // If no task is started in the task queue, set rst to false.
        CHECK_RET(OH_JSVM_PumpMessageLoop(vm, &rst)); 
        CHECK_RET(OH_JSVM_PerformMicrotaskCheckpoint(vm));
        // Exit at the scheduled time.
        auto now = std::chrono::system_clock::now();
        auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        if (cost > 100) {
            break;
        }
    }

    // Close and destroy the environment and the VM.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handlescope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_CloseVMScope(vm, vm_scope));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}

```
Expected result:
```
JSVM API TEST: Called with instance [object Object]
JSVM API TEST: Called Finally
```
### OH_JSVM_SetMicrotaskPolicy
Call **OH_JSVM_SetMicrotaskPolicy** to set the execution policy for micro tasks.  

The execution policy can be any of the following:
- **JSVM_MicrotaskPolicy::JSVM_MICROTASK_EXPLICIT**: executes micro tasks after **OH_JSVM_PerformMicrotaskCheckpoint** is called.
- **JSVM_MicrotaskPolicy::JSVM_MICROTASK_AUTO** (default): executes micro tasks automatically when the JS call stack is empty.

CPP code:

```
// Define OH_JSVM_SetMicrotaskPolicy.
static int SetMicrotaskPolicy(JSVM_VM vm, JSVM_Env env) {
    // Use the default policy or set the policy to JSVM_MICROTASK_AUTO.
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
    bool val;
    CHECK_RET(OH_JSVM_GetValueBool(env, hasEvaluateMicrotask, &val));

    OH_LOG_INFO(LOG_APP, "Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask : %{public}d", val);

    // Set the policy to JSVM_MICROTASK_EXPLICIT.
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
    // Initialize the JSVM instance.
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // Create a JSVM environment.
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, 0, nullptr, &env));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // Call the demo function using the script.
    RunDemo(vm, env);

    // Destroy the JSVM environment.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```

Expected result:
```
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask : 1
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask before calling OH_JSVM_PerformMicrotaskCheckpoint: 0
Policy :JSVM_MICROTASK_AUTO, evaluateMicrotask after calling OH_JSVM_PerformMicrotaskCheckpoint: 1
```
