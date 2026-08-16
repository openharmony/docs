# Setting ArkTS Object Properties Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:41:12.594Z pushedAt=2026-08-12T11:14:51.606Z -->

## Introduction

Node-API provides APIs for obtaining and setting properties of ArkTS objects in C/C++ to implement more complex functionalities and logic.

## Basic Concepts

Before working with ArkTS objects using Node-API, you need to understand the following concepts:

- Object: a composite data type that allows values of different types in an independent entity in ArkTS. An object is a collection of properties and methods. A property is a value associated with the object, and a method is an operation that the object can perform.

- Property: a feature, in the key-value format, of an object in ArkTS. Each property has a name (key or identifier) and a value. The property value can be of any data type, including the basic type, object, and function.

- Enumerable property: a property in ArkTS with **enumerable** set to **true**. An enumerable property can be traversed by **for...in**.

- Own property: a property defined for an object rather than inherited from the prototype chain.

## Available APIs

The following table lists the APIs for manipulating ArkTS object properties.  

| API| Description|
| -------- | -------- |
| napi_get_property_names | Obtains the names of the enumerable properties of an object in an array of strings.  |
| napi_set_property | Adds a property to an object or modifies a property value of an object.|
| napi_get_property | Obtains the requested property of an object and passes it to another function for processing.|
| napi_has_property | Checks whether an object has the specified property. This can prevent the exception or error caused by access to a property that does not exist.|
| napi_delete_property | Deletes a property from an ArkTS object.|
| napi_has_own_property | Checks whether an object has the specified own property.|
| napi_set_named_property | Sets a property with the specified name for an ArkTS object.|
| napi_get_named_property | Obtains the value of a property in an ArkTS object.|
| napi_has_named_property | Checks whether an ArkTS object has the property with the specified name.|
| napi_define_properties | Defines multiple properties for an ArkTS object.|
| napi_get_all_property_names | Obtains the names of all properties of an ArkTS object.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in related APIs.

### napi_get_property_names

Call **napi_get_property_names** to obtain the names of the enumerable properties of an object in an array of strings.

CPP code:

<!-- @[napi_get_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_property_names
static napi_value GetPropertyNames(napi_env env, napi_callback_info info)
{
    // Parse the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the names of the object's enumerable properties as a string array, and pass them out through result.
    napi_value result;
    napi_status status = napi_get_property_names(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_property_names fail");
        return nullptr;
    }
    return result;
}
```

API declaration:

<!-- @[napi_get_property_names_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getPropertyNames: (obj: Object) => Array<string> | undefined; // napi_get_property_names
```

ArkTS code:

<!-- @[ark_napi_get_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_property_names
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let propertyNames = testNapi.getPropertyNames(obj);
  if (Array.isArray(propertyNames) && propertyNames.length > 0) {
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s',
      propertyNames[0]);
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s',
      propertyNames[1]);
    // ...
  }
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_property_names error: %{public}s',
    error.message);
  // ...
}
```

### napi_set_property

Call **napi_set_property** to set a property for an object.

CPP code:

<!-- @[napi_set_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_set_property
static napi_value SetProperty(napi_env env, napi_callback_info info)
{
    // Receive three parameters from the ArkTS side: the first parameter is the object to set, the second is the property, and the third is the value corresponding to the property.
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_status status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
    }
    // Call the napi_set_property API to set the property and value into the object. If it fails, throw an error directly.
    status = napi_set_property(env, args[0], args[1], args[INT_ARG_2]);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_set_property fail");
        return nullptr;
    }
    // Return the object that was set successfully.
    return args[0];
}
```

API declaration:

