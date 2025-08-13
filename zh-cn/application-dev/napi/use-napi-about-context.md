# 使用扩展的Node-API接口在当前线程中创建、切换和销毁上下文环境
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->
在应用被拉起时，应用的主线程即为一个ArkTS线程，该线程中存在一个由系统管理的上下文环境，当ArkTS需要和C/C++交互时，在C/C++侧，napi_env即代表该上下文环境，每个上下文环境中存在着独立的globalThis对象。开发者可以通过使用Node-API中的扩展接口napi_create_ark_context和napi_destroy_ark_context在当前线程中创建和销毁新的上下文环境，这些新创建的上下文环境和线程中原始的上下文环境共用一个运行时虚拟机。需要注意的是napi_create_ark_context接口仅仅是创建新的上下文环境，而不是创建一个新的运行时，同时通过该接口创建上下文环境，需要通过napi_destroy_ark_context接口销毁，否则会造成内存泄漏。当然ArkTS线程的原始上下文环境不能通过napi_destroy_ark_context接口销毁。当需要切换到指定的上下文环境时，可以调用Node-API中的扩展接口napi_switch_ark_context来切换到指定的上下文环境。开发者可以在一个新的上下文环境中访问globalThis上的某些属性方法，也可以在访问完之后，切回到原先的上下文环境保证上下文环境的隔离。

## 场景介绍
开发者可以通过napi_create_ark_context接口在当前的线程中创建新的上下文环境，该上下文环境拥有独立的globalThis对象。这意味着当前线程上原始的上下文环境和新创建的上下文环境是相互隔离的，即上下文环境中的globalThis对象不同。开发者可以通过新创建的上下文环境进行模块化加载，加载生成的模块化对象将挂载在当前上下文环境中的globalThis对象上，不同的模块加载在不同的上下文环境中，可以避免一个模块对globalThis对象的上属性的修改影响到另一个模块对globalThis对象上属性的访问。当然部分的Node-API标准接口和扩展接口也进行上下文的适配，这意味着调用这些Node-API的接口，上下文环境会根据接口入参的napi_env来主动进行上下文的切换动作，开发者不需要主动调用napi_switch_ark_context来进行上下文环境的切换，需要注意的是从C++/C侧回到ArkTS侧时，要主动调用napi_switch_ark_context接口将上下文环境切回到对应的上下文环境，否则会造成ArkTS侧的代码执行在另外一个上下文环境导致不可预知的稳定性问题。

## 支持多运行时上下文环境调用的NAPI接口
下列表格中的NAPI接口都支持在多上下文的环境中执行，其中部分NAPI接口会主动进行上下文的切换，即使调用方没有主动调用napi_switch_ark_context来切换运行时上下文，这部分接口仍然可以通过比较当前运行的上下文环境和接口指定的运行时环境是否一致来决定是否切换上下文环境，如果上下文环境不一致，这些NAPI接口会将当前的运行时环境切换成接口参数指定的上下文环境。当然不涉及主动切换上下文环境的接口意味着这部分接口和运行时上下文无关，使用任意一个有效的上下文环境都行正常执行。

