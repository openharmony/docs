# 使用JSVM-API接口设置JavaScript对象的属性

## 简介

使用JSVM-API接口获取和设置JavaScript对象的属性。通过合理使用这些函数，实现更复杂的功能和逻辑。

## 基本概念

在JavaScript对象属性的相关开发中，需要处理JavaScript对象属性，确保正确地访问、设置、删除属性，并了解属性的继承关系和枚举特性。以下是一些关键概念：

- **对象（Object）**：在JavaScript中，对象是一种复合数据类型，它允许存储多个不同类型的值作为一个单独的实体。对象是属性和方法的集合。属性是与对象相关联的值，而方法则是对象可以执行的操作。
- **属性（Property）**：在JavaScript中，属性是对象特征的键值对。每个属性都有一个名字（也称为键或标识符）和一个值。属性的值可以是任意数据类型，包括基本类型、对象和函数。
- **可枚举属性（EnumerableProperty）**：在JavaScript中，对象的属性分为可枚举和不可枚举之分，它们是由属性的enumerable值决定的，即内部 “可枚举” 标志设置为true或false。可枚举性决定了这个属性能否被 `for...in` 查找遍历到。
- **自有属性（OwnProperty）**：自有属性是直接定义在对象上的属性，而不是从原型链上继承来的属性。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetPropertyNames   | 获取给定对象的所有可枚举属性名称，结果变量将存储一个包含所有可枚举属性名称的JavaScript数组 |
| OH_JSVM_SetProperty        | 为给定对象设置一个属性 |
| OH_JSVM_GetProperty        | 用给定的属性的名称，检索目标对象的属性 |
| OH_JSVM_HasProperty        | 用给定的属性的名称，查询目标对象是否有此属性 |
| OH_JSVM_DeleteProperty     | 用给定的属性的名称，删除目标对象属性 |
| OH_JSVM_HasOwnProperty     | 判断给定Object中是否有名为key的own property。|
| OH_JSVM_SetNamedProperty   | 用给定的属性的名称为目标对象设置属性，此方法等效于调用OH_JSVM_SetProperty， 其中，通过utf8Name传入的字符串用于创建JSVM_Value。|
| OH_JSVM_GetNamedProperty   | 用给定的属性的名称，检索目标对象的属性，此方法等效于调用OH_JSVM_GetProperty， 其中，通过utf8Name传入的字符串用于创建JSVM_Value。|
| OH_JSVM_HasNamedProperty   | 用给定的属性的名称，查询目标对象是否有此属性，此方法等效于使用从作为utf8Name传入的字符串创建的JSVM_Value调用OH_JSVM_HasProperty。|
| OH_JSVM_DefineProperties   | 批量的向给定对象中定义属性 |
| OH_JSVM_GetAllPropertyNames | 获取给定对象的所有可用属性名称，结果变量将存储一个包含所有可枚举属性名称的JavaScript数组 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_GetPropertyNames

以字符串数组的形式获取对象的可枚举属性的名称，如果接口调用成功则返回JSVM_OK。

cpp部分代码

```cpp
// OH_JSVM_GetPropertyNames的样例方法
static JSVM_Value GetPropertyNames(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 将obj作为参数传入
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 以字符串数组的形式获取对象的可枚举属性的名称，以result传出
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetPropertyNames(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Failed to get propertynames");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetPropertyNames success");
    }
    return result;
}
// GetPropertyNames注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetPropertyNames},
};
static JSVM_CallbackStruct *method = param;
// GetPropertyNames方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getPropertyNames", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = '{ data: 0, message: "hello world"}';
    let script = getPropertyNames(obj);
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_GetPropertyNames success
```

### OH_JSVM_SetProperty

将给定的属性与值设置入给定的Object。

cpp部分代码

```cpp
// OH_JSVM_SetProperty的样例方法
static JSVM_Value SetProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 接收js侧传入的三个参数：第一个参数为想要设置的object，第二个参数为属性，第三个参数为属性对应的值
    size_t argc = 3;
    JSVM_Value args[3] = {nullptr};
    JSVM_Status status = OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_GetCbInfo fail");
        return nullptr;
    }
    // 通过调用OH_JSVM_SetProperty接口将属性与值设置入object如果失败，直接抛出错误
    status = OH_JSVM_SetProperty(env, args[0], args[1], args[2]);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_SetProperty fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SetProperty success");
    }
    // 将设置成功后的object返回出去
    return args[0];
}
// SetProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetProperty},
};
static JSVM_CallbackStruct *method = param;
// SetProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"setProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    setProperty(obj, "code", "hi")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_SetProperty success
```

### OH_JSVM_GetProperty

获取给定Object的给定属性对应的值。

cpp部分代码

