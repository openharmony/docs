# Node-API开发规范


## 生命周期管理

**【规则】** 合理使用napi_open_handle_scope和napi_close_handle_scope管理napi_value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。


每个napi_value属于特定的HandleScope，HandleScope通过napi_open_handle_scope和napi_close_handle_scope来建立和关闭，HandleScope关闭后，所属的napi_value就会自动释放。


**正确示例**：


```
// 在for循环中频繁调用napi接口创建js对象时，要加handle_scope及时释放不再使用的资源。 
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
for (int i = 0; i < 100000; i++) { 
    napi_handle_scope scope = nullptr;   
    napi_open_handle_scope(env, &scope); 
    if (scope == nullptr) { 
        return; 
    } 
    napi_value res; 
    napi_create_object(env, &res); 
    napi_close_handle_scope(env, scope); 
}
```


## 上下文敏感

**【规则】** 多引擎实例场景下，禁止通过Node-API跨引擎实例访问JS对象。


引擎实例是一个独立运行环境，JS对象创建访问等操作必须在同一个引擎实例中进行。若在不同引擎实例中操作同一个对象，可能会引发程序崩溃。引擎实例在接口中体现为napi_env。


**错误示例**：


```
// 线程1执行，在env1创建string对象，值为"bar"、 
napi_create_string_utf8(env1, "bar", NAPI_AUTO_LENGTH, &string);
// 线程2执行，在env2创建object对象，并将上述的string对象设置到object对象中
napi_status status = napi_create_object(env2, &object); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
} 

status = napi_set_named_property(env2, object, "foo", string); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
}
```


所有的JS对象都隶属于具体的某一napi_env，不可将env1的对象，设置到env2中的对象中。在env2中一旦访问到env1的对象，程序可能会发生崩溃。


## 异常处理

**【建议】** Node-API接口调用发生异常需要及时处理，不能遗漏异常到后续逻辑，否则程序可能发生不可预期行为。


**正确示例**：


```
// 1.创建对象
napi_status status = napi_create_object(env, &object); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return;
} 
// 2.创建属性值 
status = napi_create_string_utf8(env, "bar", NAPI_AUTO_LENGTH, &string); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
} 
// 3.将步骤2的结果设置为对象object属性foo的值 
status = napi_set_named_property(env, object, "foo", string); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
}
```


如上示例中，步骤1或者步骤2出现异常时，步骤3都不会正常进行。只有当方法的返回值是napi_ok时，才能保持继续正常运行；否则后续流程可能会出现不可预期的行为。


## 异步任务

**【规则】** 当使用uv_queue_work方法将任务抛到JS线程上面执行的时候，对JS线程的回调方法，一般情况下需要加上napi_handle_scope来管理回调方法创建的napi_value的生命周期。


使用uv_queue_work方法，不会走Node-API框架，此时需要开发者自己合理使用napi_handle_scope来管理napi_value的生命周期。


**正确示例**：


```
void callbackTest(CallbackContext* context) 
{ 
    uv_loop_s* loop = nullptr; 
    napi_get_uv_event_loop(context->env, &loop); 
    uv_work_t* work = new uv_work_t; 
    context->retData = 1; 
    work->data = (void*)context; 
    uv_queue_work( 
        loop, work, [](uv_work_t* work) {}, 
        // using callback function back to JS thread 
        [](uv_work_t* work, int status) { 
            CallbackContext* context = (CallbackContext*)work->data; 
            napi_handle_scope scope = nullptr; napi_open_handle_scope(context->env, &scope); 
            if (scope == nullptr) { 
                return; 
            } 
            napi_value callback = nullptr; 
            napi_get_reference_value(context->env, context->callbackRef, &callback); 
            napi_value retArg; 
            napi_create_int32(context->env, context->retData, &retArg); 
            napi_value ret; 
            napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret); 
            napi_delete_reference(context->env, context->callbackRef); 
            napi_close_handle_scope(context->env, scope); 
            if (work != nullptr) { 
                delete work; 
            } 
            delete context; 
        } 
    ); 
}
```


## 对象绑定

**【规则】** 使用napi_wrap接口，如果最后一个参数result传递不为nullptr，需要开发者在合适的时机调用napi_remove_wrap函数主动删除创建的napi_ref。

napi_wrap接口定义如下：

```
napi_wrap(napi_env env, napi_value js_object, void* native_object, napi_finalize finalize_cb, void* finalize_hint, napi_ref* result)
```

当最后一个参数result不为空时，框架会创建一个napi_ref对象，指向js_object。此时开发者需要自己管理js_object的生命周期，即需要在合适的时机调用napi_remove_wrap删除napi_ref，这样GC才能正常释放js_object，从而触发绑定C++对象native_object的析构函数finalize_cb。

一般情况下，根据业务情况最后一个参数result可以直接传递为nullptr。

**正确示例**：

```
// 用法1：napi_wrap不需要接收创建的napi_ref，最后一个参数传递nullptr，创建的napi_ref是弱引用，由系统管理，不需要用户手动释放 
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr)； 

// 用法2：napi_wrap需要接收创建的napi_ref，最后一个参数不为nullptr，返回的napi_ref是强引用，需要用户手动释放，否则会内存泄漏 
napi_ref result; 
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result)； 
// 当js_object和result后续不再使用时，及时调用napi_remove_wrap释放result 
napi_value result1; 
napi_remove_wrap(env, jsobject, result1);
```


## 其它

**【规则】** 使用napi_get_arraybuffer_info接口，第三个参数data资源开发者不允许释放，data的生命周期受引擎管理。

napi_get_arraybuffer_info接口定义如下：

```
napi_get_arraybuffer_info(napi_env env, napi_value arraybuffer, void** data, size_t* byte_length)
```

data获取的是ArrayBuffer的Buffer头指针，开发者只可以在范围内读写该Buffer区域，不可以进行释放操作。该段内存由引擎内部的ArrayBuffer Allocator管理，随JS对象ArrayBuffer的生命周期释放。

**错误示例：**

```
void* arrayBufferPtr = nullptr;
napi_value arrayBuffer = nullptr;
size_t createBufferSize = ARRAY_BUFFER_SIZE;
napi_status verification = napi_create_arraybuffer(env, createBufferSize, &arrayBufferPtr, &arrayBuffer);
size_t arrayBufferSize;
napi_status result = napi_get_arraybuffer_info(env, arrayBuffer, &arrayBufferPtr, &arrayBufferSize);
delete arrayBufferPtr; // 这一步是禁止的，创建的arrayBufferPtr生命周期由引擎管理，不允许用户自己delete，否则会double free
```

**【建议】** 合理使用napi_object_freeze和napi_object_seal来控制对象以及对象属性的可变性。

napi_object_freeze等同于Object.freeze语义，freeze后对象的所有属性都不可能以任何方式被修改；napi_object_seal等同于Object.seal语义，对象不可增删属性。两者的主要区别是，freeze不能改属性的值，seal还可以改属性的值。

开发者使用以上语义时，需确保约束条件是自己需要的，一旦违背以上语义严格模式下就会抛出Error（默认严格模式）。
