# C++ Inter-Thread Data Sharing

When an application performs multithreaded computations at the C++ layer, ArkTS APIs needs to be executed within the ArkTS environment. To prevent the non-UI main thread from waiting for the API call results within the UI main thread, you need to create an ArkTS execution environment on these C++ threads and directly call the APIs. In addition, you may need to share and manipulate Sendable objects across C++ threads.

To support this scenario, you must create the capabilities to call ArkTS APIs on C++ threads, and share and manipulate Sendable objects across threads.


## Calling ArkTS APIs on C++ Threads

For details about how to use Node-API to create an ArkTS runtime environment and call ArkTS APIs on C++ threads, see [Creating an ArkTS Runtime Environment Using Node-API](../napi/use-napi-ark-runtime.md).

The core code snippet is as follows:

ArkTS file definition

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```
<!-- @[arkts_define_obj](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/SendableObjTest.ets) -->


Native implementation to load ArkTS modules

```cpp
// napi_init.cpp
#include "napi/native_api.h"
#include <thread>
static void *CreateArkRuntimeFunc(void *arg)
{
    // 1. Create the ArkTS runtime environment.
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. Load the custom module, assuming that SendableObjTest provides the newSendable function for creating Sendable objects.
    napi_value test = nullptr;
    ret = napi_load_module_with_info(env, "entry/src/main/ets/pages/SendableObjTest", "com.example.myapplication/entry", &test);
    if (ret != napi_ok) {
        std::abort();
    }
    napi_value sendableObjTest = nullptr;
    ret = napi_get_named_property(env, test, "SendableObjTest", &sendableObjTest);
    if (ret != napi_ok) {
        std::abort();
    }
    // 3. Use newSendable in ArkTS, assuming that the newSendable function in sendableObjTest returns a Sendable object.
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. Call the newSendable function to return the newly created Sendable object and store it in result.
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 5. Obtain the result returned by ArkTS.
    int value0;
    napi_get_value_int32(env, result, &value0);
    if (value0 != 1024) {
        std::abort();
    }
    // 6. Destroy the ArkTS runtime environment.
    ret = napi_destroy_ark_runtime(&env);
    return nullptr;
}
```
<!-- @[native_load_arkts_module](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/napi_init.cpp) -->

The process consists of four steps: creating an execution environment, loading modules, searching for and calling functions (or directly creating Sendable objects through Node-API), and finally destroying the execution environment. For details about how to load modules, see [Loading a Module Using Node-API](../napi/use-napi-load-module-with-info.md). For details about how to search for and call functions and more Node-API capabilities, see [Node-API](../reference/native-lib/napi.md#node-api).

## Manipulating Sendable Objects Across C++ Threads

After implementing the capabilities to call ArkTS APIs from C++, serialize and deserialize objects for cross-thread transfer. The **napi_value** variable is not thread-safe and therefore cannot be directly shared across threads.

The following code example demonstrates how to serialize and deserialize objects. Since Sendable objects are passed by reference, serialization does not create an additional copy of the data but directly passes the object reference to the deserializing thread. This makes serialization and deserialization more efficient than non-Sendable objects.

ArkTS file definition

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```
<!-- @[arkts_define_obj](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/SendableObjTest.ets) -->

Native implementation for serialization and deserialization of Sendable objects

```cpp
// napi_init.cpp
#include "napi/native_api.h"
#include <thread>

static void *serializationData = nullptr;
static void *CreateEnvAndSendSendable(void *) {
    // 1. Create the ArkTS runtime environment.
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. Load the custom module, assuming that SendableObjTest provides the newSendable function for creating Sendable objects.
    napi_value test = nullptr;
    ret = napi_load_module_with_info(env, "entry/src/main/ets/pages/SendableObjTest", "com.example.myapplication/entry",
                                     &test);
    if (ret != napi_ok) {
        std::abort();
    }
    napi_value sendableObjTest = nullptr;
    ret = napi_get_named_property(env, test, "SendableObjTest", &sendableObjTest);
    if (ret != napi_ok) {
        std::abort();
    }
    // 3. Use newSendable in ArkTS, assuming that the newSendable function in sendableObjTest returns a Sendable object.
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. Call the newSendable function to return the newly created Sendable object and store it in result.
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 5. Serialize the Sendable object.
    napi_value undefined;
    napi_get_undefined(env, &undefined);
    ret = napi_serialize(env, result, undefined, undefined, &serializationData);
    if (ret != napi_ok) {
        std::abort();
    }
    return nullptr;
}

static void *CreateEnvAndReceiveSendable(void *) {
    // 1. Create the ArkTS runtime environment.
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. Deserialize the Sendable object and store it in result, which can then be manipulated via Node-API.
    napi_value result = nullptr;
    ret = napi_deserialize(env, serializationData, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 3. Delete the serialization data.
    ret = napi_delete_serialization_data(env, serializationData);
    if (ret != napi_ok) {
        std::abort();
    }
    napi_valuetype valuetype0;
    napi_typeof(env, result, &valuetype0);
    if (valuetype0 != napi_number) {
        std::abort();
    }
    int value0;
    napi_get_value_int32(env, result, &value0);
    if (value0 != 1024) {
        std::abort();
    }
    return nullptr;
}

static napi_value TestSendSendable([[maybe_unused]] napi_env env, [[maybe_unused]] napi_callback_info info) {
    std::thread t1(CreateEnvAndSendSendable, nullptr);
    t1.join();
    std::thread t2(CreateEnvAndReceiveSendable, nullptr);
    t2.join();
    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"testSendSendable", nullptr, TestSendSendable, nullptr, nullptr, nullptr, napi_default, nullptr}};
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
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) {
    napi_module_register(&demoModule);
}
```
<!-- @[native_deserialize_sendable](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/napi_init.cpp) -->


```
// Index.d.ts
export const testSendSendable: () => void;
```
<!-- @[native_deserialize_sendable](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/types/libentry/Index.d.ts) -->

UI main thread invocation

```ts
// Index.ets
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
import { SendableObjTest } from './SendableObjTest'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            SendableObjTest.newSendable()
            hilog.info(0x0000, 'testTag', 'Test send Sendable begin');
            testNapi.testSendSendable();
            hilog.info(0x0000, 'testTag', 'Test send Sendable end');
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!-- @[main_thread_init_call](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/Index.ets) -->

The logic implementation of the entire process is as follows:

1. In the UI main thread where the **main** function resides, create an ArkTS runtime environment and initiate a C++child thread to create a Sendable object and store the object in **result**. Serialize the Sendable object referenced by **result** into global serialization data **serializationData**.

2. After the preceding steps are complete, initiate another C++ child thread. In this new thread, create the ArkTS runtime environment. Then, deserialize the Sendable object created in the UI main thread from **serializationData** using the deserialization interface and store it in **result**. This enables the transfer of Sendable objects across C++ thread. After deserialization, the deserialization data must be destroyed to prevent memory leaks. In this case, both the UI main thread and the child thread hold the Sendable object, which can be manipulated via Node-API, such as reading/writing or passing it to the ArkTS layer.

   > **NOTE**
   >
   > The object being manipulated must comply with the rules of Sendable objects. For details, see [Usage Rules and Constraints for Sendable](sendable-constraints.md).

<!--no_check-->