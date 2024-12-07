# Performing Lifecycle Management Using JSVM-API

## Introduction

In JSVM-API, **JSVM_Value** is an abstract data type that represents a JavaScript (JS) value of any type, which includes the basic type (such as number, string, or Boolean) and the composite type (such as array, function, or object).
The **JSVM_Value** lifecycle is closely related to the lifecycle of the JS value. When a JS value is garbage-collected, the **JSVM_Value** associated with it is no longer valid. Avoid using the **JSVM_Value** when the JS value no longer exists.

Scope is used to manage the **JSVM_Value** lifecycle in the framework layer. You can use **OH_JSVM_OpenHandleScope** to create a scope and use **OH_JSVM_CloseHandleScope** to destroy a scope. By creating a **JSVM_Value** in a scope, you can ensure that the **JSVM_Value** is automatically released when the scope ends. This helps prevent memory leaks.

**JSVM_Ref** is a JSVM-API data type used to manage the **JSVM_Value** lifecycle. It allows reference to a **JSVM_Value** during its lifecycle, even if the value is beyond its original context. The reference allows a **JSVM_Value** to be shared in different contexts and released in a timely manner.

Properly using **OH_JSVM_OpenHandleScope** and **OH_JSVM_CloseHandleScope** can minimize the **JSVM_Value** lifecycle and prevent memory leaks.

Each **JSVM_Value** belongs to a specific **HandleScope** instance, which is created by **OH_JSVM_OpenHandleScope** and closed by **OH_JSVM_CloseHandleScope**. After a **HandleScope** instance is closed, the corresponding **JSVM_Value** will be automatically released.

## Basic Concepts

JSVM-API provides APIs for creating and manipulating JS objects, managing references to and lifecycle of the JS objects, and registering garbage collection (GC) callbacks in C/C++. Before you get started, you need to understand the following concepts:

- Scope: used to ensure that the objects created within a certain scope remain active and are properly cleared when no longer required. JSVM-API provides APIs for creating and closing normal and escapeable scopes.
- Reference management: JSVM-API provides APIs for creating, deleting, and managing object references to extend the object lifecycle and prevent memory leaks when objects are used.
- Escapeable scope: used to return the values created within the **escapable_handle_scope** to a parent scope. It is created by **OH_JSVM_OpenEscapableHandleScope** and closed by **OH_JSVM_CloseEscapableHandleScope**.
- GC callback: You can register GC callbacks to perform specific cleanup operations when JS objects are garbage-collected.

Understanding these concepts helps you securely and effectively manipulate JS objects in C/C++ and perform object lifecycle management.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_OpenHandleScope     | Opens a handle scope. **JSVM_Value** within the scope will not be garbage-collected.|
| OH_JSVM_CloseHandleScope    | Closes a handle scope.|
| OH_JSVM_OpenEscapableHandleScope     | Opens an escapable handle scope. Before this scope is closed, the object created within the scope has the same lifecycle as its parent scope.|
| OH_JSVM_CloseEscapableHandleScope    | Closes an escapable handle scope.|
| OH_JSVM_EscapeHandle         | Promotes a handle to a JS object so that it is valid for the lifetime of the outer scope.|
| OH_JSVM_CreateReference      | Creates a reference with the specified reference count to the value passed in. The reference allows objects to be used and shared in different contexts and helps effective track of the object lifecycle.|
| OH_JSVM_DeleteReference      | Releases the reference created by **OH_JSVM_CreateReference**. This allows objects to be correctly released and reclaimed when they are no longer required, avoiding memory leaks.|
| OH_JSVM_ReferenceRef         | Increments the reference count of the reference created by **OH_JSVM_CreateReference** so that the object referenced will not be released.|
| OH_JSVM_ReferenceUnref       | Decrements the reference count of the reference created by **OH_JSVM_CreateReference** so that the object can be correctly released and reclaimed when it is not referenced.|
| OH_JSVM_GetReferenceValue   | Obtains the object referenced by **OH_JSVM_CreateReference**. |
| OH_JSVM_AddFinalizer          | Adds a **JSVM_Finalize** callback to a JS object. The callback will be invoked to release the native object when the JS object is garbage-collected.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to lifecycle management APIs.

### OH_JSVM_OpenHandleScope, OH_JSVM_CloseHandleScope

