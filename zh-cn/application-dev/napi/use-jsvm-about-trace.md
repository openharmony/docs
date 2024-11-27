# 使用JSVM-API接口进行Trace相关开发

## 简介

JSVM-API中trace相关接口用于在运行时采集并输出各种类型运行时信息。该能力可用于在JSVM模块中定位问题与性能分析。

## 基本概念

在JSVM-API中，Trace相关接口能够通过指定一系列分类，采集这些分类所属的JSVM内部事件信息，最后以JSON格式，按用户指定回调函数进行输出。

在JSVM-API中，通过支持Trace相关能力，JSVM模块能够更紧密地与JavaScript环境集成，加深用户对JSVM的理解，提高复杂问题的定位能力与性能分析能力。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_TraceStart           | 以指定事件类型与事件数量限制，开始采集运行时信息。  |
| OH_JSVM_TraceStop        | 停止采集信息，并以JSON格式在用户指定的回调函数中进行输出。  |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### 使用Trace接口进行数据采集

cpp部分代码

```cpp
#include <vector>
#include <string>

bool OutputStream(const char *data, int size, void *streamData) {
    std::string value(data, size);
    *(std::string *)streamData = std::string(data, size);
    return true;
}

// OH_JSVM_TraceStart/OH_JSVM_TraceStop样例方法
static JSVM_Value Trace(JSVM_Env env, JSVM_CallbackInfo info) {
    // start trace with categories
    std::vector<JSVM_TraceCategory> categories = {JSVM_TRACE_VM};
    JSVM_CALL(OH_JSVM_TraceStart(categories.size(), categories.data(), "trace test", 0));

    // run and trace
    JSVM_Script script;
    JSVM_Value jsSrc;
    JSVM_Value result;
    const char* trace_js = R"JS(
      function map(x, y) {
        return {"a": x, "b": y};
      }
      for (var i = 0; i < 80000; ++i) {
        var x = map(i, i);
      }
    )JS";
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, trace_js, JSVM_AUTO_LENGTH, &jsSrc));
    JSVM_CALL(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    JSVM_CALL(OH_JSVM_RunScript(env, script, &result));
    
    // stop trace and write file
    std::string data;
    JSVM_CALL(OH_JSVM_TraceStop(OutputStream, (void *)&data));

    OH_LOG_INFO(LOG_APP, "JSVM Trace success:%{public}s", data.c_str());
    return nullptr;
}
// Trace注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = Trace},
};
static JSVM_CallbackStruct *method = param;
// Trace方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"trace", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(trace())JS";
```