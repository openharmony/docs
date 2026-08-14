# Working with Class Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=5c6e465f4cb7e5e44777311b9850301a734295d4 translatedAt=2026-08-12T06:38:11.271Z pushedAt=2026-08-12T11:05:59.296Z -->

## Introduction

Node-API provides APIs for managing ArkTS classes, for example, defining an ArkTS class and creating an ArkTS instance, in C/C++.

## Basic Concepts

To begin with, it is important to understand the following basic concepts:

- Class: a template used to create an object. It provides a way to define object properties and methods in a structured manner. Classes in ArkTS are based on prototypes and added with unique syntax and semantics.

- Instance: an object created from a class. A class defines the structure and behavior of an object, and an instance is a specific representation of a class. Instantiating a class allows access to the properties and methods defined in the class. Each instance has its own property values.

- Prototype: ArkTS also employs classes to implement inheritance across types. Defined in the early EcmaScript specifications, the prototype concept is used to achieve object inheritance via prototype chains. For details about the prototype concept, see [EcmaScript Language Specification](https://262.ecma-international.org/#sec-terms-and-definitions-prototype).

## Available APIs

The following Node-API APIs are mainly used to handle classes. Their usage scenarios are as follows:

| API| Description|
| -------- | -------- |
| napi_new_instance | Creates an instance based on the given constructor.|
| napi_get_new_target | Obtains the **new.target** of the constructor call.|
| napi_define_class | Defines an ArkTS class corresponding to the C/C++ class. This API binds an ArkTS class and a C/C++ class.|
| napi_wrap | Wraps a native object into an ArkTS object. This API allows the methods and properties of a native object to be called from ArkTS.|
| napi_unwrap | Unwraps the native object from an ArkTS object.|
| napi_remove_wrap | Removes the wrapping after the native object is unwrapped from an ArkTS object.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the class-related APIs.

### napi_new_instance

Call **napi_new_instance** to create an ArkTS instance with the given constructor. This API returns an instance that can be called from ArkTS.

> **NOTE**
>
> If **constructor** is not of the function type, **napi_function_expected** will be returned.

CPP code:

<!-- @[napi_new_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_new_instance
static napi_value NewInstance(napi_env env, napi_callback_info info)
{
    // Pass and parse parameters. The first parameter is the constructor passed in, and the second parameter is the argument to pass to the constructor.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_new_instance to instantiate an object and return it.
    napi_value result = nullptr;
    napi_new_instance(env, args[0], 1, &args[1], &result);
    return result;
}
```

API declaration:

<!-- @[napi_new_instance_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const newInstance: (obj: Object, param: string) => Object; // napi_new_instance
```

ArkTS code:

<!-- @[ark_napi_new_instance_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
class Fruit {
  name: string;

  constructor(name: string) {
    this.name = name;
  }
}
```

<!-- @[ark_napi_new_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_new_instance
// Call the function and use the variable obj to receive the instantiated object returned by the function.
let obj = testNapi.newInstance(Fruit, 'test');
// Print information about the instantiated object obj.
hilog.info(0x0000, 'Node-API', 'napi_new_instance %{public}s', JSON.stringify(obj));
```

### napi_get_new_target

Call **napi_get_new_target** to obtain **new.target** of a constructor. In ArkTS, **new.target** is a meta property used to determine whether a constructor was called using the **new** operator.

For more information, see:

[Wrapping a Native Object in an ArkTS Object](use-napi-object-wrap.md)

### napi_define_class

Call **napi_define_class** to define an ArkTS class. This API creates an ArkTS class and associates the methods and properties of the ArkTS class with those of a C/C++ class.

For more information, see:

[Wrapping a Native Object in an ArkTS Object](use-napi-object-wrap.md)

### napi_wrap

Call **napi_wrap** to wrap a native instance in an ArkTS object.

> **NOTE**
>
> If **js_object** is not of the object or function type, **napi_object_expected** will be returned.

### napi_unwrap

Call **napi_unwrap** to obtain the data pointer wrapped in an object.

> **NOTE**
>
> If **js_object** is not of the object or function type, **napi_object_expected** will be returned.

### napi_remove_wrap

Call **napi_remove_wrap** to remove the wrapping after a native instance is unwrapped from an ArkTS object.

> **NOTE**
>
> If the **js_object** parameter is not of the object type or function type, **napi_object_expected** is returned.
> If a finalize callback is associated with the wrapping, this API calls it before removing the wrapping.

CPP code:

<!-- @[napi_wrap_unwrap_remove_wrap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/napi_init.cpp) -->

``` C++
struct Object {
    std::string name;
    int32_t age;
};

static void DerefItem(napi_env env, void *data, void *hint)
{
    // Optional native callback for releasing the native instance when the ArkTS object is garbage collected.
    OH_LOG_INFO(LOG_APP, "Node-API DerefItem");
    Object *obj = reinterpret_cast<Object *>(data);
    if (obj != nullptr) {
        delete obj;
    }
}

// napi_wrap
static napi_value Wrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API wrap");
    // Initialize the object of the Node-API module.
    struct Object *obj = new struct Object();
    obj->name = "liLei";
    obj->age = INT_ARG_18;
    size_t argc = 1;
    napi_value toWrap;
    // Call napi_wrap to bind the Node-API module object to the ArkTS object.
    napi_status status_cb = napi_get_cb_info(env, info, &argc, &toWrap, NULL, NULL);
    if (status_cb != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed");
        delete obj;
        return nullptr;
    }
    napi_status status = napi_wrap(env, toWrap, reinterpret_cast<void *>(obj), DerefItem, NULL, NULL);
    if (status != napi_ok) {
        // Actively release the memory.
        delete obj;
    }

    return toWrap;
}

// napi_remove_wrap
static napi_value RemoveWrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API removeWrap");
    size_t argc = 1;
    napi_value wrapped = nullptr;
    void *data = nullptr;
    // Call napi_remove_wrap to unwrap a wrapped object.
    napi_get_cb_info(env, info, &argc, &wrapped, nullptr, nullptr);
    napi_status status = napi_remove_wrap(env, wrapped, &data);
    if (status != napi_ok || data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_remove_wrap failed or data is nullptr");
        return nullptr;
    }

    return nullptr;
}

// napi_unwrap
static napi_value UnWrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API unWrap");
    size_t argc = 1;
    napi_value wrapped = nullptr;
    napi_get_cb_info(env, info, &argc, &wrapped, nullptr, nullptr);
    // Call napi_unwrap to retrieve and print the data bound to the ArkTS object.
    struct Object *data = nullptr;
    napi_status status = napi_unwrap(env, wrapped, reinterpret_cast<void **>(&data));
    if (status != napi_ok || data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_unwrap failed or data is nullptr");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "Node-API name: %{public}s", data->name.c_str());
    OH_LOG_INFO(LOG_APP, "Node-API age: %{public}d", data->age);
    return nullptr;
}
```

API declaration:

<!-- @[napi_wrap_unwrap_remove_wrap_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const wrap: (obj: Object) => Object; // napi_wrap

export const unWrap: (obj: Object) => void; // napi_unwrap

export const removeWrap: (obj: Object) => void; // napi_remove_wrap
```

ArkTS code:

<!-- @[ark_napi_wrap_unwrap_remove_wrap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
try {
  class Obj {
  }

  let obj: Obj = {};
  testNapi.wrap(obj); // napi_wrap
  testNapi.unWrap(obj); // napi_unwrap
  testNapi.removeWrap(obj); // napi_remove_wrap
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API error: %{public}s', error.message);
  // ...
}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```