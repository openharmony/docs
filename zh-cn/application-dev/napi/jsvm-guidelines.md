# JSVM-API使用规范

## 生命周期管理

**【规则】** 合理使用`OH_JSVM_OpenHandleScope`和`OH_JSVM_CloseHandleScope`管理JSVM_Value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

每个JSVM_Value属于特定的HandleScope，HandleScope通过`OH_JSVM_OpenHandleScope`和`OH_JSVM_CloseHandleScope`来建立和关闭，HandleScope关闭后，所属的JSVM_Value就会自动释放。

**注意事项**：

1. JSVM_Value必须在HandleScope打开后才可创建(Node-API无该限制)，否则会造成应用崩溃；
2. JSVM_Value不能在其对应的HandleScope关闭后使用，如需持久化持有，需调用`OH_JSVM_CreateReference`转化为`JSVM_Ref`；
3. Scope(包括JSVM_VMScope、JSVM_EnvScope、JSVM_HandleScope)需逆序关闭，最先打开的Scope需最后关闭，否则可能造成应用崩溃；

**Scope关闭错误示例**：
```
// 未逆序关闭JSVM_VMScope，可能造成应用崩溃
JSVM_VM vm;
JSVM_CreateVMOptions options;
OH_JSVM_CreateVM(&options, &vm);

JSVM_VMScope vmScope1, vmScope2;
OH_JSVM_OpenVMScope(vm, &vmScope1);
OH_JSVM_OpenVMScope(vm, &vmScope2);

// 正确顺序为先关闭vmScope2，再关闭vmScope1
OH_JSVM_CloseVMScope(vm, vmScope1);
OH_JSVM_CloseVMScope(vm, vmScope2);
OH_JSVM_DestroyVM(vm);
```


**C++使用封装**：

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

**示例**：

```c++
// 在for循环中频繁调用JSVM接口创建js对象时，要加handle_scope及时释放不再使用的资源。 
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
// 每次for循环结束后，触发HandleScopeWrapper的析构函数，释放scope持有的js对象
for (int i = 0; i < 100000; i++)
{ 
    HandleScopeWrapper scope(env);
    JSVM_Value res;
    OH_JSVM_CreateObject(env, &res);
    if (i == 1000) {
        // break退出循环后会自动调用HandleScopeWrapper析构函数释放资源
        break;
    }
}
```

## 多引擎实例上下文敏感

**【规则】** 多引擎实例（VM）场景下，禁止通过JSVM-API跨引擎实例访问JS对象。

引擎实例是一个独立运行环境，JS对象创建访问等操作必须在同一个引擎实例中进行。若在不同引擎实例中操作同一个对象，可能会引发程序崩溃。引擎实例在接口中体现为JSVM_Env。

**错误示例**：

```c++
// 线程1执行，在env1创建string对象，值为"value1"
OH_JSVM_CreateStringUtf8(env1, "value1", JSVM_AUTO_LENGTH , &string);
// 线程2执行，在env2创建object对象，并将上述的string对象设置到object对象中
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

所有的JS对象都隶属于具体的某一JSVM_Env，不可将env1的对象，设置到env2中的对象中。在env2中一旦访问到env1的对象，程序可能会发生崩溃。

## 多线程共享引擎实例

【规则】多线程同时使用同一个引擎实例的场景下，需要加锁使用。保证一个引擎实例在同一时刻只能在一个线程执行。多线程同一时刻同时使用引擎实例可能造成应用崩溃。

**注意事项**：

1. `OH_JSVM_IsLocked`的结果为**当前线程**是否持有引擎实例的锁，无需设置循环等待其他线程释放锁；
2. `OH_JSVM_AcquireLock`在同一线程中嵌套使用不会造成死锁；
3. 使用`OH_JSVM_ReleaseLock`时需判断是否在最外层，避免同一线程中嵌套使用`OH_JSVM_AcquireLock`的场景下内层释放了整个线程的锁；
4. `OH_JSVM_AcquireLock`后需调用`OH_JSVM_OpenHandleScope`让引擎实例进入线程；`OH_JSVM_ReleaseLock`前需调用`OH_JSVM_CloseHandleScope`让引擎实例退出线程；
5. 不同线程禁止嵌套使用引擎实例，如需临时切换线程使用引擎实例，请确保`JSVM_Value`已保存为`JSVM_Ref`，释放锁后对`JSVM_Value`将不可访问；
6. 需注意资源获取的顺序为：锁 -> VMScope -> EnvScope -> HandleScope，资源释放的顺序正好相反，错误的顺序可能导致程序崩溃。

**C++使用封装**：

```
class LockWrapper {
 public:
  // 构造函数，获取锁、VMScope、EnvScope
  LockWrapper(JSVM_Env env) : env(env) {
    OH_JSVM_IsLocked(env, &isLocked);
    if (!isLocked) {
      OH_JSVM_AcquireLock(env);
      OH_JSVM_GetVM(env, &vm);
      OH_JSVM_OpenVMScope(vm, &vmScope);
      OH_JSVM_OpenEnvScope(env, &envScope);
    }
  }

