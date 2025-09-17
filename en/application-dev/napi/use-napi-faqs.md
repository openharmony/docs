# Node-API FAQs
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Stability 
1. [There is a high probability that the app crashes during running, and the cppcrash stack is displayed. The top of the stack is the system library libark_jsruntime.so, and the first several frames of the crash stack also contain libace_napi.z.so. How to locate and solve the problem?](napi-faq-about-stability.md) 
2. [How Do I Handle Thread Security Issues When ArkTS Methods Are Concurrently Invoked in the C++ Thread Pool?](napi-faq-about-stability.md) 
3. [napi_value is not expected. The type of napi_value is napi_function when napi_value is created. After napi_value is saved for a period of time, the type of napi_value changes.](napi-faq-about-stability.md) 
4. [Check whether the method for obtaining the latest napi_env exists.](napi-faq-about-stability.md) 
5. [What can I do if an error is reported when napi_add_env_cleanup_hook/napi_remove_env_cleanup_hook is called?](napi-faq-about-stability.md) 
## Memory Leak 
1. [napi_create_reference can create a reference to a JavaScript object to keep the JavaScript object from being released. Generally, napi_delete_reference needs to be called to release the reference. However, if napi_delete_reference is not called, the JavaScript object may be leaked. Is there any mechanism to check whether there is a leaked napi_reference?](napi-faq-about-memory-leak.md) 
2. [How Do I Locate and Solve the Memory Leakage Problem During Node-API Development?](napi-faq-about-memory-leak.md) 
3. [For details about parameter leakage, see napi_open_handle_scope and napi_close_handle_scope](use-napi-life-cycle.md).  
4. [What should I do if the napi_threadsafe_function memory leaks?](napi-faq-about-memory-leak.md) 
## Common Basic Function Problems
1. [Failed to load the module. An error is reported when Error message: is not callable NativeModule is called.](napi-faq-about-common-basic.md) 
2. [Are there any recommended methods for thread communication with order preservation?](napi-faq-about-common-basic.md) 
3. [Is there a convenient way for NAPI to call back ArkTS?](napi-faq-about-common-basic.md) 
4. [How Do I Call a Function Transferred from ArkTS in C++?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-26) 
5. [How to securely and efficiently transfer multiple return values (including structured data and pointer information) to the ArkTS runtime environment while complying with the single return value constraint of Node-API, and how to ensure correct data type mapping and memory management security?](napi-faq-about-common-basic.md) 
6. [Node-API Calling Third-Party SO Files](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-dynamic-link-library) 
7. [Error code description of the napi_get_uv_event_loop interface](napi-faq-about-common-basic.md) 
8. [In Node-API, must a function be transferred to the native layer when the native layer calls the object method at the ArkTS layer?](napi-faq-about-common-basic.md) 
9. [Can the thread created using pthread or std::thread in C++ call the ArkTS method and obtain the result?](napi-faq-about-common-basic.md) 
10. [Whether the napi_get_value_string_utf8 API of NAPI needs to copy data each time it is called, and whether there is a nocopy napi_get_value_string_utf8 API or capability](napi-faq-about-common-basic.md) 
11. [What are the precautions for using napi_env in multi-thread mode? Are there any exceptions caused by napi_env switchover? Must napi_env be used in the main thread?](napi-faq-about-common-basic.md) 
12. [What is the execution sequence of napi_call_threadsafe_function?](napi-faq-about-common-basic.md) 
13. [After xxx is imported from libxxx.so on the ArkTS side, an error message "undefined/not callable" or a specific error message is displayed when xxx is used.](napi-faq-about-common-basic.md) 
14. [The interface execution result is not as expected. The log shows "occur exception need return."](napi-faq-about-common-basic.md) 
15. [What are the differences between the lifecycles of napi_value and napi_ref?](napi-faq-about-common-basic.md) 
16. [How Do I Locate the Fault When the Return Value of the Node-API Interface Is Not napi_ok?](napi-faq-about-common-basic.md) 
17. [How does napi_wrap ensure that wrapped objects are destructed in the expected sequence?](napi-faq-about-common-basic.md) 
18. [The napi_call_threadsafe_function callback task is not executed.](napi-faq-about-common-basic.md)
