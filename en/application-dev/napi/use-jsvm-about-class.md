# Working with Class Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

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
| OH_JSVM_GetNewTarget  | Obtains the meta property **new.target** of a function.|
| OH_JSVM_DefineClass   | Defines a JS class and associated functions within a C/C++ addon. It allows you to define a constructor, methods, and properties that can be accessed from JS.|
| OH_JSVM_Wrap           | Wraps a native instance in a JS object. You can use **OH_JSVM_Unwrap()** to retrieve the native instance later.|
| OH_JSVM_Unwrap         | Unwraps the native instance that is previously encapsulated in a JS object.|
| OH_JSVM_RemoveWrap     | Removes the wrapping after the native instance is unwrapped from a JS object.|
|OH_JSVM_DefineClassWithOptions | Defines a JS class with the given class name, constructor, properties, callback handler, and parent class. The **DefineClassOptions** parameter specifies whether to set a property proxy for the defined class, reserve the internal-field slot, and set a callback when the class is called as a function.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in class development.

### OH_JSVM_NewInstance

Call **OH_JSVM_NewInstance** to create an instance from the given constructor.

CPP code:

```cpp
// hello.cpp
#include <string.h>
#include <fstream>

std::string ToString(JSVM_Env env, JSVM_Value val) {
    JSVM_Value jsonString = nullptr;
    JSVM_CALL(OH_JSVM_JsonStringify(env, val, &jsonString));
    size_t totalLen = 0;
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, nullptr, 0, &totalLen));
    size_t needLen = totalLen + 1;
    char* buff = new char[needLen];
    std::memset(buff, 0, needLen);
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, buff, needLen, &totalLen));
    std::string str(buff);
    delete[] buff;
    return str;
}

// Define OH_JSVM_NewInstance.
static JSVM_Value NewInstance(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    JSVM_Value result = nullptr;
    // Call OH_JSVM_NewInstance to create an instance and return the instance created.
    JSVM_CALL(OH_JSVM_NewInstance(env, args[0], 1, &args[1], &result));
    std::string str = ToString(env, result);
    OH_LOG_INFO(LOG_APP, "NewInstance:%{public}s", str.c_str());
    return nullptr;
}

// Create an instance from the given constructor.
// Register the NewInstance callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = NewInstance},
};

static JSVM_CallbackStruct *method = param;

// Alias for the NewInstance method, which can be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"newInstance", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
<!-- @[oh_jsvm_newinstance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutClass/newinstance/src/main/cpp/hello.cpp) -->

JS example:
```cpp
const char *srcCallNative = R"JS( 
   function Fruit(name) {
       this.name = name;
   }
   newInstance(Fruit, "apple");
)JS";
```
**Execution result**

The following information is displayed in the log:
```cpp
NewInstance:{"name":"apple"}
```
### OH_JSVM_GetNewTarget

Call **OH_JSVM_GetNewTarget** to obtain the **new.target** value in a function. In JS, **new.target** is a special meta-property used to determine whether a function or constructor is called using the **new** operator.

### OH_JSVM_DefineClass

Call **OH_JSVM_DefineClass** to define a JS class and associated functions within a C/C++ addon. It allows you to define a constructor, methods, and properties that can be accessed from JS.

CPP code:

```cpp
// hello.cpp
#include <string>

JSVM_Value CreateInstance(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value newTarget;
    // Obtain the new.target value of the constructor.
    JSVM_CALL(OH_JSVM_GetNewTarget(env, info, &newTarget));
    OH_LOG_INFO(LOG_APP, "Create Instance");
    OH_LOG_INFO(LOG_APP, "NAPI MyObject::New %{public}s", newTarget != nullptr ? "newTarget != nullptr" : "newTarget == nullptr");
    JSVM_Value jsObject = nullptr;
    JSVM_CALL(OH_JSVM_CreateObject(env, &jsObject));
    JSVM_Value jsName = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &jsName));
    JSVM_Value jsValue = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, "lilei", JSVM_AUTO_LENGTH, &jsValue));
    JSVM_CALL(OH_JSVM_SetProperty(env, jsObject, jsName, jsValue));
    return jsObject;
}

std::string ToString(JSVM_Env env, JSVM_Value val) {
    JSVM_Value jsonString = nullptr;
    JSVM_CALL(OH_JSVM_JsonStringify(env, val, &jsonString));
    size_t totalLen = 0;
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, nullptr, 0, &totalLen));
    size_t needLen = totalLen + 1;
    char* buff = new char[needLen];
    std::memset(buff, 0, needLen);
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, buff, needLen, &totalLen));
    std::string str(buff);
    delete[] buff;
    return str;
}

