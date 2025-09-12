# Working with Proxy Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->
## Introduction
This topic walks you through on how to use JSVM-API to create a proxy instance, check whether the given **JSVM_Value** is of the proxy type, and obtain the target object from the given proxy.

## Available APIs

| API                    | Description                                           |
| ---------------------- | ----------------------------------------------- |
| OH_JSVM_CreateProxy    | Creates a proxy. This API is equivalent to calling **new Proxy (target, handler)** in JS.|
| OH_JSVM_IsProxy        | Checks whether the **JSVM_Value** is of the proxy type.                  |
| OH_JSVM_ProxyGetTarget | Obtains the target object of the specified proxy.                               |

## Example
If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in proxy-related APIs.

CPP code:
```
// Define OH_JSVM_CreateProxy.
static JSVM_Value CreateProxy(JSVM_Env env, JSVM_CallbackInfo info) {
    // Pass in two parameters: target and handler.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // Call OH_JSVM_CreateProxy to create a proxy for the target object.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateProxy(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateProxy: failed: %{public}d", status);
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateProxy: success");
    }

    return result;
}

// Define OH_JSVM_IsProxy.
static JSVM_Value IsProxy(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // Call OH_JSVM_IsProxy to check whether JSVM_Value is a proxy.
    bool result = false;
    JSVM_Status status = OH_JSVM_IsProxy(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_IsProxy: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsProxy: success: %{public}s", result ? "is a proxy" : "is not a proxy");
    }
    JSVM_Value isProxy;
    JSVM_CALL(OH_JSVM_GetBoolean(env, result, &isProxy));
    return isProxy;
}

// Define OH_JSVM_ProxyGetTarget.
static JSVM_Value GetProxyTarget(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // Call OH_JSVM_ProxyGetTarget to obtain the target object in the proxy.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_ProxyGetTarget(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ProxyGetTarget: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ProxyGetTarget: success");
    }

    return result;
}

// Register the proxy-related callbacks.
static JSVM_CallbackStruct param[] = {{.data = nullptr, .callback = CreateProxy},
                                      {.data = nullptr, .callback = IsProxy},
                                      {.data = nullptr, .callback = GetProxyTarget}};
static JSVM_CallbackStruct *method = param;
// Aliases for the proxy-related callbacks to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"CreateProxy", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"IsProxy", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"GetProxyTarget", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT}};

const char *srcCallNative = R"JS(
       target = {
         message1: "hello",
         message2: "everyone",
       };

       handler = {
         get(target, prop, receiver) {
           return "world";
         },
       };

       proxy = CreateProxy(target, handler)
       isProxy = IsProxy(proxy)
       target1 = GetProxyTarget(proxy)
)JS";
```

Expected result:
```
JSVM OH_JSVM_CreateProxy: success
JSVM OH_JSVM_IsProxy: success: is a proxy
JSVM OH_JSVM_ProxyGetTarget: success
```
