# Analyzing Error Logs and Crashes Triggered by Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:39:09.946Z pushedAt=2026-08-12T11:07:45.788Z -->

The maintenance and debugging measures mentioned in this topic rely on the Ark runtime multi-thread check. Therefore, you are advised to enable this feature before debugging. For details about how to enable Ark runtime multi-thread check, see [Analyzing CPP Crash](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-multi-thread-check).

Unless otherwise specified, the maintenance and debugging measures used in this topic will interrupt the process once the Ark runtime multi-thread check is enabled.

## Inconsistent napi_env Between the Data Being Used and the Data Being Created

### Logs

The inconsistency in **napi_env** occurs in the following scenarios:

1. The **napi_env** of the called Node-API is inconsistent with that used to create the Node-API struct.

   > **Log**<br>
   > param env not equal to its owner.
   >

2. The **napi_env** of the called Node-API is consistent with that used to create the Node-API struct, but the original **napi_env** has been destroyed.

   > **Log**<br>
   >
   > 1. For the methods other than thread-safe functions, the log information is as follows:
   >
   >    owner env has been destroyed, owner id: &lt;owner id&gt; , current    env id: &lt;current id&gt;.
   >
   > 2. For thread-safe functions, the log information is as follows:
   >
   >    current tsfn was created by dead env, owner id: &lt;owner id&gt;, current env id: &lt;current id&gt;

The following APIs may trigger this error:

1. napi_get_reference_value

2. napi_delete_reference*

3. napi_queue_async_work

4. napi_queue_async_work_with_qos

5. napi_cancel_async_work

6. napi_call_threadsafe_function*

7. napi_release_threadsafe_function*

> The APIs with an asterisk (\*) can only trigger the log information in the second scenario. The APIs without an asterisk (\*) can trigger the log information in both scenarios.

### Example

> **NOTE**
>
> The following code is intended only to create exception scenarios and trigger DFX error logs. Do not apply it to your code before you fully understand its purpose.

**Utility Class**

Define a utility class to construct the two exception scenarios.

```cpp
#define CHECK(cond)                                                 \
    do {                                                            \
        if (!(cond)) {                                                 \
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
            memset(argv_, 0, sizeof(argv_));
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

// Construct napi_env with the same address (or different addresses) to trigger different DFX information.
class EngineProxy {
public:
    EngineProxy()
    {
        STRICT_NAPI_CALL(napi_create_ark_runtime(&env_));
        // 5: makes easier reuse of the napi_env address.
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

    // Re-create napi_env until the address is the same as (or different from) the original napi_env.
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
    // Re-create napi_env and return whether the new address is the same as the original address.
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

**napi_ref APIs**

Sample code of **napi_get_reference_value** and **napi_delete_reference**:

```cpp
/*
 * API declaration index.d.ts
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
        // napi_create_reference creates a strong reference for the JS object. You need to use napi_delete_reference to destroy the reference. Otherwise, the JS object cannot be reclaimed, causing memory leaks.
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
 * API declaration index.d.ts
 * const triggerDFXDelRef: () => void;
 */
