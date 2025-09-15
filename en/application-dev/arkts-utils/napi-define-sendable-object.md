# Multithreaded Operations with Custom Native Sendable Objects
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

ArkTS supports custom native Sendable objects, which provide efficient inter-thread communication through pass-by-reference. This is particularly valuable for scenarios requiring inter-thread communication of large custom objects, such as when a child thread retrieves database data and returns it to the host thread.

The following demonstrates how to implement shared data access across concurrent instances using custom native Sendable objects.

1. Customize a Sendable class in the interface declaration.

   ```ts
   // Index.d.ets
   @Sendable
   export class MyObject {
     constructor(arg: number);
     plusOne(): number;
   
     public get value(): number;
     public set value(newVal: number);
   }
   ```

2. Configure the build environment.

    ```cmake
    # CMakeLists.txt
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(napi_wrap_sendable_demo)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)

    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
    ```

3. Implement the features in native code, such as obtaining values, setting values, and incrementing values.

    ```cpp
    // napi_init.cpp
    #include "napi/native_api.h"
    #include "hilog/log.h"

    // A native class. Its instance is wrapped in an ArkTS Sendable object.
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

    void MyObject::Destructor(napi_env env, void *nativeObject, [[maybe_unused]] void *finalize_hint)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::Destructor called");
        if (g_ref != nullptr) {
            napi_delete_reference(env, g_ref);
            g_ref = nullptr;
        }
        reinterpret_cast<MyObject *>(nativeObject)->~MyObject();
    }

    // Bind the ArkTS Sendable object to a C++ object within a constructor.
    napi_value MyObject::New(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::New called");

        napi_value newTarget;
        napi_get_new_target(env, info, &newTarget);
        if (newTarget != nullptr) {
            // Use the call mode new MyObject(...).
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
            // Use napi_wrap_sendable to bind the ArkTS Sendable object jsThis to the C++ object obj.
            napi_wrap_sendable(env, jsThis, reinterpret_cast<void *>(obj), MyObject::Destructor, nullptr);

            return jsThis;
        } else {
            // Use the call mode MyObject(...).
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
    
    // Obtain the value of the native object.
    napi_value MyObject::GetValue(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::GetValue called");

        napi_value jsThis;
        napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

        MyObject *obj;
        // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS Sendable object), and perform subsequent operations.
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        napi_value num;
        napi_create_double(env, obj->value_, &num);

        return num;
    }

    // Set the value of the native object.
    napi_value MyObject::SetValue(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::SetValue called");

        size_t argc = 1;
        napi_value value;
        napi_value jsThis;

        napi_get_cb_info(env, info, &argc, &value, &jsThis, nullptr);

        MyObject *obj;
        // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS Sendable object), and perform subsequent operations.
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        napi_get_value_double(env, value, &obj->value_);

        return nullptr;
    }
    
    // Increase the value of the native object by 1.
    napi_value MyObject::PlusOne(napi_env env, napi_callback_info info)
    {
        OH_LOG_INFO(LOG_APP, "MyObject::PlusOne called");

        napi_value jsThis;
        napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

        MyObject *obj;
        // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS Sendable object), and perform subsequent operations.
        napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
        obj->value_ += 1;
        napi_value num;
        napi_create_double(env, obj->value_, &num);

        return num;
    }

    napi_value MyObject::Init(napi_env env, napi_value exports)
    {
        napi_value num;
        napi_create_double(env, 0, &num);
        napi_property_descriptor properties[] = {
            {"value", nullptr, nullptr, GetValue, SetValue, nullptr, napi_default, nullptr},
            {"plusOne", nullptr, PlusOne, nullptr, nullptr, nullptr, napi_default, nullptr},
        };

        napi_value cons;
        // Define a Sendable class MyObject.
        napi_define_sendable_class(env, "MyObject", NAPI_AUTO_LENGTH, New, nullptr,
                                sizeof(properties) / sizeof(properties[0]), properties, nullptr, &cons);

        napi_create_reference(env, cons, 1, &g_ref);
        // Mount the MyObject class to the exports object.
        napi_set_named_property(env, exports, "MyObject", cons);
        return exports;
    }
 
    EXTERN_C_START
    // Initialize the module.
    static napi_value Init(napi_env env, napi_value exports) {
        MyObject::Init(env, exports);
        return exports;
    }
    EXTERN_C_END

    // Information about the module. Record information such as the Init() function and module name.
    static napi_module nativeModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "entry",
        .nm_priv = nullptr,
        .reserved = {0},
    };

    // This function is automatically called when the.so file is loaded to register the nativeModule module with the system.
    extern "C" __attribute__((constructor)) void RegisterObjectWrapModule() { napi_module_register(&nativeModule); }
    ```

4. On the ArkTS side, define a Sendable instance in the UI main thread and pass it to the TaskPool child thread. The child thread processes the data and returns the data to the UI main thread, which can continue to access the Sendable instance.

   ```ts
   // Index.ets
   import { MyObject } from 'libentry.so';
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   async function Sum(object: MyObject) {
     object.value = 2000;
     let num = object.plusOne();
     console.info("taskpool thread num is " + num); // taskpool thread num is 2001
     return num;
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick( async () => {
               let object : MyObject = new MyObject(0);
               object.value = 1023;
               let num = object.plusOne();
               console.info("host thread num1 is " + num); // host thread num1 is 1024
               let task = new taskpool.Task(Sum, object);
               let result = await taskpool.execute(task);
               console.info("host thread result is " + result); // host thread result is 2001
               console.info("host thread num2 is " + object.value); // host thread num2 is 2001
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
5. Modify the **oh-package.json5** file in the same directory as the **Index.d.ets** file. The configuration is as follows:
    ```ts
    {
        "name": "libentry.so",
        "types": "./Index.d.ets",
        "version": "1.0.0",
        "description": "Please describe the basic information."
    }
    ```
