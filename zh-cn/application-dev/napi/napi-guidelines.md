# Node-API开发规范
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 获取JS传入参数及其数量

**【规则】** 当传入napi_get_cb_info的argv不为nullptr时，argv的长度必须大于等于传入argc声明的大小。

当argv不为nullptr时，napi_get_cb_info会根据argc声明的数量将JS实际传入的参数写入argv。如果argc小于等于实际JS传入参数的数量，该接口仅会将声明的argc数量的参数写入argv；而当argc大于实际参数数量时，该接口会在argv的尾部填充undefined。

**错误示例**

```cpp
static napi_value IncorrectDemo1(napi_env env, napi_callback_info info) {
    // argc 未正确的初始化，其值为不确定的随机值，导致 argv 的长度可能小于 argc 声明的数量，数据越界。
    size_t argc;
    napi_value argv[10] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}

static napi_value IncorrectDemo2(napi_env env, napi_callback_info info) {
    // argc 声明的数量大于 argv 实际初始化的长度，导致 napi_get_cb_info 接口在写入 argv 时数据越界。
    size_t argc = 5;
    napi_value argv[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}
```

**正确示例**

```cpp
static napi_value GetArgvDemo1(napi_env env, napi_callback_info info) {
    size_t argc = 0;
    // argv 传入 nullptr 来获取传入参数真实数量
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
    // JS 传入参数为0，不执行后续逻辑
    if (argc == 0) {
        return nullptr;
    }
    // 创建数组用以获取JS传入的参数
    napi_value* argv = new napi_value[argc];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 业务代码
    // ... ...
    // argv 为 new 创建的对象，在使用完成后手动释放
    delete[] argv;
    return nullptr;
}

static napi_value GetArgvDemo2(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    // napi_get_cb_info 会向 argv 中写入 argc 个 JS 传入参数或 undefined
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 业务代码
    // ... ...
    return nullptr;
}
```

## 生命周期管理

**【规则】** 合理使用napi_open_handle_scope和napi_close_handle_scope管理napi_value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

每个napi_value属于特定的HandleScope，HandleScope通过napi_open_handle_scope和napi_close_handle_scope来建立和关闭，HandleScope关闭后，所属的napi_value就会自动释放。

**正确示例**：

```cpp
// 在for循环中频繁调用napi接口创建js对象时，要加handle_scope及时释放不再使用的资源。
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
for (int i = 0; i < 100000; i++) {
    napi_handle_scope scope = nullptr;
    napi_open_handle_scope(env, &scope);
    if (scope == nullptr) {
        return;
    }
    napi_value res;
    napi_create_object(env, &res);
    napi_close_handle_scope(env, scope);
}
```

## 上下文敏感

**【规则】** 多引擎实例场景下，禁止通过Node-API跨引擎实例访问JS对象。

引擎实例是一个独立运行环境，JS对象创建访问等操作必须在同一个引擎实例中进行。若在不同引擎实例中操作同一个对象，可能会引发程序崩溃。引擎实例在接口中体现为napi_env。

**错误示例**：

```cpp
// 线程1执行，在env1创建string对象，值为"bar"、
napi_create_string_utf8(env1, "bar", NAPI_AUTO_LENGTH, &string);
// 线程2执行，在env2创建object对象，并将上述的string对象设置到object对象中
napi_status status = napi_create_object(env2, &object);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}

status = napi_set_named_property(env2, object, "foo", string);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
```

所有的JS对象都隶属于具体的某一napi_env，不可将env1的对象，设置到env2中的对象中。在env2中一旦访问到env1的对象，程序可能会发生崩溃。

## 异常处理

**【建议】** Node-API接口调用发生异常需要及时处理，不能遗漏异常到后续逻辑，否则程序可能发生不可预期行为。

**正确示例**：

```cpp
// 1.创建对象
napi_status status = napi_create_object(env, &object);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
// 2.创建属性值
status = napi_create_string_utf8(env, "bar", NAPI_AUTO_LENGTH, &string);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
// 3.将步骤2的结果设置为对象object属性foo的值
status = napi_set_named_property(env, object, "foo", string);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
```

