# Native与Sendable ArkTS对象绑定

## 场景介绍

通过`napi_wrap_sendable`将Sendable ArkTS对象与Native的C++对象绑定，后续操作时再通过`napi_unwrap_sendable`将ArkTS对象绑定的C++对象取出，并对其进行操作。

## 使用示例

1. 接口声明、编译配置以及模块注册

    **接口声明**

    ```ts
    // index.d.ets
    @Sendable
    export class MyObject {
    constructor(arg: number);
    plusOne(): number;

    public get value();
    public set value(newVal: number);
    }
    ```

    **编译配置**

    ```cmake
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(napi_wrap_sendable_demo)

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

    **模块注册**

    ```cpp
    // napi_init.cpp
    #include "napi/native_api.h"
    #include "hilog/log.h"

    // 一个native类，它的实例在下面会包装在Sendable ArkTS对象中
    class MyObject {
    public:
        static napi_value Init(napi_env env, napi_value exports);
        static void Destructor(napi_env env, void *nativeObject, void *finalize_hint);

    private:
        explicit MyObject(double value_ = 0);
        ~MyObject();

        static napi_value New(napi_env env, napi_callback_info info);
        static napi_value GetValue(napi_env env, napi_callback_info info);
        static napi_value SetValue(napi_env env, napi_callback_info info);
        static napi_value PlusOne(napi_env env, napi_callback_info info);

        double value_;
        napi_env env_;
    };

    static thread_local napi_ref g_ref = nullptr;

    MyObject::MyObject(double value) : value_(value), env_(nullptr) {}

    MyObject::~MyObject() {}

    void MyObject::Destructor(napi_env env, void *nativeObject, [[maybe_unused]] void *finalize_hint) {
        OH_LOG_INFO(LOG_APP, "MyObject::Destructor called");
        reinterpret_cast<MyObject *>(nativeObject)->~MyObject();
    }

    napi_value MyObject::Init(napi_env env, napi_value exports) {
        napi_value num;
        napi_create_double(env, 0, &num);
        napi_property_descriptor properties[] = {
            {"value", nullptr, nullptr, GetValue, SetValue, nullptr, napi_default, nullptr},
            {"plusOne", nullptr, PlusOne, nullptr, nullptr, nullptr, napi_default, nullptr},
        };

        napi_value cons;
        // 定义一个Sendable class MyObject
        napi_define_sendable_class(env, "MyObject", NAPI_AUTO_LENGTH, New, nullptr,
                                sizeof(properties) / sizeof(properties[0]), properties, nullptr, &cons);

        napi_create_reference(env, cons, 1, &g_ref);
        // 在exports对象上挂载MyObject类
        napi_set_named_property(env, exports, "MyObject", cons);
        return exports;
    }

    EXTERN_C_START
    // 模块初始化
    static napi_value Init(napi_env env, napi_value exports) {
        MyObject::Init(env, exports);
        return exports;
    }
    EXTERN_C_END

    // 准备模块加载相关信息，将上述Init函数与本模块名等信息记录下来。
    static napi_module nativeModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "entry",
        .nm_priv = nullptr,
        .reserved = {0},
    };

    // 加载so时，该函数会自动被调用，将上述nativeModule模块注册到系统中。
    extern "C" __attribute__((constructor)) void RegisterObjectWrapModule() { napi_module_register(&nativeModule); }
    ```

2. 在构造函数中绑定Sendable ArkTS与C++对象

    ```cpp
    napi_value MyObject::New(napi_env env, napi_callback_info info) {
        OH_LOG_INFO(LOG_APP, "MyObject::New called");

        napi_value newTarget;
        napi_get_new_target(env, info, &newTarget);
        if (newTarget != nullptr) {
            // 使用`new MyObject(...)`调用方式
            size_t argc = 1;
            napi_value args[1];
            napi_value jsThis;
            napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);

            double value = 0.0;
            napi_valuetype valuetype;
            napi_typeof(env, args[0], &valuetype);
            if (valuetype != napi_undefined) {
                napi_get_value_double(env, args[0], &value);
            }

            MyObject *obj = new MyObject(value);

            obj->env_ = env;
            // 通过napi_wrap_sendable将Sendable ArkTS对象jsThis与C++对象obj绑定
            napi_wrap_sendable(env, jsThis, reinterpret_cast<void *>(obj), MyObject::Destructor, nullptr);

            return jsThis;
        } else {
            // 使用`MyObject(...)`调用方式
            size_t argc = 1;
            napi_value args[1];
            napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

            napi_value cons;
            napi_get_reference_value(env, g_ref, &cons);
            napi_value instance;
            napi_new_instance(env, cons, argc, args, &instance);

            return instance;
        }
    }
    ```

3. 将Sendable ArkTS对象之前绑定的C++对象取出，并对其进行操作

    ```cpp
    napi_value MyObject::GetValue(napi_env env, napi_callback_info info) {
        OH_LOG_INFO(LOG_APP, "MyObject::GetValue called");

        napi_value jsThis;
        napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

        MyObject *obj;
        // 通过napi_unwrap_sendable将jsThis之前绑定的C++对象取出，并对其进行操作
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        napi_value num;
        napi_create_double(env, obj->value_, &num);

        return num;
    }

    napi_value MyObject::SetValue(napi_env env, napi_callback_info info) {
        OH_LOG_INFO(LOG_APP, "MyObject::SetValue called");

        size_t argc = 1;
        napi_value value;
        napi_value jsThis;

        napi_get_cb_info(env, info, &argc, &value, &jsThis, nullptr);

        MyObject *obj;
        // 通过napi_unwrap_sendable将jsThis之前绑定的C++对象取出，并对其进行操作
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        napi_get_value_double(env, value, &obj->value_);

        return nullptr;
    }

    napi_value MyObject::PlusOne(napi_env env, napi_callback_info info) {
        OH_LOG_INFO(LOG_APP, "MyObject::PlusOne called");

        napi_value jsThis;
        napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

        MyObject *obj;
        // 通过napi_unwrap_sendable将jsThis之前绑定的C++对象取出，并对其进行操作
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        obj->value_ += 1;
        napi_value num;
        napi_create_double(env, obj->value_, &num);

        return num;
    }
    ```

4. ArkTS侧示例代码

    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { MyObject } from 'libentry.so';

    let object : MyObject = new MyObject(0);
    object.value = 1023;
    hilog.info(0x0000, 'testTag', 'MyObject value after set: %{public}d', object.value);
    hilog.info(0x0000, 'testTag', 'MyObject plusOne: %{public}d', object.plusOne());
    ```
