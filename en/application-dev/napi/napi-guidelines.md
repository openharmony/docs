# Node-API Development Specifications

## Obtaining Arguments Passed by JS

**[Rule]** When **argv** in **napi_get_cb_info** is not **nullptr**, the length of **argv** must be greater than or equal to **argc**.

If **argv** is not **nullptr**, the arguments actually passed by JS will be copied to **argv** in **napi_get_cb_info** based on the value of **argc**. If there are more arguments than the provided count, only the requested number of arguments are copied. If there are fewer arguments provided than the claimed, the rest of **argv** is filled with values that represent **undefined**.

**Example (incorrect)**

```cpp
static napi_value IncorrectDemo1(napi_env env, napi_callback_info info) {
    // argc is not correctly initialized and is set to a random value. If the length of argv is less than the number of arguments specified by argc, data overwriting occurs.
    size_t argc;
    napi_value argv[10] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}

static napi_value IncorrectDemo2(napi_env env, napi_callback_info info) {
    // The number of arguments specified by argc is greater than the length of argv. As a result, data overwriting occurs when napi_get_cb_info writes argv.
    size_t argc = 5;
    napi_value argv[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}
```

**Example (correct)**

```cpp
static napi_value GetArgvDemo1(napi_env env, napi_callback_info info) {
    size_t argc = 0;
    // Pass in nullptr to argv to obtain the actual number of arguments passed by JS.
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
    // If 0 is passed by JS, the subsequent logic is not executed.
    if (argc == 0) {
        return nullptr;
    }
    // Create an array to obtain the arguments passed by JS.
    napi_value* argv = new napi_value[argc];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Service code.
    // ...
    // argv is an object created by new and must be manually released when it is not required.
    delete argv;
    return nullptr;
}

static napi_value GetArgvDemo2(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    // napi_get_cb_info writes the arguments (of the quantity specified by argc) passed by JS or undefined to argv.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Service code.
    // ...
    return nullptr;
}
```

## Lifecycle Management

**[Rule]** Properly use **napi_open_handle_scope** and **napi_close_handle_scope** to minimize the lifecycle of **napi_value** and avoid memory leaks.

Each **napi_value** belongs to a specific **HandleScope**, which is opened and closed by **napi_open_handle_scope** and **napi_close_handle_scope**, respectively. After a **HandleScope** is closed, its **napi_value** is automatically released.

**Example (correct)**

```cpp
// When Node-API is frequently called to create JS objects in the for loop, use handle_scope to release resources in a timely manner when they are no longer used.
// In the following example, the lifecycle of the local variable res ends at the end of each loop. To prevent memory leaks, scope is used to release the JS object in a timely manner.
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

## Context Sensitive

**[Rule]** Do not use Node-API to access JS objects across engine instances.

An engine instance is an independent running environment. Operations such as creating and accessing a JS object must be performed in the same engine instance. If an object is operated in different engine instances, the application may crash. An engine instance is represented as a value of **napi_env** in APIs.

**Example (incorrect)**

```cpp
// Create a string object with value of "bar" in env1.
napi_create_string_utf8(env1, "bar", NAPI_AUTO_LENGTH, &string);
// Create an object in env2 and set the string object to this object.
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

JS objects belong to a specific **napi_env**. Therefore, you cannot set an object of env1 to an object of env2. If the object of env1 is accessed in env2, the application may crash.

## Exception Handling

**[Suggestion]** Any exception occurred in a Node-API call should be handled in a timely manner. Otherwise, unexpected behavior may occur.

**Example (correct)**

```cpp
// 1. Create an object.
napi_status status = napi_create_object(env, &object);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
// 2. Create a property.
status = napi_create_string_utf8(env, "bar", NAPI_AUTO_LENGTH, &string);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
// 3. Set the result of step 2 to the value of the object property foo.
status = napi_set_named_property(env, object, "foo", string);
if (status != napi_ok) {
    napi_throw_error(env, ...);
    return;
}
```

In this example, if an exception occurs in step 1 or step 2, step 3 will not be performed. Step 3 will be performed only when napi_ok is returned in steps 1 and 2.

## Asynchronous Tasks

**[Rule]** When the **uv_queue_work** method is called to throw a work to a JS thread for execution, use **napi_handle_scope** to manage the lifecycle of **napi_value** created by the JS callback.

The Node-API framework will not be used when the **uv_queue_work** method is called. In this case, you must use **napi_handle_scope** to manage the lifecycle of **napi_value**.

> **NOTE**
>
> This rule focuses on the **napi_value** lifecycle. If you only want to throw tasks to the JS thread, you are advised not to use **uv_queue_work**. To throw tasks, use [napi_threadsafe_function](./use-napi-thread-safety.md) APIs.

**Example (correct)**

