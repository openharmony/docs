# Working with Property Using Node-API

## Introduction

Node-API provides APIs for obtaining and setting properties of ArkTS objects in C/C++. Properly using these APIs help to implement more complex functionalities and logic.

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
| napi_get_property | Obtains the requested property of an object. You can use this API to obtain the property value of an ArkTS object and pass it to another function for processing.|
| napi_has_property | Checks whether an object has the specified property. Before a property is accessed, you can call this API to check whether the object has this property. This can prevent the exception or error caused due to the absence of the property.|
| napi_delete_property | Deletes a property from an ArkTS object.|
| napi_has_own_property | Checks whether an object has the specified own property.|
| napi_set_named_property | Sets a property with the specified name for an ArkTS object.|
| napi_get_named_property | Obtains the value of a property in an ArkTS object.|
| napi_has_named_property | Checks whether an ArkTS object has the property with the specified name.|
| napi_define_properties | Defines multiple properties for an ArkTS object.|
| napi_get_all_property_names | Obtains the names of all properties of an ArkTS object.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to property management.

### napi_get_property_names

Use **napi_get_property_names** to obtain the names of the enumerable properties of an object in an array of strings.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetPropertyNames(napi_env env, napi_callback_info info)
{
    // Parse the ArkTS input parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the names of all the enumerable properties of the object in the form of a string array and output the string array in result.
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

```ts
// index.d.ts
export const getPropertyNames: (obj: Object) => Array<string> | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let propertyNames = testNapi.getPropertyNames(obj);
  if (Array.isArray(propertyNames) && propertyNames.length > 0) {
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s', propertyNames[0]);
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s', propertyNames[1]);
  }
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_property_names error: %{public}s', error.message);
}
```

### napi_set_property

Use **napi_set_property** to set a property for an object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value SetProperty(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS. The first parameter specifies the object, the second parameter specifies the property name, and the third parameter specifies the property value to set.
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_status status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
    }
    // Call napi_set_property to set the property name and value to the object. If the operation fails, throw an error.
    status = napi_set_property(env, args[0], args[1], args[2]);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_set_property fail");
        return nullptr;
    }
    // Return the object that is successfully set.
    return args[0];
}
```

API declaration:

```ts
// index.d.ts
export const setProperty: (obj: Object, key: String, value: string) => Object | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let result = testNapi.setProperty(obj, "code", "hi");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property error: %{public}s', error.message);
}
```

### napi_get_property

Use **napi_get_property** to obtain the value of the specified property in an object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetProperty(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // The first parameter specifies the target object, and the second specifies the property name. Call napi_get_property to obtain the value of the property.
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

```ts
// index.d.ts
export const getProperty: (obj: Object, key: string) => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property: %{public}s', testNapi.getProperty(obj, "message"));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property error: %{public}s', error.message);
}
```

### napi_has_property

Use **napi_has_property** to check whether an object has the specified property. This can prevent the exception or error caused by access to a property that does not exist.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value HasProperty(napi_env env, napi_callback_info info)
{
    // Pass in two parameters from ArkTS. The first parameter specifies the target object, and the second parameter specifies the property to check.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Pass the parameters to napi_has_property. If the API is successfully called, convert the result to napi_value and return napi_value. Otherwise, throw an error.
    bool result;
    napi_status status = napi_has_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_has_property fail");
        return nullptr;
    }

    // If the property exists in the object, output true, convert the result to napi_value, and return napi_value.
    napi_value returnReslut;
    napi_get_boolean(env, result, &returnReslut);
    return returnReslut;
}
```

API declaration:

```ts
// index.d.ts
export const hasProperty: (obj: Object, key: number | string) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let resultFalse = testNapi.hasProperty(obj, 0);
  let resultTrue = testNapi.hasProperty(obj, "data");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s', JSON.stringify(resultFalse));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s', JSON.stringify(resultTrue));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property error: %{public}s', error.message);
}
```

### napi_delete_property

Use **napi_delete_property** to delete the property specified by **key** from an object.
If the object is a non-extensible object or the property is not configurable, the property cannot be deleted.

CPP code:

