# JSVM-API Development Specifications

## Lifecycle Management

**[Rule]** Properly use **OH_JSVM_OpenHandleScope** and **OH_JSVM_CloseHandleScope** to minimize the lifecycle of **JSVM_Value** and prevent memory leaks.

Each **JSVM_Value** belongs to a specific **HandleScope** instance, which is created by **OH_JSVM_OpenHandleScope** and closed by **OH_JSVM_CloseHandleScope**. After a **HandleScope** instance is closed, the corresponding **JSVM_Value** will be automatically released.

> **NOTE**
>
> - **JSVM_Value** can be created only after **HandleScope** is opened; otherwise, the application may crash. Node-API does not have this restriction.
> - **JSVM_Value** cannot be used after the corresponding **HandleScope** is closed. To hold **JSVM_Value** persistently, call **OH_JSVM_CreateReference** to convert **JSVM_Value** to **JSVM_Ref**.
> - The scopes (including **JSVM_VMScope**, **JSVM_EnvScope**, and **JSVM_HandleScope**) must be closed in reverse order. The scope opened first must be closed last. Otherwise, the application may crash.

**Example (scope closing error)**
```
// If JSVM_VMScope is not closed in reverse order, the application may crash.
JSVM_VM vm;
JSVM_CreateVMOptions options;
OH_JSVM_CreateVM(&options, &vm);

JSVM_VMScope vmScope1, vmScope2;
OH_JSVM_OpenVMScope(vm, &vmScope1);
OH_JSVM_OpenVMScope(vm, &vmScope2);

// You need to close vmScope2 and then vmScope1.
OH_JSVM_CloseVMScope(vm, vmScope1);
OH_JSVM_CloseVMScope(vm, vmScope2);
OH_JSVM_DestroyVM(vm);
```


**Encapsulation in C++**

```
class HandleScopeWrapper {
 public:
  HandleScopeWrapper(JSVM_Env env) : env(env) {
    OH_JSVM_OpenHandleScope(env, &handleScope);
  }

  ~HandleScopeWrapper() {
    OH_JSVM_CloseHandleScope(env, handleScope);
  }

  HandleScopeWrapper(const HandleScopeWrapper&) = delete;
  HandleScopeWrapper& operator=(const HandleScopeWrapper&) = delete;
  HandleScopeWrapper(HandleScopeWrapper&&) = delete;
  void* operator new(size_t) = delete;
  void* operator new[](size_t) = delete;

 protected:
  JSVM_Env env;
  JSVM_HandleScope handleScope;
};
```

**Example**

```c++
// When JSVM-API is frequently called to create JS objects in the for loop, use handle_scope to release resources in a timely manner when they are no longer used.
// In the following example, the lifecycle of the local variable res ends at the end of each loop. To prevent memory leaks, scope is used to release the JS object in a timely manner.
// After each for loop ends, trigger the destructor function of HandleScopeWrapper to release the JS object held by scope.
for (int i = 0; i < 100000; i++)
{ 
    HandleScopeWrapper scope(env);
    JSVM_Value res;
    OH_JSVM_CreateObject(env, &res);
    if (i == 1000) {
        // After the loop exits, the HandleScopeWrapper destructor is automatically called to release resources.
        break;
    }
}
```

## Context Sensitive in Multiple JSVM Instances

**[Rule]** Do not use JSVM-API to access JS objects across JSVM instances.

A JSVM instance is an independent running environment. Operations such as creating and accessing a JS object must be performed in the same JSVM instance. If an object is operated in different JSVM instances, the application may crash. A JSVM instance is represented as a **JSVM_Env** in APIs.

**Example (incorrect)**

```c++
// Create a string object with value of "bar" in env1.
OH_JSVM_CreateStringUtf8(env1, "value1", JSVM_AUTO_LENGTH , &string);
// Create an object in env2 and set the string object to this object.
JSVM_Status status = OH_JSVM_CreateObject(env2, &object);
if (status != JSVM_OK)
{ 
    return;
} 

status = OH_JSVM_SetNamedProperty(env2, object, "string1", string);
if (status != JSVM_OK)
{ 
    return;
}
```

A JS object belongs to a specific **JSVM_Env**. Therefore, you cannot set an object of env1 to an object of env2. If the object of env1 is accessed in env2, the application may crash.

## JSVM Instance Shared by Multiple Threads

[**Rule**] When multiple threads use the same JSVM instance, use a lock to ensure that the JSVM instance can be executed in only one thread at a time. If multiple threads use the JSVM instance at the same time, the application may crash.

