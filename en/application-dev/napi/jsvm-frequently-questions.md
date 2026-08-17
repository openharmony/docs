# JSVM-API FAQs

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2b8002975a0c421d94edbe70b3817da05adefb9a translatedAt=2026-08-12T06:26:10.234Z pushedAt=2026-08-12T08:51:13.346Z -->

## Fault Location

App crash issues: Locate the code issue by checking the call stack at the time of the C++ crash against the FAQs.

Unexpected execution result issues: Locate the issue by checking the JSVM-API return value, and then search the FAQs by function name.

## Application Crash Issues

1. Q: The app crashes when `OH_JSVM_RunScript` or `OH_JSVM_CallFunction` is called, and the top of the call stack is `SetReturnValue`.

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

   A: **SetReturnValue** is used to set the return value of a JS function and is triggered after the native function injected by JS is called. Check whether the return value of the native function is correct. For example, check whether the return value (of the **JSVM_Value** type) is returned without initialization.

2. Q: The app crashes when the JS engine executes the native function injected during initialization.

   A: Check whether **JSVM_CallbackStruct** is a variable in the stack. When **JSVM_CallbackStruct** is used across functions, the lifecycle of **JSVM_CallbackStruct** must be greater than that of **JSVM_Env**.

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
       // Create env, register a native method, and open an env scope.
       JSVM_Env env;
       OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
      // ...
       OH_JSVM_DestroyEnv(env);
      // ...
   }
   ```

   In the previous example, the JSVM instance is closed before the function ends. Therefore, the **JSVM_CallbackStruct param** in the stack can be used.

3. Q: The app crashes when `OH_JSVM_ReferenceRef`, `OH_JSVM_ReferenceUnRef`, `OH_JSVM_CreateReference`, or `OH_JSVM_DeleteReference` is called.

   A: Check whether multiple threads are holding and releasing `JSVM_Ref` at the same time. For details, see [JSVM Instance Shared by Multiple Threads](jsvm-guidelines.md#jsvm-instance-shared-by-multiple-threads).

4. Q: The app crashes when a JS data type instance is created (for example, `OH_JSVM_CreateDouble`) in a JSVM instance. The call stack is as follows:

   ```txt
   #00 pc 0000000001d209e4/system/lib64/ndk/libjsvm.so(v8::base::0S::Abort()+28)
   #01 pc 0000000001408480/system/lib64/ndk/libjsvm.so(v8::Utils::ReportApiFailure(char const*,char const*)+124)
   #02 pc 00000000015c99b8/system/lib64/ndk/libjsvm.so(v8::internal::HandleScope::Extend(v8::internal::Isolate*)+200)
   ```

   A: Check whether HandleScope is correctly used. For details, see [Lifecycle Management](jsvm-guidelines.md#lifecycle-management).

5. Q: The error `JSVM Fatal Error Message:(openHandleScopes)==(openHandleScopesBefore)` occurs when a JSVM-API is called.

   A: This error occurs when the HandleScopes lifecycle is not properly managed according to the JSVM-API usage specifications, causing the HandleScopes level to change and failing the JSVM system-level check after the call completes. To fix this issue, see [JSVM-API Development Specifications](jsvm-guidelines.md). Prioritize checking the JSVM-API call points in the injected callback functions.

6. Q: The following two errors occur when a JSVM-API is called:

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
   #05 pc 00000000059775c/system/lib64/libv8_shared.so(v8::internal::(anonymous namespace)::Invoke(v8::internal::Isolate*,v8::internal::(anonymous namespace)::InvokeParams const&)+792)
   #06 pc 00000000059740c/system/lib64/libv8_shared.so(v8::internal::Execution::Call(v8::internal::isolate*,v8::internal::Handle<v8::internal::Object>,v8::internal::Handle<v8::internal::Object>,int,v8::internal::Handle<v8::internal::Object>*)+120)
   #07 pc 0000000008269a8/system/lib64/libv8_shared.so
   ```

   A: These two errors may point to the same issue: after [OH_JSVM_DestroyEnv()](../reference/common/capi-jsvm-h.md#oh_jsvm_destroyenv) (which releases the JSVM environment) is executed on the app side, business logic is still being executed and attempts to call JSVM-API, triggering the error. This error may occur in the following three scenarios:

      a) A callback function contains a call to JSVM-API, but OH_JSVM_DestroyEnv() has already been executed on the app side when the callback is triggered. In this case, attempting to call JSVM-API directly within the callback function may cause this error. You must ensure that all JSVM-C-API calls are made on the same JS thread, and add a corresponding flag (thread_local_flag) for each JSVM instance on this thread. After OH_JSVM_DestroyEnv() is executed, set the corresponding thread_local_flag to true. When calling JSVM-API in a callback function, first check whether the current thread is the JS thread mentioned above. If it is, determine whether the API can be called based on the thread_local_flag. If it is not, post the task to the JS thread for judgment and execution.

      b) In cross-thread calling scenarios, OH_JSVM_DestroyEnv() may have already been executed on the current thread while other threads are still attempting to call JSVM-API, which may also cause this error.

      c) If a task queue is used for JS task execution, a destroy env task may be enqueued before a regular JS task, which may also cause this error. In this case, refer to scenario a) and add a thread_local_flag for the JSVM instance. If the thread_local_flag is true when a task is dequeued, all remaining tasks in the queue must be skipped.

   For more details, see [JSVM-API Development Process](use-jsvm-process.md).

## JSVM-API Execution Failures

1. Q: JS function parameters cannot be obtained by using `OH_JSVM_GetCbInfo`.

   A: Check whether the function parameters are correctly passed. For details, see [Obtaining Arguments Passed from JS](jsvm-guidelines.md#obtaining-arguments-passed-from-js).

2. Q: Functions such as `OH_JSVM_CreateFunction` fail to be called, and the return value is `JSVM_PENDING_EXCEPTION`.

   A: `JSVM_PENDING_EXCEPTION` indicates that there are unhandled exceptions in the current JSVM environment. The pending exception may be caused by the current call, or an exception thrown by a previous call has not been cleared. You can call `OH_JSVM_GetAndClearLastException` before the function call to check whether there is an uncleared exception from a previous call. If an uncleared exception exists, check whether any JSVM API call has not handled the exception return value. If the exception is caused by the current call, clear the exception to avoid affecting subsequent function calls. Use `OH_JSVM_GetAndClearLastException` to obtain and clear the exception.

3. Q: The class defined by `OH_JSVM_DefineClass` cannot be found during JS execution.

   A: Check whether the defined class is bound to the JS context. For details, see [Binding Objects to Context](jsvm-guidelines.md#binding-objects-to-context).