```cpp
void callbackTest(CallbackContext* context)
{
    uv_loop_s* loop = nullptr;
    napi_get_uv_event_loop(context->env, &loop);
    uv_work_t* work = new uv_work_t;
    context->retData = 1;
    work->data = (void*)context;
    uv_queue_work(
        loop, work,
        // Note that uv_queue_work creates a thread and executes the callback. If you only want to throw tasks to the JS thread, you are advised not to use uv_queue_work to avoid creation of redundant threads.
        [](uv_work_t* work) {
            // Execute service logic.
        },
        // The callback is executed on the JS thread where the loop is located.
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

## Object Wrapping

**[Rule]** If the value of the last parameter **result** is not **nullptr** in **napi_wrap()**, use **napi_remove_wrap()** at a proper time to delete the created **napi_ref**.

The **napi_wrap** interface is defined as follows:

```cpp
napi_wrap(napi_env env, napi_value js_object, void* native_object, napi_finalize finalize_cb, void* finalize_hint, napi_ref* result)
```

When the last parameter **result** is not null, the Node-API framework creates an **napi_ref** object pointing to **js_object**. You need to manage the lifecycle of **js_object**. Specifically, use **napi_remove_wrap** to delete **napi_ref** at a proper time so that the garbage collector (GC) can release **js_object** and trigger the destructor **finalize_cb** bound to the C++ object **native_object**.

Generally, you can directly pass in **nullptr** for the last parameter **result**.

**Example (correct)**

```cpp
// Case 1: Pass in nullptr via the last parameter in napi_wrap. In this case, the created napi_ref is a weak reference, which is managed by the system and does not need manual release.
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// Case 2: The last parameter in napi_wrap is not nullptr. In this case, the returned napi_ref is a strong reference and needs to be manually released. Otherwise, a memory leak may occur.
napi_ref result;
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// When js_object and result are no longer used, call napi_remove_wrap to release result.
void* nativeObjectResult = nullptr;
napi_remove_wrap(env, jsobject, &nativeObjectResult);
```

## Arrays for High Performance

**[Suggestion]** Use ArrayBuffer instead of JSArray to store value-type data for higher performance.

JSArray is used as a container to store data and supports almost all JS data types.

When **napi_set_element** is used to store value-type data (such as int32) in JSArray, interaction with the runtime is involved, which causes unnecessary overhead.

The operations on ArrayBuffer are performed in the buffer, which delivers higher performance than using **napi_set_element** to operate JSArray.

Therefore, you are advised to use the **ArrayBuffer** object created by **napi_create_arraybuffer** in this scenario.

**Example:**

```cpp
// In the following code, JSArray is used to store only int32 data.
// Since JSArray is a JS object, only Node-API methods can be used to operate it, which compromises the performance.
static napi_value ArrayDemo(napi_env env, napi_callback_info info)
{
    constexpr size_t arrSize = 1000;
    napi_value jsArr = nullptr;
    napi_create_array(env, &jsArr);
    for (int i = 0; i < arrSize; i++) {
        napi_value arrValue = nullptr;
        napi_create_int32(env, i, &arrValue);
        // Using Node-API methods to read and write JSArray affects the performance.
        napi_set_element(env, jsArr, i, arrValue);
    }
    return jsArr;
}

// To improve the performance, modify the code as follows:
// Use ArrayBuffer to hold int32 data.
// In this case, C/C++ methods can be used to directly add or modify data in the buffer.
static napi_value ArrayBufferDemo(napi_env env, napi_callback_info info)
{
    constexpr size_t arrSize = 1000;
    napi_value arrBuffer = nullptr;
    void* data = nullptr;

    napi_create_arraybuffer(env, arrSize * sizeof(int32_t), &data, &arrBuffer);
    // data is a null pointer. Cancel the write of data.
    if (data == nullptr) {
        return arrBuffer;
    }
    int32_t* i32Buffer = reinterpret_cast<int32_t*>(data);
    for (int i = 0; i < arrSize; i++) {
        // Using arrayBuffer allows data to be directly modified in the buffer, which eliminates the interaction with the runtime.
        // The performance is equivalent to that of operating native C/C++ objects.
        i32Buffer[i] = i;
    }

    return arrBuffer;
}
```

**napi_create_arraybuffer** is equivalent to **new ArrayBuffer(size)** in JS. The object generated cannot be directly read in TS/JS. It can be read or written only after being encapsulated into a TyppedArray or DataView object.

**Benchmark performance test result**:

> **NOTE**
>
> The following data is the accumulated data written in thousands of cycles. To better reflect the difference, the core frequency of the device has been limited.

| Container Type   | Benchmark Data (us)|
| ----------- | ------------------- |
| JSArray     | 1566.174            |
| ArrayBuffer | 3.609               |

## Data Conversion

**[Suggestion]** Minimize the number of data conversions and avoid unnecessary replication.

- Frequent data conversion affects performance. You are advised to use batch data processing or optimize the data structs to improve performance.
- During data conversion, use Node-API to access the original data instead of creating a copy.
- For the data that may be used in multiple conversions, store it in a buffer to avoid repeated data conversions. In this way, unnecessary calculations can be reduced, leading to better performance.

## Module Registration and Naming

**[Rule]**
Add "static" to the function corresponding to **nm_register_func** to prevent conflicts with symbols in other .so files.

The module registration entry, that is, the name of the function decorated by **__attribute__((constructor))** must be different from that of other modules.

The **.nm_modname** field must completely match the module name and is case sensitive.

**Example (incorrect)**
In the following example, the module name is **nativerender**.

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
    // static is not added to the function corresponding to nm_register_func.
    .nm_register_func = Init,
    // The .nm_modname value does not match the module name. As a result, the module fails to be loaded in the multi-thread scenario.
    .nm_modname = "entry",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

// The name of the module registration entry function is RegisterModule, which is easy to be duplicate with that of other modules.
extern "C" __attribute__((constructor)) void RegisterModule()
{
    napi_module_register(&nativeModule);
}
```

