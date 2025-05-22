# NDK Usage


## Where can I find the libc++ library? Is it packed into the HAP? (API version 10)

**Solution**

You can find **libc++_shared.so** in the application directory. Each application has an independent **libc++_shared.so** file in **/data/storage/el1/bundle/libs/${arch}**.

## How do I run a third-party open source C/C++ library on the system? (API version 10)

**Solution**

Currently, the official SDK supports only build with CMake. It also provides guides for GN build.

**Reference**

1. GN build: 

    [Building a Third-Party Library Based on gn_example](https://gitee.com/openharmony/build/wikis/gn%E6%9E%84%E5%BB%BA%E4%B8%89%E6%96%B9%E5%BA%93/%E5%9F%BA%E4%BA%8Egn_example%E7%BC%96%E8%AF%91%E4%B8%89%E6%96%B9%E5%BA%93%E4%BB%A3%E7%A0%81) 

    [Porting OHOS Based on a Third-Party Build Framework](https://gitee.com/openharmony/build/wikis/gn%E6%9E%84%E5%BB%BA%E4%B8%89%E6%96%B9%E5%BA%93/%E5%9F%BA%E4%BA%8E%E4%B8%89%E6%96%B9%E7%BC%96%E8%AF%91%E6%A1%86%E6%9E%B6%E7%A7%BB%E6%A4%8DOHOS)

2. CMake build:

    linux: [HOW TO USE NDK (linux)](https://gitee.com/openharmony/build/wikis/NDK/HOW%20TO%20USE%20NDK%20(linux)) 

    windows: [HOW TO USE NDK (windows)](https://gitee.com/openharmony/build/wikis/NDK/HOW%20TO%20USE%20NDK%20(windows))

## What are the common attributes to be used and how do I implement the APIs when using Node-API to extend TS interfaces? How do I obtain env, implement callback- and promise-based APIs, and use libuv? (API version 10)



**Solution**

1. **env** uses the modular programming of Node-API. After the module is registered, the APIs in the callbacks are invoked with the callbacks.

    ```cpp
    static napi_value CallNapi(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value object = nullptr;
        napi_status status;
        status = napi_get_cb_info(env, info, &argc, &object, nullptr, nullptr);
        return object;
    }
    NAPI_MODULE_INIT()
    {
        napi_property_descriptor desc[] = {
            {" callNapi ", nullptr, CallNapi, nullptr, nullptr, nullptr, napi_default, nullptr}};
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    ```

2. Callback implementation:

    ```cpp
    #include "napi/native_api.h"
    #include <assert.h>
    static napi_value NativeCall(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = {nullptr};
        napi_status status;
        status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
        assert(status == napi_ok);
    
        napi_valuetype valuetype;
        napi_typeof(env, args[0], &valuetype);
        if (valuetype != napi_valuetype::napi_function)
        {
            napi_throw_type_error(env, nullptr, "napi_function is expected");
        }
        napi_value cb = args[0];
    
        napi_value undefined;
        status = napi_get_undefined(env, &undefined);
        assert(status == napi_ok);
    
        napi_value argv[2] = {nullptr};
        status = napi_create_int32(env, 1, &argv[0]);
        assert(status == napi_ok);
        status = napi_create_int32(env, 2, &argv[1]);
        assert(status == napi_ok);
    
        napi_value result;
        status = napi_call_function(env, undefined, cb, 2, argv, &result);
        assert(status == napi_ok);
    
        return nullptr;
    }
    EXTERN_C_START 
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            {"nativeCall", nullptr, NativeCall, nullptr, nullptr, nullptr, napi_default, nullptr}};
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    static napi_module module = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "callback",
        .nm_priv = nullptr,
        .reserved = {0},
    };
    extern "C" __attribute__((constructor)) void RegisterCallbackModule(void)
    {
        napi_module_register(&module);
    }
    ```

3. Promise implementation:

    ```cpp
    #include "napi/native_api.h"
    
    // Empty value so that macros here are able to return NULL or void
    #define NAPI_RETVAL_NOTHING // Intentionally blank
    
    #define GET_AND_THROW_LAST_ERROR(env)
    do
    {
        const napi_extended_error_info *errorInfo = nullptr;
        napi_get_last_error_info((env), &errorInfo);
        bool isPending = false;
        napi_is_exception_pending((env), &isPending);
        if (!isPending && errorInfo != nullptr)
        {
            const char *errorMessage = 
                errorInfo->error_message != nullptr ? errorInfo->error_message : "empty error message";
            napi_throw_error((env), nullptr, errorMessage);
        }
    } while (0)
    
    #define NAPI_ASSERT_BASE(env, assertion, message, retVal)
    do {
        if (!(assertion))
        {
            napi_throw_error((env), nullptr, "assertion(" #assertion ") failed : " message);
            return retVal;
        }
    } while (0)
    
    #define NAPI_ASSERT(env, assertion, message) NAPI_ASSERT_BASE(env, assertion, message, nullptr)
    
    #define NAPI_ASSERT_RETURN_VOID(env, assertion, message) 
        NAPI_ASSERT_BASE(env, assertion, message, NAPI_RETVAL_NOTHING)
    
    #define NAPI_CALL_BASE(env, theCall, retVal)
        do
        {
            if ((theCall) != napi_ok)
            {
                GET_AND_THROW_LAST_ERROR((env));
                return retVal;
            }
        } while (0)
    
    #define NAPI_CALL(env, theCall) NAPI_CALL_BASE(env, theCall, nullptr)
    
    #define NAPI_CALL_RETURN_VOID(env, theCall) NAPI_CALL_BASE(env, theCall, NAPI_RETVAL_NOTHING)
    
    struct AsyncData{
        napi_deferred deferred;
        napi_async_work work;
    
        int32_t arg;
        double retVal;
    };
    
    double DoSomething(int32_t val)
    {
        if (val != 0)
        {
            return 1.0 / val;
        }
        return 0;
    }
    
    void ExecuteCallback(napi_env env, void *data)
    {
        AsyncData* asyncData = reinterpret_cast<AsyncData*>(data);
        asyncData->retVal = DoSomething(asyncData->arg);
    }
    
    void CompleteCallback(napi_env env, napi_status status, void *data)
    {
        AsyncData* asyncData = reinterpret_cast<AsyncData*>(data);
    
        napi_value retVal;
        if (asyncData->retVal == 0)
        {
            NAPI_CALL_RETURN_VOID(env, napi_create_string_utf8(env, "arg can't be zero", NAPI_AUTO_LENGTH, &retVal));
            NAPI_CALL_RETURN_VOID(env, napi_reject_deferred(env, asyncData->deferred, retVal));
        }
        else
        {
            NAPI_CALL_RETURN_VOID(env, napi_create_double(env, asyncData->retVal, &retVal));
            NAPI_CALL_RETURN_VOID(env, napi_resolve_deferred(env, asyncData->deferred, retVal));
        }
    
        NAPI_CALL_RETURN_VOID(env, napi_delete_async_work(env, asyncData->work));
        asyncData->work = nullptr;
        asyncData->deferred = nullptr;
        delete asyncData;
    }
    
    static napi_value NativeCall(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = {nullptr};
        NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, nullptr, nullptr));
    
        int32_t arg;
        NAPI_CALL(env, napi_get_value_int32(env, args[0], &arg));
    
        // Create promise
        napi_deferred deferred;
        napi_value promise;
        NAPI_CALL(env, napi_create_promise(env, &deferred, &promise));
    
        AsyncData *data = new AsyncData;
        data->deferred = deferred;
        data->arg = arg;
    
        napi_async_work work;
        napi_value workName;
        napi_create_string_utf8(env, "promise", NAPI_AUTO_LENGTH, &workName);
        NAPI_CALL(env, napi_create_async_work(env, nullptr, workName,
            ExecuteCallback, CompleteCallback, data, &work));
    
        data->work = work;
        NAPI_CALL(env, napi_queue_async_work(env, work));
    
        return promise;
    }
    
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            {"nativeCall", nullptr, NativeCall, nullptr, nullptr, nullptr, napi_default, nullptr}
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    
    static napi_module demoModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "promise",
        .nm_priv = nullptr,
        .reserved = {0},
    };
    
    extern "C" __attribute__((constructor)) void RegisterPromiseModule(void)
    {
        napi_module_register(&demoModule);
    }
    ```

4. To use libuv, import the libuv library.

## How is a raw file read by the thread created by pthread? (API version 10)

**Solution**

The raw file can be read by a thread-safe function:
1. Obtain and save a resource file object via the UI main thread.
2. Create a thread-safe function.
3. Call the thread-safe function in a non-main thread.
4. Read the file resources in **rawfile** via the thread-safe function.

## How is the processing result of a c++ thread created by an ArkTS thread using Node-API returned to the ArkTS thread? (API version 10)

**Solution**

Use **napi_create_threadsafe_function** to create a function that can be called by any thread in the ArkTS thread. Call **napi_call_threadsafe_function** in the C++ thread to return the result to the main thread.

**References**

[Thread Safety Development Using Node-API](../napi/use-napi-thread-safety.md)

## What should I do to permanently hold a JS object created by napi_create_object or passed in as a parameter? (API version 10)

**Question**

What should I do if I need to permanently hold a JS object created by **napi_create_object** or passed in as a parameter, and destroy, increment, and decrement the reference count?

**Solution**

To hold an object persistently, use **napi_create_reference** to create a strong reference and then save the reference for use. To destroy a reference, use **napi_delete_reference**. To increment the reference count, use **napi_reference_ref**; to decrement the reference count, use **api_reference_unref**.

## Can messages from C++ be passed to an ArkTS callback or object wrapped in a native object and synced to the application? (API version 11)

**Question**

Can messages from C++ be synced to an application via an ArkTS callback or object wrapped in a native object? Can **napi_env** of the ArkTS object or function be held permanently? Does a specific thread is required for syncing messages to an application?

**Solution**

An ArkTS object or function cannot be wrapped to a native object. You need to implement the related processing in C++. **env** can be held for a long period of time, but must be used in the ArkTS thread that creates **env**.

**Reference**

1. [Wrapping a Native Object in an ArkTS Object](../napi/use-napi-object-wrap.md)

