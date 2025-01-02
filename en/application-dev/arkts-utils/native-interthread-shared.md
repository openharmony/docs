# Data Sharing Between C++ Threads

When an application performs multi-thread concurrent computing at the C++ layer, the ArkTS API needs to be executed in the ArkTS environment. To prevent the non-UI main thread from waiting for the API calling result in the ArkTS environment, you need to create an ArkTS execution environment and directly call APIs on these C++ threads. In addition, you may need to share and operate Sendable objects between C++ threads.

To support this scenario, you need to create and call ArkTS on the C++ thread, and perform multi-thread sharing and operations on the Sendable object.


## Calling ArkTS Capabilities on a C++ Thread

For details about how to use Node-APIs to create and call an ArkTS runtime environment in a C++ thread, see [Creating an ArkTs Runtime Environment Using Node-API](../napi/use-napi-ark-runtime.md).

The core code snippet is as follows:

ArkTS File Definition

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```


The Naitve implements the capability of loading the ArkTS module.

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
    // 2. Load the customized module. Assume that SendableObjTest provides the newSendable method for creating the sendable object.
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
    // 3. Use newSendable in ArkTS. Assume that the newSendable function in sendableObjTest can return the sendable object.
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. Call the newSendable function to return the newly created sendable object and save it in the result.
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. Obtain the result returned by ArkTS.
    int value0;
    napi_get_value_int32(env, result, &value0);
    if (value0 != 1024) {
        std::abort();
    }
    // 6. Destroy the ArkTS environment.
    ret = napi_destroy_ark_runtime(&env);
    return nullptr;
}
```

The process consists of four steps: creating an execution environment, loading a module, searching for and calling the functions of the module (or directly creating a Sendable object through the Node-API), and destroying the execution environment. For details about how to load a module in the second step, see [Loading a Module Using Node-API](../napi/use-napi-load-module-with-info.md). For details about how to search for and call a function and more Node-API interface capabilities, see [Node-API](../reference/native-lib/napi.md).

## Operates Sendable shared objects between C++ threads.

After the ArkTS capability is called in C++, the implementation needs to be transferred across threads through serialization and deserialization. The napi_value variable cannot be directly shared among multiple threads because it is not multi-thread secure.

The following code example describes how to serialize and deserialize the transferred object. Note that the Sendable shared object is transferred by reference. Therefore, serialization does not generate another copy of data. Instead, the object reference is directly transferred to the deserialization thread. Therefore, the performance is more efficient than that of serialization and deserialization of non-Sendable objects.

ArkTS File Definition

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```

The Naitve implements the serialization and deserialization logic of the Sendable of two threads.

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
    // 2. Load the customized module. Assume that SendableObjTest provides the newSendable method for creating the sendable object.
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
    // 3. Use newSendable in ArkTS. Assume that the newSendable function in sendableObjTest can return the sendable object.
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. Call the newSendable function to return the newly created sendable object and save it in the result.
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 5. Serialize the sendable object.
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
    // 2. Obtain the sendable shared object through deserialization and save the result in the result. The result can be used to perform various operations through the napi interface.
    napi_value result = nullptr;
    ret = napi_deserialize(env, serializationData, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 3. Delete serialized data.
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


```
// Index.d.ts
export const testSendSendable: () => void;
```

The UI main thread initiates an invoking request.

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

The logic implementation of the entire process is as follows:

1. Create the ArkTS running environment in the UI main thread where the main function is located, create a Sendable object and save it to the result, and serialize the Sendable object referenced by the result to a global serialization data serializationData.

2. After these processes are complete, another C++ subthread is initiated and the ArkTS runtime environment is created in the new thread. Then, the Sendable object created by the UI main thread is deserialized from serializationData through the deserialization interface, and is saved to the result. In this way, the Sendable object is transferred across C++ threads. After deserialization is complete, destroy the deserialized data to avoid memory leakage. In this case, both the UI main thread and sub-threads hold the Sendable shared object. You can perform object operations through the Node-API, such as reading, writing, or transferring the object to the ArkTS layer.

   > **Note**
   >
   > The operation object must comply with the rules of the Sendable object. For details, see [Sendable Usage Rules and Constraints](sendable-constraints.md).
