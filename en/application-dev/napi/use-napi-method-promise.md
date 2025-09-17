# Calling an ArkTS Method with Return Value of a promise Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## When to Use
You can call the ArkTS APIs, which return a promise, in the created ArkTS runtime environment as follows:

## Calling an ArkTS Method Asynchronously
Use C++ to call the ArkTS method that returns a promise through the Node-API.

Handle the promise object: Bind the promise object to a C++ callback to process the result returned asynchronously.

Convert the data type: In the callback, convert the JavaScript (JS) result to the data that can be used by C++.

### Sample Code
- Register the module.
    ```c++
    #include "hilog/log.h"
    #include "napi/native_api.h"
    
    // Callback for processing a resolved promise.
    static napi_value ResolvedCallback(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = { nullptr };
        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
        int result = 0;
        napi_get_value_int32(env, args[0], &result);
        OH_LOG_INFO(LOG_APP, "Promise resolved with result:%{public}d", result);
        return nullptr;
    }
    
    // Callback for processing a rejected promise.
    static napi_value RejectedCallback(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = { nullptr };
        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
        napi_value error = nullptr;
        napi_coerce_to_string(env, args[0], &error);
        char errorMsg[1024];
        size_t len;
        napi_get_value_string_utf8(env, error, errorMsg, sizeof(errorMsg), &len);
        OH_LOG_ERROR(LOG_APP, "Promise rejected with error:%{public}s", errorMsg);
        return nullptr;
    }
    
    static napi_value CallArkTSAsync(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value argv[1] = { nullptr };
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
        // Initialize the promise object.
        napi_value promise = nullptr;
        napi_call_function(env, nullptr, argv[0], 0, nullptr, &promise);
    
        // Initialize the thenFunc object.
        napi_value thenFunc = nullptr;
        if (napi_get_named_property(env, promise, "then", &thenFunc) != napi_ok) {
            return nullptr;
        }
        // Initialize the onResolve object.
        napi_value onResolve = nullptr;
        // Initialize the onReject object.
        napi_value onReject = nullptr;
        napi_create_function(env, "onResolve", NAPI_AUTO_LENGTH, ResolvedCallback, nullptr, &onResolve);
        napi_create_function(env, "onReject", NAPI_AUTO_LENGTH, RejectedCallback, nullptr, &onReject);
        // Create a parameter array.
        napi_value thenArgv[2] = {onResolve, onReject};
        napi_call_function(env, promise, thenFunc, 2, thenArgv, nullptr);
    
        return nullptr;
    }
    
    // Register the module.
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        // Initialize the attribute description array.
        napi_property_descriptor desc[] = {
            {"callArkTSAsync", nullptr, CallArkTSAsync, nullptr, nullptr, nullptr, napi_default, nullptr}
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    
    // Initialize the module.
    static napi_module nativeModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "entry",
        .nm_priv = nullptr,
        .reserved = { 0 },
    };
    
    extern "C" __attribute__((constructor)) void RegisterEntryModule()
    {
        napi_module_register(&nativeModule);
    }
    ```

- Declare APIs.
    ```ts
    // index.d.ts
    export const callArkTSAsync: (func: Function) => object;
    ```

- Configure the **CMakeLists.txt** file as follows:

    ```
    // CMakeLists.txt
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.4.1)
    project(myapplication)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)

    add_definitions( "-DLOG_DOMAIN=0xd0d0" )
    add_definitions( "-DLOG_TAG=\"testTag\"" )

    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
    ```

- ArkTS sample code
    ```ts
    // index.ets
    import testNapi from 'libentry.so';
    
    export function SetTimeout() : Promise<number> {
        return new Promise((resolve) => {
            setTimeout(() => {
                resolve(42);
            }, 1000);
        })
    }
    testNapi.callArkTSAsync(SetTimeout);
    ```
