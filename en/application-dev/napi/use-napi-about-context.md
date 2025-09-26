# Creating, Switching, and Destroying a Context in a Thread Using Node-API Extension APIs
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->
When an application is started, the main thread of the application is an ArkTS thread, which has a context managed by the system. When ArkTS interacts with C/C++, **napi_env** represents the context on the C/C++ side. Every context has an independent **globalThis** object.

You can use the extension APIs **napi_create_ark_context** and **napi_destroy_ark_context** in Node-API to create and destroy a new context in the current thread. The new context and the original context in the thread share the same runtime virtual machine.

Note that **napi_create_ark_context** creates a new context but not a new runtime. The context created by this API must be destroyed by **napi_destroy_ark_context**. Otherwise, memory leaks may occur.

The original context of the ArkTS thread cannot be destroyed using the **napi_destroy_ark_context** API.

To switch to a specified context, you can call the extension API **napi_switch_ark_context** in the Node-API.

You can access some properties and methods on **globalThis** in a new context, and then switch back to the original context to ensure context isolation.

## Scenario
You can use the **napi_create_ark_context** API to create a context environment in the current thread, which has an independent **globalThis** object.

This indicates that the original context on the current thread is isolated from the newly created context , that is, the **globalThis** objects in the contexts are different.

You can use the newly created context to load modular objects, which are mounted to the **globalThis** object in the current context. Different modules are loaded to different contexts. This prevents one module's changes to **globalThis** from affecting another module's access to **globalThis**.

Some standard and extension APIs of the Node-API are context-adaptive. When these APIs are called, the context is automatically switched based on the input parameter **napi_env**. You do not need to call **napi_switch_ark_context** to switch the context.

Note that when returning from the C++/C side to the ArkTS side, you need to call **napi_switch_ark_context** to switch the context back to the corresponding context. Otherwise, the ArkTS code will be executed in another context, causing unpredictable stability issues.

## Node-APIs That Support Multi-Runtime Context
The following table lists the Node-APIs that can be executed in a multi-context environment. Some of these Node-APIs can automatically switch the context.

Even if **napi_switch_ark_context** is not actively called to switch the runtime context, these APIs can still determine whether to switch the context by comparing whether the runtime context is the same as the runtime environment specified by the API.

If the contexts are inconsistent, these Node-APIs switch the current runtime environment to the context specified by the API parameters.

If an API does not involve context switching, it is irrelevant to the runtime context and can be executed in any valid context.

| API| Whether to Proactively Switch the Context|
| -------- | -------- |
|napi_module_register | No|
|napi_fatal_error | No|
|napi_async_init | Yes|
|napi_async_destroy | No|
|napi_make_callback | Yes|
|napi_create_buffer | Yes|
|napi_create_external_buffer | Yes|
|napi_create_buffer_copy | Yes|
|napi_is_buffer | No|
|napi_get_buffer_info | No|
|napi_create_async_work | Yes|
|napi_delete_async_work | No|
|napi_queue_async_work | No|
|napi_cancel_async_work | No|
|napi_get_node_version | No|
|napi_fatal_exception | No|
|napi_add_env_cleanup_hook | No|
|napi_remove_env_cleanup_hook | No|
|napi_open_callback_scope | No|
|napi_close_callback_scope | No|
|napi_create_threadsafe_function | Yes|
|napi_get_threadsafe_function_context | No|
|napi_call_threadsafe_function | No|
|napi_acquire_threadsafe_function | No|
|napi_release_threadsafe_function | No|
|napi_unref_threadsafe_function | No|
|napi_ref_threadsafe_function | No|
|napi_add_async_cleanup_hook | No|
|napi_remove_async_cleanup_hook | No|
node_api_get_module_file_name | No|
|napi_get_last_error_info | No|
|napi_get_undefined | No|
|napi_get_null | No|
|napi_get_global | No|
|napi_get_boolean | No|
|napi_create_object | No|
|napi_create_array | No|
|napi_create_array_with_length | No|
|napi_create_double | No|
|napi_create_int32 | No|
|napi_create_uint32 | No|
|napi_create_int64 | No|
|napi_create_string_latin1 | No|
|napi_create_string_utf8 | No|
|napi_create_string_utf16 | No|
|napi_create_symbol | No|
|napi_create_function | Yes|
|napi_create_error | Yes|
|napi_create_type_error | Yes|
|napi_create_range_error | Yes|
|napi_typeof | No|
|napi_get_value_double | No|
|napi_get_value_int32 | No|
|napi_get_value_uint32 | No|
|napi_get_value_int64 | No|
|napi_get_value_bool | No|
|napi_get_value_string_latin1 | No|
|napi_get_value_string_utf8 | No|
|napi_get_value_string_utf16 | No|
|napi_coerce_to_bool | No|
|napi_coerce_to_number | Yes|
|napi_coerce_to_object | Yes|
|napi_coerce_to_string | Yes|
|napi_get_prototype | Yes|
|napi_get_property_names | Yes|
|napi_set_property | Yes|
|napi_has_property | Yes|
|napi_get_property | Yes|
|napi_delete_property | Yes|
|napi_has_own_property | Yes|
|napi_set_named_property | Yes|
|napi_has_named_property | Yes|
|napi_get_named_property | Yes|
|napi_set_element | Yes|
|napi_has_element | Yes|
|napi_get_element | Yes|
|napi_delete_element | Yes|
|napi_define_properties | Yes|
|napi_is_array | No|
|napi_get_array_length | No|
|napi_strict_equals | No|
|napi_call_function | No|
|napi_new_instance | Yes|
|napi_instanceof | Yes|
|napi_get_cb_info | No|
|napi_get_new_target | No|
|napi_define_class | Yes|
|napi_wrap | Yes|
|napi_unwrap | Yes|
|napi_remove_wrap | Yes|
|napi_create_external | No|
|napi_get_value_external | No|
|napi_create_reference | No|
|napi_delete_reference | No|
|napi_reference_ref | No|
|napi_reference_unref | No|
|napi_get_reference_value | No|
|napi_open_handle_scope | No|
|napi_close_handle_scope | No|
|napi_open_escapable_handle_scope | No|
|napi_close_escapable_handle_scope | No|
|napi_escape_handle | No|
|napi_throw | No|
|napi_throw_error | Yes|
|napi_throw_type_error | Yes|
|napi_throw_range_error | Yes|
|napi_is_error | No|
|napi_is_exception_pending | No|
|napi_get_and_clear_last_exception | No|
|napi_is_arraybuffer | No|
|napi_create_arraybuffer | No|
|napi_create_external_arraybuffer | No|
|napi_get_arraybuffer_info | No|
|napi_is_typedarray | No|
|napi_create_typedarray | No|
|napi_get_typedarray_info | No|
|napi_create_dataview | Yes|
|napi_is_dataview | No|
|napi_get_dataview_info | No|
|napi_get_version | No|
|napi_create_promise | Yes|
|napi_resolve_deferred | No|
|napi_reject_deferred | No|
|napi_is_promise | No|
|napi_run_script | No|
|napi_create_date | Yes|
|napi_is_date | No|
|napi_get_date_value | No|
|napi_add_finalizer | No|
|napi_create_bigint_int64 | No|
|napi_create_bigint_uint64 | No|
|napi_create_bigint_words | Yes|
|napi_get_value_bigint_int64 | No|
|napi_get_value_bigint_uint64 | No|
|napi_get_value_bigint_words | No|
|napi_get_all_property_names | No|
|napi_set_instance_data | No|
|napi_get_instance_data | No|
|napi_detach_arraybuffer | No|
|napi_is_detached_arraybuffer | No|
|napi_type_tag_object | No|
|napi_check_object_type_tag | Yes|
|napi_object_freeze | Yes|
|napi_object_seal | Yes|
|napi_run_script_path | Yes|
|napi_queue_async_work_with_qos | No|
|napi_load_module | Yes|
|napi_create_object_with_properties | Yes|
|napi_create_object_with_named_properties | Yes|
|napi_coerce_to_native_binding_object | Yes|
|napi_load_module_with_info | Yes|
|napi_create_ark_runtime | No|
|napi_destroy_ark_runtime | No|
|napi_serialize | Yes|
|napi_deserialize | Yes|
|napi_delete_serialization_data | No|
|napi_call_threadsafe_function_with_priority | No|
|napi_wrap_enhance | Yes|