> **NOTE**
>
> - You can use **OH_JSVM_IsLocked** to check whether the calling thread holds the lock of the JSVM instance instead of setting a loop to wait for other threads to release the lock.
> - Nested use of **OH_JSVM_AcquireLock** in the same thread will not cause deadlock.
> - When using **OH_JSVM_ReleaseLock**, you need to check whether it is at the outermost layer to prevent the inner layer from releasing the lock of the entire thread when **OH_JSVM_AcquireLock** is nested in the same thread.
> - After **OH_JSVM_AcquireLock** is called, use **OH_JSVM_OpenHandleScope** to enable the JSVM instance to enter the thread. After **OH_JSVM_ReleaseLock** is called, use **OH_JSVM_ReleaseLock** to enable the JSVM instance to exit the thread.
> - A JSVM instance cannot be nested across threads. If you need to temporarily change the thread that uses the JSVM instance, ensure that **JSVM_Value** is saved as **JSVM_Ref**. After the lock is released, **JSVM_Value** cannot be accessed.
> - The sequence of obtaining resources is as follows: Lock -> VMScope -> EnvScope -> HandleScope. The sequence of releasing resources is the opposite. An incorrect sequence may cause the application to crash.



**Encapsulation in C++**

```
class LockWrapper {
 public:
  // Constructor, lock acquisition, VMScope, and EnvScope.
  LockWrapper(JSVM_Env env) : env(env) {
    OH_JSVM_IsLocked(env, &isLocked);
    if (!isLocked) {
      OH_JSVM_AcquireLock(env);
      OH_JSVM_GetVM(env, &vm);
      OH_JSVM_OpenVMScope(vm, &vmScope);
      OH_JSVM_OpenEnvScope(env, &envScope);
    }
  }

  // Destructor used to release EnvScope, VMScope, and lock.
  ~LockWrapper() {
    if (!isLocked) {
      OH_JSVM_CloseEnvScope(env, envScope);
      OH_JSVM_CloseVMScope(vm, vmScope);
      OH_JSVM_ReleaseLock(env);
    }
  }

  LockWrapper(const LockWrapper&) = delete;
  LockWrapper& operator=(const LockWrapper&) = delete;
  LockWrapper(LockWrapper&&) = delete;
  void* operator new(size_t) = delete;
  void* operator new[](size_t) = delete;

 private:
  JSVM_Env env;
  JSVM_EnvScope envScope;
  JSVM_VMScope vmScope;
  JSVM_VM vm;
  bool isLocked;
};
```



**Example (correct)**

```
// This example demonstrates how to use a JSVM across threads.
// Thread t1 obtains the lock and call JSVM-API.
// Thread t2 is blocked when thread t1 obtained the lock, continues to call JSVM-API when t1 releases the lock.
static napi_value Add([[maybe_unused]] napi_env _env, [[maybe_unused]] napi_callback_info _info) {
    static JSVM_VM vm;
    static JSVM_Env env;
    if (aa == 0) {
        OH_JSVM_Init(nullptr);
        aa++;
        // create vm
        JSVM_CreateVMOptions options;
        memset(&options, 0, sizeof(options));
        OH_JSVM_CreateVM(&options, &vm);
        // Create env.
        OH_JSVM_CreateEnv(vm, 0, nullptr, &env);
    }

    std::thread t1([]() {
        LockWrapper lock(env);
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);
        JSVM_Value value;
        JSVM_Status rst = OH_JSVM_CreateInt32(env, 32, &value); // 32: numerical value
        if (rst == JSVM_OK) {
            OH_LOG_INFO(LOG_APP, "JSVM:t1 OH_JSVM_CreateInt32 suc");
        } else {
            OH_LOG_ERROR(LOG_APP, "JSVM:t1 OH_JSVM_CreateInt32 fail");
        }
        int32_t num1;
        OH_JSVM_GetValueInt32(env, value, &num1);
        OH_LOG_INFO(LOG_APP, "JSVM:t1 num1 = %{public}d", num1);
        OH_JSVM_CloseHandleScope(env, handleScope);
    });
    std::thread t2([]() {
        LockWrapper lock(env);
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);
        JSVM_Value value;
        JSVM_Status rst = OH_JSVM_CreateInt32(env, 32, &value); // 32: numerical value
        if (rst == JSVM_OK) {
            OH_LOG_INFO(LOG_APP, "JSVM:t2 OH_JSVM_CreateInt32 suc");
        } else {
            OH_LOG_ERROR(LOG_APP, "JSVM:t2 OH_JSVM_CreateInt32 fail");
        }
        int32_t num1;
        OH_JSVM_GetValueInt32(env, value, &num1);
        OH_LOG_INFO(LOG_APP, "JSVM:t2 num1 = %{public}d", num1);
        OH_JSVM_CloseHandleScope(env, handleScope);
    });
    t1.detach();
    t2.detach();
    return nullptr;
}
```