napi_value TriggerDFXDelRef(napi_env, napi_callback_info info)
{
    std::thread([]() {
        EngineProxy localEnv;
        napi_value obj = nullptr;
        STRICT_NAPI_CALL(napi_create_object(localEnv, &obj));
        napi_ref ref = nullptr;
        // Call napi_delete_reference to destroy the reference to avoid memory leaks.
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

**napi_async_work APIs**

Sample code of **napi_queue_async_work**, **napi_queue_async_work_with_qos**, and **napi_cancel_async_work**:

```cpp
/*
 * The macro EXPAND_ASYNC_WORK_CASE provides the following variables for op:
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
            /* Do not use an empty execute callback to create napi_async_work. */                    \
            /* Memory leak may occur here, which is only for DFX maintenance and debugging. */                            \
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
 * API declaration index.d.ts
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

**napi_threadsafe_function APIs**

Sample code of **napi_call_threadsafe_function** and **napi_release_threadsafe_function**:

```cpp
/*
 * The macro EXPAND_THREADSAFE_FUNCTION_CASE provides the following variables for op:
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
                // napi_create_threadsafe_function creates a thread-safe function.      \
                // After the task is complete, call napi_release_threadsafe_function to release it.
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
 * API declaration index.d.ts
 * const triggerDFXTsfnCall: () => void;
 * const triggerDFXTsfnRelease: () => void;
 */
EXPAND_THREADSAFE_FUNCTION_CASE(TriggerDFXTsfnCall,
    napi_call_threadsafe_function(tsfn, nullptr, napi_tsfn_nonblocking))
EXPAND_THREADSAFE_FUNCTION_CASE(TriggerDFXTsfnRelease,
    napi_release_threadsafe_function(tsfn, napi_tsfn_release))

#undef EXPAND_THREADSAFE_FUNCTION_CASE
```

## Cross-Thread Calls

### Logs

Most Node-API interfaces are not thread-safe. Additional measures are used to locate the errors caused by improper use of Node-API interfaces. 

Unless otherwise specified, the maintenance and debugging measures used in this topic will interrupt the process once the Ark runtime multi-thread check is enabled.

> **Log**<br>
>
> current napi interface cannot run in multi-thread, thread id: &lt;env tid&gt;, current thread id: &lt;current tid&gt;

The following APIs may trigger this type of error:

1. napi_add_env_cleanup_hook*

2. napi_remove_env_cleanup_hook*

3. napi_add_async_cleanup_hook

4. napi_set_instance_data

5. napi_get_instance_data

> When the triggering conditions are met in the debugging process, the APIs with an asterisk (*) can print the ERROR log with call stack information instead of interrupting the process.

### Example

> **NOTE**
>
> The following code is intended only to create exception scenarios and trigger DFX error logs. Do not apply it to your code before you fully understand its purpose.

**env_cleanup_hook APIs**

Sample code of **napi_add_env_cleanup_hook** and **napi_remove_env_cleanup_hook**:

```cpp
static void EnvCleanUpCallback(void *arg) {
    char* data = reinterpret_cast<char *>(arg);
    delete data;
}

/*
 * API declaration index.d.ts
 * const triggerDFXClnAddXT: () => void;
 */
napi_value TriggerDFXClnAddXT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = '\0';
    std::thread([](napi_env env, char* data) {
        napi_add_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    }, env, data).join();
    napi_remove_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr; 
}

/*
 * API declaration index.d.ts
 * const triggerDFXClnAddMT: () => void;
 */
napi_value TriggerDFXClnAddMT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = '\0';
    napi_add_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    napi_add_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    napi_remove_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr;
}

/*
 * API declaration index.d.ts
 * const triggerDFXClnRmXT: () => void;
 */
napi_value TriggerDFXClnRmXT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = '\0';
    napi_add_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    std::thread([](napi_env env, char* data) {
        napi_remove_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
        delete data;
    }, env, data).join();
    return nullptr; 
}

/*
 * API declaration index.d.ts
 * const triggerDFXClnRmMT: () => void;
 */
napi_value TriggerDFXClnRmMT(napi_env env, napi_callback_info info) 
{
    char* data = new char;
    CHECK_NOT_NULL(data);
    *data = '\0';
    napi_add_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    napi_remove_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    // Ensure consistency in parameters used for registering and deregistering cleanup hooks. It is more important than the errors caused by repeated deregistration.
    napi_remove_env_cleanup_hook(env, EnvCleanUpCallback, reinterpret_cast<void *>(data));
    delete data;
    return nullptr;
}
```

**async_cleanup_hook APIs**

Sample code of **napi_add_async_cleanup_hook**:

```cpp
static void AsyncCleanupCallback(napi_async_cleanup_hook_handle handle, void *)
{
    napi_remove_async_cleanup_hook(handle);    
}

