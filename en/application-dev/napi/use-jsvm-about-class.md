# Working with Classes Using JSVM-API

## Introduction

JSVM-API provides APIs for managing JavaScript (JS) classes, for example, defining a JS class and creating a JS instance.

## Basic Concepts

To begin with, it is important to understand the following basic concepts:

- Class: a template used to create an object. It provides a way to define object properties and methods in a structured manner. Classes in JavaScript are based on prototypes. Moreover, unique syntax and semantics of classes are introduced.
- Instance: an object created from a class. A class defines the structure and behavior of an object, and an instance is a specific representation of a class. Instantiating a class allows access to the properties and methods defined in the class. Each instance has its own property values.

## Available APIs

| API               | Description                          |
| ------------------- | ---------------------------------- |
| OH_JSVM_NewInstance   | Creates an instance from the given constructor.|
| OH_JSVM_GetNewTarget  | Obtains **new.target** of the constructor call.|
| OH_JSVM_DefineClass   | Defines a JS class and associated functions within a C/C++ addon. It allows you to define a constructor, methods, and properties that can be accessed from JS.|
| OH_JSVM_Wrap           | Wraps a native instance in a JS object. You can use **OH_JSVM_Unwrap()** to retrieve the native instance later.|
| OH_JSVM_Unwrap         | Unwraps a native instance from a JS object.|
| OH_JSVM_RemoveWrap     | Removes the wrapping after the native instance is unwrapped from a JS object.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following only demonstrates the C++ and ArkTS code involved in the class-related APIs.

### OH_JSVM_NewInstance

Use **OH_JSVM_NewInstance** to create an instance from the given constructor.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
Create an instance from the given constructor.
// Register the NewInstance callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = NewInstance},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named newInstance and associate it with a callback. This allows the NewInstance callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"newInstance", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_NewInstance.
static JSVM_Value NewInstance(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_NewInstance to create an instance and return the instance created.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_NewInstance(env, args[0], 1, &args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM API TEST RESULT: PASS");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: PASS");
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
// Import the native APIs.
import napitest from 'libentry.so'
let script: string = `
   function Fruit(name) {
       this.name = name;
   }
   newInstance(Fruit, "apple");
  `;
try {
  let result = napitest.runJsVm(script.toString());
  hilog.info(0x0000, 'JSVM', 'NewInstance:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'NewInstance:%{public}s', error.message);
}
```

### OH_JSVM_GetNewTarget

Use **OH_JSVM_GetNewTarget** to obtain **new.target** of a constructor. In JS, **new.target** is a meta property used to determine whether a constructor was called using the **new** operator.

### OH_JSVM_DefineClass

Use **OH_JSVM_DefineClass** to define a JS class and associated functions within a C/C++ addon. It allows you to define a constructor, methods, and properties that can be accessed from JS.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define a class struct.
struct DefineObject {
    std::string name;
    int32_t age;
    JSVM_Ref wrapper_;
};
static thread_local JSVM_Ref g_ref = nullptr;
// Create an instance.
struct DefineObject *defineObject = new struct DefineObject();
JSVM_Value New(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value newTarget;
    OH_JSVM_GetNewTarget(env, info, &newTarget);
    if (newTarget != nullptr) {
        OH_LOG_INFO(LOG_APP, "NAPI MyObject::New newTarget != nullptr");
        // Invoked as the constructor `new MyObject(...)`.
        size_t argc = 1;
        JSVM_Value args[1];
        JSVM_Value jsThis;
        OH_JSVM_GetCbInfo(env, info, &argc, args, &jsThis, nullptr);
        double value = 0.0;
        JSVM_ValueType valuetype;
        OH_JSVM_Typeof(env, args[0], &valuetype);
        if (valuetype != JSVM_UNDEFINED) {
            OH_JSVM_GetValueDouble(env, args[0], &value);
        }
        defineObject->name = "lilei";
        defineObject->age = 18;
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "NAPI MyObject::New newTarget == nullptr");
        size_t argc = 1;
        JSVM_Value args[1];
        (OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
        JSVM_Value cons;
        (OH_JSVM_GetReferenceValue(env, g_ref, &cons));
        JSVM_Value instance;
        (OH_JSVM_NewInstance(env, cons, argc, args, &instance));
        return instance;
    }
}

// Obtain the data in the encapsulated C++ struct.
napi_value GetObj(napi_env env) {
    std::string str = "{\"name\": \"" + defineObject->name + "\",\"age\": " + std::to_string(defineObject->age) + "}";
    napi_value jsResult;
    napi_create_string_utf8(env, str.c_str(), NAPI_AUTO_LENGTH, &jsResult);
    return jsResult;
}

// Encapsulate the struct in C++.
JSVM_Value DefineClass(JSVM_Env env, JSVM_Value exports) {
    JSVM_CallbackStruct param1;
    param1.data = nullptr;
    param1.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value { return New(env, info); };
    JSVM_Value cons;
    OH_JSVM_DefineClass(env, "MyObject", JSVM_AUTO_LENGTH, &param1, 0, nullptr, &cons);
    JSVM_Value instanceValue = nullptr;
    OH_JSVM_NewInstance(env, cons, 0, nullptr, &instanceValue);
    return nullptr;
}
```

Modify the **RunJsVm** method defined in [JSVM-API Development Process](use-jsvm-process.md) as follows:

```cpp
    // hello.cpp
    // Change the reserved code in defineClass() as follows:
    if (strcmp(sourceCodeStr.c_str(), "defineClass") == 0) {
        JSVM_Value obj;
        DefineClass(env, obj);
        nResult = GetObj(nEnv);
    } 
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
// Import the native APIs.
import napitest from 'libentry.so'
// test defineclass
try {
  let result = napitest.runJsVm("defineClass");
  hilog.info(0x0000, 'testJSVM', 'Test JSVM defineclass:%{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM AssertEqual error: %{public}s', error);
}
```

### OH_JSVM_Wrap

Use **OH_JSVM_Wrap** to wrap a native instance in a JS object. You can use **OH_JSVM_Unwrap()** to retrieve the native instance later.

### OH_JSVM_Unwrap

Use **OH_JSVM_Unwrap** to unwrap a native instance from a JS object.

### OH_JSVM_RemoveWrap

Use **OH_JSVM_RemoveWrap** to retrieve a native instance previously wrapped in a JS object and remove the wrapping.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the WrapObject and RemoveWrap callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WrapObject},
    {.data = nullptr, .callback = RemoveWrap},
};
static JSVM_CallbackStruct *method = param;
// Set property descriptors named wrapObject and removeWrap and associate them with a callback each. This allows the WrapObject and RemoveWrap callbacks to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"wrapObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"removeWrap", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT}
};
// Define OH_JSVM_GetNewTarget, OH_JSVM_DefineClass, OH_JSVM_Wrap, OH_JSVM_Unwrap, and OH_JSVM_RemoveWrap.
// Check whether the deref_item function is called.
static bool deref_item_called = false;

