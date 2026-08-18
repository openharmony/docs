# Performing Lifecycle Management Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=f34ddda28f1bcebae0ddfbd293a9ffe8cb2789f9 translatedAt=2026-08-12T06:35:57.861Z pushedAt=2026-08-12T11:03:22.503Z -->

## Introduction

In JSVM-API, **JSVM_Value** is an abstract data type that represents a JavaScript (JS) value of any type, which includes the basic type (such as number, string, or Boolean) and the composite type (such as array, function, or object).

The **JSVM_Value** lifecycle is related to the lifecycle of the JS value. After the JS value is garbage collected, the **JSVM_Value** is no longer valid. Do not use **JSVM_Value** when the JS value does not exist.

Scope is used to manage the **JSVM_Value** lifecycle in the framework layer. You can use **OH_JSVM_OpenHandleScope** to create a scope and use **OH_JSVM_CloseHandleScope** to destroy a scope. By creating a **JSVM_Value** in a scope, you can ensure that the **JSVM_Value** is automatically released when the scope ends. This helps prevent memory leaks.

**JSVM_Ref** is a JSVM-API data type used to manage the **JSVM_Value** lifecycle. It allows reference to a **JSVM_Value** during its lifecycle, even if the value is beyond its original context. The reference allows a **JSVM_Value** to be shared in different contexts and released in a timely manner.

You are advised to properly use **OH_JSVM_OpenHandleScope** and **OH_JSVM_CloseHandleScope** to manage the lifecycle of **JSVM_Value** instances, avoiding memory leaks.

Each **JSVM_Value** belongs to a specific **HandleScope** instance, which is created by **OH_JSVM_OpenHandleScope** and closed by **OH_JSVM_CloseHandleScope**. After a **HandleScope** instance is closed, the corresponding **JSVM_Value** will be automatically released.

## Basic Concepts

JSVM-API provides APIs for creating and manipulating JS objects, managing references to and lifecycle of the JS objects, and registering garbage collection (GC) callbacks in C/C++. Before you get started, you need to understand the following concepts:

- Scope: used to ensure that the objects created within a certain scope remain active and are properly cleared when no longer required. JSVM-API provides APIs for creating and closing normal and escapable scopes.

- Reference management: JSVM-API provides APIs for creating, deleting, and managing object references to extend the object lifecycle and prevent memory leaks when objects are used.

- Escapable scope: used to return the values created within the **escapable_handle_scope** to a parent scope. It is created by **OH_JSVM_OpenEscapableHandleScope** and closed by **OH_JSVM_CloseEscapableHandleScope**.

- GC callback: You can register GC callbacks to perform specific cleanup operations when JS objects are garbage-collected.

Understanding these concepts helps you securely and effectively manipulate JavaScript objects and manage object lifecycles.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_OpenHandleScope     | Opens a handle scope. **JSVM_Value** within the scope will not be garbage-collected.|
| OH_JSVM_CloseHandleScope    | Closes a handle scope.|
| OH_JSVM_OpenEscapableHandleScope     | Opens an escapable handle scope. Before this scope is closed, the object created within the scope has the same lifecycle as its parent scope.|
| OH_JSVM_CloseEscapableHandleScope    | Closes an escapable handle scope.|
| OH_JSVM_EscapeHandle         | Promotes a handle to a JS object so that it is valid for the lifetime of the outer scope.|
| OH_JSVM_CreateReference      | Creates a reference with the specified reference count to the value passed in. The reference allows objects to be used and shared in different contexts and helps effective track of the object lifecycle.|
| OH_JSVM_DeleteReference      | Deletes the reference created by **OH_JSVM_CreateReference**. This allows objects to be correctly released and reclaimed when they are no longer required, avoiding memory leaks.|
| OH_JSVM_ReferenceRef         | Increments the reference count of the reference created by **OH_JSVM_CreateReference** so that the object referenced will not be released.|
| OH_JSVM_ReferenceUnref       | Decrements the reference count of the reference created by **OH_JSVM_CreateReference** so that the object can be correctly released and reclaimed when it is not referenced.|
| OH_JSVM_GetReferenceValue   | Obtains the object referenced by **OH_JSVM_CreateReference**.|
| OH_JSVM_AddFinalizer          | Adds a **JSVM_Finalize** callback to a JS object. The callback will be invoked to release the native object when the JS object is garbage-collected.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in the related APIs.

### OH_JSVM_OpenHandleScope and OH_JSVM_CloseHandleScope

Call **OH_JSVM_OpenHandleScope** to create a context and call **OH_JSVM_CloseHandleScope** to close the context. Properly managing JS handle scopes can prevent GC problems.

CPP code:

<!-- @[oh_jsvm_open_handle_scope_and_oh_jsvm_close_handle_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/openhandlescope/src/main/cpp/hello.cpp) -->

