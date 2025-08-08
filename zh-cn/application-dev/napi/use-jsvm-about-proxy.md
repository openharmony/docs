# 使用 JSVM-API 提供的proxy接口
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->
## 简介
JSVM-API 提供了创建 Proxy、判断 JSVM_Value 是否为 Proxy 类型和获取 Proxy 中的目标对象的接口。

## 接口说明

| 接口                     | 功能说明                                            |
| ---------------------- | ----------------------------------------------- |
| OH_JSVM_CreateProxy    | 创建 Proxy，等价于在 js 中执行 new Proxy(target, handler) |
| OH_JSVM_IsProxy        | 判断传入的 JSVM_Value 是否为 Proxy 类型                   |
| OH_JSVM_ProxyGetTarget | 获取给定 proxy 的目标对象                                |

## 使用示例
JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++相关代码。

cpp 部分代码
```
// OH_JSVM_CreateProxy 的样例方法
static JSVM_Value CreateProxy(JSVM_Env env, JSVM_CallbackInfo info) {
    // 接受两个入参，第 1 个参数为 target，第 2 个参数为 handler
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // 用 OH_JSVM_CreateProxy 为目标对象创建代理
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateProxy(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateProxy: failed: %{public}d", status);
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateProxy: success");
    }

    return result;
}

// OH_JSVM_IsProxy 的样例方法
static JSVM_Value IsProxy(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // 调用 OH_JSVM_IsProxy 判断 JSVM_Value 是否为代理
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

// OH_JSVM_ProxyGetTarget 的样例方法
static JSVM_Value GetProxyTarget(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // 调用 OH_JSVM_ProxyGetTarget 获取代理中的目标对象
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_ProxyGetTarget(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ProxyGetTarget: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ProxyGetTarget: success");
    }

    return result;
}

// Proxy 相关回调注册
static JSVM_CallbackStruct param[] = {{.data = nullptr, .callback = CreateProxy},
                                      {.data = nullptr, .callback = IsProxy},
                                      {.data = nullptr, .callback = GetProxyTarget}};
static JSVM_CallbackStruct *method = param;
// Proxy 相关回调别名
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

预期的输出结果
```
JSVM OH_JSVM_CreateProxy: success
JSVM OH_JSVM_IsProxy: success: is a proxy
JSVM OH_JSVM_ProxyGetTarget: success
```