## Obtaining Arguments Passed from JS

**[Rule]** When **argv** in **OH_JSVM_GetCbInfo** is not **nullptr**, the length of **argv** must be greater than or equal to **argc**.

If **argv** is not **nullptr**, the arguments actually passed from JS will be written to **argv** in **OH_JSVM_GetCbInfo** based on the value of **argc**. If there are more arguments than the provided count, only the requested number of arguments are copied. If there are fewer arguments provided than the claimed, the rest of **argv** is filled with values that represent **undefined**.

**Example (incorrect)**

```cpp
static JSVM_Value IncorrectDemo1(JSVM_Env env, JSVM_CallbackInfo info) {
    // argc is not correctly initialized and is set to a random value. If the length of argv is less than the number of arguments specified by argc, data overwriting occurs.
    size_t argc;
    JSVM_Value argv[10] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}

static JSVM_Value IncorrectDemo2(JSVM_Env env, JSVM_CallbackInfo info) {
    // If the number of arguments specified by argc is greater than the length of argv, out-of-bounds write will occur when data is written to argv in napi_get_cb_info.
    size_t argc = 5;
    JSVM_Value argv[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}
```

**Example (correct)**

```cpp
static JSVM_Value GetArgvDemo1(napi_env env, JSVM_CallbackInfo info) {
    size_t argc = 0;
    // Pass in nullptr to argv to obtain the actual number of arguments passed by JS.
    OH_JSVM_GetCbInfo(env, info, &argc, nullptr, nullptr, nullptr);
    // If 0 is passed by JS, the subsequent logic is not executed.
    if (argc == 0) {
        return nullptr;
    }
    // Create an array to obtain the arguments passed by JS.
    JSVM_Value* argv = new JSVM_Value[argc];
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Service code.
    // ... ...
    // argv is an object created by new and must be manually released when it is not required.
    delete argv;
    return nullptr;
}

static JSVM_Value GetArgvDemo2(napi_env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value* argv[2] = {nullptr};
    // The arguments (of the quantity specified by argc) passed from JS or undefined will be written to argv of OH_JSVM_GetCbInfo.
    OH_JSVM_GetCbInfo(env, info, &argc, nullptr, nullptr, nullptr);
    // Service code.
    // ... ...
    return nullptr;
}
```

## Exception Handling

**[Suggestion]** Any exception occurred in a JSVM-API call should be handled in a timely manner. Otherwise, unexpected behavior may occur.

 Exception handling can be classified into the following types based on the primary/secondary relationship:

1. If a C++ exception occurs when the JSVM executes a C++ callback function (JS is primary and native is secondary), the exception needs to be thrown to the JSVM. The following example demonstrates the implementation of the C++ callback function in three difference scenarios.

  >  **NOTE**<br>If the JSVM-API call in a C++ callback fails, you can either throw an exception to the JSVM or not. To throw an exception, ensure that there is no pending exception in the JSVM. If you choose not to throw an exception, JS **try-catch** can capture such JS exceptions. For details, see **NativeFunctionExceptionDemo3**.

  ```c++
   // JSVM is primary, and native is secondary.
   void DoSomething() {
       throw("Do something failed");
   }
  
   // Demo 1: Throw the exception captured in C++ to the JSVM.
   JSVM_Value NativeFunctionExceptionDemo1(JSVM_Env env, JSVM_CallbackInfo info) {
       try {
           DoSomething();
       } catch (const char *ex) {
           OH_JSVM_ThrowError(env, nullptr, ex);
           return nullptr;
       }
       return nullptr;
   }
  
   // Demo 2: Throw an exception to the JSVM when a JSVM-API call fails.
   JSVM_Value NativeFunctionExceptionDemo2(JSVM_Env env, JSVM_CallbackInfo info) {
       JSVM_Value JSBool = nullptr;
       bool value = false;
       auto status = OH_JSVM_GetValueBool(env, JSBool, &value);
       if (status != JSVM_OK) {
           OH_JSVM_ThrowError(env, nullptr, "Get bool value failed");
           return nullptr;
       }
       return nullptr;
   }
  
   // Demo 3: Add an exception to the JSVM for handling when the JSVM-API call fails. In this case, you do not need to throw exceptions to the JSVM.
   JSVM_Value NativeFunctionExceptionDemo3(JSVM_Env env, JSVM_CallbackInfo info) {
       std::string sourcecodestr = R"JS(
           throw Error('Error throw from js');
       )JS";
       JSVM_Value sourcecodevalue = nullptr;
       OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
       JSVM_Script script;
       auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
       JSVM_Value result;
       // Execute the JS script and throw a JS exception during the execution.
       status = OH_JSVM_RunScript(env, script, &result);
       if (status != JSVM_OK) {
           bool isPending = false;
           // If an exception already exists, do not throw the exception to the JSVM.
           // If a new exception needs to be thrown, handle the pending exception in the JSVM first.
           if (JSVM_OK == OH_JSVM_IsExceptionPending((env), &isPending) && isPending) {
               return nullptr;
           }
           OH_JSVM_ThrowError(env, nullptr, "Runscript failed");
           return nullptr;
       }
       return nullptr;
   }
  
   // Bind NativeFunction to the JSVM. The process is omitted here.
   std::string sourcecodestr = R"JS(
       // The console log needs to be implemented.
       try {
           // Call the native function.
           NativeFunction()
       } catch (e) {
           // Handle the exception in C/C++.
           consolelog(e.message)
       }
   )JS";
   JSVM_Value sourcecodevalue = nullptr;
   OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
   JSVM_Script script;
   auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
   OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}d", (uint32_t)status);
   JSVM_Value result;
   // Execute the JS script to call native methods from JS.
   status = OH_JSVM_RunScript(env, script, &result);
  ```