<!-- @[napi_set_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const setProperty: (obj: Object, key: String, value: string) => Object | undefined; // napi_set_property
```

ArkTS code:

<!-- @[ark_napi_set_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_set_property
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let result = testNapi.setProperty(obj, 'code', 'hi');
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property: %{public}s',
    JSON.stringify(result));
  // ...
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property error: %{public}s', error.message);
  // ...
}
```

### napi_get_property

Call **napi_get_property** to obtain the value of the specified property in an object.

CPP code:

<!-- @[napi_get_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_property
static napi_value GetProperty(napi_env env, napi_callback_info info)
{
    // Receive two parameters from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // The first parameter passed in is the object to check, and the second is the property to check. Obtain the corresponding value by calling the napi_get_property API.
    napi_value result;
    napi_status status = napi_get_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_property fail");
        return nullptr;
    }
    return result;
}
```

API declaration:

<!-- @[napi_get_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getProperty: (obj: Object, key: string) => string | undefined; // napi_get_property
```

ArkTS code:

<!-- @[ark_napi_get_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_property
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property: %{public}s',
    testNapi.getProperty(obj, 'message'));
  // ...
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property error: %{public}s', error.message);
  // ...
}
```

### napi_has_property

Call **napi_has_property** to check whether an object has the specified property. This can prevent the exception or error caused by access to a property that does not exist.

CPP code:

<!-- @[napi_has_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_has_property
static napi_value HasProperty(napi_env env, napi_callback_info info)
{
    // Two parameters are passed from the ArkTS side: the first is the object to check, and the second is the property to check for existence in the object.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Pass the parameters to the napi_has_property method. If the API call succeeds, convert the result to napi_value and return it; otherwise, throw an error.
    bool result;
    napi_status status = napi_has_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_has_property fail");
        return nullptr;
    }

    // If the property exists in the object, output true, convert the result to napi_value, and return it.
    napi_value returnResult;
    napi_get_boolean(env, result, &returnResult);
    return returnResult;
}
```

API declaration:

<!-- @[napi_has_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const hasProperty: (obj: Object, key: number | string) => boolean | undefined; // napi_has_property
```

ArkTS code:

<!-- @[ark_napi_has_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_has_property
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let resultFalse = testNapi.hasProperty(obj, 0);
  let resultTrue = testNapi.hasProperty(obj, 'data');
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s',
    JSON.stringify(resultFalse));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s',
    JSON.stringify(resultTrue));
  // ...
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property error: %{public}s', error.message);
  // ...
}
```

### napi_delete_property

Call **napi_delete_property** to delete the property specified by **key** from an object.

If the object is non-extensible or the property is not configurable, the property cannot be deleted.

CPP code:

<!-- @[napi_delete_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_delete_property
// Delete the specified property from the passed-in Object, and return a bool result indicating whether the deletion was successful.
static napi_value DeleteProperty(napi_env env, napi_callback_info info)
{
    // Receive two parameters from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    if (valueType != napi_object) {
        napi_throw_error(env, nullptr, "Expects an object as argument.");
        return nullptr;
    }
    // Delete the specified property, and store the result in result.
    bool result = false;
    napi_status status = napi_delete_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_delete_property failed");
        return nullptr;
    }
    // Convert the bool result to napi_value and return it.
    napi_value ret;
    napi_get_boolean(env, result, &ret);
    return ret;
}
```

API declaration:

<!-- @[napi_delete_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const deleteProperty: (obj: Object, key: string) => boolean; // napi_delete_property
```

ArkTS code:

<!-- @[ark_napi_delete_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/napiDeleteProperty.ts) --> 

``` TypeScript
import testNapi from 'libentry.so';
import { hilog } from '@kit.PerformanceAnalysisKit';

export function napiDeleteProperty() {
  class Obj {
    first: number = 0;
  }

  let obj: Obj = { first: 1 };
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property first: %{public}s',
    testNapi.deleteProperty(obj, 'first'));
  // Set the new property as non-configurable
  // The Object.defineProperty method is not supported in DevEco Studio 4.1.0.400 and above versions, and needs to be used in TS (TypeScript)
  Object.defineProperty(obj, 'config', {
    configurable: false,
    value: 'value'
  })
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property config: %{public}s',
    testNapi.deleteProperty(obj, 'config'));
}
```

