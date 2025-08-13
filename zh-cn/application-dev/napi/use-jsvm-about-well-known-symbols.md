# 使用JSVM-API接口进行Well-known symbols相关开发
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

JSVM-API中Well-known symbols相关接口可以通过不同API直接获取对应的11个Well-known symbols。

## 基本概念

在JSVM-API中，Well-known symbols相关接口能够给用户提供快速获取对应的11个Well-known symbols的能力。

## 接口说明

| 接口                                    | 功能说明                       |
|----------------------------------------|--------------------------------|
| OH_JSVM_GetSymbolToStringTag           | 等价于JS中的Symbol.toStringTag。  |
| OH_JSVM_GetSymbolToPrimitive           | 等价于JS中的Symbol.toPrimitive。  |
| OH_JSVM_GetSymbolSplit                 | 等价于JS中的Symbol.split。   |
| OH_JSVM_GetSymbolSearch                | 等价于JS中的Symbol.search。   |
| OH_JSVM_GetSymbolReplace               | 等价于JS中的Symbol.replace。   |
| OH_JSVM_GetSymbolMatch                 | 等价于JS中的Symbol.match。   |
| OH_JSVM_GetSymbolIsConcatSpreadable    | 等价于JS中的Symbol.isConcatSpreadable。   |
| OH_JSVM_GetSymbolHasInstance           | 等价于JS中的Symbol.hasInstance。   |
| OH_JSVM_GetSymbolUnscopables           | 等价于JS中的Symbol.unscopables。   |
| OH_JSVM_GetSymbolAsyncIterator         | 等价于JS中的Symbol.asyncIterator。   |
| OH_JSVM_GetSymbolIterator              | 等价于JS中的Symbol.iterator。   |

## 使用示例

参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)中的JSVM-API接口开发流程，本文仅展示接口对应的C++代码。

### 使用接口获取Well-known symbols（以OH_JSVM_GetSymbolToStringTag为例）

cpp部分代码：

```cpp
#include <string>

static JSVM_Value WellKnownSymbols(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);

    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    std::string src = R"JS(Symbol.toStringTag)JS";
    JSVM_Value jsSrc;
    JSVM_Script script;
    JSVM_Value result1;

    OH_JSVM_CreateStringUtf8(env, src.c_str(), JSVM_AUTO_LENGTH, &jsSrc);
    OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);
    OH_JSVM_RunScript(env, script, &result1);
    JSVM_Value result2;
    OH_JSVM_GetSymbolToStringTag(env, &result2);
    bool is_equals = false;
    OH_JSVM_StrictEquals(env, result1, result2, &is_equals);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetSymbolToStringTag result is correct : %{public}d\n", is_equals);
    OH_JSVM_CloseHandleScope(env, handleScope);

    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WellKnownSymbols},
};

static JSVM_CallbackStruct *method = param;

// wellKnownSymbols方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"wellKnownSymbols", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试JS
const char *srcCallNative = R"JS(wellKnownSymbols();)JS";

```

预期输出：
```
JSVM OH_JSVM_GetSymbolToStringTag result is correct : 1
```