Use **OH_JSVM_OpenHandleScope** to open a handle scope. Use **OH_JSVM_CloseHandleScope** to close a handle scope. Properly managing JS handle scopes can prevent GC problems.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the HandleScopeTest, HandleScope, and HandleScopeFor callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HandleScopeTest},
    {.data = nullptr, .callback = HandleScope},
    {.data = nullptr, .callback = HandleScopeFor},
};
static JSVM_CallbackStruct *method = param;
// Expose the HandleScopeTest, HandleScope, and HandleScopeFor callbacks to JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"handleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"handleScope", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"handleScopeFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static int DIFF_VALUE_HUNDRED_THOUSAND = 100000;
// Define OH_JSVM_OpenHandleScope and OH_JSVM_CloseHandleScope.
static JSVM_Value HandleScopeFor(JSVM_Env env, JSVM_CallbackInfo info)
{
    // When JSVM-API is frequently called to create JS objects in the for loop, use handle_scope to release resources in a timely manner when they are no longer required.
    // In the following example, the lifecycle of the local variable res ends at the end of each loop. To prevent memory leaks, scope is used to release the JS object in a timely manner.
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

static JSVM_Value HandleScopeTest(JSVM_Env env, JSVM_CallbackInfo info)
{
    // NOTE
    // In the following code, obj is created within the handle scope, which is later closed by OH_JSVM_OpenHandleScope.
    // After the handle scope is closed, results can still be returned normally
    // because the results are returned as the return values of functions,
    // instead of using obj outside the handle scope.
    // Call OH_JSVM_OpenHandleScope to create a handle scope.
    JSVM_HandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
        return nullptr;
    }
    // Create an object within the handle scope.
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    // Add properties to the object.
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "test handleScope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Close the handle scope. Then, the object handles created within the scope are automatically released.
    status = OH_JSVM_CloseHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "JSVM HandleScopeTest: success");
    return obj;
}

