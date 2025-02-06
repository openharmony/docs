# 使用JSVM-API接口获取JSVM API的版本号

## 简介

用于获取当前版本信息。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetVersion         | 获取JSVM运行时支持的最高JSVM API版本。 |
| OH_JSVM_GetVMInfo          | 获取虚拟机的信息。              |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_GetVersion && OH_JSVM_GetVMInfo

获取当前环境支持的JSVM API的最高版本号和当前虚拟机的信息。

cpp部分代码

```cpp
// hello.cpp
#include <string.h>

// 待执行的js代码
static const char *STR_TASK = R"JS(getVersion();getVMInfo();)JS";

// GetVersion, GetVMInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVersion},
    {.data = nullptr, .callback = GetVMInfo},
};
static JSVM_CallbackStruct *method = param;
// GetVersion, GetVMInfo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVersion", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"getVMInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetVersion的样例方法
static JSVM_Value GetVersion(JSVM_Env env, JSVM_CallbackInfo info)
{
    uint32_t jsVersion = 0;
    // 调用接口，获取当前JSVM运行时支持的最高JSVM API版本
    JSVM_CALL(OH_JSVM_GetVersion(env, &jsVersion));
    int value = static_cast<int>(jsVersion);
    OH_LOG_INFO(LOG_APP, "JSVM GetVersion success:%{public}d", value);
    return nullptr;
}

// OH_JSVM_GetVMInfo的样例方法
// 打印JSVM（JavaScript虚拟机）的各项信息
void PrintVmInfo(JSVM_VMInfo vmInfo) {
    OH_LOG_INFO(LOG_APP, "JSVM API apiVersion: %{public}d", vmInfo.apiVersion);
    OH_LOG_INFO(LOG_APP, "JSVM API engine: %{public}s", vmInfo.engine);
    OH_LOG_INFO(LOG_APP, "JSVM API version: %{public}s", vmInfo.version);
    OH_LOG_INFO(LOG_APP, "JSVM API cachedDataVersionTag: 0x%{public}x", vmInfo.cachedDataVersionTag);
}

static JSVM_Value GetVMInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 调用接口，获取虚拟机的信息
    JSVM_VMInfo result;
    JSVM_CALL(OH_JSVM_GetVMInfo(&result));
    // 输出VM虚拟机信息
    PrintVmInfo(result);
    return nullptr;
}
```
