# Performing Debug Operations Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Overview

The JSVM-API provides an interface for enabling or disabling a specified debug option under a specific JSVM_Env. Currently, JSVM_SCOPE_CHECK is supported.
 
## Debug Options

All debug options are of the JSVM_DebugOption type.
 
### JSVM_SCOPE_CHECK

- During development, the JSVM_Value variable in HandleScope may be called after HandleScope ends. As a result, the program breaks down. JSVM_SCOPE_CHECK is a scope verification method. It checks whether the currently called variable of the JSVM_Value type exceeds the scope of HandleScope. If yes, the error message "Run in wrong HandleScope" is displayed.
- After the debug option is enabled, if JSVM_Value is created by JSVM-API, ADD_VAL_TO_SCOPE_CHECK in function: [function name] is output in hilog, for example, ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetBoolean. If JSVM_Value is used by JSVM-API, "CHECK_SCOPE in function: [function name]" is displayed in the hilog, indicating that HandleScope verification is performed on the used JSVM_Value, for example, " CHECK_SCOPE in function: OH_JSVM_IsBoolean."
 
## Available APIs

| Interface                                   | Description                      |
|-----------------------------------------|-------------------------------|
| OH_JSVM_SetDebugOption                  | Enables or disables the specified debug option of a specific JSVM_Env. The input debug option parameter debugOption must be of the JSVM_DebugOption type. The Boolean value parameter isEnabled is used to determine whether to enable the debug option. This API is used only for debugging. After this API is enabled, the performance may deteriorate.|

 
## Sample Code

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in proxy-related APIs.

### JSVM_DebugOption

You only need to replace the TestJSVM () function in the example code [Using JSVM-API to Implement Interaction Between JS and C/C++](use-jsvm-process.md).

- Invoke the JSVM_Value variable in the correct HandleScope.
```cpp
static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;

    // Initialize the JSVM instance.
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // Create a JSVM environment.
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    // Enable the JSVM_SCOPE_CHECK verification option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, true));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    // Open HandleScope.
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // Call the demo function using the script.
    JSVM_Script script;
    JSVM_Value jsSrc, result;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    bool boolResult = true;
    // The OH_JSVM_IsBoolean interface calls the JSVM_Value variable result.
    JSVM_Status status = OH_JSVM_IsBoolean(env, result, &boolResult);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_IsBoolean: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsBoolean: success: %{public}d", boolResult);
    }

    // Destroy the JSVM environment.
    // Close HandleScope.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    // Disable the JSVM_SCOPE_CHECK verification option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
**Execution result**

The following information is displayed in the hilog file:

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

- The JSVM_Value variable is called in the incorrect HandleScope.

```cpp
static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;

    // Initialize the JSVM instance.
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    // Create a JSVM environment.
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    // Enable the JSVM_SCOPE_CHECK verification option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, true));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    // Open HandleScope.
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // Call the demo function using the script.
    JSVM_Script script;
    JSVM_Value jsSrc, result;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    bool boolResult = true;

    // Destroy the JSVM environment.
    // Close HandleScope.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    // The OH_JSVM_IsBoolean API calls the JSVM_Value variable result in the incorrect HandleScope.
    JSVM_Status status = OH_JSVM_IsBoolean(env, result, &boolResult);
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    // Disable the JSVM_SCOPE_CHECK verification option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
**Execution result**

The program crashes, and the cppcrash log is generated. Information similar to the following can be found in the hilog:
```
JSVM Fatal Error Position : "../../../../../../../arkcompiler/jsvm/src/js_native_api_v8.cpp":4537
JSVM Fatal Error Message : "Run in wrong HandleScope"
```