```cpp
// OH_JSVM_GetProperty的样例方法
static JSVM_Value GetProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 接收两个js传来的参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 传入的第一个参数为要检测的object，第二个对象为要检测的属性，通过调用OH_JSVM_GetProperty接口获取对应的值
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
// GetProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetProperty},
};
static JSVM_CallbackStruct *method = param;
// GetProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    getProperty(obj, "message")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_GetProperty success
```

### OH_JSVM_HasProperty

检查对象中是否存在指定的属性，可以避免访问不存在属性导致的异常或错误。

cpp部分代码

```cpp
// OH_JSVM_HasProperty的样例方法
static JSVM_Value HasProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 从js侧传入两个参数：第一个参数为要检验的对象，第二个参数为要检测是否存在对象的属性
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将参数传入OH_JSVM_HasProperty方法中，若接口调用成功则将结果转化为JSVM_Value类型抛出，否则抛出错误
    bool result;
    JSVM_Status status = OH_JSVM_HasProperty(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasProperty fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasProperty success:%{public}d", result);
    }
    // 若传入属性存在传入对象中，则输出true将结果转化为JSVM_Value类型抛出
    JSVM_Value returnReslut = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnReslut);
    return returnReslut;
}
// HasProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasProperty},
};
static JSVM_CallbackStruct *method = param;
// HasProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasProperty(obj, "data")
    hasProperty(obj, 0)
)JS";
```

预期输出结果
```ts
// hasProperty(obj, "data")输出
JSVM OH_JSVM_HasProperty success:1
// hasProperty(obj, 0)输出
JSVM OH_JSVM_HasProperty success:0
```

### OH_JSVM_DeleteProperty

尝试从给定的Object中删除由key指定的属性，并返回操作的结果。
如果对象是一个不可扩展的对象，或者属性是不可配置的，则可能无法删除该属性。

cpp部分代码

```cpp
// OH_JSVM_DeleteProperty的样例方法
static JSVM_Value DeleteProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_ValueType valueType;
    OH_JSVM_Typeof(env, args[0], &valueType);
    if (valueType != JSVM_OBJECT) {
        OH_JSVM_ThrowError(env, nullptr, "Expects an object as argument.");
        return nullptr;
    }
    // 从传入的Object对象中删除指定属性，返回是否删除成功的bool结果值
    bool result = false;
    JSVM_Status status = OH_JSVM_DeleteProperty(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_DeleteProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_DeleteProperty success:%{public}d", result);
    }
    // 将bool结果转换为JSVM_value并返回
    JSVM_Value ret;
    OH_JSVM_GetBoolean(env, result, &ret);
    return ret;
}
// DeleteProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DeleteProperty},
};
static JSVM_CallbackStruct *method = param;
// DeleteProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"deleteProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    deleteProperty(obj, "message")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_DeleteProperty success:1
```

### OH_JSVM_HasOwnProperty

用于检查传入的Object是否具有自己的命名属性，不包括从原型链上继承的属性。

cpp部分代码

```cpp
// OH_JSVM_HasOwnProperty的样例方法
static JSVM_Value HasOwnProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 检查第一个参数是否为对象
    JSVM_ValueType valueType1;
    OH_JSVM_Typeof(env, args[0], &valueType1);
    if (valueType1 != JSVM_OBJECT) {
        OH_JSVM_ThrowError(env, nullptr, "First argument must be an object.");
        return nullptr;
    }
    // 检查第二个参数是否为string
    JSVM_ValueType valuetype2;
    OH_JSVM_Typeof(env, args[1], &valuetype2);
    if (valuetype2 != JSVM_STRING ) {
        OH_JSVM_ThrowError(env, nullptr, "Second argument must be a string.");
        return nullptr;
    }
    // 检查对象是否具有指定属性，结果存储在hasProperty中
    bool hasProperty;
    JSVM_Status status = OH_JSVM_HasOwnProperty(env, args[0], args[1], &hasProperty);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasOwnProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasOwnProperty success:%{public}d", hasProperty);
    }
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value result;
    OH_JSVM_GetBoolean(env, hasProperty, &result);
    return result;
}
// HasOwnProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasOwnProperty},
};
static JSVM_CallbackStruct *method = param;
// HasOwnProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasOwnProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasOwnProperty(obj, "message")
    hasOwnProperty(obj, "__defineGetter__")
)JS";
```

预期输出结果
```ts
// hasOwnProperty(obj, "message")输出
JSVM OH_JSVM_HasOwnProperty success:1
// hasOwnProperty(obj, "__defineGetter__")输出
// `__defineGetter__`为Object原型方法，非OwnProperty，预期返回0
JSVM OH_JSVM_HasOwnProperty success:0
```

### OH_JSVM_SetNamedProperty

用于在传入的Javascript对象上设置一个命名属性。

cpp部分代码

