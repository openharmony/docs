# 使用Node-API调用返回值为promise的ArkTS方法
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 场景介绍
当ArkTS的返回值为Promise时，可以按以下方式在创建的ArkTS运行环境中调用异步接口。

## 调用异步的ArkTS接口示例
使用C++通过NAPI调用返回Promise的ArkTS方法。

处理Promise对象：将Promise与C++回调绑定，处理异步结果。

转换数据类型：在回调中将JavaScript结果转换为c++可用的数据。

### 示例代码
- 模块注册
    ```c++
    #include "hilog/log.h"
    #include "napi/native_api.h"
    
    //解析Promise结果的回调
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
    
    //拒绝Promise的回调
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
        // 初始化Promise对象
        napi_value promise = nullptr;
        napi_call_function(env, nullptr, argv[0], 0, nullptr, &promise);
    
        // 初始化thenFunc对象
        napi_value thenFunc = nullptr;
        if (napi_get_named_property(env, promise, "then", &thenFunc) != napi_ok) {
            return nullptr;
        }
        // 初始化onResolve对象
        napi_value onResolve = nullptr;
        // 初始化onReject对象
        napi_value onReject = nullptr;
        napi_create_function(env, "onResolve", NAPI_AUTO_LENGTH, ResolvedCallback, nullptr, &onResolve);
        napi_create_function(env, "onReject", NAPI_AUTO_LENGTH, RejectedCallback, nullptr, &onReject);
        // 创建参数数组
        napi_value argv1[2] = {onResolve, onReject};
        napi_call_function(env, promise, thenFunc, 2, argv1, nullptr);
    
        return nullptr;
    }
    
    // 注册模块接口
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        // 初始化属性描述数组
        napi_property_descriptor desc[] = {
            {"callArkTSAsync", nullptr, CallArkTSAsync, nullptr, nullptr, nullptr, napi_default, nullptr}
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    
    // 初始化模块
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

- 接口声明
    ```ts
    // index.d.ts
    export const callArkTSAsync: (func: Function) => object;
    ```

- CMakeLists.txt文件需要按照以下配置：

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

- ArkTS代码示例
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