``` C++
// Three sample methods for OH_JSVM_OpenHandleScope and OH_JSVM_CloseHandleScope
static JSVM_Value HandleScopeFor(JSVM_Env env, JSVM_CallbackInfo info)
{
    // When frequently calling JSVM APIs to create JS objects in a for loop, add a handle_scope to release resources that are no longer used in a timely manner.
    // In the following example, the lifecycle of the local variable res ends after each loop iteration, so a scope is added to release the JS objects it holds in a timely manner to prevent memory leaks.
    constexpr uint32_t DIFF_VALUE_HUNDRED_THOUSAND = 10000;
    JSVM_Value checked = nullptr;
    for (int i = 0; i < DIFF_VALUE_HUNDRED_THOUSAND; i++) {
        JSVM_HandleScope scope = nullptr;
        JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
        if (status != JSVM_OK || scope == nullptr) {
            OH_JSVM_GetBoolean(env, false, &checked);
            OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
            return checked;
        }
        JSVM_Value res = nullptr;
        OH_JSVM_CreateObject(env, &res);
        status = OH_JSVM_CloseHandleScope(env, scope);
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        }
    }
    OH_JSVM_GetBoolean(env, true, &checked);
    OH_LOG_INFO(LOG_APP, "JSVM HandleScopeFor: success");
    return checked;
}

// Register callback for HandleScopeFor
static JSVM_CallbackStruct param[] = {
    {.callback = HandleScopeFor, .data = nullptr},
};

static JSVM_CallbackStruct *method = param;
// Alias for the HandleScopeFor method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"HandleScopeFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *SRC_CALL_NATIVE = "HandleScopeFor()";
```

Expected result:

```txt
JSVM HandleScopeFor: success
```

### OH_JSVM_OpenEscapableHandleScope, OH_JSVM_CloseEscapableHandleScope, and OH_JSVM_EscapeHandle

Call **OH_JSVM_OpenEscapableHandleScope** to create an escapable handle scope, which allows the declared values in a scope to be returned to its parent scope. <br>Call **OH_JSVM_CloseEscapableHandleScope** to close the created scope. Call **OH_JSVM_EscapeHandle** to promote the lifecycle of the passed-in JS object to its parent scope.

These APIs are helpful for managing JS objects more flexibly in C/C++, especially when passing cross-scope values.

CPP code:

<!-- @[oh_jsvm_open_escapable_handle_scope_close_escapable_handle_scope_escape_handle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/openescapablehandlescope/src/main/cpp/hello.cpp) -->

``` C++
// Sample methods for OH_JSVM_OpenEscapableHandleScope, OH_JSVM_CloseEscapableHandleScope, and OH_JSVM_EscapeHandle
static JSVM_Value EscapableHandleScopeTest(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create an escapable handle scope
    JSVM_EscapableHandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenEscapableHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenEscapableHandleScope: failed");
        return nullptr;
    }
    // Create an obj within the escapable handle scope
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    // Add a property to the object
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "Test jsvm_escapable_handle_scope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Call OH_JSVM_EscapeHandle to escape the object out of the scope
    JSVM_Value escapedObj = nullptr;
    OH_JSVM_EscapeHandle(env, scope, obj, &escapedObj);
    // Close the escapable handle scope and clean up resources
    status = OH_JSVM_CloseEscapableHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseEscapableHandleScope: failed");
        return nullptr;
    }
    // At this point, escapedObj has escaped and can continue to be used outside the scope
    bool result = false;
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, escapedObj, value, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "JSVM EscapableHandleScopeTest: success");
    }
    return escapedObj;
}

// Register callback for EscapableHandleScopeTest
static JSVM_CallbackStruct param[] = {
    {.callback = EscapableHandleScopeTest, .data = nullptr},
};
static JSVM_CallbackStruct *method = param;
// Alias for the EscapableHandleScopeTest method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"escapableHandleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *SRC_CALL_NATIVE = "escapableHandleScopeTest()";
```

Expected result:

```txt
JSVM EscapableHandleScopeTest: success
```

### OH_JSVM_CreateReference, OH_JSVM_DeleteReference, and OH_JSVM_GetReferenceValue

1. Call **OH_JSVM_CreateReference** to create a reference for a JS variable to extend its lifecycle.

2. Call **OH_JSVM_GetReferenceValue** to obtain the JS variable associated with the reference.

3. Call **OH_JSVM_DeleteReference** to delete the reference.

The caller must manage the reference lifecycle. During the reference validity period, the JS variable will not be garbage-collected.

### OH_JSVM_ReferenceRef and OH_JSVM_ReferenceUnref

