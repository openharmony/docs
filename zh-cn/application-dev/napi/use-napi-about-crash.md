# 使用Node-API接口产生的异常日志/崩溃分析
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

以下维测手段多数依赖于ArkTS运行时的多线程检测能力，因此建议在调试前启用此功能。启用方法参考文档[分析CppCrash（进程崩溃）](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-multi-thread-check)。

若无特殊说明，本章节描述的维测手段会在启用ArkTS运行时多线程检测开关的情况下，立即中断进程。

## 数据在使用时，与创建该数据时所使用的env不一致

### 各问题场景的关键日志

该维测手段主要包含以下两种场景：

1. 调用napi方法的入参napi_env与创建napi数据结构时所使用的napi_env不一致。

   > **关键日志**
   > param env not equal to its owner.
   >

2. 调用napi方法的入参napi_env与创建napi数据结构时所使用的napi_env一致，但原始napi_env已释放。

   > **关键日志**
   >
   > 1. 除线程安全函数相关方法外，关键日志如下：
   >
   >    owner env has been destroyed, owner id: &lt;owner id&gt; , current    env id: &lt;current id&gt;.
   >
   > 2. 线程安全函数相关方法，关键日志如下：
   >
   >    current tsfn was created by dead env, owner id: &lt;owner id&gt;, current env id: &lt;current id&gt;

该维测手段当前的覆盖范围如下：

1. napi_get_reference_value
2. napi_delete_reference*
3. napi_queue_async_work
4. napi_queue_async_work_with_qos
5. napi_cancel_async_work
6. napi_call_threadsafe_function*
7. napi_release_threadsafe_function*

> 具有\*标志的接口，仅能触发第二种场景的维测信息，不含有\*标志的接口，能触发以上两种场景的维测信息。

### 案例及示例代码

> **注意：** 下面的代码仅用于构造异常场景，触发异常分支的DFX日志。在充分理解其意图前，请勿将其应用到业务场景中。

**基础工具类**

定义一个工具类，便于在后续构造两种异常场景。

```cpp
#define CHECK(cond)                                                 \
    do {                                                            \
        if (cond) {                                                 \
            OH_LOG_FATAL(LOG_APP, "Failed to check `" #cond "`");   \
            std::abort();                                           \
        }                                                           \
    } while(0)
#define CHECK_EQ(lhs, rhs) CHECK(lhs == rhs)
#define CHECK_NE(lhs, rhs) CHECK(lhs != rhs)
#define CHECK_NOT_NULL(val) CHECK(val != nullptr)

#define STRICT_NAPI_CALL(call)                                      \
    do {                                                            \
        napi_status ret = (call);                                   \
        if (ret != napi_ok) {                                       \
            OH_LOG_FATAL(LOG_APP, "Failed to execute `" #call "`, " \
                "return code is: %{public}d", ret);                 \
            std::abort();                                           \
        }                                                           \
    } while(0)


class CallbackInfo {
public:
    CallbackInfo(napi_env env, napi_callback_info info)
        : env_(env)
    {
        napi_get_cb_info(env, info, &argc_, nullptr, &thisVar_, &data_);
        if (argc_ > 0) {
            argv_ = new napi_value[argc_];
            CHECK_NOT_NULL(argv_);
            memset(argv_, nullptr, sizeof(argv_));
            napi_get_cb_info(env, info, &argc_, argv_, nullptr, nullptr);
        }
    }
    ~CallbackInfo()
    {
        if (argc_ > 0) {
            delete[] argv_;
            argv_ = nullptr;
        }
    }

    inline size_t GetArgc() const { return argc_; }
    inline napi_value* GetArgs() const { return argv_; }

    inline napi_value GetArg(size_t index) const
    {
        if (index >= argc_) {
            napi_value undefined = nullptr;
            napi_get_undefined(env_, &undefined);
            return undefined;
        }
        return argv_[index];
    }
    inline napi_value operator[](size_t index) const
    {
        return GetArg(index);
    }

private:
    napi_env env_ { nullptr };
    size_t argc_ { 0 };
    napi_value* argv_ { nullptr };
    napi_value thisVar_ { nullptr };
    void* data_ { nullptr };
};

// 构造相同（或不同）地址的napi_env，以便能触发不同的DFX信息
class EngineProxy {
public:
    EngineProxy()
    {
        STRICT_NAPI_CALL(napi_create_ark_runtime(&env_));
        // 5: 使napi_env地址复用更容易
        for (int i = 0; i < 5; i++) {
            RecreateOnce();
        }
    }

    ~EngineProxy()
    {
        STRICT_NAPI_CALL(napi_destroy_ark_runtime(&env_));
    }

    inline bool RecreateSame()
    {
        return Recreate(true);
    }

    inline bool RecreateDiff()
    {
        return Recreate(false);
    }

    inline operator napi_env() const
    {
        return env_;
    }

    // 重新创建napi_env，直到地址与原始env相同（或不同）
    bool Recreate(bool requireSame)
    {
        const char* recreateTypeTag = requireSame ? "same" : "different";
        napi_env old = env_;
        for (int i = 0; i < MAX_RETRY_TIMES; i++) {
            if (RecreateOnce(old) == requireSame) {
                OH_LOG_INFO(LOG_APP, "Succeed to recreate env with %{public}s pointer "
                    "address after retried %{public}d times.", recreateTypeTag, i);
                return true;
            }
        }
        OH_LOG_ERROR(LOG_APP, "Failed to recreate env with %{public}s pointer "
            "address after retried %{public}d times.", recreateTypeTag, MAX_RETRY_TIMES);
        return false;
    }

private:
    // 重新创建napi_env，返回新地址是否与原地址相同
    bool RecreateOnce(napi_env old = nullptr)
    {
        STRICT_NAPI_CALL(napi_destroy_ark_runtime(&env_));
        STRICT_NAPI_CALL(napi_create_ark_runtime(&env_));
        return env_ == old;
    }

    napi_env env_ {nullptr};
    
    constexpr static int MAX_RETRY_TIMES = 1 << 8;
};
```

