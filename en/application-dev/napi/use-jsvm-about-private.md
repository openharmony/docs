# Setting the private Property Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to set a private property for an object.

## Basic Concepts

In JSVM-API, you can create private keys, use the keys to create and delete properties of objects, and persist private key symbols.

## Available APIs

| API                                   | Description                      |
|----------------------------------------|--------------------------------|
| OH_JSVM_CreateDataReference            | Creates a reference to a **JSVM_Data** instance. |
| OH_JSVM_GetReferenceData               | Obtains the **JSVM_Data** value from a reference. |
| OH_JSVM_CreatePrivate                  | Creates a JS private key object.  |
| OH_JSVM_SetPrivate                     | Sets a private property for a passed-in object.  |
| OH_JSVM_GetPrivate                     | Obtains the private property of an object based on the private key.  |
| OH_JSVM_DeletePrivate                  | Deletes the private property of an object based on the private key.  |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in manipulating private properties.

### Creating a private Key, adding a private Property, and Deleting the Property

CPP Code

```cpp
static JSVM_Value privateTest(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    JSVM_HandleScope outerScope;
    OH_JSVM_GetVM(env, &vm);
    OH_JSVM_OpenHandleScope(env, &outerScope);

    JSVM_HandleScope handleScope;
    JSVM_Data privateKey;
    JSVM_Value object;
    JSVM_Value property;
    JSVM_Ref privateRef;
    {
        OH_JSVM_OpenHandleScope(env, &handleScope);
        OH_JSVM_CreateObject(env, &object);
        OH_JSVM_CreatePrivate(env, nullptr, &privateKey);
        OH_JSVM_CreateInt32(env, 1, &property);
        OH_JSVM_SetPrivate(env, object, privateKey, property);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        int propertyValue = 0;
        OH_JSVM_GetValueInt32(env, property, &propertyValue);
        OH_LOG_INFO(LOG_APP, "private property set: %{public}d\n", propertyValue);
        OH_JSVM_DeletePrivate(env, object, privateKey);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        bool isUndefined = false;
        OH_JSVM_IsUndefined(env, property, &isUndefined);
        OH_LOG_INFO(LOG_APP, "private property deleted is undefined: %{public}d\n", isUndefined);
        OH_JSVM_CreateDataReference(env, privateKey, 1, &privateRef);
        OH_JSVM_CloseHandleScope(env, handleScope);
    }
    {
        OH_JSVM_OpenHandleScope(env, &handleScope);
        OH_JSVM_GetReferenceData(env, privateRef, &privateKey);
        OH_JSVM_CreateObject(env, &object);
        OH_JSVM_CreateInt32(env, 2, &property);
        OH_JSVM_SetPrivate(env, object, privateKey, property);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        int propertyValue = 0;
        OH_JSVM_GetValueInt32(env, property, &propertyValue);
        OH_LOG_INFO(LOG_APP, "second private property set: %{public}d\n", propertyValue);
        OH_JSVM_CloseHandleScope(env, handleScope);
    }

    OH_JSVM_CloseHandleScope(env, outerScope);
    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = privateTest},
};

static JSVM_CallbackStruct *method = param;

// Alias for the wrapperObject method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"privateTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(privateTest();)JS";
```

## Expected Result
```
private property set: 1
private property deleted is undefined: 1
second private property set: 2
```
