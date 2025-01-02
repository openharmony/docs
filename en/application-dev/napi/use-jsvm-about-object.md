# Working with Objects Using JSVM-API

## Overview

JSVM-API provides APIs for basic JavaScript (JS) object operations, including creating an object, obtaining the prototype of an object, freezing or sealing an object, and checking the object type. You can use these APIs to manage JS objects.

## Basic Concepts

You may need to define and operate objects when using JSVM-API in development. For example, define an API with an object as an input parameter, perform operations on the object, and have a result object returned. In this process, you need to ensure that the API definition is clear and compatible with the properties and methods of the object.

- API: defines the interaction protocol between components. An API includes input parameters, output result, and possible error handling. By calling APIs, components can interact and exchange data with each other without knowing the internal implementation details.
- Object: a composite data type that allows values of different types to be stored as an independent entity in JS. An object is a collection of properties and methods. A property is a value associated with an object, and a method is an operation that the object can perform.

## Available APIs

| API                      | Description                                    |
| -------------------------- | -------------------------------------------- |
| OH_JSVM_GetPrototype         | Obtains the prototype of a JS object.            |
| OH_JSVM_CreateObject         | Creates a default JS object.                  |
| OH_JSVM_ObjectFreeze         | Freezes a JS object. Once a JS object is frozen, new properties cannot be added to it, existing properties cannot be removed, the enumerability, configurability, or writability of existing properties cannot be changed, and the values of existing properties cannot be changed.                            |
| OH_JSVM_ObjectSeal           |  Seals a JS object. Once a JS object is sealed, new properties cannot be added to it and all existing properties are marked as unconfigurable.                            |
| OH_JSVM_Typeof                | Returns the type of a JS object. |
| OH_JSVM_Instanceof            | Checks whether an object is an instance of a constructor.   |
| OH_JSVM_TypeTagObject       | Associates the value of the **type_tag** pointer with a JS object or an external object.                 |
| OH_JSVM_CheckObjectTypeTag | Checks whether a tag matches the tag type of an object.|
| OH_JSVM_CreateSymbol         | Creates a symbol object based on the given descriptor.                    |
|OH_JSVM_SymbolFor | Searches for a symbol with the given key in a global (runtime-wide) symbol registry. If a match is found, the symbol will be returned. Otherwise, a symbol will be created in the registry.|
| OH_JSVM_CreateExternal       | Creates a JS object that wraps an external pointer.              |
| OH_JSVM_GetValueExternal    | Obtains the external data pointer previously passed to **OH_JSVM_CreateExternal**.                 |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following only demonstrates the C++ and ArkTS code for object management APIs.

### OH_JSVM_GetPrototype

Obtains the prototype of a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetPrototype callback.
// Define OH_JSVM_GetPrototype.
static JSVM_Value GetPrototype(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    JSVM_Value result{nullptr};
    JSVM_Status status = OH_JSVM_GetPrototype(env, argv[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetPrototype fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetPrototype success");
    }
    return result;
}
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetPrototype},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getPrototype and associate it with a callback. This allows the GetPrototype callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getPrototype", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(const myObject = {};
    const proto = getPrototype(myObject);
    console.log(proto === Object.prototype);)JS";
```

**Expected output**
```ts
JSVM GetPrototype success
```

### OH_JSVM_CreateObject

Creates a default JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CreateObject.
static JSVM_Value CreateObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value object = nullptr;
    // Create an empty object.
    JSVM_Status status = OH_JSVM_CreateObject(env, &object);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateObject fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateObject success");
    }
    // Set the object property.
    JSVM_Value name = nullptr;
    // Set the property name to "name".
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &name);
    JSVM_Value value = nullptr;
    // Set the property value to "Hello from N-API!"
    OH_JSVM_CreateStringUtf8(env, "Hello OH_JSVM_CreateObject!", JSVM_AUTO_LENGTH, &value);
    // Set the property on the object.
    OH_JSVM_SetProperty(env, object, name, value);
    return object;
}
// Register the CreateObject callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateObject},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createObject and associate it with a callback. This allows the CreateObject callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(createObject())JS";
```

**Expected output**
```ts
JSVM CreateObject success
```

### OH_JSVM_ObjectFreeze