  // 析构函数，释放EnvScope、VMScope、锁
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



**正确示例**：

```
// 该用例演示了多线程中使用vm
// t1线程先获取锁，并继续JSVM-API的调用
// t2线程会在获取锁处阻塞，直到t1线程执行结束释放锁后，t2线程继续执行，调用JSVM-API接口
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
        // create env
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

## 获取JS传入参数及其数量

**【规则】** 当传入OH_JSVM_GetCbInfo的argv不为nullptr时，argv的长度必须大于等于传入argc声明的大小。

当argv不为nullptr时，OH_JSVM_GetCbInfo会根据argc声明的数量将JS实际传入的参数写入argv。如果argc小于等于实际JS传入参数的数量，该接口仅会将声明的argc数量的参数写入argv；而当argc大于实际参数数量时，该接口会在argv的尾部填充undefined。

**错误示例**：

```cpp
static JSVM_Value IncorrectDemo1(JSVM_Env env, JSVM_CallbackInfo info) {
    // argc 未正确的初始化，其值为不确定的随机值，导致 argv 的长度可能小于 argc 声明的数量，数据越界。
    size_t argc;
    JSVM_Value argv[10] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}

static JSVM_Value IncorrectDemo2(JSVM_Env env, JSVM_CallbackInfo info) {
    // argc 声明的数量大于 argv 实际初始化的长度，导致 OH_JSVM_GetCbInfo 接口在写入 argv 时数据越界。
    size_t argc = 5;
    JSVM_Value argv[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    return nullptr;
}
```

**正确示例**：

```cpp
static JSVM_Value GetArgvDemo1(napi_env env, JSVM_CallbackInfo info) {
    size_t argc = 0;
    // argv 传入 nullptr 来获取传入参数真实数量
    OH_JSVM_GetCbInfo(env, info, &argc, nullptr, nullptr, nullptr);
    // JS 传入参数为0，不执行后续逻辑
    if (argc == 0) {
        return nullptr;
    }
    // 创建数组用以获取JS传入的参数
    JSVM_Value* argv = new JSVM_Value[argc];
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 业务代码
    // ... ...
    // argv 为 new 创建的对象，在使用完成后手动释放
    delete argv;
    return nullptr;
}

static JSVM_Value GetArgvDemo2(napi_env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value* argv[2] = {nullptr};
    // OH_JSVM_GetCbInfo 会向 argv 中写入 argc 个 JS 传入参数或 undefined
    OH_JSVM_GetCbInfo(env, info, &argc, nullptr, nullptr, nullptr);
    // 业务代码
    // ... ...
    return nullptr;
}
```

## 异常处理

**【建议】** JSVM-API接口调用发生异常需要及时处理，不能遗漏异常到后续逻辑，否则程序可能发生不可预期行为。

 根据主从类型，异常处理可以分为两类：

1. JSVM 执行 C++ 回调函数（JS主，Native从）时发生 C++ 异常，需往 JSVM 中抛出异常，下面用例描述了3种情况下 C++ 回调函数的写法
**注意事项**：回调函数中调用JSVM-API失败，如要向JSVM中抛异常，需保证JSVM中无等待处理的异常，也可以不抛出异常，JS的try-catch块可以捕获回调函数调用API失败产生的JS异常，见`NativeFunctionExceptionDemo3`。
    ```c++
    // JSVM主， Native从
    void DoSomething() {
        throw("Do something failed");
    }

    // Demo1: C++捕获到异常，抛出异常到JSVM中
    JSVM_Value NativeFunctionExceptionDemo1(JSVM_Env env, JSVM_CallbackInfo info) {
        try {
            DoSomething();
        } catch (const char *ex) {
            OH_JSVM_ThrowError(env, nullptr, ex);
            return nullptr;
        }
        return nullptr;
    }

    // Demo2: JSVM-API调用失败，抛出异常到JSVM中
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

    // Demo3：JSVM-API调用失败且在调用过程中已向JSVM中添加等待处理的异常，则无需再向JSVM中抛出异常
    JSVM_Value NativeFunctionExceptionDemo3(JSVM_Env env, JSVM_CallbackInfo info) {
        std::string sourcecodestr = R"JS(
            throw Error('Error throw from js');
        )JS";
        JSVM_Value sourcecodevalue = nullptr;
        OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
        JSVM_Script script;
        auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
        JSVM_Value result;
        // 执行JS脚本，执行过程中抛出JS异常
        status = OH_JSVM_RunScript(env, script, &result);
        if (status != JSVM_OK) {
            bool isPending = false;
            // 如果已有异常，则无需再向JSVM中抛出异常；
            // 如需处理并抛出新异常，需先处理JSVM中等待的异常
            if (JSVM_OK == OH_JSVM_IsExceptionPending((env), &isPending) && isPending) {
                return nullptr;
            }
            OH_JSVM_ThrowError(env, nullptr, "Runscript failed");
            return nullptr;
        }
        return nullptr;
    }