static JSVM_Value HandleScope(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Call OH_JSVM_OpenHandleScope to create a handle scope.
    JSVM_HandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
        return nullptr;
    }
    // Create an object within the handle scope.
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    // Add properties to the object.
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "handleScope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Close the handle scope. Then, the object handles created within the scope are automatically released.
    status = OH_JSVM_CloseHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        return nullptr;
    }
    // After the handle scope is closed, add properties to the object. The previously set property 'name' becomes invalid.
    OH_JSVM_CreateStringUtf8(env, "001", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "id", value);
    // The property 'name' is invalid.
    bool result = true;
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, obj, value, &result);
    if (!result) {
        OH_LOG_INFO(LOG_APP, "JSVM HandleScope: success");
    }
    return obj;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `handleScopeTest()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScopeTest: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScopeTest error: %{public}s', error.message);
}
try {
  let script: string = `handleScope()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScope: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScope error: %{public}s', error.message);
}
try {
  let script: string = `handleScopeFor()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScopeFor: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScopeFor error: %{public}s', error.message);
}
```

### OH_JSVM_OpenEscapableHandleScope, OH_JSVM_CloseEscapableHandleScope, OH_JSVM_EscapeHandle

Use **OH_JSVM_OpenEscapableHandleScope** to create an escapeable handle scope, which allows the declared values in the scope to be returned to the parent scope. Use **OH_JSVM_CloseEscapableHandleScope** to close an escapeable handle scope. Use **OH_JSVM_EscapeHandle** to promote the lifecycle of a JS object so that it is valid for the lifetime of the outer scope.
These APIs are helpful for managing ArkTS objects more flexibly in C/C++, especially when passing cross-scope values.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define the EscapableHandleScopeTest callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = EscapableHandleScopeTest},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named escapableHandleScopeTest and associate it with a callback. This allows the EscapableHandleScopeTest callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"escapableHandleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_OpenEscapableHandleScope, OH_JSVM_CloseEscapableHandleScope, and OH_JSVM_EscapeHandle.
static JSVM_Value EscapableHandleScopeTest(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create an escapeable handle scope.
    JSVM_EscapableHandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenEscapableHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenEscapableHandleScope: failed");
        return nullptr;
    }
    // Create an object within the scope of the escapeable handle.
    JSVM_Value obj;
    OH_JSVM_CreateObject(env, &obj);
    // Add properties to the object.
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "Test jsvm_escapable_handle_scope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Call OH_JSVM_EscapeHandle to promote the JS object handle to make it valid with the lifetime of the outer scope.
    JSVM_Value escapedObj = nullptr;
    OH_JSVM_EscapeHandle(env, scope, obj, &escapedObj);
    // Close the escapeable handle scope to clear resources.
    status = OH_JSVM_CloseEscapableHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseEscapableHandleScope: failed");
        return nullptr;
    }
    // Use escapedObj outside the scope. Since escapedObj has escaped, the property can be set successfully and obtained from ArkTs.
    OH_JSVM_CreateStringUtf8(env, "001", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "id", value);
    bool result = false;
    OH_JSVM_CreateStringUtf8(env, "id", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, obj, value, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "JSVM EscapableHandleScopeTest: success");
    }
    return escapedObj;
}
```

 

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `escapableHandleScopeTest()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM escapableHandleScopeTest: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM escapableHandleScopeTest error: %{public}s', error.message);
}
```

### OH_JSVM_CreateReference, OH_JSVM_DeleteReference

Use **OH_JSVM_CreateReference** to create a reference for an object to extend its lifespan. The caller needs to manage the reference lifespan. Use **OH_JSVM_DeleteReference** to delete a reference.

### OH_JSVM_ReferenceRef, OH_JSVM_ReferenceUnref

Use **OH_JSVM_ReferenceRef** to increment the reference count of a reference and use **OH_JSVM_ReferenceUnref** to decrement the reference count of a reference, and return the new count value.

### OH_JSVM_GetReferenceValue

Use **OH_JSVM_GetReferenceValue** to obtain the JS object associated with the reference.

### OH_JSVM_AddFinalizer

Use **OH_JSVM_AddFinalizer** to add a **JSVM_Finalize** callback, which will be called when the JS object is garbage-collected.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateReference, UseReference, and DeleteReference callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateReference},
    {.data = nullptr, .callback = UseReference},
    {.data = nullptr, .callback = DeleteReference},
};
static JSVM_CallbackStruct *method = param;
// Expose the CreateReference, UseReference, and DeleteReference callbacks to JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"useReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"deleteReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateReference and OH_JSVM_AddFinalizer.
static JSVM_Value CreateReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "CreateReference", JSVM_AUTO_LENGTH, &value);
    // Add a property to the object.
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Create a reference to the JS object.
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateReference: failed");
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // Increment the reference count and return the new reference count.
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "JSVM CreateReference success");
    return obj;
}
// Define OH_JSVM_ReferenceRef and OH_JSVM_GetReferenceValue.
static JSVM_Value UseReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "UseReference", JSVM_AUTO_LENGTH, &value);
    // Add a property to the object.
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Create a reference to the JS object.
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // Increment the reference count and return the new reference count.
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }
    JSVM_Value object = nullptr;
    // Call OH_JSVM_GetReferenceValue to obtain the referenced JS object.
    status = OH_JSVM_GetReferenceValue(env, g_ref, &object);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetReferenceValue: failed");
        return nullptr;
    }
    // Return the obtained object.
    OH_LOG_INFO(LOG_APP, "JSVM UseReference success");
    return object;
}
// Define OH_JSVM_ReferenceUnref and OH_JSVM_DeleteReference.
static JSVM_Value DeleteReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "DeleteReference", JSVM_AUTO_LENGTH, &value);
    // Add a property to the object.
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // Create a reference to the JS object.
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateReference: failed");
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // Increment the reference count and return the new reference count.
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        return nullptr;
    }
    // Decrement the reference count and return the new reference count.
    uint32_t num;
    OH_JSVM_ReferenceUnref(env, g_ref, &num);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceUnref, count = %{public}d.", num);
    if (num != 1) {
        return nullptr;
    }
    // Call OH_JSVM_DeleteReference to delete the reference to the JS object.
    status = OH_JSVM_DeleteReference(env, g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_DeleteReference: failed");
        return nullptr;
    }
    JSVM_Value returnResult = nullptr;
    OH_JSVM_CreateStringUtf8(env, "OH_JSVM_DeleteReference success", JSVM_AUTO_LENGTH, &returnResult);
    OH_LOG_INFO(LOG_APP, "JSVM DeleteReference success");
    return returnResult;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `createReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createReference error: %{public}s', error.message);
}
try {
  let script: string = `useReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM useReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM useReference error: %{public}s', error.message);
}
try {
  let script: string = `deleteReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM deleteReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM deleteReference error: %{public}s', error.message);
}
```