Freezes a JS object. Once a JS object is frozen, new properties cannot be added to it, existing properties cannot be removed, the enumerability, configurability, or writability of existing properties cannot be changed, and the values of existing properties cannot be changed.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_ObjectFreeze.
static JSVM_Value ObjectFreeze(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Accept an object passed in from JS.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Call OH_JSVM_ObjectFreeze to freeze the object passed in.
    JSVM_Status status = OH_JSVM_ObjectFreeze(env, argv[0]);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectFreeze success");
    }
    // Check whether the properties of the frozen object can be modified.
    JSVM_Value value = nullptr;
    OH_JSVM_CreateInt32(env, 111111, &value);
    OH_JSVM_SetNamedProperty(env, argv[0], "data", value);
    // Return the properties modified after the freezing to JS.
    return argv[0];
}
// Register the ObjectFreeze callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ObjectFreeze},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named objectFreeze and associate it with a callback. This allows the ObjectFreeze callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"objectFreeze", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(let obj = { data: 55, message: "hello world"};
  objectFreeze(obj))JS";
```

**Expected output**
```ts
Test JSVM OH_JSVM_ObjectFreeze success
```

### OH_JSVM_ObjectSeal

Seals a JS object. Once a JS object is sealed, new properties cannot be added to it and all existing properties are marked as unconfigurable.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_ObjectSeal.
static JSVM_Value ObjectSeal(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Accept an object passed in from JS.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Call OH_JSVM_ObjectSeal to seal the object passed in.
    JSVM_Status status = OH_JSVM_ObjectSeal(env, argv[0]);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectSeal success");
    }
    // Check whether the properties of the sealed object can be modified, deleted, or added.
    // Modify a property of the sealed object.
    JSVM_Value changeValue = nullptr;
    OH_JSVM_CreateInt32(env, 111111, &changeValue);
    OH_JSVM_SetNamedProperty(env, argv[0], "data", changeValue);
    // Delete a property from the sealed object.
    JSVM_Value deleteProperty = nullptr;
    OH_JSVM_CreateStringUtf8(env, "message", JSVM_AUTO_LENGTH, &deleteProperty);
    bool result = false;
    OH_JSVM_DeleteProperty(env, argv[0], deleteProperty, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectSeal failed");
    }
    // Add a property to the sealed object.
    JSVM_Value addValue = nullptr;
    OH_JSVM_CreateStringUtf8(env, "addValue", JSVM_AUTO_LENGTH, &addValue);
    OH_JSVM_SetNamedProperty(env, argv[0], "newProperty", addValue);
    // Return the modified object to JS.
    return argv[0];
}
// Register the ObjectSeal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ObjectSeal},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named objectSeal and associate it with a callback. This allows the ObjectSeal callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"objectSeal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS( let obj = { data: 55, message: "hello world"};
  objectSeal(obj))JS";
```

**Expected output**
```ts
Test JSVM OH_JSVM_ObjectSeal success
```

### OH_JSVM_Typeof

