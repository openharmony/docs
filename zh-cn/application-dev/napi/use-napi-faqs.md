# Node-API常见问题
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 稳定性  
1. [应用运行过程中出现高概率闪退，出现cppcrash栈，栈顶为系统库libark_jsruntime.so，崩溃栈前几帧也有libace_napi.z.so，怎么进行定位解决](napi-faq-about-stability.md#应用运行过程中出现高概率闪退怎么进行定位解决)  
2. [c++线程池中并发调用ArkTS方法（c++多线程调用ArkTS方法），如何处理线程安全问题？](napi-faq-about-stability.md#线程池中并发调用arkts方法如何处理线程安全问题)  
3. [napi_value非预期，napi_value创建时类型是napi_function，保存一段时间后napi_value类型发生变化](napi-faq-about-stability.md#napi_value内容产生变化)  
4. [是否存在获取最新napi_env的方法？](napi-faq-about-stability.md#是否存在获取最新napi_env的方法)  
5. [napi_add_env_cleanup_hook/napi_remove_env_cleanup_hook调用报错，该如何处理？](napi-faq-about-stability.md#napi_add_env_cleanup_hook调用报错该如何处理)  
## 内存泄漏  
1. [napi_create_reference可以创建对js对象的引用，保持js对象不释放，正常来说使用完需要使用napi_delete_reference进行释放，但怕漏delete导致js对象内存泄漏，当前是否有机制来检查/测试是否有泄漏的napi_reference？](napi-faq-about-memory-leak.md#当前是否有机制来检查是否有泄漏的napi_ref)  
2. [Node-API开发过程中，遇见内存泄漏问题，要怎么定位解决？](napi-faq-about-memory-leak.md#napi开发过程中遇见内存泄漏问题要怎么定位解决)  
3. [参数泄漏问题参考napi_open_handle_scope、napi_close_handle_scope](use-napi-life-cycle.md)   
4. [napi_threadsafe_function内存泄漏，应该如何处理？](napi-faq-about-memory-leak.md#napi_threadsafe_function内存泄漏应该如何处理)  
## 常见基本功能问题
1. [模块加载失败，Error message: is not callable NativeModule调用报错？](napi-faq-about-common-basic.md)  
2. [是否有保序的线程通信推荐写法？](napi-faq-about-common-basic.md#在大量需要调用arkts方法进行通信的场景中如何保证异步任务的有序性)  
3. [是否存在便捷的NAPI回调ArkTS的方式？](napi-faq-about-common-basic.md#是否存在便捷的回调arkts的方式)  
4. [如何在C++调用从ArkTS传递过来的function？](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs/faqs-ndk-26)  
5. [如何在遵循 Node-API 单一返回值约束的前提下，安全、高效地将多个返回值（包括结构化数据和指针信息）传递给 ArkTS 运行时环境，并确保数据类型的正确映射与内存管理的安全性？](napi-faq-about-common-basic.md#如何确保数据类型的正确映射与内存管理的安全性)  
6. [Node-API调用三方so](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-dynamic-link-library)  
7. [napi_get_uv_event_loop接口错误码说明](napi-faq-about-common-basic.md#napi_get_uv_event_loop接口错误码说明)  
8. [Node-API中，native层调用ArkTS层对象方法，必须传入一个function给native层吗？](napi-faq-about-common-basic.md#native层调用arkts层对象方法必须传入一个function给native层吗)  
9. [在c++通过pthread或std::thread创建的线程，是否能调用ArkTS的方法并获取到结果？](napi-faq-about-common-basic.md#是否能调用arkts的方法并获取到结果)  
10. [当前napi的napi_get_value_string_utf8每次调用的时候都要进行拷贝，是否有nocopy、不拷贝的napi_get_value_string_utf8接口或者能力？ ](napi-faq-about-common-basic.md#是否有不拷贝的napi_get_value_string_utf8接口或者能力)  
11. [多线程下napi_env的使用注意事项是什么？是否存在napi_env切换导致的异常问题？是否必须在主线程?](napi-faq-about-common-basic.md#多线程下napi_env的使用注意事项)  
12. [napi_call_threadsafe_function执行顺序是怎样的？](napi-faq-about-common-basic.md#napi_call_threadsafe_function执行顺序不符合预期)  
13. [ArkTS侧import xxx from libxxx.so后，使用xxx报错显示undefined/not callable或明确的Error message](napi-faq-about-common-basic.md#arkts侧报错显示undefined)  
14. [接口执行结果非预期，日志显示occur exception need return](napi-faq-about-common-basic.md#接口执行结果非预期)  
15. [napi_value和napi_ref的生命周期有何区别](napi-faq-about-common-basic.md#napi_value和napi_ref的生命周期有何区别)  
16. [Node-API接口返回值不是napi_ok时，如何排查定位](napi-faq-about-common-basic.md#node-api接口返回值不是napi_ok时如何排查定位)  
17. [napi_wrap如何保证被wrap的对象按期望顺序析构？](napi-faq-about-common-basic.md#napi_wrap如何保证被wrap的对象按期望顺序析构)  
18. [napi_call_threadsafe_function回调任务不执行](napi-faq-about-common-basic.md#napi_call_threadsafe_function回调任务不执行)
