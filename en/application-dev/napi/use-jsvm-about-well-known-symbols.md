# Working with Well-Known Symbols Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to obtain 11 well-known symbols.

## Basic Concepts

JSVM-API provides APIs for obtaining 11 well-known symbols.

## Available APIs

| API                                   | Description                      |
|----------------------------------------|--------------------------------|
| OH_JSVM_GetSymbolToStringTag           | Obtains the value equivalent to the JS **Symbol.toStringTag**. |
| OH_JSVM_GetSymbolToPrimitive           | Obtains the value equivalent to the JS **Symbol.toPrimitive**. |
| OH_JSVM_GetSymbolSplit                 | Obtains the value equivalent to the JS **Symbol.split**.  |
| OH_JSVM_GetSymbolSearch                | Obtains the value equivalent to the JS **Symbol.search**.  |
| OH_JSVM_GetSymbolReplace               | Obtains the value equivalent to the JS **Symbol.replace**.  |
| OH_JSVM_GetSymbolMatch                 | Obtains the value equivalent to the JS **Symbol.match**.  |
| OH_JSVM_GetSymbolIsConcatSpreadable    | Obtains the value equivalent to the JS **Symbol.isConcatSpreadable**.  |
| OH_JSVM_GetSymbolHasInstance           | Obtains the value equivalent to the JS **Symbol.hasInstance**.  |
| OH_JSVM_GetSymbolUnscopables           | Obtains the value equivalent to the JS **Symbol.unscopables**.  |
| OH_JSVM_GetSymbolAsyncIterator         | Obtains the value equivalent to the JS **Symbol.asyncIterator**.  |
| OH_JSVM_GetSymbolIterator              | Obtains the value equivalent to the JS **Symbol.iterator**.  |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in obtaining the well-known symbols.

### OH_JSVM_GetSymbolToStringTag

CPP code:

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

// Alias for the wellKnownSymbols method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"wellKnownSymbols", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(wellKnownSymbols();)JS";

```

Expected result:
```
JSVM OH_JSVM_GetSymbolToStringTag result is correct : 1
```
