# JSVM-API使用规范

## 生命周期管理

**【规则】** 合理使用OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope管理JSVM_Value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

每个JSVM_Value属于特定的HandleScope，HandleScope通过OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope来建立和关闭，HandleScope关闭后，所属的JSVM_Value就会自动释放。

**建议**：申明一个类，类的构造函数和析构函数中打开和关闭scope，可以提高编码效率，并且可以避免忘记关闭scope的问题

```c++
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

// 在for循环中频繁调用JSVM接口创建js对象时，要加handle_scope及时释放不再使用的资源。
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
// 每次for循环结束后，触发HandleScopeWrapper的析构函数，释放scope持有的js对象
for (int i = 0; i < 100000; i++)
{
    HandleScopeWrapper scope(env);
    JSVM_Value res;
    OH_JSVM_CreateObject(env, &res);
    if (i == 100) {
        break;
    }
}
```

## 多引擎实例上下文敏感

**【规则】** 多引擎实例（VM）场景下，禁止通过JSVM-API跨引擎实例访问JS对象。

引擎实例是一个独立运行环境，JS对象创建访问等操作必须在同一个引擎实例中进行。若在不同引擎实例中操作同一个对象，可能会引发程序崩溃。引擎实例在接口中体现为JSVM_Env。

**错误示例**:

```c++
// 线程1执行，在env1创建string对象，值为"bar"、
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

## 获取JS传入参数及其数量

**【规则】** 当传入OH_JSVM_GetCbInfo的argv不为nullptr时，argv的长度必须大于等于传入argc声明的大小。

当argv不为nullptr时，OH_JSVM_GetCbInfo会根据argc声明的数量将JS实际传入的参数写入argv。如果argc小于等于实际JS传入参数的数量，该接口仅会将声明的argc数量的参数写入argv；而当argc大于实际参数数量时，该接口会在argv的尾部填充undefined。

**错误示例**

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

**正确示例**

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


