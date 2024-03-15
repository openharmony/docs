# NDK开发常见问题


## 以libstd为例，C++的标准库放在哪里了，有没有打到hap包中？(API 10)

**解决方案**

libc++_shared.so被打包到应用目录下了，每个应用都有一份独立的libc++_shared.so (/data/storage/el1/bundle/libs/${arch})

## C/C++的三方开源库如何迁移到系统下运行？(API 10)

**解决方案**

当前官方SDK只支持Cmake构建，同时对于依赖GN构建的场景提供了迁移指导

**参考资料**

1. GN构建：  

    [基于gn_example编译三方库代码](https://gitee.com/openharmony/build/wikis/gn%E6%9E%84%E5%BB%BA%E4%B8%89%E6%96%B9%E5%BA%93/%E5%9F%BA%E4%BA%8Egn_example%E7%BC%96%E8%AF%91%E4%B8%89%E6%96%B9%E5%BA%93%E4%BB%A3%E7%A0%81)  

    [基于三方编译框架移植OHOS](https://gitee.com/openharmony/build/wikis/gn%E6%9E%84%E5%BB%BA%E4%B8%89%E6%96%B9%E5%BA%93/%E5%9F%BA%E4%BA%8E%E4%B8%89%E6%96%B9%E7%BC%96%E8%AF%91%E6%A1%86%E6%9E%B6%E7%A7%BB%E6%A4%8DOHOS)

2. CMake构建： 

    linux：[HOW TO USE NDK (linux)](https://gitee.com/openharmony/build/wikis/NDK/HOW%20TO%20USE%20NDK%20(linux))  

    windows：[HOW TO USE NDK (windows)](https://gitee.com/openharmony/build/wikis/NDK/HOW%20TO%20USE%20NDK%20(windows))

## 开发者使用napi扩展TS接口时，常用的属性和实现接口的基本用法是什么？例如怎么获取env，怎么实现callback和promise，怎么使用libuv？(API 10)



**解决方案**

1. env是使用napi的模块化编程，注册模块之后，调用回调的时候会通过回调函数调用过来：

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

2. callback实现：

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

3. promise实现参考：

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

4. libuv使用：可以直接导入libuv三方库使用

## pthread创建的线程中如何读取rawfile？(API 10)

**解决方案**

可在线程安全函数中读取：
1. UI 主线程中获取并保存资源文件对象;
2. 创建线程安全函数;
3. 在非UI主线程中调用线程安全函数;
4. 在线程安全函数中，读取rawfile下的文件资源。

## ArkTS线程通过napi创建的C++线程的处理结果如何返回ArkTS线程？(API 10)

**解决方案**

采用napi_create_threadsafe_function在ArkTS线程创建可被任意线程调用的函数，在C++线程调用napi_call_threadsafe_function可以将结果回调给主线程。

**参考链接**

[使用Node-API接口进行线程安全开发](../napi/use-napi-thread-safety.md)

## 由napi_create_object创建，或者作为参数传下来的JS对象，如果想持久持有，需要怎么做？(API 10)

**问题描述**

以及，怎么主动销毁或减少引用计数？

**解决方案**

持久持有一个对象，可以通过napi_create_reference创建一个强引用，然后将这个ref保存下来使用；主动销毁可以使用napi_delete_reference，减少或者增加引用计数可以通过napi_reference_unref或者napi_reference_ref。

## 在ArkTS层往C++层注册一个对象或函数，C++层可以按需往这个回调上进行扔消息同步到上层应用么？(API 11)

**问题描述**

以及，在注册对象或函数时，napi_env是否可以被长时持有？扔消息同步到上层应用时，是否需要在特定线程？

**解决方案**

纯在ArkTS侧不可以往C++层注册对象或者函数，开发者需要回到C++层自己处理；env可以长期持有，不过使用env时，需要在特定的线程，使用env时需要在创建该env的ArkTS线程使用。

**参考资料**

1. [Native与ArkTS对象绑定](../napi/use-napi-object-wrap.md)