```cpp
// OH_JSVM_SetNamedProperty的样例方法
static JSVM_Value SetNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的一个参数
    size_t argc = 1;
    JSVM_Value str;
    char strKey[32] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, &str, nullptr, nullptr);
    // 获取传入参数字符串并存储在strKey中
    size_t keyLength;
    OH_JSVM_GetValueStringUtf8(env, str, strKey, 32, &keyLength);
    // 创建一个新对象
    JSVM_Value newObj;
    OH_JSVM_CreateObject(env, &newObj);
    // 设置整数值1234为属性值
    int32_t value = 1234;
    JSVM_Value numValue;
    OH_JSVM_CreateInt32(env, value, &numValue);
    // 将整数值与指定属性名关联
    JSVM_Status status = OH_JSVM_SetNamedProperty(env, newObj, strKey, numValue);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_SetNamedProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SetNamedProperty success");
    }
    // 返回新创建并设置命名属性的对象
    return newObj;
}
// SetNamedProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// SetNamedProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"setNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    setNamedProperty("message")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_SetNamedProperty success
```

### OH_JSVM_GetNamedProperty

用于从Javascript对象中获取命名属性的值。

cpp部分代码

```cpp
// OH_JSVM_GetNamedProperty的样例方法
static JSVM_Value GetNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    char strKey[32] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取要获取的属性名
    size_t keyLength;
    OH_JSVM_GetValueStringUtf8(env, args[1], strKey, 32, &keyLength);
    // 获取指定属性的值并存储在result中
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
// GetNamedProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// GetNamedProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    getNamedProperty(obj, "message")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_GetNamedProperty success
```

### OH_JSVM_HasNamedProperty

用于检查Javascript对象中是否包含指定的命名属性。

cpp部分代码

```cpp
// OH_JSVM_HasNamedProperty的样例方法
static JSVM_Value HasNamedProperty(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    char strKey[32] = "";
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取要检查的属性名
    size_t keyLength;
    OH_JSVM_GetValueStringUtf8(env, args[1], strKey, 32, &keyLength);
    // 检查对象是否具有指定命名的属性，并将结果存储在hasProperty中
    bool hasProperty = false;
    JSVM_Status status = OH_JSVM_HasNamedProperty(env, args[0], strKey, &hasProperty);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_HasNamedProperty failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_HasNamedProperty success:%{public}d", hasProperty);
    }
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value result;
    OH_JSVM_GetBoolean(env, hasProperty, &result);
    return result;
}
// HasNamedProperty注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasNamedProperty},
};
static JSVM_CallbackStruct *method = param;
// HasNamedProperty方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasNamedProperty", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = { data: 0, message: "hello world", 50: 1};
    hasNamedProperty(obj, "message")
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_HasNamedProperty success:1
```

### OH_JSVM_DefineProperties

用于定义对象的自定义属性，可一次性为对象设置多个属性。

cpp部分代码

