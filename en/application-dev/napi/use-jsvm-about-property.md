# Setting JS Object Properties Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=fa3fc214ef4b265f033bc3f0d0a2df54f511a497 translatedAt=2026-08-12T06:33:31.112Z pushedAt=2026-08-12T10:58:17.882Z -->

## Introduction

This topic walks you through on how to obtain and set properties of a JavaScript (JS) object using JSVM-API. Properly using these APIs help to implement more complex functionalities and logic.

## Basic Concepts

Before working with JS objects using JSVM-API, you need to understand the following concepts:

- Object: a composite data type that allows values of different types in an independent entity in JS. An object is a collection of properties and methods. A property is a value associated with the object, and a method is an operation that the object can perform.

- Property: a feature, in the key-value format, of an object in JS. Each property has a name (key or identifier) and a value. The property value can be of any data type, including the basic type, object, and function.

- Enumerable property: a property in JS with **enumerable** set to **true**. An enumerable property can be traversed by **for...in**.

- Own property: a property defined for an object rather than inherited from the prototype chain.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetPropertyNames   | Obtains the names of all enumerable properties of a JS object as a JS array.|
| OH_JSVM_SetProperty        | Sets a property for a JS object.|
| OH_JSVM_GetProperty        | Obtains a property from a JS object.|
| OH_JSVM_HasProperty        | Checks whether a JS object has the specified property.|
| OH_JSVM_DeleteProperty     | Deletes a property from a JS object.|
| OH_JSVM_HasOwnProperty     | Checks whether an object has the own property with the specified name.|
| OH_JSVM_SetNamedProperty   | Sets a property with the given property name for a JS object. This API is equivalent to calling **OH_JSVM_SetProperty** with a **JSVM_Value** created from the string passed in as **utf8Name**.|
| OH_JSVM_GetNamedProperty   | Obtains a property from a JS object. This API is equivalent to calling **OH_JSVM_GetProperty** with a **JSVM_Value** created from the string passed in as **utf8Name**.|
| OH_JSVM_HasNamedProperty   | Checks whether a JS object has the specified property. This API is equivalent to calling **OH_JSVM_HasProperty** with a **JSVM_Value** created from the string passed in as **utf8Name**.|
| OH_JSVM_DefineProperties   | Defines multiple properties for a JS object.|
| OH_JSVM_GetAllPropertyNames | Obtains the names of all available properties of a JS object as a JS array.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in related APIs.

### OH_JSVM_GetPropertyNames

Call **OH_JSVM_GetPropertyNames** to obtain names of all enumerable properties of a JS object in the form of a string array. If the operation is successful, **JSVM_OK** is returned.

CPP code:

<!-- @[oh_jsvm_get_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/getpropertynames/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetPropertyNames
static JSVM_Value GetPropertyNames(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Pass obj as a parameter.
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the names of the object's enumerable properties as a string array, and pass them out via result.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetPropertyNames(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Failed to get property names");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetPropertyNames success");
    }
    return result;
}
// GetPropertyNames registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetPropertyNames},
};
static JSVM_CallbackStruct *method = param;
// GetPropertyNames method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"getPropertyNames", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = '{ data: 0, message: "hello world"}';
    let script = getPropertyNames(obj);
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_GetPropertyNames success
```

### OH_JSVM_SetProperty

Call **OH_JSVM_SetProperty** to set a property for an object.

CPP code:

<!-- @[oh_jsvm_set_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/setproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_SetProperty
static JSVM_Value SetProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Receive three parameters from the JavaScript side: the first parameter is the object to set, the second parameter is the property, and the third parameter is the value corresponding to the property.
    size_t argc = 3;
    JSVM_Value args[3] = {nullptr};
    JSVM_Status status = OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_GetCbInfo fail");
        return nullptr;
    }
    // Call the OH_JSVM_SetProperty API to set the property and value into the object. If it fails, throw an error directly.
    constexpr size_t TARGET_OBJECT_INDEX = 0;
    constexpr size_t PROPERTY_NAME_INDEX = 1;
    constexpr size_t PROPERTY_VALUE_INDEX = 2;
    status = OH_JSVM_SetProperty(env, args[TARGET_OBJECT_INDEX], args[PROPERTY_NAME_INDEX], args[PROPERTY_VALUE_INDEX]);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_SetProperty fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SetProperty success");
    }
    // Return the object after the property is set successfully.
    return args[TARGET_OBJECT_INDEX];
}
// SetProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetProperty},
};
static JSVM_CallbackStruct *method = param;
// SetProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"setProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    setProperty(obj, "code", "hi")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_SetProperty success
```

