# Working with Objects Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2cc827181a31e0a77238ca42eb3b41991d5fd686 translatedAt=2026-08-12T06:40:18.837Z pushedAt=2026-08-12T11:14:25.268Z -->

## Overview

Node-API provides APIs for basic object operations, including creating an object, obtaining the prototype of an object, freezing or sealing an object, and checking the object type.

## Basic Concepts

You may need to define and operate objects when using Node-API in development. For example, define an API with an object as an input parameter, perform operations on the object, and have a result object returned. In this process, you need to ensure that the API definition is clear and compatible with the properties and methods of the object.

- API: defines the interaction protocol between components. An API includes input parameters, output result, and possible error handling. By calling APIs, components can interact and exchange data with each other without knowing the internal implementation details.

- Object: a composite data type that allows values of different types in an independent entity in ArkTS. An object is a collection of properties and methods. A property is a value associated with an object, and a method is an operation that the object can perform.

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

<!-- @[napi_get_prototype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_prototype
static napi_value GetPrototype(napi_env env, napi_callback_info info)
{
    // Obtain and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value result = nullptr;
    // Obtain the prototype object of this object and store the result in the napi_value variable result.
    napi_get_prototype(env, args[0], &result);
    return result;
}
```

API declaration:

<!-- @[napi_get_prototype_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getPrototype: (object: Object) => Object; // napi_get_prototype
```

ArkTS code:

<!-- @[ark_napi_get_prototype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/napiGetPrototype.ts) -->

``` TypeScript
class Person {
  // Properties
  name: string;
  age: number;
  // Constructor
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
// Create an instance of the class.
const person = new Person('Alice', 30);
// Pass in the instance object and obtain its prototype.
let personPrototype = testNapi.getPrototype(person);
// Check whether the prototype obtained through the testNapi.getPrototype() function is the prototype of person.
// In DevEco Studio 4.1 and later versions, ArkTS does not have the concept of prototype,
// so attempting prototype assignment or related operations
// triggers the error 'Prototype assignment is not supported (arkts-no-prototype-assignment)',
// The following code must be executed in a .ts file.
if (personPrototype === Person.prototype) {
  hilog.info(0x0000, 'Node-API', 'get_prototype_success');
} else {
  hilog.error(0x0000, 'Node-API', 'get_prototype_fail');
}
```

### napi_create_object

Call **napi_create_object** to create an empty ArkTS object.

CPP code:

<!-- @[napi_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_object
napi_value NewObject(napi_env env, napi_callback_info info)
{
    napi_value object = nullptr;
    // Create an empty object.
    napi_create_object(env, &object);
    // Set the properties of the object.
    napi_value name = nullptr;
    // Set the property name to "name".
    napi_create_string_utf8(env, "name", NAPI_AUTO_LENGTH, &name);
    napi_value value = nullptr;
    // Set the property value to "Hello from Node-API!".
    napi_create_string_utf8(env, "Hello from Node-API!", NAPI_AUTO_LENGTH, &value);
    // Set the property on the object.
    napi_set_property(env, object, name, value);
    return object;
}
```

API declaration:

<!-- @[napi_create_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createObject: () => { name: string }; // napi_create_object
```

ArkTS code:

<!-- @[ark_napi_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_object
try {
  const myObject = testNapi.createObject();
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_object: %{public}s', myObject.name);
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_create_object errorCode: %{public}s, errorMessage: %{public}s', error.code,
    error.message);
  // ...
}
```

### napi_object_freeze

Call **napi_object_freeze** to freeze an ArkTS object. After an object is frozen, new properties or methods cannot be added to the object, and the values of existing properties or methods cannot be modified.

CPP code:

<!-- @[napi_object_freeze](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_object_freeze
static napi_value ObjectFreeze(napi_env env, napi_callback_info info)
{
    // Accept an object passed from the ArkTS side.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    // Call napi_object_freeze to freeze the passed object.
    napi_value objFreeze = argv[0];
    napi_status status = napi_object_freeze(env, objFreeze);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_freeze success");
    }
    // Return the frozen object to the ArkTS side.
    return objFreeze;
}
```

API declaration:

<!-- @[napi_object_freeze_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export interface Obj {
  data: number
  message: string
}

export const objectFreeze: (objFreeze: Object) => Obj; // napi_object_freeze
```

ArkTS code:

<!-- @[ark_napi_object_freeze](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_object_freeze
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let objFreeze = testNapi.objectFreeze(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_freeze: %{public}s', (objFreeze.data = 1));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_object_freeze error: %{public}s', error.message);
  // ...
}
```

### napi_object_seal

Call **napi_object_seal** to seal an ArkTS object. After an object is sealed, new properties cannot be added to the object, existing properties cannot be deleted, but the values of existing properties can be modified.

CPP code:

<!-- @[napi_object_seal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_object_seal
static napi_value ObjectSeal(napi_env env, napi_callback_info info)
{
    // Accept an object passed from the ArkTS side.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Call napi_object_seal to seal the passed object so that no new properties can be added.
    napi_value objSeal = argv[0];
    napi_status status = napi_object_seal(env, objSeal);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_seal success");
    } else {
        napi_throw_error(env, nullptr, "Node-API napi_object_seal failed");
        return nullptr;
    }
    // Return the sealed object to the ArkTS side.
    return objSeal;
}
```

API declaration:

<!-- @[napi_object_seal_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export interface Obj1 {
  data: number
  message: string
  id: number
}

export const objectSeal: (objSeal: Object) => Obj1; // napi_object_seal
```

ArkTS code:

<!-- @[ark_napi_object_seal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_object_seal
try {
  class Obj {
    public data: number = 0
    public message: string = ''
    // Optional property
    public address?: number = 0
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let objSeal = testNapi.objectSeal(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}s', objSeal.message);
  objSeal.data = 1;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}d', objSeal.data);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_object_seal: %{public}d', (objSeal.id = 1));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_object_seal error: %{public}s', error.message);
  // ...
}
```

### napi_typeof

Call **napi_typeof** to obtain the ArkTS type of an ArkTS value.

**NOTE**<br>**napi_typeof** can determine the following types.  

|Type| 
|-----|
|undefined|
|null|  
|boolean|  
|number|  
|string|
|object|  
|function|  
|bigint|

CPP code:

<!-- @[napi_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_typeof
static napi_value NapiTypeOf(napi_env env, napi_callback_info info)
{
    // Accept one input parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Call napi_typeof to determine the type of the passed ArkTS parameter.
    napi_valuetype valueType;
    napi_status status = napi_typeof(env, args[0], &valueType);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_typeof fail");
        return nullptr;
    }
    // Convert the result to the napi_value type and return it.
    napi_value returnValue = nullptr;
    switch (valueType) {
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

API declaration:

<!-- @[napi_typeof_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiTypeOf: <T>(value: T) => string | undefined; // napi_typeof
```

ArkTS code:

<!-- @[ark_napi_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_typeof
try {
  let varUndefined: undefined;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varUndefined));
  let varNull: null = null;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varNull));
  let varTrue = true;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varTrue));
  let varNum = 1;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varNum));
  let varString = 'str';
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varString));

  class Obj {
    public id: number = 0
    public name: string = ''
  }

  let varObject: Obj = { id: 1, name: 'LiLei' };
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varObject));
  const addNum = (a: number, b: number): number => a * b;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(addNum));
  let varBigint = BigInt('1234567890123456789012345678901234567890');
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s',
    testNapi.napiTypeOf(varBigint));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_typeof error: %{public}s', error.message);
  // ...
}
```

### napi_instanceof

Call **napi_instanceof** to check whether an ArkTS object is an instance of the specified constructor.

CPP code:

<!-- @[napi_instanceof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_instanceof
static napi_value NapiInstanceOf(napi_env env, napi_callback_info info)
{
    // Accept two input parameters.
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
    // Convert the result to the napi_value type and return it.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```