**Example (correct)**
In the following example, the module name is **nativerender**.

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

## Using JS Objects Created by napi_create_external APIs

**[Rule]** The JS object created by **napi_create_external** APIs can be passed and used only in the calling thread. If it is passed across threads (for example, using **post_message** of the **worker** interface), the application may crash. If a JS object bound with a native object needs to be passed across threads, use **napi_coerce_to_native_binding_object** to bind the two objects.

**Example (incorrect)**

```cpp
static void MyFinalizeCB(napi_env env, void *finalize_data, void *finalize_hint) { return; }

static napi_value CreateMyExternal(napi_env env, napi_callback_info info) {
    napi_value result = nullptr;
    napi_create_external(env, nullptr, MyFinalizeCB, nullptr, &result);
    return result;
}

// The code for module registration is omitted here. You may need to register the CreateMyExternal method.
```

```ts
// index.d.ts
export const createMyExternal: () => Object;

// Application code.
import testNapi from 'libentry.so';
import worker from '@ohos.worker';

const mWorker = new worker.ThreadWorker('../workers/Worker');

{
    const mExternalObj = testNapi.createMyExternal();

    mWorker.postMessage(mExternalObj);

}

// Close the worker thread.
// The application may crash in this step or when the engine performs GC.
mWorker.terminate();
// The implementation of worker is the default template, which is omitted here.
```

## Avoiding Releasing the Obtained Buffer Repeatedly

**[Rule]** The parameter **data** in certain APIs, such as **napi_get_arraybuffer_info**, cannot be released manually. Its lifecycle is managed by the engine.

The following uses **napi_get_arraybuffer_info** as an example to describe the interface definition:

```cpp
napi_get_arraybuffer_info(napi_env env, napi_value arraybuffer, void** data, size_t* byte_length)
```

The parameter **data** specifies the buffer header pointer to **ArrayBuffer**. This buffer can be read and written in the given range but cannot be released. The buffer memory is managed by the ArrayBuffer Allocator in the engine and is released with the lifecycle of the JS object **ArrayBuffer**.

**Example (incorrect)**

```cpp
void* arrayBufferPtr = nullptr;
napi_value arrayBuffer = nullptr;
size_t createBufferSize = ARRAY_BUFFER_SIZE;
napi_status verification = napi_create_arraybuffer(env, createBufferSize, &arrayBufferPtr, &arrayBuffer);
size_t arrayBufferSize;
napi_status result = napi_get_arraybuffer_info(env, arrayBuffer, &arrayBufferPtr, &arrayBufferSize);
delete arrayBufferPtr; // This operation is not allowed and may cause a double free of the buffer. The lifecycle of the created arrayBufferPtr is managed by the engine and cannot be manually deleted.
```

|Applicable APIs|
|----------------------------------|
| napi_create_arraybuffer          |
| napi_create_sendable_arraybuffer |
| napi_get_arraybuffer_info        |
| napi_create_buffer               |
| napi_get_buffer_info             |
| napi_get_typedarray_info         |
| napi_get_dataview_info           |

## Others

**[Suggestion]** Properly use **napi_object_freeze** and **napi_object_seal**.

**napi_object_freeze** is equivalent to **Object.freeze**. After an object is frozen, all its properties are immutable. **napi_object_seal** is equivalent to **Object.seal**. After an object is sealed, no properties can be added or deleted, but the existing property values are mutable.

If the semantics are violated in strict mode (default), an error will be thrown.

## Reference

[Communication Between Native Child Threads and the UI Main Thread](https://developer.huawei.com/consumer/en/doc/best-practices-V5/bpta-native-sub-main-comm-V5)

[How do I directly call ArkTS APIs in a C++ subthread on the native side without triggering callbacks on the ArkTS side?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-ndk-8-V5)

[Are napi_env and napi_value instances shared across worker threads?] (https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-ndk-55-V5)

[How do I create a subthread on the native side? What are the restrictions? How does the native subthread communicate with the main thread?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-ndk-68-V5)
