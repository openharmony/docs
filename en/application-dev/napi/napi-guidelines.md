# Node-API Development Specifications


## Lifecycle Management

**[Rule]** Properly use **napi_open_handle_scope** and **napi_close_handle_scope** to manage **napi_value** so as to minimize the lifecycle and avoid memory leakage.


Each **napi_value** belongs to a specific **HandleScope**, which is opened and closed by **napi_open_handle_scope** and **napi_close_handle_scope**, respectively. After a **HandleScope** is closed, **napi_value** is automatically released.

**Example (correct)**:


```
// When the NAPI interface is frequently called to create JS objects in the for loop, add handle_scope to release resources that are no longer used in a timely manner.
// In the following example, the lifecycle of the local variable res ends at the end of each loop. Therefore, scope needs to be added to release the JS object in time and prevent memory leakage.
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


## Context Sensitive

**[Rule]** Do not access JS objects across engine instances using Node-API.


An engine instance is an independent running environment. Operations such as creating and access a JS object must be performed in the same engine instance. If an object is operated in different engine instances, the application may crash. An engine instance is represented as **napi_env** in APIs.

**Example (incorrect)**:


```
// Create a string object with value of bar in env1.
napi_create_string_utf8(env1, "bar", NAPI_AUTO_LENGTH, &string);
// Create an object in env2 and set the previous string object to this object.
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


JS objects belong to a specific napi_env. Therefore, you cannot set an object of env1 to an object of env2. If the object of env1 is accessed in env2, the application may crash.


## Exception Handling

**[Suggestion]** Any exception occurred in a Node-API should be handled in a timely manner. Otherwise, unexpected behavior may occur in your application.


**Example (correct)**:


```
// 1. Create an object.
napi_status status = napi_create_object(env, &object); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return;
} 
// 2. Create an attribute.
status = napi_create_string_utf8(env, "bar", NAPI_AUTO_LENGTH, &string); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
} 
// 3. Set the result of step 2 to the value of the object attribute foo.
status = napi_set_named_property(env, object, "foo", string); 
if (status != napi_ok) { 
    napi_throw_error(env, ...); 
    return; 
}
```


In this example, if an exception occurs in step 1 or step 2, step 3 will not be performed. Step 3 will be performed only when napi_ok is returned in steps 1 and 2.


## Asynchronous Tasks

**[Rule]** When the **uv_queue_work** method is called to throw a task to a JS thread for execution, add **napi_handle_scope** to manage the lifecycle of **napi_value** created by the JS callback.


The Node-API framework will not be used when the **uv_queue_work** method is called. In this case, you need to use **napi_handle_scope** to manage the lifecycle of **napi_value**.


**Example (correct)**:


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


## Object Binding

**[Rule]** If the value of the last parameter **result** is not **nullptr** in **napi_wrap()** , you need to use **napi_remove_wrap()** at a proper time to delete the created **napi_ref**.

The **napi_wrap** interface is defined as follows:

```
napi_wrap(napi_env env, napi_value js_object, void* native_object, napi_finalize finalize_cb, void* finalize_hint, napi_ref* result)
```

When the last parameter **result** is not empty, the framework creates an **napi_ref** object pointing to **js_object**. You need to manage the lifecycle of **js_object**. Specifically, you need to use **napi_remove_wrap** to delete **napi_ref** at a proper time so that GC can release **js_object** and trigger the destructor **finalize_cb** bound to the C++ object **native_object**.

Generally, the last parameter **result** can directly pass in **nullptr** based on service requirements.

**Example (correct)**:

```
// Usage 1: Pass in nullptr via the last parameter in napi_wrap. In this case, the created napi_ref is a weak reference, which is managed by the system and does not need manual release.
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// Usage 2: The last parameter in napi_wrap is not nullptr. In this case, the returned napi_ref is a strong reference and needs to be manually released. Otherwise, memory leakage may occur.
napi_ref result; 
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// When js_object and result are no longer used, call napi_remove_wrap to release result.
napi_value result1; 
napi_remove_wrap(env, jsobject, result1);
```


## Others

**[Rule]** The third parameter **data** in the **napi_get_arraybuffer_info** interface is not allowed to release. The lifecycle of **data** is managed by the engine.

The **napi_get_arraybuffer_info** interface is defined as follows:

```
napi_get_arraybuffer_info(napi_env env, napi_value arraybuffer, void** data, size_t* byte_length)
```

The parameter **data** specifies the buffer header pointer of ArrayBuffer. This buffer can be read and written in the given range but cannot be released. The buffer memory is managed by the ArrayBuffer Allocator in the engine and is released with the lifecycle of the JS object **ArrayBuffer**.

**Example (incorrect)**:

```
void* arrayBufferPtr = nullptr;
napi_value arrayBuffer = nullptr;
size_t createBufferSize = ARRAY_BUFFER_SIZE;
napi_status verification = napi_create_arraybuffer(env, createBufferSize, &arrayBufferPtr, &arrayBuffer);
size_t arrayBufferSize;
napi_status result = napi_get_arraybuffer_info(env, arrayBuffer, &arrayBufferPtr, &arrayBufferSize);
delete arrayBufferPtr; // This operation is not allowed. The lifecycle of the created arrayBufferPtr is managed by the engine and cannot be manually deleted. Deleting arrayBufferPtr may cause a double free of the buffer.
```

**[Suggestion]** Properly use **napi_object_freeze** and **napi_object_seal**.

**napi_object_freeze** is equivalent to **Object.freeze**. After an object is frozen, all its attributes are immutable. **napi_object_seal** is equivalent to **Object.seal**. After an object is sealed, no attributes can be added or deleted, but the attribute values are mutable.

Ensure that you know the difference between the preceding semantics. If the semantics are violated in strict mode (default), an error will be thrown.