如上示例中，步骤1或者步骤2出现异常时，步骤3都不会正常进行。只有当方法的返回值是napi_ok时，才能保持继续正常运行；否则后续流程可能会出现不可预期的行为。

## 异步任务

**【规则】** 当使用uv_queue_work方法将任务抛到JS线程上面执行的时候，对JS线程的回调方法，一般情况下需要加上napi_handle_scope来管理回调方法创建的napi_value的生命周期。

使用uv_queue_work方法，不会走Node-API框架，此时需要开发者自己合理使用napi_handle_scope来管理napi_value的生命周期。

> **说明**
>
> 本规则旨在强调napi_value生命周期情况，若只想往JS线程抛任务，**不推荐**使用uv_queue_work方法。如有抛任务的需要，请使用[napi_threadsafe_function系列](./use-napi-thread-safety.md)接口。

**正确示例**：

```cpp
void CallbackTest(CallbackContext* context)
{
    uv_loop_s* loop = nullptr;
    napi_get_uv_event_loop(context->env, &loop);
    uv_work_t* work = new uv_work_t;
    context->retData = 1;
    work->data = (void*)context;
    uv_queue_work(
        loop, work,
        // 请注意，uv_queue_work会创建一个线程并执行该回调函数，若开发者只想往JS线程抛任务，不推荐使用uv_queue_work，以避免冗余的线程创建
        [](uv_work_t* work) {
            // 执行一些业务逻辑
        },
        // 该回调会执行在loop所在的JS线程上
        [](uv_work_t* work, int status) {
            CallbackContext* context = (CallbackContext*)work->data;
            napi_handle_scope scope = nullptr;
            napi_open_handle_scope(context->env, &scope);
            if (scope == nullptr) {
                if (work != nullptr) {
                    delete work;
                }
                return;
            }
            napi_value callback = nullptr;
            napi_get_reference_value(context->env, context->callbackRef, &callback);
            napi_value retArg;
            napi_create_int32(context->env, context->retData, &retArg);
            napi_value ret;
            napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
            napi_delete_reference(context->env, context->callbackRef);
            napi_close_handle_scope(context->env, scope);
            if (work != nullptr) {
                delete work;
            }
            delete context;
        }
    );
}
```

## 对象绑定

**【规则】** 使用napi_wrap接口，如果最后一个参数result传递不为nullptr，需要开发者在合适的时机调用napi_remove_wrap函数主动删除创建的napi_ref。

napi_wrap接口定义如下：

```cpp
napi_wrap(napi_env env, napi_value js_object, void* native_object, napi_finalize finalize_cb, void* finalize_hint, napi_ref* result)
```

当最后一个参数result不为空时，框架会创建一个napi_ref对象，指向js_object。此时开发者需要自己管理js_object的生命周期，即需要在合适的时机调用napi_remove_wrap删除napi_ref，这样GC才能正常释放js_object，从而触发绑定C++对象native_object的析构函数finalize_cb。

一般情况下，根据业务情况最后一个参数result可以直接传递为nullptr。

**正确示例**：

```cpp
// 用法1：napi_wrap不需要接收创建的napi_ref，最后一个参数传递nullptr，创建的napi_ref是弱引用，由系统管理，不需要用户手动释放
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// 用法2：napi_wrap需要接收创建的napi_ref，最后一个参数不为nullptr，返回的napi_ref是强引用，需要用户手动释放，否则会内存泄漏
napi_ref result;
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// 当js_object和result后续不再使用时，及时调用napi_remove_wrap释放result
void* nativeObjectResult = nullptr;
napi_remove_wrap(env, jsobject, &nativeObjectResult);
```

## 高性能数组

**【建议】** 存储值类型数据时，使用ArrayBuffer代替JSArray来提高应用性能。

使用JSArray作为容器储存数据，支持几乎所有的JS数据类型。

使用napi_set_element方法对JSArray存储值类型数据（如int32）时，同样会涉及到与运行时的交互，造成不必要的开销。

ArrayBuffer进行增改是直接对缓冲区进行更改，具有远优于使用napi_set_element操作JSArray的性能表现。

因此此种场景下，更推荐使用napi_create_arraybuffer接口创建的ArrayBuffer对象。

**示例：**