## Node-APIs That Do Not Support Multi-Runtime Context
| API| Return Value of Multi-Runtime Context Call|
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

### Sample Code
- Register the module.
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
        // Load the plugin1.ets module in the original context.
        napi_value plugin1 = nullptr;
        status = napi_load_module_with_info(env, "entry/src/main/ets/pages/plugin1", "com.example.myapplication/entry", &plugin1);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "load plugin1 failed");
        }
        // Obtain the GetLocation method in the plugin1 module.
        napi_value getLocation1 = nullptr;
        status = napi_get_named_property(env, plugin1, "GetLocation", &getLocation1);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "obtain GetLocation from plugin1 failed");
        }
        // Create a new context newEnv2.
        napi_env newEnv2 = nullptr;
        status = napi_create_ark_context(env, &newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        // Proactively switch to the new context newEnv2.
        status = napi_switch_ark_context(newEnv2);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "switch to newEnv2 failed");
        }
        napi_value plugin2 = nullptr;
        // Load the plugin2.ets module in the new context.
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
    
        // Execute the getLocation method on the ArkTS side in the new context. The input parameter is the GetLocation method in the plugin2 module.
        napi_value result = nullptr;
        napi_value args2[1] = {};
        args2[0] = getLocation2;

        status = napi_call_function(newEnv2, nullptr, args[0], 1, args2, &result);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "call function of env failed");
        }
        int32_t ret = 0;
        status = napi_get_value_int32(newEnv2, result, &ret);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "napi_get_value_int32 of env failed");
        } else {
            // The value of globalThis.a in the context of plugin2 is 3000.
            OH_LOG_INFO(LOG_APP, "ret is %{public}d", ret); // 3000
        }
        // Proactively switch back to the original context env.
        status = napi_switch_ark_context(env);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "switch to env failed");
        }
        args2[0] = getLocation1;
        status = napi_call_function(env, nullptr, args[0], 1, args2, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // Obtain the value returned after the GetLocation API is called.
        ret = 0;
        status = napi_get_value_int32(env, result, &ret);
        if (status != napi_ok) {
            return nullptr;
        } else {
            // The value of globalThis.a in the context of plugin1 is 2000.
            OH_LOG_INFO(LOG_APP, "ret is %{public}d", ret); // 2000
        }
        // Destroy the created context.
        status = napi_destroy_ark_context(newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        return result;
    }

    // Register the module.
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
- API declaration
    ```ts
    // index.d.ts
    export const callFunctionInContext: (func: (func:()=>number)=>{}) => number;
    ```

- Compilation configuration
1. Configure the **CMakeLists.txt** file as follows:
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

2. Add the following to the **build-profile.json5** file of the project.
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

- ArkTS sample code
    ```ts
    // index.ets
    import testNapi from "libentry.so"
    // Execute the GetLocation method in the plugin1 or plugin2 module.
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
