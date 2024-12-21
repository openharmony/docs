# Wrapping a Native Object in a Sendable ArkTS Object

## When to Use

You can use **napi_wrap_sendable** to wrap a C++ object in a sendable ArkTS object, and use **napi_unwrap_sendable** to retrieve the C++ object previously wrapped in the sendable ArkTS object for subsequent operations.

## Example

1. Declare the APIs, configure compile settings, and register the module.

  **Declare the APIs.**

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

  **Configure compile settings.**

  ```
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

  **Register the module.**

  ```cpp
  // napi_init.cpp
  #include "napi/native_api.h"
  #include "hilog/log.h"

  // A native class. Its instance is wrapped in a sendable ArkTS object.
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
      // Define a sendable class MyObject.
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

  // When the .so file is loaded, this function is automatically called to register the nativeModule module with the system.
  extern "C" __attribute__((constructor)) void RegisterObjectWrapModule() { napi_module_register(&nativeModule); }
  ```

2. Wrap a C++ object in a sendable ArkTS object in a constructor.

  ```cpp
  napi_value MyObject::New(napi_env env, napi_callback_info info) {
      OH_LOG_INFO(LOG_APP, "MyObject::New called");

      napi_value newTarget;
      napi_get_new_target(env, info, &newTarget);
      if (newTarget != nullptr) {
          // Invoked as the constructor `new MyObject(...)`.
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
          // Use napi_wrap_sendable to wrap obj (the C++ object) in jsThis (the sendable ArkTS object).
          napi_wrap_sendable(env, jsThis, reinterpret_cast<void *>(obj), MyObject::Destructor, nullptr);

          return jsThis;
      } else {
          // Invoked as the plain function `MyObject(...)`.
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

3. Retrieve the C++ object from the sendable ArkTS object and perform subsequent operations on the C++ object.

  ```cpp
  napi_value MyObject::GetValue(napi_env env, napi_callback_info info) {
      OH_LOG_INFO(LOG_APP, "MyObject::GetValue called");

      napi_value jsThis;
      napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

      MyObject *obj;
      // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the sendable ArkTS object), and perform subsequent operations.
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
      // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the sendable ArkTS object), and perform subsequent operations.
      napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
      napi_get_value_double(env, value, &obj->value_);

      return nullptr;
  }

  napi_value MyObject::PlusOne(napi_env env, napi_callback_info info) {
      OH_LOG_INFO(LOG_APP, "MyObject::PlusOne called");

      napi_value jsThis;
      napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);

      MyObject *obj;
      // Use napi_unwrap_sendable to retrieve obj (the C++ object) previously wrapped in jsThis (the sendable ArkTS object), and perform subsequent operations.
      napi_unwrap_sendable(env, jsThis, reinterpret_cast<void **>(&obj));
      obj->value_ += 1;
      napi_value num;
      napi_create_double(env, obj->value_, &num);

      return num;
  }
  ```

4. ArkTS code:

  ```ts
  import hilog from '@ohos.hilog';
  import { MyObject } from 'libentry.so';

  let object : MyObject = new MyObject(0);
  object.value = 1023;
  hilog.info(0x0000, 'testTag', 'MyObject value after set: %{public}d', object.value);
  hilog.info(0x0000, 'testTag', 'MyObject plusOne: %{public}d', object.plusOne());
  ```