```cpp
// 以下代码使用常规JSArray作为容器，但其仅存储int32类型数据。
// 但因为是JS对象，因此只能使用napi方法对其进行增改，性能较低。
static napi_value ArrayDemo(napi_env env, napi_callback_info info)
{
    constexpr size_t arrSize = 1000;
    napi_value jsArr = nullptr;
    napi_create_array(env, &jsArr);
    for (int i = 0; i < arrSize; i++) {
        napi_value arrValue = nullptr;
        napi_create_int32(env, i, &arrValue);
        // 常规JSArray使用napi方法对array进行读写，性能较差。
        napi_set_element(env, jsArr, i, arrValue);
    }
    return jsArr;
}

// 推荐写法：
// 同样以int32类型数据为例，但以下代码使用ArrayBuffer作为容器。
// 因此可以使用C/C++的方法直接对缓冲区进行增改。
static napi_value ArrayBufferDemo(napi_env env, napi_callback_info info)
{
    constexpr size_t arrSize = 1000;
    napi_value arrBuffer = nullptr;
    void* data = nullptr;

    napi_create_arraybuffer(env, arrSize * sizeof(int32_t), &data, &arrBuffer);
    // data为空指针，取消对data进行写入
    if (data == nullptr) {
        return arrBuffer;
    }
    int32_t* i32Buffer = reinterpret_cast<int32_t*>(data);
    for (int i = 0; i < arrSize; i++) {
        // arrayBuffer直接对缓冲区进行修改，跳过运行时，
        // 与操作原生C/C++对象性能相当
        i32Buffer[i] = i;
    }

    return arrBuffer;
}
```

napi_create_arraybuffer等同于JS代码中的`new ArrayBuffer(size)`，其生成的对象不可直接在TS/JS中进行读取，需要将其包装为TyppedArray或DataView后方可进行读写。

**基准性能测试结果如下：**

> **说明：**
>
> 以下数据为千次循环写入累计数据，为更好的体现出差异，已对设备核心频率进行限制。

| 容器类型    | Benchmark数据（us） |
| ----------- | ------------------- |
| JSArray     | 1566.174            |
| ArrayBuffer | 3.609               |

## 数据转换

**【建议】** 尽可能的减少数据转换次数，避免不必要的复制。

- **减少数据转换次数：** 频繁的数据转换可能会导致性能下降，可以通过批量处理数据或者使用更高效的数据结构来优化性能。
- **避免不必要的数据复制：** 在进行数据转换时，可以使用Node-API提供的接口来直接访问原始数据，而不是创建新的副本。
- **使用缓存：** 如果某些数据在多次转换中都会被使用到，可以考虑使用缓存来避免重复的数据转换。缓存可以减少不必要的计算，提高性能。

## 模块注册与模块命名

**【规则】**
nm_register_func对应的函数需要加上修饰符static，防止与其他so里的符号冲突。

模块注册的入口，即使用__attribute__((constructor))修饰函数的函数名需要确保与其他模块不同。

模块实现中.nm_modname字段需要与模块名完全匹配，区分大小写。

**错误示例**
以下代码为模块名为nativerender时的错误示例

```cpp
EXTERN_C_START
napi_value Init(napi_env env, napi_value exports)
{
    // ...
    return exports;
}
EXTERN_C_END

static napi_module nativeModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    //没有在nm_register_func对应的函数加上static
    .nm_register_func = Init,
    // 模块实现中.nm_modname字段没有与模块名完全匹配，会导致多线程场景模块加载失败
    .nm_modname = "entry",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

//模块注册的入口函数名为RegisterModule，容易与其他模块重复。
extern "C" __attribute__((constructor)) void RegisterModule()
{
    napi_module_register(&nativeModule);
}
```

**正确示例**：
以下代码为模块名为nativerender时的正确示例

```cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // ...
    return exports;
}
EXTERN_C_END

static napi_module nativeModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "nativerender",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterNativeRenderModule()
{
    napi_module_register(&nativeModule);
}
```

## dlopen与模块注册

**【规则】**
如果注册的模块事先有被dlopen，需使用以下方式注册模块。

模块需对外导出固定名称为napi_onLoad的函数，在该函数内调用注册函数。napi_onLoad函数只会在ArkTS代码的import语句中被主动调用，从而避免dlopen时提前触发模块的注册。