    // 绑定NativeFunction到JSVM中，省略
    std::string sourcecodestr = R"JS(
        // consolelog需用户实现
        try {
            // 调用Native函数
            NativeFunction()
        } catch (e) {
            // 处理Native中产生的异常
            consolelog(e.message)
        }
    )JS";
    JSVM_Value sourcecodevalue = nullptr;
    OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
    JSVM_Script script;
    auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}d", (uint32_t)status);
    JSVM_Value result;
    // 执行JS脚本，JS调用Native方法
    status = OH_JSVM_RunScript(env, script, &result);
    ```

2. C++调用JSVM-API（Native主，JS从）失败，需清理JSVM中等待处理的异常，避免影响后续JSVM-API的执行，并设置C++异常处理分支（或抛出C++异常）。
    ```
    std::string sourcecodestr = R"JS(
        throw Error('Error throw from js');
    )JS";
    JSVM_Value sourcecodevalue = nullptr;
    OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);
    JSVM_Script script;
    auto status = OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script);
    // 异常处理分支
    if (status != JSVM_OK) {
        JSVM_Value error = nullptr;
        // 获取并清理异常
        CALL_JSVM(OH_JSVM_GetAndClearLastException((env), &error));
        // 处理异常，如打印信息，省略
        // 抛出 C++ 异常或结束函数执行
        throw "JS Compile Error";
    }
    JSVM_Value result;
    // 执行JS脚本，执行过程中抛出JS异常
    status = OH_JSVM_RunScript(env, script, &result);
    
    // 异常分支处理
    if (status != JSVM_OK) {
        JSVM_Value error = nullptr;
        // 获取并清理异常
        CALL_JSVM(OH_JSVM_GetAndClearLastException((env), &error));
        // 处理异常，如打印信息，省略
        // 抛出 C++ 异常或结束函数执行
        throw "JS RunScript Error";
    }

    ```

## 上下文绑定对象

**【规则】**：调用JSVM-API生成的JS函数、对象需绑定到上下文中才能从JS侧访问，`OH_JSVM_CreateFunction`接口中的`const char *`参数为创建函数的属性`name`，不代表上下文中指向该函数的名称。调用JSVM-API生成的类、对象同理。

**示例**：

```
JSVM_Value JSFunc = nullptr;
const char *name = "NativeFunction";
JSVM_CallbackStruct cb = {NativeFunction, nullptr};
// 创建JS函数，该函数的属性 "name" 为 "NativeFunction"
OH_JSVM_CreateFunction(env, name, strlen(name), &cb, &JSFunc);
// 绑定函数到上下文
// 获取上下文的global对象
JSVM_Value global = nullptr;
OH_JSVM_GetGlobal(env, &global);
// 创建JS字符串"FunctionNameInJSContext"
JSVM_Value key = nullptr;
OH_JSVM_CreateStringLatin1(env, "FunctionNameInJSContext", JSVM_AUTO_LENGTH, &key);
// 设置global的属性"FunctionNameInJSContext"为JSFunc，将函数绑定到上下文中
OH_JSVM_SetProperty(env, global, key, JSFunc);
// 在JS中调用函数
std::string sourcecodestr = R"JS(
    // consolelog需用户实现
    FunctionNameInJSContext() // 调用成功
    consolelog(FunctionNameInJSContext.name) // 打印 "NativeFunction"
    try {
    	NativeFunction() // 无法找到该函数，抛出异常
    } catch (e) {
    	consolelog(e.message)
    }
)JS";
```