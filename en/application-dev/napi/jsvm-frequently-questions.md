# JSVM-API FAQs

## Location Method

Program crash problems: Locate code problems by querying FAQs in the call stack when C++ crashes.

If the program execution result does not meet the expectation, the application needs to locate the execution failure or execution result that does not meet the expectation based on the return value of JSVM-API invoking, and query FAQs based on the function name.

## Program Crash

1. Q: What can I do if the system crashes at `OH_JSVM_RunScript` or `OH_JSVM_CallFunction` and the top layer of the call stack is `SetReturnValue`?

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

   A: `SetReturnValue` is used to set the return value of the JS function. It is triggered after the JS calls the injected native function. Check whether the return value of the native function is correct. For example, check whether the return value (type `JSVM_Value`) is directly returned before initialization.

2. Q: The program breaks down when the JS executes the native function injected during VM initialization.

   A: Check whether `JSVM_CallbackStruce` is a stack variable. If `JSVM_CallbackStruce` is used across functions, ensure that the lifecycle of `JSVM_CallbackStruct` is greater than that of `JSVM_Env`.

   ```
   func {
   	...
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
       ...
       OH_JSVM_DestroyEnv(env);
       ...
   }
   ```

   The code structure in the example is shown in the preceding figure. The JavaScript engine instance is closed before the function ends. Therefore, you can directly use the `param` on the stack.

3. Q: Why does the program crash when `OH_JSVM_ReferenceRef`, `OH_JSVM_ReferenceUnRef`, `OH_JSVM_CreateReference`, or `OH_JSVM_DeleteReference` is executed?

   A: Check whether multiple threads hold and release `JSVM_Ref` at the same time. For details, see [Multi-thread Shared Engine Instance] (jsvm-guidelines.md#Multi-thread Shared Engine Instance).

4. Q: When a JS instance (for example, `OH_JSVM_CreateDouble`) is created in the VM engine instance, the system breaks down. The call stack is as follows:

   ```
   #00 pc 0000000001d209e4/system/1ib64/ndk/libjsvm.so(v8::base::0S::Abort()+28)
   #01 pc 0000000001408480/system/lib64/ndk/libjsvm.so(v8::Utils::ReportApiFailure(char const*,char const*)+124)
   #02 pc 00000000015c99b8/system/lib64/ndk/libjsvm.so(v8::internal::Handlescope::Extend(v8::internal::Isolate*+200)
   ```

   A: Check whether HandleScope is correctly used. For details, see [Lifecycle Management] (jsvm-guidelines.md#Lifecycle Management).

## JSVM-API execution failure class

1. Q: What can I do if the `OH_JSVM_GetCbInfo` cannot obtain JavaScript function parameters?

   A: Check whether the parameters transferred by the function are correct. For details, see [Obtaining JS Input Parameters and Their Quantity] (jsvm-guidelines.md#Obtaining JS Input Parameters and Their Quantity).

2. Q: What can I do if functions such as `OH_JSVM_CreateFunction` fail to be called and the return value is `JSVM_PENDING_EXCEPTION`?

   A: `JSVM_PENDING_EXCEPTION` indicates that an exception that is not handled exists in the current VM environment. The exception may be caused by the `JS` exception generated during the current invoking or the exception that is not cleared during the previous invoking. You can insert `OH_JSVM_GetAndClearLastException` before invoking the function to check whether there are uncleared exceptions. If the exception is not cleared, check whether any JSVM API invoking exception is not processed. If no exception is generated, clear the exception to prevent subsequent function invoking from being affected. The function for obtaining and clearing exceptions is `OH_JSVM_GetAndClearLastException`.

3. Q: What can I do if the class defined by `OH_JSVM_DefineClass` cannot be found during JavaScript execution?

   A: Check whether the defined class is bound to the context. For details, see [Context Binding Object] (jsvm-guidelines.md#Context Binding Object).