**示例**

```cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // ...
    return exports;
}
EXTERN_C_END

static napi_module nativeModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "nativerender",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

extern "C" void napi_onLoad()
{
    napi_module_register(&nativeModule);
}
```

## 正确的使用napi_create_external系列接口创建的JS Object

**【规则】** napi_create_external系列接口创建出来的JS对象仅允许在当前线程传递和使用，跨线程传递（如使用worker的post_message）将会导致应用crash。若需跨线程传递绑定有Native对象的JS对象，请使用napi_coerce_to_native_binding_object接口绑定JS对象和Native对象。

**错误示例**

```cpp
static void MyFinalizeCB(napi_env env, void *finalize_data, void *finalize_hint) { return; }

static napi_value CreateMyExternal(napi_env env, napi_callback_info info) {
    napi_value result = nullptr;
    napi_create_external(env, nullptr, MyFinalizeCB, nullptr, &result);
    return result;
}

// 此处已省略模块注册的代码，你可能需要自行注册 CreateMyExternal 方法
```

```ts
// index.d.ts
export const createMyExternal: () => Object;

// 应用代码
import testNapi from 'libentry.so';
import worker from '@ohos.worker';

const mWorker = new worker.ThreadWorker('../workers/Worker');

{
    const mExternalObj = testNapi.createMyExternal();

    mWorker.postMessage(mExternalObj);

}

// 关闭worker线程
// 应用可能在此步骤崩溃，或在后续引擎进行GC的时候崩溃
mWorker.terminate();
// Worker的实现为默认模板，此处省略
```

## 防止重复释放获取的buffer

**【规则】** 使用napi_get_arraybuffer_info等接口，参数data资源开发者不允许释放，data的生命周期受引擎管理。

这里以napi_get_arraybuffer_info为例，该接口定义如下：

```cpp
napi_get_arraybuffer_info(napi_env env, napi_value arraybuffer, void** data, size_t* byte_length)
```

data获取的是ArrayBuffer的Buffer头指针，开发者只可以在范围内读写该Buffer区域，不可以进行释放操作。该段内存由引擎内部的ArrayBuffer Allocator管理，随JS对象ArrayBuffer的生命周期释放。

**错误示例：**

```cpp
void* arrayBufferPtr = nullptr;
napi_value arrayBuffer = nullptr;
size_t createBufferSize = ARRAY_BUFFER_SIZE;
napi_status verification = napi_create_arraybuffer(env, createBufferSize, &arrayBufferPtr, &arrayBuffer);
size_t arrayBufferSize;
napi_status result = napi_get_arraybuffer_info(env, arrayBuffer, &arrayBufferPtr, &arrayBufferSize);
delete arrayBufferPtr; // 这一步是禁止的，创建的arrayBufferPtr生命周期由引擎管理，不允许用户自己delete，否则会double free
```

|Node-API中受当前规则约束的接口有：|
|----------------------------------|
| napi_create_arraybuffer          |
| napi_create_sendable_arraybuffer |
| napi_get_arraybuffer_info        |
| napi_create_buffer               |
| napi_get_buffer_info             |
| napi_get_typedarray_info         |
| napi_get_dataview_info           |

## 其他

**【建议】** 合理使用napi_object_freeze和napi_object_seal来控制对象以及对象属性的可变性。

napi_object_freeze等同于Object.freeze语义，freeze后对象的所有属性都不可能以任何方式被修改；napi_object_seal等同于Object.seal语义，对象不可增删属性。两者的主要区别是，freeze不能改属性的值，seal还可以改属性的值。

开发者使用以上语义时，需确保约束条件是自己需要的，一旦违背以上语义严格模式下就会抛出Error（默认严格模式）。

## 参考文档

[Native侧子线程与UI主线程通信开发](https://developer.huawei.com/consumer/cn/doc/best-practices-V5/bpta-native-sub-main-comm-V5);

[如何在Native侧C++子线程直接调用ArkTS接口，不用通过ArkTS侧触发回调](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-ndk-8-V5);

[napi_env、napi_value实例是否可以跨worker线程共享](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-ndk-55-V5);

[Native如何创建子线程，有什么约束，与主线程如何通信](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-ndk-68-V5).