Call **OH_JSVM_ReferenceRef** to increment the reference count of a reference and call **OH_JSVM_ReferenceUnref** to decrement the reference count of a reference, and return the new count value. When the reference count is **0**, the reference will be set as a weak reference for the JS types that can be set as weak references (objects, functions, and external variables). The associated variable will be garbage-collected when the GC mechanism deems it necessary. After the variable is garbage-collected, calling **OH_JSVM_GetReferenceValue** will return C **NULL**. For JS types that cannot be set as weak references, the reference will be cleared and calling **OH_JSVM_GetReferenceValue** will return C **NULL**.

CPP code:

<!-- @[oh_jsvm_reference_ref_and_oh_jsvm_reference_unref](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/referenceref/src/main/cpp/hello.cpp) -->

``` C++
static JSVM_Value UseReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create a JavaScript object
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "UseReference", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);

    JSVM_Ref g_ref = nullptr;
    // Create a reference to the JavaScript object
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        return nullptr;
    }

    // Increment the reference count of the passed-in reference and return the resulting reference count
    uint32_t result = 0;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    const int resultValue = 2;
    if (result != resultValue) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }

    // Decrement the reference count of the passed-in reference and return the resulting reference count
    uint32_t num = 0;
    OH_JSVM_ReferenceUnref(env, g_ref, &num);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceUnref, count = %{public}d.", num);
    if (num != 1) {
        return nullptr;
    }

    JSVM_Value object = nullptr;
    // Obtain the referenced JavaScript object by calling OH_JSVM_GetReferenceValue
    status = OH_JSVM_GetReferenceValue(env, g_ref, &object);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetReferenceValue: failed");
        return nullptr;
    }

    // When the reference is no longer needed, delete the reference to the JavaScript object by calling OH_JSVM_DeleteReference
    status = OH_JSVM_DeleteReference(env, g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_DeleteReference: failed");
        return nullptr;
    }

    // Return the obtained object
    OH_LOG_INFO(LOG_APP, "JSVM UseReference success");
    return object;
}

// Register callbacks for CreateReference, UseReference, and DeleteReference
static JSVM_CallbackStruct param[] = {
    {.callback = UseReference, .data = nullptr},
};
static JSVM_CallbackStruct *method = param;
// Aliases for the CreateReference, UseReference, and DeleteReference methods, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"useReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *SRC_CALL_NATIVE = "useReference()";
```

Expected result:

```txt
JSVM OH_JSVM_ReferenceRef, count = 2.
JSVM OH_JSVM_ReferenceUnref, count = 1.
JSVM UseReference success
```

### OH_JSVM_AddFinalizer

Call **OH_JSVM_AddFinalizer** to add the **JSVM_Finalize** callback to a JS object. The callback will be invoked when the JS object is garbage-collected. **OH_JSVM_AddFinalizer** is usually used to release the native object associated with a JS object. If the input parameter is not a JS object, the call will fail and return an error code.

The Finalizer method cannot be canceled after being registered. If it is not executed before **OH_JSVM_DestroyEnv** is called, it will be executed when **OH_JSVM_DestroyEnv** is called.

CPP code:

<!-- @[oh_jsvm_add_finalizer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/addfinalizer/src/main/cpp/hello.cpp) -->

``` C++
static int AddFinalizer(JSVM_VM vm, JSVM_Env env)
{
    // Open a handle scope
    JSVM_HandleScope handleScope;
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));
    // Create an object and set the callback
    JSVM_Value obj = nullptr;
    CHECK_RET(OH_JSVM_CreateObject(env, &obj));
    CHECK_RET(OH_JSVM_AddFinalizer(
        env, obj, nullptr,
        [](JSVM_Env env, void *data, void *hint) -> void {
            // Finalizer method, in which native objects can be cleaned up
            OH_LOG_INFO(LOG_APP, "JSVM: finalizer called.");
        },
        nullptr, nullptr));
    OH_LOG_INFO(LOG_APP, "JSVM: finalizer added.");
    // Close the handle scope to trigger GC, during which the finalizer is called
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    OH_LOG_INFO(LOG_APP, "JSVM: before call gc.");
    CHECK_RET(OH_JSVM_MemoryPressureNotification(env, JSVM_MemoryPressureLevel::JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL));
    OH_LOG_INFO(LOG_APP, "JSVM: after call gc.");

    return 0;
}

static JSVM_Value RunDemo(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);
    if (AddFinalizer(vm, env) != 0) {
        OH_LOG_INFO(LOG_APP, "Run AddFinalizer failed");
    }

    return nullptr;
}

// Register callback for RunDemo
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = RunDemo},
};
static JSVM_CallbackStruct *method = param;
// Alias for the RunDemo method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"RunDemo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(RunDemo();)JS";
```

Expected result:

```ts
JSVM: finalizer added.
JSVM: before call gc.
JSVM: finalizer called.
JSVM: after call gc.
```