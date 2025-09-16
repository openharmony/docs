# FAQs About Stability
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## What can I do if there is a high probability that an app crashes during running?

- Problem: During Node-API development, there is a high probability that the application crashes during running, and the cppcrash stack is displayed. The top of the stack is the system library libark_jsruntime.so, and the first several frames of the crash stack also contain libace_napi.z.so, how to locate and solve the problem? 
There is a high probability that the problem recurs. The crash stack varies slightly. However, the top of the crash stack is libark_jsruntime.so or libace_napi.z.so of the system library.   
- The crash information is as follows: 
```sh
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0x00000136 probably caus
Fault thread info:
Tid:15894, Name:e.myapplication
#00 pc 002b8dd4 /system/lib/platformsdk/libark_jsruntime.so
#01 pc 0024d3e1 /system/lib/platformsdk/libark_jsruntime.so
#02 pc 0024d0d9 /system/lib/platformsdk/libark_jsruntime.so
#03 pc 002eac5d /system/lib/platformsdk/libark_jsruntime.so
#04 pc 00428d0f /system/lib/platformsdk/libark_jsruntime.so
```

- Locate 
If there is a high probability that the Node-API crashes, the crash stack tops the system library libark_jsruntime.so. Generally, the crash is caused by improper use of the Node-API.  
- The following fault locating methods can be used as a reference:  
1. Check whether there are multi-thread security issues (with a high probability).  
DevEco Studio provides a switch. After the switch is turned on, recompile, package, and run the code to check whether the crash stack complies with the description in the following document. If yes, multi-thread security issues exist when Node-API is used.  
[Common multi-thread security issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120) 
DevEco Studio switch:  
![Multi-thread switch of DevEco Studio](figures/en_us_image_20-25-06-40-15-09.png)  
2. The input parameter is invalid when the Node-API is used.  
- Generally, the .so file on the crash stack is shallow. The .so file calls a specific Node-API interface, for example, napi_call_function, and then the Node-API calls the .so file of libark_jsruntime, then, the system crashes in libark_jsruntime. 
The following is an example of the stack structure: 
```sh
#01 /system/lib/platformsdk/libark_jsruntime.so
#02 /system/lib/platformsdk/libark_jsruntime.so
#03 SO of /system/lib/platformsdk/libace_napi.z.so(napi_set_named_property+170) -- Node-API, which displays the interface that fails to be called.
#04 /data/storage/el1/bundle/libs/arm/libentry.so -- Your SO file
```
- If the problem is caused by input parameters, the position of the .so file on the crash stack is generally shallow (the .so file does not run to the position far away from the top of the stack, such as #10). However, you can also locate the fault based on this method. 
- Troubleshooting method reference: 
a. Check whether napi_value is not initialized and has not been assigned a value. If yes, napi_value is directly transferred to the interface as an invalid input parameter. 
b. Check whether the corresponding chapter is found in the error-prone API list. [Ark Runtime API](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615)

## How do I handle thread security issues when the ArkTS method is concurrently invoked in the thread pool?

- In the current scenario, there is a class method in ArkTS, and the napi_ref reference is created for the method. To concurrently call the ArkTS method in the C++ thread pool, the following problems occur: 
1. Can I Call ArkTS Class Methods Cached by napi_ref in the Thread Pool Created by C++? 
2. How Do I Ensure Thread Security When Calling Back to ArkTS? 

For problem 1:
The ArkTS task can be thrown back to the ArkTS thread only in the C++ thread. In this case, the ArkTS task is thrown instead of being called synchronously. 
Note that the ArkTS method can be executed only in the ArkTS thread. That is, the method can run only on the corresponding ArkTS thread. 

For problem 2:
As mentioned above, C++ threads throw tasks to ArkTS threads to execute ArkTS methods. For details about thread security, see [Using Node-APIs for Thread Security Development](use-napi-thread-safety.md). 
In addition, you can enable the Ark multi-thread detection (https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section75786272088) switch during development to block multi-thread security issues. 

## What should I do if the content of napi_value changes?

- Description: When a program is initialized, env and a method (napi_value) are saved. The method is checked when it is created. The result of napi_typeof is napi_function, which meets the expectation. After the program runs for a period of time, the method check fails when the saved env and method are used again. In this case, the napi_function is not used. The saved and used are in the same main thread. How to solve this problem? 

- Suggestions: 
1. Check whether napi_value is out of the scope and is still in use, causing the use-after-scope problem. 
Reference documents:  
[Ark Runtime API](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615) 
2. You are advised to use napi_ref instead of napi_value. 

## Is there a method to obtain the latest napi_env?

- Description: The Native layer needs to call the ArkTS method at a deep calling layer. The napi_env cannot be transferred layer by layer. If the napi_env is directly cached, the system will crash. 
```sh
#00 /system/lib/platformsdk/libark_jsruntime.so(panda::JSValueRef::IsFunction)
#01 /system/lib/platformsdk/libace_napi.z.so(napi_call_function)
#02 /data/storage/el1/bundle/libs/arm/libentry.so
...
```
- Reference solutions 
1. About saving napi_env: 
Node-API does not provide the capability of directly obtaining napi_env. It can only be transferred by invoking functions layer by layer. You are not advised to save napi_env due to the following reasons: 
1. If the user is not aware of the exit of napi_env, the use-after-free problem may occur. 
The napi_env and ArkTS threads are strongly bound. If the napi_env is used by other ArkTS threads, multi-thread security problems may occur. 
Reference documents: 
[Why Does napi_env Disable Cache?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-73) 

2. The key points of this problem are as follows: 
If you want to forcibly save the env, you must know whether the env exits. You can use the callback of napi_add_env_cleanup_hook to know whether the env exits. In addition, enable the multi-thread detection function during development to avoid multi-thread security issues.
For details, see [Common Multi-Thread Security Issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120).  

3. The crash may occur when napi_call_function is called. The input parameter func is incorrect, that is, the input parameter is invalid. You can check whether napi_value is cached. The possible cause is that napi_value exceeds the scope of napi_handle_scope after napi_value is cached. 
If similar logic exists, napi_ref needs to be used for storage. napi_ref can be used to extend the lifecycle. 

- Reference documents: 
[napi_create_reference, napi_delete_reference](use-napi-life-cycle.md)

[Ark Runtime API](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615)   

## What should I do if an error is reported during napi_add_env_cleanup_hook invoking?

- Specific problem: What should I do if an error is reported when napi_add_env_cleanup_hook/napi_remove_env_cleanup_hook is called? 
An error is reported when `napi_add_env_cleanup_hook` and `napi_remove_env_cleanup_hook` are called. The common causes and feature logs are as follows, which are caused by improper API usage. 
1. The preceding two interfaces are used outside the ArkTS thread where `env` is located. As a result, the multi-thread security problem occurs. Feature error log `current napi interface cannot run in multi-thread`. 
2. When `napi_add_env_cleanup_hook` is called, the same `args` is repeatedly used to register different callback functions. As a result, the subsequent registration fails. The third input parameter `args` of the interface is used as the `key` value of the internal `map` of the interface. If the callback of the same `args` is registered repeatedly, the subsequent registration will fail. Only the first registration will be successful. If the registration fails, subsequent service functions may be abnormal or the system may break down. Feature error log `AddCleanupHook Failed`. 
3. When `napi_remove_env_cleanup_hook` is called, the system attempts to use an `args` that does not exist or has been deleted to delete the callback function. The interface fails to be called, and the `RemoveCleanupHook Failed` error log is generated. 

Example:

```c++
void AddEnvCleanupHook(napi_env env)
{
    napi_add_env_cleanup_hook(env, [](void* args) -> void {
        // Callback of the cleanup function.
    }, env); // env is common data. Even if it is not registered repeatedly, it may be registered in other places in advance. As a result, the registration fails.
}

static napi_value Test(napi_env env, napi_callback_info info)
{
    //First registration
    AddEnvCleanupHook(env);
    //Repeated registration for the second time
    AddEnvCleanupHook(env);
    return nullptr;
}
```

- Suggestion
1. For multi-thread security issues, ensure that the thread that calls the interface is on the ArkTS thread where `env` is located.
2. If the registration fails, the user needs to specify the function to be registered. Ensure that the value of `key` (the third input parameter of `napi_add_env_cleanup_hook`) is unique.
3. If the deletion fails, ensure that `args` has been registered and is not deleted.

Related reference documents:
[Working with Cleanup Hooks Using Node-API](use-napi-about-cleanuphook.md)
[Ark Runtime API](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615)