/*
 * API declaration index.d.ts
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

**instance_data APIs**

Sample code of **napi_set_instance_data** and **napi_get_instance_data**:

```cpp
/*
 * API declaration index.d.ts
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
 * API declaration index.d.ts
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

## Async Task Callback and Reference Callback Crashes

### Coverage Scope and Key Logs

When a callback function contains logic errors such as null pointer dereference or array out-of-bounds access, an app crash occurs. If a crash occurs with compilation optimization enabled, the crash call stack only shows the function that called the callback, without indicating which .so shared library the actual callback function belongs to. You can locate the issue by following these steps:

1. Obtain the printed callback function pointer (in decimal).

2. Convert the pointer to hexadecimal.

3. Match the hexadecimal address in the Maps section of the crash file to identify which .so shared library the function that actually caused the crash belongs to.

> **Key logs**
>
> Crash occurred on &lt;function name&gt;, callback: &lt;callback ptr&gt;

The coverage scope of this DFX measure is as follows:

1. A crash occurs during the execution of finalize_cb in napi_wrap, napi_wrap_enhance, or napi_add_finalizer.

2. A crash occurs during the execution of finalize_cb in napi_set_instance_data.

3. A crash occurs during the execution of complete in napi_async_work related APIs.

4. A crash occurs during the execution of thread_finalize_cb and call_js_cb in threadsafe_function related APIs.

### Cases and Sample Code

> **NOTE**
>
> The following code is only used to construct exception scenarios and trigger DFX logs for exception branches. Do not directly apply it to business scenarios before fully understanding its intent.

**Constructing a Crash Scenario**

``` C++
/*
 * API declaration index.d.ts
 * const wrapCb: () => void;
 */
static napi_value WrapCb(napi_env env, napi_callback_info info)
{
    napi_value obj = nullptr;
    napi_status status = napi_create_object(env, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_object fail");
        return nullptr;
    }
    const char* testStr = "test";
    status = napi_wrap(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint){
        abort();
    }, nullptr, nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_wrap fail");
        return nullptr;
    }
    return nullptr;
}
```

After wrapCb is executed, garbage collection is triggered, which triggers the execution of the callback function.

``` TypeScript
import testNapi from 'libentry.so';

declare class ArkTools {
  static forceFullGC():void;
}

testNapi.wrapCb();
ArkTools.forceFullGC();
```

**Analyzing Crash Logs**

``` text
Device Memory(kB): Total 11871352, Free 332976, Available 5793792
Reason:Signal:SIGABRT(SI_TKILL)@0x01317bf10000b226 from:45606:20020209
LastFatalMessage:[NAPI] Crash occurred on ProcessAll, callback: 385297425128
```

Convert the callback pointer address 385297425128 to hexadecimal, which is 0x59B58422E8. Search for the callback function address in the Maps section of the crash file, and subtract the start address of the libentry.so module from the obtained hexadecimal value to get the offset address 0x22E8.

``` text
59b5504000-59b5505000 rw-p 00001000 /system/lib64/lib_cpuboost.so
59b5505000-59b5805000 rw-p 00000000 [anon:native_heap:jemalloc]
59b5840000-59b5841000 r--p 00000000 /data/storage/el1/bundle/libs/arm64/libentry.so
59b5841000-59b5843000 r-xp 00000000 /data/storage/el1/bundle/libs/arm64/libentry.so
59b5843000-59b5844000 r--p 00001000 /data/storage/el1/bundle/libs/arm64/libentry.so
59b5844000-59b5845000 rw-p 00001000 /data/storage/el1/bundle/libs/arm64/libentry.so
59b5880000-59b5912000 r--p 00000000 /data/storage/el1/bundle/libs/arm64/libc++_shared.so
59b5912000-59b59ac000 r-xp 00091000 /data/storage/el1/bundle/libs/arm64/libc++_shared.so
59b59ac000-59b59b6000 r--p 0012a000 /data/storage/el1/bundle/libs/arm64/libc++_shared.so
59b59b6000-59b59b7000 rw-p 00133000 /data/storage/el1/bundle/libs/arm64/libc++_shared.so
```

Using the [llvm-addr2line](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-exception-stack-parsing-principle#section1735713501344) tool, you can confirm that 0x22E8 is exactly the line where the callback function is located. This confirms that the issue occurs in the callback function passed during napi_wrap.

``` text
llvm-addr2line -ifCe libentry.so 0x22e8
WrapCb(napi_env__, napi_callback_info__)::$_0::invoke(napi_env, void, void*)
D:/DevEcoStudioProjects/PrintCbPtr/entry/src/main/cpp/napi_init.cpp:9
```