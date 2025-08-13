# 自定义Native Sendable对象的多线程操作场景
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

ArkTS支持开发者自定义Native Sendable对象，Sendable对象提供了并发实例间高效的通信能力，即引用传递，适用于开发者自定义大对象需要线程间通信的场景，例如子线程读取数据库数据并返回给宿主线程。

本示例将详细说明如何使用自定义Native Sendable对象实现并发实例间数据共享。

1. 接口声明中自定义Sendable类。

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

2. 编译配置。

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

3. Native实现各项接口功能，例如取值、设置值或者给Native对象的值加1等功能。

    ```cpp
    // napi_init.cpp
    #include "napi/native_api.h"
    #include "hilog/log.h"

    // 一个native类，它的实例在下面会包装在ArkTS的Sendable对象中
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

    // 在构造函数中绑定ArkTS Sendable对象与C++对象
    napi_value MyObject::New(napi_env env, napi_callback_info info)
    {
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
            // 通过napi_wrap_sendable将ArkTS Sendable对象jsThis与C++对象obj绑定
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
    
    // 取出Native对象的值
    napi_value MyObject::GetValue(napi_env env, napi_callback_info info)
    {
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

    // 设置Native对象的值
    napi_value MyObject::SetValue(napi_env env, napi_callback_info info)
    {
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
    
    // 给Native对象的值加1
    napi_value MyObject::PlusOne(napi_env env, napi_callback_info info)
    {
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

    napi_value MyObject::Init(napi_env env, napi_value exports)
    {
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

    // 加载so时，自动调用该函数，将上述nativeModule模块注册到系统中。
    extern "C" __attribute__((constructor)) void RegisterObjectWrapModule() { napi_module_register(&nativeModule); }
    ```

4. ArkTS侧在UI主线程中定义Sendable实例对象并传递给TaskPool子线程，子线程处理完数据后返回UI主线程，UI主线程可以继续访问该Sendable实例对象。

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
5. 修改与Index.d.ets同目录下的配置文件oh-package.json5，配置如下：
    ```ts
    {
        "name": "libentry.so",
        "types": "./Index.d.ets",
        "version": "1.0.0",
        "description": "Please describe the basic information."
    }
    ```
