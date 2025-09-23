# FAQs About Basic Functions
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## What should I do if the module fails to be loaded and the error message "Error message: is not callable." is displayed?

- Description
When the libxxx.so file provided by the following module registration code is used to call the API of the dynamic library in some projects, `Error message: is not callable` is displayed.
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
  
- Suggestions: 
1. Perform the check according to the following documents:    
[After xxx is imported from libxxx.so on the ArkTS side, an error message "undefined/not callable" or a specific error message is displayed when xxx is used.](napi-faq-about-common-basic.md) 
[Module Registration and Naming](napi-guidelines.md) 
2. You can also check whether the dynamic loading capability can meet the requirements of this scenario. 
[Scenarios supported by napi_load_module_with_info](use-napi-load-module-with-info.md) 
[Scenarios supported by napi_load_module](use-napi-load-module.md) 

## How to ensure the order of asynchronous tasks in scenarios where a large number of ArkTS methods need to be called for communication?

- Specific question: In a large number of scenarios where ArkTS methods need to be called through C++ for communication, how to ensure the order of asynchronous tasks?
- Reference solutions 
For details, see the thread-safe function. The napi_call_threadsafe_function can ensure the execution sequence of asynchronous tasks. Note that these asynchronous tasks are delivered to the ArkTS thread for execution in sequence. If the asynchronous tasks are delivered to the main thread, the execution time of the asynchronous tasks is too long, which may cause the application to freeze and exit, therefore, you are not advised to deliver time-consuming tasks to the main thread through thread-safe functions.  
[Thread Safety Development Using Node-API](use-napi-thread-safety.md)

In addition, the differences between the common task throwing methods in Node-API are as follows:

1. The napi_async_work series APIs can ensure that execute_cb is executed before complete_cb, but cannot ensure the timing of different napi_async_work. 
Based on the common napi_queue_async_work, the [napi_queue_async_work_with_qos](../../application-dev/reference/native-lib/napi.md#napi_queue_async_work_with_qos) supports the user-defined QoS priority. However, the [napi_queue_async_work_with_qos](../../application-dev/reference/native-lib/napi.md#napi_queue_async_work_with_qos) only specifies the priority of the thread used by the libuv to schedule tasks, not the task priority. Therefore, the task time sequence cannot be ensured.  
2. The napi_threadsafe_function series APIs maintain a queue to ensure the task execution sequence. 
napi_call_threadsafe_function is executed in the first in first out (FIFO) sequence.
The napi_call_threadsafe_function_with_priority is executed based on the specified enqueuing mode.
[Passing a Task with the Specified Priority to an ArkTS Thread from an Asynchronous Thread Using Node-API](use-call-threadsafe-function-with-priority.md)

## Is there a convenient way to call back ArkTS?

- Detailed description: 
During multi-thread development, ArkTS functions can be executed only on the creation thread. C++ threads cannot directly call ArkTS callbacks in the form of napi_call_function. Is there any convenient method? 
Reference documents: 
[Communication between Native subthreads and the UI main thread](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-native-sub-main-comm)  
[Asynchronous Task Development Using Node-API](use-napi-asynchronous-task.md)  

## How do I call back the ArkTS method in C++ code?

- Reference document:  
[How to Call a Function Transferred from ArkTS in C++](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-26)   

## How to ensure the correct mapping of data types and the security of memory management?

- Specific question: How to securely and efficiently transfer multiple return values (including structured data and pointer information) to the ArkTS runtime environment while complying with the N-API single return value constraint, and ensure correct data type mapping and memory management security?
- Refer to the code snippet below:  
Although the napi_value API supports only a single return value, you can use the return value to encapsulate all required information.

For example, you can use napi_create_object to create an ArkTS object and use this object to carry all returned information. The number and string can be set to this object through the interface for setting attributes such as napi_set_property/napi_set_named_property. The native object can also be bound to the ArkTS object through the napi_wrap API and then obtained through the napi_unwrap API.  
In addition, an ArkTS array may be used as a data carrier, and has good flexibility.   
- Reference document:   
[Working with Objects Using Node-API](use-napi-about-object.md)   
[Working with Arrays Using Node-API](use-napi-about-array.md)   

## What are the error codes of the napi_get_uv_event_loop interface?

Additional parameter verification is added to prevent use of invalid **napi_env** in **napi_get_uv_event_loop**. The return value indicates the verification result. The return values of this API are as follows:

1. If **env** and/or **loop** are **nullptr**, **napi_invalid_arg** is returned.
2. If **env** is a valid **napi_env** and **loop** is a valid pointer, **napi_ok** is returned.
3. If **env** is not a valid **napi_env** (for example, a released **env**), **napi_generic_failure** is returned.

- Example:

```c++
napi_value NapiInvalidArg(napi_env env, napi_callback_info)
{
    napi_status status = napi_ok;
    If status = napi_get_uv_event_loop(env, nullptr); // loop is nullptr, the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    uv_loop_s* loop = nullptr;
    If status = napi_get_uv_event_loop(nullptr, &loop); // env is nullptr, the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    If status = napi_get_uv_event_loop(nullptr, nullptr); // env, loop is nullptr, the status code is napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}

napi_value NapiGenericFailure(napi_env env, napi_callback_info)
{
    std::thread([]() {
        napi_env env = nullptr;
        napi_create_ark_runtime (&env); // Generally, the return value needs to be checked.
        // napi_destroy_ark_runtime sets the pointer to null. Copy the pointer to simulate the problem.
        napi_env copiedEnv = env;
        napi_destroy_ark_runtime(&env);
        uv_loop_s* loop = nullptr;
        Invalid napi_status status = napi_get_uv_event_loop(copiedEnv, &loop); // env. The status code is napi_generic_failure.
        if (status == napi_ok) {
            // do something
        }
    }).detach();
}
```

## Must a function be transferred to the Native layer when the Native layer invokes the object method of the ArkTS layer?

- Specific question: When the native layer of the Node-API calls the object method at the ArkTS layer, must a function be transferred to the native layer?
- Reference solutions 
If you want to call an ArkTS object method at the Native layer, the Native layer needs to obtain the ArkTS Function object. 
There are multiple ways to obtain the information, for example: 
1. The ArkTS layer is transferred to the Native layer, that is, the solution described in the problem description.  
2. You can bind the ArkTS function to an object that can be accessed by the native layer by setting attributes. In this way, the native layer can obtain the function through the object and call the function.  
3. The Node-API layer also provides the capability of creating an ArkTS Function object, that is, napi_create_function, which can be directly created at the Native layer. In this way, the Native layer can obtain the ArkTS Function object.  

## Can I call the ArkTS method and obtain the result?

- Specific question: Can the thread created using pthread or std::thread in C++ call the ArkTS method and obtain the result?
Possible causes: 
If a C++ thread is directly created, the thread does not have the ArkTS running environment, that is, the thread does not have the corresponding napi_env. If the ArkTS method is directly called on the thread, the multi-thread security problem exists, which is an undefined behavior. 

- Solution reference: 
1. Node-APIs of the napi_threadsafe_function series are used. These APIs are equivalent to throwing tasks in the C++ thread and returning to the ArkTS thread to execute ArkTS methods. 
[Thread Safety Development Using Node-API](use-napi-thread-safety.md) 
2. Create the ArkTS running environment in the C++ thread.  
[Creating an ArkTS Runtime Environment Using Node-API](use-napi-ark-runtime.md)  

## Whether there is a napi_get_value_string_utf8 interface or capability that does not need to be copied?

- Specific question: The napi_get_value_string_utf8 of the current Node-API needs to be copied each time it is called. Is there any napi_get_value_string_utf8 interface or capability that does not need to be copied? 
- Q&A  
This function is not supported. A copy process is required for each napi_get_value_string_utf8.

Copy is necessary because it involves the string lifecycle. When GC is triggered, the ArkTS object may be moved in the VM, moved to another place, or directly reclaimed. If an address similar to char* is directly returned, the memory pointed to by the original address may change after the object is moved or reclaimed. 

## What are the precautions for using napi_env in multi-thread mode?

- Specific questions:  
What are the precautions for using napi_env in multi-thread mode? Is there any exception caused by napi_env switchover? Must be in the main thread? 

- Note:  
1. The napi_env and ArkTS threads are bound. The napi_env cannot be used across threads. Otherwise, stability problems may occur.
[Multi-thread restriction](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-process#%E5%A4%9A%E7%BA%BF%E7%A8%8B%E9%99%90%E5%88%B6)
2. When using env to call napi APIs, note that most napi APIs can be called only on the ArkTS thread where env is located. Otherwise, multi-thread security problems may occur.
For details, see the fourth point [multi-thread] [Multi-thread security issues occur when developers use napi_env or napi_value across threads when using napi APIs](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615).  
3. Do not cache napi env. Otherwise, multi-thread security problems and use-after-free problems may occur.  
For details, see [use-after-free] [Multi-thread security issues occur when developers use napi_env or napi_value across threads when using napi interfaces](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615).
4. [Why Does napi_env Disable Cache?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-73)

## What should I do if the napi_call_threadsafe_function execution sequence does not meet the expectation?

- Description:  
The napi_call_threadsafe_function execution sequence does not meet the expectation. 
The expected execution sequence is a -> b -> c. 
posttask(a);  
posttask(b);  
posttask(c);  
However, the actual execution sequence is b -> a -> c. 

- In this case, you can check the following items: 
1. Check whether the same napi_threadsafe_function is used. If different instances are used, the execution sequence may be inconsistent.  
Note: For the same napi_threadsafe_function, napi_call_threadsafe_function is sequence-preserving. A queue is maintained in the interface. If the interface is called first, the interface is executed first. 
2. Check whether the actual invoking sequence of napi_threadsafe_function is a -> b -> c.  


## What should I do if an error message "undefined" is displayed on the ArkTS side?
Specific questions:
What should I do when "undefined/not callable" or specific error message is reported for xxx after "import xxx from libxxx.so" is executed?
1. Check whether the module name in the .cpp file used in module registration is the same as that in the .so file name.
   If the module name is **entry**, the .so file name must be **libentry.so**, and the **nm_modname** field in **napi_module** must be **entry**. The module names must be of the same case.

2. Check whether the .so file is successfully loaded.
   Check the logs related to module loading during the application startup. Search for the keyword "dlopen" and check for error information. Generally, a loading failure is caused when the file to be loaded does not exist or is in a blocklist or the application does not have the required permission. In multi-thread scenarios (such as worker threads and taskpool), check whether **nm_modname** is the same as the module name. The module names must be of the same case.

3. Check whether the dependency .so files are successfully loaded.
   Check that all the dependency .so files are packaged into the application and the application has the permission to open them. Common causes for loading failures include insufficient permission and absence of the .so file.


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

## What should I do if the interface execution result is unexpected?

Problem description: The interface execution result is not as expected, and the log information "occur exception need return" is displayed.

Before the call is complete, some Node-API interfaces are checked for JavaScript (JS) exceptions in the VM. If an exception is detected, "occur exception need return" will be reported, with the line number of the code and the Node-API interface name.

You can solve this problem as follows:

- If the exception does not matter, clear the exception.
  You can directly use the Node-API napi_get_and_clear_last_exception to clear exceptions. "occur exception need return" is printed to clear the exception.

- Throw the exception to the ArkTS layer for capture.
  Throw the exception directly to the ArkTS layer without going through the native logic.

## What are the differences between the lifecycle of napi_value and napi_ref?

- napi_value is managed by HandleScope. Generally, you do not need to add HandleScope for napi_value (except for complete callback of uv_queue_work).

- **napi_ref** must be deleted manually.

## How do I locate the fault if the return value of a Node-API interface is not "napi_ok"?

After the Node-API is executed properly, an enumerated value of napi_ok is returned. If the return value of the Node-API is not napi_ok, see [Introduction to Status Codes Returned by Node-API](napi_status_introduction.md).

The common scenarios are as follows:

- Check the result of the input parameter null check, which is performed first before a Node-API interface is executed. The code is as follows:

  ```cpp
  CHECK_ENV: null check for env.
  CHECK_ARG: null check for other input parameters.
  ```

- Check the result of the input parameter type check, which is performed for certain Node-API interfaces. For example, **napi_get_value_double** is used to obtain a C double value from a JS number, and the type of the JS value passed in must be number. The parameter type check is as follows:

  ```cpp
  RETURN_STATUS_IF_FALSE(env, NativeValue->TypeOf() == Native_NUMBER, napi_number_expected);
  ```

- Check the return value, which contains the verification result of certain interfaces. For example, **napi_call_function** is used to execute a JS function. If an exception occurs in the JS function, Node-API returns **napi_pending_exception**.

  ```cpp
  // Internal implementation of the interface. The status value can be returned after verification.
  auto resultValue = engine->CallFunction(NativeRecv, NativeFunc, NativeArgv, argc);
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- Determine the status value returned, and analyze the situation in which the status value is returned.

## How does napi_wrap ensure that wrapped objects are destructed in the expected sequence?
Problem: In the scenario where `napi_wrap` is used to encapsulate two C++ objects into two JavaScript objects, one C++ object must be destructed before the other C++ object because the two C++ objects are dependent on each other. However, the timing of JavaScript garbage collection (GC) is uncertain. If C++ objects are directly destroyed in the `finalize_cb` callback of `napi_wrap`, the destructor sequence cannot meet the requirements. How Do I Ensure the Destructor Sequence of Two C++ Objects?

Reference solutions 
Mark the releasable state first. When both A and B are in the releasable state, the C++ object is released.  
Principle: The release logic of all dependent objects is processed in finalize_cb of the last destroyed ArkTS object. 
Implementation procedures:  
Mark cppObjA as to-be-destroyed (not released immediately) in finalize_cb of jsObjA. 
Mark cppObjB as to-be-destroyed (not released immediately) in finalize_cb of jsObjB. 
When jsObjA and jsObjB are to be destroyed, destroy cppObjA and cppObjB in sequence. 
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
        delete pair->objA; // Ensure that pair A is destroyed first.
        delete pair->objB; // Destroy pair B.
        delete pair; // Release the packaging structure.
    }
}

// finalize callback of jsObjB.
void FinalizeB(napi_env env, void* data, void* hint) {
    ObjectPair* pair = static_cast<ObjectPair*>(data);
    pair->objADestroyedB = true;
    if (pair->objADestroyedA && pair->objADestroyedB) {
        delete pair->objA; // Ensure that pair A is destroyed first.
        delete pair->objB; // Destroy pair B.
        delete pair; // Release the packaging structure.
    }
}
```
## What hsould I do if the napi_call_threadsafe_function callback task is not executed?

problem troubleshooting 
Cause 1: The return value of the `napi_call_threadsafe_function` function is not `napi_ok`. Check whether the return values of the functions related to `napi_call_threadsafe_function` are all `napi_ok`. If not, check the reason why the return values are not `napi_ok` by referring to [Introduction to the Status Codes Returned by Node-APIs](napi_status_introduction.md). 
Cause 2: The ArkTS thread where env is located is blocked. The callback of the `napi_call_threadsafe_function` function is executed on the ArkTS thread where env is located. If the ArkTS thread is blocked, the thread-safe function callback will not be executed. 
Cause 3: The thread security function is affected by the `uv_async_t` handle that is repeatedly initialized. As a result, the task is not executed. If a `uv_async_t` handle is re-initialized, all `uv_async_t` handles created during the first initialization and repeated initialization cannot be accessed by the UV. The thread-safe function is implemented based on the `uv_async_t` mechanism. In this special scenario, the thread-safe function becomes invalid. 

## How to use development tools to quickly develop Node-APIs using C/C++ code?

OpenHarmony provides various Node-API examples. You can quickly master the development process of the Node-API module by referring to the development guide and sample project.

You can use development tools such as [AKI](https://gitcode.com/openharmony-sig/aki) or [napi-generator](https://gitee.com/openharmony/napi_generator) to assist Node-API development, reducing learning difficulties and improving development efficiency.
