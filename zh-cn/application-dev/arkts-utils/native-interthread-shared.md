# C++线程间数据共享场景
<!--Kit: ArkTS-->
<!--Subsystem: commonlibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

在C++层进行多线程并发计算时，需要在每个C++线程上创建ArkTS执行环境，直接调用API。这样可以避免在非UI主线程回调时等待UI主线程的API调用结果。同时，还需要在C++线程之间共享和操作Sendable对象。

为了支持此类场景，C++线程需要能够创建并调用ArkTS，同时支持对Sendable对象进行多线程共享和操作。


## 在C++线程上调用ArkTS能力

使用Node-API接口在C++线程中创建ArkTS运行环境并调用的方法，可以参考[使用Node-API接口创建ArkTS运行时环境](../napi/use-napi-ark-runtime.md)。

核心代码片段如下所示：

ArkTS文件定义。

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```
<!-- @[arkts_define_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/SendableObjTest.ets) -->


实现Native加载ArkTS模块的能力。

```cpp
// napi_init.cpp
#include "napi/native_api.h"
#include <thread>
static void *CreateArkRuntimeFunc(void *arg)
{
    // 1. 创建基础运行环境
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. 加载自定义模块，假定SendableObjTest中提供创建sendable对象的方法newSendable
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
    // 3. 使用ArkTS中的newSendable，假设sendableObjTest中有一个函数newSendable能返回sendable对象
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. 调用newSendable函数返回新创建的sendable对象，并保存在result中
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 5. 获取ArkTS返回的结果
    int value0;
    napi_get_value_int32(env, result, &value0);
    if (value0 != 1024) {
        std::abort();
    }
    // 6. 销毁ArkTS环境
    ret = napi_destroy_ark_runtime(&env);
    return nullptr;
}
```
<!-- @[native_load_arkts_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/napi_init.cpp) -->

主要步骤包括：创建执行环境、加载模块、查找并调用模块函数（或直接通过Node-API接口创建Sendable对象），最后销毁执行环境。加载模块的详细信息，请参见[使用Node-API接口进行模块加载](../napi/use-napi-load-module-with-info.md)。查找并调用函数及更多Node-API接口能力，请参见[Node-API](../reference/native-lib/napi.md)。

## 在C++线程之间操作Sendable共享对象

在C++中调用ArkTS能力后，需要通过序列化和反序列化跨线程传递。napi_value不是多线程安全的，不能直接在多线程之间操作和共享。

下面代码例子说明了如何序列化和反序列化传递对象，注意因为Sendable共享对象是引用传递，所以序列化不会产生另外一份拷贝数据，而是直接传递对象引用到反序列化线程，所以在性能上相比非Sendable对象的序列化和反序列化更为高效。

ArkTS文件定义。

```ts
// SendableObjTest.ets
@Sendable
export class SendableObjTest {
  static newSendable() {
    return 1024;
  }
}
```
<!-- @[arkts_define_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/SendableObjTest.ets) -->

在Native中实现两个线程的序列化和反序列化Sendable的逻辑。

```cpp
// napi_init.cpp
#include "napi/native_api.h"
#include <thread>

static void *serializationData = nullptr;
static void *CreateEnvAndSendSendable(void *) {
    // 1. 创建基础运行环境
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. 加载自定义模块，假定SendableObjTest中提供创建sendable对象的方法newSendable
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
    // 3. 使用ArkTS中的newSendable，假设sendableObjTest中有一个函数newSendable能返回sendable对象
    napi_value newSendable = nullptr;
    ret = napi_get_named_property(env, sendableObjTest, "newSendable", &newSendable);
    if (ret != napi_ok) {
        std::abort();
    }
    // 4. 调用newSendable函数返回新创建的sendable对象，并保存在result中
    napi_value result = nullptr;
    ret = napi_call_function(env, sendableObjTest, newSendable, 0, nullptr, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 5. 序列化sendable对象
    napi_value undefined;
    napi_get_undefined(env, &undefined);
    ret = napi_serialize(env, result, undefined, undefined, &serializationData);
    if (ret != napi_ok) {
        std::abort();
    }
    return nullptr;
}

static void *CreateEnvAndReceiveSendable(void *) {
    // 1. 创建基础运行环境
    napi_env env = nullptr;
    napi_status ret = napi_create_ark_runtime(&env);
    if (ret != napi_ok) {
        std::abort();
    }
    // 2. 反序列化获取sendable共享对象，结果保存在result中，这个result就可以通过napi接口进行各种操作了
    napi_value result = nullptr;
    ret = napi_deserialize(env, serializationData, &result);
    if (ret != napi_ok) {
        std::abort();
    }
    // 3. 删除序列化数据
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
<!-- @[native_deserialize_sendable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/napi_init.cpp) -->


```
// Index.d.ts
export const testSendSendable: () => void;
```
<!-- @[native_deserialize_sendable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/cpp/types/libentry/Index.d.ts) -->

UI主线程发起调用。

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
<!-- @[main_thread_init_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/NativeInterthreadShared/entry/src/main/ets/pages/Index.ets) -->

整个过程主要包括的逻辑实现为：

1. 在UI主线程中创建ArkTS运行环境，并发起一个C++子线程创建Sendable对象，保存到result中，然后将result引用的Sendable对象序列化到全局序列化数据serializationData中。

2. 当这些流程完成后，发起另外一个C++子线程，并在这个新的线程中创建ArkTS运行环境。然后再通过反序列化接口从serializationData中反序列化出UI主线程创建的Sendable对象，并保存到result中，从而实现了Sendable对象的跨C++线程传递。反序列化完成后，需要销毁反序列化数据避免内存泄露。这时UI主线程和子线程都同时持有这个Sendable共享对象，即可通过Node-API进行对象操作，比如读写或者传递到ArkTS层等。

   > **说明：**
   >
   > 操作对象需要符合Sendable对象的规则，具体可见[Sendable使用规则与约束](sendable-constraints.md)。