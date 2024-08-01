# 使用JSVM-API接口获取JSVM API的版本号

## 简介

用于获取当前版本信息。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetVersion         | 返回JSVM运行时支持的最高JSVM API版本。 |
| OH_JSVM_GetVMInfo          | 返回虚拟机的信息。              |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_GetVersion

获取当前环境支持的JSVM API的最高版本号。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetVersion注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVersion},
};
static JSVM_CallbackStruct *method = param;
// GetVersion方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVersion", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetVersion的样例方法
static JSVM_Value GetVersion(JSVM_Env env, JSVM_CallbackInfo info)
{
    uint32_t jsVersion = 0;
    // 调用接口，获取当前JSVM运行时支持的最高JSVM API版本
    JSVM_Status status = OH_JSVM_GetVersion(env, &jsVersion);
    JSVM_Value result = nullptr;
    OH_JSVM_CreateUint32(env, jsVersion, &result);
    int value = static_cast<int>(jsVersion);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetVersion fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetVersion success:%{public}d", value);
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    getVersion()
`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getVersion: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getVersion error: %{public}s', error.message);
}
```

### OH_JSVM_GetVMInfo

获取虚拟机的信息。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetVMInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVMInfo},
};
static JSVM_CallbackStruct *method = param;
// GetVMInfo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVMInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
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
    OH_JSVM_GetVMInfo(&result);
    // 取出“此虚拟机支持的最高API版本”信息带出去打印
    JSVM_Value version = nullptr;
    OH_JSVM_CreateUint32(env, result.apiVersion, &version);
    // 输出VM虚拟机信息
    PrintVmInfo(result);
    return version;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    getVMInfo()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getVMInfo apiVersion: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getVMInfo error: %{public}s', error.message);
}
```