**napi_ref相关接口**

napi_get_reference_value 和 napi_delete_reference 的示例代码

```cpp
/*
 * 接口声明 index.d.ts
 * const triggerDFXGetRef: (samePtr: boolean) => void;
 */
napi_value TriggerDFXGetRef(napi_env env, napi_callback_info cbinfo)
{
    CallbackInfo info(env, cbinfo);
    bool same = true;
    STRICT_NAPI_CALL(napi_get_value_bool(env, info[0], &same));
    std::thread([](bool same) {
        EngineProxy localEnv;
        napi_value obj = nullptr;
        STRICT_NAPI_CALL(napi_create_object(localEnv, &obj));
        napi_ref ref = nullptr;
        // napi_create_reference为js对象创建了强引用，需要使用napi_delete_reference主动销毁，否则会导致js对象无法被回收，造成内存泄漏
        napi_create_reference(localEnv, obj, 1, &ref);
        if (!localEnv.Recreate(same)) {
            if (ref != nullptr) {
                napi_delete_reference(localEnv, ref);
            }
            return;
        }
        napi_value result = nullptr;
        napi_get_reference_value(localEnv, ref, &result);
        if (ref != nullptr) {
            napi_delete_reference(localEnv, ref);
        }
    }, same).detach();
    return nullptr;
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXDelRef: () => void;
 */
napi_value TriggerDFXDelRef(napi_env, napi_callback_info info)
{
    std::thread([]() {
        EngineProxy localEnv;
        napi_value obj = nullptr;
        STRICT_NAPI_CALL(napi_create_object(localEnv, &obj));
        napi_ref ref = nullptr;
        // 在使用完成后调用napi_delete_reference来释放引用，避免内存泄露
        napi_create_reference(localEnv, obj, 1, &ref);
        if (!localEnv.RecreateSame()) {
            if (ref != nullptr) {
                napi_delete_reference(localEnv, ref);
            }
            return;
        };
        if (ref != nullptr) {
            napi_delete_reference(localEnv, ref);
        }
    }).detach();
    return nullptr;
}
```

**napi_async_work相关接口**

napi_queue_async_work、napi_queue_async_work_with_qos 和 napi_cancel_async_work 的示例代码

