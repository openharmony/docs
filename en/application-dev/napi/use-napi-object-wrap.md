# Wrapping a Native Object in an ArkTS Object

## When to Use

You can use **napi_wrap** to wrap a C++ object in an ArkTS object, and use **napi_unwrap** to retrieve the C++ object previously wrapped in the ArkTS object for subsequent operations.

## Example

1. Declare the APIs, configure compile settings, and register the modules.

   **Declare the APIs.**

   ```ts
   // index.d.ts
   export class MyObject {
      constructor(arg: number);
      plusOne: () => number;
   
      public get value();
      public set value(newVal: number);
   }
   ```

   **Configure compile settings.**

   ```
   // CMakeLists.txt
   # Minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(object_wrap)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   
   add_definitions("-DLOG_DOMAIN=0x0000")
   add_definitions("-DLOG_TAG=\"testTag\"")
   
   add_library(object_wrap SHARED object_wrap.cpp)
   target_link_libraries(object_wrap PUBLIC libace_napi.z.so libhilog_ndk.z.so)
   ```

   **Register the module.**

   ```cpp
   // object_wrap.cpp
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
   
   static thread_local napi_ref g_ref = nullptr;
   
   MyObject::MyObject(double value)
       : value_(value), env_(nullptr), wrapper_(nullptr) {}
   
   MyObject::~MyObject()
   {
     napi_delete_reference(env_, wrapper_);
   }
   
   void MyObject::Destructor(napi_env env,
                             void* nativeObject,
                             [[maybe_unused]] void* finalize_hint)
   {
     OH_LOG_INFO(LOG_APP, "MyObject::Destructor called");
     reinterpret_cast<MyObject*>(nativeObject)->~MyObject();
   }
   
   napi_value MyObject::Init(napi_env env, napi_value exports)
   {
     napi_property_descriptor properties[] = {
         {"value", 0, 0, GetValue, SetValue, 0, napi_default, 0},
         { "plusOne", nullptr, PlusOne, nullptr, nullptr, nullptr, napi_default, nullptr }
     };
   
     napi_value cons;
     assert(napi_define_class(env, "MyObject", NAPI_AUTO_LENGTH, New, nullptr, 2,
                              properties, &cons) == napi_ok);
   
     assert(napi_create_reference(env, cons, 1, &g_ref) == napi_ok);
     assert(napi_set_named_property(env, exports, "MyObject", cons) == napi_ok);
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
       .nm_modname = "object_wrap",
       .nm_priv = nullptr,
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterObjectWrapModule()
   {
       napi_module_register(&nativeModule);
   }
   ```

2. Wrap a C++ object in an ArkJS object in a constructor.

   ```cpp
   napi_value MyObject::New(napi_env env, napi_callback_info info)
   {
     OH_LOG_INFO(LOG_APP, "MyObject::New called");
   
     napi_value newTarget;
     assert(napi_get_new_target(env, info, &newTarget) == napi_ok);
     if (newTarget != nullptr) {
       // Invoked as the constructor `new MyObject(...)`.
       size_t argc = 1;
       napi_value args[1];
       napi_value jsThis;
       assert(napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr) == napi_ok);
   
       double value = 0.0;
       napi_valuetype valuetype;
       assert(napi_typeof(env, args[0], &valuetype) == napi_ok);
       if (valuetype != napi_undefined) {
         assert(napi_get_value_double(env, args[0], &value) == napi_ok);
       }
   
       MyObject* obj = new MyObject(value);
   
       obj->env_ = env;
       // Use napi_wrap to wrap the C++ object obj in the ArkTS object jsThis.
       assert(napi_wrap(env,
                        jsThis,
                        reinterpret_cast<void*>(obj),
                        MyObject::Destructor,
                        nullptr,  // finalize_hint
                        &obj->wrapper_) == napi_ok);
   
       return jsThis;
     } else {
       // Invoked as the plain function `MyObject(...)`.
       size_t argc = 1;
       napi_value args[1];
       assert(napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) == napi_ok && argc == 1);
   
       napi_value cons;
       assert(napi_get_reference_value(env, g_ref, &cons) == napi_ok);
       napi_value instance;
       assert(napi_new_instance(env, cons, argc, args, &instance) == napi_ok);
   
       return instance;
     }
   }
   ```

3. Retrieve the C++ object from the ArkTS object and perform subsequent operations on the C++ object.

   ```cpp
   napi_value MyObject::GetValue(napi_env env, napi_callback_info info)
   {
     OH_LOG_INFO(LOG_APP, "MyObject::GetValue called");
   
     napi_value jsThis;
     assert(napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr) == napi_ok);
   
     MyObject* obj;
     // Use napi_unwrap to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS object), and perform subsequent operations.
     assert(napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj)) == napi_ok);
     napi_value num;
     assert(napi_create_double(env, obj->value_, &num) == napi_ok);
   
     return num;
   }
   
   napi_value MyObject::SetValue(napi_env env, napi_callback_info info)
   {
     OH_LOG_INFO(LOG_APP, "MyObject::SetValue called");
   
     size_t argc = 1;
     napi_value value;
     napi_value jsThis;
   
     assert(napi_get_cb_info(env, info, &argc, &value, &jsThis, nullptr) == napi_ok);
   
     MyObject* obj;
     // Use napi_unwrap to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS object), and perform subsequent operations.
     assert(napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj)) == napi_ok);
     assert(napi_get_value_double(env, value, &obj->value_) == napi_ok);
   
     return nullptr;
   }
   
   napi_value MyObject::PlusOne(napi_env env, napi_callback_info info)
   {
     OH_LOG_INFO(LOG_APP, "MyObject::PlusOne called");
   
     napi_value jsThis;
     assert(napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr) == napi_ok);
   
     MyObject* obj;
     // Use napi_unwrap to retrieve obj (the C++ object) previously wrapped in jsThis (the ArkTS object), and perform subsequent operations.
     assert(napi_unwrap(env, jsThis, reinterpret_cast<void**>(&obj)) == napi_ok);
     obj->value_ += 1;
     napi_value num;
     assert(napi_create_double(env, obj->value_, &num) == napi_ok);
   
     return num;
   }
   ```

4. The following provides the sample ArkTS code.

   ```ts
   import hilog from '@ohos.hilog';
   import { MyObject } from 'libobject_wrap.so'
   
   let object : MyObject = new MyObject(0);
   object.value = 1023;
   hilog.info(0x0000, 'testTag', 'MyObject value after set: %{public}d', object.value);
   hilog.info(0x0000, 'testTag', 'MyObject plusOne: %{public}d', object.plusOne());
   ```