// Encapsulate the struct in C++.
JSVM_Value DefineClass(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_CallbackStruct param;
    param.data = nullptr;
    param.callback = CreateInstance;
    JSVM_Value cons;
    // Define a class in JS.
    JSVM_CALL(OH_JSVM_DefineClass(env, "MyObject", JSVM_AUTO_LENGTH, &param, 0, nullptr, &cons));
    JSVM_Value instanceValue = nullptr;
    // Called as a constructor of the class.
    JSVM_CALL(OH_JSVM_NewInstance(env, cons, 0, nullptr, &instanceValue));
    std::string str = ToString(env, instanceValue);
    OH_LOG_INFO(LOG_APP, "NewInstance:%{public}s", str.c_str());
    
    // Called as a common function.
    JSVM_Value global = nullptr;
    JSVM_CALL(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value key;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, "Constructor", JSVM_AUTO_LENGTH, &key));
    JSVM_CALL(OH_JSVM_SetProperty(env, global, key, cons));
    JSVM_Value result = nullptr;
    JSVM_CALL(OH_JSVM_CallFunction(env, global, cons, 0, nullptr, &result));
    std::string buf = ToString(env, result);
    OH_LOG_INFO(LOG_APP, "NewInstance:%{public}s", buf.c_str());
    return nullptr;
}

// Register the DefineClass method.
JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DefineClass},
};

static JSVM_CallbackStruct *method = param;

// Alias for the defineClass method, which can be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"defineClass", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

```
<!-- @[oh_jsvm_defineclass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutClass/defineclass/src/main/cpp/hello.cpp) -->

JS example:
```cpp
const char *srcCallNative = R"JS( 
    defineClass();
)JS";
```
**Execution result**

The following information is displayed in the log:
```cpp
Create Instance

NAPI MyObject::New newTarget != nullptr

NewInstance:{"name":"lilei"}

Create Instance

NAPI MyObject::New newTarget == nullptr

NewInstance:{"name":"lilei"}
```
### OH_JSVM_Wrap

Call **OH_JSVM_Wrap** to wrap a native instance in a JS object. You can use **OH_JSVM_Unwrap()** to retrieve the native instance later.

### OH_JSVM_Unwrap

Call **OH_JSVM_Unwrap** to unwrap the native instance that is previously encapsulated in a JS object.

### OH_JSVM_RemoveWrap

Call **OH_JSVM_RemoveWrap** to remove the wrapping after the native instance is unwrapped from a JS object.

CPP code:

```cpp
// hello.cpp
#include <string>

// Define OH_JSVM_GetNewTarget, OH_JSVM_DefineClass, OH_JSVM_Wrap, OH_JSVM_Unwrap, and OH_JSVM_RemoveWrap.

// Define the struct Object.
struct Object {
    std::string name;
    int32_t age;
};

// Define a callback function.
static void DerefItem(JSVM_Env env, void *data, void *hint) {
    OH_LOG_INFO(LOG_APP, "JSVM deref_item");
    (void)hint;
}

static JSVM_Value WrapObject(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM wrap");
    Object obj;
    // Set a property for the object.
    obj.name = "lilei";
    obj.age = 18;
    Object *objPointer = &obj;
    // Obtain the number of parameters in the callback and the values to be wrapped.
    size_t argc = 1;
    JSVM_Value toWrap = nullptr;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, &toWrap, nullptr, nullptr));
    // Call OH_JSVM_Wrap to wrap the custom struct object.
    JSVM_CALL(OH_JSVM_Wrap(env, toWrap, reinterpret_cast<void *>(objPointer), DerefItem, NULL, NULL));
    Object *data;
    // Call OH_JSVM_Unwrap to retrieve the native instance that is previously encapsulated in the JS object.
    JSVM_CALL(OH_JSVM_Unwrap(env, toWrap, reinterpret_cast<void **>(&data)));
    OH_LOG_INFO(LOG_APP, "JSVM name: %{public}s", data->name.c_str());
    OH_LOG_INFO(LOG_APP, "JSVM age: %{public}d", data->age);
    return nullptr;
}

