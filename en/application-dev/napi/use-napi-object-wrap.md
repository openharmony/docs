# Wrapping a Native Object in an ArkTS Object

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:43:42.491Z pushedAt=2026-08-12T11:16:45.525Z -->

## When to Use

You can use **napi_wrap** to wrap a C++ object in an ArkTS object, and use **napi_unwrap** to retrieve the C++ object previously wrapped in the ArkTS object for subsequent operations.

## Example

1. Declare the APIs, configure compile settings, and register the modules.

    **Declaring APIs**

    ```ts
    // index.d.ts
    export class MyObject {
      constructor(arg: number);
      plusOne: () => number;

      public get value();
      public set value(newVal: number);
    }
    ```

    **Configuring Build Settings**

    ```txt
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(napi_wrap_demo)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)

    add_definitions("-DLOG_DOMAIN=0x0000")
    add_definitions("-DLOG_TAG=\"testTag\"")

    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
    ```

    **Registering Modules**

    ```cpp
    // napi_init.cpp
    #include "napi/native_api.h"
    #include "hilog/log.h"

    class MyObject {
    public:
        static napi_value Init(napi_env env, napi_value exports);
        static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);

    private:
        explicit MyObject(double value_ = 0);
        ~MyObject();

        static napi_value New(napi_env env, napi_callback_info info);
        static napi_value GetValue(napi_env env, napi_callback_info info);
        static napi_value SetValue(napi_env env, napi_callback_info info);
        static napi_value PlusOne(napi_env env, napi_callback_info info);

        double value_;
        napi_env env_;
        napi_ref wrapper_;
    };

    MyObject::MyObject(double value) : value_(value), env_(nullptr), wrapper_(nullptr) {}

    MyObject::~MyObject()
    {
        napi_status status = napi_delete_reference(env_, wrapper_);
        if (status != napi_ok) {
            OH_LOG_INFO(LOG_APP, "Failed to delete reference, return code: %{public}d", status);
        }
    }

    void MyObject::Destructor(napi_env env, void* nativeObject, [[maybe_unused]] void* finalize_hint)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::Destructor called");
        delete reinterpret_cast<MyObject*>(nativeObject);
    }

    napi_value MyObject::Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor properties[] = {
            { "value", nullptr, nullptr, GetValue, SetValue, nullptr, napi_default, nullptr },
            { "plusOne", nullptr, PlusOne, nullptr, nullptr, nullptr, napi_default, nullptr }
        };

        napi_value cons = nullptr;
        napi_status status = napi_define_class(env, "MyObject", NAPI_AUTO_LENGTH, New, nullptr, 2, properties, &cons);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_define_class fail");
            return nullptr;
        }

        status = napi_set_named_property(env, exports, "MyObject", cons);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_set_named_property fail");
            return nullptr;
        }
        return exports;
    }

    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        MyObject::Init(env, exports);
        return exports;
    }
    EXTERN_C_END

    static napi_module nativeModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "entry",
        .nm_priv = nullptr,
        .reserved = { 0 },
    };

    extern "C" __attribute__((constructor)) void RegisterObjectWrapModule()
    {
        napi_module_register(&nativeModule);
    }
    ```