### OH_JSVM_GetProperty

Call **OH_JSVM_GetProperty** to obtain a property value of a JS object based on the property name.

CPP code:

<!-- @[oh_jsvm_get_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/getproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetProperty
static JSVM_Value GetProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Receive two parameters from JavaScript.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // The first parameter passed in is the object to check, and the second parameter is the property to check. Obtain the corresponding value by calling the OH_JSVM_GetProperty API.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetProperty(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_GetProperty fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetProperty success");
    }
    return result;
}
// GetProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetProperty},
};
static JSVM_CallbackStruct *method = param;
// GetProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"getProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    getProperty(obj, "message")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_GetProperty success
```

### OH_JSVM_HasProperty

Call **OH_JSVM_HasProperty** to check whether an object has the specified property. This can prevent the exception or error caused by access to a property that does not exist.

CPP code:

<!-- @[oh_jsvm_has_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/hasproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_HasProperty
static JSVM_Value HasProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Receive two parameters from the JavaScript side: the first parameter is the object to check, and the second parameter is the property to check for existence in the object.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Pass the parameters to the OH_JSVM_HasProperty method. If the API call succeeds, convert the result to the JSVM_Value type and throw it; otherwise, throw an error.
    bool result = false;
    JSVM_Status status = OH_JSVM_HasProperty(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasProperty fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasProperty success:%{public}d", result);
    }
    // If the specified property exists in the given object, output true and convert the result to the JSVM_Value type and throw it.
    JSVM_Value returnResult = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnResult);
    return returnResult;
}
// HasProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasProperty},
};
static JSVM_CallbackStruct *method = param;
// HasProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasProperty(obj, "data")
    hasProperty(obj, 0)
)JS";
```

Expected result:

```ts
// hasProperty (obj, "data") output
JSVM OH_JSVM_HasProperty success:1
// Output of hasProperty (obj, 0).
JSVM OH_JSVM_HasProperty success:0
```

### OH_JSVM_DeleteProperty

Call **OH_JSVM_DeleteProperty** to delete the property specified by **key** from an object.

If the object is a non-extensible object or the property is not configurable, the property cannot be deleted.

CPP code:

<!-- @[oh_jsvm_delete_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/deleteproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_DeleteProperty
static JSVM_Value DeleteProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain two parameters from the JavaScript side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_ValueType valueType;
    OH_JSVM_Typeof(env, args[0], &valueType);
    if (valueType != JSVM_OBJECT) {
        OH_JSVM_ThrowError(env, nullptr, "Expects an object as argument.");
        return nullptr;
    }
    // Delete the specified property from the given Object, and return a bool result indicating whether the deletion is successful.
    bool result = false;
    JSVM_Status status = OH_JSVM_DeleteProperty(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_DeleteProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_DeleteProperty success:%{public}d", result);
    }
    // Convert the bool result to JSVM_Value and return it.
    JSVM_Value ret;
    OH_JSVM_GetBoolean(env, result, &ret);
    return ret;
}
// DeleteProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DeleteProperty},
};
static JSVM_CallbackStruct *method = param;
// DeleteProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"deleteProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    deleteProperty(obj, "message")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_DeleteProperty success:1
```

### OH_JSVM_HasOwnProperty

Call **OH_JSVM_HasOwnProperty** to check whether a JS object has its own property.

CPP code:

<!-- @[oh_jsvm_has_own_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/hasownproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_HasOwnProperty
static JSVM_Value HasOwnProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain two parameters from the JavaScript side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Check whether the first parameter is an object.
    JSVM_ValueType valueType1;
    OH_JSVM_Typeof(env, args[0], &valueType1);
    if (valueType1 != JSVM_OBJECT) {
        OH_JSVM_ThrowError(env, nullptr, "First argument must be an object.");
        return nullptr;
    }
    // Check whether the second parameter is a string.
    JSVM_ValueType valuetype2;
    OH_JSVM_Typeof(env, args[1], &valuetype2);
    if (valuetype2 != JSVM_STRING) {
        OH_JSVM_ThrowError(env, nullptr, "Second argument must be a string.");
        return nullptr;
    }
    // Check whether the object has the specified property, and store the result in hasProperty.
    bool hasProperty = false;
    JSVM_Status status = OH_JSVM_HasOwnProperty(env, args[0], args[1], &hasProperty);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasOwnProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasOwnProperty success:%{public}d", hasProperty);
    }
    // Convert the bool result to JSVM_Value and return it.
    JSVM_Value result;
    OH_JSVM_GetBoolean(env, hasProperty, &result);
    return result;
}
// HasOwnProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasOwnProperty},
};
static JSVM_CallbackStruct *method = param;
// HasOwnProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasOwnProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasOwnProperty(obj, "message")
    hasOwnProperty(obj, "__defineGetter__")
)JS";
```

