# FAQs About Stability
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## How do I troubleshoot the issue that an application often crashes during running

- Question: During Node-API development, an application often crashes, and the cppcrash stack is displayed. The stack top is the system library **libark_jsruntime.so**, and the first few frames of the crash stack contain **libace_napi.z.so**. How do I troubleshoot this issue? 
The issue occurs frequently. The crash stack varies slightly each time, but the crash stack top is **libark_jsruntime.so** or **libace_napi.z.so** of the system library.   
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

- Answer: 
If the application frequently crashes when the Node-API is used, and the crash stack top is in the system **library libark_jsruntime.so**, the issue may be caused by improper use of the Node-API.  
- You can refer to the following troubleshooting methods:  
1. Check whether there are multi-thread safety issues, which are likely to occur.  
DevEco Studio provides a switch for checking multi-thread safety issues. After the switch is enabled, recompile, package, and run the code to check whether the crash stack complies with the description in the following topic. If yes, multi-thread safety problems occur when Node-API is used.  
  
Multi Thread Check in DevEco Studio:  
![Multi-thread check switch in DevEco Studio](figures/en_us_image_20-25-06-40-15-09.png)  
2. Check whether the input parameter of the Node-API is invalid.  
- In this case, the .so file appears higher on the crash stack. The .so file calls a specific Node-API, for example, **napi_call_function**. Then, the Node-API calls **libark_jsruntime .so**, and the crash occurs in **libark_jsruntime**. 
The following shows an example stack structure. 
```sh
#01 /system/lib/platformsdk/libark_jsruntime.so
#02 /system/lib/platformsdk/libark_jsruntime.so
#03 /system/lib/platformsdk/libace_napi.z.so(napi_set_named_property+170) -- Node-API .so, which displays the failed API call.
#04 /data/storage/el1/bundle/libs/arm/libentry.so -- Your .so file.
```
- If the input parameter is incorrect, the .so file usually appears high on the crash stack (it will not be far away from the stack top, such as #10). However, you can also refer to the following troubleshooting methods. 
- Troubleshooting methods: 
a. Check whether the **napi_value** is not initialized (the value is not assigned successfully, but is passed to the API as an invalid input parameter). 
b. Check whether the error-prone API can be found by referring to the following topic.  

## How to handle thread safety issues when the ArkTS method is concurrently called in the thread pool

- In an ArkTS class method, **napi_ref** is created. To concurrently call the ArkTS method in the C++ thread pool, I have the following questions: 
1. Can the ArkTS class method cached by **napi_ref** be called in the thread pool created by C++? 
2. How to ensure thread safety when ArkTS is called back? 

Answer to question 1:
An ArkTS task can be thrown back to the ArkTS thread only in the C++ thread. In this case, the task is not called synchronously, but is thrown. 
Note that the ArkTS method can be executed only on the ArkTS thread. 

Answer to question 2:
As mentioned above, C++ threads throw tasks to ArkTS threads to execute ArkTS methods. For details about thread safety, see [Thread Safety Development Using Node-API](use-napi-thread-safety.md). 
  

## What should I do if the content of napi_value changes

- Question: When a program is initialized, **env** and a method (**napi_value**) are saved. The method is checked when it is created. The result of **napi_typeof** is **napi_function**, which meets the expectation. After the program runs for a period of time, the saved **env** and method fail to be checked, and the method is not a **napi_function**. The **env** and method are saved and used in the same main thread. How to solve this problem? 

- Answer: 
1. Check whether **napi_value** is used out of the scope. 
References:  
  
2. You are advised to use **napi_ref** instead of **napi_value**. 

## Is there a method to obtain the latest napi_env

- Question: The native layer needs to call an ArkTS method at a deeper layer and cannot pass **napi_env** layer by layer. If **napi_env** is directly cached, the system crashes. What should I do? 
```sh
#00 /system/lib/platformsdk/libark_jsruntime.so(panda::JSValueRef::IsFunction)
#01 /system/lib/platformsdk/libace_napi.z.so(napi_call_function)
#02 /data/storage/el1/bundle/libs/arm/libentry.so
...
```
- Answer: 
1.   
To save **napi_env**, you can only pass it by calling functions layer by layer because Node-API does not provide the capability of directly obtaining **napi_env**. You are not advised to save **napi_env** due to the following reasons: 
1. If the **napi_env**'s exit is not perceived, the **use-after-free** issue may occur. 
2. **napi_env** is strongly bound to the ArkTS thread. If **napi_env** is used by other ArkTS threads, multi-thread safety issues may occur. 
References: 
[Why cannot napi_env be cached?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-73) 

2. The key to this issue is as follows: 
To forcibly save the **env**, you can use the callback of **napi_add_env_cleanup_hook** to check whether the **env** exits. In addition, enable **Multi Thread Check** during development to avoid multi-thread safety issues.
   

3. The crash may occur because the input parameter **func** is invalid when **napi_call_function** is called. You can check whether **napi_value** is cached. The possible cause is that **napi_value** exceeds the **napi_handle_scope** after being cached. 
To use similar logic, use **napi_ref** for storage can prolong the lifecycle. 

- References: 
[napi_create_reference, napi_delete_reference](use-napi-life-cycle.md)

    

## What should I do if napi_add_env_cleanup_hook is called incorrectly

- Question: What should I do if an error is reported when **napi_add_env_cleanup_hook** or **napi_remove_env_cleanup_hook** is called? 
When an error is reported when **napi_add_env_cleanup_hook** or **napi_remove_env_cleanup_hook** is called, the possible causes and logs are as follows: 
1. The two APIs are used outside the ArkTS thread to which **env** belongs, causing multi-thread safety issues. The error log "current napi interface cannot run in multi-thread" is reported. 
2. When **napi_add_env_cleanup_hook** is called, the same **args** is repeatedly used to register different callbacks. As a result, the registration fails. The third input parameter **args** of the API is used as the **key** value of the internal **map** of the API. When the callback of the same **args** is registered repeatedly, only the first registration is successful. If the registration fails, subsequent service functionalities may be abnormal or crash. The error log "AddCleanupHook Failed" is reported. 
3. When **napi_remove_env_cleanup_hook** is called, the callback is deleted using **args** that does not exist or has been deleted. The API fails to be called, and the error message "RemoveCleanupHook Failed" is displayed. 

Example:

```c++
void AddEnvCleanupHook(napi_env env)
{
    napi_add_env_cleanup_hook(env, [](void* args) -> void {
        // Callback of the cleanup function.
    }, env); // env is a common data. Even if it is not repeatedly registered here, it may be registered in advance in other places. As a result, the registration fails.
}

static napi_value Test(napi_env env, napi_callback_info info)
{
    // First registration.
    AddEnvCleanupHook(env);
    // Second registration.
    AddEnvCleanupHook(env);
    return nullptr;
}
```

- Answer:
1. To ensure multi-thread safety, ensure that the API is called by the ArkTS thread to which **env** belongs.
2. If the registration fails, you need to specify the function to be registered and ensure that the **key** value (the third input parameter of **napi_add_env_cleanup_hook**) is unique.
3. If the deletion fails, ensure that **args** has been registered and not deleted.

References:
[Working with Cleanup Hooks Using Node-API](use-napi-about-cleanuphook.md)
 