// Define the struct Object.
struct Object {
    std::string name;
    int32_t age;
};
struct Object *obj = new struct Object();

// Define a callback function.
static void DerekItem(JSVM_Env env, void *data, void *hint) {
    OH_LOG_INFO(LOG_APP, "JSVM deref_item");
    (void)hint;
}

static JSVM_Value WrapObject(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM wrap");
    // Set a property for the object.
    obj->name = "lilei";
    obj->age = 18;
    // Obtain the number of parameters in the callback and the values to be wrapped.
    size_t argc = 1;
    JSVM_Value toWrap = nullptr;
    OH_JSVM_GetCbInfo(env, info, &argc, &toWrap, nullptr, nullptr);
    // Wrap the Object struct.
    OH_JSVM_Wrap(env, toWrap, reinterpret_cast<void *>(obj), DerekItem, NULL, NULL);
    struct Object *data;
    struct Object *data1;
    OH_JSVM_Unwrap(env, toWrap, reinterpret_cast<void **>(&data));
    OH_LOG_INFO(LOG_APP, "JSVM name: %{public}s", data->name.c_str());
    OH_LOG_INFO(LOG_APP, "JSVM age: %{public}d", data->age);
    // Retrieve the previously wrapped object and remove the wrapping.
    OH_JSVM_RemoveWrap(env, toWrap, reinterpret_cast<void **>(&obj));
    JSVM_Status status = OH_JSVM_Unwrap(env, toWrap, reinterpret_cast<void **>(&data1));
    if (status != JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_RemoveWrap success");
    }
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_Value RemoveWrap(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM removeWrap");
    size_t argc = 1;
    JSVM_Value wrapped = nullptr;
    void *data;
    OH_JSVM_GetCbInfo(env, info, &argc, &wrapped, nullptr, nullptr);
    OH_JSVM_RemoveWrap(env, wrapped, &data);
    return nullptr;
}
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
// Import the native APIs.
import napitest from 'libentry.so'
// wrapObject
class Obj {}
let obj: Obj = `{}`;
let script: string = `
  wrapObject(${obj});
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'WrapObject:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'WrapObject:%{public}s', error.message);
}

// removeWrap
class Obj {}
let obj: Obj = `{}`;
let script: string = `
  removeWrap(${obj});
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'RemoveWrap:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'RemoveWrap:%{public}s', error.message);
}
```