```cpp
#include <fstream>
#include <string>
// 属性描述符列表中defineMethodPropertiesExample属性的回调函数
static JSVM_Value DefineMethodPropertiesExample(JSVM_Env env, JSVM_CallbackInfo info)
{
    int32_t propValue = 26;
    JSVM_Value returnValue;
    OH_JSVM_CreateInt32(env, propValue, &returnValue);
    return returnValue;
}
// 属性描述符列表中getterCallback属性的回调函数
static JSVM_Value GetterCallback(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value result;
    const char *str = "Hello world!";
    size_t length = strlen(str);
    // 创建属性的值
    OH_JSVM_CreateStringUtf8(env, str, length, &result);
    return result;
}

// 执行JavaScript字符串的函数
static JSVM_Value RunScriptAndLogResult(JSVM_Env env, const std::string &srcCode) {
    JSVM_Value sourceCodeValue;
    OH_JSVM_CreateStringUtf8(env, srcCode.c_str(), srcCode.size(), &sourceCodeValue);
    JSVM_Script script;
    // 编译JavaScript代码字符串并返回编译后的脚本
    OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
    JSVM_Value jsVmResult;
    // 执行JavaScript代码字符串
    OH_JSVM_RunScript(env, script, &jsVmResult);
    return jsVmResult;
}

// OH_JSVM_DefineProperties的样例方法
static JSVM_Value DefineProperties(JSVM_Env env, JSVM_CallbackInfo info) {
    // 接受一个JavaScript侧传入的空object
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 创建一个string类型的属性值
    JSVM_Value stringValue;
    OH_JSVM_CreateStringUtf8(env, "Hello!", JSVM_AUTO_LENGTH, &stringValue);
    // 创建属性描述符对应的回调函数列表
    JSVM_CallbackStruct param[] = {
        {.data = nullptr, .callback = DefineMethodPropertiesExample},
        {.data = nullptr, .callback = GetterCallback},

    };
    // 创建属性描述符列表，不同类型属性值添加位置参考JSVM_PropertyDescriptor定义
    JSVM_PropertyDescriptor descriptor[] = {
        // 定义method类型的属性值
        {"defineMethodPropertiesExample", nullptr, &param[0], nullptr, nullptr, nullptr, JSVM_DEFAULT},
        // 定义string类型的属性值
        {"defineStringPropertiesExample", nullptr, nullptr, nullptr, nullptr, stringValue, JSVM_DEFAULT},
        // 定义getter类型的属性值
        {"getterCallback", nullptr, nullptr, &param[1], nullptr, nullptr,JSVM_DEFAULT}};
    // 根据属性描述符列表为obj对象创建属性
    JSVM_Status statusProperty;
    statusProperty = OH_JSVM_DefineProperties(env, *argv, sizeof(descriptor) / sizeof(descriptor[0]), descriptor);
    if (statusProperty != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM DefineProperties fail");
        return nullptr;
    }
    // 调用obj对象中添加的属性
    // 运行obj.defineMethodPropertiesExample()并将结果返回给JavaScript
    static std::string srcMethod;
    srcMethod = R"JS(obj.defineMethodPropertiesExample();)JS";
    JSVM_Value jsVmResult = RunScriptAndLogResult(env, srcMethod);
    if (jsVmResult != nullptr) {
        int32_t number;
        OH_JSVM_GetValueInt32(env, jsVmResult, &number);
        OH_LOG_INFO(LOG_APP, "JSVM DefineMethodPropertiesExample success:%{public}d", number);
    }
    // 运行obj.defineStringPropertiesExample()并将结果返回给JavaScript
    static std::string srcString;
    srcString = R"JS(obj.defineStringPropertiesExample;)JS";
    JSVM_Value jsVmResult1 = RunScriptAndLogResult(env, srcString);
    if (jsVmResult1 != nullptr) {
        size_t length = 0;
        OH_JSVM_GetValueStringUtf8(env, jsVmResult1, nullptr, 0, &length);
        char *buf = (char *)malloc(length + 1);
        OH_JSVM_GetValueStringUtf8(env, jsVmResult1, buf, length + 1, &length);
        OH_LOG_INFO(LOG_APP, "JSVM defineStringPropertiesExample success:%{public}s", buf);
        free(buf);
    }
    // 调用obj的getterCallback()并将结果字符串返回给JavaScript
    static std::string srcGetter;
    srcGetter = R"JS(obj.getterCallback;)JS";
    JSVM_Value jsVmResult2 = RunScriptAndLogResult(env, srcGetter);
    if (jsVmResult2 != nullptr) {
        size_t length = 0;
        OH_JSVM_GetValueStringUtf8(env, jsVmResult2, nullptr, 0, &length);
        char *buf = (char *)malloc(length + 1);
        OH_JSVM_GetValueStringUtf8(env, jsVmResult2, buf, length + 1, &length);
        OH_LOG_INFO(LOG_APP, "JSVM getterCallback success:%{public}s", buf);
        free(buf);
    }
    return jsVmResult;
}

// DefineProperties注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DefineProperties},
};
static JSVM_CallbackStruct *method = param;
// DefineProperties方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"defineProperties", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = {};
    defineProperties(obj)
)JS";
```

预期输出结果
```ts
JSVM DefineMethodPropertiesExample success:26
JSVM defineStringPropertiesExample success:Hello!
JSVM getterCallback success:Hello world!
```

### OH_JSVM_GetAllPropertyNames

获取给定对象的所有可用属性名称, 结果变量将存储一个包含所有可枚举属性名称的JavaScript数组。

cpp部分代码

```cpp
// OH_JSVM_GetAllPropertyNames的样例方法
static JSVM_Value GetAllPropertyNames(JSVM_Env env, JSVM_CallbackInfo info)
{
    // // 获取js侧传入的一个参数
    size_t argc = 1;
    JSVM_Value args[1];
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取给定对象的所有属性名称(自有属性)
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_GetAllPropertyNames(env, args[0],
                                         JSVM_KeyCollectionMode::JSVM_KEY_OWN_ONLY,
                                         JSVM_KeyFilter::JSVM_KEY_WRITABLE,
                                         JSVM_KeyConversion::JSVM_KEY_NUMBERS_TO_STRINGS, &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Failed to get allpropertynames");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetAllPropertyNames success");
    }
    return result;
}
// GetAllPropertyNames注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetAllPropertyNames},
};
static JSVM_CallbackStruct *method = param;
// GetAllPropertyNames方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getAllPropertyNames", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(
    let obj = '{ data: 0, message: "hello world", 50: 1}';
    let script = getAllPropertyNames(obj);
)JS";
```

预期输出结果
```ts
JSVM OH_JSVM_GetAllPropertyNames success
```
