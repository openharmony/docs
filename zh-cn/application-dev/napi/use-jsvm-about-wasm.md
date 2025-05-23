# 使用JSVM-API接口进行WebAssembly模块相关开发


## 简介

JSVM-API WebAssembly 接口提供了 WebAssembly 字节码编译、WebAssembly 函数优化、WebAssembly cache 序列化和反序列化的能力。
注意：WebAssembly相关接口需要应用拥有JIT权限才能执行，可参考[JSVM 申请JIT权限指导](jsvm-apply-jit-profile.md)申请对应权限。

## 基本概念

- **wasm module**：表示一个 WebAssembly 模块，(WebAssembly 简称为wasm)，通过 `OH_JSVM_CompileWasmModule` 接口可以从 wasm 字节码或 wasm cache 创建 wasm module。通过 `OH_JSVM_IsWasmModuleObject` 接口可以判断一个 JSVM_Value 是否是一个 wasm module。
- **wasm function**：表示 wasm module 中定义的函数，wasm function 在导出后被外部代码使用。`OH_JSVM_CompileWasmFunction` 接口提供了将 wasm function 编译为优化后的机器码的能力，方便开发者对指定 wasm function 提前编译和函数粒度的并行编译。
- **wasm cache**：对 wasm module 中的机器码进行序列化，生成的数据被称为 wasm cache。wasm cache 的创建和释放接口分别为 `OH_JSVM_CreateWasmCache` 和 `OH_JSVM_ReleaseCache` (对应的 cacheType 为 `JSVM_CACHE_TYPE_WASM`)。

## 接口说明

| 接口                          | 功能说明                                                                                 |
| --------------------------- | ------------------------------------------------------------------------------------ |
| OH_JSVM_CompileWasmModule   | 将 wasm 字节码同步编译为 wasm module。如果提供了 cache 参数，先尝试将 cache 反序列为 wasm module，反序列化失败时再执行编译。 |
| OH_JSVM_CompileWasmFunction | 将 wasm module 中指定编号的函数编译为优化后的机器码，目前只使能了最高的优化等级，函数编号的合法性由接口调用者保证。                     |
| OH_JSVM_IsWasmModuleObject  | 判断传入的值是否是一个 wasm module。                                                             |
| OH_JSVM_CreateWasmCache     | 将 wasm module 中的机器码序列化为 wasm cache，如果 wasm module 不包含机器码，则会序列化失败。                    |
| OH_JSVM_ReleaseCache        | 释放由 JSVM 接口生成的 cache。传入的 cacheType 和 cacheData 必须匹配，否则会产生未定义行为。                      |

## code cache 校验规格说明
| 规格        | 规格说明                                         |
| ---------- | ------------------------------------------------ |
| 完整性校验  | 由用户保证                                        |
| 兼容性校验  | 校验生成 cache 的 JSVM 版本与编译选项是否与当前一致 |
| 一致性校验  | 由用户保证                                        |

## 使用示例