Returns the type of a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_Typeof.
static JSVM_Value GetTypeof(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_ValueType valueType;
    OH_JSVM_Typeof(env, args[0], &valueType);
    JSVM_Value type = nullptr;
    switch (valueType) {
    case JSVM_UNDEFINED:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is undefined");
        OH_JSVM_CreateStringUtf8(env, "Input type is undefined", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_NULL:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is null");
        OH_JSVM_CreateStringUtf8(env, "Input type is null", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_BOOLEAN:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is boolean");
        OH_JSVM_CreateStringUtf8(env, "Input type is boolean", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_NUMBER:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is number");
        OH_JSVM_CreateStringUtf8(env, "Input type is number", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_STRING:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is string");
        OH_JSVM_CreateStringUtf8(env, "Input type is string", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_SYMBOL:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is symbol");
        OH_JSVM_CreateStringUtf8(env, "Input type is symbol", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_OBJECT:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is object");
        OH_JSVM_CreateStringUtf8(env, "Input type is object", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_FUNCTION:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is function");
        OH_JSVM_CreateStringUtf8(env, "Input type is function", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_EXTERNAL:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is external");
        OH_JSVM_CreateStringUtf8(env, "Input type is external", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_BIGINT:
        OH_LOG_INFO(LOG_APP, "JSVM Input type is bigint");
        OH_JSVM_CreateStringUtf8(env, "Input type is bigint", JSVM_AUTO_LENGTH, &type);
        break;
    default:
        OH_LOG_INFO(LOG_APP, "JSVM Input type does not match any");
        OH_JSVM_CreateStringUtf8(env, " ", JSVM_AUTO_LENGTH, &type);
        break;
    }
    return type;
}
// Register the GetTypeof callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetTypeof},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getTypeof and associate it with a callback. This allows the GetTypeof callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getTypeof", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(getTypeof(true);)JS";
```

**Expected output**
```ts
JSVM Input type is boolean
```

### OH_JSVM_Instanceof

Checks whether an object is an instance of a constructor.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_Instanceof.
static JSVM_Value InstanceOf(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_Instanceof(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM InstanceOf fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM InstanceOf: %{public}d", result);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
// Register the InstanceOf callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = InstanceOf},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named instanceOf and associate it with a callback. This allows the InstanceOf callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"instanceOf", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(class Person {
        name;
        age;
        constructor(name, age) {
          this.name = name;
          this.age = age;
        }
      }
     instanceOf(new Person('Alice', 30), Person);
     ;)JS";
```

**Expected output**
```ts
JSVM InstanceOf: 1
```

### OH_JSVM_TypeTagObject

Associate the value of the **type_tag** pointer with a JS object so that the object can be identified more accurately.

### OH_JSVM_CheckObjectTypeTag

Checks whether a tag matches the tag type of an object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#define NUMBERINT_FOUR 4
// Define a static constant JSVM_TypeTag array to store type tags.
static const JSVM_TypeTag TagsData[NUMBERINT_FOUR] = {
    {0x9e4b2449547061b3, 0x33999f8a6516c499},
    {0x1d55a794c53a726d, 0x43633f509f9c944e},
    {0, 0}, // Indicates the default tag or no tag.
    {0x6a971439f5b2e5d7, 0x531dc28a7e5317c0},
};
// Define OH_JSVM_TypeTagObject.
static JSVM_Value SetTypeTagToObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index number and convert it to JSVM_Value.
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    // Set the type tag for the parameter (object).
    JSVM_Status status = OH_JSVM_TypeTagObject(env, args[0], &TagsData[index]);
    // Convert the bool value to JSVM_Value and return it.
    JSVM_Value result = nullptr;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM SetTypeTagToObject fail");
        OH_JSVM_GetBoolean(env, false, &result);
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM SetTypeTagToObject success");
        OH_JSVM_GetBoolean(env, true, &result);
    }
    return result;
}
// Define OH_JSVM_CheckObjectTypeTag.
static JSVM_Value CheckObjectTypeTag(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index number and convert it to JSVM_Value.
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    // Check the type tag of the object.
    bool checkResult = false;
    JSVM_Status status = OH_JSVM_CheckObjectTypeTag(env, args[0], &TagsData[index], &checkResult);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM SetTypeTagToObject fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM SetTypeTagToObject:%{public}d", checkResult);
    }
    // Convert the bool value to JSVM_Value and return it.
    JSVM_Value checked = nullptr;
    OH_JSVM_GetBoolean(env, checkResult, &checked);
    return checked;
}
// Registers the SetTypeTagToObject and CheckObjectTypeTag callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetTypeTagToObject},
    {.data = nullptr, .callback = CheckObjectTypeTag},
};
static JSVM_CallbackStruct *method = param;
// Set property descriptors named setTypeTagToObject and CheckObjectTypeTag, and associate them with a callback each. This allows the SetTypeTagToObject and CheckObjectTypeTag callbacks to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"setTypeTagToObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"checkObjectTypeTag", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(
         class Obj {
           data;
           message;
         }
         let obj= { data: 0, message: "hello world"};
         setTypeTagToObject(obj, 0);
         checkObjectTypeTag(obj,0);)JS";
```

**Expected output**
```ts
JSVM SetTypeTagToObject success
JSVM SetTypeTagToObject:1
```

### OH_JSVM_CreateExternal

Use **OH_JSVM_CreateExternal** to create a JS object that wraps an external pointer.
**NOTE**<br>When a JS object is garbage-collected, the content pointed to by the wrapped external pointer is not directly managed by GC. Only the function corresponding to the third input parameter (if it is not nullptr) is called.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CreateExternal.
static JSVM_Value CreateExternal(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t dataSize = 10;
    void *data = malloc(dataSize);
    if (data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "JSVM Failed to malloc.");
        return nullptr;
    }
    memset(data, 0, dataSize);
    const char* testStr = "test";
    JSVM_Value external = nullptr;
    JSVM_Status status = OH_JSVM_CreateExternal(
        env, data, [](JSVM_Env env, void *data, void *hint) {free(data);}, (void *)testStr, &external);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM Failed to create external data, status:%{public}d.", status);
        free(data);
        data = nullptr;
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateExternal success");
    }
    return external;
}
// Register the CreateExternal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateExternal},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createExternal and associate it with a callback. This allows the CreateExternal callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createExternal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(createExternal())JS";
```

**Expected output**
```ts
JSVM CreateExternal success
```

### OH_JSVM_GetValueExternal

Use **OH_JSVM_CreateExternal** to create a JS object that wraps a custom C/C++ object, and use **OH_JSVM_GetValueExternal** to obtain the pointer to the external object wrapped by **OH_JSVM_CreateExternal**.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetValueExternal.
static JSVM_Value GetValueExternal(JSVM_Env env, JSVM_CallbackInfo info)
{
    static int data = 0x12345;
    JSVM_Value externalValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateExternal(env, (void*)&data, nullptr, nullptr, &externalValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateExternal fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateExternal sucess");
    }
    void *data_value;
    status = OH_JSVM_GetValueExternal(env, externalValue, &data_value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueExternal fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueExternal sucess");
    }
    // Convert the sign bit into a value of int type and pass it.
    JSVM_Value returnValue = nullptr;
    int retData = *static_cast<int *>(data_value);
    OH_JSVM_CreateInt32(env, retData, &returnValue);
    return returnValue;
}
// Register the GetValueExternal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueExternal},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueExternal and associate it with a callback. This allows the GetValueExternal callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueExternal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(getValueExternal())JS";
```

**Expected output**
```ts
JSVM OH_JSVM_CreateExternal sucess
JSVM GetValueExternal sucess
```

### OH_JSVM_CreateSymbol

Create a symbol. Symbol is a special data type used to indicate a unique identifier. Unlike strings or numbers, the value of a symbol is unique. Even if two symbols have the same description, they are not equal. Symbols are often used as keys for object properties to ensure property uniqueness.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CreateSymbol.
static JSVM_Value CreateSymbol(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value result = nullptr;
    const char *des = "only";
    OH_JSVM_CreateStringUtf8(env, des, JSVM_AUTO_LENGTH, &result);
    JSVM_Value returnSymbol = nullptr;
    OH_JSVM_CreateSymbol(env, result, &returnSymbol);
    JSVM_ValueType valuetypeSymbol;
    OH_JSVM_Typeof(env, returnSymbol, &valuetypeSymbol);
    if (valuetypeSymbol == JSVM_SYMBOL) {
        OH_LOG_INFO(LOG_APP, "JSVM CreateSymbol Success");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateSymbol fail");
    }
    return returnSymbol;
}
// Register the CreateSymbol callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateSymbol},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createSymbol and associate it with a callback. This allows the CreateSymbol callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createSymbol", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(createSymbol())JS";
```

**Expected output**
```ts
JSVM CreateSymbol Success
```

### OH_JSVM_SymbolFor

Searches for a symbol with the given key in a global (runtime-wide) symbol registry. If a match is found, the symbol will be returned. Otherwise, a symbol will be created in the registry.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define a constant to store the maximum length of a string.
static const int MAX_BUFFER_SIZE = 128;
// Define OH_JSVM_SymbolFor.
static JSVM_Value SymbolFor(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value description = nullptr;
    OH_JSVM_CreateStringUtf8(env, "test_demo", 9, &description);
    char buffer[MAX_BUFFER_SIZE];
    size_t bufferSize = MAX_BUFFER_SIZE;
    size_t copied = 0;
    OH_JSVM_GetValueStringUtf8(env, description, buffer, bufferSize, &copied);
    JSVM_Value symbol = nullptr;
    OH_JSVM_CreateSymbol(env, description, &symbol);
    JSVM_Value result_symbol = nullptr;
    JSVM_Status status = OH_JSVM_SymbolFor(env, buffer, copied, &result_symbol);
    JSVM_ValueType valuetypeSymbol;
    OH_JSVM_Typeof(env, result_symbol, &valuetypeSymbol);
    if (valuetypeSymbol == JSVM_SYMBOL && status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SymbolFor success");
    }
    // Return the result.
    return result_symbol;
}
// Register the SymbolFor callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SymbolFor},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named symbolFor and associate it with a callback. This allows the SymbolFor callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"symbolFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(symbolFor())JS";
```

**Expected output**
```ts
JSVM OH_JSVM_SymbolFor success
```