```cpp
/*
 * 宏 EXPAND_ASYNC_WORK_CASE 将为 op 提供如下变量
 * @variable napi_env localEnv
 * @variable napi_async_work work
 */
#define EXPAND_ASYNC_WORK_CASE(name, op)                                           \
napi_value name(napi_env env, napi_callback_info cbinfo)                           \
{                                                                                  \
    CallbackInfo info(env, cbinfo);                                                \
    bool same = true;                                                              \
    STRICT_NAPI_CALL(napi_get_value_bool(env, info[0], &same));                    \
    std::thread([](bool same) {                                                    \
        EngineProxy localEnv;                                                      \
        napi_async_work work = nullptr;                                            \
        {                                                                          \
            napi_value taskName = nullptr;                                         \
            napi_create_string_utf8(localEnv, #name, NAPI_AUTO_LENGTH, &taskName); \
            /* 不建议使用空的 execute 回调创建 napi_async_work */                    \
            /* 此处可能出现内存泄漏，仅为复现 dfx 维测 */                            \
            napi_create_async_work(localEnv, nullptr, taskName,                    \
                [](napi_env, void*) {}, [](napi_env, napi_status, void* ) {},      \
                nullptr, &work);                                                   \
            if (!localEnv.Recreate(same)) {                                        \
                if (work != nullptr) {                                             \
                    napi_delete_async_work(localEnv, work);                        \
                }                                                                  \
                return;                                                            \
            }                                                                      \
        }                                                                          \
        (op);                                                                      \
        if (work != nullptr) {                                                     \
            napi_delete_async_work(localEnv, work);                                \
        }                                                                          \
    }, same).detach();                                                             \
    return nullptr;                                                                \
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXQueueWork: (samePtr: boolean) => void;
 * const triggerDFXQueueWorkWithQos: (samePtr: boolean) => void;
 * const triggerDFXCancelWork: (samePtr: boolean) => void;
 */
EXPAND_ASYNC_WORK_CASE(TriggerDFXQueueWork,
    napi_queue_async_work(localEnv, work))
EXPAND_ASYNC_WORK_CASE(TriggerDFXQueueWorkWithQos,
    napi_queue_async_work_with_qos(localEnv, work, napi_qos_default))
EXPAND_ASYNC_WORK_CASE(TriggerDFXCancelWork,
    napi_cancel_async_work(localEnv, work))

#undef EXPAND_ASYNC_WORK_CASE
```

**napi_threadsafe_function相关接口**

napi_call_threadsafe_function 和 napi_release_threadsafe_function 的示例代码

```cpp
/*
 * 宏 EXPAND_THREADSAFE_FUNCTION_CASE 将为 op 提供如下变量
 * @variable napi_env localEnv
 * @variable napi_threadsafe_function tsfn
 */
#define EXPAND_THREADSAFE_FUNCTION_CASE(name, op)                                       \
    napi_value name(napi_env, napi_callback_info info) {                                \
        std::thread([]() {                                                              \
            EngineProxy localEnv;                                                       \
            napi_threadsafe_function tsfn = nullptr;                                    \
            {                                                                           \
                napi_value taskName = nullptr;                                          \
                napi_create_string_utf8(localEnv, "Test", NAPI_AUTO_LENGTH, &taskName); \
                // napi_create_threadsafe_function创建线程安全函数，任务执行完成后，      \
                // 需调用napi_release_threadsafe_function释放
                napi_create_threadsafe_function(                                        \
                    localEnv, nullptr, nullptr, taskName, 0, 1, nullptr,                \
                    [](napi_env, void *, void *) {}, nullptr,                           \
                    [](napi_env, napi_value, void *, void *) {}, &tsfn);                \
                if (status != napi_ok) {                                                \
                    OH_INFO_ERROR(LOG_APP,"napi_create_threadsafe_function failed");    \
                    return nullptr;                                                     \
                }                                                                       \
                if (!localEnv.RecreateSame()) {                                         \
                    return;                                                             \
                };                                                                      \
            }                                                                           \
            (op);                                                                       \
        }).detach();                                                                    \
        return nullptr;                                                                 \
    }

/*
 * 接口声明 index.d.ts
 * const triggerDFXTsfnCall: () => void;
 * const triggerDFXTsfnRelease: () => void;
 */
EXPAND_THREADSAFE_FUNCTION_CASE(TriggerDFXTsfnCall,
    napi_call_threadsafe_function(tsfn, nullptr, napi_tsfn_nonblocking))
EXPAND_THREADSAFE_FUNCTION_CASE(TriggerDFXTsfnRelease,
    napi_release_threadsafe_function(tsfn, napi_tsfn_release))

#undef EXPAND_THREADSAFE_FUNCTION_CASE
```

