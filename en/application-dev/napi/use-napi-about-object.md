# Working with Objects Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Overview

Node-API provides APIs for basic object operations, including creating an object, obtaining the prototype of an object, freezing or sealing an object, and checking the object type.

## Basic Concepts

You may need to define and operate objects when using Node-API in development. For example, define an API with an object as an input parameter, perform operations on the object, and have a result object returned. In this process, you need to ensure that the API definition is clear and compatible with the properties and methods of the object.

- API: defines the interaction protocol between components. An API includes input parameters, output result, and possible error handling. By calling APIs, components can interact and exchange data with each other without knowing the internal implementation details.
- Object: a composite data type that allows values of different types to be stored as an independent entity in ArkTS. An object is a collection of properties and methods. A property is a value associated with an object, and a method is an operation that the object can perform.

## Available APIs

The following table lists the APIs for operating and managing ArkTS objects.
| API| Description|
| -------- | -------- |
| napi_get_prototype | Obtains the prototype of an ArkTS object. You can use this API to obtain the prototype object in C/C++.|
| napi_create_object | Creates a default ArkTS object.|
| napi_object_freeze | Freezes an ArkTS object. Once an object is frozen, its properties are immutable.|
| napi_object_seal | Seals an ArkTS object. Once an object is sealed, its properties cannot be added or deleted, but property values can be modified.|
| napi_typeof | Obtains the type of an ArkTS value.|
| napi_instanceof | Checks whether an ArkTS object is an instance of the specified constructor.|
| napi_type_tag_object | Associates the value of a tag pointer with an ArkTS object.|
| napi_check_object_type_tag | Checks whether a tag pointer is associated with a ArkTS object.|
| napi_create_symbol | Creates an ArkTS **Symbol** object.|
| napi_create_external | Creates an ArkTS external object, which can be used to pass custom data structs or objects in C/C++ to ArkTS so that it can be accessible from ArkTS.|
| napi_get_value_external | Obtains the ArkTS data from the external object created by **napi_create_external**. This API can be used to pass data between ArkTS and C/C++.|

With these APIs, you can easily create and manipulate ArkTS objects in C/C++.

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to object management.

### napi_get_prototype