Expected result:

```ts
// hasOwnProperty (obj, "message") output
JSVM OH_JSVM_HasOwnProperty success:1
// hasOwnProperty(obj, "__defineGetter__") output
// `__defineGetter__` is the prototype method of the object, not OwnProperty. The expected return value is 0.
JSVM OH_JSVM_HasOwnProperty success:0
```

### OH_JSVM_SetNamedProperty

Sets a named property on the given JavaScript object.

CPP code:

<!-- @[oh_jsvm_set_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/setnamedproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_SetNamedProperty
const size_t STR_KEY_LEN = 32;
static JSVM_Value SetNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain one parameter from the JavaScript side.
    size_t argc = 1;
    JSVM_Value str;
    char strKey[STR_KEY_LEN] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, &str, nullptr, nullptr);
    // Obtain the input parameter string and store it in strKey.
    size_t keyLength;
    OH_JSVM_GetValueStringUtf8(env, str, strKey, STR_KEY_LEN, &keyLength);
    // Create a new object.
    JSVM_Value newObj;
    OH_JSVM_CreateObject(env, &newObj);
    // Set the integer value 1234 as the property value.
    int32_t value = 1234;
    JSVM_Value numValue;
    OH_JSVM_CreateInt32(env, value, &numValue);
    // Associate the integer value with the specified property name.
    JSVM_Status status = OH_JSVM_SetNamedProperty(env, newObj, strKey, numValue);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_SetNamedProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SetNamedProperty success");
    }
    // Return the newly created object with the named property set.
    return newObj;
}
// SetNamedProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// SetNamedProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"setNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    setNamedProperty("message")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_SetNamedProperty success
```

### OH_JSVM_GetNamedProperty

Obtains the value of a named property from a JavaScript object.

CPP code:

<!-- @[oh_jsvm_get_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/getnamedproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetNamedProperty
const size_t MAX_KEY_LENGTH = 32;
static JSVM_Value GetNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain two parameters from the JavaScript side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    char strKey[MAX_KEY_LENGTH] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the property name to get.
    size_t keyLength;
    OH_JSVM_GetValueStringUtf8(env, args[1], strKey, MAX_KEY_LENGTH, &keyLength);
    // Obtain the value of the specified property and store it in result.
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_GetNamedProperty(env, args[0], strKey, &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_GetNamedProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetNamedProperty success");
    }
    return result;
}
// GetNamedProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// GetNamedProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"getNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    getNamedProperty(obj, "message")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_GetNamedProperty success
```

### OH_JSVM_HasNamedProperty

Checks whether a JavaScript object contains the specified named property.

CPP code:

<!-- @[oh_jsvm_has_named_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/hasnamedproperty/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_HasNamedProperty
const size_t STR_KEY_LEN = 32;
static JSVM_Value HasNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain two parameters from the JavaScript side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    char strKey[STR_KEY_LEN] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the property name to check.
    size_t keyLength = 0;
    OH_JSVM_GetValueStringUtf8(env, args[1], strKey, STR_KEY_LEN, &keyLength);
    // Check whether the object has the specified named property, and store the result in hasProperty.
    bool hasProperty = false;
    JSVM_Status status = OH_JSVM_HasNamedProperty(env, args[0], strKey, &hasProperty);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasNamedProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasNamedProperty success:%{public}d", hasProperty);
    }
    // Convert the bool result to JSVM_Value and return it.
    JSVM_Value result;
    OH_JSVM_GetBoolean(env, hasProperty, &result);
    return result;
}
// HasNamedProperty registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// HasNamedProperty method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasNamedProperty(obj, "message")
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_HasNamedProperty success:1
```

### OH_JSVM_DefineProperties

Call **OH_JSVM_DefineProperties** to customize one or more properties for an object.

CPP code:

<!-- @[oh_jsvm_define_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/defineproperties/src/main/cpp/hello.cpp) -->

``` C++
// Callback function for the defineMethodPropertiesExample property in the property descriptor list
static JSVM_Value DefineMethodPropertiesExample(JSVM_Env env, JSVM_CallbackInfo info)
{
    int32_t propValue = 26;
    JSVM_Value returnValue;
    OH_JSVM_CreateInt32(env, propValue, &returnValue);
    return returnValue;
}
// Callback function for the getterCallback property in the property descriptor list
static JSVM_Value GetterCallback(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value result;
    const char *str = "Hello world!";
    size_t length = strlen(str);
    // Create the value of the property.
    OH_JSVM_CreateStringUtf8(env, str, length, &result);
    return result;
}

// Function that executes a JavaScript string.
static JSVM_Value RunScriptAndLogResult(JSVM_Env env, const std::string &srcCode)
{
    JSVM_Value sourceCodeValue;
    OH_JSVM_CreateStringUtf8(env, srcCode.c_str(), srcCode.size(), &sourceCodeValue);
    JSVM_Script script;
    // Compile the JavaScript code string and return the compiled script.
    OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
    JSVM_Value jsVmResult;
    // Execute the JavaScript code string.
    OH_JSVM_RunScript(env, script, &jsVmResult);
    return jsVmResult;
}