## 跨线程调用

### 覆盖范围及关键日志

大多数napi接口都不是多线程安全的，因此为这些错误用法额外增加了定位手段。

若无特殊说明，本章节描述的维测手段会在启用ArkTS运行时多线程检测开关后，立即中断进程。

> **关键日志**
>
> current napi interface cannot run in multi-thread, thread id: &lt;env tid&gt;, current thread id: &lt;current tid&gt;

该维测手段覆盖范围如下：

1. napi_add_env_cleanup_hook*
2. napi_remove_env_cleanup_hook*
3. napi_add_async_cleanup_hook
4. napi_set_instance_data
5. napi_get_instance_data

> \*：具有该标志的接口，在维测触发的情况下，仅打印带有调用栈信息的ERROR日志，并不会中断进程。

### 案例及示例代码

> **注意：** 下面的代码仅用于构造异常场景，触发异常分支的DFX日志。在充分理解其意图前，请勿将其应用到业务场景中。

**env_cleanup_hook相关接口**

napi_add_env_cleanup_hook 和 napi_remove_env_cleanup_hook 的示例代码

```cpp
static void EnvCLeanUpCallback(void *arg) {
    char* data = reinterpret_cast<char *>(arg);
    delete data;
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXClnAddXT: () => void;
 */
napi_value TriggerDFXClnAddXT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = nullptr;
    std::thread([](napi_env env, char* data) {
        napi_add_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    }, env, data).join();
    napi_remove_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr; 
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXClnAddMT: () => void;
 */
napi_value TriggerDFXClnAddMT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = nullptr;
    napi_add_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    napi_add_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    napi_remove_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr;
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXClnRmXT: () => void;
 */
napi_value TriggerDFXClnRmXT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = nullptr;
    napi_add_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    std::thread([](napi_env env, char* data) {
        napi_remove_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
        delete data;
    }, env, data).join();
    return nullptr; 
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXClnRmMT: () => void;
 */
napi_value TriggerDFXClnRmMT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = nullptr;
    napi_add_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    napi_remove_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    // 解注册使用的参数与注册时的一致性，比重复解注册更值得关注
    napi_remove_env_cleanup_hook(env, EnvCLeanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr;
}
```

**async_cleanup_hook相关接口**

napi_add_async_cleanup_hook示例代码

```cpp
static void AsyncCleanupCallback(napi_async_cleanup_hook_handle handle, void *)
{
    napi_remove_async_cleanup_hook(handle);    
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXAsyncAddXT: () => void;
 */
napi_value TriggerDFXAsyncAddXT(napi_env env, napi_callback_info info) 
{
    std::thread([](napi_env env) {
        napi_add_async_cleanup_hook(env, AsyncCleanupCallback, nullptr, nullptr);
    }, env).join();
    return nullptr;
}
```

**instance_data相关接口**

napi_set_instance_data、napi_get_instance_data示例代码

```cpp
/*
 * 接口声明 index.d.ts
 * const triggerDFXInsSetXT: () => void;
 */
napi_value TriggerDFXInsSetXT(napi_env env, napi_callback_info info)
{
    std::thread([](napi_env env) {
        napi_set_instance_data(env, nullptr, [](napi_env, void *, void *) {}, nullptr);
    }, env).join();
    return nullptr;
}

/*
 * 接口声明 index.d.ts
 * const triggerDFXInsGetXT: () => void;
 */
napi_value TriggerDFXInsGetXT(napi_env env, napi_callback_info info)
{
    std::thread([](napi_env env) {
        void *data = nullptr;
        napi_get_instance_data(env, &data);
    }, env).join();
    return nullptr;
}
```
