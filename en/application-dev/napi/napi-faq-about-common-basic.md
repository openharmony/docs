# FAQs About Basic Functionalities
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## What should I do if the module fails to be loaded and the error message "Error message: is not callable" is displayed?

- Question:
When the **libxxx.so** file provided by the following module registration code is used to call the API of the dynamic library in some projects, **Error message: is not callable** is displayed.
```cpp
static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "xxx",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule()
{
    napi_module_register(&demoModule);
}
```
  
- Answer: 
1. You can locate and resolve the issue based on the following topics:    
[What should I do if an error message "undefined" is displayed on the ArkTS side](napi-faq-about-common-basic.md#what-should-i-do-if-an-error-message-undefined-is-displayed-on-the-arkts-side) 
[Module Registration and Naming](napi-guidelines.md#module-registration-and-naming) 
2. You can also check whether the dynamic loading capability is sufficient for this scenario. 
[Scenarios Supported by napi_load_module_with_info](use-napi-load-module-with-info.md#scenarios-supported-by-napi_load_module_with_info) 
[Scenarios Supported by napi_load_module](use-napi-load-module.md#scenarios-supported-by-napi_load_module) 

## How to ensure the order of asynchronous tasks in scenarios where a large number of ArkTS methods need to be called for communication

- Question: In a scenario where a large number of ArkTS methods need to be called through C++ for communication, how to ensure the order of asynchronous tasks?
- Answer: 
You can use **napi_call_threadsafe_function** to ensure the execution sequence of asynchronous tasks. Ensure that the asynchronous tasks are delivered to the ArkTS thread for execution. If the asynchronous tasks are delivered to the main thread, the application may freeze and exit if they are executed for a long time. Therefore, you are not advised to deliver long-time tasks to the main thread through thread-safe functions.  
[Thread Safety Development Using Node-API](use-napi-thread-safety.md)

In addition, the differences between the common task throwing methods in Node-API are as follows:

1. The **napi_async_work** APIs can ensure that **execute_cb** is executed before **complete_cb**, but cannot ensure the sequence of different **napi_async_work**. 
Based on the common **napi_queue_async_work**, [napi_queue_async_work_with_qos](../../application-dev/reference/native-lib/napi.md#napi_queue_async_work_with_qos) supports custom QoS priority. However, it only specifies the thread priority when libuv schedules tasks, not the task priority. Therefore, the task sequence cannot be ensured.  
2. The **napi_threadsafe_function** APIs maintain a queue to ensure the task execution sequence. 
**napi_call_threadsafe_function** is executed in the first in first out (FIFO) sequence.
**napi_call_threadsafe_function_with_priority** is executed according to the specified queueing mode.
[Passing a Task with the Specified Priority to an ArkTS Thread from an Asynchronous Thread Using Node-API](use-call-threadsafe-function-with-priority.md)

## Is there a convenient way to call back ArkTS

- Question: 
During multi-thread development, ArkTS functions can be executed only on the thread where they are created. C++ threads cannot call ArkTS callbacks in **napi_call_function** mode. Is there a convenient method? 
References 
[Implementing Communication Between Native Child Threads and the UI Main Thread](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-native-sub-main-comm)  
[Asynchronous Task Development Using Node-API](use-napi-asynchronous-task.md)  

## How do I call back the ArkTS method in C++ code?

- References 
[How do I invoke a function transferred from ArkTS in a C++ subthread?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-26)   

## How to ensure the correct mapping of data types and the security of memory management

- Question: While complying with the single return value constraint of Node-API, how to securely and efficiently pass multiple return values (including structured data and pointer information) to the ArkTS runtime environment and ensure correct data type mapping and memory management security?
- Answer:  
Although the **napi_value** API supports only a single return value, you can use the return value to encapsulate all required information.

For example, you can use **napi_create_object** to create an ArkTS object and use it to carry all returned information. **number** and **string** can be set to this object through the API set by properties such as **napi_set_property** or **napi_set_named_property**. You can also use **napi_wrap** to bind a native object to an ArkTS object, and then use **napi_unwrap** to retrieve the native object.  
In addition, you can use an ArkTS array to carry data, which is flexible.   
- References  
[Working with Objects Using Node-API](use-napi-about-object.md)   
[Working with Arrays Using Node-API](use-napi-about-array.md)   

## What are the error codes of the napi_get_uv_event_loop API

Additional parameter verification is added to prevent use of invalid **napi_env** in **napi_get_uv_event_loop**. The return value indicates the verification result. The return values of this API are as follows:

1. If **env** and/or **loop** are **nullptr**, **napi_invalid_arg** is returned.
2. If **env** is a valid **napi_env** and **loop** is a valid pointer, **napi_ok** is returned.
3. If **env** is not a valid **napi_env** (for example, a released **env**), **napi_generic_failure** is returned.

- Example:

```c++
napi_value NapiInvalidArg(napi_env env, napi_callback_info)
{
    napi_status status = napi_ok;
    status = napi_get_uv_event_loop(env, nullptr); // loop is nullptr, and the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    uv_loop_s* loop = nullptr;
    status = napi_get_uv_event_loop(nullptr, &loop); // env is nullptr, and the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    status = napi_get_uv_event_loop(nullptr, nullptr); // env and loop are nullptr, and the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}

napi_value NapiGenericFailure(napi_env env, napi_callback_info)
{
    std::thread([]() {
        napi_env env = nullptr;
        napi_create_ark_runtime(&env); // Generally, the return value needs to be checked.
        // napi_destroy_ark_runtime sets the pointer to null. Copy the pointer to simulate the problem.
        napi_env copiedEnv = env;
        napi_destroy_ark_runtime(&env);
        uv_loop_s* loop = nullptr;
        napi_status status = napi_get_uv_event_loop(copiedEnv, &loop); // env is invalid, and the status code is napi_generic_failure.
        if (status == napi_ok) {
            // do something
        }
    }).detach();
}
```

## Must a function be passed to the native layer when the native layer calls the object method of the ArkTS layer

- Question: When the native layer of Node-API calls an object method from the ArkTS layer, must a function be passed to the native layer?
- Answer: 
To call an object method of the ArkTS layer at the native layer, the native layer needs to obtain the ArkTS function object. 
You can obtain the ArkTS function object in any of the following ways: 
1. Pass the function from the ArkTS layer to the native layer.  
2. Bind the ArkTS function to an object that can be accessed by the native layer by setting attributes. In this way, the native layer can obtain and call the function through the object.  
3. Node-API provides **napi_create_function** to create an ArkTS function object in the native layer. In this way, the native layer can obtain the ArkTS function object.  

## Can I call an ArkTS method and obtain the result

- Question: Can the thread created by using **pthread** or **std::thread** in C++ call an ArkTS method and obtain the result?
Possible causes: 
If the thread is created directly in C++, it does not have the ArkTS running environment, specifically the corresponding **napi_env**. Calling ArkTS methods on the thread directly causes multi-thread security issues, which is an undefined behavior. 

- Answer: 
1. Use the Node-API of **napi_threadsafe_function** to throw tasks from the C++ thread to the ArkTS thread for executing the ArkTS method. 
[Thread Safety Development Using Node-API](use-napi-thread-safety.md) 
2. Create an ArkTS running environment in the C++ thread.  
[Creating an ArkTS Runtime Environment Using Node-API](use-napi-ark-runtime.md)  

## Whether there is a napi_get_value_string_utf8 API or capability that does not need the copy operation

- Question: The **napi_get_value_string_utf8** API of Node-API needs a copy operation each time it is called. Is there a **napi_get_value_string_utf8** API or capability that does not need the copy operation? 
- Answer:  
No, **napi_get_value_string_utf8** always needs a copy operation.

It is necessary because the string lifecycle is involved. When GC is triggered, the ArkTS object may be moved to another place or reclaimed in the VM. If an address of a char* type is returned, the memory may change after the object is moved or reclaimed. 

## What are the precautions for using napi_env in multi-thread mode

- Question:  
What are the precautions for using **napi_env** in multi-thread mode? Is there any exception caused by **napi_env** switchover? Must **napi_env** be used in the main thread? 

- Answer:  
1. **napi_env** is bound to the ArkTS thread, so that it cannot be used across threads. Otherwise, stability issues may occur.
[Multithread Processing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-process#multithread-processing)
2. When using **env** to call Node-APIs, note that most Node-APIs can only be called on the ArkTS thread to which **env** belongs. Otherwise, thread-safety issues may arise.
    
3. Do not cache napi_env. Otherwise, thread-safety issues and **use-after-free** issues may occur.  
 
4. [Why cannot napi_env be cached?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-73)

## What should I do if the napi_call_threadsafe_function execution sequence does not meet the expectation

- Question:  
The expected execution sequence of **napi_call_threadsafe_function** is a -> b -> c. 
  
posttask(a);  
posttask(b);  
posttask(c);  
However, the actual execution sequence is b -> a -> c. 

- Answer: 
1. Check whether the same **napi_threadsafe_function** instance is used. If not, the execution sequence may be different.  
Note: For the same **napi_threadsafe_function**, the execution sequence of **napi_call_threadsafe_function** is guaranteed. The first function called is executed first. 
2. Check whether the actual call sequence of **napi_threadsafe_function** is a -> b -> c.  


## What should I do if an error message "undefined" is displayed on the ArkTS side
Question:
What should I do when "undefined/not callable" or specific error message is reported for xxx after "import xxx from libxxx.so" is executed on ArkTS?
1. Check whether the module name in the .cpp file used in module registration is the same as that in the .so file name.
   If the module name is **entry**, the .so file name must be **libentry.so**, and the **nm_modname** field in **napi_module** must be **entry**. The module names must be of the same case.

2. Check whether the .so file is successfully loaded.
   Check the logs related to module loading during the application startup. Search for the keyword "dlopen" and check for error information. Generally, a loading failure is caused when the file to be loaded does not exist or is in a blocklist or the application does not have the required permission. In multi-thread scenarios (such as worker threads and taskpool), check whether **nm_modname** is the same as the module name. The module names must be of the same case.

3. Check whether the dependency .so files are successfully loaded.
   Check that all the dependency .so files are packaged into the application and the application has the permission to open them.  


| **Error Log**| **Fault Analysis & Solution**|
| -------- | -------- |
| module $SO is not allowed to load in restricted runtime. | The module, identified by **$SO**, is not allowed for the worker thread running in a restricted environment and cannot be loaded. You are advised to delete the module.|
| module $SO is in blocklist, loading prohibited. | The module, identified by **$SO**, is in the blocklist due to the control of the widget or Extension, and cannot be loaded. You are advised to delete the module.|
| load module failed. $ERRMSG. | The dynamic library fails to be loaded. **$ERRMSG** indicates the cause of the loading failure. Possible causes include the following:<br>- The .so file to be loaded does not exist.<br>- The dependency .so file does not exist. <br>- Undefined symbol is found. <br>Locate the cause based on the error message.|
| try to load abc file from $FILEPATH failed. | You can load either a dynamic library or an .abc file. If this log information is displayed when you attempt to load a dynamic library, ignore this message. If it is displayed when you attempt to load an .abc file, the .abc file does not exist. **$FILEPATH** indicates the module path.|

5. If specific error message is reported, identify the fault based on the error message.

| **Error message** | **Fault Analysis & Solution**|
| -------- | -------- |
| First attempt: $ERRMSG. | Loading the .so file with the module name of "xxx" fails. *$ERRMSG* indicates the error information.|
| Second attempt: $ERRMSG. | Loading the .so file with the module name of "xxx_napi" fails. *$ERRMSG* indicates the error information.|
| try to load abc file from xxx failed. | Loading the .abc file fails. *xxx* indicates the name of the .abc file.|
| module xxx is not allowed to load in restricted runtime. | This module cannot be used in restricted runtime. *xxx* indicates the module name. You are advised to delete the module.|
| module xxx is in blocklist, loading prohibited. | The module cannot be used in the current extension. *xxx* indicates the module name. You are advised to delete the module.|

## What should I do if the API execution result is unexpected

Question: What should I do when an unexpected value is returned by an API and "occur exception need return" is reported?

Before the call is complete, some Node-APIs are checked for ArkTS exceptions in the VM. If an exception is detected, "occur exception need return" will be reported, with the line number of the code and the Node-API name.

Answer:

- If the exception does not matter, clear the exception.
  Call **napi_get_and_clear_last_exception** before "occur exception need return" is printed to clear the exception.

- Throw the exception to the ArkTS layer for capture.
  Throw the exception directly to the ArkTS layer without going through the native logic.

## What are the differences between the lifecycle of napi_value and napi_ref

- **napi_value** is managed by **HandleScope**. Generally, you do not need to add **HandleScope** for **napi_value** (except for complete callback of **uv_queue_work**).

- **napi_ref** must be deleted manually.

## How do I locate the fault if the return value of a Node-API is not "napi_ok"

When a Node-API is successfully executed, **napi_ok** is returned. If the return value is not **napi_ok**, see [Node-API Status Codes](napi_status_introduction.md).

Locate the fault as follows:

- Check the result of the input parameter null check, which is performed first before a Node-API is executed. The code is as follows:

  ```cpp
  CHECK_ENV: null check for env.
  CHECK_ARG: null check for other input parameters.
  ```

- Check the result of the input parameter type check, which is performed for certain Node-APIs. For example, **napi_get_value_double** is used to obtain a C double value from an ArkTS number, and the type of the ArkTS value passed in must be number. The parameter type check is as follows:

  ```cpp
  RETURN_STATUS_IF_FALSE(env, NativeValue->TypeOf() == Native_NUMBER, napi_number_expected);
  ```

- Check the return value, which contains the verification result of certain APIs. For example, **napi_call_function** is used to execute an ArkTS function. If an exception occurs in the ArkTS function, Node-API returns **napi_pending_exception**.

  ```cpp
  // Internal implementation of the API. The status value is returned after verification.
  auto resultValue = engine->CallFunction(NativeRecv, NativeFunc, NativeArgv, argc);
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- Determine the status value returned, and analyze the situation in which the status value is returned.

## How do I ensure that objects wrapped by napi_wrap are destructed in the expected order
Question: When using **napi_wrap** to bind two C++ objects to two JavaScript objects, I need to ensure that the first C++ object is destroyed before the second, since the first depends on the second. However, the JavaScript garbage collection (GC) time is uncertain. If the C++ objects are destroyed directly in the **finalize_cb** callback of **napi_wrap**, the destruction sequence cannot meet the requirements. How do I ensure the destruction sequence of two C++ objects?

Answer: 
Mark both A and B as releasable and release the C++ object at the same time.  
Principle: All the release logic of dependent objects is processed in the **finalize_cb** of the last ArkTS object to be destroyed. 
Procedure:  
Mark **cppObjA** as to-be-destroyed (not released immediately) in **finalize_cb** of **jsObjA**. 
Mark **cppObjB** as to-be-destroyed (not released immediately) in **finalize_cb** of **jsObjB**. 
When **jsObjA** and **jsObjB** are to be destroyed, destroy **cppObjA** and **cppObjB** in sequence. 
The sample code is as follows: 
```cpp
struct ObjectPair {
    CppObjA* objA;
    CppObjB* objB;
    bool objADestroyedA = false;
    bool objADestroyedB = false;
};

// finalize callback of jsObjA.
void FinalizeA(napi_env env, void* data, void* hint) {
    ObjectPair* pair = static_cast<ObjectPair*>(data);
    pair->objADestroyedA = true;
    if (pair->objADestroyedA && pair->objADestroyedB) {
        delete pair->objA; // Ensure that object A is destroyed first.
        delete pair->objB; // Destroy object B.
        delete pair;       // Release the wrapper structure.
    }
}

// finalize callback of jsObjB.
void FinalizeB(napi_env env, void* data, void* hint) {
    ObjectPair* pair = static_cast<ObjectPair*>(data);
    pair->objADestroyedB = true;
    if (pair->objADestroyedA && pair->objADestroyedB) {
        delete pair->objA; // Ensure that object A is destroyed first.
        delete pair->objB; // Destroy object B.
        delete pair;       // Release the wrapper structure.
    }
}
```
## What should I do if the napi_call_threadsafe_function callback task is not executed

Answer: 
Cause 1: The return value of **napi_call_threadsafe_function** is not **napi_ok**. Check whether all the return values of the **napi_call_threadsafe_function** calls are **napi_ok**. If not, locate the cause by referring to [Node-API Status Codes](napi_status_introduction.md). 
Cause 2: The ArkTS thread to which **env** belongs is blocked. The callback of **napi_call_threadsafe_function** is executed on the ArkTS thread to which **env** belongs. If the ArkTS thread is blocked, the thread-safe function callback will not be executed. 
Cause 3: The **uv_async_t** handle of the thread-safe function is re-initialized, and the task is not executed. All **uv_async_t** handles created during the first initialization and repeated initialization cannot be accessed by uv. Since the thread-safe function is implemented based on the **uv_async_t** mechanism, it is invalid in this scenario. 

## How to use development tools to quickly develop Node-APIs using C/C++ code?

OpenHarmony provides various Node-API examples. You can quickly learn the Node-API module development process by referring to the guides and sample projects.

With development tools such as [AKI](https://gitcode.com/openharmony-sig/aki) and [napi-generator](https://gitcode.com/openharmony/napi_generator), you can develop Node-APIs more easily and efficiently.