// Sample method for OH_JSVM_DefineProperties
static JSVM_Value DefineProperties(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Accept an empty object passed from the JavaScript side.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Create a property value of the string type.
    JSVM_Value stringValue;
    OH_JSVM_CreateStringUtf8(env, "Hello!", JSVM_AUTO_LENGTH, &stringValue);
    // Create the callback function list corresponding to the property descriptors.
    JSVM_CallbackStruct param[] = {
        {.data = nullptr, .callback = DefineMethodPropertiesExample},
        {.data = nullptr, .callback = GetterCallback},

    };
    // Create the property descriptor list. For the positions of different property value types, refer to the JSVM_PropertyDescriptor definition.
    JSVM_PropertyDescriptor descriptor[] = {
        // Define a property value of the method type.
        {"defineMethodPropertiesExample", nullptr, &param[0], nullptr, nullptr, nullptr, JSVM_DEFAULT},
        // Define a property value of the string type.
        {"defineStringPropertiesExample", nullptr, nullptr, nullptr, nullptr, stringValue, JSVM_DEFAULT},
        // Define a property value of the getter type.
        {"getterCallback", nullptr, nullptr, &param[1], nullptr, nullptr, JSVM_DEFAULT}};
    // Create properties for the obj object based on the property descriptor list.
    JSVM_Status statusProperty = OH_JSVM_DefineProperties(env,
                                                          *argv,
                                                          sizeof(descriptor) / sizeof(descriptor[0]),
                                                          descriptor);
    if (statusProperty != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM DefineProperties fail");
        return nullptr;
    }
    // Call the properties added to the obj object.
    // Run obj.defineMethodPropertiesExample() and return the result to JavaScript.
    std::string srcMethod = R"JS(obj.defineMethodPropertiesExample();)JS";
    JSVM_Value jsVmResult = RunScriptAndLogResult(env, srcMethod);
    if (jsVmResult != nullptr) {
        int32_t number;
        OH_JSVM_GetValueInt32(env, jsVmResult, &number);
        OH_LOG_INFO(LOG_APP, "JSVM DefineMethodPropertiesExample success:%{public}d", number);
    }
    // Run obj.defineStringPropertiesExample() and return the result to JavaScript.
    static std::string srcString = R"JS(obj.defineStringPropertiesExample;)JS";
    JSVM_Value jsVmResult1 = RunScriptAndLogResult(env, srcString);
    if (jsVmResult1 != nullptr) {
        size_t length = 0;
        OH_JSVM_GetValueStringUtf8(env, jsVmResult1, nullptr, 0, &length);
        if (length == 0 || length > MAX_MALLOC_SIZE) {
            OH_LOG_ERROR(LOG_APP, "Invalid string length: %{public}zu", length);
            return jsVmResult;
        }
        char *buf = (char *)malloc(length + 1);
        OH_JSVM_GetValueStringUtf8(env, jsVmResult1, buf, length + 1, &length);
        OH_LOG_INFO(LOG_APP, "JSVM defineStringPropertiesExample success:%{public}s", buf);
        free(buf);
    }
    // Call obj.getterCallback() and return the result string to JavaScript.
    static std::string srcGetter = R"JS(obj.getterCallback;)JS";
    JSVM_Value jsVmResult2 = RunScriptAndLogResult(env, srcGetter);
    if (jsVmResult2 != nullptr) {
        size_t length = 0;
        OH_JSVM_GetValueStringUtf8(env, jsVmResult2, nullptr, 0, &length);
        OH_JSVM_GetValueStringUtf8(env, jsVmResult1, nullptr, 0, &length);
        if (length == 0 || length > MAX_MALLOC_SIZE) {
            OH_LOG_ERROR(LOG_APP, "Invalid string length: %{public}zu", length);
            return jsVmResult;
        }
        char *buf = (char *)malloc(length + 1);
        OH_JSVM_GetValueStringUtf8(env, jsVmResult2, buf, length + 1, &length);
        OH_LOG_INFO(LOG_APP, "JSVM getterCallback success:%{public}s", buf);
        free(buf);
    }
    return jsVmResult;
}

// DefineProperties registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DefineProperties},
};
static JSVM_CallbackStruct *method = param;
// DefineProperties method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"defineProperties", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = {};
    defineProperties(obj)
)JS";
```

Expected result:

```ts
JSVM DefineMethodPropertiesExample success:26
JSVM defineStringPropertiesExample success:Hello!
JSVM getterCallback success:Hello world!
```

### OH_JSVM_GetAllPropertyNames

Call **OH_JSVM_GetAllPropertyNames** to obtain the names of all enumerable properties of a JS object as a JS array.

CPP code:

<!-- @[oh_jsvm_get_all_property_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutProperty/getallpropertynames/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetAllPropertyNames
static JSVM_Value GetAllPropertyNames(JSVM_Env env, JSVM_CallbackInfo info)
{
    // // Obtain one parameter from the JavaScript side.
    size_t argc = 1;
    JSVM_Value args[1];
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain all property names (own properties) of the given object.
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_GetAllPropertyNames(env, args[0],
                                                     JSVM_KeyCollectionMode::JSVM_KEY_OWN_ONLY,
                                                     JSVM_KeyFilter::JSVM_KEY_WRITABLE,
                                                     JSVM_KeyConversion::JSVM_KEY_NUMBERS_TO_STRINGS, &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Failed to get all property names");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetAllPropertyNames success");
    }
    return result;
}
// GetAllPropertyNames registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetAllPropertyNames},
};
static JSVM_CallbackStruct *method = param;
// GetAllPropertyNames method alias for JS calling
static JSVM_PropertyDescriptor descriptor[] = {
    {"getAllPropertyNames", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
    let obj = '{ data: 0, message: "hello world", 50: 1}';
    let script = getAllPropertyNames(obj);
)JS";
```

Expected result:

```ts
JSVM OH_JSVM_GetAllPropertyNames success
```