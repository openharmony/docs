# JSVM-API常见问题
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->

## 定位方法

程序崩溃类问题：通过C++崩溃时调用栈查询FAQ的方式定位代码问题

程序执行结果不符合预期类问题：需要通过JSVM-API调用返回值定位问题位置，再通过函数名查询FAQ

## 程序崩溃类

1. Q：在`OH_JSVM_RunScript`或`OH_JSVM_CallFunction`时crash，调用栈顶层为`SetReturnValue`

   ```txt
   #00 pc 0000000000c68ef0 /system/lib64/ndk/libjsvm.so(v8impl::(anonymous namespace)::FunctionCallbackWrapper::SetReturnValue(JSVM_Value__*)+16)
   #01 pc 0000000000c5ad30 /system/lib64/ndk/libjsvm.so(v8impl::(anonymous namespace)::FunctionCallbackWrapper::Invoke(v8::FunctionCallbackInfo<v8::Value> const&)+332)
   #02 pc 00000000014a9e58 /system/lib64/ndk/libjsvm.so
   #03 pc 00000000014a95d4 /system/lib64/ndk/libjsvm.so(v8::internal::Builtin_HandleApiCall(int, unsigned long*, v8::internal::Isolate*)+176)
   #04 pc 0000000000f7dab4 /system/lib64/ndk/libjsvm.so(Builtins_CEntry_Return1_ArgvOnStack_BuiltinExit+84)
   #05 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #06 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #07 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #08 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #09 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #10 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #11 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #12 pc 0000000000eece40 /system/lib64/ndk/libjsvm.so(Builtins_InterpreterEntryTrampoline+288)
   #13 pc 0000000000fe09f4 /system/lib64/ndk/libjsvm.so(Builtins_PromiseFulfillReactionJob+52)
   #14 pc 0000000000f155c0 /system/lib64/ndk/libjsvm.so(Builtins_RunMicrotasks+672)
   #15 pc 0000000000eeab54 /system/lib64/ndk/libjsvm.so(Builtins_JSRunMicrotasksEntry+148)
   #16 pc 00000000015bed78 /system/lib64/ndk/libjsvm.so(v8::internal::(anonymous namespace)::Invoke(v8::internal::Isolate*, v8::internal::(anonymous namespace)::InvokeParams const&)+2520)
   #17 pc 00000000015bf50c /system/lib64/ndk/libjsvm.so(v8::internal::(anonymous namespace)::InvokeWithTryCatch(v8::internal::Isolate*, v8::internal::(anonymous namespace)::InvokeParams const&)+104)
   #18 pc 00000000015bf730 /system/lib64/ndk/libjsvm.so(v8::internal::Execution::TryRunMicrotasks(v8::internal::Isolate*, v8::internal::MicrotaskQueue*)+80)
   #19 pc 00000000015ecf4c /system/lib64/ndk/libjsvm.so(v8::internal::MicrotaskQueue::RunMicrotasks(v8::internal::Isolate*)+312)
   #20 pc 00000000015ecd9c /system/lib64/ndk/libjsvm.so(v8::internal::MicrotaskQueue::PerformCheckpointInternal(v8::Isolate*)+52)
   #21 pc 00000000015deaa0 /system/lib64/ndk/libjsvm.so(v8::internal::Isolate::FireCallCompletedCallbackInternal(v8::internal::MicrotaskQueue*)+280)
   #22 pc 00000000014334e8 /system/lib64/ndk/libjsvm.so(v8::CallDepthScope<true>::~CallDepthScope()+248)
   #23 pc 00000000014330a4 /system/lib64/ndk/libjsvm.so(v8::Script::Run(v8::Local<v8::Context>, v8::Local<v8::Data>)+884)
   #24 pc 0000000000c5c2ac /system/lib64/ndk/libjsvm.so(OH_JSVM_RunScript+272)
   ```

   A：`SetReturnValue`用于设置js函数的返回值，在js完成注入的native函数调用后触发。需检查native函数的返回值是否正确，如返回值（`JSVM_Value`）是否未初始化就直接返回。

