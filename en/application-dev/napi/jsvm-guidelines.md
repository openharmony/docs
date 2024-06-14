# JSVM-API Development Specifications

## Lifecycle Management

**[Rule]** Properly use **OH_JSVM_OpenHandleScope** and **OH_JSVM_CloseHandleScope** to minimize the lifecycle of **JSVM_Value** and avoid memory leaks.

Each **JSVM_Value** belongs to a specific **HandleScope** instance, which is created by **OH_JSVM_OpenHandleScope** and closed by **OH_JSVM_CloseHandleScope**. After a **HandleScope** instance is closed, the corresponding **JSVM_Value** will be automatically released.

**Example (correct)**

```c++
// When JSVM-API is frequently called to create JS objects in the for loop, use handle_scope to release resources in a timely manner when they are no longer used.
// In the following example, the lifecycle of the local variable res ends at the end of each loop. To prevent memory leaks, scope is used to release the JS object in a timely manner.
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

## Context Sensitive

**[Rule]** Do not use JSVM-API to access JS objects across engine instances.

An engine instance is an independent running environment. Operations such as creating and accessing a JS object must be performed in the same engine instance. If an object is operated in different engine instances, the application may crash. An engine instance is represented as a value of **JSVM_Env** in APIs.

**Example (incorrect)**

```c++
// Create a string object with value of "bar" in env1.
OH_JSVM_CreateStringUtf8(env1, "value1", JSVM_AUTO_LENGTH , &string);
// Create an object in env2 and set the string object to this object.
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

JS objects belong to a specific **JSVM_Env**. Therefore, you cannot set an object of env1 to an object of env2. If the object of env1 is accessed in env2, the application may crash.

## Exception Handling

**[Suggestion]** Any exception occurred in a JSVM-API call should be handled in a timely manner. Otherwise, unexpected behavior may occur.

**Example (correct)**

```c++
// 1. Create an object.
JSVM_Status status = OH_JSVM_CreateObject(env, &object);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
} 
// 2. Create a property.
status = OH_JSVM_CreateStringUtf8(env, "bar", JSVM_AUTO_LENGTH, &string);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
} 
// 3. Set the result of step 2 to the value of the object property foo.
status = OH_JSVM_SetNamedProperty(env, object, "foo", string);
if (status != JSVM_OK)
{ 
    OH_JSVM_ThrowError(env, ...);
    return;
}
```

In this example, if an exception occurs in step 1 or step 2, step 3 will not be performed. Step 3 will be performed only when JSVM_OK is returned in steps 1 and 2.

## Object Wrapping

**[Rule]** If the value of the last parameter **result** is not **nullptr** in **OH_JSVM_Wrap()** , use **OH_JSVM_RemoveWrap** at a proper time to remove the created **JSVM_Ref**.

The **OH_JSVM_Wrap** API is defined as follows:

```c++
JSVM_EXTERN JSVM_Status OH_JSVM_Wrap(JSVM_Env env,
                                     JSVM_Value jsObject,
                                     void* nativeObject,
                                     JSVM_Finalize finalizeCb,
                                     void* finalizeHint,
                                     JSVM_Ref* result);
```

When the last parameter **result** is not null, the JSVM-API framework creates a **JSVM_Ref** object pointing to **js_object**. You need to manage the lifecycle of **js_object**. Specifically, use **OH_JSVM_RemoveWrap** to remove **JSVM_Ref** at a proper time so that the garbage collector (GC) can release **js_object** and trigger the destructor **finalizeCb** bound to the C++ object **native_object**.

Generally, you can directly pass in **nullptr** for the last parameter **result**.

**Example (correct)**

```c++
// Case 1: Pass in nullptr via the last parameter in OH_JSVM_Wrap. In this case, the created JSVM_Ref is a weak reference, which is managed by the system and does not need manual release.
OH_JSVM_Wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// Case 2: The last parameter in OH_JSVM_Wrap is not nullptr. In this case, the returned JSVM_Ref is a strong reference and needs to be manually released. Otherwise, a memory leak may occur.
JSVM_Ref result;
OH_JSVM_Wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// When js_object and result are no longer used, call OH_JSVM_RemoveWrap to release result.
JSVM_Value result1;
OH_JSVM_RemoveWrap(env, jsobject, result1);
```
