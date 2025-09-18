# Performing Debug Operations Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Overview

JSVM-API provides an API to enable or disable a specified debug option in a specific JSVM_Env. Currently, **JSVM_SCOPE_CHECK** is supported.
 
## Debug Options

All debug options are of the JSVM_DebugOption type.
 
### JSVM_SCOPE_CHECK

- During development, you may call **JSVM_Value** variables in the previous **HandleScope** after it ends, causing application crash. **JSVM_SCOPE_CHECK** is a method for checking whether the called **JSVM_Value** variable exceeds the scope of **HandleScope**. If yes, the error "Run in wrong HandleScope" is reported.
- After this debug option is enabled, if JSVM-API creates a **JSVM_Value**, **ADD_VAL_TO_SCOPE_CHECK in function: [function name]** is output in HiLog logs, for example, **ADD_VAL_TO_SCOPE_CHECK in function: OH_JSVM_GetBoolean**. If JSVM-API uses **JSVM_Value**, **CHECK_SCOPE in function: [function name]** is output in HiLog logs, indicating that **HandleScope** verification is performed on the used **JSVM_Value**, for example, **CHECK_SCOPE in function: OH_JSVM_IsBoolean**.
 
## Available APIs

| Name                                   | Description                      |
|-----------------------------------------|-------------------------------|
| OH_JSVM_SetDebugOption                  | Enables or disables a specified debug option in a specific **JSVM_Env**. The input **debugOption** must be of the **JSVM_DebugOption** type. The Boolean parameter **isEnabled** is used to control whether to enable the debug option. This API is used only for debugging. Enabling this API may cause performance deterioration.|

 
## Sample Code

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in using the API.

### JSVM_DebugOption

Replace the **TestJSVM()** function in the sample code of [JSVM-API Development Process](use-jsvm-process.md).

- Call the JSVM_Value variable in the correct **HandleScope**.
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
    // Enable the JSVM_SCOPE_CHECK option.
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
    // The OH_JSVM_IsBoolean API calls the JSVM_Value variable result.
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
    // Disable the JSVM_SCOPE_CHECK option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
**Execution result**

The following information is displayed in the HiLog:

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

- The **JSVM_Value** variable is called in an incorrect HandleScope.

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
    // Enable the JSVM_SCOPE_CHECK option.
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
    // Disable the JSVM_SCOPE_CHECK option.
    CHECK(OH_JSVM_SetDebugOption(env, JSVM_SCOPE_CHECK, false));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
**Execution result**

The application crashes, the cppcrash log is generated, and the following information is displayed in HiLog:
```
JSVM Fatal Error Position : "../../../../../../../arkcompiler/jsvm/src/js_native_api_v8.cpp":4537
JSVM Fatal Error Message : "Run in wrong HandleScope"
```