```cpp
#include "napi/native_api.h"

// Delete the specified property from the object and return a bool value indicating whether the deletion is successful.
static napi_value DeleteProperty(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    if (valueType != napi_object) {
        napi_throw_error(env, nullptr, "Expects an object as argument.");
        return nullptr;
    }
    // Delete the specified property and store the operation result in result.
    bool result = false;
    napi_status status = napi_delete_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_delete_property failed");
        return nullptr;
    }
    // Convert the bool value to napi_value and return it.
    napi_value ret;
    napi_get_boolean(env, result, &ret);
    return ret;
}
```

API declaration:

```ts
// index.d.ts
export const deleteProperty: (obj: Object, key:string) => boolean;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
class Obj {
  first: number = 0;
}
let obj: Obj = { first: 1};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property first: %{public}s', testNapi.deleteProperty(obj, 'first'));
// Set the new property to unconfigurable.
// The Object.defineProperty method is not supported in DevEco Studio 4.1.0.400 or later. It must be used in TS.
Object.defineProperty(obj, 'config', {
  configurable: false,
  value: "value"
})
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property config: %{public}s', testNapi.deleteProperty(obj, 'config'));
```

### napi_has_own_property

Use **napi_has_own_property** to check whether an ArkTS object has its own property.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiHasOwnProperty(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
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
    // Check whether the object has the specified property and return the result in hasProperty.
    bool hasProperty;
    napi_status status = napi_has_own_property(env, args[0], args[1], &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_own_property failed");
        return nullptr;
    }
    // Convert the bool value to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const napiHasOwnProperty: (obj: Object, key:string) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let myObj = { 'myProperty': 1 };
let inheritedObj = { 'inheritedProperty': 2 };
// The Object.setPrototypeOf method is not supported in DevEco Studio 4.1.0.400 or later. It must be used in TS.
Object.setPrototypeOf(myObj, inheritedObj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property my: %{public}s', testNapi.napiHasOwnProperty(myObj, 'myProperty'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property inherited: %{public}s', testNapi.napiHasOwnProperty(myObj, 'inheritedProperty'));
```

### napi_set_named_property

Use **napi_set_named_property** to set a property for an ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiSetNamedProperty(napi_env env, napi_callback_info info)
{
    // Obtain the parameter passed from ArkTS.
    size_t argc = 1;
    napi_value str;
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, &str, nullptr, nullptr);
    // Obtain the string passed in and store it in strKey.
    size_t keyLength;
    napi_get_value_string_utf8(env, str, strKey, strLength, &keyLength);
    // Create an object.
    napi_value newObj;
    napi_create_object(env, &newObj);
    // Set the property value to 1234.
    int32_t value = 1234;
    napi_value numValue;
    napi_create_int32(env, value, &numValue);
    // Associate the integer value with the property name.
    napi_status status = napi_set_named_property(env, newObj, strKey, numValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_set_named_property failed");
        return nullptr;
    }
    // Return the newObj object with the specified property set.
    return newObj;
}
```

API declaration:

```ts
// index.d.ts
export const napiSetNamedProperty: (key: string) => Object | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let obj = testNapi.napiSetNamedProperty('myProperty');
let objAsString = JSON.stringify(obj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_named_property: %{public}s', objAsString);
```

### napi_get_named_property

Use **napi_get_named_property** to obtain the value of the specified property from an ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiGetNamedProperty(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the name of the property to obtain.
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // Obtain the value of the property and store it in result.
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

```ts
// index.d.ts
export const napiGetNamedProperty: (obj: Object, key:string) => boolean | number | string | Object | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}
class Obj {
  str: string = "";
  num: number = 0;
  bol: boolean = false;
  nestedObj: NestedObj = { nestedStr: "", nestedNum: 0 };
}
let obj: Obj = {str: "bar", num: 42, bol: true,
  nestedObj: { nestedStr: "nestedValue", nestedNum: 123 }};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}d', testNapi.napiGetNamedProperty(obj, 'num'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'bol'));
let nestedObj = testNapi.napiGetNamedProperty(obj, 'nestedObj');
let objAsString = JSON.stringify(nestedObj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', objAsString);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'null'));
```

### napi_has_named_property

Use **napi_has_named_property** to check whether an ArkTS object contains the specified property.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiHasNamedProperty(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the property name.
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // Check whether the object has the specified property and store the result in hasProperty.
    bool hasProperty = false;
    napi_status status = napi_has_named_property(env, args[0], strKey, &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_named_property failed");
        return nullptr;
    }
    // Convert the bool value to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const napiHasNamedProperty: (obj: Object, key:string) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}
class Obj {
  str: string = "";
  num: number = 0;
  bol: boolean = false;
  nestedObj: NestedObj = { nestedStr: "", nestedNum: 0 };
}
let obj: Obj = {str: "bar", num: 42, bol: true,
  nestedObj: { nestedStr: "nestedValue", nestedNum: 123 }};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'nestedStr'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'bol'));
```

### napi_define_properties

Use **napi_define_properties** to define multiple properties for an ArkTS object.

CPP code:

```cpp
#include <string>
#include "napi/native_api.h"

static napi_value DefineMethodPropertiesExample(napi_env env, napi_callback_info info)
{
    // Create a property value of the int32 type.
    int32_t propValue = 26;
    napi_value returnValue = nullptr;
    napi_create_int32(env, propValue, &returnValue);
    return returnValue;
}
// Define a getter callback.
static napi_value GetterCallback(napi_env env, napi_callback_info info)
{
    napi_value result;
    const char *str = u8"World!";
    size_t length = strlen(str);
    // Create property values.
    napi_create_string_utf8(env, str, length, &result);
    return result;
}

// Define a setter callback.
static napi_value SetterCallback(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed to setter.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value result;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    std::string buf;
    size_t length;
    napi_get_value_string_utf8(env, argv[0], (char *)buf.c_str(), NAPI_AUTO_LENGTH, &length);
    napi_create_string_utf8(env, buf.c_str(), length, &result);
    return result;
}
static napi_value DefineMethodProperties(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // Define the defineMethodPropertiesExample function for the obj object, define a variable in the defineMethodPropertiesExample function, and return the variable. When the obj object is called, the defineMethodPropertiesExample will be called.
    napi_property_descriptor descriptor[] = {
        {"defineMethodPropertiesExample", nullptr, DefineMethodPropertiesExample, nullptr, nullptr, nullptr, napi_default, nullptr}};
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
    // Define properties with getter and setter.
    napi_property_descriptor desc = {"defineGetterSetter", nullptr, GetterCallback, SetterCallback, nullptr, obj, napi_enumerable, nullptr};
    napi_define_properties(env, obj, 1, &desc);
    return obj;
}
```

API declaration:

```ts
// index.d.ts
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
export const defineMethodProperties: () => DefineMethodObj;
export const defineStringProperties: () => DefineStringObj;
export const createStringWithGetterSetter: () => DefineGetterSetterObj;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
// Define a property of the method type.
hilog.info(0x0000, 'testTag', 'Test Node-API define_method_properties:%{public}d', testNapi.defineMethodProperties()
  .defineMethodPropertiesExample());
// Define a property of the string type.
hilog.info(0x0000, 'testTag', 'Test Node-API define_string_properties::%{public}s ', testNapi.defineStringProperties()
  .defineStringPropertiesExample);
// getter and setter.
hilog.info(0x0000, 'testTag', 'Test Node-API get::%{public}s ', testNapi.createStringWithGetterSetter()
  .getterCallback());
hilog.info(0x0000, 'testTag', 'Test Node-API setter::%{public}s ', testNapi.createStringWithGetterSetter()
  .setterCallback('set data'));
```

### napi_get_all_property_names

Use **napi_get_all_property_names** to obtain all property names in an ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetAllPropertyNames(napi_env env, napi_callback_info info)
{
    // obtain the parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain all property names of the given object.
    napi_value result;
    napi_status status = napi_get_all_property_names(env, args[0], napi_key_own_only, napi_key_writable,
                                                     napi_key_numbers_to_strings, &result);
    // If the operation fails, throw an error.
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_all_property_names fail");
        return nullptr;
    }

    return result;
}
```

API declaration:

```ts
// index.d.ts
export const getAllPropertyNames : (obj: Object) => Array<string> | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let propertyNames = testNapi.getAllPropertyNames(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names: %{public}s', JSON.stringify(propertyNames));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names error: %{public}s', error.message);
}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
