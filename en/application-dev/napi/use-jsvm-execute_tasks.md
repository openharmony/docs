# Working with Task Queues Using JSVM-API

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
## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for task queues.

### OH_JSVM_PumpMessageLoop and OH_JSVM_PerformMicrotaskCheckpoint

Use **OH_JSVM_PumpMessageLoop** to start running a task queue.

CPP code:

```cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <cassert>
#include <string.h>
#include "hilog/log.h"
#include "napi/native_api.h"
#include <unistd.h>
#undef  LOG_TAG
#define LOG_TAG "log"
#undef  LOG_DOMAIN
#define LOG_DOMAIN 0x1

// Global variable, which is used to ensure that the VM is initialized only once.
static int aa = 0;

// JS code to be executed.
static const char *STR_TASK = R"JS(
new Promise((resolve,reject) => {
    resolve(1)
})
.then(function(obj) {
    consoleinfo("Called with instance " + obj);
}).catch(function(err) {
    consoleinfo("Called with error ");
});
)JS";

// Ensure normal printing of the JS code information.
static JSVM_Value ConsoleInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t logLength;
    OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);

    OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &logLength);
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

// Start executing the tasks in the task queue.
static napi_value testHandleMicrotasks(napi_env env1, napi_callback_info info)
{
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    if (aa == 0) {
        OH_JSVM_Init(&init_options);
        aa++;
    }
    // Create a JSVM instance and open the VM scope.
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vm_scope;
    OH_JSVM_OpenVMScope(vm, &vm_scope);
    // Register the consoleinfo callback.
    JSVM_CallbackStruct param[] = {
        {.data = nullptr, .callback = ConsoleInfo},
    };
    JSVM_PropertyDescriptor descriptor[] = {
        {"consoleinfo", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
    };
    JSVM_Env env;
    OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    JSVM_HandleScope handlescope;
    OH_JSVM_OpenHandleScope(env, &handlescope);
    JSVM_Value sourcecodevalue;
    OH_JSVM_CreateStringUtf8(env, STR_TASK, strlen(STR_TASK), &sourcecodevalue);
    JSVM_Script script;
    OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
    JSVM_Value result;
    OH_JSVM_RunScript(env, script, &result);
    bool rst = false;
    for (int i = 0; i < 3; i++) { // 3: cycles
        // If no task is started in the message queue, set rst to false.
        JSVM_Status flag1 = OH_JSVM_PumpMessageLoop(vm, &rst);
        JSVM_Status flag2 = OH_JSVM_PerformMicrotaskCheckpoint(vm);
        if (rst && flag1 == JSVM_Status::JSVM_OK && flag2 == JSVM_Status::JSVM_OK) {
               sleep(3);
               break;
        }
    }
    // Close and destroy the environment and the VM.
    OH_JSVM_CloseHandleScope(env, handlescope);
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vm_scope);
    OH_JSVM_DestroyVM(vm);
    // Convert the return value of OH_JSVM_PumpMessageLoop to the Boolean type and output it.
    napi_value result11;
    napi_status status = napi_get_boolean(env1, rst, &result11);
    assert(status == napi_ok);
    return result11;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "HandleMicrotasks", nullptr, testHandleMicrotasks, nullptr, nullptr, nullptr, napi_default, nullptr }
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
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

@Entry
@Component
struct Index {
  @State message: string = 'Perform task';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let result = testNapi.HandleMicrotasks();
            console.info ("Whether the tasks in the queue are started: "+result);

          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
