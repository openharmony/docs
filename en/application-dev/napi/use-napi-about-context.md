# Creating, Switching, and Destroying Contexts in the Current Thread Using Extended Node-APIs
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->
When an application is started, the main thread of the application is an ArkTS thread. The thread has a context environment managed by the system. When ArkTS needs to interact with C/C++, napi_env represents the context environment on the C/C++ side, each context has an independent globalThis object. Developers can create and destroy new context environments in the calling thread by using the extended interfaces napi_create_ark_context and napi_destroy_ark_context in the Node-API. The newly created context environments and the original context environment in the thread share a runtime virtual machine. Note that the napi_create_ark_context interface is only used to create a new context environment instead of a new runtime environment. When this interface is used to create a context environment, the napi_destroy_ark_context interface must be used to destroy the context environment. Otherwise, memory leakage occurs. The original context of the ArkTS thread cannot be destroyed using the napi_destroy_ark_context API. When you need to switch to a specified context, you can call the extended interface napi_switch_ark_context in the Node-API to switch to the specified context. Developers can access some attribute methods on globalThis in a new context environment or switch back to the original context environment after the access is complete to ensure context environment isolation.

## When to Use
You can use the napi_create_ark_context API to create a context environment in the current thread. The context environment has an independent globalThis object. This means that the original context environment and the newly created context environment on the calling thread are isolated from each other, that is, the globalThis object in the context environment is different. You can use the newly created context environment to perform modular loading. The generated modular object is mounted to the globalThis object in the current context environment. Different modules are loaded in different context environments, this prevents the modification of the attributes of the globalThis object by one module from affecting the access of another module to the attributes of the globalThis object. Context adaptation is also performed for some Node-API standard interfaces and extended interfaces. When these Node-API interfaces are called, the context environment proactively switches the context based on the napi_env input parameter of the interface. Developers do not need to proactively call napi_switch_ark_context to switch the context environment, when returning from the C++/C side to the ArkTS side, you need to proactively call the napi_switch_ark_context API to switch the context environment back to the corresponding context environment. Otherwise, the code on the ArkTS side will be executed in another context environment, causing unpredictable stability problems.

## Node-APIs That Support Multiple Runtime Contexts
The NAPI interfaces listed in the following table can be executed in a multi-context environment. Some NAPI interfaces proactively switch the context even if the invoker does not proactively call napi_switch_ark_context to switch the runtime context, these APIs can determine whether to switch the context environment by checking whether the current running context environment is consistent with the runtime environment specified by the APIs. If the context environments are inconsistent, these APIs switch the current runtime environment to the context environment specified by the API parameters. Of course, APIs that do not involve active context switching are irrelevant to the runtime context. Any valid context environment can be used for execution.

| Interface| Whether to proactively switch the context|
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

## Node-APIs That Do Not Support Multiple Runtime Contexts
| Interface| Return values of multi-runtime context environment invoking|
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

### Sample code
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
        // Create a new context environment newEnv2.
        napi_env newEnv2 = nullptr;
        status = napi_create_ark_context(env, &newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        // Proactively switch to the new context environment newEnv2.
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
            // globalThis.a in the context of plugin2 is 3000.
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
        // Obtain the value returned after the GetLocation interface is called.
        ret = 0;
        status = napi_get_value_int32(env, result, &ret);
        if (status != napi_ok) {
            return nullptr;
        } else {
            // globalThis.a in the context of plugin1 is 2000.
            OH_LOG_INFO(LOG_APP, "ret is %{public}d", ret); // 2000
        }
        // Destroy the created context.
        status = napi_destroy_ark_context(newEnv2);
        if (status != napi_ok) {
            return nullptr;
        }
        return result;
    }

    Register the module.
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
- Interface declarations
    ```ts
    // index.d.ts
    export const callFunctionInContext: (func: (func:()=>number)=>{}) => number;
    ```

- Configure the **BUILD.gn** file.
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
    // This interface is used to execute the GetLocation method in the plugin1 or plugin2 module.
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