API declaration:

<!-- @[napi_instanceof_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiInstanceOf: (date: Object, construct: Object) => boolean | undefined; // napi_instanceof
```

ArkTS code:

<!-- @[ark_napi_instanceof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_instanceof
try {
  class Person {
    public name: string;
    public age: number;

    constructor(name: string, age: number) {
      this.name = name;
      this.age = age;
    }
  }

  const person = new Person('Alice', 30);

  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_instanceof: %{public}s',
    testNapi.napiInstanceOf(person, Person));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_instanceof: %{public}s',
    testNapi.napiInstanceOf(obj, Person));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_instanceof error: %{public}s', error.message);
  // ...
}
```

### napi_type_tag_object

Call **napi_type_tag_object** to associate the value of a **type_tag** pointer with an ArkTS object so that the object can be identified more accurately.

In the ArkTS version, **napi_type_tag_object** does not use private symbols. As a result, the type_tag may be overwritten. You are advised not to use this API in key security scenarios.

### napi_check_object_type_tag

Call **napi_check_object_type_tag** to check whether an ArkTS object is associated with a tag pointer.

The type tags associate native types with ArkTS types, allowing ArkTS objects to be accurately identified and processed in C/C++.

CPP code:

<!-- @[napi_type_tag_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
#define NUMBERINT_FOUR 4
// Define a static constant napi_type_tag array to store type tags.
static const napi_type_tag TagsData[NUMBERINT_FOUR] = {
    {0x9e4b2449547061b3, 0x33999f8a6516c499},
    {0x1d55a794c53a726d, 0x43633f509f9c944e},
    // Used to indicate no tag or the default tag.
    {0, 0},
    {0x6a971439f5b2e5d7, 0x531dc28a7e5317c0},
};
// napi_type_tag_object
static napi_value SetTypeTagToObject(napi_env env, napi_callback_info info)
{
    // Obtain the function call information and parameters.
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
    // Convert the bool result to napi_value and return it.
    napi_value result = nullptr;
    napi_get_boolean(env, true, &result);
    return result;
}
// napi_check_object_type_tag
static napi_value CheckObjectTypeTag(napi_env env, napi_callback_info info)
{
    // Obtain the function call information and parameters.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index number and convert it to napi_value.
    int32_t index = 0;
    napi_get_value_int32(env, args[1], &index);
    // Check the type tag of the object.
    bool checkResult = true;
    napi_check_object_type_tag(env, args[0], &TagsData[index], &checkResult);
    // Convert the bool result to napi_value and return it.
    napi_value checked = nullptr;
    napi_get_boolean(env, checkResult, &checked);

    return checked;
}
```

API declaration:

<!-- @[napi_type_tag_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const setTypeTagToObject: (obj: Object, index: number) => boolean | undefined; // napi_type_tag_object

export const checkObjectTypeTag: (obj: Object, index: number) => boolean; // napi_check_object_type_tag
```

<!-- @[ark_napi_type_tag_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// napi_type_tag_object and napi_check_object_type_tag
class Obj {
  public data: number = 0
  public message: string = ''
}

let objA: Obj = { data: 0, message: 'hello world' };
let objB: Obj = { data: 10, message: 'typeTag' };
hilog.info(0x0000, 'testTag', 'Test Node-API napi_type_tag_object objA -> 0: %{public}s',
  testNapi.setTypeTagToObject(objA, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_type_tag_object objB -> 0: %{public}s',
  testNapi.setTypeTagToObject(objB, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_check_object_type_tag objA -> 0: %{public}s',
  testNapi.checkObjectTypeTag(objA, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_check_object_type_tag objB -> 1: %{public}s',
  testNapi.checkObjectTypeTag(objB, 1));
```

### napi_create_external

Call **napi_create_external** to create an ArkTS external object with a custom C/C++ object and expose it to ArkTS. With this API, you can create a Node-API value that contains a pointer to a custom C/C++ object so that the object can be accessed and managed by ArkTS.

CPP code:

<!-- @[napi_create_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// Callback used to release external data.
void finalizeCallback(napi_env env, void *data, void *hint)
{
    // Release the external data.
    free(data);
}
// napi_create_external
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
    // Allocate the external data.
    void *data = malloc(dataSize);
    if (data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "malloc failed");
        return nullptr;
    }
    // Initialize the external data.
    memset(data, 0, dataSize);
    napi_value result = nullptr;
    // Return the object with external data.
    napi_status status = napi_create_external(env, data, finalizeCallback, nullptr, &result);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API Failed to create external data");
        free(data);
        return nullptr;
    }
    return result;
}
```

API declaration:

<!-- @[napi_create_external_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createExternal: () => Object; // napi_create_external

export const getExternalType: (externalData: Object) => boolean; // napi_create_external
```

ArkTS code:

<!-- @[ark_napi_create_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_external
const externalData = testNapi.createExternal();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_external:%{public}s',
  testNapi.getExternalType(externalData));
```

### napi_get_value_external

Call **napi_get_value_external** to obtain the ArkTS data from the external object created by **napi_create_external**.

CPP code:

<!-- @[napi_get_value_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_external
static int g_external = 5;
static napi_value GetValueExternal(napi_env env, napi_callback_info info)
{
    // Create the external data.
    int *data = &g_external;
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

API declaration:

<!-- @[napi_get_value_external_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueExternal: () => number; // napi_get_value_external
```

ArkTS code:

<!-- @[ark_napi_get_value_external](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_external
hilog.info(0x0000, 'Node-API', 'get_value_external:%{public}d', testNapi.getValueExternal());
```

### napi_create_symbol

Call **napi_create_symbol** to create a symbol. Symbol is a special data type used to indicate a unique identifier. Unlike strings or numbers, the value of a symbol is unique. Even if two symbols have the same description, they are not equal. Symbols are often used as keys for object properties to ensure property uniqueness.

CPP code:

<!-- @[napi_create_symbol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_symbol
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
    // Create a symbol type and return it.
    status = napi_create_symbol(env, result, &returnSymbol);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_create_symbol failed");
        return nullptr;
    }
    return returnSymbol;
}
```

<!-- @[napi_create_symbol_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createSymbol: () => symbol; // napi_create_symbol
```

ArkTS code:

<!-- @[ark_napi_create_symbol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIObject/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_symbol
let varSymbol = testNapi.createSymbol();
hilog.info(0x0000, 'Node-API', 'createSymbol:%{public}s', typeof varSymbol);
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```