2. Wrap a C++ object in an ArkTS object in a constructor.

    ```cpp
    napi_value MyObject::New(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::New called");

        napi_value newTarget = nullptr;
        napi_status status = napi_get_new_target(env, info, &newTarget);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_get_new_target fail");
            return nullptr;
        }
        if (newTarget != nullptr) {
            // Called with `new MyObject(...)`.
            size_t argc = 1;
            napi_value args[1] = { nullptr };
            napi_value jsThis = nullptr;
            status = napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);
            if (status != napi_ok) {
                napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
                return nullptr;
            }

            double value = 0.0;
            napi_valuetype valuetype = napi_undefined;
            status = napi_typeof(env, args[0], &valuetype);
            if (status != napi_ok) {
                napi_throw_error(env, nullptr, "Node-API napi_typeof fail");
                return nullptr;
            }
            if (valuetype != napi_undefined) {
                status = napi_get_value_double(env, args[0], &value);
                if (status != napi_ok) {
                    napi_throw_error(env, nullptr, "Node-API napi_get_value_double fail");
                    return nullptr;
                }
            }

            MyObject* obj = new MyObject(value);

            obj->env_ = env;
            // Bind the ArkTS object (jsThis) to the C++ object (obj) through napi_wrap.
            status = napi_wrap(env,
                               jsThis,
                               reinterpret_cast<void*>(obj),
                               MyObject::Destructor,
                               nullptr,  // finalize_hint
                               &obj->wrapper_);
            // If napi_wrap fails, you must manually release the allocated memory to prevent memory leaks.
            if (status != napi_ok) {
                delete obj;
                napi_throw_error(env, nullptr, "Node-API napi_wrap fail");
                return jsThis;
            }
            // Obtaining an napi_ref from the result of napi_wrap creates a strong reference to jsThis.
            // If you do not need to actively manage the lifecycle of jsThis, you can pass nullptr directly as the last parameter of napi_wrap.
            // Alternatively, use napi_reference_unref to convert the napi_ref to a weak reference.
            uint32_t refCount = 0;
            napi_reference_unref(env, obj->wrapper_, &refCount);

            return jsThis;
        } else {
            // Called with `MyObject(...)`.
            size_t argc = 1;
            napi_value args[1] = { nullptr };
            napi_value jsThis = nullptr;
            status = napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);
            if (status != napi_ok) {
                napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
                return nullptr;
            }

            napi_value cons = nullptr;
            const char* constructorName = "MyObject";
            status = napi_get_named_property(env, jsThis, constructorName, &cons);
            if (status != napi_ok) {
                napi_throw_error(env, nullptr, "Node-API napi_get_named_property fail");
                return nullptr;
            }
            napi_value instance = nullptr;
            status = napi_new_instance(env, cons, argc, args, &instance);
            if (status != napi_ok) {
                napi_throw_error(env, nullptr, "Node-API napi_new_instance fail");
                return nullptr;
            }

            return instance;
        }
    }
    ```

3. Retrieve the C++ object from the ArkTS object and perform subsequent operations on the C++ object.

    ```cpp
    napi_value MyObject::GetValue(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::GetValue called");

        napi_value jsThis = nullptr;
        napi_status status = napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
            return nullptr;
        }

        MyObject* obj = nullptr;
        // Use napi_unwrap to retrieve the C++ object previously bound to jsThis, and operate on it.
        status = napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj));
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_unwrap fail");
            return nullptr;
        }
        napi_value num = nullptr;
        status = napi_create_double(env, obj->value_, &num);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_create_double fail");
            return nullptr;
        }

        return num;
    }

    napi_value MyObject::SetValue(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::SetValue called");

        size_t argc = 1;
        napi_value value = nullptr;
        napi_value jsThis = nullptr;

        napi_status status = napi_get_cb_info(env, info, &argc, &value, &jsThis, nullptr);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
            return nullptr;
        }

        MyObject* obj = nullptr;
        // Use napi_unwrap to retrieve the C++ object previously bound to jsThis, and operate on it.
        status = napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj));
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_unwrap fail");
            return nullptr;
        }
        status = napi_get_value_double(env, value, &obj->value_);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_get_value_double fail");
            return nullptr;
        }

        return nullptr;
    }

    napi_value MyObject::PlusOne(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::PlusOne called");

        napi_value jsThis = nullptr;
        napi_status status = napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
            return nullptr;
        }

        MyObject* obj = nullptr;
        // Use napi_unwrap to retrieve the C++ object previously bound to jsThis, and operate on it.
        status = napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj));
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_unwrap fail");
            return nullptr;
        }
        obj->value_ += 1;
        napi_value num = nullptr;
        status = napi_create_double(env, obj->value_, &num);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Node-API napi_create_double fail");
            return nullptr;
        }

        return num;
    }
    ```

4. The following provides the sample ArkTS code.

    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { MyObject } from 'libentry.so';

    try {
        let object : MyObject = new MyObject(0);
        object.value = 1023.1;
        hilog.info(0x0000, 'testTag', 'MyObject value after set: %{public}s', object.value.toString());
        hilog.info(0x0000, 'testTag', 'MyObject plusOne: %{public}s', object.plusOne().toString());
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'Test Node-API error: %{public}s', error.message);
    }
    ```