### napi_has_own_property

Call **napi_has_own_property** to check whether an ArkTS object has its own property.

CPP code:

<!-- @[napi_has_own_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_has_own_property
static napi_value NapiHasOwnProperty(napi_env env, napi_callback_info info)
{
    // Receive two parameters from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Check whether the first parameter is an object.
    napi_valuetype valueTypeObj;
    napi_typeof(env, args[0], &valueTypeObj);
    if (valueTypeObj != napi_object) {
        napi_throw_error(env, nullptr, "First argument must be an object.");
        return nullptr;
    }
    // Check whether the second parameter is a string.
    napi_valuetype valuetypeStr;
    napi_typeof(env, args[1], &valuetypeStr);
    if (valuetypeStr != napi_string) {
        napi_throw_error(env, nullptr, "Second argument must be a string.");
        return nullptr;
    }
    // Check whether the object has the specified property, and store the result in hasProperty.
    bool hasProperty;
    napi_status status = napi_has_own_property(env, args[0], args[1], &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_own_property failed");
        return nullptr;
    }
    // Convert the bool result to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```

API declaration:

<!-- @[napi_has_own_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiHasOwnProperty: (obj: Object, key: string) => boolean | undefined; // napi_has_own_property
```

ArkTS code:

<!-- @[ark_napi_has_own_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/napiHasOwnProperty.ts) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

export function napiHasOwnProperty() {
  let myObj = { 'myProperty': 1 };
  let inheritedObj = { 'inheritedProperty': 2 };
  // The Object.setPrototypeOf method is not supported in DevEco Studio 4.1.0.400 and later versions, and must be used in TypeScript (TS).
  Object.setPrototypeOf(myObj, inheritedObj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property my: %{public}s',
    testNapi.napiHasOwnProperty(myObj, 'myProperty'));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property inherited: %{public}s',
    testNapi.napiHasOwnProperty(myObj, 'inheritedProperty'));
}
```

### napi_set_named_property

Call **napi_set_named_property** to set a property for an ArkTS object.

CPP code:

<!-- @[napi_set_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_set_named_property
static napi_value NapiSetNamedProperty(napi_env env, napi_callback_info info)
{
    // Receive one parameter from ArkTS.
    size_t argc = 1;
    napi_value str;
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, &str, nullptr, nullptr);
    // Obtain the passed-in parameter string and store it in strKey.
    size_t keyLength;
    napi_status status = napi_get_value_string_utf8(env, str, strKey, strLength, &keyLength);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_value_string_utf8 failed");
        return nullptr;
    }
    // Create a new object.
    napi_value newObj;
    napi_create_object(env, &newObj);
    // Set the integer value 1234 as the property value.
    int32_t value = 1234;
    napi_value numValue;
    napi_create_int32(env, value, &numValue);
    // Associate the integer value with the specified property name.
    status = napi_set_named_property(env, newObj, strKey, numValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_set_named_property failed");
        return nullptr;
    }
    // Return the object newObj with the named property set.
    return newObj;
}
```

API declaration:

<!-- @[napi_set_named_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiSetNamedProperty: (key: string) => Object | undefined; // napi_set_named_property
```

ArkTS code:

<!-- @[ark_napi_set_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_set_named_property
let obj = testNapi.napiSetNamedProperty('myProperty');
let objAsString = JSON.stringify(obj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_named_property: %{public}s', objAsString);
```

### napi_get_named_property

Call **napi_get_named_property** to obtain the value of the specified property from an ArkTS object.

CPP code:

<!-- @[napi_get_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_named_property
static napi_value NapiGetNamedProperty(napi_env env, napi_callback_info info)
{
    // Receive two parameters from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the name of the property to retrieve.
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // Obtain the value of the specified property and store it in result.
    napi_value result;
    napi_status status = napi_get_named_property(env, args[0], strKey, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_named_property failed");
        return nullptr;
    }
    // Return result.
    return result;
}
```

API declaration:

<!-- @[napi_get_named_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiGetNamedProperty: (obj: Object,
  key: string) => boolean | number | string | Object | undefined; // napi_get_named_property
```

ArkTS code:

<!-- @[ark_napi_get_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_named_property
interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}

class Obj {
  public str: string = '';
  public num: number = 0;
  public bol: boolean = false;
  public nestedObj: NestedObj = { nestedStr: '', nestedNum: 0 };
}

let obj: Obj = {
  str: 'bar',
  num: 42,
  bol: true,
  nestedObj: { nestedStr: 'nestedValue', nestedNum: 123 }
};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s',
  testNapi.napiGetNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}d',
  testNapi.napiGetNamedProperty(obj, 'num'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s',
  testNapi.napiGetNamedProperty(obj, 'bol'));
let nestedObj = testNapi.napiGetNamedProperty(obj, 'nestedObj');
let objAsString = JSON.stringify(nestedObj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', objAsString);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s',
  testNapi.napiGetNamedProperty(obj, 'null'));
```

### napi_has_named_property

Call **napi_has_named_property** to check whether an ArkTS object contains the specified property.

CPP code:

<!-- @[napi_has_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_has_named_property
static napi_value NapiHasNamedProperty(napi_env env, napi_callback_info info)
{
    // Receive two parameters from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the name of the property to check.
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // Check whether the object has the specified named property, and store the result in hasProperty.
    bool hasProperty = false;
    napi_status status = napi_has_named_property(env, args[0], strKey, &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_named_property failed");
        return nullptr;
    }
    // Convert the bool result to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```

API declaration:

<!-- @[napi_has_named_property_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const napiHasNamedProperty: (obj: Object, key: string) => boolean | undefined; // napi_has_named_property
```

ArkTS code:

<!-- @[ark_napi_has_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_has_named_property
interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}

class Obj {
  public str: string = '';
  public num: number = 0;
  public bol: boolean = false;
  public nestedObj: NestedObj = { nestedStr: '', nestedNum: 0 };
}

let obj: Obj = {
  str: 'bar',
  num: 42,
  bol: true,
  nestedObj: { nestedStr: 'nestedValue', nestedNum: 123 }
};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s',
  testNapi.napiHasNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s',
  testNapi.napiHasNamedProperty(obj, 'nestedStr'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s',
  testNapi.napiHasNamedProperty(obj, 'bol'));
```

### napi_define_properties

Call **napi_define_properties** to set object properties.

CPP code:

<!-- @[napi_define_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_define_properties
static napi_value DefineMethodPropertiesExample(napi_env env, napi_callback_info info)
{
    // Create a property value of the int32 type.
    int32_t propValue = 26;
    napi_value returnValue = nullptr;
    napi_create_int32(env, propValue, &returnValue);
    return returnValue;
}

// Getter callback function.
static napi_value GetterCallback(napi_env env, napi_callback_info info)
{
    napi_value result;
    const char *str = u8"World!";
    size_t length = strlen(str);
    // Create the value of the property.
    napi_create_string_utf8(env, str, length, &result);
    return result;
}

// Setter callback function.
static napi_value SetterCallback(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed to the setter.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value result;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    size_t length = 0;
    napi_get_value_string_utf8(env, argv[0], nullptr, 0, &length);
    char* buf = new char[length + 1];
    std::memset(buf, 0, length + 1);
    napi_get_value_string_utf8(env, argv[0], buf, length + 1, &length);
    napi_create_string_utf8(env, buf, length, &result);
    delete[] buf;
    return result;
}

static napi_value DefineMethodProperties(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // Define a function defineMethodPropertiesExample on the obj object. In the function defineMethodPropertiesExample, a variable is defined and returned. This function can be called when invoking this object of obj.
    napi_property_descriptor descriptor[] = {{"defineMethodPropertiesExample", nullptr, DefineMethodPropertiesExample,
                                              nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, obj, sizeof(descriptor) / sizeof(descriptor[0]), descriptor);
    return obj;
}

static napi_value DefineStringProperties(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // Create a property value of the string type.
    napi_value string_value;
    napi_create_string_utf8(env, "Hello!", NAPI_AUTO_LENGTH, &string_value);
    napi_property_descriptor descriptor[] = {
        {"defineStringPropertiesExample", nullptr, nullptr, nullptr, nullptr, string_value, napi_default, nullptr}};
    napi_define_properties(env, obj, sizeof(descriptor) / sizeof(descriptor[0]), descriptor);
    return obj;
}

static napi_value CreateStringWithGetterSetter(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // Define the getter function.
    napi_value getterFn;
    napi_create_function(env, nullptr, 0, GetterCallback, nullptr, &getterFn);
    napi_set_named_property(env, obj, "getterCallback", getterFn);
    // Define the setter function.
    napi_value setterFn;
    napi_create_function(env, nullptr, 0, SetterCallback, nullptr, &setterFn);
    napi_set_named_property(env, obj, "setterCallback", setterFn);
    // Define a property with getter and setter.
    napi_property_descriptor desc = {"defineGetterSetter", nullptr, nullptr, GetterCallback, SetterCallback, nullptr,
                                     napi_enumerable, nullptr};
    napi_define_properties(env, obj, 1, &desc);
    return obj;
}
```

API declaration:

<!-- @[napi_define_properties_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export class DefineMethodObj {
  defineMethodPropertiesExample: Function;
}

export class DefineStringObj {
  defineStringPropertiesExample: string;
}

export class DefineGetterSetterObj {
  getterCallback: Function;
  setterCallback: Function;
}

export const defineMethodProperties: () => DefineMethodObj; // napi_define_properties

export const defineStringProperties: () => DefineStringObj;

export const createStringWithGetterSetter: () => DefineGetterSetterObj;
```

ArkTS code:

<!-- @[ark_napi_define_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_define_properties
// Define a property of the method type.
hilog.info(0x0000, 'testTag', 'Test Node-API define_method_properties:%{public}d',
  testNapi.defineMethodProperties()
    .defineMethodPropertiesExample());
// Define a property of the string type.
hilog.info(0x0000, 'testTag', 'Test Node-API define_string_properties::%{public}s ',
  testNapi.defineStringProperties()
    .defineStringPropertiesExample);
// Getter and setter.
hilog.info(0x0000, 'testTag', 'Test Node-API get::%{public}s ',
  testNapi.createStringWithGetterSetter()
    .getterCallback());
hilog.info(0x0000, 'testTag', 'Test Node-API setter::%{public}s ',
  testNapi.createStringWithGetterSetter()
    .setterCallback('set data'));
```

### napi_get_all_property_names

Call **napi_get_all_property_names** to obtain all property names in an ArkTS object.

CPP code:

<!-- @[napi_get_all_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_all_property_names
static napi_value GetAllPropertyNames(napi_env env, napi_callback_info info)
{
    // Pass in one parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain all property names of the given object.
    napi_value result;
    napi_status status = napi_get_all_property_names(env, args[0], napi_key_own_only, napi_key_writable,
                                                     napi_key_numbers_to_strings, &result);
    // If obtaining the property names fails, throw an error.
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_all_property_names fail");
        return nullptr;
    }

    return result;
}
```

API declaration:

<!-- @[napi_get_all_property_names_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getAllPropertyNames: (obj: Object) => Array<string> | undefined; // napi_get_all_property_names
```

ArkTS code:

<!-- @[ark_napi_get_all_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_all_property_names
try {
  class Obj {
    public data: number = 0
    public message: string = ''
  }

  let obj: Obj = { data: 0, message: 'hello world' };
  let propertyNames = testNapi.getAllPropertyNames(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names: %{public}s',
    JSON.stringify(propertyNames));
  // ...
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names error: %{public}s',
    error.message);
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