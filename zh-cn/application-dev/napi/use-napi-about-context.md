# 使用扩展的Node-API接口在当前线程中创建、切换和销毁上下文环境
在应用被拉起时，应用的主线程即为一个ArkTS线程，该线程中存在一个由系统管理的上下文环境，当ArkTS需要和C/C++交互时，在C/C++侧，napi_env即代表该上下文环境，每个上下文环境中存在着独立的globalThis对象。开发者可以通过使用Node-API中的扩展接口napi_create_ark_context和napi_destroy_ark_context在当前线程中创建和销毁新的上下文环境，这些新创建的上下文环境和线程中原始的上下文环境共用一个运行时虚拟机。需要注意的是napi_create_ark_context接口仅仅是创建新的上下文环境，而不是创建一个新的运行时，同时通过该接口创建上下文环境，需要通过napi_destroy_ark_context接口销毁，否则会造成内存泄漏。当然ArkTS线程的原始上下文环境不能通过napi_destroy_ark_context接口销毁。

## 场景介绍
开发者可以通过napi_create_ark_context接口在当前的线程中创建新的上下文环境，该上下文环境拥有独立的globalThis对象。这意味着当前线程上原始的上下文环境和新创建的上下文环境是相互隔离的，即上下文环境中的globalThis对象不同。开发者可以通过新创建的上下文环境进行模块化加载，加载生成的模块化对象将挂载在当前上下文环境中的globalThis对象上，不同的模块加载在不同的上下文环境中，可以避免一个模块对globalThis对象的上属性的修改影响到另一个模块对globalThis对象上属性的访问。

### 示例代码
- 模块注册
    ```c++
    // napi_init.cpp
    #include "napi/native_api.h"
    #include "hilog/log.h"

    static napi_value NAPI_Global_callFunctionInContext(napi_env env, napi_callback_info info)
    {
        napi_status status = napi_ok;
        size_t argc = 1;
        napi_value args[1] = {nullptr};
        if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
            return nullptr;
        }
        // 在原始上下文中加载模块plugin1.ets
        napi_value plugin1 = nullptr;
        status = napi_load_module_with_info(env, "entry/src/main/ets/pages/plugin1", "com.example.myapplication/entry", &plugin1);
        if (status != napi_ok) {
            return nullptr;
        }
        // 获取模块plugin1中的方法GetLocation
        napi_value getLocation1 = nullptr;
        status = napi_get_named_property(env, plugin1, "GetLocation", &getLocation1);
        if (status != napi_ok) {
            return nullptr;
        }
        // 创建新的上下文环境newEnv2
        napi_env newEnv2 = nullptr;
        status = napi_create_ark_context(env, &newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }

        // 在原始的上下文环境中执行ArkTS侧的方法getLocation, 入参为模块plugin1中的方法GetLocation
        napi_value result = nullptr;
        napi_value argss[1] = {};
        argss[0] = getLocation1;
        status = napi_call_function(env, nullptr, args[0], 1, argss, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // 获取GetLocation接口调用之后的返回值
        int32_t ret = 0;
        status = napi_get_value_int32(env, result, &ret);
        if (status != napi_ok) {
            return nullptr;
        } else {
            OH_LOG_INFO(LOG_APP, "ret is %{public}d", ret); // 2000
        }
        // 销毁创建的上下文环境
        status = napi_destroy_ark_context(newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        return result;
    }

    // 模块注册
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports) {
        napi_property_descriptor desc[] = {
            {"callFunctionInContext", nullptr, NAPI_Global_callFunctionInContext,
                nullptr, nullptr, nullptr, napi_default, nullptr }
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
        .nm_modname = "entry",
        .nm_priv = ((void*)0),
        .reserved = { 0 },
    };

    extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
    {
        napi_module_register(&demoModule);
    }
    ```
- 接口声明
    ```ts
    // index.d.ts
    export const callFunctionInContext: (func: (func:()=>number)=>{}) => number;
    ```

- 编译配置
1. CMakeLists.txt文件需要按照如下配置
    ```
    // CMakeLists.txt
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(MyApplication8)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    add_definitions( "-DLOG_DOMAIN=0xd0d0" )
    add_definitions( "-DLOG_TAG=\"testTag\"")

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include
                        ${NATIVERENDER_ROOT_PATH}/utils/include)

    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
    ```

2. 需要在工程的build-profile.json5文件中进行以下配置
    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "sources": [
                        "./src/main/ets/pages/plugin1.ets",
                        "./src/main/ets/pages/plugin2.ets"
                    ]
                }
            }
        }
    }
    ```

- ArkTS代码示例
    ```ts
    // index.ets
    import testNapi from "libentry.so"
    // 该接口用于执行模块plugin1或plugin2中的GetLocation方法
    function getLocation(func: () => number) {
        return func();
    }
    testNapi.callFunctionInContext(getLocation)
    ```
    ```ts
    // ets/pages/plugin1.ets
    globalThis.a = 2000;

    export function GetLocation() : number {
        return globalThis.a;
    }
    ```
    ```ts
    // ets/pages/plugin2.ets
    globalThis.a = 3000;

    export function GetLocation() : number {
    return globalThis.a;
    }
    ```
