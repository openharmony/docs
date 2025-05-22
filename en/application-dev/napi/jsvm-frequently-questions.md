# JSVM-API FAQs

## Fault Location

If the application crashes, check the call stack to locate the fault. For details, see [Application Crash Issues](#application-crash-issues).

If an unexpected behavior occurs during the running of the application, locate the code where the execution fails or the unexpected behavior occurs based on the return value and make further analysis based on the function name. For details, see [JSVM-API Execution Failures](#jsvm-api-execution-failures).

## Application Crash Issues

1. Q: The application crashes when **OH_JSVM_RunScript** or **OH_JSVM_CallFunction** is called, and the stack top is **SetReturnValue**.

   ```
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

2. Q: The application crashes when the native function injected during JSVM initialization is executed by JS.

   A: Check whether **JSVM_CallbackStruct** is a variable in the stack. When **JSVM_CallbackStruct** is used across functions, the lifecycle of **JSVM_CallbackStruct** must be greater than that of **JSVM_Env**.

   ```
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
       // Create env, register native method, and open env scope.
       JSVM_Env env;
       OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
      // ...
       OH_JSVM_DestroyEnv(env);
      // ...
   }
   ```

   In the previous example, the JSVM instance is closed before the function ends. Therefore, the **JSVM_CallbackStruct param** in the stack can be used.

3. Q: The application crashes when **OH_JSVM_ReferenceRef**, **OH_JSVM_ReferenceUnRef**, **OH_JSVM_CreateReference**, or **OH_JSVM_DeleteReference** is called.

   A: Check whether **JSVM_Ref** is held and released by multiple threads at the same time. For details, see [JSVM Instance Shared by Multiple Threads](jsvm-guidelines.md#jsvm-instance-shared-by-multiple-threads).

4. Q: The application crashes when a JS data type instance is created (for example, **OH_JSVM_CreateDouble**) in a JSVM instance. The call stack is as follows:

   ```
   #00 pc 0000000001d209e4/system/1ib64/ndk/libjsvm.so(v8::base::0S::Abort()+28)
   #01 pc 0000000001408480/system/lib64/ndk/libjsvm.so(v8::Utils::ReportApiFailure(char const*,char const*)+124)
   #02 pc 00000000015c99b8/system/lib64/ndk/libjsvm.so(v8::internal::Handlescope::Extend(v8::internal::Isolate*+200)
   ```

   A: Check whether **HandleScope** is correctly used. For details, see [Lifecycle Management](jsvm-guidelines.md#lifecycle-management).

## JSVM-API Execution Failures

1. Q: The JS function parameters failed to be obtained by using **OH_JSVM_GetCbInfo**.

   A: Check whether the function parameters are correctly passed. For details, see [Obtaining Arguments Passed from JS](jsvm-guidelines.md#obtaining-arguments-passed-from-js).

2. Q: **JSVM_PENDING_EXCEPTION** is returned when functions such as **OH_JSVM_CreateFunction** are called.

   A: **JSVM_PENDING_EXCEPTION** indicates that the JSVM has pending exceptions. The pending exception may be caused by the current call, or an exception thrown by a previous call has not been cleared. You can use **OH_JSVM_GetAndClearLastException** before the current function is called to check whether there are uncleared exceptions. If there is uncleared exception, check for exception value that is not processed. If the exception is thrown by the current call, handle the exception. You can use **OH_JSVM_GetAndClearLastException** to obtain and clear the pending exception.

3. Q: The class defined by **OH_JSVM_DefineClass** cannot be found during the JSVM execution.

   A: Check whether the defined class is bound to the JS context. For details, see [Binding Object Context](jsvm-guidelines.md#binding-object-context).
