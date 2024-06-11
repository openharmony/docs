# JSVM-API常见问题

CPP crash类问题：通过调用栈查询FAQ的方式定位代码问题

执行结果不符合预期类问题：需应用通过JSVM-API调用返回值定位到执行失败或执行结果不符合预期的位置，通过函数名查询FAQ

## CPP Crash

1. Q：在`OH_JSVM_RunScript`或`OH_JSVM_CallFunction`时crash，调用栈顶层为`SetReturnValue`

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

   A：SetReturnValue为设置js中函数函数执行的返回值，当js中调用注入的native函数时触发。需检查native函数的返回值是否正确，如返回值JSVM_Value是否未初始化为nullptr。
   
2. Q：js中执行虚拟机初始化注入的native函数crash

      A：检查`JSVM_CallbackStruce`是否为栈上变量，需保证`JSVM_CallbackStruct`生命周期 >=`JSVM_Env`的生命周期

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

      样例中的代码结构如上，虚拟机在函数结束前被关闭，所以可以直接使用栈上的`param`。

3. Q：`OH_JSVM_ReferenceRef`、`OH_JSVM_ReferenceUnRef`、`OH_JSVM_CreateReference`、`OH_JSVM_DeleteReference`时crash

   A：检查是否同时有多个线程持有和释放`JSVM_Ref`，见 xxx

## JSVM执行失败

1. Q：`OH_JSVM_GetCbInfo`的无法获取JS函数参数

   A：检查函数传递的参数是否正确，见[获取JS传入参数及其数量](jsvm-guidelines.md#获取js传入参数及其数量)

2. Q：`OH_JSVM_CreateFunction`等函数调用失败，返回值为`JSVM_PENDING_EXCEPTION`

   A：`JSVM_PENDING_EXCEPTION`表明当前虚拟机环境中存在未处理的异常，可能是由于本次调用产生的`JS`异常，也可能是之前调用产生的未被清理的异常。可以通过在函数调用前插入`OH_JSVM_GetAndClearLastException`排查之前是否有未清除的异常。如果为之前的未清理异常，检查是否有JSVM接口调用未处理异常返回值；如未本次产生的异常，需清理异常，避免影响后续的函数调用。获取并清理异常的函数为`OH_JSVM_GetAndClearLastException`