| 接口 | 是否会主动进行上下文切换 |
| -------- | -------- |
|napi_module_register | 否 |
|napi_fatal_error | 否 |
|napi_async_init | 是 |
|napi_async_destroy | 否 |
|napi_make_callback | 是 |
|napi_create_buffer | 是 |
|napi_create_external_buffer | 是 |
|napi_create_buffer_copy | 是 |
|napi_is_buffer | 否 |
|napi_get_buffer_info | 否 |
|napi_create_async_work | 是 |
|napi_delete_async_work | 否 |
|napi_queue_async_work | 否 |
|napi_cancel_async_work | 否 |
|napi_get_node_version | 否 |
|napi_fatal_exception | 否 |
|napi_add_env_cleanup_hook | 否 |
|napi_remove_env_cleanup_hook | 否 |
|napi_open_callback_scope | 否 |
|napi_close_callback_scope | 否 |
|napi_create_threadsafe_function | 是 |
|napi_get_threadsafe_function_context | 否 |
|napi_call_threadsafe_function | 否 |
|napi_acquire_threadsafe_function | 否 |
|napi_release_threadsafe_function | 否 |
|napi_unref_threadsafe_function | 否 |
|napi_ref_threadsafe_function | 否 |
|napi_add_async_cleanup_hook | 否 |
|napi_remove_async_cleanup_hook | 否 |
node_api_get_module_file_name | 否 |
|napi_get_last_error_info | 否 |
|napi_get_undefined | 否 |
|napi_get_null | 否 |
|napi_get_global | 否 |
|napi_get_boolean | 否 |
|napi_create_object | 否 |
|napi_create_array | 否 |
|napi_create_array_with_length | 否 |
|napi_create_double | 否 |
|napi_create_int32 | 否 |
|napi_create_uint32 | 否 |
|napi_create_int64 | 否 |
|napi_create_string_latin1 | 否 |
|napi_create_string_utf8 | 否 |
|napi_create_string_utf16 | 否 |
|napi_create_symbol | 否 |
|napi_create_function | 是 |
|napi_create_error | 是 |
|napi_create_type_error | 是 |
|napi_create_range_error | 是 |
|napi_typeof | 否 |
|napi_get_value_double | 否 |
|napi_get_value_int32 | 否 |
|napi_get_value_uint32 | 否 |
|napi_get_value_int64 | 否 |
|napi_get_value_bool | 否 |
|napi_get_value_string_latin1 | 否 |
|napi_get_value_string_utf8 | 否 |
|napi_get_value_string_utf16 | 否 |
|napi_coerce_to_bool | 否 |
|napi_coerce_to_number | 是 |
|napi_coerce_to_object | 是 |
|napi_coerce_to_string | 是 |
|napi_get_prototype | 是 |
|napi_get_property_names | 是 |
|napi_set_property | 是 |
|napi_has_property | 是 |
|napi_get_property | 是 |
|napi_delete_property | 是 |
|napi_has_own_property | 是 |
|napi_set_named_property | 是 |
|napi_has_named_property | 是 |
|napi_get_named_property | 是 |
|napi_set_element | 是 |
|napi_has_element | 是 |
|napi_get_element | 是 |
|napi_delete_element | 是 |
|napi_define_properties | 是 |
|napi_is_array | 否 |
|napi_get_array_length | 否 |
|napi_strict_equals | 否 |
|napi_call_function | 否 |
|napi_new_instance | 是 |
|napi_instanceof | 是 |
|napi_get_cb_info | 否 |
|napi_get_new_target | 否 |
|napi_define_class | 是 |
|napi_wrap | 是 |
|napi_unwrap | 是 |
|napi_remove_wrap | 是 |
|napi_create_external | 否 |
|napi_get_value_external | 否 |
|napi_create_reference | 否 |
|napi_delete_reference | 否 |
|napi_reference_ref | 否 |
|napi_reference_unref | 否 |
|napi_get_reference_value | 否 |
|napi_open_handle_scope | 否 |
|napi_close_handle_scope | 否 |
|napi_open_escapable_handle_scope | 否 |
|napi_close_escapable_handle_scope | 否 |
|napi_escape_handle | 否 |
|napi_throw | 否 |
|napi_throw_error | 是 |
|napi_throw_type_error | 是 |
|napi_throw_range_error | 是 |
|napi_is_error | 否 |
|napi_is_exception_pending | 否 |
|napi_get_and_clear_last_exception | 否 |
|napi_is_arraybuffer | 否 |
|napi_create_arraybuffer | 否 |
|napi_create_external_arraybuffer | 否 |
|napi_get_arraybuffer_info | 否 |
|napi_is_typedarray | 否 |
|napi_create_typedarray | 否 |
|napi_get_typedarray_info | 否 |
|napi_create_dataview | 是 |
|napi_is_dataview | 否 |
|napi_get_dataview_info | 否 |
|napi_get_version | 否 |
|napi_create_promise | 是 |
|napi_resolve_deferred | 否 |
|napi_reject_deferred | 否 |
|napi_is_promise | 否 |
|napi_run_script | 否 |
|napi_create_date | 是 |
|napi_is_date | 否 |
|napi_get_date_value | 否 |
|napi_add_finalizer | 否 |
|napi_create_bigint_int64 | 否 |
|napi_create_bigint_uint64 | 否 |
|napi_create_bigint_words | 是 |
|napi_get_value_bigint_int64 | 否 |
|napi_get_value_bigint_uint64 | 否 |
|napi_get_value_bigint_words | 否 |
|napi_get_all_property_names | 否 |
|napi_set_instance_data | 否 |
|napi_get_instance_data | 否 |
|napi_detach_arraybuffer | 否 |
|napi_is_detached_arraybuffer | 否 |
|napi_type_tag_object | 否 |
|napi_check_object_type_tag | 是 |
|napi_object_freeze | 是 |
|napi_object_seal | 是 |
|napi_run_script_path | 是 |
|napi_queue_async_work_with_qos | 否 |
|napi_load_module | 是 |
|napi_create_object_with_properties | 是 |
|napi_create_object_with_named_properties | 是 |
|napi_coerce_to_native_binding_object | 是 |
|napi_load_module_with_info | 是 |
|napi_create_ark_runtime | 否 |
|napi_destroy_ark_runtime | 否 |
|napi_serialize | 是 |
|napi_deserialize | 是 |
|napi_delete_serialization_data | 否 |
|napi_call_threadsafe_function_with_priority | 否 |
|napi_wrap_enhance | 是 |

