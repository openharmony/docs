# Napi子系统Changelog

## cl.Napi.1 napi_call_threadsafe_function_with_priority和napi_call_threadsafe_funcyion的使用规格一致

**访问级别**

公开接口

**变更原因**

通过napi_call_threadsafe_function_with_priority接口投递任务，在线程安全函数释放时，若还有未执行的任务，则这些任务不再执行。

**变更影响**

此变更涉及应用适配。

变更前：调用该接口后，释放线程安全函数，不会执行未执行的任务，直接释放。

变更后：调用该接口后，释放线程安全函数，会执行完尚未执行的任务，执行完以后再释放。


**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.1.0.50开始。

**变更的接口/组件**

napi_call_threadsafe_function_with_priority

**适配指导**

修改后napi_call_threadsafe_function_with_priority和napi_call_threadsafe_funcyion的使用规格一致，开发者需要确认是否受到影响