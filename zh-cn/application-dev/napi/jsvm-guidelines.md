# JSVM-API开发规范

## 生命周期管理

**【规则】** 合理使用OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope管理JSVM_Value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

每个JSVM_Value属于特定的HandleScope，HandleScope通过OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope来建立和关闭，HandleScope关闭后，所属的JSVM_Value就会自动释放。

**正确示例**：

```c++
// 在for循环中频繁调用JSVM接口创建js对象时，要加handle_scope及时释放不再使用的资源。 
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
for (int i = 0; i < 100000; i++)
{ 
    JSVM_HandleScope scope = nullptr;
    OH_JSVM_OpenHandleScope(env, &scope);
    if (scope == nullptr)
    { 
        return;
    } 
    JSVM_Value res;
    OH_JSVM_CreateObject(env, &res);
    OH_JSVM_CloseHandleScope(env, scope);
}
```

## 上下文敏感

**【规则】** 多引擎实例场景下，禁止通过JSVM-API跨引擎实例访问JS对象。

引擎实例是一个独立运行环境，JS对象创建访问等操作必须在同一个引擎实例中进行。若在不同引擎实例中操作同一个对象，可能会引发程序崩溃。引擎实例在接口中体现为JSVM_Env。

**错误示例**:

```c++
// 线程1执行，在env1创建string对象，值为"bar"、
OH_JSVM_CreateStringUtf8(env1, "value1", JSVM_AUTO_LENGTH , &string);
// 线程2执行，在env2创建object对象，并将上述的string对象设置到object对象中
JSVM_Status status = OH_JSVM_CreateObject(env2, &object);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
} 

status = OH_JSVM_SetNamedProperty(env2, object, "string1", string);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
}
```

所有的JS对象都隶属于具体的某一JSVM_Env，不可将env1的对象，设置到env2中的对象中。在env2中一旦访问到env1的对象，程序可能会发生崩溃。

## 异常处理

**【建议】** JSVM-API接口调用发生异常需要及时处理，不能遗漏异常到后续逻辑，否则程序可能发生不可预期行为。

**正确示例**：

```c++
// 1.创建对象
JSVM_Status status = OH_JSVM_CreateObject(env, &object);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
} 
// 2.创建属性值 
status = OH_JSVM_CreateStringUtf8(env, "bar", JSVM_AUTO_LENGTH, &string);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
} 
// 3.将步骤2的结果设置为对象object属性foo的值
status = OH_JSVM_SetNamedProperty(env, object, "foo", string);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
}
```

如上示例中，步骤1或者步骤2出现异常时，步骤3都不会正常进行。只有当方法的返回值是JSVM_OK时，才能保持继续正常运行；否则后续流程可能会出现不可预期的行为。

## 对象绑定

**【规则】** 使用OH_JSVM_Wrap接口，如果最后一个参数result传递不为nullptr，需要开发者在合适的时机调用OH_JSVM_RemoveWrap函数主动删除创建的JSVM_Ref。

OH_JSVM_Wrap接口定义如下：

```c++
JSVM_EXTERN JSVM_Status OH_JSVM_Wrap(JSVM_Env env,
                                     JSVM_Value jsObject,
                                     void* nativeObject,
                                     JSVM_Finalize finalizeCb,
                                     void* finalizeHint,
                                     JSVM_Ref* result);
```

当最后一个参数result不为空时，框架会创建一个JSVM_Ref对象，指向js_object。此时开发者需要自己管理js_object的生命周期，即需要在合适的时机调用OH_JSVM_RemoveWrap删除JSVM_Ref，这样GC才能正常释放js_object，从而触发绑定C++对象native_object的析构函数finalizeCb。

一般情况下，根据业务情况最后一个参数result可以直接传递为nullptr。

**正确示例**：

```c++
// 用法1：OH_JSVM_Wrap不需要接收创建的JSVM_Ref，最后一个参数传递nullptr，创建的JSVM_Ref是弱引用，由系统管理，不需要用户手动释放
OH_JSVM_Wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// 用法2：OH_JSVM_Wrap需要接收创建的JSVM_Ref，最后一个参数不为nullptr，返回的JSVM_Ref是强引用，需要用户手动释放，否则会内存泄漏
JSVM_Ref result;
OH_JSVM_Wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// 当js_object和result后续不再使用时，及时调用OH_JSVM_RemoveWrap释放result
JSVM_Value result1;
OH_JSVM_RemoveWrap(env, jsobject, result1);
```