## 不支持多运行时上下文环境调用的NAPI接口
| 接口 | 多运行时上下文环境调用返回值 |
| -------- | -------- |
|napi_define_sendable_class | napi_invalid_arg |
|napi_is_sendable | napi_invalid_arg |
|napi_create_sendable_object_with_properties | napi_invalid_arg |
|napi_wrap_sendable | napi_invalid_arg |
|napi_wrap_sendable_with_size | napi_invalid_arg |
|napi_unwrap_sendable | napi_invalid_arg |
|napi_remove_wrap_sendable | napi_invalid_arg |
|napi_create_sendable_array | napi_invalid_arg |
|napi_create_sendable_array_with_length | napi_invalid_arg |
|napi_create_sendable_arraybuffer | napi_invalid_arg |
|napi_create_sendable_typedarray | napi_invalid_arg |
|napi_run_event_loop | napi_invalid_arg |
|napi_stop_event_loop | napi_invalid_arg |
|napi_get_uv_event_loop | napi_invalid_arg |

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
            OH_LOG_INFO(LOG_APP, "load plugin1 failed");
        }
        // 获取模块plugin1中的方法GetLocation
        napi_value getLocation1 = nullptr;
        status = napi_get_named_property(env, plugin1, "GetLocation", &getLocation1);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "obtain GetLocation from plugin1 failed");
        }
        // 创建新的上下文环境newEnv2
        napi_env newEnv2 = nullptr;
        status = napi_create_ark_context(env, &newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        // 主动切换到新的上下文环境newEnv2
        status = napi_switch_ark_context(newEnv2);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "switch to newEnv2 failed");
        }
        napi_value plugin2 = nullptr;
        // 在新的上下文环境中加载模块plugin2.ets
        status = napi_load_module_with_info(newEnv2, "entry/src/main/ets/pages/plugin2", "com.example.myapplication/entry",
                                            &plugin2);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "load plugin2 failed");
        }

        napi_value getLocation2 = nullptr;
        status = napi_get_named_property(newEnv2, plugin2, "GetLocation", &getLocation2);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "obtain GetLocation from plugin2 failed");
        }
    
        // 在新上下文环境中执行ArkTS侧的方法getLocation, 入参为模块plugin2中的方法GetLocation
        napi_value result = nullptr;
        napi_value args2[1] = {};
        args2[0] = getLocation2;

        status = napi_call_function(newEnv2, nullptr, args[0], 1, args2, &result);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "napi_get_global of env failed");
            return nullptr;
        }
        status = napi_call_function(newEnv2, globalObj, args[0], 1, args2, &result);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "call function of env failed");
        }
        int32_t ret = 0;
        status = napi_get_value_int32(newEnv2, result, &ret);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "napi_get_value_int32 of env failed");
        } else {
            // plugin2的上下文中globalThis.a为3000
            OH_LOG_INFO(LOG_APP, "ret is %{public}d", ret); // 3000
        }
        // 主动切回原始上下文环境env
        status = napi_switch_ark_context(env);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "switch to env failed");
        }
        args2[0] = getLocation1;
        status = napi_call_function(env, nullptr, args[0], 1, args2, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // 获取GetLocation接口调用之后的返回值
        ret = 0;
        status = napi_get_value_int32(env, result, &ret);
        if (status != napi_ok) {
            return nullptr;
        } else {
            // plugin1的上下文中globalThis.a为2000
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
                nullptr, nullptr, nullptr, napi_default, nullptr}
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
                        ${NATIVERENDER_ROOT_PATH}/include)

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