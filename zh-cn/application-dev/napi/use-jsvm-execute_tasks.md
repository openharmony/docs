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

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_PumpMessageLoop && OH_JSVM_PerformMicrotaskCheckpoint

启动任务队列，执行任务。

cpp代码

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

//全局变量，保证虚拟机只初始化一次
static int aa = 0;

//待执行的js代码
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

//保证js代码中的打印信息可以正常输出
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

//启动任务队列里的任务并执行
static napi_value testHandleMicrotasks(napi_env env1, napi_callback_info info)
{
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    if (aa == 0) {
        OH_JSVM_Init(&init_options);
        aa++;
    }
    // 创建JavaScript虚拟机实例,打开虚拟机作用域
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vm_scope;
    OH_JSVM_OpenVMScope(vm, &vm_scope);
    // 注册consoleinfo的方法
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
        //如果消息队列中没有任务启动，则rst设置为false。
        JSVM_Status flag1 = OH_JSVM_PumpMessageLoop(vm, &rst);
        JSVM_Status flag2 = OH_JSVM_PerformMicrotaskCheckpoint(vm);
        if (rst && flag1 == JSVM_Status::JSVM_OK && flag2 == JSVM_Status::JSVM_OK) {
               sleep(3);
               break;
        }
    }
    // 关闭并销毁环境和虚拟机
    OH_JSVM_CloseHandleScope(env, handlescope);
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vm_scope);
    OH_JSVM_DestroyVM(vm);
    //将OH_JSVM_PumpMessageLoop执行后返回的结果转换为布尔类型输出
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

ArkTS侧示例代码

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
            console.info("任务队列是否启动任务："+result);

          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
