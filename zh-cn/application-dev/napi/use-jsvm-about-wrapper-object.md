# 使用JSVM-API接口进行Wrapper object相关开发
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

JSVM-API中，装箱类型(Wrapper object)判断相关接口支持通过不同API快速判断object的装箱类型。

## 基本概念

在JSVM-API中，装箱类型相关接口提供快速判断5种装箱类型的能力。

## 接口说明

| 接口                                    | 功能说明                       |
|----------------------------------------|--------------------------------|
| OH_JSVM_IsNumberObject            | 判断是否是Number Object。  |
| OH_JSVM_IsBooleanObject           | 判断是否是Boolean Object。  |
| OH_JSVM_IsBigIntObject            | 判断是否是BigInt Object。   |
| OH_JSVM_IsStringObject            | 判断是否是String Object。   |
| OH_JSVM_IsSymbolObject            | 判断是否是Symbol Object。   |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++代码。

### 使用接口判断是否是Number Object

cpp部分代码：

```cpp
#include <string>

static JSVM_Value WrapperObject(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);

    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    std::string src = R"JS(new Number(42))JS";
    JSVM_Value jsSrc;
    JSVM_Script script;
    JSVM_Value result;

    OH_JSVM_CreateStringUtf8(env, src.c_str(), JSVM_AUTO_LENGTH, &jsSrc);
    OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);
    OH_JSVM_RunScript(env, script, &result);
    bool isNumberObject = false;
    OH_JSVM_IsNumberObject(env, result, &isNumberObject);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsNumberObject: %{public}d\n", isNumberObject);
    OH_JSVM_CloseHandleScope(env, handleScope);

    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WrapperObject},
};

static JSVM_CallbackStruct *method = param;

// wrapperObject方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"wrapperObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试JS
const char *srcCallNative = R"JS(wrapperObject();)JS";

```

预期输出：
```
JSVM OH_JSVM_IsNumberObject: 1
```