JSVM-API 接口开发流程参考 [使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应 C++ 相关代码进行展示。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <vector>

#ifndef CHECK_STATUS
#define CHECK_STATUS(cond)                           \
    do {                                             \
        if (!(cond)) {                               \
            OH_LOG_ERROR(LOG_APP, "CHECK FAILED");   \
        }                                            \
    } while (0)
#endif

// 判断一个 JSVM_Value 是否是 wasm module
static bool IsWasmModuleObject(JSVM_Env env, JSVM_Value value) {
    bool result;
    JSVM_Status status = OH_JSVM_IsWasmModuleObject(env, value, &result);
    CHECK_STATUS(status == JSVM_OK);
    return result;
}

// 由 C 字符串创建 JSVM string
static JSVM_Value CreateString(JSVM_Env env, const char *str) {
    JSVM_Value jsvmStr;
    JSVM_Status status = OH_JSVM_CreateStringUtf8(env, str, JSVM_AUTO_LENGTH, &jsvmStr);
    CHECK_STATUS(status == JSVM_OK);
    return jsvmStr;
}

// 由 C int32_t 创建 JSVM number
static JSVM_Value CreateInt32(JSVM_Env env, int32_t val) {
    JSVM_Value jsvmInt32;
    JSVM_Status status = OH_JSVM_CreateInt32(env, val, &jsvmInt32);
    CHECK_STATUS(status == JSVM_OK);
    return jsvmInt32;
}

// 对 wasm module 进行实例化
static JSVM_Value InstantiateWasmModule(JSVM_Env env, JSVM_Value wasmModule) {
    JSVM_Status status = JSVM_OK;
    JSVM_Value globalThis;
    status = OH_JSVM_GetGlobal(env, &globalThis);
    CHECK_STATUS(status == JSVM_OK);

    JSVM_Value webAssembly;
    status = OH_JSVM_GetProperty(env, globalThis, CreateString(env, "WebAssembly"), &webAssembly);
    CHECK_STATUS(status == JSVM_OK);

    JSVM_Value webAssemblyInstance;
    status = OH_JSVM_GetProperty(env, webAssembly, CreateString(env, "Instance"), &webAssemblyInstance);
    CHECK_STATUS(status == JSVM_OK);

    JSVM_Value instance;
    JSVM_Value argv[] = {wasmModule};
    status = OH_JSVM_NewInstance(env, webAssemblyInstance, 1, argv, &instance);
    CHECK_STATUS(status == JSVM_OK);
    return instance;
}

// 获取 wasm 字节码 (add 模块)
static std::vector<uint8_t> GetAddWasmBuffer() {
    // 以下 wasmBuffer 对应的 wasm 字节码文本格式如下所示，只包含了一个函数 add
    // (module
    //   (func $add (param $lhs i32) (param $rhs i32) (result i32)
    //     local.get $lhs
    //     local.get $rhs
    //     i32.add
    //   )
    //   (export "add" (func $add))
    // )
    std::vector<uint8_t> wasmBuffer = {0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x07, 0x01,
                                       0x60, 0x02, 0x7f, 0x7f, 0x01, 0x7f, 0x03, 0x02, 0x01, 0x00, 0x07,
                                       0x07, 0x01, 0x03, 0x61, 0x64, 0x64, 0x00, 0x00, 0x0a, 0x09, 0x01,
                                       0x07, 0x00, 0x20, 0x00, 0x20, 0x01, 0x6a, 0x0b};
    return wasmBuffer;
}

// 验证 wasm instance 功能 (add 模块)
static void VerifyAddWasmInstance(JSVM_Env env, JSVM_Value wasmInstance) {
    JSVM_Status status = JSVM_OK;
    // 从 wasm instance 获取 exports.add 函数
    JSVM_Value exports;
    status = OH_JSVM_GetProperty(env, wasmInstance, CreateString(env, "exports"), &exports);
    CHECK_STATUS(status == JSVM_OK);

    JSVM_Value add;
    status = OH_JSVM_GetProperty(env, exports, CreateString(env, "add"), &add);
    CHECK_STATUS(status == JSVM_OK);

    // 执行 exports.add(1, 2)，期望得到结果 3
    JSVM_Value undefined;
    OH_JSVM_GetUndefined(env, &undefined);
    JSVM_Value one = CreateInt32(env, 1);
    JSVM_Value two = CreateInt32(env, 2);
    JSVM_Value argv[] = {one, two};
    JSVM_Value result;
    status = OH_JSVM_CallFunction(env, undefined, add, 2, argv, &result);
    CHECK_STATUS(status == JSVM_OK);
    int32_t resultInt32;
    OH_JSVM_GetValueInt32(env, result, &resultInt32);
    CHECK_STATUS(resultInt32 == 3);
}

// WebAssembly demo 主函数
static JSVM_Value WasmDemo(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Status status = JSVM_OK;
    std::vector<uint8_t> wasmBuffer = GetAddWasmBuffer();
    uint8_t *wasmBytecode = wasmBuffer.data();
    size_t wasmBytecodeLength = wasmBuffer.size();
    JSVM_Value wasmModule;
    // 根据 wasm 字节码得到 wasm module
    status = OH_JSVM_CompileWasmModule(env, wasmBytecode, wasmBytecodeLength, NULL, 0, NULL, &wasmModule);
    CHECK_STATUS(status == JSVM_OK);
    CHECK_STATUS(IsWasmModuleObject(env, wasmModule));

    // 对当前 wasm module 中定义的第一个函数 (即 add) 执行编译优化
    int32_t functionIndex = 0;
    // 注意：当前只支持 high level optimization，即传入 JSVM_WASM_OPT_BASELINE 和传入 JSVM_WASM_OPT_HIGH 效果是一样的
    status = OH_JSVM_CompileWasmFunction(env, wasmModule, functionIndex, JSVM_WASM_OPT_HIGH);
    CHECK_STATUS(status == JSVM_OK);
    // 对编译得到的 wasm module 进行实例化
    JSVM_Value wasmInstance = InstantiateWasmModule(env, wasmModule);
    // 对实例化的 wasm instance 中的函数进行功能验证
    VerifyAddWasmInstance(env, wasmInstance);

    // 创建 wasm cache
    const uint8_t *wasmCacheData = NULL;
    size_t wasmCacheLength = 0;
    status = OH_JSVM_CreateWasmCache(env, wasmModule, &wasmCacheData, &wasmCacheLength);
    CHECK_STATUS(status == JSVM_OK);
    // 期望 wasm cache 创建成功
    CHECK_STATUS(wasmCacheData != NULL);
    CHECK_STATUS(wasmCacheLength > 0);

    // 通过将 wasm cache 赋值来模拟 cache 持久化，实际使用场景可能将 wasm cache 保存到文件
    std::vector<uint8_t> cacheBuffer(wasmCacheData, wasmCacheData + wasmCacheLength);

    // cache 一旦保存完成后，需要显式释放，以免发生内存泄露
    // 注意：传入的 JSVM_CacheType 必须匹配
    status = OH_JSVM_ReleaseCache(env, wasmCacheData, JSVM_CACHE_TYPE_WASM);
    CHECK_STATUS(status == JSVM_OK);

    // 使用 wasm code 反序列化来生成 wasm module
    bool cacheRejected;
    JSVM_Value wasmModule2;
    status = OH_JSVM_CompileWasmModule(env, wasmBytecode, wasmBytecodeLength, cacheBuffer.data(), cacheBuffer.size(),
                                       &cacheRejected, &wasmModule2);
   
    // 传入的 wasm cache 如果是匹配的，且内部校验通过 (如版本)，则会接受 cache
    CHECK_STATUS(cacheRejected == false);
    CHECK_STATUS(IsWasmModuleObject(env, wasmModule2));

    // 对反序列化得到的 wasmModule2 进行同样的操作：函数编译、实例化、验证功能，期望也都是通过的
    status = OH_JSVM_CompileWasmFunction(env, wasmModule2, functionIndex, JSVM_WASM_OPT_HIGH);
    CHECK_STATUS(status == JSVM_OK);

    JSVM_Value wasmInstance2 = InstantiateWasmModule(env, wasmModule);
    VerifyAddWasmInstance(env, wasmInstance2);

    JSVM_Value result;
    OH_JSVM_GetBoolean(env, true, &result);
    OH_LOG_INFO(LOG_APP, "JSVM resultInt: %{public}d", result);
    return result;
}

// WasmDemo 方法注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WasmDemo}
};
static JSVM_CallbackStruct *method = param;
// 将 C++ callback WasmDemo 函数注册为 JSVM globalThis.wasmDemo 属性，供 JS 侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"wasmDemo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(wasmDemo())JS";
```
预期输出
```
JSVM Init
JSVM resultInt: 975178312
```