static JSVM_Value RemoveWrap(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM removeWrap");
    Object obj;
    // Set a property for the object.
    obj.name = "lilei";
    obj.age = 18;
    Object *objPointer = &obj;
    // Obtain the number of parameters in the callback and the values to be wrapped.
    size_t argc = 1;
    JSVM_Value toWrap = nullptr;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, &toWrap, nullptr, nullptr));
    // Wrap the Object struct.
    JSVM_CALL(OH_JSVM_Wrap(env, toWrap, reinterpret_cast<void *>(objPointer), DerefItem, NULL, NULL));
    Object *data;
    // Unwrap the previously encapsulated object and remove the wrapping.
    JSVM_CALL(OH_JSVM_RemoveWrap(env, toWrap, reinterpret_cast<void **>(&objPointer)));
    // Check whether the wrapping is removed.
    JSVM_Status status = OH_JSVM_Unwrap(env, toWrap, reinterpret_cast<void **>(&data));
    if (status != JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_RemoveWrap success");
    }
    return nullptr;
}

// Register the WrapObject and RemoveWrap callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WrapObject},
    {.data = nullptr, .callback = RemoveWrap},
};
static JSVM_CallbackStruct *method = param;
// Aliases for the WrapObject and RemoveWrap methods, which can be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"wrapObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"removeWrap", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
<!-- @[oh_jsvm_removewrap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutClass/removewrap/src/main/cpp/hello.cpp) -->

JS example:
```cpp
const char *srcCallNative = R"JS( 
    class Obj {};
    wrapObject(new Obj());
    removeWrap(new Obj());
)JS";
```
**Execution result**

The following information is displayed in the log:
```cpp
JSVM wrap

JSVM name: lilei

JSVM age: 18

JSVM removeWrap

JSVM OH_JSVM_RemoveWrap success

JSVM deref_item
```
### OH_JSVM_DefineClassWithOptions
> **NOTE**<br>The parent class passed in must be created by using an **OH_JSVM_DefineClass** API. Otherwise, the **JSVM_INVALID_ARG** error will be returned.
**DefineClassOptions** supports the following options:
- **JSVM_DEFINE_CLASS_NORMAL**: defines a class in normal mode. The default status is **JSVM_DEFINE_CLASS_NORMAL**.
- **JSVM_DEFINE_CLASS_WITH_COUNT**: reserves **internal-field** slot for the created class.
- **JSVM_DEFINE_CLASS_WITH_PROPERTY_HANDLER**: sets a listener property for the created class and sets a callback to be invoked when it is called as a function.

CPP code:

```c++
#include <string>
#include <memory>
static JSVM_PropertyHandlerConfigurationStruct propertyCfg{
  nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};

static bool g_call_as_function_flag = false;
static bool g_set_named_property_flag = false;
static bool g_call_as_constructor_flag = false;
static bool g_properties_flag = false;

static JSVM_Value SetNamedPropertyCbInfo2(JSVM_Env env, JSVM_Value name, JSVM_Value property, JSVM_Value thisArg,
    JSVM_Value data)
{
    g_set_named_property_flag = true;
    return property;
}

static JSVM_Value Add(JSVM_Env env, JSVM_CallbackInfo info) {
    g_properties_flag = true;
    size_t argc = 2;
    JSVM_Value args[2];
    OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);
    double num1 = 0;
    double num2 = 0;
    OH_JSVM_GetValueDouble(env, args[0], &num1);
    OH_JSVM_GetValueDouble(env, args[1], &num2);
    JSVM_Value sum = nullptr;
    OH_JSVM_CreateDouble(env, num1 + num2, &sum);
    return sum;
}

std::string ToString(JSVM_Env jsvm_env, JSVM_Value val)
{
    JSVM_Value js_string;
    OH_JSVM_CoerceToString(jsvm_env, val, &js_string);
    size_t length = 0;
    OH_JSVM_GetValueStringUtf8(jsvm_env, js_string, NULL, 0, &length);
    size_t capacity = length + 1;
    auto buffer = std::make_unique<char[]>(capacity);
    size_t copy_length = 0;
    OH_JSVM_GetValueStringUtf8(jsvm_env, js_string, buffer.get(), capacity, &copy_length);
    std::string str(buffer.get());
    return str;
}

JSVM_Value Run(JSVM_Env env, const char *s)
{
    // 1. Convert const char* to JS_String.
    JSVM_Value str;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, s, JSVM_AUTO_LENGTH, &str));
    // 2. Convert JS_String to JS_Script.
    JSVM_Script script;
    OH_JSVM_CompileScript(env, str, nullptr, JSVM_AUTO_LENGTH,   false, nullptr, &script);
    // 3. Execute JS_Script.
    JSVM_Value result = nullptr;
    OH_JSVM_RunScript(env, script, &result);
    return result;
}

static JSVM_Value TestDefineClassWithOptions(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_call_as_function_flag = false;
    g_set_named_property_flag = false;
    g_call_as_constructor_flag = false;
    g_properties_flag = false;
    // 1. Define parent-class.
    JSVM_Value parentClass = nullptr;
    JSVM_CallbackStruct parentClassConstructor;
    parentClassConstructor.data = nullptr;
    parentClassConstructor.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        JSVM_Value thisVar = nullptr;
        OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, &thisVar, nullptr);
        return thisVar;
    };
    JSVM_Value fooVal;
    OH_JSVM_CreateStringUtf8(env, "bar", JSVM_AUTO_LENGTH, &fooVal);
    JSVM_PropertyDescriptor des[2];
    des[0] = {
        .utf8name = "foo",
        .value = fooVal,
    };
    JSVM_CallbackStruct parentProperties[] = {
        {.callback = Add, .data = nullptr},
    };
    des[1] = {
        .utf8name = "add",
        .method = &parentProperties[0],
    };
    JSVM_DefineClassOptions options[1];
    options[0].id = JSVM_DEFINE_CLASS_WITH_COUNT;
    options[0].content.num = 3;
    JSVM_CALL(OH_JSVM_DefineClassWithOptions(env, "parentClass", JSVM_AUTO_LENGTH, &parentClassConstructor, 2, des,
        nullptr, 1, options, &parentClass));
  
    // 2. Define sub-class.
    JSVM_Value subClass = nullptr;
    JSVM_CallbackStruct subClassConstructor;
    subClassConstructor.data = nullptr;
    subClassConstructor.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        JSVM_Value thisVar = nullptr;
        g_call_as_constructor_flag = true;
        OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, &thisVar, nullptr);
        return thisVar;
    };
    JSVM_DefineClassOptions subOptions[2];
    JSVM_CallbackStruct callAsFuncParam;
    callAsFuncParam.data = nullptr;
    callAsFuncParam.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        JSVM_Value thisVar = nullptr;
        g_call_as_function_flag = true;
        OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, &thisVar, nullptr);
        return thisVar;
    };
    propertyCfg.genericNamedPropertySetterCallback = SetNamedPropertyCbInfo2;
    JSVM_PropertyHandler propertyHandler = {
        .propertyHandlerCfg = &propertyCfg,
        .callAsFunctionCallback = &callAsFuncParam,
    };
    subOptions[0].id = JSVM_DEFINE_CLASS_WITH_COUNT;
    subOptions[0].content.num = 4;
    subOptions[1].id = JSVM_DEFINE_CLASS_WITH_PROPERTY_HANDLER;
    subOptions[1].content.ptr = &propertyHandler;
    JSVM_CALL(OH_JSVM_DefineClassWithOptions(env, "subClass", JSVM_AUTO_LENGTH, &subClassConstructor, 0, nullptr,
        parentClass, 2, subOptions, &subClass));
    // 3. Verify the validity of 'constructor'.
    JSVM_Value subInstance;
    JSVM_CALL(OH_JSVM_NewInstance(env, subClass, 0, nullptr, &subInstance));

    JSVM_Value globalVal;
    OH_JSVM_GetGlobal(env, &globalVal);
    OH_JSVM_SetNamedProperty(env, globalVal, "obj", subInstance);

    // 4. Verify the validity of 'parentClass'.
    JSVM_Value subRes = nullptr;
    JSVM_CALL(OH_JSVM_GetNamedProperty(env, subInstance, "foo", &subRes));
    if (ToString(env, subRes).compare("bar") != 0) {
        OH_LOG_ERROR(LOG_APP, "Run OH_JSVM_DefineClassWithOptions: Failed");
    }
    // 5. Verify the validity of 'properties'.
    Run(env, "obj.add(3, 4);");
    // 6. Verify the validity of 'options'.
    Run(env, "obj()");
    Run(env, "obj.x = 123;");
    if (g_call_as_function_flag &&
    g_set_named_property_flag &&
    g_call_as_constructor_flag &&
    g_properties_flag) {
        OH_LOG_INFO(LOG_APP, "Run OH_JSVM_DefineClassWithOptions: Success");
    } else {
        OH_LOG_ERROR(LOG_APP, "Run OH_JSVM_DefineClassWithOptions: Failed");
    }
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = TestDefineClassWithOptions},
};
static JSVM_CallbackStruct *method = param;

static JSVM_PropertyDescriptor descriptor[] = {
    {"testDefineClassWithOptions", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

```
JS example:
```cpp
const char *srcCallNative = R"JS(testDefineClassWithOptions();)JS";
```
**Execution result**

The following information is displayed in the log:
```cpp
Run OH_JSVM_DefineClassWithOptions: Success
```