2. If JSVM-API (native is primary and JS is secondary) fails to be called from C++, clear the pending exceptions in JSVM to prevent the impact on subsequent JSVM-API execution and set a branch to handling C++ exception (or throw a C++ exception).
    ```
    std::string sourcecodestr = R"JS(
        throw Error('Error throw from js');
    )JS";
    JSVM_Value sourcecodevalue = nullptr;
    OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
    JSVM_Script script;
    auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
    // Exception handling.
    if (status != JSVM_OK) {
        JSVM_Value error = nullptr;
        // Obtain and clear the exception.
        CALL_JSVM(OH_JSVM_GetAndClearLastException((env), &error));
        // Handle the exception, for example, printing information. The code is omitted here.
        // Throw a C++ exception or stop function execution.
        throw "JS Compile Error";
    }
    JSVM_Value result;
    // Execute the JS script and throw a JS exception during the execution.
    status = OH_JSVM_RunScript(env, script, &result);
    
    // Exception handling.
    if (status != JSVM_OK) {
        JSVM_Value error = nullptr;
        // Obtain and clear the exception.
        CALL_JSVM(OH_JSVM_GetAndClearLastException((env), &error));
        // Handle the exception, for example, printing information. The code is omitted here.
        // Throw a C++ exception or stop function execution.
        throw "JS RunScript Error";
    }
    
    ```

## Binding Object Context

**[Rule]**: The JS function and object generated by JSVM-API can be accessed from JS only after they are bound to the context. The **const char *** parameter in **OH_JSVM_CreateFunction** is the property **name** of the created function, without pointing to the function in the context. This rule also applies to the class and object generated by JSVM-API.

**Example**

```
JSVM_Value JSFunc = nullptr;
const char *name = "NativeFunction";
JSVM_CallbackStruct cb = {NativeFunction, nullptr};
// Create a JS function, whose property "name" is set to "NativeFunction".
OH_JSVM_CreateFunction(env, name, strlen(name), &cb, &JSFunc);
// Bind the function to the context.
// Obtain the global object of the context.
JSVM_Value global = nullptr;
OH_JSVM_GetGlobal(env, &global);
// Create the JS string "FunctionNameInJSContext."
JSVM_Value key = nullptr;
OH_JSVM_CreateStringLatin1(env, "FunctionNameInJSContext", JSVM_AUTO_LENGTH, &key);
// Set the global property "FunctionNameInJSContext" to "JSFunc". This binds the function to the context.
OH_JSVM_SetProperty(env, global, key, JSFunc);
// Call the function from JS.
std::string sourcecodestr = R"JS(
    // The console log needs to be implemented.
    FunctionNameInJSContext() // The call is successful.
    consolelog(FunctionNameInJSContext.name) // Print "NativeFunction."
    try {
    	NativeFunction() // If the function cannot be found, throw an exception.
    } catch (e) {
    	consolelog(e.message)
    }
)JS";
```
