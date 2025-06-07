# 使用JSVM-API接口进行debug操作

## 简介

JSVM-API中提供接口，可以启用/禁用特定JSVM_Env下的指定debug选项。目前支持的debug选项有JSVM_SCOPE_CHECK。
 
## debug选项介绍

debug选项皆为JSVM_DebugOption类型。
 
### JSVM_SCOPE_CHECK

- 开发者在开发时，可能会出现在HandleScope结束后，调用上一次HandleScope内的JSVM_Value类型变量，导致程序崩溃。JSVM_SCOPE_CHECK为scope校验手段，校验当前调用的JSVM_Value类型变量是否超出HandleScope作用域，如果超出，则抛出错误“Run in wrong HandleScope”。
- 开启该debug选项后，若JSVM-API创建了JSVM_Value，则在hilog中有“ADD_VAL_TO_SCOPE_CHECK in function: [函数名]”输出，例如“ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetBoolean”。若JSVM-API使用了JSVM_Value，则在hilog中有“CHECK_SCOPE in function: [函数名]”输出，表示对使用的JSVM_Value进行了HandleScope校验，例如“CHECK_SCOPE in function: OH_JSVM_IsBoolean”。
 
## 接口说明

| 接口                                    | 功能说明                       |
|-----------------------------------------|-------------------------------|
| OH_JSVM_SetDebugOption                  | 启用/禁用特定JSVM_Env的指定debug选项。传入的debug选项参数debugOption必须为JSVM_DebugOption类型，布尔值参数isEnabled用于控制是否开启该debug选项。此API仅供debug时使用，开启后可能会带来性能下降。|

 
## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### JSVM_DebugOption

仅需替换[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)示例代码中的“TestJSVM()”函数即可运行。

- 在正确的HandleScope内调用JSVM_Value类型变量。
```cpp
static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;

    // 初始化JavaScript引擎实例
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // 创建JSVM环境
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    // 打开JSVM_SCOPE_CHECK校验选项
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, true));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    // 打开HandleScope
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // 通过script调用测试函数
    JSVM_Script script;
    JSVM_Value jsSrc, result;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    bool boolResult = true;
    // OH_JSVM_IsBoolean接口调用JSVM_Value类型变量result
    JSVM_Status status = OH_JSVM_IsBoolean(env, result, &boolResult);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_IsBoolean: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsBoolean: success: %{public}d", boolResult);
    }

    // 销毁JSVM环境
    // 关闭HandleScope
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    // 关闭JSVM_SCOPE_CHECK校验选项
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
#### 执行结果

hilog中有以下结果输出：

```
ADD_VAL_TO_SCOPE_CHECK in function: NewString
CHECK_SCOPE in function: OH_JSVM_CompileScript
ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetCbInfo
ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetCbInfo
ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetCbInfo
CHECK_SCOPE in function: OH_JSVM_StrictEquals
CHECK_SCOPE in function: OH_JSVM_StrictEquals
JSVM OH_JSVM_StrictEquals: success: 0
ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetBoolean
ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_RunScript
CHECK_SCOPE in function: OH_JSVM_IsBoolean
JSVM OH_JSVM_IsBoolean: success: 1
```

- 在错误的HandleScope内调用JSVM_Value类型变量。

```cpp
static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;

    // 初始化JavaScript引擎实例
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // 创建JSVM环境
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    // 打开JSVM_SCOPE_CHECK校验选项
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, true));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    // 打开HandleScope
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // 通过script调用测试函数
    JSVM_Script script;
    JSVM_Value jsSrc, result;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    bool boolResult = true;

    // 销毁JSVM环境
    // 关闭HandleScope
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    // OH_JSVM_IsBoolean接口在错误的HandleScope调用JSVM_Value类型变量result
    JSVM_Status status = OH_JSVM_IsBoolean(env, result, &boolResult);
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    // 关闭JSVM_SCOPE_CHECK校验选项
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
#### 执行结果

程序崩溃，有cppcrash日志生成，在hilog中可以检索到类似以下的信息：
```
JSVM Fatal Error Position : "../../../../../../../arkcompiler/jsvm/src/js_native_api_v8.cpp":4537
JSVM Fatal Error Message : "Run in wrong HandleScope"
```