Call **napi_get_prototype** to obtain the prototype of an ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetPrototype(napi_env env, napi_callback_info info)
{
    // Obtain and parse input parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    napi_value result = nullptr;
    // Obtain the prototype object of this object and return the prototype object obtained to the variable result of the napi_value type.
    napi_get_prototype(env, args[0], &result);
    return result;
}
```
<!-- @[napi_get_prototype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getPrototype: (object: Object) => Object;
```
<!-- @[napi_get_prototype_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// Define a class.
class Person {
  // Property.
  name: string;
  age: number;
  // Constructor.
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
// Create a class instance.
const person = new Person('Alice', 30);
// Pass in an instance object and obtain the prototype of the object.
let applePrototype = testNapi.getPrototype(person);
// Check whether the prototype obtained by testNapi.getPrototype() is an Apple prototype.
// ArkTS does not have the prototype concept in DevEco Studio 4.1 and later. When you perform prototype-related operations, 'Prototype assignment is not supported (arkts-no-prototype-assignment)' will be displayed. Therefore, you need to run the following code in a TS file:
if (applePrototype === Person.prototype) {
  hilog.info(0x0000, 'Node-API', 'get_prototype_success');
} else {
  hilog.error(0x0000, 'Node-API', 'get_prototype_fail');
}
```
<!-- @[ark_napi_get_prototype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/napiGetPrototype.ts) -->

### napi_create_object

Call **napi_create_object** to create an empty ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

napi_value NewObject(napi_env env, napi_callback_info info)
{
    napi_value object = nullptr;
    // Create an empty object.
    napi_create_object(env, &object);
    // Set the object property.
    napi_value name = nullptr;
    // Set the property name to "name".
    napi_create_string_utf8(env, "name", NAPI_AUTO_LENGTH, &name);
    napi_value value = nullptr;
    // Set the property value to "Hello from N-API!"
    napi_create_string_utf8(env, "Hello from Node-API!", NAPI_AUTO_LENGTH, &value);
    // Set the property on the object.
    napi_set_property(env, object, name, value);
    return object;
}
```
<!-- @[napi_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createObject: () => { name: string };
```
<!-- @[napi_create_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  const myObject = testNapi.createObject();
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_object: %{public}s', myObject.name);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_object errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_object_freeze

Call **napi_object_freeze** to freeze an ArkTS object. After an object is frozen, new properties or methods cannot be added to the object, and the values of existing properties or methods cannot be modified.

CPP code:

```cpp
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value ObjectFreeze(napi_env env, napi_callback_info info)
{
    // Obtain the object passed from ArkTS.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    // Call napi_object_freeze to freeze the object passed in.
    napi_value objFreeze = argv[0];
    napi_status status = napi_object_freeze(env, objFreeze);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_freeze success");
    }
    // Return the frozen object to ArkTS.
    return objFreeze;
}
```
<!-- @[napi_object_freeze](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export interface Obj {
  data: number
  message: string
}
export const objectFreeze: (objFreeze: Object) => Obj;
```
<!-- @[napi_object_freeze_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = {data: 0, message: "hello world"};
  let objFreeze = testNapi.objectFreeze(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_freeze: %{public}s', (objFreeze.data = 1));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_object_freeze error: %{public}s', error.message);
}
```
<!-- @[ark_napi_object_freeze](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_object_seal

Call **napi_object_seal** to seal an ArkTS object. After an object is sealed, new properties cannot be added to the object, existing properties cannot be deleted, but the values of existing properties can be modified.

CPP code:

```cpp
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value ObjectSeal(napi_env env, napi_callback_info info)
{
    // Obtain the object passed from ArkTS.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Call napi_object_seal to seal the object passed in.
    napi_value objSeal = argv[0];
    napi_status status = napi_object_seal(env, objSeal);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_seal success");
    } else {
        napi_throw_error(env, nullptr, "Node-API napi_object_seal failed");
        return nullptr;
    }
    // Return the sealed object to ArkTS.
    return objSeal;
}
```
<!-- @[napi_object_seal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export interface Obj {
  data: number
  message: string
  id: number
}
export const objectSeal : (objSeal: Object) => Obj;
```
<!-- @[napi_object_seal_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
    // Optional property.
    address?: number
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let objSeal = testNapi.objectSeal(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}s', objSeal.message);
  objSeal.data = 1;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}d', objSeal.data);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}d', (objSeal.id = 1));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_object_seal error: %{public}s', error.message);
}
```
<!-- @[ark_napi_object_seal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_typeof

Call **napi_typeof** to obtain the ArkTS type of an ArkTS value.

**Note**: **napi_typeof** can determine the following types:  
undefined  
null  
boolean  
number  
string  
object  
function  
bigint

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiTypeOf(napi_env env, napi_callback_info info)
{
    // Obtain the parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Call napi_typeof to check the type of the ArkTS parameter passed in.
    napi_valuetype valueType;
    napi_status status = napi_typeof(env, args[0], &valueType);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_typeof fail");
        return nullptr;
    }
    // Convert the result to napi_value and return napi_value.
    napi_value returnValue = nullptr;
    switch(valueType) {
    case napi_undefined:
        napi_create_string_utf8(env, "Input type is napi_undefined", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_null:
        napi_create_string_utf8(env, "Input type is napi_null", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_boolean:
        napi_create_string_utf8(env, "Input type is napi_boolean", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_number:
        napi_create_string_utf8(env, "Input type is napi_number", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_string:
        napi_create_string_utf8(env, "Input type is napi_string", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_object:
        napi_create_string_utf8(env, "Input type is napi_object", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_function:
        napi_create_string_utf8(env, "Input type is napi_function", NAPI_AUTO_LENGTH, &returnValue);
        break;
    case napi_bigint:
        napi_create_string_utf8(env, "Input type is napi_bigint", NAPI_AUTO_LENGTH, &returnValue);
        break;
    default:
        napi_create_string_utf8(env, "unknown", NAPI_AUTO_LENGTH, &returnValue);
    }

    return returnValue;
}
```
<!-- @[napi_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiTypeOf : <T>(value: T) => string | undefined;
```
<!-- @[napi_typeof_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  let varUndefined: undefined;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varUndefined));
  let varNull: null = null;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varNull));
  let varTrue= true;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varTrue));
  let varNum = 1;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varNum));
  let varString = "str";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varString));
  class Obj {
    id: number = 0
    name: string = ""
  }
  let varObject: Obj = {id: 1, name: "LiLei"};
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varObject));
  const mulNum = (a: number, b: number): number => a * b;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(mulNum));
  let varBigint = BigInt("1234567890123456789012345678901234567890");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varBigint));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_typeof error: %{public}s', error.message);
}
```
<!-- @[ark_napi_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_instanceof

Call **napi_instanceof** to check whether an ArkTS object is an instance of the specified constructor.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiInstanceOf(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_instanceof to check whether the given object is an instance of the given constructor.
    bool result = true;
    napi_status status = napi_instanceof(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_instanceof fail");
        return nullptr;
    }
    // Convert the result to napi_value and return napi_value.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_instanceof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiInstanceOf: (date: Object, construct: Object) => boolean | undefined;
```
<!-- @[napi_instanceof_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  class Person {
    name: string;
    age: number;

    constructor(name: string, age: number) {
      this.name = name;
      this.age = age;
    }
  }
  const person = new Person("Alice", 30);
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_instanceof: %{public}s', testNapi.napiInstanceOf(person, Person));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_instanceof: %{public}s', testNapi.napiInstanceOf(obj, Person));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_instanceof error: %{public}s', error.message);
}
```
<!-- @[ark_napi_instanceof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_type_tag_object

Call **napi_type_tag_object** to associate the value of a **type_tag** pointer with an ArkTS object so that the object can be identified more accurately.

### napi_check_object_type_tag

Call **napi_check_object_type_tag** to check whether an ArkTS object is associated with a tag pointer.

The type tags associate native types with ArkTS types, allowing ArkTS objects to be accurately identified and processed in C/C++.

CPP code:

```cpp
#include "napi/native_api.h"

#define NUMBERINT_FOUR 4
// Define a static constant named napi_type_tag array to store type tags.
static const napi_type_tag TagsData[NUMBERINT_FOUR] = {
    {0x9e4b2449547061b3, 0x33999f8a6516c499},
    {0x1d55a794c53a726d, 0x43633f509f9c944e},
    // Default tag or no tag.
    {0, 0},
    {0x6a971439f5b2e5d7, 0x531dc28a7e5317c0},
};

static napi_value SetTypeTagToObject(napi_env env, napi_callback_info info)
{
    // Obtain the call information and parameters.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index number and convert it to napi_value.
    int32_t index = 0;
    napi_get_value_int32(env, args[1], &index);
    // Set the type tag for the parameter (object).
    napi_status status = napi_type_tag_object(env, args[0], &TagsData[index]);
    if (status != napi_ok) {
        napi_throw_error(env, "Reconnect error", "napi_type_tag_object failed");
        return nullptr;
    }
    // Convert the bool value to napi_value and return it.
    napi_value result = nullptr;
    napi_get_boolean(env, true, &result);
    return result;
}

static napi_value CheckObjectTypeTag(napi_env env, napi_callback_info info)
{
    // Obtain the call information and parameters.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index number and convert it to napi_value.
    int32_t index = 0;
    napi_get_value_int32(env, args[1], &index);
    // Check the type tag of the object.
    bool checkResult = true;
    napi_check_object_type_tag(env, args[0], &TagsData[index], &checkResult);
    // Convert the bool value to napi_value and return it.
    napi_value checked = nullptr;
    napi_get_boolean(env, checkResult, &checked);

    return checked;
}
```
<!-- @[napi_type_tag_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const setTypeTagToObject: (obj: Object, index: number) => boolean | undefined;
export const checkObjectTypeTag: (obj: Object, index: number) => boolean;
```
<!-- @[napi_type_tag_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
class Obj {
  data: number = 0
  message: string = ""
}
let objA: Obj = { data: 0, message: "hello world"};
let objB: Obj = { data: 10, message: "typeTag"};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_type_tag_object objA -> 0: %{public}s', testNapi.setTypeTagToObject(objA, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_type_tag_object objB -> 0: %{public}s', testNapi.setTypeTagToObject(objB, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_check_object_type_tag objA -> 0: %{public}s', testNapi.checkObjectTypeTag(objA, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_check_object_type_tag objB -> 1: %{public}s', testNapi.checkObjectTypeTag(objB, 1));
```
<!-- @[ark_napi_type_tag_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_create_external

Call **napi_create_external** to create an ArkTS external object with a custom C/C++ object and expose it to ArkTS. With this API, you can create a Node-API value that contains a pointer to a custom C/C++ object so that the object can be accessed and managed by ArkTS.

CPP code:

```cpp
#include <cstdlib>
#include <string>
#include "hilog/log.h"
#include "napi/native_api.h"

// Callback used to release the external data.
void finalizeCallback(napi_env env, void *data, void *hint) {
    // Release external data.
    free(data);
}

static napi_value GetExternalType(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the data type of the parameter.
    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    napi_value returnValue = nullptr;
    if (valueType == napi_external) {
        // If the data type is napi_external, return true.
        napi_get_boolean(env, true, &returnValue);
    } else {
        napi_get_boolean(env, false, &returnValue);
    }
    return returnValue;
}

static napi_value CreateExternal(napi_env env, napi_callback_info info)
{
    // Set the external data size to 10.
    const size_t dataSize = 10;
    // Allocate memory to the external data.
    void *data = malloc(dataSize);
    if (data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "malloc failed");
        return nullptr;
    }
    // Initialize the external data.
    memset(data, 0, dataSize);
    napi_value result = nullptr;
    // Return an object with external data.
    napi_status status = napi_create_external(env, data, finalizeCallback, nullptr, &result);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, " Node-API Failed to create external data");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_create_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createExternal: () => Object;
export const getExternalType: (externalData: Object) => boolean;
```
<!-- @[napi_create_external_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
const externalData = testNapi.createExternal();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_external:%{public}s', testNapi.getExternalType(externalData));
```
<!-- @[ark_napi_create_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_external

Call **napi_get_value_external** to obtain the ArkTS data from the external object created by **napi_create_external**.

CPP code:

```cpp
#include "napi/native_api.h"

static int external = 5; 
static napi_value GetValueExternal(napi_env env, napi_callback_info info)
{
    // Create external data.
    int* data = &external;
    napi_value setExternal = nullptr;
    napi_create_external(env, data, nullptr, nullptr, &setExternal);
    // Obtain the value of the external data.
    void *getExternal;
    napi_get_value_external(env, setExternal, &getExternal);
    // Return the obtained external data.
    napi_value result = nullptr;
    napi_create_int32(env, *(int *)getExternal, &result);
    return result;
}
```
<!-- @[napi_get_value_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getValueExternal: () => number;
```
<!-- @[napi_get_value_external_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
hilog.info(0x0000, 'Node-API', 'get_value_external:%{public}d', testNapi.getValueExternal());
```
<!-- @[ark_napi_get_value_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

### napi_create_symbol

Call **napi_create_symbol** to create a symbol. Symbol is a special data type used to indicate a unique identifier. Unlike strings or numbers, the value of a symbol is unique. Even if two symbols have the same description, they are not equal. Symbols are often used as keys for object properties to ensure property uniqueness.

CPP code:

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static napi_value CreateSymbol(napi_env env, napi_callback_info info)
{
    napi_value result = nullptr;
    const char *des = "only";
    // Use napi_create_string_utf8 to create a description string.
    napi_status status = napi_create_string_utf8(env, des, NAPI_AUTO_LENGTH, &result);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_create_string_utf8 failed");
        return nullptr;
    }
    napi_value returnSymbol = nullptr;
    // Create a symbol and return it.
    status = napi_create_symbol(env, result, &returnSymbol);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_create_symbol failed");
        return nullptr;
    }
    return returnSymbol;
}
```
<!-- @[napi_create_symbol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createSymbol : () => symbol;
```
<!-- @[napi_create_symbol_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
let varSymbol = testNapi.createSymbol();
hilog.info(0x0000, 'Node-API', 'createSymbol:%{public}s', typeof varSymbol);
```
<!-- @[ark_napi_create_symbol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