2. Q：js执行虚拟机初始化注入的native函数时程序崩溃

   A：检查`JSVM_CallbackStruct`是否为栈上变量。如果跨函数使用，需确保`JSVM_CallbackStruct`的生命周期长于`JSVM_Env`的生命周期。

   ```c++
   func {
      // ...
       JSVM_CallbackStruct param[] = {
           {.data = nullptr, .callback = ConsoleInfo},
           {.data = nullptr, .callback = Add},
       };
       JSVM_PropertyDescriptor descriptor[] = {
           {"consoleinfo", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
           {"add", NULL, &param[1], NULL, NULL, NULL, JSVM_DEFAULT},
       };
       // create env, register native method, and open env scope
       JSVM_Env env;
       OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
      // ...
       OH_JSVM_DestroyEnv(env);
      // ...
   }
   ```

   在上述示例代码中，JS引擎实例在函数结束前被关闭，因此可以直接使用栈上的`param`。

3. Q：`OH_JSVM_ReferenceRef`、`OH_JSVM_ReferenceUnRef`、`OH_JSVM_CreateReference`、`OH_JSVM_DeleteReference`时程序崩溃

   A：检查是否同时有多个线程持有和释放`JSVM_Ref`，见[多线程共享引擎实例](jsvm-guidelines.md#多线程共享引擎实例)

4. Q：在虚拟机引擎实例中创建JS类型实例崩溃（如`OH_JSVM_CreateDouble`），调用栈如下

   ```txt
   #00 pc 0000000001d209e4/system/lib64/ndk/libjsvm.so(v8::base::0S::Abort()+28)
   #01 pc 0000000001408480/system/lib64/ndk/libjsvm.so(v8::Utils::ReportApiFailure(char const*,char const*)+124)
   #02 pc 00000000015c99b8/system/lib64/ndk/libjsvm.so(v8::internal::HandleScope::Extend(v8::internal::Isolate*)+200)
   ```

   A：检查HandleScope的使用是否正确，参考[生命周期管理](jsvm-guidelines.md#生命周期管理)

5. Q：调用JSVM-API时出现 `JSVM Fatal Error Message:(openHandleScopes)==(openHandleScopesBefore)` 错误
   
   A：调用JSVM-API时未遵循其使用规范正确管理HandleScopes生命周期，导致HandleScopes层数发生变化，调用结束后无法通过JSVM系统层检查，则返回该报错。修改请参考[JSVM-API使用规范](jsvm-guidelines.md)，优先排查注入回调函数中的JSVM-API调用点。

6. Q：在调用JSVM-API时出现如下两种报错：
   ```txt
   #00 pc 00000000068f670/system/lib64/libv8_shared.so(v8::internal::PagedSpaceBase::RelinkFreeListCategories(v8::internal::PageMetadata*)+72)
   #01 pc 00000000068f670/system/lib64/libv8_shared.so(v8::internal::PagedSpaceBase::RelinkFreeListCategories(v8::internal::PageMetadata*)+80)
   #02 pc 0000000006608bc/system/lib64/libv8_shared.so(v8::internal::MarkCompactCollector::StartSweepSpace(v8::internal::PageSpace*)+132)
   #03 pc 000000000649de8/system/lib64/libv8_shared.so(v8::internal::MarkCompactCollector::Sweep()+576)
   #04 pc 000000000647344/system/lib64/libv8_shared.so(v8::internal::MarkCompactCollector::CollectGarbage()+212)
   #05 pc 00000000062bc1c/system/lib64/libv8_shared.so(v8::internal::Heap::MarkCompact()+396)
   #06 pc 00000000062b530/system/lib64/libv8_shared.so(v8::internal::Heap::PerformGarbageCollection(v8::internal::GarbageCollector,v8::internal::GarbageCollectionReason,char const*)+844)
   #07 pc 00000000063ba1c/system/lib64/libv8_shared.so(v8::internal::Heap::CollectGarbage(v8::internal::AllocationSpace,v8::internal::GarbageCollectionReason,v8::GCCCallbackFlags)::$_3::operator()() const+1208)
   ```

   ```txt
   #00 pc 0000000003b902c/system/lib64/libv8_shared.so(Builtins_JumpIfToBooleanFalseHandler+44)
   #01 pc 00000000022765c/system/lib64/libv8_shared.so(Builtins_InterpreterEntryTrampoline+284)
   #02 pc 00000000022765c/system/lib64/libv8_shared.so(Builtins_InterpreterEntryTrampoline+284)
   #03 pc 000000000224ff0/system/lib64/libv8_shared.so(Builtins_JSEntryTrampoline+176)
   #04 pc 000000000224c38/system/lib64/libv8_shared.so(Builtins_JSEntry+184)
   #05 pc 00000000059775c/system/lib64/libv8_shared.so(v8::internal::(anonymous namespace)::Invoke(v8::iternal::Isolate*,v8::internal::(anonymous namespace)::InvokeParams const&)+792)
   #06 pc 00000000059740c/system/lib64/libv8_shared.so(v8::internal::Execution::Call(v8::internal::isolate*,v8::internal::Handle<v8::internal::Object>,v8::internal::Handle<v8::internal::Object>,int,v8::internal::Handle<v8::internal::Object>*)+120)
   #07 pc 0000000008269a8/system/lib64/libv8_shared.so
   ```

   A：这两种报错可能指向同一问题，即应用侧执行[OH_JSVM_DestroyEnv()](../reference/common/capi-jsvm-h.md#oh_jsvm_destroyenv)(释放JSVM环境)后，仍在执行业务逻辑，尝试调用JSVM-API，触发报错。该报错可能由三种情况产生：

      a) 回调函数中含有对JSVM-API的调用，在被触发时应用侧已经执行完OH_JSVM_DestroyEnv()，此时直接在回调函数内尝试调用JSVM-API，则可能会导致该错误。开发者应当保证所有JSVM-C-API在同一个js线程上调用，并在此线程上为每个JSVM实例添加对应标记(thread_local_flag)，在执行OH_JSVM_DestroyEnv()后将对应thread_local_flag置为true。回调函数中调用JSVM-API时，应当先判断当前是否在上述js线程上，若是，则直接根据thread_local_flag判断是否能够调用API，若不是，则把该任务抛到上述js线程上再进行判断和执行。

      b) 在跨线程调用场景中，可能出现在当前线程已经执行完OH_JSVM_DestroyEnv()后，其他线程仍在尝试调用JSVM-API的情况，此时也可能会导致该错误。

      c) 若使用任务队列来进行js任务执行，出现了先抛出destroy env的任务，后抛出普通js任务的情况，此时也可能导致该报错。针对这个情况，可以参考a情况做法，为JSVM实例添加thread_local_flag，若任务取出时thread_local_flag为true，则队列中剩余的任务需要全部跳过。
      
   如需获取更详细信息，请参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)

## JSVM-API执行失败类

1. Q：`OH_JSVM_GetCbInfo`无法获取JS函数参数

   A：检查函数传递的参数是否正确，见[获取JS传入参数及其数量](jsvm-guidelines.md#获取js传入参数及其数量)

2. Q：`OH_JSVM_CreateFunction`等函数调用失败，返回值为`JSVM_PENDING_EXCEPTION`

   A：`JSVM_PENDING_EXCEPTION`表明当前虚拟机环境中存在未处理的异常，可能是由于本次调用产生的`JS`异常，也可能是之前调用产生的未被清理的异常。可以通过在函数调用前插入`OH_JSVM_GetAndClearLastException`排查之前是否有未清除的异常。如果为之前的未清理异常，检查是否有JSVM接口调用未处理异常返回值；如果是本次产生的异常，需清理异常，避免影响后续的函数调用。获取并清理异常的函数为`OH_JSVM_GetAndClearLastException`

3. Q：JS执行时无法找到`OH_JSVM_DefineClass`定义的类

   A：检查是否将定义的类绑定到上下文中，见[上下文绑定对象](jsvm-guidelines.md#上下文绑定对象)